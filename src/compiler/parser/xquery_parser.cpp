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
#line 71 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"


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
#line 77 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"


#include "xquery_parser.hpp"

/* User implementation prologue.  */

/* Line 299 of lalr1.cc  */
#line 864 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 299 of lalr1.cc  */
#line 964 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"

#include "compiler/parser/xquery_scanner.h"

#undef yylex
#define yylex driver.lexer->lex

/*
 *  Functions to validate lists of properties
 */
// Returns false if validation fails and the parser should call YYERROR, true otherwise
bool validate_collection_properties(
    parsenode* props,
    location& loc,
    parsenode* qname,
    xquery_driver& driver)
{
  Error const &error = CollectionDecl::validatePropertyList(static_cast<DeclPropertyList*>(props));
  if (error != zorba::zerr::ZXQP0000_NO_ERROR)
  {
    driver.set_expr(new ParseErrorNode(driver.createQueryLoc(loc),
                                       error,
                                       static_cast<QName*>(qname)->get_qname(),
                                       true));
    return false;
  }
  return true;
}

// Returns false if validation fails and the parser should call YYERROR, true otherwise
bool validate_index_properties(
    parsenode* props,
    location& loc,
    parsenode* qname,
    xquery_driver& driver)
{
  Error const &error =
  AST_IndexDecl::validatePropertyList(static_cast<DeclPropertyList*>(props));

  if (error != zorba::zerr::ZXQP0000_NO_ERROR)
  {
    driver.set_expr(new ParseErrorNode(driver.createQueryLoc(loc),
                                       error,
                                       static_cast<QName*>(qname)->get_qname(),
                                       true));
    return false;
  }
  return true;
}



/* Line 299 of lalr1.cc  */
#line 150 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"

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
#line 236 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"

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
#line 862 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 341 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 123: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 861 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 350 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 148: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 860 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 359 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 368 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 377 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 386 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 395 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 404 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 413 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 422 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 431 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 440 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 449 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 458 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 467 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 476 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 485 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 494 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 503 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 512 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 521 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 530 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 539 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 548 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 557 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 566 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 575 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 885 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 584 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 885 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 593 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 602 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 879 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 611 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 620 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 629 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 638 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 647 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 656 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 885 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 665 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "AnnotationList" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 674 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "Annotation" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 683 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "AnnotationLiteralList" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 692 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 701 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 710 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "FunctionDeclSimple" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 719 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 728 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 885 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 737 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 746 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 755 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "DeclPropertyList" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 764 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "DeclProperty" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 773 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 782 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "NodeModifier" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 791 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 800 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 809 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 818 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 827 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 836 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "StatementsAndOptionalExprTop" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 845 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "StatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "StatementsAndExpr" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 863 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "Statements" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 872 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "Statement" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 881 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "BlockStatement" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 890 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 899 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "EnclosedStatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 908 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "VarDeclStatement" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "AssignStatement" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 926 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "ApplyStatement" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 935 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "ExitStatement" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "WhileStatement" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 962 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "FLWORStatement" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 971 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "ReturnStatement" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 980 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "IfStatement" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 989 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "TryStatement" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 998 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "CatchListStatement" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1007 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "CatchStatement" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1016 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1025 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1034 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "ExprSimple" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1043 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1052 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1061 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1070 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1079 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1088 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1097 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1106 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1115 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1124 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1133 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1142 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 879 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1151 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1160 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1169 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1178 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1187 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1196 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1205 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1214 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1223 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1232 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1241 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1250 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1259 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1268 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1277 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1286 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1295 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1304 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1313 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1322 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1331 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1340 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1349 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "SwitchExpr" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1358 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "SwitchCaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1367 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "SwitchCaseClause" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1376 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "SwitchCaseOperandList" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1385 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "SwitchStatement" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1394 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1403 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "TypeswitchStatement" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1412 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1421 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1430 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1439 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1448 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1457 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1466 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1475 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 879 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1484 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1493 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1502 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1511 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1520 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1529 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1538 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1547 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1556 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1565 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1574 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1583 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1592 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1601 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1610 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1619 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1628 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1637 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1646 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1655 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1664 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1673 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1682 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1691 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1700 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1709 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1718 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1727 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1736 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1745 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1754 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1763 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1772 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1781 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1790 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1799 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1808 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1817 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1826 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1835 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1844 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1853 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1862 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1871 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1880 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1889 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1898 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1907 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1916 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1925 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1934 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1943 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1952 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1961 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1970 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1979 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1988 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1997 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2006 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2015 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2024 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2033 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2042 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2051 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2060 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2069 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2078 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2087 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 533: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2096 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 534: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2105 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 535: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2114 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 536: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2123 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 537: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2132 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2141 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 539: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2150 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 540: /* "AtomicType" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2159 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 541: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2168 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2177 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 543: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2186 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 544: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2195 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 545: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2204 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 546: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2213 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 547: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2222 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 548: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2231 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 549: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2240 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 550: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2249 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 551: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2258 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 552: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2267 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 553: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2276 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 558: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2285 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 559: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2294 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 562: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2303 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 563: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2312 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 564: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2321 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 565: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2330 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 566: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2339 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 567: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2348 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 568: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2357 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 569: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2366 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 570: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2375 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 571: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2384 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 572: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2393 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 573: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 885 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2402 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 574: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 879 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2411 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 577: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 879 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2420 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 578: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 879 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2429 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 579: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 879 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2438 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 580: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 879 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2447 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 581: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 879 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2456 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 582: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 879 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2465 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 584: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 879 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2474 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 585: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 879 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2483 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 586: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 879 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2492 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 587: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 879 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2501 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 589: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 879 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2510 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 590: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 879 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2519 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 592: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 879 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2528 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 595: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 879 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2537 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 596: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 879 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2546 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 597: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 879 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2555 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 598: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 879 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2564 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 599: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 879 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2573 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 600: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 879 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2582 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 601: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 879 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2591 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 602: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 879 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2600 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 603: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 879 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2609 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 604: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 879 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2618 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 605: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 879 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2627 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 606: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 879 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2636 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 610: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 879 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2645 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 613: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 879 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2654 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 614: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 879 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2663 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 618: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 879 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2672 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 619: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 879 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2681 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 620: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 879 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2690 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 621: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 879 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2699 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 622: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 879 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2708 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 623: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 879 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2717 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 624: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 879 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2726 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 625: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 879 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2735 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 626: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 879 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2744 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 629: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2753 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 630: /* "FUNCTION_NAME" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2762 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 631: /* "EQNAME" */

/* Line 480 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2771 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
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
#line 124 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename2);
}

/* Line 565 of lalr1.cc  */
#line 2868 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"

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
#line 1025 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 4:

/* Line 690 of lalr1.cc  */
#line 1034 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 5:

/* Line 690 of lalr1.cc  */
#line 1043 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 6:

/* Line 690 of lalr1.cc  */
#line 1049 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      MainModule* mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
      mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 7:

/* Line 690 of lalr1.cc  */
#line 1057 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 8:

/* Line 690 of lalr1.cc  */
#line 1063 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      LibraryModule* lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
      lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 9:

/* Line 690 of lalr1.cc  */
#line 1074 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8" );
    }
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 1079 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
    }
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 1087 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 1094 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 1101 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
    }
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 1110 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
    }
    break;

  case 15:

/* Line 690 of lalr1.cc  */
#line 1117 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 1125 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 1133 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (3)]).step();
      error((yylocation_stack_[(5) - (3)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 1141 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (1)]).step();
      error((yylocation_stack_[(5) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 1152 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
    }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 1157 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 1164 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 1171 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
    }
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 1183 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );

      dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
    }
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 1193 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
      sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = sdl;
    }
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 1200 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 1207 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1242 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::preserve_space);
    }
    break;

  case 41:

/* Line 690 of lalr1.cc  */
#line 1247 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::strip_space);
    }
    break;

  case 42:

/* Line 690 of lalr1.cc  */
#line 1255 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
    }
    break;

  case 43:

/* Line 690 of lalr1.cc  */
#line 1263 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 44:

/* Line 690 of lalr1.cc  */
#line 1271 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_preserve);
    }
    break;

  case 45:

/* Line 690 of lalr1.cc  */
#line 1276 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_strip);
    }
    break;

  case 46:

/* Line 690 of lalr1.cc  */
#line 1284 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 1289 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 1297 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_greatest);
    }
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 1302 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_least);
    }
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 1310 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::preserve_ns,
                                  StaticContextConsts::inherit_ns);
    }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 1317 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::preserve_ns,
                                  StaticContextConsts::no_inherit_ns);
    }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 1324 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::no_preserve_ns,
                                  StaticContextConsts::inherit_ns);
    }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 1331 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::no_preserve_ns,
                                  StaticContextConsts::no_inherit_ns);
    }
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 1346 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yyval.node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (2)]), "syntax error, \"import\" should be followed by either \"schema\" or \"module\".");
      YYERROR;
    }
    break;

  case 57:

/* Line 690 of lalr1.cc  */
#line 1356 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
    }
    break;

  case 58:

/* Line 690 of lalr1.cc  */
#line 1361 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                            NULL);
    }
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 1369 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            NULL,
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 1377 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 61:

/* Line 690 of lalr1.cc  */
#line 1388 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      URILiteralList *ull = new URILiteralList( LOC((yyloc)));
      ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
      (yyval.node) = ull;
    }
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 1395 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
        ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 63:

/* Line 690 of lalr1.cc  */
#line 1406 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 64:

/* Line 690 of lalr1.cc  */
#line 1411 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
    }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 1419 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 1426 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 1433 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 1442 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1455 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
    }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 1463 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_element_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 1470 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_function_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 1480 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
      vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = vdl;
    }
    break;

  case 73:

/* Line 690 of lalr1.cc  */
#line 1487 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 1494 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 83:

/* Line 690 of lalr1.cc  */
#line 1517 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 84:

/* Line 690 of lalr1.cc  */
#line 1523 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 85:

/* Line 690 of lalr1.cc  */
#line 1532 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.vstrpair) = new vector<string_pair_t>();
      (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
      delete (yysemantic_stack_[(1) - (1)].strpair);
    }
    break;

  case 86:

/* Line 690 of lalr1.cc  */
#line 1539 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
      delete (yysemantic_stack_[(2) - (2)].strpair);
      (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
    }
    break;

  case 87:

/* Line 690 of lalr1.cc  */
#line 1549 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
      delete sl;
    }
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 1558 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 1559 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 1560 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 1561 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 1562 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 1563 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 1564 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 1565 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 1566 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 1567 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 1573 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OptionDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)));
    }
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 1581 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
    }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 1589 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 1597 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
      d->theType = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 1604 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 1612 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
      d->theIsExternal = false;
      (yyval.node) = d;
    }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 1619 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), NULL);
    }
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 1624 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 1632 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 1640 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1655 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1670 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1688 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL, NULL);
    }
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 1693 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 112:

/* Line 690 of lalr1.cc  */
#line 1701 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                              NULL,
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (1)].node)));
    }
    break;

  case 113:

/* Line 690 of lalr1.cc  */
#line 1709 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)),
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (1)].node)));
    }
    break;

  case 114:

/* Line 690 of lalr1.cc  */
#line 1720 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationListParsenode(LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
    }
    break;

  case 115:

/* Line 690 of lalr1.cc  */
#line 1725 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 116:

/* Line 690 of lalr1.cc  */
#line 1734 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
    }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 1739 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 1746 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true), NULL);
    }
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 1751 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval)), true),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 1761 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationLiteralListParsenode(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 1766 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 1775 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 1781 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl* fdecl = static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));

      fdecl->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );

      fdecl->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 1794 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 1799 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 1807 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1818 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1833 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1845 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1860 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL);
    }
    break;

  case 131:

/* Line 690 of lalr1.cc  */
#line 1865 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 132:

/* Line 690 of lalr1.cc  */
#line 1870 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 133:

/* Line 690 of lalr1.cc  */
#line 1875 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 134:

/* Line 690 of lalr1.cc  */
#line 1883 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      ParamList *pl = new ParamList( LOC((yyloc)) );
      pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = pl;
    }
    break;

  case 135:

/* Line 690 of lalr1.cc  */
#line 1890 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
        pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 136:

/* Line 690 of lalr1.cc  */
#line 1901 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1906 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1916 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      DeclPropertyList *dpl = new DeclPropertyList( LOC((yyloc)) );
      dpl->addProperty(dynamic_cast<DeclProperty*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = dpl;
    }
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 1922 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      DeclPropertyList *dpl = dynamic_cast<DeclPropertyList*>((yysemantic_stack_[(2) - (1)].node));
      dpl->addProperty( static_cast<DeclProperty*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 1932 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_const );
        }
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 1936 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_append_only
            );
        }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1942 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_queue );
        }
    break;

  case 143:

/* Line 690 of lalr1.cc  */
#line 1946 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_mutable );
        }
    break;

  case 144:

/* Line 690 of lalr1.cc  */
#line 1950 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_ordered );
        }
    break;

  case 145:

/* Line 690 of lalr1.cc  */
#line 1954 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_unordered
            );
        }
    break;

  case 146:

/* Line 690 of lalr1.cc  */
#line 1960 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_value_equality
            );
        }
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 1966 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_value_range
            );
        }
    break;

  case 148:

/* Line 690 of lalr1.cc  */
#line 1972 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_general_equality
            );
        }
    break;

  case 149:

/* Line 690 of lalr1.cc  */
#line 1978 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_general_range
            );
        }
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 1984 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_unique );
        }
    break;

  case 151:

/* Line 690 of lalr1.cc  */
#line 1988 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_non_unique
            );
        }
    break;

  case 152:

/* Line 690 of lalr1.cc  */
#line 1994 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_automatic
            );
        }
    break;

  case 153:

/* Line 690 of lalr1.cc  */
#line 2000 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_manual );
        }
    break;

  case 154:

/* Line 690 of lalr1.cc  */
#line 2007 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)),
                              NULL,
                              NULL,
                              NULL);
    }
    break;

  case 155:

/* Line 690 of lalr1.cc  */
#line 2015 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              NULL,
                              static_cast<NodeModifier*>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 156:

/* Line 690 of lalr1.cc  */
#line 2023 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                              NULL,
                              NULL,
                              static_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 157:

/* Line 690 of lalr1.cc  */
#line 2031 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                              NULL,
                              static_cast<NodeModifier*>((yysemantic_stack_[(6) - (6)].node)),
                              static_cast<SequenceType*>((yysemantic_stack_[(6) - (5)].node)));
    }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 2039 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      if (!validate_collection_properties((yysemantic_stack_[(4) - (2)].node), (yyloc), (yysemantic_stack_[(4) - (4)].expr), driver)) {
        delete (yysemantic_stack_[(4) - (2)].node); delete (yysemantic_stack_[(4) - (4)].expr); // these need to be deleted explicitly, as bison does not free them
        YYERROR;
      }

      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                               static_cast<DeclPropertyList*>((yysemantic_stack_[(4) - (2)].node)), 0, 0);
      delete (yysemantic_stack_[(4) - (2)].node);
    }
    break;

  case 159:

/* Line 690 of lalr1.cc  */
#line 2051 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      if (!validate_collection_properties((yysemantic_stack_[(5) - (2)].node), (yyloc), (yysemantic_stack_[(5) - (4)].expr), driver )) {
        delete (yysemantic_stack_[(5) - (2)].node); delete (yysemantic_stack_[(5) - (4)].expr);  delete (yysemantic_stack_[(5) - (5)].node); // these need to be deleted explicitly, as bison does not free them
        YYERROR;
      }

      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                               static_cast<DeclPropertyList*>((yysemantic_stack_[(5) - (2)].node)),
                               static_cast<NodeModifier*>((yysemantic_stack_[(5) - (5)].node)),
                               NULL);
      delete (yysemantic_stack_[(5) - (2)].node);
    }
    break;

  case 160:

/* Line 690 of lalr1.cc  */
#line 2065 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      if (!validate_collection_properties((yysemantic_stack_[(6) - (2)].node), (yyloc), (yysemantic_stack_[(6) - (4)].expr), driver)) {
        delete (yysemantic_stack_[(6) - (2)].node); delete (yysemantic_stack_[(6) - (4)].expr); delete (yysemantic_stack_[(6) - (6)].node); // these need to be deleted explicitly, as bison does not free them
        YYERROR;
      }

      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(6) - (4)].expr)),
                               static_cast<DeclPropertyList*>((yysemantic_stack_[(6) - (2)].node)),
                               NULL,
                               static_cast<SequenceType*>((yysemantic_stack_[(6) - (6)].node)));
      delete (yysemantic_stack_[(6) - (2)].node);
    }
    break;

  case 161:

/* Line 690 of lalr1.cc  */
#line 2079 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      if (!validate_collection_properties((yysemantic_stack_[(7) - (2)].node), (yyloc), (yysemantic_stack_[(7) - (4)].expr), driver)) {
        delete (yysemantic_stack_[(7) - (2)].node); delete (yysemantic_stack_[(7) - (4)].expr); delete (yysemantic_stack_[(7) - (6)].node); delete (yysemantic_stack_[(7) - (7)].node); // these need to be deleted explicitly, as bison does not free them
        YYERROR;
      }

      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(7) - (4)].expr)),
                               static_cast<DeclPropertyList*>((yysemantic_stack_[(7) - (2)].node)),
                               static_cast<NodeModifier*>((yysemantic_stack_[(7) - (7)].node)),
                               static_cast<SequenceType*>((yysemantic_stack_[(7) - (6)].node)));
      delete (yysemantic_stack_[(7) - (2)].node);
    }
    break;

  case 162:

/* Line 690 of lalr1.cc  */
#line 2096 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 163:

/* Line 690 of lalr1.cc  */
#line 2100 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 164:

/* Line 690 of lalr1.cc  */
#line 2109 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier(LOC((yyloc)), StaticContextConsts::read_only);
    }
    break;

  case 165:

/* Line 690 of lalr1.cc  */
#line 2113 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier(LOC((yyloc)), StaticContextConsts::mutable_node);
    }
    break;

  case 166:

/* Line 690 of lalr1.cc  */
#line 2120 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AST_IndexDecl(LOC((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(8) - (3)].expr)),
                             (yysemantic_stack_[(8) - (6)].expr),
                             dynamic_cast<IndexKeyList*>((yysemantic_stack_[(8) - (8)].node)),
                             NULL);
    }
    break;

  case 167:

/* Line 690 of lalr1.cc  */
#line 2128 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      if (!validate_index_properties((yysemantic_stack_[(9) - (2)].node), (yyloc), (yysemantic_stack_[(9) - (4)].expr), driver))
      {
        delete (yysemantic_stack_[(9) - (2)].node); delete (yysemantic_stack_[(9) - (4)].expr); delete (yysemantic_stack_[(9) - (7)].expr); delete (yysemantic_stack_[(9) - (9)].node); // these need to be deleted explicitly, as bison does not free them
        YYERROR;
      }

      (yyval.node) = new AST_IndexDecl(LOC((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(9) - (4)].expr)),
                             (yysemantic_stack_[(9) - (7)].expr),
                             dynamic_cast<IndexKeyList*>((yysemantic_stack_[(9) - (9)].node)),
                             dynamic_cast<DeclPropertyList*>((yysemantic_stack_[(9) - (2)].node)));
      delete (yysemantic_stack_[(9) - (2)].node);
    }
    break;

  case 168:

/* Line 690 of lalr1.cc  */
#line 2146 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 169:

/* Line 690 of lalr1.cc  */
#line 2152 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 170:

/* Line 690 of lalr1.cc  */
#line 2161 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 171:

/* Line 690 of lalr1.cc  */
#line 2166 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 172:

/* Line 690 of lalr1.cc  */
#line 2173 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 173:

/* Line 690 of lalr1.cc  */
#line 2180 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 174:

/* Line 690 of lalr1.cc  */
#line 2192 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollSimpleCheck(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (9)].expr)),
                                 (yysemantic_stack_[(11) - (11)].expr));
    }
    break;

  case 175:

/* Line 690 of lalr1.cc  */
#line 2202 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollUniqueKeyCheck(LOC((yyloc)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (4)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (7)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (10)].expr)),
                                    (yysemantic_stack_[(14) - (14)].expr));
    }
    break;

  case 176:

/* Line 690 of lalr1.cc  */
#line 2212 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollForeachNode(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (11)].expr)),
                                 (yysemantic_stack_[(13) - (13)].expr));
    }
    break;

  case 177:

/* Line 690 of lalr1.cc  */
#line 2223 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
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

  case 178:

/* Line 690 of lalr1.cc  */
#line 2239 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
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

  case 179:

/* Line 690 of lalr1.cc  */
#line 2259 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 180:

/* Line 690 of lalr1.cc  */
#line 2264 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 181:

/* Line 690 of lalr1.cc  */
#line 2268 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  NULL;
    }
    break;

  case 182:

/* Line 690 of lalr1.cc  */
#line 2276 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 183:

/* Line 690 of lalr1.cc  */
#line 2281 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 184:

/* Line 690 of lalr1.cc  */
#line 2285 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  new BlockBody(LOC((yyloc)));
    }
    break;

  case 185:

/* Line 690 of lalr1.cc  */
#line 2293 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 186:

/* Line 690 of lalr1.cc  */
#line 2298 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 187:

/* Line 690 of lalr1.cc  */
#line 2310 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = new BlockBody(LOC((yyloc)));
      blk->add((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 188:

/* Line 690 of lalr1.cc  */
#line 2317 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 2346 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 202:

/* Line 690 of lalr1.cc  */
#line 2351 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 203:

/* Line 690 of lalr1.cc  */
#line 2359 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
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

  case 204:

/* Line 690 of lalr1.cc  */
#line 2376 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 205:

/* Line 690 of lalr1.cc  */
#line 2384 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 206:

/* Line 690 of lalr1.cc  */
#line 2392 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = static_cast<VarDeclStmt*>((yysemantic_stack_[(3) - (1)].expr));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 207:

/* Line 690 of lalr1.cc  */
#line 2399 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(2) - (2)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 208:

/* Line 690 of lalr1.cc  */
#line 2406 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 209:

/* Line 690 of lalr1.cc  */
#line 2413 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (1)].node)));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 210:

/* Line 690 of lalr1.cc  */
#line 2420 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (2)].node)));
      vdecl->add((yysemantic_stack_[(4) - (4)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 211:

/* Line 690 of lalr1.cc  */
#line 2430 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
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

  case 212:

/* Line 690 of lalr1.cc  */
#line 2442 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
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

  case 213:

/* Line 690 of lalr1.cc  */
#line 2455 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
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

  case 214:

/* Line 690 of lalr1.cc  */
#line 2467 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
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

  case 215:

/* Line 690 of lalr1.cc  */
#line 2483 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 216:

/* Line 690 of lalr1.cc  */
#line 2491 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ApplyExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr));
    }
    break;

  case 217:

/* Line 690 of lalr1.cc  */
#line 2499 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 218:

/* Line 690 of lalr1.cc  */
#line 2507 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
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

  case 219:

/* Line 690 of lalr1.cc  */
#line 2522 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement(LOC((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 220:

/* Line 690 of lalr1.cc  */
#line 2527 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
    }
    break;

  case 221:

/* Line 690 of lalr1.cc  */
#line 2535 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
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

  case 222:

/* Line 690 of lalr1.cc  */
#line 2549 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
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

  case 223:

/* Line 690 of lalr1.cc  */
#line 2566 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
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

  case 224:

/* Line 690 of lalr1.cc  */
#line 2591 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TryExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 225:

/* Line 690 of lalr1.cc  */
#line 2599 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* cle = new CatchListExpr( LOC((yyloc)) );
      cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.expr) = cle;
    }
    break;

  case 226:

/* Line 690 of lalr1.cc  */
#line 2606 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 227:

/* Line 690 of lalr1.cc  */
#line 2617 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 228:

/* Line 690 of lalr1.cc  */
#line 2623 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CatchExpr(LOC((yyloc)),*(yysemantic_stack_[(7) - (2)].name_test_list), static_cast<QName*>((yysemantic_stack_[(7) - (5)].expr)), NULL, NULL, (yysemantic_stack_[(7) - (7)].expr));
       delete (yysemantic_stack_[(7) - (2)].name_test_list);
    }
    break;

  case 229:

/* Line 690 of lalr1.cc  */
#line 2629 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
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

  case 230:

/* Line 690 of lalr1.cc  */
#line 2640 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
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

  case 231:

/* Line 690 of lalr1.cc  */
#line 2655 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 232:

/* Line 690 of lalr1.cc  */
#line 2660 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
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

  case 246:

/* Line 690 of lalr1.cc  */
#line 2698 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
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

  case 247:

/* Line 690 of lalr1.cc  */
#line 2712 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
    }
    break;

  case 248:

/* Line 690 of lalr1.cc  */
#line 2720 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 249:

/* Line 690 of lalr1.cc  */
#line 2725 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 250:

/* Line 690 of lalr1.cc  */
#line 2733 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 251:

/* Line 690 of lalr1.cc  */
#line 2738 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 252:

/* Line 690 of lalr1.cc  */
#line 2743 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
    (yyval.strval) = parser::the_only_end;
  }
    break;

  case 253:

/* Line 690 of lalr1.cc  */
#line 2751 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            dynamic_cast<WindowVars*>((yysemantic_stack_[(4) - (2)].node)),
                            (yysemantic_stack_[(4) - (4)].expr),
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 254:

/* Line 690 of lalr1.cc  */
#line 2760 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            NULL,
                            (yysemantic_stack_[(3) - (3)].expr),
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 255:

/* Line 690 of lalr1.cc  */
#line 2772 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
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

  case 256:

/* Line 690 of lalr1.cc  */
#line 2782 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling ?
                              WindowClause::tumbling_window :
                              WindowClause::sliding_window),
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    }
    break;

  case 257:

/* Line 690 of lalr1.cc  */
#line 2795 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 266:

/* Line 690 of lalr1.cc  */
#line 2819 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 267:

/* Line 690 of lalr1.cc  */
#line 2826 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 268:

/* Line 690 of lalr1.cc  */
#line 2836 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 269:

/* Line 690 of lalr1.cc  */
#line 2844 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      VarInDeclList *vdl = new VarInDeclList( LOC((yyloc)) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = vdl;
    }
    break;

  case 270:

/* Line 690 of lalr1.cc  */
#line 2851 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      if ( VarInDeclList *vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 271:

/* Line 690 of lalr1.cc  */
#line 2861 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
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

  case 272:

/* Line 690 of lalr1.cc  */
#line 2871 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
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

  case 273:

/* Line 690 of lalr1.cc  */
#line 2881 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
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

  case 274:

/* Line 690 of lalr1.cc  */
#line 2891 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
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

  case 275:

/* Line 690 of lalr1.cc  */
#line 2901 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
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

  case 276:

/* Line 690 of lalr1.cc  */
#line 2911 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
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

  case 277:

/* Line 690 of lalr1.cc  */
#line 2921 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
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

  case 278:

/* Line 690 of lalr1.cc  */
#line 2931 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
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

  case 279:

/* Line 690 of lalr1.cc  */
#line 2942 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         NULL,NULL,
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
                         (yysemantic_stack_[(4) - (4)].expr),
                         false);
    }
    break;

  case 280:

/* Line 690 of lalr1.cc  */
#line 2951 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
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

  case 281:

/* Line 690 of lalr1.cc  */
#line 2961 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
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

  case 282:

/* Line 690 of lalr1.cc  */
#line 2971 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
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

  case 283:

/* Line 690 of lalr1.cc  */
#line 2987 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 284:

/* Line 690 of lalr1.cc  */
#line 2996 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 285:

/* Line 690 of lalr1.cc  */
#line 3005 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 286:

/* Line 690 of lalr1.cc  */
#line 3013 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 287:

/* Line 690 of lalr1.cc  */
#line 3019 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 288:

/* Line 690 of lalr1.cc  */
#line 3031 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                           NULL,
                           NULL,
                           (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 289:

/* Line 690 of lalr1.cc  */
#line 3039 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                           NULL,
                           (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 290:

/* Line 690 of lalr1.cc  */
#line 3049 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node))->get_var_name(),
                           NULL,
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node)),
                           (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 291:

/* Line 690 of lalr1.cc  */
#line 3057 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (3)].node)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
                           (yysemantic_stack_[(6) - (6)].expr));
    }
    break;

  case 292:

/* Line 690 of lalr1.cc  */
#line 3069 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 293:

/* Line 690 of lalr1.cc  */
#line 3075 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 295:

/* Line 690 of lalr1.cc  */
#line 3088 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 296:

/* Line 690 of lalr1.cc  */
#line 3092 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 297:

/* Line 690 of lalr1.cc  */
#line 3100 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 298:

/* Line 690 of lalr1.cc  */
#line 3104 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 300:

/* Line 690 of lalr1.cc  */
#line 3113 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 301:

/* Line 690 of lalr1.cc  */
#line 3117 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 302:

/* Line 690 of lalr1.cc  */
#line 3121 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 303:

/* Line 690 of lalr1.cc  */
#line 3131 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 304:

/* Line 690 of lalr1.cc  */
#line 3139 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 305:

/* Line 690 of lalr1.cc  */
#line 3146 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = new GroupSpecList( LOC((yyloc)) );
            gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 306:

/* Line 690 of lalr1.cc  */
#line 3152 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
            if ( gsl )
                gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 307:

/* Line 690 of lalr1.cc  */
#line 3163 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 308:

/* Line 690 of lalr1.cc  */
#line 3167 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                         dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 309:

/* Line 690 of lalr1.cc  */
#line 3176 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 3184 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 3190 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 312:

/* Line 690 of lalr1.cc  */
#line 3200 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 313:

/* Line 690 of lalr1.cc  */
#line 3206 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 314:

/* Line 690 of lalr1.cc  */
#line 3216 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 315:

/* Line 690 of lalr1.cc  */
#line 3220 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 316:

/* Line 690 of lalr1.cc  */
#line 3230 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 317:

/* Line 690 of lalr1.cc  */
#line 3236 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 318:

/* Line 690 of lalr1.cc  */
#line 3242 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 319:

/* Line 690 of lalr1.cc  */
#line 3248 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
                NULL
            );
        }
    break;

  case 320:

/* Line 690 of lalr1.cc  */
#line 3257 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                NULL,
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 321:

/* Line 690 of lalr1.cc  */
#line 3266 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                NULL,
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 322:

/* Line 690 of lalr1.cc  */
#line 3275 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 323:

/* Line 690 of lalr1.cc  */
#line 3288 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 324:

/* Line 690 of lalr1.cc  */
#line 3292 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 325:

/* Line 690 of lalr1.cc  */
#line 3300 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 326:

/* Line 690 of lalr1.cc  */
#line 3306 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 327:

/* Line 690 of lalr1.cc  */
#line 3316 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 328:

/* Line 690 of lalr1.cc  */
#line 3324 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_some,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 329:

/* Line 690 of lalr1.cc  */
#line 3333 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_every,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 330:

/* Line 690 of lalr1.cc  */
#line 3346 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 331:

/* Line 690 of lalr1.cc  */
#line 3353 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 332:

/* Line 690 of lalr1.cc  */
#line 3365 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 333:

/* Line 690 of lalr1.cc  */
#line 3369 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 334:

/* Line 690 of lalr1.cc  */
#line 3381 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 335:

/* Line 690 of lalr1.cc  */
#line 3388 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 336:

/* Line 690 of lalr1.cc  */
#line 3394 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 337:

/* Line 690 of lalr1.cc  */
#line 3403 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 338:

/* Line 690 of lalr1.cc  */
#line 3410 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 339:

/* Line 690 of lalr1.cc  */
#line 3416 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 340:

/* Line 690 of lalr1.cc  */
#line 3427 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 341:

/* Line 690 of lalr1.cc  */
#line 3434 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 342:

/* Line 690 of lalr1.cc  */
#line 3440 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 343:

/* Line 690 of lalr1.cc  */
#line 3449 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 344:

/* Line 690 of lalr1.cc  */
#line 3458 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 345:

/* Line 690 of lalr1.cc  */
#line 3465 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 346:

/* Line 690 of lalr1.cc  */
#line 3476 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 347:

/* Line 690 of lalr1.cc  */
#line 3483 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 348:

/* Line 690 of lalr1.cc  */
#line 3495 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 349:

/* Line 690 of lalr1.cc  */
#line 3501 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 350:

/* Line 690 of lalr1.cc  */
#line 3513 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 351:

/* Line 690 of lalr1.cc  */
#line 3519 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 352:

/* Line 690 of lalr1.cc  */
#line 3530 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 353:

/* Line 690 of lalr1.cc  */
#line 3536 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 354:

/* Line 690 of lalr1.cc  */
#line 3547 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 355:

/* Line 690 of lalr1.cc  */
#line 3553 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 356:

/* Line 690 of lalr1.cc  */
#line 3564 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 357:

/* Line 690 of lalr1.cc  */
#line 3573 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 358:

/* Line 690 of lalr1.cc  */
#line 3577 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 359:

/* Line 690 of lalr1.cc  */
#line 3586 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 360:

/* Line 690 of lalr1.cc  */
#line 3590 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 361:

/* Line 690 of lalr1.cc  */
#line 3598 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 362:

/* Line 690 of lalr1.cc  */
#line 3602 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
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

  case 363:

/* Line 690 of lalr1.cc  */
#line 3612 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 364:

/* Line 690 of lalr1.cc  */
#line 3619 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_eq ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 365:

/* Line 690 of lalr1.cc  */
#line 3628 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ne ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 366:

/* Line 690 of lalr1.cc  */
#line 3637 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 367:

/* Line 690 of lalr1.cc  */
#line 3642 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_lt ),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr)
            );
        }
    break;

  case 368:

/* Line 690 of lalr1.cc  */
#line 3651 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_le ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 369:

/* Line 690 of lalr1.cc  */
#line 3660 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_gt ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 370:

/* Line 690 of lalr1.cc  */
#line 3669 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ge ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 371:

/* Line 690 of lalr1.cc  */
#line 3682 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 372:

/* Line 690 of lalr1.cc  */
#line 3686 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FTContainsExpr(
                LOC((yyloc)),
                (yysemantic_stack_[(5) - (1)].expr),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(5) - (4)].node)),
                dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 373:

/* Line 690 of lalr1.cc  */
#line 3698 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 374:

/* Line 690 of lalr1.cc  */
#line 3702 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 375:

/* Line 690 of lalr1.cc  */
#line 3709 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 376:

/* Line 690 of lalr1.cc  */
#line 3713 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 377:

/* Line 690 of lalr1.cc  */
#line 3722 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 378:

/* Line 690 of lalr1.cc  */
#line 3726 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 379:

/* Line 690 of lalr1.cc  */
#line 3730 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 380:

/* Line 690 of lalr1.cc  */
#line 3739 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 381:

/* Line 690 of lalr1.cc  */
#line 3743 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 382:

/* Line 690 of lalr1.cc  */
#line 3749 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 383:

/* Line 690 of lalr1.cc  */
#line 3755 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 384:

/* Line 690 of lalr1.cc  */
#line 3761 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 385:

/* Line 690 of lalr1.cc  */
#line 3772 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 386:

/* Line 690 of lalr1.cc  */
#line 3776 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 387:

/* Line 690 of lalr1.cc  */
#line 3780 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 388:

/* Line 690 of lalr1.cc  */
#line 3788 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 389:

/* Line 690 of lalr1.cc  */
#line 3792 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 390:

/* Line 690 of lalr1.cc  */
#line 3798 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 391:

/* Line 690 of lalr1.cc  */
#line 3808 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 392:

/* Line 690 of lalr1.cc  */
#line 3812 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 393:

/* Line 690 of lalr1.cc  */
#line 3822 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 394:

/* Line 690 of lalr1.cc  */
#line 3826 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 395:

/* Line 690 of lalr1.cc  */
#line 3836 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 396:

/* Line 690 of lalr1.cc  */
#line 3840 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 397:

/* Line 690 of lalr1.cc  */
#line 3850 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 398:

/* Line 690 of lalr1.cc  */
#line 3854 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 399:

/* Line 690 of lalr1.cc  */
#line 3864 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 400:

/* Line 690 of lalr1.cc  */
#line 3868 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 401:

/* Line 690 of lalr1.cc  */
#line 3876 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 402:

/* Line 690 of lalr1.cc  */
#line 3880 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 403:

/* Line 690 of lalr1.cc  */
#line 3884 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 404:

/* Line 690 of lalr1.cc  */
#line 3888 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 405:

/* Line 690 of lalr1.cc  */
#line 3898 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 406:

/* Line 690 of lalr1.cc  */
#line 3902 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 407:

/* Line 690 of lalr1.cc  */
#line 3906 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 408:

/* Line 690 of lalr1.cc  */
#line 3914 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 409:

/* Line 690 of lalr1.cc  */
#line 3918 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 410:

/* Line 690 of lalr1.cc  */
#line 3922 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 411:

/* Line 690 of lalr1.cc  */
#line 3926 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 412:

/* Line 690 of lalr1.cc  */
#line 3930 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 413:

/* Line 690 of lalr1.cc  */
#line 3934 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 414:

/* Line 690 of lalr1.cc  */
#line 3942 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 415:

/* Line 690 of lalr1.cc  */
#line 3946 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 416:

/* Line 690 of lalr1.cc  */
#line 3950 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 417:

/* Line 690 of lalr1.cc  */
#line 3958 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 418:

/* Line 690 of lalr1.cc  */
#line 3962 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 419:

/* Line 690 of lalr1.cc  */
#line 3966 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 420:

/* Line 690 of lalr1.cc  */
#line 3970 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 421:

/* Line 690 of lalr1.cc  */
#line 3981 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 422:

/* Line 690 of lalr1.cc  */
#line 3987 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 423:

/* Line 690 of lalr1.cc  */
#line 3997 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 424:

/* Line 690 of lalr1.cc  */
#line 4003 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 425:

/* Line 690 of lalr1.cc  */
#line 4013 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 426:

/* Line 690 of lalr1.cc  */
#line 4017 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 427:

/* Line 690 of lalr1.cc  */
#line 4021 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 428:

/* Line 690 of lalr1.cc  */
#line 4059 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new PathExpr(LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
    }
    break;

  case 429:

/* Line 690 of lalr1.cc  */
#line 4063 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, NULL, (yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slash,
                        rpe);
    }
    break;

  case 430:

/* Line 690 of lalr1.cc  */
#line 4073 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, NULL, (yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slashslash,
                        rpe);
    }
    break;

  case 431:

/* Line 690 of lalr1.cc  */
#line 4083 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = (!rpe ?
            (yysemantic_stack_[(1) - (1)].expr) :
            new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 432:

/* Line 690 of lalr1.cc  */
#line 4096 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 433:

/* Line 690 of lalr1.cc  */
#line 4105 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
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

  case 434:

/* Line 690 of lalr1.cc  */
#line 4115 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 435:

/* Line 690 of lalr1.cc  */
#line 4119 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 436:

/* Line 690 of lalr1.cc  */
#line 4128 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 437:

/* Line 690 of lalr1.cc  */
#line 4132 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 438:

/* Line 690 of lalr1.cc  */
#line 4141 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 439:

/* Line 690 of lalr1.cc  */
#line 4147 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 440:

/* Line 690 of lalr1.cc  */
#line 4155 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 441:

/* Line 690 of lalr1.cc  */
#line 4161 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 442:

/* Line 690 of lalr1.cc  */
#line 4173 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 443:

/* Line 690 of lalr1.cc  */
#line 4179 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 444:

/* Line 690 of lalr1.cc  */
#line 4189 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 445:

/* Line 690 of lalr1.cc  */
#line 4193 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 446:

/* Line 690 of lalr1.cc  */
#line 4197 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 447:

/* Line 690 of lalr1.cc  */
#line 4201 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 448:

/* Line 690 of lalr1.cc  */
#line 4205 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 449:

/* Line 690 of lalr1.cc  */
#line 4211 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 450:

/* Line 690 of lalr1.cc  */
#line 4217 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 451:

/* Line 690 of lalr1.cc  */
#line 4225 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 452:

/* Line 690 of lalr1.cc  */
#line 4229 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 453:

/* Line 690 of lalr1.cc  */
#line 4237 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 454:

/* Line 690 of lalr1.cc  */
#line 4241 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 455:

/* Line 690 of lalr1.cc  */
#line 4252 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 456:

/* Line 690 of lalr1.cc  */
#line 4256 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 457:

/* Line 690 of lalr1.cc  */
#line 4260 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 458:

/* Line 690 of lalr1.cc  */
#line 4266 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 459:

/* Line 690 of lalr1.cc  */
#line 4270 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 460:

/* Line 690 of lalr1.cc  */
#line 4284 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 461:

/* Line 690 of lalr1.cc  */
#line 4288 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 462:

/* Line 690 of lalr1.cc  */
#line 4296 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 463:

/* Line 690 of lalr1.cc  */
#line 4300 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 464:

/* Line 690 of lalr1.cc  */
#line 4310 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all, false);
    }
    break;

  case 465:

/* Line 690 of lalr1.cc  */
#line 4314 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, false);
    }
    break;

  case 466:

/* Line 690 of lalr1.cc  */
#line 4318 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, true);
    }
    break;

  case 467:

/* Line 690 of lalr1.cc  */
#line 4322 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix, false);
    }
    break;

  case 468:

/* Line 690 of lalr1.cc  */
#line 4331 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 469:

/* Line 690 of lalr1.cc  */
#line 4335 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 470:

/* Line 690 of lalr1.cc  */
#line 4339 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
     }
    break;

  case 471:

/* Line 690 of lalr1.cc  */
#line 4343 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
     }
    break;

  case 472:

/* Line 690 of lalr1.cc  */
#line 4351 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 473:

/* Line 690 of lalr1.cc  */
#line 4357 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 474:

/* Line 690 of lalr1.cc  */
#line 4367 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 475:

/* Line 690 of lalr1.cc  */
#line 4375 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 476:

/* Line 690 of lalr1.cc  */
#line 4379 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 477:

/* Line 690 of lalr1.cc  */
#line 4383 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 478:

/* Line 690 of lalr1.cc  */
#line 4387 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 479:

/* Line 690 of lalr1.cc  */
#line 4391 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 480:

/* Line 690 of lalr1.cc  */
#line 4395 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 481:

/* Line 690 of lalr1.cc  */
#line 4399 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 482:

/* Line 690 of lalr1.cc  */
#line 4403 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 483:

/* Line 690 of lalr1.cc  */
#line 4407 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 484:

/* Line 690 of lalr1.cc  */
#line 4417 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 485:

/* Line 690 of lalr1.cc  */
#line 4425 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 486:

/* Line 690 of lalr1.cc  */
#line 4429 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 487:

/* Line 690 of lalr1.cc  */
#line 4437 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 488:

/* Line 690 of lalr1.cc  */
#line 4444 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 489:

/* Line 690 of lalr1.cc  */
#line 4451 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 490:

/* Line 690 of lalr1.cc  */
#line 4462 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 491:

/* Line 690 of lalr1.cc  */
#line 4470 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 492:

/* Line 690 of lalr1.cc  */
#line 4474 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 493:

/* Line 690 of lalr1.cc  */
#line 4482 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 494:

/* Line 690 of lalr1.cc  */
#line 4490 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 495:

/* Line 690 of lalr1.cc  */
#line 4498 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 496:

/* Line 690 of lalr1.cc  */
#line 4552 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
        }
    break;

  case 497:

/* Line 690 of lalr1.cc  */
#line 4556 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 498:

/* Line 690 of lalr1.cc  */
#line 4569 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            ArgList *al = new ArgList( LOC((yyloc)) );
            al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
            (yyval.node) = al;
        }
    break;

  case 499:

/* Line 690 of lalr1.cc  */
#line 4575 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
                al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 500:

/* Line 690 of lalr1.cc  */
#line 4585 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 501:

/* Line 690 of lalr1.cc  */
#line 4589 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 502:

/* Line 690 of lalr1.cc  */
#line 4597 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 503:

/* Line 690 of lalr1.cc  */
#line 4601 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 504:

/* Line 690 of lalr1.cc  */
#line 4605 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 505:

/* Line 690 of lalr1.cc  */
#line 4613 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
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

  case 506:

/* Line 690 of lalr1.cc  */
#line 4623 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
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

  case 507:

/* Line 690 of lalr1.cc  */
#line 4633 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
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

  case 508:

/* Line 690 of lalr1.cc  */
#line 4643 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
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

  case 509:

/* Line 690 of lalr1.cc  */
#line 4653 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
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

  case 510:

/* Line 690 of lalr1.cc  */
#line 4663 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
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

  case 511:

/* Line 690 of lalr1.cc  */
#line 4678 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
            decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = decl;
        }
    break;

  case 512:

/* Line 690 of lalr1.cc  */
#line 4684 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( decl )
                decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 513:

/* Line 690 of lalr1.cc  */
#line 4695 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
            dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = dal;
        }
    break;

  case 514:

/* Line 690 of lalr1.cc  */
#line 4701 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
            if ( dal )
                dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 515:

/* Line 690 of lalr1.cc  */
#line 4712 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttr(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node))
            );
        }
    break;

  case 518:

/* Line 690 of lalr1.cc  */
#line 4729 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 519:

/* Line 690 of lalr1.cc  */
#line 4734 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 520:

/* Line 690 of lalr1.cc  */
#line 4743 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
        }
    break;

  case 521:

/* Line 690 of lalr1.cc  */
#line 4747 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 522:

/* Line 690 of lalr1.cc  */
#line 4754 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = qacl;
        }
    break;

  case 523:

/* Line 690 of lalr1.cc  */
#line 4760 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = qacl;
        }
    break;

  case 524:

/* Line 690 of lalr1.cc  */
#line 4766 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 525:

/* Line 690 of lalr1.cc  */
#line 4774 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 526:

/* Line 690 of lalr1.cc  */
#line 4786 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
        }
    break;

  case 527:

/* Line 690 of lalr1.cc  */
#line 4790 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 528:

/* Line 690 of lalr1.cc  */
#line 4797 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = aacl;
        }
    break;

  case 529:

/* Line 690 of lalr1.cc  */
#line 4803 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = aacl;
        }
    break;

  case 530:

/* Line 690 of lalr1.cc  */
#line 4809 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if (aacl)
                aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 531:

/* Line 690 of lalr1.cc  */
#line 4816 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( aacl )
                aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 532:

/* Line 690 of lalr1.cc  */
#line 4827 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 533:

/* Line 690 of lalr1.cc  */
#line 4831 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 534:

/* Line 690 of lalr1.cc  */
#line 4841 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 535:

/* Line 690 of lalr1.cc  */
#line 4845 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 536:

/* Line 690 of lalr1.cc  */
#line 4855 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 537:

/* Line 690 of lalr1.cc  */
#line 4859 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 538:

/* Line 690 of lalr1.cc  */
#line 4863 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
        }
    break;

  case 539:

/* Line 690 of lalr1.cc  */
#line 4868 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
        }
    break;

  case 540:

/* Line 690 of lalr1.cc  */
#line 4877 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval))
            );
        }
    break;

  case 541:

/* Line 690 of lalr1.cc  */
#line 4883 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_lbrace
            );
        }
    break;

  case 542:

/* Line 690 of lalr1.cc  */
#line 4889 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_rbrace
            );
        }
    break;

  case 543:

/* Line 690 of lalr1.cc  */
#line 4895 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
        }
    break;

  case 544:

/* Line 690 of lalr1.cc  */
#line 4903 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 545:

/* Line 690 of lalr1.cc  */
#line 4908 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 546:

/* Line 690 of lalr1.cc  */
#line 4916 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 547:

/* Line 690 of lalr1.cc  */
#line 4921 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 548:

/* Line 690 of lalr1.cc  */
#line 4929 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 549:

/* Line 690 of lalr1.cc  */
#line 4937 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 550:

/* Line 690 of lalr1.cc  */
#line 4942 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 551:

/* Line 690 of lalr1.cc  */
#line 4947 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 552:

/* Line 690 of lalr1.cc  */
#line 4952 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 553:

/* Line 690 of lalr1.cc  */
#line 4957 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 554:

/* Line 690 of lalr1.cc  */
#line 4962 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 555:

/* Line 690 of lalr1.cc  */
#line 4971 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 556:

/* Line 690 of lalr1.cc  */
#line 4979 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
        }
    break;

  case 557:

/* Line 690 of lalr1.cc  */
#line 4983 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 558:

/* Line 690 of lalr1.cc  */
#line 5000 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 559:

/* Line 690 of lalr1.cc  */
#line 5004 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 560:

/* Line 690 of lalr1.cc  */
#line 5012 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 561:

/* Line 690 of lalr1.cc  */
#line 5020 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 562:

/* Line 690 of lalr1.cc  */
#line 5028 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 563:

/* Line 690 of lalr1.cc  */
#line 5032 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 564:

/* Line 690 of lalr1.cc  */
#line 5040 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)), false
            );
        }
    break;

  case 565:

/* Line 690 of lalr1.cc  */
#line 5046 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)), true
            );
        }
    break;

  case 566:

/* Line 690 of lalr1.cc  */
#line 5056 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 567:

/* Line 690 of lalr1.cc  */
#line 5064 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 568:

/* Line 690 of lalr1.cc  */
#line 5068 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 569:

/* Line 690 of lalr1.cc  */
#line 5072 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 570:

/* Line 690 of lalr1.cc  */
#line 5107 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 571:

/* Line 690 of lalr1.cc  */
#line 5113 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 572:

/* Line 690 of lalr1.cc  */
#line 5119 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 573:

/* Line 690 of lalr1.cc  */
#line 5129 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 574:

/* Line 690 of lalr1.cc  */
#line 5133 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 575:

/* Line 690 of lalr1.cc  */
#line 5137 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)),true );
        }
    break;

  case 576:

/* Line 690 of lalr1.cc  */
#line 5141 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 577:

/* Line 690 of lalr1.cc  */
#line 5145 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 578:

/* Line 690 of lalr1.cc  */
#line 5152 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 579:

/* Line 690 of lalr1.cc  */
#line 5158 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 580:

/* Line 690 of lalr1.cc  */
#line 5168 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 581:

/* Line 690 of lalr1.cc  */
#line 5176 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 582:

/* Line 690 of lalr1.cc  */
#line 5180 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 583:

/* Line 690 of lalr1.cc  */
#line 5184 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 584:

/* Line 690 of lalr1.cc  */
#line 5188 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 585:

/* Line 690 of lalr1.cc  */
#line 5192 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 586:

/* Line 690 of lalr1.cc  */
#line 5196 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 587:

/* Line 690 of lalr1.cc  */
#line 5200 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 588:

/* Line 690 of lalr1.cc  */
#line 5204 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 589:

/* Line 690 of lalr1.cc  */
#line 5208 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 590:

/* Line 690 of lalr1.cc  */
#line 5216 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyKindTest( LOC((yyloc)) );
        }
    break;

  case 591:

/* Line 690 of lalr1.cc  */
#line 5224 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)) );
        }
    break;

  case 592:

/* Line 690 of lalr1.cc  */
#line 5228 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)) );
        }
    break;

  case 593:

/* Line 690 of lalr1.cc  */
#line 5232 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest(
                LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 594:

/* Line 690 of lalr1.cc  */
#line 5242 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TextTest( LOC((yyloc)) );
        }
    break;

  case 595:

/* Line 690 of lalr1.cc  */
#line 5250 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CommentTest( LOC((yyloc)));
        }
    break;

  case 596:

/* Line 690 of lalr1.cc  */
#line 5258 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 597:

/* Line 690 of lalr1.cc  */
#line 5262 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 598:

/* Line 690 of lalr1.cc  */
#line 5266 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 599:

/* Line 690 of lalr1.cc  */
#line 5274 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 600:

/* Line 690 of lalr1.cc  */
#line 5278 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 601:

/* Line 690 of lalr1.cc  */
#line 5284 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 602:

/* Line 690 of lalr1.cc  */
#line 5290 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 603:

/* Line 690 of lalr1.cc  */
#line 5294 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 604:

/* Line 690 of lalr1.cc  */
#line 5304 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 605:

/* Line 690 of lalr1.cc  */
#line 5312 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 606:

/* Line 690 of lalr1.cc  */
#line 5316 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 607:

/* Line 690 of lalr1.cc  */
#line 5322 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 608:

/* Line 690 of lalr1.cc  */
#line 5331 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 609:

/* Line 690 of lalr1.cc  */
#line 5340 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 610:

/* Line 690 of lalr1.cc  */
#line 5346 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 611:

/* Line 690 of lalr1.cc  */
#line 5352 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 612:

/* Line 690 of lalr1.cc  */
#line 5362 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 613:

/* Line 690 of lalr1.cc  */
#line 5379 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 614:

/* Line 690 of lalr1.cc  */
#line 5386 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 615:

/* Line 690 of lalr1.cc  */
#line 5401 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 616:

/* Line 690 of lalr1.cc  */
#line 5437 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 617:

/* Line 690 of lalr1.cc  */
#line 5441 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 618:

/* Line 690 of lalr1.cc  */
#line 5449 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 619:

/* Line 690 of lalr1.cc  */
#line 5457 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new InlineFunction(LOC((yyloc)),
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theParams,
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theReturnType,
                              (yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (2)].fnsig);
    }
    break;

  case 620:

/* Line 690 of lalr1.cc  */
#line 5469 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 621:

/* Line 690 of lalr1.cc  */
#line 5473 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 622:

/* Line 690 of lalr1.cc  */
#line 5481 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 623:

/* Line 690 of lalr1.cc  */
#line 5489 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 624:

/* Line 690 of lalr1.cc  */
#line 5493 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 625:

/* Line 690 of lalr1.cc  */
#line 5504 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 626:

/* Line 690 of lalr1.cc  */
#line 5521 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 627:

/* Line 690 of lalr1.cc  */
#line 5527 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 628:

/* Line 690 of lalr1.cc  */
#line 5533 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 629:

/* Line 690 of lalr1.cc  */
#line 5543 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 630:

/* Line 690 of lalr1.cc  */
#line 5547 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 631:

/* Line 690 of lalr1.cc  */
#line 5553 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 632:

/* Line 690 of lalr1.cc  */
#line 5559 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 633:

/* Line 690 of lalr1.cc  */
#line 5563 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 634:

/* Line 690 of lalr1.cc  */
#line 5569 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 635:

/* Line 690 of lalr1.cc  */
#line 5573 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 636:

/* Line 690 of lalr1.cc  */
#line 5579 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 637:

/* Line 690 of lalr1.cc  */
#line 5585 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 638:

/* Line 690 of lalr1.cc  */
#line 5592 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 639:

/* Line 690 of lalr1.cc  */
#line 5602 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 640:

/* Line 690 of lalr1.cc  */
#line 5607 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 641:

/* Line 690 of lalr1.cc  */
#line 5615 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 642:

/* Line 690 of lalr1.cc  */
#line 5621 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 643:

/* Line 690 of lalr1.cc  */
#line 5631 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 644:

/* Line 690 of lalr1.cc  */
#line 5653 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 645:

/* Line 690 of lalr1.cc  */
#line 5662 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 646:

/* Line 690 of lalr1.cc  */
#line 5668 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 647:

/* Line 690 of lalr1.cc  */
#line 5681 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 648:

/* Line 690 of lalr1.cc  */
#line 5695 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 649:

/* Line 690 of lalr1.cc  */
#line 5702 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 650:

/* Line 690 of lalr1.cc  */
#line 5708 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 651:

/* Line 690 of lalr1.cc  */
#line 5718 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 652:

/* Line 690 of lalr1.cc  */
#line 5723 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CatchExpr(LOC((yyloc)),*(yysemantic_stack_[(7) - (2)].name_test_list), static_cast<QName*>((yysemantic_stack_[(7) - (5)].expr)), NULL, NULL, (yysemantic_stack_[(7) - (7)].expr));
       delete (yysemantic_stack_[(7) - (2)].name_test_list);
    }
    break;

  case 653:

/* Line 690 of lalr1.cc  */
#line 5728 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
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

  case 654:

/* Line 690 of lalr1.cc  */
#line 5738 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
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

  case 655:

/* Line 690 of lalr1.cc  */
#line 5752 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 656:

/* Line 690 of lalr1.cc  */
#line 5760 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 657:

/* Line 690 of lalr1.cc  */
#line 5766 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 658:

/* Line 690 of lalr1.cc  */
#line 5784 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 659:

/* Line 690 of lalr1.cc  */
#line 5792 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 660:

/* Line 690 of lalr1.cc  */
#line 5796 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 661:

/* Line 690 of lalr1.cc  */
#line 5803 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 662:

/* Line 690 of lalr1.cc  */
#line 5808 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 663:

/* Line 690 of lalr1.cc  */
#line 5816 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 664:

/* Line 690 of lalr1.cc  */
#line 5820 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 665:

/* Line 690 of lalr1.cc  */
#line 5827 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 666:

/* Line 690 of lalr1.cc  */
#line 5831 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 667:

/* Line 690 of lalr1.cc  */
#line 5838 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 668:

/* Line 690 of lalr1.cc  */
#line 5842 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 669:

/* Line 690 of lalr1.cc  */
#line 5849 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 670:

/* Line 690 of lalr1.cc  */
#line 5853 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 671:

/* Line 690 of lalr1.cc  */
#line 5862 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 672:

/* Line 690 of lalr1.cc  */
#line 5874 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 673:

/* Line 690 of lalr1.cc  */
#line 5878 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 674:

/* Line 690 of lalr1.cc  */
#line 5885 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 675:

/* Line 690 of lalr1.cc  */
#line 5889 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 676:

/* Line 690 of lalr1.cc  */
#line 5897 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 677:

/* Line 690 of lalr1.cc  */
#line 5905 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 678:

/* Line 690 of lalr1.cc  */
#line 5913 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 679:

/* Line 690 of lalr1.cc  */
#line 5917 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 680:

/* Line 690 of lalr1.cc  */
#line 5924 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 681:

/* Line 690 of lalr1.cc  */
#line 5928 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 682:

/* Line 690 of lalr1.cc  */
#line 5936 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 683:

/* Line 690 of lalr1.cc  */
#line 5947 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 684:

/* Line 690 of lalr1.cc  */
#line 5951 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 685:

/* Line 690 of lalr1.cc  */
#line 5959 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 686:

/* Line 690 of lalr1.cc  */
#line 5971 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 687:

/* Line 690 of lalr1.cc  */
#line 5977 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 688:

/* Line 690 of lalr1.cc  */
#line 5986 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 689:

/* Line 690 of lalr1.cc  */
#line 5990 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 690:

/* Line 690 of lalr1.cc  */
#line 5998 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 691:

/* Line 690 of lalr1.cc  */
#line 6002 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 692:

/* Line 690 of lalr1.cc  */
#line 6006 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 693:

/* Line 690 of lalr1.cc  */
#line 6013 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 694:

/* Line 690 of lalr1.cc  */
#line 6017 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 695:

/* Line 690 of lalr1.cc  */
#line 6024 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 696:

/* Line 690 of lalr1.cc  */
#line 6028 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 697:

/* Line 690 of lalr1.cc  */
#line 6036 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 698:

/* Line 690 of lalr1.cc  */
#line 6040 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 699:

/* Line 690 of lalr1.cc  */
#line 6044 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 700:

/* Line 690 of lalr1.cc  */
#line 6048 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 701:

/* Line 690 of lalr1.cc  */
#line 6052 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 702:

/* Line 690 of lalr1.cc  */
#line 6060 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 703:

/* Line 690 of lalr1.cc  */
#line 6068 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 704:

/* Line 690 of lalr1.cc  */
#line 6080 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 705:

/* Line 690 of lalr1.cc  */
#line 6092 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 706:

/* Line 690 of lalr1.cc  */
#line 6096 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 707:

/* Line 690 of lalr1.cc  */
#line 6100 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 708:

/* Line 690 of lalr1.cc  */
#line 6108 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 709:

/* Line 690 of lalr1.cc  */
#line 6114 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 710:

/* Line 690 of lalr1.cc  */
#line 6124 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 711:

/* Line 690 of lalr1.cc  */
#line 6128 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 712:

/* Line 690 of lalr1.cc  */
#line 6132 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 713:

/* Line 690 of lalr1.cc  */
#line 6136 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 714:

/* Line 690 of lalr1.cc  */
#line 6140 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 715:

/* Line 690 of lalr1.cc  */
#line 6144 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 716:

/* Line 690 of lalr1.cc  */
#line 6148 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 717:

/* Line 690 of lalr1.cc  */
#line 6152 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 718:

/* Line 690 of lalr1.cc  */
#line 6160 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 719:

/* Line 690 of lalr1.cc  */
#line 6164 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 720:

/* Line 690 of lalr1.cc  */
#line 6168 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 721:

/* Line 690 of lalr1.cc  */
#line 6172 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 722:

/* Line 690 of lalr1.cc  */
#line 6180 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 723:

/* Line 690 of lalr1.cc  */
#line 6186 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 724:

/* Line 690 of lalr1.cc  */
#line 6196 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 725:

/* Line 690 of lalr1.cc  */
#line 6206 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::with );
        }
    break;

  case 726:

/* Line 690 of lalr1.cc  */
#line 6210 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::without );
        }
    break;

  case 727:

/* Line 690 of lalr1.cc  */
#line 6218 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
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

  case 728:

/* Line 690 of lalr1.cc  */
#line 6228 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
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

  case 729:

/* Line 690 of lalr1.cc  */
#line 6239 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 730:

/* Line 690 of lalr1.cc  */
#line 6246 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 731:

/* Line 690 of lalr1.cc  */
#line 6250 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 732:

/* Line 690 of lalr1.cc  */
#line 6257 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 733:

/* Line 690 of lalr1.cc  */
#line 6261 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 734:

/* Line 690 of lalr1.cc  */
#line 6268 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 735:

/* Line 690 of lalr1.cc  */
#line 6273 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 736:

/* Line 690 of lalr1.cc  */
#line 6282 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 737:

/* Line 690 of lalr1.cc  */
#line 6291 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = NULL;
        }
    break;

  case 738:

/* Line 690 of lalr1.cc  */
#line 6295 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 739:

/* Line 690 of lalr1.cc  */
#line 6302 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 740:

/* Line 690 of lalr1.cc  */
#line 6306 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 741:

/* Line 690 of lalr1.cc  */
#line 6314 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 742:

/* Line 690 of lalr1.cc  */
#line 6323 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 743:

/* Line 690 of lalr1.cc  */
#line 6330 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 744:

/* Line 690 of lalr1.cc  */
#line 6340 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 745:

/* Line 690 of lalr1.cc  */
#line 6344 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 746:

/* Line 690 of lalr1.cc  */
#line 6351 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 747:

/* Line 690 of lalr1.cc  */
#line 6357 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 748:

/* Line 690 of lalr1.cc  */
#line 6366 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 749:

/* Line 690 of lalr1.cc  */
#line 6370 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 750:

/* Line 690 of lalr1.cc  */
#line 6377 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 751:

/* Line 690 of lalr1.cc  */
#line 6382 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 752:

/* Line 690 of lalr1.cc  */
#line 6394 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 753:

/* Line 690 of lalr1.cc  */
#line 6402 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 754:

/* Line 690 of lalr1.cc  */
#line 6414 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 755:

/* Line 690 of lalr1.cc  */
#line 6422 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 756:

/* Line 690 of lalr1.cc  */
#line 6426 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 757:

/* Line 690 of lalr1.cc  */
#line 6434 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 758:

/* Line 690 of lalr1.cc  */
#line 6438 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 759:

/* Line 690 of lalr1.cc  */
#line 6442 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 760:

/* Line 690 of lalr1.cc  */
#line 6450 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 761:

/* Line 690 of lalr1.cc  */
#line 6458 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 762:

/* Line 690 of lalr1.cc  */
#line 6462 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 763:

/* Line 690 of lalr1.cc  */
#line 6466 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 764:

/* Line 690 of lalr1.cc  */
#line 6470 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 765:

/* Line 690 of lalr1.cc  */
#line 6478 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 766:

/* Line 690 of lalr1.cc  */
#line 6486 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 767:

/* Line 690 of lalr1.cc  */
#line 6498 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 768:

/* Line 690 of lalr1.cc  */
#line 6502 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 769:

/* Line 690 of lalr1.cc  */
#line 6510 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 772:

/* Line 690 of lalr1.cc  */
#line 6528 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
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

  case 774:

/* Line 690 of lalr1.cc  */
#line 6541 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 775:

/* Line 690 of lalr1.cc  */
#line 6542 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 776:

/* Line 690 of lalr1.cc  */
#line 6543 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 777:

/* Line 690 of lalr1.cc  */
#line 6544 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 778:

/* Line 690 of lalr1.cc  */
#line 6545 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 779:

/* Line 690 of lalr1.cc  */
#line 6546 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 780:

/* Line 690 of lalr1.cc  */
#line 6547 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 781:

/* Line 690 of lalr1.cc  */
#line 6548 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 782:

/* Line 690 of lalr1.cc  */
#line 6549 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 783:

/* Line 690 of lalr1.cc  */
#line 6550 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 784:

/* Line 690 of lalr1.cc  */
#line 6551 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 785:

/* Line 690 of lalr1.cc  */
#line 6552 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 786:

/* Line 690 of lalr1.cc  */
#line 6553 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 787:

/* Line 690 of lalr1.cc  */
#line 6554 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 788:

/* Line 690 of lalr1.cc  */
#line 6555 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 790:

/* Line 690 of lalr1.cc  */
#line 6560 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 791:

/* Line 690 of lalr1.cc  */
#line 6561 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 792:

/* Line 690 of lalr1.cc  */
#line 6562 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 793:

/* Line 690 of lalr1.cc  */
#line 6563 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 794:

/* Line 690 of lalr1.cc  */
#line 6564 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 795:

/* Line 690 of lalr1.cc  */
#line 6565 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 796:

/* Line 690 of lalr1.cc  */
#line 6566 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 797:

/* Line 690 of lalr1.cc  */
#line 6567 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 798:

/* Line 690 of lalr1.cc  */
#line 6568 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 799:

/* Line 690 of lalr1.cc  */
#line 6569 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 800:

/* Line 690 of lalr1.cc  */
#line 6570 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 801:

/* Line 690 of lalr1.cc  */
#line 6571 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 802:

/* Line 690 of lalr1.cc  */
#line 6572 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 803:

/* Line 690 of lalr1.cc  */
#line 6573 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 804:

/* Line 690 of lalr1.cc  */
#line 6574 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 805:

/* Line 690 of lalr1.cc  */
#line 6575 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 806:

/* Line 690 of lalr1.cc  */
#line 6576 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 807:

/* Line 690 of lalr1.cc  */
#line 6577 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 808:

/* Line 690 of lalr1.cc  */
#line 6578 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 809:

/* Line 690 of lalr1.cc  */
#line 6579 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 810:

/* Line 690 of lalr1.cc  */
#line 6580 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 811:

/* Line 690 of lalr1.cc  */
#line 6581 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 812:

/* Line 690 of lalr1.cc  */
#line 6582 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 813:

/* Line 690 of lalr1.cc  */
#line 6583 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 814:

/* Line 690 of lalr1.cc  */
#line 6584 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 815:

/* Line 690 of lalr1.cc  */
#line 6585 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 816:

/* Line 690 of lalr1.cc  */
#line 6586 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 817:

/* Line 690 of lalr1.cc  */
#line 6587 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 818:

/* Line 690 of lalr1.cc  */
#line 6588 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 819:

/* Line 690 of lalr1.cc  */
#line 6589 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 820:

/* Line 690 of lalr1.cc  */
#line 6590 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 821:

/* Line 690 of lalr1.cc  */
#line 6591 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 822:

/* Line 690 of lalr1.cc  */
#line 6592 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 823:

/* Line 690 of lalr1.cc  */
#line 6593 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 824:

/* Line 690 of lalr1.cc  */
#line 6594 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 825:

/* Line 690 of lalr1.cc  */
#line 6595 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 826:

/* Line 690 of lalr1.cc  */
#line 6596 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 827:

/* Line 690 of lalr1.cc  */
#line 6597 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 828:

/* Line 690 of lalr1.cc  */
#line 6598 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 829:

/* Line 690 of lalr1.cc  */
#line 6599 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 830:

/* Line 690 of lalr1.cc  */
#line 6600 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 831:

/* Line 690 of lalr1.cc  */
#line 6601 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 832:

/* Line 690 of lalr1.cc  */
#line 6602 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 833:

/* Line 690 of lalr1.cc  */
#line 6603 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 834:

/* Line 690 of lalr1.cc  */
#line 6604 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 835:

/* Line 690 of lalr1.cc  */
#line 6605 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 836:

/* Line 690 of lalr1.cc  */
#line 6606 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 837:

/* Line 690 of lalr1.cc  */
#line 6607 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 838:

/* Line 690 of lalr1.cc  */
#line 6608 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 839:

/* Line 690 of lalr1.cc  */
#line 6609 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 840:

/* Line 690 of lalr1.cc  */
#line 6610 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 841:

/* Line 690 of lalr1.cc  */
#line 6611 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 842:

/* Line 690 of lalr1.cc  */
#line 6612 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 843:

/* Line 690 of lalr1.cc  */
#line 6613 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 844:

/* Line 690 of lalr1.cc  */
#line 6614 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 845:

/* Line 690 of lalr1.cc  */
#line 6615 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 846:

/* Line 690 of lalr1.cc  */
#line 6616 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 847:

/* Line 690 of lalr1.cc  */
#line 6617 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 848:

/* Line 690 of lalr1.cc  */
#line 6618 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 849:

/* Line 690 of lalr1.cc  */
#line 6619 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 850:

/* Line 690 of lalr1.cc  */
#line 6620 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 851:

/* Line 690 of lalr1.cc  */
#line 6621 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 852:

/* Line 690 of lalr1.cc  */
#line 6622 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 853:

/* Line 690 of lalr1.cc  */
#line 6623 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 854:

/* Line 690 of lalr1.cc  */
#line 6624 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 855:

/* Line 690 of lalr1.cc  */
#line 6625 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 856:

/* Line 690 of lalr1.cc  */
#line 6626 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 857:

/* Line 690 of lalr1.cc  */
#line 6627 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 858:

/* Line 690 of lalr1.cc  */
#line 6628 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 859:

/* Line 690 of lalr1.cc  */
#line 6629 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 860:

/* Line 690 of lalr1.cc  */
#line 6630 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 861:

/* Line 690 of lalr1.cc  */
#line 6631 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 862:

/* Line 690 of lalr1.cc  */
#line 6632 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 863:

/* Line 690 of lalr1.cc  */
#line 6633 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 864:

/* Line 690 of lalr1.cc  */
#line 6634 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 865:

/* Line 690 of lalr1.cc  */
#line 6635 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 866:

/* Line 690 of lalr1.cc  */
#line 6636 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 867:

/* Line 690 of lalr1.cc  */
#line 6637 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 868:

/* Line 690 of lalr1.cc  */
#line 6638 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 869:

/* Line 690 of lalr1.cc  */
#line 6639 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 870:

/* Line 690 of lalr1.cc  */
#line 6640 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 871:

/* Line 690 of lalr1.cc  */
#line 6641 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 872:

/* Line 690 of lalr1.cc  */
#line 6642 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 873:

/* Line 690 of lalr1.cc  */
#line 6643 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 874:

/* Line 690 of lalr1.cc  */
#line 6644 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 875:

/* Line 690 of lalr1.cc  */
#line 6645 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 876:

/* Line 690 of lalr1.cc  */
#line 6646 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 877:

/* Line 690 of lalr1.cc  */
#line 6647 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 878:

/* Line 690 of lalr1.cc  */
#line 6648 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 879:

/* Line 690 of lalr1.cc  */
#line 6649 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 880:

/* Line 690 of lalr1.cc  */
#line 6650 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 881:

/* Line 690 of lalr1.cc  */
#line 6651 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 882:

/* Line 690 of lalr1.cc  */
#line 6652 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 883:

/* Line 690 of lalr1.cc  */
#line 6653 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 884:

/* Line 690 of lalr1.cc  */
#line 6654 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 885:

/* Line 690 of lalr1.cc  */
#line 6655 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 886:

/* Line 690 of lalr1.cc  */
#line 6656 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 887:

/* Line 690 of lalr1.cc  */
#line 6657 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 888:

/* Line 690 of lalr1.cc  */
#line 6658 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 889:

/* Line 690 of lalr1.cc  */
#line 6659 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 890:

/* Line 690 of lalr1.cc  */
#line 6660 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 891:

/* Line 690 of lalr1.cc  */
#line 6661 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 892:

/* Line 690 of lalr1.cc  */
#line 6662 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 893:

/* Line 690 of lalr1.cc  */
#line 6663 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 894:

/* Line 690 of lalr1.cc  */
#line 6664 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 895:

/* Line 690 of lalr1.cc  */
#line 6665 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 896:

/* Line 690 of lalr1.cc  */
#line 6666 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 897:

/* Line 690 of lalr1.cc  */
#line 6667 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 898:

/* Line 690 of lalr1.cc  */
#line 6668 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 899:

/* Line 690 of lalr1.cc  */
#line 6669 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 900:

/* Line 690 of lalr1.cc  */
#line 6670 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 901:

/* Line 690 of lalr1.cc  */
#line 6671 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 902:

/* Line 690 of lalr1.cc  */
#line 6672 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 903:

/* Line 690 of lalr1.cc  */
#line 6673 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 904:

/* Line 690 of lalr1.cc  */
#line 6674 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 905:

/* Line 690 of lalr1.cc  */
#line 6675 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 906:

/* Line 690 of lalr1.cc  */
#line 6676 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 907:

/* Line 690 of lalr1.cc  */
#line 6677 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 908:

/* Line 690 of lalr1.cc  */
#line 6678 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 909:

/* Line 690 of lalr1.cc  */
#line 6679 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 910:

/* Line 690 of lalr1.cc  */
#line 6680 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 911:

/* Line 690 of lalr1.cc  */
#line 6681 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 912:

/* Line 690 of lalr1.cc  */
#line 6682 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 913:

/* Line 690 of lalr1.cc  */
#line 6683 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 914:

/* Line 690 of lalr1.cc  */
#line 6684 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 915:

/* Line 690 of lalr1.cc  */
#line 6685 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraphs"))); }
    break;

  case 916:

/* Line 690 of lalr1.cc  */
#line 6686 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 917:

/* Line 690 of lalr1.cc  */
#line 6687 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 918:

/* Line 690 of lalr1.cc  */
#line 6688 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 919:

/* Line 690 of lalr1.cc  */
#line 6689 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 920:

/* Line 690 of lalr1.cc  */
#line 6690 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 921:

/* Line 690 of lalr1.cc  */
#line 6691 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 922:

/* Line 690 of lalr1.cc  */
#line 6692 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 923:

/* Line 690 of lalr1.cc  */
#line 6693 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 924:

/* Line 690 of lalr1.cc  */
#line 6694 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 925:

/* Line 690 of lalr1.cc  */
#line 6695 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 926:

/* Line 690 of lalr1.cc  */
#line 6696 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 927:

/* Line 690 of lalr1.cc  */
#line 6697 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 928:

/* Line 690 of lalr1.cc  */
#line 6698 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 929:

/* Line 690 of lalr1.cc  */
#line 6699 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 930:

/* Line 690 of lalr1.cc  */
#line 6700 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 931:

/* Line 690 of lalr1.cc  */
#line 6701 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 932:

/* Line 690 of lalr1.cc  */
#line 6702 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 933:

/* Line 690 of lalr1.cc  */
#line 6703 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 934:

/* Line 690 of lalr1.cc  */
#line 6704 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 935:

/* Line 690 of lalr1.cc  */
#line 6705 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("local"))); }
    break;

  case 936:

/* Line 690 of lalr1.cc  */
#line 6706 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 937:

/* Line 690 of lalr1.cc  */
#line 6707 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 938:

/* Line 690 of lalr1.cc  */
#line 6708 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 939:

/* Line 690 of lalr1.cc  */
#line 6709 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 940:

/* Line 690 of lalr1.cc  */
#line 6710 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 941:

/* Line 690 of lalr1.cc  */
#line 6711 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 942:

/* Line 690 of lalr1.cc  */
#line 6712 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eval"))); }
    break;

  case 943:

/* Line 690 of lalr1.cc  */
#line 6713 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 944:

/* Line 690 of lalr1.cc  */
#line 6714 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 945:

/* Line 690 of lalr1.cc  */
#line 6715 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 946:

/* Line 690 of lalr1.cc  */
#line 6716 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 947:

/* Line 690 of lalr1.cc  */
#line 6717 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 948:

/* Line 690 of lalr1.cc  */
#line 6718 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 949:

/* Line 690 of lalr1.cc  */
#line 6719 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 950:

/* Line 690 of lalr1.cc  */
#line 6720 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 951:

/* Line 690 of lalr1.cc  */
#line 6721 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 952:

/* Line 690 of lalr1.cc  */
#line 6722 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 953:

/* Line 690 of lalr1.cc  */
#line 6723 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 954:

/* Line 690 of lalr1.cc  */
#line 6724 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 955:

/* Line 690 of lalr1.cc  */
#line 6725 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 956:

/* Line 690 of lalr1.cc  */
#line 6726 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 957:

/* Line 690 of lalr1.cc  */
#line 6727 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 958:

/* Line 690 of lalr1.cc  */
#line 6728 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 959:

/* Line 690 of lalr1.cc  */
#line 6729 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 960:

/* Line 690 of lalr1.cc  */
#line 6730 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 961:

/* Line 690 of lalr1.cc  */
#line 6731 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 962:

/* Line 690 of lalr1.cc  */
#line 6732 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 963:

/* Line 690 of lalr1.cc  */
#line 6733 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 964:

/* Line 690 of lalr1.cc  */
#line 6734 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 965:

/* Line 690 of lalr1.cc  */
#line 6735 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 966:

/* Line 690 of lalr1.cc  */
#line 6736 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 967:

/* Line 690 of lalr1.cc  */
#line 6737 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 968:

/* Line 690 of lalr1.cc  */
#line 6738 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 969:

/* Line 690 of lalr1.cc  */
#line 6739 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 970:

/* Line 690 of lalr1.cc  */
#line 6740 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 971:

/* Line 690 of lalr1.cc  */
#line 6741 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 972:

/* Line 690 of lalr1.cc  */
#line 6742 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 973:

/* Line 690 of lalr1.cc  */
#line 6743 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 974:

/* Line 690 of lalr1.cc  */
#line 6744 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 975:

/* Line 690 of lalr1.cc  */
#line 6745 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 976:

/* Line 690 of lalr1.cc  */
#line 6746 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 977:

/* Line 690 of lalr1.cc  */
#line 6747 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 978:

/* Line 690 of lalr1.cc  */
#line 6748 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 979:

/* Line 690 of lalr1.cc  */
#line 6749 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 980:

/* Line 690 of lalr1.cc  */
#line 6750 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 981:

/* Line 690 of lalr1.cc  */
#line 6751 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 982:

/* Line 690 of lalr1.cc  */
#line 6752 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 983:

/* Line 690 of lalr1.cc  */
#line 6753 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 984:

/* Line 690 of lalr1.cc  */
#line 6754 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 985:

/* Line 690 of lalr1.cc  */
#line 6755 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 986:

/* Line 690 of lalr1.cc  */
#line 6756 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 987:

/* Line 690 of lalr1.cc  */
#line 6757 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 988:

/* Line 690 of lalr1.cc  */
#line 6758 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 989:

/* Line 690 of lalr1.cc  */
#line 6764 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    {
          // EQName's namespace URI value is whitespace normalized according to the rules for the xs:anyURI type
          std::string uri = "\"" + SYMTAB((yysemantic_stack_[(3) - (1)].sval)) + "\"";
          std::string eqname = SYMTAB(driver.symtab.put_uri(uri.c_str(), uri.size())) + ":" + SYMTAB((yysemantic_stack_[(3) - (3)].sval));
          (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT(eqname.c_str())), true);
        }
    break;

  case 990:

/* Line 690 of lalr1.cc  */
#line 6770 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;



/* Line 690 of lalr1.cc  */
#line 11983 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1449;
  const short int
  xquery_parser::yypact_[] =
  {
      3220, -1449, -1449, -1449,  4711,  4711,  4711, -1449, -1449,    -4,
      18,   238,   875,    29, -1449, -1449, -1449,   554, -1449, -1449,
   -1449,   231,   337,   651, -1449,   312,   428,   497,   116, -1449,
     -35, -1449, -1449, -1449, -1449, -1449, -1449,   707, -1449,   547,
     566, -1449, -1449, -1449, -1449,   553, -1449,   718, -1449,   604,
     611, -1449,   214, -1449, -1449, -1449, -1449, -1449, -1449, -1449,
   -1449, -1449, -1449, -1449, -1449, -1449,   683,   739, -1449, -1449,
   -1449, -1449,   491,  9181, -1449, -1449, -1449,   742, -1449, -1449,
   -1449,   752, -1449,   762,   766, -1449, -1449, 12921, -1449, -1449,
   -1449, -1449, -1449, -1449, -1449, -1449,   786, -1449, -1449,   793,
     806, -1449, -1449, -1449, -1449, -1449, -1449, -1449,  3519,  6499,
   12921, -1449, -1449, -1449, -1449, -1449, -1449, -1449,   777, -1449,
   -1449,   810, 10065, -1449, 10356,   815,   819, -1449, -1449, -1449,
     826, -1449,  8883, -1449, -1449, -1449, -1449, -1449, -1449,   813,
   -1449, -1449, -1449, -1449, -1449, -1449, -1449, -1449,    45,   745,
   -1449, -1449, -1449, -1449, -1449, -1449, -1449, -1449,   115,   808,
     549, -1449,   747,   -69, -1449, -1449, -1449, -1449, -1449, -1449,
     851, -1449,   112,   734,   735,   736, -1449, -1449,   821,   827,
   -1449, -1449, -1449, -1449, -1449, -1449, -1449, -1449, -1449, -1449,
   -1449, -1449, -1449, -1449, -1449, -1449, -1449, -1449, -1449, -1449,
   -1449, -1449, -1449, -1449, -1449, -1449, -1449, -1449, -1449, -1449,
   -1449, -1449, -1449, -1449, -1449, -1449, -1449, -1449, -1449, -1449,
   -1449, -1449, -1449, -1449, -1449, -1449, -1449, -1449, -1449, -1449,
   -1449, -1449, -1449, -1449, -1449, -1449, -1449, -1449, -1449, -1449,
   -1449, -1449, -1449,  5009,   978, -1449,  5307, -1449, -1449,   660,
      80, -1449, -1449, -1449, -1449, -1449, -1449, -1449, -1449, -1449,
   -1449, -1449, -1449, -1449, -1449,    83, -1449, -1449, -1449, -1449,
   -1449, -1449,   307, -1449, -1449, -1449, -1449, -1449, -1449, -1449,
   -1449,  4711, -1449, -1449, -1449, -1449,     4, -1449, -1449, -1449,
   -1449, -1449, -1449, -1449, -1449,   876, -1449,   792, -1449, -1449,
   -1449,   595, -1449, -1449, -1449, -1449, -1449, -1449, -1449, -1449,
     817,   892, -1449,  1075,   740,   -10,   495,   318,   594, -1449,
     939,   794,   893,   894,  7691, -1449, -1449, -1449,    -9, -1449,
   -1449,  8883, -1449,   717, -1449,   843,  9181, -1449,   843,  9181,
   -1449, -1449, -1449,   726, -1449, -1449, -1449, -1449, -1449, -1449,
   -1449, -1449, -1449, -1449, -1449, -1449, -1449, -1449, -1449, -1449,
   -1449, -1449, -1449, -1449, -1449, -1449, -1449, -1449, -1449, -1449,
   -1449, -1449, -1449, -1449, -1449, -1449, -1449, -1449, -1449, -1449,
   -1449, -1449, -1449, -1449, -1449, -1449,   877,   855,   849, -1449,
   -1449, -1449, -1449, -1449,   822, -1449,  4711,   828,   835,   277,
     277,   995,   573,   576,   246, 13206, 12921,   488,   979, 12921,
     878,   909,   319, 10065, -1449, -1449,   705,   618,   785, 12921,
   -1449, -1449, -1449, -1449, -1449,   743, 12921,   744,   748,   622,
     728,   686,   298, -1449, -1449, -1449,  1069, -1449, 10065,  4711,
     846,  4711,    59,  7989, 10926,   750,   753, 12921,   920,   228,
     887,  7989,  1043,    57,   101, 12921,   929,   906,   942, -1449,
    7989,  9772, 12921, 12921, 12921,  4711,   864,  7989,  7989, 12921,
    4711,   899,   901, -1449, -1449, -1449,  7989, 11211, -1449,   900,
   -1449,   902, -1449, -1449, -1449, -1449,   904, -1449,   907, -1449,
   -1449, -1449, -1449, -1449,   908, -1449, -1449, -1449, -1449, -1449,
   -1449, -1449, -1449, -1449, -1449, -1449, -1449, -1449, -1449, -1449,
   -1449, -1449, -1449, -1449, -1449, -1449, -1449, -1449, -1449, -1449,
   -1449, -1449, -1449, 12921, -1449, -1449, -1449, -1449, -1449, -1449,
   -1449, -1449, -1449, -1449, -1449, -1449,   913, 12921, -1449, -1449,
   -1449,   873,  3817,   910,   912,   914, 12921,  4711, -1449,   918,
      23, -1449,   631,  1026,  7989, -1449, -1449,    70, -1449, -1449,
   -1449,  1047, -1449, -1449, -1449, -1449,  7989,   859, -1449,  1048,
    7989,  7989,   890,  7989,  7989,  7989,  7989,   854, 12921,   752,
     315,   895,   897,  7989,  7989,  3519,   845, -1449, -1449, -1449,
   -1449,   875,   116,    84,    86,  1084,  5605,  5605,  5903,  5903,
     752, -1449, -1449,   876,   752, -1449,  7989, -1449,   974,   312,
     -35,   925,   926,   927,  4711,  7989, -1449, -1449, -1449, -1449,
   -1449, -1449, -1449, -1449,  8287,  8287,  8287, -1449,  8287,  8287,
   -1449,  8287, -1449,  8287, -1449, -1449, -1449, -1449, -1449, -1449,
   -1449,  8287,  8287,  1027,  8287,  8287,  8287,  8287,  8287,  8287,
    8287,  8287,  8287,  8287,  8287,   868,  1005,  1006,  1007, -1449,
   -1449, -1449,  6797, -1449, -1449,  8883,  8883,  7989,   843, -1449,
   -1449,   843, -1449,  7095,   843, 10065,   954,  7393, -1449, -1449,
   -1449, -1449,    28, -1449,    46, -1449, -1449, -1449, -1449, -1449,
     998,   999,   428,  1077, -1449, -1449, 13206,   811,   509, 12921,
     949,   950,   811,   995,   985,   981, -1449, -1449, -1449, -1449,
   -1449,   125,   869,    20, -1449,   820, -1449, -1449, -1449, -1449,
   12921,   972,  7989,  1000, -1449, 12921, 12921, -1449,   984,   933,
    4711, -1449,   936,   902,   566, -1449,   934,   935,   253, -1449,
      91,   188, -1449, -1449,  1016, -1449,    24, 12921,    15, 12921,
    1030,   205, -1449,  4711, -1449,   229, -1449, 10065,  1029,  1081,
   10065,   995,  1031,    48, 12921,  7989,   -35,   265,   943, -1449,
     944,   945,   946,     7, -1449,    38,   951, -1449,   244,   249,
     976, -1449,   955,  4711,  4711,   289, -1449,   251,   257,   278,
    7989,    13, -1449, -1449,  7989,  7989,  7989, -1449,  7989, -1449,
    7989, 12921,  1026, -1449,   -12,   293, -1449, -1449, -1449,   300,
   -1449,   323, -1449, -1449, -1449,    85,   131,  1039,   911,   916,
       3, -1449,   996, -1449,   752, -1449, -1449,   952,   276,  4115,
     338,  9479,   845, -1449,   660,   695,  1110,  1110, -1449, -1449,
      90, -1449, -1449,    94, -1449,   720, -1449, -1449, -1449, -1449,
   -1449, -1449, -1449, 12921,   975,  7989,  1028, -1449, -1449, -1449,
     892, -1449, -1449, -1449, -1449, -1449,  8287, -1449, -1449, -1449,
      51,   495,   495,     6,   318,   318,   318,   318,   594,   594,
   -1449, -1449, 12351, 12351, 12921, 12921, -1449,   352, -1449, -1449,
      49, -1449, -1449, -1449,   281, -1449, -1449, -1449,   316,   277,
   -1449, -1449,   584,   588,   515, -1449,   428, -1449, -1449, -1449,
   -1449, -1449, -1449, -1449, -1449, -1449, -1449,   811, -1449,  1017,
   12636,  1008,  7989, -1449, -1449, -1449,  1053,   995,   995,   811,
   -1449,   807,   995,   628, 12921,   561,   574,  1122, -1449, -1449,
     870,    41, -1449, -1449, -1449, -1449, -1449, -1449, -1449, -1449,
   -1449, -1449, -1449,   125,   443,   647, -1449,   928,   541,  7989,
   -1449, 12921,    47,   858,   995, -1449, -1449, -1449, -1449,  1014,
   12921, -1449, 12921, -1449,  1035,  1032, 12351,  1040,  7989,   -46,
    1013,    32,   440,   919, -1449, -1449,   615,    15,  1053, 12351,
    1057,  1066,   992,   983,  1049,   995,  1022,  1051,  1088,   995,
    7989,   -53, -1449, -1449, -1449,  1036, -1449, -1449, -1449, -1449,
    1073,  7989,  7989,  1045, -1449,  1093,  1094,  4711, -1449,  1011,
    1012,  1050, 12921, -1449, 12921, -1449,  7989,  1059,  1015,  7989,
     325,   336,   350,  1166, -1449,   159, -1449,   506, -1449, -1449,
    1176, -1449,   654,  7989,  7989,  7989,   698,  7989,  7989,  7989,
    7989,  7989,  7989,  1090,  7989,  7989, -1449, -1449,  6201,  1054,
    1055,  1056,  1060,   792,   648,   964, -1449,   469, -1449,    96,
     108,   720,  5903,  5903,  5903,  1137, -1449,  7989,   645,  1112,
   -1449, 12921,  1113, -1449, -1449,  7989,    51,    63,    -8, -1449,
     938,    66,   966,   967, -1449, -1449,   785, -1449,   961,   429,
    1078,  1079, 12636,  1083, -1449,   505, -1449, -1449, -1449, -1449,
   -1449, -1449, -1449, -1449, -1449,  1085, -1449, -1449, -1449,  7989,
   -1449, -1449, -1449, -1449, -1449, -1449, -1449, -1449, -1449,   597,
   -1449,  1201,   704, -1449, -1449, -1449, -1449, -1449, -1449, -1449,
   -1449, -1449,   956, -1449, -1449,  1210, -1449, -1449, -1449, -1449,
   -1449,   479,  1211, -1449,   646, -1449, -1449, -1449,   900,   337,
     904,   547,   907,   908,   808,  1009,   505,  1020,  1023,  8585,
     969,   937, -1449,  1053,   443, -1449,  1025,  1058,  4711,  1070,
    1071,  1109,  1072,  1074, 12921,   463, -1449, 12921, -1449,  7989,
    1115,  7989,  1133,  7989,   -22,  1117,  7989,  1118, -1449,  1148,
    1149,  7989, 12921,   697,  1190, -1449, -1449, -1449, -1449, -1449,
   -1449, 12351, -1449,  4711,   995,  1165, -1449, -1449, -1449,   995,
    1165, -1449,  7989,  1131,  4711, 12921, -1449, -1449,  7989,  7989,
     677, -1449,    16,   682, -1449, 11496,   708, -1449,   712, -1449,
    1092, -1449, -1449,  4711,  1087,  1096, -1449,  7989, -1449, -1449,
    1097,  1093,  1184, -1449,  1153, -1449,   617, -1449, -1449,  1282,
   -1449, -1449,  4711, 12921, -1449,   787, -1449, -1449, -1449,  1105,
    1065,  1076, -1449, -1449, -1449,  1082,  1086, -1449, -1449, -1449,
   -1449, -1449,  1068, 12921,  1116, -1449, -1449,  7989,  7989,  7989,
    4413,  6201,  9479,   964, -1449,  1183,  9479, -1449,  1110,   147,
   -1449, -1449, -1449,  1112, -1449,   995, -1449,   818, -1449,   555,
    1199, -1449,  7989,  1203,  1028,   363,  1120, -1449,    51,  1061,
   -1449, -1449,   -89, -1449,   149,    35,  1067,    51,   149,  8287,
   -1449,    61, -1449, -1449, -1449, -1449, -1449, -1449,    51,  1163,
    1033,   869,    35, -1449, -1449,  1034,  1234, -1449, -1449, -1449,
   10641,  1132,  1135,  1136, -1449, -1449, -1449, -1449, -1449, -1449,
   -1449, -1449, -1449, -1449, -1449, -1449,  1294,   195,  1295,   195,
    1062,  1219, -1449, -1449, -1449, -1449,  1157, 12921,  1080, -1449,
    1009,  8585, -1449,  1144, -1449, -1449, -1449, -1449, -1449, -1449,
    7989,  1182, -1449, -1449,  7989, -1449,   498, -1449,  7989,  1185,
    7989, -1449,  7989, 12921, 12921, -1449,   102, -1449,  7989, -1449,
    1208,  1209,  1239,   995,  1165, -1449,  7989,  1154, -1449, -1449,
   -1449,  1155, -1449,    22,  7989,  4711,  1156,    36, -1449, 12921,
    1159, 11781,   328, -1449, 12066,  1160, -1449, -1449,  1164, -1449,
   -1449, -1449,  7989,   713,  1166, 12921,   867, -1449,  1167,  1166,
   12921, -1449, -1449,  7989,  7989,  7989,  7989,  7989, -1449,  7989,
     355,   365,   368,   477, -1449, 12921, -1449, -1449, -1449, -1449,
    1199, -1449, -1449, -1449,   995, -1449, -1449, -1449, -1449, -1449,
    1168,  8287, -1449, -1449, -1449, -1449, -1449,    74,  8287,  8287,
     452, -1449,   966, -1449,   153, -1449,   967,    51,  1186, -1449,
   -1449,  1089, -1449, -1449, -1449, -1449,  1245,  1162, -1449,   371,
   -1449, -1449, -1449, -1449,   478,   478, -1449,   195, -1449, -1449,
     398, -1449,  1313,    35,  1250,  1174,  8585,   -48,  1091, -1449,
    1180, -1449, -1449,  7989, -1449,  7989,  1206, -1449,  7989, -1449,
   -1449, -1449,  1300, -1449, -1449,  6201,  7989,   995, -1449, -1449,
   -1449,  7989,  7989, -1449, -1449, -1449,  6201,  6201,  1272,  4711,
   12921,  1187, 12921,  7989, 12921,  1188,  6201, -1449,   333,    30,
    1166, 12921, -1449,  1172,  1166, -1449, -1449, -1449, -1449, -1449,
   -1449,  1173,  1093,  1094,  7989,  1254, -1449,   404, -1449, -1449,
   -1449,   318,  8287,  8287,     6,   511, -1449, -1449, -1449, -1449,
   -1449, -1449,  7989, -1449, 12351, -1449, 12351,  1281, -1449, -1449,
   -1449,  1347, -1449, -1449, -1449,  1114,  1273, -1449, -1449,  1274,
   -1449,   741, 12921,  1265,  1169, 12921,  8585, -1449, -1449,  7989,
   -1449,  1266, -1449, -1449,  1165, -1449, -1449, 12351, -1449, -1449,
    1291,  7989,  1202, -1449,  1292,  6201, -1449, 12921,   199,   539,
   -1449,  1193,  1166, -1449,  1194,  6201,   714,   378, 12921,  1276,
    1060,     6,     6,  8287,   395, -1449, -1449, 12351, -1449, -1449,
    1250,  8585, -1449,  1199,  1099, 12921,  1277,  1175,  1274, -1449,
   12921,  1205, 12351,  4711, 12351,  1212, -1449, -1449,  1298,   288,
   -1449, -1449, -1449, -1449,  1213,   592, -1449, -1449, -1449,  1214,
   -1449,  1279, -1449,   433, 12921, -1449,     6, -1449, -1449, -1449,
   -1449, -1449,  7989,  1100, 12921,  1283, -1449,  4711,  1220, -1449,
   -1449,  1221,  7989, -1449, -1449, -1449, -1449, -1449, -1449, -1449,
   12921,  1290,  1256,   437, -1449,  1119,  1111, 12921, -1449, -1449,
    7989,  6201,  1228, 12921, -1449,  1299,  1060,  1121,  7989,  1123,
    6201,   439, 12921, -1449,  8585, -1449,  8585,  1301,  1256,  1231,
   -1449,  1222, 12921, -1449,  1060,  1134,  1235, -1449, 12921,  1256,
    1200, -1449,  1305, 12921,  1124,  8585, -1449
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
       181,   465,   466,   467,   184,   184,   184,   790,   990,   116,
     118,   615,   881,   890,   831,   795,   793,   775,   882,   885,
     838,   799,   776,   777,   942,   830,   891,   779,   888,   860,
     840,   815,   835,   836,   886,   883,   834,   781,   889,   782,
     783,   930,   944,   929,   832,   851,   845,   784,   833,   786,
     785,   931,   869,   837,   812,   954,   955,   956,   957,   958,
     959,   960,   961,   962,   963,   964,   978,   985,   859,   855,
     846,   826,   774,     0,   854,   862,   870,   979,   850,   487,
     827,   828,   884,   980,   986,   847,   864,     0,   493,   454,
     489,   857,   792,   848,   849,   877,   852,   868,   876,   984,
     987,   798,   839,   879,   488,   867,   872,   778,     0,     0,
       0,   402,   865,   875,   880,   878,   858,   844,   932,   842,
     843,   981,     0,   401,     0,   982,   988,   873,   829,   853,
     983,   432,     0,   464,   874,   856,   863,   871,   866,   933,
     820,   825,   824,   823,   822,   821,   787,   841,     0,   791,
     887,   813,   921,   920,   922,   797,   796,   816,   927,   780,
     919,   924,   925,   916,   819,   861,   918,   928,   926,   917,
     817,   923,   935,   938,   939,   936,   937,   934,   788,   940,
     941,   943,   907,   906,   893,   811,   804,   900,   896,   814,
     810,   908,   909,   800,   801,   794,   803,   905,   904,   901,
     897,   914,   915,   913,   903,   899,   892,   802,   912,   911,
     806,   808,   807,   898,   902,   894,   809,   895,   805,   910,
     965,   966,   967,   968,   969,   970,   946,   947,   945,   951,
     952,   953,   948,   949,   950,   818,   971,   972,   973,   974,
     975,   976,   977,   181,     0,     2,   181,     5,     7,    19,
       0,    24,    27,    32,    33,    34,    35,    36,    37,    38,
      28,    54,    55,    29,    30,     0,    72,    75,    76,    31,
      77,    78,     0,   114,    79,    80,    81,    82,    14,   178,
     179,   180,   187,   189,   484,   190,     0,   191,   192,   193,
     194,   195,   196,   197,   200,   185,   231,   238,   233,   260,
     266,     0,   258,   259,   240,   234,   199,   235,   198,   236,
     239,   357,   359,   361,   371,   375,   377,   380,   385,   388,
     391,   393,   395,   397,     0,   399,   405,   407,     0,   423,
     406,   428,   431,   433,   436,   438,     0,   443,   440,     0,
     451,   461,   463,   437,   468,   475,   485,   476,   477,   478,
     481,   482,   479,   480,   500,   502,   503,   504,   501,   549,
     550,   551,   552,   553,   554,   460,   589,   581,   588,   587,
     586,   583,   585,   582,   584,   486,   483,   616,   617,    39,
     241,   242,   244,   243,   245,   237,     0,   462,   773,   789,
     881,   890,   888,   791,     0,   182,   183,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   144,   145,     0,     0,     0,     0,
     140,   141,   142,   143,   150,     0,     0,     0,     0,     0,
       0,     0,     0,   122,   124,   125,     0,   138,     0,     0,
       0,   184,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   285,   286,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   456,   459,   446,     0,     0,   770,   775,
     799,   777,   830,   891,   779,   840,   781,   851,   784,   786,
     785,   869,   978,   985,   774,   979,   828,   980,   986,   852,
     984,   987,   932,   981,   982,   988,   983,   933,   927,   919,
     925,   916,   817,   935,   938,   939,   936,   788,   940,   452,
     462,   773,   444,     0,   207,   445,   448,   775,   776,   777,
     781,   782,   783,   784,   774,   780,   490,     0,   450,   449,
     202,     0,     0,   779,   786,   785,     0,   184,   491,   940,
       0,   238,     0,   516,     0,   455,   771,     0,   772,   426,
     427,     0,   458,   457,   447,   430,     0,     0,   545,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     3,     1,     6,
       8,     0,     0,     0,     0,     0,   181,   181,   181,   181,
       0,   115,   188,   186,     0,   205,     0,   216,     0,     0,
       0,     0,     0,     0,     0,     0,   221,   246,   265,   261,
     267,   262,   264,   263,     0,     0,     0,   416,     0,     0,
     414,     0,   366,     0,   415,   408,   413,   412,   411,   410,
     409,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   404,
     403,   400,     0,   424,   429,     0,     0,     0,   439,   472,
     442,   441,   453,     0,   469,     0,     0,     0,   556,   558,
     562,   615,     0,   120,     0,    43,    40,    41,    44,    45,
       0,     0,     0,     0,    46,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   626,   627,   628,   147,
     146,     0,    99,   154,   151,     0,   153,   152,   149,   148,
       0,   108,     0,     0,   123,     0,     0,   139,     0,     0,
       0,   595,     0,     0,     0,   591,     0,     0,     0,   605,
       0,     0,   248,   249,   268,   269,     0,     0,     0,     0,
     130,     0,   134,   184,   619,     0,    56,     0,    65,     0,
       0,     0,    57,     0,     0,     0,     0,     0,   770,   596,
       0,     0,     0,     0,   330,     0,     0,   594,     0,     0,
       0,   613,     0,     0,     0,     0,   599,     0,     0,   211,
       0,     0,   203,   201,     0,     0,     0,   490,     0,   492,
       0,   517,   516,   513,     0,     0,   547,   546,   425,     0,
     544,     0,   639,   640,   590,     0,     0,     0,     0,     0,
       0,   645,     0,   208,     0,   219,   220,     0,     0,     0,
       0,     0,   224,   225,    20,     0,    21,     0,     4,    25,
       0,    11,    26,     0,    15,   881,    73,    12,    74,    16,
     209,   206,   232,     0,     0,     0,     0,   222,   247,   303,
     358,   360,   364,   370,   369,   368,     0,   365,   362,   363,
       0,   379,   378,   376,   382,   383,   384,   381,   386,   387,
     390,   389,     0,     0,     0,     0,   421,     0,   434,   435,
       0,   473,   470,   498,     0,   989,   618,   496,     0,     0,
     117,   119,     0,     0,     0,    98,     0,    88,    90,    91,
      92,    93,    95,    96,    97,    89,    94,    84,    85,     0,
       0,   104,     0,   100,   102,   103,   110,     0,     0,    83,
      42,     0,     0,     0,     0,     0,     0,     0,   720,   725,
       0,     0,   721,   755,   708,   710,   711,   712,   714,   716,
     715,   713,   717,     0,     0,     0,   155,     0,     0,     0,
     107,     0,   158,     0,     0,   561,   555,   592,   593,     0,
       0,   609,     0,   606,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   250,   251,     0,   256,   136,     0,
       0,   131,     0,     0,     0,     0,     0,     0,    58,     0,
       0,     0,   284,   290,   287,     0,   598,   597,   604,   612,
       0,     0,     0,     0,   560,     0,     0,     0,   417,     0,
       0,     0,     0,   602,     0,   600,     0,   212,     0,     0,
       0,     0,     0,   516,   514,     0,   505,     0,   494,   495,
       0,     9,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   210,   217,     0,   779,
     786,   785,   940,     0,     0,     0,   656,     0,   226,     0,
       0,     0,   181,   181,   181,     0,   257,     0,   314,   310,
     312,     0,   304,   305,   367,     0,     0,     0,     0,   686,
     373,   659,   663,   665,   667,   669,   672,   679,   680,   688,
     891,   778,     0,   787,   392,   567,   573,   574,   576,   620,
     621,   577,   580,   394,   396,   564,   398,   422,   474,     0,
     471,   497,   121,    52,    53,    50,    51,   127,   126,     0,
      86,     0,     0,   105,   106,   111,    70,    71,    48,    49,
      69,   726,     0,   729,   756,     0,   719,   718,   723,   722,
     754,     0,     0,   731,     0,   727,   730,   709,     0,     0,
       0,     0,     0,     0,     0,   156,   162,     0,     0,     0,
       0,     0,   109,   112,     0,   159,     0,     0,   184,     0,
       0,   613,     0,     0,     0,     0,   566,     0,   271,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   252,     0,
       0,     0,     0,   297,     0,   294,   299,   255,   137,   132,
     135,     0,   204,     0,     0,    67,    61,    64,    63,     0,
      59,   288,     0,     0,   184,     0,   328,   332,     0,     0,
       0,   335,     0,     0,   341,     0,     0,   348,     0,   352,
       0,   419,   418,   184,     0,     0,   213,     0,   215,   329,
       0,     0,     0,   517,     0,   506,     0,   540,   537,     0,
     541,   542,     0,     0,   536,     0,   511,   539,   538,     0,
       0,     0,   632,   633,   629,     0,     0,   637,   638,   634,
     643,   641,     0,     0,     0,   647,   218,     0,     0,     0,
       0,     0,     0,   648,   649,     0,     0,   227,    22,     0,
      13,    17,    18,   311,   323,     0,   324,     0,   315,   316,
     317,   318,     0,   307,     0,     0,     0,   670,   683,     0,
     372,   374,     0,   702,     0,     0,     0,     0,     0,     0,
     658,   660,   661,   697,   698,   699,   701,   700,     0,     0,
     674,   673,     0,   677,   681,   695,   693,   692,   685,   689,
       0,     0,     0,     0,   570,   572,   571,   568,   565,   499,
     129,   128,    87,   101,   743,   724,     0,   748,     0,   748,
     737,   732,   157,   163,   165,   164,     0,     0,     0,   113,
     160,     0,    23,     0,   610,   611,   614,   607,   608,   270,
       0,     0,   283,   275,     0,   279,     0,   273,     0,     0,
       0,   292,     0,     0,     0,   254,   295,   298,     0,   133,
       0,     0,    66,     0,    60,   289,     0,     0,   331,   333,
     338,     0,   336,     0,     0,     0,     0,     0,   342,     0,
       0,     0,     0,   349,     0,     0,   353,   420,     0,   603,
     601,   214,     0,     0,   516,     0,     0,   548,     0,   516,
       0,   512,    10,     0,     0,     0,     0,     0,   646,     0,
       0,     0,     0,     0,   650,     0,   657,   327,   325,   326,
     319,   320,   321,   313,     0,   308,   306,   687,   678,   684,
       0,     0,   757,   758,   768,   767,   766,     0,     0,     0,
       0,   759,   664,   765,     0,   662,   666,     0,     0,   671,
     675,     0,   696,   691,   694,   690,     0,     0,   578,     0,
     575,   625,   569,   744,     0,     0,   742,   749,   750,   746,
       0,   741,     0,   739,     0,     0,     0,     0,     0,   161,
       0,   557,   272,     0,   281,     0,     0,   277,     0,   280,
     293,   301,   302,   296,   253,     0,     0,     0,    62,   291,
     563,     0,     0,   339,   343,   337,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   559,     0,     0,
     516,     0,   543,     0,   516,   630,   631,   635,   636,   642,
     644,     0,     0,     0,     0,     0,   651,     0,   322,   309,
     682,   769,     0,     0,   761,     0,   707,   706,   705,   704,
     703,   668,     0,   760,     0,   622,     0,     0,   753,   752,
     751,     0,   745,   738,   736,     0,   733,   734,   728,   166,
     168,   170,     0,     0,     0,     0,     0,   276,   274,     0,
     282,     0,   223,   356,    68,   334,   340,     0,   354,   350,
       0,     0,     0,   344,     0,     0,   346,     0,   526,   520,
     515,     0,   516,   507,     0,     0,     0,     0,     0,     0,
       0,   763,   762,     0,     0,   623,   579,     0,   747,   740,
       0,     0,   172,   171,     0,     0,     0,     0,   167,   278,
       0,     0,     0,     0,     0,     0,   534,   528,     0,   527,
     529,   535,   532,   522,     0,   521,   523,   533,   509,     0,
     508,     0,   655,     0,     0,   228,   764,   676,   624,   735,
     169,   173,     0,     0,     0,     0,   300,     0,     0,   347,
     345,     0,     0,   519,   530,   531,   518,   524,   525,   510,
       0,     0,     0,     0,   174,     0,     0,     0,   355,   351,
       0,     0,     0,     0,   652,     0,     0,     0,     0,     0,
       0,     0,     0,   229,     0,   176,     0,     0,     0,     0,
     175,     0,     0,   653,     0,     0,     0,   230,     0,     0,
       0,   654,     0,     0,     0,     0,   177
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1449, -1449,  -223,  1181, -1449,  1189,  1191, -1449,  1178,  -535,
   -1449, -1449, -1449, -1449, -1449, -1449, -1449, -1449, -1449, -1449,
    -955, -1449, -1449, -1449, -1449,  -216,  -575, -1449,   729,  -340,
   -1449, -1449, -1449, -1449, -1449,   302,   517, -1449, -1449,    -3,
    -215,  1041, -1449,  1004, -1449, -1449,  -626, -1449,   442, -1449,
     994, -1449,   266,  -934, -1449,  -187,  -229, -1449,  -544, -1449,
      11,    68,    25,  -271,  -177, -1449,  -837, -1449, -1449,  -521,
   -1449, -1449, -1449, -1449, -1449, -1449, -1449, -1449, -1449, -1449,
     612,   -91,  1490,     0, -1449, -1449, -1449, -1449,   456, -1449,
   -1449,  -282, -1449,     8, -1449, -1449,   261,  -725,  -703, -1449,
   -1449,   681, -1449, -1449,    42,   247, -1449, -1449, -1449,   135,
   -1449, -1449,   374,   140, -1449, -1449,   144, -1260, -1449,   917,
     230, -1449, -1449,   226,  -980, -1449, -1449,   224, -1449, -1449,
   -1205, -1177, -1449,   220, -1449, -1449,   836,   834, -1449,  -530,
   -1449, -1449,  -635,   311,  -609,   310,   313, -1449, -1449, -1449,
   -1449, -1449,  1138, -1449, -1449, -1449, -1449,  -838,  -325, -1118,
   -1449,   -96, -1449, -1449, -1449, -1449, -1449, -1449, -1449,   -17,
    -811, -1449, -1449,   518,   200, -1449,  -374, -1449, -1449, -1449,
   -1449, -1449, -1449, -1449,   784, -1449,  -991, -1449,   207, -1449,
     662,  -795, -1449, -1449, -1449, -1449, -1449,  -230,  -222, -1160,
   -1129, -1449, -1449, -1449, -1449, -1449, -1449, -1449, -1449, -1449,
   -1449,   581,  -741,  -882,   305,  -843, -1449,    67,  -818, -1449,
   -1449, -1449, -1449, -1449, -1449, -1449,  1038,  1042,  -288,   501,
     343, -1449, -1449, -1449, -1449, -1449, -1449, -1449, -1449, -1449,
   -1449, -1449, -1449, -1449, -1449,   192, -1449, -1449,   184, -1043,
     186, -1023, -1449, -1449, -1449,   154,   148,    -7,   400, -1449,
   -1449, -1449, -1449, -1449, -1449, -1449, -1449, -1449, -1449, -1449,
   -1449, -1449,   157, -1449, -1449, -1449,    -2,   389,   538, -1449,
   -1449, -1449, -1449, -1449,   340, -1449, -1449, -1448, -1449, -1449,
   -1449,  -542, -1449,   127, -1449,   -20, -1449, -1449, -1449, -1449,
   -1236, -1449,   170, -1449,  -364,  -368,  1063,   118, -1449
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   244,   837,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
    1215,   761,   262,   263,   264,   265,   266,   267,   917,   918,
     919,   268,   269,   270,   923,   924,   925,   271,   431,   272,
     273,   682,   274,   433,   434,   435,   450,   751,   752,   436,
     437,   275,  1165,   956,   276,  1619,  1620,   277,   278,   279,
     541,   280,   281,   282,   283,   284,   754,   285,   286,   524,
     287,   288,   289,   290,   291,   292,   616,   293,   294,   832,
     833,   295,   296,   551,   298,   617,   448,   986,   987,   299,
     618,   300,   620,   552,   302,   744,   745,  1203,   457,   303,
     458,   459,   748,  1204,  1205,  1206,   621,   622,  1082,  1083,
    1475,   623,  1079,  1080,  1308,  1309,  1310,  1311,   304,   773,
     774,   305,  1230,  1231,  1423,   306,  1233,  1234,   307,   308,
    1236,  1237,  1238,  1239,   309,   310,   311,   312,   866,   313,
    1320,   314,   315,   316,   317,   318,   319,   320,   321,   322,
     323,   324,   325,   641,   642,   326,   327,   328,   329,   330,
     331,   332,   333,   334,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   668,   669,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   894,   353,   354,   355,  1265,   802,
     803,   804,  1650,  1694,  1695,  1688,  1689,  1696,  1690,  1266,
    1267,   356,   357,  1268,   358,   359,   360,   361,   362,   363,
     364,  1114,   981,  1104,  1357,  1105,  1509,  1106,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   780,  1180,
     375,   376,   377,   378,  1108,  1109,  1110,  1111,   379,   380,
     381,   382,   383,   384,   820,   821,   385,  1293,  1294,  1586,
    1067,  1090,  1330,  1331,  1091,  1092,  1093,  1094,  1095,  1340,
    1499,  1500,  1096,  1343,  1097,  1480,  1098,  1099,  1348,  1349,
    1505,  1503,  1332,  1333,  1334,  1335,  1599,   712,   944,   945,
     946,   947,   948,   949,  1155,  1525,  1616,  1156,  1523,  1614,
     950,  1369,  1520,  1516,  1517,  1518,   951,   952,  1336,  1344,
    1490,  1337,  1486,  1321,   386,   557,   387,   388,   389
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int xquery_parser::yytable_ninf_ = -771;
  const short int
  xquery_parser::yytable_[] =
  {
       297,  1113,   586,   663,   297,   297,   297,  1035,   301,   432,
     602,   873,   301,   301,   301,   394,   397,   398,   550,   619,
    1066,   979,  1001,   846,   848,   683,   683,   597,  1175,   396,
     396,   396,  1088,   594,  1013,  1232,   565,   685,   874,   875,
     876,   877,   599,   980,  1220,   705,  1264,  1443,  1027,  1471,
    1472,  1376,   841,   844,   847,   849,   519,   601,   823,  1433,
     975,   839,   842,  1316,  1107,  1107,   904,  1128,  1192,  1622,
     728,   983,   395,   395,   395,   567,  1617,  1132,   806,   850,
     681,   595,   455,   851,   595,   595,   478,   595,  1222,   758,
     762,   595,   681,   770,  1186,   595,   862,   595,   863,   864,
    1189,   865,  1107,   867,   733,  1451,  1501,  1209,   297,  1053,
     604,   868,   869,  1010,   954,  1424,   301,  1036,   976,  1010,
     977,  1424,   734,  1648,  1398,   602,  1482,  1592,   977,   606,
     478,  1487,   976,   542,   899,  1424,  1166,  1152,     9,    10,
     452,  1174,   976,   662,  1318,   401,   402,   644,   403,   404,
     453,   399,   899,  1153,   576,   606,  1199,  1322,  1107,   577,
      79,  1200,  1322,   644,  1483,   645,   407,   124,   124,   580,
     978,  1107,    79,   400,    90,  1623,   395,   454,  1193,  1042,
     933,   645,   934,  1037,  1012,  1135,    90,   646,   438,  1000,
     603,   521,   700,   605,  1011,   701,  1154,   970,   977,   104,
    1029,  1425,  1593,  1085,  1686,   521,  1086,  1552,  1257,   799,
    1588,   104,  1649,   759,   900,  1085,   757,   601,  1086,   456,
    1299,  1557,  1709,   579,   935,  1046,   456,   124,   521,  1323,
     984,  1372,   901,  1118,  1323,   664,  1054,   456,  1254,   124,
     521,  1197,   521,   297,   807,   735,   297,  1208,  1088,  1088,
     456,   301,   703,  1427,   301,   955,  1194,   568,  1624,  1352,
     760,   846,   848,  1530,  1414,  1264,  1433,   413,   985,   596,
     619,   602,   598,   834,  1264,   836,  1190,   971,  1195,  1072,
    1129,   297,   955,  1074,  1107,  1298,  1451,  1615,  1255,   301,
    1488,  1489,  1361,  1686,   972,  1479,   456,  1257,  1223,   839,
     842,  1043,  1044,  1056,   456,   603,   681,   895,   469,  1087,
     644,   990,  1324,  1325,   704,  1326,  1045,  1324,  1325,   670,
    1326,  1260,   672,  1261,     9,    10,   416,  1327,   645,  1409,
    1514,  1687,  1328,     9,    10,   606,  1084,  1328,   570,   930,
     571,     9,    10,   857,  1329,   749,   405,  1047,  1048,  1329,
     606,  1262,   738,  1430,  1256,   606,  1166,  1022,  -770,   606,
     755,  1672,  1049,  1024,   700,   601,   470,   701,   418,   767,
     835,   606,   976,   408,   973,   936,   778,   779,  1656,   445,
     840,   843,   606,   441,   446,   785,    79,  1119,   937,   994,
     938,   991,   997,  1107,  1515,   606,   297,   998,   702,   606,
      90,   939,   940,   941,   301,   942,   606,   943,  1621,   723,
    1260,   690,  1261,  1711,   750,   993,  1484,  1107,   600,  1026,
    1724,  1596,  1119,  1485,   703,   104,   824,   691,  1597,   447,
    1015,   606,  1379,   471,   472,  1016,   969,  1023,  1598,   297,
    1262,   297,   606,  1025,   606,  1562,  1529,   301,  1005,   301,
    1647,   603,   732,  1040,   521,  1264,   606,   521,   606,   602,
    1391,   606,  1058,   805,   730,   297,   396,  1120,  1508,   606,
     297,   606,  1021,   301,   606,   809,  1038,  1606,   301,  1433,
    1088,  1066,  1158,  1039,   606,  1466,   704,  1159,   733,  1088,
     730,  1399,   442,   828,   830,   730,  1089,   846,   848,   846,
    1088,   606,  1121,  1160,  1611,  1161,   734,   729,  1621,   395,
    1659,  1250,  1041,  1563,  1162,  1257,  1258,   651,  1563,  1691,
    1697,  1065,  1251,   692,   521,  1122,   652,   521,  1300,  1301,
    1302,   521,  1107,   776,   976,  1117,  1252,   521,   782,  1731,
    1163,  1581,   297,  1745,   521,  1757,  1477,   297,  1257,  1561,
     301,  1582,  1565,  1621,  1583,   301,   521,  1607,   602,   977,
    1691,  1702,   521,  1136,  1137,   521,  1697,  1692,  1140,   888,
     889,   887,   396,   521,  1366,  1366,   890,  1130,  1707,   521,
     521,   521,   521,   449,  1612,   297,  1196,   521,   432,  1130,
    1660,  1367,  1634,   301,   977,   521,   297,   297,   297,   297,
    1177,  1257,  1427,   920,   301,   301,   301,   301,  1259,  1390,
     829,   647,   475,  1107,   297,   395,  1107,  1073,  1069,  1732,
    1692,  1290,   301,  1746,  1295,  1758,  1257,  1258,  1260,  1584,
    1261,  1216,  1585,  1368,  1368,  1216,  1760,   608,  1761,   603,
     648,   521,   609,   476,  1535,   921,   477,   610,  1354,  1569,
     922,  1127,   451,   649,  1573,   521,   694,  1776,  1262,  1088,
    1305,  1260,   110,  1261,   521,   611,  1164,   753,   644,  1199,
     464,  1536,  1693,   608,  1200,  1345,  1346,  1296,   609,   122,
    1355,  1307,  1179,   610,  1182,  1296,   645,   650,   695,  1744,
     608,  1262,  1201,   591,  1494,   609,   521,  1356,  1347,  1263,
     610,   611,   462,  1030,  1031,  1032,   439,   830,  1663,   440,
     592,   977,  1089,  1089,  1260,  1763,  1261,   148,   611,  1259,
    1596,   463,  1665,   846,  1666,  1727,  1771,  1597,  1070,   653,
     297,  1123,  1202,  1360,  1244,  1125,  1245,  1598,   301,  1260,
    1304,  1261,  1152,   654,  1262,   592,     9,    10,  1124,   753,
    1305,  1199,  1126,   297,   686,  1681,  1200,   688,  1153,   467,
    1306,   301,   612,   663,   992,   613,   468,   687,   405,  1262,
     689,  1307,   573,   110,   574,  1651,  1229,   406,   396,  1654,
     614,  1229,   619,   297,   297,  1708,  1107,  1286,  1107,  1421,
     122,   301,   301,   521,  1426,   408,  1257,  1258,   612,   409,
    1718,   613,  1721,   443,   473,   615,   444,  1431,   730,   730,
    1445,  1434,  1431,  1431,   906,   612,   800,   521,   613,  1107,
    1432,   395,   721,  1146,  1435,  1568,  1701,   722,   148,  1063,
     410,   411,  1075,  1291,  1147,   976,  1148,  1064,   521,  1170,
     921,   615,   432,   521,   521,   922,  1305,  1149,  1171,  1107,
    1412,  1019,  1020,  1594,  1595,  1216,   671,  1699,   615,   460,
     474,   674,   461,   522,  1107,   521,  1107,   521,   891,   523,
     465,   891,  1591,   466,   891,   521,  1257,  1258,   521,   667,
    1673,   673,   521,   525,  1270,   586,  1271,   526,   414,  1259,
    1297,   907,   908,   909,   910,   911,   912,   913,   914,   915,
     916,     9,    10,   537,  1141,  1142,  1143,   665,   666,  1260,
    1144,  1261,   401,   402,   538,   403,   404,   709,   710,   521,
     415,   718,   719,   405,   706,   707,   708,   539,  1275,   554,
    1276,   555,   406,   407,  1138,  1139,   562,  1167,  1168,  1262,
     563,  1467,  1410,   110,  1089,  1468,  1469,   564,   417,   521,
     408,  1115,  1115,  1089,   409,   871,   872,  1661,  1662,   569,
     122,   878,   879,   572,  1089,   566,   880,   881,   578,  1259,
     575,   521,  1608,  1609,   581,   582,   584,   583,   588,   585,
    1450,   607,   606,   624,   625,   410,   411,   412,   643,  1260,
     655,  1261,   656,   657,  1315,   658,   667,   675,   148,   676,
     521,   521,   521,   521,   677,   678,   419,   420,   421,   422,
     423,   679,   424,   425,   426,   427,   428,   297,   680,  1262,
     857,   429,   430,   110,   478,   301,   699,   696,  1706,   698,
     711,   720,   731,   742,   413,   714,   743,   747,   521,   753,
     122,   716,   730,   414,   756,   717,   764,   765,   766,  1548,
     777,   783,   521,   784,   790,   440,   792,   444,  1063,   461,
    1571,   801,   466,   477,   808,   794,  1064,   795,   432,   796,
     798,   810,   297,   297,   297,   415,   814,   811,   148,   521,
     301,   301,   301,   819,   825,  1240,   826,   838,   521,   831,
     521,   853,   854,   416,   521,   855,   856,   882,   870,   883,
     884,   885,   896,   417,   902,   903,   905,   521,   927,   928,
    1589,   931,   932,   959,   953,   964,   965,   961,   957,   966,
     967,   968,   974,  1089,   989,   995,   996,   999,  1017,  1006,
    1007,  1008,  1009,  1050,  1014,   418,   520,  1055,  1018,  1052,
     521,  1057,   521,  1071,  1077,  1081,  1051,   976,  1131,   922,
     536,  1150,  1184,  1169,  1554,  1151,  1176,  1187,  1185,  1191,
    1211,   419,   420,   421,   422,   423,  1178,   424,   425,   426,
     427,   428,  1198,   553,   749,  1212,   429,   430,   297,  1213,
    1214,  1217,  1218,  1216,  1219,   558,   301,   561,  1224,  1383,
    1225,  1228,  1229,  1235,  1241,  1242,  1460,  1461,  1462,   521,
    1247,  1253,  1243,   396,  1248,  1269,   626,  1283,  1292,  1287,
    1288,  1289,  1290,   297,   627,   628,   702,   629,  1312,  1314,
     521,   301,  1319,  1338,   297,   630,  1339,  1342,  1358,   631,
     681,   632,   301,  1350,  1351,  1417,   633,   414,  1353,  1365,
    1370,  1364,  1378,   297,   955,  1374,   395,  1382,  1375,   396,
    1381,   301,  1386,   634,  1438,  1377,  1384,  1385,  1387,  1396,
    1388,  1394,   297,  1400,  1402,  1403,  1404,  1408,   396,   415,
     301,  1413,  1416,  1439,  1632,  1437,   635,   636,   637,   638,
     639,   640,  1440,  1431,  1444,  1636,  1554,   730,  1638,  1447,
    1063,  1063,   395,  1442,  1452,  1646,  1453,   417,  1064,  1064,
    1465,  1459,   521,  1457,  1305,   521,  1478,  1454,  1474,  1497,
    1481,   395,  1504,  1455,  1498,   829,  1491,  1456,  1510,  1502,
     521,  1511,  1512,  1513,  1519,  1524,  1526,  1531,  1533,   521,
    1448,  1538,  1522,  1545,  1546,  1547,  1528,  1550,  1602,  1604,
    1551,  1556,  1613,   521,  1559,  1566,  1152,  1567,  1605,  1626,
    1572,  1590,  1629,   521,  1631,   725,   420,   421,   422,   423,
    1618,   424,   425,   726,   427,   428,  1637,  1653,  1603,  1655,
     429,  1658,  1641,  1645,  1638,  1667,  1668,  1625,  1669,  1670,
    1671,   521,  1675,  1680,  1410,  1682,  1684,  1683,  1698,  1700,
    1717,  1723,  1676,  1704,  1714,  1726,  1730,  1722,  1715,   520,
    1737,   521,   520,  1712,  1735,  1740,  1741,  1743,  1584,  1729,
     521,  1747,  1719,  1750,   521,  1748,  1752,  1764,  1762,  1765,
    1768,  1769,  1773,  1772,   587,   297,  1754,   593,  1756,  1775,
     727,   929,  1210,   301,  1363,   589,   724,   590,  1133,  1678,
    1380,   684,  1710,  1207,  1068,  1389,  1738,  1004,  1543,  1476,
    1407,  1303,  1473,  1470,   791,  1418,  1422,  1428,  1436,   861,
     860,   898,   661,  1446,  1034,  1728,  1116,  1725,   521,   693,
    1738,  1373,   697,  1183,  1362,  1458,   558,  1464,  1463,  1719,
     736,  1492,   713,  1705,   737,  1341,  1496,  1317,  1495,   715,
    1601,  1157,  1600,  1657,  1371,   521,  1521,  1610,  1493,     0,
       0,   558,     0,     0,     0,     0,     0,   741,     0,     0,
     746,  1664,     0,     0,     0,     0,     0,     0,   763,     0,
       0,   521,   521,     0,   558,   771,   772,   775,     0,     0,
       0,     0,   781,     0,     0,     0,     0,     0,     0,     0,
     788,     0,     0,     0,     0,  1063,     0,   521,     0,   521,
       0,     0,   521,  1064,     0,     0,  1063,  1063,     0,   297,
       0,     0,     0,   521,  1064,  1064,  1063,   301,   521,  1753,
       0,     0,     0,     0,  1064,     0,     0,     0,     0,     0,
       0,     0,     0,   521,     0,     0,   789,  1767,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     775,     0,     0,     0,     0,     0,     0,     0,     0,   797,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   822,     0,     0,     0,  1063,     0,     0,     0,     0,
       0,     0,     0,  1064,     0,  1063,     0,     0,     0,     0,
       0,     0,     0,  1064,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   521,     0,
     521,     0,   521,   297,     0,     0,     0,     0,     0,   521,
       0,   301,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   297,     0,     0,
       0,     0,   521,     0,   521,   301,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   558,     0,
     521,  1063,     0,   521,     0,     0,     0,     0,     0,  1064,
    1063,     0,     0,     0,     0,   521,     0,     0,  1064,     0,
       0,     0,   926,     0,     0,   521,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   521,     0,     0,     0,
       0,     0,     0,   958,     0,   521,     0,     0,   962,   963,
       0,     0,     0,   521,     0,     0,     0,     0,   521,     0,
     521,     0,   521,     0,     0,     0,     0,     0,     0,     0,
     982,     0,   988,     0,     0,     0,     0,     0,     0,     0,
     558,     0,   521,   558,     0,     0,     0,  1002,     0,     0,
       0,     0,   521,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   521,     0,
       0,     0,     0,     0,     0,   521,     0,     0,     0,     0,
       0,   521,     0,     0,  1033,     0,     0,     0,     0,     0,
     521,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     521,     0,     0,     0,     0,     0,   521,     0,     0,     0,
       0,   521,     0,     0,   520,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1076,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1112,  1112,  1112,  1112,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1112,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1145,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1173,     0,     0,     0,     0,     0,
       0,     0,     0,  1181,     0,  1181,     0,     0,     0,  1112,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1112,     0,     0,     0,     0,     0,     0,     0,
     812,   813,     0,   815,   816,   817,   818,     0,     0,     0,
       0,     0,     0,   827,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   781,     0,   781,     0,     0,
       0,     0,     0,     0,     0,     0,   852,     0,     0,     0,
       0,     0,     0,     0,   858,   859,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1313,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   893,     0,  1112,     0,   893,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   960,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   746,     0,     0,
    1392,     0,     0,     0,     0,  1003,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1406,     0,     0,     0,     0,
       0,     0,     0,     0,  1112,     0,     0,     0,     0,     0,
    1028,     0,     0,     0,     0,     0,     0,     0,   775,     0,
     858,     0,     0,     0,     0,     0,     0,     0,  1112,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1449,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1078,   822,     0,     0,     0,
       0,     0,     0,     0,     0,   520,     0,     0,     0,   520,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1134,  1112,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1527,     0,     0,     0,     0,     0,     0,     0,     0,  1172,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1541,  1542,  1188,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1221,     0,  1558,     0,  1112,     0,     0,  1112,     0,     0,
       0,  1226,  1227,     0,     0,     0,     0,     0,  1570,     0,
       0,     0,     0,  1574,     0,     0,  1246,     0,     0,  1249,
       0,     0,     0,     0,     0,     0,     0,     0,  1587,     0,
       0,     0,     0,  1272,  1273,  1274,     0,  1277,  1278,  1279,
    1280,  1281,  1282,     0,  1284,  1285,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1078,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1359,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1640,     0,  1642,     0,  1644,     0,     0,
       0,     0,     0,     0,  1652,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1112,     0,  1112,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1393,
       0,  1395,     0,  1397,     0,  1674,  1401,     0,  1677,     0,
       0,  1405,     0,     0,     0,     0,     0,     0,     0,     0,
    1112,     0,     0,  1411,     0,     0,     0,     0,     0,     0,
    1685,     0,  1415,     0,     0,     0,     0,     0,  1419,  1420,
       0,  1703,     0,     0,     0,     0,     0,     0,     0,     0,
    1112,     0,     0,     0,     0,     0,     0,  1441,  1713,     0,
       0,     0,     0,  1716,     0,  1112,     0,  1112,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1733,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1736,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1742,     0,     0,     0,     0,     0,     0,
    1749,     0,  1078,     0,     0,     0,  1751,     0,     0,     0,
       0,     0,     0,     0,     0,  1759,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1766,     0,     0,     0,     0,
       0,  1770,     0,     0,     0,     0,  1774,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1532,     0,     0,     0,  1534,     0,     0,     0,  1537,     0,
    1539,     0,  1540,     0,     0,     0,     0,     0,  1544,     0,
       0,     0,     0,     0,     0,     0,  1549,     0,     0,     0,
       0,     0,     0,     0,  1553,  1555,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1411,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1575,  1576,  1577,  1578,  1579,     0,  1580,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1627,     0,  1628,     0,     0,  1630,     0,
       0,     0,     0,     0,     0,     0,  1633,     0,     0,     0,
       0,  1635,  1555,     0,     0,     0,     0,     0,     0,  1639,
       0,     0,     0,  1643,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1679,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1639,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1720,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1734,     0,     0,     0,     0,  1739,     0,     0,
       0,     0,  1720,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1739,     1,     2,     0,     0,     0,     0,     0,  1755,     0,
       3,     4,     5,     6,     7,     8,     9,    10,     0,    11,
       0,     0,     0,    12,    13,     0,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,     0,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,     0,
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
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
       1,     2,     0,     0,     0,     0,     0,     0,     0,     3,
       4,     5,     6,     7,     8,     9,    10,     0,    11,     0,
       0,     0,   390,   391,     0,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,   392,
      29,    30,    31,    32,     0,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,     0,    46,
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
     127,     0,   540,     0,   128,     0,   129,   130,     0,   131,
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
     390,   391,     0,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,   392,    29,    30,
      31,    32,     0,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,     0,    46,    47,    48,
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
     793,     0,   128,     0,   129,   130,     0,   131,   132,   133,
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
      23,    24,    25,    26,  1059,   392,    29,    30,    31,    32,
       0,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,     0,    46,    47,    48,  1060,  1061,
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
     123,   124,     0,     0,   125,   126,   127,     0,   793,     0,
     128,     0,   129,   130,     0,   131,   132,   133,     0,   134,
       0,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,     0,     0,   146,   147,   148,     0,   393,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,  1062,   180,
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
      25,    26,  1059,   392,    29,    30,    31,    32,     0,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,     0,    46,    47,    48,  1060,  1061,    51,    52,
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
       0,     0,   125,   126,   127,     0,   540,     0,   128,     0,
     129,   130,     0,   131,   132,   133,     0,   134,     0,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
       0,     0,   146,   147,   148,     0,   393,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,  1062,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,     1,     2,     0,     0,     0,     0,     0,     0,
       0,     3,     4,     5,     6,     7,     8,     9,    10,     0,
      11,     0,     0,     0,   390,   391,     0,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,   392,    29,    30,    31,    32,     0,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
       0,    46,    47,    48,    49,    50,    51,    52,    53,    54,
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
       0,     0,    12,    13,     0,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,     0,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,     0,    46,
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
     148,     0,   149,   150,   151,   152,   153,   154,   155,   156,
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
      31,    32,     0,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,     0,    46,    47,    48,
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
       8,     9,    10,     0,    11,     0,     0,     0,    12,   391,
       0,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
       0,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,     0,    46,    47,    48,    49,    50,
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
      10,     0,    11,     0,     0,     0,   845,   391,     0,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,   392,    29,    30,    31,    32,     0,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,     0,    46,    47,    48,    49,    50,    51,    52,
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
      11,     0,     0,     0,   390,   391,     0,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
    1059,   392,    29,    30,    31,    32,     0,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
       0,    46,    47,    48,  1060,  1061,    51,    52,    53,    54,
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
     175,   176,   177,   178,  1062,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
       1,     2,     0,     0,     0,     0,     0,     0,     0,     3,
       4,     5,     6,     7,     8,     0,     0,     0,    11,     0,
       0,     0,   390,   391,     0,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,   543,   392,
      29,    30,    31,    32,     0,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,     0,    46,
      47,    48,   544,   545,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,     0,    69,    70,    71,    72,    73,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     496,    82,    83,    84,    85,    86,   546,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,    96,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   547,     0,     0,   109,   110,   111,   112,   113,     0,
       0,     0,     0,   114,   115,   116,   117,   118,   119,   120,
     121,     0,   122,     0,   123,   124,     0,     0,   125,   126,
     127,     0,     0,     0,   128,   548,   129,   130,     0,   131,
     132,   133,     0,   134,     0,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,     0,     0,   146,   147,
     148,     0,   393,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   513,   514,   515,   516,   176,
     177,   517,   549,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,     1,     2,
       0,     0,     0,     0,     0,     0,     0,     3,     4,     5,
       6,     7,     8,     0,     0,     0,    11,     0,     0,     0,
     390,   391,     0,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,   543,   392,    29,    30,
      31,    32,     0,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,     0,    46,    47,    48,
     544,   545,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
       0,    69,    70,    71,    72,    73,    74,    75,    76,     0,
       0,    77,    78,     0,     0,     0,    79,    80,   496,    82,
      83,    84,    85,    86,   546,    88,    89,     0,     0,     0,
      90,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,    96,    97,    98,    99,   100,     0,     0,     0,     0,
       0,     0,   101,   102,   103,   104,   105,   106,   107,   547,
       0,     0,   109,   110,   111,   112,   113,     0,     0,     0,
       0,   114,   115,   116,   117,   118,   119,   120,   121,     0,
     122,     0,   123,   124,     0,     0,   125,   126,   127,     0,
     886,     0,   128,     0,   129,   130,     0,   131,   132,   133,
       0,   134,     0,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,     0,     0,   146,   147,   148,     0,
     393,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   513,   514,   515,   516,   176,   177,   517,
     549,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,     1,     2,     0,     0,
       0,     0,     0,     0,     0,     3,     4,     5,     6,     7,
       8,     0,     0,     0,    11,     0,     0,     0,   390,   391,
       0,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,   543,   392,    29,    30,    31,    32,
       0,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,     0,    46,    47,    48,   544,   545,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,     0,    69,
      70,    71,    72,    73,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,   496,    82,    83,    84,
      85,    86,   546,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,    96,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   547,     0,     0,
     109,   110,   111,   112,   113,     0,     0,     0,     0,   114,
     115,   116,   117,   118,   119,   120,   121,     0,   122,     0,
     123,   124,     0,     0,   125,   126,   127,     0,     0,     0,
     128,   892,   129,   130,     0,   131,   132,   133,     0,   134,
       0,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,     0,     0,   146,   147,   148,     0,   393,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   513,   514,   515,   516,   176,   177,   517,   549,   180,
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
      25,    26,   543,   392,    29,    30,    31,    32,     0,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,     0,    46,    47,    48,   544,   545,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,     0,    69,    70,    71,
      72,    73,    74,    75,    76,     0,     0,    77,    78,     0,
       0,     0,    79,    80,   496,    82,    83,    84,    85,    86,
     546,    88,    89,     0,     0,     0,    90,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,    96,    97,    98,
      99,   100,     0,     0,     0,     0,     0,     0,   101,   102,
     103,   104,   105,   106,   107,   547,     0,     0,   109,   110,
     111,   112,   113,     0,     0,     0,     0,   114,   115,   116,
     117,   118,   119,   120,   121,     0,   122,     0,   123,   124,
       0,     0,   125,   126,   127,     0,     0,     0,   128,   897,
     129,   130,     0,   131,   132,   133,     0,   134,     0,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
       0,     0,   146,   147,   148,     0,   393,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   513,
     514,   515,   516,   176,   177,   517,   549,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,     1,     2,     0,     0,     0,     0,     0,     0,
       0,     3,     4,     5,     6,     7,     8,     0,     0,     0,
      11,     0,     0,     0,   390,   391,     0,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,   482,    26,
     484,   392,    29,   485,    31,    32,     0,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,   487,
       0,    46,    47,    48,   489,   490,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,     0,    69,    70,    71,    72,    73,
      74,    75,    76,     0,     0,    77,    78,     0,     0,     0,
      79,    80,   496,    82,    83,    84,    85,    86,   546,    88,
      89,     0,     0,     0,    90,     0,    91,    92,    93,    94,
       0,    95,     0,     0,     0,   499,    97,    98,    99,   100,
       0,     0,     0,     0,     0,     0,   101,   102,   103,   104,
     105,   106,   107,   547,     0,     0,   109,   110,   659,   112,
     113,     0,     0,     0,     0,   114,   115,   116,   117,   118,
     119,   120,   121,     0,   122,     0,   660,   124,     0,     0,
     125,   126,   127,     0,     0,     0,   128,     0,   129,   130,
       0,   131,   132,   133,     0,   134,     0,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,     0,     0,
     146,   147,   148,     0,   393,   150,   151,   152,   153,   154,
     155,   156,   157,   508,   159,   509,   161,   510,   511,   164,
     165,   166,   167,   168,   169,   512,   171,   513,   514,   515,
     516,   176,   177,   517,   518,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
       1,     2,     0,     0,     0,     0,     0,     0,     0,     3,
       4,     5,     6,     7,     8,     0,     0,     0,    11,     0,
       0,     0,   390,   391,     0,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,   543,   392,
      29,    30,    31,    32,     0,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,     0,    46,
      47,    48,   544,   545,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,     0,    69,    70,    71,    72,    73,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     496,    82,    83,    84,    85,    86,   546,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,    96,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   547,     0,     0,   109,   110,   111,   112,   113,     0,
       0,     0,     0,   114,   115,   116,   117,   118,   119,   120,
     121,     0,   122,     0,   123,   124,     0,     0,   125,   126,
     127,     0,     0,     0,   128,     0,   129,   130,     0,   131,
     132,   133,     0,   134,     0,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,     0,     0,   146,   147,
     148,     0,   393,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   513,   514,   515,   516,   176,
     177,   517,   549,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,     1,     2,
       0,     0,     0,     0,     0,     0,     0,     3,     4,     5,
       6,     7,     8,     0,     0,     0,    11,     0,     0,     0,
     390,   391,     0,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,   482,    26,   484,   392,    29,   485,
      31,    32,     0,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,   487,     0,    46,    47,    48,
     489,   490,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
       0,    69,    70,    71,    72,    73,    74,    75,    76,     0,
       0,    77,    78,     0,     0,     0,    79,    80,   496,    82,
      83,    84,    85,    86,   546,    88,    89,     0,     0,     0,
      90,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,   499,    97,    98,    99,   100,     0,     0,     0,     0,
       0,     0,   101,   102,   103,   104,   105,   106,   107,   547,
       0,     0,   109,   110,   111,   112,   113,     0,     0,     0,
       0,   114,   115,   116,   117,   118,   119,   120,   121,     0,
     122,     0,   123,   124,     0,     0,   125,   126,   127,     0,
       0,     0,   128,     0,   129,   130,     0,   131,   132,   133,
       0,   134,     0,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,     0,     0,   146,   147,   148,     0,
     393,   150,   151,   152,   153,   154,   155,   156,   157,   508,
     159,   509,   161,   510,   511,   164,   165,   166,   167,   168,
     169,   512,   171,   513,   514,   515,   516,   176,   177,   517,
     518,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,     1,     2,     0,     0,
       0,     0,     0,     0,     0,     3,     4,     5,     6,     7,
       8,     0,     0,     0,    11,     0,     0,     0,   390,   391,
       0,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,   482,    26,   484,   392,    29,   485,    31,    32,
       0,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,   487,     0,    46,    47,    48,   489,   490,
      51,   491,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,     0,    69,
      70,    71,    72,    73,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,   496,    82,    83,    84,
      85,    86,   546,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,   499,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   547,     0,     0,
     109,   110,     0,   112,   113,     0,     0,     0,     0,   114,
     115,   116,   117,   118,   119,   120,   121,     0,   122,     0,
       0,     0,     0,     0,   125,   126,   127,     0,     0,     0,
     128,     0,   129,   130,     0,   131,   132,   133,     0,   134,
       0,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,     0,     0,   146,   147,   148,     0,   393,   150,
     151,   152,   153,   154,   155,   156,   157,   508,   159,   509,
     161,   510,   511,   164,   165,   166,   167,   168,   169,   512,
     171,   513,   514,   515,   516,   176,   177,   517,   518,   180,
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
     482,    26,   484,   392,    29,   485,    31,    32,     0,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,   487,     0,    46,    47,    48,   489,   490,    51,   491,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,     0,    69,    70,    71,
      72,    73,    74,    75,    76,     0,     0,    77,    78,     0,
       0,     0,    79,    80,   496,    82,    83,    84,    85,    86,
     546,    88,    89,     0,     0,     0,    90,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,   499,    97,    98,
      99,   100,     0,     0,     0,     0,     0,     0,   101,   102,
     103,   104,   105,   106,   107,   547,     0,     0,   109,   110,
       0,   112,   113,     0,     0,     0,     0,   114,   115,   116,
     117,   118,   119,   120,   121,     0,   122,     0,     0,     0,
       0,     0,   125,   126,   127,     0,     0,     0,   128,     0,
     129,   130,     0,     0,     0,   133,     0,   134,     0,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
       0,     0,   146,   147,   148,     0,   393,   150,   151,   152,
     153,   154,   155,   156,   157,   508,   159,   509,   161,   510,
     511,   164,   165,   166,   167,   168,   169,   512,   171,   513,
     514,   515,   516,   176,   177,   517,   518,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,     1,     2,     0,     0,     0,     0,     0,     0,
       0,     3,     0,     0,     0,     7,     8,     0,     0,     0,
     478,     0,     0,     0,   390,   391,     0,    14,    15,    16,
     479,    18,    19,    20,   480,    22,   481,    24,   482,   483,
     484,   392,    29,   485,    31,    32,     0,    33,    34,    35,
      36,   486,    38,    39,    40,    41,    42,    43,    44,   487,
       0,    46,   488,    48,   489,   490,    51,   491,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,   492,   493,    68,     0,    69,    70,    71,   494,     0,
      74,    75,    76,     0,     0,   495,    78,     0,     0,     0,
       0,    80,   496,    82,   497,   498,    85,    86,     0,     0,
       0,     0,     0,     0,     0,     0,    91,    92,    93,    94,
       0,    95,     0,     0,     0,   499,    97,    98,   500,   501,
       0,     0,     0,     0,     0,     0,   101,   102,   103,     0,
     105,   106,   107,     0,     0,     0,     0,     0,     0,   112,
     113,     0,     0,     0,     0,   114,   115,   116,   117,   502,
     119,   120,   503,     0,     0,     0,     0,     0,     0,     0,
     504,   505,   127,     0,     0,     0,   128,     0,   129,   506,
       0,     0,     0,   133,     0,   134,     0,   135,   136,   137,
     138,   507,   140,   141,   142,   143,   144,   145,     0,     0,
     146,   147,     0,     0,   393,   150,   151,   152,   153,   154,
     155,   156,   157,   508,   159,   509,   161,   510,   511,   164,
     165,   166,   167,   168,   169,   512,   171,   513,   514,   515,
     516,   176,   177,   517,   518,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
       1,     2,     0,     0,     0,     0,     0,     0,     0,     3,
       0,     0,     0,     7,     8,     0,     0,     0,   478,     0,
       0,     0,   390,   391,     0,    14,    15,    16,   527,    18,
      19,    20,   480,   528,   529,    24,   482,   483,   484,   392,
      29,   485,    31,    32,     0,    33,    34,    35,    36,   530,
      38,   531,   532,    41,    42,    43,    44,   487,     0,    46,
     533,    48,   489,   490,    51,   491,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,   492,
     493,    68,     0,    69,    70,    71,   534,     0,    74,    75,
      76,     0,     0,   495,    78,     0,     0,     0,     0,    80,
     496,    82,   497,   498,    85,    86,     0,     0,     0,     0,
       0,     0,     0,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,   499,    97,    98,   500,   501,     0,     0,
       0,     0,     0,     0,   101,   102,   103,     0,   105,   106,
     107,     0,     0,     0,     0,     0,     0,   112,   113,     0,
       0,     0,     0,   114,   115,   116,   117,   502,   119,   120,
     503,     0,     0,     0,     0,     0,     0,     0,   504,   505,
     127,     0,     0,     0,   128,     0,   129,   506,     0,     0,
       0,   133,     0,   134,     0,   135,   136,   137,   138,   507,
     140,   141,   142,   143,   144,   145,     0,     0,   146,   147,
       0,     0,   393,   150,   151,   152,   153,   154,   155,   156,
     157,   508,   535,   509,   161,   510,   511,   164,   165,   166,
     167,   168,   169,   512,   171,   513,   514,   515,   516,   176,
     177,   517,   518,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   556,     0,
       0,     0,     0,     0,     0,     0,     7,     8,     0,     0,
       0,   768,     0,     0,     0,   390,   391,     0,    14,    15,
      16,   527,    18,    19,    20,   480,   528,   529,    24,   482,
     483,   484,   392,    29,   485,    31,    32,     0,    33,    34,
      35,    36,   530,    38,   531,   532,    41,    42,    43,    44,
     487,     0,    46,   533,    48,   489,   490,    51,   491,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,   492,   493,    68,     0,    69,    70,    71,   534,
       0,    74,    75,    76,     0,     0,   495,    78,     0,     0,
       0,     0,    80,   496,    82,   497,   498,    85,    86,     0,
       0,     0,     0,     0,     0,     0,     0,    91,    92,    93,
      94,     0,    95,     0,     0,     0,   499,    97,    98,   500,
     501,     0,     0,     0,     0,     0,     0,   101,   102,   103,
       0,   105,   106,   107,     0,     0,     0,     0,     0,     0,
     112,   113,     0,     0,     0,     0,   114,   115,   116,   117,
     502,   119,   120,   503,     0,     0,     0,     0,     0,     0,
       0,   504,   505,   127,     0,     0,     0,   128,   769,   129,
     506,     0,     0,     0,     0,     0,   134,     0,   135,   136,
     137,   138,   507,   140,   141,   142,   143,   144,   145,     0,
       0,   146,   147,     0,     0,   393,   150,   151,   152,   153,
     154,   155,   156,   157,   508,   535,   509,   161,   510,   511,
     164,   165,   166,   167,   168,   169,   512,   171,   513,   514,
     515,   516,   176,   177,   517,   518,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,     0,
     193,   194,   195,     0,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   556,     0,     0,     0,     0,     0,     0,     0,     7,
       8,     0,     0,     0,   478,     0,     0,     0,   390,   391,
       0,    14,    15,    16,   527,    18,    19,    20,   480,   528,
     529,    24,   482,   483,   484,   392,    29,   485,    31,    32,
       0,    33,    34,    35,    36,   530,    38,   531,   532,    41,
      42,    43,    44,   487,     0,    46,   533,    48,   489,   490,
      51,   491,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,   492,   493,    68,     0,    69,
      70,    71,   534,     0,    74,    75,    76,     0,     0,   495,
      78,     0,     0,     0,     0,    80,   496,    82,   497,   498,
      85,    86,     0,     0,     0,     0,     0,     0,     0,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,   499,
      97,    98,   500,   501,     0,     0,     0,     0,     0,     0,
     101,   102,   103,     0,   105,   106,   107,     0,     0,     0,
       0,     0,     0,   112,   113,     0,     0,     0,     0,   114,
     115,   116,   117,   502,   119,   120,   503,     0,     0,     0,
       0,     0,     0,     0,   504,   505,   127,     0,     0,     0,
     128,     0,   129,   506,     0,     0,     0,     0,     0,   134,
       0,   135,   136,   137,   138,   507,   140,   141,   142,   143,
     144,   145,     0,     0,   146,   147,     0,     0,   393,   150,
     151,   152,   153,   154,   155,   156,   157,   508,   535,   509,
     161,   510,   511,   164,   165,   166,   167,   168,   169,   512,
     171,   513,   514,   515,   516,   176,   177,   517,   518,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   559,   560,     0,     0,     0,     0,
       7,     8,     0,     0,     0,   478,     0,     0,     0,   390,
     391,     0,    14,    15,    16,   527,    18,    19,    20,   480,
     528,   529,    24,   482,   483,   484,   392,    29,   485,    31,
      32,     0,    33,    34,    35,    36,   530,    38,   531,   532,
      41,    42,    43,    44,   487,     0,    46,   533,    48,   489,
     490,    51,   491,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,   492,   493,    68,     0,
      69,    70,    71,   534,     0,    74,    75,    76,     0,     0,
     495,    78,     0,     0,     0,     0,    80,   496,    82,   497,
     498,    85,    86,     0,     0,     0,     0,     0,     0,     0,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
     499,    97,    98,   500,   501,     0,     0,     0,     0,     0,
       0,   101,   102,   103,     0,   105,   106,   107,     0,     0,
       0,     0,     0,     0,   112,   113,     0,     0,     0,     0,
     114,   115,   116,   117,   502,   119,   120,   503,     0,     0,
       0,     0,     0,     0,     0,   504,   505,   127,     0,     0,
       0,   128,     0,   129,   506,     0,     0,     0,     0,     0,
     134,     0,   135,   136,   137,   138,   507,   140,   141,   142,
     143,   144,   145,     0,     0,   146,   147,     0,     0,   393,
     150,   151,   152,   153,   154,   155,   156,   157,   508,   535,
     509,   161,   510,   511,   164,   165,   166,   167,   168,   169,
     512,   171,   513,   514,   515,   516,   176,   177,   517,   518,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,     7,     8,     0,     0,     0,
     478,     0,     0,     0,   390,   391,     0,    14,    15,    16,
     479,    18,    19,    20,   480,    22,   481,    24,   482,  1100,
     484,   392,    29,   485,    31,    32,     0,    33,    34,    35,
      36,   486,    38,    39,    40,    41,    42,    43,    44,   487,
       0,    46,   488,    48,   489,   490,    51,   491,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,   492,   493,    68,     0,    69,    70,    71,   494,     0,
      74,    75,    76,     0,     0,   495,    78,     0,     0,     0,
       0,    80,   496,    82,   497,   498,    85,    86,     0,     0,
       0,     0,     0,     0,     0,     0,    91,    92,    93,    94,
       0,    95,     0,     0,     0,   499,    97,    98,   500,   501,
       0,     0,     0,     0,     0,     0,   101,   102,   103,     0,
     105,   106,  1101,     0,     0,     0,  1102,     0,     0,   112,
     113,     0,     0,     0,     0,   114,   115,   116,   117,   502,
     119,   120,   503,     0,     0,     0,     0,     0,     0,     0,
     504,   505,   127,     0,     0,     0,   128,  1506,   129,   506,
       0,     0,     0,  1507,     0,   134,     0,   135,   136,   137,
     138,   507,   140,   141,   142,   143,   144,   145,     0,     0,
    1103,   147,     0,     0,   393,   150,   151,   152,   153,   154,
     155,   156,   157,   508,   159,   509,   161,   510,   511,   164,
     165,   166,   167,   168,   169,   512,   171,   513,   514,   515,
     516,   176,   177,   517,   518,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
       7,     8,     0,     0,     0,   478,     0,     0,     0,   390,
     391,     0,    14,    15,    16,   527,    18,    19,    20,   480,
     528,   529,    24,   482,   483,   484,   392,    29,   485,    31,
      32,     0,    33,    34,    35,    36,   530,    38,   531,   532,
      41,    42,    43,    44,   487,     0,    46,   533,    48,   489,
     490,    51,   491,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,   492,   493,    68,     0,
      69,    70,    71,   534,     0,    74,    75,    76,     0,     0,
     495,    78,     0,     0,     0,     0,    80,   496,    82,   497,
     498,    85,    86,     0,     0,     0,     0,     0,     0,     0,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
     499,    97,    98,   500,   501,     0,     0,     0,     0,     0,
       0,   101,   102,   103,     0,   105,   106,   107,     0,     0,
       0,     0,     0,     0,   112,   113,     0,     0,     0,     0,
     114,   115,   116,   117,   502,   119,   120,   503,     0,     0,
       0,     0,     0,     0,     0,   504,   505,   127,     0,     0,
       0,   128,   739,   129,   506,     0,     0,     0,   740,     0,
     134,     0,   135,   136,   137,   138,   507,   140,   141,   142,
     143,   144,   145,     0,     0,   146,   147,     0,     0,   393,
     150,   151,   152,   153,   154,   155,   156,   157,   508,   535,
     509,   161,   510,   511,   164,   165,   166,   167,   168,   169,
     512,   171,   513,   514,   515,   516,   176,   177,   517,   518,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,     7,     8,     0,     0,     0,
     478,     0,     0,     0,   390,   391,     0,    14,    15,    16,
     527,    18,    19,    20,   480,   528,   529,    24,   482,   483,
     484,   392,    29,   485,    31,    32,     0,    33,    34,    35,
      36,   530,    38,   531,   532,    41,    42,    43,    44,   487,
       0,    46,   533,    48,   489,   490,    51,   491,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,   492,   493,    68,     0,    69,    70,    71,   534,     0,
      74,    75,    76,     0,     0,   495,    78,     0,     0,     0,
       0,    80,   496,    82,   497,   498,    85,    86,     0,     0,
       0,     0,     0,     0,     0,     0,    91,    92,    93,    94,
       0,    95,     0,     0,     0,   499,    97,    98,   500,   501,
       0,     0,     0,     0,     0,     0,   101,   102,   103,     0,
     105,   106,   107,     0,     0,     0,     0,     0,     0,   112,
     113,     0,     0,     0,     0,   114,   115,   116,   117,   502,
     119,   120,   503,     0,     0,     0,     0,     0,     0,     0,
     504,   505,   127,     0,     0,     0,   128,   786,   129,   506,
       0,     0,     0,   787,     0,   134,     0,   135,   136,   137,
     138,   507,   140,   141,   142,   143,   144,   145,     0,     0,
     146,   147,     0,     0,   393,   150,   151,   152,   153,   154,
     155,   156,   157,   508,   535,   509,   161,   510,   511,   164,
     165,   166,   167,   168,   169,   512,   171,   513,   514,   515,
     516,   176,   177,   517,   518,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
       7,     8,     0,     0,     0,   478,     0,     0,     0,   390,
     391,     0,    14,    15,    16,   479,    18,    19,    20,   480,
      22,   481,    24,   482,  1100,   484,   392,    29,   485,    31,
      32,     0,    33,    34,    35,    36,   486,    38,    39,    40,
      41,    42,    43,    44,   487,     0,    46,   488,    48,   489,
     490,    51,   491,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,   492,   493,    68,     0,
      69,    70,    71,   494,     0,    74,    75,    76,     0,     0,
     495,    78,     0,     0,     0,     0,    80,   496,    82,   497,
     498,    85,    86,  1429,     0,     0,     0,     0,     0,     0,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
     499,    97,    98,   500,   501,     0,     0,     0,     0,     0,
       0,   101,   102,   103,     0,   105,   106,  1101,     0,     0,
       0,  1102,     0,     0,   112,   113,     0,     0,     0,     0,
     114,   115,   116,   117,   502,   119,   120,   503,     0,     0,
       0,     0,     0,     0,     0,   504,   505,   127,     0,     0,
       0,   128,     0,   129,   506,     0,     0,     0,     0,     0,
     134,     0,   135,   136,   137,   138,   507,   140,   141,   142,
     143,   144,   145,     0,     0,  1103,   147,     0,     0,   393,
     150,   151,   152,   153,   154,   155,   156,   157,   508,   159,
     509,   161,   510,   511,   164,   165,   166,   167,   168,   169,
     512,   171,   513,   514,   515,   516,   176,   177,   517,   518,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,     7,     8,     0,     0,     0,
     478,     0,     0,     0,   390,   391,     0,    14,    15,    16,
     479,    18,    19,    20,   480,    22,   481,    24,   482,  1100,
     484,   392,    29,   485,    31,    32,     0,    33,    34,    35,
      36,   486,    38,    39,    40,    41,    42,    43,    44,   487,
       0,    46,   488,    48,   489,   490,    51,   491,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,   492,   493,    68,     0,    69,    70,    71,   494,     0,
      74,    75,    76,     0,     0,   495,    78,     0,     0,     0,
       0,    80,   496,    82,   497,   498,    85,    86,  1560,     0,
       0,     0,     0,     0,     0,     0,    91,    92,    93,    94,
       0,    95,     0,     0,     0,   499,    97,    98,   500,   501,
       0,     0,     0,     0,     0,     0,   101,   102,   103,     0,
     105,   106,  1101,     0,     0,     0,  1102,     0,     0,   112,
     113,     0,     0,     0,     0,   114,   115,   116,   117,   502,
     119,   120,   503,     0,     0,     0,     0,     0,     0,     0,
     504,   505,   127,     0,     0,     0,   128,     0,   129,   506,
       0,     0,     0,     0,     0,   134,     0,   135,   136,   137,
     138,   507,   140,   141,   142,   143,   144,   145,     0,     0,
    1103,   147,     0,     0,   393,   150,   151,   152,   153,   154,
     155,   156,   157,   508,   159,   509,   161,   510,   511,   164,
     165,   166,   167,   168,   169,   512,   171,   513,   514,   515,
     516,   176,   177,   517,   518,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
       7,     8,     0,     0,     0,   478,     0,     0,     0,   390,
     391,     0,    14,    15,    16,   479,    18,    19,    20,   480,
      22,   481,    24,   482,  1100,   484,   392,    29,   485,    31,
      32,     0,    33,    34,    35,    36,   486,    38,    39,    40,
      41,    42,    43,    44,   487,     0,    46,   488,    48,   489,
     490,    51,   491,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,   492,   493,    68,     0,
      69,    70,    71,   494,     0,    74,    75,    76,     0,     0,
     495,    78,     0,     0,     0,     0,    80,   496,    82,   497,
     498,    85,    86,  1564,     0,     0,     0,     0,     0,     0,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
     499,    97,    98,   500,   501,     0,     0,     0,     0,     0,
       0,   101,   102,   103,     0,   105,   106,  1101,     0,     0,
       0,  1102,     0,     0,   112,   113,     0,     0,     0,     0,
     114,   115,   116,   117,   502,   119,   120,   503,     0,     0,
       0,     0,     0,     0,     0,   504,   505,   127,     0,     0,
       0,   128,     0,   129,   506,     0,     0,     0,     0,     0,
     134,     0,   135,   136,   137,   138,   507,   140,   141,   142,
     143,   144,   145,     0,     0,  1103,   147,     0,     0,   393,
     150,   151,   152,   153,   154,   155,   156,   157,   508,   159,
     509,   161,   510,   511,   164,   165,   166,   167,   168,   169,
     512,   171,   513,   514,   515,   516,   176,   177,   517,   518,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,     7,     8,     0,     0,     0,
     478,     0,     0,     0,   390,   391,     0,    14,    15,    16,
     479,    18,    19,    20,   480,    22,   481,    24,   482,  1100,
     484,   392,    29,   485,    31,    32,     0,    33,    34,    35,
      36,   486,    38,    39,    40,    41,    42,    43,    44,   487,
       0,    46,   488,    48,   489,   490,    51,   491,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,   492,   493,    68,     0,    69,    70,    71,   494,     0,
      74,    75,    76,     0,     0,   495,    78,     0,     0,     0,
       0,    80,   496,    82,   497,   498,    85,    86,     0,     0,
       0,     0,     0,     0,     0,     0,    91,    92,    93,    94,
       0,    95,     0,     0,     0,   499,    97,    98,   500,   501,
       0,     0,     0,     0,     0,     0,   101,   102,   103,     0,
     105,   106,  1101,     0,     0,     0,  1102,     0,     0,   112,
     113,     0,     0,     0,     0,   114,   115,   116,   117,   502,
     119,   120,   503,     0,     0,     0,     0,     0,     0,     0,
     504,   505,   127,     0,     0,     0,   128,     0,   129,   506,
       0,     0,     0,     0,     0,   134,     0,   135,   136,   137,
     138,   507,   140,   141,   142,   143,   144,   145,     0,     0,
    1103,   147,     0,     0,   393,   150,   151,   152,   153,   154,
     155,   156,   157,   508,   159,   509,   161,   510,   511,   164,
     165,   166,   167,   168,   169,   512,   171,   513,   514,   515,
     516,   176,   177,   517,   518,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
       7,     8,     0,     0,     0,   478,     0,     0,     0,   390,
     391,     0,    14,    15,    16,   479,    18,    19,    20,   480,
      22,   481,    24,   482,  1100,   484,   392,    29,   485,    31,
      32,     0,    33,    34,    35,    36,   486,    38,    39,    40,
      41,    42,    43,    44,   487,     0,    46,   488,    48,   489,
     490,    51,   491,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,   492,   493,    68,     0,
      69,    70,    71,   494,     0,    74,    75,    76,     0,     0,
     495,    78,     0,     0,     0,     0,    80,   496,    82,   497,
     498,    85,    86,     0,     0,     0,     0,     0,     0,     0,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
     499,    97,    98,   500,   501,     0,     0,     0,     0,     0,
       0,   101,   102,   103,     0,   105,   106,  1101,     0,     0,
       0,  1102,     0,     0,   112,   113,     0,     0,     0,     0,
     114,   115,   116,   117,   502,   119,   120,   503,     0,     0,
       0,     0,     0,     0,     0,   504,   505,   127,     0,     0,
       0,   128,     0,   129,   506,     0,     0,     0,     0,     0,
     134,     0,   135,   136,   137,   138,   507,   140,   141,   142,
     143,   144,   145,     0,     0,   146,   147,     0,     0,   393,
     150,   151,   152,   153,   154,   155,   156,   157,   508,   159,
     509,   161,   510,   511,   164,   165,   166,   167,   168,   169,
     512,   171,   513,   514,   515,   516,   176,   177,   517,   518,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,     7,     8,     0,     0,     0,
     478,     0,     0,     0,   390,   391,     0,    14,    15,    16,
     527,    18,    19,    20,   480,   528,   529,    24,   482,   483,
     484,   392,    29,   485,    31,    32,     0,    33,    34,    35,
      36,   530,    38,   531,   532,    41,    42,    43,    44,   487,
       0,    46,   533,    48,   489,   490,    51,   491,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,   492,   493,    68,     0,    69,    70,    71,   534,     0,
      74,    75,    76,     0,     0,   495,    78,     0,     0,     0,
       0,    80,   496,    82,   497,   498,    85,    86,     0,     0,
       0,     0,     0,     0,     0,     0,    91,    92,    93,    94,
       0,    95,     0,     0,     0,   499,    97,    98,   500,   501,
       0,     0,     0,     0,     0,     0,   101,   102,   103,     0,
     105,   106,   107,     0,     0,     0,     0,     0,     0,   112,
     113,     0,     0,     0,     0,   114,   115,   116,   117,   502,
     119,   120,   503,     0,     0,     0,     0,     0,     0,     0,
     504,   505,   127,     0,     0,     0,   128,     0,   129,   506,
       0,     0,     0,     0,     0,   134,     0,   135,   136,   137,
     138,   507,   140,   141,   142,   143,   144,   145,     0,     0,
     146,   147,     0,     0,   393,   150,   151,   152,   153,   154,
     155,   156,   157,   508,   535,   509,   161,   510,   511,   164,
     165,   166,   167,   168,   169,   512,   171,   513,   514,   515,
     516,   176,   177,   517,   518,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
       7,     8,     0,     0,     0,   478,     0,     0,     0,   390,
     391,     0,    14,    15,    16,     0,    18,    19,    20,   480,
       0,     0,    24,   482,   483,     0,   392,    29,   485,    31,
      32,     0,    33,    34,    35,    36,     0,    38,     0,     0,
      41,    42,    43,    44,   487,     0,    46,     0,    48,     0,
       0,    51,   491,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,   492,   493,    68,     0,
      69,    70,    71,     0,     0,    74,    75,    76,     0,     0,
     495,    78,     0,     0,     0,     0,    80,   496,    82,   497,
     498,    85,    86,     0,     0,     0,     0,     0,     0,     0,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
     499,    97,    98,   500,   501,     0,     0,     0,     0,     0,
       0,   101,   102,   103,     0,   105,   106,     0,     0,     0,
       0,     0,     0,     0,   112,   113,     0,     0,     0,     0,
     114,   115,   116,   117,   502,   119,   120,   503,     0,     0,
       0,     0,     0,     0,     0,   504,   505,   127,     0,     0,
       0,   128,     0,   129,   506,     0,     0,     0,     0,     0,
     134,     0,   135,   136,   137,   138,   507,   140,   141,   142,
     143,   144,   145,     0,     0,     0,   147,     0,     0,   393,
     150,   151,   152,   153,   154,   155,   156,   157,   508,     0,
     509,   161,   510,   511,   164,   165,   166,   167,   168,   169,
     512,   171,   513,   514,   515,   516,   176,   177,     0,   518,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         0,   883,   179,   328,     4,     5,     6,   802,     0,    12,
     281,   646,     4,     5,     6,     4,     5,     6,   109,   301,
     831,   746,   763,   598,   599,   399,   400,   250,   962,     4,
       5,     6,   870,   249,   775,  1015,   132,   401,   647,   648,
     649,   650,   265,   746,   999,   413,  1037,  1252,   789,  1309,
    1310,  1169,   596,   597,   598,   599,    73,   272,   579,  1236,
      36,   596,   597,  1086,   882,   883,   692,   904,    36,   117,
     438,    56,     4,     5,     6,    30,  1524,   920,     8,   600,
      29,     1,   117,   604,     1,     1,    29,     1,   141,   453,
     454,     1,    29,   461,   976,     1,   626,     1,   628,   629,
     146,   631,   920,   633,    45,  1265,  1342,   989,   108,   106,
     106,   641,   642,   106,    94,    99,   108,   129,    94,   106,
      96,    99,    63,    93,   146,   396,   215,    53,    96,   106,
      29,    96,    94,   108,   106,    99,   954,    96,    26,    27,
      24,    94,    94,   152,   152,    37,    38,   157,    40,    41,
      34,   155,   106,   112,   223,   106,    54,    96,   976,   228,
     109,    59,    96,   157,   253,   175,    58,   176,   176,   172,
     146,   989,   109,   155,   123,   223,   108,    61,   146,    94,
      55,   175,    57,   195,   146,   926,   123,   197,   159,   141,
     281,    73,    45,   189,   187,    48,   155,   106,    96,   148,
     187,   185,   128,   152,     5,    87,   155,   185,     9,   186,
    1470,   148,   182,   112,   186,   152,   159,   432,   155,   272,
     112,   185,  1670,   111,    99,    94,   272,   176,   110,   168,
     215,  1165,   186,   184,   168,   331,   233,   272,  1033,   176,
     122,   982,   124,   243,   174,   186,   246,   988,  1086,  1087,
     272,   243,   105,  1233,   246,   235,   981,   212,   306,  1102,
     159,   836,   837,  1381,  1219,  1256,  1443,   159,   253,   189,
     552,   542,   189,   189,  1265,   189,   979,   186,   981,   189,
     906,   281,   235,   189,  1102,   189,  1446,  1523,   129,   281,
     255,   256,  1129,     5,   106,  1318,   272,     9,  1001,   834,
     835,   216,   217,   824,   272,   396,    29,   675,    94,   258,
     157,   106,   251,   252,   167,   254,   231,   251,   252,   336,
     254,   122,   339,   124,    26,    27,   218,   261,   175,  1211,
     135,   132,   271,    26,    27,   106,   866,   271,   223,   703,
     225,    26,    27,   614,   283,   117,    48,   216,   217,   283,
     106,   152,   443,  1235,   195,   106,  1174,   106,   120,   106,
     451,  1621,   231,   106,    45,   580,   152,    48,   260,   460,
     593,   106,    94,    75,   186,   250,   467,   468,  1583,    67,
     596,   597,   106,   152,    72,   476,   109,   106,   263,   757,
     265,   186,   760,  1211,   199,   106,   396,   761,    79,   106,
     123,   276,   277,   278,   396,   280,   106,   282,  1526,   111,
     122,   165,   124,  1673,   186,   186,   267,  1235,   111,   141,
     132,   268,   106,   274,   105,   148,   111,   181,   275,   117,
     186,   106,  1173,   219,   220,   186,   183,   186,   285,   439,
     152,   441,   106,   186,   106,   117,  1380,   439,   183,   441,
     117,   542,   441,   130,   336,  1446,   106,   339,   106,   730,
    1185,   106,   186,   554,   439,   465,   441,   186,  1350,   106,
     470,   106,   183,   465,   106,   566,   183,   106,   470,  1656,
    1318,  1292,    39,   183,   106,  1296,   167,    44,    45,  1327,
     465,  1194,   155,   584,   585,   470,   870,  1072,  1073,  1074,
    1338,   106,   186,    60,   106,    62,    63,   439,  1626,   441,
     106,   186,   189,   185,    71,     9,    10,   199,   185,  1648,
    1649,   183,   186,   405,   406,   899,   208,   409,  1072,  1073,
    1074,   413,  1350,   465,    94,   183,   186,   419,   470,   106,
      97,   186,   542,   106,   426,   106,   183,   547,     9,  1431,
     542,   186,  1434,  1671,   186,   547,   438,   186,   829,    96,
    1689,   183,   444,   927,   928,   447,  1695,    28,   932,   665,
     666,   662,   547,   455,    96,    96,   667,   917,   183,   461,
     462,   463,   464,   155,   186,   585,   146,   469,   591,   929,
     186,   112,  1547,   585,    96,   477,   596,   597,   598,   599,
     964,     9,  1582,    94,   596,   597,   598,   599,   102,   146,
     585,   116,   121,  1431,   614,   547,  1434,   840,   834,   186,
      28,   152,   614,   186,   155,   186,     9,    10,   122,   152,
     124,   995,   155,   155,   155,   999,  1754,    42,  1756,   730,
     145,   523,    47,   152,   146,   136,   155,    52,   143,  1444,
     141,   136,   155,   158,  1449,   537,   168,  1775,   152,  1497,
     105,   122,   156,   124,   546,    70,   223,   152,   157,    54,
     117,  1396,   133,    42,    59,   246,   247,   208,    47,   173,
     175,   126,   970,    52,   972,   208,   175,   192,   200,  1732,
      42,   152,    77,    33,  1329,    47,   578,   192,   269,   193,
      52,    70,   155,   794,   795,   796,   152,   798,   197,   155,
      50,    96,  1086,  1087,   122,  1758,   124,   211,    70,   102,
     268,   155,  1604,  1298,  1606,   133,  1769,   275,    33,   135,
     730,   147,   117,   136,  1022,   147,  1024,   285,   730,   122,
      95,   124,    96,   149,   152,    50,    26,    27,   164,   152,
     105,    54,   164,   753,   181,  1637,    59,   181,   112,   155,
     115,   753,   167,  1088,   753,   170,   155,   194,    48,   152,
     194,   126,   223,   156,   225,  1570,    99,    57,   753,  1574,
     185,    99,  1064,   783,   784,  1667,  1604,  1058,  1606,   112,
     173,   783,   784,   675,   112,    75,     9,    10,   167,    79,
    1682,   170,  1684,   152,   121,   210,   155,    99,   783,   784,
     193,    99,    99,    99,   696,   167,   185,   699,   170,  1637,
     112,   753,   136,   262,   112,   112,   112,   141,   211,   829,
     110,   111,   112,   185,   273,    94,   262,   829,   720,   298,
     136,   210,   845,   725,   726,   141,   105,   273,   307,  1667,
    1214,   783,   784,  1488,  1489,  1219,   338,  1652,   210,   152,
     121,   343,   155,   121,  1682,   747,  1684,   749,   668,   117,
     152,   671,  1481,   155,   674,   757,     9,    10,   760,   153,
    1621,   155,   764,   121,   230,  1062,   232,   121,   168,   102,
    1067,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    26,    27,   117,   276,   277,   278,   190,   191,   122,
     282,   124,    37,    38,   121,    40,    41,   299,   300,   801,
     200,   299,   300,    48,   219,   220,   221,   121,   230,   152,
     232,   121,    57,    58,   127,   128,   121,   290,   291,   152,
     121,  1305,  1213,   156,  1318,   127,   128,   121,   228,   831,
      75,   884,   885,  1327,    79,   644,   645,  1592,  1593,   214,
     173,   651,   652,   155,  1338,   152,   653,   654,   117,   102,
     223,   853,  1514,  1515,   240,   240,   155,   241,     0,   152,
     193,   189,   106,   166,    92,   110,   111,   112,   248,   122,
      51,   124,   198,   100,  1085,   101,   153,   120,   211,   144,
     882,   883,   884,   885,   155,   183,   286,   287,   288,   289,
     290,   183,   292,   293,   294,   295,   296,  1017,   183,   152,
    1291,   301,   302,   156,    29,  1017,   117,    48,  1663,   151,
     245,   303,   186,   283,   159,   292,   283,   117,   920,   152,
     173,   297,  1017,   168,     1,   297,   117,   141,   106,  1413,
     186,   152,   934,   152,   141,   155,   183,   155,  1058,   155,
     193,    35,   155,   155,    17,   155,  1058,   155,  1071,   155,
     152,   212,  1072,  1073,  1074,   200,   186,    29,   211,   961,
    1072,  1073,  1074,   229,   189,  1017,   189,     3,   970,   244,
     972,   117,   167,   218,   976,   169,   169,   229,    71,    94,
      94,    94,   148,   228,   106,   106,    29,   989,   159,   159,
    1474,   126,   131,   141,   245,   131,   183,   117,   298,   183,
     186,   186,   106,  1497,    94,    96,    45,    96,   152,   186,
     186,   186,   186,    94,   183,   260,    73,   141,   183,   223,
    1022,   189,  1024,    33,   169,   117,   235,    94,   131,   141,
      87,    29,   117,   225,  1425,   285,   298,   117,   126,   146,
      94,   286,   287,   288,   289,   290,   152,   292,   293,   294,
     295,   296,   253,   110,   117,   183,   301,   302,  1178,   196,
     131,   159,   131,  1547,    96,   122,  1178,   124,   152,  1178,
     117,   146,    99,    99,   183,   183,  1287,  1288,  1289,  1081,
     141,    35,   152,  1178,   189,    29,   131,   117,   244,   155,
     155,   155,   152,  1213,   139,   140,    79,   142,   106,   106,
    1102,  1213,   284,   257,  1224,   150,   259,   266,   143,   154,
      29,   156,  1224,   155,   155,  1224,   161,   168,   155,    29,
      29,   285,   305,  1243,   235,   225,  1178,   189,   225,  1224,
     225,  1243,   143,   178,  1243,   286,   186,   186,   186,   126,
     186,   146,  1262,   146,   146,   117,   117,    77,  1243,   200,
    1262,   106,   141,   186,  1545,   183,   201,   202,   203,   204,
     205,   206,   186,    99,   131,  1556,  1557,  1262,  1559,     7,
    1290,  1291,  1224,   196,   189,  1566,   231,   228,  1290,  1291,
     117,   185,  1184,   235,   105,  1187,   186,   231,   105,   146,
     249,  1243,    78,   231,   281,  1290,   249,   231,   186,   285,
    1202,   186,   186,    29,    29,   106,   169,   183,   146,  1211,
    1262,   146,   270,   125,   125,    96,   256,   183,   152,    94,
     185,   185,    29,  1225,   185,   185,    96,   183,   186,   169,
     183,   183,   146,  1235,    54,   286,   287,   288,   289,   290,
     186,   292,   293,   294,   295,   296,    94,   195,   279,   196,
     301,   117,   185,   185,  1645,    94,    29,   286,   264,   106,
     106,  1263,   117,   117,  1655,    94,    94,   185,   195,   195,
     185,    93,   223,   117,   117,   182,   117,   185,   223,   336,
     117,  1283,   339,   304,   304,   185,   185,   117,   152,   195,
    1292,   292,  1683,   185,  1296,   304,   117,   186,   117,   197,
     286,   186,   117,   223,   243,  1425,   305,   249,   305,   305,
     436,   702,   990,  1425,  1132,   246,   432,   246,   921,  1626,
    1174,   400,  1671,   987,   832,  1184,  1717,   766,  1406,  1314,
    1203,  1077,  1312,  1309,   537,  1225,  1230,  1233,  1238,   625,
     624,   677,   324,  1256,   802,  1695,   885,  1689,  1350,   406,
    1741,  1166,   409,   972,  1131,  1283,   413,  1293,  1292,  1750,
     442,  1327,   419,  1660,   442,  1096,  1338,  1087,  1331,   426,
    1497,   953,  1494,  1584,  1154,  1377,  1369,  1517,  1328,    -1,
      -1,   438,    -1,    -1,    -1,    -1,    -1,   444,    -1,    -1,
     447,  1602,    -1,    -1,    -1,    -1,    -1,    -1,   455,    -1,
      -1,  1403,  1404,    -1,   461,   462,   463,   464,    -1,    -1,
      -1,    -1,   469,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     477,    -1,    -1,    -1,    -1,  1545,    -1,  1429,    -1,  1431,
      -1,    -1,  1434,  1545,    -1,    -1,  1556,  1557,    -1,  1559,
      -1,    -1,    -1,  1445,  1556,  1557,  1566,  1559,  1450,  1746,
      -1,    -1,    -1,    -1,  1566,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1465,    -1,    -1,   523,  1764,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     537,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   546,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   578,    -1,    -1,    -1,  1645,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1645,    -1,  1655,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1655,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1560,    -1,
    1562,    -1,  1564,  1683,    -1,    -1,    -1,    -1,    -1,  1571,
      -1,  1683,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1717,    -1,    -1,
      -1,    -1,  1604,    -1,  1606,  1717,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   675,    -1,
    1622,  1741,    -1,  1625,    -1,    -1,    -1,    -1,    -1,  1741,
    1750,    -1,    -1,    -1,    -1,  1637,    -1,    -1,  1750,    -1,
      -1,    -1,   699,    -1,    -1,  1647,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1658,    -1,    -1,    -1,
      -1,    -1,    -1,   720,    -1,  1667,    -1,    -1,   725,   726,
      -1,    -1,    -1,  1675,    -1,    -1,    -1,    -1,  1680,    -1,
    1682,    -1,  1684,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     747,    -1,   749,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     757,    -1,  1704,   760,    -1,    -1,    -1,   764,    -1,    -1,
      -1,    -1,  1714,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1730,    -1,
      -1,    -1,    -1,    -1,    -1,  1737,    -1,    -1,    -1,    -1,
      -1,  1743,    -1,    -1,   801,    -1,    -1,    -1,    -1,    -1,
    1752,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1762,    -1,    -1,    -1,    -1,    -1,  1768,    -1,    -1,    -1,
      -1,  1773,    -1,    -1,   831,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   853,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   882,   883,   884,   885,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   920,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   934,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   961,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   970,    -1,   972,    -1,    -1,    -1,   976,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   989,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     570,   571,    -1,   573,   574,   575,   576,    -1,    -1,    -1,
      -1,    -1,    -1,   583,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1022,    -1,  1024,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   606,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   614,   615,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1081,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   673,    -1,  1102,    -1,   677,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   722,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1184,    -1,    -1,
    1187,    -1,    -1,    -1,    -1,   765,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1202,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1211,    -1,    -1,    -1,    -1,    -1,
     790,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1225,    -1,
     800,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1235,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1263,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   855,  1283,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1292,    -1,    -1,    -1,  1296,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   922,  1350,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1377,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   959,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1403,  1404,   978,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1000,    -1,  1429,    -1,  1431,    -1,    -1,  1434,    -1,    -1,
      -1,  1011,  1012,    -1,    -1,    -1,    -1,    -1,  1445,    -1,
      -1,    -1,    -1,  1450,    -1,    -1,  1026,    -1,    -1,  1029,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1465,    -1,
      -1,    -1,    -1,  1043,  1044,  1045,    -1,  1047,  1048,  1049,
    1050,  1051,  1052,    -1,  1054,  1055,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1077,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1119,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1560,    -1,  1562,    -1,  1564,    -1,    -1,
      -1,    -1,    -1,    -1,  1571,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1604,    -1,  1606,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1189,
      -1,  1191,    -1,  1193,    -1,  1622,  1196,    -1,  1625,    -1,
      -1,  1201,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1637,    -1,    -1,  1213,    -1,    -1,    -1,    -1,    -1,    -1,
    1647,    -1,  1222,    -1,    -1,    -1,    -1,    -1,  1228,  1229,
      -1,  1658,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1667,    -1,    -1,    -1,    -1,    -1,    -1,  1247,  1675,    -1,
      -1,    -1,    -1,  1680,    -1,  1682,    -1,  1684,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1704,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1714,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1730,    -1,    -1,    -1,    -1,    -1,    -1,
    1737,    -1,  1312,    -1,    -1,    -1,  1743,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1752,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1762,    -1,    -1,    -1,    -1,
      -1,  1768,    -1,    -1,    -1,    -1,  1773,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1390,    -1,    -1,    -1,  1394,    -1,    -1,    -1,  1398,    -1,
    1400,    -1,  1402,    -1,    -1,    -1,    -1,    -1,  1408,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1416,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1424,  1425,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1442,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1453,  1454,  1455,  1456,  1457,    -1,  1459,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1533,    -1,  1535,    -1,    -1,  1538,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1546,    -1,    -1,    -1,
      -1,  1551,  1552,    -1,    -1,    -1,    -1,    -1,    -1,  1559,
      -1,    -1,    -1,  1563,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1629,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1641,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1683,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1712,    -1,    -1,    -1,    -1,  1717,    -1,    -1,
      -1,    -1,  1722,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1740,    11,    12,    -1,    -1,    -1,    -1,    -1,  1748,    -1,
      20,    21,    22,    23,    24,    25,    26,    27,    -1,    29,
      -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
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
      51,    52,    53,    54,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    70,
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
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      -1,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    -1,    70,    71,    72,    73,    74,
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
      47,    48,    49,    50,    51,    52,    53,    54,    -1,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    -1,    70,    71,    72,    73,    74,    75,    76,
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
      49,    50,    51,    52,    53,    54,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    78,
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
      51,    52,    53,    54,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    70,
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
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      -1,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    -1,    70,    71,    72,    73,    74,
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
      47,    48,    49,    50,    51,    52,    53,    54,    -1,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    -1,    70,    71,    72,    73,    74,    75,    76,
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
      49,    50,    51,    52,    53,    54,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    78,
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
      21,    22,    23,    24,    25,    -1,    -1,    -1,    29,    -1,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    70,
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
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
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
      25,    -1,    -1,    -1,    29,    -1,    -1,    -1,    33,    34,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      -1,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    -1,    70,    71,    72,    73,    74,
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
     255,   256,    -1,   258,   259,   260,    -1,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    21,    22,    23,    24,    25,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    -1,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    -1,    70,    71,    72,    73,    74,    75,    76,
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
      49,    50,    51,    52,    53,    54,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    78,
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
      21,    22,    23,    24,    25,    -1,    -1,    -1,    29,    -1,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    70,
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
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      -1,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    -1,    94,
      95,    96,    97,    98,    99,   100,   101,    -1,    -1,   104,
     105,    -1,    -1,    -1,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,    -1,    -1,    -1,   123,    -1,
     125,   126,   127,   128,    -1,   130,    -1,    -1,    -1,   134,
     135,   136,   137,   138,    -1,    -1,    -1,    -1,    -1,    -1,
     145,   146,   147,   148,   149,   150,   151,   152,    -1,    -1,
     155,   156,    -1,   158,   159,    -1,    -1,    -1,    -1,   164,
     165,   166,   167,   168,   169,   170,   171,    -1,   173,    -1,
      -1,    -1,    -1,    -1,   179,   180,   181,    -1,    -1,    -1,
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
      47,    48,    49,    50,    51,    52,    53,    54,    -1,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    -1,    70,    71,    72,    73,    74,    75,    76,
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
     187,   188,    -1,    -1,    -1,   192,    -1,   194,    -1,   196,
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
      -1,    20,    -1,    -1,    -1,    24,    25,    -1,    -1,    -1,
      29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    78,
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
      51,    52,    53,    54,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    70,
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
     301,   302,   303,   304,   305,   306,   307,   308,    16,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    24,    25,    -1,    -1,
      -1,    29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
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
      -1,   179,   180,   181,    -1,    -1,    -1,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,    -1,   194,    -1,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,    -1,
      -1,   209,   210,    -1,    -1,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,    -1,
     258,   259,   260,    -1,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      25,    -1,    -1,    -1,    29,    -1,    -1,    -1,    33,    34,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      -1,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    -1,    70,    71,    72,    73,    74,
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
     255,   256,    -1,   258,   259,   260,    -1,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,    18,    19,    -1,    -1,    -1,    -1,
      24,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    72,    73,
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
     254,   255,   256,    -1,   258,   259,   260,    -1,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,    24,    25,    -1,    -1,    -1,
      29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    78,
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
     179,   180,   181,    -1,    -1,    -1,   185,   186,   187,   188,
      -1,    -1,    -1,   192,    -1,   194,    -1,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,    -1,    -1,
     209,   210,    -1,    -1,   213,   214,   215,   216,   217,   218,
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
      54,    -1,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    72,    73,
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
     254,   255,   256,    -1,   258,   259,   260,    -1,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,    24,    25,    -1,    -1,    -1,
      29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    78,
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
     249,   250,   251,   252,   253,   254,   255,   256,    -1,   258,
     259,   260,    -1,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
      24,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    72,    73,
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
     254,   255,   256,    -1,   258,   259,   260,    -1,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,    24,    25,    -1,    -1,    -1,
      29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    78,
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
     249,   250,   251,   252,   253,   254,   255,   256,    -1,   258,
     259,   260,    -1,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
      24,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    72,    73,
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
     254,   255,   256,    -1,   258,   259,   260,    -1,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,    24,    25,    -1,    -1,    -1,
      29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    78,
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
     249,   250,   251,   252,   253,   254,   255,   256,    -1,   258,
     259,   260,    -1,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
      24,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    72,    73,
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
     254,   255,   256,    -1,   258,   259,   260,    -1,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,    24,    25,    -1,    -1,    -1,
      29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    78,
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
      -1,    -1,    -1,    -1,    -1,   194,    -1,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,    -1,    -1,
     209,   210,    -1,    -1,   213,   214,   215,   216,   217,   218,
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
      34,    -1,    36,    37,    38,    -1,    40,    41,    42,    43,
      -1,    -1,    46,    47,    48,    -1,    50,    51,    52,    53,
      54,    -1,    56,    57,    58,    59,    -1,    61,    -1,    -1,
      64,    65,    66,    67,    68,    -1,    70,    -1,    72,    -1,
      -1,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      94,    95,    96,    -1,    -1,    99,   100,   101,    -1,    -1,
     104,   105,    -1,    -1,    -1,    -1,   110,   111,   112,   113,
     114,   115,   116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   125,   126,   127,   128,    -1,   130,    -1,    -1,    -1,
     134,   135,   136,   137,   138,    -1,    -1,    -1,    -1,    -1,
      -1,   145,   146,   147,    -1,   149,   150,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   158,   159,    -1,    -1,    -1,    -1,
     164,   165,   166,   167,   168,   169,   170,   171,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   179,   180,   181,    -1,    -1,
      -1,   185,    -1,   187,   188,    -1,    -1,    -1,    -1,    -1,
     194,    -1,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,    -1,    -1,    -1,   210,    -1,    -1,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,    -1,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,    -1,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,   258,   259,   260,    -1,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  xquery_parser::yystos_[] =
  {
         0,    11,    12,    20,    21,    22,    23,    24,    25,    26,
      27,    29,    33,    34,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    70,    71,    72,    73,
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
     356,   360,   362,   363,   365,   374,   377,   380,   381,   382,
     384,   385,   386,   387,   388,   390,   391,   393,   394,   395,
     396,   397,   398,   400,   401,   404,   405,   406,   407,   412,
     414,   416,   417,   422,   441,   444,   448,   451,   452,   457,
     458,   459,   460,   462,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   498,   499,   500,   501,   502,   503,
     504,   505,   506,   508,   509,   510,   524,   525,   527,   528,
     529,   530,   531,   532,   533,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   550,   553,   554,   555,   556,   561,
     562,   563,   564,   565,   566,   569,   627,   629,   630,   631,
      33,    34,    50,   213,   383,   384,   385,   383,   383,   155,
     155,    37,    38,    40,    41,    48,    57,    58,    75,    79,
     110,   111,   112,   159,   168,   200,   218,   228,   260,   286,
     287,   288,   289,   290,   292,   293,   294,   295,   296,   301,
     302,   361,   362,   366,   367,   368,   372,   373,   159,   152,
     155,   152,   155,   152,   155,    67,    72,   117,   409,   155,
     369,   155,    24,    34,    61,   117,   272,   421,   423,   424,
     152,   155,   155,   155,   117,   152,   155,   155,   155,    94,
     152,   219,   220,   121,   121,   121,   152,   155,    29,    39,
      43,    45,    47,    48,    49,    52,    60,    68,    71,    73,
      74,    76,    90,    91,    97,   104,   111,   113,   114,   134,
     137,   138,   168,   171,   179,   180,   188,   200,   222,   224,
     226,   227,   234,   236,   237,   238,   239,   242,   243,   492,
     629,   630,   121,   117,   392,   121,   121,    39,    44,    45,
      60,    62,    63,    71,    97,   223,   629,   117,   121,   121,
     183,   383,   385,    49,    73,    74,   117,   152,   186,   243,
     404,   406,   416,   629,   152,   121,    16,   628,   629,    18,
      19,   629,   121,   121,   121,   484,   152,    30,   212,   214,
     223,   225,   155,   223,   225,   223,   223,   228,   117,   111,
     362,   240,   240,   241,   155,   152,   387,   326,     0,   328,
     329,    33,    50,   331,   348,     1,   189,   325,   189,   325,
     111,   363,   386,   404,   106,   189,   106,   189,    42,    47,
      52,    70,   167,   170,   185,   210,   399,   408,   413,   414,
     415,   429,   430,   434,   166,    92,   131,   139,   140,   142,
     150,   154,   156,   161,   178,   201,   202,   203,   204,   205,
     206,   476,   477,   248,   157,   175,   197,   116,   145,   158,
     192,   199,   208,   135,   149,    51,   198,   100,   101,   157,
     175,   475,   152,   481,   484,   190,   191,   153,   496,   497,
     492,   496,   492,   155,   496,   120,   144,   155,   183,   183,
     183,    29,   364,   499,   364,   627,   181,   194,   181,   194,
     165,   181,   630,   629,   168,   200,    48,   629,   151,   117,
      45,    48,    79,   105,   167,   628,   219,   220,   221,   299,
     300,   245,   600,   629,   292,   629,   297,   297,   299,   300,
     303,   136,   141,   111,   366,   286,   294,   373,   628,   384,
     385,   186,   383,    45,    63,   186,   549,   550,   404,   186,
     192,   629,   283,   283,   418,   419,   629,   117,   425,   117,
     186,   370,   371,   152,   389,   404,     1,   159,   627,   112,
     159,   344,   627,   629,   117,   141,   106,   404,    29,   186,
     628,   629,   629,   442,   443,   629,   384,   186,   404,   404,
     551,   629,   384,   152,   152,   404,   186,   192,   629,   629,
     141,   442,   183,   183,   155,   155,   155,   629,   152,   186,
     185,    35,   512,   513,   514,   404,     8,   174,    17,   404,
     212,    29,   405,   405,   186,   405,   405,   405,   405,   229,
     567,   568,   629,   392,   111,   189,   189,   405,   404,   385,
     404,   244,   402,   403,   189,   325,   189,   325,     3,   332,
     348,   381,   332,   348,   381,    33,   349,   381,   349,   381,
     392,   392,   405,   117,   167,   169,   169,   386,   405,   405,
     459,   460,   462,   462,   462,   462,   461,   462,   462,   462,
      71,   466,   466,   465,   467,   467,   467,   467,   468,   468,
     469,   469,   229,    94,    94,    94,   183,   404,   484,   484,
     404,   497,   186,   405,   507,   628,   148,   186,   507,   106,
     186,   186,   106,   106,   369,    29,   630,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,   351,   352,   353,
      94,   136,   141,   357,   358,   359,   629,   159,   159,   351,
     627,   126,   131,    55,    57,    99,   250,   263,   265,   276,
     277,   278,   280,   282,   601,   602,   603,   604,   605,   606,
     613,   619,   620,   245,    94,   235,   376,   298,   629,   141,
     405,   117,   629,   629,   131,   183,   183,   186,   186,   183,
     106,   186,   106,   186,   106,    36,    94,    96,   146,   420,
     421,   535,   629,    56,   215,   253,   410,   411,   629,    94,
     106,   186,   383,   186,   628,    96,    45,   628,   627,    96,
     141,   535,   629,   405,   424,   183,   186,   186,   186,   186,
     106,   187,   146,   535,   183,   186,   186,   152,   183,   384,
     384,   183,   106,   186,   106,   186,   141,   535,   405,   187,
     404,   404,   404,   629,   513,   514,   129,   195,   183,   183,
     130,   189,    94,   216,   217,   231,    94,   216,   217,   231,
      94,   235,   223,   106,   233,   141,   392,   189,   186,    49,
      73,    74,   243,   406,   416,   183,   493,   573,   403,   348,
      33,    33,   189,   325,   189,   112,   629,   169,   405,   435,
     436,   117,   431,   432,   462,   152,   155,   258,   480,   499,
     574,   577,   578,   579,   580,   581,   585,   587,   589,   590,
      48,   151,   155,   209,   536,   538,   540,   541,   557,   558,
     559,   560,   629,   536,   534,   540,   534,   183,   184,   106,
     186,   186,   499,   147,   164,   147,   164,   136,   389,   369,
     352,   131,   538,   359,   405,   535,   627,   627,   127,   128,
     627,   276,   277,   278,   282,   629,   262,   273,   262,   273,
      29,   285,    96,   112,   155,   607,   610,   601,    39,    44,
      60,    62,    71,    97,   223,   375,   541,   290,   291,   225,
     298,   307,   405,   629,    94,   376,   298,   627,   152,   551,
     552,   629,   551,   552,   117,   126,   536,   117,   405,   146,
     421,   146,    36,   146,   420,   421,   146,   535,   253,    54,
      59,    77,   117,   420,   426,   427,   428,   411,   535,   536,
     371,    94,   183,   196,   131,   343,   627,   159,   131,    96,
     343,   405,   141,   421,   152,   117,   405,   405,   146,    99,
     445,   446,   447,   449,   450,    99,   453,   454,   455,   456,
     384,   183,   183,   152,   551,   551,   405,   141,   189,   405,
     186,   186,   186,    35,   514,   129,   195,     9,    10,   102,
     122,   124,   152,   193,   509,   511,   522,   523,   526,    29,
     230,   232,   405,   405,   405,   230,   232,   405,   405,   405,
     405,   405,   405,   117,   405,   405,   386,   155,   155,   155,
     152,   185,   244,   570,   571,   155,   208,   387,   189,   112,
     381,   381,   381,   435,    95,   105,   115,   126,   437,   438,
     439,   440,   106,   629,   106,   404,   574,   581,   152,   284,
     463,   626,    96,   168,   251,   252,   254,   261,   271,   283,
     575,   576,   595,   596,   597,   598,   621,   624,   257,   259,
     582,   600,   266,   586,   622,   246,   247,   269,   591,   592,
     155,   155,   538,   155,   143,   175,   192,   537,   143,   405,
     136,   389,   553,   358,   285,    29,    96,   112,   155,   614,
      29,   607,   376,   537,   225,   225,   482,   286,   305,   535,
     375,   225,   189,   383,   186,   186,   143,   186,   186,   419,
     146,   420,   629,   405,   146,   405,   126,   405,   146,   421,
     146,   405,   146,   117,   117,   405,   629,   428,    77,   536,
     386,   405,   627,   106,   343,   405,   141,   383,   443,   405,
     405,   112,   446,   447,    99,   185,   112,   447,   450,   117,
     536,    99,   112,   454,    99,   112,   456,   183,   383,   186,
     186,   405,   196,   453,   131,   193,   511,     7,   384,   629,
     193,   522,   189,   231,   231,   231,   231,   235,   568,   185,
     404,   404,   404,   573,   571,   117,   493,   627,   127,   128,
     439,   440,   440,   436,   105,   433,   432,   183,   186,   574,
     588,   249,   215,   253,   267,   274,   625,    96,   255,   256,
     623,   249,   578,   625,   465,   595,   579,   146,   281,   583,
     584,   623,   285,   594,    78,   593,   186,   192,   536,   539,
     186,   186,   186,    29,   135,   199,   616,   617,   618,    29,
     615,   616,   270,   611,   106,   608,   169,   629,   256,   376,
     482,   183,   405,   146,   405,   146,   420,   405,   146,   405,
     405,   629,   629,   427,   405,   125,   125,    96,   627,   405,
     183,   185,   185,   405,   386,   405,   185,   185,   629,   185,
     117,   536,   117,   185,   117,   536,   185,   183,   112,   514,
     629,   193,   183,   514,   629,   405,   405,   405,   405,   405,
     405,   186,   186,   186,   152,   155,   572,   629,   440,   627,
     183,   467,    53,   128,   465,   465,   268,   275,   285,   599,
     599,   580,   152,   279,    94,   186,   106,   186,   614,   614,
     618,   106,   186,    29,   612,   623,   609,   610,   186,   378,
     379,   482,   117,   223,   306,   286,   169,   405,   405,   146,
     405,    54,   386,   405,   343,   405,   386,    94,   386,   405,
     629,   185,   629,   405,   629,   185,   386,   117,    93,   182,
     515,   514,   629,   195,   514,   196,   453,   404,   117,   106,
     186,   465,   465,   197,   404,   536,   536,    94,    29,   264,
     106,   106,   440,   535,   629,   117,   223,   629,   378,   405,
     117,   536,    94,   185,    94,   629,     5,   132,   518,   519,
     521,   523,    28,   133,   516,   517,   520,   523,   195,   514,
     195,   112,   183,   629,   117,   387,   465,   183,   536,   610,
     379,   440,   304,   629,   117,   223,   629,   185,   536,   386,
     405,   536,   185,    93,   132,   521,   182,   133,   520,   195,
     117,   106,   186,   629,   405,   304,   629,   117,   386,   405,
     185,   185,   629,   117,   572,   106,   186,   292,   304,   629,
     185,   629,   117,   387,   305,   405,   305,   106,   186,   629,
     482,   482,   117,   572,   186,   197,   629,   387,   286,   186,
     629,   572,   223,   117,   629,   305,   482
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
     373,   373,   373,   373,   373,   373,   373,   373,   373,   373,
     373,   373,   373,   373,   374,   374,   374,   374,   374,   374,
     374,   374,   375,   375,   376,   376,   377,   377,   378,   378,
     379,   379,   379,   379,   380,   380,   380,   380,   381,   382,
     382,   382,   383,   383,   383,   384,   384,   385,   385,   386,
     386,   386,   386,   386,   386,   386,   386,   386,   386,   386,
     386,   387,   387,   388,   389,   390,   391,   391,   391,   391,
     391,   392,   392,   392,   392,   393,   394,   395,   396,   397,
     397,   398,   399,   400,   401,   402,   402,   403,   403,   403,
     403,   404,   404,   405,   405,   405,   405,   405,   405,   406,
     406,   406,   406,   406,   406,   406,   407,   408,   409,   409,
     410,   410,   410,   411,   411,   412,   412,   413,   414,   414,
     414,   415,   415,   415,   415,   415,   416,   416,   417,   418,
     418,   419,   419,   419,   419,   419,   419,   419,   419,   419,
     419,   419,   419,   420,   421,   422,   423,   423,   424,   424,
     424,   424,   425,   425,   426,   426,   426,   427,   427,   427,
     428,   428,   428,   429,   430,   431,   431,   432,   432,   433,
     434,   434,   435,   435,   436,   436,   437,   437,   437,   437,
     437,   437,   437,   438,   438,   439,   439,   440,   441,   441,
     442,   442,   443,   443,   444,   445,   445,   446,   447,   447,
     448,   449,   449,   450,   451,   451,   452,   452,   453,   453,
     454,   454,   455,   455,   456,   456,   457,   458,   458,   459,
     459,   460,   460,   460,   460,   460,   461,   460,   460,   460,
     460,   462,   462,   463,   463,   464,   464,   465,   465,   465,
     466,   466,   466,   466,   466,   467,   467,   467,   468,   468,
     468,   469,   469,   470,   470,   471,   471,   472,   472,   473,
     473,   474,   474,   474,   474,   475,   475,   475,   476,   476,
     476,   476,   476,   476,   477,   477,   477,   478,   478,   478,
     478,   479,   479,   480,   480,   481,   481,   481,   482,   482,
     482,   482,   483,   484,   484,   484,   485,   485,   486,   486,
     486,   486,   487,   487,   488,   488,   488,   488,   488,   488,
     488,   489,   489,   490,   490,   491,   491,   491,   491,   491,
     492,   492,   493,   493,   494,   494,   494,   494,   495,   495,
     495,   495,   496,   496,   497,   498,   498,   498,   498,   498,
     498,   498,   498,   498,   498,   499,   499,   500,   500,   500,
     501,   502,   502,   503,   504,   505,   506,   506,   507,   507,
     508,   508,   509,   509,   509,   510,   510,   510,   510,   510,
     510,   511,   511,   512,   512,   513,   514,   514,   515,   515,
     516,   516,   517,   517,   517,   517,   518,   518,   519,   519,
     519,   519,   520,   520,   521,   521,   522,   522,   522,   522,
     523,   523,   523,   523,   524,   524,   525,   525,   526,   527,
     527,   527,   527,   527,   527,   528,   529,   529,   530,   530,
     531,   532,   533,   533,   534,   534,   535,   536,   536,   536,
     537,   537,   537,   538,   538,   538,   538,   538,   539,   539,
     540,   541,   541,   541,   541,   541,   541,   541,   541,   541,
     542,   543,   543,   543,   544,   545,   546,   546,   546,   547,
     547,   547,   547,   547,   548,   549,   549,   549,   549,   549,
     549,   549,   550,   551,   552,   553,   554,   554,   555,   556,
     557,   557,   558,   559,   559,   560,   561,   561,   561,   562,
     562,   562,   562,   562,   562,   562,   562,   562,   562,   563,
     563,   564,   564,   565,   566,   567,   567,   568,   569,   570,
     570,   571,   571,   571,   571,   572,   573,   573,   574,   575,
     575,   576,   576,   577,   577,   578,   578,   579,   579,   580,
     580,   581,   582,   582,   583,   583,   584,   585,   585,   585,
     586,   586,   587,   588,   588,   589,   590,   590,   591,   591,
     592,   592,   592,   593,   593,   594,   594,   595,   595,   595,
     595,   595,   596,   597,   598,   599,   599,   599,   600,   600,
     601,   601,   601,   601,   601,   601,   601,   601,   602,   602,
     602,   602,   603,   603,   604,   605,   605,   606,   606,   606,
     607,   607,   608,   608,   609,   609,   610,   611,   611,   612,
     612,   613,   613,   613,   614,   614,   615,   615,   616,   616,
     617,   617,   618,   618,   619,   620,   620,   621,   621,   621,
     622,   623,   623,   623,   623,   624,   624,   625,   625,   626,
     627,   628,   628,   629,   629,   629,   629,   629,   629,   629,
     629,   629,   629,   629,   629,   629,   629,   629,   629,   630,
     630,   630,   630,   630,   630,   630,   630,   630,   630,   630,
     630,   630,   630,   630,   630,   630,   630,   630,   630,   630,
     630,   630,   630,   630,   630,   630,   630,   630,   630,   630,
     630,   630,   630,   630,   630,   630,   630,   630,   630,   630,
     630,   630,   630,   630,   630,   630,   630,   630,   630,   630,
     630,   630,   630,   630,   630,   630,   630,   630,   630,   630,
     630,   630,   630,   630,   630,   630,   630,   630,   630,   630,
     630,   630,   630,   630,   630,   630,   630,   630,   630,   630,
     630,   630,   630,   630,   630,   630,   630,   630,   630,   630,
     630,   630,   630,   630,   630,   630,   630,   630,   630,   630,
     630,   630,   630,   630,   630,   630,   630,   630,   630,   630,
     630,   630,   630,   630,   630,   630,   630,   630,   630,   630,
     630,   630,   630,   630,   630,   630,   630,   630,   630,   630,
     630,   630,   630,   630,   630,   630,   630,   630,   630,   630,
     630,   630,   630,   630,   630,   630,   630,   630,   630,   630,
     630,   630,   630,   630,   630,   630,   630,   630,   630,   630,
     630,   630,   630,   630,   630,   630,   630,   630,   630,   630,
     630,   630,   630,   630,   630,   630,   630,   630,   630,   630,
     630,   630,   630,   630,   630,   630,   630,   630,   630,   630,
     630,   630,   630,   630,   630,   630,   630,   630,   630,   631,
     631
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
       2,     3,     4,     5,     1,     3,     2,     3,     1,     2,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     2,
       1,     2,     2,     2,     3,     4,     5,     6,     4,     5,
       6,     7,     1,     2,     3,     3,     8,     9,     1,     3,
       1,     2,     2,     3,    11,    14,    13,    22,     1,     1,
       1,     0,     1,     1,     0,     1,     2,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     2,     3,     3,     2,     3,     2,     3,     3,
       4,     2,     3,     4,     5,     5,     2,     4,     5,     3,
       3,     2,     2,     8,     3,     1,     2,     3,     7,    10,
      13,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     2,
       1,     1,     2,     4,     3,     5,     4,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     3,     1,
       4,     3,     5,     4,     6,     4,     6,     5,     7,     4,
       5,     5,     6,     3,     3,     2,     1,     3,     4,     5,
       3,     6,     4,     5,     1,     2,     3,     1,     2,     1,
       6,     3,     3,     2,     3,     1,     3,     2,     3,     2,
       3,     4,     1,     3,     1,     2,     1,     1,     1,     2,
       2,     2,     3,     1,     1,     2,     2,     2,     5,     5,
       1,     4,     3,     4,     8,     1,     2,     3,     2,     3,
       8,     1,     2,     3,     8,    10,     8,    10,     1,     2,
       4,     7,     1,     2,     4,     7,     8,     1,     3,     1,
       3,     1,     3,     3,     3,     3,     0,     4,     3,     3,
       3,     1,     5,     0,     1,     1,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     4,     1,     4,     1,     4,     1,     4,     1,
       2,     1,     1,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     5,     5,
       6,     3,     4,     1,     2,     3,     2,     2,     1,     2,
       2,     1,     1,     1,     3,     3,     1,     1,     1,     2,
       1,     2,     2,     1,     2,     2,     2,     2,     2,     2,
       2,     1,     2,     2,     1,     2,     2,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       3,     4,     1,     2,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     3,     1,     4,     4,     3,     4,     1,     3,
       1,     1,     1,     1,     1,     4,     5,     8,     9,     9,
      10,     1,     2,     1,     2,     6,     0,     1,     3,     3,
       0,     1,     1,     1,     2,     2,     0,     1,     1,     1,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     2,     3,     3,     2,     1,
       1,     1,     1,     1,     1,     4,     3,     7,     3,     7,
       4,     4,     3,     7,     1,     2,     2,     1,     2,     3,
       1,     1,     1,     1,     1,     3,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     4,     4,     3,     3,     3,     4,     4,     3,
       4,     6,     4,     6,     4,     3,     4,     6,     6,     4,
       6,     6,     4,     1,     2,     1,     1,     1,     3,     3,
       1,     1,     4,     5,     6,     3,     3,     3,     3,     5,
       7,     7,     5,     5,     5,     7,     7,     5,     5,     3,
       3,     5,     7,     5,     7,     1,     4,     3,     5,     1,
       2,     3,     7,    10,    13,     3,     1,     3,     2,     0,
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1
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
  "\"'document'\"", "\"'document-node'\"", "\"'element'\"", "\"'eval'\"",
  "\"'for'\"", "\"'function'\"", "\"'if'\"", "\"'import'\"",
  "\"'instance'\"", "\"'let'\"", "\"'most'\"", "\"'next'\"", "\"'no'\"",
  "\"'only'\"", "\"'option'\"", "\"'ordering'\"", "\"'previous'\"",
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
  "Param", "DeclPropertyList", "DeclProperty", "CollectionDecl",
  "CollectionTypeDecl", "NodeModifier", "IndexDecl", "IndexKeyList",
  "IndexKeySpec", "IntegrityConstraintDecl", "QueryBody",
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
      29,   189,    -1,   331,   189,   381,    -1,   348,   189,   381,
      -1,   331,   189,   348,   189,   381,    -1,   381,    -1,   331,
     325,   381,    -1,   348,   325,   381,    -1,   331,   189,   348,
     325,   381,    -1,   331,   325,   348,   189,   381,    -1,   330,
      -1,   330,   331,   189,    -1,   330,   348,   189,    -1,   330,
     331,   189,   348,   189,    -1,    34,   159,   628,   131,   627,
     189,    -1,   332,    -1,   331,   189,   332,    -1,   331,   325,
     332,    -1,   333,    -1,   341,    -1,   346,    -1,   347,    -1,
     355,    -1,   334,    -1,   335,    -1,   336,    -1,   337,    -1,
     338,    -1,   339,    -1,   340,    -1,   561,    -1,    33,    38,
     181,    -1,    33,    38,   194,    -1,    33,   112,   105,   627,
      -1,    33,    37,   627,    -1,    33,    40,   181,    -1,    33,
      40,   194,    -1,    33,    58,   168,    -1,    33,    58,   200,
      -1,    33,   112,   167,   126,   127,    -1,    33,   112,   167,
     126,   128,    -1,    33,    41,   181,   106,   147,    -1,    33,
      41,   181,   106,   164,    -1,    33,    41,   165,   106,   147,
      -1,    33,    41,   165,   106,   164,    -1,   342,    -1,   345,
      -1,    50,    24,     1,    -1,    50,    61,   627,    -1,    50,
      61,   344,   627,    -1,    50,    61,   627,    96,   343,    -1,
      50,    61,   344,   627,    96,   343,    -1,   627,    -1,   343,
     106,   627,    -1,   159,   628,   131,    -1,   112,    45,   159,
      -1,    50,    34,   627,    -1,    50,    34,   159,   628,   131,
     627,    -1,    50,    34,   627,    96,   343,    -1,    50,    34,
     159,   628,   131,   627,    96,   343,    -1,    33,   159,   628,
     131,   627,    -1,    33,   112,    45,   159,   627,    -1,    33,
     112,    48,   159,   627,    -1,   349,    -1,   348,   189,   349,
      -1,   348,   325,   349,    -1,   350,    -1,   354,    -1,   356,
      -1,   360,    -1,   365,    -1,   374,    -1,   377,    -1,   380,
      -1,    33,   112,    79,   351,    -1,    33,    79,   629,   351,
      -1,   352,    -1,   351,   352,    -1,   353,   131,   553,    -1,
      80,    -1,    88,    -1,    81,    -1,    82,    -1,    83,    -1,
      84,    -1,    89,    -1,    85,    -1,    86,    -1,    87,    -1,
      33,    57,   629,    29,    -1,    33,   260,   600,    -1,    33,
     110,   151,   357,    -1,    94,   538,   358,    -1,   358,    -1,
     359,    -1,   136,    -1,   136,   359,    -1,   141,   405,    -1,
      33,   361,   141,   405,    -1,    33,   361,   136,    -1,    33,
     361,   136,   141,   405,    -1,   111,   117,   629,    -1,   111,
     117,   629,   535,    -1,   362,   111,   117,   629,    -1,   362,
     111,   117,   629,   535,    -1,   363,    -1,   362,   363,    -1,
      26,    -1,    26,   155,   364,   186,    -1,    27,    -1,    27,
     155,   364,   186,    -1,   499,    -1,   364,   106,   499,    -1,
      33,   366,    -1,    33,   362,   366,    -1,   367,    -1,   368,
      -1,    48,   630,   369,   389,    -1,    48,   630,   369,   136,
      -1,    75,    48,   630,   369,   389,    -1,    75,    48,   630,
     369,   136,    -1,   155,   186,    -1,   155,   370,   186,    -1,
     155,   186,    94,   536,    -1,   155,   370,   186,    94,   536,
      -1,   371,    -1,   370,   106,   371,    -1,   117,   629,    -1,
     117,   629,   535,    -1,   373,    -1,   372,   373,    -1,   287,
      -1,   288,    -1,   289,    -1,   290,    -1,   168,    -1,   200,
      -1,   228,   300,    -1,   228,   299,    -1,   301,   300,    -1,
     301,   299,    -1,   292,    -1,   293,   292,    -1,   296,   297,
      -1,   295,   297,    -1,    33,   286,   629,    -1,    33,   286,
     629,   376,    -1,    33,   286,   629,    94,   375,    -1,    33,
     286,   629,    94,   375,   376,    -1,    33,   372,   286,   629,
      -1,    33,   372,   286,   629,   376,    -1,    33,   372,   286,
     629,    94,   375,    -1,    33,   372,   286,   629,    94,   375,
     376,    -1,   541,    -1,   541,   537,    -1,   235,   291,   225,
      -1,   235,   290,   225,    -1,    33,   294,   629,   298,   225,
     482,   169,   378,    -1,    33,   372,   294,   629,   298,   225,
     482,   169,   378,    -1,   379,    -1,   378,   106,   379,    -1,
     482,    -1,   482,   535,    -1,   482,   440,    -1,   482,   535,
     440,    -1,    33,   302,   303,   629,   298,   286,   629,   117,
     629,   304,   405,    -1,    33,   302,   303,   629,   298,   286,
     629,   223,   117,   629,   304,   292,   305,   482,    -1,    33,
     302,   303,   629,   298,   286,   629,   306,   223,   117,   629,
     304,   405,    -1,    33,   302,   303,   629,   307,   305,   256,
     286,   629,   223,   117,   629,   305,   482,   197,   286,   629,
     223,   117,   629,   305,   482,    -1,   382,    -1,   384,    -1,
     385,    -1,    -1,   384,    -1,   385,    -1,    -1,   404,    -1,
     385,   404,    -1,   386,    -1,   385,   386,    -1,   387,    -1,
     390,    -1,   393,    -1,   394,    -1,   395,    -1,   396,    -1,
     397,    -1,   398,    -1,   400,    -1,   452,    -1,   448,    -1,
     401,    -1,   152,   385,   183,    -1,   152,   183,    -1,   152,
     383,   183,    -1,   152,   383,   183,    -1,   391,   189,    -1,
     391,   106,   392,    -1,   111,   392,    -1,   236,   111,   392,
      -1,   362,   111,   392,    -1,   236,   362,   111,   392,    -1,
     117,   629,    -1,   117,   629,   535,    -1,   117,   629,   141,
     405,    -1,   117,   629,   535,   141,   405,    -1,   117,   629,
     141,   405,   189,    -1,   406,   189,    -1,   239,   241,   405,
     189,    -1,   242,   155,   404,   186,   386,    -1,   237,   240,
     189,    -1,   238,   240,   189,    -1,   416,   399,    -1,   185,
     386,    -1,    49,   155,   404,   186,   196,   386,   125,   386,
      -1,   243,   387,   402,    -1,   403,    -1,   402,   403,    -1,
     244,   573,   387,    -1,   244,   573,   155,   117,   629,   186,
     387,    -1,   244,   573,   155,   117,   629,   106,   117,   629,
     186,   387,    -1,   244,   573,   155,   117,   629,   106,   117,
     629,   106,   117,   629,   186,   387,    -1,   405,    -1,   404,
     106,   405,    -1,   407,    -1,   444,    -1,   451,    -1,   457,
      -1,   569,    -1,   406,    -1,   458,    -1,   441,    -1,   562,
      -1,   563,    -1,   565,    -1,   564,    -1,   566,    -1,   416,
     408,    -1,   185,   405,    -1,    67,   283,    -1,    72,   283,
      -1,   215,    -1,   253,    -1,    56,   253,    -1,   410,   426,
      77,   405,    -1,   410,    77,   405,    -1,    47,   409,   425,
     411,   411,    -1,    47,   409,   425,   411,    -1,    42,   117,
     629,    -1,   417,    -1,   422,    -1,   412,    -1,   414,    -1,
     429,    -1,   434,    -1,   430,    -1,   413,    -1,   414,    -1,
     416,   415,    -1,    47,   117,   418,    -1,   419,    -1,   418,
     106,   117,   419,    -1,   629,   146,   405,    -1,   629,    36,
     126,   146,   405,    -1,   629,   535,   146,   405,    -1,   629,
     535,    36,   126,   146,   405,    -1,   629,   420,   146,   405,
      -1,   629,    36,   126,   420,   146,   405,    -1,   629,   535,
     420,   146,   405,    -1,   629,   535,    36,   126,   420,   146,
     405,    -1,   629,   421,   146,   405,    -1,   629,   535,   421,
     146,   405,    -1,   629,   420,   421,   146,   405,    -1,   629,
     535,   420,   421,   146,   405,    -1,    96,   117,   629,    -1,
     272,   117,   629,    -1,    52,   423,    -1,   424,    -1,   423,
     106,   424,    -1,   117,   629,   141,   405,    -1,   117,   629,
     535,   141,   405,    -1,   421,   141,   405,    -1,   117,   629,
     535,   421,   141,   405,    -1,   117,   629,   146,   405,    -1,
     117,   629,   535,   146,   405,    -1,   427,    -1,   117,   629,
      -1,   117,   629,   427,    -1,   420,    -1,   420,   428,    -1,
     428,    -1,    59,   117,   629,    54,   117,   629,    -1,    54,
     117,   629,    -1,    59,   117,   629,    -1,   210,   405,    -1,
     170,   169,   431,    -1,   432,    -1,   431,   106,   432,    -1,
     117,   629,    -1,   117,   629,   433,    -1,   105,   627,    -1,
     167,   169,   435,    -1,    70,   167,   169,   435,    -1,   436,
      -1,   435,   106,   436,    -1,   405,    -1,   405,   437,    -1,
     438,    -1,   439,    -1,   440,    -1,   438,   439,    -1,   438,
     440,    -1,   439,   440,    -1,   438,   439,   440,    -1,    95,
      -1,   115,    -1,   126,   127,    -1,   126,   128,    -1,   105,
     627,    -1,    68,   117,   442,   187,   405,    -1,   134,   117,
     442,   187,   405,    -1,   443,    -1,   442,   106,   117,   443,
      -1,   629,   146,   405,    -1,   629,   535,   146,   405,    -1,
      73,   155,   404,   186,   445,   112,   185,   405,    -1,   446,
      -1,   445,   446,    -1,   447,   185,   405,    -1,    99,   405,
      -1,   447,    99,   405,    -1,    73,   155,   404,   186,   449,
     112,   185,   386,    -1,   450,    -1,   449,   450,    -1,   447,
     185,   386,    -1,    74,   155,   404,   186,   453,   112,   185,
     405,    -1,    74,   155,   404,   186,   453,   112,   117,   629,
     185,   405,    -1,    74,   155,   404,   186,   455,   112,   185,
     386,    -1,    74,   155,   404,   186,   453,   112,   117,   629,
     185,   386,    -1,   454,    -1,   453,   454,    -1,    99,   536,
     185,   405,    -1,    99,   117,   629,    94,   536,   185,   405,
      -1,   456,    -1,   455,   456,    -1,    99,   536,   185,   386,
      -1,    99,   117,   629,    94,   536,   185,   386,    -1,    49,
     155,   404,   186,   196,   405,   125,   405,    -1,   459,    -1,
     458,   166,   459,    -1,   460,    -1,   459,    92,   460,    -1,
     462,    -1,   462,   476,   462,    -1,   462,   477,   462,    -1,
     462,   131,   462,    -1,   462,   161,   462,    -1,    -1,   462,
     156,   461,   462,    -1,   462,   154,   462,    -1,   462,   142,
     462,    -1,   462,   140,   462,    -1,   464,    -1,   464,   248,
      71,   574,   463,    -1,    -1,   626,    -1,   465,    -1,   465,
     197,   465,    -1,   466,    -1,   465,   175,   466,    -1,   465,
     157,   466,    -1,   467,    -1,   466,   192,   467,    -1,   466,
     116,   467,    -1,   466,   145,   467,    -1,   466,   158,   467,
      -1,   468,    -1,   467,   199,   468,    -1,   467,   208,   468,
      -1,   469,    -1,   468,   149,   469,    -1,   468,   135,   469,
      -1,   470,    -1,   470,    51,   229,   536,    -1,   471,    -1,
     471,   198,    94,   536,    -1,   472,    -1,   472,   100,    94,
     534,    -1,   473,    -1,   473,   101,    94,   534,    -1,   475,
      -1,   474,   475,    -1,   175,    -1,   157,    -1,   474,   175,
      -1,   474,   157,    -1,   478,    -1,   482,    -1,   479,    -1,
     201,    -1,   206,    -1,   205,    -1,   204,    -1,   203,    -1,
     202,    -1,   150,    -1,   178,    -1,   139,    -1,    76,   152,
     384,   183,    -1,    76,   220,   152,   384,   183,    -1,    76,
     219,   152,   384,   183,    -1,    76,    94,   551,   152,   384,
     183,    -1,   480,   152,   183,    -1,   480,   152,   404,   183,
      -1,   481,    -1,   480,   481,    -1,   176,   629,    17,    -1,
     176,    18,    -1,   176,    19,    -1,   483,    -1,   483,   484,
      -1,   191,   484,    -1,   484,    -1,   190,    -1,   485,    -1,
     485,   190,   484,    -1,   485,   191,   484,    -1,   486,    -1,
     495,    -1,   487,    -1,   487,   496,    -1,   490,    -1,   490,
     496,    -1,   488,   492,    -1,   489,    -1,   104,   121,    -1,
     113,   121,    -1,    97,   121,    -1,   188,   121,    -1,   114,
     121,    -1,   138,   121,    -1,   137,   121,    -1,   492,    -1,
      98,   492,    -1,   491,   492,    -1,   119,    -1,   171,   121,
      -1,    90,   121,    -1,   180,   121,    -1,   179,   121,    -1,
      91,   121,    -1,   541,    -1,   493,    -1,   629,    -1,   494,
      -1,   192,    -1,    11,    -1,    12,    -1,    20,    -1,   498,
      -1,   495,   496,    -1,   495,   155,   186,    -1,   495,   155,
     507,   186,    -1,   497,    -1,   496,   497,    -1,   153,   404,
     184,    -1,   499,    -1,   501,    -1,   502,    -1,   503,    -1,
     506,    -1,   508,    -1,   504,    -1,   505,    -1,   554,    -1,
     388,    -1,   500,    -1,   553,    -1,   109,    -1,   148,    -1,
     123,    -1,   117,   629,    -1,   155,   186,    -1,   155,   404,
     186,    -1,   118,    -1,   168,   152,   404,   183,    -1,   200,
     152,   404,   183,    -1,   630,   155,   186,    -1,   630,   155,
     507,   186,    -1,   405,    -1,   507,   106,   405,    -1,   509,
      -1,   527,    -1,   510,    -1,   524,    -1,   525,    -1,   156,
     629,   514,   129,    -1,   156,   629,   512,   514,   129,    -1,
     156,   629,   514,   195,   193,   629,   514,   195,    -1,   156,
     629,   514,   195,   511,   193,   629,   514,   195,    -1,   156,
     629,   512,   514,   195,   193,   629,   514,   195,    -1,   156,
     629,   512,   514,   195,   511,   193,   629,   514,   195,    -1,
     522,    -1,   511,   522,    -1,   513,    -1,   512,   513,    -1,
      35,   629,   514,   131,   514,   515,    -1,    -1,    35,    -1,
     182,   516,   182,    -1,    93,   518,    93,    -1,    -1,   517,
      -1,   133,    -1,   520,    -1,   517,   133,    -1,   517,   520,
      -1,    -1,   519,    -1,   132,    -1,   521,    -1,   519,   132,
      -1,   519,   521,    -1,    28,    -1,   523,    -1,     5,    -1,
     523,    -1,   509,    -1,    10,    -1,   526,    -1,   523,    -1,
       9,    -1,   122,    -1,   124,    -1,   152,   384,   183,    -1,
     211,    30,   212,    -1,   211,   212,    -1,   173,   628,   174,
      -1,   173,   628,     8,    -1,   102,     7,    -1,   528,    -1,
     529,    -1,   530,    -1,   531,    -1,   532,    -1,   533,    -1,
      43,   152,   383,   183,    -1,    21,   383,   183,    -1,    45,
     152,   404,   183,   152,   383,   183,    -1,    22,   383,   183,
      -1,    97,   152,   404,   183,   152,   383,   183,    -1,    71,
     152,   384,   183,    -1,    39,   152,   384,   183,    -1,    23,
     383,   183,    -1,    60,   152,   404,   183,   152,   383,   183,
      -1,   540,    -1,   540,   143,    -1,    94,   536,    -1,   538,
      -1,   538,   537,    -1,   209,   155,   186,    -1,   143,    -1,
     192,    -1,   175,    -1,   540,    -1,   541,    -1,   151,   155,
     186,    -1,   557,    -1,   560,    -1,   536,    -1,   539,   106,
     536,    -1,   629,    -1,   543,    -1,   549,    -1,   547,    -1,
     550,    -1,   548,    -1,   546,    -1,   545,    -1,   544,    -1,
     542,    -1,   223,   155,   186,    -1,    44,   155,   186,    -1,
      44,   155,   549,   186,    -1,    44,   155,   550,   186,    -1,
      71,   155,   186,    -1,    39,   155,   186,    -1,    60,   155,
     186,    -1,    60,   155,   628,   186,    -1,    60,   155,    29,
     186,    -1,    97,   155,   186,    -1,    97,   155,   629,   186,
      -1,    97,   155,   629,   106,   551,   186,    -1,    97,   155,
     192,   186,    -1,    97,   155,   192,   106,   551,   186,    -1,
      62,   155,   629,   186,    -1,    45,   155,   186,    -1,    45,
     155,   629,   186,    -1,    45,   155,   629,   106,   551,   186,
      -1,    45,   155,   629,   106,   552,   186,    -1,    45,   155,
     192,   186,    -1,    45,   155,   192,   106,   551,   186,    -1,
      45,   155,   192,   106,   552,   186,    -1,    63,   155,   629,
     186,    -1,   629,    -1,   629,   143,    -1,    29,    -1,   555,
      -1,   556,    -1,   629,   144,   148,    -1,    48,   369,   389,
      -1,   558,    -1,   559,    -1,    48,   155,   192,   186,    -1,
      48,   155,   186,    94,   536,    -1,    48,   155,   539,   186,
      94,   536,    -1,   155,   538,   186,    -1,    33,   218,   219,
      -1,    33,   218,   220,    -1,    33,   218,   221,    -1,   224,
     223,   405,   231,   405,    -1,   224,   223,   405,    94,   230,
     231,   405,    -1,   224,   223,   405,    94,   232,   231,   405,
      -1,   224,   223,   405,   216,   405,    -1,   224,   223,   405,
     217,   405,    -1,   224,   225,   405,   231,   405,    -1,   224,
     225,   405,    94,   230,   231,   405,    -1,   224,   225,   405,
      94,   232,   231,   405,    -1,   224,   225,   405,   216,   405,
      -1,   224,   225,   405,   217,   405,    -1,   222,   223,   405,
      -1,   222,   225,   405,    -1,   227,   223,   405,   235,   405,
      -1,   227,   228,   229,   223,   405,   235,   405,    -1,   226,
     223,   405,    94,   405,    -1,   234,   117,   567,   233,   405,
     185,   405,    -1,   568,    -1,   567,   106,   117,   568,    -1,
     629,   141,   405,    -1,   243,   152,   404,   183,   570,    -1,
     571,    -1,   570,   571,    -1,   244,   573,   572,    -1,   244,
     573,   155,   117,   629,   186,   572,    -1,   244,   573,   155,
     117,   629,   106,   117,   629,   186,   572,    -1,   244,   573,
     155,   117,   629,   106,   117,   629,   106,   117,   629,   186,
     572,    -1,   152,   404,   183,    -1,   493,    -1,   573,   208,
     493,    -1,   577,   575,    -1,    -1,   576,    -1,   595,    -1,
     576,   595,    -1,   578,    -1,   577,   261,   578,    -1,   579,
      -1,   578,   257,   579,    -1,   580,    -1,   579,   259,   146,
     580,    -1,   581,    -1,   258,   581,    -1,   585,   582,   583,
      -1,    -1,   600,    -1,    -1,   584,    -1,   281,   152,   404,
     183,    -1,   589,   586,    -1,   155,   574,   186,    -1,   587,
      -1,    -1,   622,    -1,   480,   152,   588,   183,    -1,    -1,
     574,    -1,   590,   591,    -1,   499,    -1,   152,   404,   183,
      -1,    -1,   592,    -1,   247,   593,    -1,   246,   594,    -1,
     269,    -1,    -1,    78,    -1,    -1,   285,    -1,   596,    -1,
     597,    -1,   598,    -1,   624,    -1,   621,    -1,   168,    -1,
     283,   465,   599,    -1,   252,   623,   599,    -1,   285,    -1,
     275,    -1,   268,    -1,   245,   601,    -1,   600,   245,   601,
      -1,   602,    -1,   603,    -1,   604,    -1,   619,    -1,   605,
      -1,   613,    -1,   606,    -1,   620,    -1,    99,   273,    -1,
      99,   262,    -1,   265,    -1,   280,    -1,   250,   273,    -1,
     250,   262,    -1,    57,   629,    29,    -1,   276,    -1,    55,
     276,    -1,   278,   607,    -1,   278,   155,   607,   608,   186,
      -1,    55,   278,    -1,   610,    -1,   112,    -1,    -1,   106,
     609,    -1,   610,    -1,   609,   106,   610,    -1,    96,    29,
     611,   612,    -1,    -1,   270,    29,    -1,    -1,   623,   264,
      -1,   277,   285,   614,   616,    -1,   277,   285,   112,   616,
      -1,    55,   277,   285,    -1,    96,    29,    -1,   155,   615,
     186,    -1,    29,    -1,   615,   106,    29,    -1,    -1,   617,
      -1,   618,    -1,   617,   618,    -1,   199,   614,    -1,   135,
     614,    -1,   263,    29,    -1,   282,    -1,    55,   282,    -1,
      96,   215,    -1,    96,   253,    -1,   254,   249,    -1,   266,
     623,   279,    -1,   255,   465,    -1,    96,   128,   465,    -1,
      96,    53,   465,    -1,   256,   465,   197,   465,    -1,   271,
     625,    -1,   251,   625,    -1,   274,    -1,   267,    -1,   284,
     249,   467,    -1,    29,    -1,    16,    -1,   629,    -1,   630,
      -1,    97,    -1,    39,    -1,    44,    -1,    45,    -1,   151,
      -1,    49,    -1,   223,    -1,    60,    -1,    62,    -1,    63,
      -1,    71,    -1,    74,    -1,    73,    -1,   209,    -1,   242,
      -1,   631,    -1,    24,    -1,   213,    -1,   126,    -1,    38,
      -1,   260,    -1,    37,    -1,   220,    -1,   219,    -1,   145,
      -1,    43,    -1,   258,    -1,   259,    -1,   273,    -1,   262,
      -1,   250,    -1,   284,    -1,   276,    -1,   278,    -1,   277,
      -1,   282,    -1,   254,    -1,   249,    -1,    78,    -1,   215,
      -1,   253,    -1,    53,    -1,   221,    -1,   234,    -1,   301,
      -1,   228,    -1,   201,    -1,   206,    -1,   205,    -1,   204,
      -1,   203,    -1,   202,    -1,    96,    -1,   110,    -1,   111,
      -1,   185,    -1,    47,    -1,    36,    -1,    67,    -1,    72,
      -1,    59,    -1,    54,    -1,    56,    -1,    77,    -1,    42,
      -1,   146,    -1,    52,    -1,   210,    -1,   169,    -1,   170,
      -1,   167,    -1,    70,    -1,    95,    -1,   115,    -1,   127,
      -1,   128,    -1,   105,    -1,    68,    -1,   134,    -1,   187,
      -1,    99,    -1,    94,    -1,   196,    -1,   125,    -1,   166,
      -1,    92,    -1,    51,    -1,   229,    -1,   100,    -1,   197,
      -1,   116,    -1,   158,    -1,   199,    -1,   149,    -1,   135,
      -1,    76,    -1,   101,    -1,   198,    -1,   150,    -1,   181,
      -1,   194,    -1,   159,    -1,   136,    -1,   130,    -1,   165,
      -1,   147,    -1,   164,    -1,    33,    -1,    40,    -1,    58,
      -1,   112,    -1,    41,    -1,    57,    -1,   214,    -1,    50,
      -1,    61,    -1,    34,    -1,    48,    -1,   272,    -1,   248,
      -1,   281,    -1,   283,    -1,   252,    -1,   266,    -1,   279,
      -1,   271,    -1,   251,    -1,   265,    -1,   280,    -1,   270,
      -1,   264,    -1,   263,    -1,   247,    -1,   246,    -1,   255,
      -1,   256,    -1,   285,    -1,   275,    -1,   274,    -1,   269,
      -1,   267,    -1,   268,    -1,   227,    -1,   233,    -1,   230,
      -1,   224,    -1,   217,    -1,   216,    -1,   218,    -1,   235,
      -1,   225,    -1,   226,    -1,   232,    -1,   222,    -1,   231,
      -1,    66,    -1,    64,    -1,    75,    -1,   168,    -1,   200,
      -1,   241,    -1,   236,    -1,   239,    -1,   240,    -1,   237,
      -1,   238,    -1,   243,    -1,   244,    -1,    46,    -1,   245,
      -1,    65,    -1,   294,    -1,   292,    -1,   293,    -1,   298,
      -1,   299,    -1,   300,    -1,   295,    -1,   296,    -1,   297,
      -1,    79,    -1,    80,    -1,    81,    -1,    82,    -1,    83,
      -1,    84,    -1,    85,    -1,    86,    -1,    87,    -1,    88,
      -1,    89,    -1,   286,    -1,   287,    -1,   288,    -1,   289,
      -1,   290,    -1,   291,    -1,   302,    -1,   303,    -1,   304,
      -1,   305,    -1,   306,    -1,   307,    -1,   308,    -1,    90,
      -1,   104,    -1,   113,    -1,   171,    -1,   179,    -1,   188,
      -1,   137,    -1,    91,    -1,   114,    -1,   138,    -1,   180,
      -1,   627,   120,   628,    -1,    25,    -1
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
     473,   476,   480,   485,   491,   493,   497,   500,   504,   506,
     509,   511,   513,   515,   517,   519,   521,   524,   527,   530,
     533,   535,   538,   541,   544,   548,   553,   559,   566,   571,
     577,   584,   592,   594,   597,   601,   605,   614,   624,   626,
     630,   632,   635,   638,   642,   654,   669,   683,   706,   708,
     710,   712,   713,   715,   717,   718,   720,   723,   725,   728,
     730,   732,   734,   736,   738,   740,   742,   744,   746,   748,
     750,   752,   756,   759,   763,   767,   770,   774,   777,   781,
     785,   790,   793,   797,   802,   808,   814,   817,   822,   828,
     832,   836,   839,   842,   851,   855,   857,   860,   864,   872,
     883,   897,   899,   903,   905,   907,   909,   911,   913,   915,
     917,   919,   921,   923,   925,   927,   929,   932,   935,   938,
     941,   943,   945,   948,   953,   957,   963,   968,   972,   974,
     976,   978,   980,   982,   984,   986,   988,   990,   993,   997,
     999,  1004,  1008,  1014,  1019,  1026,  1031,  1038,  1044,  1052,
    1057,  1063,  1069,  1076,  1080,  1084,  1087,  1089,  1093,  1098,
    1104,  1108,  1115,  1120,  1126,  1128,  1131,  1135,  1137,  1140,
    1142,  1149,  1153,  1157,  1160,  1164,  1166,  1170,  1173,  1177,
    1180,  1184,  1189,  1191,  1195,  1197,  1200,  1202,  1204,  1206,
    1209,  1212,  1215,  1219,  1221,  1223,  1226,  1229,  1232,  1238,
    1244,  1246,  1251,  1255,  1260,  1269,  1271,  1274,  1278,  1281,
    1285,  1294,  1296,  1299,  1303,  1312,  1323,  1332,  1343,  1345,
    1348,  1353,  1361,  1363,  1366,  1371,  1379,  1388,  1390,  1394,
    1396,  1400,  1402,  1406,  1410,  1414,  1418,  1419,  1424,  1428,
    1432,  1436,  1438,  1444,  1445,  1447,  1449,  1453,  1455,  1459,
    1463,  1465,  1469,  1473,  1477,  1481,  1483,  1487,  1491,  1493,
    1497,  1501,  1503,  1508,  1510,  1515,  1517,  1522,  1524,  1529,
    1531,  1534,  1536,  1538,  1541,  1544,  1546,  1548,  1550,  1552,
    1554,  1556,  1558,  1560,  1562,  1564,  1566,  1568,  1573,  1579,
    1585,  1592,  1596,  1601,  1603,  1606,  1610,  1613,  1616,  1618,
    1621,  1624,  1626,  1628,  1630,  1634,  1638,  1640,  1642,  1644,
    1647,  1649,  1652,  1655,  1657,  1660,  1663,  1666,  1669,  1672,
    1675,  1678,  1680,  1683,  1686,  1688,  1691,  1694,  1697,  1700,
    1703,  1705,  1707,  1709,  1711,  1713,  1715,  1717,  1719,  1721,
    1724,  1728,  1733,  1735,  1738,  1742,  1744,  1746,  1748,  1750,
    1752,  1754,  1756,  1758,  1760,  1762,  1764,  1766,  1768,  1770,
    1772,  1775,  1778,  1782,  1784,  1789,  1794,  1798,  1803,  1805,
    1809,  1811,  1813,  1815,  1817,  1819,  1824,  1830,  1839,  1849,
    1859,  1870,  1872,  1875,  1877,  1880,  1887,  1888,  1890,  1894,
    1898,  1899,  1901,  1903,  1905,  1908,  1911,  1912,  1914,  1916,
    1918,  1921,  1924,  1926,  1928,  1930,  1932,  1934,  1936,  1938,
    1940,  1942,  1944,  1946,  1950,  1954,  1957,  1961,  1965,  1968,
    1970,  1972,  1974,  1976,  1978,  1980,  1985,  1989,  1997,  2001,
    2009,  2014,  2019,  2023,  2031,  2033,  2036,  2039,  2041,  2044,
    2048,  2050,  2052,  2054,  2056,  2058,  2062,  2064,  2066,  2068,
    2072,  2074,  2076,  2078,  2080,  2082,  2084,  2086,  2088,  2090,
    2092,  2096,  2100,  2105,  2110,  2114,  2118,  2122,  2127,  2132,
    2136,  2141,  2148,  2153,  2160,  2165,  2169,  2174,  2181,  2188,
    2193,  2200,  2207,  2212,  2214,  2217,  2219,  2221,  2223,  2227,
    2231,  2233,  2235,  2240,  2246,  2253,  2257,  2261,  2265,  2269,
    2275,  2283,  2291,  2297,  2303,  2309,  2317,  2325,  2331,  2337,
    2341,  2345,  2351,  2359,  2365,  2373,  2375,  2380,  2384,  2390,
    2392,  2395,  2399,  2407,  2418,  2432,  2436,  2438,  2442,  2445,
    2446,  2448,  2450,  2453,  2455,  2459,  2461,  2465,  2467,  2472,
    2474,  2477,  2481,  2482,  2484,  2485,  2487,  2492,  2495,  2499,
    2501,  2502,  2504,  2509,  2510,  2512,  2515,  2517,  2521,  2522,
    2524,  2527,  2530,  2532,  2533,  2535,  2536,  2538,  2540,  2542,
    2544,  2546,  2548,  2550,  2554,  2558,  2560,  2562,  2564,  2567,
    2571,  2573,  2575,  2577,  2579,  2581,  2583,  2585,  2587,  2590,
    2593,  2595,  2597,  2600,  2603,  2607,  2609,  2612,  2615,  2621,
    2624,  2626,  2628,  2629,  2632,  2634,  2638,  2643,  2644,  2647,
    2648,  2651,  2656,  2661,  2665,  2668,  2672,  2674,  2678,  2679,
    2681,  2683,  2686,  2689,  2692,  2695,  2697,  2700,  2703,  2706,
    2709,  2713,  2716,  2720,  2724,  2729,  2732,  2735,  2737,  2739,
    2743,  2745,  2747,  2749,  2751,  2753,  2755,  2757,  2759,  2761,
    2763,  2765,  2767,  2769,  2771,  2773,  2775,  2777,  2779,  2781,
    2783,  2785,  2787,  2789,  2791,  2793,  2795,  2797,  2799,  2801,
    2803,  2805,  2807,  2809,  2811,  2813,  2815,  2817,  2819,  2821,
    2823,  2825,  2827,  2829,  2831,  2833,  2835,  2837,  2839,  2841,
    2843,  2845,  2847,  2849,  2851,  2853,  2855,  2857,  2859,  2861,
    2863,  2865,  2867,  2869,  2871,  2873,  2875,  2877,  2879,  2881,
    2883,  2885,  2887,  2889,  2891,  2893,  2895,  2897,  2899,  2901,
    2903,  2905,  2907,  2909,  2911,  2913,  2915,  2917,  2919,  2921,
    2923,  2925,  2927,  2929,  2931,  2933,  2935,  2937,  2939,  2941,
    2943,  2945,  2947,  2949,  2951,  2953,  2955,  2957,  2959,  2961,
    2963,  2965,  2967,  2969,  2971,  2973,  2975,  2977,  2979,  2981,
    2983,  2985,  2987,  2989,  2991,  2993,  2995,  2997,  2999,  3001,
    3003,  3005,  3007,  3009,  3011,  3013,  3015,  3017,  3019,  3021,
    3023,  3025,  3027,  3029,  3031,  3033,  3035,  3037,  3039,  3041,
    3043,  3045,  3047,  3049,  3051,  3053,  3055,  3057,  3059,  3061,
    3063,  3065,  3067,  3069,  3071,  3073,  3075,  3077,  3079,  3081,
    3083,  3085,  3087,  3089,  3091,  3093,  3095,  3097,  3099,  3101,
    3103,  3105,  3107,  3109,  3111,  3113,  3115,  3117,  3119,  3121,
    3123,  3125,  3127,  3129,  3131,  3133,  3135,  3137,  3139,  3141,
    3143,  3145,  3147,  3149,  3151,  3153,  3155,  3157,  3159,  3161,
    3163,  3165,  3167,  3169,  3171,  3173,  3175,  3177,  3179,  3181,
    3185
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,  1023,  1023,  1024,  1033,  1042,  1048,  1056,  1062,  1073,
    1078,  1086,  1093,  1100,  1109,  1116,  1124,  1132,  1140,  1151,
    1156,  1163,  1170,  1182,  1192,  1199,  1206,  1218,  1219,  1220,
    1221,  1222,  1227,  1228,  1229,  1230,  1231,  1232,  1233,  1236,
    1241,  1246,  1254,  1262,  1270,  1275,  1283,  1288,  1296,  1301,
    1309,  1316,  1323,  1330,  1340,  1342,  1345,  1355,  1360,  1368,
    1376,  1387,  1394,  1405,  1410,  1418,  1425,  1432,  1441,  1454,
    1462,  1469,  1479,  1486,  1493,  1504,  1505,  1506,  1507,  1508,
    1509,  1510,  1511,  1516,  1522,  1531,  1538,  1548,  1558,  1559,
    1560,  1561,  1562,  1563,  1564,  1565,  1566,  1567,  1572,  1580,
    1588,  1596,  1603,  1611,  1618,  1623,  1631,  1639,  1654,  1669,
    1687,  1692,  1700,  1708,  1719,  1724,  1733,  1738,  1745,  1750,
    1760,  1765,  1774,  1780,  1793,  1798,  1806,  1817,  1832,  1844,
    1859,  1864,  1869,  1874,  1882,  1889,  1900,  1905,  1915,  1921,
    1931,  1935,  1941,  1945,  1949,  1953,  1959,  1965,  1971,  1977,
    1983,  1987,  1993,  1999,  2006,  2014,  2022,  2030,  2038,  2050,
    2064,  2078,  2095,  2099,  2108,  2112,  2119,  2127,  2145,  2151,
    2160,  2165,  2172,  2179,  2190,  2200,  2210,  2220,  2238,  2258,
    2263,  2268,  2275,  2280,  2285,  2292,  2297,  2309,  2316,  2328,
    2329,  2330,  2331,  2332,  2333,  2334,  2336,  2337,  2338,  2339,
    2340,  2345,  2350,  2358,  2375,  2383,  2391,  2398,  2405,  2412,
    2419,  2429,  2441,  2454,  2466,  2482,  2490,  2498,  2506,  2521,
    2526,  2534,  2548,  2565,  2590,  2598,  2605,  2616,  2622,  2628,
    2639,  2654,  2659,  2674,  2675,  2676,  2677,  2678,  2679,  2684,
    2685,  2688,  2689,  2690,  2691,  2692,  2697,  2711,  2719,  2724,
    2732,  2737,  2742,  2750,  2759,  2771,  2781,  2794,  2802,  2803,
    2804,  2809,  2810,  2811,  2812,  2813,  2818,  2825,  2835,  2843,
    2850,  2860,  2870,  2880,  2890,  2900,  2910,  2920,  2930,  2941,
    2950,  2960,  2970,  2986,  2995,  3004,  3012,  3018,  3030,  3038,
    3048,  3056,  3068,  3074,  3085,  3087,  3091,  3099,  3103,  3108,
    3112,  3116,  3120,  3130,  3138,  3145,  3151,  3162,  3166,  3175,
    3183,  3189,  3199,  3205,  3215,  3219,  3229,  3235,  3241,  3247,
    3256,  3265,  3274,  3287,  3291,  3299,  3305,  3315,  3323,  3332,
    3345,  3352,  3364,  3368,  3380,  3387,  3393,  3402,  3409,  3415,
    3426,  3433,  3439,  3448,  3457,  3464,  3475,  3482,  3494,  3500,
    3512,  3518,  3529,  3535,  3546,  3552,  3563,  3572,  3576,  3585,
    3589,  3597,  3601,  3611,  3618,  3627,  3637,  3636,  3650,  3659,
    3668,  3681,  3685,  3698,  3701,  3708,  3712,  3721,  3725,  3729,
    3738,  3742,  3748,  3754,  3760,  3771,  3775,  3779,  3787,  3791,
    3797,  3807,  3811,  3821,  3825,  3835,  3839,  3849,  3853,  3863,
    3867,  3875,  3879,  3883,  3887,  3897,  3901,  3905,  3913,  3917,
    3921,  3925,  3929,  3933,  3941,  3945,  3949,  3957,  3961,  3965,
    3969,  3980,  3986,  3996,  4002,  4012,  4016,  4020,  4058,  4062,
    4072,  4082,  4095,  4104,  4114,  4118,  4127,  4131,  4140,  4146,
    4154,  4160,  4172,  4178,  4188,  4192,  4196,  4200,  4204,  4210,
    4216,  4224,  4228,  4236,  4240,  4251,  4255,  4259,  4265,  4269,
    4283,  4287,  4295,  4299,  4309,  4313,  4317,  4321,  4330,  4334,
    4338,  4342,  4350,  4356,  4366,  4374,  4378,  4382,  4386,  4390,
    4394,  4398,  4402,  4406,  4416,  4424,  4428,  4436,  4443,  4450,
    4461,  4469,  4473,  4481,  4489,  4497,  4551,  4555,  4568,  4574,
    4584,  4588,  4596,  4600,  4604,  4612,  4622,  4632,  4642,  4652,
    4662,  4677,  4683,  4694,  4700,  4711,  4722,  4724,  4728,  4733,
    4743,  4746,  4753,  4759,  4765,  4773,  4786,  4789,  4796,  4802,
    4808,  4815,  4826,  4830,  4840,  4844,  4854,  4858,  4862,  4867,
    4876,  4882,  4888,  4894,  4902,  4907,  4915,  4920,  4928,  4936,
    4941,  4946,  4951,  4956,  4961,  4970,  4978,  4982,  4999,  5003,
    5011,  5019,  5027,  5031,  5039,  5045,  5055,  5063,  5067,  5071,
    5106,  5112,  5118,  5128,  5132,  5136,  5140,  5144,  5151,  5157,
    5167,  5175,  5179,  5183,  5187,  5191,  5195,  5199,  5203,  5207,
    5215,  5223,  5227,  5231,  5241,  5249,  5257,  5261,  5265,  5273,
    5277,  5283,  5289,  5293,  5303,  5311,  5315,  5321,  5330,  5339,
    5345,  5351,  5361,  5378,  5385,  5400,  5436,  5440,  5448,  5456,
    5468,  5472,  5480,  5488,  5492,  5503,  5520,  5526,  5532,  5542,
    5546,  5552,  5558,  5562,  5568,  5572,  5578,  5584,  5591,  5601,
    5606,  5614,  5620,  5630,  5652,  5661,  5667,  5680,  5694,  5701,
    5707,  5717,  5722,  5727,  5737,  5751,  5759,  5765,  5783,  5792,
    5795,  5802,  5807,  5815,  5819,  5826,  5830,  5837,  5841,  5848,
    5852,  5861,  5874,  5877,  5885,  5888,  5896,  5904,  5912,  5916,
    5924,  5927,  5935,  5947,  5950,  5958,  5970,  5976,  5986,  5989,
    5997,  6001,  6005,  6013,  6016,  6024,  6027,  6035,  6039,  6043,
    6047,  6051,  6059,  6067,  6079,  6091,  6095,  6099,  6107,  6113,
    6123,  6127,  6131,  6135,  6139,  6143,  6147,  6151,  6159,  6163,
    6167,  6171,  6179,  6185,  6195,  6205,  6209,  6217,  6227,  6238,
    6245,  6249,  6257,  6260,  6267,  6272,  6281,  6291,  6294,  6302,
    6305,  6313,  6322,  6329,  6339,  6343,  6350,  6356,  6366,  6369,
    6376,  6381,  6393,  6401,  6413,  6421,  6425,  6433,  6437,  6441,
    6449,  6457,  6461,  6465,  6469,  6477,  6485,  6497,  6501,  6509,
    6522,  6526,  6527,  6540,  6541,  6542,  6543,  6544,  6545,  6546,
    6547,  6548,  6549,  6550,  6551,  6552,  6553,  6554,  6555,  6559,
    6560,  6561,  6562,  6563,  6564,  6565,  6566,  6567,  6568,  6569,
    6570,  6571,  6572,  6573,  6574,  6575,  6576,  6577,  6578,  6579,
    6580,  6581,  6582,  6583,  6584,  6585,  6586,  6587,  6588,  6589,
    6590,  6591,  6592,  6593,  6594,  6595,  6596,  6597,  6598,  6599,
    6600,  6601,  6602,  6603,  6604,  6605,  6606,  6607,  6608,  6609,
    6610,  6611,  6612,  6613,  6614,  6615,  6616,  6617,  6618,  6619,
    6620,  6621,  6622,  6623,  6624,  6625,  6626,  6627,  6628,  6629,
    6630,  6631,  6632,  6633,  6634,  6635,  6636,  6637,  6638,  6639,
    6640,  6641,  6642,  6643,  6644,  6645,  6646,  6647,  6648,  6649,
    6650,  6651,  6652,  6653,  6654,  6655,  6656,  6657,  6658,  6659,
    6660,  6661,  6662,  6663,  6664,  6665,  6666,  6667,  6668,  6669,
    6670,  6671,  6672,  6673,  6674,  6675,  6676,  6677,  6678,  6679,
    6680,  6681,  6682,  6683,  6684,  6685,  6686,  6687,  6688,  6689,
    6690,  6691,  6692,  6693,  6694,  6695,  6696,  6697,  6698,  6699,
    6700,  6701,  6702,  6703,  6704,  6705,  6706,  6707,  6708,  6709,
    6710,  6711,  6712,  6713,  6714,  6715,  6716,  6717,  6718,  6719,
    6720,  6721,  6722,  6723,  6724,  6725,  6726,  6727,  6728,  6729,
    6730,  6731,  6732,  6733,  6734,  6735,  6736,  6737,  6738,  6739,
    6740,  6741,  6742,  6743,  6744,  6745,  6746,  6747,  6748,  6749,
    6750,  6751,  6752,  6753,  6754,  6755,  6756,  6757,  6758,  6763,
    6770
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
  const int xquery_parser::yylast_ = 13514;
  const int xquery_parser::yynnts_ = 309;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 588;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 323;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 577;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


} // zorba

/* Line 1136 of lalr1.cc  */
#line 16689 "/Users/pjl/src/flwor/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.cpp"


/* Line 1138 of lalr1.cc  */
#line 6774 "/Users/pjl/src/flwor/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"


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

