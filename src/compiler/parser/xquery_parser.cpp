/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002-2010 Free Software Foundation, Inc.
   
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

/* Line 310 of lalr1.cc  */
#line 72 "F:/xquery/src/compiler/parser/xquery_parser.y"


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



/* Line 310 of lalr1.cc  */
#line 77 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"


#include "xquery_parser.hpp"

/* User implementation prologue.  */

/* Line 316 of lalr1.cc  */
#line 865 "F:/xquery/src/compiler/parser/xquery_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 316 of lalr1.cc  */
#line 965 "F:/xquery/src/compiler/parser/xquery_parser.y"

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
  XQUERY_ERROR err = CollectionDecl::validatePropertyList(static_cast<DeclPropertyList*>(props));
  if (err != XQ_NO_ERROR)
  {
    driver.set_expr(new ParseErrorNode(driver.createQueryLoc(loc),
                                       err,
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
  XQUERY_ERROR err = AST_IndexDecl::validatePropertyList(static_cast<DeclPropertyList*>(props));
  if (err != XQ_NO_ERROR)
  {
    driver.set_expr(new ParseErrorNode(driver.createQueryLoc(loc),
                                       err,
                                       static_cast<QName*>(qname)->get_qname(),
                                       true));
    return false;
  }
  return true;
}



/* Line 316 of lalr1.cc  */
#line 148 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"

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

/* Line 379 of lalr1.cc  */
#line 214 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
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
        case 109: /* "\"'DECIMAL'\"" */

/* Line 479 of lalr1.cc  */
#line 863 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 479 of lalr1.cc  */
#line 321 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 123: /* "\"'DOUBLE'\"" */

/* Line 479 of lalr1.cc  */
#line 862 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 479 of lalr1.cc  */
#line 330 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 148: /* "\"'INTEGER'\"" */

/* Line 479 of lalr1.cc  */
#line 861 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 479 of lalr1.cc  */
#line 339 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "VersionDecl" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 348 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "MainModule" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 357 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "LibraryModule" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 366 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "ModuleDecl" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 375 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "SIND_DeclList" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 384 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "VFO_DeclList" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 393 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "SIND_Decl" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 402 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "VFO_Decl" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 411 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "DecimalFormatDecl" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 420 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "DecimalFormatParamList" */

/* Line 479 of lalr1.cc  */
#line 886 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 479 of lalr1.cc  */
#line 429 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "DecimalFormatParam" */

/* Line 479 of lalr1.cc  */
#line 886 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 479 of lalr1.cc  */
#line 438 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "Setter" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 447 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "Import" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 456 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "NamespaceDecl" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 465 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "BoundarySpaceDecl" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 474 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "DefaultNamespaceDecl" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 483 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "OptionDecl" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 492 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "FTOptionDecl" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 501 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "OrderingModeDecl" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 510 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "EmptyOrderDecl" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 519 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "CopyNamespacesDecl" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 528 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "DefaultCollationDecl" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 537 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "BaseURIDecl" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 546 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "SchemaImport" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 555 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "URILiteralList" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 564 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "SchemaPrefix" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 573 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "ModuleImport" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 582 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "CtxItemDecl" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 591 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "CtxItemDecl2" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 600 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "CtxItemDecl3" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 609 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "CtxItemDecl4" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 618 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "VarNameAndType" */

/* Line 479 of lalr1.cc  */
#line 886 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 479 of lalr1.cc  */
#line 627 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "VarDecl" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 636 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "DeclPropertyList" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 645 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "DeclProperty" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 654 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "CollectionDecl" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 663 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "NodeModifier" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 672 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "IndexDecl" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 681 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "IndexKeyList" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 690 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "IndexKeySpec" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 699 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "IntegrityConstraintDecl" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 708 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "ConstructionDecl" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 717 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "FunctionSig" */

/* Line 479 of lalr1.cc  */
#line 886 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 479 of lalr1.cc  */
#line 726 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "BlockExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 735 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "Block" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 744 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "BlockDecls" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 753 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "BlockVarDeclList" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 762 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "BlockVarDecl" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 771 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "AssignExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 780 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "ExitExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 789 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "WhileExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 798 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "FlowCtlStatement" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 807 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "AnnotationList" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 816 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "Annotation" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 825 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "AnnotationLiteralList" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 834 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "FunctionDecl" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 843 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "FunctionDecl2" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 852 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "FunctionDeclSimple" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 861 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "FunctionDeclSequential" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 870 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "FunctionDeclUpdating" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 879 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "ParamList" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 888 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "Param" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 897 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "EnclosedExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 906 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "BracedExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 915 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "QueryBody" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 924 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "Expr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 933 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "ApplyExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 942 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "ConcatExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 951 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "ExprSingle" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 960 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "FLWORExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 969 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "ReturnExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 978 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "FLWORWinCond" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 987 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "WindowClause" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 996 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "CountClause" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1005 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "ForLetWinClause" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1014 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "FLWORClauseList" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1023 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "ForClause" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1032 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "VarInDeclList" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1041 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "VarInDecl" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1050 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "PositionalVar" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1059 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "FTScoreVar" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1068 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "LetClause" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1077 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "VarGetsDeclList" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1086 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "EvalVarDeclList" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1095 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "EvalVarDecl" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1104 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "VarGetsDecl" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1113 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "WindowVarDecl" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1122 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "WindowVars" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1131 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "WindowVars3" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1140 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "WindowVars2" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1149 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "WhereClause" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1158 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "GroupByClause" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1167 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "GroupSpecList" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1176 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "GroupSpec" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1185 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "GroupCollationSpec" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1194 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "OrderByClause" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1203 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "OrderSpecList" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1212 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "OrderSpec" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1221 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "OrderModifier" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1230 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "OrderDirSpec" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1239 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "OrderEmptySpec" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1248 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "OrderCollationSpec" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1257 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "QuantifiedExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1266 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "QVarInDeclList" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1275 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "QVarInDecl" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1284 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "SwitchExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1293 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "SwitchCaseClauseList" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1302 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "SwitchCaseClause" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1311 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "SwitchCaseOperandList" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1320 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "TypeswitchExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1329 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "CaseClauseList" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1338 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "CaseClause" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1347 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "IfExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1356 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "OrExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1365 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "AndExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1374 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "ComparisonExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1383 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "FTContainsExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1392 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "opt_FTIgnoreOption" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1401 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "RangeExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1410 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "AdditiveExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1419 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "MultiplicativeExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1428 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "UnionExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1437 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "IntersectExceptExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1446 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "InstanceofExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1455 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "TreatExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1464 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "CastableExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1473 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "CastExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1482 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "UnaryExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1491 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "SignList" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1500 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "ValueExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1509 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "ValueComp" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1518 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "NodeComp" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1527 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "ValidateExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1536 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "ExtensionExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1545 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "Pragma_list" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1554 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "Pragma" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1563 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "PathExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1572 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "RelativePathExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1581 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "StepExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1590 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "AxisStep" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1599 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "ForwardStep" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1608 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "ForwardAxis" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1617 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "AbbrevForwardStep" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1626 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "ReverseStep" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1635 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "ReverseAxis" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1644 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "NodeTest" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1653 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "NameTest" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1662 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "Wildcard" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1671 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "FilterExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1680 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "PredicateList" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1689 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "Predicate" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1698 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "PrimaryExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1707 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "Literal" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1716 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "NumericLiteral" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1725 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "VarRef" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1734 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "ParenthesizedExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1743 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "ContextItemExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1752 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "OrderedExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1761 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "UnorderedExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1770 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "FunctionCall" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1779 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "ArgList" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1788 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "Constructor" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1797 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "DirectConstructor" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1806 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "DirElemConstructor" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1815 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "DirElemContentList" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1824 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "DirAttributeList" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1833 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "DirAttr" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1842 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "DirAttributeValue" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1851 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "opt_QuoteAttrContentList" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1860 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "QuoteAttrContentList" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1869 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "opt_AposAttrContentList" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1878 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "AposAttrContentList" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1887 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "QuoteAttrValueContent" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1896 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "AposAttrValueContent" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1905 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "DirElemContent" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1914 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "CommonContent" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1923 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "DirCommentConstructor" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1932 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "DirPIConstructor" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1941 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "CDataSection" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1950 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "ComputedConstructor" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1959 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "CompDocConstructor" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1968 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "CompElemConstructor" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1977 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "CompAttrConstructor" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1986 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "CompTextConstructor" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1995 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "CompCommentConstructor" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2004 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "CompPIConstructor" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2013 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "SingleType" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2022 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "TypeDeclaration" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2031 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "SequenceType" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2040 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "OccurrenceIndicator" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2049 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "ItemType" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2058 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "TypeList" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2067 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* "AtomicType" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2076 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* "KindTest" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2085 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* "AnyKindTest" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2094 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* "DocumentTest" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2103 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "TextTest" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2112 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* "CommentTest" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2121 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 533: /* "PITest" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2130 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 534: /* "AttributeTest" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2139 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 535: /* "SchemaAttributeTest" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2148 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 536: /* "ElementTest" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2157 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 537: /* "SchemaElementTest" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2166 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* "TypeName" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2175 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 539: /* "TypeName_WITH_HOOK" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2184 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 540: /* "StringLiteral" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2193 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 545: /* "AnyFunctionTest" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2202 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 546: /* "TypedFunctionTest" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2211 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 549: /* "InsertExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2220 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 550: /* "DeleteExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2229 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 551: /* "ReplaceExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2238 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 552: /* "RenameExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2247 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 553: /* "TransformExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2256 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 554: /* "VarNameList" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2265 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 555: /* "VarNameDecl" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2274 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 556: /* "TryExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2283 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 557: /* "CatchListExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2292 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 558: /* "CatchExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2301 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 559: /* "NameTestList" */

/* Line 479 of lalr1.cc  */
#line 886 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 479 of lalr1.cc  */
#line 2310 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 560: /* "EvalExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2319 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 561: /* "FTSelection" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2328 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 564: /* "FTOr" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2337 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 565: /* "FTAnd" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2346 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 566: /* "FTMildNot" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2355 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 567: /* "FTUnaryNot" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2364 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 568: /* "FTPrimaryWithOptions" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2373 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 569: /* "opt_FTMatchOptions" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2382 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 571: /* "FTWeight" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2391 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 572: /* "FTPrimary" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2400 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 573: /* "opt_FTTimes" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2409 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 574: /* "FTExtensionSelection" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2418 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 576: /* "FTWords" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2427 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 577: /* "FTWordsValue" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2436 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 579: /* "FTAnyallOption" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2445 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 582: /* "FTPosFilter" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2454 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 583: /* "FTOrder" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2463 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 584: /* "FTWindow" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2472 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 585: /* "FTDistance" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2481 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 586: /* "FTUnit" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2490 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 587: /* "FTMatchOptions" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2499 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 588: /* "FTMatchOption" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2508 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 589: /* "FTCaseOption" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2517 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 590: /* "FTDiacriticsOption" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2526 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 591: /* "FTExtensionOption" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2535 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 592: /* "FTStemOption" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2544 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 593: /* "FTThesaurusOption" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2553 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 597: /* "FTThesaurusID" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2562 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 600: /* "FTStopWordOption" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2571 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 601: /* "FTStopWords" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2580 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 605: /* "FTStopWordsInclExcl" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2589 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 606: /* "FTLanguageOption" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2598 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 607: /* "FTWildCardOption" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2607 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 608: /* "FTContent" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2616 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 609: /* "FTTimes" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2625 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 610: /* "FTRange" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2634 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 611: /* "FTScope" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2643 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 612: /* "FTBigUnit" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2652 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 613: /* "FTIgnoreOption" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2661 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 616: /* "QNAME" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2670 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 617: /* "FUNCTION_NAME" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2679 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 618: /* "EQNAME" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2688 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
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
    
/* Line 552 of lalr1.cc  */
#line 125 "F:/xquery/src/compiler/parser/xquery_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename2);
}

/* Line 552 of lalr1.cc  */
#line 2773 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"

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

/* Line 677 of lalr1.cc  */
#line 1024 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 4:

/* Line 677 of lalr1.cc  */
#line 1057 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL; YYABORT;
        }
    break;

  case 5:

/* Line 677 of lalr1.cc  */
#line 1066 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 6:

/* Line 677 of lalr1.cc  */
#line 1071 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            MainModule *mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
            mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 7:

/* Line 677 of lalr1.cc  */
#line 1078 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 8:

/* Line 677 of lalr1.cc  */
#line 1083 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            LibraryModule *lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
            lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 9:

/* Line 677 of lalr1.cc  */
#line 1094 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8" );
        }
    break;

  case 10:

/* Line 677 of lalr1.cc  */
#line 1098 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
        }
    break;

  case 11:

/* Line 677 of lalr1.cc  */
#line 1106 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);
          (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
        }
    break;

  case 12:

/* Line 677 of lalr1.cc  */
#line 1111 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));
          (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
        }
    break;

  case 13:

/* Line 677 of lalr1.cc  */
#line 1116 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)), static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));
          (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
        }
    break;

  case 14:

/* Line 677 of lalr1.cc  */
#line 1121 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
        }
    break;

  case 15:

/* Line 677 of lalr1.cc  */
#line 1126 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
          (yylocation_stack_[(3) - (1)]).step();
          driver.parserErr("syntax error, missing semicolon \";\" after statement", (yylocation_stack_[(3) - (1)]));
          error((yyloc), ""); // The error message will be taken from the driver
          YYERROR;
        }
    break;

  case 16:

/* Line 677 of lalr1.cc  */
#line 1134 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
          (yylocation_stack_[(3) - (1)]).step();
          driver.parserErr("syntax error, missing semicolon \";\" after declaration", (yylocation_stack_[(3) - (1)]));
          error((yyloc), ""); // The error message will be taken from the driver
          YYERROR;
        }
    break;

  case 17:

/* Line 677 of lalr1.cc  */
#line 1142 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
          (yylocation_stack_[(5) - (3)]).step();
          driver.parserErr("syntax error, missing semicolon \";\" after declaration", (yylocation_stack_[(5) - (3)]));
          error((yyloc), ""); // The error message will be taken from the driver
          YYERROR;
        }
    break;

  case 18:

/* Line 677 of lalr1.cc  */
#line 1150 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
          (yylocation_stack_[(5) - (1)]).step();
          driver.parserErr("syntax error, missing semicolon \";\" after statement", (yylocation_stack_[(5) - (1)]));
          error((yyloc), ""); // The error message will be taken from the driver
          YYERROR;
        }
    break;

  case 19:

/* Line 677 of lalr1.cc  */
#line 1162 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
        }
    break;

  case 20:

/* Line 677 of lalr1.cc  */
#line 1166 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);
          (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
        }
    break;

  case 21:

/* Line 677 of lalr1.cc  */
#line 1171 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));
          (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
        }
    break;

  case 22:

/* Line 677 of lalr1.cc  */
#line 1176 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)), static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));
          (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
        }
    break;

  case 23:

/* Line 677 of lalr1.cc  */
#line 1185 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
            dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
        }
    break;

  case 24:

/* Line 677 of lalr1.cc  */
#line 1194 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
            sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
            (yyval.node) = sdl;
        }
    break;

  case 25:

/* Line 677 of lalr1.cc  */
#line 1200 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 26:

/* Line 677 of lalr1.cc  */
#line 1206 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            // error
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
            (yylocation_stack_[(3) - (1)]).step();
            driver.parserErr("syntax error, missing semicolon \";\" after declaration", (yylocation_stack_[(3) - (1)]));
            error((yyloc), ""); // The error message will be taken from the driver
            YYERROR;
        }
    break;

  case 27:

/* Line 677 of lalr1.cc  */
#line 1219 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
            vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
            (yyval.node) = vdl;
        }
    break;

  case 28:

/* Line 677 of lalr1.cc  */
#line 1225 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 29:

/* Line 677 of lalr1.cc  */
#line 1231 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
            (yylocation_stack_[(3) - (1)]).step();
            driver.parserErr("syntax error, missing semicolon \";\" after declaration", (yylocation_stack_[(3) - (1)]));
            error((yyloc), ""); // The error message will be taken from the driver
            YYERROR;
        }
    break;

  case 43:

/* Line 677 of lalr1.cc  */
#line 1265 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
          delete (yysemantic_stack_[(4) - (4)].vstrpair);
        }
    break;

  case 44:

/* Line 677 of lalr1.cc  */
#line 1270 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
          delete (yysemantic_stack_[(4) - (4)].vstrpair);
        }
    break;

  case 45:

/* Line 677 of lalr1.cc  */
#line 1279 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.vstrpair) = new vector<string_pair_t>();
          (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
          delete (yysemantic_stack_[(1) - (1)].strpair);
        }
    break;

  case 46:

/* Line 677 of lalr1.cc  */
#line 1285 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
          delete (yysemantic_stack_[(2) - (2)].strpair);
          (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
        }
    break;

  case 47:

/* Line 677 of lalr1.cc  */
#line 1294 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
            (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
            delete sl;
        }
    break;

  case 48:

/* Line 677 of lalr1.cc  */
#line 1302 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 49:

/* Line 677 of lalr1.cc  */
#line 1303 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 50:

/* Line 677 of lalr1.cc  */
#line 1304 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 51:

/* Line 677 of lalr1.cc  */
#line 1305 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 52:

/* Line 677 of lalr1.cc  */
#line 1306 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 53:

/* Line 677 of lalr1.cc  */
#line 1307 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 54:

/* Line 677 of lalr1.cc  */
#line 1308 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 55:

/* Line 677 of lalr1.cc  */
#line 1309 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 56:

/* Line 677 of lalr1.cc  */
#line 1310 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 57:

/* Line 677 of lalr1.cc  */
#line 1311 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 68:

/* Line 677 of lalr1.cc  */
#line 1337 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
        }
    break;

  case 69:

/* Line 677 of lalr1.cc  */
#line 1345 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BoundarySpaceDecl(
                LOC((yyloc)), StaticContextConsts::preserve_space
            );
        }
    break;

  case 70:

/* Line 677 of lalr1.cc  */
#line 1351 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BoundarySpaceDecl(
                LOC((yyloc)), StaticContextConsts::strip_space
            );
        }
    break;

  case 71:

/* Line 677 of lalr1.cc  */
#line 1361 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultNamespaceDecl(
                LOC((yyloc)), ParseConstants::ns_element_default, SYMTAB((yysemantic_stack_[(5) - (5)].sval))
            );
        }
    break;

  case 72:

/* Line 677 of lalr1.cc  */
#line 1367 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultNamespaceDecl(
                LOC((yyloc)), ParseConstants::ns_function_default, SYMTAB((yysemantic_stack_[(5) - (5)].sval))
            );
        }
    break;

  case 73:

/* Line 677 of lalr1.cc  */
#line 1377 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OptionDecl(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval))
            );
        }
    break;

  case 74:

/* Line 677 of lalr1.cc  */
#line 1387 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
        }
    break;

  case 75:

/* Line 677 of lalr1.cc  */
#line 1395 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OrderingModeDecl(
                LOC((yyloc)), StaticContextConsts::ordered
            );
        }
    break;

  case 76:

/* Line 677 of lalr1.cc  */
#line 1401 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OrderingModeDecl(
                LOC((yyloc)), StaticContextConsts::unordered
            );
        }
    break;

  case 77:

/* Line 677 of lalr1.cc  */
#line 1412 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new EmptyOrderDecl( LOC((yyloc)),
                                StaticContextConsts::empty_greatest);
        }
    break;

  case 78:

/* Line 677 of lalr1.cc  */
#line 1417 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new EmptyOrderDecl( LOC((yyloc)),
                                StaticContextConsts::empty_least);
        }
    break;

  case 79:

/* Line 677 of lalr1.cc  */
#line 1427 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::preserve_ns,
                                StaticContextConsts::inherit_ns);
        }
    break;

  case 80:

/* Line 677 of lalr1.cc  */
#line 1433 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::preserve_ns,
                                StaticContextConsts::no_inherit_ns);
        }
    break;

  case 81:

/* Line 677 of lalr1.cc  */
#line 1439 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::no_preserve_ns,
                                StaticContextConsts::inherit_ns);
        }
    break;

  case 82:

/* Line 677 of lalr1.cc  */
#line 1445 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::no_preserve_ns,
                                StaticContextConsts::no_inherit_ns);
        }
    break;

  case 83:

/* Line 677 of lalr1.cc  */
#line 1462 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
        }
    break;

  case 84:

/* Line 677 of lalr1.cc  */
#line 1470 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 85:

/* Line 677 of lalr1.cc  */
#line 1478 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
        }
    break;

  case 86:

/* Line 677 of lalr1.cc  */
#line 1482 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new SchemaImport(
                LOC((yyloc)),
                dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                NULL
            );
        }
    break;

  case 87:

/* Line 677 of lalr1.cc  */
#line 1491 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new SchemaImport(
                LOC((yyloc)),
                NULL,
                SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 88:

/* Line 677 of lalr1.cc  */
#line 1500 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new SchemaImport(
                LOC((yyloc)),
                dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node))
            );
        }
    break;

  case 89:

/* Line 677 of lalr1.cc  */
#line 1513 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            URILiteralList *ull = new URILiteralList( LOC((yyloc)));
            ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.node) = ull;
        }
    break;

  case 90:

/* Line 677 of lalr1.cc  */
#line 1519 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
                ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 91:

/* Line 677 of lalr1.cc  */
#line 1530 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 92:

/* Line 677 of lalr1.cc  */
#line 1534 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
        }
    break;

  case 93:

/* Line 677 of lalr1.cc  */
#line 1542 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 94:

/* Line 677 of lalr1.cc  */
#line 1547 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 95:

/* Line 677 of lalr1.cc  */
#line 1552 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 96:

/* Line 677 of lalr1.cc  */
#line 1559 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(8) - (4)].sval)),
                            SYMTAB((yysemantic_stack_[(8) - (6)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(8) - (8)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(8) - (2)].sval)));
    }
    break;

  case 97:

/* Line 677 of lalr1.cc  */
#line 1572 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
        }
    break;

  case 98:

/* Line 677 of lalr1.cc  */
#line 1579 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            CtxItemDecl *d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
            d->type = (yysemantic_stack_[(3) - (2)].node);
            (yyval.node) = d;
        }
    break;

  case 99:

/* Line 677 of lalr1.cc  */
#line 1585 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 100:

/* Line 677 of lalr1.cc  */
#line 1592 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            CtxItemDecl *d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
            d->ext = false;
            (yyval.node) = d;
        }
    break;

  case 101:

/* Line 677 of lalr1.cc  */
#line 1598 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CtxItemDecl( LOC((yyloc)), NULL );
        }
    break;

  case 102:

/* Line 677 of lalr1.cc  */
#line 1602 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 103:

/* Line 677 of lalr1.cc  */
#line 1609 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CtxItemDecl( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 104:

/* Line 677 of lalr1.cc  */
#line 1620 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)), NULL, NULL);
      dynamic_cast<VarNameAndType*>((yyval.varnametype))->setComment(SYMTAB((yysemantic_stack_[(4) - (1)].sval)));
    }
    break;

  case 105:

/* Line 677 of lalr1.cc  */
#line 1625 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)), NULL);
      dynamic_cast<VarNameAndType*>((yyval.varnametype))->setComment(SYMTAB((yysemantic_stack_[(5) - (1)].sval)));
    }
    break;

  case 106:

/* Line 677 of lalr1.cc  */
#line 1630 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (5)].expr)), NULL, static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (2)].node)));
      dynamic_cast<VarNameAndType*>((yyval.varnametype))->setComment(SYMTAB((yysemantic_stack_[(5) - (1)].sval)));
    }
    break;

  case 107:

/* Line 677 of lalr1.cc  */
#line 1635 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (5)].expr)), dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)), static_cast<AnnotationListParsenode*>((yysemantic_stack_[(6) - (2)].node)));
      dynamic_cast<VarNameAndType*>((yyval.varnametype))->setComment(SYMTAB((yysemantic_stack_[(6) - (1)].sval)));
    }
    break;

  case 108:

/* Line 677 of lalr1.cc  */
#line 1644 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(3) - (1)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, (yysemantic_stack_[(3) - (3)].expr), nt->get_annotations());
      dynamic_cast<VarDecl*>((yyval.node))->setComment(nt->getCommentString());
    }
    break;

  case 109:

/* Line 677 of lalr1.cc  */
#line 1650 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(2) - (1)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, NULL, nt->get_annotations(), true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(nt->getCommentString());
    }
    break;

  case 110:

/* Line 677 of lalr1.cc  */
#line 1656 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(4) - (1)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, (yysemantic_stack_[(4) - (4)].expr), nt->get_annotations(), true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(nt->getCommentString());
    }
    break;

  case 111:

/* Line 677 of lalr1.cc  */
#line 1665 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            DeclPropertyList *dpl = new DeclPropertyList( LOC((yyloc)) );
            dpl->addProperty(dynamic_cast<DeclProperty*>((yysemantic_stack_[(1) - (1)].node)));
            (yyval.node) = dpl;
        }
    break;

  case 112:

/* Line 677 of lalr1.cc  */
#line 1671 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
        DeclPropertyList *dpl = dynamic_cast<DeclPropertyList*>((yysemantic_stack_[(2) - (1)].node));
        dpl->addProperty( static_cast<DeclProperty*>((yysemantic_stack_[(2) - (2)].node)) );
        (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 113:

/* Line 677 of lalr1.cc  */
#line 1680 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_const );
        }
    break;

  case 114:

/* Line 677 of lalr1.cc  */
#line 1684 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_append_only
            );
        }
    break;

  case 115:

/* Line 677 of lalr1.cc  */
#line 1690 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_queue );
        }
    break;

  case 116:

/* Line 677 of lalr1.cc  */
#line 1694 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_mutable );
        }
    break;

  case 117:

/* Line 677 of lalr1.cc  */
#line 1698 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_ordered );
        }
    break;

  case 118:

/* Line 677 of lalr1.cc  */
#line 1702 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_unordered
            );
        }
    break;

  case 119:

/* Line 677 of lalr1.cc  */
#line 1708 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_value_equality
            );
        }
    break;

  case 120:

/* Line 677 of lalr1.cc  */
#line 1714 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_value_range
            );
        }
    break;

  case 121:

/* Line 677 of lalr1.cc  */
#line 1720 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_general_equality
            );
        }
    break;

  case 122:

/* Line 677 of lalr1.cc  */
#line 1726 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_general_range
            );
        }
    break;

  case 123:

/* Line 677 of lalr1.cc  */
#line 1732 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_unique );
        }
    break;

  case 124:

/* Line 677 of lalr1.cc  */
#line 1736 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_non_unique
            );
        }
    break;

  case 125:

/* Line 677 of lalr1.cc  */
#line 1742 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_automatic
            );
        }
    break;

  case 126:

/* Line 677 of lalr1.cc  */
#line 1748 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_manual );
        }
    break;

  case 127:

/* Line 677 of lalr1.cc  */
#line 1755 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)),
                              NULL,
                              NULL,
                              NULL);
    }
    break;

  case 128:

/* Line 677 of lalr1.cc  */
#line 1763 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              NULL,
                              static_cast<NodeModifier*>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 129:

/* Line 677 of lalr1.cc  */
#line 1771 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                              NULL,
                              NULL,
                              static_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 130:

/* Line 677 of lalr1.cc  */
#line 1779 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                              NULL,
                              static_cast<NodeModifier*>((yysemantic_stack_[(6) - (6)].node)),
                              static_cast<SequenceType*>((yysemantic_stack_[(6) - (5)].node)));
    }
    break;

  case 131:

/* Line 677 of lalr1.cc  */
#line 1787 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

  case 132:

/* Line 677 of lalr1.cc  */
#line 1799 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

  case 133:

/* Line 677 of lalr1.cc  */
#line 1813 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

  case 134:

/* Line 677 of lalr1.cc  */
#line 1827 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

  case 135:

/* Line 677 of lalr1.cc  */
#line 1844 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 136:

/* Line 677 of lalr1.cc  */
#line 1848 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 137:

/* Line 677 of lalr1.cc  */
#line 1857 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier(LOC((yyloc)), StaticContextConsts::read_only);
    }
    break;

  case 138:

/* Line 677 of lalr1.cc  */
#line 1861 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier(LOC((yyloc)), StaticContextConsts::mutable_node);
    }
    break;

  case 139:

/* Line 677 of lalr1.cc  */
#line 1868 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AST_IndexDecl(LOC((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(8) - (3)].expr)),
                             (yysemantic_stack_[(8) - (6)].expr),
                             dynamic_cast<IndexKeyList*>((yysemantic_stack_[(8) - (8)].node)),
                             NULL);
    }
    break;

  case 140:

/* Line 677 of lalr1.cc  */
#line 1876 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

  case 141:

/* Line 677 of lalr1.cc  */
#line 1894 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 142:

/* Line 677 of lalr1.cc  */
#line 1900 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 143:

/* Line 677 of lalr1.cc  */
#line 1908 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 144:

/* Line 677 of lalr1.cc  */
#line 1913 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 145:

/* Line 677 of lalr1.cc  */
#line 1920 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 146:

/* Line 677 of lalr1.cc  */
#line 1927 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 147:

/* Line 677 of lalr1.cc  */
#line 1938 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollSimpleCheck(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (9)].expr)),
                                 (yysemantic_stack_[(11) - (11)].expr));
    }
    break;

  case 148:

/* Line 677 of lalr1.cc  */
#line 1948 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollUniqueKeyCheck(LOC((yyloc)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (4)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (7)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (10)].expr)),
                                    (yysemantic_stack_[(14) - (14)].expr));
    }
    break;

  case 149:

/* Line 677 of lalr1.cc  */
#line 1958 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollForeachNode(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (11)].expr)),
                                 (yysemantic_stack_[(13) - (13)].expr));
    }
    break;

  case 150:

/* Line 677 of lalr1.cc  */
#line 1969 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

  case 151:

/* Line 677 of lalr1.cc  */
#line 1984 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ConstructionDecl(
                LOC((yyloc)), StaticContextConsts::cons_preserve
            );
        }
    break;

  case 152:

/* Line 677 of lalr1.cc  */
#line 1990 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ConstructionDecl(
                LOC((yyloc)), StaticContextConsts::cons_strip
            );
        }
    break;

  case 153:

/* Line 677 of lalr1.cc  */
#line 2001 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( NULL );
        }
    break;

  case 154:

/* Line 677 of lalr1.cc  */
#line 2005 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 155:

/* Line 677 of lalr1.cc  */
#line 2009 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)) );
        }
    break;

  case 156:

/* Line 677 of lalr1.cc  */
#line 2013 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 157:

/* Line 677 of lalr1.cc  */
#line 2020 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(2) - (2)].expr);
        }
    break;

  case 158:

/* Line 677 of lalr1.cc  */
#line 2027 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( !(yysemantic_stack_[(4) - (2)].node) ) {
                (yyval.expr) = (yysemantic_stack_[(4) - (3)].expr);
            } else {
                BlockBody *bb = dynamic_cast<BlockBody*>((yysemantic_stack_[(4) - (3)].expr));
                VFO_DeclList *vfo = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(4) - (2)].node));
                if ( !bb ) {
                    bb = new BlockBody( (yysemantic_stack_[(4) - (3)].expr)->get_location(), vfo );
                    bb->add( (yysemantic_stack_[(4) - (3)].expr) );
                } else {
                    bb->set_decls( vfo );
                }
                (yyval.expr) = bb;
            }
        }
    break;

  case 159:

/* Line 677 of lalr1.cc  */
#line 2046 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vfo = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node));
            auto_ptr<VFO_DeclList> vfo2( dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)) );
            if ( !(yysemantic_stack_[(3) - (1)].node) )
                vfo = new VFO_DeclList( LOC((yyloc)) );
            vfo->push_back( *vfo2.get() );
            (yyval.node) = vfo;
        }
    break;

  case 160:

/* Line 677 of lalr1.cc  */
#line 2055 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 161:

/* Line 677 of lalr1.cc  */
#line 2062 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vfo = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node));
            vfo->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = vfo;
        }
    break;

  case 162:

/* Line 677 of lalr1.cc  */
#line 2068 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vfo = new VFO_DeclList( LOC((yyloc)) );
            vfo->push_back((yysemantic_stack_[(2) - (2)].node));
            (yyval.node) = vfo;
        }
    break;

  case 163:

/* Line 677 of lalr1.cc  */
#line 2078 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      VarDecl* vd = new VarDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL, NULL);
      vd->set_global(false);
      (yyval.node) = vd;
    }
    break;

  case 164:

/* Line 677 of lalr1.cc  */
#line 2084 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      VarDecl* vd = new VarDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)), NULL, NULL);

      vd->set_global(false);
      (yyval.node) = vd;
    }
    break;

  case 165:

/* Line 677 of lalr1.cc  */
#line 2091 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      VarDecl* vd = new VarDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)), NULL, (yysemantic_stack_[(4) - (4)].expr), NULL);
      vd->set_global(false);
      (yyval.node) = vd;
    }
    break;

  case 166:

/* Line 677 of lalr1.cc  */
#line 2097 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      VarDecl* vd = new VarDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (3)].node)), (yysemantic_stack_[(5) - (5)].expr), NULL);
      vd->set_global(false);
      (yyval.node) = vd;
    }
    break;

  case 167:

/* Line 677 of lalr1.cc  */
#line 2107 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 168:

/* Line 677 of lalr1.cc  */
#line 2114 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExitExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 169:

/* Line 677 of lalr1.cc  */
#line 2121 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            BlockBody *bb = dynamic_cast<BlockBody *>((yysemantic_stack_[(5) - (5)].expr));
            if ( !bb ) {
                bb = new BlockBody( (yysemantic_stack_[(5) - (5)].expr)->get_location() );
                bb->add((yysemantic_stack_[(5) - (5)].expr));
            }
            (yyval.expr) = new WhileExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), bb );
        }
    break;

  case 170:

/* Line 677 of lalr1.cc  */
#line 2133 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::BREAK );
        }
    break;

  case 171:

/* Line 677 of lalr1.cc  */
#line 2137 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
        }
    break;

  case 172:

/* Line 677 of lalr1.cc  */
#line 2145 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnnotationListParsenode( LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
        }
    break;

  case 173:

/* Line 677 of lalr1.cc  */
#line 2149 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 174:

/* Line 677 of lalr1.cc  */
#line 2157 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnnotationParsenode( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
        }
    break;

  case 175:

/* Line 677 of lalr1.cc  */
#line 2161 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnnotationParsenode( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))), static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
        }
    break;

  case 176:

/* Line 677 of lalr1.cc  */
#line 2168 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnnotationLiteralListParsenode( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
        }
    break;

  case 177:

/* Line 677 of lalr1.cc  */
#line 2172 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 178:

/* Line 677 of lalr1.cc  */
#line 2180 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 179:

/* Line 677 of lalr1.cc  */
#line 2185 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node))->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );
            static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node))->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
            (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
        }
    break;

  case 180:

/* Line 677 of lalr1.cc  */
#line 2194 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 181:

/* Line 677 of lalr1.cc  */
#line 2198 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 182:

/* Line 677 of lalr1.cc  */
#line 2202 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 183:

/* Line 677 of lalr1.cc  */
#line 2206 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 184:

/* Line 677 of lalr1.cc  */
#line 2214 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC ((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                            &* (yysemantic_stack_[(4) - (3)].fnsig)->param,
                            &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
                            (yysemantic_stack_[(4) - (4)].expr),
                            ParseConstants::fn_read,
                            NULL);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 185:

/* Line 677 of lalr1.cc  */
#line 2225 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC ((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                            &* (yysemantic_stack_[(4) - (3)].fnsig)->param,
                            &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
                            NULL,
                            ParseConstants::fn_extern,
                            NULL);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 186:

/* Line 677 of lalr1.cc  */
#line 2240 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC ((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                            &* (yysemantic_stack_[(5) - (4)].fnsig)->param,
                            &* (yysemantic_stack_[(5) - (4)].fnsig)->ret,
                            (yysemantic_stack_[(5) - (5)].expr),
                            ParseConstants::fn_sequential,
                            NULL);
      delete (yysemantic_stack_[(5) - (4)].fnsig);
    }
    break;

  case 187:

/* Line 677 of lalr1.cc  */
#line 2251 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC ((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                            &* (yysemantic_stack_[(5) - (4)].fnsig)->param,
                            &* (yysemantic_stack_[(5) - (4)].fnsig)->ret,
                            NULL,
                            ParseConstants::fn_extern_sequential,
                            NULL);
      delete (yysemantic_stack_[(5) - (4)].fnsig);
    }
    break;

  case 188:

/* Line 677 of lalr1.cc  */
#line 2266 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC ((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                            &* (yysemantic_stack_[(7) - (4)].fnsig)->param,
                            &* (yysemantic_stack_[(7) - (4)].fnsig)->ret,
                            (yysemantic_stack_[(7) - (6)].expr),
                            ParseConstants::fn_update,
                            NULL);
      delete (yysemantic_stack_[(7) - (4)].fnsig);
    }
    break;

  case 189:

/* Line 677 of lalr1.cc  */
#line 2277 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC ((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                            &* (yysemantic_stack_[(5) - (4)].fnsig)->param,
                            &* (yysemantic_stack_[(5) - (4)].fnsig)->ret,
                            NULL,
                            ParseConstants::fn_extern_update,
                            NULL);
      delete (yysemantic_stack_[(5) - (4)].fnsig);
    }
    break;

  case 190:

/* Line 677 of lalr1.cc  */
#line 2293 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            ParamList *pl = new ParamList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 191:

/* Line 677 of lalr1.cc  */
#line 2299 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
                pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 192:

/* Line 677 of lalr1.cc  */
#line 2311 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 193:

/* Line 677 of lalr1.cc  */
#line 2315 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 194:

/* Line 677 of lalr1.cc  */
#line 2326 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new EnclosedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 195:

/* Line 677 of lalr1.cc  */
#line 2333 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 196:

/* Line 677 of lalr1.cc  */
#line 2341 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QueryBody( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 197:

/* Line 677 of lalr1.cc  */
#line 2356 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 198:

/* Line 677 of lalr1.cc  */
#line 2360 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            auto_ptr<BlockBody> blk( dynamic_cast<BlockBody*>((yysemantic_stack_[(2) - (2)].expr)) );
            BlockBody *blk2 = new BlockBody( LOC((yyloc)) );
            blk2->add( (yysemantic_stack_[(2) - (1)].expr) );

            for ( ulong i = 0; i < blk->size(); ++i )
                blk2->add( (*blk)[i] );

            (yyval.expr) = blk2;
        }
    break;

  case 199:

/* Line 677 of lalr1.cc  */
#line 2374 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new BlockBody( LOC((yyloc)) );
        }
    break;

  case 200:

/* Line 677 of lalr1.cc  */
#line 2378 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            BlockBody *bb = dynamic_cast<BlockBody*>((yysemantic_stack_[(3) - (1)].expr));
            bb->add( (yysemantic_stack_[(3) - (2)].expr) );
            (yyval.expr) = bb;
        }
    break;

  case 201:

/* Line 677 of lalr1.cc  */
#line 2387 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 202:

/* Line 677 of lalr1.cc  */
#line 2391 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            Expr *expr = dynamic_cast<Expr*>((yysemantic_stack_[(3) - (1)].expr));
            if ( !expr ) {
                expr = new Expr( LOC((yyloc)) );
                expr->push_back( (yysemantic_stack_[(3) - (1)].expr) );
            }
            expr->push_back( (yysemantic_stack_[(3) - (3)].expr) );
            (yyval.expr) = expr;
        }
    break;

  case 221:

/* Line 677 of lalr1.cc  */
#line 2446 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            ReturnExpr *re = dynamic_cast<ReturnExpr*>((yysemantic_stack_[(2) - (2)].expr));
            (yyval.expr) = new FLWORExpr(
                LOC((yyloc)),
                dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node)),
                re->get_return_val(),
                re->get_location(),
                driver.theCompilerCB->theConfig.force_gflwor
            );
            delete (yysemantic_stack_[(2) - (2)].expr);
        }
    break;

  case 222:

/* Line 677 of lalr1.cc  */
#line 2461 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 223:

/* Line 677 of lalr1.cc  */
#line 2468 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_sliding;
        }
    break;

  case 224:

/* Line 677 of lalr1.cc  */
#line 2472 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_tumbling;
        }
    break;

  case 225:

/* Line 677 of lalr1.cc  */
#line 2479 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_start;
        }
    break;

  case 226:

/* Line 677 of lalr1.cc  */
#line 2483 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_end;
        }
    break;

  case 227:

/* Line 677 of lalr1.cc  */
#line 2487 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_only_end;
        }
    break;

  case 228:

/* Line 677 of lalr1.cc  */
#line 2494 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FLWORWinCond(
                LOC((yyloc)),
                dynamic_cast<WindowVars*>((yysemantic_stack_[(4) - (2)].node)), (yysemantic_stack_[(4) - (4)].expr),
                (yysemantic_stack_[(4) - (1)].strval) == parser::the_start, (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end
            );
        }
    break;

  case 229:

/* Line 677 of lalr1.cc  */
#line 2502 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FLWORWinCond(
                LOC((yyloc)), NULL, (yysemantic_stack_[(3) - (3)].expr),
                (yysemantic_stack_[(3) - (1)].strval) == parser::the_start, (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end
            );
        }
    break;

  case 230:

/* Line 677 of lalr1.cc  */
#line 2513 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

  case 231:

/* Line 677 of lalr1.cc  */
#line 2523 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling ?
                              WindowClause::tumbling_window :
                              WindowClause::sliding_window),
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    }
    break;

  case 232:

/* Line 677 of lalr1.cc  */
#line 2536 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 241:

/* Line 677 of lalr1.cc  */
#line 2558 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
            fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = fcl;
        }
    break;

  case 242:

/* Line 677 of lalr1.cc  */
#line 2564 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
            fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = fcl;
        }
    break;

  case 243:

/* Line 677 of lalr1.cc  */
#line 2574 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
        }
    break;

  case 244:

/* Line 677 of lalr1.cc  */
#line 2582 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            VarInDeclList *vdl = new VarInDeclList( LOC((yyloc)) );
            vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vdl;
        }
    break;

  case 245:

/* Line 677 of lalr1.cc  */
#line 2588 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( VarInDeclList *vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 246:

/* Line 677 of lalr1.cc  */
#line 2600 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 247:

/* Line 677 of lalr1.cc  */
#line 2604 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)), NULL, NULL, NULL, (yysemantic_stack_[(5) - (5)].expr), true);
    }
    break;

  case 248:

/* Line 677 of lalr1.cc  */
#line 2608 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)), dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)), NULL, NULL, (yysemantic_stack_[(4) - (4)].expr), false);
    }
    break;

  case 249:

/* Line 677 of lalr1.cc  */
#line 2612 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (1)].expr)), dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (2)].node)), NULL, NULL, (yysemantic_stack_[(6) - (6)].expr), true);
    }
    break;

  case 250:

/* Line 677 of lalr1.cc  */
#line 2616 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)), NULL, dynamic_cast<PositionalVar*>((yysemantic_stack_[(4) - (2)].node)), NULL, (yysemantic_stack_[(4) - (4)].expr), false);
    }
    break;

  case 251:

/* Line 677 of lalr1.cc  */
#line 2620 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (1)].expr)), NULL, dynamic_cast<PositionalVar*>((yysemantic_stack_[(6) - (4)].node)), NULL, (yysemantic_stack_[(6) - (6)].expr), true);
    }
    break;

  case 252:

/* Line 677 of lalr1.cc  */
#line 2624 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (3)].node)), NULL, (yysemantic_stack_[(5) - (5)].expr), false);
    }
    break;

  case 253:

/* Line 677 of lalr1.cc  */
#line 2629 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(7) - (1)].expr)), dynamic_cast<SequenceType *>((yysemantic_stack_[(7) - (2)].node)),
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(7) - (5)].node)), NULL, (yysemantic_stack_[(7) - (7)].expr), true);
    }
    break;

  case 254:

/* Line 677 of lalr1.cc  */
#line 2635 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 677 of lalr1.cc  */
#line 2644 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 677 of lalr1.cc  */
#line 2654 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 677 of lalr1.cc  */
#line 2664 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 677 of lalr1.cc  */
#line 2680 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 259:

/* Line 677 of lalr1.cc  */
#line 2689 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 260:

/* Line 677 of lalr1.cc  */
#line 2698 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 261:

/* Line 677 of lalr1.cc  */
#line 2706 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 262:

/* Line 677 of lalr1.cc  */
#line 2712 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 263:

/* Line 677 of lalr1.cc  */
#line 2721 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 264:

/* Line 677 of lalr1.cc  */
#line 2727 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 265:

/* Line 677 of lalr1.cc  */
#line 2736 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)),
                           NULL, NULL,
                           new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr))),
                           VarGetsDecl::eval_var);
    }
    break;

  case 266:

/* Line 677 of lalr1.cc  */
#line 2750 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                           NULL,
                           NULL,
                           (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 267:

/* Line 677 of lalr1.cc  */
#line 2758 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                           NULL,
                           (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 268:

/* Line 677 of lalr1.cc  */
#line 2768 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node))->get_var_name(),
                           NULL,
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node)),
                           (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 269:

/* Line 677 of lalr1.cc  */
#line 2776 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (3)].node)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
                           (yysemantic_stack_[(6) - (6)].expr));
    }
    break;

  case 270:

/* Line 677 of lalr1.cc  */
#line 2788 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 271:

/* Line 677 of lalr1.cc  */
#line 2794 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 273:

/* Line 677 of lalr1.cc  */
#line 2807 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 274:

/* Line 677 of lalr1.cc  */
#line 2811 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 275:

/* Line 677 of lalr1.cc  */
#line 2819 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 276:

/* Line 677 of lalr1.cc  */
#line 2823 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 278:

/* Line 677 of lalr1.cc  */
#line 2832 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 279:

/* Line 677 of lalr1.cc  */
#line 2836 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 280:

/* Line 677 of lalr1.cc  */
#line 2840 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 281:

/* Line 677 of lalr1.cc  */
#line 2850 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 282:

/* Line 677 of lalr1.cc  */
#line 2858 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 283:

/* Line 677 of lalr1.cc  */
#line 2865 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = new GroupSpecList( LOC((yyloc)) );
            gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 284:

/* Line 677 of lalr1.cc  */
#line 2871 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
            if ( gsl )
                gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 285:

/* Line 677 of lalr1.cc  */
#line 2882 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 286:

/* Line 677 of lalr1.cc  */
#line 2886 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                         dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 287:

/* Line 677 of lalr1.cc  */
#line 2895 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 288:

/* Line 677 of lalr1.cc  */
#line 2903 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 289:

/* Line 677 of lalr1.cc  */
#line 2909 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 290:

/* Line 677 of lalr1.cc  */
#line 2919 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 291:

/* Line 677 of lalr1.cc  */
#line 2925 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 292:

/* Line 677 of lalr1.cc  */
#line 2935 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 293:

/* Line 677 of lalr1.cc  */
#line 2939 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 294:

/* Line 677 of lalr1.cc  */
#line 2949 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 295:

/* Line 677 of lalr1.cc  */
#line 2955 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 296:

/* Line 677 of lalr1.cc  */
#line 2961 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 297:

/* Line 677 of lalr1.cc  */
#line 2967 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 677 of lalr1.cc  */
#line 2976 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 677 of lalr1.cc  */
#line 2985 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 677 of lalr1.cc  */
#line 2994 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 677 of lalr1.cc  */
#line 3007 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 302:

/* Line 677 of lalr1.cc  */
#line 3011 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 303:

/* Line 677 of lalr1.cc  */
#line 3019 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 304:

/* Line 677 of lalr1.cc  */
#line 3025 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 305:

/* Line 677 of lalr1.cc  */
#line 3035 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 306:

/* Line 677 of lalr1.cc  */
#line 3043 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 677 of lalr1.cc  */
#line 3052 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 677 of lalr1.cc  */
#line 3065 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 309:

/* Line 677 of lalr1.cc  */
#line 3072 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 310:

/* Line 677 of lalr1.cc  */
#line 3084 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 311:

/* Line 677 of lalr1.cc  */
#line 3088 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 312:

/* Line 677 of lalr1.cc  */
#line 3100 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 313:

/* Line 677 of lalr1.cc  */
#line 3107 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 314:

/* Line 677 of lalr1.cc  */
#line 3113 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 315:

/* Line 677 of lalr1.cc  */
#line 3122 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 316:

/* Line 677 of lalr1.cc  */
#line 3129 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 317:

/* Line 677 of lalr1.cc  */
#line 3135 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 318:

/* Line 677 of lalr1.cc  */
#line 3147 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 319:

/* Line 677 of lalr1.cc  */
#line 3154 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 320:

/* Line 677 of lalr1.cc  */
#line 3167 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 321:

/* Line 677 of lalr1.cc  */
#line 3173 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 322:

/* Line 677 of lalr1.cc  */
#line 3185 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 323:

/* Line 677 of lalr1.cc  */
#line 3191 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 324:

/* Line 677 of lalr1.cc  */
#line 3203 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 325:

/* Line 677 of lalr1.cc  */
#line 3212 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 326:

/* Line 677 of lalr1.cc  */
#line 3216 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 327:

/* Line 677 of lalr1.cc  */
#line 3225 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 328:

/* Line 677 of lalr1.cc  */
#line 3229 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 329:

/* Line 677 of lalr1.cc  */
#line 3237 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 330:

/* Line 677 of lalr1.cc  */
#line 3241 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

  case 331:

/* Line 677 of lalr1.cc  */
#line 3251 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 332:

/* Line 677 of lalr1.cc  */
#line 3258 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_eq ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 333:

/* Line 677 of lalr1.cc  */
#line 3267 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ne ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 334:

/* Line 677 of lalr1.cc  */
#line 3276 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 335:

/* Line 677 of lalr1.cc  */
#line 3281 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_lt ),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr)
            );
        }
    break;

  case 336:

/* Line 677 of lalr1.cc  */
#line 3290 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_le ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 337:

/* Line 677 of lalr1.cc  */
#line 3299 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_gt ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 338:

/* Line 677 of lalr1.cc  */
#line 3308 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ge ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 339:

/* Line 677 of lalr1.cc  */
#line 3321 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 340:

/* Line 677 of lalr1.cc  */
#line 3325 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FTContainsExpr(
                LOC((yyloc)),
                (yysemantic_stack_[(5) - (1)].expr),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(5) - (4)].node)),
                dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 341:

/* Line 677 of lalr1.cc  */
#line 3337 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 342:

/* Line 677 of lalr1.cc  */
#line 3341 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 343:

/* Line 677 of lalr1.cc  */
#line 3348 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 344:

/* Line 677 of lalr1.cc  */
#line 3352 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 345:

/* Line 677 of lalr1.cc  */
#line 3361 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 346:

/* Line 677 of lalr1.cc  */
#line 3365 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 347:

/* Line 677 of lalr1.cc  */
#line 3369 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 348:

/* Line 677 of lalr1.cc  */
#line 3378 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 349:

/* Line 677 of lalr1.cc  */
#line 3382 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 350:

/* Line 677 of lalr1.cc  */
#line 3388 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 351:

/* Line 677 of lalr1.cc  */
#line 3394 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 352:

/* Line 677 of lalr1.cc  */
#line 3400 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 353:

/* Line 677 of lalr1.cc  */
#line 3411 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 354:

/* Line 677 of lalr1.cc  */
#line 3415 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 355:

/* Line 677 of lalr1.cc  */
#line 3419 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 356:

/* Line 677 of lalr1.cc  */
#line 3427 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 357:

/* Line 677 of lalr1.cc  */
#line 3431 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 358:

/* Line 677 of lalr1.cc  */
#line 3437 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 359:

/* Line 677 of lalr1.cc  */
#line 3447 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 360:

/* Line 677 of lalr1.cc  */
#line 3451 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 361:

/* Line 677 of lalr1.cc  */
#line 3461 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 362:

/* Line 677 of lalr1.cc  */
#line 3465 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 363:

/* Line 677 of lalr1.cc  */
#line 3475 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 364:

/* Line 677 of lalr1.cc  */
#line 3479 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 365:

/* Line 677 of lalr1.cc  */
#line 3489 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 366:

/* Line 677 of lalr1.cc  */
#line 3493 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 367:

/* Line 677 of lalr1.cc  */
#line 3503 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 368:

/* Line 677 of lalr1.cc  */
#line 3507 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 369:

/* Line 677 of lalr1.cc  */
#line 3515 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 370:

/* Line 677 of lalr1.cc  */
#line 3519 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 371:

/* Line 677 of lalr1.cc  */
#line 3523 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 372:

/* Line 677 of lalr1.cc  */
#line 3527 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 373:

/* Line 677 of lalr1.cc  */
#line 3537 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 374:

/* Line 677 of lalr1.cc  */
#line 3541 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 375:

/* Line 677 of lalr1.cc  */
#line 3545 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 376:

/* Line 677 of lalr1.cc  */
#line 3553 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 377:

/* Line 677 of lalr1.cc  */
#line 3557 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 378:

/* Line 677 of lalr1.cc  */
#line 3561 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 379:

/* Line 677 of lalr1.cc  */
#line 3565 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 380:

/* Line 677 of lalr1.cc  */
#line 3569 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 381:

/* Line 677 of lalr1.cc  */
#line 3573 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 382:

/* Line 677 of lalr1.cc  */
#line 3581 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 383:

/* Line 677 of lalr1.cc  */
#line 3585 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 384:

/* Line 677 of lalr1.cc  */
#line 3589 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 385:

/* Line 677 of lalr1.cc  */
#line 3597 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 386:

/* Line 677 of lalr1.cc  */
#line 3601 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 387:

/* Line 677 of lalr1.cc  */
#line 3605 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 388:

/* Line 677 of lalr1.cc  */
#line 3609 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 389:

/* Line 677 of lalr1.cc  */
#line 3620 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 390:

/* Line 677 of lalr1.cc  */
#line 3626 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 391:

/* Line 677 of lalr1.cc  */
#line 3636 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 392:

/* Line 677 of lalr1.cc  */
#line 3642 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 393:

/* Line 677 of lalr1.cc  */
#line 3652 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 394:

/* Line 677 of lalr1.cc  */
#line 3656 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 395:

/* Line 677 of lalr1.cc  */
#line 3660 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 396:

/* Line 677 of lalr1.cc  */
#line 3699 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new PathExpr(LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
    }
    break;

  case 397:

/* Line 677 of lalr1.cc  */
#line 3703 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, NULL, (yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slash,
                        rpe);
    }
    break;

  case 398:

/* Line 677 of lalr1.cc  */
#line 3713 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, NULL, (yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slashslash,
                        rpe);
    }
    break;

  case 399:

/* Line 677 of lalr1.cc  */
#line 3723 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = (!rpe ?
            (yysemantic_stack_[(1) - (1)].expr) :
            new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 400:

/* Line 677 of lalr1.cc  */
#line 3737 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 401:

/* Line 677 of lalr1.cc  */
#line 3747 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

  case 402:

/* Line 677 of lalr1.cc  */
#line 3757 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 403:

/* Line 677 of lalr1.cc  */
#line 3761 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 404:

/* Line 677 of lalr1.cc  */
#line 3771 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 405:

/* Line 677 of lalr1.cc  */
#line 3775 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 406:

/* Line 677 of lalr1.cc  */
#line 3784 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 407:

/* Line 677 of lalr1.cc  */
#line 3790 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 408:

/* Line 677 of lalr1.cc  */
#line 3798 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 409:

/* Line 677 of lalr1.cc  */
#line 3804 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 410:

/* Line 677 of lalr1.cc  */
#line 3816 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 411:

/* Line 677 of lalr1.cc  */
#line 3822 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 412:

/* Line 677 of lalr1.cc  */
#line 3832 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 413:

/* Line 677 of lalr1.cc  */
#line 3836 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 414:

/* Line 677 of lalr1.cc  */
#line 3840 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 415:

/* Line 677 of lalr1.cc  */
#line 3844 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 416:

/* Line 677 of lalr1.cc  */
#line 3848 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 417:

/* Line 677 of lalr1.cc  */
#line 3854 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 418:

/* Line 677 of lalr1.cc  */
#line 3860 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 419:

/* Line 677 of lalr1.cc  */
#line 3883 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 420:

/* Line 677 of lalr1.cc  */
#line 3887 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 421:

/* Line 677 of lalr1.cc  */
#line 3895 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 422:

/* Line 677 of lalr1.cc  */
#line 3899 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 423:

/* Line 677 of lalr1.cc  */
#line 3910 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 424:

/* Line 677 of lalr1.cc  */
#line 3914 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 425:

/* Line 677 of lalr1.cc  */
#line 3918 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 426:

/* Line 677 of lalr1.cc  */
#line 3924 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 427:

/* Line 677 of lalr1.cc  */
#line 3928 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 428:

/* Line 677 of lalr1.cc  */
#line 3942 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 429:

/* Line 677 of lalr1.cc  */
#line 3946 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 430:

/* Line 677 of lalr1.cc  */
#line 3954 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 431:

/* Line 677 of lalr1.cc  */
#line 3958 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 432:

/* Line 677 of lalr1.cc  */
#line 3968 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all);
    }
    break;

  case 433:

/* Line 677 of lalr1.cc  */
#line 3972 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem);
    }
    break;

  case 434:

/* Line 677 of lalr1.cc  */
#line 3976 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix);
    }
    break;

  case 435:

/* Line 677 of lalr1.cc  */
#line 3985 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 436:

/* Line 677 of lalr1.cc  */
#line 3989 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 437:

/* Line 677 of lalr1.cc  */
#line 3993 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
     }
    break;

  case 438:

/* Line 677 of lalr1.cc  */
#line 3997 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
     }
    break;

  case 439:

/* Line 677 of lalr1.cc  */
#line 4005 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 440:

/* Line 677 of lalr1.cc  */
#line 4011 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 441:

/* Line 677 of lalr1.cc  */
#line 4021 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 442:

/* Line 677 of lalr1.cc  */
#line 4029 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 443:

/* Line 677 of lalr1.cc  */
#line 4033 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 444:

/* Line 677 of lalr1.cc  */
#line 4037 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 445:

/* Line 677 of lalr1.cc  */
#line 4041 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 446:

/* Line 677 of lalr1.cc  */
#line 4045 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 447:

/* Line 677 of lalr1.cc  */
#line 4049 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 448:

/* Line 677 of lalr1.cc  */
#line 4053 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 449:

/* Line 677 of lalr1.cc  */
#line 4057 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 450:

/* Line 677 of lalr1.cc  */
#line 4061 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 451:

/* Line 677 of lalr1.cc  */
#line 4069 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 452:

/* Line 677 of lalr1.cc  */
#line 4073 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 453:

/* Line 677 of lalr1.cc  */
#line 4081 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 454:

/* Line 677 of lalr1.cc  */
#line 4088 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 455:

/* Line 677 of lalr1.cc  */
#line 4095 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 456:

/* Line 677 of lalr1.cc  */
#line 4106 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 457:

/* Line 677 of lalr1.cc  */
#line 4114 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 458:

/* Line 677 of lalr1.cc  */
#line 4118 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 459:

/* Line 677 of lalr1.cc  */
#line 4126 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 460:

/* Line 677 of lalr1.cc  */
#line 4134 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 461:

/* Line 677 of lalr1.cc  */
#line 4142 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 462:

/* Line 677 of lalr1.cc  */
#line 4196 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
        }
    break;

  case 463:

/* Line 677 of lalr1.cc  */
#line 4200 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 464:

/* Line 677 of lalr1.cc  */
#line 4213 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            ArgList *al = new ArgList( LOC((yyloc)) );
            al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
            (yyval.node) = al;
        }
    break;

  case 465:

/* Line 677 of lalr1.cc  */
#line 4219 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
                al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 466:

/* Line 677 of lalr1.cc  */
#line 4229 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 467:

/* Line 677 of lalr1.cc  */
#line 4233 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 468:

/* Line 677 of lalr1.cc  */
#line 4241 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 469:

/* Line 677 of lalr1.cc  */
#line 4245 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 470:

/* Line 677 of lalr1.cc  */
#line 4249 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 471:

/* Line 677 of lalr1.cc  */
#line 4257 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

  case 472:

/* Line 677 of lalr1.cc  */
#line 4267 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

  case 473:

/* Line 677 of lalr1.cc  */
#line 4277 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

  case 474:

/* Line 677 of lalr1.cc  */
#line 4287 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

  case 475:

/* Line 677 of lalr1.cc  */
#line 4297 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

  case 476:

/* Line 677 of lalr1.cc  */
#line 4307 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

  case 477:

/* Line 677 of lalr1.cc  */
#line 4322 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
            decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = decl;
        }
    break;

  case 478:

/* Line 677 of lalr1.cc  */
#line 4328 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( decl )
                decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 479:

/* Line 677 of lalr1.cc  */
#line 4339 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
            dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = dal;
        }
    break;

  case 480:

/* Line 677 of lalr1.cc  */
#line 4345 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
            if ( dal )
                dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 481:

/* Line 677 of lalr1.cc  */
#line 4356 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttr(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node))
            );
        }
    break;

  case 484:

/* Line 677 of lalr1.cc  */
#line 4373 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 485:

/* Line 677 of lalr1.cc  */
#line 4378 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 486:

/* Line 677 of lalr1.cc  */
#line 4387 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
        }
    break;

  case 487:

/* Line 677 of lalr1.cc  */
#line 4391 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 488:

/* Line 677 of lalr1.cc  */
#line 4398 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = qacl;
        }
    break;

  case 489:

/* Line 677 of lalr1.cc  */
#line 4404 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = qacl;
        }
    break;

  case 490:

/* Line 677 of lalr1.cc  */
#line 4410 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 491:

/* Line 677 of lalr1.cc  */
#line 4418 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 492:

/* Line 677 of lalr1.cc  */
#line 4430 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
        }
    break;

  case 493:

/* Line 677 of lalr1.cc  */
#line 4434 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 494:

/* Line 677 of lalr1.cc  */
#line 4441 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = aacl;
        }
    break;

  case 495:

/* Line 677 of lalr1.cc  */
#line 4447 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = aacl;
        }
    break;

  case 496:

/* Line 677 of lalr1.cc  */
#line 4453 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if (aacl)
                aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 497:

/* Line 677 of lalr1.cc  */
#line 4460 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( aacl )
                aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 498:

/* Line 677 of lalr1.cc  */
#line 4471 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 499:

/* Line 677 of lalr1.cc  */
#line 4475 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 500:

/* Line 677 of lalr1.cc  */
#line 4485 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 501:

/* Line 677 of lalr1.cc  */
#line 4489 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 502:

/* Line 677 of lalr1.cc  */
#line 4499 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 503:

/* Line 677 of lalr1.cc  */
#line 4503 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 504:

/* Line 677 of lalr1.cc  */
#line 4507 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
        }
    break;

  case 505:

/* Line 677 of lalr1.cc  */
#line 4512 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
        }
    break;

  case 506:

/* Line 677 of lalr1.cc  */
#line 4521 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval))
            );
        }
    break;

  case 507:

/* Line 677 of lalr1.cc  */
#line 4527 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_lbrace
            );
        }
    break;

  case 508:

/* Line 677 of lalr1.cc  */
#line 4533 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_rbrace
            );
        }
    break;

  case 509:

/* Line 677 of lalr1.cc  */
#line 4539 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 510:

/* Line 677 of lalr1.cc  */
#line 4549 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 511:

/* Line 677 of lalr1.cc  */
#line 4553 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
        }
    break;

  case 512:

/* Line 677 of lalr1.cc  */
#line 4565 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 513:

/* Line 677 of lalr1.cc  */
#line 4569 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 514:

/* Line 677 of lalr1.cc  */
#line 4581 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 515:

/* Line 677 of lalr1.cc  */
#line 4593 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 516:

/* Line 677 of lalr1.cc  */
#line 4597 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 517:

/* Line 677 of lalr1.cc  */
#line 4601 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 518:

/* Line 677 of lalr1.cc  */
#line 4605 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 519:

/* Line 677 of lalr1.cc  */
#line 4609 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 520:

/* Line 677 of lalr1.cc  */
#line 4613 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 521:

/* Line 677 of lalr1.cc  */
#line 4621 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 522:

/* Line 677 of lalr1.cc  */
#line 4629 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (1)].sval))), NULL);
        }
    break;

  case 523:

/* Line 677 of lalr1.cc  */
#line 4633 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
        }
    break;

  case 524:

/* Line 677 of lalr1.cc  */
#line 4637 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 525:

/* Line 677 of lalr1.cc  */
#line 4641 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 526:

/* Line 677 of lalr1.cc  */
#line 4658 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (1)].sval))), NULL );
        }
    break;

  case 527:

/* Line 677 of lalr1.cc  */
#line 4662 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 528:

/* Line 677 of lalr1.cc  */
#line 4666 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 529:

/* Line 677 of lalr1.cc  */
#line 4670 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 530:

/* Line 677 of lalr1.cc  */
#line 4678 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 531:

/* Line 677 of lalr1.cc  */
#line 4686 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 532:

/* Line 677 of lalr1.cc  */
#line 4694 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (1)].sval)), NULL );
        }
    break;

  case 533:

/* Line 677 of lalr1.cc  */
#line 4698 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 534:

/* Line 677 of lalr1.cc  */
#line 4702 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 535:

/* Line 677 of lalr1.cc  */
#line 4706 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 536:

/* Line 677 of lalr1.cc  */
#line 4714 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)), false
            );
        }
    break;

  case 537:

/* Line 677 of lalr1.cc  */
#line 4720 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)), true
            );
        }
    break;

  case 538:

/* Line 677 of lalr1.cc  */
#line 4730 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 539:

/* Line 677 of lalr1.cc  */
#line 4738 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 540:

/* Line 677 of lalr1.cc  */
#line 4742 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 541:

/* Line 677 of lalr1.cc  */
#line 4746 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 542:

/* Line 677 of lalr1.cc  */
#line 4781 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 543:

/* Line 677 of lalr1.cc  */
#line 4787 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 544:

/* Line 677 of lalr1.cc  */
#line 4793 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 545:

/* Line 677 of lalr1.cc  */
#line 4803 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 546:

/* Line 677 of lalr1.cc  */
#line 4807 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 547:

/* Line 677 of lalr1.cc  */
#line 4811 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)),true );
        }
    break;

  case 548:

/* Line 677 of lalr1.cc  */
#line 4815 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 549:

/* Line 677 of lalr1.cc  */
#line 4819 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 550:

/* Line 677 of lalr1.cc  */
#line 4826 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 551:

/* Line 677 of lalr1.cc  */
#line 4832 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 552:

/* Line 677 of lalr1.cc  */
#line 4842 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 553:

/* Line 677 of lalr1.cc  */
#line 4850 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 554:

/* Line 677 of lalr1.cc  */
#line 4854 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 555:

/* Line 677 of lalr1.cc  */
#line 4858 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 556:

/* Line 677 of lalr1.cc  */
#line 4862 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 557:

/* Line 677 of lalr1.cc  */
#line 4866 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 558:

/* Line 677 of lalr1.cc  */
#line 4870 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 559:

/* Line 677 of lalr1.cc  */
#line 4874 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 560:

/* Line 677 of lalr1.cc  */
#line 4878 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 561:

/* Line 677 of lalr1.cc  */
#line 4882 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 562:

/* Line 677 of lalr1.cc  */
#line 4890 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyKindTest( LOC((yyloc)) );
        }
    break;

  case 563:

/* Line 677 of lalr1.cc  */
#line 4898 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)) );
        }
    break;

  case 564:

/* Line 677 of lalr1.cc  */
#line 4902 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)) );
        }
    break;

  case 565:

/* Line 677 of lalr1.cc  */
#line 4906 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest(
                LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 566:

/* Line 677 of lalr1.cc  */
#line 4916 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TextTest( LOC((yyloc)) );
        }
    break;

  case 567:

/* Line 677 of lalr1.cc  */
#line 4924 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CommentTest( LOC((yyloc)));
        }
    break;

  case 568:

/* Line 677 of lalr1.cc  */
#line 4932 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 569:

/* Line 677 of lalr1.cc  */
#line 4936 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 570:

/* Line 677 of lalr1.cc  */
#line 4940 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 571:

/* Line 677 of lalr1.cc  */
#line 4948 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 572:

/* Line 677 of lalr1.cc  */
#line 4952 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 573:

/* Line 677 of lalr1.cc  */
#line 4958 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 574:

/* Line 677 of lalr1.cc  */
#line 4964 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 575:

/* Line 677 of lalr1.cc  */
#line 4968 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 576:

/* Line 677 of lalr1.cc  */
#line 4978 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 577:

/* Line 677 of lalr1.cc  */
#line 4986 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 578:

/* Line 677 of lalr1.cc  */
#line 4990 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 579:

/* Line 677 of lalr1.cc  */
#line 4996 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 580:

/* Line 677 of lalr1.cc  */
#line 5005 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 581:

/* Line 677 of lalr1.cc  */
#line 5014 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 582:

/* Line 677 of lalr1.cc  */
#line 5020 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 583:

/* Line 677 of lalr1.cc  */
#line 5026 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 584:

/* Line 677 of lalr1.cc  */
#line 5036 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 585:

/* Line 677 of lalr1.cc  */
#line 5053 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 586:

/* Line 677 of lalr1.cc  */
#line 5060 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 587:

/* Line 677 of lalr1.cc  */
#line 5075 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 588:

/* Line 677 of lalr1.cc  */
#line 5111 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 589:

/* Line 677 of lalr1.cc  */
#line 5115 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 590:

/* Line 677 of lalr1.cc  */
#line 5124 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
        }
    break;

  case 591:

/* Line 677 of lalr1.cc  */
#line 5133 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new InlineFunction(LOC ((yyloc)), &*(yysemantic_stack_[(3) - (2)].fnsig)->param, &*(yysemantic_stack_[(3) - (2)].fnsig)->ret, dynamic_cast<EnclosedExpr *>((yysemantic_stack_[(3) - (3)].expr)));
          delete (yysemantic_stack_[(3) - (2)].fnsig);
        }
    break;

  case 592:

/* Line 677 of lalr1.cc  */
#line 5143 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 593:

/* Line 677 of lalr1.cc  */
#line 5147 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 594:

/* Line 677 of lalr1.cc  */
#line 5156 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
        }
    break;

  case 595:

/* Line 677 of lalr1.cc  */
#line 5165 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 596:

/* Line 677 of lalr1.cc  */
#line 5169 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 597:

/* Line 677 of lalr1.cc  */
#line 5180 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 598:

/* Line 677 of lalr1.cc  */
#line 5197 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 599:

/* Line 677 of lalr1.cc  */
#line 5203 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 600:

/* Line 677 of lalr1.cc  */
#line 5209 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 601:

/* Line 677 of lalr1.cc  */
#line 5219 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 602:

/* Line 677 of lalr1.cc  */
#line 5223 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 603:

/* Line 677 of lalr1.cc  */
#line 5229 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 604:

/* Line 677 of lalr1.cc  */
#line 5235 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 605:

/* Line 677 of lalr1.cc  */
#line 5239 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 606:

/* Line 677 of lalr1.cc  */
#line 5245 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 607:

/* Line 677 of lalr1.cc  */
#line 5249 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 608:

/* Line 677 of lalr1.cc  */
#line 5255 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 609:

/* Line 677 of lalr1.cc  */
#line 5261 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 610:

/* Line 677 of lalr1.cc  */
#line 5268 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 611:

/* Line 677 of lalr1.cc  */
#line 5278 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 612:

/* Line 677 of lalr1.cc  */
#line 5283 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 613:

/* Line 677 of lalr1.cc  */
#line 5291 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 614:

/* Line 677 of lalr1.cc  */
#line 5297 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 615:

/* Line 677 of lalr1.cc  */
#line 5307 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 616:

/* Line 677 of lalr1.cc  */
#line 5329 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 617:

/* Line 677 of lalr1.cc  */
#line 5338 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 618:

/* Line 677 of lalr1.cc  */
#line 5344 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 619:

/* Line 677 of lalr1.cc  */
#line 5357 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 620:

/* Line 677 of lalr1.cc  */
#line 5371 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 621:

/* Line 677 of lalr1.cc  */
#line 5378 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 622:

/* Line 677 of lalr1.cc  */
#line 5384 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 623:

/* Line 677 of lalr1.cc  */
#line 5394 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 624:

/* Line 677 of lalr1.cc  */
#line 5399 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CatchExpr(LOC((yyloc)),*(yysemantic_stack_[(7) - (2)].name_test_list), static_cast<QName*>((yysemantic_stack_[(7) - (5)].expr)), NULL, NULL, (yysemantic_stack_[(7) - (7)].expr));
       delete (yysemantic_stack_[(7) - (2)].name_test_list);
    }
    break;

  case 625:

/* Line 677 of lalr1.cc  */
#line 5404 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

  case 626:

/* Line 677 of lalr1.cc  */
#line 5414 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

  case 627:

/* Line 677 of lalr1.cc  */
#line 5427 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 628:

/* Line 677 of lalr1.cc  */
#line 5433 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 629:

/* Line 677 of lalr1.cc  */
#line 5450 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new EvalExpr(LOC((yyloc)), dynamic_cast<VarGetsDeclList *> ((yysemantic_stack_[(7) - (3)].node)), (yysemantic_stack_[(7) - (6)].expr));
        }
    break;

  case 630:

/* Line 677 of lalr1.cc  */
#line 5454 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new EvalExpr( LOC((yyloc)), new VarGetsDeclList( LOC((yyloc)) ), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 631:

/* Line 677 of lalr1.cc  */
#line 5469 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 632:

/* Line 677 of lalr1.cc  */
#line 5477 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 633:

/* Line 677 of lalr1.cc  */
#line 5481 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 634:

/* Line 677 of lalr1.cc  */
#line 5488 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 635:

/* Line 677 of lalr1.cc  */
#line 5493 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 636:

/* Line 677 of lalr1.cc  */
#line 5501 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 637:

/* Line 677 of lalr1.cc  */
#line 5505 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 638:

/* Line 677 of lalr1.cc  */
#line 5512 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 639:

/* Line 677 of lalr1.cc  */
#line 5516 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 640:

/* Line 677 of lalr1.cc  */
#line 5523 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 641:

/* Line 677 of lalr1.cc  */
#line 5527 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 642:

/* Line 677 of lalr1.cc  */
#line 5534 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 643:

/* Line 677 of lalr1.cc  */
#line 5538 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 644:

/* Line 677 of lalr1.cc  */
#line 5547 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 645:

/* Line 677 of lalr1.cc  */
#line 5559 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 646:

/* Line 677 of lalr1.cc  */
#line 5563 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 647:

/* Line 677 of lalr1.cc  */
#line 5570 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 648:

/* Line 677 of lalr1.cc  */
#line 5574 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 649:

/* Line 677 of lalr1.cc  */
#line 5582 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 650:

/* Line 677 of lalr1.cc  */
#line 5590 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 651:

/* Line 677 of lalr1.cc  */
#line 5598 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 652:

/* Line 677 of lalr1.cc  */
#line 5602 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 653:

/* Line 677 of lalr1.cc  */
#line 5609 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 654:

/* Line 677 of lalr1.cc  */
#line 5613 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 655:

/* Line 677 of lalr1.cc  */
#line 5621 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 656:

/* Line 677 of lalr1.cc  */
#line 5632 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 657:

/* Line 677 of lalr1.cc  */
#line 5636 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 658:

/* Line 677 of lalr1.cc  */
#line 5644 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 659:

/* Line 677 of lalr1.cc  */
#line 5656 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 660:

/* Line 677 of lalr1.cc  */
#line 5662 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 661:

/* Line 677 of lalr1.cc  */
#line 5671 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 662:

/* Line 677 of lalr1.cc  */
#line 5675 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 663:

/* Line 677 of lalr1.cc  */
#line 5683 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 664:

/* Line 677 of lalr1.cc  */
#line 5687 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 665:

/* Line 677 of lalr1.cc  */
#line 5691 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 666:

/* Line 677 of lalr1.cc  */
#line 5698 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 667:

/* Line 677 of lalr1.cc  */
#line 5702 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 668:

/* Line 677 of lalr1.cc  */
#line 5709 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 669:

/* Line 677 of lalr1.cc  */
#line 5713 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 670:

/* Line 677 of lalr1.cc  */
#line 5721 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 671:

/* Line 677 of lalr1.cc  */
#line 5725 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 672:

/* Line 677 of lalr1.cc  */
#line 5729 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 673:

/* Line 677 of lalr1.cc  */
#line 5733 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 674:

/* Line 677 of lalr1.cc  */
#line 5737 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 675:

/* Line 677 of lalr1.cc  */
#line 5745 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 676:

/* Line 677 of lalr1.cc  */
#line 5753 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 677:

/* Line 677 of lalr1.cc  */
#line 5765 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 678:

/* Line 677 of lalr1.cc  */
#line 5777 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 679:

/* Line 677 of lalr1.cc  */
#line 5781 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 680:

/* Line 677 of lalr1.cc  */
#line 5785 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 681:

/* Line 677 of lalr1.cc  */
#line 5793 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 682:

/* Line 677 of lalr1.cc  */
#line 5799 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 683:

/* Line 677 of lalr1.cc  */
#line 5809 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 684:

/* Line 677 of lalr1.cc  */
#line 5813 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 685:

/* Line 677 of lalr1.cc  */
#line 5817 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 686:

/* Line 677 of lalr1.cc  */
#line 5821 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 687:

/* Line 677 of lalr1.cc  */
#line 5825 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 688:

/* Line 677 of lalr1.cc  */
#line 5829 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 689:

/* Line 677 of lalr1.cc  */
#line 5833 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 690:

/* Line 677 of lalr1.cc  */
#line 5837 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 691:

/* Line 677 of lalr1.cc  */
#line 5845 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 692:

/* Line 677 of lalr1.cc  */
#line 5849 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 693:

/* Line 677 of lalr1.cc  */
#line 5853 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 694:

/* Line 677 of lalr1.cc  */
#line 5857 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 695:

/* Line 677 of lalr1.cc  */
#line 5865 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 696:

/* Line 677 of lalr1.cc  */
#line 5871 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 697:

/* Line 677 of lalr1.cc  */
#line 5881 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 698:

/* Line 677 of lalr1.cc  */
#line 5891 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::with );
        }
    break;

  case 699:

/* Line 677 of lalr1.cc  */
#line 5895 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::without );
        }
    break;

  case 700:

/* Line 677 of lalr1.cc  */
#line 5903 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

  case 701:

/* Line 677 of lalr1.cc  */
#line 5913 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

  case 702:

/* Line 677 of lalr1.cc  */
#line 5924 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 703:

/* Line 677 of lalr1.cc  */
#line 5931 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 704:

/* Line 677 of lalr1.cc  */
#line 5935 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 705:

/* Line 677 of lalr1.cc  */
#line 5942 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 706:

/* Line 677 of lalr1.cc  */
#line 5946 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(1) - (1)].thesaurus_id_list);
        }
    break;

  case 707:

/* Line 677 of lalr1.cc  */
#line 5953 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 708:

/* Line 677 of lalr1.cc  */
#line 5958 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 709:

/* Line 677 of lalr1.cc  */
#line 5967 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 710:

/* Line 677 of lalr1.cc  */
#line 5976 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = NULL;
        }
    break;

  case 711:

/* Line 677 of lalr1.cc  */
#line 5980 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 712:

/* Line 677 of lalr1.cc  */
#line 5987 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 713:

/* Line 677 of lalr1.cc  */
#line 5991 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 714:

/* Line 677 of lalr1.cc  */
#line 5999 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 715:

/* Line 677 of lalr1.cc  */
#line 6008 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 716:

/* Line 677 of lalr1.cc  */
#line 6015 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 717:

/* Line 677 of lalr1.cc  */
#line 6025 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 718:

/* Line 677 of lalr1.cc  */
#line 6029 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 719:

/* Line 677 of lalr1.cc  */
#line 6036 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 720:

/* Line 677 of lalr1.cc  */
#line 6042 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 721:

/* Line 677 of lalr1.cc  */
#line 6051 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 722:

/* Line 677 of lalr1.cc  */
#line 6055 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 723:

/* Line 677 of lalr1.cc  */
#line 6062 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 724:

/* Line 677 of lalr1.cc  */
#line 6067 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 725:

/* Line 677 of lalr1.cc  */
#line 6079 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 726:

/* Line 677 of lalr1.cc  */
#line 6087 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 727:

/* Line 677 of lalr1.cc  */
#line 6099 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 728:

/* Line 677 of lalr1.cc  */
#line 6107 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 729:

/* Line 677 of lalr1.cc  */
#line 6111 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 730:

/* Line 677 of lalr1.cc  */
#line 6119 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 731:

/* Line 677 of lalr1.cc  */
#line 6123 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 732:

/* Line 677 of lalr1.cc  */
#line 6127 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 733:

/* Line 677 of lalr1.cc  */
#line 6135 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 734:

/* Line 677 of lalr1.cc  */
#line 6143 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 735:

/* Line 677 of lalr1.cc  */
#line 6147 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 736:

/* Line 677 of lalr1.cc  */
#line 6151 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 737:

/* Line 677 of lalr1.cc  */
#line 6155 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 738:

/* Line 677 of lalr1.cc  */
#line 6163 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 739:

/* Line 677 of lalr1.cc  */
#line 6171 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 740:

/* Line 677 of lalr1.cc  */
#line 6183 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 741:

/* Line 677 of lalr1.cc  */
#line 6187 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 742:

/* Line 677 of lalr1.cc  */
#line 6195 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 745:

/* Line 677 of lalr1.cc  */
#line 6213 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

  case 747:

/* Line 677 of lalr1.cc  */
#line 6226 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 748:

/* Line 677 of lalr1.cc  */
#line 6227 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 749:

/* Line 677 of lalr1.cc  */
#line 6228 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 750:

/* Line 677 of lalr1.cc  */
#line 6229 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 751:

/* Line 677 of lalr1.cc  */
#line 6230 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 752:

/* Line 677 of lalr1.cc  */
#line 6231 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 753:

/* Line 677 of lalr1.cc  */
#line 6232 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 754:

/* Line 677 of lalr1.cc  */
#line 6233 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 755:

/* Line 677 of lalr1.cc  */
#line 6234 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 756:

/* Line 677 of lalr1.cc  */
#line 6235 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 757:

/* Line 677 of lalr1.cc  */
#line 6236 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 758:

/* Line 677 of lalr1.cc  */
#line 6237 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 759:

/* Line 677 of lalr1.cc  */
#line 6238 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 760:

/* Line 677 of lalr1.cc  */
#line 6239 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 761:

/* Line 677 of lalr1.cc  */
#line 6240 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 763:

/* Line 677 of lalr1.cc  */
#line 6245 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 764:

/* Line 677 of lalr1.cc  */
#line 6246 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 765:

/* Line 677 of lalr1.cc  */
#line 6247 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 766:

/* Line 677 of lalr1.cc  */
#line 6248 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 767:

/* Line 677 of lalr1.cc  */
#line 6249 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 768:

/* Line 677 of lalr1.cc  */
#line 6250 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 769:

/* Line 677 of lalr1.cc  */
#line 6251 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 770:

/* Line 677 of lalr1.cc  */
#line 6252 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 771:

/* Line 677 of lalr1.cc  */
#line 6253 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 772:

/* Line 677 of lalr1.cc  */
#line 6254 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 773:

/* Line 677 of lalr1.cc  */
#line 6255 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 774:

/* Line 677 of lalr1.cc  */
#line 6256 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 775:

/* Line 677 of lalr1.cc  */
#line 6257 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 776:

/* Line 677 of lalr1.cc  */
#line 6258 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 777:

/* Line 677 of lalr1.cc  */
#line 6259 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 778:

/* Line 677 of lalr1.cc  */
#line 6260 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 779:

/* Line 677 of lalr1.cc  */
#line 6261 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 780:

/* Line 677 of lalr1.cc  */
#line 6262 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 781:

/* Line 677 of lalr1.cc  */
#line 6263 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 782:

/* Line 677 of lalr1.cc  */
#line 6264 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 783:

/* Line 677 of lalr1.cc  */
#line 6265 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 784:

/* Line 677 of lalr1.cc  */
#line 6266 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 785:

/* Line 677 of lalr1.cc  */
#line 6267 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 786:

/* Line 677 of lalr1.cc  */
#line 6268 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 787:

/* Line 677 of lalr1.cc  */
#line 6269 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 788:

/* Line 677 of lalr1.cc  */
#line 6270 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 789:

/* Line 677 of lalr1.cc  */
#line 6271 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 790:

/* Line 677 of lalr1.cc  */
#line 6272 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 791:

/* Line 677 of lalr1.cc  */
#line 6273 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 792:

/* Line 677 of lalr1.cc  */
#line 6274 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 793:

/* Line 677 of lalr1.cc  */
#line 6275 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 794:

/* Line 677 of lalr1.cc  */
#line 6276 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 795:

/* Line 677 of lalr1.cc  */
#line 6277 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 796:

/* Line 677 of lalr1.cc  */
#line 6278 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 797:

/* Line 677 of lalr1.cc  */
#line 6279 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 798:

/* Line 677 of lalr1.cc  */
#line 6280 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 799:

/* Line 677 of lalr1.cc  */
#line 6281 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 800:

/* Line 677 of lalr1.cc  */
#line 6282 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 801:

/* Line 677 of lalr1.cc  */
#line 6283 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 802:

/* Line 677 of lalr1.cc  */
#line 6284 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 803:

/* Line 677 of lalr1.cc  */
#line 6285 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 804:

/* Line 677 of lalr1.cc  */
#line 6286 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 805:

/* Line 677 of lalr1.cc  */
#line 6287 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 806:

/* Line 677 of lalr1.cc  */
#line 6288 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 807:

/* Line 677 of lalr1.cc  */
#line 6289 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 808:

/* Line 677 of lalr1.cc  */
#line 6290 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 809:

/* Line 677 of lalr1.cc  */
#line 6291 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 810:

/* Line 677 of lalr1.cc  */
#line 6292 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 811:

/* Line 677 of lalr1.cc  */
#line 6293 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 812:

/* Line 677 of lalr1.cc  */
#line 6294 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 813:

/* Line 677 of lalr1.cc  */
#line 6295 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 814:

/* Line 677 of lalr1.cc  */
#line 6296 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 815:

/* Line 677 of lalr1.cc  */
#line 6297 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 816:

/* Line 677 of lalr1.cc  */
#line 6298 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 817:

/* Line 677 of lalr1.cc  */
#line 6299 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 818:

/* Line 677 of lalr1.cc  */
#line 6300 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 819:

/* Line 677 of lalr1.cc  */
#line 6301 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 820:

/* Line 677 of lalr1.cc  */
#line 6302 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 821:

/* Line 677 of lalr1.cc  */
#line 6303 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 822:

/* Line 677 of lalr1.cc  */
#line 6304 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 823:

/* Line 677 of lalr1.cc  */
#line 6305 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 824:

/* Line 677 of lalr1.cc  */
#line 6306 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 825:

/* Line 677 of lalr1.cc  */
#line 6307 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 826:

/* Line 677 of lalr1.cc  */
#line 6308 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 827:

/* Line 677 of lalr1.cc  */
#line 6309 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 828:

/* Line 677 of lalr1.cc  */
#line 6310 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 829:

/* Line 677 of lalr1.cc  */
#line 6311 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 830:

/* Line 677 of lalr1.cc  */
#line 6312 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 831:

/* Line 677 of lalr1.cc  */
#line 6313 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 832:

/* Line 677 of lalr1.cc  */
#line 6314 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 833:

/* Line 677 of lalr1.cc  */
#line 6315 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 834:

/* Line 677 of lalr1.cc  */
#line 6316 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 835:

/* Line 677 of lalr1.cc  */
#line 6317 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 836:

/* Line 677 of lalr1.cc  */
#line 6318 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 837:

/* Line 677 of lalr1.cc  */
#line 6319 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 838:

/* Line 677 of lalr1.cc  */
#line 6320 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 839:

/* Line 677 of lalr1.cc  */
#line 6321 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 840:

/* Line 677 of lalr1.cc  */
#line 6322 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 841:

/* Line 677 of lalr1.cc  */
#line 6323 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 842:

/* Line 677 of lalr1.cc  */
#line 6324 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 843:

/* Line 677 of lalr1.cc  */
#line 6325 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 844:

/* Line 677 of lalr1.cc  */
#line 6326 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 845:

/* Line 677 of lalr1.cc  */
#line 6327 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 846:

/* Line 677 of lalr1.cc  */
#line 6328 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 847:

/* Line 677 of lalr1.cc  */
#line 6329 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 848:

/* Line 677 of lalr1.cc  */
#line 6330 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 849:

/* Line 677 of lalr1.cc  */
#line 6331 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 850:

/* Line 677 of lalr1.cc  */
#line 6332 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 851:

/* Line 677 of lalr1.cc  */
#line 6333 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 852:

/* Line 677 of lalr1.cc  */
#line 6334 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 853:

/* Line 677 of lalr1.cc  */
#line 6335 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 854:

/* Line 677 of lalr1.cc  */
#line 6336 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 855:

/* Line 677 of lalr1.cc  */
#line 6337 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 856:

/* Line 677 of lalr1.cc  */
#line 6338 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 857:

/* Line 677 of lalr1.cc  */
#line 6339 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 858:

/* Line 677 of lalr1.cc  */
#line 6340 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 859:

/* Line 677 of lalr1.cc  */
#line 6341 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 860:

/* Line 677 of lalr1.cc  */
#line 6342 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 861:

/* Line 677 of lalr1.cc  */
#line 6343 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 862:

/* Line 677 of lalr1.cc  */
#line 6344 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 863:

/* Line 677 of lalr1.cc  */
#line 6345 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 864:

/* Line 677 of lalr1.cc  */
#line 6346 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 865:

/* Line 677 of lalr1.cc  */
#line 6347 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 866:

/* Line 677 of lalr1.cc  */
#line 6348 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 867:

/* Line 677 of lalr1.cc  */
#line 6349 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 868:

/* Line 677 of lalr1.cc  */
#line 6350 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 869:

/* Line 677 of lalr1.cc  */
#line 6351 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 870:

/* Line 677 of lalr1.cc  */
#line 6352 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 871:

/* Line 677 of lalr1.cc  */
#line 6353 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 872:

/* Line 677 of lalr1.cc  */
#line 6354 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 873:

/* Line 677 of lalr1.cc  */
#line 6355 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 874:

/* Line 677 of lalr1.cc  */
#line 6356 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 875:

/* Line 677 of lalr1.cc  */
#line 6357 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 876:

/* Line 677 of lalr1.cc  */
#line 6358 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 877:

/* Line 677 of lalr1.cc  */
#line 6359 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 878:

/* Line 677 of lalr1.cc  */
#line 6360 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 879:

/* Line 677 of lalr1.cc  */
#line 6361 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 880:

/* Line 677 of lalr1.cc  */
#line 6362 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 881:

/* Line 677 of lalr1.cc  */
#line 6363 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 882:

/* Line 677 of lalr1.cc  */
#line 6364 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 883:

/* Line 677 of lalr1.cc  */
#line 6365 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 884:

/* Line 677 of lalr1.cc  */
#line 6366 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 885:

/* Line 677 of lalr1.cc  */
#line 6367 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 886:

/* Line 677 of lalr1.cc  */
#line 6368 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 887:

/* Line 677 of lalr1.cc  */
#line 6369 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 888:

/* Line 677 of lalr1.cc  */
#line 6370 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 889:

/* Line 677 of lalr1.cc  */
#line 6371 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 890:

/* Line 677 of lalr1.cc  */
#line 6372 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 891:

/* Line 677 of lalr1.cc  */
#line 6373 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 892:

/* Line 677 of lalr1.cc  */
#line 6374 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 893:

/* Line 677 of lalr1.cc  */
#line 6375 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 894:

/* Line 677 of lalr1.cc  */
#line 6376 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 895:

/* Line 677 of lalr1.cc  */
#line 6377 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 896:

/* Line 677 of lalr1.cc  */
#line 6378 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 897:

/* Line 677 of lalr1.cc  */
#line 6379 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 898:

/* Line 677 of lalr1.cc  */
#line 6380 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 899:

/* Line 677 of lalr1.cc  */
#line 6381 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 900:

/* Line 677 of lalr1.cc  */
#line 6382 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 901:

/* Line 677 of lalr1.cc  */
#line 6383 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 902:

/* Line 677 of lalr1.cc  */
#line 6384 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 903:

/* Line 677 of lalr1.cc  */
#line 6385 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 904:

/* Line 677 of lalr1.cc  */
#line 6386 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("deterministic"))); }
    break;

  case 905:

/* Line 677 of lalr1.cc  */
#line 6387 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nondeterministic"))); }
    break;

  case 906:

/* Line 677 of lalr1.cc  */
#line 6388 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 907:

/* Line 677 of lalr1.cc  */
#line 6389 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 908:

/* Line 677 of lalr1.cc  */
#line 6390 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 909:

/* Line 677 of lalr1.cc  */
#line 6391 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("block"))); }
    break;

  case 910:

/* Line 677 of lalr1.cc  */
#line 6392 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 911:

/* Line 677 of lalr1.cc  */
#line 6393 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 912:

/* Line 677 of lalr1.cc  */
#line 6394 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 913:

/* Line 677 of lalr1.cc  */
#line 6395 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 914:

/* Line 677 of lalr1.cc  */
#line 6396 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 915:

/* Line 677 of lalr1.cc  */
#line 6397 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 916:

/* Line 677 of lalr1.cc  */
#line 6398 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eval"))); }
    break;

  case 917:

/* Line 677 of lalr1.cc  */
#line 6399 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 918:

/* Line 677 of lalr1.cc  */
#line 6400 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 919:

/* Line 677 of lalr1.cc  */
#line 6401 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 920:

/* Line 677 of lalr1.cc  */
#line 6402 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 921:

/* Line 677 of lalr1.cc  */
#line 6403 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 922:

/* Line 677 of lalr1.cc  */
#line 6404 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 923:

/* Line 677 of lalr1.cc  */
#line 6405 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 924:

/* Line 677 of lalr1.cc  */
#line 6406 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 925:

/* Line 677 of lalr1.cc  */
#line 6407 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 926:

/* Line 677 of lalr1.cc  */
#line 6408 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 927:

/* Line 677 of lalr1.cc  */
#line 6409 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 928:

/* Line 677 of lalr1.cc  */
#line 6410 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 929:

/* Line 677 of lalr1.cc  */
#line 6411 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 930:

/* Line 677 of lalr1.cc  */
#line 6412 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 931:

/* Line 677 of lalr1.cc  */
#line 6413 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 932:

/* Line 677 of lalr1.cc  */
#line 6414 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 933:

/* Line 677 of lalr1.cc  */
#line 6415 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 934:

/* Line 677 of lalr1.cc  */
#line 6416 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 935:

/* Line 677 of lalr1.cc  */
#line 6417 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 936:

/* Line 677 of lalr1.cc  */
#line 6418 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 937:

/* Line 677 of lalr1.cc  */
#line 6419 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 938:

/* Line 677 of lalr1.cc  */
#line 6420 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 939:

/* Line 677 of lalr1.cc  */
#line 6421 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 940:

/* Line 677 of lalr1.cc  */
#line 6422 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 941:

/* Line 677 of lalr1.cc  */
#line 6423 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 942:

/* Line 677 of lalr1.cc  */
#line 6424 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 943:

/* Line 677 of lalr1.cc  */
#line 6425 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 944:

/* Line 677 of lalr1.cc  */
#line 6426 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 945:

/* Line 677 of lalr1.cc  */
#line 6427 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 946:

/* Line 677 of lalr1.cc  */
#line 6428 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 947:

/* Line 677 of lalr1.cc  */
#line 6429 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 948:

/* Line 677 of lalr1.cc  */
#line 6430 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 949:

/* Line 677 of lalr1.cc  */
#line 6431 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 950:

/* Line 677 of lalr1.cc  */
#line 6432 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 951:

/* Line 677 of lalr1.cc  */
#line 6433 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 952:

/* Line 677 of lalr1.cc  */
#line 6434 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 953:

/* Line 677 of lalr1.cc  */
#line 6435 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 954:

/* Line 677 of lalr1.cc  */
#line 6436 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 955:

/* Line 677 of lalr1.cc  */
#line 6437 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 956:

/* Line 677 of lalr1.cc  */
#line 6438 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 957:

/* Line 677 of lalr1.cc  */
#line 6439 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 958:

/* Line 677 of lalr1.cc  */
#line 6440 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 959:

/* Line 677 of lalr1.cc  */
#line 6441 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 960:

/* Line 677 of lalr1.cc  */
#line 6442 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 961:

/* Line 677 of lalr1.cc  */
#line 6443 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 962:

/* Line 677 of lalr1.cc  */
#line 6444 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 963:

/* Line 677 of lalr1.cc  */
#line 6449 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { 
          // EQName's namespace URI value is whitespace normalized according to the rules for the xs:anyURI type
          std::string uri = "\"" + SYMTAB((yysemantic_stack_[(3) - (1)].sval)) + "\"";
          std::string eqname = SYMTAB(driver.symtab.put_uri(uri.c_str(), uri.size())) + ":" + SYMTAB((yysemantic_stack_[(3) - (3)].sval));
          (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT(eqname.c_str())), true); 
        }
    break;

  case 964:

/* Line 677 of lalr1.cc  */
#line 6455 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;



/* Line 677 of lalr1.cc  */
#line 11555 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1370;
  const short int
  xquery_parser::yypact_[] =
  {
      1992, -1370, -1370,  2291,  2589,  2887, -1370, -1370,    -7,  1036,
       2, -1370, -1370, -1370,   569, -1370, -1370, -1370, -1370,   269,
     183,   570,   277,   464,   234,   515,    96, -1370,   -15, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370,   574, -1370,   519,   556,
   -1370,   386, -1370, -1370,   465, -1370,   580, -1370,   582,   585,
   -1370,   236, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370,   545,   562, -1370, -1370, -1370,
   -1370,   368,  8251, -1370, -1370, -1370,   628, -1370, -1370, -1370,
   -1370, -1370,   631,   639, -1370, -1370, 11431, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370,   647, -1370, -1370,   645,   655,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370,  3185, 11431, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370,   630, -1370, -1370,   663,
    9137, -1370,  9429,   678,   682, -1370, -1370, -1370,   688, -1370,
    7953, -1370, -1370, -1370, -1370, -1370, -1370,   661, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370,    18,   603, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370,   379,   677,   475, -1370,
     601,   469, -1370, -1370, -1370, -1370, -1370, -1370,   719, -1370,
     685,   598,   602,   600, -1370, -1370,   684,   691, -1370,   727,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
    5271,   845, -1370,  5569, -1370, -1370,   543,    48,    57, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370,   571, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370,    10, -1370, -1370, -1370, -1370,   439, -1370, -1370, -1370,
   -1370, -1370, -1370,   680,   756, -1370,   679,   604,   428,   228,
      84,   466, -1370,   799,   652,   751,   752,  5867, -1370, -1370,
   -1370,   153, -1370, -1370,  7953, -1370,   599, -1370,   702,  8251,
   -1370,   702,  8251, -1370, -1370, -1370,   591, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
     738,   715,   705, -1370, -1370, -1370, -1370, -1370, -1370,   683,
   -1370,   686, -1370,   687,   712,   841,   -39,   -25,   507, 11717,
   11431,   -38,   824,   825,   826, 11431,   724,   760,   423,  9137,
   -1370, -1370,   535,   492,   633, 11431, -1370, -1370, -1370, -1370,
   -1370,   587, 11431,   605,   606,   494,   593,   485, -1370,    71,
   -1370, -1370, -1370, -1370, -1370,  9137,  6165,   711,  6165,    30,
    6165, 10001,  6165,   617,   621, 11431,   788,    15,   754,  6165,
      80,    85, 11431,   790,   768,   805, -1370,  6165,  8843, 11431,
   11431, 11431, 11431,  6165,   726,  6165,  6165, 11431,  6165,   761,
     762, -1370, -1370, -1370,  6165, 10287, -1370,   763, -1370,   764,
   -1370, -1370, -1370, -1370, -1370,   765, -1370, -1370,   766, -1370,
   -1370, -1370, -1370, -1370,   767, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, 11431, -1370, -1370, -1370,   730,
     884,  6165, -1370, -1370,    55, -1370, -1370, -1370,   907, -1370,
   -1370, -1370, -1370,  6165,   713, -1370,   897,  6165,  6165,   740,
    6165,  6165,  6165,  6165,   698, 11431, -1370, -1370, -1370, -1370,
    6165,  6165,  6165, 11431, -1370, -1370, -1370, -1370,  1036,    96,
      72,    78,   925,  6463,  6463,  6761,  6761,   791,  6165,  6165,
   -1370,  6165,   812,   464,   -15,   770,   769,   771,  6165,  6165,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370,  7059,  7059,  7059,
   -1370,  7059,  7059, -1370,  7059, -1370,  7059, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370,  7059,  7059,   868,  7059,  7059,  7059,
    7059,  7059,  7059,  7059,  7059,  7059,  7059,  7059,   716,   847,
     852,   853, -1370, -1370, -1370,  3483, -1370, -1370,  7953,  7953,
    6165,   702, -1370, -1370,   702, -1370,  3781,   702,  9137,   800,
    4079, -1370, -1370, -1370,   186, -1370, -1370, -1370, -1370, -1370,
     844,   846,   234,   926, -1370, -1370, 11717, -1370, 11717,   806,
     516, 11431,   795,   796,   806,   841,   833,   829, -1370, -1370,
   -1370, -1370, -1370,    34,   718,   -24, -1370,   666, -1370, -1370,
   -1370, -1370, 11431, 11431, 11431, -1370,   848, -1370, -1370,   835,
     784, -1370,   785,   764,   556, -1370,   787,   789,   793, -1370,
      74,   197,   794, -1370, -1370,   864, -1370,     5, 11431,   -11,
   11431,   880,   218, -1370,  6165, -1370,   797,  9137,   885,   936,
    9137,   841,   886,   226, 11431,  6165,   -15,   801,   803, -1370,
     804,   807,   808,   850,    20, -1370,   290,   802, -1370,   809,
     810,   834, -1370,   814,  6165,  6165,   815, -1370,   231,   233,
      89, -1370, 11431,   884, -1370,   -31,   816, -1370, -1370, -1370,
     817, -1370,   205, -1370, -1370, -1370,   165,   298,   893,   757,
     778,   -21, -1370,   861,  7357, -1370,   818,   823,    94, -1370,
   -1370,   543,   581,   976,   976, -1370,    81, -1370, -1370,    82,
   -1370, -1370,   113, -1370, -1370, -1370, -1370,  6165, -1370, -1370,
      13, 11431,   839,  6165,   892, -1370, -1370,   756, -1370, -1370,
   -1370, -1370, -1370,  7059, -1370, -1370, -1370,    11,   228,   228,
     460,    84,    84,    84,    84,   466,   466, -1370, -1370, 10859,
   10859, 11431, 11431, -1370,   827, -1370, -1370,   828, -1370, -1370,
   -1370,   241, -1370, -1370, -1370,   245, -1370,   252, -1370,   184,
     503,   537, -1370,   234,   234, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370,   806, -1370,   882, 11145,   870,
    6165, -1370, -1370, -1370,   920,   841,   841,   806, -1370,   669,
     841,   427, 11431,  -121,   238,   988, -1370, -1370,   731,   327,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370,    34,    43,   517, -1370,   792,   239,   -18,   720, 11431,
     841, -1370, -1370, -1370, -1370,   867, 11431, -1370, 11431, -1370,
   -1370,   903,   895, 10859,   905,  6165,    22,   877,     1,   304,
     772, -1370, -1370,   520,   -11,   920, 10859,   909,   930,   849,
     831,   899,   841,   869,   900,   938,   841,  6165,   -66, -1370,
   -1370, -1370,   883, -1370, -1370, -1370, -1370,  6165,   919,  6165,
    6165,   894, -1370,   939,   942,  6165, -1370,   859,   860,   896,
   11431, -1370, 11431, -1370,  6165,  1011, -1370,    -2, -1370,   163,
   -1370, -1370,  1018, -1370,   504,  6165,  6165,  6165,   531,  6165,
    6165,  6165,  6165,  6165,  6165,   929,  6165,  6165,   932,    65,
     871,   685,   811,   898,   934,    83,    86,   113,  6761,  6761,
    6761,   968, -1370, -1370, -1370,  6165,   417,   947, -1370, 11431,
     950, -1370, -1370,  6165,    11,    67,   349, -1370,   773,   301,
     813,   819, -1370, -1370,   633, -1370,   798,   395,   904,   908,
   11145,   911, -1370,   413, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370,   915, -1370, -1370, -1370,  6165, -1370, -1370,
     186, -1370, -1370, -1370, -1370, -1370, -1370,  6165, -1370,   539,
     541, -1370,  1033,   578, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370,   782, -1370, -1370,  1041, -1370, -1370, -1370,
   -1370, -1370,   445,  1042, -1370,   583, -1370, -1370, -1370,   763,
     183,   765,   519,   766,   767,   677,   842,   413,   851,   854,
    7655,   820,   777,    43, -1370,   862,   920,   901,  4377,   902,
     906,   941,   910,   912, 11431,   348, -1370, 11431, -1370,  6165,
     940,  6165,   959,  6165,    50,   945,  6165,   949, -1370,   980,
     982,  6165, 11431,   237,  1024, -1370, -1370, -1370, -1370, -1370,
   -1370, 10859, -1370,  6165,   841,   997, -1370, -1370, -1370,   841,
     997, -1370,  6165,   964,  4675, -1370, 11431, -1370, -1370,  6165,
    6165,   393, -1370,     9, 10573,   528, -1370,   924, -1370, -1370,
    4973,   922,   923, -1370, -1370,   979, -1370,   402, -1370, -1370,
    1106, -1370, -1370, 11431, -1370, -1370,   509, -1370, -1370, -1370,
     927,   888,   889, -1370, -1370, -1370,   890,   891, -1370, -1370,
   -1370, -1370, -1370,   914, 11431,   943, -1370, 11431, -1370,   932,
   -1370, -1370, -1370,  8549,   811, -1370,  6165, 11431,   976,   440,
   -1370, -1370, -1370,   947, -1370,   841, -1370,   674, -1370,   472,
    1012, -1370,  6165,  1019,   892,   944,   937, -1370,    11,   876,
   -1370, -1370,   -67, -1370,   362,   -28,   881,    11,   362,  7059,
   -1370,   256, -1370, -1370, -1370, -1370, -1370, -1370,    11,   983,
     855,   718,   -28, -1370, -1370,   856,  1048, -1370, -1370, -1370,
    9715,   948,   951,   952, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370,   956, -1370, -1370, -1370,  6165, -1370, -1370, -1370, -1370,
    1108,    19,  1113,    19,   863,  1046, -1370, -1370, -1370, -1370,
     974, 11431,   913,   842,  7655, -1370, -1370, -1370,   961, -1370,
   -1370, -1370, -1370, -1370, -1370,  6165,   999, -1370, -1370,  6165,
   -1370,   434, -1370,  6165,  1004,  6165, -1370,  6165, 11431, 11431,
   -1370,   512, -1370,  6165, -1370,  1026,  1057,   841,   997, -1370,
    6165, -1370,   971, -1370, -1370, -1370,   973, -1370,  6165,  6165,
   11431,   977,     6, -1370, -1370, -1370,   981, -1370, -1370,  1011,
   11431,   554, -1370,  1011, 11431, -1370, -1370,  6165,  6165,  6165,
    6165,  6165, -1370,  6165,   372, -1370, -1370,   202, -1370,   984,
   -1370, -1370, -1370, -1370,  1012, -1370, -1370, -1370,   841, -1370,
   -1370, -1370, -1370, -1370,   985,  7059, -1370, -1370, -1370, -1370,
   -1370,    77,  7059,  7059,  -110, -1370,   813, -1370,   -65, -1370,
     819,    11,  1007, -1370, -1370,   887, -1370, -1370, -1370, -1370,
    1062,   986, -1370,   255, -1370, -1370, -1370, -1370,   -16, -1370,
     344,   344, -1370,    19, -1370, -1370,   259, -1370,  1136,   -28,
     987,  1064, -1370,  7655,   -73,   916, -1370,  1002, -1370, -1370,
    6165, -1370,  6165,  1028, -1370,  6165, -1370, -1370, -1370,  1123,
   -1370, -1370,  6165,   841, -1370, -1370, -1370,  6165, -1370, -1370,
    1083,  6165, 11431,  6165, -1370,     7,  1011, 11431,   990,  1011,
   -1370, -1370, -1370, -1370, -1370, -1370,  6165,  1038,  1063,  8549,
   -1370, -1370, -1370, -1370, -1370,    84,  7059,  7059,   460,   511,
   -1370, -1370, -1370, -1370, -1370, -1370,  6165, -1370, 10859, -1370,
   10859,  1087, -1370, -1370, -1370, -1370,  1155, -1370, -1370, -1370,
     928, -1370,  1046,  1077, -1370,   575, 11431,  1069,   965, 11431,
    7655, -1370, -1370,  6165, -1370,  1070, -1370,   997, -1370, 10859,
   -1370,  1006, -1370,   169,   416, -1370,   994,  1011, -1370,   998,
   -1370,  6165, 11431, -1370,   460,   460,  7059,  1014, -1370, -1370,
   10859, -1370, -1370, -1370,  7655, -1370,  1012,   917, 11431,  1081,
     978,  1077, -1370, 11431,  1015,  6165, -1370, -1370,  1110,   176,
   -1370, -1370, -1370, -1370,  1023,   437, -1370, -1370, -1370,  1013,
   -1370, -1370,   263,   460, -1370, -1370, -1370, -1370,  6165,   918,
   11431,  1089, -1370,  6165, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370,  1092,  1058, -1370,   921,   931, 11431, -1370, 11431,
   -1370,   933,  6165,   935,   266,  7655, -1370,  7655,  1094,  1058,
   -1370,  1017, 11431, -1370,   946,  1029, 11431,  1058,   989, -1370,
    1099, 11431,   953,  7655, -1370
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
         0,   433,   434,     0,     0,     0,   763,   964,   587,   854,
     863,   804,   768,   766,   748,   855,   858,   811,   904,   772,
     749,   750,   916,   803,   864,   752,   861,   833,   813,   788,
     808,   905,   809,   859,   856,   807,   754,   862,   755,   756,
     902,   918,   901,   805,   824,   818,   757,   806,   759,   758,
     903,   842,   810,   785,   928,   929,   930,   931,   932,   933,
     934,   935,   936,   937,   938,   952,   959,   832,   828,   819,
     799,   747,     0,   827,   835,   843,   953,   823,   453,   800,
     801,   857,   954,   960,   820,   837,     0,   459,   422,   455,
     830,   765,   821,   822,   850,   825,   841,   849,   958,   961,
     771,   812,   852,   454,   840,   845,   751,     0,     0,   370,
     838,   848,   853,   851,   831,   817,   906,   815,   816,   955,
       0,   369,     0,   956,   962,   846,   802,   826,   957,   400,
       0,   432,   847,   829,   836,   844,   839,   907,   793,   798,
     797,   796,   795,   794,   760,   814,     0,   764,   860,   786,
     893,   892,   894,   770,   769,   789,   899,   753,   891,   896,
     897,   888,   792,   834,   890,   900,   898,   889,   790,   895,
     909,   912,   913,   910,   911,   908,   761,   914,   915,   917,
     880,   879,   866,   784,   777,   873,   869,   787,   783,   882,
     883,   773,   774,   767,   776,   878,   877,   874,   870,   887,
     881,   876,   872,   865,   775,   886,   885,   779,   781,   780,
     871,   875,   867,   782,   868,   778,   884,   939,   940,   941,
     942,   943,   944,   920,   921,   919,   925,   926,   927,   922,
     923,   924,   791,   945,   946,   947,   948,   949,   950,   951,
       0,     0,     2,     0,     5,     7,    19,     0,     0,    24,
      27,    38,    30,    31,    32,    58,    33,    42,    34,    62,
      63,    64,    59,    60,    66,    67,    37,     0,    35,    36,
      40,    41,    61,   220,   219,   216,   217,   218,    39,    14,
     196,   197,   201,   203,   235,   241,     0,   233,   234,   204,
     205,   206,   207,   208,   325,   327,   329,   339,   343,   345,
     348,   353,   356,   359,   361,   363,   365,     0,   367,   373,
     375,     0,   391,   374,   396,   399,   401,   404,   406,     0,
     411,   408,     0,   419,   429,   431,   405,   435,   442,   451,
     443,   444,   445,   448,   449,   446,   447,   466,   468,   469,
     470,   467,   515,   516,   517,   518,   519,   520,   428,   561,
     553,   560,   559,   558,   555,   557,   554,   556,   452,   450,
     588,   589,    65,   209,   210,   212,   211,   213,   214,   215,
       0,   430,   746,   762,   854,   863,   861,   522,   764,     0,
     526,     0,   532,     0,   174,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     117,   118,     0,     0,     0,     0,   113,   114,   115,   116,
     123,     0,     0,     0,     0,     0,     0,     0,   111,     0,
     172,   178,   180,   183,   182,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   260,   261,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   424,   427,   414,     0,     0,   743,   748,   772,   750,
     916,   803,   864,   752,   813,   754,   918,   824,   757,   759,
     758,   842,   952,   959,   747,   953,   954,   960,   825,   958,
     961,   906,   955,   956,   962,   957,   907,   899,   891,   897,
     888,   790,   909,   912,   913,   910,   761,   914,   917,   420,
     430,   746,   412,   413,   416,   748,   749,   750,   754,   755,
     756,   757,   747,   753,   456,     0,   418,   417,   457,     0,
     482,     0,   423,   744,     0,   745,   394,   395,     0,   426,
     425,   415,   398,     0,     0,   511,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   160,   157,   170,   171,
       0,     0,     0,     0,     3,     1,     6,     8,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   109,     0,     0,
     199,   198,     0,     0,     0,     0,     0,     0,     0,     0,
     221,   240,   236,   242,   237,   239,   238,     0,     0,     0,
     384,     0,     0,   382,     0,   334,     0,   383,   376,   381,
     380,   379,   378,   377,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   372,   371,   368,     0,   392,   397,     0,     0,
       0,   407,   439,   410,   409,   421,     0,   436,     0,     0,
       0,   523,   527,   533,     0,    84,    69,    70,   151,   152,
       0,     0,     0,     0,    75,    76,     0,   181,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   598,   599,
     600,   120,   119,     0,    74,   127,   124,     0,   126,   125,
     122,   121,     0,     0,     0,   112,     0,   173,   179,     0,
       0,   567,     0,     0,     0,   563,     0,     0,     0,   577,
       0,     0,     0,   223,   224,   243,   244,     0,     0,     0,
       0,   153,     0,   190,     0,   591,     0,     0,    93,     0,
       0,     0,    85,     0,     0,     0,     0,     0,   743,   568,
       0,     0,     0,     0,     0,   308,     0,     0,   566,     0,
       0,     0,   585,     0,     0,     0,     0,   571,     0,     0,
       0,   458,   483,   482,   479,     0,     0,   513,   512,   393,
       0,   510,     0,   611,   612,   562,     0,     0,     0,     0,
       0,     0,   617,     0,     0,   168,     0,     0,     0,   263,
     265,    20,     0,    21,     0,     4,     0,    25,    11,     0,
      26,    15,   854,    28,    12,    29,    16,     0,   108,   202,
       0,     0,     0,     0,     0,   222,   281,   326,   328,   332,
     338,   337,   336,     0,   333,   330,   331,     0,   347,   346,
     344,   350,   351,   352,   349,   354,   355,   358,   357,     0,
       0,     0,     0,   389,     0,   402,   403,     0,   440,   437,
     464,     0,   963,   590,   462,     0,   587,     0,   176,     0,
       0,     0,    73,     0,     0,    48,    50,    51,    52,    53,
      55,    56,    57,    49,    54,    44,    45,     0,     0,   101,
       0,    97,    99,   100,   104,     0,     0,    43,    83,     0,
       0,     0,     0,     0,     0,     0,   693,   698,     0,     0,
     694,   728,   681,   683,   684,   685,   687,   689,   688,   686,
     690,     0,     0,     0,   128,     0,     0,   131,     0,     0,
       0,   531,   521,   564,   565,     0,     0,   581,     0,   578,
     630,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   225,   226,     0,   231,   192,     0,     0,   154,     0,
       0,     0,     0,     0,     0,    86,     0,     0,     0,   259,
     268,   262,     0,   570,   569,   576,   584,     0,     0,     0,
       0,     0,   530,     0,     0,     0,   385,     0,     0,     0,
       0,   574,     0,   572,     0,   482,   480,     0,   471,     0,
     460,   461,     0,     9,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   854,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   110,   200,   232,     0,   292,   288,   290,     0,
     282,   283,   335,     0,     0,     0,     0,   659,   341,   632,
     636,   638,   640,   642,   645,   652,   653,   661,   864,   751,
       0,   760,   360,   539,   545,   546,   548,   592,   593,   549,
     552,   362,   364,   536,   366,   390,   441,     0,   438,   463,
       0,   175,    81,    82,    79,    80,   185,     0,   184,     0,
       0,    46,     0,     0,   102,   103,   105,    71,    72,    77,
      78,    68,   699,     0,   702,   729,     0,   692,   691,   696,
     695,   727,     0,     0,   704,     0,   700,   703,   682,     0,
       0,     0,     0,     0,     0,     0,   129,   135,     0,     0,
       0,     0,     0,     0,   132,     0,   106,     0,     0,     0,
       0,   585,     0,     0,     0,     0,   538,     0,   246,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   227,     0,
       0,     0,     0,   275,     0,   272,   277,   230,   193,   155,
     191,     0,   194,     0,     0,    95,    89,    92,    91,     0,
      87,   266,     0,     0,     0,   167,     0,   306,   310,     0,
       0,     0,   313,     0,     0,     0,   320,     0,   387,   386,
       0,     0,     0,   307,   483,     0,   472,     0,   506,   503,
       0,   507,   508,     0,   509,   502,     0,   477,   505,   504,
       0,     0,     0,   604,   605,   601,     0,     0,   609,   610,
     606,   615,   613,     0,     0,     0,   619,     0,   162,     0,
     159,   158,   169,     0,   620,   621,     0,     0,    22,     0,
      13,    17,    18,   289,   301,     0,   302,     0,   293,   294,
     295,   296,     0,   285,     0,     0,     0,   643,   656,     0,
     340,   342,     0,   675,     0,     0,     0,     0,     0,     0,
     631,   633,   634,   670,   671,   672,   674,   673,     0,     0,
     647,   646,     0,   650,   654,   668,   666,   665,   658,   662,
       0,     0,     0,     0,   542,   544,   543,   540,   537,   465,
     177,     0,   187,   186,   189,     0,    47,    98,   716,   697,
       0,   721,     0,   721,   710,   705,   130,   136,   138,   137,
       0,     0,     0,   133,     0,   107,    23,   524,     0,   582,
     583,   586,   579,   580,   245,     0,     0,   258,   250,     0,
     254,     0,   248,     0,     0,     0,   270,     0,     0,     0,
     229,   273,   276,     0,   156,     0,    94,     0,    88,   267,
       0,   534,     0,   309,   311,   316,     0,   314,     0,     0,
       0,     0,     0,   321,   388,   528,     0,   575,   573,   482,
       0,     0,   514,   482,     0,   478,    10,     0,     0,     0,
       0,     0,   618,     0,   163,   161,   627,     0,   622,     0,
     264,   305,   303,   304,   297,   298,   299,   291,     0,   286,
     284,   660,   651,   657,     0,     0,   730,   731,   741,   740,
     739,     0,     0,     0,     0,   732,   637,   738,     0,   635,
     639,     0,     0,   644,   648,     0,   669,   664,   667,   663,
       0,     0,   550,     0,   547,   597,   541,   195,     0,   717,
       0,     0,   715,   722,   723,   719,     0,   714,     0,   712,
       0,   706,   707,     0,     0,     0,   134,     0,   525,   247,
       0,   256,     0,     0,   252,     0,   255,   271,   279,   280,
     274,   228,     0,     0,    90,   269,   535,     0,   317,   315,
       0,     0,     0,     0,   529,     0,   482,     0,     0,   482,
     602,   603,   607,   608,   614,   616,     0,   164,     0,     0,
     623,   629,   300,   287,   655,   742,     0,     0,   734,     0,
     680,   679,   678,   677,   676,   641,     0,   733,     0,   594,
       0,     0,   188,   726,   725,   724,     0,   718,   711,   709,
       0,   701,     0,   139,   141,   143,     0,     0,     0,     0,
       0,   251,   249,     0,   257,     0,   324,    96,   312,     0,
     322,     0,   318,   492,   486,   481,     0,   482,   473,     0,
     165,     0,     0,   628,   736,   735,     0,     0,   595,   551,
       0,   720,   713,   708,     0,   145,   144,     0,     0,     0,
       0,   140,   253,     0,     0,     0,   500,   494,     0,   493,
     495,   501,   498,   488,     0,   487,   489,   499,   475,     0,
     474,   166,     0,   737,   649,   596,   142,   146,     0,     0,
       0,     0,   278,     0,   319,   485,   496,   497,   484,   490,
     491,   476,     0,     0,   147,     0,     0,     0,   323,     0,
     624,     0,     0,     0,     0,     0,   149,     0,     0,     0,
     148,     0,     0,   625,     0,     0,     0,     0,     0,   626,
       0,     0,     0,     0,   150
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1370, -1370,  -227,   991, -1370,   996,  1000, -1370,   995,  -224,
    -517,  -542, -1370,   546,  -249, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,  -933,
   -1370, -1370, -1370, -1370,   134,   340, -1370, -1370, -1370,   836,
   -1370,   100,  -890, -1370,  -326,  -357, -1370, -1370,  -615, -1370,
    -704, -1370, -1370,    -4, -1370, -1370, -1370, -1370, -1370,   832,
   -1370, -1370,   838,   837, -1370, -1370, -1370,   281,   821, -1369,
    -522,     4, -1370,  -563,   383, -1370, -1370, -1370, -1370,   285,
   -1370, -1370,   958, -1370, -1370, -1370, -1370,    99,  -698,  -680,
   -1370, -1370, -1370,    -3,   501, -1370, -1370,  -109,    92, -1370,
   -1370, -1370,    -8, -1370, -1370,   223,     0, -1370, -1370,    12,
   -1220, -1370,   737,    79, -1370, -1370,    87, -1370, -1370, -1370,
      88, -1370, -1370,   668,   671, -1370,  -537, -1370, -1370,  -618,
     194,  -617,   198,   199, -1370, -1370, -1370, -1370, -1370,   960,
   -1370, -1370, -1370, -1370,  -772,  -298, -1103, -1370,  -105, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370,   -40, -1207, -1370, -1370,
     397,    40, -1370,  -644, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370,   616, -1370,  -965, -1370,    73, -1370,   508,  -751, -1370,
   -1370, -1370, -1370, -1370,  -333,  -325, -1146,  -945, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,   433,  -731,
    -829,   161,  -819, -1370,   -14,  -797, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370,   857,   858,  -335,   351,   200, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,
   -1370, -1370,    56, -1370, -1370,    47, -1370, -1370, -1003, -1370,
   -1370, -1370,    16,    14,  -147,   250, -1370, -1370, -1370, -1370,
   -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370, -1370,    17,
   -1370, -1370, -1370,  -139,   246,   380, -1370, -1370, -1370, -1370,
   -1370,   188, -1370, -1370, -1274, -1370, -1370, -1370,  -620, -1370,
     -19, -1370,  -158, -1370, -1370, -1370, -1370, -1221, -1370,    29,
   -1370,  -369,  -359,    23,   -72, -1370
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   241,   794,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   875,   876,   877,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,  1165,
     731,   265,   266,   881,   882,   883,   267,   268,   417,   418,
     269,  1116,   914,   270,  1543,  1544,   271,   272,   438,   273,
     557,   784,  1009,  1228,   274,   275,   276,   277,   419,   420,
     857,   278,   421,   422,   423,   424,   722,   723,  1204,  1078,
     279,   280,   581,   281,   282,   283,   590,   436,   943,   944,
     284,   591,   285,   593,   286,   287,   715,   716,  1153,   444,
     288,   445,   788,   789,   446,   719,  1154,  1155,  1156,   594,
     595,  1030,  1031,  1409,   596,  1027,  1028,  1248,  1249,  1250,
    1251,   289,   744,   745,   290,  1181,  1182,  1183,   291,  1185,
    1186,   292,   293,   294,   295,   823,   296,  1260,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     614,   615,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     641,   642,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   851,   336,   337,   338,  1206,   763,   764,   765,  1565,
    1604,  1605,  1598,  1599,  1606,  1600,  1207,  1208,   339,   340,
    1209,   341,   342,   343,   344,   345,   346,   347,  1062,   938,
    1052,  1297,  1053,  1443,  1054,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   751,  1130,   358,   359,   360,
     361,  1056,  1057,  1058,  1059,   362,   363,   364,   365,   366,
     367,   781,   782,   368,  1234,  1235,  1397,   369,  1038,  1270,
    1271,  1039,  1040,  1041,  1042,  1043,  1280,  1433,  1434,  1044,
    1283,  1045,  1414,  1046,  1047,  1288,  1289,  1439,  1437,  1272,
    1273,  1274,  1275,  1523,   684,   902,   903,   904,   905,   906,
     907,  1106,  1460,  1461,  1107,  1459,  1539,   908,  1313,  1456,
    1452,  1453,  1454,   909,   910,  1276,  1284,  1424,  1277,  1420,
    1261,   370,   534,   371,   372,   373
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int xquery_parser::yytable_ninf_ = -744;
  const short int
  xquery_parser::yytable_[] =
  {
       511,   830,   958,   831,   832,   833,   834,   379,   381,   383,
     858,  1061,   987,   636,   511,   971,   655,  1320,   810,   936,
     574,   576,   571,  1170,  1205,   542,  1396,  1124,  1510,  1405,
    1406,  1256,   509,   803,   805,  1142,   511,   937,   856,   932,
     677,  1462,  1055,  1055,  1546,   940,   544,   861,   511,   572,
     511,   798,   801,   804,   806,  1036,   797,   800,   572,  1083,
    1385,  1435,   819,   767,   820,   821,   699,   822,  1421,   824,
     912,   728,   732,   572,   703,  1172,  1123,   825,   826,   572,
    1109,  1055,   572,   572,   572,  1005,  1110,   703,   891,   740,
     579,   892,   617,   704,   856,   510,   384,   934,   988,   933,
    1563,   934,   442,  1111,  1136,  1112,   704,   466,  1368,   524,
     618,   529,   466,  -743,  1113,  1117,   579,  1159,   389,   579,
      78,   385,   386,  1492,   387,   388,   968,  1196,   440,  1516,
     664,   530,   720,   893,    89,   392,  1055,   393,   384,  1013,
    1114,  1097,   656,   535,   391,   538,   394,  1143,  1416,  1055,
    1547,   935,  1098,  1086,  1450,   657,   658,   441,  1520,   103,
     389,   425,   665,  1033,   989,  1521,  1034,  1532,  1139,   659,
     390,  1229,  1198,  1199,  1596,  1522,    78,   392,  1198,   393,
     926,  1596,   696,  1037,  1512,  1198,  1417,   122,   394,  1564,
      89,  1493,   395,  1197,  1369,   968,  1343,   729,  1239,   580,
    1014,   721,  1023,  1520,   941,  1517,   443,   969,  1147,   637,
    1521,   913,  1006,   856,  1158,   103,   705,   913,  1451,  1033,
    1522,  1467,  1034,   396,   397,  1021,  1316,  1422,  1423,   768,
     545,  1292,  1205,  1548,  1195,  1385,  1358,   573,  1540,   727,
    1144,  1205,   942,   122,   730,   399,   575,   511,  1079,  1080,
     511,   803,   805,  1055,  1230,  1413,  1140,   443,  1145,   994,
     927,   791,  1036,  1036,  1640,  1200,  1115,   793,  1583,  1035,
    1018,  1020,  1238,   443,   797,   800,   984,   443,  1173,   643,
    1653,   400,   645,   624,   894,  1201,  1032,  1202,  1659,   852,
    1149,  1201,   625,  1202,   443,    78,  1150,   895,  1201,   896,
    1202,  1597,  1573,   928,   402,   635,   888,  1232,  1626,    89,
     897,   898,   899,   401,   900,   724,   901,   662,   511,   108,
     933,   724,   443,   511,   947,  1585,  1117,   511,   724,   122,
     457,  1072,  1354,   511,   103,   992,   120,   980,   429,   982,
     511,   403,   510,   792,   620,   510,   404,  1067,  1073,   796,
     799,  1067,  1262,   511,  1077,  1371,  1203,  1508,  1070,   511,
    1545,  1530,   955,   511,  1055,  1536,  1617,   957,   951,  1632,
     511,   954,  1648,   621,   146,  1303,   511,   511,   511,   511,
     511,   995,   996,   929,   933,   511,   622,  1055,   458,   437,
    1037,  1037,   998,   511,   993,  1325,   997,  1262,   933,   405,
     406,   407,   408,   409,   948,   410,   411,   412,   413,   414,
    1509,  1198,  1199,   663,   415,   416,  1205,   981,   669,   983,
     623,   428,   535,  1103,  1263,  1198,  1300,  1068,   685,   432,
     700,  1069,   702,  1466,   708,   687,   970,  1336,  1071,  1104,
    1310,  1531,  1602,   726,   934,  1537,  1198,  1545,   535,  1633,
    1146,   737,  1649,   511,   711,   459,   460,   747,   717,   749,
     750,  1442,   753,  1602,  1344,   733,   933,   672,   756,  1263,
     673,   535,   741,   742,   743,   746,   803,   805,   803,   582,
     752,  1545,  1105,   511,   672,   583,  1036,   673,   759,   463,
     584,   511,  1180,  1055,  1335,  1036,  1240,  1241,  1242,  1312,
    1099,  1258,   674,   451,  1200,  1366,  1036,  1264,  1265,   585,
    1266,  1100,  1244,  1506,   999,  1000,  1087,  1088,  1198,  1199,
     464,  1091,  1245,   465,  1201,   122,  1202,  1268,   675,  1001,
     934,   433,  1246,   845,   846,   766,   434,  1121,  1201,  1269,
    1202,  1310,  1650,  1247,  1651,   675,  1122,   770,   746,  1603,
    1557,  1127,  1264,  1265,   724,  1266,  1294,  1311,   108,  1201,
    1664,  1202,  1267,  1198,  1199,  1149,   787,  1015,   724,  1019,
    1629,  1150,  1268,  1149,   568,   120,   511,  1245,   783,  1150,
    1472,   435,   452,  1166,  1269,   617,   790,  1166,  1295,   724,
     676,  1129,   569,  1132,   863,  1380,   864,  1151,  1247,   511,
    1312,   626,   547,   618,   548,  1296,   586,   676,   934,   587,
     878,  1200,  1016,   146,  1037,   627,   934,   617,  1601,  1607,
     511,   511,   511,  1037,   588,   619,  1081,  1184,  1495,  1418,
     569,  1201,  1498,  1202,  1037,   618,  1419,  1152,  1081,   844,
    1372,  1285,  1286,  1473,   847,  1191,   511,  1192,   511,   589,
    1074,  1428,   879,   400,  1601,   511,  1200,   880,   511,  1036,
    1607,   724,   511,  1507,  1287,   108,   461,  1075,   617,   933,
     439,   535,   660,  1076,   449,  1302,  1201,  1304,  1202,  1103,
    1245,   848,   120,   462,   848,   401,   618,   848,   661,  1077,
     511,   556,   553,  1305,   884,  1104,   803,   554,   550,  1578,
     551,  1579,  1384,  1092,  1093,  1094,   724,   577,  1576,  1095,
     108,   450,   578,   403,   879,   916,   917,   918,   644,   880,
     146,   426,   430,   647,   427,   431,   447,   120,   949,   448,
    1594,  1055,   453,  1055,  1211,   454,  1212,   455,   636,   511,
     456,   939,  1448,   945,   640,  1566,   646,  1497,  1569,   512,
     535,  1615,   513,   535,   678,   679,   680,   959,   977,   978,
     514,  1216,  1055,  1217,   525,   146,   526,   511,   511,   511,
     511,   693,   406,   407,   408,   409,   527,   410,   411,   694,
     413,   414,   531,  1055,   532,   985,   415,  1037,  1010,   638,
     639,   681,   682,   690,   691,  1356,  1089,  1090,  1515,   539,
    1166,  1402,  1403,   540,  1518,  1519,   511,  1118,  1119,   541,
     599,   828,   829,   543,  1586,   712,  1609,   546,   600,   601,
     511,   602,   835,   836,   552,   837,   838,  1063,  1063,   603,
    1533,  1534,   549,   604,  1024,   605,   555,   556,   558,   561,
     606,   560,   559,   562,   563,   565,   597,   511,   598,   628,
     629,   630,   616,   631,   511,   640,   511,   607,   648,   649,
     650,   511,  1060,  1060,  1060,  1060,   651,   654,   466,   652,
     653,   666,   389,   668,   511,   670,  1401,   671,   683,   686,
     608,   609,   610,   611,   612,   613,   865,   866,   867,   868,
     869,   870,   871,   872,   873,   874,   692,   701,  1574,  1575,
     713,  1060,   688,   689,   714,   718,   724,   734,   511,   735,
     511,   736,   748,   754,   755,  1096,   761,   762,   427,   431,
     448,   454,   465,   769,   772,   771,   775,   780,   795,   811,
     773,   774,   807,   776,   777,   778,   779,   812,   813,   827,
     814,   840,  1126,   785,   786,   839,   841,   842,   853,  1131,
     859,  1131,   860,   862,   885,   886,  1060,   511,  1613,   889,
     890,   808,   809,   911,   915,   919,   920,   921,   922,  1060,
     931,   815,   816,   923,   946,   924,   925,   930,   511,  1187,
     953,   952,   956,   950,   962,   972,   975,  1002,  1484,   963,
     964,   967,  1003,   965,   966,   973,   974,   976,   979,   990,
     991,  1004,  1007,   752,  1011,   752,  1012,  1017,  1025,  1029,
    1065,   880,  1066,  1082,   933,  1101,  1102,  1120,  1125,  1128,
    1134,  1135,  1137,  1141,  1161,  1148,   720,  1163,  1167,   850,
    1164,  1168,  1162,   850,  1169,  1174,  1176,  1255,  1180,  1513,
    1179,  1184,  1188,  1189,  1194,  1210,  1224,   674,  1190,  1227,
    1236,  1237,  1253,  1252,  1231,  1233,  1254,  1259,  1298,  1290,
     856,   384,   511,  1291,  1282,   511,  1293,  1308,  1309,  1314,
    1278,   385,   386,  1060,   387,   388,  1318,   913,  1279,  1319,
     511,  1301,  1322,   389,  1331,  1341,  1339,  1324,  1329,   511,
    1326,  1345,  1330,   390,   391,  1347,  1332,  1348,  1333,  1349,
     392,  1353,   393,  1357,   511,  1360,  1321,  1374,  1377,  1378,
    1379,   394,   511,  1382,  1166,   395,  1386,  1245,   960,  1387,
    1388,  1389,  1390,  1412,  1408,  1415,  1438,  1411,  1393,  1431,
    1425,   511,  1328,  1458,  1444,  1449,  1432,  1445,  1446,  1447,
    1455,  1436,  1103,  1463,  1468,  1470,   396,   397,   398,  1391,
    1475,  1482,   511,  1483,  1486,   511,  1528,   717,  1487,  1526,
    1337,   511,  1491,  1538,  1494,   511,  1527,  1511,  1514,  1465,
    1542,  1550,  1529,  1541,  1553,  1351,  1555,  1559,  1362,  1571,
    1572,  1580,  1581,  1584,  1060,  1568,  1588,  1593,  1589,  1608,
    1022,  1595,  1582,  1610,  1376,   399,  1026,  1614,  1620,   746,
    1623,  1621,  1549,  1625,   400,  1628,  1637,  1060,  1631,  1639,
    1077,  1652,  1660,  1641,  1654,  1657,  1661,  1307,   511,  1084,
     887,  1618,  1635,  1323,  1591,  1395,  1383,  1616,  1160,  1157,
     667,   564,  1656,  1334,  1400,  1642,   401,   961,  1645,   566,
    1647,   570,  1480,   567,   592,  1352,  1410,   783,  1243,   511,
    1394,   697,  1407,   695,   402,  1363,   510,   698,  1663,   725,
     790,  1404,   760,  1085,   403,   817,   855,   634,  1367,   818,
    1381,   986,  1630,  1373,  1627,  1064,   511,   511,  1317,  1133,
    1392,  1398,  1306,  1426,  1525,  1257,   706,   707,  1429,  1524,
    1281,  1108,  1430,  1315,  1457,  1535,   404,  1427,   511,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   511,     0,
       0,     0,   511,  1060,     0,     0,     0,     0,  1138,     0,
       0,     0,   405,   406,   407,   408,   409,     0,   410,   411,
     412,   413,   414,     0,     0,     0,     0,   415,   416,     0,
    1171,     0,     0,     0,  1464,     0,     0,     0,     0,     0,
    1175,     0,  1177,  1178,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1193,     0,     0,
       0,  1478,  1479,     0,     0,     0,     0,     0,  1213,  1214,
    1215,     0,  1218,  1219,  1220,  1221,  1222,  1223,     0,  1225,
    1226,     0,     0,  1490,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1496,     0,     0,     0,  1499,  1026,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     511,     0,     0,     0,     0,   511,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   511,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1299,     0,     0,     0,     0,     0,   511,     0,   511,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   511,     0,     0,   511,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   511,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     511,     0,     0,     0,     0,     0,     0,     0,   511,     0,
       0,     0,     0,     0,     0,  1561,   511,     0,     0,     0,
    1567,   511,  1338,     0,  1340,     0,  1342,     0,     0,  1346,
    1577,     0,   510,     0,  1350,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1355,     0,   511,     0,
       0,  1060,     0,  1060,     0,  1359,     0,     0,     0,     0,
       0,     0,  1364,  1365,     0,   511,     0,   511,     0,  1587,
       0,     0,  1590,     0,     0,     0,     0,     0,     0,     0,
     511,     0,  1060,     0,   511,     0,     0,     0,     0,   511,
       0,     0,     0,     0,     0,  1612,     0,     0,     0,     0,
       0,     0,     0,  1060,     0,     0,     0,     0,     0,     0,
       0,  1619,     0,     0,     0,     0,  1622,     0,     0,  1399,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1026,     0,     0,     0,     0,
       0,     0,     0,  1636,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1643,     0,  1644,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1655,     0,     0,     0,  1658,
       0,     0,     0,     0,  1662,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1469,     0,
       0,     0,  1471,     0,     0,     0,  1474,     0,  1476,     0,
    1477,     0,     0,     0,     0,     0,  1481,     0,     0,     0,
       0,     0,     0,  1485,     0,     0,     0,     0,     0,     0,
       0,  1488,  1489,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1500,  1501,  1502,  1503,  1504,     0,  1505,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1551,     0,  1552,     0,     0,  1554,     0,
       0,     0,     0,     0,     0,  1556,     0,     0,     0,     0,
    1558,     0,     0,     0,  1560,     0,  1562,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1570,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1592,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1611,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1624,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1634,     0,     1,     0,     0,  1638,     0,     0,     0,
       0,     2,     3,     4,     5,     6,     7,     0,     0,     8,
       0,     0,     0,     9,    10,  1646,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,     0,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,     0,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,    71,
      72,    73,    74,    75,     0,     0,    76,    77,     0,     0,
       0,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,     0,     0,     0,    89,     0,    90,    91,    92,
      93,     0,    94,     0,     0,     0,    95,    96,    97,    98,
      99,     0,     0,     0,     0,     0,     0,   100,   101,   102,
     103,   104,   105,   106,     0,     0,     0,   107,   108,   109,
     110,   111,     0,     0,     0,     0,   112,   113,   114,   115,
     116,   117,   118,   119,     0,   120,     0,   121,   122,     0,
       0,   123,   124,   125,     0,     0,     0,   126,     0,   127,
     128,     0,   129,   130,   131,     0,   132,     0,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,     0,
       0,   144,   145,   146,     0,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,     0,
     191,   192,   193,     0,   194,   195,   196,   197,   198,   199,
       0,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,     1,     0,     0,     0,     0,     0,     0,     0,
       2,     3,     4,     5,     6,     7,     0,     0,     8,     0,
       0,     0,   374,   375,     0,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
     376,    27,    28,    29,    30,     0,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       0,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,     0,    68,    69,    70,    71,    72,
      73,    74,    75,     0,     0,    76,    77,     0,     0,     0,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,     0,     0,     0,    89,     0,    90,    91,    92,    93,
       0,    94,     0,     0,     0,    95,    96,    97,    98,    99,
       0,     0,     0,     0,     0,     0,   100,   101,   102,   103,
     104,   105,   106,     0,     0,     0,   107,   108,   109,   110,
     111,     0,     0,     0,     0,   112,   113,   114,   115,   116,
     117,   118,   119,     0,   120,     0,   121,   122,     0,     0,
     123,   124,   125,     0,   377,     0,   126,     0,   127,   128,
       0,   129,   130,   131,     0,   132,     0,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,     0,     0,
     144,   145,   146,     0,   378,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,     0,   191,
     192,   193,     0,   194,   195,   196,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
       1,     0,     0,     0,     0,     0,     0,     0,     2,     3,
       4,     5,     6,     7,     0,     0,     8,     0,     0,     0,
     374,   375,     0,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,   376,    27,
      28,    29,    30,     0,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,     0,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,     0,    68,    69,    70,    71,    72,    73,    74,
      75,     0,     0,    76,    77,     0,     0,     0,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,     0,
       0,     0,    89,     0,    90,    91,    92,    93,     0,    94,
       0,     0,     0,    95,    96,    97,    98,    99,     0,     0,
       0,     0,     0,     0,   100,   101,   102,   103,   104,   105,
     106,     0,     0,     0,   107,   108,   109,   110,   111,     0,
       0,     0,     0,   112,   113,   114,   115,   116,   117,   118,
     119,     0,   120,     0,   121,   122,     0,     0,   123,   124,
     125,     0,   380,     0,   126,     0,   127,   128,     0,   129,
     130,   131,     0,   132,     0,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,     0,     0,   144,   145,
     146,     0,   378,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,     0,   191,   192,   193,
       0,   194,   195,   196,   197,   198,   199,     0,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,     1,     0,
       0,     0,     0,     0,     0,     0,     2,     3,     4,     5,
       6,     7,     0,     0,     8,     0,     0,     0,   374,   375,
       0,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,   376,    27,    28,    29,
      30,     0,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
       0,    68,    69,    70,    71,    72,    73,    74,    75,     0,
       0,    76,    77,     0,     0,     0,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,     0,     0,     0,
      89,     0,    90,    91,    92,    93,     0,    94,     0,     0,
       0,    95,    96,    97,    98,    99,     0,     0,     0,     0,
       0,     0,   100,   101,   102,   103,   104,   105,   106,     0,
       0,     0,   107,   108,   109,   110,   111,     0,     0,     0,
       0,   112,   113,   114,   115,   116,   117,   118,   119,     0,
     120,     0,   121,   122,     0,     0,   123,   124,   125,     0,
     382,     0,   126,     0,   127,   128,     0,   129,   130,   131,
       0,   132,     0,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,     0,     0,   144,   145,   146,     0,
     378,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,     0,   191,   192,   193,     0,   194,
     195,   196,   197,   198,   199,     0,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,     1,     0,     0,     0,
       0,     0,     0,     0,     2,     3,     4,     5,     6,     7,
       0,     0,     8,     0,     0,     0,   374,   375,     0,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,   376,    27,    28,    29,    30,     0,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,     0,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     0,    68,
      69,    70,    71,    72,    73,    74,    75,     0,     0,    76,
      77,     0,     0,     0,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,     0,     0,     0,    89,     0,
      90,    91,    92,    93,     0,    94,     0,     0,     0,    95,
      96,    97,    98,    99,     0,     0,     0,     0,     0,     0,
     100,   101,   102,   103,   104,   105,   106,     0,     0,     0,
     107,   108,   109,   110,   111,     0,     0,     0,     0,   112,
     113,   114,   115,   116,   117,   118,   119,     0,   120,     0,
     121,   122,     0,     0,   123,   124,   125,     0,     0,     0,
     126,   528,   127,   128,     0,   129,   130,   131,     0,   132,
       0,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,     0,     0,   144,   145,   146,     0,   378,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,     0,   191,   192,   193,     0,   194,   195,   196,
     197,   198,   199,     0,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,     1,     0,     0,     0,     0,     0,
       0,     0,     2,     3,     4,     5,     6,     7,     0,     0,
       8,     0,     0,     0,   374,   375,     0,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,   376,    27,    28,    29,    30,     0,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,     0,    68,    69,    70,
      71,    72,    73,    74,    75,     0,     0,    76,    77,     0,
       0,     0,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,     0,     0,     0,    89,     0,    90,    91,
      92,    93,     0,    94,     0,     0,     0,    95,    96,    97,
      98,    99,     0,     0,     0,     0,     0,     0,   100,   101,
     102,   103,   104,   105,   106,     0,     0,     0,   107,   108,
     109,   110,   111,     0,     0,     0,     0,   112,   113,   114,
     115,   116,   117,   118,   119,     0,   120,     0,   121,   122,
       0,     0,   123,   124,   125,     0,   843,     0,   126,     0,
     127,   128,     0,   129,   130,   131,     0,   132,     0,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
       0,     0,   144,   145,   146,     0,   378,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
       0,   191,   192,   193,     0,   194,   195,   196,   197,   198,
     199,     0,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,     1,     0,     0,     0,     0,     0,     0,     0,
       2,     3,     4,     5,     6,     7,     0,     0,     8,     0,
       0,     0,   374,   375,     0,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
     376,    27,    28,    29,    30,     0,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       0,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,     0,    68,    69,    70,    71,    72,
      73,    74,    75,     0,     0,    76,    77,     0,     0,     0,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,     0,     0,     0,    89,     0,    90,    91,    92,    93,
       0,    94,     0,     0,     0,    95,    96,    97,    98,    99,
       0,     0,     0,     0,     0,     0,   100,   101,   102,   103,
     104,   105,   106,     0,     0,     0,   107,   108,   109,   110,
     111,     0,     0,     0,     0,   112,   113,   114,   115,   116,
     117,   118,   119,     0,   120,     0,   121,   122,     0,     0,
     123,   124,   125,     0,     0,     0,   126,   849,   127,   128,
       0,   129,   130,   131,     0,   132,     0,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,     0,     0,
     144,   145,   146,     0,   378,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,     0,   191,
     192,   193,     0,   194,   195,   196,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
       1,     0,     0,     0,     0,     0,     0,     0,     2,     3,
       4,     5,     6,     7,     0,     0,     8,     0,     0,     0,
     374,   375,     0,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,   376,    27,
      28,    29,    30,     0,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,     0,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,     0,    68,    69,    70,    71,    72,    73,    74,
      75,     0,     0,    76,    77,     0,     0,     0,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,     0,
       0,     0,    89,     0,    90,    91,    92,    93,     0,    94,
       0,     0,     0,    95,    96,    97,    98,    99,     0,     0,
       0,     0,     0,     0,   100,   101,   102,   103,   104,   105,
     106,     0,     0,     0,   107,   108,   109,   110,   111,     0,
       0,     0,     0,   112,   113,   114,   115,   116,   117,   118,
     119,     0,   120,     0,   121,   122,     0,     0,   123,   124,
     125,     0,     0,     0,   126,   854,   127,   128,     0,   129,
     130,   131,     0,   132,     0,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,     0,     0,   144,   145,
     146,     0,   378,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,     0,   191,   192,   193,
       0,   194,   195,   196,   197,   198,   199,     0,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,     1,     0,
       0,     0,     0,     0,     0,     0,     2,     3,     4,     5,
       6,     7,     0,     0,     8,     0,     0,     0,   374,   375,
       0,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,   376,    27,    28,    29,
      30,     0,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
       0,    68,    69,    70,    71,    72,    73,    74,    75,     0,
       0,    76,    77,     0,     0,     0,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,     0,     0,     0,
      89,     0,    90,    91,    92,    93,     0,    94,     0,     0,
       0,    95,    96,    97,    98,    99,     0,     0,     0,     0,
       0,     0,   100,   101,   102,   103,   104,   105,   106,     0,
       0,     0,   107,   108,   109,   110,   111,     0,     0,     0,
       0,   112,   113,   114,   115,   116,   117,   118,   119,     0,
     120,     0,   121,   122,     0,     0,   123,   124,   125,     0,
    1327,     0,   126,     0,   127,   128,     0,   129,   130,   131,
       0,   132,     0,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,     0,     0,   144,   145,   146,     0,
     378,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,     0,   191,   192,   193,     0,   194,
     195,   196,   197,   198,   199,     0,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,     1,     0,     0,     0,
       0,     0,     0,     0,     2,     3,     4,     5,     6,     7,
       0,     0,     8,     0,     0,     0,   374,   375,     0,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,   376,    27,    28,    29,    30,     0,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,     0,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     0,    68,
      69,    70,    71,    72,    73,    74,    75,     0,     0,    76,
      77,     0,     0,     0,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,     0,     0,     0,    89,     0,
      90,    91,    92,    93,     0,    94,     0,     0,     0,    95,
      96,    97,    98,    99,     0,     0,     0,     0,     0,     0,
     100,   101,   102,   103,   104,   105,   106,     0,     0,     0,
     107,   108,   109,   110,   111,     0,     0,     0,     0,   112,
     113,   114,   115,   116,   117,   118,   119,     0,   120,     0,
     121,   122,     0,     0,   123,   124,   125,     0,  1361,     0,
     126,     0,   127,   128,     0,   129,   130,   131,     0,   132,
       0,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,     0,     0,   144,   145,   146,     0,   378,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,     0,   191,   192,   193,     0,   194,   195,   196,
     197,   198,   199,     0,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,     1,     0,     0,     0,     0,     0,
       0,     0,     2,     3,     4,     5,     6,     7,     0,     0,
       8,     0,     0,     0,   374,   375,     0,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,   376,    27,    28,    29,    30,     0,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,     0,    68,    69,    70,
      71,    72,    73,    74,    75,     0,     0,    76,    77,     0,
       0,     0,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,     0,     0,     0,    89,     0,    90,    91,
      92,    93,     0,    94,     0,     0,     0,    95,    96,    97,
      98,    99,     0,     0,     0,     0,     0,     0,   100,   101,
     102,   103,   104,   105,   106,     0,     0,     0,   107,   108,
     109,   110,   111,     0,     0,     0,     0,   112,   113,   114,
     115,   116,   117,   118,   119,     0,   120,     0,   121,   122,
       0,     0,   123,   124,   125,     0,  1375,     0,   126,     0,
     127,   128,     0,   129,   130,   131,     0,   132,     0,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
       0,     0,   144,   145,   146,     0,   378,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
       0,   191,   192,   193,     0,   194,   195,   196,   197,   198,
     199,     0,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,     1,     0,     0,     0,     0,     0,     0,     0,
       2,     3,     4,     5,     6,     7,     0,     0,     8,     0,
       0,     0,     9,    10,     0,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,     0,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       0,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,     0,    68,    69,    70,    71,    72,
      73,    74,    75,     0,     0,    76,    77,     0,     0,     0,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,     0,     0,     0,    89,     0,    90,    91,    92,    93,
       0,    94,     0,     0,     0,    95,    96,    97,    98,    99,
       0,     0,     0,     0,     0,     0,   100,   101,   102,   103,
     104,   105,   106,     0,     0,     0,   107,   108,   109,   110,
     111,     0,     0,     0,     0,   112,   113,   114,   115,   116,
     117,   118,   119,     0,   120,     0,   121,   122,     0,     0,
     123,   124,   125,     0,     0,     0,   126,     0,   127,   128,
       0,   129,   130,   131,     0,   132,     0,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,     0,     0,
     144,   145,   146,     0,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,     0,   191,
     192,   193,     0,   194,   195,   196,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
       1,     0,     0,     0,     0,     0,     0,     0,     2,     3,
       4,     5,     6,     7,     0,     0,     8,     0,     0,     0,
       9,    10,     0,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,     0,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,     0,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,     0,    68,    69,    70,    71,    72,    73,    74,
      75,     0,     0,    76,    77,     0,     0,     0,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,     0,
       0,     0,    89,     0,    90,    91,    92,    93,     0,    94,
       0,     0,     0,    95,    96,    97,    98,    99,     0,     0,
       0,     0,     0,     0,   100,   101,   102,   103,   104,   105,
     106,     0,     0,     0,   107,   108,   109,   110,   111,     0,
       0,     0,     0,   112,   113,   114,   115,   116,   117,   118,
     119,     0,   120,     0,   121,   122,     0,     0,   123,   124,
     125,     0,     0,     0,   126,     0,   127,   128,     0,   129,
     130,   131,     0,   132,     0,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,     0,     0,   144,   145,
     146,     0,   378,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,     0,   191,   192,   193,
       0,   194,   195,   196,   197,   198,   199,     0,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,     1,     0,
       0,     0,     0,     0,     0,     0,     2,     3,     4,     5,
       6,     7,     0,     0,     8,     0,     0,     0,   374,   375,
       0,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,   470,   471,    24,   473,   376,    27,   474,    29,
      30,     0,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,   476,    42,    43,   477,     0,    45,    46,    47,
     479,   480,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
       0,    68,    69,    70,    71,    72,    73,    74,    75,     0,
       0,    76,    77,     0,     0,     0,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,     0,     0,     0,
      89,     0,    90,    91,    92,    93,     0,    94,     0,     0,
       0,   488,    96,    97,    98,    99,     0,     0,     0,     0,
       0,     0,   100,   101,   102,   103,   104,   105,   106,     0,
       0,     0,   107,   108,   632,   110,   111,     0,     0,     0,
       0,   112,   113,   114,   115,   116,   117,   118,   119,     0,
     120,     0,   633,   122,     0,     0,   123,   124,   125,     0,
       0,     0,   126,     0,   127,   128,     0,   129,   130,   131,
       0,   132,     0,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,     0,     0,   144,   145,   146,     0,
     378,   148,   149,   150,   151,   152,   153,   154,   155,   497,
     157,   498,   159,   499,   500,   162,   163,   164,   165,   166,
     167,   501,   169,   502,   503,   504,   505,   174,   175,   506,
     507,   178,   508,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,     0,   191,   192,   193,     0,   194,
     195,   196,   197,   198,   199,     0,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,     1,     0,     0,     0,
       0,     0,     0,     0,     2,     3,     4,     5,     6,     7,
       0,     0,     8,     0,     0,     0,   374,   375,     0,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,   376,    27,    28,    29,    30,     0,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,     0,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     0,    68,
      69,    70,    71,    72,    73,    74,    75,     0,     0,    76,
      77,     0,     0,     0,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,     0,     0,     0,    89,     0,
      90,    91,    92,    93,     0,    94,     0,     0,     0,    95,
      96,    97,    98,    99,     0,     0,     0,     0,     0,     0,
     100,   101,   102,   103,   104,   105,   106,     0,     0,     0,
     107,   108,   109,   110,   111,     0,     0,     0,     0,   112,
     113,   114,   115,   116,   117,   118,   119,     0,   120,     0,
     121,   122,     0,     0,   123,   124,   125,     0,     0,     0,
     126,     0,   127,   128,     0,   129,   130,   131,     0,   132,
       0,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,     0,     0,   144,   145,   146,     0,   378,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,     0,   191,   192,   193,     0,   194,   195,   196,
     197,   198,   199,     0,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,     1,     0,     0,     0,     0,     0,
       0,     0,     2,     3,     4,     5,     6,     7,     0,     0,
       8,     0,     0,     0,     9,   375,     0,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,     0,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,     0,    68,    69,    70,
      71,    72,    73,    74,    75,     0,     0,    76,    77,     0,
       0,     0,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,     0,     0,     0,    89,     0,    90,    91,
      92,    93,     0,    94,     0,     0,     0,    95,    96,    97,
      98,    99,     0,     0,     0,     0,     0,     0,   100,   101,
     102,   103,   104,   105,   106,     0,     0,     0,   107,   108,
     109,   110,   111,     0,     0,     0,     0,   112,   113,   114,
     115,   116,   117,   118,   119,     0,   120,     0,   121,   122,
       0,     0,   123,   124,   125,     0,     0,     0,   126,     0,
     127,   128,     0,   129,   130,   131,     0,   132,     0,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
       0,     0,   144,   145,   146,     0,   378,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
       0,   191,   192,   193,     0,   194,   195,   196,   197,   198,
     199,     0,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,     1,     0,     0,     0,     0,     0,     0,     0,
       2,     3,     4,     5,     6,     7,     0,     0,     8,     0,
       0,     0,   802,   375,     0,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
     376,    27,    28,    29,    30,     0,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       0,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,     0,    68,    69,    70,    71,    72,
      73,    74,    75,     0,     0,    76,    77,     0,     0,     0,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,     0,     0,     0,    89,     0,    90,    91,    92,    93,
       0,    94,     0,     0,     0,    95,    96,    97,    98,    99,
       0,     0,     0,     0,     0,     0,   100,   101,   102,   103,
     104,   105,   106,     0,     0,     0,   107,   108,   109,   110,
     111,     0,     0,     0,     0,   112,   113,   114,   115,   116,
     117,   118,   119,     0,   120,     0,   121,   122,     0,     0,
     123,   124,   125,     0,     0,     0,   126,     0,   127,   128,
       0,   129,   130,   131,     0,   132,     0,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,     0,     0,
     144,   145,   146,     0,   378,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,     0,   191,
     192,   193,     0,   194,   195,   196,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
       1,     0,     0,     0,     0,     0,     0,     0,     2,     3,
       4,     5,     6,     7,     0,     0,     8,     0,     0,     0,
     374,   375,     0,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,   470,   471,    24,   473,   376,    27,
     474,    29,    30,     0,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,   476,    42,    43,   477,     0,    45,
      46,    47,   479,   480,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,     0,    68,    69,    70,    71,    72,    73,    74,
      75,     0,     0,    76,    77,     0,     0,     0,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,     0,
       0,     0,    89,     0,    90,    91,    92,    93,     0,    94,
       0,     0,     0,   488,    96,    97,    98,    99,     0,     0,
       0,     0,     0,     0,   100,   101,   102,   103,   104,   105,
     106,     0,     0,     0,   107,   108,   109,   110,   111,     0,
       0,     0,     0,   112,   113,   114,   115,   116,   117,   118,
     119,     0,   120,     0,   121,   122,     0,     0,   123,   124,
     125,     0,     0,     0,   126,     0,   127,   128,     0,   129,
     130,   131,     0,   132,     0,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,     0,     0,   144,   145,
     146,     0,   378,   148,   149,   150,   151,   152,   153,   154,
     155,   497,   157,   498,   159,   499,   500,   162,   163,   164,
     165,   166,   167,   501,   169,   502,   503,   504,   505,   174,
     175,   506,   507,   178,   508,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,     0,   191,   192,   193,
       0,   194,   195,   196,   197,   198,   199,     0,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,     1,     0,
       0,     0,     0,     0,     0,     0,     2,     3,     4,     5,
       6,     7,     0,     0,     8,     0,     0,     0,  1008,   375,
       0,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,   376,    27,    28,    29,
      30,     0,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
       0,    68,    69,    70,    71,    72,    73,    74,    75,     0,
       0,    76,    77,     0,     0,     0,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,     0,     0,     0,
      89,     0,    90,    91,    92,    93,     0,    94,     0,     0,
       0,    95,    96,    97,    98,    99,     0,     0,     0,     0,
       0,     0,   100,   101,   102,   103,   104,   105,   106,     0,
       0,     0,   107,   108,   109,   110,   111,     0,     0,     0,
       0,   112,   113,   114,   115,   116,   117,   118,   119,     0,
     120,     0,   121,   122,     0,     0,   123,   124,   125,     0,
       0,     0,   126,     0,   127,   128,     0,   129,   130,   131,
       0,   132,     0,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,     0,     0,   144,   145,   146,     0,
     378,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,     0,   191,   192,   193,     0,   194,
     195,   196,   197,   198,   199,     0,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,     1,     0,     0,     0,
       0,     0,     0,     0,     2,     3,     4,     5,     6,     7,
       0,     0,     8,     0,     0,     0,   374,   375,     0,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
     470,   471,    24,   473,   376,    27,   474,    29,    30,     0,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
     476,    42,    43,   477,     0,    45,    46,    47,   479,   480,
      50,   481,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     0,    68,
      69,    70,    71,    72,    73,    74,    75,     0,     0,    76,
      77,     0,     0,     0,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,     0,     0,     0,    89,     0,
      90,    91,    92,    93,     0,    94,     0,     0,     0,   488,
      96,    97,    98,    99,     0,     0,     0,     0,     0,     0,
     100,   101,   102,   103,   104,   105,   106,     0,     0,     0,
     107,   108,     0,   110,   111,     0,     0,     0,     0,   112,
     113,   114,   115,   116,   117,   118,   119,     0,   120,     0,
       0,     0,     0,     0,   123,   124,   125,     0,     0,     0,
     126,     0,   127,   128,     0,   129,   130,   131,     0,   132,
       0,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,     0,     0,   144,   145,   146,     0,   378,   148,
     149,   150,   151,   152,   153,   154,   155,   497,   157,   498,
     159,   499,   500,   162,   163,   164,   165,   166,   167,   501,
     169,   502,   503,   504,   505,   174,   175,   506,   507,   178,
     508,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,     0,   191,   192,   193,     0,   194,   195,   196,
     197,   198,   199,     0,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,     1,     0,     0,     0,     0,     0,
       0,     0,     2,     3,     4,     5,     6,     7,     0,     0,
       8,     0,     0,     0,   374,   375,     0,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,   470,   471,
      24,   473,   376,    27,   474,    29,    30,     0,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,   476,    42,
      43,   477,     0,    45,    46,    47,   479,   480,    50,   481,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,     0,    68,    69,    70,
      71,    72,    73,    74,    75,     0,     0,    76,    77,     0,
       0,     0,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,     0,     0,     0,    89,     0,    90,    91,
      92,    93,     0,    94,     0,     0,     0,   488,    96,    97,
      98,    99,     0,     0,     0,     0,     0,     0,   100,   101,
     102,   103,   104,   105,   106,     0,     0,     0,   107,   108,
       0,   110,   111,     0,     0,     0,     0,   112,   113,   114,
     115,   116,   117,   118,   119,     0,   120,     0,     0,     0,
       0,     0,   123,   124,   125,     0,     0,     0,   126,     0,
     127,   128,     0,     0,     0,   131,     0,   132,     0,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
       0,     0,   144,   145,   146,     0,   378,   148,   149,   150,
     151,   152,   153,   154,   155,   497,   157,   498,   159,   499,
     500,   162,   163,   164,   165,   166,   167,   501,   169,   502,
     503,   504,   505,   174,   175,   506,   507,   178,   508,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
       0,   191,   192,   193,     0,   194,   195,   196,   197,   198,
     199,     0,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,     1,     0,     0,     0,     0,     0,     0,     0,
       2,     0,     0,     0,     6,     7,     0,     0,   466,     0,
       0,     0,   374,   375,     0,    11,    12,    13,   467,    15,
      16,    17,    18,   468,    20,   469,   470,   471,   472,   473,
     376,    27,   474,    29,    30,     0,    31,    32,    33,    34,
      35,   475,    37,    38,    39,    40,   476,    42,    43,   477,
       0,    45,   478,    47,   479,   480,    50,   481,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,   482,   483,    67,     0,    68,    69,    70,   484,     0,
      73,    74,    75,     0,     0,   485,    77,     0,     0,     0,
       0,    79,    80,    81,   486,   487,    84,    85,     0,     0,
       0,     0,     0,     0,     0,     0,    90,    91,    92,    93,
       0,    94,     0,     0,     0,   488,    96,    97,   489,   490,
       0,     0,     0,     0,     0,     0,   100,   101,   102,     0,
     104,   105,   106,     0,     0,     0,     0,     0,     0,   110,
     111,     0,     0,     0,     0,   112,   113,   114,   115,   491,
     117,   118,   492,     0,     0,     0,     0,     0,     0,     0,
     493,   494,   125,     0,     0,     0,   126,     0,   127,   495,
       0,     0,     0,   131,     0,   132,     0,   133,   134,   135,
     136,   496,   138,   139,   140,   141,   142,   143,     0,     0,
     144,   145,     0,     0,   378,   148,   149,   150,   151,   152,
     153,   154,   155,   497,   157,   498,   159,   499,   500,   162,
     163,   164,   165,   166,   167,   501,   169,   502,   503,   504,
     505,   174,   175,   506,   507,   178,   508,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,     0,   191,
     192,   193,     0,   194,   195,   196,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
       1,     0,     0,     0,     0,     0,     0,     0,     2,     0,
       0,     0,     6,     7,     0,     0,   466,     0,     0,     0,
     374,   375,     0,    11,    12,    13,   515,    15,    16,    17,
      18,   468,   516,   517,   470,   471,   472,   473,   376,    27,
     474,    29,    30,     0,    31,    32,    33,    34,    35,   518,
      37,   519,   520,    40,   476,    42,    43,   477,     0,    45,
     521,    47,   479,   480,    50,   481,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,   482,
     483,    67,     0,    68,    69,    70,   522,     0,    73,    74,
      75,     0,     0,   485,    77,     0,     0,     0,     0,    79,
      80,    81,   486,   487,    84,    85,     0,     0,     0,     0,
       0,     0,     0,     0,    90,    91,    92,    93,     0,    94,
       0,     0,     0,   488,    96,    97,   489,   490,     0,     0,
       0,     0,     0,     0,   100,   101,   102,     0,   104,   105,
     106,     0,     0,     0,     0,     0,     0,   110,   111,     0,
       0,     0,     0,   112,   113,   114,   115,   491,   117,   118,
     492,     0,     0,     0,     0,     0,     0,     0,   493,   494,
     125,     0,     0,     0,   126,     0,   127,   495,     0,     0,
       0,   131,     0,   132,     0,   133,   134,   135,   136,   496,
     138,   139,   140,   141,   142,   143,     0,     0,   144,   145,
       0,     0,   378,   148,   149,   150,   151,   152,   153,   154,
     155,   497,   523,   498,   159,   499,   500,   162,   163,   164,
     165,   166,   167,   501,   169,   502,   503,   504,   505,   174,
     175,   506,   507,   178,   508,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,     0,   191,   192,   193,
       0,   194,   195,   196,   197,   198,   199,     0,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   533,     0,
       0,     0,     0,     0,     0,     0,     6,     7,     0,     0,
     738,     0,     0,     0,   374,   375,     0,    11,    12,    13,
     515,    15,    16,    17,    18,   468,   516,   517,   470,   471,
     472,   473,   376,    27,   474,    29,    30,     0,    31,    32,
      33,    34,    35,   518,    37,   519,   520,    40,   476,    42,
      43,   477,     0,    45,   521,    47,   479,   480,    50,   481,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,   482,   483,    67,     0,    68,    69,    70,
     522,     0,    73,    74,    75,     0,     0,   485,    77,     0,
       0,     0,     0,    79,    80,    81,   486,   487,    84,    85,
       0,     0,     0,     0,     0,     0,     0,     0,    90,    91,
      92,    93,     0,    94,     0,     0,     0,   488,    96,    97,
     489,   490,     0,     0,     0,     0,     0,     0,   100,   101,
     102,     0,   104,   105,   106,     0,     0,     0,     0,     0,
       0,   110,   111,     0,     0,     0,     0,   112,   113,   114,
     115,   491,   117,   118,   492,     0,     0,     0,     0,     0,
       0,     0,   493,   494,   125,     0,     0,     0,   126,   739,
     127,   495,     0,     0,     0,     0,     0,   132,     0,   133,
     134,   135,   136,   496,   138,   139,   140,   141,   142,   143,
       0,     0,   144,   145,     0,     0,   378,   148,   149,   150,
     151,   152,   153,   154,   155,   497,   523,   498,   159,   499,
     500,   162,   163,   164,   165,   166,   167,   501,   169,   502,
     503,   504,   505,   174,   175,   506,   507,   178,   508,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
       0,   191,   192,   193,     0,   194,   195,   196,   197,   198,
     199,     0,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   533,     0,     0,     0,     0,     0,     0,     0,
       6,     7,     0,     0,   466,     0,     0,     0,   374,   375,
       0,    11,    12,    13,   515,    15,    16,    17,    18,   468,
     516,   517,   470,   471,   472,   473,   376,    27,   474,    29,
      30,     0,    31,    32,    33,    34,    35,   518,    37,   519,
     520,    40,   476,    42,    43,   477,     0,    45,   521,    47,
     479,   480,    50,   481,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,   482,   483,    67,
       0,    68,    69,    70,   522,     0,    73,    74,    75,     0,
       0,   485,    77,     0,     0,     0,     0,    79,    80,    81,
     486,   487,    84,    85,     0,     0,     0,     0,     0,     0,
       0,     0,    90,    91,    92,    93,     0,    94,     0,     0,
       0,   488,    96,    97,   489,   490,     0,     0,     0,     0,
       0,     0,   100,   101,   102,     0,   104,   105,   106,     0,
       0,     0,     0,     0,     0,   110,   111,     0,     0,     0,
       0,   112,   113,   114,   115,   491,   117,   118,   492,     0,
       0,     0,     0,     0,     0,     0,   493,   494,   125,     0,
       0,     0,   126,     0,   127,   495,     0,     0,     0,     0,
       0,   132,     0,   133,   134,   135,   136,   496,   138,   139,
     140,   141,   142,   143,     0,     0,   144,   145,     0,     0,
     378,   148,   149,   150,   151,   152,   153,   154,   155,   497,
     523,   498,   159,   499,   500,   162,   163,   164,   165,   166,
     167,   501,   169,   502,   503,   504,   505,   174,   175,   506,
     507,   178,   508,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,     0,   191,   192,   193,     0,   194,
     195,   196,   197,   198,   199,     0,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   536,   537,     0,     0,
       0,     0,     6,     7,     0,     0,   466,     0,     0,     0,
     374,   375,     0,    11,    12,    13,   515,    15,    16,    17,
      18,   468,   516,   517,   470,   471,   472,   473,   376,    27,
     474,    29,    30,     0,    31,    32,    33,    34,    35,   518,
      37,   519,   520,    40,   476,    42,    43,   477,     0,    45,
     521,    47,   479,   480,    50,   481,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,   482,
     483,    67,     0,    68,    69,    70,   522,     0,    73,    74,
      75,     0,     0,   485,    77,     0,     0,     0,     0,    79,
      80,    81,   486,   487,    84,    85,     0,     0,     0,     0,
       0,     0,     0,     0,    90,    91,    92,    93,     0,    94,
       0,     0,     0,   488,    96,    97,   489,   490,     0,     0,
       0,     0,     0,     0,   100,   101,   102,     0,   104,   105,
     106,     0,     0,     0,     0,     0,     0,   110,   111,     0,
       0,     0,     0,   112,   113,   114,   115,   491,   117,   118,
     492,     0,     0,     0,     0,     0,     0,     0,   493,   494,
     125,     0,     0,     0,   126,     0,   127,   495,     0,     0,
       0,     0,     0,   132,     0,   133,   134,   135,   136,   496,
     138,   139,   140,   141,   142,   143,     0,     0,   144,   145,
       0,     0,   378,   148,   149,   150,   151,   152,   153,   154,
     155,   497,   523,   498,   159,   499,   500,   162,   163,   164,
     165,   166,   167,   501,   169,   502,   503,   504,   505,   174,
     175,   506,   507,   178,   508,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,     0,   191,   192,   193,
       0,   194,   195,   196,   197,   198,   199,     0,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,     6,     7,
       0,     0,   466,     0,     0,     0,   374,   375,     0,    11,
      12,    13,   467,    15,    16,    17,    18,   468,    20,   469,
     470,   471,  1048,   473,   376,    27,   474,    29,    30,     0,
      31,    32,    33,    34,    35,   475,    37,    38,    39,    40,
     476,    42,    43,   477,     0,    45,   478,    47,   479,   480,
      50,   481,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,   482,   483,    67,     0,    68,
      69,    70,   484,     0,    73,    74,    75,     0,     0,   485,
      77,     0,     0,     0,     0,    79,    80,    81,   486,   487,
      84,    85,     0,     0,     0,     0,     0,     0,     0,     0,
      90,    91,    92,    93,     0,    94,     0,     0,     0,   488,
      96,    97,   489,   490,     0,     0,     0,     0,     0,     0,
     100,   101,   102,     0,   104,   105,  1049,     0,     0,     0,
    1050,     0,     0,   110,   111,     0,     0,     0,     0,   112,
     113,   114,   115,   491,   117,   118,   492,     0,     0,     0,
       0,     0,     0,     0,   493,   494,   125,     0,     0,     0,
     126,  1440,   127,   495,     0,     0,     0,  1441,     0,   132,
       0,   133,   134,   135,   136,   496,   138,   139,   140,   141,
     142,   143,     0,     0,  1051,   145,     0,     0,   378,   148,
     149,   150,   151,   152,   153,   154,   155,   497,   157,   498,
     159,   499,   500,   162,   163,   164,   165,   166,   167,   501,
     169,   502,   503,   504,   505,   174,   175,   506,   507,   178,
     508,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,     0,   191,   192,   193,     0,   194,   195,   196,
     197,   198,   199,     0,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,     6,     7,     0,     0,   466,     0,
       0,     0,   374,   375,     0,    11,    12,    13,   515,    15,
      16,    17,    18,   468,   516,   517,   470,   471,   472,   473,
     376,    27,   474,    29,    30,     0,    31,    32,    33,    34,
      35,   518,    37,   519,   520,    40,   476,    42,    43,   477,
       0,    45,   521,    47,   479,   480,    50,   481,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,   482,   483,    67,     0,    68,    69,    70,   522,     0,
      73,    74,    75,     0,     0,   485,    77,     0,     0,     0,
       0,    79,    80,    81,   486,   487,    84,    85,     0,     0,
       0,     0,     0,     0,     0,     0,    90,    91,    92,    93,
       0,    94,     0,     0,     0,   488,    96,    97,   489,   490,
       0,     0,     0,     0,     0,     0,   100,   101,   102,     0,
     104,   105,   106,     0,     0,     0,     0,     0,     0,   110,
     111,     0,     0,     0,     0,   112,   113,   114,   115,   491,
     117,   118,   492,     0,     0,     0,     0,     0,     0,     0,
     493,   494,   125,     0,     0,     0,   126,   709,   127,   495,
       0,     0,     0,   710,     0,   132,     0,   133,   134,   135,
     136,   496,   138,   139,   140,   141,   142,   143,     0,     0,
     144,   145,     0,     0,   378,   148,   149,   150,   151,   152,
     153,   154,   155,   497,   523,   498,   159,   499,   500,   162,
     163,   164,   165,   166,   167,   501,   169,   502,   503,   504,
     505,   174,   175,   506,   507,   178,   508,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,     0,   191,
     192,   193,     0,   194,   195,   196,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
       6,     7,     0,     0,   466,     0,     0,     0,   374,   375,
       0,    11,    12,    13,   515,    15,    16,    17,    18,   468,
     516,   517,   470,   471,   472,   473,   376,    27,   474,    29,
      30,     0,    31,    32,    33,    34,    35,   518,    37,   519,
     520,    40,   476,    42,    43,   477,     0,    45,   521,    47,
     479,   480,    50,   481,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,   482,   483,    67,
       0,    68,    69,    70,   522,     0,    73,    74,    75,     0,
       0,   485,    77,     0,     0,     0,     0,    79,    80,    81,
     486,   487,    84,    85,     0,     0,     0,     0,     0,     0,
       0,     0,    90,    91,    92,    93,     0,    94,     0,     0,
       0,   488,    96,    97,   489,   490,     0,     0,     0,     0,
       0,     0,   100,   101,   102,     0,   104,   105,   106,     0,
       0,     0,     0,     0,     0,   110,   111,     0,     0,     0,
       0,   112,   113,   114,   115,   491,   117,   118,   492,     0,
       0,     0,     0,     0,     0,     0,   493,   494,   125,     0,
       0,     0,   126,   757,   127,   495,     0,     0,     0,   758,
       0,   132,     0,   133,   134,   135,   136,   496,   138,   139,
     140,   141,   142,   143,     0,     0,   144,   145,     0,     0,
     378,   148,   149,   150,   151,   152,   153,   154,   155,   497,
     523,   498,   159,   499,   500,   162,   163,   164,   165,   166,
     167,   501,   169,   502,   503,   504,   505,   174,   175,   506,
     507,   178,   508,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,     0,   191,   192,   193,     0,   194,
     195,   196,   197,   198,   199,     0,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,     6,     7,     0,     0,
     466,     0,     0,     0,   374,   375,     0,    11,    12,    13,
     467,    15,    16,    17,    18,   468,    20,   469,   470,   471,
    1048,   473,   376,    27,   474,    29,    30,     0,    31,    32,
      33,    34,    35,   475,    37,    38,    39,    40,   476,    42,
      43,   477,     0,    45,   478,    47,   479,   480,    50,   481,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,   482,   483,    67,     0,    68,    69,    70,
     484,     0,    73,    74,    75,     0,     0,   485,    77,     0,
       0,     0,     0,    79,    80,    81,   486,   487,    84,    85,
    1370,     0,     0,     0,     0,     0,     0,     0,    90,    91,
      92,    93,     0,    94,     0,     0,     0,   488,    96,    97,
     489,   490,     0,     0,     0,     0,     0,     0,   100,   101,
     102,     0,   104,   105,  1049,     0,     0,     0,  1050,     0,
       0,   110,   111,     0,     0,     0,     0,   112,   113,   114,
     115,   491,   117,   118,   492,     0,     0,     0,     0,     0,
       0,     0,   493,   494,   125,     0,     0,     0,   126,     0,
     127,   495,     0,     0,     0,     0,     0,   132,     0,   133,
     134,   135,   136,   496,   138,   139,   140,   141,   142,   143,
       0,     0,  1051,   145,     0,     0,   378,   148,   149,   150,
     151,   152,   153,   154,   155,   497,   157,   498,   159,   499,
     500,   162,   163,   164,   165,   166,   167,   501,   169,   502,
     503,   504,   505,   174,   175,   506,   507,   178,   508,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
       0,   191,   192,   193,     0,   194,   195,   196,   197,   198,
     199,     0,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,     6,     7,     0,     0,   466,     0,     0,     0,
     374,   375,     0,    11,    12,    13,   467,    15,    16,    17,
      18,   468,    20,   469,   470,   471,  1048,   473,   376,    27,
     474,    29,    30,     0,    31,    32,    33,    34,    35,   475,
      37,    38,    39,    40,   476,    42,    43,   477,     0,    45,
     478,    47,   479,   480,    50,   481,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,   482,
     483,    67,     0,    68,    69,    70,   484,     0,    73,    74,
      75,     0,     0,   485,    77,     0,     0,     0,     0,    79,
      80,    81,   486,   487,    84,    85,     0,     0,     0,     0,
       0,     0,     0,     0,    90,    91,    92,    93,     0,    94,
       0,     0,     0,   488,    96,    97,   489,   490,     0,     0,
       0,     0,     0,     0,   100,   101,   102,     0,   104,   105,
    1049,     0,     0,     0,  1050,     0,     0,   110,   111,     0,
       0,     0,     0,   112,   113,   114,   115,   491,   117,   118,
     492,     0,     0,     0,     0,     0,     0,     0,   493,   494,
     125,     0,     0,     0,   126,     0,   127,   495,     0,     0,
       0,     0,     0,   132,     0,   133,   134,   135,   136,   496,
     138,   139,   140,   141,   142,   143,     0,     0,  1051,   145,
       0,     0,   378,   148,   149,   150,   151,   152,   153,   154,
     155,   497,   157,   498,   159,   499,   500,   162,   163,   164,
     165,   166,   167,   501,   169,   502,   503,   504,   505,   174,
     175,   506,   507,   178,   508,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,     0,   191,   192,   193,
       0,   194,   195,   196,   197,   198,   199,     0,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,     6,     7,
       0,     0,   466,     0,     0,     0,   374,   375,     0,    11,
      12,    13,   467,    15,    16,    17,    18,   468,    20,   469,
     470,   471,  1048,   473,   376,    27,   474,    29,    30,     0,
      31,    32,    33,    34,    35,   475,    37,    38,    39,    40,
     476,    42,    43,   477,     0,    45,   478,    47,   479,   480,
      50,   481,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,   482,   483,    67,     0,    68,
      69,    70,   484,     0,    73,    74,    75,     0,     0,   485,
      77,     0,     0,     0,     0,    79,    80,    81,   486,   487,
      84,    85,     0,     0,     0,     0,     0,     0,     0,     0,
      90,    91,    92,    93,     0,    94,     0,     0,     0,   488,
      96,    97,   489,   490,     0,     0,     0,     0,     0,     0,
     100,   101,   102,     0,   104,   105,  1049,     0,     0,     0,
    1050,     0,     0,   110,   111,     0,     0,     0,     0,   112,
     113,   114,   115,   491,   117,   118,   492,     0,     0,     0,
       0,     0,     0,     0,   493,   494,   125,     0,     0,     0,
     126,     0,   127,   495,     0,     0,     0,     0,     0,   132,
       0,   133,   134,   135,   136,   496,   138,   139,   140,   141,
     142,   143,     0,     0,   144,   145,     0,     0,   378,   148,
     149,   150,   151,   152,   153,   154,   155,   497,   157,   498,
     159,   499,   500,   162,   163,   164,   165,   166,   167,   501,
     169,   502,   503,   504,   505,   174,   175,   506,   507,   178,
     508,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,     0,   191,   192,   193,     0,   194,   195,   196,
     197,   198,   199,     0,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,     6,     7,     0,     0,   466,     0,
       0,     0,   374,   375,     0,    11,    12,    13,   515,    15,
      16,    17,    18,   468,   516,   517,   470,   471,   472,   473,
     376,    27,   474,    29,    30,     0,    31,    32,    33,    34,
      35,   518,    37,   519,   520,    40,   476,    42,    43,   477,
       0,    45,   521,    47,   479,   480,    50,   481,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,   482,   483,    67,     0,    68,    69,    70,   522,     0,
      73,    74,    75,     0,     0,   485,    77,     0,     0,     0,
       0,    79,    80,    81,   486,   487,    84,    85,     0,     0,
       0,     0,     0,     0,     0,     0,    90,    91,    92,    93,
       0,    94,     0,     0,     0,   488,    96,    97,   489,   490,
       0,     0,     0,     0,     0,     0,   100,   101,   102,     0,
     104,   105,   106,     0,     0,     0,     0,     0,     0,   110,
     111,     0,     0,     0,     0,   112,   113,   114,   115,   491,
     117,   118,   492,     0,     0,     0,     0,     0,     0,     0,
     493,   494,   125,     0,     0,     0,   126,     0,   127,   495,
       0,     0,     0,     0,     0,   132,     0,   133,   134,   135,
     136,   496,   138,   139,   140,   141,   142,   143,     0,     0,
     144,   145,     0,     0,   378,   148,   149,   150,   151,   152,
     153,   154,   155,   497,   523,   498,   159,   499,   500,   162,
     163,   164,   165,   166,   167,   501,   169,   502,   503,   504,
     505,   174,   175,   506,   507,   178,   508,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,     0,   191,
     192,   193,     0,   194,   195,   196,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
       6,     7,     0,     0,   466,     0,     0,     0,   374,   375,
       0,    11,    12,    13,     0,    15,    16,    17,    18,   468,
       0,     0,   470,   471,   472,     0,   376,    27,   474,    29,
      30,     0,    31,    32,    33,    34,    35,     0,    37,     0,
       0,    40,   476,    42,    43,   477,     0,    45,     0,    47,
       0,     0,    50,   481,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,   482,   483,    67,
       0,    68,    69,    70,     0,     0,    73,    74,    75,     0,
       0,   485,    77,     0,     0,     0,     0,    79,    80,    81,
     486,   487,    84,    85,     0,     0,     0,     0,     0,     0,
       0,     0,    90,    91,    92,    93,     0,    94,     0,     0,
       0,   488,    96,    97,   489,   490,     0,     0,     0,     0,
       0,     0,   100,   101,   102,     0,   104,   105,     0,     0,
       0,     0,     0,     0,     0,   110,   111,     0,     0,     0,
       0,   112,   113,   114,   115,   491,   117,   118,   492,     0,
       0,     0,     0,     0,     0,     0,   493,   494,   125,     0,
       0,     0,   126,     0,   127,   495,     0,     0,     0,     0,
       0,   132,     0,   133,   134,   135,   136,   496,   138,   139,
     140,   141,   142,   143,     0,     0,     0,   145,     0,     0,
     378,   148,   149,   150,   151,   152,   153,   154,   155,   497,
       0,   498,   159,   499,   500,   162,   163,   164,   165,   166,
     167,   501,   169,   502,   503,   504,   505,   174,   175,     0,
     507,   178,   508,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,     0,   191,   192,   193,     0,   194,
     195,   196,   197,   198,   199,     0,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
        72,   619,   733,   620,   621,   622,   623,     3,     4,     5,
     654,   840,   763,   311,    86,   746,   385,  1120,   581,   717,
     247,   248,   246,   956,   989,   130,  1233,   917,  1397,  1249,
    1250,  1034,    72,   575,   576,    34,   108,   717,    27,    34,
     399,  1315,   839,   840,   117,    56,    28,   662,   120,     1,
     122,   573,   574,   575,   576,   827,   573,   574,     1,   878,
    1206,  1282,   599,     8,   601,   602,   425,   604,    96,   606,
      94,   440,   441,     1,    44,   141,    94,   614,   615,     1,
      37,   878,     1,     1,     1,   106,    43,    44,    54,   448,
     106,    57,   157,    63,    27,    72,    25,    96,   129,    94,
      93,    96,   117,    60,   933,    62,    63,    27,    99,    86,
     175,   107,    27,   120,    71,   912,   106,   946,    47,   106,
     109,    35,    36,   117,    38,    39,   106,   129,    32,    52,
     168,   108,   117,    99,   123,    64,   933,    66,    25,    45,
      97,   262,   181,   120,    58,   122,    75,   146,   215,   946,
     223,   146,   273,   884,   135,   194,   181,    61,   268,   148,
      47,   159,   200,   152,   195,   275,   155,   183,   146,   194,
      57,   106,     9,    10,     5,   285,   109,    64,     9,    66,
     106,     5,   111,   827,  1404,     9,   253,   176,    75,   182,
     123,   185,    79,   195,   185,   106,   146,   112,   112,   189,
     106,   186,   189,   268,   215,   128,   272,   187,   939,   314,
     275,   235,   233,    27,   945,   148,   186,   235,   199,   152,
     285,  1324,   155,   110,   111,   112,  1116,   255,   256,   174,
     212,  1050,  1197,   306,   985,  1381,  1169,   189,  1459,   159,
     938,  1206,   253,   176,   159,   159,   189,   319,   863,   864,
     322,   793,   794,  1050,   189,  1258,   936,   272,   938,    94,
     186,   189,  1034,  1035,  1633,   102,   223,   189,  1542,   258,
     189,   189,   189,   272,   791,   792,   187,   272,   958,   319,
    1649,   168,   322,   199,   250,   122,   823,   124,  1657,   648,
      53,   122,   208,   124,   272,   109,    59,   263,   122,   265,
     124,   132,  1509,   106,   218,   152,   675,  1011,   132,   123,
     276,   277,   278,   200,   280,   152,   282,   389,   390,   156,
      94,   152,   272,   395,   106,  1545,  1123,   399,   152,   176,
      94,   147,  1161,   405,   148,   130,   173,   106,   155,   106,
     412,   228,   319,   570,   116,   322,   260,   106,   164,   573,
     574,   106,    96,   425,   152,  1184,   193,   155,   106,   431,
    1463,   106,   731,   435,  1161,   106,  1586,   141,   727,   106,
     442,   730,   106,   145,   211,  1079,   448,   449,   450,   451,
     452,   216,   217,   186,    94,   457,   158,  1184,   152,   155,
    1034,  1035,    94,   465,   189,  1126,   231,    96,    94,   286,
     287,   288,   289,   290,   186,   292,   293,   294,   295,   296,
     208,     9,    10,   390,   301,   302,  1381,   186,   395,   186,
     192,   152,   399,    96,   168,     9,  1070,   186,   405,   152,
     426,   186,   428,  1323,   430,   412,   146,  1135,   186,   112,
      96,   186,    26,   439,    96,   186,     9,  1550,   425,   186,
     146,   447,   186,   525,   431,   219,   220,   453,   435,   455,
     456,  1290,   458,    26,  1144,   442,    94,    44,   464,   168,
      47,   448,   449,   450,   451,   452,  1018,  1019,  1020,    40,
     457,  1584,   155,   555,    44,    46,  1258,    47,   465,   121,
      51,   563,    99,  1290,   146,  1267,  1018,  1019,  1020,   155,
     262,   152,    79,   117,   102,   112,  1278,   251,   252,    70,
     254,   273,    95,   141,   216,   217,   885,   886,     9,    10,
     152,   890,   105,   155,   122,   176,   124,   271,   105,   231,
      96,    67,   115,   638,   639,   531,    72,   298,   122,   283,
     124,    96,  1645,   126,  1647,   105,   307,   543,   525,   133,
    1483,   920,   251,   252,   152,   254,   143,   112,   156,   122,
    1663,   124,   261,     9,    10,    53,   562,   791,   152,   796,
     133,    59,   271,    53,    31,   173,   648,   105,   555,    59,
     146,   117,   117,   952,   283,   157,   563,   956,   175,   152,
     167,   926,    49,   928,   666,   193,   668,    77,   126,   671,
     155,   135,   223,   175,   225,   192,   167,   167,    96,   170,
      94,   102,    31,   211,  1258,   149,    96,   157,  1563,  1564,
     692,   693,   694,  1267,   185,   197,   875,    99,  1379,   267,
      49,   122,  1383,   124,  1278,   175,   274,   117,   887,   635,
     112,   246,   247,  1341,   640,   980,   718,   982,   720,   210,
     147,  1269,   136,   168,  1599,   727,   102,   141,   730,  1431,
    1605,   152,   734,  1394,   269,   156,   121,   164,   157,    94,
     155,   648,   165,   136,   155,   136,   122,   136,   124,    96,
     105,   641,   173,   121,   644,   200,   175,   647,   181,   152,
     762,   152,   223,   152,   671,   112,  1238,   228,   223,  1528,
     225,  1530,   193,   276,   277,   278,   152,   136,   197,   282,
     156,   155,   141,   228,   136,   692,   693,   694,   321,   141,
     211,   152,   152,   326,   155,   155,   152,   173,   724,   155,
    1559,  1528,   152,  1530,   230,   155,   232,   155,  1036,   811,
     155,   718,  1305,   720,   153,  1496,   155,   193,  1499,   121,
     727,  1580,   121,   730,   219,   220,   221,   734,   754,   755,
     121,   230,  1559,   232,   117,   211,   121,   839,   840,   841,
     842,   286,   287,   288,   289,   290,   121,   292,   293,   294,
     295,   296,   152,  1580,   121,   762,   301,  1431,   784,   190,
     191,   299,   300,   299,   300,  1164,   127,   128,  1415,   121,
    1169,   127,   128,   121,  1422,  1423,   878,   290,   291,   121,
     131,   617,   618,   152,  1545,   432,  1567,   214,   139,   140,
     892,   142,   624,   625,   223,   626,   627,   841,   842,   150,
    1450,  1451,   155,   154,   811,   156,   117,   152,   240,   155,
     161,   241,   240,   152,   117,     0,   166,   919,    92,    50,
     198,   100,   248,   101,   926,   153,   928,   178,   120,   144,
     155,   933,   839,   840,   841,   842,   183,   155,    27,   183,
     183,    47,    47,    47,   946,   151,  1245,   117,   245,   292,
     201,   202,   203,   204,   205,   206,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,   303,   186,  1516,  1517,
     283,   878,   297,   297,   283,   117,   152,   117,   980,   141,
     982,   106,   186,   152,   152,   892,   186,    33,   155,   155,
     155,   155,   155,    16,    27,   212,   186,   229,     3,   117,
     547,   548,   141,   550,   551,   552,   553,   167,   169,    71,
     169,    94,   919,   560,   561,   229,    94,    94,   148,   926,
     106,   928,   106,    27,   159,   159,   933,  1029,  1576,   126,
     131,   578,   579,   245,   298,   117,   131,   183,   183,   946,
     106,   588,   589,   186,    94,   186,   183,   183,  1050,   975,
      44,    96,    96,   186,   183,   183,   152,    94,  1357,   186,
     186,   141,   235,   186,   186,   186,   186,   183,   183,   183,
     183,   223,   141,   980,   186,   982,   183,    31,   169,   117,
     183,   141,   184,   131,    94,    27,   285,   225,   298,   152,
     117,   126,   117,   146,    94,   253,   117,   196,   159,   646,
     131,   131,   183,   650,    96,   152,   117,  1033,    99,  1408,
     146,    99,   183,   183,    33,    27,   117,    79,   152,   117,
     152,   117,  1029,   106,   183,   244,   106,   284,   143,   155,
      27,    25,  1134,   155,   266,  1137,   155,   285,    27,    27,
     257,    35,    36,  1050,    38,    39,   225,   235,   259,   225,
    1152,  1077,   305,    47,   143,   126,   146,   225,   186,  1161,
     189,   146,   186,    57,    58,   146,   186,   117,   186,   117,
      64,    77,    66,   106,  1176,   141,   286,   183,   186,   186,
     131,    75,  1184,     7,  1483,    79,   189,   105,   735,   231,
     231,   231,   231,   186,   105,   249,    78,   183,   185,   146,
     249,  1203,  1128,   270,   186,    27,   281,   186,   186,   183,
      27,   285,    96,   169,   183,   146,   110,   111,   112,   235,
     146,   125,  1224,    96,   183,  1227,    94,  1134,   185,   152,
    1137,  1233,   185,    27,   183,  1237,   279,   183,   183,   256,
     106,   169,   186,   186,   146,  1152,    53,    94,  1174,   141,
     117,    94,    27,   106,  1161,   195,   117,   117,   223,   195,
     807,   185,   264,   195,  1190,   159,   813,   183,   117,  1176,
     185,   223,   286,    93,   168,   182,   117,  1184,   195,   117,
     152,   117,   223,   292,   197,   186,   117,  1083,  1290,   879,
     674,   304,   304,  1123,  1550,  1229,  1203,  1584,   947,   944,
     393,   240,   286,  1134,  1237,   304,   200,   736,   305,   243,
     305,   246,  1351,   243,   286,  1153,  1254,  1224,  1025,  1321,
    1227,   419,  1252,   417,   218,  1176,  1233,   419,   305,   438,
    1237,  1249,   525,   880,   228,   597,   650,   307,  1181,   598,
    1197,   763,  1605,  1185,  1599,   842,  1348,  1349,  1117,   928,
    1224,  1234,  1082,  1267,  1431,  1035,   429,   429,  1271,  1428,
    1044,   911,  1278,  1105,  1313,  1453,   260,  1268,  1370,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1380,    -1,
      -1,    -1,  1384,  1290,    -1,    -1,    -1,    -1,   935,    -1,
      -1,    -1,   286,   287,   288,   289,   290,    -1,   292,   293,
     294,   295,   296,    -1,    -1,    -1,    -1,   301,   302,    -1,
     957,    -1,    -1,    -1,  1321,    -1,    -1,    -1,    -1,    -1,
     967,    -1,   969,   970,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   984,    -1,    -1,
      -1,  1348,  1349,    -1,    -1,    -1,    -1,    -1,   995,   996,
     997,    -1,   999,  1000,  1001,  1002,  1003,  1004,    -1,  1006,
    1007,    -1,    -1,  1370,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1380,    -1,    -1,    -1,  1384,  1025,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1492,    -1,    -1,    -1,    -1,  1497,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1509,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1067,    -1,    -1,    -1,    -1,    -1,  1528,    -1,  1530,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1546,    -1,    -1,  1549,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1559,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1572,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1580,    -1,
      -1,    -1,    -1,    -1,    -1,  1492,  1588,    -1,    -1,    -1,
    1497,  1593,  1139,    -1,  1141,    -1,  1143,    -1,    -1,  1146,
    1526,    -1,  1509,    -1,  1151,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1163,    -1,  1620,    -1,
      -1,  1528,    -1,  1530,    -1,  1172,    -1,    -1,    -1,    -1,
      -1,    -1,  1179,  1180,    -1,  1637,    -1,  1639,    -1,  1546,
      -1,    -1,  1549,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1652,    -1,  1559,    -1,  1656,    -1,    -1,    -1,    -1,  1661,
      -1,    -1,    -1,    -1,    -1,  1572,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1580,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1588,    -1,    -1,    -1,    -1,  1593,    -1,    -1,  1236,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1252,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1620,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1637,    -1,  1639,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1652,    -1,    -1,    -1,  1656,
      -1,    -1,    -1,    -1,  1661,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1335,    -1,
      -1,    -1,  1339,    -1,    -1,    -1,  1343,    -1,  1345,    -1,
    1347,    -1,    -1,    -1,    -1,    -1,  1353,    -1,    -1,    -1,
      -1,    -1,    -1,  1360,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1368,  1369,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1387,  1388,  1389,  1390,  1391,    -1,  1393,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1470,    -1,  1472,    -1,    -1,  1475,    -1,
      -1,    -1,    -1,    -1,    -1,  1482,    -1,    -1,    -1,    -1,
    1487,    -1,    -1,    -1,  1491,    -1,  1493,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1506,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1553,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1571,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1595,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1618,    -1,    11,    -1,    -1,  1623,    -1,    -1,    -1,
      -1,    19,    20,    21,    22,    23,    24,    -1,    -1,    27,
      -1,    -1,    -1,    31,    32,  1642,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    -1,    94,    95,    96,    97,
      98,    99,   100,   101,    -1,    -1,   104,   105,    -1,    -1,
      -1,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,    -1,    -1,    -1,   123,    -1,   125,   126,   127,
     128,    -1,   130,    -1,    -1,    -1,   134,   135,   136,   137,
     138,    -1,    -1,    -1,    -1,    -1,    -1,   145,   146,   147,
     148,   149,   150,   151,    -1,    -1,    -1,   155,   156,   157,
     158,   159,    -1,    -1,    -1,    -1,   164,   165,   166,   167,
     168,   169,   170,   171,    -1,   173,    -1,   175,   176,    -1,
      -1,   179,   180,   181,    -1,    -1,    -1,   185,    -1,   187,
     188,    -1,   190,   191,   192,    -1,   194,    -1,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,    -1,
      -1,   209,   210,   211,    -1,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,    -1,
     258,   259,   260,    -1,   262,   263,   264,   265,   266,   267,
      -1,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      19,    20,    21,    22,    23,    24,    -1,    -1,    27,    -1,
      -1,    -1,    31,    32,    -1,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    -1,    94,    95,    96,    97,    98,
      99,   100,   101,    -1,    -1,   104,   105,    -1,    -1,    -1,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,    -1,    -1,    -1,   123,    -1,   125,   126,   127,   128,
      -1,   130,    -1,    -1,    -1,   134,   135,   136,   137,   138,
      -1,    -1,    -1,    -1,    -1,    -1,   145,   146,   147,   148,
     149,   150,   151,    -1,    -1,    -1,   155,   156,   157,   158,
     159,    -1,    -1,    -1,    -1,   164,   165,   166,   167,   168,
     169,   170,   171,    -1,   173,    -1,   175,   176,    -1,    -1,
     179,   180,   181,    -1,   183,    -1,   185,    -1,   187,   188,
      -1,   190,   191,   192,    -1,   194,    -1,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,    -1,    -1,
     209,   210,   211,    -1,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,   258,
     259,   260,    -1,   262,   263,   264,   265,   266,   267,    -1,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,
      21,    22,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,
      31,    32,    -1,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    94,    95,    96,    97,    98,    99,   100,
     101,    -1,    -1,   104,   105,    -1,    -1,    -1,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,    -1,
      -1,    -1,   123,    -1,   125,   126,   127,   128,    -1,   130,
      -1,    -1,    -1,   134,   135,   136,   137,   138,    -1,    -1,
      -1,    -1,    -1,    -1,   145,   146,   147,   148,   149,   150,
     151,    -1,    -1,    -1,   155,   156,   157,   158,   159,    -1,
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
      -1,   262,   263,   264,   265,   266,   267,    -1,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    21,    22,
      23,    24,    -1,    -1,    27,    -1,    -1,    -1,    31,    32,
      -1,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      -1,    94,    95,    96,    97,    98,    99,   100,   101,    -1,
      -1,   104,   105,    -1,    -1,    -1,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,    -1,    -1,    -1,
     123,    -1,   125,   126,   127,   128,    -1,   130,    -1,    -1,
      -1,   134,   135,   136,   137,   138,    -1,    -1,    -1,    -1,
      -1,    -1,   145,   146,   147,   148,   149,   150,   151,    -1,
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
     263,   264,   265,   266,   267,    -1,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    19,    20,    21,    22,    23,    24,
      -1,    -1,    27,    -1,    -1,    -1,    31,    32,    -1,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    -1,    94,
      95,    96,    97,    98,    99,   100,   101,    -1,    -1,   104,
     105,    -1,    -1,    -1,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,    -1,    -1,    -1,   123,    -1,
     125,   126,   127,   128,    -1,   130,    -1,    -1,    -1,   134,
     135,   136,   137,   138,    -1,    -1,    -1,    -1,    -1,    -1,
     145,   146,   147,   148,   149,   150,   151,    -1,    -1,    -1,
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
     265,   266,   267,    -1,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    19,    20,    21,    22,    23,    24,    -1,    -1,
      27,    -1,    -1,    -1,    31,    32,    -1,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    -1,    94,    95,    96,
      97,    98,    99,   100,   101,    -1,    -1,   104,   105,    -1,
      -1,    -1,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,    -1,    -1,    -1,   123,    -1,   125,   126,
     127,   128,    -1,   130,    -1,    -1,    -1,   134,   135,   136,
     137,   138,    -1,    -1,    -1,    -1,    -1,    -1,   145,   146,
     147,   148,   149,   150,   151,    -1,    -1,    -1,   155,   156,
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
     267,    -1,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      19,    20,    21,    22,    23,    24,    -1,    -1,    27,    -1,
      -1,    -1,    31,    32,    -1,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    -1,    94,    95,    96,    97,    98,
      99,   100,   101,    -1,    -1,   104,   105,    -1,    -1,    -1,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,    -1,    -1,    -1,   123,    -1,   125,   126,   127,   128,
      -1,   130,    -1,    -1,    -1,   134,   135,   136,   137,   138,
      -1,    -1,    -1,    -1,    -1,    -1,   145,   146,   147,   148,
     149,   150,   151,    -1,    -1,    -1,   155,   156,   157,   158,
     159,    -1,    -1,    -1,    -1,   164,   165,   166,   167,   168,
     169,   170,   171,    -1,   173,    -1,   175,   176,    -1,    -1,
     179,   180,   181,    -1,    -1,    -1,   185,   186,   187,   188,
      -1,   190,   191,   192,    -1,   194,    -1,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,    -1,    -1,
     209,   210,   211,    -1,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,   258,
     259,   260,    -1,   262,   263,   264,   265,   266,   267,    -1,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,
      21,    22,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,
      31,    32,    -1,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    94,    95,    96,    97,    98,    99,   100,
     101,    -1,    -1,   104,   105,    -1,    -1,    -1,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,    -1,
      -1,    -1,   123,    -1,   125,   126,   127,   128,    -1,   130,
      -1,    -1,    -1,   134,   135,   136,   137,   138,    -1,    -1,
      -1,    -1,    -1,    -1,   145,   146,   147,   148,   149,   150,
     151,    -1,    -1,    -1,   155,   156,   157,   158,   159,    -1,
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
      -1,   262,   263,   264,   265,   266,   267,    -1,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    21,    22,
      23,    24,    -1,    -1,    27,    -1,    -1,    -1,    31,    32,
      -1,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      -1,    94,    95,    96,    97,    98,    99,   100,   101,    -1,
      -1,   104,   105,    -1,    -1,    -1,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,    -1,    -1,    -1,
     123,    -1,   125,   126,   127,   128,    -1,   130,    -1,    -1,
      -1,   134,   135,   136,   137,   138,    -1,    -1,    -1,    -1,
      -1,    -1,   145,   146,   147,   148,   149,   150,   151,    -1,
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
     263,   264,   265,   266,   267,    -1,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    19,    20,    21,    22,    23,    24,
      -1,    -1,    27,    -1,    -1,    -1,    31,    32,    -1,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    -1,    94,
      95,    96,    97,    98,    99,   100,   101,    -1,    -1,   104,
     105,    -1,    -1,    -1,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,    -1,    -1,    -1,   123,    -1,
     125,   126,   127,   128,    -1,   130,    -1,    -1,    -1,   134,
     135,   136,   137,   138,    -1,    -1,    -1,    -1,    -1,    -1,
     145,   146,   147,   148,   149,   150,   151,    -1,    -1,    -1,
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
     265,   266,   267,    -1,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    19,    20,    21,    22,    23,    24,    -1,    -1,
      27,    -1,    -1,    -1,    31,    32,    -1,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    -1,    94,    95,    96,
      97,    98,    99,   100,   101,    -1,    -1,   104,   105,    -1,
      -1,    -1,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,    -1,    -1,    -1,   123,    -1,   125,   126,
     127,   128,    -1,   130,    -1,    -1,    -1,   134,   135,   136,
     137,   138,    -1,    -1,    -1,    -1,    -1,    -1,   145,   146,
     147,   148,   149,   150,   151,    -1,    -1,    -1,   155,   156,
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
     267,    -1,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      19,    20,    21,    22,    23,    24,    -1,    -1,    27,    -1,
      -1,    -1,    31,    32,    -1,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    -1,    94,    95,    96,    97,    98,
      99,   100,   101,    -1,    -1,   104,   105,    -1,    -1,    -1,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,    -1,    -1,    -1,   123,    -1,   125,   126,   127,   128,
      -1,   130,    -1,    -1,    -1,   134,   135,   136,   137,   138,
      -1,    -1,    -1,    -1,    -1,    -1,   145,   146,   147,   148,
     149,   150,   151,    -1,    -1,    -1,   155,   156,   157,   158,
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
     259,   260,    -1,   262,   263,   264,   265,   266,   267,    -1,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,
      21,    22,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,
      31,    32,    -1,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    94,    95,    96,    97,    98,    99,   100,
     101,    -1,    -1,   104,   105,    -1,    -1,    -1,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,    -1,
      -1,    -1,   123,    -1,   125,   126,   127,   128,    -1,   130,
      -1,    -1,    -1,   134,   135,   136,   137,   138,    -1,    -1,
      -1,    -1,    -1,    -1,   145,   146,   147,   148,   149,   150,
     151,    -1,    -1,    -1,   155,   156,   157,   158,   159,    -1,
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
      -1,   262,   263,   264,   265,   266,   267,    -1,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    21,    22,
      23,    24,    -1,    -1,    27,    -1,    -1,    -1,    31,    32,
      -1,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      -1,    94,    95,    96,    97,    98,    99,   100,   101,    -1,
      -1,   104,   105,    -1,    -1,    -1,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,    -1,    -1,    -1,
     123,    -1,   125,   126,   127,   128,    -1,   130,    -1,    -1,
      -1,   134,   135,   136,   137,   138,    -1,    -1,    -1,    -1,
      -1,    -1,   145,   146,   147,   148,   149,   150,   151,    -1,
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
     263,   264,   265,   266,   267,    -1,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    19,    20,    21,    22,    23,    24,
      -1,    -1,    27,    -1,    -1,    -1,    31,    32,    -1,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    -1,    94,
      95,    96,    97,    98,    99,   100,   101,    -1,    -1,   104,
     105,    -1,    -1,    -1,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,    -1,    -1,    -1,   123,    -1,
     125,   126,   127,   128,    -1,   130,    -1,    -1,    -1,   134,
     135,   136,   137,   138,    -1,    -1,    -1,    -1,    -1,    -1,
     145,   146,   147,   148,   149,   150,   151,    -1,    -1,    -1,
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
     265,   266,   267,    -1,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    19,    20,    21,    22,    23,    24,    -1,    -1,
      27,    -1,    -1,    -1,    31,    32,    -1,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    -1,    94,    95,    96,
      97,    98,    99,   100,   101,    -1,    -1,   104,   105,    -1,
      -1,    -1,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,    -1,    -1,    -1,   123,    -1,   125,   126,
     127,   128,    -1,   130,    -1,    -1,    -1,   134,   135,   136,
     137,   138,    -1,    -1,    -1,    -1,    -1,    -1,   145,   146,
     147,   148,   149,   150,   151,    -1,    -1,    -1,   155,   156,
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
     267,    -1,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      19,    20,    21,    22,    23,    24,    -1,    -1,    27,    -1,
      -1,    -1,    31,    32,    -1,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    -1,    94,    95,    96,    97,    98,
      99,   100,   101,    -1,    -1,   104,   105,    -1,    -1,    -1,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,    -1,    -1,    -1,   123,    -1,   125,   126,   127,   128,
      -1,   130,    -1,    -1,    -1,   134,   135,   136,   137,   138,
      -1,    -1,    -1,    -1,    -1,    -1,   145,   146,   147,   148,
     149,   150,   151,    -1,    -1,    -1,   155,   156,   157,   158,
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
     259,   260,    -1,   262,   263,   264,   265,   266,   267,    -1,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,
      21,    22,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,
      31,    32,    -1,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    94,    95,    96,    97,    98,    99,   100,
     101,    -1,    -1,   104,   105,    -1,    -1,    -1,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,    -1,
      -1,    -1,   123,    -1,   125,   126,   127,   128,    -1,   130,
      -1,    -1,    -1,   134,   135,   136,   137,   138,    -1,    -1,
      -1,    -1,    -1,    -1,   145,   146,   147,   148,   149,   150,
     151,    -1,    -1,    -1,   155,   156,   157,   158,   159,    -1,
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
      -1,   262,   263,   264,   265,   266,   267,    -1,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    21,    22,
      23,    24,    -1,    -1,    27,    -1,    -1,    -1,    31,    32,
      -1,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      -1,    94,    95,    96,    97,    98,    99,   100,   101,    -1,
      -1,   104,   105,    -1,    -1,    -1,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,    -1,    -1,    -1,
     123,    -1,   125,   126,   127,   128,    -1,   130,    -1,    -1,
      -1,   134,   135,   136,   137,   138,    -1,    -1,    -1,    -1,
      -1,    -1,   145,   146,   147,   148,   149,   150,   151,    -1,
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
     263,   264,   265,   266,   267,    -1,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    19,    20,    21,    22,    23,    24,
      -1,    -1,    27,    -1,    -1,    -1,    31,    32,    -1,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    -1,    94,
      95,    96,    97,    98,    99,   100,   101,    -1,    -1,   104,
     105,    -1,    -1,    -1,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,    -1,    -1,    -1,   123,    -1,
     125,   126,   127,   128,    -1,   130,    -1,    -1,    -1,   134,
     135,   136,   137,   138,    -1,    -1,    -1,    -1,    -1,    -1,
     145,   146,   147,   148,   149,   150,   151,    -1,    -1,    -1,
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
     265,   266,   267,    -1,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    19,    20,    21,    22,    23,    24,    -1,    -1,
      27,    -1,    -1,    -1,    31,    32,    -1,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    -1,    94,    95,    96,
      97,    98,    99,   100,   101,    -1,    -1,   104,   105,    -1,
      -1,    -1,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,    -1,    -1,    -1,   123,    -1,   125,   126,
     127,   128,    -1,   130,    -1,    -1,    -1,   134,   135,   136,
     137,   138,    -1,    -1,    -1,    -1,    -1,    -1,   145,   146,
     147,   148,   149,   150,   151,    -1,    -1,    -1,   155,   156,
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
     267,    -1,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      19,    -1,    -1,    -1,    23,    24,    -1,    -1,    27,    -1,
      -1,    -1,    31,    32,    -1,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    56,    57,    58,
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
     259,   260,    -1,   262,   263,   264,   265,   266,   267,    -1,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    -1,
      -1,    -1,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,
      31,    32,    -1,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    60,
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
      -1,   262,   263,   264,   265,   266,   267,    -1,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    23,    24,    -1,    -1,
      27,    -1,    -1,    -1,    31,    32,    -1,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    -1,    94,    95,    96,
      97,    -1,    99,   100,   101,    -1,    -1,   104,   105,    -1,
      -1,    -1,    -1,   110,   111,   112,   113,   114,   115,   116,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,   126,
     127,   128,    -1,   130,    -1,    -1,    -1,   134,   135,   136,
     137,   138,    -1,    -1,    -1,    -1,    -1,    -1,   145,   146,
     147,    -1,   149,   150,   151,    -1,    -1,    -1,    -1,    -1,
      -1,   158,   159,    -1,    -1,    -1,    -1,   164,   165,   166,
     167,   168,   169,   170,   171,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   179,   180,   181,    -1,    -1,    -1,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
      -1,    -1,   209,   210,    -1,    -1,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
      -1,   258,   259,   260,    -1,   262,   263,   264,   265,   266,
     267,    -1,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      23,    24,    -1,    -1,    27,    -1,    -1,    -1,    31,    32,
      -1,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
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
     253,   254,   255,   256,    -1,   258,   259,   260,    -1,   262,
     263,   264,   265,   266,   267,    -1,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,    17,    18,    -1,    -1,
      -1,    -1,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,
      31,    32,    -1,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    60,
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
      -1,    -1,    -1,   194,    -1,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,    -1,    -1,   209,   210,
      -1,    -1,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,    -1,   258,   259,   260,
      -1,   262,   263,   264,   265,   266,   267,    -1,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,    23,    24,
      -1,    -1,    27,    -1,    -1,    -1,    31,    32,    -1,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    -1,    94,
      95,    96,    97,    -1,    99,   100,   101,    -1,    -1,   104,
     105,    -1,    -1,    -1,    -1,   110,   111,   112,   113,   114,
     115,   116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     125,   126,   127,   128,    -1,   130,    -1,    -1,    -1,   134,
     135,   136,   137,   138,    -1,    -1,    -1,    -1,    -1,    -1,
     145,   146,   147,    -1,   149,   150,   151,    -1,    -1,    -1,
     155,    -1,    -1,   158,   159,    -1,    -1,    -1,    -1,   164,
     165,   166,   167,   168,   169,   170,   171,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   179,   180,   181,    -1,    -1,    -1,
     185,   186,   187,   188,    -1,    -1,    -1,   192,    -1,   194,
      -1,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,    -1,    -1,   209,   210,    -1,    -1,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,    -1,   258,   259,   260,    -1,   262,   263,   264,
     265,   266,   267,    -1,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,    23,    24,    -1,    -1,    27,    -1,
      -1,    -1,    31,    32,    -1,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    56,    57,    58,
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
     259,   260,    -1,   262,   263,   264,   265,   266,   267,    -1,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
      23,    24,    -1,    -1,    27,    -1,    -1,    -1,    31,    32,
      -1,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
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
     253,   254,   255,   256,    -1,   258,   259,   260,    -1,   262,
     263,   264,   265,   266,   267,    -1,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,    23,    24,    -1,    -1,
      27,    -1,    -1,    -1,    31,    32,    -1,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    -1,    70,    71,    72,    73,    74,    75,    76,
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
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
      -1,   258,   259,   260,    -1,   262,   263,   264,   265,   266,
     267,    -1,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,
      31,    32,    -1,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    70,
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
     251,   252,   253,   254,   255,   256,    -1,   258,   259,   260,
      -1,   262,   263,   264,   265,   266,   267,    -1,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,    23,    24,
      -1,    -1,    27,    -1,    -1,    -1,    31,    32,    -1,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    -1,    94,
      95,    96,    97,    -1,    99,   100,   101,    -1,    -1,   104,
     105,    -1,    -1,    -1,    -1,   110,   111,   112,   113,   114,
     115,   116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     255,   256,    -1,   258,   259,   260,    -1,   262,   263,   264,
     265,   266,   267,    -1,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,    23,    24,    -1,    -1,    27,    -1,
      -1,    -1,    31,    32,    -1,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    56,    57,    58,
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
     259,   260,    -1,   262,   263,   264,   265,   266,   267,    -1,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
      23,    24,    -1,    -1,    27,    -1,    -1,    -1,    31,    32,
      -1,    34,    35,    36,    -1,    38,    39,    40,    41,    42,
      -1,    -1,    45,    46,    47,    -1,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    -1,    61,    -1,
      -1,    64,    65,    66,    67,    68,    -1,    70,    -1,    72,
      -1,    -1,    75,    76,    77,    78,    79,    80,    81,    82,
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
     233,   234,   235,   236,   237,   238,   239,   240,   241,    -1,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,    -1,   258,   259,   260,    -1,   262,
     263,   264,   265,   266,   267,    -1,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  xquery_parser::yystos_[] =
  {
         0,    11,    19,    20,    21,    22,    23,    24,    27,    31,
      32,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    94,    95,
      96,    97,    98,    99,   100,   101,   104,   105,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   123,
     125,   126,   127,   128,   130,   134,   135,   136,   137,   138,
     145,   146,   147,   148,   149,   150,   151,   155,   156,   157,
     158,   159,   164,   165,   166,   167,   168,   169,   170,   171,
     173,   175,   176,   179,   180,   181,   185,   187,   188,   190,
     191,   192,   194,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   209,   210,   211,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   258,   259,   260,   262,   263,   264,   265,   266,   267,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   324,   326,   327,   328,   329,   330,   331,   332,   333,
     334,   335,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   354,   355,   359,   360,   363,
     366,   369,   370,   372,   377,   378,   379,   380,   384,   393,
     394,   396,   397,   398,   403,   405,   407,   408,   413,   434,
     437,   441,   444,   445,   446,   447,   449,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   495,   496,   497,   511,
     512,   514,   515,   516,   517,   518,   519,   520,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   540,   541,
     542,   543,   548,   549,   550,   551,   552,   553,   556,   560,
     614,   616,   617,   618,    31,    32,    49,   183,   213,   394,
     183,   394,   183,   394,    25,    35,    36,    38,    39,    47,
      57,    58,    64,    66,    75,    79,   110,   111,   112,   159,
     168,   200,   218,   228,   260,   286,   287,   288,   289,   290,
     292,   293,   294,   295,   296,   301,   302,   361,   362,   381,
     382,   385,   386,   387,   388,   159,   152,   155,   152,   155,
     152,   155,   152,    67,    72,   117,   400,   155,   371,   155,
      32,    61,   117,   272,   412,   414,   417,   152,   155,   155,
     155,   117,   117,   152,   155,   155,   155,    94,   152,   219,
     220,   121,   121,   121,   152,   155,    27,    37,    42,    44,
      45,    46,    47,    48,    51,    60,    65,    68,    71,    73,
      74,    76,    90,    91,    97,   104,   113,   114,   134,   137,
     138,   168,   171,   179,   180,   188,   200,   222,   224,   226,
     227,   234,   236,   237,   238,   239,   242,   243,   245,   479,
     616,   617,   121,   121,   121,    37,    43,    44,    60,    62,
      63,    71,    97,   223,   616,   117,   121,   121,   186,   394,
     616,   152,   121,    15,   615,   616,    17,    18,   616,   121,
     121,   121,   471,   152,    28,   212,   214,   223,   225,   155,
     223,   225,   223,   223,   228,   117,   152,   373,   240,   240,
     241,   155,   152,   117,   326,     0,   328,   329,    31,    49,
     331,   332,     1,   189,   325,   189,   325,   136,   141,   106,
     189,   395,    40,    46,    51,    70,   167,   170,   185,   210,
     399,   404,   405,   406,   422,   423,   427,   166,    92,   131,
     139,   140,   142,   150,   154,   156,   161,   178,   201,   202,
     203,   204,   205,   206,   463,   464,   248,   157,   175,   197,
     116,   145,   158,   192,   199,   208,   135,   149,    50,   198,
     100,   101,   157,   175,   462,   152,   468,   471,   190,   191,
     153,   483,   484,   479,   483,   479,   155,   483,   120,   144,
     155,   183,   183,   183,   155,   614,   181,   194,   181,   194,
     165,   181,   617,   616,   168,   200,    47,   386,    47,   616,
     151,   117,    44,    47,    79,   105,   167,   615,   219,   220,
     221,   299,   300,   245,   587,   616,   292,   616,   297,   297,
     299,   300,   303,   286,   294,   362,   111,   382,   385,   615,
     394,   186,   394,    44,    63,   186,   536,   537,   394,   186,
     192,   616,   397,   283,   283,   409,   410,   616,   117,   418,
     117,   186,   389,   390,   152,   391,   394,   159,   614,   112,
     159,   353,   614,   616,   117,   141,   106,   394,    27,   186,
     615,   616,   616,   616,   435,   436,   616,   394,   186,   394,
     394,   538,   616,   394,   152,   152,   394,   186,   192,   616,
     435,   186,    33,   499,   500,   501,   394,     8,   174,    16,
     394,   212,    27,   397,   397,   186,   397,   397,   397,   397,
     229,   554,   555,   616,   374,   397,   397,   394,   415,   416,
     616,   189,   325,   189,   325,     3,   332,   333,   393,   332,
     333,   393,    31,   334,   393,   334,   393,   141,   397,   397,
     396,   117,   167,   169,   169,   397,   397,   446,   447,   449,
     449,   449,   449,   448,   449,   449,   449,    71,   453,   453,
     452,   454,   454,   454,   454,   455,   455,   456,   456,   229,
      94,    94,    94,   183,   394,   471,   471,   394,   484,   186,
     397,   494,   615,   148,   186,   494,    27,   383,   486,   106,
     106,   371,    27,   617,   617,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,   336,   337,   338,    94,   136,
     141,   356,   357,   358,   616,   159,   159,   336,   614,   126,
     131,    54,    57,    99,   250,   263,   265,   276,   277,   278,
     280,   282,   588,   589,   590,   591,   592,   593,   600,   606,
     607,   245,    94,   235,   365,   298,   616,   616,   616,   117,
     131,   183,   183,   186,   186,   183,   106,   186,   106,   186,
     183,   106,    34,    94,    96,   146,   411,   412,   522,   616,
      56,   215,   253,   401,   402,   616,    94,   106,   186,   394,
     186,   615,    96,    44,   615,   614,    96,   141,   522,   616,
     397,   417,   183,   186,   186,   186,   186,   141,   106,   187,
     146,   522,   183,   186,   186,   152,   183,   394,   394,   183,
     106,   186,   106,   186,   187,   616,   500,   501,   129,   195,
     183,   183,   130,   189,    94,   216,   217,   231,    94,   216,
     217,   231,    94,   235,   223,   106,   233,   141,    31,   375,
     394,   186,   183,    45,   106,   332,    31,    31,   189,   325,
     189,   112,   397,   189,   616,   169,   397,   428,   429,   117,
     424,   425,   449,   152,   155,   258,   467,   486,   561,   564,
     565,   566,   567,   568,   572,   574,   576,   577,    47,   151,
     155,   209,   523,   525,   527,   528,   544,   545,   546,   547,
     616,   523,   521,   527,   521,   183,   184,   106,   186,   186,
     106,   186,   147,   164,   147,   164,   136,   152,   392,   371,
     371,   337,   131,   525,   358,   397,   522,   614,   614,   127,
     128,   614,   276,   277,   278,   282,   616,   262,   273,   262,
     273,    27,   285,    96,   112,   155,   594,   597,   588,    37,
      43,    60,    62,    71,    97,   223,   364,   528,   290,   291,
     225,   298,   307,    94,   365,   298,   616,   614,   152,   538,
     539,   616,   538,   539,   117,   126,   523,   117,   397,   146,
     412,   146,    34,   146,   411,   412,   146,   522,   253,    53,
      59,    77,   117,   411,   419,   420,   421,   402,   522,   523,
     390,    94,   183,   196,   131,   352,   614,   159,   131,    96,
     352,   397,   141,   412,   152,   397,   117,   397,   397,   146,
      99,   438,   439,   440,    99,   442,   443,   394,   183,   183,
     152,   538,   538,   397,    33,   501,   129,   195,     9,    10,
     102,   122,   124,   193,   391,   496,   498,   509,   510,   513,
      27,   230,   232,   397,   397,   397,   230,   232,   397,   397,
     397,   397,   397,   397,   117,   397,   397,   117,   376,   106,
     189,   183,   373,   244,   557,   558,   152,   117,   189,   112,
     393,   393,   393,   428,    95,   105,   115,   126,   430,   431,
     432,   433,   106,   616,   106,   394,   561,   568,   152,   284,
     450,   613,    96,   168,   251,   252,   254,   261,   271,   283,
     562,   563,   582,   583,   584,   585,   608,   611,   257,   259,
     569,   587,   266,   573,   609,   246,   247,   269,   578,   579,
     155,   155,   525,   155,   143,   175,   192,   524,   143,   397,
     486,   394,   136,   373,   136,   152,   540,   357,   285,    27,
      96,   112,   155,   601,    27,   594,   365,   524,   225,   225,
     469,   286,   305,   364,   225,   522,   189,   183,   394,   186,
     186,   143,   186,   186,   410,   146,   411,   616,   397,   146,
     397,   126,   397,   146,   412,   146,   397,   146,   117,   117,
     397,   616,   421,    77,   523,   397,   614,   106,   352,   397,
     141,   183,   394,   436,   397,   397,   112,   439,    99,   185,
     117,   523,   112,   443,   183,   183,   394,   186,   186,   131,
     193,   498,     7,   616,   193,   509,   189,   231,   231,   231,
     231,   235,   555,   185,   616,   376,   480,   559,   558,   397,
     416,   614,   127,   128,   432,   433,   433,   429,   105,   426,
     425,   183,   186,   561,   575,   249,   215,   253,   267,   274,
     612,    96,   255,   256,   610,   249,   565,   612,   452,   582,
     566,   146,   281,   570,   571,   610,   285,   581,    78,   580,
     186,   192,   523,   526,   186,   186,   186,   183,   396,    27,
     135,   199,   603,   604,   605,    27,   602,   603,   270,   598,
     595,   596,   597,   169,   616,   256,   365,   469,   183,   397,
     146,   397,   146,   411,   397,   146,   397,   397,   616,   616,
     420,   397,   125,    96,   614,   397,   183,   185,   397,   397,
     616,   185,   117,   185,   183,   501,   616,   193,   501,   616,
     397,   397,   397,   397,   397,   397,   141,   522,   155,   208,
     392,   183,   433,   614,   183,   454,    52,   128,   452,   452,
     268,   275,   285,   586,   586,   567,   152,   279,    94,   186,
     106,   186,   183,   601,   601,   605,   106,   186,    27,   599,
     610,   186,   106,   367,   368,   469,   117,   223,   306,   286,
     169,   397,   397,   146,   397,    53,   397,   352,   397,    94,
     397,   616,   397,    93,   182,   502,   501,   616,   195,   501,
     397,   141,   117,   480,   452,   452,   197,   394,   523,   523,
      94,    27,   264,   597,   106,   433,   522,   616,   117,   223,
     616,   367,   397,   117,   523,   185,     5,   132,   505,   506,
     508,   510,    26,   133,   503,   504,   507,   510,   195,   501,
     195,   397,   616,   452,   183,   523,   368,   433,   304,   616,
     117,   223,   616,   185,   397,    93,   132,   508,   182,   133,
     507,   195,   106,   186,   397,   304,   616,   117,   397,   117,
     392,   292,   304,   616,   616,   305,   397,   305,   106,   186,
     469,   469,   117,   392,   197,   616,   286,   186,   616,   392,
     223,   117,   616,   305,   469
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
     333,   333,   333,   333,   333,   334,   334,   334,   334,   334,
     334,   334,   334,   335,   335,   336,   336,   337,   338,   338,
     338,   338,   338,   338,   338,   338,   338,   338,   339,   339,
     339,   339,   339,   339,   339,   339,   340,   340,   341,   342,
     342,   343,   343,   344,   345,   346,   346,   347,   347,   348,
     348,   348,   348,   349,   350,   351,   351,   351,   351,   352,
     352,   353,   353,   354,   354,   354,   354,   355,   356,   356,
     357,   357,   357,   358,   359,   359,   359,   359,   360,   360,
     360,   361,   361,   362,   362,   362,   362,   362,   362,   362,
     362,   362,   362,   362,   362,   362,   362,   363,   363,   363,
     363,   363,   363,   363,   363,   364,   364,   365,   365,   366,
     366,   367,   367,   368,   368,   368,   368,   369,   369,   369,
     369,   370,   370,   371,   371,   371,   371,   372,   373,   374,
     374,   375,   375,   376,   376,   376,   376,   377,   378,   379,
     380,   380,   381,   381,   382,   382,   383,   383,   384,   384,
     385,   385,   385,   385,   386,   386,   387,   387,   388,   388,
     389,   389,   390,   390,   391,   392,   393,   394,   394,   395,
     395,   396,   396,   397,   397,   397,   397,   397,   397,   397,
     397,   397,   397,   397,   397,   397,   397,   397,   397,   397,
     397,   398,   399,   400,   400,   401,   401,   401,   402,   402,
     403,   403,   404,   405,   405,   405,   406,   406,   406,   406,
     406,   407,   407,   408,   409,   409,   410,   410,   410,   410,
     410,   410,   410,   410,   410,   410,   410,   410,   411,   412,
     413,   414,   414,   415,   415,   416,   417,   417,   417,   417,
     418,   418,   419,   419,   419,   420,   420,   420,   421,   421,
     421,   422,   423,   424,   424,   425,   425,   426,   427,   427,
     428,   428,   429,   429,   430,   430,   430,   430,   430,   430,
     430,   431,   431,   432,   432,   433,   434,   434,   435,   435,
     436,   436,   437,   438,   438,   439,   440,   440,   441,   441,
     442,   442,   443,   443,   444,   445,   445,   446,   446,   447,
     447,   447,   447,   447,   448,   447,   447,   447,   447,   449,
     449,   450,   450,   451,   451,   452,   452,   452,   453,   453,
     453,   453,   453,   454,   454,   454,   455,   455,   455,   456,
     456,   457,   457,   458,   458,   459,   459,   460,   460,   461,
     461,   461,   461,   462,   462,   462,   463,   463,   463,   463,
     463,   463,   464,   464,   464,   465,   465,   465,   465,   466,
     466,   467,   467,   468,   468,   468,   469,   469,   469,   469,
     470,   471,   471,   471,   472,   472,   473,   473,   473,   473,
     474,   474,   475,   475,   475,   475,   475,   475,   475,   476,
     476,   477,   477,   478,   478,   478,   478,   478,   479,   479,
     480,   480,   481,   481,   481,   482,   482,   482,   482,   483,
     483,   484,   485,   485,   485,   485,   485,   485,   485,   485,
     485,   486,   486,   487,   487,   487,   488,   489,   489,   490,
     491,   492,   493,   493,   494,   494,   495,   495,   496,   496,
     496,   497,   497,   497,   497,   497,   497,   498,   498,   499,
     499,   500,   501,   501,   502,   502,   503,   503,   504,   504,
     504,   504,   505,   505,   506,   506,   506,   506,   507,   507,
     508,   508,   509,   509,   509,   509,   510,   510,   510,   510,
     511,   511,   512,   512,   513,   514,   514,   514,   514,   514,
     514,   515,   516,   516,   516,   516,   517,   517,   517,   517,
     518,   519,   520,   520,   520,   520,   521,   521,   522,   523,
     523,   523,   524,   524,   524,   525,   525,   525,   525,   525,
     526,   526,   527,   528,   528,   528,   528,   528,   528,   528,
     528,   528,   529,   530,   530,   530,   531,   532,   533,   533,
     533,   534,   534,   534,   534,   534,   535,   536,   536,   536,
     536,   536,   536,   536,   537,   538,   539,   540,   541,   541,
     542,   543,   544,   544,   545,   546,   546,   547,   548,   548,
     548,   549,   549,   549,   549,   549,   549,   549,   549,   549,
     549,   550,   550,   551,   551,   552,   553,   554,   554,   555,
     556,   557,   557,   558,   558,   558,   558,   559,   559,   560,
     560,   561,   562,   562,   563,   563,   564,   564,   565,   565,
     566,   566,   567,   567,   568,   569,   569,   570,   570,   571,
     572,   572,   572,   573,   573,   574,   575,   575,   576,   577,
     577,   578,   578,   579,   579,   579,   580,   580,   581,   581,
     582,   582,   582,   582,   582,   583,   584,   585,   586,   586,
     586,   587,   587,   588,   588,   588,   588,   588,   588,   588,
     588,   589,   589,   589,   589,   590,   590,   591,   592,   592,
     593,   593,   593,   594,   594,   595,   595,   596,   596,   597,
     598,   598,   599,   599,   600,   600,   600,   601,   601,   602,
     602,   603,   603,   604,   604,   605,   605,   606,   607,   607,
     608,   608,   608,   609,   610,   610,   610,   610,   611,   611,
     612,   612,   613,   614,   615,   615,   616,   616,   616,   616,
     616,   616,   616,   616,   616,   616,   616,   616,   616,   616,
     616,   616,   617,   617,   617,   617,   617,   617,   617,   617,
     617,   617,   617,   617,   617,   617,   617,   617,   617,   617,
     617,   617,   617,   617,   617,   617,   617,   617,   617,   617,
     617,   617,   617,   617,   617,   617,   617,   617,   617,   617,
     617,   617,   617,   617,   617,   617,   617,   617,   617,   617,
     617,   617,   617,   617,   617,   617,   617,   617,   617,   617,
     617,   617,   617,   617,   617,   617,   617,   617,   617,   617,
     617,   617,   617,   617,   617,   617,   617,   617,   617,   617,
     617,   617,   617,   617,   617,   617,   617,   617,   617,   617,
     617,   617,   617,   617,   617,   617,   617,   617,   617,   617,
     617,   617,   617,   617,   617,   617,   617,   617,   617,   617,
     617,   617,   617,   617,   617,   617,   617,   617,   617,   617,
     617,   617,   617,   617,   617,   617,   617,   617,   617,   617,
     617,   617,   617,   617,   617,   617,   617,   617,   617,   617,
     617,   617,   617,   617,   617,   617,   617,   617,   617,   617,
     617,   617,   617,   617,   617,   617,   617,   617,   617,   617,
     617,   617,   617,   617,   617,   617,   617,   617,   617,   617,
     617,   617,   617,   617,   617,   617,   617,   617,   617,   617,
     617,   617,   617,   617,   617,   617,   617,   617,   617,   617,
     617,   617,   617,   617,   617,   617,   617,   617,   617,   617,
     617,   617,   617,   618,   618
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  xquery_parser::yyr2_[] =
  {
         0,     2,     1,     2,     2,     1,     2,     1,     2,     4,
       6,     3,     3,     5,     1,     3,     3,     5,     5,     1,
       3,     3,     5,     6,     1,     3,     3,     1,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     1,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     3,
       3,     5,     5,     4,     3,     3,     3,     5,     5,     5,
       5,     5,     5,     4,     3,     3,     4,     5,     6,     1,
       3,     3,     3,     3,     6,     5,     8,     4,     3,     1,
       1,     1,     2,     2,     4,     5,     5,     6,     3,     2,
       4,     1,     2,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     2,     1,     2,     2,     2,     3,     4,     5,
       6,     4,     5,     6,     7,     1,     2,     3,     3,     8,
       9,     1,     3,     1,     2,     2,     3,    11,    14,    13,
      22,     3,     3,     2,     3,     4,     5,     2,     4,     3,
       0,     3,     2,     2,     3,     4,     5,     5,     3,     5,
       2,     2,     1,     2,     1,     4,     1,     3,     2,     3,
       1,     2,     1,     1,     4,     4,     5,     5,     7,     5,
       1,     3,     2,     3,     3,     3,     1,     1,     2,     1,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     1,     1,     2,     4,     3,
       5,     4,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     3,     1,     4,     3,     5,     4,     6,
       4,     6,     5,     7,     4,     5,     5,     6,     3,     3,
       2,     1,     3,     1,     4,     1,     4,     5,     3,     6,
       4,     5,     1,     2,     3,     1,     2,     1,     6,     3,
       3,     2,     3,     1,     3,     2,     3,     2,     3,     4,
       1,     3,     1,     2,     1,     1,     1,     2,     2,     2,
       3,     1,     1,     2,     2,     2,     5,     5,     1,     4,
       3,     4,     8,     1,     2,     3,     2,     3,     8,    10,
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
       1,     1,     1,     1,     1,     1,     2,     3,     4,     1,
       2,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     3,     1,
       4,     4,     3,     4,     1,     3,     1,     1,     1,     1,
       1,     4,     5,     8,     9,     9,    10,     1,     2,     1,
       2,     6,     0,     1,     3,     3,     0,     1,     1,     1,
       2,     2,     0,     1,     1,     1,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     2,     3,     3,     2,     1,     1,     1,     1,     1,
       1,     4,     2,     3,     6,     7,     2,     3,     6,     7,
       4,     4,     2,     3,     6,     7,     1,     2,     2,     1,
       2,     3,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     4,     4,     3,     3,     3,     4,
       4,     3,     4,     6,     4,     6,     4,     3,     4,     6,
       6,     4,     6,     6,     4,     1,     2,     1,     1,     1,
       3,     3,     1,     1,     4,     5,     6,     3,     3,     3,
       3,     5,     7,     7,     5,     5,     5,     7,     7,     5,
       5,     3,     3,     5,     7,     5,     7,     1,     4,     3,
       5,     1,     2,     3,     7,    10,    13,     1,     3,     7,
       4,     2,     0,     1,     1,     2,     1,     3,     1,     3,
       1,     4,     1,     2,     3,     0,     1,     0,     1,     4,
       2,     3,     1,     0,     1,     4,     0,     1,     2,     1,
       3,     0,     1,     2,     2,     1,     0,     1,     0,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     1,     1,
       1,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     1,     1,     2,     2,     3,     1,     2,
       2,     5,     2,     1,     1,     0,     1,     1,     3,     4,
       0,     2,     0,     2,     4,     4,     3,     2,     3,     1,
       3,     0,     1,     1,     2,     2,     2,     2,     1,     2,
       2,     2,     2,     3,     2,     3,     3,     4,     2,     2,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
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
       1,     1,     1,     3,     1
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
  "\"'&entity;'\"", "\"'comment literal'\"", "\"'pi <NCName {>'\"",
  "\"'NCName_sval'\"", "\"'pragma literal'\"", "\"'QName #)'\"",
  "\"'EQName #)'\"", "\"'*:QName'\"", "\"'element QName {'\"",
  "\"'attribute QName {'\"", "\"'processing-instruction NCName {'\"",
  "\"'QName'\"", "\"'EQName'\"", "\"'%QName'\"",
  "\"'quote attribute content'\"", "\"'STRING'\"", "\"'XML comment'\"",
  "\"'URI'\"", "\"'NCName'\"", "\"'declare'\"", "\"'module'\"",
  "\"'<blank>'\"", "\"'allowing'\"", "\"'base-uri'\"",
  "\"'boundary-space'\"", "\"'comment'\"", "\"'construction'\"",
  "\"'copy-namespaces'\"", "\"'count'\"", "\"'deterministic'\"",
  "\"'document'\"", "\"'document-node'\"", "\"'element'\"", "\"'eval'\"",
  "\"'for'\"", "\"'function'\"", "\"'if'\"", "\"'import'\"",
  "\"'instance'\"", "\"'let'\"", "\"'most'\"", "\"'next'\"", "\"'no'\"",
  "\"'nondeterministic'\"", "\"'only'\"", "\"'option'\"", "\"'ordering'\"",
  "\"'previous'\"", "\"'processing-instruction'\"", "\"'schema'\"",
  "\"'schema-attribute'\"", "\"'schema-element'\"", "\"'sequential'\"",
  "\"'set'\"", "\"'simple'\"", "\"'sliding'\"", "\"'some'\"",
  "\"'space'\"", "\"'stable'\"", "\"'text'\"", "\"'tumbling'\"",
  "\"'switch'\"", "\"'typeswitch'\"", "\"'updating'\"", "\"'validate'\"",
  "\"'when'\"", "\"'word'\"", "\"'decimal-format'\"",
  "\"'decimal-separator'\"", "\"'grouping-separator'\"", "\"'infinity'\"",
  "\"'minus-sign'\"", "\"'NaN'\"", "\"'percent'\"", "\"'per-mille'\"",
  "\"'zero-digit'\"", "\"'digit'\"", "\"'pattern-separator'\"",
  "\"'ancestor'\"", "\"'ancestor-or-self'\"", "\"'and'\"", "\"'''\"",
  "\"'as'\"", "\"'ascending'\"", "\"'at'\"", "\"'attribute'\"", "\"'@'\"",
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
  "\"'copy'\"", "\"'with'\"", "\"'block'\"", "\"'break'\"",
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
  "SIND_DeclList", "VFO_DeclList", "SIND_Decl", "VFO_Decl",
  "DecimalFormatDecl", "DecimalFormatParamList", "DecimalFormatParam",
  "DecimalFormatParamName", "Setter", "Import", "NamespaceDecl",
  "BoundarySpaceDecl", "DefaultNamespaceDecl", "OptionDecl",
  "FTOptionDecl", "OrderingModeDecl", "EmptyOrderDecl",
  "CopyNamespacesDecl", "DefaultCollationDecl", "BaseURIDecl",
  "SchemaImport", "URILiteralList", "SchemaPrefix", "ModuleImport",
  "CtxItemDecl", "CtxItemDecl2", "CtxItemDecl3", "CtxItemDecl4",
  "VarNameAndType", "VarDecl", "DeclPropertyList", "DeclProperty",
  "CollectionDecl", "CollectionTypeDecl", "NodeModifier", "IndexDecl",
  "IndexKeyList", "IndexKeySpec", "IntegrityConstraintDecl",
  "ConstructionDecl", "FunctionSig", "BlockExpr", "Block", "BlockDecls",
  "BlockVarDeclList", "BlockVarDecl", "AssignExpr", "ExitExpr",
  "WhileExpr", "FlowCtlStatement", "AnnotationList", "Annotation",
  "AnnotationLiteralList", "FunctionDecl", "FunctionDecl2",
  "FunctionDeclSimple", "FunctionDeclSequential", "FunctionDeclUpdating",
  "ParamList", "Param", "EnclosedExpr", "BracedExpr", "QueryBody", "Expr",
  "ApplyExpr", "ConcatExpr", "ExprSingle", "FLWORExpr", "ReturnExpr",
  "WindowType", "FLWORWinCondType", "FLWORWinCond", "WindowClause",
  "CountClause", "ForLetWinClause", "FLWORClause", "FLWORClauseList",
  "ForClause", "VarInDeclList", "VarInDecl", "PositionalVar", "FTScoreVar",
  "LetClause", "VarGetsDeclList", "EvalVarDeclList", "EvalVarDecl",
  "VarGetsDecl", "WindowVarDecl", "WindowVars", "WindowVars3",
  "WindowVars2", "WhereClause", "GroupByClause", "GroupSpecList",
  "GroupSpec", "GroupCollationSpec", "OrderByClause", "OrderSpecList",
  "OrderSpec", "OrderModifier", "OrderDirSpec", "OrderEmptySpec",
  "OrderCollationSpec", "QuantifiedExpr", "QVarInDeclList", "QVarInDecl",
  "SwitchExpr", "SwitchCaseClauseList", "SwitchCaseClause",
  "SwitchCaseOperandList", "TypeswitchExpr", "CaseClauseList",
  "CaseClause", "IfExpr", "OrExpr", "AndExpr", "ComparisonExpr", "$@1",
  "FTContainsExpr", "opt_FTIgnoreOption", "RangeExpr", "AdditiveExpr",
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
  "CatchListExpr", "CatchExpr", "NameTestList", "EvalExpr", "FTSelection",
  "opt_FTPosFilter_list", "FTPosFilter_list", "FTOr", "FTAnd", "FTMildNot",
  "FTUnaryNot", "FTPrimaryWithOptions", "opt_FTMatchOptions",
  "opt_FTWeight", "FTWeight", "FTPrimary", "opt_FTTimes",
  "FTExtensionSelection", "opt_FTSelection", "FTWords", "FTWordsValue",
  "opt_FTAnyallOption", "FTAnyallOption", "opt_word", "opt_words",
  "FTPosFilter", "FTOrder", "FTWindow", "FTDistance", "FTUnit",
  "FTMatchOptions", "FTMatchOption", "FTCaseOption", "FTDiacriticsOption",
  "FTExtensionOption", "FTStemOption", "FTThesaurusOption",
  "FTThesaurusID_or_default", "opt_FTThesaurus_list", "FTThesaurus_list",
  "FTThesaurusID", "opt_relationship", "opt_levels", "FTStopWordOption",
  "FTStopWords", "STRING_LITERAL_list", "opt_FTStopWordsInclExcl_list",
  "FTStopWordsInclExcl_list", "FTStopWordsInclExcl", "FTLanguageOption",
  "FTWildCardOption", "FTContent", "FTTimes", "FTRange", "FTScope",
  "FTBigUnit", "FTIgnoreOption", "URI_LITERAL", "NCNAME", "QNAME",
  "FUNCTION_NAME", "EQNAME", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const xquery_parser::rhs_number_type
  xquery_parser::yyrhs_[] =
  {
       324,     0,    -1,   326,    -1,   309,   326,    -1,     1,     3,
      -1,   328,    -1,   327,   328,    -1,   329,    -1,   327,   329,
      -1,   213,   214,    27,   189,    -1,   213,   214,    27,   130,
      27,   189,    -1,   331,   189,   393,    -1,   332,   189,   393,
      -1,   331,   189,   332,   189,   393,    -1,   393,    -1,   331,
     325,   393,    -1,   332,   325,   393,    -1,   331,   189,   332,
     325,   393,    -1,   331,   325,   332,   189,   393,    -1,   330,
      -1,   330,   331,   189,    -1,   330,   332,   189,    -1,   330,
     331,   189,   332,   189,    -1,    32,   159,   615,   131,   614,
     189,    -1,   333,    -1,   331,   189,   333,    -1,   331,   325,
     333,    -1,   334,    -1,   332,   189,   334,    -1,   332,   325,
     334,    -1,   339,    -1,   340,    -1,   341,    -1,   343,    -1,
     345,    -1,   360,    -1,   363,    -1,   355,    -1,   335,    -1,
     384,    -1,   366,    -1,   369,    -1,   344,    -1,    31,   112,
      79,   336,    -1,    31,    79,   616,   336,    -1,   337,    -1,
     336,   337,    -1,   338,   131,   540,    -1,    80,    -1,    88,
      -1,    81,    -1,    82,    -1,    83,    -1,    84,    -1,    89,
      -1,    85,    -1,    86,    -1,    87,    -1,   342,    -1,   349,
      -1,   350,    -1,   370,    -1,   346,    -1,   347,    -1,   348,
      -1,   548,    -1,   351,    -1,   354,    -1,    31,   159,   615,
     131,   614,    -1,    31,    36,   181,    -1,    31,    36,   194,
      -1,    31,   112,    44,   159,   614,    -1,    31,   112,    47,
     159,   614,    -1,    31,    57,   616,    27,    -1,    31,   260,
     587,    -1,    31,    58,   168,    -1,    31,    58,   200,    -1,
      31,   112,   167,   126,   127,    -1,    31,   112,   167,   126,
     128,    -1,    31,    39,   181,   106,   147,    -1,    31,    39,
     181,   106,   164,    -1,    31,    39,   165,   106,   147,    -1,
      31,    39,   165,   106,   164,    -1,    31,   112,   105,   614,
      -1,    31,    35,   614,    -1,    49,    61,   614,    -1,    49,
      61,   353,   614,    -1,    49,    61,   614,    96,   352,    -1,
      49,    61,   353,   614,    96,   352,    -1,   614,    -1,   352,
     106,   614,    -1,   159,   615,   131,    -1,   112,    44,   159,
      -1,    49,    32,   614,    -1,    49,    32,   159,   615,   131,
     614,    -1,    49,    32,   614,    96,   352,    -1,    49,    32,
     159,   615,   131,   614,    96,   352,    -1,    31,   110,   151,
     356,    -1,    94,   525,   357,    -1,   357,    -1,   358,    -1,
     136,    -1,   136,   358,    -1,   141,   397,    -1,    31,   111,
     117,   616,    -1,    31,   111,   117,   616,   522,    -1,    31,
     381,   111,   117,   616,    -1,    31,   381,   111,   117,   616,
     522,    -1,   359,   141,   397,    -1,   359,   136,    -1,   359,
     136,   141,   397,    -1,   362,    -1,   361,   362,    -1,   287,
      -1,   288,    -1,   289,    -1,   290,    -1,   168,    -1,   200,
      -1,   228,   300,    -1,   228,   299,    -1,   301,   300,    -1,
     301,   299,    -1,   292,    -1,   293,   292,    -1,   296,   297,
      -1,   295,   297,    -1,    31,   286,   616,    -1,    31,   286,
     616,   365,    -1,    31,   286,   616,    94,   364,    -1,    31,
     286,   616,    94,   364,   365,    -1,    31,   361,   286,   616,
      -1,    31,   361,   286,   616,   365,    -1,    31,   361,   286,
     616,    94,   364,    -1,    31,   361,   286,   616,    94,   364,
     365,    -1,   528,    -1,   528,   524,    -1,   235,   291,   225,
      -1,   235,   290,   225,    -1,    31,   294,   616,   298,   225,
     469,   169,   367,    -1,    31,   361,   294,   616,   298,   225,
     469,   169,   367,    -1,   368,    -1,   367,   106,   368,    -1,
     469,    -1,   469,   522,    -1,   469,   433,    -1,   469,   522,
     433,    -1,    31,   302,   303,   616,   298,   286,   616,   117,
     616,   304,   397,    -1,    31,   302,   303,   616,   298,   286,
     616,   223,   117,   616,   304,   292,   305,   469,    -1,    31,
     302,   303,   616,   298,   286,   616,   306,   223,   117,   616,
     304,   397,    -1,    31,   302,   303,   616,   307,   305,   256,
     286,   616,   223,   117,   616,   305,   469,   197,   286,   616,
     223,   117,   616,   305,   469,    -1,    31,    38,   181,    -1,
      31,    38,   194,    -1,   155,   186,    -1,   155,   389,   186,
      -1,   155,   186,    94,   523,    -1,   155,   389,   186,    94,
     523,    -1,   236,   373,    -1,   152,   374,   394,   183,    -1,
     374,   375,   189,    -1,    -1,   375,   106,   376,    -1,    31,
     376,    -1,   117,   616,    -1,   117,   616,   522,    -1,   117,
     616,   141,   397,    -1,   117,   616,   522,   141,   397,    -1,
      65,   117,   616,   141,   397,    -1,   239,   241,   397,    -1,
     242,   155,   397,   186,   373,    -1,   237,   240,    -1,   238,
     240,    -1,   382,    -1,   381,   382,    -1,    25,    -1,    25,
     155,   383,   186,    -1,   486,    -1,   383,   106,   486,    -1,
      31,   385,    -1,    31,   381,   385,    -1,   386,    -1,    66,
     386,    -1,   388,    -1,   387,    -1,    47,   617,   371,   392,
      -1,    47,   617,   371,   136,    -1,    64,    47,   617,   371,
     373,    -1,    64,    47,   617,   371,   136,    -1,    75,    47,
     617,   371,   152,   396,   183,    -1,    75,    47,   617,   371,
     136,    -1,   390,    -1,   389,   106,   390,    -1,   117,   616,
      -1,   117,   616,   522,    -1,   152,   394,   183,    -1,   152,
     394,   183,    -1,   394,    -1,   396,    -1,   396,   395,    -1,
     189,    -1,   395,   396,   189,    -1,   397,    -1,   396,   106,
     397,    -1,   398,    -1,   434,    -1,   437,    -1,   441,    -1,
     444,    -1,   445,    -1,   549,    -1,   550,    -1,   552,    -1,
     551,    -1,   553,    -1,   556,    -1,   560,    -1,   378,    -1,
     379,    -1,   380,    -1,   377,    -1,   372,    -1,   407,   399,
      -1,   185,   397,    -1,    67,   283,    -1,    72,   283,    -1,
     215,    -1,   253,    -1,    56,   253,    -1,   401,   419,    77,
     397,    -1,   401,    77,   397,    -1,    46,   400,   418,   402,
     402,    -1,    46,   400,   418,   402,    -1,    40,   117,   616,
      -1,   408,    -1,   413,    -1,   403,    -1,   405,    -1,   422,
      -1,   427,    -1,   423,    -1,   404,    -1,   405,    -1,   407,
     406,    -1,    46,   117,   409,    -1,   410,    -1,   409,   106,
     117,   410,    -1,   616,   146,   397,    -1,   616,    34,   126,
     146,   397,    -1,   616,   522,   146,   397,    -1,   616,   522,
      34,   126,   146,   397,    -1,   616,   411,   146,   397,    -1,
     616,    34,   126,   411,   146,   397,    -1,   616,   522,   411,
     146,   397,    -1,   616,   522,    34,   126,   411,   146,   397,
      -1,   616,   412,   146,   397,    -1,   616,   522,   412,   146,
     397,    -1,   616,   411,   412,   146,   397,    -1,   616,   522,
     411,   412,   146,   397,    -1,    96,   117,   616,    -1,   272,
     117,   616,    -1,    51,   414,    -1,   417,    -1,   414,   106,
     417,    -1,   416,    -1,   415,   106,   117,   416,    -1,   616,
      -1,   117,   616,   141,   397,    -1,   117,   616,   522,   141,
     397,    -1,   412,   141,   397,    -1,   117,   616,   522,   412,
     141,   397,    -1,   117,   616,   146,   397,    -1,   117,   616,
     522,   146,   397,    -1,   420,    -1,   117,   616,    -1,   117,
     616,   420,    -1,   411,    -1,   411,   421,    -1,   421,    -1,
      59,   117,   616,    53,   117,   616,    -1,    53,   117,   616,
      -1,    59,   117,   616,    -1,   210,   397,    -1,   170,   169,
     424,    -1,   425,    -1,   424,   106,   425,    -1,   117,   616,
      -1,   117,   616,   426,    -1,   105,   614,    -1,   167,   169,
     428,    -1,    70,   167,   169,   428,    -1,   429,    -1,   428,
     106,   429,    -1,   397,    -1,   397,   430,    -1,   431,    -1,
     432,    -1,   433,    -1,   431,   432,    -1,   431,   433,    -1,
     432,   433,    -1,   431,   432,   433,    -1,    95,    -1,   115,
      -1,   126,   127,    -1,   126,   128,    -1,   105,   614,    -1,
      68,   117,   435,   187,   397,    -1,   134,   117,   435,   187,
     397,    -1,   436,    -1,   435,   106,   117,   436,    -1,   616,
     146,   397,    -1,   616,   522,   146,   397,    -1,    73,   155,
     394,   186,   438,   112,   185,   397,    -1,   439,    -1,   438,
     439,    -1,   440,   185,   397,    -1,    99,   397,    -1,   440,
      99,   397,    -1,    74,   155,   394,   186,   442,   112,   185,
     397,    -1,    74,   155,   394,   186,   442,   112,   117,   616,
     185,   397,    -1,   443,    -1,   442,   443,    -1,    99,   523,
     185,   397,    -1,    99,   117,   616,    94,   523,   185,   397,
      -1,    48,   155,   394,   186,   196,   397,   125,   397,    -1,
     446,    -1,   445,   166,   446,    -1,   447,    -1,   446,    92,
     447,    -1,   449,    -1,   449,   463,   449,    -1,   449,   464,
     449,    -1,   449,   131,   449,    -1,   449,   161,   449,    -1,
      -1,   449,   156,   448,   449,    -1,   449,   154,   449,    -1,
     449,   142,   449,    -1,   449,   140,   449,    -1,   451,    -1,
     451,   248,    71,   561,   450,    -1,    -1,   613,    -1,   452,
      -1,   452,   197,   452,    -1,   453,    -1,   452,   175,   453,
      -1,   452,   157,   453,    -1,   454,    -1,   453,   192,   454,
      -1,   453,   116,   454,    -1,   453,   145,   454,    -1,   453,
     158,   454,    -1,   455,    -1,   454,   199,   455,    -1,   454,
     208,   455,    -1,   456,    -1,   455,   149,   456,    -1,   455,
     135,   456,    -1,   457,    -1,   457,    50,   229,   523,    -1,
     458,    -1,   458,   198,    94,   523,    -1,   459,    -1,   459,
     100,    94,   521,    -1,   460,    -1,   460,   101,    94,   521,
      -1,   462,    -1,   461,   462,    -1,   175,    -1,   157,    -1,
     461,   175,    -1,   461,   157,    -1,   465,    -1,   469,    -1,
     466,    -1,   201,    -1,   206,    -1,   205,    -1,   204,    -1,
     203,    -1,   202,    -1,   150,    -1,   178,    -1,   139,    -1,
      76,   152,   394,   183,    -1,    76,   220,   152,   394,   183,
      -1,    76,   219,   152,   394,   183,    -1,    76,    94,   538,
     152,   394,   183,    -1,   467,   152,   183,    -1,   467,   152,
     394,   183,    -1,   468,    -1,   467,   468,    -1,   176,   616,
      16,    -1,   176,    17,    -1,   176,    18,    -1,   470,    -1,
     470,   471,    -1,   191,   471,    -1,   471,    -1,   190,    -1,
     472,    -1,   472,   190,   471,    -1,   472,   191,   471,    -1,
     473,    -1,   482,    -1,   474,    -1,   474,   483,    -1,   477,
      -1,   477,   483,    -1,   475,   479,    -1,   476,    -1,   104,
     121,    -1,   113,   121,    -1,    97,   121,    -1,   188,   121,
      -1,   114,   121,    -1,   138,   121,    -1,   137,   121,    -1,
     479,    -1,    98,   479,    -1,   478,   479,    -1,   119,    -1,
     171,   121,    -1,    90,   121,    -1,   180,   121,    -1,   179,
     121,    -1,    91,   121,    -1,   528,    -1,   480,    -1,   616,
      -1,   481,    -1,   192,    -1,    11,    -1,    19,    -1,   485,
      -1,   482,   483,    -1,   482,   155,   186,    -1,   482,   155,
     494,   186,    -1,   484,    -1,   483,   484,    -1,   153,   394,
     184,    -1,   486,    -1,   488,    -1,   489,    -1,   490,    -1,
     493,    -1,   495,    -1,   491,    -1,   492,    -1,   541,    -1,
     487,    -1,   540,    -1,   109,    -1,   148,    -1,   123,    -1,
     117,   616,    -1,   155,   186,    -1,   155,   394,   186,    -1,
     118,    -1,   168,   152,   394,   183,    -1,   200,   152,   394,
     183,    -1,   617,   155,   186,    -1,   617,   155,   494,   186,
      -1,   397,    -1,   494,   106,   397,    -1,   496,    -1,   514,
      -1,   497,    -1,   511,    -1,   512,    -1,   156,   616,   501,
     129,    -1,   156,   616,   499,   501,   129,    -1,   156,   616,
     501,   195,   193,   616,   501,   195,    -1,   156,   616,   501,
     195,   498,   193,   616,   501,   195,    -1,   156,   616,   499,
     501,   195,   193,   616,   501,   195,    -1,   156,   616,   499,
     501,   195,   498,   193,   616,   501,   195,    -1,   509,    -1,
     498,   509,    -1,   500,    -1,   499,   500,    -1,    33,   616,
     501,   131,   501,   502,    -1,    -1,    33,    -1,   182,   503,
     182,    -1,    93,   505,    93,    -1,    -1,   504,    -1,   133,
      -1,   507,    -1,   504,   133,    -1,   504,   507,    -1,    -1,
     506,    -1,   132,    -1,   508,    -1,   506,   132,    -1,   506,
     508,    -1,    26,    -1,   510,    -1,     5,    -1,   510,    -1,
     496,    -1,    10,    -1,   513,    -1,   510,    -1,     9,    -1,
     122,    -1,   124,    -1,   391,    -1,   211,    28,   212,    -1,
     211,   212,    -1,   173,   615,   174,    -1,   173,   615,     8,
      -1,   102,     7,    -1,   515,    -1,   516,    -1,   517,    -1,
     518,    -1,   519,    -1,   520,    -1,    42,   152,   394,   183,
      -1,    20,   183,    -1,    20,   394,   183,    -1,    44,   152,
     394,   183,   152,   183,    -1,    44,   152,   394,   183,   152,
     394,   183,    -1,    21,   183,    -1,    21,   394,   183,    -1,
      97,   152,   394,   183,   152,   183,    -1,    97,   152,   394,
     183,   152,   394,   183,    -1,    71,   152,   394,   183,    -1,
      37,   152,   394,   183,    -1,    22,   183,    -1,    22,   394,
     183,    -1,    60,   152,   394,   183,   152,   183,    -1,    60,
     152,   394,   183,   152,   394,   183,    -1,   527,    -1,   527,
     143,    -1,    94,   523,    -1,   525,    -1,   525,   524,    -1,
     209,   155,   186,    -1,   143,    -1,   192,    -1,   175,    -1,
     527,    -1,   528,    -1,   151,   155,   186,    -1,   544,    -1,
     547,    -1,   523,    -1,   526,   106,   523,    -1,   616,    -1,
     530,    -1,   536,    -1,   534,    -1,   537,    -1,   535,    -1,
     533,    -1,   532,    -1,   531,    -1,   529,    -1,   223,   155,
     186,    -1,    43,   155,   186,    -1,    43,   155,   536,   186,
      -1,    43,   155,   537,   186,    -1,    71,   155,   186,    -1,
      37,   155,   186,    -1,    60,   155,   186,    -1,    60,   155,
     615,   186,    -1,    60,   155,    27,   186,    -1,    97,   155,
     186,    -1,    97,   155,   616,   186,    -1,    97,   155,   616,
     106,   538,   186,    -1,    97,   155,   192,   186,    -1,    97,
     155,   192,   106,   538,   186,    -1,    62,   155,   616,   186,
      -1,    44,   155,   186,    -1,    44,   155,   616,   186,    -1,
      44,   155,   616,   106,   538,   186,    -1,    44,   155,   616,
     106,   539,   186,    -1,    44,   155,   192,   186,    -1,    44,
     155,   192,   106,   538,   186,    -1,    44,   155,   192,   106,
     539,   186,    -1,    63,   155,   616,   186,    -1,   616,    -1,
     616,   143,    -1,    27,    -1,   542,    -1,   543,    -1,   616,
     144,   148,    -1,    47,   371,   391,    -1,   545,    -1,   546,
      -1,    47,   155,   192,   186,    -1,    47,   155,   186,    94,
     523,    -1,    47,   155,   526,   186,    94,   523,    -1,   155,
     525,   186,    -1,    31,   218,   219,    -1,    31,   218,   220,
      -1,    31,   218,   221,    -1,   224,   223,   397,   231,   397,
      -1,   224,   223,   397,    94,   230,   231,   397,    -1,   224,
     223,   397,    94,   232,   231,   397,    -1,   224,   223,   397,
     216,   397,    -1,   224,   223,   397,   217,   397,    -1,   224,
     225,   397,   231,   397,    -1,   224,   225,   397,    94,   230,
     231,   397,    -1,   224,   225,   397,    94,   232,   231,   397,
      -1,   224,   225,   397,   216,   397,    -1,   224,   225,   397,
     217,   397,    -1,   222,   223,   397,    -1,   222,   225,   397,
      -1,   227,   223,   397,   235,   397,    -1,   227,   228,   229,
     223,   397,   235,   397,    -1,   226,   223,   397,    94,   397,
      -1,   234,   117,   554,   233,   397,   185,   397,    -1,   555,
      -1,   554,   106,   117,   555,    -1,   616,   141,   397,    -1,
     243,   152,   394,   183,   557,    -1,   558,    -1,   557,   558,
      -1,   244,   559,   392,    -1,   244,   559,   155,   117,   616,
     186,   392,    -1,   244,   559,   155,   117,   616,   106,   117,
     616,   186,   392,    -1,   244,   559,   155,   117,   616,   106,
     117,   616,   106,   117,   616,   186,   392,    -1,   480,    -1,
     559,   208,   480,    -1,   245,   117,   415,    45,   152,   397,
     183,    -1,    45,   152,   397,   183,    -1,   564,   562,    -1,
      -1,   563,    -1,   582,    -1,   563,   582,    -1,   565,    -1,
     564,   261,   565,    -1,   566,    -1,   565,   257,   566,    -1,
     567,    -1,   566,   259,   146,   567,    -1,   568,    -1,   258,
     568,    -1,   572,   569,   570,    -1,    -1,   587,    -1,    -1,
     571,    -1,   281,   152,   394,   183,    -1,   576,   573,    -1,
     155,   561,   186,    -1,   574,    -1,    -1,   609,    -1,   467,
     152,   575,   183,    -1,    -1,   561,    -1,   577,   578,    -1,
     486,    -1,   152,   394,   183,    -1,    -1,   579,    -1,   247,
     580,    -1,   246,   581,    -1,   269,    -1,    -1,    78,    -1,
      -1,   285,    -1,   583,    -1,   584,    -1,   585,    -1,   611,
      -1,   608,    -1,   168,    -1,   283,   452,   586,    -1,   252,
     610,   586,    -1,   285,    -1,   275,    -1,   268,    -1,   245,
     588,    -1,   587,   245,   588,    -1,   589,    -1,   590,    -1,
     591,    -1,   606,    -1,   592,    -1,   600,    -1,   593,    -1,
     607,    -1,    99,   273,    -1,    99,   262,    -1,   265,    -1,
     280,    -1,   250,   273,    -1,   250,   262,    -1,    57,   616,
      27,    -1,   276,    -1,    54,   276,    -1,   278,   594,    -1,
     278,   155,   594,   595,   186,    -1,    54,   278,    -1,   597,
      -1,   112,    -1,    -1,   596,    -1,   597,    -1,   596,   106,
     597,    -1,    96,    27,   598,   599,    -1,    -1,   270,    27,
      -1,    -1,   610,   264,    -1,   277,   285,   601,   603,    -1,
     277,   285,   112,   603,    -1,    54,   277,   285,    -1,    96,
      27,    -1,   155,   602,   186,    -1,    27,    -1,   602,   106,
      27,    -1,    -1,   604,    -1,   605,    -1,   604,   605,    -1,
     199,   601,    -1,   135,   601,    -1,   263,    27,    -1,   282,
      -1,    54,   282,    -1,    96,   215,    -1,    96,   253,    -1,
     254,   249,    -1,   266,   610,   279,    -1,   255,   452,    -1,
      96,   128,   452,    -1,    96,    52,   452,    -1,   256,   452,
     197,   452,    -1,   271,   612,    -1,   251,   612,    -1,   274,
      -1,   267,    -1,   284,   249,   454,    -1,    27,    -1,    15,
      -1,   616,    -1,   617,    -1,    97,    -1,    37,    -1,    43,
      -1,    44,    -1,   151,    -1,    48,    -1,   223,    -1,    60,
      -1,    62,    -1,    63,    -1,    71,    -1,    74,    -1,    73,
      -1,   209,    -1,   242,    -1,   618,    -1,    23,    -1,   213,
      -1,   126,    -1,    36,    -1,   260,    -1,    35,    -1,   220,
      -1,   219,    -1,   145,    -1,    42,    -1,   258,    -1,   259,
      -1,   273,    -1,   262,    -1,   250,    -1,   284,    -1,   276,
      -1,   278,    -1,   277,    -1,   282,    -1,   254,    -1,   249,
      -1,    78,    -1,   215,    -1,   253,    -1,    52,    -1,   221,
      -1,   234,    -1,   301,    -1,   228,    -1,   201,    -1,   206,
      -1,   205,    -1,   204,    -1,   203,    -1,   202,    -1,    96,
      -1,   110,    -1,   111,    -1,   185,    -1,    46,    -1,    34,
      -1,    67,    -1,    72,    -1,    59,    -1,    53,    -1,    56,
      -1,    77,    -1,    40,    -1,   146,    -1,    51,    -1,   210,
      -1,   169,    -1,   170,    -1,   167,    -1,    70,    -1,    95,
      -1,   115,    -1,   127,    -1,   128,    -1,   105,    -1,    68,
      -1,   134,    -1,   187,    -1,    99,    -1,    94,    -1,   196,
      -1,   125,    -1,   166,    -1,    92,    -1,    50,    -1,   229,
      -1,   100,    -1,   197,    -1,   116,    -1,   158,    -1,   199,
      -1,   149,    -1,   135,    -1,    76,    -1,   101,    -1,   198,
      -1,   150,    -1,   181,    -1,   194,    -1,   159,    -1,   136,
      -1,   130,    -1,   165,    -1,   147,    -1,   164,    -1,    31,
      -1,    38,    -1,    58,    -1,   112,    -1,    39,    -1,    57,
      -1,   214,    -1,    49,    -1,    61,    -1,    32,    -1,    47,
      -1,   272,    -1,   248,    -1,   281,    -1,   283,    -1,   252,
      -1,   266,    -1,   279,    -1,   271,    -1,   251,    -1,   265,
      -1,   280,    -1,   270,    -1,   264,    -1,   263,    -1,   247,
      -1,   246,    -1,   269,    -1,   255,    -1,   256,    -1,   285,
      -1,   275,    -1,   274,    -1,   267,    -1,   227,    -1,   233,
      -1,   230,    -1,   224,    -1,   217,    -1,   216,    -1,   218,
      -1,   235,    -1,   225,    -1,   226,    -1,   232,    -1,   222,
      -1,   231,    -1,    66,    -1,    64,    -1,    75,    -1,    41,
      -1,    55,    -1,   168,    -1,   200,    -1,   241,    -1,   236,
      -1,   239,    -1,   240,    -1,   237,    -1,   238,    -1,   243,
      -1,   244,    -1,    45,    -1,   245,    -1,    65,    -1,   294,
      -1,   292,    -1,   293,    -1,   298,    -1,   299,    -1,   300,
      -1,   295,    -1,   296,    -1,   297,    -1,    79,    -1,    80,
      -1,    81,    -1,    82,    -1,    83,    -1,    84,    -1,    85,
      -1,    86,    -1,    87,    -1,    88,    -1,    89,    -1,   286,
      -1,   287,    -1,   288,    -1,   289,    -1,   290,    -1,   291,
      -1,   302,    -1,   303,    -1,   304,    -1,   305,    -1,   306,
      -1,   307,    -1,   308,    -1,    90,    -1,   104,    -1,   113,
      -1,   171,    -1,   179,    -1,   188,    -1,   137,    -1,    91,
      -1,   114,    -1,   138,    -1,   180,    -1,   614,   120,   615,
      -1,    24,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  xquery_parser::yyprhs_[] =
  {
         0,     0,     3,     5,     8,    11,    13,    16,    18,    21,
      26,    33,    37,    41,    47,    49,    53,    57,    63,    69,
      71,    75,    79,    85,    92,    94,    98,   102,   104,   108,
     112,   114,   116,   118,   120,   122,   124,   126,   128,   130,
     132,   134,   136,   138,   143,   148,   150,   153,   157,   159,
     161,   163,   165,   167,   169,   171,   173,   175,   177,   179,
     181,   183,   185,   187,   189,   191,   193,   195,   197,   203,
     207,   211,   217,   223,   228,   232,   236,   240,   246,   252,
     258,   264,   270,   276,   281,   285,   289,   294,   300,   307,
     309,   313,   317,   321,   325,   332,   338,   347,   352,   356,
     358,   360,   362,   365,   368,   373,   379,   385,   392,   396,
     399,   404,   406,   409,   411,   413,   415,   417,   419,   421,
     424,   427,   430,   433,   435,   438,   441,   444,   448,   453,
     459,   466,   471,   477,   484,   492,   494,   497,   501,   505,
     514,   524,   526,   530,   532,   535,   538,   542,   554,   569,
     583,   606,   610,   614,   617,   621,   626,   632,   635,   640,
     644,   645,   649,   652,   655,   659,   664,   670,   676,   680,
     686,   689,   692,   694,   697,   699,   704,   706,   710,   713,
     717,   719,   722,   724,   726,   731,   736,   742,   748,   756,
     762,   764,   768,   771,   775,   779,   783,   785,   787,   790,
     792,   796,   798,   802,   804,   806,   808,   810,   812,   814,
     816,   818,   820,   822,   824,   826,   828,   830,   832,   834,
     836,   838,   841,   844,   847,   850,   852,   854,   857,   862,
     866,   872,   877,   881,   883,   885,   887,   889,   891,   893,
     895,   897,   899,   902,   906,   908,   913,   917,   923,   928,
     935,   940,   947,   953,   961,   966,   972,   978,   985,   989,
     993,   996,   998,  1002,  1004,  1009,  1011,  1016,  1022,  1026,
    1033,  1038,  1044,  1046,  1049,  1053,  1055,  1058,  1060,  1067,
    1071,  1075,  1078,  1082,  1084,  1088,  1091,  1095,  1098,  1102,
    1107,  1109,  1113,  1115,  1118,  1120,  1122,  1124,  1127,  1130,
    1133,  1137,  1139,  1141,  1144,  1147,  1150,  1156,  1162,  1164,
    1169,  1173,  1178,  1187,  1189,  1192,  1196,  1199,  1203,  1212,
    1223,  1225,  1228,  1233,  1241,  1250,  1252,  1256,  1258,  1262,
    1264,  1268,  1272,  1276,  1280,  1281,  1286,  1290,  1294,  1298,
    1300,  1306,  1307,  1309,  1311,  1315,  1317,  1321,  1325,  1327,
    1331,  1335,  1339,  1343,  1345,  1349,  1353,  1355,  1359,  1363,
    1365,  1370,  1372,  1377,  1379,  1384,  1386,  1391,  1393,  1396,
    1398,  1400,  1403,  1406,  1408,  1410,  1412,  1414,  1416,  1418,
    1420,  1422,  1424,  1426,  1428,  1430,  1435,  1441,  1447,  1454,
    1458,  1463,  1465,  1468,  1472,  1475,  1478,  1480,  1483,  1486,
    1488,  1490,  1492,  1496,  1500,  1502,  1504,  1506,  1509,  1511,
    1514,  1517,  1519,  1522,  1525,  1528,  1531,  1534,  1537,  1540,
    1542,  1545,  1548,  1550,  1553,  1556,  1559,  1562,  1565,  1567,
    1569,  1571,  1573,  1575,  1577,  1579,  1581,  1584,  1588,  1593,
    1595,  1598,  1602,  1604,  1606,  1608,  1610,  1612,  1614,  1616,
    1618,  1620,  1622,  1624,  1626,  1628,  1630,  1633,  1636,  1640,
    1642,  1647,  1652,  1656,  1661,  1663,  1667,  1669,  1671,  1673,
    1675,  1677,  1682,  1688,  1697,  1707,  1717,  1728,  1730,  1733,
    1735,  1738,  1745,  1746,  1748,  1752,  1756,  1757,  1759,  1761,
    1763,  1766,  1769,  1770,  1772,  1774,  1776,  1779,  1782,  1784,
    1786,  1788,  1790,  1792,  1794,  1796,  1798,  1800,  1802,  1804,
    1806,  1810,  1813,  1817,  1821,  1824,  1826,  1828,  1830,  1832,
    1834,  1836,  1841,  1844,  1848,  1855,  1863,  1866,  1870,  1877,
    1885,  1890,  1895,  1898,  1902,  1909,  1917,  1919,  1922,  1925,
    1927,  1930,  1934,  1936,  1938,  1940,  1942,  1944,  1948,  1950,
    1952,  1954,  1958,  1960,  1962,  1964,  1966,  1968,  1970,  1972,
    1974,  1976,  1978,  1982,  1986,  1991,  1996,  2000,  2004,  2008,
    2013,  2018,  2022,  2027,  2034,  2039,  2046,  2051,  2055,  2060,
    2067,  2074,  2079,  2086,  2093,  2098,  2100,  2103,  2105,  2107,
    2109,  2113,  2117,  2119,  2121,  2126,  2132,  2139,  2143,  2147,
    2151,  2155,  2161,  2169,  2177,  2183,  2189,  2195,  2203,  2211,
    2217,  2223,  2227,  2231,  2237,  2245,  2251,  2259,  2261,  2266,
    2270,  2276,  2278,  2281,  2285,  2293,  2304,  2318,  2320,  2324,
    2332,  2337,  2340,  2341,  2343,  2345,  2348,  2350,  2354,  2356,
    2360,  2362,  2367,  2369,  2372,  2376,  2377,  2379,  2380,  2382,
    2387,  2390,  2394,  2396,  2397,  2399,  2404,  2405,  2407,  2410,
    2412,  2416,  2417,  2419,  2422,  2425,  2427,  2428,  2430,  2431,
    2433,  2435,  2437,  2439,  2441,  2443,  2445,  2449,  2453,  2455,
    2457,  2459,  2462,  2466,  2468,  2470,  2472,  2474,  2476,  2478,
    2480,  2482,  2485,  2488,  2490,  2492,  2495,  2498,  2502,  2504,
    2507,  2510,  2516,  2519,  2521,  2523,  2524,  2526,  2528,  2532,
    2537,  2538,  2541,  2542,  2545,  2550,  2555,  2559,  2562,  2566,
    2568,  2572,  2573,  2575,  2577,  2580,  2583,  2586,  2589,  2591,
    2594,  2597,  2600,  2603,  2607,  2610,  2614,  2618,  2623,  2626,
    2629,  2631,  2633,  2637,  2639,  2641,  2643,  2645,  2647,  2649,
    2651,  2653,  2655,  2657,  2659,  2661,  2663,  2665,  2667,  2669,
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
    3071,  3073,  3075,  3077,  3081
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,  1022,  1022,  1023,  1056,  1065,  1070,  1077,  1082,  1093,
    1097,  1105,  1110,  1115,  1120,  1125,  1133,  1141,  1149,  1161,
    1165,  1170,  1175,  1184,  1193,  1199,  1205,  1218,  1224,  1230,
    1242,  1243,  1244,  1245,  1246,  1251,  1252,  1253,  1254,  1255,
    1256,  1257,  1258,  1264,  1269,  1278,  1284,  1293,  1302,  1303,
    1304,  1305,  1306,  1307,  1308,  1309,  1310,  1311,  1316,  1317,
    1318,  1319,  1320,  1321,  1322,  1325,  1330,  1331,  1336,  1344,
    1350,  1360,  1366,  1376,  1386,  1394,  1400,  1411,  1416,  1426,
    1432,  1438,  1444,  1461,  1469,  1477,  1481,  1490,  1499,  1512,
    1518,  1529,  1533,  1541,  1546,  1551,  1558,  1571,  1578,  1584,
    1591,  1597,  1601,  1608,  1619,  1624,  1629,  1634,  1643,  1649,
    1655,  1664,  1670,  1679,  1683,  1689,  1693,  1697,  1701,  1707,
    1713,  1719,  1725,  1731,  1735,  1741,  1747,  1754,  1762,  1770,
    1778,  1786,  1798,  1812,  1826,  1843,  1847,  1856,  1860,  1867,
    1875,  1893,  1899,  1907,  1912,  1919,  1926,  1936,  1946,  1956,
    1966,  1983,  1989,  2000,  2004,  2008,  2012,  2019,  2026,  2045,
    2055,  2061,  2067,  2077,  2083,  2090,  2096,  2106,  2113,  2120,
    2132,  2136,  2144,  2148,  2156,  2160,  2167,  2171,  2179,  2184,
    2193,  2197,  2201,  2205,  2213,  2224,  2239,  2250,  2265,  2276,
    2292,  2298,  2310,  2314,  2325,  2332,  2340,  2355,  2359,  2373,
    2377,  2386,  2390,  2418,  2419,  2420,  2421,  2422,  2423,  2426,
    2427,  2428,  2429,  2430,  2432,  2433,  2436,  2437,  2438,  2439,
    2440,  2445,  2460,  2467,  2471,  2478,  2482,  2486,  2493,  2501,
    2512,  2522,  2535,  2544,  2545,  2546,  2550,  2551,  2552,  2553,
    2554,  2557,  2563,  2573,  2581,  2587,  2599,  2603,  2607,  2611,
    2615,  2619,  2623,  2628,  2634,  2643,  2653,  2663,  2679,  2688,
    2697,  2705,  2711,  2720,  2726,  2735,  2749,  2757,  2767,  2775,
    2787,  2793,  2804,  2806,  2810,  2818,  2822,  2827,  2831,  2835,
    2839,  2849,  2857,  2864,  2870,  2881,  2885,  2894,  2902,  2908,
    2918,  2924,  2934,  2938,  2948,  2954,  2960,  2966,  2975,  2984,
    2993,  3006,  3010,  3018,  3024,  3034,  3042,  3051,  3064,  3071,
    3083,  3087,  3099,  3106,  3112,  3121,  3128,  3134,  3146,  3153,
    3166,  3172,  3184,  3190,  3202,  3211,  3215,  3224,  3228,  3236,
    3240,  3250,  3257,  3266,  3276,  3275,  3289,  3298,  3307,  3320,
    3324,  3337,  3340,  3347,  3351,  3360,  3364,  3368,  3377,  3381,
    3387,  3393,  3399,  3410,  3414,  3418,  3426,  3430,  3436,  3446,
    3450,  3460,  3464,  3474,  3478,  3488,  3492,  3502,  3506,  3514,
    3518,  3522,  3526,  3536,  3540,  3544,  3552,  3556,  3560,  3564,
    3568,  3572,  3580,  3584,  3588,  3596,  3600,  3604,  3608,  3619,
    3625,  3635,  3641,  3651,  3655,  3659,  3698,  3702,  3712,  3722,
    3736,  3746,  3756,  3760,  3770,  3774,  3783,  3789,  3797,  3803,
    3815,  3821,  3831,  3835,  3839,  3843,  3847,  3853,  3859,  3882,
    3886,  3894,  3898,  3909,  3913,  3917,  3923,  3927,  3941,  3945,
    3953,  3957,  3967,  3971,  3975,  3984,  3988,  3992,  3996,  4004,
    4010,  4020,  4028,  4032,  4036,  4040,  4044,  4048,  4052,  4056,
    4060,  4068,  4072,  4080,  4087,  4094,  4105,  4113,  4117,  4125,
    4133,  4141,  4195,  4199,  4212,  4218,  4228,  4232,  4240,  4244,
    4248,  4256,  4266,  4276,  4286,  4296,  4306,  4321,  4327,  4338,
    4344,  4355,  4366,  4368,  4372,  4377,  4387,  4390,  4397,  4403,
    4409,  4417,  4430,  4433,  4440,  4446,  4452,  4459,  4470,  4474,
    4484,  4488,  4498,  4502,  4506,  4511,  4520,  4526,  4532,  4538,
    4548,  4552,  4564,  4568,  4580,  4592,  4596,  4600,  4604,  4608,
    4612,  4620,  4628,  4632,  4636,  4640,  4657,  4661,  4665,  4669,
    4677,  4685,  4693,  4697,  4701,  4705,  4713,  4719,  4729,  4737,
    4741,  4745,  4780,  4786,  4792,  4802,  4806,  4810,  4814,  4818,
    4825,  4831,  4841,  4849,  4853,  4857,  4861,  4865,  4869,  4873,
    4877,  4881,  4889,  4897,  4901,  4905,  4915,  4923,  4931,  4935,
    4939,  4947,  4951,  4957,  4963,  4967,  4977,  4985,  4989,  4995,
    5004,  5013,  5019,  5025,  5035,  5052,  5059,  5074,  5110,  5114,
    5123,  5132,  5142,  5146,  5155,  5164,  5168,  5179,  5196,  5202,
    5208,  5218,  5222,  5228,  5234,  5238,  5244,  5248,  5254,  5260,
    5267,  5277,  5282,  5290,  5296,  5306,  5328,  5337,  5343,  5356,
    5370,  5377,  5383,  5393,  5398,  5403,  5413,  5426,  5432,  5449,
    5453,  5468,  5477,  5480,  5487,  5492,  5500,  5504,  5511,  5515,
    5522,  5526,  5533,  5537,  5546,  5559,  5562,  5570,  5573,  5581,
    5589,  5597,  5601,  5609,  5612,  5620,  5632,  5635,  5643,  5655,
    5661,  5671,  5674,  5682,  5686,  5690,  5698,  5701,  5709,  5712,
    5720,  5724,  5728,  5732,  5736,  5744,  5752,  5764,  5776,  5780,
    5784,  5792,  5798,  5808,  5812,  5816,  5820,  5824,  5828,  5832,
    5836,  5844,  5848,  5852,  5856,  5864,  5870,  5880,  5890,  5894,
    5902,  5912,  5923,  5930,  5934,  5942,  5945,  5952,  5957,  5966,
    5976,  5979,  5987,  5990,  5998,  6007,  6014,  6024,  6028,  6035,
    6041,  6051,  6054,  6061,  6066,  6078,  6086,  6098,  6106,  6110,
    6118,  6122,  6126,  6134,  6142,  6146,  6150,  6154,  6162,  6170,
    6182,  6186,  6194,  6207,  6211,  6212,  6225,  6226,  6227,  6228,
    6229,  6230,  6231,  6232,  6233,  6234,  6235,  6236,  6237,  6238,
    6239,  6240,  6244,  6245,  6246,  6247,  6248,  6249,  6250,  6251,
    6252,  6253,  6254,  6255,  6256,  6257,  6258,  6259,  6260,  6261,
    6262,  6263,  6264,  6265,  6266,  6267,  6268,  6269,  6270,  6271,
    6272,  6273,  6274,  6275,  6276,  6277,  6278,  6279,  6280,  6281,
    6282,  6283,  6284,  6285,  6286,  6287,  6288,  6289,  6290,  6291,
    6292,  6293,  6294,  6295,  6296,  6297,  6298,  6299,  6300,  6301,
    6302,  6303,  6304,  6305,  6306,  6307,  6308,  6309,  6310,  6311,
    6312,  6313,  6314,  6315,  6316,  6317,  6318,  6319,  6320,  6321,
    6322,  6323,  6324,  6325,  6326,  6327,  6328,  6329,  6330,  6331,
    6332,  6333,  6334,  6335,  6336,  6337,  6338,  6339,  6340,  6341,
    6342,  6343,  6344,  6345,  6346,  6347,  6348,  6349,  6350,  6351,
    6352,  6353,  6354,  6355,  6356,  6357,  6358,  6359,  6360,  6361,
    6362,  6363,  6364,  6365,  6366,  6367,  6368,  6369,  6370,  6371,
    6372,  6373,  6374,  6375,  6376,  6377,  6378,  6379,  6380,  6381,
    6382,  6383,  6384,  6385,  6386,  6387,  6388,  6389,  6390,  6391,
    6392,  6393,  6394,  6395,  6396,  6397,  6398,  6399,  6400,  6401,
    6402,  6403,  6404,  6405,  6406,  6407,  6408,  6409,  6410,  6411,
    6412,  6413,  6414,  6415,  6416,  6417,  6418,  6419,  6420,  6421,
    6422,  6423,  6424,  6425,  6426,  6427,  6428,  6429,  6430,  6431,
    6432,  6433,  6434,  6435,  6436,  6437,  6438,  6439,  6440,  6441,
    6442,  6443,  6444,  6449,  6455
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
  const int xquery_parser::yylast_ = 12025;
  const int xquery_parser::yynnts_ = 296;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 565;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 323;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 577;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


} // zorba

/* Line 1053 of lalr1.cc  */
#line 15832 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"


/* Line 1055 of lalr1.cc  */
#line 6459 "F:/xquery/src/compiler/parser/xquery_parser.y"


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
    driver.set_expr(new ParseErrorNode(driver.parserError->loc, driver.parserError->err_code, driver.parserError->msg));
  else
  {
    // remove the double quoting "''" from every token description
    string message = msg;
    int pos;
    while ((pos = message.find("\"'")) != -1 || (pos = message.find("'\"")) != -1)
      message.replace(pos, 2, "\"");
    driver.set_expr(new ParseErrorNode(driver.createQueryLoc(loc), XPST0003, message));
  }
}

} // namespace zorba


#if 0
static void print_token_value(FILE *file, int type, YYSTYPE value)
{
  if (type==VAR) {
    fprintf (file, "%s", value.tptr->name);
  }
  else if (type==NUM) {
    fprintf (file, "%d", value.val);
  }
}
#endif
/* vim:set et sw=4 ts=4: */

