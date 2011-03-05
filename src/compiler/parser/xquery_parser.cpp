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
  XQUERY_ERROR err = 
  AST_IndexDecl::validatePropertyList(static_cast<DeclPropertyList*>(props));

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
#line 150 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"

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
#line 216 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
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
#line 323 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 123: /* "\"'DOUBLE'\"" */

/* Line 479 of lalr1.cc  */
#line 862 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 479 of lalr1.cc  */
#line 332 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 148: /* "\"'INTEGER'\"" */

/* Line 479 of lalr1.cc  */
#line 861 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 479 of lalr1.cc  */
#line 341 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "VersionDecl" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 350 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "MainModule" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 359 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "LibraryModule" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 368 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "ModuleDecl" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 377 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "SIND_DeclList" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 386 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "VFO_DeclList" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 395 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "SIND_Decl" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 404 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "VFO_Decl" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 413 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "DecimalFormatDecl" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 422 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "DecimalFormatParamList" */

/* Line 479 of lalr1.cc  */
#line 886 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 479 of lalr1.cc  */
#line 431 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "DecimalFormatParam" */

/* Line 479 of lalr1.cc  */
#line 886 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 479 of lalr1.cc  */
#line 440 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "Setter" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 449 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "Import" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 458 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "NamespaceDecl" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 467 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "BoundarySpaceDecl" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 476 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "DefaultNamespaceDecl" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 485 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "OptionDecl" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 494 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "FTOptionDecl" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 503 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "OrderingModeDecl" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 512 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "EmptyOrderDecl" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 521 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "CopyNamespacesDecl" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 530 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "DefaultCollationDecl" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 539 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "BaseURIDecl" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 548 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "SchemaImport" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 557 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "URILiteralList" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 566 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "SchemaPrefix" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 575 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "ModuleImport" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 584 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "CtxItemDecl" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 593 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "CtxItemDecl2" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 602 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "CtxItemDecl3" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 611 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "CtxItemDecl4" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 620 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "VarNameAndType" */

/* Line 479 of lalr1.cc  */
#line 886 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 479 of lalr1.cc  */
#line 629 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "VarDecl" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 638 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "DeclPropertyList" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 647 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "DeclProperty" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 656 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "CollectionDecl" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 665 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "NodeModifier" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 674 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "IndexDecl" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 683 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "IndexKeyList" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 692 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "IndexKeySpec" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 701 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "IntegrityConstraintDecl" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 710 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "ConstructionDecl" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 719 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "FunctionSig" */

/* Line 479 of lalr1.cc  */
#line 886 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 479 of lalr1.cc  */
#line 728 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "BlockExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 737 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "Block" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 746 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "BlockDecls" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 755 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "BlockVarDeclList" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 764 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "BlockVarDecl" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 773 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "AssignExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 782 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "ExitExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 791 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "WhileExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 800 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "FlowCtlStatement" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 809 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "AnnotationList" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 818 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "Annotation" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 827 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "AnnotationLiteralList" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 836 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "FunctionDecl" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 845 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "FunctionDecl2" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 854 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "FunctionDeclSimple" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 863 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "FunctionDeclSequential" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 872 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "FunctionDeclUpdating" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 881 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "ParamList" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 890 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "Param" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 899 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "EnclosedExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 908 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "BracedExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 917 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "QueryBody" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 926 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "Expr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 935 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "ApplyExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 944 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "ConcatExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 953 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "ExprSingle" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 962 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "FLWORExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 971 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "ReturnExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 980 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "FLWORWinCond" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 989 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "WindowClause" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 998 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "CountClause" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1007 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "ForLetWinClause" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1016 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "FLWORClauseList" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1025 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "ForClause" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1034 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "VarInDeclList" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1043 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "VarInDecl" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1052 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "PositionalVar" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1061 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "FTScoreVar" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1070 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "LetClause" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1079 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "VarGetsDeclList" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1088 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "EvalVarDeclList" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1097 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "EvalVarDecl" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1106 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "VarGetsDecl" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1115 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "WindowVarDecl" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1124 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "WindowVars" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1133 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "WindowVars3" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1142 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "WindowVars2" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1151 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "WhereClause" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1160 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "GroupByClause" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1169 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "GroupSpecList" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1178 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "GroupSpec" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1187 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "GroupCollationSpec" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1196 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "OrderByClause" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1205 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "OrderSpecList" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1214 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "OrderSpec" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1223 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "OrderModifier" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1232 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "OrderDirSpec" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1241 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "OrderEmptySpec" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1250 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "OrderCollationSpec" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1259 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "QuantifiedExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1268 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "QVarInDeclList" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1277 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "QVarInDecl" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1286 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "SwitchExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1295 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "SwitchCaseClauseList" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1304 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "SwitchCaseClause" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1313 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "SwitchCaseOperandList" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1322 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "TypeswitchExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1331 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "CaseClauseList" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1340 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "CaseClause" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1349 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "IfExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1358 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "OrExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1367 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "AndExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1376 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "ComparisonExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1385 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "FTContainsExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1394 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "opt_FTIgnoreOption" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1403 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "RangeExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1412 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "AdditiveExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1421 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "MultiplicativeExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1430 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "UnionExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1439 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "IntersectExceptExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1448 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "InstanceofExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1457 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "TreatExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1466 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "CastableExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1475 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "CastExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1484 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "UnaryExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1493 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "SignList" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1502 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "ValueExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1511 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "ValueComp" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1520 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "NodeComp" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1529 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "ValidateExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1538 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "ExtensionExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1547 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "Pragma_list" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1556 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "Pragma" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1565 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "PathExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1574 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "RelativePathExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1583 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "StepExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1592 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "AxisStep" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1601 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "ForwardStep" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1610 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "ForwardAxis" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1619 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "AbbrevForwardStep" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1628 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "ReverseStep" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1637 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "ReverseAxis" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1646 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "NodeTest" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1655 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "NameTest" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1664 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "Wildcard" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1673 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "FilterExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1682 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "PredicateList" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1691 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "Predicate" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1700 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "PrimaryExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1709 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "Literal" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1718 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "NumericLiteral" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1727 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "VarRef" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1736 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "ParenthesizedExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1745 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "ContextItemExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1754 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "OrderedExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1763 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "UnorderedExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1772 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "FunctionCall" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1781 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "ArgList" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1790 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "Constructor" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1799 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "DirectConstructor" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1808 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "DirElemConstructor" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1817 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "DirElemContentList" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1826 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "DirAttributeList" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1835 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "DirAttr" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1844 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "DirAttributeValue" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1853 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "opt_QuoteAttrContentList" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1862 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "QuoteAttrContentList" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1871 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "opt_AposAttrContentList" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1880 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "AposAttrContentList" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1889 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "QuoteAttrValueContent" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1898 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "AposAttrValueContent" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1907 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "DirElemContent" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1916 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "CommonContent" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1925 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "DirCommentConstructor" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1934 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "DirPIConstructor" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1943 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "CDataSection" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1952 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "ComputedConstructor" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1961 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "CompDocConstructor" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1970 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "CompElemConstructor" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1979 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "CompAttrConstructor" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1988 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "CompTextConstructor" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1997 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "CompCommentConstructor" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2006 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "CompPIConstructor" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2015 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "SingleType" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2024 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "TypeDeclaration" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2033 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "SequenceType" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2042 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "OccurrenceIndicator" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2051 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "ItemType" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2060 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "TypeList" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2069 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* "AtomicType" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2078 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* "KindTest" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2087 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* "AnyKindTest" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2096 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* "DocumentTest" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2105 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "TextTest" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2114 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* "CommentTest" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2123 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 533: /* "PITest" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2132 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 534: /* "AttributeTest" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2141 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 535: /* "SchemaAttributeTest" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2150 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 536: /* "ElementTest" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2159 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 537: /* "SchemaElementTest" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2168 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* "TypeName" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2177 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 539: /* "TypeName_WITH_HOOK" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2186 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 540: /* "StringLiteral" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2195 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 545: /* "AnyFunctionTest" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2204 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 546: /* "TypedFunctionTest" */

/* Line 479 of lalr1.cc  */
#line 877 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2213 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 549: /* "InsertExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2222 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 550: /* "DeleteExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2231 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 551: /* "ReplaceExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2240 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 552: /* "RenameExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2249 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 553: /* "TransformExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2258 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 554: /* "VarNameList" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2267 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 555: /* "VarNameDecl" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2276 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 556: /* "TryExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2285 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 557: /* "CatchListExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2294 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 558: /* "CatchExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2303 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 559: /* "NameTestList" */

/* Line 479 of lalr1.cc  */
#line 886 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 479 of lalr1.cc  */
#line 2312 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 560: /* "EvalExpr" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2321 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 561: /* "FTSelection" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2330 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 564: /* "FTOr" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2339 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 565: /* "FTAnd" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2348 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 566: /* "FTMildNot" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2357 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 567: /* "FTUnaryNot" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2366 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 568: /* "FTPrimaryWithOptions" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2375 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 569: /* "opt_FTMatchOptions" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2384 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 571: /* "FTWeight" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2393 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 572: /* "FTPrimary" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2402 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 573: /* "opt_FTTimes" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2411 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 574: /* "FTExtensionSelection" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2420 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 576: /* "FTWords" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2429 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 577: /* "FTWordsValue" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2438 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 579: /* "FTAnyallOption" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2447 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 582: /* "FTPosFilter" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2456 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 583: /* "FTOrder" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2465 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 584: /* "FTWindow" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2474 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 585: /* "FTDistance" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2483 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 586: /* "FTUnit" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2492 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 587: /* "FTMatchOptions" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2501 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 588: /* "FTMatchOption" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2510 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 589: /* "FTCaseOption" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2519 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 590: /* "FTDiacriticsOption" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2528 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 591: /* "FTExtensionOption" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2537 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 592: /* "FTStemOption" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2546 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 593: /* "FTThesaurusOption" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2555 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 597: /* "FTThesaurusID" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2564 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 600: /* "FTStopWordOption" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2573 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 601: /* "FTStopWords" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2582 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 605: /* "FTStopWordsInclExcl" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2591 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 606: /* "FTLanguageOption" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2600 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 607: /* "FTWildCardOption" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2609 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 608: /* "FTContent" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2618 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 609: /* "FTTimes" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2627 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 610: /* "FTRange" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2636 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 611: /* "FTScope" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2645 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 612: /* "FTBigUnit" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2654 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 613: /* "FTIgnoreOption" */

/* Line 479 of lalr1.cc  */
#line 880 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2663 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 616: /* "QNAME" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2672 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 617: /* "FUNCTION_NAME" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2681 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
	break;
      case 618: /* "EQNAME" */

/* Line 479 of lalr1.cc  */
#line 883 "F:/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2690 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
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
#line 2775 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"

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
#line 1026 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 4:

/* Line 677 of lalr1.cc  */
#line 1059 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL; YYABORT;
        }
    break;

  case 5:

/* Line 677 of lalr1.cc  */
#line 1068 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 6:

/* Line 677 of lalr1.cc  */
#line 1073 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            MainModule *mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
            mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 7:

/* Line 677 of lalr1.cc  */
#line 1080 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 8:

/* Line 677 of lalr1.cc  */
#line 1085 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            LibraryModule *lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
            lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 9:

/* Line 677 of lalr1.cc  */
#line 1096 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8" );
        }
    break;

  case 10:

/* Line 677 of lalr1.cc  */
#line 1100 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
        }
    break;

  case 11:

/* Line 677 of lalr1.cc  */
#line 1108 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);
          (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
        }
    break;

  case 12:

/* Line 677 of lalr1.cc  */
#line 1113 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));
          (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
        }
    break;

  case 13:

/* Line 677 of lalr1.cc  */
#line 1118 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)), static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));
          (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
        }
    break;

  case 14:

/* Line 677 of lalr1.cc  */
#line 1123 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
        }
    break;

  case 15:

/* Line 677 of lalr1.cc  */
#line 1128 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
          (yylocation_stack_[(3) - (1)]).step();
          error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after statement."); 
          YYERROR;
        }
    break;

  case 16:

/* Line 677 of lalr1.cc  */
#line 1135 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
          (yylocation_stack_[(3) - (1)]).step();
          error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration."); 
          YYERROR;
        }
    break;

  case 17:

/* Line 677 of lalr1.cc  */
#line 1142 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
          (yylocation_stack_[(5) - (3)]).step();
          error((yylocation_stack_[(5) - (3)]), "syntax error, missing semicolon \";\" after declaration.");
          YYERROR;
        }
    break;

  case 18:

/* Line 677 of lalr1.cc  */
#line 1149 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
          (yylocation_stack_[(5) - (1)]).step();
          error((yylocation_stack_[(5) - (1)]), "syntax error, missing semicolon \";\" after statement.");
          YYERROR;
        }
    break;

  case 19:

/* Line 677 of lalr1.cc  */
#line 1160 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
        }
    break;

  case 20:

/* Line 677 of lalr1.cc  */
#line 1164 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);
          (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
        }
    break;

  case 21:

/* Line 677 of lalr1.cc  */
#line 1169 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));
          (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
        }
    break;

  case 22:

/* Line 677 of lalr1.cc  */
#line 1174 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)), static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));
          (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
        }
    break;

  case 23:

/* Line 677 of lalr1.cc  */
#line 1183 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
            dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
        }
    break;

  case 24:

/* Line 677 of lalr1.cc  */
#line 1192 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
            sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
            (yyval.node) = sdl;
        }
    break;

  case 25:

/* Line 677 of lalr1.cc  */
#line 1198 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 26:

/* Line 677 of lalr1.cc  */
#line 1204 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            // error
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
            (yylocation_stack_[(3) - (1)]).step();
            error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration."); 
            YYERROR;
        }
    break;

  case 27:

/* Line 677 of lalr1.cc  */
#line 1216 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
            vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
            (yyval.node) = vdl;
        }
    break;

  case 28:

/* Line 677 of lalr1.cc  */
#line 1222 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 29:

/* Line 677 of lalr1.cc  */
#line 1228 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
            (yylocation_stack_[(3) - (1)]).step();
            error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
            YYERROR;
        }
    break;

  case 43:

/* Line 677 of lalr1.cc  */
#line 1261 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
          delete (yysemantic_stack_[(4) - (4)].vstrpair);
        }
    break;

  case 44:

/* Line 677 of lalr1.cc  */
#line 1266 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
          delete (yysemantic_stack_[(4) - (4)].vstrpair);
        }
    break;

  case 45:

/* Line 677 of lalr1.cc  */
#line 1275 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.vstrpair) = new vector<string_pair_t>();
          (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
          delete (yysemantic_stack_[(1) - (1)].strpair);
        }
    break;

  case 46:

/* Line 677 of lalr1.cc  */
#line 1281 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
          delete (yysemantic_stack_[(2) - (2)].strpair);
          (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
        }
    break;

  case 47:

/* Line 677 of lalr1.cc  */
#line 1290 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
            (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
            delete sl;
        }
    break;

  case 48:

/* Line 677 of lalr1.cc  */
#line 1298 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 49:

/* Line 677 of lalr1.cc  */
#line 1299 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 50:

/* Line 677 of lalr1.cc  */
#line 1300 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 51:

/* Line 677 of lalr1.cc  */
#line 1301 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 52:

/* Line 677 of lalr1.cc  */
#line 1302 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 53:

/* Line 677 of lalr1.cc  */
#line 1303 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 54:

/* Line 677 of lalr1.cc  */
#line 1304 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 55:

/* Line 677 of lalr1.cc  */
#line 1305 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 56:

/* Line 677 of lalr1.cc  */
#line 1306 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 57:

/* Line 677 of lalr1.cc  */
#line 1307 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 68:

/* Line 677 of lalr1.cc  */
#line 1330 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yyval.node); // to prevent the Bison warning
          error((yylocation_stack_[(3) - (2)]), "syntax error, \"import\" should be followed by either \"schema\" or \"module\".");
          YYERROR;
        }
    break;

  case 69:

/* Line 677 of lalr1.cc  */
#line 1340 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
        }
    break;

  case 70:

/* Line 677 of lalr1.cc  */
#line 1348 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BoundarySpaceDecl(
                LOC((yyloc)), StaticContextConsts::preserve_space
            );
        }
    break;

  case 71:

/* Line 677 of lalr1.cc  */
#line 1354 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BoundarySpaceDecl(
                LOC((yyloc)), StaticContextConsts::strip_space
            );
        }
    break;

  case 72:

/* Line 677 of lalr1.cc  */
#line 1364 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultNamespaceDecl(
                LOC((yyloc)), ParseConstants::ns_element_default, SYMTAB((yysemantic_stack_[(5) - (5)].sval))
            );
        }
    break;

  case 73:

/* Line 677 of lalr1.cc  */
#line 1370 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultNamespaceDecl(
                LOC((yyloc)), ParseConstants::ns_function_default, SYMTAB((yysemantic_stack_[(5) - (5)].sval))
            );
        }
    break;

  case 74:

/* Line 677 of lalr1.cc  */
#line 1380 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OptionDecl(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval))
            );
        }
    break;

  case 75:

/* Line 677 of lalr1.cc  */
#line 1390 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
        }
    break;

  case 76:

/* Line 677 of lalr1.cc  */
#line 1398 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OrderingModeDecl(
                LOC((yyloc)), StaticContextConsts::ordered
            );
        }
    break;

  case 77:

/* Line 677 of lalr1.cc  */
#line 1404 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OrderingModeDecl(
                LOC((yyloc)), StaticContextConsts::unordered
            );
        }
    break;

  case 78:

/* Line 677 of lalr1.cc  */
#line 1415 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new EmptyOrderDecl( LOC((yyloc)),
                                StaticContextConsts::empty_greatest);
        }
    break;

  case 79:

/* Line 677 of lalr1.cc  */
#line 1420 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new EmptyOrderDecl( LOC((yyloc)),
                                StaticContextConsts::empty_least);
        }
    break;

  case 80:

/* Line 677 of lalr1.cc  */
#line 1430 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::preserve_ns,
                                StaticContextConsts::inherit_ns);
        }
    break;

  case 81:

/* Line 677 of lalr1.cc  */
#line 1436 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::preserve_ns,
                                StaticContextConsts::no_inherit_ns);
        }
    break;

  case 82:

/* Line 677 of lalr1.cc  */
#line 1442 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::no_preserve_ns,
                                StaticContextConsts::inherit_ns);
        }
    break;

  case 83:

/* Line 677 of lalr1.cc  */
#line 1448 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::no_preserve_ns,
                                StaticContextConsts::no_inherit_ns);
        }
    break;

  case 84:

/* Line 677 of lalr1.cc  */
#line 1465 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
        }
    break;

  case 85:

/* Line 677 of lalr1.cc  */
#line 1473 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 86:

/* Line 677 of lalr1.cc  */
#line 1481 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
        }
    break;

  case 87:

/* Line 677 of lalr1.cc  */
#line 1485 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new SchemaImport(
                LOC((yyloc)),
                dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                NULL
            );
        }
    break;

  case 88:

/* Line 677 of lalr1.cc  */
#line 1494 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new SchemaImport(
                LOC((yyloc)),
                NULL,
                SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 89:

/* Line 677 of lalr1.cc  */
#line 1503 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new SchemaImport(
                LOC((yyloc)),
                dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node))
            );
        }
    break;

  case 90:

/* Line 677 of lalr1.cc  */
#line 1516 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            URILiteralList *ull = new URILiteralList( LOC((yyloc)));
            ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.node) = ull;
        }
    break;

  case 91:

/* Line 677 of lalr1.cc  */
#line 1522 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
                ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 92:

/* Line 677 of lalr1.cc  */
#line 1533 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 93:

/* Line 677 of lalr1.cc  */
#line 1537 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
        }
    break;

  case 94:

/* Line 677 of lalr1.cc  */
#line 1545 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 95:

/* Line 677 of lalr1.cc  */
#line 1550 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 96:

/* Line 677 of lalr1.cc  */
#line 1555 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 97:

/* Line 677 of lalr1.cc  */
#line 1562 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(8) - (4)].sval)),
                            SYMTAB((yysemantic_stack_[(8) - (6)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(8) - (8)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(8) - (2)].sval)));
    }
    break;

  case 98:

/* Line 677 of lalr1.cc  */
#line 1575 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
        }
    break;

  case 99:

/* Line 677 of lalr1.cc  */
#line 1582 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            CtxItemDecl *d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
            d->type = (yysemantic_stack_[(3) - (2)].node);
            (yyval.node) = d;
        }
    break;

  case 100:

/* Line 677 of lalr1.cc  */
#line 1588 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 101:

/* Line 677 of lalr1.cc  */
#line 1595 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            CtxItemDecl *d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
            d->ext = false;
            (yyval.node) = d;
        }
    break;

  case 102:

/* Line 677 of lalr1.cc  */
#line 1601 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CtxItemDecl( LOC((yyloc)), NULL );
        }
    break;

  case 103:

/* Line 677 of lalr1.cc  */
#line 1605 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 104:

/* Line 677 of lalr1.cc  */
#line 1612 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CtxItemDecl( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 105:

/* Line 677 of lalr1.cc  */
#line 1623 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)), NULL, NULL);
      dynamic_cast<VarNameAndType*>((yyval.varnametype))->setComment(SYMTAB((yysemantic_stack_[(4) - (1)].sval)));
    }
    break;

  case 106:

/* Line 677 of lalr1.cc  */
#line 1628 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)), NULL);
      dynamic_cast<VarNameAndType*>((yyval.varnametype))->setComment(SYMTAB((yysemantic_stack_[(5) - (1)].sval)));
    }
    break;

  case 107:

/* Line 677 of lalr1.cc  */
#line 1633 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (5)].expr)), NULL, static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (2)].node)));
      dynamic_cast<VarNameAndType*>((yyval.varnametype))->setComment(SYMTAB((yysemantic_stack_[(5) - (1)].sval)));
    }
    break;

  case 108:

/* Line 677 of lalr1.cc  */
#line 1638 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (5)].expr)), dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)), static_cast<AnnotationListParsenode*>((yysemantic_stack_[(6) - (2)].node)));
      dynamic_cast<VarNameAndType*>((yyval.varnametype))->setComment(SYMTAB((yysemantic_stack_[(6) - (1)].sval)));
    }
    break;

  case 109:

/* Line 677 of lalr1.cc  */
#line 1647 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(3) - (1)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, (yysemantic_stack_[(3) - (3)].expr), nt->get_annotations());
      dynamic_cast<VarDecl*>((yyval.node))->setComment(nt->getCommentString());
    }
    break;

  case 110:

/* Line 677 of lalr1.cc  */
#line 1653 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(2) - (1)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, NULL, nt->get_annotations(), true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(nt->getCommentString());
    }
    break;

  case 111:

/* Line 677 of lalr1.cc  */
#line 1659 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(4) - (1)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, (yysemantic_stack_[(4) - (4)].expr), nt->get_annotations(), true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(nt->getCommentString());
    }
    break;

  case 112:

/* Line 677 of lalr1.cc  */
#line 1668 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            DeclPropertyList *dpl = new DeclPropertyList( LOC((yyloc)) );
            dpl->addProperty(dynamic_cast<DeclProperty*>((yysemantic_stack_[(1) - (1)].node)));
            (yyval.node) = dpl;
        }
    break;

  case 113:

/* Line 677 of lalr1.cc  */
#line 1674 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
        DeclPropertyList *dpl = dynamic_cast<DeclPropertyList*>((yysemantic_stack_[(2) - (1)].node));
        dpl->addProperty( static_cast<DeclProperty*>((yysemantic_stack_[(2) - (2)].node)) );
        (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 114:

/* Line 677 of lalr1.cc  */
#line 1683 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_const );
        }
    break;

  case 115:

/* Line 677 of lalr1.cc  */
#line 1687 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_append_only
            );
        }
    break;

  case 116:

/* Line 677 of lalr1.cc  */
#line 1693 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_queue );
        }
    break;

  case 117:

/* Line 677 of lalr1.cc  */
#line 1697 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_mutable );
        }
    break;

  case 118:

/* Line 677 of lalr1.cc  */
#line 1701 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_ordered );
        }
    break;

  case 119:

/* Line 677 of lalr1.cc  */
#line 1705 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_unordered
            );
        }
    break;

  case 120:

/* Line 677 of lalr1.cc  */
#line 1711 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_value_equality
            );
        }
    break;

  case 121:

/* Line 677 of lalr1.cc  */
#line 1717 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_value_range
            );
        }
    break;

  case 122:

/* Line 677 of lalr1.cc  */
#line 1723 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_general_equality
            );
        }
    break;

  case 123:

/* Line 677 of lalr1.cc  */
#line 1729 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_general_range
            );
        }
    break;

  case 124:

/* Line 677 of lalr1.cc  */
#line 1735 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_unique );
        }
    break;

  case 125:

/* Line 677 of lalr1.cc  */
#line 1739 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_non_unique
            );
        }
    break;

  case 126:

/* Line 677 of lalr1.cc  */
#line 1745 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_automatic
            );
        }
    break;

  case 127:

/* Line 677 of lalr1.cc  */
#line 1751 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_manual );
        }
    break;

  case 128:

/* Line 677 of lalr1.cc  */
#line 1758 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)),
                              NULL,
                              NULL,
                              NULL);
    }
    break;

  case 129:

/* Line 677 of lalr1.cc  */
#line 1766 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              NULL,
                              static_cast<NodeModifier*>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 130:

/* Line 677 of lalr1.cc  */
#line 1774 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                              NULL,
                              NULL,
                              static_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 131:

/* Line 677 of lalr1.cc  */
#line 1782 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                              NULL,
                              static_cast<NodeModifier*>((yysemantic_stack_[(6) - (6)].node)),
                              static_cast<SequenceType*>((yysemantic_stack_[(6) - (5)].node)));
    }
    break;

  case 132:

/* Line 677 of lalr1.cc  */
#line 1790 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

  case 133:

/* Line 677 of lalr1.cc  */
#line 1802 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

  case 134:

/* Line 677 of lalr1.cc  */
#line 1816 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

  case 135:

/* Line 677 of lalr1.cc  */
#line 1830 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

  case 136:

/* Line 677 of lalr1.cc  */
#line 1847 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 137:

/* Line 677 of lalr1.cc  */
#line 1851 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 138:

/* Line 677 of lalr1.cc  */
#line 1860 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier(LOC((yyloc)), StaticContextConsts::read_only);
    }
    break;

  case 139:

/* Line 677 of lalr1.cc  */
#line 1864 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier(LOC((yyloc)), StaticContextConsts::mutable_node);
    }
    break;

  case 140:

/* Line 677 of lalr1.cc  */
#line 1871 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AST_IndexDecl(LOC((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(8) - (3)].expr)),
                             (yysemantic_stack_[(8) - (6)].expr),
                             dynamic_cast<IndexKeyList*>((yysemantic_stack_[(8) - (8)].node)),
                             NULL);
    }
    break;

  case 141:

/* Line 677 of lalr1.cc  */
#line 1879 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

  case 142:

/* Line 677 of lalr1.cc  */
#line 1897 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 143:

/* Line 677 of lalr1.cc  */
#line 1903 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 144:

/* Line 677 of lalr1.cc  */
#line 1911 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 145:

/* Line 677 of lalr1.cc  */
#line 1916 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 146:

/* Line 677 of lalr1.cc  */
#line 1923 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 147:

/* Line 677 of lalr1.cc  */
#line 1930 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 148:

/* Line 677 of lalr1.cc  */
#line 1941 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollSimpleCheck(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (9)].expr)),
                                 (yysemantic_stack_[(11) - (11)].expr));
    }
    break;

  case 149:

/* Line 677 of lalr1.cc  */
#line 1951 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollUniqueKeyCheck(LOC((yyloc)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (4)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (7)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (10)].expr)),
                                    (yysemantic_stack_[(14) - (14)].expr));
    }
    break;

  case 150:

/* Line 677 of lalr1.cc  */
#line 1961 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollForeachNode(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (11)].expr)),
                                 (yysemantic_stack_[(13) - (13)].expr));
    }
    break;

  case 151:

/* Line 677 of lalr1.cc  */
#line 1972 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

  case 152:

/* Line 677 of lalr1.cc  */
#line 1987 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ConstructionDecl(
                LOC((yyloc)), StaticContextConsts::cons_preserve
            );
        }
    break;

  case 153:

/* Line 677 of lalr1.cc  */
#line 1993 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ConstructionDecl(
                LOC((yyloc)), StaticContextConsts::cons_strip
            );
        }
    break;

  case 154:

/* Line 677 of lalr1.cc  */
#line 2004 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( NULL );
        }
    break;

  case 155:

/* Line 677 of lalr1.cc  */
#line 2008 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 156:

/* Line 677 of lalr1.cc  */
#line 2012 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)) );
        }
    break;

  case 157:

/* Line 677 of lalr1.cc  */
#line 2016 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 158:

/* Line 677 of lalr1.cc  */
#line 2023 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(2) - (2)].expr);
        }
    break;

  case 159:

/* Line 677 of lalr1.cc  */
#line 2030 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

  case 160:

/* Line 677 of lalr1.cc  */
#line 2049 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vfo = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node));
            auto_ptr<VFO_DeclList> vfo2( dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)) );
            if ( !(yysemantic_stack_[(3) - (1)].node) )
                vfo = new VFO_DeclList( LOC((yyloc)) );
            vfo->push_back( *vfo2.get() );
            (yyval.node) = vfo;
        }
    break;

  case 161:

/* Line 677 of lalr1.cc  */
#line 2058 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 162:

/* Line 677 of lalr1.cc  */
#line 2065 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vfo = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node));
            vfo->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = vfo;
        }
    break;

  case 163:

/* Line 677 of lalr1.cc  */
#line 2071 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vfo = new VFO_DeclList( LOC((yyloc)) );
            vfo->push_back((yysemantic_stack_[(2) - (2)].node));
            (yyval.node) = vfo;
        }
    break;

  case 164:

/* Line 677 of lalr1.cc  */
#line 2081 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      VarDecl* vd = new VarDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL, NULL);
      vd->set_global(false);
      (yyval.node) = vd;
    }
    break;

  case 165:

/* Line 677 of lalr1.cc  */
#line 2087 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      VarDecl* vd = new VarDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)), NULL, NULL);

      vd->set_global(false);
      (yyval.node) = vd;
    }
    break;

  case 166:

/* Line 677 of lalr1.cc  */
#line 2094 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      VarDecl* vd = new VarDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)), NULL, (yysemantic_stack_[(4) - (4)].expr), NULL);
      vd->set_global(false);
      (yyval.node) = vd;
    }
    break;

  case 167:

/* Line 677 of lalr1.cc  */
#line 2100 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      VarDecl* vd = new VarDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (3)].node)), (yysemantic_stack_[(5) - (5)].expr), NULL);
      vd->set_global(false);
      (yyval.node) = vd;
    }
    break;

  case 168:

/* Line 677 of lalr1.cc  */
#line 2110 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 169:

/* Line 677 of lalr1.cc  */
#line 2117 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExitExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 170:

/* Line 677 of lalr1.cc  */
#line 2124 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            BlockBody *bb = dynamic_cast<BlockBody *>((yysemantic_stack_[(5) - (5)].expr));
            if ( !bb ) {
                bb = new BlockBody( (yysemantic_stack_[(5) - (5)].expr)->get_location() );
                bb->add((yysemantic_stack_[(5) - (5)].expr));
            }
            (yyval.expr) = new WhileExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), bb );
        }
    break;

  case 171:

/* Line 677 of lalr1.cc  */
#line 2136 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::BREAK );
        }
    break;

  case 172:

/* Line 677 of lalr1.cc  */
#line 2140 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
        }
    break;

  case 173:

/* Line 677 of lalr1.cc  */
#line 2148 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnnotationListParsenode( LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
        }
    break;

  case 174:

/* Line 677 of lalr1.cc  */
#line 2152 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 175:

/* Line 677 of lalr1.cc  */
#line 2160 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnnotationParsenode( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
        }
    break;

  case 176:

/* Line 677 of lalr1.cc  */
#line 2164 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnnotationParsenode( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))), static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
        }
    break;

  case 177:

/* Line 677 of lalr1.cc  */
#line 2171 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnnotationLiteralListParsenode( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
        }
    break;

  case 178:

/* Line 677 of lalr1.cc  */
#line 2175 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 179:

/* Line 677 of lalr1.cc  */
#line 2183 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 180:

/* Line 677 of lalr1.cc  */
#line 2188 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node))->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );
            static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node))->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
            (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
        }
    break;

  case 181:

/* Line 677 of lalr1.cc  */
#line 2197 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 182:

/* Line 677 of lalr1.cc  */
#line 2201 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 183:

/* Line 677 of lalr1.cc  */
#line 2205 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 184:

/* Line 677 of lalr1.cc  */
#line 2209 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 185:

/* Line 677 of lalr1.cc  */
#line 2217 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

  case 186:

/* Line 677 of lalr1.cc  */
#line 2228 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

  case 187:

/* Line 677 of lalr1.cc  */
#line 2243 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

  case 188:

/* Line 677 of lalr1.cc  */
#line 2254 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

  case 189:

/* Line 677 of lalr1.cc  */
#line 2269 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

  case 190:

/* Line 677 of lalr1.cc  */
#line 2280 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

  case 191:

/* Line 677 of lalr1.cc  */
#line 2296 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            ParamList *pl = new ParamList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 192:

/* Line 677 of lalr1.cc  */
#line 2302 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
                pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 193:

/* Line 677 of lalr1.cc  */
#line 2314 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 194:

/* Line 677 of lalr1.cc  */
#line 2318 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 195:

/* Line 677 of lalr1.cc  */
#line 2329 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new EnclosedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 196:

/* Line 677 of lalr1.cc  */
#line 2336 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 197:

/* Line 677 of lalr1.cc  */
#line 2344 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QueryBody( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 198:

/* Line 677 of lalr1.cc  */
#line 2359 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 199:

/* Line 677 of lalr1.cc  */
#line 2363 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            auto_ptr<BlockBody> blk( dynamic_cast<BlockBody*>((yysemantic_stack_[(2) - (2)].expr)) );
            BlockBody *blk2 = new BlockBody( LOC((yyloc)) );
            blk2->add( (yysemantic_stack_[(2) - (1)].expr) );

            for ( ulong i = 0; i < blk->size(); ++i )
                blk2->add( (*blk)[i] );

            (yyval.expr) = blk2;
        }
    break;

  case 200:

/* Line 677 of lalr1.cc  */
#line 2377 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new BlockBody( LOC((yyloc)) );
        }
    break;

  case 201:

/* Line 677 of lalr1.cc  */
#line 2381 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            BlockBody *bb = dynamic_cast<BlockBody*>((yysemantic_stack_[(3) - (1)].expr));
            bb->add( (yysemantic_stack_[(3) - (2)].expr) );
            (yyval.expr) = bb;
        }
    break;

  case 202:

/* Line 677 of lalr1.cc  */
#line 2390 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 203:

/* Line 677 of lalr1.cc  */
#line 2394 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

  case 222:

/* Line 677 of lalr1.cc  */
#line 2449 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

  case 223:

/* Line 677 of lalr1.cc  */
#line 2464 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 224:

/* Line 677 of lalr1.cc  */
#line 2471 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_sliding;
        }
    break;

  case 225:

/* Line 677 of lalr1.cc  */
#line 2475 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_tumbling;
        }
    break;

  case 226:

/* Line 677 of lalr1.cc  */
#line 2482 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_start;
        }
    break;

  case 227:

/* Line 677 of lalr1.cc  */
#line 2486 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_end;
        }
    break;

  case 228:

/* Line 677 of lalr1.cc  */
#line 2490 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_only_end;
        }
    break;

  case 229:

/* Line 677 of lalr1.cc  */
#line 2497 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FLWORWinCond(
                LOC((yyloc)),
                dynamic_cast<WindowVars*>((yysemantic_stack_[(4) - (2)].node)), (yysemantic_stack_[(4) - (4)].expr),
                (yysemantic_stack_[(4) - (1)].strval) == parser::the_start, (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end
            );
        }
    break;

  case 230:

/* Line 677 of lalr1.cc  */
#line 2505 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FLWORWinCond(
                LOC((yyloc)), NULL, (yysemantic_stack_[(3) - (3)].expr),
                (yysemantic_stack_[(3) - (1)].strval) == parser::the_start, (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end
            );
        }
    break;

  case 231:

/* Line 677 of lalr1.cc  */
#line 2516 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

  case 232:

/* Line 677 of lalr1.cc  */
#line 2526 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling ?
                              WindowClause::tumbling_window :
                              WindowClause::sliding_window),
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    }
    break;

  case 233:

/* Line 677 of lalr1.cc  */
#line 2539 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 242:

/* Line 677 of lalr1.cc  */
#line 2561 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
            fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = fcl;
        }
    break;

  case 243:

/* Line 677 of lalr1.cc  */
#line 2567 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
            fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = fcl;
        }
    break;

  case 244:

/* Line 677 of lalr1.cc  */
#line 2577 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
        }
    break;

  case 245:

/* Line 677 of lalr1.cc  */
#line 2585 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            VarInDeclList *vdl = new VarInDeclList( LOC((yyloc)) );
            vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vdl;
        }
    break;

  case 246:

/* Line 677 of lalr1.cc  */
#line 2591 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( VarInDeclList *vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 247:

/* Line 677 of lalr1.cc  */
#line 2603 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 248:

/* Line 677 of lalr1.cc  */
#line 2607 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)), NULL, NULL, NULL, (yysemantic_stack_[(5) - (5)].expr), true);
    }
    break;

  case 249:

/* Line 677 of lalr1.cc  */
#line 2611 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)), dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)), NULL, NULL, (yysemantic_stack_[(4) - (4)].expr), false);
    }
    break;

  case 250:

/* Line 677 of lalr1.cc  */
#line 2615 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (1)].expr)), dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (2)].node)), NULL, NULL, (yysemantic_stack_[(6) - (6)].expr), true);
    }
    break;

  case 251:

/* Line 677 of lalr1.cc  */
#line 2619 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)), NULL, dynamic_cast<PositionalVar*>((yysemantic_stack_[(4) - (2)].node)), NULL, (yysemantic_stack_[(4) - (4)].expr), false);
    }
    break;

  case 252:

/* Line 677 of lalr1.cc  */
#line 2623 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (1)].expr)), NULL, dynamic_cast<PositionalVar*>((yysemantic_stack_[(6) - (4)].node)), NULL, (yysemantic_stack_[(6) - (6)].expr), true);
    }
    break;

  case 253:

/* Line 677 of lalr1.cc  */
#line 2627 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (3)].node)), NULL, (yysemantic_stack_[(5) - (5)].expr), false);
    }
    break;

  case 254:

/* Line 677 of lalr1.cc  */
#line 2632 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(7) - (1)].expr)), dynamic_cast<SequenceType *>((yysemantic_stack_[(7) - (2)].node)),
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(7) - (5)].node)), NULL, (yysemantic_stack_[(7) - (7)].expr), true);
    }
    break;

  case 255:

/* Line 677 of lalr1.cc  */
#line 2638 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         NULL,NULL,
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
                         (yysemantic_stack_[(4) - (4)].expr),
                         false);
    }
    break;

  case 256:

/* Line 677 of lalr1.cc  */
#line 2647 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

  case 257:

/* Line 677 of lalr1.cc  */
#line 2657 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

  case 258:

/* Line 677 of lalr1.cc  */
#line 2667 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

  case 259:

/* Line 677 of lalr1.cc  */
#line 2683 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 260:

/* Line 677 of lalr1.cc  */
#line 2692 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 261:

/* Line 677 of lalr1.cc  */
#line 2701 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 262:

/* Line 677 of lalr1.cc  */
#line 2709 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 263:

/* Line 677 of lalr1.cc  */
#line 2715 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 264:

/* Line 677 of lalr1.cc  */
#line 2724 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 265:

/* Line 677 of lalr1.cc  */
#line 2730 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 266:

/* Line 677 of lalr1.cc  */
#line 2739 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)),
                           NULL, // no type
                           NULL, // no ftscore var
                           new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr))),
                           VarGetsDecl::eval_var);
    }
    break;

  case 267:

/* Line 677 of lalr1.cc  */
#line 2754 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                           NULL,
                           NULL,
                           (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 268:

/* Line 677 of lalr1.cc  */
#line 2762 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                           NULL,
                           (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 269:

/* Line 677 of lalr1.cc  */
#line 2772 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node))->get_var_name(),
                           NULL,
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node)),
                           (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 270:

/* Line 677 of lalr1.cc  */
#line 2780 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (3)].node)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
                           (yysemantic_stack_[(6) - (6)].expr));
    }
    break;

  case 271:

/* Line 677 of lalr1.cc  */
#line 2792 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 272:

/* Line 677 of lalr1.cc  */
#line 2798 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 274:

/* Line 677 of lalr1.cc  */
#line 2811 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 275:

/* Line 677 of lalr1.cc  */
#line 2815 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 276:

/* Line 677 of lalr1.cc  */
#line 2823 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 277:

/* Line 677 of lalr1.cc  */
#line 2827 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 279:

/* Line 677 of lalr1.cc  */
#line 2836 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 280:

/* Line 677 of lalr1.cc  */
#line 2840 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 281:

/* Line 677 of lalr1.cc  */
#line 2844 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 282:

/* Line 677 of lalr1.cc  */
#line 2854 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 283:

/* Line 677 of lalr1.cc  */
#line 2862 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 284:

/* Line 677 of lalr1.cc  */
#line 2869 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = new GroupSpecList( LOC((yyloc)) );
            gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 285:

/* Line 677 of lalr1.cc  */
#line 2875 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
            if ( gsl )
                gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 286:

/* Line 677 of lalr1.cc  */
#line 2886 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 287:

/* Line 677 of lalr1.cc  */
#line 2890 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                         dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 288:

/* Line 677 of lalr1.cc  */
#line 2899 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 289:

/* Line 677 of lalr1.cc  */
#line 2907 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 290:

/* Line 677 of lalr1.cc  */
#line 2913 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 291:

/* Line 677 of lalr1.cc  */
#line 2923 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 292:

/* Line 677 of lalr1.cc  */
#line 2929 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 293:

/* Line 677 of lalr1.cc  */
#line 2939 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 294:

/* Line 677 of lalr1.cc  */
#line 2943 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 295:

/* Line 677 of lalr1.cc  */
#line 2953 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 296:

/* Line 677 of lalr1.cc  */
#line 2959 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 297:

/* Line 677 of lalr1.cc  */
#line 2965 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 298:

/* Line 677 of lalr1.cc  */
#line 2971 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
                NULL
            );
        }
    break;

  case 299:

/* Line 677 of lalr1.cc  */
#line 2980 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                NULL,
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 300:

/* Line 677 of lalr1.cc  */
#line 2989 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                NULL,
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 301:

/* Line 677 of lalr1.cc  */
#line 2998 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 302:

/* Line 677 of lalr1.cc  */
#line 3011 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 303:

/* Line 677 of lalr1.cc  */
#line 3015 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 304:

/* Line 677 of lalr1.cc  */
#line 3023 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 305:

/* Line 677 of lalr1.cc  */
#line 3029 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 306:

/* Line 677 of lalr1.cc  */
#line 3039 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 307:

/* Line 677 of lalr1.cc  */
#line 3047 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_some,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 308:

/* Line 677 of lalr1.cc  */
#line 3056 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_every,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 309:

/* Line 677 of lalr1.cc  */
#line 3069 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 310:

/* Line 677 of lalr1.cc  */
#line 3076 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 311:

/* Line 677 of lalr1.cc  */
#line 3088 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 312:

/* Line 677 of lalr1.cc  */
#line 3092 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 313:

/* Line 677 of lalr1.cc  */
#line 3104 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 314:

/* Line 677 of lalr1.cc  */
#line 3111 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 315:

/* Line 677 of lalr1.cc  */
#line 3117 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 316:

/* Line 677 of lalr1.cc  */
#line 3126 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 317:

/* Line 677 of lalr1.cc  */
#line 3133 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 318:

/* Line 677 of lalr1.cc  */
#line 3139 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 319:

/* Line 677 of lalr1.cc  */
#line 3151 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 320:

/* Line 677 of lalr1.cc  */
#line 3158 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 321:

/* Line 677 of lalr1.cc  */
#line 3171 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 322:

/* Line 677 of lalr1.cc  */
#line 3177 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 323:

/* Line 677 of lalr1.cc  */
#line 3189 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 324:

/* Line 677 of lalr1.cc  */
#line 3195 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 325:

/* Line 677 of lalr1.cc  */
#line 3207 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 326:

/* Line 677 of lalr1.cc  */
#line 3216 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 327:

/* Line 677 of lalr1.cc  */
#line 3220 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 328:

/* Line 677 of lalr1.cc  */
#line 3229 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 329:

/* Line 677 of lalr1.cc  */
#line 3233 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 330:

/* Line 677 of lalr1.cc  */
#line 3241 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 331:

/* Line 677 of lalr1.cc  */
#line 3245 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

  case 332:

/* Line 677 of lalr1.cc  */
#line 3255 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 333:

/* Line 677 of lalr1.cc  */
#line 3262 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_eq ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 334:

/* Line 677 of lalr1.cc  */
#line 3271 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ne ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 335:

/* Line 677 of lalr1.cc  */
#line 3280 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 336:

/* Line 677 of lalr1.cc  */
#line 3285 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_lt ),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr)
            );
        }
    break;

  case 337:

/* Line 677 of lalr1.cc  */
#line 3294 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_le ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 338:

/* Line 677 of lalr1.cc  */
#line 3303 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_gt ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 339:

/* Line 677 of lalr1.cc  */
#line 3312 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ge ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 340:

/* Line 677 of lalr1.cc  */
#line 3325 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 341:

/* Line 677 of lalr1.cc  */
#line 3329 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FTContainsExpr(
                LOC((yyloc)),
                (yysemantic_stack_[(5) - (1)].expr),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(5) - (4)].node)),
                dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 342:

/* Line 677 of lalr1.cc  */
#line 3341 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 343:

/* Line 677 of lalr1.cc  */
#line 3345 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 344:

/* Line 677 of lalr1.cc  */
#line 3352 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 345:

/* Line 677 of lalr1.cc  */
#line 3356 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 346:

/* Line 677 of lalr1.cc  */
#line 3365 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 347:

/* Line 677 of lalr1.cc  */
#line 3369 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 348:

/* Line 677 of lalr1.cc  */
#line 3373 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 349:

/* Line 677 of lalr1.cc  */
#line 3382 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 350:

/* Line 677 of lalr1.cc  */
#line 3386 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 351:

/* Line 677 of lalr1.cc  */
#line 3392 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 352:

/* Line 677 of lalr1.cc  */
#line 3398 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 353:

/* Line 677 of lalr1.cc  */
#line 3404 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 354:

/* Line 677 of lalr1.cc  */
#line 3415 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
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
#line 3423 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 357:

/* Line 677 of lalr1.cc  */
#line 3431 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 358:

/* Line 677 of lalr1.cc  */
#line 3435 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 359:

/* Line 677 of lalr1.cc  */
#line 3441 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 360:

/* Line 677 of lalr1.cc  */
#line 3451 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 361:

/* Line 677 of lalr1.cc  */
#line 3455 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 362:

/* Line 677 of lalr1.cc  */
#line 3465 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 363:

/* Line 677 of lalr1.cc  */
#line 3469 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 364:

/* Line 677 of lalr1.cc  */
#line 3479 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 365:

/* Line 677 of lalr1.cc  */
#line 3483 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 366:

/* Line 677 of lalr1.cc  */
#line 3493 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 367:

/* Line 677 of lalr1.cc  */
#line 3497 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 368:

/* Line 677 of lalr1.cc  */
#line 3507 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 369:

/* Line 677 of lalr1.cc  */
#line 3511 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 370:

/* Line 677 of lalr1.cc  */
#line 3519 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 371:

/* Line 677 of lalr1.cc  */
#line 3523 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 372:

/* Line 677 of lalr1.cc  */
#line 3527 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 373:

/* Line 677 of lalr1.cc  */
#line 3531 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
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
#line 3549 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 377:

/* Line 677 of lalr1.cc  */
#line 3557 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 378:

/* Line 677 of lalr1.cc  */
#line 3561 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 379:

/* Line 677 of lalr1.cc  */
#line 3565 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 380:

/* Line 677 of lalr1.cc  */
#line 3569 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 381:

/* Line 677 of lalr1.cc  */
#line 3573 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 382:

/* Line 677 of lalr1.cc  */
#line 3577 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 383:

/* Line 677 of lalr1.cc  */
#line 3585 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 384:

/* Line 677 of lalr1.cc  */
#line 3589 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 385:

/* Line 677 of lalr1.cc  */
#line 3593 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 386:

/* Line 677 of lalr1.cc  */
#line 3601 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 387:

/* Line 677 of lalr1.cc  */
#line 3605 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 388:

/* Line 677 of lalr1.cc  */
#line 3609 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 389:

/* Line 677 of lalr1.cc  */
#line 3613 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 390:

/* Line 677 of lalr1.cc  */
#line 3624 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 391:

/* Line 677 of lalr1.cc  */
#line 3630 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 392:

/* Line 677 of lalr1.cc  */
#line 3640 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 393:

/* Line 677 of lalr1.cc  */
#line 3646 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 394:

/* Line 677 of lalr1.cc  */
#line 3656 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 395:

/* Line 677 of lalr1.cc  */
#line 3660 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 396:

/* Line 677 of lalr1.cc  */
#line 3664 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 397:

/* Line 677 of lalr1.cc  */
#line 3703 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new PathExpr(LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
    }
    break;

  case 398:

/* Line 677 of lalr1.cc  */
#line 3707 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, NULL, (yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slash,
                        rpe);
    }
    break;

  case 399:

/* Line 677 of lalr1.cc  */
#line 3717 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, NULL, (yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slashslash,
                        rpe);
    }
    break;

  case 400:

/* Line 677 of lalr1.cc  */
#line 3727 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = (!rpe ?
            (yysemantic_stack_[(1) - (1)].expr) :
            new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 401:

/* Line 677 of lalr1.cc  */
#line 3741 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 402:

/* Line 677 of lalr1.cc  */
#line 3751 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

  case 403:

/* Line 677 of lalr1.cc  */
#line 3761 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 404:

/* Line 677 of lalr1.cc  */
#line 3765 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
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
#line 3779 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 407:

/* Line 677 of lalr1.cc  */
#line 3788 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 408:

/* Line 677 of lalr1.cc  */
#line 3794 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 409:

/* Line 677 of lalr1.cc  */
#line 3802 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 410:

/* Line 677 of lalr1.cc  */
#line 3808 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 411:

/* Line 677 of lalr1.cc  */
#line 3820 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 412:

/* Line 677 of lalr1.cc  */
#line 3826 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 413:

/* Line 677 of lalr1.cc  */
#line 3836 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 414:

/* Line 677 of lalr1.cc  */
#line 3840 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 415:

/* Line 677 of lalr1.cc  */
#line 3844 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 416:

/* Line 677 of lalr1.cc  */
#line 3848 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 417:

/* Line 677 of lalr1.cc  */
#line 3852 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 418:

/* Line 677 of lalr1.cc  */
#line 3858 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 419:

/* Line 677 of lalr1.cc  */
#line 3864 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 420:

/* Line 677 of lalr1.cc  */
#line 3887 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 421:

/* Line 677 of lalr1.cc  */
#line 3891 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 422:

/* Line 677 of lalr1.cc  */
#line 3899 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 423:

/* Line 677 of lalr1.cc  */
#line 3903 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 424:

/* Line 677 of lalr1.cc  */
#line 3914 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 425:

/* Line 677 of lalr1.cc  */
#line 3918 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 426:

/* Line 677 of lalr1.cc  */
#line 3922 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 427:

/* Line 677 of lalr1.cc  */
#line 3928 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 428:

/* Line 677 of lalr1.cc  */
#line 3932 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
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
#line 3950 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 431:

/* Line 677 of lalr1.cc  */
#line 3958 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 432:

/* Line 677 of lalr1.cc  */
#line 3962 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 433:

/* Line 677 of lalr1.cc  */
#line 3972 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all);
    }
    break;

  case 434:

/* Line 677 of lalr1.cc  */
#line 3976 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem);
    }
    break;

  case 435:

/* Line 677 of lalr1.cc  */
#line 3980 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix);
    }
    break;

  case 436:

/* Line 677 of lalr1.cc  */
#line 3989 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 437:

/* Line 677 of lalr1.cc  */
#line 3993 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 438:

/* Line 677 of lalr1.cc  */
#line 3997 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
     }
    break;

  case 439:

/* Line 677 of lalr1.cc  */
#line 4001 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
     }
    break;

  case 440:

/* Line 677 of lalr1.cc  */
#line 4009 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 441:

/* Line 677 of lalr1.cc  */
#line 4015 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 442:

/* Line 677 of lalr1.cc  */
#line 4025 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
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
#line 4065 "F:/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4077 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 454:

/* Line 677 of lalr1.cc  */
#line 4085 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 455:

/* Line 677 of lalr1.cc  */
#line 4092 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 456:

/* Line 677 of lalr1.cc  */
#line 4099 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 457:

/* Line 677 of lalr1.cc  */
#line 4110 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 458:

/* Line 677 of lalr1.cc  */
#line 4118 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 459:

/* Line 677 of lalr1.cc  */
#line 4122 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 460:

/* Line 677 of lalr1.cc  */
#line 4130 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 461:

/* Line 677 of lalr1.cc  */
#line 4138 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 462:

/* Line 677 of lalr1.cc  */
#line 4146 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 463:

/* Line 677 of lalr1.cc  */
#line 4200 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
        }
    break;

  case 464:

/* Line 677 of lalr1.cc  */
#line 4204 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 465:

/* Line 677 of lalr1.cc  */
#line 4217 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            ArgList *al = new ArgList( LOC((yyloc)) );
            al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
            (yyval.node) = al;
        }
    break;

  case 466:

/* Line 677 of lalr1.cc  */
#line 4223 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
                al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
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
#line 4237 "F:/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4253 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 472:

/* Line 677 of lalr1.cc  */
#line 4261 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

  case 473:

/* Line 677 of lalr1.cc  */
#line 4271 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

  case 474:

/* Line 677 of lalr1.cc  */
#line 4281 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

  case 475:

/* Line 677 of lalr1.cc  */
#line 4291 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

  case 476:

/* Line 677 of lalr1.cc  */
#line 4301 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

  case 477:

/* Line 677 of lalr1.cc  */
#line 4311 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

  case 478:

/* Line 677 of lalr1.cc  */
#line 4326 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
            decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = decl;
        }
    break;

  case 479:

/* Line 677 of lalr1.cc  */
#line 4332 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( decl )
                decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 480:

/* Line 677 of lalr1.cc  */
#line 4343 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
            dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = dal;
        }
    break;

  case 481:

/* Line 677 of lalr1.cc  */
#line 4349 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
            if ( dal )
                dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 482:

/* Line 677 of lalr1.cc  */
#line 4360 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttr(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node))
            );
        }
    break;

  case 485:

/* Line 677 of lalr1.cc  */
#line 4377 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 486:

/* Line 677 of lalr1.cc  */
#line 4382 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 487:

/* Line 677 of lalr1.cc  */
#line 4391 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
        }
    break;

  case 488:

/* Line 677 of lalr1.cc  */
#line 4395 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 489:

/* Line 677 of lalr1.cc  */
#line 4402 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = qacl;
        }
    break;

  case 490:

/* Line 677 of lalr1.cc  */
#line 4408 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = qacl;
        }
    break;

  case 491:

/* Line 677 of lalr1.cc  */
#line 4414 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 492:

/* Line 677 of lalr1.cc  */
#line 4422 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 493:

/* Line 677 of lalr1.cc  */
#line 4434 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
        }
    break;

  case 494:

/* Line 677 of lalr1.cc  */
#line 4438 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 495:

/* Line 677 of lalr1.cc  */
#line 4445 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = aacl;
        }
    break;

  case 496:

/* Line 677 of lalr1.cc  */
#line 4451 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = aacl;
        }
    break;

  case 497:

/* Line 677 of lalr1.cc  */
#line 4457 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if (aacl)
                aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 498:

/* Line 677 of lalr1.cc  */
#line 4464 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( aacl )
                aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 499:

/* Line 677 of lalr1.cc  */
#line 4475 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 500:

/* Line 677 of lalr1.cc  */
#line 4479 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 501:

/* Line 677 of lalr1.cc  */
#line 4489 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 502:

/* Line 677 of lalr1.cc  */
#line 4493 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 503:

/* Line 677 of lalr1.cc  */
#line 4503 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 504:

/* Line 677 of lalr1.cc  */
#line 4507 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 505:

/* Line 677 of lalr1.cc  */
#line 4511 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
        }
    break;

  case 506:

/* Line 677 of lalr1.cc  */
#line 4516 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
        }
    break;

  case 507:

/* Line 677 of lalr1.cc  */
#line 4525 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval))
            );
        }
    break;

  case 508:

/* Line 677 of lalr1.cc  */
#line 4531 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_lbrace
            );
        }
    break;

  case 509:

/* Line 677 of lalr1.cc  */
#line 4537 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_rbrace
            );
        }
    break;

  case 510:

/* Line 677 of lalr1.cc  */
#line 4543 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 511:

/* Line 677 of lalr1.cc  */
#line 4553 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 512:

/* Line 677 of lalr1.cc  */
#line 4557 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
        }
    break;

  case 513:

/* Line 677 of lalr1.cc  */
#line 4569 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 514:

/* Line 677 of lalr1.cc  */
#line 4573 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 515:

/* Line 677 of lalr1.cc  */
#line 4585 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
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
#line 4617 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 522:

/* Line 677 of lalr1.cc  */
#line 4625 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 523:

/* Line 677 of lalr1.cc  */
#line 4633 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (1)].sval))), NULL);
        }
    break;

  case 524:

/* Line 677 of lalr1.cc  */
#line 4637 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
        }
    break;

  case 525:

/* Line 677 of lalr1.cc  */
#line 4641 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 526:

/* Line 677 of lalr1.cc  */
#line 4645 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 527:

/* Line 677 of lalr1.cc  */
#line 4662 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (1)].sval))), NULL );
        }
    break;

  case 528:

/* Line 677 of lalr1.cc  */
#line 4666 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 529:

/* Line 677 of lalr1.cc  */
#line 4670 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 530:

/* Line 677 of lalr1.cc  */
#line 4674 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 531:

/* Line 677 of lalr1.cc  */
#line 4682 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 532:

/* Line 677 of lalr1.cc  */
#line 4690 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 533:

/* Line 677 of lalr1.cc  */
#line 4698 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (1)].sval)), NULL );
        }
    break;

  case 534:

/* Line 677 of lalr1.cc  */
#line 4702 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 535:

/* Line 677 of lalr1.cc  */
#line 4706 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 536:

/* Line 677 of lalr1.cc  */
#line 4710 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 537:

/* Line 677 of lalr1.cc  */
#line 4718 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)), false
            );
        }
    break;

  case 538:

/* Line 677 of lalr1.cc  */
#line 4724 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)), true
            );
        }
    break;

  case 539:

/* Line 677 of lalr1.cc  */
#line 4734 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 540:

/* Line 677 of lalr1.cc  */
#line 4742 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 541:

/* Line 677 of lalr1.cc  */
#line 4746 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 542:

/* Line 677 of lalr1.cc  */
#line 4750 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 543:

/* Line 677 of lalr1.cc  */
#line 4785 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 544:

/* Line 677 of lalr1.cc  */
#line 4791 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 545:

/* Line 677 of lalr1.cc  */
#line 4797 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
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
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 548:

/* Line 677 of lalr1.cc  */
#line 4815 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)),true );
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
#line 4823 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 551:

/* Line 677 of lalr1.cc  */
#line 4830 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 552:

/* Line 677 of lalr1.cc  */
#line 4836 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 553:

/* Line 677 of lalr1.cc  */
#line 4846 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
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
#line 4886 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 563:

/* Line 677 of lalr1.cc  */
#line 4894 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyKindTest( LOC((yyloc)) );
        }
    break;

  case 564:

/* Line 677 of lalr1.cc  */
#line 4902 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)) );
        }
    break;

  case 565:

/* Line 677 of lalr1.cc  */
#line 4906 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)) );
        }
    break;

  case 566:

/* Line 677 of lalr1.cc  */
#line 4910 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest(
                LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 567:

/* Line 677 of lalr1.cc  */
#line 4920 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TextTest( LOC((yyloc)) );
        }
    break;

  case 568:

/* Line 677 of lalr1.cc  */
#line 4928 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CommentTest( LOC((yyloc)));
        }
    break;

  case 569:

/* Line 677 of lalr1.cc  */
#line 4936 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
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
#line 4944 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 572:

/* Line 677 of lalr1.cc  */
#line 4952 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 573:

/* Line 677 of lalr1.cc  */
#line 4956 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 574:

/* Line 677 of lalr1.cc  */
#line 4962 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 575:

/* Line 677 of lalr1.cc  */
#line 4968 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 576:

/* Line 677 of lalr1.cc  */
#line 4972 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 577:

/* Line 677 of lalr1.cc  */
#line 4982 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 578:

/* Line 677 of lalr1.cc  */
#line 4990 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 579:

/* Line 677 of lalr1.cc  */
#line 4994 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 580:

/* Line 677 of lalr1.cc  */
#line 5000 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 677 of lalr1.cc  */
#line 5009 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 677 of lalr1.cc  */
#line 5018 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 583:

/* Line 677 of lalr1.cc  */
#line 5024 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 584:

/* Line 677 of lalr1.cc  */
#line 5030 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 585:

/* Line 677 of lalr1.cc  */
#line 5040 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 586:

/* Line 677 of lalr1.cc  */
#line 5057 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 587:

/* Line 677 of lalr1.cc  */
#line 5064 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 588:

/* Line 677 of lalr1.cc  */
#line 5079 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
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
#line 5119 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 591:

/* Line 677 of lalr1.cc  */
#line 5128 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
        }
    break;

  case 592:

/* Line 677 of lalr1.cc  */
#line 5137 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new InlineFunction(LOC ((yyloc)), &*(yysemantic_stack_[(3) - (2)].fnsig)->param, &*(yysemantic_stack_[(3) - (2)].fnsig)->ret, dynamic_cast<EnclosedExpr *>((yysemantic_stack_[(3) - (3)].expr)));
          delete (yysemantic_stack_[(3) - (2)].fnsig);
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
#line 5151 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 595:

/* Line 677 of lalr1.cc  */
#line 5160 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
        }
    break;

  case 596:

/* Line 677 of lalr1.cc  */
#line 5169 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 597:

/* Line 677 of lalr1.cc  */
#line 5173 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 598:

/* Line 677 of lalr1.cc  */
#line 5184 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 599:

/* Line 677 of lalr1.cc  */
#line 5201 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 600:

/* Line 677 of lalr1.cc  */
#line 5207 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 601:

/* Line 677 of lalr1.cc  */
#line 5213 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 602:

/* Line 677 of lalr1.cc  */
#line 5223 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 603:

/* Line 677 of lalr1.cc  */
#line 5227 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 604:

/* Line 677 of lalr1.cc  */
#line 5233 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 605:

/* Line 677 of lalr1.cc  */
#line 5239 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 606:

/* Line 677 of lalr1.cc  */
#line 5243 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 607:

/* Line 677 of lalr1.cc  */
#line 5249 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 608:

/* Line 677 of lalr1.cc  */
#line 5253 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 609:

/* Line 677 of lalr1.cc  */
#line 5259 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 610:

/* Line 677 of lalr1.cc  */
#line 5265 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 611:

/* Line 677 of lalr1.cc  */
#line 5272 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 612:

/* Line 677 of lalr1.cc  */
#line 5282 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 613:

/* Line 677 of lalr1.cc  */
#line 5287 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 614:

/* Line 677 of lalr1.cc  */
#line 5295 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 615:

/* Line 677 of lalr1.cc  */
#line 5301 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 616:

/* Line 677 of lalr1.cc  */
#line 5311 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 617:

/* Line 677 of lalr1.cc  */
#line 5333 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 618:

/* Line 677 of lalr1.cc  */
#line 5342 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 619:

/* Line 677 of lalr1.cc  */
#line 5348 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 620:

/* Line 677 of lalr1.cc  */
#line 5361 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 621:

/* Line 677 of lalr1.cc  */
#line 5375 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 622:

/* Line 677 of lalr1.cc  */
#line 5382 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 623:

/* Line 677 of lalr1.cc  */
#line 5388 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 624:

/* Line 677 of lalr1.cc  */
#line 5398 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 625:

/* Line 677 of lalr1.cc  */
#line 5403 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CatchExpr(LOC((yyloc)),*(yysemantic_stack_[(7) - (2)].name_test_list), static_cast<QName*>((yysemantic_stack_[(7) - (5)].expr)), NULL, NULL, (yysemantic_stack_[(7) - (7)].expr));
       delete (yysemantic_stack_[(7) - (2)].name_test_list);
    }
    break;

  case 626:

/* Line 677 of lalr1.cc  */
#line 5408 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

  case 627:

/* Line 677 of lalr1.cc  */
#line 5418 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

  case 628:

/* Line 677 of lalr1.cc  */
#line 5431 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 629:

/* Line 677 of lalr1.cc  */
#line 5437 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 630:

/* Line 677 of lalr1.cc  */
#line 5454 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new EvalExpr(LOC((yyloc)), dynamic_cast<VarGetsDeclList *> ((yysemantic_stack_[(7) - (3)].node)), (yysemantic_stack_[(7) - (6)].expr));
        }
    break;

  case 631:

/* Line 677 of lalr1.cc  */
#line 5458 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new EvalExpr( LOC((yyloc)), new VarGetsDeclList( LOC((yyloc)) ), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 632:

/* Line 677 of lalr1.cc  */
#line 5473 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 633:

/* Line 677 of lalr1.cc  */
#line 5481 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 634:

/* Line 677 of lalr1.cc  */
#line 5485 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 635:

/* Line 677 of lalr1.cc  */
#line 5492 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 636:

/* Line 677 of lalr1.cc  */
#line 5497 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 637:

/* Line 677 of lalr1.cc  */
#line 5505 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 638:

/* Line 677 of lalr1.cc  */
#line 5509 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 639:

/* Line 677 of lalr1.cc  */
#line 5516 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 640:

/* Line 677 of lalr1.cc  */
#line 5520 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 641:

/* Line 677 of lalr1.cc  */
#line 5527 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 642:

/* Line 677 of lalr1.cc  */
#line 5531 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 643:

/* Line 677 of lalr1.cc  */
#line 5538 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 644:

/* Line 677 of lalr1.cc  */
#line 5542 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 645:

/* Line 677 of lalr1.cc  */
#line 5551 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 677 of lalr1.cc  */
#line 5563 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 647:

/* Line 677 of lalr1.cc  */
#line 5567 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 648:

/* Line 677 of lalr1.cc  */
#line 5574 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 649:

/* Line 677 of lalr1.cc  */
#line 5578 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 650:

/* Line 677 of lalr1.cc  */
#line 5586 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 651:

/* Line 677 of lalr1.cc  */
#line 5594 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 652:

/* Line 677 of lalr1.cc  */
#line 5602 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 653:

/* Line 677 of lalr1.cc  */
#line 5606 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 654:

/* Line 677 of lalr1.cc  */
#line 5613 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 655:

/* Line 677 of lalr1.cc  */
#line 5617 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 656:

/* Line 677 of lalr1.cc  */
#line 5625 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 657:

/* Line 677 of lalr1.cc  */
#line 5636 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 658:

/* Line 677 of lalr1.cc  */
#line 5640 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 659:

/* Line 677 of lalr1.cc  */
#line 5648 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 660:

/* Line 677 of lalr1.cc  */
#line 5660 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 661:

/* Line 677 of lalr1.cc  */
#line 5666 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 662:

/* Line 677 of lalr1.cc  */
#line 5675 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 663:

/* Line 677 of lalr1.cc  */
#line 5679 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
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
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 666:

/* Line 677 of lalr1.cc  */
#line 5695 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 667:

/* Line 677 of lalr1.cc  */
#line 5702 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 668:

/* Line 677 of lalr1.cc  */
#line 5706 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 669:

/* Line 677 of lalr1.cc  */
#line 5713 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 670:

/* Line 677 of lalr1.cc  */
#line 5717 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
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
#line 5741 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 676:

/* Line 677 of lalr1.cc  */
#line 5749 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 677:

/* Line 677 of lalr1.cc  */
#line 5757 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 678:

/* Line 677 of lalr1.cc  */
#line 5769 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 679:

/* Line 677 of lalr1.cc  */
#line 5781 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 680:

/* Line 677 of lalr1.cc  */
#line 5785 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 681:

/* Line 677 of lalr1.cc  */
#line 5789 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 682:

/* Line 677 of lalr1.cc  */
#line 5797 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 683:

/* Line 677 of lalr1.cc  */
#line 5803 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
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
#line 5841 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 692:

/* Line 677 of lalr1.cc  */
#line 5849 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 693:

/* Line 677 of lalr1.cc  */
#line 5853 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 694:

/* Line 677 of lalr1.cc  */
#line 5857 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 695:

/* Line 677 of lalr1.cc  */
#line 5861 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 696:

/* Line 677 of lalr1.cc  */
#line 5869 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 697:

/* Line 677 of lalr1.cc  */
#line 5875 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 698:

/* Line 677 of lalr1.cc  */
#line 5885 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 699:

/* Line 677 of lalr1.cc  */
#line 5895 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::with );
        }
    break;

  case 700:

/* Line 677 of lalr1.cc  */
#line 5899 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::without );
        }
    break;

  case 701:

/* Line 677 of lalr1.cc  */
#line 5907 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 677 of lalr1.cc  */
#line 5917 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 677 of lalr1.cc  */
#line 5928 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 704:

/* Line 677 of lalr1.cc  */
#line 5935 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 705:

/* Line 677 of lalr1.cc  */
#line 5939 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 706:

/* Line 677 of lalr1.cc  */
#line 5946 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 707:

/* Line 677 of lalr1.cc  */
#line 5950 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 708:

/* Line 677 of lalr1.cc  */
#line 5957 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 709:

/* Line 677 of lalr1.cc  */
#line 5962 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 710:

/* Line 677 of lalr1.cc  */
#line 5971 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 711:

/* Line 677 of lalr1.cc  */
#line 5980 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = NULL;
        }
    break;

  case 712:

/* Line 677 of lalr1.cc  */
#line 5984 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 713:

/* Line 677 of lalr1.cc  */
#line 5991 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 714:

/* Line 677 of lalr1.cc  */
#line 5995 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 715:

/* Line 677 of lalr1.cc  */
#line 6003 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 677 of lalr1.cc  */
#line 6012 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 717:

/* Line 677 of lalr1.cc  */
#line 6019 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 718:

/* Line 677 of lalr1.cc  */
#line 6029 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 719:

/* Line 677 of lalr1.cc  */
#line 6033 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 720:

/* Line 677 of lalr1.cc  */
#line 6040 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 721:

/* Line 677 of lalr1.cc  */
#line 6046 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 722:

/* Line 677 of lalr1.cc  */
#line 6055 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 723:

/* Line 677 of lalr1.cc  */
#line 6059 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 724:

/* Line 677 of lalr1.cc  */
#line 6066 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 725:

/* Line 677 of lalr1.cc  */
#line 6071 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 726:

/* Line 677 of lalr1.cc  */
#line 6083 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 727:

/* Line 677 of lalr1.cc  */
#line 6091 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 728:

/* Line 677 of lalr1.cc  */
#line 6103 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 729:

/* Line 677 of lalr1.cc  */
#line 6111 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 730:

/* Line 677 of lalr1.cc  */
#line 6115 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 731:

/* Line 677 of lalr1.cc  */
#line 6123 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 732:

/* Line 677 of lalr1.cc  */
#line 6127 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 733:

/* Line 677 of lalr1.cc  */
#line 6131 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 734:

/* Line 677 of lalr1.cc  */
#line 6139 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 735:

/* Line 677 of lalr1.cc  */
#line 6147 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 736:

/* Line 677 of lalr1.cc  */
#line 6151 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 737:

/* Line 677 of lalr1.cc  */
#line 6155 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 738:

/* Line 677 of lalr1.cc  */
#line 6159 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 739:

/* Line 677 of lalr1.cc  */
#line 6167 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 740:

/* Line 677 of lalr1.cc  */
#line 6175 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 741:

/* Line 677 of lalr1.cc  */
#line 6187 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 742:

/* Line 677 of lalr1.cc  */
#line 6191 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 743:

/* Line 677 of lalr1.cc  */
#line 6199 "F:/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 746:

/* Line 677 of lalr1.cc  */
#line 6217 "F:/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 677 of lalr1.cc  */
#line 6230 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 749:

/* Line 677 of lalr1.cc  */
#line 6231 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 750:

/* Line 677 of lalr1.cc  */
#line 6232 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 751:

/* Line 677 of lalr1.cc  */
#line 6233 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 752:

/* Line 677 of lalr1.cc  */
#line 6234 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 753:

/* Line 677 of lalr1.cc  */
#line 6235 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 754:

/* Line 677 of lalr1.cc  */
#line 6236 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 755:

/* Line 677 of lalr1.cc  */
#line 6237 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 756:

/* Line 677 of lalr1.cc  */
#line 6238 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 757:

/* Line 677 of lalr1.cc  */
#line 6239 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 758:

/* Line 677 of lalr1.cc  */
#line 6240 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 759:

/* Line 677 of lalr1.cc  */
#line 6241 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 760:

/* Line 677 of lalr1.cc  */
#line 6242 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 761:

/* Line 677 of lalr1.cc  */
#line 6243 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 762:

/* Line 677 of lalr1.cc  */
#line 6244 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 764:

/* Line 677 of lalr1.cc  */
#line 6249 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 765:

/* Line 677 of lalr1.cc  */
#line 6250 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 766:

/* Line 677 of lalr1.cc  */
#line 6251 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 767:

/* Line 677 of lalr1.cc  */
#line 6252 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 768:

/* Line 677 of lalr1.cc  */
#line 6253 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 769:

/* Line 677 of lalr1.cc  */
#line 6254 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 770:

/* Line 677 of lalr1.cc  */
#line 6255 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 771:

/* Line 677 of lalr1.cc  */
#line 6256 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 772:

/* Line 677 of lalr1.cc  */
#line 6257 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 773:

/* Line 677 of lalr1.cc  */
#line 6258 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 774:

/* Line 677 of lalr1.cc  */
#line 6259 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 775:

/* Line 677 of lalr1.cc  */
#line 6260 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 776:

/* Line 677 of lalr1.cc  */
#line 6261 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 777:

/* Line 677 of lalr1.cc  */
#line 6262 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 778:

/* Line 677 of lalr1.cc  */
#line 6263 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 779:

/* Line 677 of lalr1.cc  */
#line 6264 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 780:

/* Line 677 of lalr1.cc  */
#line 6265 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 781:

/* Line 677 of lalr1.cc  */
#line 6266 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 782:

/* Line 677 of lalr1.cc  */
#line 6267 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 783:

/* Line 677 of lalr1.cc  */
#line 6268 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 784:

/* Line 677 of lalr1.cc  */
#line 6269 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 785:

/* Line 677 of lalr1.cc  */
#line 6270 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 786:

/* Line 677 of lalr1.cc  */
#line 6271 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 787:

/* Line 677 of lalr1.cc  */
#line 6272 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 788:

/* Line 677 of lalr1.cc  */
#line 6273 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 789:

/* Line 677 of lalr1.cc  */
#line 6274 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 790:

/* Line 677 of lalr1.cc  */
#line 6275 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 791:

/* Line 677 of lalr1.cc  */
#line 6276 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 792:

/* Line 677 of lalr1.cc  */
#line 6277 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 793:

/* Line 677 of lalr1.cc  */
#line 6278 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 794:

/* Line 677 of lalr1.cc  */
#line 6279 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 795:

/* Line 677 of lalr1.cc  */
#line 6280 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 796:

/* Line 677 of lalr1.cc  */
#line 6281 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 797:

/* Line 677 of lalr1.cc  */
#line 6282 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 798:

/* Line 677 of lalr1.cc  */
#line 6283 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 799:

/* Line 677 of lalr1.cc  */
#line 6284 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 800:

/* Line 677 of lalr1.cc  */
#line 6285 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 801:

/* Line 677 of lalr1.cc  */
#line 6286 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 802:

/* Line 677 of lalr1.cc  */
#line 6287 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 803:

/* Line 677 of lalr1.cc  */
#line 6288 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 804:

/* Line 677 of lalr1.cc  */
#line 6289 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 805:

/* Line 677 of lalr1.cc  */
#line 6290 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 806:

/* Line 677 of lalr1.cc  */
#line 6291 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 807:

/* Line 677 of lalr1.cc  */
#line 6292 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 808:

/* Line 677 of lalr1.cc  */
#line 6293 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 809:

/* Line 677 of lalr1.cc  */
#line 6294 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 810:

/* Line 677 of lalr1.cc  */
#line 6295 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 811:

/* Line 677 of lalr1.cc  */
#line 6296 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 812:

/* Line 677 of lalr1.cc  */
#line 6297 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 813:

/* Line 677 of lalr1.cc  */
#line 6298 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 814:

/* Line 677 of lalr1.cc  */
#line 6299 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 815:

/* Line 677 of lalr1.cc  */
#line 6300 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 816:

/* Line 677 of lalr1.cc  */
#line 6301 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 817:

/* Line 677 of lalr1.cc  */
#line 6302 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 818:

/* Line 677 of lalr1.cc  */
#line 6303 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 819:

/* Line 677 of lalr1.cc  */
#line 6304 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 820:

/* Line 677 of lalr1.cc  */
#line 6305 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 821:

/* Line 677 of lalr1.cc  */
#line 6306 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 822:

/* Line 677 of lalr1.cc  */
#line 6307 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 823:

/* Line 677 of lalr1.cc  */
#line 6308 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 824:

/* Line 677 of lalr1.cc  */
#line 6309 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 825:

/* Line 677 of lalr1.cc  */
#line 6310 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 826:

/* Line 677 of lalr1.cc  */
#line 6311 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 827:

/* Line 677 of lalr1.cc  */
#line 6312 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 828:

/* Line 677 of lalr1.cc  */
#line 6313 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 829:

/* Line 677 of lalr1.cc  */
#line 6314 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 830:

/* Line 677 of lalr1.cc  */
#line 6315 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 831:

/* Line 677 of lalr1.cc  */
#line 6316 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 832:

/* Line 677 of lalr1.cc  */
#line 6317 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 833:

/* Line 677 of lalr1.cc  */
#line 6318 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 834:

/* Line 677 of lalr1.cc  */
#line 6319 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 835:

/* Line 677 of lalr1.cc  */
#line 6320 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 836:

/* Line 677 of lalr1.cc  */
#line 6321 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 837:

/* Line 677 of lalr1.cc  */
#line 6322 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 838:

/* Line 677 of lalr1.cc  */
#line 6323 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 839:

/* Line 677 of lalr1.cc  */
#line 6324 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 840:

/* Line 677 of lalr1.cc  */
#line 6325 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 841:

/* Line 677 of lalr1.cc  */
#line 6326 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 842:

/* Line 677 of lalr1.cc  */
#line 6327 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 843:

/* Line 677 of lalr1.cc  */
#line 6328 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 844:

/* Line 677 of lalr1.cc  */
#line 6329 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 845:

/* Line 677 of lalr1.cc  */
#line 6330 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 846:

/* Line 677 of lalr1.cc  */
#line 6331 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 847:

/* Line 677 of lalr1.cc  */
#line 6332 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 848:

/* Line 677 of lalr1.cc  */
#line 6333 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 849:

/* Line 677 of lalr1.cc  */
#line 6334 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 850:

/* Line 677 of lalr1.cc  */
#line 6335 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 851:

/* Line 677 of lalr1.cc  */
#line 6336 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 852:

/* Line 677 of lalr1.cc  */
#line 6337 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 853:

/* Line 677 of lalr1.cc  */
#line 6338 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 854:

/* Line 677 of lalr1.cc  */
#line 6339 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 855:

/* Line 677 of lalr1.cc  */
#line 6340 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 856:

/* Line 677 of lalr1.cc  */
#line 6341 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 857:

/* Line 677 of lalr1.cc  */
#line 6342 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 858:

/* Line 677 of lalr1.cc  */
#line 6343 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 859:

/* Line 677 of lalr1.cc  */
#line 6344 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 860:

/* Line 677 of lalr1.cc  */
#line 6345 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 861:

/* Line 677 of lalr1.cc  */
#line 6346 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 862:

/* Line 677 of lalr1.cc  */
#line 6347 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 863:

/* Line 677 of lalr1.cc  */
#line 6348 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 864:

/* Line 677 of lalr1.cc  */
#line 6349 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 865:

/* Line 677 of lalr1.cc  */
#line 6350 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 866:

/* Line 677 of lalr1.cc  */
#line 6351 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 867:

/* Line 677 of lalr1.cc  */
#line 6352 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 868:

/* Line 677 of lalr1.cc  */
#line 6353 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 869:

/* Line 677 of lalr1.cc  */
#line 6354 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 870:

/* Line 677 of lalr1.cc  */
#line 6355 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 871:

/* Line 677 of lalr1.cc  */
#line 6356 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 872:

/* Line 677 of lalr1.cc  */
#line 6357 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 873:

/* Line 677 of lalr1.cc  */
#line 6358 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 874:

/* Line 677 of lalr1.cc  */
#line 6359 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 875:

/* Line 677 of lalr1.cc  */
#line 6360 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 876:

/* Line 677 of lalr1.cc  */
#line 6361 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 877:

/* Line 677 of lalr1.cc  */
#line 6362 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 878:

/* Line 677 of lalr1.cc  */
#line 6363 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 879:

/* Line 677 of lalr1.cc  */
#line 6364 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 880:

/* Line 677 of lalr1.cc  */
#line 6365 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 881:

/* Line 677 of lalr1.cc  */
#line 6366 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 882:

/* Line 677 of lalr1.cc  */
#line 6367 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 883:

/* Line 677 of lalr1.cc  */
#line 6368 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 884:

/* Line 677 of lalr1.cc  */
#line 6369 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 885:

/* Line 677 of lalr1.cc  */
#line 6370 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 886:

/* Line 677 of lalr1.cc  */
#line 6371 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 887:

/* Line 677 of lalr1.cc  */
#line 6372 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 888:

/* Line 677 of lalr1.cc  */
#line 6373 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 889:

/* Line 677 of lalr1.cc  */
#line 6374 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 890:

/* Line 677 of lalr1.cc  */
#line 6375 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 891:

/* Line 677 of lalr1.cc  */
#line 6376 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 892:

/* Line 677 of lalr1.cc  */
#line 6377 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 893:

/* Line 677 of lalr1.cc  */
#line 6378 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 894:

/* Line 677 of lalr1.cc  */
#line 6379 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 895:

/* Line 677 of lalr1.cc  */
#line 6380 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 896:

/* Line 677 of lalr1.cc  */
#line 6381 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 897:

/* Line 677 of lalr1.cc  */
#line 6382 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 898:

/* Line 677 of lalr1.cc  */
#line 6383 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 899:

/* Line 677 of lalr1.cc  */
#line 6384 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 900:

/* Line 677 of lalr1.cc  */
#line 6385 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 901:

/* Line 677 of lalr1.cc  */
#line 6386 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 902:

/* Line 677 of lalr1.cc  */
#line 6387 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 903:

/* Line 677 of lalr1.cc  */
#line 6388 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 904:

/* Line 677 of lalr1.cc  */
#line 6389 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 905:

/* Line 677 of lalr1.cc  */
#line 6390 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("deterministic"))); }
    break;

  case 906:

/* Line 677 of lalr1.cc  */
#line 6391 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nondeterministic"))); }
    break;

  case 907:

/* Line 677 of lalr1.cc  */
#line 6392 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 908:

/* Line 677 of lalr1.cc  */
#line 6393 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 909:

/* Line 677 of lalr1.cc  */
#line 6394 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 910:

/* Line 677 of lalr1.cc  */
#line 6395 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("block"))); }
    break;

  case 911:

/* Line 677 of lalr1.cc  */
#line 6396 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 912:

/* Line 677 of lalr1.cc  */
#line 6397 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 913:

/* Line 677 of lalr1.cc  */
#line 6398 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 914:

/* Line 677 of lalr1.cc  */
#line 6399 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 915:

/* Line 677 of lalr1.cc  */
#line 6400 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 916:

/* Line 677 of lalr1.cc  */
#line 6401 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 917:

/* Line 677 of lalr1.cc  */
#line 6402 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eval"))); }
    break;

  case 918:

/* Line 677 of lalr1.cc  */
#line 6403 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 919:

/* Line 677 of lalr1.cc  */
#line 6404 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 920:

/* Line 677 of lalr1.cc  */
#line 6405 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 921:

/* Line 677 of lalr1.cc  */
#line 6406 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 922:

/* Line 677 of lalr1.cc  */
#line 6407 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 923:

/* Line 677 of lalr1.cc  */
#line 6408 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 924:

/* Line 677 of lalr1.cc  */
#line 6409 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 925:

/* Line 677 of lalr1.cc  */
#line 6410 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 926:

/* Line 677 of lalr1.cc  */
#line 6411 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 927:

/* Line 677 of lalr1.cc  */
#line 6412 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 928:

/* Line 677 of lalr1.cc  */
#line 6413 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 929:

/* Line 677 of lalr1.cc  */
#line 6414 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 930:

/* Line 677 of lalr1.cc  */
#line 6415 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 931:

/* Line 677 of lalr1.cc  */
#line 6416 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 932:

/* Line 677 of lalr1.cc  */
#line 6417 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 933:

/* Line 677 of lalr1.cc  */
#line 6418 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 934:

/* Line 677 of lalr1.cc  */
#line 6419 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 935:

/* Line 677 of lalr1.cc  */
#line 6420 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 936:

/* Line 677 of lalr1.cc  */
#line 6421 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 937:

/* Line 677 of lalr1.cc  */
#line 6422 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 938:

/* Line 677 of lalr1.cc  */
#line 6423 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 939:

/* Line 677 of lalr1.cc  */
#line 6424 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 940:

/* Line 677 of lalr1.cc  */
#line 6425 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 941:

/* Line 677 of lalr1.cc  */
#line 6426 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 942:

/* Line 677 of lalr1.cc  */
#line 6427 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 943:

/* Line 677 of lalr1.cc  */
#line 6428 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 944:

/* Line 677 of lalr1.cc  */
#line 6429 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 945:

/* Line 677 of lalr1.cc  */
#line 6430 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 946:

/* Line 677 of lalr1.cc  */
#line 6431 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 947:

/* Line 677 of lalr1.cc  */
#line 6432 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 948:

/* Line 677 of lalr1.cc  */
#line 6433 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 949:

/* Line 677 of lalr1.cc  */
#line 6434 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 950:

/* Line 677 of lalr1.cc  */
#line 6435 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 951:

/* Line 677 of lalr1.cc  */
#line 6436 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 952:

/* Line 677 of lalr1.cc  */
#line 6437 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 953:

/* Line 677 of lalr1.cc  */
#line 6438 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 954:

/* Line 677 of lalr1.cc  */
#line 6439 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 955:

/* Line 677 of lalr1.cc  */
#line 6440 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 956:

/* Line 677 of lalr1.cc  */
#line 6441 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 957:

/* Line 677 of lalr1.cc  */
#line 6442 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 958:

/* Line 677 of lalr1.cc  */
#line 6443 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 959:

/* Line 677 of lalr1.cc  */
#line 6444 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 960:

/* Line 677 of lalr1.cc  */
#line 6445 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 961:

/* Line 677 of lalr1.cc  */
#line 6446 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 962:

/* Line 677 of lalr1.cc  */
#line 6447 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 963:

/* Line 677 of lalr1.cc  */
#line 6448 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 964:

/* Line 677 of lalr1.cc  */
#line 6453 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { 
          // EQName's namespace URI value is whitespace normalized according to the rules for the xs:anyURI type
          std::string uri = "\"" + SYMTAB((yysemantic_stack_[(3) - (1)].sval)) + "\"";
          std::string eqname = SYMTAB(driver.symtab.put_uri(uri.c_str(), uri.size())) + ":" + SYMTAB((yysemantic_stack_[(3) - (3)].sval));
          (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT(eqname.c_str())), true); 
        }
    break;

  case 965:

/* Line 677 of lalr1.cc  */
#line 6459 "F:/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;



/* Line 677 of lalr1.cc  */
#line 11563 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1379;
  const short int
  xquery_parser::yypact_[] =
  {
      2237, -1379, -1379,  2536,  2834,  3132, -1379, -1379,   178,  1612,
     253, -1379, -1379, -1379,   297, -1379, -1379, -1379, -1379,    17,
     196,   402,   298,    43,   319,   353,   558, -1379,   -46, -1379,
   -1379, -1379, -1379, -1379, -1379, -1379,   550, -1379,   376,   424,
   -1379,   427, -1379, -1379,   514, -1379,   552, -1379,   491,   513,
   -1379,   145, -1379, -1379, -1379, -1379, -1379, -1379, -1379, -1379,
   -1379, -1379, -1379, -1379, -1379,   554,   569, -1379, -1379, -1379,
   -1379,   378,  8496, -1379, -1379, -1379,   592, -1379, -1379, -1379,
   -1379, -1379,   610,   632, -1379, -1379, 11676, -1379, -1379, -1379,
   -1379, -1379, -1379, -1379, -1379,   612, -1379, -1379,   636,   637,
   -1379, -1379, -1379, -1379, -1379, -1379, -1379,  3430, 11676, -1379,
   -1379, -1379, -1379, -1379, -1379, -1379,   609, -1379, -1379,   641,
    9382, -1379,  9674,   645,   646, -1379, -1379, -1379,   652, -1379,
    8198, -1379, -1379, -1379, -1379, -1379, -1379,   622, -1379, -1379,
   -1379, -1379, -1379, -1379, -1379, -1379,    34,   561, -1379, -1379,
   -1379, -1379, -1379, -1379, -1379, -1379,   -77,   621,   369, -1379,
     555,   389, -1379, -1379, -1379, -1379, -1379, -1379,   660, -1379,
     628,   544,   545,   542, -1379, -1379,   631,   635, -1379,   671,
   -1379, -1379, -1379, -1379, -1379, -1379, -1379, -1379, -1379, -1379,
   -1379, -1379, -1379, -1379, -1379, -1379, -1379, -1379, -1379, -1379,
   -1379, -1379, -1379, -1379, -1379, -1379, -1379, -1379, -1379, -1379,
   -1379, -1379, -1379, -1379, -1379, -1379, -1379, -1379, -1379, -1379,
   -1379, -1379, -1379, -1379, -1379, -1379, -1379, -1379, -1379, -1379,
   -1379, -1379, -1379, -1379, -1379, -1379, -1379, -1379, -1379, -1379,
    5516,   789, -1379,  5814, -1379, -1379,   452,    48,    52, -1379,
   -1379, -1379, -1379, -1379, -1379, -1379, -1379, -1379, -1379, -1379,
   -1379, -1379, -1379, -1379, -1379, -1379, -1379,   522, -1379, -1379,
   -1379, -1379, -1379, -1379, -1379, -1379, -1379, -1379, -1379, -1379,
   -1379,    -6, -1379, -1379, -1379, -1379,   303, -1379, -1379, -1379,
   -1379, -1379, -1379,   626,   699, -1379,   701,   546,   383,   244,
     403,    10, -1379,   746,   601,   697,   708,  6112, -1379, -1379,
   -1379,   -24, -1379, -1379,  8198, -1379,   495, -1379,   649,  8496,
   -1379,   649,  8496, -1379, -1379, -1379,   543, -1379, -1379, -1379,
   -1379, -1379, -1379, -1379, -1379, -1379, -1379, -1379, -1379, -1379,
   -1379, -1379, -1379, -1379, -1379, -1379, -1379, -1379, -1379, -1379,
   -1379, -1379, -1379, -1379, -1379, -1379, -1379, -1379, -1379, -1379,
   -1379, -1379, -1379, -1379, -1379, -1379, -1379, -1379, -1379, -1379,
     678,   666,   656, -1379, -1379, -1379, -1379, -1379, -1379,   630,
   -1379,   638, -1379,   640,   659,   788,   150,   209,   -32, 11962,
   11676,   -38,   771,   772,   773, 11676,   673,   709,   470,  9382,
   -1379, -1379,   496,   422,   580, 11676, -1379, -1379, -1379, -1379,
   -1379,   535, 11676,   533,   536,   425,   531,   600, -1379,   566,
   -1379, -1379, -1379, -1379, -1379,  9382,  6410,   650,  6410,    31,
    6410, 10246,  6410,   562,   564, 11676,   718,   -21,   685,  6410,
     837,    63,    49, 11676,   731,   711,   744, -1379,  6410,  9088,
   11676, 11676, 11676, 11676,  6410,   667,  6410,  6410, 11676,  6410,
     702,   707, -1379, -1379, -1379,  6410, 10532, -1379,   705, -1379,
     706, -1379, -1379, -1379, -1379, -1379,   710, -1379, -1379,   712,
   -1379, -1379, -1379, -1379, -1379,   713, -1379, -1379, -1379, -1379,
   -1379, -1379, -1379, -1379, -1379, -1379, -1379, -1379, -1379, -1379,
   -1379, -1379, -1379, -1379, -1379, -1379, -1379, -1379, -1379, -1379,
   -1379, -1379, -1379, -1379, -1379, -1379, -1379, -1379, -1379, -1379,
   -1379, -1379, -1379, -1379, -1379, -1379, 11676, -1379, -1379, -1379,
     680,   831,  6410, -1379, -1379,    90, -1379, -1379, -1379,   853,
   -1379, -1379, -1379, -1379,  6410,   658, -1379,   846,  6410,  6410,
     689,  6410,  6410,  6410,  6410,   648, 11676, -1379, -1379, -1379,
   -1379,  6410,  6410,  6410, 11676, -1379, -1379, -1379, -1379,  1612,
     558,    60,    66,   875,  6708,  6708,  7006,  7006,   739,  6410,
    6410, -1379,  6410,   764,    43,   -46,   715,   714,   716,  6410,
    6410, -1379, -1379, -1379, -1379, -1379, -1379, -1379,  7304,  7304,
    7304, -1379,  7304,  7304, -1379,  7304, -1379,  7304, -1379, -1379,
   -1379, -1379, -1379, -1379, -1379,  7304,  7304,   813,  7304,  7304,
    7304,  7304,  7304,  7304,  7304,  7304,  7304,  7304,  7304,   662,
     803,   804,   814, -1379, -1379, -1379,  3728, -1379, -1379,  8198,
    8198,  6410,   649, -1379, -1379,   649, -1379,  4026,   649,  9382,
     761,  4324, -1379, -1379, -1379,   371, -1379, -1379, -1379, -1379,
   -1379,   805,   818,   319,   898, -1379, -1379, 11962, -1379, 11962,
     833,   278, 11676,   767,   768,   833,   788,   802,   798, -1379,
   -1379, -1379, -1379, -1379,    28,   690,   -20, -1379,   643, -1379,
   -1379, -1379, -1379, 11676, 11676, 11676, -1379,   825, -1379, -1379,
     812,   765, -1379,   766,   706,   424, -1379,   758,   769,   774,
   -1379,     5,    14,   775, -1379, -1379,   841, -1379,    11, 11676,
      -9, 11676,   856,    15, -1379,  6410, -1379,   770, -1379,  9382,
     865,   918,  9382,   788,   867,   235, 11676,  6410,   -46,   781,
     779, -1379,   780,   782,   783,   826,   -11, -1379,    42,   787,
   -1379,   785,   786,   821, -1379,   791,  6410,  6410,   792, -1379,
      38,    47,     3, -1379, 11676,   831, -1379,     8,   793, -1379,
   -1379, -1379,   794, -1379,   195, -1379, -1379, -1379,   104,   307,
     884,   747,   756,   -29, -1379,   840,  7602, -1379,   799,   806,
      74, -1379, -1379,   452,   498,   955,   955, -1379,    68, -1379,
   -1379,    69, -1379, -1379,   644, -1379, -1379, -1379, -1379,  6410,
   -1379, -1379,    -3, 11676,   819,  6410,   870, -1379, -1379,   699,
   -1379, -1379, -1379, -1379, -1379,  7304, -1379, -1379, -1379,    16,
     244,   244,   398,   403,   403,   403,   403,    10,    10, -1379,
   -1379, 11104, 11104, 11676, 11676, -1379,   808, -1379, -1379,   809,
   -1379, -1379, -1379,    79, -1379, -1379, -1379,    91, -1379,   108,
   -1379,     9,   439,   468, -1379,   319,   319, -1379, -1379, -1379,
   -1379, -1379, -1379, -1379, -1379, -1379, -1379,   833, -1379,   861,
   11390,   854,  6410, -1379, -1379, -1379,   900,   788,   788,   833,
   -1379,   599,   788,   417, 11676,   270,   405,   969, -1379, -1379,
     717,    26, -1379, -1379, -1379, -1379, -1379, -1379, -1379, -1379,
   -1379, -1379, -1379,    28,    80,   443, -1379,   776,   382,   -14,
     700, 11676,   788, -1379, -1379, -1379, -1379,   845, 11676, -1379,
   11676, -1379, -1379,   882,   874, 11104,   886,  6410,   -49,   859,
      12,    56,   753, -1379, -1379,   497,    -9,   900, 11104,   890,
     914,   827,   815,   878,   788,   855,   881,   917,   788,  6410,
     -60, -1379, -1379, -1379,   863, -1379, -1379, -1379, -1379,  6410,
     899,  6410,  6410,   871, -1379,   919,   920,  6410, -1379,   838,
     839,   868, 11676, -1379, 11676, -1379,  6410,   990, -1379,    25,
   -1379,   157, -1379, -1379,   997, -1379,   479,  6410,  6410,  6410,
     488,  6410,  6410,  6410,  6410,  6410,  6410,   908,  6410,  6410,
     909,    -2,   844,   628,   784,   877,   913,    71,    20,   644,
    7006,  7006,  7006,   953, -1379, -1379, -1379,  6410,   556,   927,
   -1379, 11676,   929, -1379, -1379,  6410,    16,   334,   264, -1379,
     752,   173,   790,   778, -1379, -1379,   580, -1379,   777,   257,
     889,   891, 11390,   893, -1379,   310, -1379, -1379, -1379, -1379,
   -1379, -1379, -1379, -1379, -1379,   896, -1379, -1379, -1379,  6410,
   -1379, -1379,   371, -1379, -1379, -1379, -1379, -1379, -1379,  6410,
   -1379,   503,   518, -1379,  1014,   540, -1379, -1379, -1379, -1379,
   -1379, -1379, -1379, -1379, -1379,   795, -1379, -1379,  1022, -1379,
   -1379, -1379, -1379, -1379,   335,  1023, -1379,   560, -1379, -1379,
   -1379,   705,   196,   710,   376,   712,   713,   621,   816,   310,
     828,   829,  7900,   797,   750,    80, -1379,   834,   900,   872,
    4622,   866,   876,   922,   880,   883, 11676,   192, -1379, 11676,
   -1379,  6410,   910,  6410,   934,  6410,    -5,   924,  6410,   925,
   -1379,   946,   951,  6410, 11676,   591,   995, -1379, -1379, -1379,
   -1379, -1379, -1379, 11104, -1379,  6410,   788,   967, -1379, -1379,
   -1379,   788,   967, -1379,  6410,   933,  4920, -1379, 11676, -1379,
   -1379,  6410,  6410,   301, -1379,    -7, 10818,   394, -1379,   892,
   -1379, -1379,  5218,   895,   901, -1379, -1379,   945, -1379,   286,
   -1379, -1379,  1070, -1379, -1379, 11676, -1379, -1379,   396, -1379,
   -1379, -1379,   904,   847,   848, -1379, -1379, -1379,   857,   858,
   -1379, -1379, -1379, -1379, -1379,   849, 11676,   905, -1379, 11676,
   -1379,   909, -1379, -1379, -1379,  8794,   784, -1379,  6410, 11676,
     955,   360, -1379, -1379, -1379,   927, -1379,   788, -1379,   608,
   -1379,   147,   980, -1379,  6410,   991,   870,   912,   911, -1379,
      16,   850, -1379, -1379,   143, -1379,   342,    30,   851,    16,
     342,  7304, -1379,   313, -1379, -1379, -1379, -1379, -1379, -1379,
      16,   952,   820,   690,    30, -1379, -1379,   817,  1025, -1379,
   -1379, -1379,  9960,   921,   923,   926, -1379, -1379, -1379, -1379,
   -1379, -1379, -1379,   928, -1379, -1379, -1379,  6410, -1379, -1379,
   -1379, -1379,  1077,   -36,  1078,   -36,   843,  1004, -1379, -1379,
   -1379, -1379,   947, 11676,   862,   816,  7900, -1379, -1379, -1379,
     932, -1379, -1379, -1379, -1379, -1379, -1379,  6410,   971, -1379,
   -1379,  6410, -1379,   220, -1379,  6410,   973,  6410, -1379,  6410,
   11676, 11676, -1379,   475, -1379,  6410, -1379,   996,  1024,   788,
     967, -1379,  6410, -1379,   939, -1379, -1379, -1379,   938, -1379,
    6410,  6410, 11676,   940,    -1, -1379, -1379, -1379,   941, -1379,
   -1379,   990, 11676,   486, -1379,   990, 11676, -1379, -1379,  6410,
    6410,  6410,  6410,  6410, -1379,  6410,   280, -1379, -1379,   240,
   -1379,   943, -1379, -1379, -1379, -1379,   980, -1379, -1379, -1379,
     788, -1379, -1379, -1379, -1379, -1379,   944,  7304, -1379, -1379,
   -1379, -1379, -1379,    77,  7304,  7304,   377, -1379,   790, -1379,
     350, -1379,   778,    16,   976, -1379, -1379,   852, -1379, -1379,
   -1379, -1379,  1035,   948, -1379,   113, -1379, -1379, -1379, -1379,
       6, -1379,    39,    39, -1379,   -36, -1379, -1379,   166, -1379,
    1103,    30,  1036,   949,  7900,   -53,   860, -1379,   970, -1379,
   -1379,  6410, -1379,  6410,   992, -1379,  6410, -1379, -1379, -1379,
    1083, -1379, -1379,  6410,   788, -1379, -1379, -1379,  6410, -1379,
   -1379,  1046,  6410, 11676,  6410, -1379,   -10,   990, 11676,   950,
     990, -1379, -1379, -1379, -1379, -1379, -1379,  6410,  1001,  1026,
    8794, -1379, -1379, -1379, -1379, -1379,   403,  7304,  7304,   398,
     430, -1379, -1379, -1379, -1379, -1379, -1379,  6410, -1379, 11104,
   -1379, 11104,  1050, -1379, -1379, -1379, -1379,  1120, -1379, -1379,
   -1379,   885,  1042, -1379, -1379,  1044, -1379,   579, 11676,  1034,
     930, 11676,  7900, -1379, -1379,  6410, -1379,  1038, -1379,   967,
   -1379, 11104, -1379,   974, -1379,   190,   293, -1379,   957,   990,
   -1379,   961, -1379,  6410, 11676, -1379,   398,   398,  7304,   975,
   -1379, -1379, 11104, -1379, -1379,  1036,  7900, -1379,   980,   864,
   11676,  1043,   942,  1044, -1379, 11676,   979,  6410, -1379, -1379,
    1068,   204, -1379, -1379, -1379, -1379,   984,   306, -1379, -1379,
   -1379,   977, -1379, -1379,   169,   398, -1379, -1379, -1379, -1379,
   -1379,  6410,   887, 11676,  1052, -1379,  6410, -1379, -1379, -1379,
   -1379, -1379, -1379, -1379, -1379,  1053,  1019, -1379,   888,   894,
   11676, -1379, 11676, -1379,   879,  6410,   897,   201,  7900, -1379,
    7900,  1058,  1019, -1379,   985, 11676, -1379,   902,   999, 11676,
    1019,   958, -1379,  1072, 11676,   903,  7900, -1379
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
         0,   434,   435,     0,     0,     0,   764,   965,   588,   855,
     864,   805,   769,   767,   749,   856,   859,   812,   905,   773,
     750,   751,   917,   804,   865,   753,   862,   834,   814,   789,
     809,   906,   810,   860,   857,   808,   755,   863,   756,   757,
     903,   919,   902,   806,   825,   819,   758,   807,   760,   759,
     904,   843,   811,   786,   929,   930,   931,   932,   933,   934,
     935,   936,   937,   938,   939,   953,   960,   833,   829,   820,
     800,   748,     0,   828,   836,   844,   954,   824,   454,   801,
     802,   858,   955,   961,   821,   838,     0,   460,   423,   456,
     831,   766,   822,   823,   851,   826,   842,   850,   959,   962,
     772,   813,   853,   455,   841,   846,   752,     0,     0,   371,
     839,   849,   854,   852,   832,   818,   907,   816,   817,   956,
       0,   370,     0,   957,   963,   847,   803,   827,   958,   401,
       0,   433,   848,   830,   837,   845,   840,   908,   794,   799,
     798,   797,   796,   795,   761,   815,     0,   765,   861,   787,
     894,   893,   895,   771,   770,   790,   900,   754,   892,   897,
     898,   889,   793,   835,   891,   901,   899,   890,   791,   896,
     910,   913,   914,   911,   912,   909,   762,   915,   916,   918,
     881,   880,   867,   785,   778,   874,   870,   788,   784,   883,
     884,   774,   775,   768,   777,   879,   878,   875,   871,   888,
     882,   877,   873,   866,   776,   887,   886,   780,   782,   781,
     872,   876,   868,   783,   869,   779,   885,   940,   941,   942,
     943,   944,   945,   921,   922,   920,   926,   927,   928,   923,
     924,   925,   792,   946,   947,   948,   949,   950,   951,   952,
       0,     0,     2,     0,     5,     7,    19,     0,     0,    24,
      27,    38,    30,    31,    32,    58,    33,    42,    34,    62,
      63,    64,    59,    60,    66,    67,    37,     0,    35,    36,
      40,    41,    61,   221,   220,   217,   218,   219,    39,    14,
     197,   198,   202,   204,   236,   242,     0,   234,   235,   205,
     206,   207,   208,   209,   326,   328,   330,   340,   344,   346,
     349,   354,   357,   360,   362,   364,   366,     0,   368,   374,
     376,     0,   392,   375,   397,   400,   402,   405,   407,     0,
     412,   409,     0,   420,   430,   432,   406,   436,   443,   452,
     444,   445,   446,   449,   450,   447,   448,   467,   469,   470,
     471,   468,   516,   517,   518,   519,   520,   521,   429,   562,
     554,   561,   560,   559,   556,   558,   555,   557,   453,   451,
     589,   590,    65,   210,   211,   213,   212,   214,   215,   216,
       0,   431,   747,   763,   855,   864,   862,   523,   765,     0,
     527,     0,   533,     0,   175,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     118,   119,     0,     0,     0,     0,   114,   115,   116,   117,
     124,     0,     0,     0,     0,     0,     0,     0,   112,     0,
     173,   179,   181,   184,   183,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   261,   262,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   425,   428,   415,     0,     0,   744,   749,   773,
     751,   917,   804,   865,   753,   814,   755,   919,   825,   758,
     760,   759,   843,   953,   960,   748,   954,   955,   961,   826,
     959,   962,   907,   956,   957,   963,   958,   908,   900,   892,
     898,   889,   791,   910,   913,   914,   911,   762,   915,   918,
     421,   431,   747,   413,   414,   417,   749,   750,   751,   755,
     756,   757,   758,   748,   754,   457,     0,   419,   418,   458,
       0,   483,     0,   424,   745,     0,   746,   395,   396,     0,
     427,   426,   416,   399,     0,     0,   512,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   161,   158,   171,
     172,     0,     0,     0,     0,     3,     1,     6,     8,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   110,     0,
       0,   200,   199,     0,     0,     0,     0,     0,     0,     0,
       0,   222,   241,   237,   243,   238,   240,   239,     0,     0,
       0,   385,     0,     0,   383,     0,   335,     0,   384,   377,
     382,   381,   380,   379,   378,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   373,   372,   369,     0,   393,   398,     0,
       0,     0,   408,   440,   411,   410,   422,     0,   437,     0,
       0,     0,   524,   528,   534,     0,    85,    70,    71,   152,
     153,     0,     0,     0,     0,    76,    77,     0,   182,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   599,
     600,   601,   121,   120,     0,    75,   128,   125,     0,   127,
     126,   123,   122,     0,     0,     0,   113,     0,   174,   180,
       0,     0,   568,     0,     0,     0,   564,     0,     0,     0,
     578,     0,     0,     0,   224,   225,   244,   245,     0,     0,
       0,     0,   154,     0,   191,     0,   592,     0,    68,     0,
      94,     0,     0,     0,    86,     0,     0,     0,     0,     0,
     744,   569,     0,     0,     0,     0,     0,   309,     0,     0,
     567,     0,     0,     0,   586,     0,     0,     0,     0,   572,
       0,     0,     0,   459,   484,   483,   480,     0,     0,   514,
     513,   394,     0,   511,     0,   612,   613,   563,     0,     0,
       0,     0,     0,     0,   618,     0,     0,   169,     0,     0,
       0,   264,   266,    20,     0,    21,     0,     4,     0,    25,
      11,     0,    26,    15,   855,    28,    12,    29,    16,     0,
     109,   203,     0,     0,     0,     0,     0,   223,   282,   327,
     329,   333,   339,   338,   337,     0,   334,   331,   332,     0,
     348,   347,   345,   351,   352,   353,   350,   355,   356,   359,
     358,     0,     0,     0,     0,   390,     0,   403,   404,     0,
     441,   438,   465,     0,   964,   591,   463,     0,   588,     0,
     177,     0,     0,     0,    74,     0,     0,    48,    50,    51,
      52,    53,    55,    56,    57,    49,    54,    44,    45,     0,
       0,   102,     0,    98,   100,   101,   105,     0,     0,    43,
      84,     0,     0,     0,     0,     0,     0,     0,   694,   699,
       0,     0,   695,   729,   682,   684,   685,   686,   688,   690,
     689,   687,   691,     0,     0,     0,   129,     0,     0,   132,
       0,     0,     0,   532,   522,   565,   566,     0,     0,   582,
       0,   579,   631,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   226,   227,     0,   232,   193,     0,     0,
     155,     0,     0,     0,     0,     0,     0,    87,     0,     0,
       0,   260,   269,   263,     0,   571,   570,   577,   585,     0,
       0,     0,     0,     0,   531,     0,     0,     0,   386,     0,
       0,     0,     0,   575,     0,   573,     0,   483,   481,     0,
     472,     0,   461,   462,     0,     9,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     855,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   111,   201,   233,     0,   293,   289,
     291,     0,   283,   284,   336,     0,     0,     0,     0,   660,
     342,   633,   637,   639,   641,   643,   646,   653,   654,   662,
     865,   752,     0,   761,   361,   540,   546,   547,   549,   593,
     594,   550,   553,   363,   365,   537,   367,   391,   442,     0,
     439,   464,     0,   176,    82,    83,    80,    81,   186,     0,
     185,     0,     0,    46,     0,     0,   103,   104,   106,    72,
      73,    78,    79,    69,   700,     0,   703,   730,     0,   693,
     692,   697,   696,   728,     0,     0,   705,     0,   701,   704,
     683,     0,     0,     0,     0,     0,     0,     0,   130,   136,
       0,     0,     0,     0,     0,     0,   133,     0,   107,     0,
       0,     0,     0,   586,     0,     0,     0,     0,   539,     0,
     247,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     228,     0,     0,     0,     0,   276,     0,   273,   278,   231,
     194,   156,   192,     0,   195,     0,     0,    96,    90,    93,
      92,     0,    88,   267,     0,     0,     0,   168,     0,   307,
     311,     0,     0,     0,   314,     0,     0,     0,   321,     0,
     388,   387,     0,     0,     0,   308,   484,     0,   473,     0,
     507,   504,     0,   508,   509,     0,   510,   503,     0,   478,
     506,   505,     0,     0,     0,   605,   606,   602,     0,     0,
     610,   611,   607,   616,   614,     0,     0,     0,   620,     0,
     163,     0,   160,   159,   170,     0,   621,   622,     0,     0,
      22,     0,    13,    17,    18,   290,   302,     0,   303,     0,
     294,   295,   296,   297,     0,   286,     0,     0,     0,   644,
     657,     0,   341,   343,     0,   676,     0,     0,     0,     0,
       0,     0,   632,   634,   635,   671,   672,   673,   675,   674,
       0,     0,   648,   647,     0,   651,   655,   669,   667,   666,
     659,   663,     0,     0,     0,     0,   543,   545,   544,   541,
     538,   466,   178,     0,   188,   187,   190,     0,    47,    99,
     717,   698,     0,   722,     0,   722,   711,   706,   131,   137,
     139,   138,     0,     0,     0,   134,     0,   108,    23,   525,
       0,   583,   584,   587,   580,   581,   246,     0,     0,   259,
     251,     0,   255,     0,   249,     0,     0,     0,   271,     0,
       0,     0,   230,   274,   277,     0,   157,     0,    95,     0,
      89,   268,     0,   535,     0,   310,   312,   317,     0,   315,
       0,     0,     0,     0,     0,   322,   389,   529,     0,   576,
     574,   483,     0,     0,   515,   483,     0,   479,    10,     0,
       0,     0,     0,     0,   619,     0,   164,   162,   628,     0,
     623,     0,   265,   306,   304,   305,   298,   299,   300,   292,
       0,   287,   285,   661,   652,   658,     0,     0,   731,   732,
     742,   741,   740,     0,     0,     0,     0,   733,   638,   739,
       0,   636,   640,     0,     0,   645,   649,     0,   670,   665,
     668,   664,     0,     0,   551,     0,   548,   598,   542,   196,
       0,   718,     0,     0,   716,   723,   724,   720,     0,   715,
       0,   713,     0,     0,     0,     0,     0,   135,     0,   526,
     248,     0,   257,     0,     0,   253,     0,   256,   272,   280,
     281,   275,   229,     0,     0,    91,   270,   536,     0,   318,
     316,     0,     0,     0,     0,   530,     0,   483,     0,     0,
     483,   603,   604,   608,   609,   615,   617,     0,   165,     0,
       0,   624,   630,   301,   288,   656,   743,     0,     0,   735,
       0,   681,   680,   679,   678,   677,   642,     0,   734,     0,
     595,     0,     0,   189,   727,   726,   725,     0,   719,   712,
     710,     0,   707,   708,   702,   140,   142,   144,     0,     0,
       0,     0,     0,   252,   250,     0,   258,     0,   325,    97,
     313,     0,   323,     0,   319,   493,   487,   482,     0,   483,
     474,     0,   166,     0,     0,   629,   737,   736,     0,     0,
     596,   552,     0,   721,   714,     0,     0,   146,   145,     0,
       0,     0,     0,   141,   254,     0,     0,     0,   501,   495,
       0,   494,   496,   502,   499,   489,     0,   488,   490,   500,
     476,     0,   475,   167,     0,   738,   650,   597,   709,   143,
     147,     0,     0,     0,     0,   279,     0,   320,   486,   497,
     498,   485,   491,   492,   477,     0,     0,   148,     0,     0,
       0,   324,     0,   625,     0,     0,     0,     0,     0,   150,
       0,     0,     0,   149,     0,     0,   626,     0,     0,     0,
       0,     0,   627,     0,     0,     0,     0,   151
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1379, -1379,  -226,   954, -1379,   960,   963, -1379,   964,  -227,
    -523,  -553, -1379,   515,  -466, -1379, -1379, -1379, -1379, -1379,
   -1379, -1379, -1379, -1379, -1379, -1379, -1379, -1379, -1379,  -942,
   -1379, -1379, -1379, -1379,   107,   312, -1379, -1379, -1379,   796,
   -1379,    70,  -884, -1379,  -356,  -389, -1379, -1379,  -603, -1379,
    -907, -1379, -1379,   -31, -1379, -1379, -1379, -1379, -1379,   800,
   -1379, -1379,   807,   823, -1379, -1379, -1379,   252,   801, -1370,
    -544,     7, -1379,  -564,   625, -1379, -1379, -1379, -1379,   261,
   -1379, -1379,   931, -1379, -1379, -1379, -1379,    73,  -715,  -684,
   -1379, -1379, -1379,   -28,   474, -1379, -1379,  -135,    67, -1379,
   -1379, -1379,   -35, -1379, -1379,   197,   -27, -1379, -1379,   -26,
   -1213, -1379,   703,    45, -1379, -1379,    50, -1379, -1379, -1379,
      41, -1379, -1379,   633,   639, -1379,  -514, -1379, -1379,  -618,
     119,  -616,   114,   122, -1379, -1379, -1379, -1379, -1379,   935,
   -1379, -1379, -1379, -1379,  -809,  -296, -1065, -1379,  -103, -1379,
   -1379, -1379, -1379, -1379, -1379, -1379,   -30, -1209, -1379, -1379,
     362,    58, -1379,  -654, -1379, -1379, -1379, -1379, -1379, -1379,
   -1379,   581, -1379,  -963, -1379,    35, -1379,   465,  -752, -1379,
   -1379, -1379, -1379, -1379,  -372,  -365, -1135,  -967, -1379, -1379,
   -1379, -1379, -1379, -1379, -1379, -1379, -1379, -1379,   393,  -731,
    -817,   121,  -812, -1379,   -97,  -801, -1379, -1379, -1379, -1379,
   -1379, -1379, -1379,   824,   830,  -591,   311,   159, -1379, -1379,
   -1379, -1379, -1379, -1379, -1379, -1379, -1379, -1379, -1379, -1379,
   -1379, -1379,    18, -1379, -1379,    19, -1379, -1379,  -992, -1379,
   -1379, -1379,   -22,   -23,  -188,   211, -1379, -1379, -1379, -1379,
   -1379, -1379, -1379, -1379, -1379, -1379, -1379, -1379, -1379,   -19,
   -1379, -1379, -1379,  -180,   206,   343, -1379, -1379, -1379, -1379,
   -1379,   151, -1379, -1379, -1378, -1379, -1379, -1379,  -701, -1379,
     -55, -1379,  -194, -1379, -1379, -1379, -1379, -1230, -1379,    -8,
   -1379,  -376,  -362,   110,   -72, -1379
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   241,   796,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   877,   878,   879,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,  1167,
     733,   265,   266,   883,   884,   885,   267,   268,   417,   418,
     269,  1118,   916,   270,  1545,  1546,   271,   272,   438,   273,
     558,   786,  1011,  1230,   274,   275,   276,   277,   419,   420,
     859,   278,   421,   422,   423,   424,   723,   724,  1206,  1080,
     279,   280,   582,   281,   282,   283,   591,   436,   945,   946,
     284,   592,   285,   594,   286,   287,   716,   717,  1155,   445,
     288,   446,   790,   791,   447,   720,  1156,  1157,  1158,   595,
     596,  1032,  1033,  1411,   597,  1029,  1030,  1250,  1251,  1252,
    1253,   289,   746,   747,   290,  1183,  1184,  1185,   291,  1187,
    1188,   292,   293,   294,   295,   825,   296,  1262,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     615,   616,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     642,   643,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   853,   336,   337,   338,  1208,   765,   766,   767,  1567,
    1606,  1607,  1600,  1601,  1608,  1602,  1209,  1210,   339,   340,
    1211,   341,   342,   343,   344,   345,   346,   347,  1064,   940,
    1054,  1299,  1055,  1445,  1056,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   753,  1132,   358,   359,   360,
     361,  1058,  1059,  1060,  1061,   362,   363,   364,   365,   366,
     367,   783,   784,   368,  1236,  1237,  1399,   369,  1040,  1272,
    1273,  1041,  1042,  1043,  1044,  1045,  1282,  1435,  1436,  1046,
    1285,  1047,  1416,  1048,  1049,  1290,  1291,  1441,  1439,  1274,
    1275,  1276,  1277,  1524,   685,   904,   905,   906,   907,   908,
     909,  1108,  1463,  1542,  1109,  1461,  1540,   910,  1315,  1458,
    1454,  1455,  1456,   911,   912,  1278,  1286,  1426,  1279,  1422,
    1263,   370,   535,   371,   372,   373
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int xquery_parser::yytable_ninf_ = -745;
  const short int
  xquery_parser::yytable_[] =
  {
       512,   860,   832,   938,   960,   833,   834,   835,   836,   656,
     379,   381,   383,   989,   512,   637,  1172,   973,   812,   572,
    1038,   575,   577,   805,   807,  1063,  1398,   543,  1207,  1511,
     800,   803,   806,   808,   939,  1126,   512,   678,  1407,  1408,
    1057,  1057,   510,   858,  1258,   934,  1144,   942,   512,   573,
     512,   799,   802,   573,  1437,   385,   386,  1322,   387,   388,
     863,   573,   545,   700,  1548,   730,   734,   573,  1085,   573,
     573,   443,   573,  1387,   914,   704,   467,  1007,   391,  1057,
    1125,  1174,   893,  1565,  1543,   894,   821,   742,   822,   823,
     467,   824,  1370,   826,   705,   970,   721,  1141,   769,  1452,
     580,   827,   828,   580,  1231,   935,  1234,   936,   936,   970,
     433,   928,   580,  1119,   530,   434,  1493,  1111,  1138,  1015,
     930,   949,  1105,  1112,   704,    78,  1423,   895,   636,  1517,
     665,  1161,  1241,   661,  1057,  1312,   935,   990,  1106,    89,
    1113,  1345,  1114,   705,   982,   627,   548,  1057,   549,   662,
     935,  1115,   122,   984,  1198,  1088,  1074,   937,  1145,   628,
     435,   731,   666,  1453,   103,   722,  1200,  1201,  1035,   428,
    1549,  1036,  1566,  1075,  1305,  1039,   971,  1116,  1371,   399,
    1016,  1107,   511,   581,  1494,  1069,  1025,  1232,   972,  1533,
     986,   929,   122,  1513,  1314,  1598,   525,  1069,   996,  1200,
     931,   950,  1148,   991,  1008,  1518,   943,  1618,   732,  1598,
    1149,   638,   444,  1200,  1072,   915,  1160,   706,   531,  1531,
    1199,   915,   729,   444,   983,  1146,   444,  1038,  1038,  1360,
     536,  1541,   539,   985,  1318,  1197,  1207,   574,   402,   458,
    1294,   576,   805,   807,   944,  1207,   546,   512,  1387,   793,
     512,  1057,  1247,  1550,  1142,   795,  1147,  1020,  1022,  1202,
    1240,  1468,  1081,  1082,   770,  1070,  1643,   444,  1415,  1264,
     799,   802,  1537,  1249,  1037,  1635,  1175,  1071,   896,  1203,
     404,  1204,  1656,   444,   444,  1424,  1425,   854,   936,   644,
    1662,   897,   646,   898,  1073,  1200,  1201,   459,  -744,  1532,
     890,  1575,  1200,  1117,   899,   900,   901,  1651,   902,   725,
     903,  1034,  1203,   108,  1204,  1200,   936,   663,   512,  1604,
     997,   998,  1599,   512,  1119,   994,  1203,   512,  1204,   935,
     120,   657,  1604,   512,  1587,   999,  1629,  1131,  1337,  1134,
     512,  1265,   725,   583,   658,   794,  1356,   798,   801,   584,
    1205,   429,  1538,   512,   585,  1636,   725,   957,  1418,   512,
     621,   858,  1057,   512,   460,   461,  1473,   953,   146,  1373,
     956,   512,   880,   586,   935,  1620,   959,   512,   512,   512,
     512,   512,  1039,  1039,   995,  1057,   512,  1652,  1202,   622,
     659,  1193,  1079,  1194,   512,  1509,  1419,  1327,   858,  1547,
    1182,  1000,   623,   660,   673,  1200,  1201,   674,  1203,  1264,
    1204,  1083,   425,  1368,   881,  1203,  1260,  1204,  1302,   882,
    1207,  1507,  1338,  1083,  1266,  1267,  1605,  1268,  1203,   511,
    1204,  1312,   511,   701,  1269,   703,   624,   709,   725,  1632,
     122,  1467,   108,    78,  1270,   725,   727,  1313,  1510,   426,
     432,  1038,   427,  1296,   512,   739,  1271,    89,   725,   120,
    1038,   749,  1346,   751,   752,   676,   755,   805,   807,   805,
     587,  1038,   758,   588,   437,  1444,  1242,  1243,  1244,  1382,
      78,  1265,   103,   569,   512,  1297,  1035,  1547,   589,  1036,
    1314,  1057,   512,  1186,    89,  1200,  1201,   146,  1202,   464,
     664,   570,  1298,  1287,  1288,   670,  1374,   618,   439,   536,
     122,  1089,  1090,   590,   673,   686,  1093,   674,  1203,   103,
    1204,  1547,   688,  1001,  1002,   619,  1289,   677,  1151,  1018,
     465,   450,  1099,   466,  1152,   536,   847,   848,  1003,   768,
     618,   712,  1559,  1100,   452,   718,  1129,   570,   725,   675,
    1151,   772,   108,   735,   430,   618,  1152,   431,   619,   536,
     743,   744,   745,   748,  1266,  1267,  1017,  1268,   754,   120,
     789,   936,  1021,   619,  1153,   676,   761,   512,  1168,   451,
     620,   440,  1168,  1653,  1270,  1654,  1076,   618,  1202,  1386,
     441,   384,   551,   936,   552,   865,  1271,   866,  1603,  1609,
     512,  1667,   625,  1077,  1078,   619,  1039,   146,  1203,  1420,
    1204,   626,   554,   389,  1154,  1039,  1421,   555,  1521,   442,
    1079,   512,   512,   512,  1038,  1522,  1039,  1578,  1474,  1496,
     392,   453,   393,  1499,  1603,  1523,   748,   677,   725,  1304,
    1609,   394,   108,   846,  1151,  1521,   456,   512,   849,   512,
    1152,  1246,  1522,  1430,  1306,   557,  1105,   512,   578,   120,
     512,  1247,  1523,   579,   512,  1508,   785,  1101,   457,   384,
    1307,  1248,  1106,   935,   792,   462,   881,   697,  1102,  1498,
    1123,   882,  1249,   645,  1247,   639,   640,   805,   648,  1124,
     463,   389,   512,  1094,  1095,  1096,   641,   146,   647,  1097,
     850,   390,   448,   850,   454,   449,   850,   455,   392,  1213,
     393,  1214,  1580,   513,  1581,   679,   680,   681,  1218,   394,
    1219,   682,   683,   395,   691,   692,  1091,  1092,  1057,   526,
    1057,   514,   951,  1120,  1121,  1404,  1405,   830,   831,   837,
     838,   512,   637,  1450,  1596,  1568,  1065,  1065,  1571,   839,
     840,  1534,  1535,   515,   396,   397,  1023,   527,   528,   536,
    1057,   532,   533,   979,   980,  1617,   540,   541,   400,   512,
     512,   512,   512,   542,   544,   547,   550,   556,   553,  1039,
     557,  1057,   886,   561,   559,   560,   562,   563,   564,   566,
    1358,   599,   598,  1012,   617,  1168,   629,   631,   649,   630,
     401,  1516,   641,   918,   919,   920,  1519,  1520,   512,   632,
     650,   651,   400,   652,   655,   467,  1588,  1611,   667,   389,
     669,   653,   512,   654,   671,   684,   672,   687,   403,   941,
     689,   947,   600,   690,   693,   719,   702,   725,   728,   536,
     601,   602,   536,   603,   401,   714,   961,   715,   736,   512,
     738,   604,   737,   750,   756,   605,   512,   606,   512,   757,
     427,   431,   607,   512,   764,   449,   763,   455,   466,   771,
     773,  1403,   403,   774,   987,   777,   512,   782,   797,   608,
     809,   813,   814,   815,   829,   816,   694,   406,   407,   408,
     409,   841,   410,   411,   695,   413,   414,   842,   843,  1576,
    1577,   415,   609,   610,   611,   612,   613,   614,   844,   855,
     512,   861,   512,   867,   868,   869,   870,   871,   872,   873,
     874,   875,   876,  1026,   862,   864,   887,   888,   891,   892,
     405,   406,   407,   408,   409,   913,   410,   411,   412,   413,
     414,   917,   921,   922,   925,   415,   416,   933,   923,   924,
     948,  1062,  1062,  1062,  1062,   926,   952,   927,   932,   512,
    1615,   954,   955,   958,   964,   965,   966,   969,   967,   968,
     974,   975,   976,   977,   978,   981,   992,   993,  1004,  1006,
     512,  1009,  1005,  1485,  1189,  1013,  1019,  1031,  1027,  1014,
    1062,  1067,  1084,  1068,   935,   882,  1103,  1130,  1127,  1136,
    1137,  1122,  1104,  1139,  1098,  1143,  1150,   721,  1163,  1166,
    1164,  1165,  1170,  1171,  1169,  1176,  1178,  1181,  1182,  1186,
    1192,  1190,  1191,  1196,  1212,  1226,  1229,  1233,  1235,  1238,
    1239,  1128,   675,  1254,  1514,  1256,  1261,  1281,  1133,  1300,
    1133,   858,  1257,  1284,  1292,  1062,  1293,  1280,  1295,  1311,
    1316,   915,  1331,  1320,  1321,  1324,  1341,   713,  1062,  1326,
    1343,  1328,  1332,  1350,   512,  1333,  1334,   512,  1351,  1335,
    1347,  1349,  1355,  1359,  1362,  1376,  1381,  1384,  1389,  1390,
    1310,  1379,   512,  1323,  1393,  1247,  1303,  1380,  1391,  1392,
    1395,   512,   754,  1388,   754,  1413,  1410,  1414,  1433,  1417,
    1427,  1434,  1438,  1440,  1451,  1457,   512,  1446,  1168,  1447,
    1462,  1449,  1448,  1460,   512,  1469,  1464,  1471,  1466,  1476,
    1484,  1483,  1487,  1488,  1495,  1492,  1512,  1515,  1527,  1529,
    1539,  1528,  1105,   512,  1530,  1544,  1557,  1330,  1555,  1552,
    1561,  1255,  1573,  1574,  1582,  1570,  1551,  1583,  1585,  1584,
    1586,  1590,  1610,  1591,   512,  1595,  1612,   512,  1616,  1597,
    1623,  1628,  1062,   512,  1626,  1624,  1631,   512,  1621,  1640,
    1642,  1079,  1634,   775,   776,  1655,   778,   779,   780,   781,
    1644,  1663,  1657,  1364,  1648,  1660,   787,   788,  1659,  1664,
     889,  1638,  1309,  1086,   565,  1325,  1593,  1619,  1645,  1378,
    1397,  1162,  1650,   567,   810,   811,   568,  1159,  1666,  1336,
     571,  1402,   963,   696,   817,   818,   668,   593,  1481,   698,
     512,  1412,  1354,  1365,  1245,  1406,   699,  1409,  1375,   762,
     988,   819,   857,  1369,  1383,  1633,  1630,  1066,   820,   726,
    1319,  1135,   635,  1308,  1394,  1526,   718,  1428,  1259,  1339,
    1525,   512,  1283,   707,  1431,  1400,  1110,  1432,  1317,   708,
    1459,  1536,  1429,     0,  1353,     0,     0,     0,     0,     0,
       0,     0,   852,  1062,     0,     0,   852,     0,   512,   512,
       0,     0,     0,     0,     0,     0,     0,     0,   748,     0,
       0,     0,     0,     0,     0,     0,  1062,     0,     0,     0,
     512,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     512,     0,     0,     0,   512,  1385,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   785,     0,     0,  1396,
       0,     0,     0,     0,     0,   511,     0,     0,     0,   792,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   962,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1062,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   512,     0,     0,     0,     0,   512,     0,     0,     0,
       0,     0,     0,  1465,  1024,     0,     0,     0,   512,     0,
    1028,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   512,     0,   512,
    1479,  1480,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   512,     0,     0,   512,
       0,     0,  1491,     0,     0,     0,     0,     0,     0,   512,
       0,     0,  1497,     0,     0,     0,  1500,     0,     0,     0,
       0,     0,   512,     0,     0,     0,     0,  1087,     0,     0,
     512,     0,     0,     0,     0,     0,     0,     0,   512,     0,
       0,     0,     0,   512,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1579,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   512,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1140,     0,     0,     0,     0,     0,   512,     0,
     512,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   512,  1173,     0,     0,   512,     0,     0,
       0,     0,   512,     0,  1177,     0,  1179,  1180,     0,     0,
       0,     0,     0,  1563,     0,     0,     0,     0,  1569,     0,
       0,  1195,     0,     0,     0,     0,     0,     0,     0,     0,
     511,     0,  1215,  1216,  1217,     0,  1220,  1221,  1222,  1223,
    1224,  1225,     0,  1227,  1228,     0,     0,   384,     0,  1062,
       0,  1062,     0,     0,     0,     0,     0,   385,   386,     0,
     387,   388,  1028,     0,     0,     0,     0,     0,  1589,   389,
       0,  1592,     0,     0,     0,     0,     0,     0,     0,   390,
     391,  1062,     0,     0,     0,     0,   392,     0,   393,     0,
       0,     0,     0,     0,  1614,     0,     0,   394,     0,     0,
       0,   395,  1062,     0,  1301,     0,     0,     0,     0,     0,
    1622,     0,     0,     0,     0,  1625,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   396,   397,   398,     0,     0,     0,     0,     0,
       0,     0,     0,  1639,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1646,     0,  1647,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1658,  1340,     0,  1342,  1661,
    1344,   399,     0,  1348,  1665,     0,     0,     0,  1352,     0,
     400,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1357,     0,     0,     0,     0,     0,     0,     0,     0,  1361,
       0,     0,     0,     0,     0,     0,  1366,  1367,     0,     0,
       0,     0,   401,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     402,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     403,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1401,     0,     0,     0,     0,     0,     0,
       0,     0,   404,     0,     0,     0,     0,     0,     0,  1028,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   405,   406,
     407,   408,   409,     0,   410,   411,   412,   413,   414,     0,
       0,     0,     0,   415,   416,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1470,     0,     0,     0,  1472,     0,     0,     0,
    1475,     0,  1477,     0,  1478,     0,     0,     0,     0,     0,
    1482,     0,     0,     0,     0,     0,     0,  1486,     0,     0,
       0,     0,     0,     0,     0,  1489,  1490,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1501,  1502,  1503,  1504,  1505,     0,
    1506,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1553,     0,  1554,     0,
       0,  1556,     0,     0,     0,     0,     0,     0,  1558,     0,
       0,     0,     0,  1560,     0,     0,     0,  1562,     0,  1564,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1572,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1594,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1613,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1627,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1637,     0,     1,     0,
       0,  1641,     0,     0,     0,     0,     2,     3,     4,     5,
       6,     7,     0,     0,     8,     0,     0,     0,     9,    10,
    1649,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
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
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,     0,   191,   192,   193,     0,   194,
     195,   196,   197,   198,   199,     0,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,     1,     0,     0,
       0,     0,     0,     0,     0,     2,     3,     4,     5,     6,
       7,     0,     0,     8,     0,     0,     0,   374,   375,     0,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,   376,    27,    28,    29,    30,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,     0,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,    71,    72,    73,    74,    75,     0,     0,
      76,    77,     0,     0,     0,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,     0,     0,     0,    89,
       0,    90,    91,    92,    93,     0,    94,     0,     0,     0,
      95,    96,    97,    98,    99,     0,     0,     0,     0,     0,
       0,   100,   101,   102,   103,   104,   105,   106,     0,     0,
       0,   107,   108,   109,   110,   111,     0,     0,     0,     0,
     112,   113,   114,   115,   116,   117,   118,   119,     0,   120,
       0,   121,   122,     0,     0,   123,   124,   125,     0,   377,
       0,   126,     0,   127,   128,     0,   129,   130,   131,     0,
     132,     0,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,     0,     0,   144,   145,   146,     0,   378,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,     0,   191,   192,   193,     0,   194,   195,
     196,   197,   198,   199,     0,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,     1,     0,     0,     0,     0,
       0,     0,     0,     2,     3,     4,     5,     6,     7,     0,
       0,     8,     0,     0,     0,   374,   375,     0,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,   376,    27,    28,    29,    30,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,     0,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,    71,    72,    73,    74,    75,     0,     0,    76,    77,
       0,     0,     0,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,     0,     0,     0,    89,     0,    90,
      91,    92,    93,     0,    94,     0,     0,     0,    95,    96,
      97,    98,    99,     0,     0,     0,     0,     0,     0,   100,
     101,   102,   103,   104,   105,   106,     0,     0,     0,   107,
     108,   109,   110,   111,     0,     0,     0,     0,   112,   113,
     114,   115,   116,   117,   118,   119,     0,   120,     0,   121,
     122,     0,     0,   123,   124,   125,     0,   380,     0,   126,
       0,   127,   128,     0,   129,   130,   131,     0,   132,     0,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,     0,     0,   144,   145,   146,     0,   378,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,     0,   191,   192,   193,     0,   194,   195,   196,   197,
     198,   199,     0,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,     1,     0,     0,     0,     0,     0,     0,
       0,     2,     3,     4,     5,     6,     7,     0,     0,     8,
       0,     0,     0,   374,   375,     0,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,   376,    27,    28,    29,    30,     0,    31,    32,    33,
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
       0,   123,   124,   125,     0,   382,     0,   126,     0,   127,
     128,     0,   129,   130,   131,     0,   132,     0,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,     0,
       0,   144,   145,   146,     0,   378,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,     0,
     191,   192,   193,     0,   194,   195,   196,   197,   198,   199,
       0,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,     1,     0,     0,     0,     0,     0,     0,     0,     2,
       3,     4,     5,     6,     7,     0,     0,     8,     0,     0,
       0,   374,   375,     0,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,   376,
      27,    28,    29,    30,     0,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,     0,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,    71,    72,    73,
      74,    75,     0,     0,    76,    77,     0,     0,     0,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
       0,     0,     0,    89,     0,    90,    91,    92,    93,     0,
      94,     0,     0,     0,    95,    96,    97,    98,    99,     0,
       0,     0,     0,     0,     0,   100,   101,   102,   103,   104,
     105,   106,     0,     0,     0,   107,   108,   109,   110,   111,
       0,     0,     0,     0,   112,   113,   114,   115,   116,   117,
     118,   119,     0,   120,     0,   121,   122,     0,     0,   123,
     124,   125,     0,     0,     0,   126,   529,   127,   128,     0,
     129,   130,   131,     0,   132,     0,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,     0,     0,   144,
     145,   146,     0,   378,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,     0,   191,   192,
     193,     0,   194,   195,   196,   197,   198,   199,     0,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,     1,
       0,     0,     0,     0,     0,     0,     0,     2,     3,     4,
       5,     6,     7,     0,     0,     8,     0,     0,     0,   374,
     375,     0,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,   376,    27,    28,
      29,    30,     0,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,     0,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,    71,    72,    73,    74,    75,
       0,     0,    76,    77,     0,     0,     0,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,     0,     0,
       0,    89,     0,    90,    91,    92,    93,     0,    94,     0,
       0,     0,    95,    96,    97,    98,    99,     0,     0,     0,
       0,     0,     0,   100,   101,   102,   103,   104,   105,   106,
       0,     0,     0,   107,   108,   109,   110,   111,     0,     0,
       0,     0,   112,   113,   114,   115,   116,   117,   118,   119,
       0,   120,     0,   121,   122,     0,     0,   123,   124,   125,
       0,   845,     0,   126,     0,   127,   128,     0,   129,   130,
     131,     0,   132,     0,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,     0,     0,   144,   145,   146,
       0,   378,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,     0,   191,   192,   193,     0,
     194,   195,   196,   197,   198,   199,     0,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,     1,     0,     0,
       0,     0,     0,     0,     0,     2,     3,     4,     5,     6,
       7,     0,     0,     8,     0,     0,     0,   374,   375,     0,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,   376,    27,    28,    29,    30,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,     0,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,    71,    72,    73,    74,    75,     0,     0,
      76,    77,     0,     0,     0,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,     0,     0,     0,    89,
       0,    90,    91,    92,    93,     0,    94,     0,     0,     0,
      95,    96,    97,    98,    99,     0,     0,     0,     0,     0,
       0,   100,   101,   102,   103,   104,   105,   106,     0,     0,
       0,   107,   108,   109,   110,   111,     0,     0,     0,     0,
     112,   113,   114,   115,   116,   117,   118,   119,     0,   120,
       0,   121,   122,     0,     0,   123,   124,   125,     0,     0,
       0,   126,   851,   127,   128,     0,   129,   130,   131,     0,
     132,     0,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,     0,     0,   144,   145,   146,     0,   378,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,     0,   191,   192,   193,     0,   194,   195,
     196,   197,   198,   199,     0,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,     1,     0,     0,     0,     0,
       0,     0,     0,     2,     3,     4,     5,     6,     7,     0,
       0,     8,     0,     0,     0,   374,   375,     0,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,   376,    27,    28,    29,    30,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,     0,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,    71,    72,    73,    74,    75,     0,     0,    76,    77,
       0,     0,     0,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,     0,     0,     0,    89,     0,    90,
      91,    92,    93,     0,    94,     0,     0,     0,    95,    96,
      97,    98,    99,     0,     0,     0,     0,     0,     0,   100,
     101,   102,   103,   104,   105,   106,     0,     0,     0,   107,
     108,   109,   110,   111,     0,     0,     0,     0,   112,   113,
     114,   115,   116,   117,   118,   119,     0,   120,     0,   121,
     122,     0,     0,   123,   124,   125,     0,     0,     0,   126,
     856,   127,   128,     0,   129,   130,   131,     0,   132,     0,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,     0,     0,   144,   145,   146,     0,   378,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,     0,   191,   192,   193,     0,   194,   195,   196,   197,
     198,   199,     0,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,     1,     0,     0,     0,     0,     0,     0,
       0,     2,     3,     4,     5,     6,     7,     0,     0,     8,
       0,     0,     0,   374,   375,     0,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,   376,    27,    28,    29,    30,     0,    31,    32,    33,
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
       0,   123,   124,   125,     0,  1329,     0,   126,     0,   127,
     128,     0,   129,   130,   131,     0,   132,     0,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,     0,
       0,   144,   145,   146,     0,   378,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,     0,
     191,   192,   193,     0,   194,   195,   196,   197,   198,   199,
       0,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,     1,     0,     0,     0,     0,     0,     0,     0,     2,
       3,     4,     5,     6,     7,     0,     0,     8,     0,     0,
       0,   374,   375,     0,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,   376,
      27,    28,    29,    30,     0,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,     0,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,    71,    72,    73,
      74,    75,     0,     0,    76,    77,     0,     0,     0,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
       0,     0,     0,    89,     0,    90,    91,    92,    93,     0,
      94,     0,     0,     0,    95,    96,    97,    98,    99,     0,
       0,     0,     0,     0,     0,   100,   101,   102,   103,   104,
     105,   106,     0,     0,     0,   107,   108,   109,   110,   111,
       0,     0,     0,     0,   112,   113,   114,   115,   116,   117,
     118,   119,     0,   120,     0,   121,   122,     0,     0,   123,
     124,   125,     0,  1363,     0,   126,     0,   127,   128,     0,
     129,   130,   131,     0,   132,     0,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,     0,     0,   144,
     145,   146,     0,   378,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,     0,   191,   192,
     193,     0,   194,   195,   196,   197,   198,   199,     0,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,     1,
       0,     0,     0,     0,     0,     0,     0,     2,     3,     4,
       5,     6,     7,     0,     0,     8,     0,     0,     0,   374,
     375,     0,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,   376,    27,    28,
      29,    30,     0,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,     0,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,    71,    72,    73,    74,    75,
       0,     0,    76,    77,     0,     0,     0,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,     0,     0,
       0,    89,     0,    90,    91,    92,    93,     0,    94,     0,
       0,     0,    95,    96,    97,    98,    99,     0,     0,     0,
       0,     0,     0,   100,   101,   102,   103,   104,   105,   106,
       0,     0,     0,   107,   108,   109,   110,   111,     0,     0,
       0,     0,   112,   113,   114,   115,   116,   117,   118,   119,
       0,   120,     0,   121,   122,     0,     0,   123,   124,   125,
       0,  1377,     0,   126,     0,   127,   128,     0,   129,   130,
     131,     0,   132,     0,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,     0,     0,   144,   145,   146,
       0,   378,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,     0,   191,   192,   193,     0,
     194,   195,   196,   197,   198,   199,     0,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,     1,     0,     0,
       0,     0,     0,     0,     0,     2,     3,     4,     5,     6,
       7,     0,     0,     8,     0,     0,     0,     9,    10,     0,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,     0,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,    71,    72,    73,    74,    75,     0,     0,
      76,    77,     0,     0,     0,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,     0,     0,     0,    89,
       0,    90,    91,    92,    93,     0,    94,     0,     0,     0,
      95,    96,    97,    98,    99,     0,     0,     0,     0,     0,
       0,   100,   101,   102,   103,   104,   105,   106,     0,     0,
       0,   107,   108,   109,   110,   111,     0,     0,     0,     0,
     112,   113,   114,   115,   116,   117,   118,   119,     0,   120,
       0,   121,   122,     0,     0,   123,   124,   125,     0,     0,
       0,   126,     0,   127,   128,     0,   129,   130,   131,     0,
     132,     0,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,     0,     0,   144,   145,   146,     0,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,     0,   191,   192,   193,     0,   194,   195,
     196,   197,   198,   199,     0,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,     1,     0,     0,     0,     0,
       0,     0,     0,     2,     3,     4,     5,     6,     7,     0,
       0,     8,     0,     0,     0,     9,    10,     0,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,     0,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,    71,    72,    73,    74,    75,     0,     0,    76,    77,
       0,     0,     0,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,     0,     0,     0,    89,     0,    90,
      91,    92,    93,     0,    94,     0,     0,     0,    95,    96,
      97,    98,    99,     0,     0,     0,     0,     0,     0,   100,
     101,   102,   103,   104,   105,   106,     0,     0,     0,   107,
     108,   109,   110,   111,     0,     0,     0,     0,   112,   113,
     114,   115,   116,   117,   118,   119,     0,   120,     0,   121,
     122,     0,     0,   123,   124,   125,     0,     0,     0,   126,
       0,   127,   128,     0,   129,   130,   131,     0,   132,     0,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,     0,     0,   144,   145,   146,     0,   378,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,     0,   191,   192,   193,     0,   194,   195,   196,   197,
     198,   199,     0,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,     1,     0,     0,     0,     0,     0,     0,
       0,     2,     3,     4,     5,     6,     7,     0,     0,     8,
       0,     0,     0,   374,   375,     0,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,   471,   472,    24,
     474,   376,    27,   475,    29,    30,     0,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,   477,    42,    43,
     478,     0,    45,    46,    47,   480,   481,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,    71,
      72,    73,    74,    75,     0,     0,    76,    77,     0,     0,
       0,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,     0,     0,     0,    89,     0,    90,    91,    92,
      93,     0,    94,     0,     0,     0,   489,    96,    97,    98,
      99,     0,     0,     0,     0,     0,     0,   100,   101,   102,
     103,   104,   105,   106,     0,     0,     0,   107,   108,   633,
     110,   111,     0,     0,     0,     0,   112,   113,   114,   115,
     116,   117,   118,   119,     0,   120,     0,   634,   122,     0,
       0,   123,   124,   125,     0,     0,     0,   126,     0,   127,
     128,     0,   129,   130,   131,     0,   132,     0,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,     0,
       0,   144,   145,   146,     0,   378,   148,   149,   150,   151,
     152,   153,   154,   155,   498,   157,   499,   159,   500,   501,
     162,   163,   164,   165,   166,   167,   502,   169,   503,   504,
     505,   506,   174,   175,   507,   508,   178,   509,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,     0,
     191,   192,   193,     0,   194,   195,   196,   197,   198,   199,
       0,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,     1,     0,     0,     0,     0,     0,     0,     0,     2,
       3,     4,     5,     6,     7,     0,     0,     8,     0,     0,
       0,   374,   375,     0,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,   376,
      27,    28,    29,    30,     0,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,     0,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,    71,    72,    73,
      74,    75,     0,     0,    76,    77,     0,     0,     0,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
       0,     0,     0,    89,     0,    90,    91,    92,    93,     0,
      94,     0,     0,     0,    95,    96,    97,    98,    99,     0,
       0,     0,     0,     0,     0,   100,   101,   102,   103,   104,
     105,   106,     0,     0,     0,   107,   108,   109,   110,   111,
       0,     0,     0,     0,   112,   113,   114,   115,   116,   117,
     118,   119,     0,   120,     0,   121,   122,     0,     0,   123,
     124,   125,     0,     0,     0,   126,     0,   127,   128,     0,
     129,   130,   131,     0,   132,     0,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,     0,     0,   144,
     145,   146,     0,   378,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,     0,   191,   192,
     193,     0,   194,   195,   196,   197,   198,   199,     0,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,     1,
       0,     0,     0,     0,     0,     0,     0,     2,     3,     4,
       5,     6,     7,     0,     0,     8,     0,     0,     0,     9,
     375,     0,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,     0,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,     0,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,    71,    72,    73,    74,    75,
       0,     0,    76,    77,     0,     0,     0,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,     0,     0,
       0,    89,     0,    90,    91,    92,    93,     0,    94,     0,
       0,     0,    95,    96,    97,    98,    99,     0,     0,     0,
       0,     0,     0,   100,   101,   102,   103,   104,   105,   106,
       0,     0,     0,   107,   108,   109,   110,   111,     0,     0,
       0,     0,   112,   113,   114,   115,   116,   117,   118,   119,
       0,   120,     0,   121,   122,     0,     0,   123,   124,   125,
       0,     0,     0,   126,     0,   127,   128,     0,   129,   130,
     131,     0,   132,     0,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,     0,     0,   144,   145,   146,
       0,   378,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,     0,   191,   192,   193,     0,
     194,   195,   196,   197,   198,   199,     0,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,     1,     0,     0,
       0,     0,     0,     0,     0,     2,     3,     4,     5,     6,
       7,     0,     0,     8,     0,     0,     0,   804,   375,     0,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,   376,    27,    28,    29,    30,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,     0,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,    71,    72,    73,    74,    75,     0,     0,
      76,    77,     0,     0,     0,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,     0,     0,     0,    89,
       0,    90,    91,    92,    93,     0,    94,     0,     0,     0,
      95,    96,    97,    98,    99,     0,     0,     0,     0,     0,
       0,   100,   101,   102,   103,   104,   105,   106,     0,     0,
       0,   107,   108,   109,   110,   111,     0,     0,     0,     0,
     112,   113,   114,   115,   116,   117,   118,   119,     0,   120,
       0,   121,   122,     0,     0,   123,   124,   125,     0,     0,
       0,   126,     0,   127,   128,     0,   129,   130,   131,     0,
     132,     0,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,     0,     0,   144,   145,   146,     0,   378,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,     0,   191,   192,   193,     0,   194,   195,
     196,   197,   198,   199,     0,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,     1,     0,     0,     0,     0,
       0,     0,     0,     2,     3,     4,     5,     6,     7,     0,
       0,     8,     0,     0,     0,   374,   375,     0,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,   471,
     472,    24,   474,   376,    27,   475,    29,    30,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,   477,
      42,    43,   478,     0,    45,    46,    47,   480,   481,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,    71,    72,    73,    74,    75,     0,     0,    76,    77,
       0,     0,     0,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,     0,     0,     0,    89,     0,    90,
      91,    92,    93,     0,    94,     0,     0,     0,   489,    96,
      97,    98,    99,     0,     0,     0,     0,     0,     0,   100,
     101,   102,   103,   104,   105,   106,     0,     0,     0,   107,
     108,   109,   110,   111,     0,     0,     0,     0,   112,   113,
     114,   115,   116,   117,   118,   119,     0,   120,     0,   121,
     122,     0,     0,   123,   124,   125,     0,     0,     0,   126,
       0,   127,   128,     0,   129,   130,   131,     0,   132,     0,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,     0,     0,   144,   145,   146,     0,   378,   148,   149,
     150,   151,   152,   153,   154,   155,   498,   157,   499,   159,
     500,   501,   162,   163,   164,   165,   166,   167,   502,   169,
     503,   504,   505,   506,   174,   175,   507,   508,   178,   509,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,     0,   191,   192,   193,     0,   194,   195,   196,   197,
     198,   199,     0,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,     1,     0,     0,     0,     0,     0,     0,
       0,     2,     3,     4,     5,     6,     7,     0,     0,     8,
       0,     0,     0,  1010,   375,     0,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,   376,    27,    28,    29,    30,     0,    31,    32,    33,
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
       0,   144,   145,   146,     0,   378,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,     0,
     191,   192,   193,     0,   194,   195,   196,   197,   198,   199,
       0,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,     1,     0,     0,     0,     0,     0,     0,     0,     2,
       3,     4,     5,     6,     7,     0,     0,     8,     0,     0,
       0,   374,   375,     0,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,   471,   472,    24,   474,   376,
      27,   475,    29,    30,     0,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,   477,    42,    43,   478,     0,
      45,    46,    47,   480,   481,    50,   482,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,    71,    72,    73,
      74,    75,     0,     0,    76,    77,     0,     0,     0,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
       0,     0,     0,    89,     0,    90,    91,    92,    93,     0,
      94,     0,     0,     0,   489,    96,    97,    98,    99,     0,
       0,     0,     0,     0,     0,   100,   101,   102,   103,   104,
     105,   106,     0,     0,     0,   107,   108,     0,   110,   111,
       0,     0,     0,     0,   112,   113,   114,   115,   116,   117,
     118,   119,     0,   120,     0,     0,     0,     0,     0,   123,
     124,   125,     0,     0,     0,   126,     0,   127,   128,     0,
     129,   130,   131,     0,   132,     0,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,     0,     0,   144,
     145,   146,     0,   378,   148,   149,   150,   151,   152,   153,
     154,   155,   498,   157,   499,   159,   500,   501,   162,   163,
     164,   165,   166,   167,   502,   169,   503,   504,   505,   506,
     174,   175,   507,   508,   178,   509,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,     0,   191,   192,
     193,     0,   194,   195,   196,   197,   198,   199,     0,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,     1,
       0,     0,     0,     0,     0,     0,     0,     2,     3,     4,
       5,     6,     7,     0,     0,     8,     0,     0,     0,   374,
     375,     0,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,   471,   472,    24,   474,   376,    27,   475,
      29,    30,     0,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,   477,    42,    43,   478,     0,    45,    46,
      47,   480,   481,    50,   482,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,    71,    72,    73,    74,    75,
       0,     0,    76,    77,     0,     0,     0,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,     0,     0,
       0,    89,     0,    90,    91,    92,    93,     0,    94,     0,
       0,     0,   489,    96,    97,    98,    99,     0,     0,     0,
       0,     0,     0,   100,   101,   102,   103,   104,   105,   106,
       0,     0,     0,   107,   108,     0,   110,   111,     0,     0,
       0,     0,   112,   113,   114,   115,   116,   117,   118,   119,
       0,   120,     0,     0,     0,     0,     0,   123,   124,   125,
       0,     0,     0,   126,     0,   127,   128,     0,     0,     0,
     131,     0,   132,     0,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,     0,     0,   144,   145,   146,
       0,   378,   148,   149,   150,   151,   152,   153,   154,   155,
     498,   157,   499,   159,   500,   501,   162,   163,   164,   165,
     166,   167,   502,   169,   503,   504,   505,   506,   174,   175,
     507,   508,   178,   509,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,     0,   191,   192,   193,     0,
     194,   195,   196,   197,   198,   199,     0,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,     1,     0,     0,
       0,     0,     0,     0,     0,     2,     0,     0,     0,     6,
       7,     0,     0,   467,     0,     0,     0,   374,   375,     0,
      11,    12,    13,   468,    15,    16,    17,    18,   469,    20,
     470,   471,   472,   473,   474,   376,    27,   475,    29,    30,
       0,    31,    32,    33,    34,    35,   476,    37,    38,    39,
      40,   477,    42,    43,   478,     0,    45,   479,    47,   480,
     481,    50,   482,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,   483,   484,    67,     0,
      68,    69,    70,   485,     0,    73,    74,    75,     0,     0,
     486,    77,     0,     0,     0,     0,    79,    80,    81,   487,
     488,    84,    85,     0,     0,     0,     0,     0,     0,     0,
       0,    90,    91,    92,    93,     0,    94,     0,     0,     0,
     489,    96,    97,   490,   491,     0,     0,     0,     0,     0,
       0,   100,   101,   102,     0,   104,   105,   106,     0,     0,
       0,     0,     0,     0,   110,   111,     0,     0,     0,     0,
     112,   113,   114,   115,   492,   117,   118,   493,     0,     0,
       0,     0,     0,     0,     0,   494,   495,   125,     0,     0,
       0,   126,     0,   127,   496,     0,     0,     0,   131,     0,
     132,     0,   133,   134,   135,   136,   497,   138,   139,   140,
     141,   142,   143,     0,     0,   144,   145,     0,     0,   378,
     148,   149,   150,   151,   152,   153,   154,   155,   498,   157,
     499,   159,   500,   501,   162,   163,   164,   165,   166,   167,
     502,   169,   503,   504,   505,   506,   174,   175,   507,   508,
     178,   509,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,     0,   191,   192,   193,     0,   194,   195,
     196,   197,   198,   199,     0,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,     1,     0,     0,     0,     0,
       0,     0,     0,     2,     0,     0,     0,     6,     7,     0,
       0,   467,     0,     0,     0,   374,   375,     0,    11,    12,
      13,   516,    15,    16,    17,    18,   469,   517,   518,   471,
     472,   473,   474,   376,    27,   475,    29,    30,     0,    31,
      32,    33,    34,    35,   519,    37,   520,   521,    40,   477,
      42,    43,   478,     0,    45,   522,    47,   480,   481,    50,
     482,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,   483,   484,    67,     0,    68,    69,
      70,   523,     0,    73,    74,    75,     0,     0,   486,    77,
       0,     0,     0,     0,    79,    80,    81,   487,   488,    84,
      85,     0,     0,     0,     0,     0,     0,     0,     0,    90,
      91,    92,    93,     0,    94,     0,     0,     0,   489,    96,
      97,   490,   491,     0,     0,     0,     0,     0,     0,   100,
     101,   102,     0,   104,   105,   106,     0,     0,     0,     0,
       0,     0,   110,   111,     0,     0,     0,     0,   112,   113,
     114,   115,   492,   117,   118,   493,     0,     0,     0,     0,
       0,     0,     0,   494,   495,   125,     0,     0,     0,   126,
       0,   127,   496,     0,     0,     0,   131,     0,   132,     0,
     133,   134,   135,   136,   497,   138,   139,   140,   141,   142,
     143,     0,     0,   144,   145,     0,     0,   378,   148,   149,
     150,   151,   152,   153,   154,   155,   498,   524,   499,   159,
     500,   501,   162,   163,   164,   165,   166,   167,   502,   169,
     503,   504,   505,   506,   174,   175,   507,   508,   178,   509,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,     0,   191,   192,   193,     0,   194,   195,   196,   197,
     198,   199,     0,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   534,     0,     0,     0,     0,     0,     0,
       0,     6,     7,     0,     0,   740,     0,     0,     0,   374,
     375,     0,    11,    12,    13,   516,    15,    16,    17,    18,
     469,   517,   518,   471,   472,   473,   474,   376,    27,   475,
      29,    30,     0,    31,    32,    33,    34,    35,   519,    37,
     520,   521,    40,   477,    42,    43,   478,     0,    45,   522,
      47,   480,   481,    50,   482,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,   483,   484,
      67,     0,    68,    69,    70,   523,     0,    73,    74,    75,
       0,     0,   486,    77,     0,     0,     0,     0,    79,    80,
      81,   487,   488,    84,    85,     0,     0,     0,     0,     0,
       0,     0,     0,    90,    91,    92,    93,     0,    94,     0,
       0,     0,   489,    96,    97,   490,   491,     0,     0,     0,
       0,     0,     0,   100,   101,   102,     0,   104,   105,   106,
       0,     0,     0,     0,     0,     0,   110,   111,     0,     0,
       0,     0,   112,   113,   114,   115,   492,   117,   118,   493,
       0,     0,     0,     0,     0,     0,     0,   494,   495,   125,
       0,     0,     0,   126,   741,   127,   496,     0,     0,     0,
       0,     0,   132,     0,   133,   134,   135,   136,   497,   138,
     139,   140,   141,   142,   143,     0,     0,   144,   145,     0,
       0,   378,   148,   149,   150,   151,   152,   153,   154,   155,
     498,   524,   499,   159,   500,   501,   162,   163,   164,   165,
     166,   167,   502,   169,   503,   504,   505,   506,   174,   175,
     507,   508,   178,   509,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,     0,   191,   192,   193,     0,
     194,   195,   196,   197,   198,   199,     0,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   534,     0,     0,
       0,     0,     0,     0,     0,     6,     7,     0,     0,   467,
       0,     0,     0,   374,   375,     0,    11,    12,    13,   516,
      15,    16,    17,    18,   469,   517,   518,   471,   472,   473,
     474,   376,    27,   475,    29,    30,     0,    31,    32,    33,
      34,    35,   519,    37,   520,   521,    40,   477,    42,    43,
     478,     0,    45,   522,    47,   480,   481,    50,   482,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,   483,   484,    67,     0,    68,    69,    70,   523,
       0,    73,    74,    75,     0,     0,   486,    77,     0,     0,
       0,     0,    79,    80,    81,   487,   488,    84,    85,     0,
       0,     0,     0,     0,     0,     0,     0,    90,    91,    92,
      93,     0,    94,     0,     0,     0,   489,    96,    97,   490,
     491,     0,     0,     0,     0,     0,     0,   100,   101,   102,
       0,   104,   105,   106,     0,     0,     0,     0,     0,     0,
     110,   111,     0,     0,     0,     0,   112,   113,   114,   115,
     492,   117,   118,   493,     0,     0,     0,     0,     0,     0,
       0,   494,   495,   125,     0,     0,     0,   126,     0,   127,
     496,     0,     0,     0,     0,     0,   132,     0,   133,   134,
     135,   136,   497,   138,   139,   140,   141,   142,   143,     0,
       0,   144,   145,     0,     0,   378,   148,   149,   150,   151,
     152,   153,   154,   155,   498,   524,   499,   159,   500,   501,
     162,   163,   164,   165,   166,   167,   502,   169,   503,   504,
     505,   506,   174,   175,   507,   508,   178,   509,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,     0,
     191,   192,   193,     0,   194,   195,   196,   197,   198,   199,
       0,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   537,   538,     0,     0,     0,     0,     6,     7,     0,
       0,   467,     0,     0,     0,   374,   375,     0,    11,    12,
      13,   516,    15,    16,    17,    18,   469,   517,   518,   471,
     472,   473,   474,   376,    27,   475,    29,    30,     0,    31,
      32,    33,    34,    35,   519,    37,   520,   521,    40,   477,
      42,    43,   478,     0,    45,   522,    47,   480,   481,    50,
     482,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,   483,   484,    67,     0,    68,    69,
      70,   523,     0,    73,    74,    75,     0,     0,   486,    77,
       0,     0,     0,     0,    79,    80,    81,   487,   488,    84,
      85,     0,     0,     0,     0,     0,     0,     0,     0,    90,
      91,    92,    93,     0,    94,     0,     0,     0,   489,    96,
      97,   490,   491,     0,     0,     0,     0,     0,     0,   100,
     101,   102,     0,   104,   105,   106,     0,     0,     0,     0,
       0,     0,   110,   111,     0,     0,     0,     0,   112,   113,
     114,   115,   492,   117,   118,   493,     0,     0,     0,     0,
       0,     0,     0,   494,   495,   125,     0,     0,     0,   126,
       0,   127,   496,     0,     0,     0,     0,     0,   132,     0,
     133,   134,   135,   136,   497,   138,   139,   140,   141,   142,
     143,     0,     0,   144,   145,     0,     0,   378,   148,   149,
     150,   151,   152,   153,   154,   155,   498,   524,   499,   159,
     500,   501,   162,   163,   164,   165,   166,   167,   502,   169,
     503,   504,   505,   506,   174,   175,   507,   508,   178,   509,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,     0,   191,   192,   193,     0,   194,   195,   196,   197,
     198,   199,     0,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,     6,     7,     0,     0,   467,     0,     0,
       0,   374,   375,     0,    11,    12,    13,   468,    15,    16,
      17,    18,   469,    20,   470,   471,   472,  1050,   474,   376,
      27,   475,    29,    30,     0,    31,    32,    33,    34,    35,
     476,    37,    38,    39,    40,   477,    42,    43,   478,     0,
      45,   479,    47,   480,   481,    50,   482,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
     483,   484,    67,     0,    68,    69,    70,   485,     0,    73,
      74,    75,     0,     0,   486,    77,     0,     0,     0,     0,
      79,    80,    81,   487,   488,    84,    85,     0,     0,     0,
       0,     0,     0,     0,     0,    90,    91,    92,    93,     0,
      94,     0,     0,     0,   489,    96,    97,   490,   491,     0,
       0,     0,     0,     0,     0,   100,   101,   102,     0,   104,
     105,  1051,     0,     0,     0,  1052,     0,     0,   110,   111,
       0,     0,     0,     0,   112,   113,   114,   115,   492,   117,
     118,   493,     0,     0,     0,     0,     0,     0,     0,   494,
     495,   125,     0,     0,     0,   126,  1442,   127,   496,     0,
       0,     0,  1443,     0,   132,     0,   133,   134,   135,   136,
     497,   138,   139,   140,   141,   142,   143,     0,     0,  1053,
     145,     0,     0,   378,   148,   149,   150,   151,   152,   153,
     154,   155,   498,   157,   499,   159,   500,   501,   162,   163,
     164,   165,   166,   167,   502,   169,   503,   504,   505,   506,
     174,   175,   507,   508,   178,   509,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,     0,   191,   192,
     193,     0,   194,   195,   196,   197,   198,   199,     0,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,     6,
       7,     0,     0,   467,     0,     0,     0,   374,   375,     0,
      11,    12,    13,   516,    15,    16,    17,    18,   469,   517,
     518,   471,   472,   473,   474,   376,    27,   475,    29,    30,
       0,    31,    32,    33,    34,    35,   519,    37,   520,   521,
      40,   477,    42,    43,   478,     0,    45,   522,    47,   480,
     481,    50,   482,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,   483,   484,    67,     0,
      68,    69,    70,   523,     0,    73,    74,    75,     0,     0,
     486,    77,     0,     0,     0,     0,    79,    80,    81,   487,
     488,    84,    85,     0,     0,     0,     0,     0,     0,     0,
       0,    90,    91,    92,    93,     0,    94,     0,     0,     0,
     489,    96,    97,   490,   491,     0,     0,     0,     0,     0,
       0,   100,   101,   102,     0,   104,   105,   106,     0,     0,
       0,     0,     0,     0,   110,   111,     0,     0,     0,     0,
     112,   113,   114,   115,   492,   117,   118,   493,     0,     0,
       0,     0,     0,     0,     0,   494,   495,   125,     0,     0,
       0,   126,   710,   127,   496,     0,     0,     0,   711,     0,
     132,     0,   133,   134,   135,   136,   497,   138,   139,   140,
     141,   142,   143,     0,     0,   144,   145,     0,     0,   378,
     148,   149,   150,   151,   152,   153,   154,   155,   498,   524,
     499,   159,   500,   501,   162,   163,   164,   165,   166,   167,
     502,   169,   503,   504,   505,   506,   174,   175,   507,   508,
     178,   509,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,     0,   191,   192,   193,     0,   194,   195,
     196,   197,   198,   199,     0,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,     6,     7,     0,     0,   467,
       0,     0,     0,   374,   375,     0,    11,    12,    13,   516,
      15,    16,    17,    18,   469,   517,   518,   471,   472,   473,
     474,   376,    27,   475,    29,    30,     0,    31,    32,    33,
      34,    35,   519,    37,   520,   521,    40,   477,    42,    43,
     478,     0,    45,   522,    47,   480,   481,    50,   482,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,   483,   484,    67,     0,    68,    69,    70,   523,
       0,    73,    74,    75,     0,     0,   486,    77,     0,     0,
       0,     0,    79,    80,    81,   487,   488,    84,    85,     0,
       0,     0,     0,     0,     0,     0,     0,    90,    91,    92,
      93,     0,    94,     0,     0,     0,   489,    96,    97,   490,
     491,     0,     0,     0,     0,     0,     0,   100,   101,   102,
       0,   104,   105,   106,     0,     0,     0,     0,     0,     0,
     110,   111,     0,     0,     0,     0,   112,   113,   114,   115,
     492,   117,   118,   493,     0,     0,     0,     0,     0,     0,
       0,   494,   495,   125,     0,     0,     0,   126,   759,   127,
     496,     0,     0,     0,   760,     0,   132,     0,   133,   134,
     135,   136,   497,   138,   139,   140,   141,   142,   143,     0,
       0,   144,   145,     0,     0,   378,   148,   149,   150,   151,
     152,   153,   154,   155,   498,   524,   499,   159,   500,   501,
     162,   163,   164,   165,   166,   167,   502,   169,   503,   504,
     505,   506,   174,   175,   507,   508,   178,   509,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,     0,
     191,   192,   193,     0,   194,   195,   196,   197,   198,   199,
       0,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,     6,     7,     0,     0,   467,     0,     0,     0,   374,
     375,     0,    11,    12,    13,   468,    15,    16,    17,    18,
     469,    20,   470,   471,   472,  1050,   474,   376,    27,   475,
      29,    30,     0,    31,    32,    33,    34,    35,   476,    37,
      38,    39,    40,   477,    42,    43,   478,     0,    45,   479,
      47,   480,   481,    50,   482,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,   483,   484,
      67,     0,    68,    69,    70,   485,     0,    73,    74,    75,
       0,     0,   486,    77,     0,     0,     0,     0,    79,    80,
      81,   487,   488,    84,    85,  1372,     0,     0,     0,     0,
       0,     0,     0,    90,    91,    92,    93,     0,    94,     0,
       0,     0,   489,    96,    97,   490,   491,     0,     0,     0,
       0,     0,     0,   100,   101,   102,     0,   104,   105,  1051,
       0,     0,     0,  1052,     0,     0,   110,   111,     0,     0,
       0,     0,   112,   113,   114,   115,   492,   117,   118,   493,
       0,     0,     0,     0,     0,     0,     0,   494,   495,   125,
       0,     0,     0,   126,     0,   127,   496,     0,     0,     0,
       0,     0,   132,     0,   133,   134,   135,   136,   497,   138,
     139,   140,   141,   142,   143,     0,     0,  1053,   145,     0,
       0,   378,   148,   149,   150,   151,   152,   153,   154,   155,
     498,   157,   499,   159,   500,   501,   162,   163,   164,   165,
     166,   167,   502,   169,   503,   504,   505,   506,   174,   175,
     507,   508,   178,   509,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,     0,   191,   192,   193,     0,
     194,   195,   196,   197,   198,   199,     0,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,     6,     7,     0,
       0,   467,     0,     0,     0,   374,   375,     0,    11,    12,
      13,   468,    15,    16,    17,    18,   469,    20,   470,   471,
     472,  1050,   474,   376,    27,   475,    29,    30,     0,    31,
      32,    33,    34,    35,   476,    37,    38,    39,    40,   477,
      42,    43,   478,     0,    45,   479,    47,   480,   481,    50,
     482,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,   483,   484,    67,     0,    68,    69,
      70,   485,     0,    73,    74,    75,     0,     0,   486,    77,
       0,     0,     0,     0,    79,    80,    81,   487,   488,    84,
      85,     0,     0,     0,     0,     0,     0,     0,     0,    90,
      91,    92,    93,     0,    94,     0,     0,     0,   489,    96,
      97,   490,   491,     0,     0,     0,     0,     0,     0,   100,
     101,   102,     0,   104,   105,  1051,     0,     0,     0,  1052,
       0,     0,   110,   111,     0,     0,     0,     0,   112,   113,
     114,   115,   492,   117,   118,   493,     0,     0,     0,     0,
       0,     0,     0,   494,   495,   125,     0,     0,     0,   126,
       0,   127,   496,     0,     0,     0,     0,     0,   132,     0,
     133,   134,   135,   136,   497,   138,   139,   140,   141,   142,
     143,     0,     0,  1053,   145,     0,     0,   378,   148,   149,
     150,   151,   152,   153,   154,   155,   498,   157,   499,   159,
     500,   501,   162,   163,   164,   165,   166,   167,   502,   169,
     503,   504,   505,   506,   174,   175,   507,   508,   178,   509,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,     0,   191,   192,   193,     0,   194,   195,   196,   197,
     198,   199,     0,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,     6,     7,     0,     0,   467,     0,     0,
       0,   374,   375,     0,    11,    12,    13,   468,    15,    16,
      17,    18,   469,    20,   470,   471,   472,  1050,   474,   376,
      27,   475,    29,    30,     0,    31,    32,    33,    34,    35,
     476,    37,    38,    39,    40,   477,    42,    43,   478,     0,
      45,   479,    47,   480,   481,    50,   482,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
     483,   484,    67,     0,    68,    69,    70,   485,     0,    73,
      74,    75,     0,     0,   486,    77,     0,     0,     0,     0,
      79,    80,    81,   487,   488,    84,    85,     0,     0,     0,
       0,     0,     0,     0,     0,    90,    91,    92,    93,     0,
      94,     0,     0,     0,   489,    96,    97,   490,   491,     0,
       0,     0,     0,     0,     0,   100,   101,   102,     0,   104,
     105,  1051,     0,     0,     0,  1052,     0,     0,   110,   111,
       0,     0,     0,     0,   112,   113,   114,   115,   492,   117,
     118,   493,     0,     0,     0,     0,     0,     0,     0,   494,
     495,   125,     0,     0,     0,   126,     0,   127,   496,     0,
       0,     0,     0,     0,   132,     0,   133,   134,   135,   136,
     497,   138,   139,   140,   141,   142,   143,     0,     0,   144,
     145,     0,     0,   378,   148,   149,   150,   151,   152,   153,
     154,   155,   498,   157,   499,   159,   500,   501,   162,   163,
     164,   165,   166,   167,   502,   169,   503,   504,   505,   506,
     174,   175,   507,   508,   178,   509,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,     0,   191,   192,
     193,     0,   194,   195,   196,   197,   198,   199,     0,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,     6,
       7,     0,     0,   467,     0,     0,     0,   374,   375,     0,
      11,    12,    13,   516,    15,    16,    17,    18,   469,   517,
     518,   471,   472,   473,   474,   376,    27,   475,    29,    30,
       0,    31,    32,    33,    34,    35,   519,    37,   520,   521,
      40,   477,    42,    43,   478,     0,    45,   522,    47,   480,
     481,    50,   482,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,   483,   484,    67,     0,
      68,    69,    70,   523,     0,    73,    74,    75,     0,     0,
     486,    77,     0,     0,     0,     0,    79,    80,    81,   487,
     488,    84,    85,     0,     0,     0,     0,     0,     0,     0,
       0,    90,    91,    92,    93,     0,    94,     0,     0,     0,
     489,    96,    97,   490,   491,     0,     0,     0,     0,     0,
       0,   100,   101,   102,     0,   104,   105,   106,     0,     0,
       0,     0,     0,     0,   110,   111,     0,     0,     0,     0,
     112,   113,   114,   115,   492,   117,   118,   493,     0,     0,
       0,     0,     0,     0,     0,   494,   495,   125,     0,     0,
       0,   126,     0,   127,   496,     0,     0,     0,     0,     0,
     132,     0,   133,   134,   135,   136,   497,   138,   139,   140,
     141,   142,   143,     0,     0,   144,   145,     0,     0,   378,
     148,   149,   150,   151,   152,   153,   154,   155,   498,   524,
     499,   159,   500,   501,   162,   163,   164,   165,   166,   167,
     502,   169,   503,   504,   505,   506,   174,   175,   507,   508,
     178,   509,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,     0,   191,   192,   193,     0,   194,   195,
     196,   197,   198,   199,     0,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,     6,     7,     0,     0,   467,
       0,     0,     0,   374,   375,     0,    11,    12,    13,     0,
      15,    16,    17,    18,   469,     0,     0,   471,   472,   473,
       0,   376,    27,   475,    29,    30,     0,    31,    32,    33,
      34,    35,     0,    37,     0,     0,    40,   477,    42,    43,
     478,     0,    45,     0,    47,     0,     0,    50,   482,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,   483,   484,    67,     0,    68,    69,    70,     0,
       0,    73,    74,    75,     0,     0,   486,    77,     0,     0,
       0,     0,    79,    80,    81,   487,   488,    84,    85,     0,
       0,     0,     0,     0,     0,     0,     0,    90,    91,    92,
      93,     0,    94,     0,     0,     0,   489,    96,    97,   490,
     491,     0,     0,     0,     0,     0,     0,   100,   101,   102,
       0,   104,   105,     0,     0,     0,     0,     0,     0,     0,
     110,   111,     0,     0,     0,     0,   112,   113,   114,   115,
     492,   117,   118,   493,     0,     0,     0,     0,     0,     0,
       0,   494,   495,   125,     0,     0,     0,   126,     0,   127,
     496,     0,     0,     0,     0,     0,   132,     0,   133,   134,
     135,   136,   497,   138,   139,   140,   141,   142,   143,     0,
       0,     0,   145,     0,     0,   378,   148,   149,   150,   151,
     152,   153,   154,   155,   498,     0,   499,   159,   500,   501,
     162,   163,   164,   165,   166,   167,   502,   169,   503,   504,
     505,   506,   174,   175,     0,   508,   178,   509,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,     0,
     191,   192,   193,     0,   194,   195,   196,   197,   198,   199,
       0,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
        72,   655,   620,   718,   735,   621,   622,   623,   624,   385,
       3,     4,     5,   765,    86,   311,   958,   748,   582,   246,
     829,   247,   248,   576,   577,   842,  1235,   130,   991,  1399,
     574,   575,   576,   577,   718,   919,   108,   399,  1251,  1252,
     841,   842,    72,    27,  1036,    34,    34,    56,   120,     1,
     122,   574,   575,     1,  1284,    35,    36,  1122,    38,    39,
     663,     1,    28,   425,   117,   441,   442,     1,   880,     1,
       1,   117,     1,  1208,    94,    44,    27,   106,    58,   880,
      94,   141,    54,    93,  1462,    57,   600,   449,   602,   603,
      27,   605,    99,   607,    63,   106,   117,   146,     8,   135,
     106,   615,   616,   106,   106,    94,  1013,    96,    96,   106,
      67,   106,   106,   914,   107,    72,   117,    37,   935,    45,
     106,   106,    96,    43,    44,   109,    96,    99,   152,    52,
     168,   948,   112,   165,   935,    96,    94,   129,   112,   123,
      60,   146,    62,    63,   106,   135,   223,   948,   225,   181,
      94,    71,   176,   106,   129,   886,   147,   146,   146,   149,
     117,   112,   200,   199,   148,   186,     9,    10,   152,   152,
     223,   155,   182,   164,  1081,   829,   187,    97,   185,   159,
     106,   155,    72,   189,   185,   106,   189,   189,   146,   183,
     187,   186,   176,  1406,   155,     5,    86,   106,    94,     9,
     186,   186,   146,   195,   233,   128,   215,  1585,   159,     5,
     941,   314,   272,     9,   106,   235,   947,   186,   108,   106,
     195,   235,   159,   272,   186,   940,   272,  1036,  1037,  1171,
     120,  1461,   122,   186,  1118,   987,  1199,   189,   218,    94,
    1052,   189,   795,   796,   253,  1208,   212,   319,  1383,   189,
     322,  1052,   105,   306,   938,   189,   940,   189,   189,   102,
     189,  1326,   865,   866,   174,   186,  1636,   272,  1260,    96,
     793,   794,   106,   126,   258,   106,   960,   186,   250,   122,
     260,   124,  1652,   272,   272,   255,   256,   649,    96,   319,
    1660,   263,   322,   265,   186,     9,    10,   152,   120,   186,
     676,  1510,     9,   223,   276,   277,   278,   106,   280,   152,
     282,   825,   122,   156,   124,     9,    96,   389,   390,    26,
     216,   217,   132,   395,  1125,   130,   122,   399,   124,    94,
     173,   181,    26,   405,  1547,   231,   132,   928,   146,   930,
     412,   168,   152,    40,   194,   571,  1163,   574,   575,    46,
     193,   155,   186,   425,    51,   186,   152,   733,   215,   431,
     116,    27,  1163,   435,   219,   220,   146,   729,   211,  1186,
     732,   443,    94,    70,    94,  1588,   141,   449,   450,   451,
     452,   453,  1036,  1037,   189,  1186,   458,   186,   102,   145,
     181,   982,   152,   984,   466,   155,   253,  1128,    27,  1464,
      99,    94,   158,   194,    44,     9,    10,    47,   122,    96,
     124,   877,   159,   112,   136,   122,   152,   124,  1072,   141,
    1383,   141,  1137,   889,   251,   252,   133,   254,   122,   319,
     124,    96,   322,   426,   261,   428,   192,   430,   152,   133,
     176,  1325,   156,   109,   271,   152,   439,   112,   208,   152,
     152,  1260,   155,   143,   526,   448,   283,   123,   152,   173,
    1269,   454,  1146,   456,   457,   105,   459,  1020,  1021,  1022,
     167,  1280,   465,   170,   155,  1292,  1020,  1021,  1022,   193,
     109,   168,   148,    31,   556,   175,   152,  1552,   185,   155,
     155,  1292,   564,    99,   123,     9,    10,   211,   102,   121,
     390,    49,   192,   246,   247,   395,   112,   157,   155,   399,
     176,   887,   888,   210,    44,   405,   892,    47,   122,   148,
     124,  1586,   412,   216,   217,   175,   269,   167,    53,    31,
     152,   155,   262,   155,    59,   425,   639,   640,   231,   532,
     157,   431,  1484,   273,   117,   435,   922,    49,   152,    79,
      53,   544,   156,   443,   152,   157,    59,   155,   175,   449,
     450,   451,   452,   453,   251,   252,   793,   254,   458,   173,
     563,    96,   798,   175,    77,   105,   466,   649,   954,   155,
     197,    23,   958,  1648,   271,  1650,   147,   157,   102,   193,
      32,    25,   223,    96,   225,   667,   283,   669,  1565,  1566,
     672,  1666,   199,   164,   136,   175,  1260,   211,   122,   267,
     124,   208,   223,    47,   117,  1269,   274,   228,   268,    61,
     152,   693,   694,   695,  1433,   275,  1280,   197,  1343,  1381,
      64,   117,    66,  1385,  1601,   285,   526,   167,   152,   136,
    1607,    75,   156,   636,    53,   268,   155,   719,   641,   721,
      59,    95,   275,  1271,   136,   152,    96,   729,   136,   173,
     732,   105,   285,   141,   736,  1396,   556,   262,   155,    25,
     152,   115,   112,    94,   564,   121,   136,   111,   273,   193,
     298,   141,   126,   321,   105,   190,   191,  1240,   326,   307,
     121,    47,   764,   276,   277,   278,   153,   211,   155,   282,
     642,    57,   152,   645,   152,   155,   648,   155,    64,   230,
      66,   232,  1529,   121,  1531,   219,   220,   221,   230,    75,
     232,   299,   300,    79,   299,   300,   127,   128,  1529,   117,
    1531,   121,   725,   290,   291,   127,   128,   618,   619,   625,
     626,   813,  1038,  1307,  1561,  1497,   843,   844,  1500,   627,
     628,  1452,  1453,   121,   110,   111,   112,   121,   121,   649,
    1561,   152,   121,   756,   757,  1582,   121,   121,   168,   841,
     842,   843,   844,   121,   152,   214,   155,   117,   223,  1433,
     152,  1582,   672,   241,   240,   240,   155,   152,   117,     0,
    1166,    92,   166,   786,   248,  1171,    50,   100,   120,   198,
     200,  1417,   153,   693,   694,   695,  1424,  1425,   880,   101,
     144,   155,   168,   183,   155,    27,  1547,  1569,    47,    47,
      47,   183,   894,   183,   151,   245,   117,   292,   228,   719,
     297,   721,   131,   297,   303,   117,   186,   152,     1,   729,
     139,   140,   732,   142,   200,   283,   736,   283,   117,   921,
     106,   150,   141,   186,   152,   154,   928,   156,   930,   152,
     155,   155,   161,   935,    33,   155,   186,   155,   155,    16,
     212,  1247,   228,    27,   764,   186,   948,   229,     3,   178,
     141,   117,   167,   169,    71,   169,   286,   287,   288,   289,
     290,   229,   292,   293,   294,   295,   296,    94,    94,  1517,
    1518,   301,   201,   202,   203,   204,   205,   206,    94,   148,
     982,   106,   984,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,   813,   106,    27,   159,   159,   126,   131,
     286,   287,   288,   289,   290,   245,   292,   293,   294,   295,
     296,   298,   117,   131,   186,   301,   302,   106,   183,   183,
      94,   841,   842,   843,   844,   186,   186,   183,   183,  1031,
    1578,    96,    44,    96,   183,   186,   186,   141,   186,   186,
     183,   186,   186,   152,   183,   183,   183,   183,    94,   223,
    1052,   141,   235,  1359,   977,   186,    31,   117,   169,   183,
     880,   183,   131,   184,    94,   141,    27,   152,   298,   117,
     126,   225,   285,   117,   894,   146,   253,   117,    94,   131,
     183,   196,   131,    96,   159,   152,   117,   146,    99,    99,
     152,   183,   183,    33,    27,   117,   117,   183,   244,   152,
     117,   921,    79,   106,  1410,   106,   284,   259,   928,   143,
     930,    27,  1035,   266,   155,   935,   155,   257,   155,    27,
      27,   235,   186,   225,   225,   305,   146,   432,   948,   225,
     126,   189,   186,   117,  1136,   143,   186,  1139,   117,   186,
     146,   146,    77,   106,   141,   183,   131,     7,   231,   231,
     285,   186,  1154,   286,   235,   105,  1079,   186,   231,   231,
     185,  1163,   982,   189,   984,   183,   105,   186,   146,   249,
     249,   281,   285,    78,    27,    27,  1178,   186,  1484,   186,
     106,   183,   186,   270,  1186,   183,   169,   146,   256,   146,
      96,   125,   183,   185,   183,   185,   183,   183,   152,    94,
      27,   279,    96,  1205,   186,   186,    53,  1130,   146,   169,
      94,  1031,   141,   117,    94,   195,   286,    27,   106,   264,
     106,   117,   195,   223,  1226,   117,   195,  1229,   183,   185,
     117,    93,  1052,  1235,   185,   223,   182,  1239,   304,   117,
     117,   152,   195,   548,   549,   117,   551,   552,   553,   554,
     292,   223,   197,  1176,   305,   186,   561,   562,   286,   117,
     675,   304,  1085,   881,   240,  1125,  1552,  1586,   304,  1192,
    1231,   949,   305,   243,   579,   580,   243,   946,   305,  1136,
     246,  1239,   738,   417,   589,   590,   393,   286,  1353,   419,
    1292,  1256,  1155,  1178,  1027,  1251,   419,  1254,  1187,   526,
     765,   598,   651,  1183,  1199,  1607,  1601,   844,   599,   438,
    1119,   930,   307,  1084,  1226,  1433,  1136,  1269,  1037,  1139,
    1430,  1323,  1046,   429,  1273,  1236,   913,  1280,  1107,   429,
    1315,  1455,  1270,    -1,  1154,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   647,  1163,    -1,    -1,   651,    -1,  1350,  1351,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1178,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1186,    -1,    -1,    -1,
    1372,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1382,    -1,    -1,    -1,  1386,  1205,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1226,    -1,    -1,  1229,
      -1,    -1,    -1,    -1,    -1,  1235,    -1,    -1,    -1,  1239,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   737,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1292,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1493,    -1,    -1,    -1,    -1,  1498,    -1,    -1,    -1,
      -1,    -1,    -1,  1323,   809,    -1,    -1,    -1,  1510,    -1,
     815,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1529,    -1,  1531,
    1350,  1351,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1548,    -1,    -1,  1551,
      -1,    -1,  1372,    -1,    -1,    -1,    -1,    -1,    -1,  1561,
      -1,    -1,  1382,    -1,    -1,    -1,  1386,    -1,    -1,    -1,
      -1,    -1,  1574,    -1,    -1,    -1,    -1,   882,    -1,    -1,
    1582,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1590,    -1,
      -1,    -1,    -1,  1595,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1527,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1623,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   937,    -1,    -1,    -1,    -1,    -1,  1640,    -1,
    1642,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1655,   959,    -1,    -1,  1659,    -1,    -1,
      -1,    -1,  1664,    -1,   969,    -1,   971,   972,    -1,    -1,
      -1,    -1,    -1,  1493,    -1,    -1,    -1,    -1,  1498,    -1,
      -1,   986,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1510,    -1,   997,   998,   999,    -1,  1001,  1002,  1003,  1004,
    1005,  1006,    -1,  1008,  1009,    -1,    -1,    25,    -1,  1529,
      -1,  1531,    -1,    -1,    -1,    -1,    -1,    35,    36,    -1,
      38,    39,  1027,    -1,    -1,    -1,    -1,    -1,  1548,    47,
      -1,  1551,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,
      58,  1561,    -1,    -1,    -1,    -1,    64,    -1,    66,    -1,
      -1,    -1,    -1,    -1,  1574,    -1,    -1,    75,    -1,    -1,
      -1,    79,  1582,    -1,  1069,    -1,    -1,    -1,    -1,    -1,
    1590,    -1,    -1,    -1,    -1,  1595,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   110,   111,   112,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1623,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1640,    -1,  1642,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1655,  1141,    -1,  1143,  1659,
    1145,   159,    -1,  1148,  1664,    -1,    -1,    -1,  1153,    -1,
     168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1165,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1174,
      -1,    -1,    -1,    -1,    -1,    -1,  1181,  1182,    -1,    -1,
      -1,    -1,   200,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     218,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1238,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,    -1,  1254,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   286,   287,
     288,   289,   290,    -1,   292,   293,   294,   295,   296,    -1,
      -1,    -1,    -1,   301,   302,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1337,    -1,    -1,    -1,  1341,    -1,    -1,    -1,
    1345,    -1,  1347,    -1,  1349,    -1,    -1,    -1,    -1,    -1,
    1355,    -1,    -1,    -1,    -1,    -1,    -1,  1362,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1370,  1371,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1389,  1390,  1391,  1392,  1393,    -1,
    1395,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1471,    -1,  1473,    -1,
      -1,  1476,    -1,    -1,    -1,    -1,    -1,    -1,  1483,    -1,
      -1,    -1,    -1,  1488,    -1,    -1,    -1,  1492,    -1,  1494,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1507,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1555,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1573,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1597,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1621,    -1,    11,    -1,
      -1,  1626,    -1,    -1,    -1,    -1,    19,    20,    21,    22,
      23,    24,    -1,    -1,    27,    -1,    -1,    -1,    31,    32,
    1645,    34,    35,    36,    37,    38,    39,    40,    41,    42,
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
     303,   304,   305,   306,   307,   308,   309,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    19,    20,    21,    22,    23,
      24,    -1,    -1,    27,    -1,    -1,    -1,    31,    32,    -1,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      94,    95,    96,    97,    98,    99,   100,   101,    -1,    -1,
     104,   105,    -1,    -1,    -1,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,    -1,    -1,    -1,   123,
      -1,   125,   126,   127,   128,    -1,   130,    -1,    -1,    -1,
     134,   135,   136,   137,   138,    -1,    -1,    -1,    -1,    -1,
      -1,   145,   146,   147,   148,   149,   150,   151,    -1,    -1,
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
     254,   255,   256,    -1,   258,   259,   260,    -1,   262,   263,
     264,   265,   266,   267,    -1,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    19,    20,    21,    22,    23,    24,    -1,
      -1,    27,    -1,    -1,    -1,    31,    32,    -1,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    98,    99,   100,   101,    -1,    -1,   104,   105,
      -1,    -1,    -1,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,    -1,    -1,    -1,   123,    -1,   125,
     126,   127,   128,    -1,   130,    -1,    -1,    -1,   134,   135,
     136,   137,   138,    -1,    -1,    -1,    -1,    -1,    -1,   145,
     146,   147,   148,   149,   150,   151,    -1,    -1,    -1,   155,
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
     256,    -1,   258,   259,   260,    -1,   262,   263,   264,   265,
     266,   267,    -1,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    19,    20,    21,    22,    23,    24,    -1,    -1,    27,
      -1,    -1,    -1,    31,    32,    -1,    34,    35,    36,    37,
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
      -1,   179,   180,   181,    -1,   183,    -1,   185,    -1,   187,
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
     308,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      20,    21,    22,    23,    24,    -1,    -1,    27,    -1,    -1,
      -1,    31,    32,    -1,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    -1,    94,    95,    96,    97,    98,    99,
     100,   101,    -1,    -1,   104,   105,    -1,    -1,    -1,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
      -1,    -1,    -1,   123,    -1,   125,   126,   127,   128,    -1,
     130,    -1,    -1,    -1,   134,   135,   136,   137,   138,    -1,
      -1,    -1,    -1,    -1,    -1,   145,   146,   147,   148,   149,
     150,   151,    -1,    -1,    -1,   155,   156,   157,   158,   159,
      -1,    -1,    -1,    -1,   164,   165,   166,   167,   168,   169,
     170,   171,    -1,   173,    -1,   175,   176,    -1,    -1,   179,
     180,   181,    -1,    -1,    -1,   185,   186,   187,   188,    -1,
     190,   191,   192,    -1,   194,    -1,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,    -1,    -1,   209,
     210,   211,    -1,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,    -1,   258,   259,
     260,    -1,   262,   263,   264,   265,   266,   267,    -1,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    21,
      22,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,    31,
      32,    -1,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    97,    98,    99,   100,   101,
      -1,    -1,   104,   105,    -1,    -1,    -1,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,    -1,    -1,
      -1,   123,    -1,   125,   126,   127,   128,    -1,   130,    -1,
      -1,    -1,   134,   135,   136,   137,   138,    -1,    -1,    -1,
      -1,    -1,    -1,   145,   146,   147,   148,   149,   150,   151,
      -1,    -1,    -1,   155,   156,   157,   158,   159,    -1,    -1,
      -1,    -1,   164,   165,   166,   167,   168,   169,   170,   171,
      -1,   173,    -1,   175,   176,    -1,    -1,   179,   180,   181,
      -1,   183,    -1,   185,    -1,   187,   188,    -1,   190,   191,
     192,    -1,   194,    -1,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,    -1,    -1,   209,   210,   211,
      -1,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,    -1,   258,   259,   260,    -1,
     262,   263,   264,   265,   266,   267,    -1,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    19,    20,    21,    22,    23,
      24,    -1,    -1,    27,    -1,    -1,    -1,    31,    32,    -1,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      94,    95,    96,    97,    98,    99,   100,   101,    -1,    -1,
     104,   105,    -1,    -1,    -1,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,    -1,    -1,    -1,   123,
      -1,   125,   126,   127,   128,    -1,   130,    -1,    -1,    -1,
     134,   135,   136,   137,   138,    -1,    -1,    -1,    -1,    -1,
      -1,   145,   146,   147,   148,   149,   150,   151,    -1,    -1,
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
     254,   255,   256,    -1,   258,   259,   260,    -1,   262,   263,
     264,   265,   266,   267,    -1,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    19,    20,    21,    22,    23,    24,    -1,
      -1,    27,    -1,    -1,    -1,    31,    32,    -1,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    98,    99,   100,   101,    -1,    -1,   104,   105,
      -1,    -1,    -1,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,    -1,    -1,    -1,   123,    -1,   125,
     126,   127,   128,    -1,   130,    -1,    -1,    -1,   134,   135,
     136,   137,   138,    -1,    -1,    -1,    -1,    -1,    -1,   145,
     146,   147,   148,   149,   150,   151,    -1,    -1,    -1,   155,
     156,   157,   158,   159,    -1,    -1,    -1,    -1,   164,   165,
     166,   167,   168,   169,   170,   171,    -1,   173,    -1,   175,
     176,    -1,    -1,   179,   180,   181,    -1,    -1,    -1,   185,
     186,   187,   188,    -1,   190,   191,   192,    -1,   194,    -1,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,    -1,    -1,   209,   210,   211,    -1,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,    -1,   258,   259,   260,    -1,   262,   263,   264,   265,
     266,   267,    -1,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    19,    20,    21,    22,    23,    24,    -1,    -1,    27,
      -1,    -1,    -1,    31,    32,    -1,    34,    35,    36,    37,
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
      -1,   179,   180,   181,    -1,   183,    -1,   185,    -1,   187,
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
     308,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      20,    21,    22,    23,    24,    -1,    -1,    27,    -1,    -1,
      -1,    31,    32,    -1,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    -1,    94,    95,    96,    97,    98,    99,
     100,   101,    -1,    -1,   104,   105,    -1,    -1,    -1,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
      -1,    -1,    -1,   123,    -1,   125,   126,   127,   128,    -1,
     130,    -1,    -1,    -1,   134,   135,   136,   137,   138,    -1,
      -1,    -1,    -1,    -1,    -1,   145,   146,   147,   148,   149,
     150,   151,    -1,    -1,    -1,   155,   156,   157,   158,   159,
      -1,    -1,    -1,    -1,   164,   165,   166,   167,   168,   169,
     170,   171,    -1,   173,    -1,   175,   176,    -1,    -1,   179,
     180,   181,    -1,   183,    -1,   185,    -1,   187,   188,    -1,
     190,   191,   192,    -1,   194,    -1,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,    -1,    -1,   209,
     210,   211,    -1,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,    -1,   258,   259,
     260,    -1,   262,   263,   264,   265,   266,   267,    -1,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    21,
      22,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,    31,
      32,    -1,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    97,    98,    99,   100,   101,
      -1,    -1,   104,   105,    -1,    -1,    -1,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,    -1,    -1,
      -1,   123,    -1,   125,   126,   127,   128,    -1,   130,    -1,
      -1,    -1,   134,   135,   136,   137,   138,    -1,    -1,    -1,
      -1,    -1,    -1,   145,   146,   147,   148,   149,   150,   151,
      -1,    -1,    -1,   155,   156,   157,   158,   159,    -1,    -1,
      -1,    -1,   164,   165,   166,   167,   168,   169,   170,   171,
      -1,   173,    -1,   175,   176,    -1,    -1,   179,   180,   181,
      -1,   183,    -1,   185,    -1,   187,   188,    -1,   190,   191,
     192,    -1,   194,    -1,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,    -1,    -1,   209,   210,   211,
      -1,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,    -1,   258,   259,   260,    -1,
     262,   263,   264,   265,   266,   267,    -1,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    19,    20,    21,    22,    23,
      24,    -1,    -1,    27,    -1,    -1,    -1,    31,    32,    -1,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      94,    95,    96,    97,    98,    99,   100,   101,    -1,    -1,
     104,   105,    -1,    -1,    -1,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,    -1,    -1,    -1,   123,
      -1,   125,   126,   127,   128,    -1,   130,    -1,    -1,    -1,
     134,   135,   136,   137,   138,    -1,    -1,    -1,    -1,    -1,
      -1,   145,   146,   147,   148,   149,   150,   151,    -1,    -1,
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
     254,   255,   256,    -1,   258,   259,   260,    -1,   262,   263,
     264,   265,   266,   267,    -1,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    19,    20,    21,    22,    23,    24,    -1,
      -1,    27,    -1,    -1,    -1,    31,    32,    -1,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    98,    99,   100,   101,    -1,    -1,   104,   105,
      -1,    -1,    -1,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,    -1,    -1,    -1,   123,    -1,   125,
     126,   127,   128,    -1,   130,    -1,    -1,    -1,   134,   135,
     136,   137,   138,    -1,    -1,    -1,    -1,    -1,    -1,   145,
     146,   147,   148,   149,   150,   151,    -1,    -1,    -1,   155,
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
     256,    -1,   258,   259,   260,    -1,   262,   263,   264,   265,
     266,   267,    -1,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    19,    20,    21,    22,    23,    24,    -1,    -1,    27,
      -1,    -1,    -1,    31,    32,    -1,    34,    35,    36,    37,
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
     308,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      20,    21,    22,    23,    24,    -1,    -1,    27,    -1,    -1,
      -1,    31,    32,    -1,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    -1,    94,    95,    96,    97,    98,    99,
     100,   101,    -1,    -1,   104,   105,    -1,    -1,    -1,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
      -1,    -1,    -1,   123,    -1,   125,   126,   127,   128,    -1,
     130,    -1,    -1,    -1,   134,   135,   136,   137,   138,    -1,
      -1,    -1,    -1,    -1,    -1,   145,   146,   147,   148,   149,
     150,   151,    -1,    -1,    -1,   155,   156,   157,   158,   159,
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
     260,    -1,   262,   263,   264,   265,   266,   267,    -1,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    21,
      22,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,    31,
      32,    -1,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    97,    98,    99,   100,   101,
      -1,    -1,   104,   105,    -1,    -1,    -1,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,    -1,    -1,
      -1,   123,    -1,   125,   126,   127,   128,    -1,   130,    -1,
      -1,    -1,   134,   135,   136,   137,   138,    -1,    -1,    -1,
      -1,    -1,    -1,   145,   146,   147,   148,   149,   150,   151,
      -1,    -1,    -1,   155,   156,   157,   158,   159,    -1,    -1,
      -1,    -1,   164,   165,   166,   167,   168,   169,   170,   171,
      -1,   173,    -1,   175,   176,    -1,    -1,   179,   180,   181,
      -1,    -1,    -1,   185,    -1,   187,   188,    -1,   190,   191,
     192,    -1,   194,    -1,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,    -1,    -1,   209,   210,   211,
      -1,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,    -1,   258,   259,   260,    -1,
     262,   263,   264,   265,   266,   267,    -1,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    19,    20,    21,    22,    23,
      24,    -1,    -1,    27,    -1,    -1,    -1,    31,    32,    -1,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      94,    95,    96,    97,    98,    99,   100,   101,    -1,    -1,
     104,   105,    -1,    -1,    -1,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,    -1,    -1,    -1,   123,
      -1,   125,   126,   127,   128,    -1,   130,    -1,    -1,    -1,
     134,   135,   136,   137,   138,    -1,    -1,    -1,    -1,    -1,
      -1,   145,   146,   147,   148,   149,   150,   151,    -1,    -1,
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
     254,   255,   256,    -1,   258,   259,   260,    -1,   262,   263,
     264,   265,   266,   267,    -1,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    19,    20,    21,    22,    23,    24,    -1,
      -1,    27,    -1,    -1,    -1,    31,    32,    -1,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    98,    99,   100,   101,    -1,    -1,   104,   105,
      -1,    -1,    -1,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,    -1,    -1,    -1,   123,    -1,   125,
     126,   127,   128,    -1,   130,    -1,    -1,    -1,   134,   135,
     136,   137,   138,    -1,    -1,    -1,    -1,    -1,    -1,   145,
     146,   147,   148,   149,   150,   151,    -1,    -1,    -1,   155,
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
     256,    -1,   258,   259,   260,    -1,   262,   263,   264,   265,
     266,   267,    -1,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    19,    20,    21,    22,    23,    24,    -1,    -1,    27,
      -1,    -1,    -1,    31,    32,    -1,    34,    35,    36,    37,
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
     308,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      20,    21,    22,    23,    24,    -1,    -1,    27,    -1,    -1,
      -1,    31,    32,    -1,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    -1,    94,    95,    96,    97,    98,    99,
     100,   101,    -1,    -1,   104,   105,    -1,    -1,    -1,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
      -1,    -1,    -1,   123,    -1,   125,   126,   127,   128,    -1,
     130,    -1,    -1,    -1,   134,   135,   136,   137,   138,    -1,
      -1,    -1,    -1,    -1,    -1,   145,   146,   147,   148,   149,
     150,   151,    -1,    -1,    -1,   155,   156,    -1,   158,   159,
      -1,    -1,    -1,    -1,   164,   165,   166,   167,   168,   169,
     170,   171,    -1,   173,    -1,    -1,    -1,    -1,    -1,   179,
     180,   181,    -1,    -1,    -1,   185,    -1,   187,   188,    -1,
     190,   191,   192,    -1,   194,    -1,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,    -1,    -1,   209,
     210,   211,    -1,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,    -1,   258,   259,
     260,    -1,   262,   263,   264,   265,   266,   267,    -1,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    21,
      22,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,    31,
      32,    -1,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    97,    98,    99,   100,   101,
      -1,    -1,   104,   105,    -1,    -1,    -1,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,    -1,    -1,
      -1,   123,    -1,   125,   126,   127,   128,    -1,   130,    -1,
      -1,    -1,   134,   135,   136,   137,   138,    -1,    -1,    -1,
      -1,    -1,    -1,   145,   146,   147,   148,   149,   150,   151,
      -1,    -1,    -1,   155,   156,    -1,   158,   159,    -1,    -1,
      -1,    -1,   164,   165,   166,   167,   168,   169,   170,   171,
      -1,   173,    -1,    -1,    -1,    -1,    -1,   179,   180,   181,
      -1,    -1,    -1,   185,    -1,   187,   188,    -1,    -1,    -1,
     192,    -1,   194,    -1,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,    -1,    -1,   209,   210,   211,
      -1,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,    -1,   258,   259,   260,    -1,
     262,   263,   264,   265,   266,   267,    -1,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    19,    -1,    -1,    -1,    23,
      24,    -1,    -1,    27,    -1,    -1,    -1,    31,    32,    -1,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
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
      -1,   185,    -1,   187,   188,    -1,    -1,    -1,   192,    -1,
     194,    -1,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,    -1,    -1,   209,   210,    -1,    -1,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,   258,   259,   260,    -1,   262,   263,
     264,   265,   266,   267,    -1,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    19,    -1,    -1,    -1,    23,    24,    -1,
      -1,    27,    -1,    -1,    -1,    31,    32,    -1,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    70,    71,    72,    73,    74,    75,
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
      -1,   187,   188,    -1,    -1,    -1,   192,    -1,   194,    -1,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,    -1,    -1,   209,   210,    -1,    -1,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,    -1,   258,   259,   260,    -1,   262,   263,   264,   265,
     266,   267,    -1,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,    31,
      32,    -1,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
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
      -1,    -1,    -1,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,    -1,   194,    -1,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,    -1,    -1,   209,   210,    -1,
      -1,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,    -1,   258,   259,   260,    -1,
     262,   263,   264,   265,   266,   267,    -1,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,    15,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    23,    24,    -1,    -1,    27,
      -1,    -1,    -1,    31,    32,    -1,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
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
      -1,   179,   180,   181,    -1,    -1,    -1,   185,    -1,   187,
     188,    -1,    -1,    -1,    -1,    -1,   194,    -1,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,    -1,
      -1,   209,   210,    -1,    -1,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,    -1,
     258,   259,   260,    -1,   262,   263,   264,   265,   266,   267,
      -1,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,    17,    18,    -1,    -1,    -1,    -1,    23,    24,    -1,
      -1,    27,    -1,    -1,    -1,    31,    32,    -1,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    70,    71,    72,    73,    74,    75,
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
     256,    -1,   258,   259,   260,    -1,   262,   263,   264,   265,
     266,   267,    -1,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,    23,    24,    -1,    -1,    27,    -1,    -1,
      -1,    31,    32,    -1,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
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
     250,   251,   252,   253,   254,   255,   256,    -1,   258,   259,
     260,    -1,   262,   263,   264,   265,   266,   267,    -1,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,    23,
      24,    -1,    -1,    27,    -1,    -1,    -1,    31,    32,    -1,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
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
     264,   265,   266,   267,    -1,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,    23,    24,    -1,    -1,    27,
      -1,    -1,    -1,    31,    32,    -1,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
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
     188,    -1,    -1,    -1,   192,    -1,   194,    -1,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,    -1,
      -1,   209,   210,    -1,    -1,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,    -1,
     258,   259,   260,    -1,   262,   263,   264,   265,   266,   267,
      -1,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,    31,
      32,    -1,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
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
     252,   253,   254,   255,   256,    -1,   258,   259,   260,    -1,
     262,   263,   264,   265,   266,   267,    -1,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,    23,    24,    -1,
      -1,    27,    -1,    -1,    -1,    31,    32,    -1,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    -1,    99,   100,   101,    -1,    -1,   104,   105,
      -1,    -1,    -1,    -1,   110,   111,   112,   113,   114,   115,
     116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,
     126,   127,   128,    -1,   130,    -1,    -1,    -1,   134,   135,
     136,   137,   138,    -1,    -1,    -1,    -1,    -1,    -1,   145,
     146,   147,    -1,   149,   150,   151,    -1,    -1,    -1,   155,
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
     256,    -1,   258,   259,   260,    -1,   262,   263,   264,   265,
     266,   267,    -1,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,    23,    24,    -1,    -1,    27,    -1,    -1,
      -1,    31,    32,    -1,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
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
     250,   251,   252,   253,   254,   255,   256,    -1,   258,   259,
     260,    -1,   262,   263,   264,   265,   266,   267,    -1,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,    23,
      24,    -1,    -1,    27,    -1,    -1,    -1,    31,    32,    -1,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
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
     264,   265,   266,   267,    -1,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,    23,    24,    -1,    -1,    27,
      -1,    -1,    -1,    31,    32,    -1,    34,    35,    36,    -1,
      38,    39,    40,    41,    42,    -1,    -1,    45,    46,    47,
      -1,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    -1,    61,    -1,    -1,    64,    65,    66,    67,
      68,    -1,    70,    -1,    72,    -1,    -1,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    -1,    94,    95,    96,    -1,
      -1,    99,   100,   101,    -1,    -1,   104,   105,    -1,    -1,
      -1,    -1,   110,   111,   112,   113,   114,   115,   116,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,   126,   127,
     128,    -1,   130,    -1,    -1,    -1,   134,   135,   136,   137,
     138,    -1,    -1,    -1,    -1,    -1,    -1,   145,   146,   147,
      -1,   149,   150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     158,   159,    -1,    -1,    -1,    -1,   164,   165,   166,   167,
     168,   169,   170,   171,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   179,   180,   181,    -1,    -1,    -1,   185,    -1,   187,
     188,    -1,    -1,    -1,    -1,    -1,   194,    -1,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,    -1,
      -1,    -1,   210,    -1,    -1,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,    -1,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,    -1,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,    -1,
     258,   259,   260,    -1,   262,   263,   264,   265,   266,   267,
      -1,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308
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
      23,    32,    61,   117,   272,   412,   414,   417,   152,   155,
     155,   155,   117,   117,   152,   155,   155,   155,    94,   152,
     219,   220,   121,   121,   121,   152,   155,    27,    37,    42,
      44,    45,    46,    47,    48,    51,    60,    65,    68,    71,
      73,    74,    76,    90,    91,    97,   104,   113,   114,   134,
     137,   138,   168,   171,   179,   180,   188,   200,   222,   224,
     226,   227,   234,   236,   237,   238,   239,   242,   243,   245,
     479,   616,   617,   121,   121,   121,    37,    43,    44,    60,
      62,    63,    71,    97,   223,   616,   117,   121,   121,   186,
     394,   616,   152,   121,    15,   615,   616,    17,    18,   616,
     121,   121,   121,   471,   152,    28,   212,   214,   223,   225,
     155,   223,   225,   223,   223,   228,   117,   152,   373,   240,
     240,   241,   155,   152,   117,   326,     0,   328,   329,    31,
      49,   331,   332,     1,   189,   325,   189,   325,   136,   141,
     106,   189,   395,    40,    46,    51,    70,   167,   170,   185,
     210,   399,   404,   405,   406,   422,   423,   427,   166,    92,
     131,   139,   140,   142,   150,   154,   156,   161,   178,   201,
     202,   203,   204,   205,   206,   463,   464,   248,   157,   175,
     197,   116,   145,   158,   192,   199,   208,   135,   149,    50,
     198,   100,   101,   157,   175,   462,   152,   468,   471,   190,
     191,   153,   483,   484,   479,   483,   479,   155,   483,   120,
     144,   155,   183,   183,   183,   155,   614,   181,   194,   181,
     194,   165,   181,   617,   616,   168,   200,    47,   386,    47,
     616,   151,   117,    44,    47,    79,   105,   167,   615,   219,
     220,   221,   299,   300,   245,   587,   616,   292,   616,   297,
     297,   299,   300,   303,   286,   294,   362,   111,   382,   385,
     615,   394,   186,   394,    44,    63,   186,   536,   537,   394,
     186,   192,   616,   397,   283,   283,   409,   410,   616,   117,
     418,   117,   186,   389,   390,   152,   391,   394,     1,   159,
     614,   112,   159,   353,   614,   616,   117,   141,   106,   394,
      27,   186,   615,   616,   616,   616,   435,   436,   616,   394,
     186,   394,   394,   538,   616,   394,   152,   152,   394,   186,
     192,   616,   435,   186,    33,   499,   500,   501,   394,     8,
     174,    16,   394,   212,    27,   397,   397,   186,   397,   397,
     397,   397,   229,   554,   555,   616,   374,   397,   397,   394,
     415,   416,   616,   189,   325,   189,   325,     3,   332,   333,
     393,   332,   333,   393,    31,   334,   393,   334,   393,   141,
     397,   397,   396,   117,   167,   169,   169,   397,   397,   446,
     447,   449,   449,   449,   449,   448,   449,   449,   449,    71,
     453,   453,   452,   454,   454,   454,   454,   455,   455,   456,
     456,   229,    94,    94,    94,   183,   394,   471,   471,   394,
     484,   186,   397,   494,   615,   148,   186,   494,    27,   383,
     486,   106,   106,   371,    27,   617,   617,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,   336,   337,   338,
      94,   136,   141,   356,   357,   358,   616,   159,   159,   336,
     614,   126,   131,    54,    57,    99,   250,   263,   265,   276,
     277,   278,   280,   282,   588,   589,   590,   591,   592,   593,
     600,   606,   607,   245,    94,   235,   365,   298,   616,   616,
     616,   117,   131,   183,   183,   186,   186,   183,   106,   186,
     106,   186,   183,   106,    34,    94,    96,   146,   411,   412,
     522,   616,    56,   215,   253,   401,   402,   616,    94,   106,
     186,   394,   186,   615,    96,    44,   615,   614,    96,   141,
     522,   616,   397,   417,   183,   186,   186,   186,   186,   141,
     106,   187,   146,   522,   183,   186,   186,   152,   183,   394,
     394,   183,   106,   186,   106,   186,   187,   616,   500,   501,
     129,   195,   183,   183,   130,   189,    94,   216,   217,   231,
      94,   216,   217,   231,    94,   235,   223,   106,   233,   141,
      31,   375,   394,   186,   183,    45,   106,   332,    31,    31,
     189,   325,   189,   112,   397,   189,   616,   169,   397,   428,
     429,   117,   424,   425,   449,   152,   155,   258,   467,   486,
     561,   564,   565,   566,   567,   568,   572,   574,   576,   577,
      47,   151,   155,   209,   523,   525,   527,   528,   544,   545,
     546,   547,   616,   523,   521,   527,   521,   183,   184,   106,
     186,   186,   106,   186,   147,   164,   147,   164,   136,   152,
     392,   371,   371,   337,   131,   525,   358,   397,   522,   614,
     614,   127,   128,   614,   276,   277,   278,   282,   616,   262,
     273,   262,   273,    27,   285,    96,   112,   155,   594,   597,
     588,    37,    43,    60,    62,    71,    97,   223,   364,   528,
     290,   291,   225,   298,   307,    94,   365,   298,   616,   614,
     152,   538,   539,   616,   538,   539,   117,   126,   523,   117,
     397,   146,   412,   146,    34,   146,   411,   412,   146,   522,
     253,    53,    59,    77,   117,   411,   419,   420,   421,   402,
     522,   523,   390,    94,   183,   196,   131,   352,   614,   159,
     131,    96,   352,   397,   141,   412,   152,   397,   117,   397,
     397,   146,    99,   438,   439,   440,    99,   442,   443,   394,
     183,   183,   152,   538,   538,   397,    33,   501,   129,   195,
       9,    10,   102,   122,   124,   193,   391,   496,   498,   509,
     510,   513,    27,   230,   232,   397,   397,   397,   230,   232,
     397,   397,   397,   397,   397,   397,   117,   397,   397,   117,
     376,   106,   189,   183,   373,   244,   557,   558,   152,   117,
     189,   112,   393,   393,   393,   428,    95,   105,   115,   126,
     430,   431,   432,   433,   106,   616,   106,   394,   561,   568,
     152,   284,   450,   613,    96,   168,   251,   252,   254,   261,
     271,   283,   562,   563,   582,   583,   584,   585,   608,   611,
     257,   259,   569,   587,   266,   573,   609,   246,   247,   269,
     578,   579,   155,   155,   525,   155,   143,   175,   192,   524,
     143,   397,   486,   394,   136,   373,   136,   152,   540,   357,
     285,    27,    96,   112,   155,   601,    27,   594,   365,   524,
     225,   225,   469,   286,   305,   364,   225,   522,   189,   183,
     394,   186,   186,   143,   186,   186,   410,   146,   411,   616,
     397,   146,   397,   126,   397,   146,   412,   146,   397,   146,
     117,   117,   397,   616,   421,    77,   523,   397,   614,   106,
     352,   397,   141,   183,   394,   436,   397,   397,   112,   439,
      99,   185,   117,   523,   112,   443,   183,   183,   394,   186,
     186,   131,   193,   498,     7,   616,   193,   509,   189,   231,
     231,   231,   231,   235,   555,   185,   616,   376,   480,   559,
     558,   397,   416,   614,   127,   128,   432,   433,   433,   429,
     105,   426,   425,   183,   186,   561,   575,   249,   215,   253,
     267,   274,   612,    96,   255,   256,   610,   249,   565,   612,
     452,   582,   566,   146,   281,   570,   571,   610,   285,   581,
      78,   580,   186,   192,   523,   526,   186,   186,   186,   183,
     396,    27,   135,   199,   603,   604,   605,    27,   602,   603,
     270,   598,   106,   595,   169,   616,   256,   365,   469,   183,
     397,   146,   397,   146,   411,   397,   146,   397,   397,   616,
     616,   420,   397,   125,    96,   614,   397,   183,   185,   397,
     397,   616,   185,   117,   185,   183,   501,   616,   193,   501,
     616,   397,   397,   397,   397,   397,   397,   141,   522,   155,
     208,   392,   183,   433,   614,   183,   454,    52,   128,   452,
     452,   268,   275,   285,   586,   586,   567,   152,   279,    94,
     186,   106,   186,   183,   601,   601,   605,   106,   186,    27,
     599,   610,   596,   597,   186,   367,   368,   469,   117,   223,
     306,   286,   169,   397,   397,   146,   397,    53,   397,   352,
     397,    94,   397,   616,   397,    93,   182,   502,   501,   616,
     195,   501,   397,   141,   117,   480,   452,   452,   197,   394,
     523,   523,    94,    27,   264,   106,   106,   433,   522,   616,
     117,   223,   616,   367,   397,   117,   523,   185,     5,   132,
     505,   506,   508,   510,    26,   133,   503,   504,   507,   510,
     195,   501,   195,   397,   616,   452,   183,   523,   597,   368,
     433,   304,   616,   117,   223,   616,   185,   397,    93,   132,
     508,   182,   133,   507,   195,   106,   186,   397,   304,   616,
     117,   397,   117,   392,   292,   304,   616,   616,   305,   397,
     305,   106,   186,   469,   469,   117,   392,   197,   616,   286,
     186,   616,   392,   223,   117,   616,   305,   469
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
     339,   339,   339,   339,   339,   339,   340,   340,   340,   341,
     342,   342,   343,   343,   344,   345,   346,   346,   347,   347,
     348,   348,   348,   348,   349,   350,   351,   351,   351,   351,
     352,   352,   353,   353,   354,   354,   354,   354,   355,   356,
     356,   357,   357,   357,   358,   359,   359,   359,   359,   360,
     360,   360,   361,   361,   362,   362,   362,   362,   362,   362,
     362,   362,   362,   362,   362,   362,   362,   362,   363,   363,
     363,   363,   363,   363,   363,   363,   364,   364,   365,   365,
     366,   366,   367,   367,   368,   368,   368,   368,   369,   369,
     369,   369,   370,   370,   371,   371,   371,   371,   372,   373,
     374,   374,   375,   375,   376,   376,   376,   376,   377,   378,
     379,   380,   380,   381,   381,   382,   382,   383,   383,   384,
     384,   385,   385,   385,   385,   386,   386,   387,   387,   388,
     388,   389,   389,   390,   390,   391,   392,   393,   394,   394,
     395,   395,   396,   396,   397,   397,   397,   397,   397,   397,
     397,   397,   397,   397,   397,   397,   397,   397,   397,   397,
     397,   397,   398,   399,   400,   400,   401,   401,   401,   402,
     402,   403,   403,   404,   405,   405,   405,   406,   406,   406,
     406,   406,   407,   407,   408,   409,   409,   410,   410,   410,
     410,   410,   410,   410,   410,   410,   410,   410,   410,   411,
     412,   413,   414,   414,   415,   415,   416,   417,   417,   417,
     417,   418,   418,   419,   419,   419,   420,   420,   420,   421,
     421,   421,   422,   423,   424,   424,   425,   425,   426,   427,
     427,   428,   428,   429,   429,   430,   430,   430,   430,   430,
     430,   430,   431,   431,   432,   432,   433,   434,   434,   435,
     435,   436,   436,   437,   438,   438,   439,   440,   440,   441,
     441,   442,   442,   443,   443,   444,   445,   445,   446,   446,
     447,   447,   447,   447,   447,   448,   447,   447,   447,   447,
     449,   449,   450,   450,   451,   451,   452,   452,   452,   453,
     453,   453,   453,   453,   454,   454,   454,   455,   455,   455,
     456,   456,   457,   457,   458,   458,   459,   459,   460,   460,
     461,   461,   461,   461,   462,   462,   462,   463,   463,   463,
     463,   463,   463,   464,   464,   464,   465,   465,   465,   465,
     466,   466,   467,   467,   468,   468,   468,   469,   469,   469,
     469,   470,   471,   471,   471,   472,   472,   473,   473,   473,
     473,   474,   474,   475,   475,   475,   475,   475,   475,   475,
     476,   476,   477,   477,   478,   478,   478,   478,   478,   479,
     479,   480,   480,   481,   481,   481,   482,   482,   482,   482,
     483,   483,   484,   485,   485,   485,   485,   485,   485,   485,
     485,   485,   486,   486,   487,   487,   487,   488,   489,   489,
     490,   491,   492,   493,   493,   494,   494,   495,   495,   496,
     496,   496,   497,   497,   497,   497,   497,   497,   498,   498,
     499,   499,   500,   501,   501,   502,   502,   503,   503,   504,
     504,   504,   504,   505,   505,   506,   506,   506,   506,   507,
     507,   508,   508,   509,   509,   509,   509,   510,   510,   510,
     510,   511,   511,   512,   512,   513,   514,   514,   514,   514,
     514,   514,   515,   516,   516,   516,   516,   517,   517,   517,
     517,   518,   519,   520,   520,   520,   520,   521,   521,   522,
     523,   523,   523,   524,   524,   524,   525,   525,   525,   525,
     525,   526,   526,   527,   528,   528,   528,   528,   528,   528,
     528,   528,   528,   529,   530,   530,   530,   531,   532,   533,
     533,   533,   534,   534,   534,   534,   534,   535,   536,   536,
     536,   536,   536,   536,   536,   537,   538,   539,   540,   541,
     541,   542,   543,   544,   544,   545,   546,   546,   547,   548,
     548,   548,   549,   549,   549,   549,   549,   549,   549,   549,
     549,   549,   550,   550,   551,   551,   552,   553,   554,   554,
     555,   556,   557,   557,   558,   558,   558,   558,   559,   559,
     560,   560,   561,   562,   562,   563,   563,   564,   564,   565,
     565,   566,   566,   567,   567,   568,   569,   569,   570,   570,
     571,   572,   572,   572,   573,   573,   574,   575,   575,   576,
     577,   577,   578,   578,   579,   579,   579,   580,   580,   581,
     581,   582,   582,   582,   582,   582,   583,   584,   585,   586,
     586,   586,   587,   587,   588,   588,   588,   588,   588,   588,
     588,   588,   589,   589,   589,   589,   590,   590,   591,   592,
     592,   593,   593,   593,   594,   594,   595,   595,   596,   596,
     597,   598,   598,   599,   599,   600,   600,   600,   601,   601,
     602,   602,   603,   603,   604,   604,   605,   605,   606,   607,
     607,   608,   608,   608,   609,   610,   610,   610,   610,   611,
     611,   612,   612,   613,   614,   615,   615,   616,   616,   616,
     616,   616,   616,   616,   616,   616,   616,   616,   616,   616,
     616,   616,   616,   617,   617,   617,   617,   617,   617,   617,
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
     617,   617,   617,   617,   618,   618
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
       1,     1,     1,     1,     1,     1,     1,     1,     3,     5,
       3,     3,     5,     5,     4,     3,     3,     3,     5,     5,
       5,     5,     5,     5,     4,     3,     3,     4,     5,     6,
       1,     3,     3,     3,     3,     6,     5,     8,     4,     3,
       1,     1,     1,     2,     2,     4,     5,     5,     6,     3,
       2,     4,     1,     2,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     2,     1,     2,     2,     2,     3,     4,
       5,     6,     4,     5,     6,     7,     1,     2,     3,     3,
       8,     9,     1,     3,     1,     2,     2,     3,    11,    14,
      13,    22,     3,     3,     2,     3,     4,     5,     2,     4,
       3,     0,     3,     2,     2,     3,     4,     5,     5,     3,
       5,     2,     2,     1,     2,     1,     4,     1,     3,     2,
       3,     1,     2,     1,     1,     4,     4,     5,     5,     7,
       5,     1,     3,     2,     3,     3,     3,     1,     1,     2,
       1,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     2,     1,     1,     2,     4,
       3,     5,     4,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     3,     1,     4,     3,     5,     4,
       6,     4,     6,     5,     7,     4,     5,     5,     6,     3,
       3,     2,     1,     3,     1,     4,     1,     4,     5,     3,
       6,     4,     5,     1,     2,     3,     1,     2,     1,     6,
       3,     3,     2,     3,     1,     3,     2,     3,     2,     3,
       4,     1,     3,     1,     2,     1,     1,     1,     2,     2,
       2,     3,     1,     1,     2,     2,     2,     5,     5,     1,
       4,     3,     4,     8,     1,     2,     3,     2,     3,     8,
      10,     1,     2,     4,     7,     8,     1,     3,     1,     3,
       1,     3,     3,     3,     3,     0,     4,     3,     3,     3,
       1,     5,     0,     1,     1,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       1,     4,     1,     4,     1,     4,     1,     4,     1,     2,
       1,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     5,     5,     6,
       3,     4,     1,     2,     3,     2,     2,     1,     2,     2,
       1,     1,     1,     3,     3,     1,     1,     1,     2,     1,
       2,     2,     1,     2,     2,     2,     2,     2,     2,     2,
       1,     2,     2,     1,     2,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     3,     4,
       1,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     3,
       1,     4,     4,     3,     4,     1,     3,     1,     1,     1,
       1,     1,     4,     5,     8,     9,     9,    10,     1,     2,
       1,     2,     6,     0,     1,     3,     3,     0,     1,     1,
       1,     2,     2,     0,     1,     1,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     2,     3,     3,     2,     1,     1,     1,     1,
       1,     1,     4,     2,     3,     6,     7,     2,     3,     6,
       7,     4,     4,     2,     3,     6,     7,     1,     2,     2,
       1,     2,     3,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     4,     4,     3,     3,     3,
       4,     4,     3,     4,     6,     4,     6,     4,     3,     4,
       6,     6,     4,     6,     6,     4,     1,     2,     1,     1,
       1,     3,     3,     1,     1,     4,     5,     6,     3,     3,
       3,     3,     5,     7,     7,     5,     5,     5,     7,     7,
       5,     5,     3,     3,     5,     7,     5,     7,     1,     4,
       3,     5,     1,     2,     3,     7,    10,    13,     1,     3,
       7,     4,     2,     0,     1,     1,     2,     1,     3,     1,
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
       1,     1,     1,     1,     3,     1
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
      -1,   548,    -1,   351,    -1,   354,    -1,    49,    23,     1,
      -1,    31,   159,   615,   131,   614,    -1,    31,    36,   181,
      -1,    31,    36,   194,    -1,    31,   112,    44,   159,   614,
      -1,    31,   112,    47,   159,   614,    -1,    31,    57,   616,
      27,    -1,    31,   260,   587,    -1,    31,    58,   168,    -1,
      31,    58,   200,    -1,    31,   112,   167,   126,   127,    -1,
      31,   112,   167,   126,   128,    -1,    31,    39,   181,   106,
     147,    -1,    31,    39,   181,   106,   164,    -1,    31,    39,
     165,   106,   147,    -1,    31,    39,   165,   106,   164,    -1,
      31,   112,   105,   614,    -1,    31,    35,   614,    -1,    49,
      61,   614,    -1,    49,    61,   353,   614,    -1,    49,    61,
     614,    96,   352,    -1,    49,    61,   353,   614,    96,   352,
      -1,   614,    -1,   352,   106,   614,    -1,   159,   615,   131,
      -1,   112,    44,   159,    -1,    49,    32,   614,    -1,    49,
      32,   159,   615,   131,   614,    -1,    49,    32,   614,    96,
     352,    -1,    49,    32,   159,   615,   131,   614,    96,   352,
      -1,    31,   110,   151,   356,    -1,    94,   525,   357,    -1,
     357,    -1,   358,    -1,   136,    -1,   136,   358,    -1,   141,
     397,    -1,    31,   111,   117,   616,    -1,    31,   111,   117,
     616,   522,    -1,    31,   381,   111,   117,   616,    -1,    31,
     381,   111,   117,   616,   522,    -1,   359,   141,   397,    -1,
     359,   136,    -1,   359,   136,   141,   397,    -1,   362,    -1,
     361,   362,    -1,   287,    -1,   288,    -1,   289,    -1,   290,
      -1,   168,    -1,   200,    -1,   228,   300,    -1,   228,   299,
      -1,   301,   300,    -1,   301,   299,    -1,   292,    -1,   293,
     292,    -1,   296,   297,    -1,   295,   297,    -1,    31,   286,
     616,    -1,    31,   286,   616,   365,    -1,    31,   286,   616,
      94,   364,    -1,    31,   286,   616,    94,   364,   365,    -1,
      31,   361,   286,   616,    -1,    31,   361,   286,   616,   365,
      -1,    31,   361,   286,   616,    94,   364,    -1,    31,   361,
     286,   616,    94,   364,   365,    -1,   528,    -1,   528,   524,
      -1,   235,   291,   225,    -1,   235,   290,   225,    -1,    31,
     294,   616,   298,   225,   469,   169,   367,    -1,    31,   361,
     294,   616,   298,   225,   469,   169,   367,    -1,   368,    -1,
     367,   106,   368,    -1,   469,    -1,   469,   522,    -1,   469,
     433,    -1,   469,   522,   433,    -1,    31,   302,   303,   616,
     298,   286,   616,   117,   616,   304,   397,    -1,    31,   302,
     303,   616,   298,   286,   616,   223,   117,   616,   304,   292,
     305,   469,    -1,    31,   302,   303,   616,   298,   286,   616,
     306,   223,   117,   616,   304,   397,    -1,    31,   302,   303,
     616,   307,   305,   256,   286,   616,   223,   117,   616,   305,
     469,   197,   286,   616,   223,   117,   616,   305,   469,    -1,
      31,    38,   181,    -1,    31,    38,   194,    -1,   155,   186,
      -1,   155,   389,   186,    -1,   155,   186,    94,   523,    -1,
     155,   389,   186,    94,   523,    -1,   236,   373,    -1,   152,
     374,   394,   183,    -1,   374,   375,   189,    -1,    -1,   375,
     106,   376,    -1,    31,   376,    -1,   117,   616,    -1,   117,
     616,   522,    -1,   117,   616,   141,   397,    -1,   117,   616,
     522,   141,   397,    -1,    65,   117,   616,   141,   397,    -1,
     239,   241,   397,    -1,   242,   155,   397,   186,   373,    -1,
     237,   240,    -1,   238,   240,    -1,   382,    -1,   381,   382,
      -1,    25,    -1,    25,   155,   383,   186,    -1,   486,    -1,
     383,   106,   486,    -1,    31,   385,    -1,    31,   381,   385,
      -1,   386,    -1,    66,   386,    -1,   388,    -1,   387,    -1,
      47,   617,   371,   392,    -1,    47,   617,   371,   136,    -1,
      64,    47,   617,   371,   373,    -1,    64,    47,   617,   371,
     136,    -1,    75,    47,   617,   371,   152,   396,   183,    -1,
      75,    47,   617,   371,   136,    -1,   390,    -1,   389,   106,
     390,    -1,   117,   616,    -1,   117,   616,   522,    -1,   152,
     394,   183,    -1,   152,   394,   183,    -1,   394,    -1,   396,
      -1,   396,   395,    -1,   189,    -1,   395,   396,   189,    -1,
     397,    -1,   396,   106,   397,    -1,   398,    -1,   434,    -1,
     437,    -1,   441,    -1,   444,    -1,   445,    -1,   549,    -1,
     550,    -1,   552,    -1,   551,    -1,   553,    -1,   556,    -1,
     560,    -1,   378,    -1,   379,    -1,   380,    -1,   377,    -1,
     372,    -1,   407,   399,    -1,   185,   397,    -1,    67,   283,
      -1,    72,   283,    -1,   215,    -1,   253,    -1,    56,   253,
      -1,   401,   419,    77,   397,    -1,   401,    77,   397,    -1,
      46,   400,   418,   402,   402,    -1,    46,   400,   418,   402,
      -1,    40,   117,   616,    -1,   408,    -1,   413,    -1,   403,
      -1,   405,    -1,   422,    -1,   427,    -1,   423,    -1,   404,
      -1,   405,    -1,   407,   406,    -1,    46,   117,   409,    -1,
     410,    -1,   409,   106,   117,   410,    -1,   616,   146,   397,
      -1,   616,    34,   126,   146,   397,    -1,   616,   522,   146,
     397,    -1,   616,   522,    34,   126,   146,   397,    -1,   616,
     411,   146,   397,    -1,   616,    34,   126,   411,   146,   397,
      -1,   616,   522,   411,   146,   397,    -1,   616,   522,    34,
     126,   411,   146,   397,    -1,   616,   412,   146,   397,    -1,
     616,   522,   412,   146,   397,    -1,   616,   411,   412,   146,
     397,    -1,   616,   522,   411,   412,   146,   397,    -1,    96,
     117,   616,    -1,   272,   117,   616,    -1,    51,   414,    -1,
     417,    -1,   414,   106,   417,    -1,   416,    -1,   415,   106,
     117,   416,    -1,   616,    -1,   117,   616,   141,   397,    -1,
     117,   616,   522,   141,   397,    -1,   412,   141,   397,    -1,
     117,   616,   522,   412,   141,   397,    -1,   117,   616,   146,
     397,    -1,   117,   616,   522,   146,   397,    -1,   420,    -1,
     117,   616,    -1,   117,   616,   420,    -1,   411,    -1,   411,
     421,    -1,   421,    -1,    59,   117,   616,    53,   117,   616,
      -1,    53,   117,   616,    -1,    59,   117,   616,    -1,   210,
     397,    -1,   170,   169,   424,    -1,   425,    -1,   424,   106,
     425,    -1,   117,   616,    -1,   117,   616,   426,    -1,   105,
     614,    -1,   167,   169,   428,    -1,    70,   167,   169,   428,
      -1,   429,    -1,   428,   106,   429,    -1,   397,    -1,   397,
     430,    -1,   431,    -1,   432,    -1,   433,    -1,   431,   432,
      -1,   431,   433,    -1,   432,   433,    -1,   431,   432,   433,
      -1,    95,    -1,   115,    -1,   126,   127,    -1,   126,   128,
      -1,   105,   614,    -1,    68,   117,   435,   187,   397,    -1,
     134,   117,   435,   187,   397,    -1,   436,    -1,   435,   106,
     117,   436,    -1,   616,   146,   397,    -1,   616,   522,   146,
     397,    -1,    73,   155,   394,   186,   438,   112,   185,   397,
      -1,   439,    -1,   438,   439,    -1,   440,   185,   397,    -1,
      99,   397,    -1,   440,    99,   397,    -1,    74,   155,   394,
     186,   442,   112,   185,   397,    -1,    74,   155,   394,   186,
     442,   112,   117,   616,   185,   397,    -1,   443,    -1,   442,
     443,    -1,    99,   523,   185,   397,    -1,    99,   117,   616,
      94,   523,   185,   397,    -1,    48,   155,   394,   186,   196,
     397,   125,   397,    -1,   446,    -1,   445,   166,   446,    -1,
     447,    -1,   446,    92,   447,    -1,   449,    -1,   449,   463,
     449,    -1,   449,   464,   449,    -1,   449,   131,   449,    -1,
     449,   161,   449,    -1,    -1,   449,   156,   448,   449,    -1,
     449,   154,   449,    -1,   449,   142,   449,    -1,   449,   140,
     449,    -1,   451,    -1,   451,   248,    71,   561,   450,    -1,
      -1,   613,    -1,   452,    -1,   452,   197,   452,    -1,   453,
      -1,   452,   175,   453,    -1,   452,   157,   453,    -1,   454,
      -1,   453,   192,   454,    -1,   453,   116,   454,    -1,   453,
     145,   454,    -1,   453,   158,   454,    -1,   455,    -1,   454,
     199,   455,    -1,   454,   208,   455,    -1,   456,    -1,   455,
     149,   456,    -1,   455,   135,   456,    -1,   457,    -1,   457,
      50,   229,   523,    -1,   458,    -1,   458,   198,    94,   523,
      -1,   459,    -1,   459,   100,    94,   521,    -1,   460,    -1,
     460,   101,    94,   521,    -1,   462,    -1,   461,   462,    -1,
     175,    -1,   157,    -1,   461,   175,    -1,   461,   157,    -1,
     465,    -1,   469,    -1,   466,    -1,   201,    -1,   206,    -1,
     205,    -1,   204,    -1,   203,    -1,   202,    -1,   150,    -1,
     178,    -1,   139,    -1,    76,   152,   394,   183,    -1,    76,
     220,   152,   394,   183,    -1,    76,   219,   152,   394,   183,
      -1,    76,    94,   538,   152,   394,   183,    -1,   467,   152,
     183,    -1,   467,   152,   394,   183,    -1,   468,    -1,   467,
     468,    -1,   176,   616,    16,    -1,   176,    17,    -1,   176,
      18,    -1,   470,    -1,   470,   471,    -1,   191,   471,    -1,
     471,    -1,   190,    -1,   472,    -1,   472,   190,   471,    -1,
     472,   191,   471,    -1,   473,    -1,   482,    -1,   474,    -1,
     474,   483,    -1,   477,    -1,   477,   483,    -1,   475,   479,
      -1,   476,    -1,   104,   121,    -1,   113,   121,    -1,    97,
     121,    -1,   188,   121,    -1,   114,   121,    -1,   138,   121,
      -1,   137,   121,    -1,   479,    -1,    98,   479,    -1,   478,
     479,    -1,   119,    -1,   171,   121,    -1,    90,   121,    -1,
     180,   121,    -1,   179,   121,    -1,    91,   121,    -1,   528,
      -1,   480,    -1,   616,    -1,   481,    -1,   192,    -1,    11,
      -1,    19,    -1,   485,    -1,   482,   483,    -1,   482,   155,
     186,    -1,   482,   155,   494,   186,    -1,   484,    -1,   483,
     484,    -1,   153,   394,   184,    -1,   486,    -1,   488,    -1,
     489,    -1,   490,    -1,   493,    -1,   495,    -1,   491,    -1,
     492,    -1,   541,    -1,   487,    -1,   540,    -1,   109,    -1,
     148,    -1,   123,    -1,   117,   616,    -1,   155,   186,    -1,
     155,   394,   186,    -1,   118,    -1,   168,   152,   394,   183,
      -1,   200,   152,   394,   183,    -1,   617,   155,   186,    -1,
     617,   155,   494,   186,    -1,   397,    -1,   494,   106,   397,
      -1,   496,    -1,   514,    -1,   497,    -1,   511,    -1,   512,
      -1,   156,   616,   501,   129,    -1,   156,   616,   499,   501,
     129,    -1,   156,   616,   501,   195,   193,   616,   501,   195,
      -1,   156,   616,   501,   195,   498,   193,   616,   501,   195,
      -1,   156,   616,   499,   501,   195,   193,   616,   501,   195,
      -1,   156,   616,   499,   501,   195,   498,   193,   616,   501,
     195,    -1,   509,    -1,   498,   509,    -1,   500,    -1,   499,
     500,    -1,    33,   616,   501,   131,   501,   502,    -1,    -1,
      33,    -1,   182,   503,   182,    -1,    93,   505,    93,    -1,
      -1,   504,    -1,   133,    -1,   507,    -1,   504,   133,    -1,
     504,   507,    -1,    -1,   506,    -1,   132,    -1,   508,    -1,
     506,   132,    -1,   506,   508,    -1,    26,    -1,   510,    -1,
       5,    -1,   510,    -1,   496,    -1,    10,    -1,   513,    -1,
     510,    -1,     9,    -1,   122,    -1,   124,    -1,   391,    -1,
     211,    28,   212,    -1,   211,   212,    -1,   173,   615,   174,
      -1,   173,   615,     8,    -1,   102,     7,    -1,   515,    -1,
     516,    -1,   517,    -1,   518,    -1,   519,    -1,   520,    -1,
      42,   152,   394,   183,    -1,    20,   183,    -1,    20,   394,
     183,    -1,    44,   152,   394,   183,   152,   183,    -1,    44,
     152,   394,   183,   152,   394,   183,    -1,    21,   183,    -1,
      21,   394,   183,    -1,    97,   152,   394,   183,   152,   183,
      -1,    97,   152,   394,   183,   152,   394,   183,    -1,    71,
     152,   394,   183,    -1,    37,   152,   394,   183,    -1,    22,
     183,    -1,    22,   394,   183,    -1,    60,   152,   394,   183,
     152,   183,    -1,    60,   152,   394,   183,   152,   394,   183,
      -1,   527,    -1,   527,   143,    -1,    94,   523,    -1,   525,
      -1,   525,   524,    -1,   209,   155,   186,    -1,   143,    -1,
     192,    -1,   175,    -1,   527,    -1,   528,    -1,   151,   155,
     186,    -1,   544,    -1,   547,    -1,   523,    -1,   526,   106,
     523,    -1,   616,    -1,   530,    -1,   536,    -1,   534,    -1,
     537,    -1,   535,    -1,   533,    -1,   532,    -1,   531,    -1,
     529,    -1,   223,   155,   186,    -1,    43,   155,   186,    -1,
      43,   155,   536,   186,    -1,    43,   155,   537,   186,    -1,
      71,   155,   186,    -1,    37,   155,   186,    -1,    60,   155,
     186,    -1,    60,   155,   615,   186,    -1,    60,   155,    27,
     186,    -1,    97,   155,   186,    -1,    97,   155,   616,   186,
      -1,    97,   155,   616,   106,   538,   186,    -1,    97,   155,
     192,   186,    -1,    97,   155,   192,   106,   538,   186,    -1,
      62,   155,   616,   186,    -1,    44,   155,   186,    -1,    44,
     155,   616,   186,    -1,    44,   155,   616,   106,   538,   186,
      -1,    44,   155,   616,   106,   539,   186,    -1,    44,   155,
     192,   186,    -1,    44,   155,   192,   106,   538,   186,    -1,
      44,   155,   192,   106,   539,   186,    -1,    63,   155,   616,
     186,    -1,   616,    -1,   616,   143,    -1,    27,    -1,   542,
      -1,   543,    -1,   616,   144,   148,    -1,    47,   371,   391,
      -1,   545,    -1,   546,    -1,    47,   155,   192,   186,    -1,
      47,   155,   186,    94,   523,    -1,    47,   155,   526,   186,
      94,   523,    -1,   155,   525,   186,    -1,    31,   218,   219,
      -1,    31,   218,   220,    -1,    31,   218,   221,    -1,   224,
     223,   397,   231,   397,    -1,   224,   223,   397,    94,   230,
     231,   397,    -1,   224,   223,   397,    94,   232,   231,   397,
      -1,   224,   223,   397,   216,   397,    -1,   224,   223,   397,
     217,   397,    -1,   224,   225,   397,   231,   397,    -1,   224,
     225,   397,    94,   230,   231,   397,    -1,   224,   225,   397,
      94,   232,   231,   397,    -1,   224,   225,   397,   216,   397,
      -1,   224,   225,   397,   217,   397,    -1,   222,   223,   397,
      -1,   222,   225,   397,    -1,   227,   223,   397,   235,   397,
      -1,   227,   228,   229,   223,   397,   235,   397,    -1,   226,
     223,   397,    94,   397,    -1,   234,   117,   554,   233,   397,
     185,   397,    -1,   555,    -1,   554,   106,   117,   555,    -1,
     616,   141,   397,    -1,   243,   152,   394,   183,   557,    -1,
     558,    -1,   557,   558,    -1,   244,   559,   392,    -1,   244,
     559,   155,   117,   616,   186,   392,    -1,   244,   559,   155,
     117,   616,   106,   117,   616,   186,   392,    -1,   244,   559,
     155,   117,   616,   106,   117,   616,   106,   117,   616,   186,
     392,    -1,   480,    -1,   559,   208,   480,    -1,   245,   117,
     415,    45,   152,   397,   183,    -1,    45,   152,   397,   183,
      -1,   564,   562,    -1,    -1,   563,    -1,   582,    -1,   563,
     582,    -1,   565,    -1,   564,   261,   565,    -1,   566,    -1,
     565,   257,   566,    -1,   567,    -1,   566,   259,   146,   567,
      -1,   568,    -1,   258,   568,    -1,   572,   569,   570,    -1,
      -1,   587,    -1,    -1,   571,    -1,   281,   152,   394,   183,
      -1,   576,   573,    -1,   155,   561,   186,    -1,   574,    -1,
      -1,   609,    -1,   467,   152,   575,   183,    -1,    -1,   561,
      -1,   577,   578,    -1,   486,    -1,   152,   394,   183,    -1,
      -1,   579,    -1,   247,   580,    -1,   246,   581,    -1,   269,
      -1,    -1,    78,    -1,    -1,   285,    -1,   583,    -1,   584,
      -1,   585,    -1,   611,    -1,   608,    -1,   168,    -1,   283,
     452,   586,    -1,   252,   610,   586,    -1,   285,    -1,   275,
      -1,   268,    -1,   245,   588,    -1,   587,   245,   588,    -1,
     589,    -1,   590,    -1,   591,    -1,   606,    -1,   592,    -1,
     600,    -1,   593,    -1,   607,    -1,    99,   273,    -1,    99,
     262,    -1,   265,    -1,   280,    -1,   250,   273,    -1,   250,
     262,    -1,    57,   616,    27,    -1,   276,    -1,    54,   276,
      -1,   278,   594,    -1,   278,   155,   594,   595,   186,    -1,
      54,   278,    -1,   597,    -1,   112,    -1,    -1,   106,   596,
      -1,   597,    -1,   596,   106,   597,    -1,    96,    27,   598,
     599,    -1,    -1,   270,    27,    -1,    -1,   610,   264,    -1,
     277,   285,   601,   603,    -1,   277,   285,   112,   603,    -1,
      54,   277,   285,    -1,    96,    27,    -1,   155,   602,   186,
      -1,    27,    -1,   602,   106,    27,    -1,    -1,   604,    -1,
     605,    -1,   604,   605,    -1,   199,   601,    -1,   135,   601,
      -1,   263,    27,    -1,   282,    -1,    54,   282,    -1,    96,
     215,    -1,    96,   253,    -1,   254,   249,    -1,   266,   610,
     279,    -1,   255,   452,    -1,    96,   128,   452,    -1,    96,
      52,   452,    -1,   256,   452,   197,   452,    -1,   271,   612,
      -1,   251,   612,    -1,   274,    -1,   267,    -1,   284,   249,
     454,    -1,    27,    -1,    15,    -1,   616,    -1,   617,    -1,
      97,    -1,    37,    -1,    43,    -1,    44,    -1,   151,    -1,
      48,    -1,   223,    -1,    60,    -1,    62,    -1,    63,    -1,
      71,    -1,    74,    -1,    73,    -1,   209,    -1,   242,    -1,
     618,    -1,    23,    -1,   213,    -1,   126,    -1,    36,    -1,
     260,    -1,    35,    -1,   220,    -1,   219,    -1,   145,    -1,
      42,    -1,   258,    -1,   259,    -1,   273,    -1,   262,    -1,
     250,    -1,   284,    -1,   276,    -1,   278,    -1,   277,    -1,
     282,    -1,   254,    -1,   249,    -1,    78,    -1,   215,    -1,
     253,    -1,    52,    -1,   221,    -1,   234,    -1,   301,    -1,
     228,    -1,   201,    -1,   206,    -1,   205,    -1,   204,    -1,
     203,    -1,   202,    -1,    96,    -1,   110,    -1,   111,    -1,
     185,    -1,    46,    -1,    34,    -1,    67,    -1,    72,    -1,
      59,    -1,    53,    -1,    56,    -1,    77,    -1,    40,    -1,
     146,    -1,    51,    -1,   210,    -1,   169,    -1,   170,    -1,
     167,    -1,    70,    -1,    95,    -1,   115,    -1,   127,    -1,
     128,    -1,   105,    -1,    68,    -1,   134,    -1,   187,    -1,
      99,    -1,    94,    -1,   196,    -1,   125,    -1,   166,    -1,
      92,    -1,    50,    -1,   229,    -1,   100,    -1,   197,    -1,
     116,    -1,   158,    -1,   199,    -1,   149,    -1,   135,    -1,
      76,    -1,   101,    -1,   198,    -1,   150,    -1,   181,    -1,
     194,    -1,   159,    -1,   136,    -1,   130,    -1,   165,    -1,
     147,    -1,   164,    -1,    31,    -1,    38,    -1,    58,    -1,
     112,    -1,    39,    -1,    57,    -1,   214,    -1,    49,    -1,
      61,    -1,    32,    -1,    47,    -1,   272,    -1,   248,    -1,
     281,    -1,   283,    -1,   252,    -1,   266,    -1,   279,    -1,
     271,    -1,   251,    -1,   265,    -1,   280,    -1,   270,    -1,
     264,    -1,   263,    -1,   247,    -1,   246,    -1,   269,    -1,
     255,    -1,   256,    -1,   285,    -1,   275,    -1,   274,    -1,
     267,    -1,   227,    -1,   233,    -1,   230,    -1,   224,    -1,
     217,    -1,   216,    -1,   218,    -1,   235,    -1,   225,    -1,
     226,    -1,   232,    -1,   222,    -1,   231,    -1,    66,    -1,
      64,    -1,    75,    -1,    41,    -1,    55,    -1,   168,    -1,
     200,    -1,   241,    -1,   236,    -1,   239,    -1,   240,    -1,
     237,    -1,   238,    -1,   243,    -1,   244,    -1,    45,    -1,
     245,    -1,    65,    -1,   294,    -1,   292,    -1,   293,    -1,
     298,    -1,   299,    -1,   300,    -1,   295,    -1,   296,    -1,
     297,    -1,    79,    -1,    80,    -1,    81,    -1,    82,    -1,
      83,    -1,    84,    -1,    85,    -1,    86,    -1,    87,    -1,
      88,    -1,    89,    -1,   286,    -1,   287,    -1,   288,    -1,
     289,    -1,   290,    -1,   291,    -1,   302,    -1,   303,    -1,
     304,    -1,   305,    -1,   306,    -1,   307,    -1,   308,    -1,
      90,    -1,   104,    -1,   113,    -1,   171,    -1,   179,    -1,
     188,    -1,   137,    -1,    91,    -1,   114,    -1,   138,    -1,
     180,    -1,   614,   120,   615,    -1,    24,    -1
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
     181,   183,   185,   187,   189,   191,   193,   195,   197,   201,
     207,   211,   215,   221,   227,   232,   236,   240,   244,   250,
     256,   262,   268,   274,   280,   285,   289,   293,   298,   304,
     311,   313,   317,   321,   325,   329,   336,   342,   351,   356,
     360,   362,   364,   366,   369,   372,   377,   383,   389,   396,
     400,   403,   408,   410,   413,   415,   417,   419,   421,   423,
     425,   428,   431,   434,   437,   439,   442,   445,   448,   452,
     457,   463,   470,   475,   481,   488,   496,   498,   501,   505,
     509,   518,   528,   530,   534,   536,   539,   542,   546,   558,
     573,   587,   610,   614,   618,   621,   625,   630,   636,   639,
     644,   648,   649,   653,   656,   659,   663,   668,   674,   680,
     684,   690,   693,   696,   698,   701,   703,   708,   710,   714,
     717,   721,   723,   726,   728,   730,   735,   740,   746,   752,
     760,   766,   768,   772,   775,   779,   783,   787,   789,   791,
     794,   796,   800,   802,   806,   808,   810,   812,   814,   816,
     818,   820,   822,   824,   826,   828,   830,   832,   834,   836,
     838,   840,   842,   845,   848,   851,   854,   856,   858,   861,
     866,   870,   876,   881,   885,   887,   889,   891,   893,   895,
     897,   899,   901,   903,   906,   910,   912,   917,   921,   927,
     932,   939,   944,   951,   957,   965,   970,   976,   982,   989,
     993,   997,  1000,  1002,  1006,  1008,  1013,  1015,  1020,  1026,
    1030,  1037,  1042,  1048,  1050,  1053,  1057,  1059,  1062,  1064,
    1071,  1075,  1079,  1082,  1086,  1088,  1092,  1095,  1099,  1102,
    1106,  1111,  1113,  1117,  1119,  1122,  1124,  1126,  1128,  1131,
    1134,  1137,  1141,  1143,  1145,  1148,  1151,  1154,  1160,  1166,
    1168,  1173,  1177,  1182,  1191,  1193,  1196,  1200,  1203,  1207,
    1216,  1227,  1229,  1232,  1237,  1245,  1254,  1256,  1260,  1262,
    1266,  1268,  1272,  1276,  1280,  1284,  1285,  1290,  1294,  1298,
    1302,  1304,  1310,  1311,  1313,  1315,  1319,  1321,  1325,  1329,
    1331,  1335,  1339,  1343,  1347,  1349,  1353,  1357,  1359,  1363,
    1367,  1369,  1374,  1376,  1381,  1383,  1388,  1390,  1395,  1397,
    1400,  1402,  1404,  1407,  1410,  1412,  1414,  1416,  1418,  1420,
    1422,  1424,  1426,  1428,  1430,  1432,  1434,  1439,  1445,  1451,
    1458,  1462,  1467,  1469,  1472,  1476,  1479,  1482,  1484,  1487,
    1490,  1492,  1494,  1496,  1500,  1504,  1506,  1508,  1510,  1513,
    1515,  1518,  1521,  1523,  1526,  1529,  1532,  1535,  1538,  1541,
    1544,  1546,  1549,  1552,  1554,  1557,  1560,  1563,  1566,  1569,
    1571,  1573,  1575,  1577,  1579,  1581,  1583,  1585,  1588,  1592,
    1597,  1599,  1602,  1606,  1608,  1610,  1612,  1614,  1616,  1618,
    1620,  1622,  1624,  1626,  1628,  1630,  1632,  1634,  1637,  1640,
    1644,  1646,  1651,  1656,  1660,  1665,  1667,  1671,  1673,  1675,
    1677,  1679,  1681,  1686,  1692,  1701,  1711,  1721,  1732,  1734,
    1737,  1739,  1742,  1749,  1750,  1752,  1756,  1760,  1761,  1763,
    1765,  1767,  1770,  1773,  1774,  1776,  1778,  1780,  1783,  1786,
    1788,  1790,  1792,  1794,  1796,  1798,  1800,  1802,  1804,  1806,
    1808,  1810,  1814,  1817,  1821,  1825,  1828,  1830,  1832,  1834,
    1836,  1838,  1840,  1845,  1848,  1852,  1859,  1867,  1870,  1874,
    1881,  1889,  1894,  1899,  1902,  1906,  1913,  1921,  1923,  1926,
    1929,  1931,  1934,  1938,  1940,  1942,  1944,  1946,  1948,  1952,
    1954,  1956,  1958,  1962,  1964,  1966,  1968,  1970,  1972,  1974,
    1976,  1978,  1980,  1982,  1986,  1990,  1995,  2000,  2004,  2008,
    2012,  2017,  2022,  2026,  2031,  2038,  2043,  2050,  2055,  2059,
    2064,  2071,  2078,  2083,  2090,  2097,  2102,  2104,  2107,  2109,
    2111,  2113,  2117,  2121,  2123,  2125,  2130,  2136,  2143,  2147,
    2151,  2155,  2159,  2165,  2173,  2181,  2187,  2193,  2199,  2207,
    2215,  2221,  2227,  2231,  2235,  2241,  2249,  2255,  2263,  2265,
    2270,  2274,  2280,  2282,  2285,  2289,  2297,  2308,  2322,  2324,
    2328,  2336,  2341,  2344,  2345,  2347,  2349,  2352,  2354,  2358,
    2360,  2364,  2366,  2371,  2373,  2376,  2380,  2381,  2383,  2384,
    2386,  2391,  2394,  2398,  2400,  2401,  2403,  2408,  2409,  2411,
    2414,  2416,  2420,  2421,  2423,  2426,  2429,  2431,  2432,  2434,
    2435,  2437,  2439,  2441,  2443,  2445,  2447,  2449,  2453,  2457,
    2459,  2461,  2463,  2466,  2470,  2472,  2474,  2476,  2478,  2480,
    2482,  2484,  2486,  2489,  2492,  2494,  2496,  2499,  2502,  2506,
    2508,  2511,  2514,  2520,  2523,  2525,  2527,  2528,  2531,  2533,
    2537,  2542,  2543,  2546,  2547,  2550,  2555,  2560,  2564,  2567,
    2571,  2573,  2577,  2578,  2580,  2582,  2585,  2588,  2591,  2594,
    2596,  2599,  2602,  2605,  2608,  2612,  2615,  2619,  2623,  2628,
    2631,  2634,  2636,  2638,  2642,  2644,  2646,  2648,  2650,  2652,
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
    3014,  3016,  3018,  3020,  3022,  3024,  3026,  3028,  3030,  3032,
    3034,  3036,  3038,  3040,  3042,  3044,  3046,  3048,  3050,  3052,
    3054,  3056,  3058,  3060,  3062,  3064,  3066,  3068,  3070,  3072,
    3074,  3076,  3078,  3080,  3082,  3086
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,  1024,  1024,  1025,  1058,  1067,  1072,  1079,  1084,  1095,
    1099,  1107,  1112,  1117,  1122,  1127,  1134,  1141,  1148,  1159,
    1163,  1168,  1173,  1182,  1191,  1197,  1203,  1215,  1221,  1227,
    1238,  1239,  1240,  1241,  1242,  1247,  1248,  1249,  1250,  1251,
    1252,  1253,  1254,  1260,  1265,  1274,  1280,  1289,  1298,  1299,
    1300,  1301,  1302,  1303,  1304,  1305,  1306,  1307,  1312,  1313,
    1314,  1315,  1316,  1317,  1318,  1321,  1326,  1327,  1329,  1339,
    1347,  1353,  1363,  1369,  1379,  1389,  1397,  1403,  1414,  1419,
    1429,  1435,  1441,  1447,  1464,  1472,  1480,  1484,  1493,  1502,
    1515,  1521,  1532,  1536,  1544,  1549,  1554,  1561,  1574,  1581,
    1587,  1594,  1600,  1604,  1611,  1622,  1627,  1632,  1637,  1646,
    1652,  1658,  1667,  1673,  1682,  1686,  1692,  1696,  1700,  1704,
    1710,  1716,  1722,  1728,  1734,  1738,  1744,  1750,  1757,  1765,
    1773,  1781,  1789,  1801,  1815,  1829,  1846,  1850,  1859,  1863,
    1870,  1878,  1896,  1902,  1910,  1915,  1922,  1929,  1939,  1949,
    1959,  1969,  1986,  1992,  2003,  2007,  2011,  2015,  2022,  2029,
    2048,  2058,  2064,  2070,  2080,  2086,  2093,  2099,  2109,  2116,
    2123,  2135,  2139,  2147,  2151,  2159,  2163,  2170,  2174,  2182,
    2187,  2196,  2200,  2204,  2208,  2216,  2227,  2242,  2253,  2268,
    2279,  2295,  2301,  2313,  2317,  2328,  2335,  2343,  2358,  2362,
    2376,  2380,  2389,  2393,  2421,  2422,  2423,  2424,  2425,  2426,
    2429,  2430,  2431,  2432,  2433,  2435,  2436,  2439,  2440,  2441,
    2442,  2443,  2448,  2463,  2470,  2474,  2481,  2485,  2489,  2496,
    2504,  2515,  2525,  2538,  2547,  2548,  2549,  2553,  2554,  2555,
    2556,  2557,  2560,  2566,  2576,  2584,  2590,  2602,  2606,  2610,
    2614,  2618,  2622,  2626,  2631,  2637,  2646,  2656,  2666,  2682,
    2691,  2700,  2708,  2714,  2723,  2729,  2738,  2753,  2761,  2771,
    2779,  2791,  2797,  2808,  2810,  2814,  2822,  2826,  2831,  2835,
    2839,  2843,  2853,  2861,  2868,  2874,  2885,  2889,  2898,  2906,
    2912,  2922,  2928,  2938,  2942,  2952,  2958,  2964,  2970,  2979,
    2988,  2997,  3010,  3014,  3022,  3028,  3038,  3046,  3055,  3068,
    3075,  3087,  3091,  3103,  3110,  3116,  3125,  3132,  3138,  3150,
    3157,  3170,  3176,  3188,  3194,  3206,  3215,  3219,  3228,  3232,
    3240,  3244,  3254,  3261,  3270,  3280,  3279,  3293,  3302,  3311,
    3324,  3328,  3341,  3344,  3351,  3355,  3364,  3368,  3372,  3381,
    3385,  3391,  3397,  3403,  3414,  3418,  3422,  3430,  3434,  3440,
    3450,  3454,  3464,  3468,  3478,  3482,  3492,  3496,  3506,  3510,
    3518,  3522,  3526,  3530,  3540,  3544,  3548,  3556,  3560,  3564,
    3568,  3572,  3576,  3584,  3588,  3592,  3600,  3604,  3608,  3612,
    3623,  3629,  3639,  3645,  3655,  3659,  3663,  3702,  3706,  3716,
    3726,  3740,  3750,  3760,  3764,  3774,  3778,  3787,  3793,  3801,
    3807,  3819,  3825,  3835,  3839,  3843,  3847,  3851,  3857,  3863,
    3886,  3890,  3898,  3902,  3913,  3917,  3921,  3927,  3931,  3945,
    3949,  3957,  3961,  3971,  3975,  3979,  3988,  3992,  3996,  4000,
    4008,  4014,  4024,  4032,  4036,  4040,  4044,  4048,  4052,  4056,
    4060,  4064,  4072,  4076,  4084,  4091,  4098,  4109,  4117,  4121,
    4129,  4137,  4145,  4199,  4203,  4216,  4222,  4232,  4236,  4244,
    4248,  4252,  4260,  4270,  4280,  4290,  4300,  4310,  4325,  4331,
    4342,  4348,  4359,  4370,  4372,  4376,  4381,  4391,  4394,  4401,
    4407,  4413,  4421,  4434,  4437,  4444,  4450,  4456,  4463,  4474,
    4478,  4488,  4492,  4502,  4506,  4510,  4515,  4524,  4530,  4536,
    4542,  4552,  4556,  4568,  4572,  4584,  4596,  4600,  4604,  4608,
    4612,  4616,  4624,  4632,  4636,  4640,  4644,  4661,  4665,  4669,
    4673,  4681,  4689,  4697,  4701,  4705,  4709,  4717,  4723,  4733,
    4741,  4745,  4749,  4784,  4790,  4796,  4806,  4810,  4814,  4818,
    4822,  4829,  4835,  4845,  4853,  4857,  4861,  4865,  4869,  4873,
    4877,  4881,  4885,  4893,  4901,  4905,  4909,  4919,  4927,  4935,
    4939,  4943,  4951,  4955,  4961,  4967,  4971,  4981,  4989,  4993,
    4999,  5008,  5017,  5023,  5029,  5039,  5056,  5063,  5078,  5114,
    5118,  5127,  5136,  5146,  5150,  5159,  5168,  5172,  5183,  5200,
    5206,  5212,  5222,  5226,  5232,  5238,  5242,  5248,  5252,  5258,
    5264,  5271,  5281,  5286,  5294,  5300,  5310,  5332,  5341,  5347,
    5360,  5374,  5381,  5387,  5397,  5402,  5407,  5417,  5430,  5436,
    5453,  5457,  5472,  5481,  5484,  5491,  5496,  5504,  5508,  5515,
    5519,  5526,  5530,  5537,  5541,  5550,  5563,  5566,  5574,  5577,
    5585,  5593,  5601,  5605,  5613,  5616,  5624,  5636,  5639,  5647,
    5659,  5665,  5675,  5678,  5686,  5690,  5694,  5702,  5705,  5713,
    5716,  5724,  5728,  5732,  5736,  5740,  5748,  5756,  5768,  5780,
    5784,  5788,  5796,  5802,  5812,  5816,  5820,  5824,  5828,  5832,
    5836,  5840,  5848,  5852,  5856,  5860,  5868,  5874,  5884,  5894,
    5898,  5906,  5916,  5927,  5934,  5938,  5946,  5949,  5956,  5961,
    5970,  5980,  5983,  5991,  5994,  6002,  6011,  6018,  6028,  6032,
    6039,  6045,  6055,  6058,  6065,  6070,  6082,  6090,  6102,  6110,
    6114,  6122,  6126,  6130,  6138,  6146,  6150,  6154,  6158,  6166,
    6174,  6186,  6190,  6198,  6211,  6215,  6216,  6229,  6230,  6231,
    6232,  6233,  6234,  6235,  6236,  6237,  6238,  6239,  6240,  6241,
    6242,  6243,  6244,  6248,  6249,  6250,  6251,  6252,  6253,  6254,
    6255,  6256,  6257,  6258,  6259,  6260,  6261,  6262,  6263,  6264,
    6265,  6266,  6267,  6268,  6269,  6270,  6271,  6272,  6273,  6274,
    6275,  6276,  6277,  6278,  6279,  6280,  6281,  6282,  6283,  6284,
    6285,  6286,  6287,  6288,  6289,  6290,  6291,  6292,  6293,  6294,
    6295,  6296,  6297,  6298,  6299,  6300,  6301,  6302,  6303,  6304,
    6305,  6306,  6307,  6308,  6309,  6310,  6311,  6312,  6313,  6314,
    6315,  6316,  6317,  6318,  6319,  6320,  6321,  6322,  6323,  6324,
    6325,  6326,  6327,  6328,  6329,  6330,  6331,  6332,  6333,  6334,
    6335,  6336,  6337,  6338,  6339,  6340,  6341,  6342,  6343,  6344,
    6345,  6346,  6347,  6348,  6349,  6350,  6351,  6352,  6353,  6354,
    6355,  6356,  6357,  6358,  6359,  6360,  6361,  6362,  6363,  6364,
    6365,  6366,  6367,  6368,  6369,  6370,  6371,  6372,  6373,  6374,
    6375,  6376,  6377,  6378,  6379,  6380,  6381,  6382,  6383,  6384,
    6385,  6386,  6387,  6388,  6389,  6390,  6391,  6392,  6393,  6394,
    6395,  6396,  6397,  6398,  6399,  6400,  6401,  6402,  6403,  6404,
    6405,  6406,  6407,  6408,  6409,  6410,  6411,  6412,  6413,  6414,
    6415,  6416,  6417,  6418,  6419,  6420,  6421,  6422,  6423,  6424,
    6425,  6426,  6427,  6428,  6429,  6430,  6431,  6432,  6433,  6434,
    6435,  6436,  6437,  6438,  6439,  6440,  6441,  6442,  6443,  6444,
    6445,  6446,  6447,  6448,  6453,  6459
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
  const int xquery_parser::yylast_ = 12270;
  const int xquery_parser::yynnts_ = 296;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 566;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 323;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 577;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


} // zorba

/* Line 1053 of lalr1.cc  */
#line 15890 "F:/xquery/build_win/src/compiler/parser/xquery_parser.cpp"


/* Line 1055 of lalr1.cc  */
#line 6463 "F:/xquery/src/compiler/parser/xquery_parser.y"


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

