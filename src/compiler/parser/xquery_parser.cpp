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
#line 111 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"


#ifdef _WIN32
  // Include the NOMINMAX definition before windwows.h is included,
  // so that min and max macros are not defined, and std::max and std::min
  // uses do not generate errors on Windows.
#define NOMINMAX
#endif

#include "common/common.h"

#ifdef _WIN32
#pragma warning(disable: 4786)
#endif

#include "compiler/parsetree/parsenodes.h"
#include "compiler/parser/parse_constants.h"
#include "compiler/api/compilercb.h"
#include "store/api/update_consts.h"

#define SYMTAB( n ) driver.symtab.get( (off_t)n )
#define SYMTAB_PUT( s ) driver.symtab.put( s )
#define LOC( p ) driver.createQueryLoc( p )


namespace zorba
{
namespace parser
{
  extern const char *the_tumbling, *the_sliding, *the_start, *the_end, *the_only_end, *the_ofor, *the_declare, *the_create;

}
}

#define YYDEBUG 1

using namespace std;
using namespace zorba;



/* Line 310 of lalr1.cc  */
#line 83 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"


#include "xquery_parser.hpp"

/* User implementation prologue.  */

/* Line 316 of lalr1.cc  */
#line 895 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 316 of lalr1.cc  */
#line 1011 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"

#include "compiler/parser/xquery_driver.h"
#include "compiler/parser/xquery_scanner.h"

#undef yylex
#define yylex driver.lexer->lex

/*
 *  Functions to validate lists of properties
 */
// Returns false if validation fails and the parser should call YYERROR, true otherwise
bool validate_collection_properties(parsenode* props, location& loc, parsenode* qname, xquery_driver& driver)
{
  XQUERY_ERROR err = CollectionDecl::validatePropertyList(static_cast<DeclPropertyList*>(props));
  if (err != XQ_NO_ERROR) {
    driver.set_expr(new ParseErrorNode(driver.createQueryLoc(loc), err, static_cast<QName*>(qname)->get_qname(), true));
    return false;
  }
  return true;
}

// Returns false if validation fails and the parser should call YYERROR, true otherwise
bool validate_index_properties(parsenode* props, location& loc, parsenode* qname, xquery_driver& driver)
{
  XQUERY_ERROR err = IndexDecl::validatePropertyList(static_cast<DeclPropertyList*>(props));
  if (err != XQ_NO_ERROR) {
    driver.set_expr(new ParseErrorNode(driver.createQueryLoc(loc), err, static_cast<QName*>(qname)->get_qname(), true));
    return false;
  }
  return true;
}



/* Line 316 of lalr1.cc  */
#line 139 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"

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
#line 205 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
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
        case 103: /* "\"'DECIMAL'\"" */

/* Line 479 of lalr1.cc  */
#line 891 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 479 of lalr1.cc  */
#line 312 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 116: /* "\"'DOUBLE'\"" */

/* Line 479 of lalr1.cc  */
#line 890 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 479 of lalr1.cc  */
#line 321 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 141: /* "\"'INTEGER'\"" */

/* Line 479 of lalr1.cc  */
#line 889 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 479 of lalr1.cc  */
#line 330 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 321: /* "VersionDecl" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 339 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 322: /* "MainModule" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 348 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 323: /* "LibraryModule" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 357 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 324: /* "ModuleDecl" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 366 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 325: /* "Prolog" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 375 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 326: /* "SIND_DeclList" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 384 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "VFO_DeclList" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 393 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "SIND_Decl" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 402 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "VFO_Decl" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 411 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "DecimalFormatDecl" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 420 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "DecimalFormatParamList" */

/* Line 479 of lalr1.cc  */
#line 916 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 479 of lalr1.cc  */
#line 429 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "DecimalFormatParam" */

/* Line 479 of lalr1.cc  */
#line 916 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 479 of lalr1.cc  */
#line 438 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "Setter" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 447 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "Import" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 456 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "NamespaceDecl" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 465 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "BoundarySpaceDecl" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 474 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "DefaultNamespaceDecl" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 483 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "OptionDecl" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 492 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "FTOptionDecl" */

/* Line 479 of lalr1.cc  */
#line 910 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 501 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "OrderingModeDecl" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 510 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "EmptyOrderDecl" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 519 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "CopyNamespacesDecl" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 528 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "DefaultCollationDecl" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 537 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "BaseURIDecl" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 546 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "SchemaImport" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 555 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "URILiteralList" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 564 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "SchemaPrefix" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 573 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "ModuleImport" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 582 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "CtxItemDecl" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 591 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "CtxItemDecl2" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 600 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "CtxItemDecl3" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 609 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "CtxItemDecl4" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 618 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "VarNameAndType" */

/* Line 479 of lalr1.cc  */
#line 916 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 479 of lalr1.cc  */
#line 627 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "VarDecl" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 636 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "DeclPropertyList" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 645 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "DeclProperty" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 654 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "CollectionDecl" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 663 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "NodeModifier" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 672 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "IndexDecl" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 681 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "IndexKeyList" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 690 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "IndexKeySpec" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 699 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "IntegrityConstraintDecl" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 708 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "ConstructionDecl" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 717 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "FunctionSig" */

/* Line 479 of lalr1.cc  */
#line 916 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 479 of lalr1.cc  */
#line 726 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "BlockExpr" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 735 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "Block" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 744 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "BlockDecls" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 753 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "BlockVarDeclList" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 762 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "BlockVarDecl" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 771 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "AssignExpr" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 780 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "ExitExpr" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 789 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "WhileExpr" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 798 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "FlowCtlStatement" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 807 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "FunctionDecl" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 816 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "FunctionDecl2" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 825 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "FunctionDeclSimple" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 834 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "FunctionDeclSequential" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 843 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "FunctionDeclUpdating" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 852 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "ParamList" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "Param" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 870 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "EnclosedExpr" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "BracedExpr" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 888 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "QueryBody" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 897 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "Expr" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 906 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "ApplyExpr" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 915 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "ConcatExpr" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 924 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "ExprSingle" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 933 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "FLWORExpr" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 942 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "ReturnExpr" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 951 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "FLWORWinCond" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 960 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "WindowClause" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 969 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "CountClause" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 978 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "ForLetWinClause" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 987 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "FLWORClauseList" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 996 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "ForClause" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1005 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "VarInDeclList" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1014 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "VarInDecl" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1023 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "PositionalVar" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1032 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "FTScoreVar" */

/* Line 479 of lalr1.cc  */
#line 910 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1041 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "LetClause" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1050 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "VarGetsDeclList" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1059 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "EvalVarDeclList" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1068 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "VarGetsDecl" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1077 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "WindowVarDecl" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1086 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "WindowVars" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1095 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "WindowVars3" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1104 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "WindowVars2" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1113 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "EvalVarDecl" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1122 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "WhereClause" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1131 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "GroupByClause" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1140 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "GroupSpecList" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1149 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "GroupSpec" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1158 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "GroupCollationSpec" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1167 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "OrderByClause" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1176 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "OrderSpecList" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1185 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "OrderSpec" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1194 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "OrderModifier" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1203 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "OrderDirSpec" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1212 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "OrderEmptySpec" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1221 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "OrderCollationSpec" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1230 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "QuantifiedExpr" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1239 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "QVarInDeclList" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1248 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "QVarInDecl" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1257 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "SwitchExpr" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1266 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "SwitchCaseClauseList" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1275 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "SwitchCaseClause" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1284 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "SwitchCaseOperandList" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1293 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "TypeswitchExpr" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1302 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "CaseClauseList" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1311 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "CaseClause" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1320 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "IfExpr" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1329 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "OrExpr" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1338 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "AndExpr" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1347 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "ComparisonExpr" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1356 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "FTContainsExpr" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1365 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "opt_FTIgnoreOption" */

/* Line 479 of lalr1.cc  */
#line 910 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1374 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "RangeExpr" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1383 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "AdditiveExpr" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1392 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "MultiplicativeExpr" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1401 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "UnionExpr" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1410 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "IntersectExceptExpr" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1419 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "InstanceofExpr" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1428 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "TreatExpr" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1437 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "CastableExpr" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1446 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "CastExpr" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1455 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "UnaryExpr" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1464 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "SignList" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1473 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "ValueExpr" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1482 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "ValueComp" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1491 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "NodeComp" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1500 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "ValidateExpr" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1509 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "ExtensionExpr" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1518 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "Pragma_list" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1527 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "Pragma" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1536 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "PathExpr" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1545 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "RelativePathExpr" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1554 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "StepExpr" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1563 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "AxisStep" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1572 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "ForwardStep" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1581 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "ForwardAxis" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1590 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "AbbrevForwardStep" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1599 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "ReverseStep" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1608 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "ReverseAxis" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1617 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "NodeTest" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1626 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "NameTest" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1635 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "Wildcard" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1644 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "FilterExpr" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1653 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "PredicateList" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1662 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "Predicate" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1671 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "PrimaryExpr" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1680 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "Literal" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1689 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "NumericLiteral" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1698 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "VarRef" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1707 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "ParenthesizedExpr" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1716 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "ContextItemExpr" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1725 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "OrderedExpr" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1734 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "UnorderedExpr" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1743 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "FunctionCall" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1752 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "ArgList" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1761 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "Constructor" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1770 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "DirectConstructor" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1779 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "DirElemConstructor" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1788 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "DirElemContentList" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1797 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "DirAttributeList" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1806 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "DirAttr" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1815 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "DirAttributeValue" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1824 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "opt_QuoteAttrContentList" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1833 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "QuoteAttrContentList" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1842 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "opt_AposAttrContentList" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1851 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "AposAttrContentList" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1860 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "QuoteAttrValueContent" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1869 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "AposAttrValueContent" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1878 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "DirElemContent" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1887 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "CommonContent" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1896 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "DirCommentConstructor" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1905 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "DirPIConstructor" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1914 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "CDataSection" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1923 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "ComputedConstructor" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1932 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "CompDocConstructor" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1941 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "CompElemConstructor" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1950 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "CompAttrConstructor" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1959 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "CompTextConstructor" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1968 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "CompCommentConstructor" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1977 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "CompPIConstructor" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1986 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "SingleType" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1995 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "TypeDeclaration" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2004 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "SequenceType" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2013 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "OccurrenceIndicator" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2022 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "ItemType" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2031 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "TypeList" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2040 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "AtomicType" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2049 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "KindTest" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2058 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "AnyKindTest" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2067 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "DocumentTest" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2076 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "TextTest" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2085 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "CommentTest" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2094 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "PITest" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2103 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* "AttributeTest" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2112 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* "SchemaAttributeTest" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2121 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* "ElementTest" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2130 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* "SchemaElementTest" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2139 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "TypeName" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2148 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* "TypeName_WITH_HOOK" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2157 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 533: /* "StringLiteral" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2166 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* "AnyFunctionTest" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2175 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 539: /* "TypedFunctionTest" */

/* Line 479 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2184 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* "InsertExpr" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2193 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 543: /* "DeleteExpr" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2202 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 544: /* "ReplaceExpr" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2211 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 545: /* "RenameExpr" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2220 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 546: /* "TransformExpr" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2229 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 547: /* "VarNameList" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2238 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 548: /* "VarNameDecl" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2247 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 549: /* "TryExpr" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2256 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 550: /* "CatchListExpr" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2265 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 551: /* "CatchExpr" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2274 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 552: /* "NameTestList" */

/* Line 479 of lalr1.cc  */
#line 916 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 479 of lalr1.cc  */
#line 2283 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 555: /* "EvalExpr" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2292 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 556: /* "FTSelection" */

/* Line 479 of lalr1.cc  */
#line 910 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2301 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 559: /* "FTOr" */

/* Line 479 of lalr1.cc  */
#line 910 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2310 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 560: /* "FTAnd" */

/* Line 479 of lalr1.cc  */
#line 910 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2319 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 561: /* "FTMildNot" */

/* Line 479 of lalr1.cc  */
#line 910 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2328 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 562: /* "FTUnaryNot" */

/* Line 479 of lalr1.cc  */
#line 910 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2337 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 563: /* "FTPrimaryWithOptions" */

/* Line 479 of lalr1.cc  */
#line 910 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2346 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 564: /* "opt_FTMatchOptions" */

/* Line 479 of lalr1.cc  */
#line 910 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2355 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 566: /* "FTWeight" */

/* Line 479 of lalr1.cc  */
#line 910 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2364 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 567: /* "FTPrimary" */

/* Line 479 of lalr1.cc  */
#line 910 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2373 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 568: /* "opt_FTTimes" */

/* Line 479 of lalr1.cc  */
#line 910 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2382 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 569: /* "FTExtensionSelection" */

/* Line 479 of lalr1.cc  */
#line 910 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2391 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 571: /* "FTWords" */

/* Line 479 of lalr1.cc  */
#line 910 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2400 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 572: /* "FTWordsValue" */

/* Line 479 of lalr1.cc  */
#line 910 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2409 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 574: /* "FTAnyallOption" */

/* Line 479 of lalr1.cc  */
#line 910 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2418 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 577: /* "FTPosFilter" */

/* Line 479 of lalr1.cc  */
#line 910 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2427 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 578: /* "FTOrder" */

/* Line 479 of lalr1.cc  */
#line 910 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2436 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 579: /* "FTWindow" */

/* Line 479 of lalr1.cc  */
#line 910 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2445 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 580: /* "FTDistance" */

/* Line 479 of lalr1.cc  */
#line 910 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2454 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 581: /* "FTUnit" */

/* Line 479 of lalr1.cc  */
#line 910 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2463 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 582: /* "FTMatchOptions" */

/* Line 479 of lalr1.cc  */
#line 910 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2472 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 583: /* "FTMatchOption" */

/* Line 479 of lalr1.cc  */
#line 910 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2481 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 584: /* "FTCaseOption" */

/* Line 479 of lalr1.cc  */
#line 910 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2490 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 585: /* "FTDiacriticsOption" */

/* Line 479 of lalr1.cc  */
#line 910 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2499 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 586: /* "FTExtensionOption" */

/* Line 479 of lalr1.cc  */
#line 910 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2508 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 587: /* "FTStemOption" */

/* Line 479 of lalr1.cc  */
#line 910 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2517 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 588: /* "FTThesaurusOption" */

/* Line 479 of lalr1.cc  */
#line 910 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2526 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 592: /* "FTThesaurusID" */

/* Line 479 of lalr1.cc  */
#line 910 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2535 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 595: /* "FTStopWordOption" */

/* Line 479 of lalr1.cc  */
#line 910 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2544 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 596: /* "FTStopWords" */

/* Line 479 of lalr1.cc  */
#line 910 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2553 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 600: /* "FTStopWordsInclExcl" */

/* Line 479 of lalr1.cc  */
#line 910 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2562 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 601: /* "FTLanguageOption" */

/* Line 479 of lalr1.cc  */
#line 910 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2571 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 602: /* "FTWildCardOption" */

/* Line 479 of lalr1.cc  */
#line 910 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2580 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 603: /* "FTContent" */

/* Line 479 of lalr1.cc  */
#line 910 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2589 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 604: /* "FTTimes" */

/* Line 479 of lalr1.cc  */
#line 910 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2598 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 605: /* "FTRange" */

/* Line 479 of lalr1.cc  */
#line 910 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2607 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 606: /* "FTScope" */

/* Line 479 of lalr1.cc  */
#line 910 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2616 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 607: /* "FTBigUnit" */

/* Line 479 of lalr1.cc  */
#line 910 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2625 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 608: /* "FTIgnoreOption" */

/* Line 479 of lalr1.cc  */
#line 910 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2634 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
	break;
      case 609: /* "QNAME" */

/* Line 479 of lalr1.cc  */
#line 913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2643 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
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
#line 170 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename);
}

/* Line 552 of lalr1.cc  */
#line 2728 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"

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
#line 1055 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 4:

/* Line 677 of lalr1.cc  */
#line 1059 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.node) = NULL; }
    break;

  case 5:

/* Line 677 of lalr1.cc  */
#line 1060 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.node) = NULL; }
    break;

  case 6:

/* Line 677 of lalr1.cc  */
#line 1061 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.node) = NULL; }
    break;

  case 7:

/* Line 677 of lalr1.cc  */
#line 1062 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.node) = NULL; }
    break;

  case 8:

/* Line 677 of lalr1.cc  */
#line 1067 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          // Catch unrecognized tokens and report them
          (yyval.node) = NULL;
          if ((yysemantic_stack_[(1) - (1)].err) != NULL) {
            error((yyloc), (yysemantic_stack_[(1) - (1)].err)->msg);
            delete (yysemantic_stack_[(1) - (1)].err);
          } else
            error((yyloc), std::string("syntax error, unexpected character"));
          YYERROR;
        }
    break;

  case 9:

/* Line 677 of lalr1.cc  */
#line 1083 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 10:

/* Line 677 of lalr1.cc  */
#line 1088 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            MainModule *mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
            mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 11:

/* Line 677 of lalr1.cc  */
#line 1095 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 12:

/* Line 677 of lalr1.cc  */
#line 1100 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            LibraryModule *lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
            lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 13:

/* Line 677 of lalr1.cc  */
#line 1111 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            std::string encoding = "utf-8";
            (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), encoding );
        }
    break;

  case 14:

/* Line 677 of lalr1.cc  */
#line 1116 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
        }
    break;

  case 15:

/* Line 677 of lalr1.cc  */
#line 1124 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new MainModule(
                LOC((yyloc)),
                static_cast<QueryBody*>((yysemantic_stack_[(2) - (2)].expr)),
                static_cast<Prolog*>((yysemantic_stack_[(2) - (1)].node))
            );
        }
    break;

  case 16:

/* Line 677 of lalr1.cc  */
#line 1132 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
        }
    break;

  case 17:

/* Line 677 of lalr1.cc  */
#line 1140 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LibraryModule(
                LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 18:

/* Line 677 of lalr1.cc  */
#line 1146 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LibraryModule(
                LOC((yyloc)),
                static_cast<ModuleDecl*>((yysemantic_stack_[(2) - (1)].node)),
                static_cast<Prolog*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 19:

/* Line 677 of lalr1.cc  */
#line 1158 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
            dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
        }
    break;

  case 20:

/* Line 677 of lalr1.cc  */
#line 1167 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Prolog( LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(2) - (1)].node)), NULL );
        }
    break;

  case 21:

/* Line 677 of lalr1.cc  */
#line 1171 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Prolog( LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(2) - (1)].node)) );
        }
    break;

  case 22:

/* Line 677 of lalr1.cc  */
#line 1175 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Prolog(
                LOC((yyloc)),
                static_cast<SIND_DeclList*>((yysemantic_stack_[(4) - (1)].node)),
                static_cast<VFO_DeclList*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 23:

/* Line 677 of lalr1.cc  */
#line 1187 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
            sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
            (yyval.node) = sdl;
        }
    break;

  case 24:

/* Line 677 of lalr1.cc  */
#line 1193 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( SIND_DeclList *sdl = static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                sdl->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 25:

/* Line 677 of lalr1.cc  */
#line 1203 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
            vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
            (yyval.node) = vdl;
        }
    break;

  case 26:

/* Line 677 of lalr1.cc  */
#line 1209 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( VFO_DeclList *vdl = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vdl->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 40:

/* Line 677 of lalr1.cc  */
#line 1241 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
         (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
         delete (yysemantic_stack_[(4) - (4)].vstrpair);
       }
    break;

  case 41:

/* Line 677 of lalr1.cc  */
#line 1246 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
         (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
         delete (yysemantic_stack_[(4) - (4)].vstrpair);
       }
    break;

  case 42:

/* Line 677 of lalr1.cc  */
#line 1255 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.vstrpair) = new vector<string_pair_t>();
          (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
          delete (yysemantic_stack_[(1) - (1)].strpair);
        }
    break;

  case 43:

/* Line 677 of lalr1.cc  */
#line 1261 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
          delete (yysemantic_stack_[(2) - (2)].strpair);
          (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
        }
    break;

  case 44:

/* Line 677 of lalr1.cc  */
#line 1270 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
            (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval() );
            delete sl;
        }
    break;

  case 45:

/* Line 677 of lalr1.cc  */
#line 1278 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 46:

/* Line 677 of lalr1.cc  */
#line 1279 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 47:

/* Line 677 of lalr1.cc  */
#line 1280 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 48:

/* Line 677 of lalr1.cc  */
#line 1281 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 49:

/* Line 677 of lalr1.cc  */
#line 1282 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 50:

/* Line 677 of lalr1.cc  */
#line 1283 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 51:

/* Line 677 of lalr1.cc  */
#line 1284 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 52:

/* Line 677 of lalr1.cc  */
#line 1285 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 53:

/* Line 677 of lalr1.cc  */
#line 1286 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 54:

/* Line 677 of lalr1.cc  */
#line 1287 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 65:

/* Line 677 of lalr1.cc  */
#line 1318 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
        }
    break;

  case 66:

/* Line 677 of lalr1.cc  */
#line 1327 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BoundarySpaceDecl(
                LOC((yyloc)), StaticContextConsts::preserve_space
            );
        }
    break;

  case 67:

/* Line 677 of lalr1.cc  */
#line 1333 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BoundarySpaceDecl(
                LOC((yyloc)), StaticContextConsts::strip_space
            );
        }
    break;

  case 68:

/* Line 677 of lalr1.cc  */
#line 1343 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultNamespaceDecl(
                LOC((yyloc)), ParseConstants::ns_element_default, SYMTAB((yysemantic_stack_[(5) - (5)].sval))
            );
        }
    break;

  case 69:

/* Line 677 of lalr1.cc  */
#line 1349 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultNamespaceDecl(
                LOC((yyloc)), ParseConstants::ns_function_default, SYMTAB((yysemantic_stack_[(5) - (5)].sval))
            );
        }
    break;

  case 70:

/* Line 677 of lalr1.cc  */
#line 1359 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OptionDecl(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval))
            );
        }
    break;

  case 71:

/* Line 677 of lalr1.cc  */
#line 1369 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
        }
    break;

  case 72:

/* Line 677 of lalr1.cc  */
#line 1377 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OrderingModeDecl(
                LOC((yyloc)), StaticContextConsts::ordered
            );
        }
    break;

  case 73:

/* Line 677 of lalr1.cc  */
#line 1383 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OrderingModeDecl(
                LOC((yyloc)), StaticContextConsts::unordered
            );
        }
    break;

  case 74:

/* Line 677 of lalr1.cc  */
#line 1394 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new EmptyOrderDecl( LOC((yyloc)),
                                StaticContextConsts::empty_greatest);
        }
    break;

  case 75:

/* Line 677 of lalr1.cc  */
#line 1399 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new EmptyOrderDecl( LOC((yyloc)),
                                StaticContextConsts::empty_least);
        }
    break;

  case 76:

/* Line 677 of lalr1.cc  */
#line 1409 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::preserve_ns,
                                StaticContextConsts::inherit_ns);
        }
    break;

  case 77:

/* Line 677 of lalr1.cc  */
#line 1415 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::preserve_ns,
                                StaticContextConsts::no_inherit_ns);
        }
    break;

  case 78:

/* Line 677 of lalr1.cc  */
#line 1421 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::no_preserve_ns,
                                StaticContextConsts::inherit_ns);
        }
    break;

  case 79:

/* Line 677 of lalr1.cc  */
#line 1427 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::no_preserve_ns,
                                StaticContextConsts::no_inherit_ns);
        }
    break;

  case 80:

/* Line 677 of lalr1.cc  */
#line 1444 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
        }
    break;

  case 81:

/* Line 677 of lalr1.cc  */
#line 1452 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 82:

/* Line 677 of lalr1.cc  */
#line 1460 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
        }
    break;

  case 83:

/* Line 677 of lalr1.cc  */
#line 1464 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new SchemaImport(
                LOC((yyloc)),
                dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                NULL
            );
        }
    break;

  case 84:

/* Line 677 of lalr1.cc  */
#line 1473 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new SchemaImport(
                LOC((yyloc)),
                NULL,
                SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 85:

/* Line 677 of lalr1.cc  */
#line 1482 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new SchemaImport(
                LOC((yyloc)),
                dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node))
            );
        }
    break;

  case 86:

/* Line 677 of lalr1.cc  */
#line 1495 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            URILiteralList *ull = new URILiteralList( LOC((yyloc)));
            ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.node) = ull;
        }
    break;

  case 87:

/* Line 677 of lalr1.cc  */
#line 1501 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
                ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 88:

/* Line 677 of lalr1.cc  */
#line 1512 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 89:

/* Line 677 of lalr1.cc  */
#line 1516 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
        }
    break;

  case 90:

/* Line 677 of lalr1.cc  */
#line 1524 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 91:

/* Line 677 of lalr1.cc  */
#line 1529 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 92:

/* Line 677 of lalr1.cc  */
#line 1534 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 93:

/* Line 677 of lalr1.cc  */
#line 1541 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(8) - (4)].sval)),
                            SYMTAB((yysemantic_stack_[(8) - (6)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(8) - (8)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(8) - (2)].sval)));
    }
    break;

  case 94:

/* Line 677 of lalr1.cc  */
#line 1554 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
        }
    break;

  case 95:

/* Line 677 of lalr1.cc  */
#line 1561 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            CtxItemDecl *d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
            d->type = (yysemantic_stack_[(3) - (2)].node);
            (yyval.node) = d;
        }
    break;

  case 96:

/* Line 677 of lalr1.cc  */
#line 1567 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 97:

/* Line 677 of lalr1.cc  */
#line 1574 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            CtxItemDecl *d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
            d->ext = false;
            (yyval.node) = d;
        }
    break;

  case 98:

/* Line 677 of lalr1.cc  */
#line 1580 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CtxItemDecl( LOC((yyloc)), NULL );
        }
    break;

  case 99:

/* Line 677 of lalr1.cc  */
#line 1584 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 100:

/* Line 677 of lalr1.cc  */
#line 1591 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CtxItemDecl( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 101:

/* Line 677 of lalr1.cc  */
#line 1602 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 102:

/* Line 677 of lalr1.cc  */
#line 1606 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 103:

/* Line 677 of lalr1.cc  */
#line 1614 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(5) - (3)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, (yysemantic_stack_[(5) - (5)].expr));
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (1)].sval)));
    }
    break;

  case 104:

/* Line 677 of lalr1.cc  */
#line 1620 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(4) - (3)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, NULL, true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(4) - (1)].sval)));
    }
    break;

  case 105:

/* Line 677 of lalr1.cc  */
#line 1626 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(6) - (3)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, (yysemantic_stack_[(6) - (6)].expr), true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (1)].sval)));
    }
    break;

  case 106:

/* Line 677 of lalr1.cc  */
#line 1635 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            DeclPropertyList *dpl = new DeclPropertyList( LOC((yyloc)) );
            dpl->addProperty(dynamic_cast<DeclProperty*>((yysemantic_stack_[(1) - (1)].node)));
            (yyval.node) = dpl;
        }
    break;

  case 107:

/* Line 677 of lalr1.cc  */
#line 1641 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
        DeclPropertyList *dpl = dynamic_cast<DeclPropertyList*>((yysemantic_stack_[(2) - (1)].node));
        dpl->addProperty( static_cast<DeclProperty*>((yysemantic_stack_[(2) - (2)].node)) );
        (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 108:

/* Line 677 of lalr1.cc  */
#line 1650 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_const );
        }
    break;

  case 109:

/* Line 677 of lalr1.cc  */
#line 1654 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_append_only
            );
        }
    break;

  case 110:

/* Line 677 of lalr1.cc  */
#line 1660 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_queue );
        }
    break;

  case 111:

/* Line 677 of lalr1.cc  */
#line 1664 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_mutable );
        }
    break;

  case 112:

/* Line 677 of lalr1.cc  */
#line 1668 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_ordered );
        }
    break;

  case 113:

/* Line 677 of lalr1.cc  */
#line 1672 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_unordered
            );
        }
    break;

  case 114:

/* Line 677 of lalr1.cc  */
#line 1678 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_value_equality
            );
        }
    break;

  case 115:

/* Line 677 of lalr1.cc  */
#line 1684 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_value_range
            );
        }
    break;

  case 116:

/* Line 677 of lalr1.cc  */
#line 1690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_general_equality
            );
        }
    break;

  case 117:

/* Line 677 of lalr1.cc  */
#line 1696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_general_range
            );
        }
    break;

  case 118:

/* Line 677 of lalr1.cc  */
#line 1702 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_unique );
        }
    break;

  case 119:

/* Line 677 of lalr1.cc  */
#line 1706 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_non_unique
            );
        }
    break;

  case 120:

/* Line 677 of lalr1.cc  */
#line 1712 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_automatic
            );
        }
    break;

  case 121:

/* Line 677 of lalr1.cc  */
#line 1718 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_manual );
        }
    break;

  case 122:

/* Line 677 of lalr1.cc  */
#line 1725 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)),
                              NULL,
                              NULL,
                              NULL);
    }
    break;

  case 123:

/* Line 677 of lalr1.cc  */
#line 1733 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              NULL,
                              static_cast<NodeModifier*>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 124:

/* Line 677 of lalr1.cc  */
#line 1741 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                              NULL,
                              NULL,
                              static_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 125:

/* Line 677 of lalr1.cc  */
#line 1749 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                              NULL,
                              static_cast<NodeModifier*>((yysemantic_stack_[(6) - (6)].node)),
                              static_cast<SequenceType*>((yysemantic_stack_[(6) - (5)].node)));
    }
    break;

  case 126:

/* Line 677 of lalr1.cc  */
#line 1757 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 127:

/* Line 677 of lalr1.cc  */
#line 1769 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 128:

/* Line 677 of lalr1.cc  */
#line 1783 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 129:

/* Line 677 of lalr1.cc  */
#line 1797 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 130:

/* Line 677 of lalr1.cc  */
#line 1814 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 131:

/* Line 677 of lalr1.cc  */
#line 1818 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 132:

/* Line 677 of lalr1.cc  */
#line 1825 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier( LOC((yyloc)), StaticContextConsts::read_only);
    }
    break;

  case 133:

/* Line 677 of lalr1.cc  */
#line 1829 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier( LOC((yyloc)), StaticContextConsts::mutable_node);
    }
    break;

  case 134:

/* Line 677 of lalr1.cc  */
#line 1836 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexDecl( LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(8) - (3)].expr)),
                         (yysemantic_stack_[(8) - (6)].expr),
                         dynamic_cast<IndexKeyList*>((yysemantic_stack_[(8) - (8)].node)),
                         NULL);
    }
    break;

  case 135:

/* Line 677 of lalr1.cc  */
#line 1844 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      if (!validate_index_properties((yysemantic_stack_[(9) - (2)].node), (yyloc), (yysemantic_stack_[(9) - (4)].expr), driver)) {
        delete (yysemantic_stack_[(9) - (2)].node); delete (yysemantic_stack_[(9) - (4)].expr); delete (yysemantic_stack_[(9) - (7)].expr); delete (yysemantic_stack_[(9) - (9)].node); // these need to be deleted explicitly, as bison does not free them
        YYERROR;
      }

      (yyval.node) = new IndexDecl( LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(9) - (4)].expr)),
                         (yysemantic_stack_[(9) - (7)].expr),
                         dynamic_cast<IndexKeyList*>((yysemantic_stack_[(9) - (9)].node)),
                         dynamic_cast<DeclPropertyList*>((yysemantic_stack_[(9) - (2)].node)));
      delete (yysemantic_stack_[(9) - (2)].node);
    }
    break;

  case 136:

/* Line 677 of lalr1.cc  */
#line 1861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList( LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 137:

/* Line 677 of lalr1.cc  */
#line 1867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 138:

/* Line 677 of lalr1.cc  */
#line 1875 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec( LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<AtomicType*>((yysemantic_stack_[(3) - (3)].node)),
                            NULL);
    }
    break;

  case 139:

/* Line 677 of lalr1.cc  */
#line 1882 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec( LOC((yyloc)),
                            (yysemantic_stack_[(4) - (1)].expr),
                            dynamic_cast<AtomicType*>((yysemantic_stack_[(4) - (3)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 140:

/* Line 677 of lalr1.cc  */
#line 1893 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollSimpleCheck( LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (9)].expr)),
                                 (yysemantic_stack_[(11) - (11)].expr));
    }
    break;

  case 141:

/* Line 677 of lalr1.cc  */
#line 1903 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollUniqueKeyCheck( LOC((yyloc)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (4)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (7)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (10)].expr)),
                                    (yysemantic_stack_[(14) - (14)].expr));
    }
    break;

  case 142:

/* Line 677 of lalr1.cc  */
#line 1913 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollForeachNode( LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (11)].expr)),
                                 (yysemantic_stack_[(13) - (13)].expr));
    }
    break;

  case 143:

/* Line 677 of lalr1.cc  */
#line 1924 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 144:

/* Line 677 of lalr1.cc  */
#line 1939 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ConstructionDecl(
                LOC((yyloc)), StaticContextConsts::cons_preserve
            );
        }
    break;

  case 145:

/* Line 677 of lalr1.cc  */
#line 1945 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ConstructionDecl(
                LOC((yyloc)), StaticContextConsts::cons_strip
            );
        }
    break;

  case 146:

/* Line 677 of lalr1.cc  */
#line 1956 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( NULL );
        }
    break;

  case 147:

/* Line 677 of lalr1.cc  */
#line 1960 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 148:

/* Line 677 of lalr1.cc  */
#line 1964 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)) );
        }
    break;

  case 149:

/* Line 677 of lalr1.cc  */
#line 1968 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig(
                dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 150:

/* Line 677 of lalr1.cc  */
#line 1977 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(2) - (2)].expr);
        }
    break;

  case 151:

/* Line 677 of lalr1.cc  */
#line 1984 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 152:

/* Line 677 of lalr1.cc  */
#line 2003 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vfo = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node));
            std::auto_ptr<VFO_DeclList> vfo2( dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)) );
            if ( !(yysemantic_stack_[(3) - (1)].node) )
                vfo = new VFO_DeclList( LOC((yyloc)) );
            vfo->push_back( *vfo2.get() );
            (yyval.node) = vfo;
        }
    break;

  case 153:

/* Line 677 of lalr1.cc  */
#line 2012 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 154:

/* Line 677 of lalr1.cc  */
#line 2019 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vfo = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node));
            vfo->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = vfo;
        }
    break;

  case 155:

/* Line 677 of lalr1.cc  */
#line 2025 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vfo = new VFO_DeclList( LOC((yyloc)) );
            vfo->push_back((yysemantic_stack_[(2) - (2)].node));
            (yyval.node) = vfo;
        }
    break;

  case 156:

/* Line 677 of lalr1.cc  */
#line 2035 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(1) - (1)].varnametype)));
      VarDecl* vd = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, NULL);
      vd->set_global(false);
      (yyval.node) = vd;
    }
    break;

  case 157:

/* Line 677 of lalr1.cc  */
#line 2042 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(3) - (1)].varnametype)));
      VarDecl* vd = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, (yysemantic_stack_[(3) - (3)].expr));
      vd->set_global(false);
      (yyval.node) = vd;
        }
    break;

  case 158:

/* Line 677 of lalr1.cc  */
#line 2053 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 159:

/* Line 677 of lalr1.cc  */
#line 2060 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExitExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 160:

/* Line 677 of lalr1.cc  */
#line 2067 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            BlockBody *bb = dynamic_cast<BlockBody *>((yysemantic_stack_[(5) - (5)].expr));
            if ( !bb ) {
                bb = new BlockBody( (yysemantic_stack_[(5) - (5)].expr)->get_location() );
                bb->add((yysemantic_stack_[(5) - (5)].expr));
            }
            (yyval.expr) = new WhileExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), bb );
        }
    break;

  case 161:

/* Line 677 of lalr1.cc  */
#line 2079 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::BREAK );
        }
    break;

  case 162:

/* Line 677 of lalr1.cc  */
#line 2083 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
        }
    break;

  case 163:

/* Line 677 of lalr1.cc  */
#line 2090 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            dynamic_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 164:

/* Line 677 of lalr1.cc  */
#line 2095 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            FunctionDecl* fd = dynamic_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));
            if (fd->get_kind() != ParseConstants::fn_extern &&
                fd->get_kind() != ParseConstants::fn_extern_sequential &&
                fd->get_kind() != ParseConstants::fn_extern_update)
            {
              delete (yysemantic_stack_[(3) - (3)].node);
              error((yyloc), "Only external functions may be declared nondeterministic");
              YYERROR;
            }
            fd->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );
            fd->set_deterministic(false);
            (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
        }
    break;

  case 165:

/* Line 677 of lalr1.cc  */
#line 2110 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            FunctionDecl* fd = dynamic_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));
            if (fd->get_kind() != ParseConstants::fn_extern &&
                fd->get_kind() != ParseConstants::fn_extern_sequential &&
                fd->get_kind() != ParseConstants::fn_extern_update)
            {
              delete (yysemantic_stack_[(3) - (3)].node);
              error((yyloc), "Only external functions may be declared deterministic");
              YYERROR;
            }
            fd->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );
            (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
        }
    break;

  case 166:

/* Line 677 of lalr1.cc  */
#line 2127 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 167:

/* Line 677 of lalr1.cc  */
#line 2131 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 168:

/* Line 677 of lalr1.cc  */
#line 2135 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 169:

/* Line 677 of lalr1.cc  */
#line 2139 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 170:

/* Line 677 of lalr1.cc  */
#line 2147 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC ((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                            &* (yysemantic_stack_[(4) - (3)].fnsig)->param,
                            &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
                            (yysemantic_stack_[(4) - (4)].expr),
                            ParseConstants::fn_read);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 171:

/* Line 677 of lalr1.cc  */
#line 2157 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC ((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                            &* (yysemantic_stack_[(4) - (3)].fnsig)->param,
                            &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
                            NULL,
                            ParseConstants::fn_extern);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 172:

/* Line 677 of lalr1.cc  */
#line 2171 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC ((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                            &* (yysemantic_stack_[(5) - (4)].fnsig)->param,
                            &* (yysemantic_stack_[(5) - (4)].fnsig)->ret,
                            (yysemantic_stack_[(5) - (5)].expr),
                            ParseConstants::fn_sequential);
      delete (yysemantic_stack_[(5) - (4)].fnsig);
    }
    break;

  case 173:

/* Line 677 of lalr1.cc  */
#line 2181 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC ((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                            &* (yysemantic_stack_[(5) - (4)].fnsig)->param,
                            &* (yysemantic_stack_[(5) - (4)].fnsig)->ret,
                            NULL,
                            ParseConstants::fn_extern_sequential);
      delete (yysemantic_stack_[(5) - (4)].fnsig);
    }
    break;

  case 174:

/* Line 677 of lalr1.cc  */
#line 2195 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC ((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                            &* (yysemantic_stack_[(7) - (4)].fnsig)->param,
                            &* (yysemantic_stack_[(7) - (4)].fnsig)->ret,
                            (yysemantic_stack_[(7) - (6)].expr),
                            ParseConstants::fn_update);
      delete (yysemantic_stack_[(7) - (4)].fnsig);
    }
    break;

  case 175:

/* Line 677 of lalr1.cc  */
#line 2205 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC ((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                            &* (yysemantic_stack_[(5) - (4)].fnsig)->param,
                            &* (yysemantic_stack_[(5) - (4)].fnsig)->ret,
                            NULL,
                            ParseConstants::fn_extern_update);
      delete (yysemantic_stack_[(5) - (4)].fnsig);
    }
    break;

  case 176:

/* Line 677 of lalr1.cc  */
#line 2220 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            ParamList *pl = new ParamList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 177:

/* Line 677 of lalr1.cc  */
#line 2226 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
                pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 178:

/* Line 677 of lalr1.cc  */
#line 2238 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 179:

/* Line 677 of lalr1.cc  */
#line 2242 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 180:

/* Line 677 of lalr1.cc  */
#line 2253 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new EnclosedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 181:

/* Line 677 of lalr1.cc  */
#line 2260 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 182:

/* Line 677 of lalr1.cc  */
#line 2268 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QueryBody( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 183:

/* Line 677 of lalr1.cc  */
#line 2283 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 184:

/* Line 677 of lalr1.cc  */
#line 2287 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            std::auto_ptr<BlockBody> blk( dynamic_cast<BlockBody*>((yysemantic_stack_[(2) - (2)].expr)) );
            BlockBody *blk2 = new BlockBody( LOC((yyloc)) );
            blk2->add( (yysemantic_stack_[(2) - (1)].expr) );

            for ( int i = 0; i < blk->size(); ++i )
                blk2->add( (*blk)[i] );

            (yyval.expr) = blk2;
        }
    break;

  case 185:

/* Line 677 of lalr1.cc  */
#line 2301 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new BlockBody( LOC((yyloc)) );
        }
    break;

  case 186:

/* Line 677 of lalr1.cc  */
#line 2305 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            BlockBody *bb = dynamic_cast<BlockBody*>((yysemantic_stack_[(3) - (1)].expr));
            bb->add( (yysemantic_stack_[(3) - (2)].expr) );
            (yyval.expr) = bb;
        }
    break;

  case 187:

/* Line 677 of lalr1.cc  */
#line 2314 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 188:

/* Line 677 of lalr1.cc  */
#line 2318 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 207:

/* Line 677 of lalr1.cc  */
#line 2359 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 208:

/* Line 677 of lalr1.cc  */
#line 2374 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 209:

/* Line 677 of lalr1.cc  */
#line 2381 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_sliding;
        }
    break;

  case 210:

/* Line 677 of lalr1.cc  */
#line 2385 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_tumbling;
        }
    break;

  case 211:

/* Line 677 of lalr1.cc  */
#line 2392 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_start;
        }
    break;

  case 212:

/* Line 677 of lalr1.cc  */
#line 2396 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_end;
        }
    break;

  case 213:

/* Line 677 of lalr1.cc  */
#line 2400 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_only_end;
        }
    break;

  case 214:

/* Line 677 of lalr1.cc  */
#line 2407 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FLWORWinCond(
                LOC((yyloc)),
                dynamic_cast<WindowVars*>((yysemantic_stack_[(4) - (2)].node)), (yysemantic_stack_[(4) - (4)].expr),
                (yysemantic_stack_[(4) - (1)].strval) == parser::the_start, (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end
            );
        }
    break;

  case 215:

/* Line 677 of lalr1.cc  */
#line 2415 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FLWORWinCond(
                LOC((yyloc)), NULL, (yysemantic_stack_[(3) - (3)].expr),
                (yysemantic_stack_[(3) - (1)].strval) == parser::the_start, (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end
            );
        }
    break;

  case 216:

/* Line 677 of lalr1.cc  */
#line 2426 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 217:

/* Line 677 of lalr1.cc  */
#line 2436 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling ?
                              WindowClause::tumbling_window :
                              WindowClause::sliding_window),
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    }
    break;

  case 218:

/* Line 677 of lalr1.cc  */
#line 2449 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 227:

/* Line 677 of lalr1.cc  */
#line 2471 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
            fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = fcl;
        }
    break;

  case 228:

/* Line 677 of lalr1.cc  */
#line 2477 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
            fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = fcl;
        }
    break;

  case 229:

/* Line 677 of lalr1.cc  */
#line 2486 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = NULL;
        }
    break;

  case 230:

/* Line 677 of lalr1.cc  */
#line 2490 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_ofor;
        }
    break;

  case 231:

/* Line 677 of lalr1.cc  */
#line 2498 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForClause(
                LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(2) - (2)].node)), (yysemantic_stack_[(2) - (1)].strval) != NULL
            );
        }
    break;

  case 232:

/* Line 677 of lalr1.cc  */
#line 2508 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            VarInDeclList *vdl = new VarInDeclList( LOC((yyloc)) );
            vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vdl;
        }
    break;

  case 233:

/* Line 677 of lalr1.cc  */
#line 2514 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( VarInDeclList *vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 234:

/* Line 677 of lalr1.cc  */
#line 2526 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 235:

/* Line 677 of lalr1.cc  */
#line 2530 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                         NULL,NULL,
                         (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 236:

/* Line 677 of lalr1.cc  */
#line 2538 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         NULL,
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(4) - (2)].node)),
                         NULL,
                         (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 237:

/* Line 677 of lalr1.cc  */
#line 2547 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (3)].node)),
                         NULL,
                         (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 238:

/* Line 677 of lalr1.cc  */
#line 2557 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         NULL,NULL,
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
                         (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 239:

/* Line 677 of lalr1.cc  */
#line 2565 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
                         NULL,
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
                         (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 240:

/* Line 677 of lalr1.cc  */
#line 2574 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC ((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)),
                         NULL,
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (2)].node)),
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
                         (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 241:

/* Line 677 of lalr1.cc  */
#line 2583 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC ((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(6) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (2)].node)),
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(6) - (3)].node)),
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
                         (yysemantic_stack_[(6) - (6)].expr));
    }
    break;

  case 242:

/* Line 677 of lalr1.cc  */
#line 2598 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 243:

/* Line 677 of lalr1.cc  */
#line 2607 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
    }
    break;

  case 244:

/* Line 677 of lalr1.cc  */
#line 2617 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (3)].node)) );
        }
    break;

  case 245:

/* Line 677 of lalr1.cc  */
#line 2625 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 246:

/* Line 677 of lalr1.cc  */
#line 2631 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 247:

/* Line 677 of lalr1.cc  */
#line 2640 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 248:

/* Line 677 of lalr1.cc  */
#line 2646 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 249:

/* Line 677 of lalr1.cc  */
#line 2658 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)),
                           NULL,
                           NULL,
                           (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 250:

/* Line 677 of lalr1.cc  */
#line 2666 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                           NULL,
                           (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 251:

/* Line 677 of lalr1.cc  */
#line 2676 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                           NULL,
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
                           (yysemantic_stack_[(4) - (4)].expr));
     }
    break;

  case 252:

/* Line 677 of lalr1.cc  */
#line 2684 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
                           (yysemantic_stack_[(5) - (5)].expr));
     }
    break;

  case 253:

/* Line 677 of lalr1.cc  */
#line 2696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 254:

/* Line 677 of lalr1.cc  */
#line 2702 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 256:

/* Line 677 of lalr1.cc  */
#line 2715 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 257:

/* Line 677 of lalr1.cc  */
#line 2719 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 258:

/* Line 677 of lalr1.cc  */
#line 2727 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 259:

/* Line 677 of lalr1.cc  */
#line 2731 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 261:

/* Line 677 of lalr1.cc  */
#line 2740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 262:

/* Line 677 of lalr1.cc  */
#line 2744 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 263:

/* Line 677 of lalr1.cc  */
#line 2748 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 264:

/* Line 677 of lalr1.cc  */
#line 2756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)),
                           NULL, NULL,
                           new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr))),
                           VarGetsDecl::eval_var);
    }
    break;

  case 265:

/* Line 677 of lalr1.cc  */
#line 2770 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 266:

/* Line 677 of lalr1.cc  */
#line 2778 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 267:

/* Line 677 of lalr1.cc  */
#line 2785 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = new GroupSpecList( LOC((yyloc)) );
            gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 268:

/* Line 677 of lalr1.cc  */
#line 2791 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
            if ( gsl )
                gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 269:

/* Line 677 of lalr1.cc  */
#line 2802 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 270:

/* Line 677 of lalr1.cc  */
#line 2806 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                         dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 271:

/* Line 677 of lalr1.cc  */
#line 2815 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 272:

/* Line 677 of lalr1.cc  */
#line 2823 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 273:

/* Line 677 of lalr1.cc  */
#line 2829 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 274:

/* Line 677 of lalr1.cc  */
#line 2839 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 275:

/* Line 677 of lalr1.cc  */
#line 2845 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 276:

/* Line 677 of lalr1.cc  */
#line 2855 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 277:

/* Line 677 of lalr1.cc  */
#line 2859 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 278:

/* Line 677 of lalr1.cc  */
#line 2869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 279:

/* Line 677 of lalr1.cc  */
#line 2875 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 280:

/* Line 677 of lalr1.cc  */
#line 2881 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 281:

/* Line 677 of lalr1.cc  */
#line 2887 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
                NULL
            );
        }
    break;

  case 282:

/* Line 677 of lalr1.cc  */
#line 2896 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                NULL,
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 283:

/* Line 677 of lalr1.cc  */
#line 2905 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                NULL,
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 284:

/* Line 677 of lalr1.cc  */
#line 2914 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 285:

/* Line 677 of lalr1.cc  */
#line 2927 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 286:

/* Line 677 of lalr1.cc  */
#line 2931 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 287:

/* Line 677 of lalr1.cc  */
#line 2939 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 288:

/* Line 677 of lalr1.cc  */
#line 2945 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 289:

/* Line 677 of lalr1.cc  */
#line 2955 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 290:

/* Line 677 of lalr1.cc  */
#line 2963 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_some,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 291:

/* Line 677 of lalr1.cc  */
#line 2972 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_every,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 292:

/* Line 677 of lalr1.cc  */
#line 2985 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 293:

/* Line 677 of lalr1.cc  */
#line 2992 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 294:

/* Line 677 of lalr1.cc  */
#line 3004 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 295:

/* Line 677 of lalr1.cc  */
#line 3008 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 296:

/* Line 677 of lalr1.cc  */
#line 3020 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 297:

/* Line 677 of lalr1.cc  */
#line 3027 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 298:

/* Line 677 of lalr1.cc  */
#line 3033 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 299:

/* Line 677 of lalr1.cc  */
#line 3042 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 300:

/* Line 677 of lalr1.cc  */
#line 3049 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 301:

/* Line 677 of lalr1.cc  */
#line 3055 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 302:

/* Line 677 of lalr1.cc  */
#line 3067 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 303:

/* Line 677 of lalr1.cc  */
#line 3074 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 304:

/* Line 677 of lalr1.cc  */
#line 3087 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 305:

/* Line 677 of lalr1.cc  */
#line 3093 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 306:

/* Line 677 of lalr1.cc  */
#line 3105 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 307:

/* Line 677 of lalr1.cc  */
#line 3111 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 308:

/* Line 677 of lalr1.cc  */
#line 3123 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 309:

/* Line 677 of lalr1.cc  */
#line 3132 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 310:

/* Line 677 of lalr1.cc  */
#line 3136 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 311:

/* Line 677 of lalr1.cc  */
#line 3145 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 312:

/* Line 677 of lalr1.cc  */
#line 3149 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 313:

/* Line 677 of lalr1.cc  */
#line 3157 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 314:

/* Line 677 of lalr1.cc  */
#line 3161 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 315:

/* Line 677 of lalr1.cc  */
#line 3171 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 316:

/* Line 677 of lalr1.cc  */
#line 3178 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_eq ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 317:

/* Line 677 of lalr1.cc  */
#line 3187 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ne ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 318:

/* Line 677 of lalr1.cc  */
#line 3196 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 319:

/* Line 677 of lalr1.cc  */
#line 3201 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_lt ),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr)
            );
        }
    break;

  case 320:

/* Line 677 of lalr1.cc  */
#line 3210 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_le ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 321:

/* Line 677 of lalr1.cc  */
#line 3219 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_gt ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 322:

/* Line 677 of lalr1.cc  */
#line 3228 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ge ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 323:

/* Line 677 of lalr1.cc  */
#line 3241 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 324:

/* Line 677 of lalr1.cc  */
#line 3245 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FTContainsExpr(
                LOC((yyloc)),
                (yysemantic_stack_[(5) - (1)].expr),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(5) - (4)].node)),
                dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 325:

/* Line 677 of lalr1.cc  */
#line 3257 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 326:

/* Line 677 of lalr1.cc  */
#line 3261 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 327:

/* Line 677 of lalr1.cc  */
#line 3268 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 328:

/* Line 677 of lalr1.cc  */
#line 3272 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 329:

/* Line 677 of lalr1.cc  */
#line 3281 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 330:

/* Line 677 of lalr1.cc  */
#line 3285 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 331:

/* Line 677 of lalr1.cc  */
#line 3289 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 332:

/* Line 677 of lalr1.cc  */
#line 3298 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 333:

/* Line 677 of lalr1.cc  */
#line 3302 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 334:

/* Line 677 of lalr1.cc  */
#line 3308 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 335:

/* Line 677 of lalr1.cc  */
#line 3314 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 336:

/* Line 677 of lalr1.cc  */
#line 3320 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 337:

/* Line 677 of lalr1.cc  */
#line 3331 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 338:

/* Line 677 of lalr1.cc  */
#line 3335 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 339:

/* Line 677 of lalr1.cc  */
#line 3339 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 340:

/* Line 677 of lalr1.cc  */
#line 3347 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 341:

/* Line 677 of lalr1.cc  */
#line 3351 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 342:

/* Line 677 of lalr1.cc  */
#line 3357 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 343:

/* Line 677 of lalr1.cc  */
#line 3367 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 344:

/* Line 677 of lalr1.cc  */
#line 3371 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 345:

/* Line 677 of lalr1.cc  */
#line 3381 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 346:

/* Line 677 of lalr1.cc  */
#line 3385 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 347:

/* Line 677 of lalr1.cc  */
#line 3395 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 348:

/* Line 677 of lalr1.cc  */
#line 3399 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 349:

/* Line 677 of lalr1.cc  */
#line 3409 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 350:

/* Line 677 of lalr1.cc  */
#line 3413 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 351:

/* Line 677 of lalr1.cc  */
#line 3423 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 352:

/* Line 677 of lalr1.cc  */
#line 3427 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 353:

/* Line 677 of lalr1.cc  */
#line 3435 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 354:

/* Line 677 of lalr1.cc  */
#line 3439 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 355:

/* Line 677 of lalr1.cc  */
#line 3443 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 356:

/* Line 677 of lalr1.cc  */
#line 3447 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 357:

/* Line 677 of lalr1.cc  */
#line 3457 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 358:

/* Line 677 of lalr1.cc  */
#line 3461 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 359:

/* Line 677 of lalr1.cc  */
#line 3465 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 360:

/* Line 677 of lalr1.cc  */
#line 3473 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 361:

/* Line 677 of lalr1.cc  */
#line 3477 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 362:

/* Line 677 of lalr1.cc  */
#line 3481 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 363:

/* Line 677 of lalr1.cc  */
#line 3485 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 364:

/* Line 677 of lalr1.cc  */
#line 3489 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 365:

/* Line 677 of lalr1.cc  */
#line 3493 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 366:

/* Line 677 of lalr1.cc  */
#line 3501 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 367:

/* Line 677 of lalr1.cc  */
#line 3505 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 368:

/* Line 677 of lalr1.cc  */
#line 3509 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 369:

/* Line 677 of lalr1.cc  */
#line 3517 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 370:

/* Line 677 of lalr1.cc  */
#line 3521 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 371:

/* Line 677 of lalr1.cc  */
#line 3525 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 372:

/* Line 677 of lalr1.cc  */
#line 3529 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 373:

/* Line 677 of lalr1.cc  */
#line 3540 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 374:

/* Line 677 of lalr1.cc  */
#line 3546 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 375:

/* Line 677 of lalr1.cc  */
#line 3556 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 376:

/* Line 677 of lalr1.cc  */
#line 3562 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 377:

/* Line 677 of lalr1.cc  */
#line 3572 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 378:

/* Line 677 of lalr1.cc  */
#line 3576 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 379:

/* Line 677 of lalr1.cc  */
#line 3614 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new PathExpr(
                LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL
            );
        }
    break;

  case 380:

/* Line 677 of lalr1.cc  */
#line 3620 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new PathExpr(
                LOC((yyloc)), ParseConstants::path_leading_slash, (yysemantic_stack_[(2) - (2)].expr)
            );
        }
    break;

  case 381:

/* Line 677 of lalr1.cc  */
#line 3626 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new PathExpr(
                LOC((yyloc)), ParseConstants::path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr)
            );
        }
    break;

  case 382:

/* Line 677 of lalr1.cc  */
#line 3632 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            RelativePathExpr *rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = !rpe ?
                (yysemantic_stack_[(1) - (1)].expr) : new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 383:

/* Line 677 of lalr1.cc  */
#line 3643 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NULL;
        }
    break;

  case 384:

/* Line 677 of lalr1.cc  */
#line 3651 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            AxisStep *as = dynamic_cast<AxisStep*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = as ?
                new RelativePathExpr(
                    LOC((yyloc)), ParseConstants::st_slash,
                    new ContextItemExpr( LOC((yyloc)), true ), (yysemantic_stack_[(1) - (1)].expr)
                )
            :
                (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 385:

/* Line 677 of lalr1.cc  */
#line 3662 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RelativePathExpr(
                LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 386:

/* Line 677 of lalr1.cc  */
#line 3668 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RelativePathExpr(
                LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 387:

/* Line 677 of lalr1.cc  */
#line 3678 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 388:

/* Line 677 of lalr1.cc  */
#line 3682 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 389:

/* Line 677 of lalr1.cc  */
#line 3690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 390:

/* Line 677 of lalr1.cc  */
#line 3696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 391:

/* Line 677 of lalr1.cc  */
#line 3704 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 392:

/* Line 677 of lalr1.cc  */
#line 3710 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 393:

/* Line 677 of lalr1.cc  */
#line 3722 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 394:

/* Line 677 of lalr1.cc  */
#line 3728 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 395:

/* Line 677 of lalr1.cc  */
#line 3738 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 396:

/* Line 677 of lalr1.cc  */
#line 3742 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 397:

/* Line 677 of lalr1.cc  */
#line 3746 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 398:

/* Line 677 of lalr1.cc  */
#line 3750 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 399:

/* Line 677 of lalr1.cc  */
#line 3754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 400:

/* Line 677 of lalr1.cc  */
#line 3760 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 401:

/* Line 677 of lalr1.cc  */
#line 3766 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 402:

/* Line 677 of lalr1.cc  */
#line 3774 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 403:

/* Line 677 of lalr1.cc  */
#line 3778 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 404:

/* Line 677 of lalr1.cc  */
#line 3786 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 405:

/* Line 677 of lalr1.cc  */
#line 3790 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 406:

/* Line 677 of lalr1.cc  */
#line 3801 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 407:

/* Line 677 of lalr1.cc  */
#line 3805 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 408:

/* Line 677 of lalr1.cc  */
#line 3809 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 409:

/* Line 677 of lalr1.cc  */
#line 3815 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 410:

/* Line 677 of lalr1.cc  */
#line 3819 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 411:

/* Line 677 of lalr1.cc  */
#line 3833 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 412:

/* Line 677 of lalr1.cc  */
#line 3837 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 413:

/* Line 677 of lalr1.cc  */
#line 3845 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 414:

/* Line 677 of lalr1.cc  */
#line 3849 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 415:

/* Line 677 of lalr1.cc  */
#line 3859 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all);
    }
    break;

  case 416:

/* Line 677 of lalr1.cc  */
#line 3863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem);
    }
    break;

  case 417:

/* Line 677 of lalr1.cc  */
#line 3867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix);
    }
    break;

  case 418:

/* Line 677 of lalr1.cc  */
#line 3876 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 419:

/* Line 677 of lalr1.cc  */
#line 3880 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FilterExpr(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 420:

/* Line 677 of lalr1.cc  */
#line 3886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
        }
    break;

  case 421:

/* Line 677 of lalr1.cc  */
#line 3890 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
        }
    break;

  case 422:

/* Line 677 of lalr1.cc  */
#line 3898 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 423:

/* Line 677 of lalr1.cc  */
#line 3904 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 424:

/* Line 677 of lalr1.cc  */
#line 3914 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 425:

/* Line 677 of lalr1.cc  */
#line 3922 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 426:

/* Line 677 of lalr1.cc  */
#line 3926 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 427:

/* Line 677 of lalr1.cc  */
#line 3930 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 428:

/* Line 677 of lalr1.cc  */
#line 3934 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 429:

/* Line 677 of lalr1.cc  */
#line 3938 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 430:

/* Line 677 of lalr1.cc  */
#line 3942 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 431:

/* Line 677 of lalr1.cc  */
#line 3946 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 432:

/* Line 677 of lalr1.cc  */
#line 3950 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 433:

/* Line 677 of lalr1.cc  */
#line 3954 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 434:

/* Line 677 of lalr1.cc  */
#line 3962 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 435:

/* Line 677 of lalr1.cc  */
#line 3966 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 436:

/* Line 677 of lalr1.cc  */
#line 3974 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 437:

/* Line 677 of lalr1.cc  */
#line 3981 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 438:

/* Line 677 of lalr1.cc  */
#line 3988 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 439:

/* Line 677 of lalr1.cc  */
#line 3999 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 440:

/* Line 677 of lalr1.cc  */
#line 4007 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 441:

/* Line 677 of lalr1.cc  */
#line 4011 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 442:

/* Line 677 of lalr1.cc  */
#line 4019 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 443:

/* Line 677 of lalr1.cc  */
#line 4027 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 444:

/* Line 677 of lalr1.cc  */
#line 4035 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 445:

/* Line 677 of lalr1.cc  */
#line 4089 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
        }
    break;

  case 446:

/* Line 677 of lalr1.cc  */
#line 4093 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 447:

/* Line 677 of lalr1.cc  */
#line 4105 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            ArgList *al = new ArgList( LOC((yyloc)) );
            al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
            (yyval.node) = al;
        }
    break;

  case 448:

/* Line 677 of lalr1.cc  */
#line 4111 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
                al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 449:

/* Line 677 of lalr1.cc  */
#line 4121 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 450:

/* Line 677 of lalr1.cc  */
#line 4125 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 451:

/* Line 677 of lalr1.cc  */
#line 4133 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 452:

/* Line 677 of lalr1.cc  */
#line 4137 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 453:

/* Line 677 of lalr1.cc  */
#line 4141 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 454:

/* Line 677 of lalr1.cc  */
#line 4149 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 455:

/* Line 677 of lalr1.cc  */
#line 4159 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 456:

/* Line 677 of lalr1.cc  */
#line 4169 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 457:

/* Line 677 of lalr1.cc  */
#line 4179 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 458:

/* Line 677 of lalr1.cc  */
#line 4189 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 459:

/* Line 677 of lalr1.cc  */
#line 4199 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 460:

/* Line 677 of lalr1.cc  */
#line 4214 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
            decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = decl;
        }
    break;

  case 461:

/* Line 677 of lalr1.cc  */
#line 4220 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( decl )
                decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 462:

/* Line 677 of lalr1.cc  */
#line 4231 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
            dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = dal;
        }
    break;

  case 463:

/* Line 677 of lalr1.cc  */
#line 4237 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
            if ( dal )
                dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 464:

/* Line 677 of lalr1.cc  */
#line 4248 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttr(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node))
            );
        }
    break;

  case 467:

/* Line 677 of lalr1.cc  */
#line 4265 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 468:

/* Line 677 of lalr1.cc  */
#line 4270 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 469:

/* Line 677 of lalr1.cc  */
#line 4279 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
        }
    break;

  case 470:

/* Line 677 of lalr1.cc  */
#line 4283 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 471:

/* Line 677 of lalr1.cc  */
#line 4290 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back(
                new QuoteAttrValueContent( LOC((yyloc)),std::string("\"") )
            );
            (yyval.node) = qacl;
        }
    break;

  case 472:

/* Line 677 of lalr1.cc  */
#line 4298 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = qacl;
        }
    break;

  case 473:

/* Line 677 of lalr1.cc  */
#line 4304 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back(
                    new QuoteAttrValueContent( LOC((yyloc)),std::string("\"") )
                );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 474:

/* Line 677 of lalr1.cc  */
#line 4314 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 475:

/* Line 677 of lalr1.cc  */
#line 4326 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
        }
    break;

  case 476:

/* Line 677 of lalr1.cc  */
#line 4330 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 477:

/* Line 677 of lalr1.cc  */
#line 4337 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = aacl;
        }
    break;

  case 478:

/* Line 677 of lalr1.cc  */
#line 4343 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = aacl;
        }
    break;

  case 479:

/* Line 677 of lalr1.cc  */
#line 4349 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if (aacl)
                aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 480:

/* Line 677 of lalr1.cc  */
#line 4356 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( aacl )
                aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 481:

/* Line 677 of lalr1.cc  */
#line 4367 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 482:

/* Line 677 of lalr1.cc  */
#line 4371 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 483:

/* Line 677 of lalr1.cc  */
#line 4381 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 484:

/* Line 677 of lalr1.cc  */
#line 4385 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 485:

/* Line 677 of lalr1.cc  */
#line 4395 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 486:

/* Line 677 of lalr1.cc  */
#line 4399 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 487:

/* Line 677 of lalr1.cc  */
#line 4403 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
        }
    break;

  case 488:

/* Line 677 of lalr1.cc  */
#line 4408 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
        }
    break;

  case 489:

/* Line 677 of lalr1.cc  */
#line 4417 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval))
            );
        }
    break;

  case 490:

/* Line 677 of lalr1.cc  */
#line 4423 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_lbrace
            );
        }
    break;

  case 491:

/* Line 677 of lalr1.cc  */
#line 4429 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_rbrace
            );
        }
    break;

  case 492:

/* Line 677 of lalr1.cc  */
#line 4435 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 493:

/* Line 677 of lalr1.cc  */
#line 4445 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 494:

/* Line 677 of lalr1.cc  */
#line 4449 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
        }
    break;

  case 495:

/* Line 677 of lalr1.cc  */
#line 4461 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 496:

/* Line 677 of lalr1.cc  */
#line 4465 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 497:

/* Line 677 of lalr1.cc  */
#line 4477 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 498:

/* Line 677 of lalr1.cc  */
#line 4489 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 499:

/* Line 677 of lalr1.cc  */
#line 4493 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 500:

/* Line 677 of lalr1.cc  */
#line 4497 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 501:

/* Line 677 of lalr1.cc  */
#line 4501 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 502:

/* Line 677 of lalr1.cc  */
#line 4505 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 503:

/* Line 677 of lalr1.cc  */
#line 4509 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 504:

/* Line 677 of lalr1.cc  */
#line 4517 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 505:

/* Line 677 of lalr1.cc  */
#line 4525 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)), NULL
            );
        }
    break;

  case 506:

/* Line 677 of lalr1.cc  */
#line 4531 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr)
            );
        }
    break;

  case 507:

/* Line 677 of lalr1.cc  */
#line 4537 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 508:

/* Line 677 of lalr1.cc  */
#line 4541 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 509:

/* Line 677 of lalr1.cc  */
#line 4558 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (2)].expr), NULL );
        }
    break;

  case 510:

/* Line 677 of lalr1.cc  */
#line 4562 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(5) - (2)].expr), (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 511:

/* Line 677 of lalr1.cc  */
#line 4566 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 512:

/* Line 677 of lalr1.cc  */
#line 4570 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 513:

/* Line 677 of lalr1.cc  */
#line 4578 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 514:

/* Line 677 of lalr1.cc  */
#line 4586 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 515:

/* Line 677 of lalr1.cc  */
#line 4594 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), NULL );
        }
    break;

  case 516:

/* Line 677 of lalr1.cc  */
#line 4598 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (2)].sval)), (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 517:

/* Line 677 of lalr1.cc  */
#line 4602 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 518:

/* Line 677 of lalr1.cc  */
#line 4606 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 519:

/* Line 677 of lalr1.cc  */
#line 4614 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)), false
            );
        }
    break;

  case 520:

/* Line 677 of lalr1.cc  */
#line 4620 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)), true
            );
        }
    break;

  case 521:

/* Line 677 of lalr1.cc  */
#line 4630 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 522:

/* Line 677 of lalr1.cc  */
#line 4638 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 523:

/* Line 677 of lalr1.cc  */
#line 4642 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 524:

/* Line 677 of lalr1.cc  */
#line 4648 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 525:

/* Line 677 of lalr1.cc  */
#line 4683 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 526:

/* Line 677 of lalr1.cc  */
#line 4689 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 527:

/* Line 677 of lalr1.cc  */
#line 4695 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 528:

/* Line 677 of lalr1.cc  */
#line 4705 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 529:

/* Line 677 of lalr1.cc  */
#line 4709 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 530:

/* Line 677 of lalr1.cc  */
#line 4713 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)),true );
        }
    break;

  case 531:

/* Line 677 of lalr1.cc  */
#line 4717 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 532:

/* Line 677 of lalr1.cc  */
#line 4721 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 533:

/* Line 677 of lalr1.cc  */
#line 4728 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 534:

/* Line 677 of lalr1.cc  */
#line 4734 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 535:

/* Line 677 of lalr1.cc  */
#line 4744 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 536:

/* Line 677 of lalr1.cc  */
#line 4752 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 537:

/* Line 677 of lalr1.cc  */
#line 4756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 538:

/* Line 677 of lalr1.cc  */
#line 4760 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 539:

/* Line 677 of lalr1.cc  */
#line 4764 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 540:

/* Line 677 of lalr1.cc  */
#line 4768 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 541:

/* Line 677 of lalr1.cc  */
#line 4772 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 542:

/* Line 677 of lalr1.cc  */
#line 4776 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 543:

/* Line 677 of lalr1.cc  */
#line 4780 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 544:

/* Line 677 of lalr1.cc  */
#line 4784 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 545:

/* Line 677 of lalr1.cc  */
#line 4792 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyKindTest( LOC((yyloc)) );
        }
    break;

  case 546:

/* Line 677 of lalr1.cc  */
#line 4800 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)) );
        }
    break;

  case 547:

/* Line 677 of lalr1.cc  */
#line 4804 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)) );
        }
    break;

  case 548:

/* Line 677 of lalr1.cc  */
#line 4808 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest(
                LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 549:

/* Line 677 of lalr1.cc  */
#line 4818 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TextTest( LOC((yyloc)) );
        }
    break;

  case 550:

/* Line 677 of lalr1.cc  */
#line 4826 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CommentTest( LOC((yyloc)));
        }
    break;

  case 551:

/* Line 677 of lalr1.cc  */
#line 4834 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 552:

/* Line 677 of lalr1.cc  */
#line 4838 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 553:

/* Line 677 of lalr1.cc  */
#line 4842 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 554:

/* Line 677 of lalr1.cc  */
#line 4850 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 555:

/* Line 677 of lalr1.cc  */
#line 4854 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 556:

/* Line 677 of lalr1.cc  */
#line 4860 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 557:

/* Line 677 of lalr1.cc  */
#line 4866 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 558:

/* Line 677 of lalr1.cc  */
#line 4870 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 559:

/* Line 677 of lalr1.cc  */
#line 4880 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)) );
        }
    break;

  case 560:

/* Line 677 of lalr1.cc  */
#line 4888 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 561:

/* Line 677 of lalr1.cc  */
#line 4892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 562:

/* Line 677 of lalr1.cc  */
#line 4898 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 563:

/* Line 677 of lalr1.cc  */
#line 4907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 564:

/* Line 677 of lalr1.cc  */
#line 4916 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 565:

/* Line 677 of lalr1.cc  */
#line 4922 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 566:

/* Line 677 of lalr1.cc  */
#line 4928 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 567:

/* Line 677 of lalr1.cc  */
#line 4938 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 568:

/* Line 677 of lalr1.cc  */
#line 4955 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 569:

/* Line 677 of lalr1.cc  */
#line 4962 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 570:

/* Line 677 of lalr1.cc  */
#line 4977 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 571:

/* Line 677 of lalr1.cc  */
#line 5013 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 572:

/* Line 677 of lalr1.cc  */
#line 5017 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 573:

/* Line 677 of lalr1.cc  */
#line 5026 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
        }
    break;

  case 574:

/* Line 677 of lalr1.cc  */
#line 5035 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new InlineFunction(LOC ((yyloc)), &*(yysemantic_stack_[(3) - (2)].fnsig)->param, &*(yysemantic_stack_[(3) - (2)].fnsig)->ret, dynamic_cast<EnclosedExpr *>((yysemantic_stack_[(3) - (3)].expr)));
          delete (yysemantic_stack_[(3) - (2)].fnsig);
        }
    break;

  case 575:

/* Line 677 of lalr1.cc  */
#line 5045 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 576:

/* Line 677 of lalr1.cc  */
#line 5049 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 577:

/* Line 677 of lalr1.cc  */
#line 5058 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
        }
    break;

  case 578:

/* Line 677 of lalr1.cc  */
#line 5067 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 579:

/* Line 677 of lalr1.cc  */
#line 5071 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 580:

/* Line 677 of lalr1.cc  */
#line 5082 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 581:

/* Line 677 of lalr1.cc  */
#line 5099 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 582:

/* Line 677 of lalr1.cc  */
#line 5105 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 583:

/* Line 677 of lalr1.cc  */
#line 5111 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 584:

/* Line 677 of lalr1.cc  */
#line 5121 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 585:

/* Line 677 of lalr1.cc  */
#line 5125 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 586:

/* Line 677 of lalr1.cc  */
#line 5131 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 587:

/* Line 677 of lalr1.cc  */
#line 5137 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 588:

/* Line 677 of lalr1.cc  */
#line 5141 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 589:

/* Line 677 of lalr1.cc  */
#line 5147 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 590:

/* Line 677 of lalr1.cc  */
#line 5151 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 591:

/* Line 677 of lalr1.cc  */
#line 5157 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 592:

/* Line 677 of lalr1.cc  */
#line 5163 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 593:

/* Line 677 of lalr1.cc  */
#line 5170 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 594:

/* Line 677 of lalr1.cc  */
#line 5180 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 595:

/* Line 677 of lalr1.cc  */
#line 5185 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 596:

/* Line 677 of lalr1.cc  */
#line 5193 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 597:

/* Line 677 of lalr1.cc  */
#line 5199 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 598:

/* Line 677 of lalr1.cc  */
#line 5209 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 599:

/* Line 677 of lalr1.cc  */
#line 5231 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 600:

/* Line 677 of lalr1.cc  */
#line 5240 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 601:

/* Line 677 of lalr1.cc  */
#line 5246 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 602:

/* Line 677 of lalr1.cc  */
#line 5259 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 603:

/* Line 677 of lalr1.cc  */
#line 5273 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 604:

/* Line 677 of lalr1.cc  */
#line 5280 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 605:

/* Line 677 of lalr1.cc  */
#line 5286 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 606:

/* Line 677 of lalr1.cc  */
#line 5296 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 607:

/* Line 677 of lalr1.cc  */
#line 5301 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CatchExpr(LOC((yyloc)),*(yysemantic_stack_[(7) - (2)].name_test_list), static_cast<QName*>((yysemantic_stack_[(7) - (5)].expr)), NULL, NULL, (yysemantic_stack_[(7) - (7)].expr));
       delete (yysemantic_stack_[(7) - (2)].name_test_list);
    }
    break;

  case 608:

/* Line 677 of lalr1.cc  */
#line 5307 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 609:

/* Line 677 of lalr1.cc  */
#line 5317 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 610:

/* Line 677 of lalr1.cc  */
#line 5330 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 611:

/* Line 677 of lalr1.cc  */
#line 5336 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 614:

/* Line 677 of lalr1.cc  */
#line 5357 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            std::auto_ptr<QName> lQName( static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
            std::string tmp = lQName->get_qname();
            if ( tmp.find (':') != std::string::npos ) {
                error((yylocation_stack_[(1) - (1)]), "A NCName is expected, found a QName");
                YYERROR;
            }
            (yyval.sval) = SYMTAB_PUT(tmp.c_str());
        }
    break;

  case 615:

/* Line 677 of lalr1.cc  */
#line 5376 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new EvalExpr(
        LOC((yyloc)), dynamic_cast<VarGetsDeclList *> ((yysemantic_stack_[(7) - (3)].node)), (yysemantic_stack_[(7) - (6)].expr)
        );
    }
    break;

  case 616:

/* Line 677 of lalr1.cc  */
#line 5382 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new EvalExpr( LOC((yyloc)), new VarGetsDeclList( LOC((yyloc)) ), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 617:

/* Line 677 of lalr1.cc  */
#line 5397 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 618:

/* Line 677 of lalr1.cc  */
#line 5405 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 619:

/* Line 677 of lalr1.cc  */
#line 5409 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 620:

/* Line 677 of lalr1.cc  */
#line 5416 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 621:

/* Line 677 of lalr1.cc  */
#line 5421 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 622:

/* Line 677 of lalr1.cc  */
#line 5429 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 623:

/* Line 677 of lalr1.cc  */
#line 5433 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 624:

/* Line 677 of lalr1.cc  */
#line 5440 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 625:

/* Line 677 of lalr1.cc  */
#line 5444 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 626:

/* Line 677 of lalr1.cc  */
#line 5451 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 627:

/* Line 677 of lalr1.cc  */
#line 5455 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 628:

/* Line 677 of lalr1.cc  */
#line 5462 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 629:

/* Line 677 of lalr1.cc  */
#line 5466 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 630:

/* Line 677 of lalr1.cc  */
#line 5475 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 631:

/* Line 677 of lalr1.cc  */
#line 5487 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 632:

/* Line 677 of lalr1.cc  */
#line 5491 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 633:

/* Line 677 of lalr1.cc  */
#line 5498 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 634:

/* Line 677 of lalr1.cc  */
#line 5502 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 635:

/* Line 677 of lalr1.cc  */
#line 5510 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 636:

/* Line 677 of lalr1.cc  */
#line 5518 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 637:

/* Line 677 of lalr1.cc  */
#line 5526 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 638:

/* Line 677 of lalr1.cc  */
#line 5530 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 639:

/* Line 677 of lalr1.cc  */
#line 5537 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 640:

/* Line 677 of lalr1.cc  */
#line 5541 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 641:

/* Line 677 of lalr1.cc  */
#line 5549 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 642:

/* Line 677 of lalr1.cc  */
#line 5560 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 643:

/* Line 677 of lalr1.cc  */
#line 5564 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 644:

/* Line 677 of lalr1.cc  */
#line 5572 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 645:

/* Line 677 of lalr1.cc  */
#line 5584 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 646:

/* Line 677 of lalr1.cc  */
#line 5590 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 647:

/* Line 677 of lalr1.cc  */
#line 5599 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 648:

/* Line 677 of lalr1.cc  */
#line 5603 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 649:

/* Line 677 of lalr1.cc  */
#line 5611 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 650:

/* Line 677 of lalr1.cc  */
#line 5615 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 651:

/* Line 677 of lalr1.cc  */
#line 5619 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 652:

/* Line 677 of lalr1.cc  */
#line 5626 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 653:

/* Line 677 of lalr1.cc  */
#line 5630 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 654:

/* Line 677 of lalr1.cc  */
#line 5637 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 655:

/* Line 677 of lalr1.cc  */
#line 5641 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 656:

/* Line 677 of lalr1.cc  */
#line 5649 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 657:

/* Line 677 of lalr1.cc  */
#line 5653 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 658:

/* Line 677 of lalr1.cc  */
#line 5657 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 659:

/* Line 677 of lalr1.cc  */
#line 5661 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 660:

/* Line 677 of lalr1.cc  */
#line 5665 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 661:

/* Line 677 of lalr1.cc  */
#line 5673 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 662:

/* Line 677 of lalr1.cc  */
#line 5681 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 663:

/* Line 677 of lalr1.cc  */
#line 5693 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 664:

/* Line 677 of lalr1.cc  */
#line 5705 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 665:

/* Line 677 of lalr1.cc  */
#line 5709 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 666:

/* Line 677 of lalr1.cc  */
#line 5713 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 667:

/* Line 677 of lalr1.cc  */
#line 5721 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 668:

/* Line 677 of lalr1.cc  */
#line 5727 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 669:

/* Line 677 of lalr1.cc  */
#line 5737 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 670:

/* Line 677 of lalr1.cc  */
#line 5741 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 671:

/* Line 677 of lalr1.cc  */
#line 5745 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 672:

/* Line 677 of lalr1.cc  */
#line 5749 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 673:

/* Line 677 of lalr1.cc  */
#line 5753 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 674:

/* Line 677 of lalr1.cc  */
#line 5757 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 675:

/* Line 677 of lalr1.cc  */
#line 5761 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 676:

/* Line 677 of lalr1.cc  */
#line 5765 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 677:

/* Line 677 of lalr1.cc  */
#line 5773 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 678:

/* Line 677 of lalr1.cc  */
#line 5777 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 679:

/* Line 677 of lalr1.cc  */
#line 5781 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 680:

/* Line 677 of lalr1.cc  */
#line 5785 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 681:

/* Line 677 of lalr1.cc  */
#line 5793 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 682:

/* Line 677 of lalr1.cc  */
#line 5799 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 683:

/* Line 677 of lalr1.cc  */
#line 5809 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 684:

/* Line 677 of lalr1.cc  */
#line 5819 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::with );
        }
    break;

  case 685:

/* Line 677 of lalr1.cc  */
#line 5823 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::without );
        }
    break;

  case 686:

/* Line 677 of lalr1.cc  */
#line 5831 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 687:

/* Line 677 of lalr1.cc  */
#line 5841 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 688:

/* Line 677 of lalr1.cc  */
#line 5852 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 689:

/* Line 677 of lalr1.cc  */
#line 5859 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 690:

/* Line 677 of lalr1.cc  */
#line 5863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 691:

/* Line 677 of lalr1.cc  */
#line 5870 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 692:

/* Line 677 of lalr1.cc  */
#line 5874 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(1) - (1)].thesaurus_id_list);
        }
    break;

  case 693:

/* Line 677 of lalr1.cc  */
#line 5881 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 694:

/* Line 677 of lalr1.cc  */
#line 5886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 695:

/* Line 677 of lalr1.cc  */
#line 5895 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 696:

/* Line 677 of lalr1.cc  */
#line 5904 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = NULL;
        }
    break;

  case 697:

/* Line 677 of lalr1.cc  */
#line 5908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 698:

/* Line 677 of lalr1.cc  */
#line 5915 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 699:

/* Line 677 of lalr1.cc  */
#line 5919 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 700:

/* Line 677 of lalr1.cc  */
#line 5927 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 701:

/* Line 677 of lalr1.cc  */
#line 5936 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 702:

/* Line 677 of lalr1.cc  */
#line 5943 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 703:

/* Line 677 of lalr1.cc  */
#line 5953 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 704:

/* Line 677 of lalr1.cc  */
#line 5957 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), NULL, (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 705:

/* Line 677 of lalr1.cc  */
#line 5964 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 706:

/* Line 677 of lalr1.cc  */
#line 5970 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 707:

/* Line 677 of lalr1.cc  */
#line 5979 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 708:

/* Line 677 of lalr1.cc  */
#line 5983 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 709:

/* Line 677 of lalr1.cc  */
#line 5990 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 710:

/* Line 677 of lalr1.cc  */
#line 5995 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 711:

/* Line 677 of lalr1.cc  */
#line 6007 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 712:

/* Line 677 of lalr1.cc  */
#line 6015 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 713:

/* Line 677 of lalr1.cc  */
#line 6027 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 714:

/* Line 677 of lalr1.cc  */
#line 6035 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 715:

/* Line 677 of lalr1.cc  */
#line 6039 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 716:

/* Line 677 of lalr1.cc  */
#line 6047 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 717:

/* Line 677 of lalr1.cc  */
#line 6051 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 718:

/* Line 677 of lalr1.cc  */
#line 6055 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 719:

/* Line 677 of lalr1.cc  */
#line 6063 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 720:

/* Line 677 of lalr1.cc  */
#line 6071 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 721:

/* Line 677 of lalr1.cc  */
#line 6075 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 722:

/* Line 677 of lalr1.cc  */
#line 6079 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 723:

/* Line 677 of lalr1.cc  */
#line 6083 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 724:

/* Line 677 of lalr1.cc  */
#line 6091 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 725:

/* Line 677 of lalr1.cc  */
#line 6099 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 726:

/* Line 677 of lalr1.cc  */
#line 6111 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 727:

/* Line 677 of lalr1.cc  */
#line 6115 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 728:

/* Line 677 of lalr1.cc  */
#line 6123 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 729:

/* Line 677 of lalr1.cc  */
#line 6136 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 730:

/* Line 677 of lalr1.cc  */
#line 6140 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 731:

/* Line 677 of lalr1.cc  */
#line 6146 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("xquery"); }
    break;

  case 732:

/* Line 677 of lalr1.cc  */
#line 6147 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("empty"); }
    break;

  case 733:

/* Line 677 of lalr1.cc  */
#line 6148 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("attribute"); }
    break;

  case 734:

/* Line 677 of lalr1.cc  */
#line 6149 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("comment"); }
    break;

  case 735:

/* Line 677 of lalr1.cc  */
#line 6150 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("document-node"); }
    break;

  case 736:

/* Line 677 of lalr1.cc  */
#line 6151 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("element"); }
    break;

  case 737:

/* Line 677 of lalr1.cc  */
#line 6152 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("item"); }
    break;

  case 738:

/* Line 677 of lalr1.cc  */
#line 6153 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("if"); }
    break;

  case 739:

/* Line 677 of lalr1.cc  */
#line 6154 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("node"); }
    break;

  case 740:

/* Line 677 of lalr1.cc  */
#line 6155 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("processing-instruction"); }
    break;

  case 741:

/* Line 677 of lalr1.cc  */
#line 6156 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("schema-attribute"); }
    break;

  case 742:

/* Line 677 of lalr1.cc  */
#line 6157 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("schema-element"); }
    break;

  case 743:

/* Line 677 of lalr1.cc  */
#line 6158 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("text"); }
    break;

  case 744:

/* Line 677 of lalr1.cc  */
#line 6159 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("typeswitch"); }
    break;

  case 745:

/* Line 677 of lalr1.cc  */
#line 6160 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("switch"); }
    break;

  case 746:

/* Line 677 of lalr1.cc  */
#line 6161 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("empty-sequence"); }
    break;

  case 747:

/* Line 677 of lalr1.cc  */
#line 6162 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("boundary-space"); }
    break;

  case 748:

/* Line 677 of lalr1.cc  */
#line 6163 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ft-option"); }
    break;

  case 749:

/* Line 677 of lalr1.cc  */
#line 6164 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("base-uri"); }
    break;

  case 750:

/* Line 677 of lalr1.cc  */
#line 6165 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("lax"); }
    break;

  case 751:

/* Line 677 of lalr1.cc  */
#line 6166 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("strict"); }
    break;

  case 752:

/* Line 677 of lalr1.cc  */
#line 6167 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("idiv"); }
    break;

  case 753:

/* Line 677 of lalr1.cc  */
#line 6168 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("document"); }
    break;

  case 754:

/* Line 677 of lalr1.cc  */
#line 6169 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ftnot"); }
    break;

  case 755:

/* Line 677 of lalr1.cc  */
#line 6170 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("not"); }
    break;

  case 756:

/* Line 677 of lalr1.cc  */
#line 6171 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("sensitive"); }
    break;

  case 757:

/* Line 677 of lalr1.cc  */
#line 6172 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("insensitive"); }
    break;

  case 758:

/* Line 677 of lalr1.cc  */
#line 6173 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("diacritics"); }
    break;

  case 759:

/* Line 677 of lalr1.cc  */
#line 6174 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("without"); }
    break;

  case 760:

/* Line 677 of lalr1.cc  */
#line 6175 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("stemming"); }
    break;

  case 761:

/* Line 677 of lalr1.cc  */
#line 6176 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("thesaurus"); }
    break;

  case 762:

/* Line 677 of lalr1.cc  */
#line 6177 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("stop"); }
    break;

  case 763:

/* Line 677 of lalr1.cc  */
#line 6178 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("wildcards"); }
    break;

  case 764:

/* Line 677 of lalr1.cc  */
#line 6179 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("entire"); }
    break;

  case 765:

/* Line 677 of lalr1.cc  */
#line 6180 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("content"); }
    break;

  case 766:

/* Line 677 of lalr1.cc  */
#line 6181 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("word"); }
    break;

  case 767:

/* Line 677 of lalr1.cc  */
#line 6182 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("start"); }
    break;

  case 768:

/* Line 677 of lalr1.cc  */
#line 6183 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("end"); }
    break;

  case 769:

/* Line 677 of lalr1.cc  */
#line 6184 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("most"); }
    break;

  case 770:

/* Line 677 of lalr1.cc  */
#line 6185 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("skip"); }
    break;

  case 771:

/* Line 677 of lalr1.cc  */
#line 6186 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("copy"); }
    break;

  case 772:

/* Line 677 of lalr1.cc  */
#line 6187 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("general"); }
    break;

  case 773:

/* Line 677 of lalr1.cc  */
#line 6188 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("value"); }
    break;

  case 774:

/* Line 677 of lalr1.cc  */
#line 6189 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("eq"); }
    break;

  case 775:

/* Line 677 of lalr1.cc  */
#line 6190 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ne"); }
    break;

  case 776:

/* Line 677 of lalr1.cc  */
#line 6191 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("lt"); }
    break;

  case 777:

/* Line 677 of lalr1.cc  */
#line 6192 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("le"); }
    break;

  case 778:

/* Line 677 of lalr1.cc  */
#line 6193 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("gt"); }
    break;

  case 779:

/* Line 677 of lalr1.cc  */
#line 6194 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ge"); }
    break;

  case 780:

/* Line 677 of lalr1.cc  */
#line 6195 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("at"); }
    break;

  case 781:

/* Line 677 of lalr1.cc  */
#line 6196 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("context"); }
    break;

  case 782:

/* Line 677 of lalr1.cc  */
#line 6197 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("variable"); }
    break;

  case 783:

/* Line 677 of lalr1.cc  */
#line 6198 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("return"); }
    break;

  case 784:

/* Line 677 of lalr1.cc  */
#line 6199 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("for"); }
    break;

  case 785:

/* Line 677 of lalr1.cc  */
#line 6200 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("outer"); }
    break;

  case 786:

/* Line 677 of lalr1.cc  */
#line 6201 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("sliding"); }
    break;

  case 787:

/* Line 677 of lalr1.cc  */
#line 6202 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("tumbling"); }
    break;

  case 788:

/* Line 677 of lalr1.cc  */
#line 6203 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("previous"); }
    break;

  case 789:

/* Line 677 of lalr1.cc  */
#line 6204 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("next"); }
    break;

  case 790:

/* Line 677 of lalr1.cc  */
#line 6205 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("only"); }
    break;

  case 791:

/* Line 677 of lalr1.cc  */
#line 6206 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("when"); }
    break;

  case 792:

/* Line 677 of lalr1.cc  */
#line 6207 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("count"); }
    break;

  case 793:

/* Line 677 of lalr1.cc  */
#line 6208 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("in"); }
    break;

  case 794:

/* Line 677 of lalr1.cc  */
#line 6209 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("let"); }
    break;

  case 795:

/* Line 677 of lalr1.cc  */
#line 6210 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("where"); }
    break;

  case 796:

/* Line 677 of lalr1.cc  */
#line 6211 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("by"); }
    break;

  case 797:

/* Line 677 of lalr1.cc  */
#line 6212 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("group"); }
    break;

  case 798:

/* Line 677 of lalr1.cc  */
#line 6213 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("order"); }
    break;

  case 799:

/* Line 677 of lalr1.cc  */
#line 6214 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("stable"); }
    break;

  case 800:

/* Line 677 of lalr1.cc  */
#line 6215 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ascending"); }
    break;

  case 801:

/* Line 677 of lalr1.cc  */
#line 6216 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("descending"); }
    break;

  case 802:

/* Line 677 of lalr1.cc  */
#line 6217 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("greatest"); }
    break;

  case 803:

/* Line 677 of lalr1.cc  */
#line 6218 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("least"); }
    break;

  case 804:

/* Line 677 of lalr1.cc  */
#line 6219 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("collation"); }
    break;

  case 805:

/* Line 677 of lalr1.cc  */
#line 6220 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("some"); }
    break;

  case 806:

/* Line 677 of lalr1.cc  */
#line 6221 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("every"); }
    break;

  case 807:

/* Line 677 of lalr1.cc  */
#line 6222 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("satisfies"); }
    break;

  case 808:

/* Line 677 of lalr1.cc  */
#line 6223 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("case"); }
    break;

  case 809:

/* Line 677 of lalr1.cc  */
#line 6224 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("as"); }
    break;

  case 810:

/* Line 677 of lalr1.cc  */
#line 6225 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("then"); }
    break;

  case 811:

/* Line 677 of lalr1.cc  */
#line 6226 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("else"); }
    break;

  case 812:

/* Line 677 of lalr1.cc  */
#line 6227 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("or"); }
    break;

  case 813:

/* Line 677 of lalr1.cc  */
#line 6228 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("and"); }
    break;

  case 814:

/* Line 677 of lalr1.cc  */
#line 6229 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("instance"); }
    break;

  case 815:

/* Line 677 of lalr1.cc  */
#line 6230 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("of"); }
    break;

  case 816:

/* Line 677 of lalr1.cc  */
#line 6231 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("castable"); }
    break;

  case 817:

/* Line 677 of lalr1.cc  */
#line 6232 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("to"); }
    break;

  case 818:

/* Line 677 of lalr1.cc  */
#line 6233 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("div"); }
    break;

  case 819:

/* Line 677 of lalr1.cc  */
#line 6234 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("mod"); }
    break;

  case 820:

/* Line 677 of lalr1.cc  */
#line 6235 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("union"); }
    break;

  case 821:

/* Line 677 of lalr1.cc  */
#line 6236 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("intersect"); }
    break;

  case 822:

/* Line 677 of lalr1.cc  */
#line 6237 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("except"); }
    break;

  case 823:

/* Line 677 of lalr1.cc  */
#line 6238 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("validate"); }
    break;

  case 824:

/* Line 677 of lalr1.cc  */
#line 6239 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("cast"); }
    break;

  case 825:

/* Line 677 of lalr1.cc  */
#line 6240 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("treat"); }
    break;

  case 826:

/* Line 677 of lalr1.cc  */
#line 6241 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("is"); }
    break;

  case 827:

/* Line 677 of lalr1.cc  */
#line 6242 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("preserve"); }
    break;

  case 828:

/* Line 677 of lalr1.cc  */
#line 6243 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("strip"); }
    break;

  case 829:

/* Line 677 of lalr1.cc  */
#line 6244 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("namespace"); }
    break;

  case 830:

/* Line 677 of lalr1.cc  */
#line 6245 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("external"); }
    break;

  case 831:

/* Line 677 of lalr1.cc  */
#line 6246 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("encoding"); }
    break;

  case 832:

/* Line 677 of lalr1.cc  */
#line 6247 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("no-preserve"); }
    break;

  case 833:

/* Line 677 of lalr1.cc  */
#line 6248 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("inherit"); }
    break;

  case 834:

/* Line 677 of lalr1.cc  */
#line 6249 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("no-inherit"); }
    break;

  case 835:

/* Line 677 of lalr1.cc  */
#line 6250 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("declare"); }
    break;

  case 836:

/* Line 677 of lalr1.cc  */
#line 6251 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("construction"); }
    break;

  case 837:

/* Line 677 of lalr1.cc  */
#line 6252 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ordering"); }
    break;

  case 838:

/* Line 677 of lalr1.cc  */
#line 6253 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("default"); }
    break;

  case 839:

/* Line 677 of lalr1.cc  */
#line 6254 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("copy-namespaces"); }
    break;

  case 840:

/* Line 677 of lalr1.cc  */
#line 6255 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("option"); }
    break;

  case 841:

/* Line 677 of lalr1.cc  */
#line 6256 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("version"); }
    break;

  case 842:

/* Line 677 of lalr1.cc  */
#line 6257 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("import"); }
    break;

  case 843:

/* Line 677 of lalr1.cc  */
#line 6258 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("schema"); }
    break;

  case 844:

/* Line 677 of lalr1.cc  */
#line 6259 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("module"); }
    break;

  case 845:

/* Line 677 of lalr1.cc  */
#line 6260 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("function"); }
    break;

  case 846:

/* Line 677 of lalr1.cc  */
#line 6261 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("score"); }
    break;

  case 847:

/* Line 677 of lalr1.cc  */
#line 6262 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("contains"); }
    break;

  case 848:

/* Line 677 of lalr1.cc  */
#line 6263 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("weight"); }
    break;

  case 849:

/* Line 677 of lalr1.cc  */
#line 6264 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("window"); }
    break;

  case 850:

/* Line 677 of lalr1.cc  */
#line 6265 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("distance"); }
    break;

  case 851:

/* Line 677 of lalr1.cc  */
#line 6266 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("occurs"); }
    break;

  case 852:

/* Line 677 of lalr1.cc  */
#line 6267 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("times"); }
    break;

  case 853:

/* Line 677 of lalr1.cc  */
#line 6268 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("same"); }
    break;

  case 854:

/* Line 677 of lalr1.cc  */
#line 6269 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("different"); }
    break;

  case 855:

/* Line 677 of lalr1.cc  */
#line 6270 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("lowercase"); }
    break;

  case 856:

/* Line 677 of lalr1.cc  */
#line 6271 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("uppercase"); }
    break;

  case 857:

/* Line 677 of lalr1.cc  */
#line 6272 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("relationship"); }
    break;

  case 858:

/* Line 677 of lalr1.cc  */
#line 6273 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("levels"); }
    break;

  case 859:

/* Line 677 of lalr1.cc  */
#line 6274 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("language"); }
    break;

  case 860:

/* Line 677 of lalr1.cc  */
#line 6275 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("any"); }
    break;

  case 861:

/* Line 677 of lalr1.cc  */
#line 6276 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("all"); }
    break;

  case 862:

/* Line 677 of lalr1.cc  */
#line 6277 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("phrase"); }
    break;

  case 863:

/* Line 677 of lalr1.cc  */
#line 6278 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("exactly"); }
    break;

  case 864:

/* Line 677 of lalr1.cc  */
#line 6279 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("from"); }
    break;

  case 865:

/* Line 677 of lalr1.cc  */
#line 6280 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("words"); }
    break;

  case 866:

/* Line 677 of lalr1.cc  */
#line 6281 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("sentences"); }
    break;

  case 867:

/* Line 677 of lalr1.cc  */
#line 6282 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("sentence"); }
    break;

  case 868:

/* Line 677 of lalr1.cc  */
#line 6283 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("paragraph"); }
    break;

  case 869:

/* Line 677 of lalr1.cc  */
#line 6284 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("replace"); }
    break;

  case 870:

/* Line 677 of lalr1.cc  */
#line 6285 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("modify"); }
    break;

  case 871:

/* Line 677 of lalr1.cc  */
#line 6286 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("first"); }
    break;

  case 872:

/* Line 677 of lalr1.cc  */
#line 6287 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("insert"); }
    break;

  case 873:

/* Line 677 of lalr1.cc  */
#line 6288 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("before"); }
    break;

  case 874:

/* Line 677 of lalr1.cc  */
#line 6289 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("after"); }
    break;

  case 875:

/* Line 677 of lalr1.cc  */
#line 6290 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("revalidation"); }
    break;

  case 876:

/* Line 677 of lalr1.cc  */
#line 6291 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("with"); }
    break;

  case 877:

/* Line 677 of lalr1.cc  */
#line 6292 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("nodes"); }
    break;

  case 878:

/* Line 677 of lalr1.cc  */
#line 6293 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("rename"); }
    break;

  case 879:

/* Line 677 of lalr1.cc  */
#line 6294 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("last"); }
    break;

  case 880:

/* Line 677 of lalr1.cc  */
#line 6295 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("delete"); }
    break;

  case 881:

/* Line 677 of lalr1.cc  */
#line 6296 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("into"); }
    break;

  case 882:

/* Line 677 of lalr1.cc  */
#line 6297 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("simple"); }
    break;

  case 883:

/* Line 677 of lalr1.cc  */
#line 6298 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("sequential"); }
    break;

  case 884:

/* Line 677 of lalr1.cc  */
#line 6299 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("updating"); }
    break;

  case 885:

/* Line 677 of lalr1.cc  */
#line 6300 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("deterministic"); }
    break;

  case 886:

/* Line 677 of lalr1.cc  */
#line 6301 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("nondeterministic"); }
    break;

  case 887:

/* Line 677 of lalr1.cc  */
#line 6302 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ordered"); }
    break;

  case 888:

/* Line 677 of lalr1.cc  */
#line 6303 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("unordered"); }
    break;

  case 889:

/* Line 677 of lalr1.cc  */
#line 6304 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("returning"); }
    break;

  case 890:

/* Line 677 of lalr1.cc  */
#line 6305 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("block"); }
    break;

  case 891:

/* Line 677 of lalr1.cc  */
#line 6306 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("exit"); }
    break;

  case 892:

/* Line 677 of lalr1.cc  */
#line 6307 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("loop"); }
    break;

  case 893:

/* Line 677 of lalr1.cc  */
#line 6308 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("while"); }
    break;

  case 894:

/* Line 677 of lalr1.cc  */
#line 6309 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("break"); }
    break;

  case 895:

/* Line 677 of lalr1.cc  */
#line 6310 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("continue"); }
    break;

  case 896:

/* Line 677 of lalr1.cc  */
#line 6311 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("try"); }
    break;

  case 897:

/* Line 677 of lalr1.cc  */
#line 6312 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("catch"); }
    break;

  case 898:

/* Line 677 of lalr1.cc  */
#line 6313 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("eval"); }
    break;

  case 899:

/* Line 677 of lalr1.cc  */
#line 6314 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("using"); }
    break;

  case 900:

/* Line 677 of lalr1.cc  */
#line 6315 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("set"); }
    break;

  case 901:

/* Line 677 of lalr1.cc  */
#line 6316 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("index"); }
    break;

  case 902:

/* Line 677 of lalr1.cc  */
#line 6317 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("unique"); }
    break;

  case 903:

/* Line 677 of lalr1.cc  */
#line 6318 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("non"); }
    break;

  case 904:

/* Line 677 of lalr1.cc  */
#line 6319 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("on"); }
    break;

  case 905:

/* Line 677 of lalr1.cc  */
#line 6320 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("range"); }
    break;

  case 906:

/* Line 677 of lalr1.cc  */
#line 6321 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("equality"); }
    break;

  case 907:

/* Line 677 of lalr1.cc  */
#line 6322 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("manually"); }
    break;

  case 908:

/* Line 677 of lalr1.cc  */
#line 6323 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("automatically"); }
    break;

  case 909:

/* Line 677 of lalr1.cc  */
#line 6324 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("maintained"); }
    break;

  case 910:

/* Line 677 of lalr1.cc  */
#line 6325 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("decimal-format"); }
    break;

  case 911:

/* Line 677 of lalr1.cc  */
#line 6326 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("decimal-separator"); }
    break;

  case 912:

/* Line 677 of lalr1.cc  */
#line 6327 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("grouping-separator"); }
    break;

  case 913:

/* Line 677 of lalr1.cc  */
#line 6328 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("infinity"); }
    break;

  case 914:

/* Line 677 of lalr1.cc  */
#line 6329 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("minus-sign"); }
    break;

  case 915:

/* Line 677 of lalr1.cc  */
#line 6330 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("NaN"); }
    break;

  case 916:

/* Line 677 of lalr1.cc  */
#line 6331 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("percent"); }
    break;

  case 917:

/* Line 677 of lalr1.cc  */
#line 6332 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("per-mille"); }
    break;

  case 918:

/* Line 677 of lalr1.cc  */
#line 6333 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("zero-digit"); }
    break;

  case 919:

/* Line 677 of lalr1.cc  */
#line 6334 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("digit"); }
    break;

  case 920:

/* Line 677 of lalr1.cc  */
#line 6335 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("pattern-separator"); }
    break;

  case 921:

/* Line 677 of lalr1.cc  */
#line 6336 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("collection"); }
    break;

  case 922:

/* Line 677 of lalr1.cc  */
#line 6337 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("const"); }
    break;

  case 923:

/* Line 677 of lalr1.cc  */
#line 6338 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("append-only"); }
    break;

  case 924:

/* Line 677 of lalr1.cc  */
#line 6339 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("queue"); }
    break;

  case 925:

/* Line 677 of lalr1.cc  */
#line 6340 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("mutable"); }
    break;

  case 926:

/* Line 677 of lalr1.cc  */
#line 6341 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("read-only"); }
    break;

  case 927:

/* Line 677 of lalr1.cc  */
#line 6342 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("integrity"); }
    break;

  case 928:

/* Line 677 of lalr1.cc  */
#line 6343 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("constraint"); }
    break;

  case 929:

/* Line 677 of lalr1.cc  */
#line 6344 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("check"); }
    break;

  case 930:

/* Line 677 of lalr1.cc  */
#line 6345 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("key"); }
    break;

  case 931:

/* Line 677 of lalr1.cc  */
#line 6346 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("foreach"); }
    break;

  case 932:

/* Line 677 of lalr1.cc  */
#line 6347 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("foreign"); }
    break;

  case 933:

/* Line 677 of lalr1.cc  */
#line 6348 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("keys"); }
    break;

  case 934:

/* Line 677 of lalr1.cc  */
#line 6349 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ancestor"); }
    break;

  case 935:

/* Line 677 of lalr1.cc  */
#line 6350 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("child"); }
    break;

  case 936:

/* Line 677 of lalr1.cc  */
#line 6351 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("descendant"); }
    break;

  case 937:

/* Line 677 of lalr1.cc  */
#line 6352 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("parent"); }
    break;

  case 938:

/* Line 677 of lalr1.cc  */
#line 6353 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("preceding"); }
    break;

  case 939:

/* Line 677 of lalr1.cc  */
#line 6354 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("self"); }
    break;

  case 940:

/* Line 677 of lalr1.cc  */
#line 6355 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("following"); }
    break;

  case 941:

/* Line 677 of lalr1.cc  */
#line 6356 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ancestor-or-self"); }
    break;

  case 942:

/* Line 677 of lalr1.cc  */
#line 6357 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("descendant-or-self"); }
    break;

  case 943:

/* Line 677 of lalr1.cc  */
#line 6358 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("following-sibling"); }
    break;

  case 944:

/* Line 677 of lalr1.cc  */
#line 6359 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("preceding-sibling"); }
    break;



/* Line 677 of lalr1.cc  */
#line 11358 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1331;
  const short int
  xquery_parser::yypact_[] =
  {
      1571, -1331, -1331, -1331, -1331, -1331,   264,   165, -1331, -1331,
     190, -1331, -1331, -1331, -1331,   243,   318,  9733,   348,    65,
     379,   394,    87, -1331,    24, -1331, -1331, -1331, -1331, -1331,
   -1331,   485, -1331,  7728, -1331, -1331,   421, -1331,   461, -1331,
   -1331,   495, -1331,   270, -1331,   466,   480, -1331,   260, -1331,
   -1331, -1331, -1331, -1331, -1331, -1331, -1331, -1331, -1331, -1331,
   -1331, -1331,   504,   517, -1331, -1331, -1331, -1331,  9163,  7146,
   -1331, -1331, -1331,   540, -1331, -1331, -1331, -1331, -1331,   546,
     558, -1331, -1331, 11158, -1331, -1331, -1331, -1331, -1331, -1331,
   -1331, -1331,   531, -1331, -1331,   563,   568, -1331, -1331, -1331,
   -1331, -1331, -1331, -1331,  2165, 11158, -1331, -1331, -1331, -1331,
   -1331, -1331, -1331,   542, -1331, -1331,   571,  8306, -1331,  8593,
     580,   581, -1331, -1331, -1331, 11158,   585, -1331,  6853, -1331,
   -1331, -1331, -1331, -1331, -1331,   555, -1331, -1331, -1331, -1331,
   -1331, -1331, -1331, -1331,    41,   497, -1331, -1331, -1331, -1331,
   -1331, -1331, -1331, -1331,   159,   554,   405, -1331,   488,   -83,
   -1331, -1331, -1331, -1331, -1331, -1331,   596, -1331,   565,   474,
     482,   484, -1331, -1331,   572,   569, -1331,   602, -1331, -1331,
   -1331, -1331, -1331, -1331, -1331, -1331, -1331, -1331, -1331, -1331,
   -1331, -1331, -1331, -1331, -1331, -1331, -1331, -1331, -1331, -1331,
   -1331, -1331, -1331, -1331, -1331, -1331, -1331, -1331, -1331, -1331,
   -1331, -1331, -1331, -1331, -1331, -1331, -1331, -1331, -1331, -1331,
   -1331, -1331, -1331, -1331, -1331, -1331, -1331, -1331, -1331, -1331,
   -1331, -1331, -1331, -1331, -1331, -1331, -1331, -1331,  1872,   722,
   -1331,   721,  5095, -1331, -1331,   249,  5388,   544,   550, -1331,
   -1331, -1331, -1331, -1331, -1331, -1331, -1331, -1331, -1331, -1331,
   -1331, -1331, -1331, -1331, -1331, -1331, -1331, -1331, -1331, -1331,
   -1331, -1331, -1331, -1331, -1331, -1331, -1331, -1331, -1331, -1331,
     -16, -1331, -1331, -1331, -1331,   146, 11158, -1331, -1331, -1331,
   -1331, -1331, -1331,   575,   642, -1331,   829,   493,   -30,   234,
     391,   121, -1331,   687,   545,   643,   644,  5681, -1331, -1331,
   -1331,   191, -1331, -1331,  6853, -1331,   456, -1331,   592,  7146,
   -1331,   592,  7146, -1331, -1331, -1331,   479, -1331, -1331, -1331,
   -1331, -1331, -1331, -1331, -1331, -1331, -1331, -1331, -1331, -1331,
   -1331, -1331, -1331, -1331, -1331, -1331, -1331, -1331, -1331, -1331,
   -1331, -1331, -1331, -1331, -1331, -1331, -1331, -1331, -1331, -1331,
   -1331, -1331, -1331, -1331, -1331, -1331, -1331, -1331, -1331, -1331,
     429, -1331,   720,   103,   350,   224,    78, 11158,    78, 11158,
     269,   701,   702,   704, 11158,   601,   635,   321,  8306, -1331,
   -1331,   376,   211,   508, 11158, -1331, -1331, -1331, -1331, -1331,
     462, 11158,   458,   460,   352,   457,   505, -1331, -1331, -1331,
   -1331, -1331,  8306,  5388,   577,  5388,    28, -1331, -1331, -1331,
   -1331, -1331, -1331, -1331, -1331, -1331, -1331, -1331, -1331, -1331,
   -1331, -1331, -1331, -1331, -1331, -1331, -1331, -1331, -1331, -1331,
   -1331, -1331, -1331, -1331, -1331, -1331, -1331,  5388, 10018, -1331,
   -1331, -1331, -1331, -1331, -1331, -1331, -1331, -1331, -1331, -1331,
   -1331, -1331, -1331, -1331, -1331, -1331, -1331, -1331, -1331,   608,
    5388,   486,   487, -1331,   645,     0,   612,  5388,    59,    50,
   11158,   648, -1331,  5388,  8017,   617, -1331, 11158, 11158, 11158,
    5388,   587,  5388,  5388, 11158,  5388,   623,   624, -1331, -1331,
   -1331,  5388, 10303,   626,   627,   629,   630,   631,   632, -1331,
   -1331, -1331, -1331, -1331, -1331, 11158, -1331, -1331, -1331,   594,
     747,  5388, -1331,    57, -1331,   766, -1331, -1331,   605, -1331,
   -1331,  5388,   591, -1331,   770,  5388,  5388,   619,  5388,  5388,
    5388,  5388,   576, 11158, -1331, -1331, -1331, -1331,  5388,  5388,
    5388, 11158, -1331,   721, -1331, -1331, -1331, -1331,   264,    87,
   -1331, -1331,   249,   773,  5388, -1331,  5388,   690,    65,    24,
     485,   653,   657,   658,  5388,  5388, -1331, -1331, -1331, -1331,
   -1331, -1331, -1331,   725, -1331,   -14,  5974,  5974,  5974, -1331,
    5974,  5974, -1331,  5974, -1331,  5974, -1331, -1331, -1331, -1331,
   -1331, -1331, -1331,  5974,  5974,   756,  5974,  5974,  5974,  5974,
    5974,  5974,  5974,  5974,  5974,  5974,  5974,   599,   738,   739,
     740, -1331, -1331, -1331,  2458, -1331, -1331,  6853,  6853,  5388,
     592, -1331, -1331,   592, -1331,  2751,   592,   688,  3044, -1331,
   -1331, -1331, -1331, -1331, -1331,   730,   731, -1331,   379, -1331,
     812, -1331, -1331, 11158, -1331, 11158,   789,    39, 11158,   470,
     681,   683,   789,   720,   717,   714, -1331, -1331, -1331, -1331,
   -1331,   -12,   600,   -25, -1331,   552, -1331, -1331, -1331, -1331,
   11158, 11158, 11158, -1331,   718,   666, -1331,   672,   629,   421,
   -1331,   670,   671,   675, -1331,    -8,    -3,  3337,   676, -1331,
   -1331, 11158,    -6, 11158,   767,    -1, -1331,  5388, -1331,   678,
    8306,   764,   820,  8306,   720,   768,   759, -1331,   -31, -1331,
     685,   698, -1331,   705,  3630,   709,   727,   -29, -1331,   189,
     716, -1331,   715,   723,   749, -1331,   724,  5388,  5388,   728,
   -1331,     4,    14,  3923,    -5, -1331, 11158,   747, -1331,   -36,
     729, -1331, -1331, -1331, -1331,   732, -1331,   -27, -1331, -1331,
   -1331,   132,   198,   804,   667,   689,    -2, -1331,   761,  6267,
   -1331,   733,   734,    63, -1331, -1331, -1331,   726, -1331,   528,
   -1331, -1331,   -11, 11158,   736,  5388,   791, -1331, -1331,   794,
   10588,   799,  5388,   801,   -70,   774,   -22,   642, -1331, -1331,
   -1331, -1331, -1331,  5974, -1331, -1331, -1331,    13,   234,   234,
     237,   391,   391,   391,   391,   121,   121, -1331, -1331, 10588,
   10588, 11158, 11158, -1331,   741, -1331, -1331,   742, -1331, -1331,
   -1331,    15, -1331, -1331,    83,   325,   344,   361, -1331,   379,
     379, -1331, -1331, -1331, -1331, -1331, -1331, -1331, -1331, -1331,
   -1331,   789, -1331,   790, 10873,   781,  5388, -1331, -1331, -1331,
     831,   783,  5388,   720,   720,   789, -1331,   536,   720,   339,
   11158,  -124,   315,   900, -1331, -1331,   646,    16, -1331, -1331,
   -1331, -1331, -1331, -1331, -1331, -1331, -1331, -1331, -1331,   -12,
     356,   374, -1331,   703,   293,   -21,   634,   720, -1331, -1331,
   -1331, -1331,   782, 11158, -1331, 11158, -1331, -1331,   753, -1331,
     200,   684, -1331, -1331,   468,    -6,   831, 10588,   819,   844,
     758,   746,   813,   720,   786,   815,   850,   720,   830,  5388,
     809,   -40,   800, -1331, -1331, -1331,   769, -1331,  5388,   835,
    5388,  5388,   808, -1331,   855,   858,  5388, -1331,   777,   779,
     810, 11158, -1331, 11158, -1331, -1331,   785,  5388,   929, -1331,
     203, -1331,    52, -1331, -1331,   937, -1331,   411,  5388,  5388,
    5388,   426,  5388,  5388,  5388,  5388,  5388,  5388,   847,  5388,
    5388,   635,   -10,   788,   565,   735,   821,   854,   773,   894,
   -1331, -1331,  5388,   398,   869, -1331, 11158,   870, -1331, 11158,
     823,   826, 10873,   827, -1331,   267, -1331, -1331, -1331, -1331,
   -1331, -1331, -1331, 11158, -1331, 11158,  5388,   838,  5388,  5388,
      -9,   841, -1331,  5388,    13,   416,   205, -1331,   706,    34,
     737,   744, -1331, -1331,   508, -1331,   743,   268, -1331, -1331,
   -1331,   845, -1331, -1331, -1331,  5388, -1331, -1331, -1331, -1331,
   -1331, -1331, -1331,  5388, -1331,   371,   396, -1331,   966,   478,
   -1331, -1331, -1331,  5388, -1331, -1331, -1331, -1331, -1331, -1331,
   -1331,   708, -1331, -1331,   969, -1331, -1331, -1331, -1331, -1331,
     284,   970, -1331,   459, -1331, -1331, -1331,   627,   318,   630,
     631,   632,   554,   762,   267,   775,   776,  6560,   712,   694,
     356, -1331,   787,   818,  4216,   833,   834,   865,   836,   837,
   -1331,  5388,   866, -1331,   893,   896,  5388, 11158,   549,   938,
   -1331, -1331, -1331, -1331, -1331, -1331, 10588, -1331,  5388,   720,
     908, -1331, -1331, -1331,   720,   908, 11158, -1331,  5388,  5388,
     879,  4509, -1331, -1331, 11158, -1331, -1331,  5388,  5388,    35,
   -1331,   -20,  9448,   409, -1331,   842, -1331, -1331,  4802,   840,
     851, -1331, -1331, -1331,   895, -1331,    69, -1331, -1331,  1014,
   -1331, -1331, 11158, -1331, -1331,   502, -1331, -1331, -1331,   848,
     797,   806, -1331, -1331, -1331,   807,   811, -1331, -1331, -1331,
   -1331, -1331,   805, 11158,   860, -1331,   901, -1331,   635, -1331,
   -1331, -1331,  7439,   735, -1331,  5388, 11158,   869, -1331,   720,
   -1331,   548, -1331,   307,   939, -1331,  5388,   940,   791, -1331,
    8878,   862,   863,   864, -1331, -1331, -1331, -1331, -1331, -1331,
   -1331,  5388, -1331, -1331,  5388,   906,  5388,   871,   872, -1331,
      13,   814, -1331, -1331,    66, -1331,  -128,    22,   816,    13,
    -128,  5974, -1331,    55, -1331, -1331, -1331, -1331, -1331, -1331,
      13,   909,   780,   600,    22, -1331, -1331,   772,   977, -1331,
   -1331, -1331, -1331, -1331,   881, -1331, -1331, -1331,  5388, -1331,
   -1331, -1331, -1331, -1331,  1034,   -48,  1038,   -48,   796,   971,
   -1331, -1331, -1331, -1331,   903, 11158,   817,   762,  6560, -1331,
   -1331,   887, -1331, -1331, -1331, -1331, -1331, -1331,  5388, 11158,
   11158, -1331,   443, -1331,  5388, -1331,   945,   976,   720,   908,
   -1331, -1331, -1331,  5388, -1331,   897, -1331, -1331, -1331,   891,
   -1331,  5388,  5388, 11158,   892,   223, -1331, -1331, -1331,   898,
   -1331, -1331,   929, 11158,   566, -1331,   929, 11158, -1331, -1331,
    5388,  5388,  5388,  5388,  5388, -1331,  5388,  5388, -1331, -1331,
     290, -1331,   899, -1331, -1331, -1331, -1331,   939, -1331, -1331,
   -1331,   720, -1331, -1331,   982,   902, -1331,    88, -1331, -1331,
   -1331, -1331, -1331,  5388, -1331, -1331, -1331, -1331,   904,  5974,
   -1331, -1331, -1331, -1331, -1331,    30,  5974,  5974,   301, -1331,
     737, -1331,   160, -1331,   744,    13,   926, -1331, -1331,   802,
   -1331, -1331, -1331, -1331, -1331,   -13, -1331,     1,     1, -1331,
     -48, -1331, -1331,   130, -1331,  1056,    22,   905,   978, -1331,
    6560,   -64,   822, -1331,   915, -1331, -1331, -1331,  1035, -1331,
   -1331,  5388,   720, -1331, -1331, -1331,  5388, -1331, -1331,   994,
    5388, 11158,  5388, -1331,   -15,   929, 11158,   907,   929, -1331,
   -1331, -1331, -1331, -1331, -1331, -1331,   973,  7439, -1331, -1331,
   -1331, -1331, 10588, -1331, 10588,   997, -1331, -1331,   391,  5974,
    5974,   237,   261, -1331, -1331, -1331, -1331, -1331, -1331,  5388,
   -1331, -1331, -1331, -1331, -1331,  1066, -1331, -1331, -1331,   832,
   -1331,   971,   987, -1331,  1000, 11158,   980,   875, 11158,  6560,
     983, -1331,   908, -1331, 10588, -1331,   912, -1331,   201,    74,
   -1331,   910,   929, -1331,   911, 11158, -1331, -1331, -1331, 10588,
     237,   237,  5974,   918, -1331, -1331, -1331,  6560, 11158,   798,
   11158,   986,   884,   987, 11158,   927,  5388, -1331, -1331,  1016,
     343, -1331, -1331, -1331, -1331,   931,   333, -1331, -1331, -1331,
     919, -1331,   185, -1331,   237, -1331, -1331,   939,  5388,   824,
   11158,   995, -1331,  5388, -1331, -1331, -1331, -1331, -1331, -1331,
   -1331, -1331,  1001,   963, -1331, -1331,   825,   828, 11158, -1331,
   11158, -1331,   839,  5388,   843,   187,  6560, -1331,  6560,  1002,
     963, -1331,   924, 11158, -1331,   849,   942, 11158,   963,   913,
   -1331,  1004, 11158,   846,  6560, -1331
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
         0,     8,   416,   417,   729,   570,   835,   844,   749,   747,
     734,   836,   839,   792,   885,   753,   735,   736,   898,   784,
     845,   738,   842,   814,   794,   769,   789,   886,   790,   840,
     837,   785,   788,   740,   843,   741,   742,   883,   900,   882,
     786,   805,   799,   743,   787,   745,   744,   884,   823,   791,
     766,   910,   911,   912,   913,   914,   915,   916,   917,   918,
     919,   920,   934,   941,   813,   809,   800,   780,   733,     0,
     808,   816,   824,   935,   804,   436,   781,   782,   838,   936,
     942,   801,   818,     0,   442,   405,   438,   811,   732,   802,
     803,   831,   806,   822,   830,   940,   943,   752,   793,   833,
     437,   821,   826,   737,     0,     0,   354,   819,   829,   834,
     832,   812,   798,   887,   796,   797,   937,     0,   353,     0,
     938,   944,   827,   783,   807,     0,   939,   383,     0,   415,
     828,   810,   817,   825,   820,   888,   774,   779,   778,   777,
     776,   775,   746,   795,     0,   731,   841,   767,   874,   873,
     875,   751,   750,   770,   880,   739,   872,   877,   878,   869,
     773,   815,   871,   881,   879,   870,   771,   876,   890,   894,
     895,   891,   892,   889,   893,   896,   897,   899,   861,   860,
     847,   765,   758,   854,   850,   768,   764,   863,   864,   754,
     755,   748,   757,   859,   858,   855,   851,   868,   862,   857,
     853,   846,   756,   867,   866,   760,   762,   761,   852,   856,
     848,   763,   849,   759,   865,   921,   922,   923,   924,   925,
     926,   902,   903,   901,   907,   908,   909,   904,   905,   906,
     772,   927,   928,   929,   930,   931,   932,   933,     0,     0,
       4,     2,     0,     9,    11,    17,     0,     0,     0,    23,
      25,    34,    27,    28,    29,    55,    30,    39,    35,    59,
      60,    61,    56,    57,    63,    64,    33,    31,    32,    37,
      38,    58,   206,   205,   202,   203,   204,    36,    16,   182,
     183,   187,   189,   221,   227,     0,     0,   219,   220,   190,
     191,   192,   193,   194,   309,   311,   313,   323,   327,   329,
     332,   337,   340,   343,   345,   347,   349,     0,   351,   357,
     359,     0,   375,   358,   379,   382,   384,   387,   389,     0,
     394,   391,     0,   402,   412,   414,   388,   418,   425,   434,
     426,   427,   428,   431,   432,   429,   430,   449,   451,   452,
     453,   450,   498,   499,   500,   501,   502,   503,   411,   544,
     536,   543,   542,   541,   538,   540,   537,   539,   435,   433,
     571,   572,    62,   195,   196,   198,   197,   199,   200,   201,
     413,   730,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   112,
     113,     0,     0,     0,     0,   108,   109,   110,   111,   118,
       0,     0,     0,     0,     0,     0,     0,   106,   163,   166,
     169,   168,     0,     0,     0,     0,     0,   835,   844,   734,
     753,   735,   736,   898,   784,   845,   738,   842,   794,   785,
     740,   742,   900,   805,   743,   745,   744,   823,   934,   941,
     733,   935,   936,   942,   806,   940,   943,     0,     0,   887,
     937,   938,   944,   939,   888,   731,   880,   739,   872,   878,
     869,   771,   890,   894,   895,   891,   893,   896,   899,     0,
       0,     0,     0,   229,     0,     0,     0,     0,     0,     0,
       0,     0,   613,     0,     0,     0,   614,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   407,   410,
     397,     0,     0,     0,   734,   736,   740,   743,   733,   403,
     413,   395,   396,   399,   439,     0,   401,   400,   440,     0,
     465,     0,   406,     0,   378,     0,   409,   408,     0,   398,
     381,     0,     0,   494,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   153,   150,   161,   162,     0,     0,
       0,     0,     6,     3,     1,     5,    10,    12,     0,     0,
      18,    15,    20,    21,     0,   185,   184,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   207,   226,   222,   228,
     223,   225,   224,   231,   232,     0,     0,     0,     0,   368,
       0,     0,   366,     0,   318,     0,   367,   360,   365,   364,
     363,   362,   361,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   356,   355,   352,     0,   376,   380,     0,     0,     0,
     390,   422,   393,   392,   404,     0,   419,     0,     0,   612,
      81,    66,    67,   144,   145,     0,     0,   165,     0,   164,
       0,    72,    73,     0,   167,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   581,   582,   583,   115,
     114,     0,    71,   122,   119,     0,   121,   120,   117,   116,
       0,     0,     0,   107,     0,     0,   550,     0,     0,     0,
     546,     0,     0,     0,   560,     0,     0,     0,     0,   209,
     210,     0,     0,     0,   146,     0,   176,     0,   574,     0,
       0,    90,     0,     0,     0,    82,   244,   245,     0,   230,
       0,     0,   551,     0,     0,     0,     0,     0,   292,     0,
       0,   549,     0,     0,     0,   568,     0,     0,     0,     0,
     554,     0,     0,     0,     0,   441,   466,   465,   462,     0,
       0,   496,   495,   377,   559,     0,   493,     0,   594,   595,
     545,     0,     0,     0,     0,     0,     0,   600,     0,     0,
     159,     0,     0,     0,   247,   264,     7,     0,    24,     0,
      26,   188,     0,     0,     0,     0,     0,   208,   265,     0,
       0,     0,     0,     0,     0,     0,     0,   310,   312,   316,
     322,   321,   320,     0,   317,   314,   315,     0,   331,   330,
     328,   334,   335,   336,   333,   338,   339,   342,   341,     0,
       0,     0,     0,   373,     0,   385,   386,     0,   423,   420,
     447,     0,   573,   445,     0,     0,     0,     0,    70,     0,
       0,    45,    47,    48,    49,    50,    52,    53,    54,    46,
      51,    41,    42,     0,     0,    98,     0,    94,    96,    97,
     101,   104,     0,     0,     0,    40,    80,     0,     0,     0,
       0,     0,     0,     0,   679,   684,     0,     0,   680,   714,
     667,   669,   670,   671,   673,   675,   674,   672,   676,     0,
       0,     0,   123,     0,     0,   126,     0,     0,   514,   504,
     547,   548,     0,     0,   564,     0,   561,   505,     0,   616,
       0,     0,   211,   212,     0,   217,   178,     0,     0,   147,
       0,     0,     0,     0,     0,     0,    83,     0,     0,     0,
       0,     0,     0,   553,   552,   515,     0,   567,     0,     0,
       0,     0,     0,   513,     0,     0,     0,   369,     0,     0,
       0,     0,   557,     0,   555,   509,     0,     0,   465,   463,
       0,   454,     0,   443,   444,     0,    13,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   835,     0,     0,     0,     0,     0,     0,    22,     0,
     186,   218,     0,   276,   272,   274,     0,   266,   267,     0,
     845,   737,     0,   746,   521,   522,   528,   529,   531,   575,
     576,   532,   535,     0,   234,     0,     0,     0,     0,     0,
       0,     0,   319,     0,     0,     0,     0,   645,   325,   618,
     622,   624,   626,   628,   631,   638,   639,   647,   344,   346,
     348,   519,   350,   374,   424,     0,   421,   446,    78,    79,
      76,    77,   171,     0,   170,     0,     0,    43,     0,     0,
      99,   100,   102,     0,   103,    68,    69,    74,    75,    65,
     685,     0,   688,   715,     0,   678,   677,   682,   681,   713,
       0,     0,   690,     0,   686,   689,   668,     0,     0,     0,
       0,     0,     0,   124,   130,     0,     0,     0,     0,     0,
       0,   127,     0,     0,     0,     0,     0,   568,     0,     0,
     506,     0,     0,   213,     0,     0,     0,     0,   258,     0,
     255,   260,   216,   179,   148,   177,     0,   180,     0,     0,
      92,    86,    89,    88,     0,    84,     0,   249,     0,     0,
       0,     0,   516,   158,     0,   290,   294,     0,     0,     0,
     297,     0,     0,     0,   304,     0,   371,   370,     0,     0,
       0,   510,   291,   466,     0,   455,     0,   489,   486,     0,
     490,   491,     0,   492,   485,     0,   460,   488,   487,     0,
       0,     0,   587,   588,   584,     0,     0,   592,   593,   589,
     598,   596,     0,     0,     0,   602,   156,   155,     0,   152,
     151,   160,     0,   603,   604,     0,     0,   273,   285,     0,
     286,     0,   277,   278,   279,   280,     0,   269,     0,   233,
       0,     0,     0,     0,   525,   527,   526,   523,   242,   243,
     236,     0,   238,   235,     0,     0,     0,     0,     0,   629,
     642,     0,   324,   326,     0,   661,     0,     0,     0,     0,
       0,     0,   617,   619,   620,   656,   657,   658,   660,   659,
       0,     0,   633,   632,     0,   636,   640,   654,   652,   651,
     644,   648,   520,   448,     0,   173,   172,   175,     0,    44,
      95,   105,   702,   683,     0,   707,     0,   707,   696,   691,
     125,   131,   133,   132,     0,     0,     0,   128,     0,    19,
     507,     0,   565,   566,   569,   562,   563,   253,     0,     0,
       0,   215,   256,   259,     0,   149,     0,    91,     0,    85,
     246,   251,   250,     0,   517,     0,   293,   295,   300,     0,
     298,     0,     0,     0,     0,     0,   305,   372,   511,     0,
     558,   556,   465,     0,     0,   497,   465,     0,   461,    14,
       0,     0,     0,     0,     0,   601,     0,     0,   154,   610,
       0,   605,     0,   248,   289,   287,   288,   281,   282,   283,
     275,     0,   270,   268,     0,     0,   533,     0,   530,   580,
     524,   240,   237,     0,   239,   646,   637,   643,     0,     0,
     716,   717,   727,   726,   725,     0,     0,     0,     0,   718,
     623,   724,     0,   621,   625,     0,     0,   630,   634,     0,
     655,   650,   653,   649,   181,     0,   703,     0,     0,   701,
     708,   709,   705,     0,   700,     0,   698,     0,   692,   693,
       0,     0,     0,   129,     0,   508,   254,   262,   263,   257,
     214,     0,     0,    87,   252,   518,     0,   301,   299,     0,
       0,     0,     0,   512,     0,   465,     0,     0,   465,   585,
     586,   590,   591,   597,   599,   157,     0,     0,   606,   615,
     284,   271,     0,   577,     0,     0,   241,   641,   728,     0,
       0,   720,     0,   666,   665,   664,   663,   662,   627,     0,
     719,   174,   712,   711,   710,     0,   704,   697,   695,     0,
     687,     0,   134,   136,     0,     0,     0,     0,     0,     0,
       0,   308,    93,   296,     0,   306,     0,   302,   475,   469,
     464,     0,   465,   456,     0,     0,   611,   578,   534,     0,
     722,   721,     0,     0,   706,   699,   694,     0,     0,     0,
       0,     0,     0,   135,     0,     0,     0,   483,   477,     0,
     476,   478,   484,   481,   471,     0,   470,   472,   482,   458,
       0,   457,     0,   579,   723,   635,   137,   138,     0,     0,
       0,     0,   261,     0,   303,   468,   479,   480,   467,   473,
     474,   459,     0,     0,   139,   140,     0,     0,     0,   307,
       0,   607,     0,     0,     0,     0,     0,   142,     0,     0,
       0,   141,     0,     0,   608,     0,     0,     0,     0,     0,
     609,     0,     0,     0,     0,   143
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1331, -1331,  -213,   878, -1331,   876,   882, -1331,   880, -1331,
     561,   570,  -546, -1331,   455,  -284, -1331, -1331, -1331, -1331,
   -1331, -1331, -1331, -1331, -1331, -1331, -1331, -1331, -1331, -1331,
    -913, -1331, -1331, -1331, -1331,    72,   273,   748, -1331, -1331,
     745, -1331,    33,  -880, -1331,  -372,  -397, -1331, -1331,  -611,
   -1331,  -861, -1331, -1331,   -55, -1331, -1331, -1331, -1331, -1331,
     277,   765, -1331, -1331, -1331,   226,   673, -1330,   914,   -94,
   -1331,  -555,   -95, -1331, -1331, -1331, -1331,   231, -1331, -1331,
     867, -1331, -1331, -1331, -1331, -1331,   149,  -545,  -689, -1331,
   -1331, -1331,    17, -1331, -1331,  -162,    36,   -50, -1331, -1331,
   -1331,   -61, -1331, -1331,   166,   -57, -1331, -1331,   -52, -1187,
   -1331,   647,    19, -1331, -1331,    18, -1331, -1331, -1331,    11,
   -1331, -1331,   579,   582, -1331,  -549, -1331, -1331,  -590,    64,
    -605,    60,    76, -1331, -1331, -1331, -1331, -1331,   859, -1331,
   -1331, -1331, -1331,  -785,  -309, -1076, -1331,  -115, -1331, -1331,
   -1331, -1331, -1331, -1331, -1331,   -38, -1170, -1331, -1331,   295,
      -7, -1331,  -757, -1331, -1331, -1331, -1331, -1331, -1331, -1331,
     530, -1331,  -942, -1331,     5, -1331,   423,  -746, -1331, -1331,
   -1331, -1331, -1331,  -384,  -377, -1117,  -963, -1331, -1331, -1331,
   -1331, -1331, -1331, -1331, -1331, -1331, -1331,   353,  -673,  -796,
      80,  -795, -1331,  -813,  -771, -1331, -1331, -1331, -1331, -1331,
   -1331, -1331,   763,   771,  -539,   272,   120, -1331, -1331, -1331,
   -1331, -1331, -1331, -1331, -1331, -1331, -1331, -1331, -1331, -1331,
   -1331,     2, -1331, -1331,   -23, -1331,  -369,  -105, -1331,  -990,
   -1331, -1331, -1331,   -68,   -78,  -222,   161, -1331, -1331, -1331,
   -1331, -1331, -1331, -1331, -1331, -1331, -1331, -1331, -1331, -1331,
     -69, -1331, -1331, -1331,  -214,   156,   302, -1331, -1331, -1331,
   -1331, -1331,   109, -1331, -1331, -1253, -1331, -1331, -1331,  -738,
   -1331,   -93, -1331,  -227, -1331, -1331, -1331, -1331, -1211, -1331,
     -54, -1331,   -17, -1331
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   851,   852,   853,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
    1130,   714,   265,   266,   857,   858,   859,  1196,   267,   406,
     407,   268,  1093,   892,   269,  1502,  1503,   270,   271,   476,
     272,   545,   769,   982,  1197,   273,   274,   275,   276,   277,
     408,   409,   410,   411,   705,   706,  1173,  1054,   278,   279,
     566,   280,   281,   282,   576,   474,   914,   915,   283,   577,
     284,   579,   285,   286,   287,   583,   584,  1118,   795,   288,
     716,   773,   717,   702,  1119,  1120,  1121,   774,   580,   581,
     997,   998,  1372,   582,   994,   995,  1212,  1213,  1214,  1215,
     289,   727,   728,   290,  1149,  1150,  1151,   291,  1153,  1154,
     292,   293,   294,   295,   803,   296,  1242,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   603,
     604,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   322,   323,   324,   325,   326,   630,
     631,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     831,   336,   337,   338,  1175,   747,   748,   749,  1520,  1555,
    1556,  1549,  1550,  1557,  1551,  1176,  1177,   339,   340,  1178,
     341,   342,   343,   344,   345,   346,   347,  1040,   796,  1004,
    1227,  1005,  1377,  1006,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   734,  1106,   358,   359,   360,   361,
    1008,  1009,  1010,  1011,   362,   363,   364,   365,   366,   367,
     766,   767,   368,  1203,  1204,  1360,  1131,   485,   369,  1028,
    1252,  1253,  1029,  1030,  1031,  1032,  1033,  1262,  1407,  1408,
    1034,  1265,  1035,  1388,  1036,  1037,  1270,  1271,  1413,  1411,
    1254,  1255,  1256,  1257,  1486,   672,   880,   881,   882,   883,
     884,   885,  1084,  1427,  1428,  1085,  1426,  1498,   886,  1287,
    1423,  1419,  1420,  1421,   887,   888,  1258,  1266,  1398,  1259,
    1394,  1243,   370,   371
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       469,   960,   625,   640,   811,   812,   813,   814,  1041,  1041,
     519,   782,   523,   530,  1135,  1101,   486,   780,   810,  1007,
    1174,  1294,  1026,  1038,  1039,   552,  1368,  1369,   555,   930,
    1468,   509,  1359,     5,  1238,   869,  1429,   837,   870,   799,
     794,   800,   801,   911,   802,   931,   804,  1505,  1007,  1007,
    1027,   503,   510,  1409,   805,   806,   942,   790,  1348,  1059,
    1167,  1168,   532,   890,   751,   688,   514,  1100,   791,  1016,
     639,   939,  1518,  1331,   790,  1479,   791,  1167,  1168,   639,
    1417,   871,  1167,  1007,   564,   689,   961,   564,   520,   564,
    1198,  1284,   903,  1553,  1139,   939,   965,   905,   978,   918,
     486,   986,   525,   929,   951,  1017,  1081,  1021,   528,   711,
     715,   703,  1395,   478,   953,  1045,    75,  1019,   377,  1094,
     606,  1124,  1082,  1201,  1244,   792,   471,   854,  1148,    86,
    1234,   472,  1075,  1392,   541,   480,   381,   607,   382,   542,
    1393,  1329,   479,  1076,  1418,  1244,  1007,   383,  1169,  1286,
     940,  1480,   962,  1506,   100,   966,   712,  1332,  1023,  1519,
     608,  1024,  1491,   987,  1083,  1169,   565,  1170,   855,  1171,
     904,   990,  1199,   856,   957,   906,   473,   919,   704,   567,
    1470,   119,   952,  1045,  1170,   568,  1171,  1062,  1474,  1170,
     569,  1171,   954,  1046,  1276,  1245,   793,   707,   570,   626,
    1554,   105,   713,   912,   891,  1547,   690,  1222,   891,  1167,
     571,   710,  1164,  1290,   707,  1499,  1245,   117,   105,   707,
     967,  1319,  1434,   752,  1174,   979,   793,  1348,  1055,  1056,
    1495,  1007,   872,  1174,   117,   793,  1507,  1112,  1172,  1026,
    1026,   913,  1140,  1123,   793,   873,   533,   874,  1536,   615,
    1387,  1020,   793,  1591,  1022,  1343,   144,   793,   875,   876,
     877,  1047,   878,   616,   879,  1025,  1475,  1027,  1027,   585,
    1604,  1396,  1397,   144,   558,  1390,   641,   790,  1610,  1246,
    1247,   632,  1248,   665,   634,  1582,   971,  1599,   790,  1249,
     642,   559,   372,   373,   866,   374,   375,  1526,   376,  1250,
    1246,  1247,   510,  1248,   377,   510,   572,   684,  1496,   573,
     606,  1251,   378,  1391,   379,   380,  1170,   412,  1171,   685,
    1250,   687,   381,   574,   382,  1165,  1548,   607,   941,  1094,
    1315,  1235,  1251,   383,  1451,   413,   624,   384,   414,  1111,
     776,  1167,   968,   969,   609,   926,   707,  1547,   494,   575,
    1240,  1167,  1553,   693,  1504,  1007,  1334,   970,   660,   119,
     648,   661,   650,  1583,  1105,  1600,  1108,   656,   385,   386,
     387,   486,   610,   119,  1284,   698,   535,   673,   536,   723,
    1584,  1007,   645,   709,   675,   611,  1087,   606,   415,   720,
    1285,  1166,  1088,   688,   662,   486,   730,   646,   732,   733,
    1452,   736,  1174,  1224,   607,   495,  1209,   739,   972,   973,
    1089,   606,  1159,   689,  1160,   490,   388,  1433,   491,   612,
     663,  1090,  1483,   974,  1376,   389,  1211,   750,   607,  1484,
     651,   696,  1286,  1504,  1225,  1053,     5,   755,  1466,  1485,
     758,   759,   780,   761,   762,   763,   764,  1091,  1170,  1007,
    1171,  1532,  1226,   770,   771,  1026,   772,   390,  1170,  1579,
    1171,  1504,   652,   718,  1026,  1048,   416,   486,  1576,   781,
     725,   726,   729,   496,   497,  1026,   391,   735,   707,   787,
     788,   664,  1049,  1027,  1050,   742,   392,  1208,   707,  1114,
    1052,  1467,  1027,   470,  1065,  1066,  1115,  1209,   729,  1069,
    1275,  1051,  1152,  1027,   669,   670,  1053,  1210,  1267,  1268,
    1167,  1168,   825,   826,  1114,  1335,   544,  1211,   393,    75,
    1601,  1115,  1602,   643,   481,  1277,   768,   475,  1103,  1512,
     824,  1269,    86,   791,   775,   827,   125,   644,  1615,  1116,
     830,  1278,   477,   830,   394,   395,   396,   397,   398,  1081,
     399,   400,   401,   402,   403,  1552,  1558,   100,   791,   404,
     405,  1023,   376,  1483,  1024,  1082,   637,  1057,   377,   487,
    1484,  1077,   488,  1092,  1167,  1168,   378,   638,   379,  1117,
    1485,  1057,  1078,   613,   119,  1098,   381,  1552,   382,   666,
     667,   668,   614,  1558,  1099,  1114,  1454,   383,  1169,   861,
    1457,   384,  1115,   908,   862,   922,   489,   855,   925,  1070,
    1071,  1072,   856,   920,   492,  1073,   633,  1170,   498,  1171,
    1026,   636,   538,   828,   539,   629,   828,   635,   493,   828,
     936,   499,   385,   386,   989,  1180,   839,  1181,   840,   627,
     628,   860,   515,   948,   949,   678,   679,   707,  1027,   956,
    1185,   105,  1186,   647,   511,   649,  1067,  1068,  1095,  1096,
     512,  1402,  1169,   894,   895,   896,   389,   117,  1365,  1366,
     808,   809,   513,   815,   816,   983,  1527,   516,  1528,  1492,
    1493,  1170,   517,  1171,   910,   522,   916,   521,  1347,   389,
     993,   817,   818,   486,   526,   527,   486,  1014,   390,   529,
     531,  1007,   537,  1007,   534,   540,   144,   543,   546,  1521,
     544,   707,  1524,   551,   550,   105,   547,   625,  1545,   548,
     549,   390,   554,  1415,     1,  1567,   562,   392,   587,   958,
     617,   117,   563,  1563,   586,   605,   618,   619,   629,   620,
     639,   653,   377,  1007,   655,   657,   658,   671,   674,   676,
     392,   677,  1456,   697,   680,   686,   701,   707,  1007,   719,
    1317,  1061,   724,   699,   700,   731,   991,  1064,   737,   738,
     144,   743,   745,  1012,   746,   414,  1560,   448,   484,   491,
     502,   753,   393,   754,  1478,   681,   395,   396,   397,   398,
     757,   399,   400,   682,   402,   403,   756,   760,   779,   765,
     404,   783,  1012,  1012,  1012,  1012,  1481,  1482,   394,   395,
     396,   397,   398,   784,   399,   400,   401,   402,   403,   785,
     786,   807,   819,   404,   405,   789,   820,   821,   822,   832,
     835,   836,   838,   863,  1137,   864,   867,  1012,   868,   889,
    1364,   898,   897,  1143,   893,  1145,  1146,   899,   900,   901,
     902,   909,  1155,  1074,   923,   917,   921,   924,   927,   928,
     932,   938,  1162,   841,   842,   843,   844,   845,   846,   847,
     848,   849,   850,  1182,  1183,  1184,   933,  1187,  1188,  1189,
    1190,  1191,  1192,   934,  1194,  1195,  1107,   937,  1107,  1530,
    1531,   943,   975,   944,   946,   980,   976,   993,   992,   947,
    1012,   945,   996,   950,   963,   999,   977,   964,   988,   985,
    1013,   984,  1015,  1018,  1058,   856,  1043,  1063,  1044,   790,
    1079,  1230,  1097,  1232,  1233,  1080,  1102,  1104,  1110,  1237,
     703,  1113,  1126,  1127,   735,  1128,   735,  1129,  1132,  1133,
    1134,  1136,  1564,  1138,  1142,  1141,  1144,  1147,  1148,  1443,
    1273,  1152,  1156,   588,  1157,  1158,  1163,  1179,  1193,  1274,
    1161,   589,   590,  1200,   591,  1206,  1205,   662,  1281,  1216,
    1218,  1220,   592,  1202,  1221,  1223,   593,  1231,   594,  1217,
    1236,  1272,   585,   595,  1241,  1012,     5,  1282,  1260,  1283,
    1288,   891,  1295,  1296,  1292,  1293,  1228,  1261,  1229,   596,
    1299,  1304,  1471,  1264,  1309,  1308,  1298,  1310,  1318,  1314,
    1301,  1302,  1303,  1323,  1305,  1306,  1307,  1337,  1340,  1342,
    1345,  1311,  1350,   597,   598,   599,   600,   601,   602,  1341,
    1349,  1351,  1352,  1316,  1354,  1357,  1353,  1356,  1209,  1371,
    1378,  1379,  1380,  1321,  1322,  1383,  1385,  1325,  1405,  1412,
    1386,  1410,  1327,  1328,  1416,  1406,  1414,  1389,  1422,  1399,
    1425,  1081,  1435,  1441,  1339,  1430,  1442,  1432,  1446,  1450,
    1472,  1489,  1445,  1453,  1469,  1490,  1497,  1509,  1501,  1477,
    1473,  1510,  1514,  1500,  1525,  1529,  1534,  1537,  1538,  1546,
    1535,  1540,  1541,  1565,  1544,  1523,  1568,  1570,  1559,  1561,
    1312,  1571,  1508,  1575,  1573,  1578,  1588,  1581,  1053,  1012,
    1362,  1592,  1590,  1603,  1605,  1612,   553,   865,   556,   718,
    1608,   993,  1586,   777,   557,   560,  1593,   729,  1060,  1607,
    1611,  1280,   778,  1297,   659,  1012,  1381,  1543,  1596,  1382,
    1566,  1384,  1598,  1358,  1125,  1614,  1122,   654,  1219,   708,
    1439,   683,   578,  1320,  1313,  1346,  1363,  1373,  1207,  1370,
     561,  1367,   744,  1326,  1336,   797,   623,  1330,   834,   798,
     959,  1344,  1580,  1577,  1291,  1042,   768,  1109,  1279,   691,
    1361,  1400,  1404,  1488,  1403,   510,  1239,   692,  1487,   775,
    1263,  1086,  1289,  1494,  1424,  1355,  1401,     0,     0,     0,
       0,     0,     0,  1012,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1436,     0,     0,     0,     0,     0,  1440,
       0,     0,     0,     0,     0,     0,     0,     0,  1444,     0,
       0,     0,     0,     0,     0,     0,  1447,  1448,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1459,  1460,  1461,  1462,  1463,
       0,  1464,  1465,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1431,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1476,     0,
       0,     0,  1437,  1438,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1449,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1455,     0,     0,     0,
    1458,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1511,     0,     0,     0,
       0,  1513,     0,     0,     0,  1515,     0,  1517,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1533,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1516,     0,     0,     0,     0,  1522,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     510,  1574,     0,     0,     0,  1012,     0,  1012,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1585,     0,     0,     0,     0,  1589,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1539,     0,
       0,  1542,     0,     0,     0,     0,     0,  1012,  1597,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1562,     0,
       0,     0,  1012,     0,     0,     0,     0,     0,     0,     0,
       0,  1012,     0,  1569,     0,     0,     0,  1572,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1587,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1594,     0,  1595,     1,     0,     0,     0,     0,     0,
       0,     2,     0,     0,     0,     0,  1606,     0,     3,     4,
    1609,     5,     0,     0,     0,  1613,     6,     7,     0,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,     0,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,     0,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,     0,    65,
      66,    67,    68,    69,    70,    71,    72,     0,     0,    73,
      74,     0,     0,     0,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,     0,     0,    86,     0,    87,
      88,    89,    90,     0,    91,     0,     0,     0,    92,    93,
      94,    95,    96,     0,     0,     0,     0,     0,     0,    97,
      98,    99,   100,   101,   102,   103,     0,     0,     0,   104,
     105,   106,   107,   108,     0,     0,     0,     0,   109,   110,
     111,   112,   113,   114,   115,   116,   117,     0,   118,   119,
       0,     0,   120,   121,   122,     0,     0,     0,   123,     0,
     124,   125,   126,     0,   127,   128,   129,     0,   130,     0,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,     0,     0,   142,   143,   144,     0,   145,   146,     0,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,     0,   189,   190,   191,     0,   192,   193,   194,
     195,   196,   197,     0,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,     1,     0,     0,     0,     0,
       0,     0,     2,     0,     0,     0,     0,     0,     0,     3,
       4,     0,     5,     0,     0,     0,     0,     6,     7,     0,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,     0,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,     0,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,     0,
      65,    66,    67,    68,    69,    70,    71,    72,     0,     0,
      73,    74,     0,     0,     0,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,     0,     0,    86,     0,
      87,    88,    89,    90,     0,    91,     0,     0,     0,    92,
      93,    94,    95,    96,     0,     0,     0,     0,     0,     0,
      97,    98,    99,   100,   101,   102,   103,     0,     0,     0,
     104,   105,   106,   107,   108,     0,     0,     0,     0,   109,
     110,   111,   112,   113,   114,   115,   116,   117,     0,   118,
     119,     0,     0,   120,   121,   122,     0,     0,     0,   123,
       0,   124,   125,   126,     0,   127,   128,   129,     0,   130,
       0,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,     0,     0,   142,   143,   144,     0,   145,   146,
       0,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,     0,   189,   190,   191,     0,   192,   193,
     194,   195,   196,   197,     0,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,     2,     0,     0,     0,     0,
       0,     0,     3,     4,     0,     5,     0,     0,     0,     0,
     417,   418,     0,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,   427,    23,    24,
      25,    26,     0,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,     0,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,     0,    65,    66,    67,    68,    69,    70,    71,
      72,     0,     0,    73,    74,     0,     0,     0,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,     0,
       0,    86,     0,    87,    88,    89,    90,     0,    91,     0,
       0,     0,    92,    93,    94,    95,    96,     0,     0,     0,
       0,     0,     0,    97,    98,    99,   100,   101,   102,   103,
       0,     0,     0,   104,   105,   106,   107,   108,     0,     0,
       0,     0,   109,   110,   111,   112,   113,   114,   115,   116,
     117,     0,   118,   119,     0,     0,   120,   121,   122,     0,
       0,     0,   123,   518,   124,   125,   126,     0,   127,   128,
     129,     0,   130,     0,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,     0,     0,   142,   143,   144,
       0,   455,   146,     0,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,     0,   189,   190,   191,
       0,   192,   193,   194,   195,   196,   197,     0,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,     2,     0,
       0,     0,     0,     0,     0,     3,     4,     0,     5,     0,
       0,     0,     0,   417,   418,     0,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
     427,    23,    24,    25,    26,     0,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,     0,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,     0,    65,    66,    67,    68,
      69,    70,    71,    72,     0,     0,    73,    74,     0,     0,
       0,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,     0,     0,    86,     0,    87,    88,    89,    90,
       0,    91,     0,     0,     0,    92,    93,    94,    95,    96,
       0,     0,     0,     0,     0,     0,    97,    98,    99,   100,
     101,   102,   103,     0,     0,     0,   104,   105,   106,   107,
     108,     0,     0,     0,     0,   109,   110,   111,   112,   113,
     114,   115,   116,   117,     0,   118,   119,     0,     0,   120,
     121,   122,     0,   823,     0,   123,     0,   124,   125,   126,
       0,   127,   128,   129,     0,   130,     0,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,     0,     0,
     142,   143,   144,     0,   455,   146,     0,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,     0,
     189,   190,   191,     0,   192,   193,   194,   195,   196,   197,
       0,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,     2,     0,     0,     0,     0,     0,     0,     3,     4,
       0,     5,     0,     0,     0,     0,   417,   418,     0,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,   427,    23,    24,    25,    26,     0,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,     0,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,     0,    65,
      66,    67,    68,    69,    70,    71,    72,     0,     0,    73,
      74,     0,     0,     0,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,     0,     0,    86,     0,    87,
      88,    89,    90,     0,    91,     0,     0,     0,    92,    93,
      94,    95,    96,     0,     0,     0,     0,     0,     0,    97,
      98,    99,   100,   101,   102,   103,     0,     0,     0,   104,
     105,   106,   107,   108,     0,     0,     0,     0,   109,   110,
     111,   112,   113,   114,   115,   116,   117,     0,   118,   119,
       0,     0,   120,   121,   122,     0,     0,     0,   123,   829,
     124,   125,   126,     0,   127,   128,   129,     0,   130,     0,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,     0,     0,   142,   143,   144,     0,   455,   146,     0,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,     0,   189,   190,   191,     0,   192,   193,   194,
     195,   196,   197,     0,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,     2,     0,     0,     0,     0,     0,
       0,     3,     4,     0,     5,     0,     0,     0,     0,   417,
     418,     0,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,   427,    23,    24,    25,
      26,     0,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,     0,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,     0,    65,    66,    67,    68,    69,    70,    71,    72,
       0,     0,    73,    74,     0,     0,     0,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,     0,     0,
      86,     0,    87,    88,    89,    90,     0,    91,     0,     0,
       0,    92,    93,    94,    95,    96,     0,     0,     0,     0,
       0,     0,    97,    98,    99,   100,   101,   102,   103,     0,
       0,     0,   104,   105,   106,   107,   108,     0,     0,     0,
       0,   109,   110,   111,   112,   113,   114,   115,   116,   117,
       0,   118,   119,     0,     0,   120,   121,   122,     0,     0,
       0,   123,   833,   124,   125,   126,     0,   127,   128,   129,
       0,   130,     0,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,     0,     0,   142,   143,   144,     0,
     455,   146,     0,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,     0,   189,   190,   191,     0,
     192,   193,   194,   195,   196,   197,     0,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,     2,     0,     0,
       0,     0,     0,     0,     3,     4,     0,     5,     0,     0,
       0,     0,   417,   418,     0,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,   427,
      23,    24,    25,    26,     0,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
       0,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,     0,    65,    66,    67,    68,    69,
      70,    71,    72,     0,     0,    73,    74,     0,     0,     0,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,     0,     0,    86,     0,    87,    88,    89,    90,     0,
      91,     0,     0,     0,    92,    93,    94,    95,    96,     0,
       0,     0,     0,     0,     0,    97,    98,    99,   100,   101,
     102,   103,     0,     0,     0,   104,   105,   106,   107,   108,
       0,     0,     0,     0,   109,   110,   111,   112,   113,   114,
     115,   116,   117,     0,   118,   119,     0,     0,   120,   121,
     122,     0,   907,     0,   123,     0,   124,   125,   126,     0,
     127,   128,   129,     0,   130,     0,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,     0,     0,   142,
     143,   144,     0,   455,   146,     0,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,     0,   189,
     190,   191,     0,   192,   193,   194,   195,   196,   197,     0,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
       2,     0,     0,     0,     0,     0,     0,     3,     4,     0,
       5,     0,     0,     0,     0,   417,   418,     0,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,   427,    23,    24,    25,    26,     0,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,     0,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,     0,    65,    66,
      67,    68,    69,    70,    71,    72,     0,     0,    73,    74,
       0,     0,     0,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,     0,     0,    86,     0,    87,    88,
      89,    90,     0,    91,     0,     0,     0,    92,    93,    94,
      95,    96,     0,     0,     0,     0,     0,     0,    97,    98,
      99,   100,   101,   102,   103,     0,     0,     0,   104,   105,
     106,   107,   108,     0,     0,     0,     0,   109,   110,   111,
     112,   113,   114,   115,   116,   117,     0,   118,   119,     0,
       0,   120,   121,   122,     0,   935,     0,   123,     0,   124,
     125,   126,     0,   127,   128,   129,     0,   130,     0,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
       0,     0,   142,   143,   144,     0,   455,   146,     0,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,     0,   189,   190,   191,     0,   192,   193,   194,   195,
     196,   197,     0,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,     2,     0,     0,     0,     0,     0,     0,
       3,     4,     0,     5,     0,     0,     0,     0,   417,   418,
       0,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,   427,    23,    24,    25,    26,
       0,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     0,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
       0,    65,    66,    67,    68,    69,    70,    71,    72,     0,
       0,    73,    74,     0,     0,     0,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,     0,     0,    86,
       0,    87,    88,    89,    90,     0,    91,     0,     0,     0,
      92,    93,    94,    95,    96,     0,     0,     0,     0,     0,
       0,    97,    98,    99,   100,   101,   102,   103,     0,     0,
       0,   104,   105,   106,   107,   108,     0,     0,     0,     0,
     109,   110,   111,   112,   113,   114,   115,   116,   117,     0,
     118,   119,     0,     0,   120,   121,   122,     0,   955,     0,
     123,     0,   124,   125,   126,     0,   127,   128,   129,     0,
     130,     0,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,     0,     0,   142,   143,   144,     0,   455,
     146,     0,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,     0,   189,   190,   191,     0,   192,
     193,   194,   195,   196,   197,     0,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,     2,     0,     0,     0,
       0,     0,     0,     3,     4,     0,     5,     0,     0,     0,
       0,   417,   418,     0,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,   427,    23,
      24,    25,    26,     0,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,     0,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,     0,    65,    66,    67,    68,    69,    70,
      71,    72,     0,     0,    73,    74,     0,     0,     0,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
       0,     0,    86,     0,    87,    88,    89,    90,     0,    91,
       0,     0,     0,    92,    93,    94,    95,    96,     0,     0,
       0,     0,     0,     0,    97,    98,    99,   100,   101,   102,
     103,     0,     0,     0,   104,   105,   106,   107,   108,     0,
       0,     0,     0,   109,   110,   111,   112,   113,   114,   115,
     116,   117,     0,   118,   119,     0,     0,   120,   121,   122,
       0,  1300,     0,   123,     0,   124,   125,   126,     0,   127,
     128,   129,     0,   130,     0,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,     0,     0,   142,   143,
     144,     0,   455,   146,     0,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,     0,   189,   190,
     191,     0,   192,   193,   194,   195,   196,   197,     0,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,     2,
       0,     0,     0,     0,     0,     0,     3,     4,     0,     5,
       0,     0,     0,     0,   417,   418,     0,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,   427,    23,    24,    25,    26,     0,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,     0,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,     0,    65,    66,    67,
      68,    69,    70,    71,    72,     0,     0,    73,    74,     0,
       0,     0,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,     0,     0,    86,     0,    87,    88,    89,
      90,     0,    91,     0,     0,     0,    92,    93,    94,    95,
      96,     0,     0,     0,     0,     0,     0,    97,    98,    99,
     100,   101,   102,   103,     0,     0,     0,   104,   105,   106,
     107,   108,     0,     0,     0,     0,   109,   110,   111,   112,
     113,   114,   115,   116,   117,     0,   118,   119,     0,     0,
     120,   121,   122,     0,  1324,     0,   123,     0,   124,   125,
     126,     0,   127,   128,   129,     0,   130,     0,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,     0,
       0,   142,   143,   144,     0,   455,   146,     0,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
       0,   189,   190,   191,     0,   192,   193,   194,   195,   196,
     197,     0,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,     2,     0,     0,     0,     0,     0,     0,     3,
       4,     0,     5,     0,     0,     0,     0,   417,   418,     0,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,   427,    23,    24,    25,    26,     0,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,     0,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,     0,
      65,    66,    67,    68,    69,    70,    71,    72,     0,     0,
      73,    74,     0,     0,     0,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,     0,     0,    86,     0,
      87,    88,    89,    90,     0,    91,     0,     0,     0,    92,
      93,    94,    95,    96,     0,     0,     0,     0,     0,     0,
      97,    98,    99,   100,   101,   102,   103,     0,     0,     0,
     104,   105,   106,   107,   108,     0,     0,     0,     0,   109,
     110,   111,   112,   113,   114,   115,   116,   117,     0,   118,
     119,     0,     0,   120,   121,   122,     0,  1338,     0,   123,
       0,   124,   125,   126,     0,   127,   128,   129,     0,   130,
       0,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,     0,     0,   142,   143,   144,     0,   455,   146,
       0,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,     0,   189,   190,   191,     0,   192,   193,
     194,   195,   196,   197,     0,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,     2,     0,     0,     0,     0,
       0,     0,     3,     4,     0,     5,     0,     0,     0,     0,
       6,     7,     0,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,     0,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,     0,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,     0,    65,    66,    67,    68,    69,    70,    71,
      72,     0,     0,    73,    74,     0,     0,     0,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,     0,
       0,    86,     0,    87,    88,    89,    90,     0,    91,     0,
       0,     0,    92,    93,    94,    95,    96,     0,     0,     0,
       0,     0,     0,    97,    98,    99,   100,   101,   102,   103,
       0,     0,     0,   104,   105,   106,   107,   108,     0,     0,
       0,     0,   109,   110,   111,   112,   113,   114,   115,   116,
     117,     0,   118,   119,     0,     0,   120,   121,   122,     0,
       0,     0,   123,     0,   124,   125,   126,     0,   127,   128,
     129,     0,   130,     0,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,     0,     0,   142,   143,   144,
       0,   455,   146,     0,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,     0,   189,   190,   191,
       0,   192,   193,   194,   195,   196,   197,     0,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,     2,     0,
       0,     0,     0,     0,     0,     3,     4,     0,     5,     0,
       0,     0,     0,   417,   418,     0,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
     427,    23,    24,    25,    26,     0,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,     0,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,     0,    65,    66,    67,    68,
      69,    70,    71,    72,     0,     0,    73,    74,     0,     0,
       0,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,     0,     0,    86,     0,    87,    88,    89,    90,
       0,    91,     0,     0,     0,    92,    93,    94,    95,    96,
       0,     0,     0,     0,     0,     0,    97,    98,    99,   100,
     101,   102,   103,     0,     0,     0,   104,   105,   106,   107,
     108,     0,     0,     0,     0,   109,   110,   111,   112,   113,
     114,   115,   116,   117,     0,   118,   119,     0,     0,   120,
     121,   122,     0,     0,     0,   123,     0,   124,   125,   126,
       0,   127,   128,   129,     0,   130,     0,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,     0,     0,
     142,   143,   144,     0,   455,   146,     0,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,     0,
     189,   190,   191,     0,   192,   193,   194,   195,   196,   197,
       0,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,     2,     0,     0,     0,     0,     0,     0,     3,     4,
       0,     5,     0,     0,     0,     0,   417,   418,     0,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,   423,
     424,    20,   426,   427,    23,   428,    25,    26,     0,    27,
      28,    29,    30,   429,    32,    33,    34,    35,    36,    37,
     432,    39,    40,   433,     0,    42,    43,    44,   435,   436,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,     0,    65,
      66,    67,    68,    69,    70,    71,    72,     0,     0,    73,
      74,     0,     0,     0,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,     0,     0,    86,     0,    87,
      88,    89,    90,     0,    91,     0,     0,     0,   444,    93,
      94,    95,    96,     0,     0,     0,     0,     0,     0,    97,
      98,    99,   100,   101,   102,   103,     0,     0,     0,   104,
     105,   621,   107,   108,     0,     0,     0,     0,   109,   110,
     111,   112,   113,   114,   115,   116,   117,     0,   622,   119,
       0,     0,   120,   121,   122,     0,     0,     0,   123,     0,
     124,   125,   126,     0,   127,   128,   129,     0,   130,     0,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,     0,     0,   142,   143,   144,     0,   455,   146,     0,
     147,   148,   149,   150,   151,   152,   153,   456,   155,   458,
     157,   459,   460,   160,   161,   162,   163,   164,   165,   461,
     167,   462,   463,   464,   465,   172,   173,   466,   467,   176,
     468,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,     0,   189,   190,   191,     0,   192,   193,   194,
     195,   196,   197,     0,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,     2,     0,     0,     0,     0,     0,
       0,     3,     4,     0,     5,     0,     0,     0,     0,   417,
     418,     0,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,   423,   424,    20,   426,   427,    23,   428,    25,
      26,     0,    27,    28,    29,    30,   429,    32,    33,    34,
      35,    36,    37,   432,    39,    40,   433,     0,    42,    43,
      44,   435,   436,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,     0,    65,    66,    67,    68,    69,    70,    71,    72,
       0,     0,    73,    74,     0,     0,     0,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,     0,     0,
      86,     0,    87,    88,    89,    90,     0,    91,     0,     0,
       0,   444,    93,    94,    95,    96,     0,     0,     0,     0,
       0,     0,    97,    98,    99,   100,   101,   102,   103,     0,
       0,     0,   104,   105,   106,   107,   108,     0,     0,     0,
       0,   109,   110,   111,   112,   113,   114,   115,   116,   117,
       0,   118,   119,     0,     0,   120,   121,   122,     0,     0,
       0,   123,     0,   124,   125,   126,     0,   127,   128,   129,
       0,   130,     0,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,     0,     0,   142,   143,   144,     0,
     455,   146,     0,   147,   148,   149,   150,   151,   152,   153,
     456,   155,   458,   157,   459,   460,   160,   161,   162,   163,
     164,   165,   461,   167,   462,   463,   464,   465,   172,   173,
     466,   467,   176,   468,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,     0,   189,   190,   191,     0,
     192,   193,   194,   195,   196,   197,     0,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,     2,     0,     0,
       0,     0,     0,     0,     3,     4,     0,     5,     0,     0,
       0,     0,   981,   418,     0,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,   427,
      23,    24,    25,    26,     0,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
       0,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,     0,    65,    66,    67,    68,    69,
      70,    71,    72,     0,     0,    73,    74,     0,     0,     0,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,     0,     0,    86,     0,    87,    88,    89,    90,     0,
      91,     0,     0,     0,    92,    93,    94,    95,    96,     0,
       0,     0,     0,     0,     0,    97,    98,    99,   100,   101,
     102,   103,     0,     0,     0,   104,   105,   106,   107,   108,
       0,     0,     0,     0,   109,   110,   111,   112,   113,   114,
     115,   116,   117,     0,   118,   119,     0,     0,   120,   121,
     122,     0,     0,     0,   123,     0,   124,   125,   126,     0,
     127,   128,   129,     0,   130,     0,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,     0,     0,   142,
     143,   144,     0,   455,   146,     0,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,     0,   189,
     190,   191,     0,   192,   193,   194,   195,   196,   197,     0,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
       2,     0,     0,     0,     0,     0,     0,     3,     4,     0,
       5,     0,     0,     0,     0,   417,   418,     0,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,   423,   424,
      20,   426,   427,    23,   428,    25,    26,     0,    27,    28,
      29,    30,   429,    32,    33,    34,    35,    36,    37,   432,
      39,    40,   433,     0,    42,    43,    44,   435,   436,    47,
     437,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,     0,    65,    66,
      67,    68,    69,    70,    71,    72,     0,     0,    73,    74,
       0,     0,     0,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,     0,     0,    86,     0,    87,    88,
      89,    90,     0,    91,     0,     0,     0,   444,    93,    94,
      95,    96,     0,     0,     0,     0,     0,     0,    97,    98,
      99,   100,   101,   102,   103,     0,     0,     0,   104,   105,
       0,   107,   108,     0,     0,     0,     0,   109,   110,   111,
     112,   113,   114,   115,   116,   117,     0,     0,     0,     0,
       0,   120,   121,   122,     0,     0,     0,   123,     0,   124,
     125,   126,     0,   127,   128,   129,     0,   130,     0,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
       0,     0,   142,   143,   144,     0,   455,   146,     0,   147,
     148,   149,   150,   151,   152,   153,   456,   155,   458,   157,
     459,   460,   160,   161,   162,   163,   164,   165,   461,   167,
     462,   463,   464,   465,   172,   173,   466,   467,   176,   468,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,     0,   189,   190,   191,     0,   192,   193,   194,   195,
     196,   197,     0,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,     2,     0,     0,     0,     0,     0,     0,
       3,     4,     0,     5,     0,     0,     0,     0,   417,   418,
       0,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,   423,   424,    20,   426,   427,    23,   428,    25,    26,
       0,    27,    28,    29,    30,   429,    32,    33,    34,    35,
      36,    37,   432,    39,    40,   433,     0,    42,    43,    44,
     435,   436,    47,   437,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
       0,    65,    66,    67,    68,    69,    70,    71,    72,     0,
       0,    73,    74,     0,     0,     0,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,     0,     0,    86,
       0,    87,    88,    89,    90,     0,    91,     0,     0,     0,
     444,    93,    94,    95,    96,     0,     0,     0,     0,     0,
       0,    97,    98,    99,   100,   101,   102,   103,     0,     0,
       0,   104,   105,     0,   107,   108,     0,     0,     0,     0,
     109,   110,   111,   112,   113,   114,   115,   116,   117,     0,
       0,     0,     0,     0,   120,   121,   122,     0,     0,     0,
     123,     0,   124,   125,   126,     0,     0,     0,   129,     0,
     130,     0,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,     0,     0,   142,   143,   144,     0,   455,
     146,     0,   147,   148,   149,   150,   151,   152,   153,   456,
     155,   458,   157,   459,   460,   160,   161,   162,   163,   164,
     165,   461,   167,   462,   463,   464,   465,   172,   173,   466,
     467,   176,   468,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,     0,   189,   190,   191,     0,   192,
     193,   194,   195,   196,   197,     0,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,     2,     0,     0,     0,
       0,     0,     0,     3,     4,     0,     0,     0,     0,     0,
       0,   417,   418,     0,     8,     9,   504,    11,    12,    13,
      14,   420,    16,   505,   423,   424,   425,   426,   427,    23,
     428,    25,    26,     0,    27,    28,    29,    30,   429,    32,
     506,    34,    35,    36,    37,   432,    39,    40,   433,     0,
      42,   507,    44,   435,   436,    47,   437,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
     438,   439,    64,     0,    65,    66,    67,   508,     0,    70,
      71,    72,     0,     0,   441,    74,     0,     0,     0,     0,
      76,    77,    78,   442,   443,    81,    82,     0,     0,     0,
       0,     0,     0,     0,    87,    88,    89,    90,     0,    91,
       0,     0,     0,   444,    93,    94,   445,   446,     0,     0,
       0,     0,     0,     0,    97,    98,    99,     0,   101,   102,
     103,     0,     0,     0,     0,     0,     0,   107,   108,     0,
       0,     0,     0,   109,   110,   111,   112,   449,   114,   115,
     450,     0,     0,     0,     0,     0,     0,   451,   452,   122,
       0,     0,     0,   123,     0,   124,   125,   453,     0,     0,
       0,   129,     0,   130,     0,   131,   132,   133,   134,   454,
     136,   137,   138,   139,   140,   141,     0,     0,   142,   143,
       0,     0,   455,   146,     0,   147,   148,   149,   150,   151,
     152,   153,   456,   155,   458,   157,   459,   460,   160,   161,
     162,   163,   164,   165,   461,   167,   462,   463,   464,   465,
     172,   173,   466,   467,   176,   468,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,     0,   189,   190,
     191,     0,   192,   193,   194,   195,   196,   197,     0,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,     2,
       0,     0,     0,     0,     0,     0,     3,     4,     0,     0,
       0,     0,     0,     0,   417,   418,     0,     8,     9,   419,
      11,    12,    13,    14,   420,   421,   422,   423,   424,   425,
     426,   427,    23,   428,    25,    26,     0,    27,    28,    29,
      30,   429,    32,   430,    34,    35,   431,    37,   432,    39,
      40,   433,     0,    42,   434,    44,   435,   436,    47,   437,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,   438,   439,    64,     0,    65,    66,    67,
     440,     0,    70,    71,    72,     0,     0,   441,    74,     0,
       0,     0,     0,    76,    77,    78,   442,   443,    81,    82,
       0,     0,     0,     0,     0,     0,     0,    87,    88,    89,
      90,     0,    91,     0,     0,     0,   444,    93,    94,   445,
     446,     0,     0,     0,     0,     0,     0,    97,    98,    99,
       0,   101,   102,   103,     0,     0,     0,     0,     0,     0,
     107,   108,     0,     0,     0,     0,   109,   110,   111,   112,
     449,   114,   115,   450,     0,     0,     0,     0,     0,     0,
     451,   452,   122,     0,     0,     0,   123,     0,   124,     0,
     453,     0,     0,     0,   129,     0,   130,     0,   131,   132,
     133,   134,   454,   136,   137,   138,   139,   140,   141,     0,
       0,   142,   143,     0,     0,   455,   146,     0,   147,   148,
     149,   150,   151,   152,   153,   456,   457,   458,   157,   459,
     460,   160,   161,   162,   163,   164,   165,   461,   167,   462,
     463,   464,   465,   172,   173,   466,   467,   176,   468,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
       0,   189,   190,   191,     0,   192,   193,   194,   195,   196,
     197,     0,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   482,     0,     0,     0,     4,     0,     0,     0,
       0,     0,     0,   417,   418,     0,     8,     9,   419,    11,
      12,    13,    14,   420,   421,   422,   423,   424,   425,   426,
     427,    23,   428,    25,    26,     0,    27,    28,    29,    30,
     429,    32,   430,    34,    35,   431,    37,   432,    39,    40,
     433,     0,    42,   434,    44,   435,   436,    47,   437,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,   438,   439,    64,     0,    65,    66,    67,   440,
       0,    70,    71,    72,     0,     0,   441,    74,     0,     0,
       0,     0,    76,    77,    78,   442,   443,    81,    82,     0,
       0,     0,     0,     0,     0,     0,    87,    88,    89,    90,
       0,    91,     0,     0,     0,   444,    93,    94,   445,   446,
       0,     0,     0,     0,     0,     0,    97,    98,    99,     0,
     101,   102,   103,   483,     0,     0,   484,     0,     0,   107,
     108,     0,     0,     0,     0,   109,   110,   111,   112,   449,
     114,   115,   450,     0,     0,     0,     0,     0,     0,   451,
     452,   122,     0,     0,     0,   123,     0,   124,     0,   453,
       0,     0,     0,     0,     0,   130,     0,   131,   132,   133,
     134,   454,   136,   137,   138,   139,   140,   141,     0,     0,
     142,   143,     0,     0,   455,   146,     0,   147,   148,   149,
     150,   151,   152,   153,   456,   457,   458,   157,   459,   460,
     160,   161,   162,   163,   164,   165,   461,   167,   462,   463,
     464,   465,   172,   173,   466,   467,   176,   468,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,     0,
     189,   190,   191,     0,   192,   193,   194,   195,   196,   197,
       0,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   482,     0,     0,     0,     4,     0,   721,     0,     0,
       0,     0,   417,   418,     0,     8,     9,   419,    11,    12,
      13,    14,   420,   421,   422,   423,   424,   425,   426,   427,
      23,   428,    25,    26,     0,    27,    28,    29,    30,   429,
      32,   430,    34,    35,   431,    37,   432,    39,    40,   433,
       0,    42,   434,    44,   435,   436,    47,   437,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,   438,   439,    64,     0,    65,    66,    67,   440,     0,
      70,    71,    72,     0,     0,   441,    74,     0,     0,     0,
       0,    76,    77,    78,   442,   443,    81,    82,     0,     0,
       0,     0,     0,     0,     0,    87,    88,    89,    90,     0,
      91,     0,     0,     0,   444,    93,    94,   445,   446,     0,
       0,     0,     0,     0,     0,    97,    98,    99,     0,   101,
     102,   103,     0,     0,     0,     0,     0,     0,   107,   108,
       0,     0,     0,     0,   109,   110,   111,   112,   449,   114,
     115,   450,     0,     0,     0,     0,     0,     0,   451,   452,
     122,     0,     0,     0,   123,   722,   124,     0,   453,     0,
       0,     0,     0,     0,   130,     0,   131,   132,   133,   134,
     454,   136,   137,   138,   139,   140,   141,     0,     0,   142,
     143,     0,     0,   455,   146,     0,   147,   148,   149,   150,
     151,   152,   153,   456,   457,   458,   157,   459,   460,   160,
     161,   162,   163,   164,   165,   461,   167,   462,   463,   464,
     465,   172,   173,   466,   467,   176,   468,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,     0,   189,
     190,   191,     0,   192,   193,   194,   195,   196,   197,     0,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     482,     0,     0,     0,     4,     0,     0,     0,     0,     0,
       0,   417,   418,     0,     8,     9,   419,    11,    12,    13,
      14,   420,   421,   422,   423,   424,   425,   426,   427,    23,
     428,    25,    26,     0,    27,    28,    29,    30,   429,    32,
     430,    34,    35,   431,    37,   432,    39,    40,   433,     0,
      42,   434,    44,   435,   436,    47,   437,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
     438,   439,    64,     0,    65,    66,    67,   440,     0,    70,
      71,    72,     0,     0,   441,    74,     0,     0,     0,     0,
      76,    77,    78,   442,   443,    81,    82,     0,     0,     0,
       0,     0,     0,     0,    87,    88,    89,    90,     0,    91,
       0,     0,     0,   444,    93,    94,   445,   446,     0,     0,
       0,     0,     0,     0,    97,    98,    99,     0,   101,   102,
     103,     0,     0,     0,     0,     0,     0,   107,   108,     0,
       0,     0,     0,   109,   110,   111,   112,   449,   114,   115,
     450,     0,     0,     0,     0,     0,     0,   451,   452,   122,
       0,     0,     0,   123,     0,   124,     0,   453,     0,     0,
       0,     0,     0,   130,     0,   131,   132,   133,   134,   454,
     136,   137,   138,   139,   140,   141,     0,     0,   142,   143,
       0,     0,   455,   146,     0,   147,   148,   149,   150,   151,
     152,   153,   456,   457,   458,   157,   459,   460,   160,   161,
     162,   163,   164,   165,   461,   167,   462,   463,   464,   465,
     172,   173,   466,   467,   176,   468,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,     0,   189,   190,
     191,     0,   192,   193,   194,   195,   196,   197,     0,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   524,
       0,     4,     0,     0,     0,     0,     0,     0,   417,   418,
       0,     8,     9,   419,    11,    12,    13,    14,   420,   421,
     422,   423,   424,   425,   426,   427,    23,   428,    25,    26,
       0,    27,    28,    29,    30,   429,    32,   430,    34,    35,
     431,    37,   432,    39,    40,   433,     0,    42,   434,    44,
     435,   436,    47,   437,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,   438,   439,    64,
       0,    65,    66,    67,   440,     0,    70,    71,    72,     0,
       0,   441,    74,     0,     0,     0,     0,    76,    77,    78,
     442,   443,    81,    82,     0,     0,     0,     0,     0,     0,
       0,    87,    88,    89,    90,     0,    91,     0,     0,     0,
     444,    93,    94,   445,   446,     0,     0,     0,     0,     0,
       0,    97,    98,    99,     0,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   107,   108,     0,     0,     0,     0,
     109,   110,   111,   112,   449,   114,   115,   450,     0,     0,
       0,     0,     0,     0,   451,   452,   122,     0,     0,     0,
     123,     0,   124,     0,   453,     0,     0,     0,     0,     0,
     130,     0,   131,   132,   133,   134,   454,   136,   137,   138,
     139,   140,   141,     0,     0,   142,   143,     0,     0,   455,
     146,     0,   147,   148,   149,   150,   151,   152,   153,   456,
     457,   458,   157,   459,   460,   160,   161,   162,   163,   164,
     165,   461,   167,   462,   463,   464,   465,   172,   173,   466,
     467,   176,   468,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,     0,   189,   190,   191,     0,   192,
     193,   194,   195,   196,   197,     0,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,     4,     0,     0,     0,
       0,     0,     0,   417,   418,     0,     8,     9,   504,    11,
      12,    13,    14,   420,    16,   505,   423,   424,  1000,   426,
     427,    23,   428,    25,    26,     0,    27,    28,    29,    30,
     429,    32,   506,    34,    35,    36,    37,   432,    39,    40,
     433,     0,    42,   507,    44,   435,   436,    47,   437,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,   438,   439,    64,     0,    65,    66,    67,   508,
       0,    70,    71,    72,     0,     0,   441,    74,     0,     0,
       0,     0,    76,    77,    78,   442,   443,    81,    82,     0,
       0,     0,     0,     0,     0,     0,    87,    88,    89,    90,
       0,    91,     0,     0,     0,   444,    93,    94,   445,   446,
       0,     0,     0,     0,     0,     0,    97,    98,    99,     0,
     101,   102,  1001,     0,     0,     0,  1002,     0,     0,   107,
     108,     0,     0,     0,     0,   109,   110,   111,   112,   449,
     114,   115,   450,     0,     0,     0,     0,     0,     0,   451,
     452,   122,     0,     0,     0,   123,  1374,   124,   125,   453,
       0,     0,     0,  1375,     0,   130,     0,   131,   132,   133,
     134,   454,   136,   137,   138,   139,   140,   141,     0,     0,
    1003,   143,     0,     0,   455,   146,     0,   147,   148,   149,
     150,   151,   152,   153,   456,   155,   458,   157,   459,   460,
     160,   161,   162,   163,   164,   165,   461,   167,   462,   463,
     464,   465,   172,   173,   466,   467,   176,   468,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,     0,
     189,   190,   191,     0,   192,   193,   194,   195,   196,   197,
       0,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,     4,     0,     0,     0,     0,     0,     0,   417,   418,
       0,     8,     9,   419,    11,    12,    13,    14,   420,   421,
     422,   423,   424,   425,   426,   427,    23,   428,    25,    26,
       0,    27,    28,    29,    30,   429,    32,   430,    34,    35,
     431,    37,   432,    39,    40,   433,     0,    42,   434,    44,
     435,   436,    47,   437,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,   438,   439,    64,
       0,    65,    66,    67,   440,     0,    70,    71,    72,     0,
       0,   441,    74,     0,     0,     0,     0,    76,    77,    78,
     442,   443,    81,    82,     0,     0,     0,   500,     0,     0,
       0,    87,    88,    89,    90,     0,    91,     0,     0,     0,
     444,    93,    94,   445,   446,     0,     0,     0,     0,     0,
       0,    97,    98,    99,     0,   101,   102,   103,   501,     0,
       0,   502,     0,     0,   107,   108,     0,     0,     0,     0,
     109,   110,   111,   112,   449,   114,   115,   450,     0,     0,
       0,     0,     0,     0,   451,   452,   122,     0,     0,     0,
     123,     0,   124,     0,   453,     0,     0,     0,     0,     0,
     130,     0,   131,   132,   133,   134,   454,   136,   137,   138,
     139,   140,   141,     0,     0,   142,   143,     0,     0,   455,
     146,     0,   147,   148,   149,   150,   151,   152,   153,   456,
     457,   458,   157,   459,   460,   160,   161,   162,   163,   164,
     165,   461,   167,   462,   463,   464,   465,   172,   173,   466,
     467,   176,   468,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,     0,   189,   190,   191,     0,   192,
     193,   194,   195,   196,   197,     0,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,     4,     0,     0,     0,
       0,     0,     0,   417,   418,     0,     8,     9,   504,    11,
      12,    13,    14,   420,    16,   505,   423,   424,  1000,   426,
     427,    23,   428,    25,    26,     0,    27,    28,    29,    30,
     429,    32,   506,    34,    35,    36,    37,   432,    39,    40,
     433,     0,    42,   507,    44,   435,   436,    47,   437,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,   438,   439,    64,     0,    65,    66,    67,   508,
       0,    70,    71,    72,     0,     0,   441,    74,     0,     0,
       0,     0,    76,    77,    78,   442,   443,    81,    82,  1333,
       0,     0,     0,     0,     0,     0,    87,    88,    89,    90,
       0,    91,     0,     0,     0,   444,    93,    94,   445,   446,
       0,     0,     0,     0,     0,     0,    97,    98,    99,     0,
     101,   102,  1001,     0,     0,     0,  1002,     0,     0,   107,
     108,     0,     0,     0,     0,   109,   110,   111,   112,   449,
     114,   115,   450,     0,     0,     0,     0,     0,     0,   451,
     452,   122,     0,     0,     0,   123,     0,   124,   125,   453,
       0,     0,     0,     0,     0,   130,     0,   131,   132,   133,
     134,   454,   136,   137,   138,   139,   140,   141,     0,     0,
    1003,   143,     0,     0,   455,   146,     0,   147,   148,   149,
     150,   151,   152,   153,   456,   155,   458,   157,   459,   460,
     160,   161,   162,   163,   164,   165,   461,   167,   462,   463,
     464,   465,   172,   173,   466,   467,   176,   468,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,     0,
     189,   190,   191,     0,   192,   193,   194,   195,   196,   197,
       0,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,     4,     0,     0,     0,     0,     0,     0,   417,   418,
       0,     8,     9,   419,    11,    12,    13,    14,   420,   421,
     422,   423,   424,   425,   426,   427,    23,   428,    25,    26,
       0,    27,    28,    29,    30,   429,    32,   430,    34,    35,
     431,    37,   432,    39,    40,   433,     0,    42,   434,    44,
     435,   436,    47,   437,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,   438,   439,    64,
       0,    65,    66,    67,   440,     0,    70,    71,    72,     0,
       0,   441,    74,     0,     0,     0,     0,    76,    77,    78,
     442,   443,    81,    82,     0,     0,     0,     0,     0,     0,
       0,    87,    88,    89,    90,     0,    91,     0,     0,     0,
     444,    93,    94,   445,   446,     0,     0,     0,     0,     0,
       0,    97,    98,    99,     0,   101,   102,   103,   447,     0,
       0,   448,     0,     0,   107,   108,     0,     0,     0,     0,
     109,   110,   111,   112,   449,   114,   115,   450,     0,     0,
       0,     0,     0,     0,   451,   452,   122,     0,     0,     0,
     123,     0,   124,     0,   453,     0,     0,     0,     0,     0,
     130,     0,   131,   132,   133,   134,   454,   136,   137,   138,
     139,   140,   141,     0,     0,   142,   143,     0,     0,   455,
     146,     0,   147,   148,   149,   150,   151,   152,   153,   456,
     457,   458,   157,   459,   460,   160,   161,   162,   163,   164,
     165,   461,   167,   462,   463,   464,   465,   172,   173,   466,
     467,   176,   468,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,     0,   189,   190,   191,     0,   192,
     193,   194,   195,   196,   197,     0,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,     4,     0,     0,     0,
       0,     0,     0,   417,   418,     0,     8,     9,   419,    11,
      12,    13,    14,   420,   421,   422,   423,   424,   425,   426,
     427,    23,   428,    25,    26,     0,    27,    28,    29,    30,
     429,    32,   430,    34,    35,   431,    37,   432,    39,    40,
     433,     0,    42,   434,    44,   435,   436,    47,   437,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,   438,   439,    64,     0,    65,    66,    67,   440,
       0,    70,    71,    72,     0,     0,   441,    74,     0,     0,
       0,     0,    76,    77,    78,   442,   443,    81,    82,     0,
       0,     0,     0,     0,     0,     0,    87,    88,    89,    90,
       0,    91,     0,     0,     0,   444,    93,    94,   445,   446,
       0,     0,     0,     0,     0,     0,    97,    98,    99,     0,
     101,   102,   103,     0,     0,     0,     0,     0,     0,   107,
     108,     0,     0,     0,     0,   109,   110,   111,   112,   449,
     114,   115,   450,     0,     0,     0,     0,     0,     0,   451,
     452,   122,     0,     0,     0,   123,   694,   124,     0,   453,
       0,     0,     0,   695,     0,   130,     0,   131,   132,   133,
     134,   454,   136,   137,   138,   139,   140,   141,     0,     0,
     142,   143,     0,     0,   455,   146,     0,   147,   148,   149,
     150,   151,   152,   153,   456,   457,   458,   157,   459,   460,
     160,   161,   162,   163,   164,   165,   461,   167,   462,   463,
     464,   465,   172,   173,   466,   467,   176,   468,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,     0,
     189,   190,   191,     0,   192,   193,   194,   195,   196,   197,
       0,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,     4,     0,     0,     0,     0,     0,     0,   417,   418,
       0,     8,     9,   419,    11,    12,    13,    14,   420,   421,
     422,   423,   424,   425,   426,   427,    23,   428,    25,    26,
       0,    27,    28,    29,    30,   429,    32,   430,    34,    35,
     431,    37,   432,    39,    40,   433,     0,    42,   434,    44,
     435,   436,    47,   437,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,   438,   439,    64,
       0,    65,    66,    67,   440,     0,    70,    71,    72,     0,
       0,   441,    74,     0,     0,     0,     0,    76,    77,    78,
     442,   443,    81,    82,     0,     0,     0,     0,     0,     0,
       0,    87,    88,    89,    90,     0,    91,     0,     0,     0,
     444,    93,    94,   445,   446,     0,     0,     0,     0,     0,
       0,    97,    98,    99,     0,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   107,   108,     0,     0,     0,     0,
     109,   110,   111,   112,   449,   114,   115,   450,     0,     0,
       0,     0,     0,     0,   451,   452,   122,     0,     0,     0,
     123,   740,   124,     0,   453,     0,     0,     0,   741,     0,
     130,     0,   131,   132,   133,   134,   454,   136,   137,   138,
     139,   140,   141,     0,     0,   142,   143,     0,     0,   455,
     146,     0,   147,   148,   149,   150,   151,   152,   153,   456,
     457,   458,   157,   459,   460,   160,   161,   162,   163,   164,
     165,   461,   167,   462,   463,   464,   465,   172,   173,   466,
     467,   176,   468,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,     0,   189,   190,   191,     0,   192,
     193,   194,   195,   196,   197,     0,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,     4,     0,     0,     0,
       0,     0,     0,   417,   418,     0,     8,     9,   504,    11,
      12,    13,    14,   420,    16,   505,   423,   424,  1000,   426,
     427,    23,   428,    25,    26,     0,    27,    28,    29,    30,
     429,    32,   506,    34,    35,    36,    37,   432,    39,    40,
     433,     0,    42,   507,    44,   435,   436,    47,   437,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,   438,   439,    64,     0,    65,    66,    67,   508,
       0,    70,    71,    72,     0,     0,   441,    74,     0,     0,
       0,     0,    76,    77,    78,   442,   443,    81,    82,     0,
       0,     0,     0,     0,     0,     0,    87,    88,    89,    90,
       0,    91,     0,     0,     0,   444,    93,    94,   445,   446,
       0,     0,     0,     0,     0,     0,    97,    98,    99,     0,
     101,   102,  1001,     0,     0,     0,  1002,     0,     0,   107,
     108,     0,     0,     0,     0,   109,   110,   111,   112,   449,
     114,   115,   450,     0,     0,     0,     0,     0,     0,   451,
     452,   122,     0,     0,     0,   123,     0,   124,   125,   453,
       0,     0,     0,     0,     0,   130,     0,   131,   132,   133,
     134,   454,   136,   137,   138,   139,   140,   141,     0,     0,
    1003,   143,     0,     0,   455,   146,     0,   147,   148,   149,
     150,   151,   152,   153,   456,   155,   458,   157,   459,   460,
     160,   161,   162,   163,   164,   165,   461,   167,   462,   463,
     464,   465,   172,   173,   466,   467,   176,   468,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,     0,
     189,   190,   191,     0,   192,   193,   194,   195,   196,   197,
       0,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,     4,     0,     0,     0,     0,     0,     0,   417,   418,
       0,     8,     9,   504,    11,    12,    13,    14,   420,    16,
     505,   423,   424,  1000,   426,   427,    23,   428,    25,    26,
       0,    27,    28,    29,    30,   429,    32,   506,    34,    35,
      36,    37,   432,    39,    40,   433,     0,    42,   507,    44,
     435,   436,    47,   437,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,   438,   439,    64,
       0,    65,    66,    67,   508,     0,    70,    71,    72,     0,
       0,   441,    74,     0,     0,     0,     0,    76,    77,    78,
     442,   443,    81,    82,     0,     0,     0,     0,     0,     0,
       0,    87,    88,    89,    90,     0,    91,     0,     0,     0,
     444,    93,    94,   445,   446,     0,     0,     0,     0,     0,
       0,    97,    98,    99,     0,   101,   102,  1001,     0,     0,
       0,  1002,     0,     0,   107,   108,     0,     0,     0,     0,
     109,   110,   111,   112,   449,   114,   115,   450,     0,     0,
       0,     0,     0,     0,   451,   452,   122,     0,     0,     0,
     123,     0,   124,   125,   453,     0,     0,     0,     0,     0,
     130,     0,   131,   132,   133,   134,   454,   136,   137,   138,
     139,   140,   141,     0,     0,   142,   143,     0,     0,   455,
     146,     0,   147,   148,   149,   150,   151,   152,   153,   456,
     155,   458,   157,   459,   460,   160,   161,   162,   163,   164,
     165,   461,   167,   462,   463,   464,   465,   172,   173,   466,
     467,   176,   468,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,     0,   189,   190,   191,     0,   192,
     193,   194,   195,   196,   197,     0,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,     4,     0,     0,     0,
       0,     0,     0,   417,   418,     0,     8,     9,   419,    11,
      12,    13,    14,   420,   421,   422,   423,   424,   425,   426,
     427,    23,   428,    25,    26,     0,    27,    28,    29,    30,
     429,    32,   430,    34,    35,   431,    37,   432,    39,    40,
     433,     0,    42,   434,    44,   435,   436,    47,   437,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,   438,   439,    64,     0,    65,    66,    67,   440,
       0,    70,    71,    72,     0,     0,   441,    74,     0,     0,
       0,     0,    76,    77,    78,   442,   443,    81,    82,     0,
       0,     0,     0,     0,     0,     0,    87,    88,    89,    90,
       0,    91,     0,     0,     0,   444,    93,    94,   445,   446,
       0,     0,     0,     0,     0,     0,    97,    98,    99,     0,
     101,   102,   103,     0,     0,     0,     0,     0,     0,   107,
     108,     0,     0,     0,     0,   109,   110,   111,   112,   449,
     114,   115,   450,     0,     0,     0,     0,     0,     0,   451,
     452,   122,     0,     0,     0,   123,     0,   124,     0,   453,
       0,     0,     0,     0,     0,   130,     0,   131,   132,   133,
     134,   454,   136,   137,   138,   139,   140,   141,     0,     0,
     142,   143,     0,     0,   455,   146,     0,   147,   148,   149,
     150,   151,   152,   153,   456,   457,   458,   157,   459,   460,
     160,   161,   162,   163,   164,   165,   461,   167,   462,   463,
     464,   465,   172,   173,   466,   467,   176,   468,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,     0,
     189,   190,   191,     0,   192,   193,   194,   195,   196,   197,
       0,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
        17,   747,   311,   372,   609,   610,   611,   612,   821,   822,
     104,   566,   117,   128,   927,   895,    33,   563,   608,   790,
     962,  1097,   807,   819,   820,   238,  1213,  1214,   241,   718,
    1360,    69,  1202,    20,  1024,    47,  1289,   648,    50,   588,
     585,   590,   591,    49,   593,   718,   595,   111,   819,   820,
     807,    68,    69,  1264,   603,   604,   729,    88,  1175,   854,
       8,     9,    21,    88,     7,    37,    83,    88,    90,   139,
      20,   100,    87,    93,    88,    45,    90,     8,     9,    20,
     128,    93,     8,   854,   100,    57,   122,   100,   105,   100,
     100,    90,   100,    19,   134,   100,   123,   100,   100,   100,
     117,    38,   119,   134,   100,   794,    90,   796,   125,   478,
     479,   111,    90,    26,   100,   100,   103,   139,    40,   890,
     150,   917,   106,   984,    90,   139,    61,    88,    93,   116,
     139,    66,   256,   261,   217,   111,    58,   167,    60,   222,
     268,   106,    55,   267,   192,    90,   917,    69,    96,   148,
     179,   121,   188,   217,   141,   182,   106,   177,   145,   174,
     190,   148,   175,   100,   148,    96,   182,   115,   129,   117,
     178,   182,   182,   134,   179,   178,   111,   178,   178,    33,
    1367,   168,   178,   100,   115,    39,   117,   860,   100,   115,
      44,   117,   178,   178,  1055,   161,   266,   145,    52,   314,
     126,   149,   152,   209,   229,     4,   178,  1002,   229,     8,
      64,   152,   958,  1093,   145,  1426,   161,   165,   149,   145,
      88,  1134,  1298,   166,  1166,   227,   266,  1344,   839,   840,
     100,  1002,   244,  1175,   165,   266,   300,   910,   186,  1024,
    1025,   247,   931,   916,   266,   257,   205,   259,  1501,   128,
    1240,   796,   266,  1583,   803,   186,   204,   266,   270,   271,
     272,   178,   274,   142,   276,   252,   178,  1024,  1025,   286,
    1600,   249,   250,   204,    25,   209,   173,    88,  1608,   245,
     246,   319,   248,   388,   322,   100,    88,   100,    88,   255,
     187,    42,    28,    29,   663,    31,    32,  1467,    34,   265,
     245,   246,   319,   248,    40,   322,   160,   412,   178,   163,
     150,   277,    48,   247,    50,    51,   115,   152,   117,   413,
     265,   415,    58,   177,    60,   122,   125,   167,   139,  1100,
    1126,  1020,   277,    69,   111,   145,   145,    73,   148,   139,
     553,     8,   210,   211,   110,   714,   145,     4,    88,   203,
     145,     8,    19,   447,  1430,  1126,  1152,   225,    37,   168,
     377,    40,   379,   178,   903,   178,   905,   384,   104,   105,
     106,   388,   138,   168,    90,   470,   217,   394,   219,   484,
    1567,  1152,   158,   477,   401,   151,    30,   150,   145,   483,
     106,   188,    36,    37,    73,   412,   490,   173,   492,   493,
     177,   495,  1344,   136,   167,   145,    99,   501,   210,   211,
      54,   150,   951,    57,   953,   145,   152,  1297,   148,   185,
      99,    65,   262,   225,  1220,   161,   119,   521,   167,   269,
     161,   448,   148,  1509,   167,   145,    20,   531,   148,   279,
     535,   536,   988,   538,   539,   540,   541,    91,   115,  1220,
     117,   190,   185,   548,   549,  1240,   550,   193,   115,   126,
     117,  1537,   193,   480,  1249,   140,   148,   484,   125,   564,
     487,   488,   489,   213,   214,  1260,   212,   494,   145,   574,
     575,   160,   157,  1240,   140,   502,   222,    89,   145,    46,
     129,   201,  1249,   145,   863,   864,    53,    99,   515,   868,
     129,   157,    93,  1260,   293,   294,   145,   109,   240,   241,
       8,     9,   627,   628,    46,   106,   145,   119,   254,   103,
    1596,    53,  1598,   173,    39,   129,   543,   148,   897,  1442,
     624,   263,   116,    90,   551,   629,   180,   187,  1614,    71,
     635,   145,   148,   638,   280,   281,   282,   283,   284,    90,
     286,   287,   288,   289,   290,  1518,  1519,   141,    90,   295,
     296,   145,    34,   262,   148,   106,   137,   851,    40,   148,
     269,   256,   111,   217,     8,     9,    48,   148,    50,   111,
     279,   865,   267,   192,   168,   292,    58,  1550,    60,   213,
     214,   215,   201,  1556,   301,    46,  1342,    69,    96,   129,
    1346,    73,    53,   697,   134,   710,   111,   129,   713,   270,
     271,   272,   134,   707,   148,   276,   321,   115,   114,   117,
    1405,   326,   217,   630,   219,   146,   633,   148,   148,   636,
     724,   114,   104,   105,   106,   224,   653,   226,   655,   183,
     184,   658,   111,   737,   738,   293,   294,   145,  1405,   743,
     224,   149,   226,   376,   114,   378,   120,   121,   284,   285,
     114,  1251,    96,   680,   681,   682,   161,   165,   120,   121,
     606,   607,   114,   613,   614,   769,  1472,   114,  1474,  1417,
    1418,   115,   114,   117,   701,   114,   703,   145,   186,   161,
     785,   615,   616,   710,   114,   114,   713,   792,   193,   114,
     145,  1472,   148,  1474,   207,   217,   204,   111,   234,  1455,
     145,   145,  1458,   111,   145,   149,   234,  1026,  1514,   235,
     148,   193,     0,  1278,     3,  1538,   182,   222,    86,   746,
      43,   165,   182,  1529,   159,   242,   191,    94,   146,    95,
      20,    40,    40,  1514,    40,   144,   111,   239,   286,   291,
     222,   291,   186,   145,   297,   178,   111,   145,  1529,   111,
    1129,   856,   145,   277,   277,   178,   783,   862,   145,   145,
     204,   145,   178,   790,    27,   148,  1522,   148,   148,   148,
     148,    15,   254,   178,  1389,   280,   281,   282,   283,   284,
      20,   286,   287,   288,   289,   290,   205,   178,    25,   223,
     295,   111,   819,   820,   821,   822,  1396,  1397,   280,   281,
     282,   283,   284,   160,   286,   287,   288,   289,   290,   162,
     162,    65,   223,   295,   296,   100,    88,    88,    88,   141,
     100,   100,    20,   152,   929,   152,   119,   854,   124,   239,
    1209,   175,   124,   938,   292,   940,   941,   175,   178,   178,
     175,   175,   946,   870,    90,    88,   178,    37,    90,   100,
     175,   134,   957,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,   968,   969,   970,   178,   972,   973,   974,
     975,   976,   977,   178,   979,   980,   903,   178,   905,  1479,
    1480,   175,    88,   178,   145,   134,   229,   992,   162,   175,
     917,   178,   111,   175,   175,   111,   217,   175,   182,   175,
     111,   178,   111,   139,   124,   134,   175,   134,   176,    88,
      20,  1016,   219,  1018,  1019,   279,   292,   145,   175,  1023,
     111,   247,    88,   175,   951,   189,   953,   124,   152,   124,
      90,   111,  1532,   134,   175,   145,   111,   139,    93,  1318,
    1045,    93,   175,   124,   175,   145,    27,    20,   111,  1053,
     175,   132,   133,   175,   135,   111,   145,    73,  1063,   100,
     100,   148,   143,   238,   148,   148,   147,   139,   149,   996,
     139,   136,   999,   154,   278,  1002,    20,   279,   251,    20,
      20,   229,   280,   299,   219,   219,  1013,   253,  1015,   170,
     182,   136,  1371,   260,   111,   139,   219,   111,   100,    71,
    1104,   178,   178,   134,   178,   178,  1111,   175,   178,   124,
       6,  1116,   225,   194,   195,   196,   197,   198,   199,   178,
     182,   225,   225,  1128,   229,   134,   225,   177,    99,    99,
     178,   178,   178,  1138,  1139,   139,   175,  1141,   139,    72,
     178,   279,  1147,  1148,    20,   275,   175,   243,    20,   243,
     264,    90,   175,   118,  1158,   162,    90,   250,   177,   177,
      88,   145,   175,   175,   175,   273,    20,   162,   100,   175,
     178,    46,    88,   178,   111,    88,    20,   100,    88,   177,
     258,   111,   217,   175,   111,   188,   298,   111,   188,   188,
    1117,   217,   280,    87,   177,   174,   111,   188,   145,  1126,
    1205,   286,   111,   111,   190,   111,   238,   662,   242,  1136,
     178,  1216,   298,   562,   242,   245,   298,  1144,   855,   280,
     217,  1059,   562,  1100,   386,  1152,  1231,  1509,   299,  1234,
    1537,  1236,   299,  1198,   918,   299,   915,   382,   999,   476,
    1312,   406,   285,  1136,  1118,  1172,  1206,  1218,   992,  1216,
     246,  1213,   515,  1144,  1153,   586,   307,  1149,   638,   587,
     747,  1166,  1556,  1550,  1094,   822,  1193,   905,  1058,   416,
    1203,  1249,  1260,  1405,  1253,  1202,  1025,   416,  1402,  1206,
    1034,   889,  1083,  1420,  1287,  1193,  1250,    -1,    -1,    -1,
      -1,    -1,    -1,  1220,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1308,    -1,    -1,    -1,    -1,    -1,  1314,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1323,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1331,  1332,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1350,  1351,  1352,  1353,  1354,
      -1,  1356,  1357,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1295,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1383,    -1,
      -1,    -1,  1309,  1310,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1333,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1343,    -1,    -1,    -1,
    1347,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1441,    -1,    -1,    -1,
      -1,  1446,    -1,    -1,    -1,  1450,    -1,  1452,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1489,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1451,    -1,    -1,    -1,    -1,  1456,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1467,  1546,    -1,    -1,    -1,  1472,    -1,  1474,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1568,    -1,    -1,    -1,    -1,  1573,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1505,    -1,
      -1,  1508,    -1,    -1,    -1,    -1,    -1,  1514,  1593,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1525,    -1,
      -1,    -1,  1529,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1538,    -1,  1540,    -1,    -1,    -1,  1544,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1570,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1588,    -1,  1590,     3,    -1,    -1,    -1,    -1,    -1,
      -1,    10,    -1,    -1,    -1,    -1,  1603,    -1,    17,    18,
    1607,    20,    -1,    -1,    -1,  1612,    25,    26,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    -1,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    -1,    88,
      89,    90,    91,    92,    93,    94,    95,    -1,    -1,    98,
      99,    -1,    -1,    -1,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,    -1,    -1,   116,    -1,   118,
     119,   120,   121,    -1,   123,    -1,    -1,    -1,   127,   128,
     129,   130,   131,    -1,    -1,    -1,    -1,    -1,    -1,   138,
     139,   140,   141,   142,   143,   144,    -1,    -1,    -1,   148,
     149,   150,   151,   152,    -1,    -1,    -1,    -1,   157,   158,
     159,   160,   161,   162,   163,   164,   165,    -1,   167,   168,
      -1,    -1,   171,   172,   173,    -1,    -1,    -1,   177,    -1,
     179,   180,   181,    -1,   183,   184,   185,    -1,   187,    -1,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,    -1,    -1,   202,   203,   204,    -1,   206,   207,    -1,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,    -1,   252,   253,   254,    -1,   256,   257,   258,
     259,   260,   261,    -1,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,     3,    -1,    -1,    -1,    -1,
      -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    20,    -1,    -1,    -1,    -1,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    -1,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    -1,
      88,    89,    90,    91,    92,    93,    94,    95,    -1,    -1,
      98,    99,    -1,    -1,    -1,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,    -1,    -1,   116,    -1,
     118,   119,   120,   121,    -1,   123,    -1,    -1,    -1,   127,
     128,   129,   130,   131,    -1,    -1,    -1,    -1,    -1,    -1,
     138,   139,   140,   141,   142,   143,   144,    -1,    -1,    -1,
     148,   149,   150,   151,   152,    -1,    -1,    -1,    -1,   157,
     158,   159,   160,   161,   162,   163,   164,   165,    -1,   167,
     168,    -1,    -1,   171,   172,   173,    -1,    -1,    -1,   177,
      -1,   179,   180,   181,    -1,   183,   184,   185,    -1,   187,
      -1,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,    -1,    -1,   202,   203,   204,    -1,   206,   207,
      -1,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,    -1,   252,   253,   254,    -1,   256,   257,
     258,   259,   260,   261,    -1,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    -1,    88,    89,    90,    91,    92,    93,    94,
      95,    -1,    -1,    98,    99,    -1,    -1,    -1,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,    -1,
      -1,   116,    -1,   118,   119,   120,   121,    -1,   123,    -1,
      -1,    -1,   127,   128,   129,   130,   131,    -1,    -1,    -1,
      -1,    -1,    -1,   138,   139,   140,   141,   142,   143,   144,
      -1,    -1,    -1,   148,   149,   150,   151,   152,    -1,    -1,
      -1,    -1,   157,   158,   159,   160,   161,   162,   163,   164,
     165,    -1,   167,   168,    -1,    -1,   171,   172,   173,    -1,
      -1,    -1,   177,   178,   179,   180,   181,    -1,   183,   184,
     185,    -1,   187,    -1,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,    -1,    -1,   202,   203,   204,
      -1,   206,   207,    -1,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,    -1,   252,   253,   254,
      -1,   256,   257,   258,   259,   260,   261,    -1,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,
      -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    -1,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    -1,    88,    89,    90,    91,
      92,    93,    94,    95,    -1,    -1,    98,    99,    -1,    -1,
      -1,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,    -1,    -1,   116,    -1,   118,   119,   120,   121,
      -1,   123,    -1,    -1,    -1,   127,   128,   129,   130,   131,
      -1,    -1,    -1,    -1,    -1,    -1,   138,   139,   140,   141,
     142,   143,   144,    -1,    -1,    -1,   148,   149,   150,   151,
     152,    -1,    -1,    -1,    -1,   157,   158,   159,   160,   161,
     162,   163,   164,   165,    -1,   167,   168,    -1,    -1,   171,
     172,   173,    -1,   175,    -1,   177,    -1,   179,   180,   181,
      -1,   183,   184,   185,    -1,   187,    -1,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,    -1,    -1,
     202,   203,   204,    -1,   206,   207,    -1,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,    -1,
     252,   253,   254,    -1,   256,   257,   258,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      -1,    20,    -1,    -1,    -1,    -1,    25,    26,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    -1,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    -1,    88,
      89,    90,    91,    92,    93,    94,    95,    -1,    -1,    98,
      99,    -1,    -1,    -1,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,    -1,    -1,   116,    -1,   118,
     119,   120,   121,    -1,   123,    -1,    -1,    -1,   127,   128,
     129,   130,   131,    -1,    -1,    -1,    -1,    -1,    -1,   138,
     139,   140,   141,   142,   143,   144,    -1,    -1,    -1,   148,
     149,   150,   151,   152,    -1,    -1,    -1,    -1,   157,   158,
     159,   160,   161,   162,   163,   164,   165,    -1,   167,   168,
      -1,    -1,   171,   172,   173,    -1,    -1,    -1,   177,   178,
     179,   180,   181,    -1,   183,   184,   185,    -1,   187,    -1,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,    -1,    -1,   202,   203,   204,    -1,   206,   207,    -1,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,    -1,   252,   253,   254,    -1,   256,   257,   258,
     259,   260,   261,    -1,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,    25,
      26,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    -1,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    -1,    88,    89,    90,    91,    92,    93,    94,    95,
      -1,    -1,    98,    99,    -1,    -1,    -1,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,    -1,    -1,
     116,    -1,   118,   119,   120,   121,    -1,   123,    -1,    -1,
      -1,   127,   128,   129,   130,   131,    -1,    -1,    -1,    -1,
      -1,    -1,   138,   139,   140,   141,   142,   143,   144,    -1,
      -1,    -1,   148,   149,   150,   151,   152,    -1,    -1,    -1,
      -1,   157,   158,   159,   160,   161,   162,   163,   164,   165,
      -1,   167,   168,    -1,    -1,   171,   172,   173,    -1,    -1,
      -1,   177,   178,   179,   180,   181,    -1,   183,   184,   185,
      -1,   187,    -1,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,    -1,    -1,   202,   203,   204,    -1,
     206,   207,    -1,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,    -1,   252,   253,   254,    -1,
     256,   257,   258,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,
      -1,    -1,    25,    26,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      -1,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    -1,    88,    89,    90,    91,    92,
      93,    94,    95,    -1,    -1,    98,    99,    -1,    -1,    -1,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,    -1,    -1,   116,    -1,   118,   119,   120,   121,    -1,
     123,    -1,    -1,    -1,   127,   128,   129,   130,   131,    -1,
      -1,    -1,    -1,    -1,    -1,   138,   139,   140,   141,   142,
     143,   144,    -1,    -1,    -1,   148,   149,   150,   151,   152,
      -1,    -1,    -1,    -1,   157,   158,   159,   160,   161,   162,
     163,   164,   165,    -1,   167,   168,    -1,    -1,   171,   172,
     173,    -1,   175,    -1,   177,    -1,   179,   180,   181,    -1,
     183,   184,   185,    -1,   187,    -1,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,    -1,    -1,   202,
     203,   204,    -1,   206,   207,    -1,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,    -1,   252,
     253,   254,    -1,   256,   257,   258,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,
      20,    -1,    -1,    -1,    -1,    25,    26,    -1,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    -1,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    -1,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    -1,    88,    89,
      90,    91,    92,    93,    94,    95,    -1,    -1,    98,    99,
      -1,    -1,    -1,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,    -1,    -1,   116,    -1,   118,   119,
     120,   121,    -1,   123,    -1,    -1,    -1,   127,   128,   129,
     130,   131,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,
     140,   141,   142,   143,   144,    -1,    -1,    -1,   148,   149,
     150,   151,   152,    -1,    -1,    -1,    -1,   157,   158,   159,
     160,   161,   162,   163,   164,   165,    -1,   167,   168,    -1,
      -1,   171,   172,   173,    -1,   175,    -1,   177,    -1,   179,
     180,   181,    -1,   183,   184,   185,    -1,   187,    -1,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
      -1,    -1,   202,   203,   204,    -1,   206,   207,    -1,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,    -1,   252,   253,   254,    -1,   256,   257,   258,   259,
     260,   261,    -1,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    20,    -1,    -1,    -1,    -1,    25,    26,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    -1,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      -1,    88,    89,    90,    91,    92,    93,    94,    95,    -1,
      -1,    98,    99,    -1,    -1,    -1,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,    -1,    -1,   116,
      -1,   118,   119,   120,   121,    -1,   123,    -1,    -1,    -1,
     127,   128,   129,   130,   131,    -1,    -1,    -1,    -1,    -1,
      -1,   138,   139,   140,   141,   142,   143,   144,    -1,    -1,
      -1,   148,   149,   150,   151,   152,    -1,    -1,    -1,    -1,
     157,   158,   159,   160,   161,   162,   163,   164,   165,    -1,
     167,   168,    -1,    -1,   171,   172,   173,    -1,   175,    -1,
     177,    -1,   179,   180,   181,    -1,   183,   184,   185,    -1,
     187,    -1,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,    -1,    -1,   202,   203,   204,    -1,   206,
     207,    -1,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,    -1,   252,   253,   254,    -1,   256,
     257,   258,   259,   260,   261,    -1,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,
      -1,    25,    26,    -1,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    -1,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    -1,    88,    89,    90,    91,    92,    93,
      94,    95,    -1,    -1,    98,    99,    -1,    -1,    -1,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
      -1,    -1,   116,    -1,   118,   119,   120,   121,    -1,   123,
      -1,    -1,    -1,   127,   128,   129,   130,   131,    -1,    -1,
      -1,    -1,    -1,    -1,   138,   139,   140,   141,   142,   143,
     144,    -1,    -1,    -1,   148,   149,   150,   151,   152,    -1,
      -1,    -1,    -1,   157,   158,   159,   160,   161,   162,   163,
     164,   165,    -1,   167,   168,    -1,    -1,   171,   172,   173,
      -1,   175,    -1,   177,    -1,   179,   180,   181,    -1,   183,
     184,   185,    -1,   187,    -1,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,    -1,    -1,   202,   203,
     204,    -1,   206,   207,    -1,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,    -1,   252,   253,
     254,    -1,   256,   257,   258,   259,   260,   261,    -1,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,
      -1,    -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    -1,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    -1,    88,    89,    90,
      91,    92,    93,    94,    95,    -1,    -1,    98,    99,    -1,
      -1,    -1,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,    -1,    -1,   116,    -1,   118,   119,   120,
     121,    -1,   123,    -1,    -1,    -1,   127,   128,   129,   130,
     131,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,   140,
     141,   142,   143,   144,    -1,    -1,    -1,   148,   149,   150,
     151,   152,    -1,    -1,    -1,    -1,   157,   158,   159,   160,
     161,   162,   163,   164,   165,    -1,   167,   168,    -1,    -1,
     171,   172,   173,    -1,   175,    -1,   177,    -1,   179,   180,
     181,    -1,   183,   184,   185,    -1,   187,    -1,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,    -1,
      -1,   202,   203,   204,    -1,   206,   207,    -1,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
      -1,   252,   253,   254,    -1,   256,   257,   258,   259,   260,
     261,    -1,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    20,    -1,    -1,    -1,    -1,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    -1,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    -1,
      88,    89,    90,    91,    92,    93,    94,    95,    -1,    -1,
      98,    99,    -1,    -1,    -1,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,    -1,    -1,   116,    -1,
     118,   119,   120,   121,    -1,   123,    -1,    -1,    -1,   127,
     128,   129,   130,   131,    -1,    -1,    -1,    -1,    -1,    -1,
     138,   139,   140,   141,   142,   143,   144,    -1,    -1,    -1,
     148,   149,   150,   151,   152,    -1,    -1,    -1,    -1,   157,
     158,   159,   160,   161,   162,   163,   164,   165,    -1,   167,
     168,    -1,    -1,   171,   172,   173,    -1,   175,    -1,   177,
      -1,   179,   180,   181,    -1,   183,   184,   185,    -1,   187,
      -1,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,    -1,    -1,   202,   203,   204,    -1,   206,   207,
      -1,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,    -1,   252,   253,   254,    -1,   256,   257,
     258,   259,   260,   261,    -1,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    -1,    88,    89,    90,    91,    92,    93,    94,
      95,    -1,    -1,    98,    99,    -1,    -1,    -1,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,    -1,
      -1,   116,    -1,   118,   119,   120,   121,    -1,   123,    -1,
      -1,    -1,   127,   128,   129,   130,   131,    -1,    -1,    -1,
      -1,    -1,    -1,   138,   139,   140,   141,   142,   143,   144,
      -1,    -1,    -1,   148,   149,   150,   151,   152,    -1,    -1,
      -1,    -1,   157,   158,   159,   160,   161,   162,   163,   164,
     165,    -1,   167,   168,    -1,    -1,   171,   172,   173,    -1,
      -1,    -1,   177,    -1,   179,   180,   181,    -1,   183,   184,
     185,    -1,   187,    -1,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,    -1,    -1,   202,   203,   204,
      -1,   206,   207,    -1,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,    -1,   252,   253,   254,
      -1,   256,   257,   258,   259,   260,   261,    -1,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,
      -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    -1,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    -1,    88,    89,    90,    91,
      92,    93,    94,    95,    -1,    -1,    98,    99,    -1,    -1,
      -1,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,    -1,    -1,   116,    -1,   118,   119,   120,   121,
      -1,   123,    -1,    -1,    -1,   127,   128,   129,   130,   131,
      -1,    -1,    -1,    -1,    -1,    -1,   138,   139,   140,   141,
     142,   143,   144,    -1,    -1,    -1,   148,   149,   150,   151,
     152,    -1,    -1,    -1,    -1,   157,   158,   159,   160,   161,
     162,   163,   164,   165,    -1,   167,   168,    -1,    -1,   171,
     172,   173,    -1,    -1,    -1,   177,    -1,   179,   180,   181,
      -1,   183,   184,   185,    -1,   187,    -1,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,    -1,    -1,
     202,   203,   204,    -1,   206,   207,    -1,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,    -1,
     252,   253,   254,    -1,   256,   257,   258,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      -1,    20,    -1,    -1,    -1,    -1,    25,    26,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    -1,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    -1,    88,
      89,    90,    91,    92,    93,    94,    95,    -1,    -1,    98,
      99,    -1,    -1,    -1,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,    -1,    -1,   116,    -1,   118,
     119,   120,   121,    -1,   123,    -1,    -1,    -1,   127,   128,
     129,   130,   131,    -1,    -1,    -1,    -1,    -1,    -1,   138,
     139,   140,   141,   142,   143,   144,    -1,    -1,    -1,   148,
     149,   150,   151,   152,    -1,    -1,    -1,    -1,   157,   158,
     159,   160,   161,   162,   163,   164,   165,    -1,   167,   168,
      -1,    -1,   171,   172,   173,    -1,    -1,    -1,   177,    -1,
     179,   180,   181,    -1,   183,   184,   185,    -1,   187,    -1,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,    -1,    -1,   202,   203,   204,    -1,   206,   207,    -1,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,    -1,   252,   253,   254,    -1,   256,   257,   258,
     259,   260,   261,    -1,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,    25,
      26,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    -1,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    -1,    88,    89,    90,    91,    92,    93,    94,    95,
      -1,    -1,    98,    99,    -1,    -1,    -1,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,    -1,    -1,
     116,    -1,   118,   119,   120,   121,    -1,   123,    -1,    -1,
      -1,   127,   128,   129,   130,   131,    -1,    -1,    -1,    -1,
      -1,    -1,   138,   139,   140,   141,   142,   143,   144,    -1,
      -1,    -1,   148,   149,   150,   151,   152,    -1,    -1,    -1,
      -1,   157,   158,   159,   160,   161,   162,   163,   164,   165,
      -1,   167,   168,    -1,    -1,   171,   172,   173,    -1,    -1,
      -1,   177,    -1,   179,   180,   181,    -1,   183,   184,   185,
      -1,   187,    -1,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,    -1,    -1,   202,   203,   204,    -1,
     206,   207,    -1,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,    -1,   252,   253,   254,    -1,
     256,   257,   258,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,
      -1,    -1,    25,    26,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      -1,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    -1,    88,    89,    90,    91,    92,
      93,    94,    95,    -1,    -1,    98,    99,    -1,    -1,    -1,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,    -1,    -1,   116,    -1,   118,   119,   120,   121,    -1,
     123,    -1,    -1,    -1,   127,   128,   129,   130,   131,    -1,
      -1,    -1,    -1,    -1,    -1,   138,   139,   140,   141,   142,
     143,   144,    -1,    -1,    -1,   148,   149,   150,   151,   152,
      -1,    -1,    -1,    -1,   157,   158,   159,   160,   161,   162,
     163,   164,   165,    -1,   167,   168,    -1,    -1,   171,   172,
     173,    -1,    -1,    -1,   177,    -1,   179,   180,   181,    -1,
     183,   184,   185,    -1,   187,    -1,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,    -1,    -1,   202,
     203,   204,    -1,   206,   207,    -1,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,    -1,   252,
     253,   254,    -1,   256,   257,   258,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,
      20,    -1,    -1,    -1,    -1,    25,    26,    -1,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    -1,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    -1,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    -1,    88,    89,
      90,    91,    92,    93,    94,    95,    -1,    -1,    98,    99,
      -1,    -1,    -1,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,    -1,    -1,   116,    -1,   118,   119,
     120,   121,    -1,   123,    -1,    -1,    -1,   127,   128,   129,
     130,   131,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,
     140,   141,   142,   143,   144,    -1,    -1,    -1,   148,   149,
      -1,   151,   152,    -1,    -1,    -1,    -1,   157,   158,   159,
     160,   161,   162,   163,   164,   165,    -1,    -1,    -1,    -1,
      -1,   171,   172,   173,    -1,    -1,    -1,   177,    -1,   179,
     180,   181,    -1,   183,   184,   185,    -1,   187,    -1,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
      -1,    -1,   202,   203,   204,    -1,   206,   207,    -1,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,    -1,   252,   253,   254,    -1,   256,   257,   258,   259,
     260,   261,    -1,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    20,    -1,    -1,    -1,    -1,    25,    26,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    -1,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      -1,    88,    89,    90,    91,    92,    93,    94,    95,    -1,
      -1,    98,    99,    -1,    -1,    -1,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,    -1,    -1,   116,
      -1,   118,   119,   120,   121,    -1,   123,    -1,    -1,    -1,
     127,   128,   129,   130,   131,    -1,    -1,    -1,    -1,    -1,
      -1,   138,   139,   140,   141,   142,   143,   144,    -1,    -1,
      -1,   148,   149,    -1,   151,   152,    -1,    -1,    -1,    -1,
     157,   158,   159,   160,   161,   162,   163,   164,   165,    -1,
      -1,    -1,    -1,    -1,   171,   172,   173,    -1,    -1,    -1,
     177,    -1,   179,   180,   181,    -1,    -1,    -1,   185,    -1,
     187,    -1,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,    -1,    -1,   202,   203,   204,    -1,   206,
     207,    -1,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,    -1,   252,   253,   254,    -1,   256,
     257,   258,   259,   260,   261,    -1,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    -1,    -1,    -1,    -1,    -1,
      -1,    25,    26,    -1,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    -1,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    -1,    88,    89,    90,    91,    -1,    93,
      94,    95,    -1,    -1,    98,    99,    -1,    -1,    -1,    -1,
     104,   105,   106,   107,   108,   109,   110,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   118,   119,   120,   121,    -1,   123,
      -1,    -1,    -1,   127,   128,   129,   130,   131,    -1,    -1,
      -1,    -1,    -1,    -1,   138,   139,   140,    -1,   142,   143,
     144,    -1,    -1,    -1,    -1,    -1,    -1,   151,   152,    -1,
      -1,    -1,    -1,   157,   158,   159,   160,   161,   162,   163,
     164,    -1,    -1,    -1,    -1,    -1,    -1,   171,   172,   173,
      -1,    -1,    -1,   177,    -1,   179,   180,   181,    -1,    -1,
      -1,   185,    -1,   187,    -1,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,    -1,    -1,   202,   203,
      -1,    -1,   206,   207,    -1,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,    -1,   252,   253,
     254,    -1,   256,   257,   258,   259,   260,   261,    -1,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    -1,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    -1,    88,    89,    90,
      91,    -1,    93,    94,    95,    -1,    -1,    98,    99,    -1,
      -1,    -1,    -1,   104,   105,   106,   107,   108,   109,   110,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,   119,   120,
     121,    -1,   123,    -1,    -1,    -1,   127,   128,   129,   130,
     131,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,   140,
      -1,   142,   143,   144,    -1,    -1,    -1,    -1,    -1,    -1,
     151,   152,    -1,    -1,    -1,    -1,   157,   158,   159,   160,
     161,   162,   163,   164,    -1,    -1,    -1,    -1,    -1,    -1,
     171,   172,   173,    -1,    -1,    -1,   177,    -1,   179,    -1,
     181,    -1,    -1,    -1,   185,    -1,   187,    -1,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,    -1,
      -1,   202,   203,    -1,    -1,   206,   207,    -1,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
      -1,   252,   253,   254,    -1,   256,   257,   258,   259,   260,
     261,    -1,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,    14,    -1,    -1,    -1,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    -1,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    -1,    88,    89,    90,    91,
      -1,    93,    94,    95,    -1,    -1,    98,    99,    -1,    -1,
      -1,    -1,   104,   105,   106,   107,   108,   109,   110,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   118,   119,   120,   121,
      -1,   123,    -1,    -1,    -1,   127,   128,   129,   130,   131,
      -1,    -1,    -1,    -1,    -1,    -1,   138,   139,   140,    -1,
     142,   143,   144,   145,    -1,    -1,   148,    -1,    -1,   151,
     152,    -1,    -1,    -1,    -1,   157,   158,   159,   160,   161,
     162,   163,   164,    -1,    -1,    -1,    -1,    -1,    -1,   171,
     172,   173,    -1,    -1,    -1,   177,    -1,   179,    -1,   181,
      -1,    -1,    -1,    -1,    -1,   187,    -1,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,    -1,    -1,
     202,   203,    -1,    -1,   206,   207,    -1,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,    -1,
     252,   253,   254,    -1,   256,   257,   258,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,    14,    -1,    -1,    -1,    18,    -1,    20,    -1,    -1,
      -1,    -1,    25,    26,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      -1,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    -1,    88,    89,    90,    91,    -1,
      93,    94,    95,    -1,    -1,    98,    99,    -1,    -1,    -1,
      -1,   104,   105,   106,   107,   108,   109,   110,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   118,   119,   120,   121,    -1,
     123,    -1,    -1,    -1,   127,   128,   129,   130,   131,    -1,
      -1,    -1,    -1,    -1,    -1,   138,   139,   140,    -1,   142,
     143,   144,    -1,    -1,    -1,    -1,    -1,    -1,   151,   152,
      -1,    -1,    -1,    -1,   157,   158,   159,   160,   161,   162,
     163,   164,    -1,    -1,    -1,    -1,    -1,    -1,   171,   172,
     173,    -1,    -1,    -1,   177,   178,   179,    -1,   181,    -1,
      -1,    -1,    -1,    -1,   187,    -1,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,    -1,    -1,   202,
     203,    -1,    -1,   206,   207,    -1,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,    -1,   252,
     253,   254,    -1,   256,   257,   258,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
      14,    -1,    -1,    -1,    18,    -1,    -1,    -1,    -1,    -1,
      -1,    25,    26,    -1,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    -1,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    -1,    88,    89,    90,    91,    -1,    93,
      94,    95,    -1,    -1,    98,    99,    -1,    -1,    -1,    -1,
     104,   105,   106,   107,   108,   109,   110,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   118,   119,   120,   121,    -1,   123,
      -1,    -1,    -1,   127,   128,   129,   130,   131,    -1,    -1,
      -1,    -1,    -1,    -1,   138,   139,   140,    -1,   142,   143,
     144,    -1,    -1,    -1,    -1,    -1,    -1,   151,   152,    -1,
      -1,    -1,    -1,   157,   158,   159,   160,   161,   162,   163,
     164,    -1,    -1,    -1,    -1,    -1,    -1,   171,   172,   173,
      -1,    -1,    -1,   177,    -1,   179,    -1,   181,    -1,    -1,
      -1,    -1,    -1,   187,    -1,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,    -1,    -1,   202,   203,
      -1,    -1,   206,   207,    -1,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,    -1,   252,   253,
     254,    -1,   256,   257,   258,   259,   260,   261,    -1,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,    16,
      -1,    18,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    -1,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      -1,    88,    89,    90,    91,    -1,    93,    94,    95,    -1,
      -1,    98,    99,    -1,    -1,    -1,    -1,   104,   105,   106,
     107,   108,   109,   110,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   118,   119,   120,   121,    -1,   123,    -1,    -1,    -1,
     127,   128,   129,   130,   131,    -1,    -1,    -1,    -1,    -1,
      -1,   138,   139,   140,    -1,   142,   143,   144,    -1,    -1,
      -1,    -1,    -1,    -1,   151,   152,    -1,    -1,    -1,    -1,
     157,   158,   159,   160,   161,   162,   163,   164,    -1,    -1,
      -1,    -1,    -1,    -1,   171,   172,   173,    -1,    -1,    -1,
     177,    -1,   179,    -1,   181,    -1,    -1,    -1,    -1,    -1,
     187,    -1,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,    -1,    -1,   202,   203,    -1,    -1,   206,
     207,    -1,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,    -1,   252,   253,   254,    -1,   256,
     257,   258,   259,   260,   261,    -1,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    -1,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    -1,    88,    89,    90,    91,
      -1,    93,    94,    95,    -1,    -1,    98,    99,    -1,    -1,
      -1,    -1,   104,   105,   106,   107,   108,   109,   110,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   118,   119,   120,   121,
      -1,   123,    -1,    -1,    -1,   127,   128,   129,   130,   131,
      -1,    -1,    -1,    -1,    -1,    -1,   138,   139,   140,    -1,
     142,   143,   144,    -1,    -1,    -1,   148,    -1,    -1,   151,
     152,    -1,    -1,    -1,    -1,   157,   158,   159,   160,   161,
     162,   163,   164,    -1,    -1,    -1,    -1,    -1,    -1,   171,
     172,   173,    -1,    -1,    -1,   177,   178,   179,   180,   181,
      -1,    -1,    -1,   185,    -1,   187,    -1,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,    -1,    -1,
     202,   203,    -1,    -1,   206,   207,    -1,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,    -1,
     252,   253,   254,    -1,   256,   257,   258,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,    18,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    -1,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      -1,    88,    89,    90,    91,    -1,    93,    94,    95,    -1,
      -1,    98,    99,    -1,    -1,    -1,    -1,   104,   105,   106,
     107,   108,   109,   110,    -1,    -1,    -1,   114,    -1,    -1,
      -1,   118,   119,   120,   121,    -1,   123,    -1,    -1,    -1,
     127,   128,   129,   130,   131,    -1,    -1,    -1,    -1,    -1,
      -1,   138,   139,   140,    -1,   142,   143,   144,   145,    -1,
      -1,   148,    -1,    -1,   151,   152,    -1,    -1,    -1,    -1,
     157,   158,   159,   160,   161,   162,   163,   164,    -1,    -1,
      -1,    -1,    -1,    -1,   171,   172,   173,    -1,    -1,    -1,
     177,    -1,   179,    -1,   181,    -1,    -1,    -1,    -1,    -1,
     187,    -1,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,    -1,    -1,   202,   203,    -1,    -1,   206,
     207,    -1,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,    -1,   252,   253,   254,    -1,   256,
     257,   258,   259,   260,   261,    -1,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    -1,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    -1,    88,    89,    90,    91,
      -1,    93,    94,    95,    -1,    -1,    98,    99,    -1,    -1,
      -1,    -1,   104,   105,   106,   107,   108,   109,   110,   111,
      -1,    -1,    -1,    -1,    -1,    -1,   118,   119,   120,   121,
      -1,   123,    -1,    -1,    -1,   127,   128,   129,   130,   131,
      -1,    -1,    -1,    -1,    -1,    -1,   138,   139,   140,    -1,
     142,   143,   144,    -1,    -1,    -1,   148,    -1,    -1,   151,
     152,    -1,    -1,    -1,    -1,   157,   158,   159,   160,   161,
     162,   163,   164,    -1,    -1,    -1,    -1,    -1,    -1,   171,
     172,   173,    -1,    -1,    -1,   177,    -1,   179,   180,   181,
      -1,    -1,    -1,    -1,    -1,   187,    -1,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,    -1,    -1,
     202,   203,    -1,    -1,   206,   207,    -1,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,    -1,
     252,   253,   254,    -1,   256,   257,   258,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,    18,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    -1,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      -1,    88,    89,    90,    91,    -1,    93,    94,    95,    -1,
      -1,    98,    99,    -1,    -1,    -1,    -1,   104,   105,   106,
     107,   108,   109,   110,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   118,   119,   120,   121,    -1,   123,    -1,    -1,    -1,
     127,   128,   129,   130,   131,    -1,    -1,    -1,    -1,    -1,
      -1,   138,   139,   140,    -1,   142,   143,   144,   145,    -1,
      -1,   148,    -1,    -1,   151,   152,    -1,    -1,    -1,    -1,
     157,   158,   159,   160,   161,   162,   163,   164,    -1,    -1,
      -1,    -1,    -1,    -1,   171,   172,   173,    -1,    -1,    -1,
     177,    -1,   179,    -1,   181,    -1,    -1,    -1,    -1,    -1,
     187,    -1,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,    -1,    -1,   202,   203,    -1,    -1,   206,
     207,    -1,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,    -1,   252,   253,   254,    -1,   256,
     257,   258,   259,   260,   261,    -1,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    -1,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    -1,    88,    89,    90,    91,
      -1,    93,    94,    95,    -1,    -1,    98,    99,    -1,    -1,
      -1,    -1,   104,   105,   106,   107,   108,   109,   110,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   118,   119,   120,   121,
      -1,   123,    -1,    -1,    -1,   127,   128,   129,   130,   131,
      -1,    -1,    -1,    -1,    -1,    -1,   138,   139,   140,    -1,
     142,   143,   144,    -1,    -1,    -1,    -1,    -1,    -1,   151,
     152,    -1,    -1,    -1,    -1,   157,   158,   159,   160,   161,
     162,   163,   164,    -1,    -1,    -1,    -1,    -1,    -1,   171,
     172,   173,    -1,    -1,    -1,   177,   178,   179,    -1,   181,
      -1,    -1,    -1,   185,    -1,   187,    -1,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,    -1,    -1,
     202,   203,    -1,    -1,   206,   207,    -1,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,    -1,
     252,   253,   254,    -1,   256,   257,   258,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,    18,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    -1,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      -1,    88,    89,    90,    91,    -1,    93,    94,    95,    -1,
      -1,    98,    99,    -1,    -1,    -1,    -1,   104,   105,   106,
     107,   108,   109,   110,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   118,   119,   120,   121,    -1,   123,    -1,    -1,    -1,
     127,   128,   129,   130,   131,    -1,    -1,    -1,    -1,    -1,
      -1,   138,   139,   140,    -1,   142,   143,   144,    -1,    -1,
      -1,    -1,    -1,    -1,   151,   152,    -1,    -1,    -1,    -1,
     157,   158,   159,   160,   161,   162,   163,   164,    -1,    -1,
      -1,    -1,    -1,    -1,   171,   172,   173,    -1,    -1,    -1,
     177,   178,   179,    -1,   181,    -1,    -1,    -1,   185,    -1,
     187,    -1,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,    -1,    -1,   202,   203,    -1,    -1,   206,
     207,    -1,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,    -1,   252,   253,   254,    -1,   256,
     257,   258,   259,   260,   261,    -1,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    -1,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    -1,    88,    89,    90,    91,
      -1,    93,    94,    95,    -1,    -1,    98,    99,    -1,    -1,
      -1,    -1,   104,   105,   106,   107,   108,   109,   110,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   118,   119,   120,   121,
      -1,   123,    -1,    -1,    -1,   127,   128,   129,   130,   131,
      -1,    -1,    -1,    -1,    -1,    -1,   138,   139,   140,    -1,
     142,   143,   144,    -1,    -1,    -1,   148,    -1,    -1,   151,
     152,    -1,    -1,    -1,    -1,   157,   158,   159,   160,   161,
     162,   163,   164,    -1,    -1,    -1,    -1,    -1,    -1,   171,
     172,   173,    -1,    -1,    -1,   177,    -1,   179,   180,   181,
      -1,    -1,    -1,    -1,    -1,   187,    -1,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,    -1,    -1,
     202,   203,    -1,    -1,   206,   207,    -1,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,    -1,
     252,   253,   254,    -1,   256,   257,   258,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,    18,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    -1,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      -1,    88,    89,    90,    91,    -1,    93,    94,    95,    -1,
      -1,    98,    99,    -1,    -1,    -1,    -1,   104,   105,   106,
     107,   108,   109,   110,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   118,   119,   120,   121,    -1,   123,    -1,    -1,    -1,
     127,   128,   129,   130,   131,    -1,    -1,    -1,    -1,    -1,
      -1,   138,   139,   140,    -1,   142,   143,   144,    -1,    -1,
      -1,   148,    -1,    -1,   151,   152,    -1,    -1,    -1,    -1,
     157,   158,   159,   160,   161,   162,   163,   164,    -1,    -1,
      -1,    -1,    -1,    -1,   171,   172,   173,    -1,    -1,    -1,
     177,    -1,   179,   180,   181,    -1,    -1,    -1,    -1,    -1,
     187,    -1,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,    -1,    -1,   202,   203,    -1,    -1,   206,
     207,    -1,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,    -1,   252,   253,   254,    -1,   256,
     257,   258,   259,   260,   261,    -1,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    -1,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    -1,    88,    89,    90,    91,
      -1,    93,    94,    95,    -1,    -1,    98,    99,    -1,    -1,
      -1,    -1,   104,   105,   106,   107,   108,   109,   110,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   118,   119,   120,   121,
      -1,   123,    -1,    -1,    -1,   127,   128,   129,   130,   131,
      -1,    -1,    -1,    -1,    -1,    -1,   138,   139,   140,    -1,
     142,   143,   144,    -1,    -1,    -1,    -1,    -1,    -1,   151,
     152,    -1,    -1,    -1,    -1,   157,   158,   159,   160,   161,
     162,   163,   164,    -1,    -1,    -1,    -1,    -1,    -1,   171,
     172,   173,    -1,    -1,    -1,   177,    -1,   179,    -1,   181,
      -1,    -1,    -1,    -1,    -1,   187,    -1,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,    -1,    -1,
     202,   203,    -1,    -1,   206,   207,    -1,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,    -1,
     252,   253,   254,    -1,   256,   257,   258,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  xquery_parser::yystos_[] =
  {
         0,     3,    10,    17,    18,    20,    25,    26,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    88,    89,    90,    91,    92,
      93,    94,    95,    98,    99,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   116,   118,   119,   120,
     121,   123,   127,   128,   129,   130,   131,   138,   139,   140,
     141,   142,   143,   144,   148,   149,   150,   151,   152,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   167,   168,
     171,   172,   173,   177,   179,   180,   181,   183,   184,   185,
     187,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   202,   203,   204,   206,   207,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   252,
     253,   254,   256,   257,   258,   259,   260,   261,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   334,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   349,   350,   355,   358,   361,
     364,   365,   367,   372,   373,   374,   375,   376,   385,   386,
     388,   389,   390,   395,   397,   399,   400,   401,   406,   427,
     430,   434,   437,   438,   439,   440,   442,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   488,   489,   490,   504,
     505,   507,   508,   509,   510,   511,   512,   513,   521,   522,
     523,   524,   525,   526,   527,   528,   529,   530,   533,   534,
     535,   536,   541,   542,   543,   544,   545,   546,   549,   555,
     609,   610,    28,    29,    31,    32,    34,    40,    48,    50,
      51,    58,    60,    69,    73,   104,   105,   106,   152,   161,
     193,   212,   222,   254,   280,   281,   282,   283,   284,   286,
     287,   288,   289,   290,   295,   296,   356,   357,   377,   378,
     379,   380,   152,   145,   148,   145,   148,    25,    26,    30,
      35,    36,    37,    38,    39,    40,    41,    42,    44,    52,
      54,    57,    59,    62,    65,    67,    68,    70,    84,    85,
      91,    98,   107,   108,   127,   130,   131,   145,   148,   161,
     164,   171,   172,   181,   193,   206,   216,   217,   218,   220,
     221,   228,   230,   231,   232,   233,   236,   237,   239,   609,
     145,    61,    66,   111,   392,   148,   366,   148,    26,    55,
     111,    39,    14,   145,   148,   554,   609,   148,   111,   111,
     145,   148,   148,   148,    88,   145,   213,   214,   114,   114,
     114,   145,   148,   609,    30,    37,    54,    65,    91,   472,
     609,   114,   114,   114,   609,   111,   114,   114,   178,   386,
     609,   145,   114,   554,    16,   609,   114,   114,   609,   114,
     464,   145,    21,   205,   207,   217,   219,   148,   217,   219,
     217,   217,   222,   111,   145,   368,   234,   234,   235,   148,
     145,   111,   319,   320,     0,   319,   322,   323,    25,    42,
     325,   385,   182,   182,   100,   182,   387,    33,    39,    44,
      52,    64,   160,   163,   177,   203,   391,   396,   397,   398,
     415,   416,   420,   402,   403,   609,   159,    86,   124,   132,
     133,   135,   143,   147,   149,   154,   170,   194,   195,   196,
     197,   198,   199,   456,   457,   242,   150,   167,   190,   110,
     138,   151,   185,   192,   201,   128,   142,    43,   191,    94,
      95,   150,   167,   455,   145,   461,   464,   183,   184,   146,
     476,   477,   472,   476,   472,   148,   476,   137,   148,    20,
     553,   173,   187,   173,   187,   158,   173,   377,   609,   377,
     609,   161,   193,    40,   378,    40,   609,   144,   111,   354,
      37,    40,    73,    99,   160,   554,   213,   214,   215,   293,
     294,   239,   582,   609,   286,   609,   291,   291,   293,   294,
     297,   280,   288,   357,   554,   386,   178,   386,    37,    57,
     178,   529,   530,   386,   178,   185,   609,   145,   389,   277,
     277,   111,   410,   111,   178,   381,   382,   145,   383,   386,
     152,   553,   106,   152,   348,   553,   407,   409,   609,   111,
     386,    20,   178,   554,   145,   609,   609,   428,   429,   609,
     386,   178,   386,   386,   531,   609,   386,   145,   145,   386,
     178,   185,   609,   145,   428,   178,    27,   492,   493,   494,
     386,     7,   166,    15,   178,   386,   205,    20,   389,   389,
     178,   389,   389,   389,   389,   223,   547,   548,   609,   369,
     389,   389,   386,   408,   414,   609,   319,   327,   328,    25,
     329,   389,   388,   111,   160,   162,   162,   389,   389,   100,
      88,    90,   139,   266,   404,   405,   515,   439,   440,   442,
     442,   442,   442,   441,   442,   442,   442,    65,   446,   446,
     445,   447,   447,   447,   447,   448,   448,   449,   449,   223,
      88,    88,    88,   175,   386,   464,   464,   386,   477,   178,
     389,   487,   141,   178,   487,   100,   100,   366,    20,   609,
     609,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,   331,   332,   333,    88,   129,   134,   351,   352,   353,
     609,   129,   134,   152,   152,   331,   553,   119,   124,    47,
      50,    93,   244,   257,   259,   270,   271,   272,   274,   276,
     583,   584,   585,   586,   587,   588,   595,   601,   602,   239,
      88,   229,   360,   292,   609,   609,   609,   124,   175,   175,
     178,   178,   175,   100,   178,   100,   178,   175,   386,   175,
     609,    49,   209,   247,   393,   394,   609,    88,   100,   178,
     386,   178,   554,    90,    37,   554,   553,    90,   100,   134,
     405,   515,   175,   178,   178,   175,   386,   178,   134,   100,
     179,   139,   515,   175,   178,   178,   145,   175,   386,   386,
     175,   100,   178,   100,   178,   175,   386,   179,   609,   493,
     494,   122,   188,   175,   175,   123,   182,    88,   210,   211,
     225,    88,   210,   211,   225,    88,   229,   217,   100,   227,
     134,    25,   370,   386,   178,   175,    38,   100,   182,   106,
     182,   609,   162,   389,   421,   422,   111,   417,   418,   111,
      40,   144,   148,   202,   516,   518,   520,   521,   537,   538,
     539,   540,   609,   111,   389,   111,   139,   405,   139,   139,
     404,   405,   442,   145,   148,   252,   460,   479,   556,   559,
     560,   561,   562,   563,   567,   569,   571,   572,   516,   516,
     514,   520,   514,   175,   176,   100,   178,   178,   140,   157,
     140,   157,   129,   145,   384,   366,   366,   332,   124,   518,
     353,   389,   515,   134,   389,   553,   553,   120,   121,   553,
     270,   271,   272,   276,   609,   256,   267,   256,   267,    20,
     279,    90,   106,   148,   589,   592,   583,    30,    36,    54,
      65,    91,   217,   359,   521,   284,   285,   219,   292,   301,
      88,   360,   292,   553,   145,   531,   532,   609,   531,   532,
     175,   139,   515,   247,    46,    53,    71,   111,   404,   411,
     412,   413,   394,   515,   516,   382,    88,   175,   189,   124,
     347,   553,   152,   124,    90,   347,   111,   389,   134,   134,
     405,   145,   175,   389,   111,   389,   389,   139,    93,   431,
     432,   433,    93,   435,   436,   386,   175,   175,   145,   531,
     531,   175,   389,    27,   494,   122,   188,     8,     9,    96,
     115,   117,   186,   383,   489,   491,   502,   503,   506,    20,
     224,   226,   389,   389,   389,   224,   226,   389,   389,   389,
     389,   389,   389,   111,   389,   389,   354,   371,   100,   182,
     175,   368,   238,   550,   551,   145,   111,   421,    89,    99,
     109,   119,   423,   424,   425,   426,   100,   609,   100,   403,
     148,   148,   518,   148,   136,   167,   185,   517,   609,   609,
     389,   139,   389,   389,   139,   405,   139,   386,   556,   563,
     145,   278,   443,   608,    90,   161,   245,   246,   248,   255,
     265,   277,   557,   558,   577,   578,   579,   580,   603,   606,
     251,   253,   564,   582,   260,   568,   604,   240,   241,   263,
     573,   574,   136,   389,   386,   129,   368,   129,   145,   533,
     352,   389,   279,    20,    90,   106,   148,   596,    20,   589,
     360,   517,   219,   219,   462,   280,   299,   359,   219,   182,
     175,   386,   178,   178,   136,   178,   178,   389,   139,   111,
     111,   389,   609,   413,    71,   516,   389,   553,   100,   347,
     409,   389,   389,   134,   175,   386,   429,   389,   389,   106,
     432,    93,   177,   111,   516,   106,   436,   175,   175,   386,
     178,   178,   124,   186,   491,     6,   609,   186,   502,   182,
     225,   225,   225,   225,   229,   548,   177,   134,   371,   473,
     552,   551,   389,   414,   553,   120,   121,   425,   426,   426,
     422,    99,   419,   418,   178,   185,   516,   519,   178,   178,
     178,   389,   389,   139,   389,   175,   178,   556,   570,   243,
     209,   247,   261,   268,   607,    90,   249,   250,   605,   243,
     560,   607,   445,   577,   561,   139,   275,   565,   566,   605,
     279,   576,    72,   575,   175,   388,    20,   128,   192,   598,
     599,   600,    20,   597,   598,   264,   593,   590,   591,   592,
     162,   609,   250,   360,   462,   175,   389,   609,   609,   412,
     389,   118,    90,   553,   389,   175,   177,   389,   389,   609,
     177,   111,   177,   175,   494,   609,   186,   494,   609,   389,
     389,   389,   389,   389,   389,   389,   148,   201,   384,   175,
     426,   553,    88,   178,   100,   178,   389,   175,   447,    45,
     121,   445,   445,   262,   269,   279,   581,   581,   562,   145,
     273,   175,   596,   596,   600,   100,   178,    20,   594,   605,
     178,   100,   362,   363,   462,   111,   217,   300,   280,   162,
      46,   389,   347,   389,    88,   389,   609,   389,    87,   174,
     495,   494,   609,   188,   494,   111,   473,   516,   516,    88,
     445,   445,   190,   386,    20,   258,   592,   100,    88,   609,
     111,   217,   609,   362,   111,   516,   177,     4,   125,   498,
     499,   501,   503,    19,   126,   496,   497,   500,   503,   188,
     494,   188,   609,   516,   445,   175,   363,   520,   298,   609,
     111,   217,   609,   177,   389,    87,   125,   501,   174,   126,
     500,   188,   100,   178,   426,   389,   298,   609,   111,   389,
     111,   384,   286,   298,   609,   609,   299,   389,   299,   100,
     178,   462,   462,   111,   384,   190,   609,   280,   178,   609,
     384,   217,   111,   609,   299,   462
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
     565,   566,   567,   568,   569,   570,   571
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   317,   318,   318,   318,   318,   318,   318,   319,   320,
     320,   320,   320,   321,   321,   322,   322,   323,   323,   324,
     325,   325,   325,   326,   326,   327,   327,   328,   328,   328,
     328,   329,   329,   329,   329,   329,   329,   329,   329,   329,
     330,   330,   331,   331,   332,   333,   333,   333,   333,   333,
     333,   333,   333,   333,   333,   334,   334,   334,   334,   334,
     334,   334,   334,   335,   335,   336,   337,   337,   338,   338,
     339,   340,   341,   341,   342,   342,   343,   343,   343,   343,
     344,   345,   346,   346,   346,   346,   347,   347,   348,   348,
     349,   349,   349,   349,   350,   351,   351,   352,   352,   352,
     353,   354,   354,   355,   355,   355,   356,   356,   357,   357,
     357,   357,   357,   357,   357,   357,   357,   357,   357,   357,
     357,   357,   358,   358,   358,   358,   358,   358,   358,   358,
     359,   359,   360,   360,   361,   361,   362,   362,   363,   363,
     364,   364,   364,   364,   365,   365,   366,   366,   366,   366,
     367,   368,   369,   369,   370,   370,   371,   371,   372,   373,
     374,   375,   375,   376,   376,   376,   377,   377,   377,   377,
     378,   378,   379,   379,   380,   380,   381,   381,   382,   382,
     383,   384,   385,   386,   386,   387,   387,   388,   388,   389,
     389,   389,   389,   389,   389,   389,   389,   389,   389,   389,
     389,   389,   389,   389,   389,   389,   389,   390,   391,   392,
     392,   393,   393,   393,   394,   394,   395,   395,   396,   397,
     397,   397,   398,   398,   398,   398,   398,   399,   399,   400,
     400,   401,   402,   402,   403,   403,   403,   403,   403,   403,
     403,   403,   404,   405,   406,   407,   407,   408,   408,   409,
     409,   409,   409,   410,   410,   411,   411,   411,   412,   412,
     412,   413,   413,   413,   414,   415,   416,   417,   417,   418,
     418,   419,   420,   420,   421,   421,   422,   422,   423,   423,
     423,   423,   423,   423,   423,   424,   424,   425,   425,   426,
     427,   427,   428,   428,   429,   429,   430,   431,   431,   432,
     433,   433,   434,   434,   435,   435,   436,   436,   437,   438,
     438,   439,   439,   440,   440,   440,   440,   440,   441,   440,
     440,   440,   440,   442,   442,   443,   443,   444,   444,   445,
     445,   445,   446,   446,   446,   446,   446,   447,   447,   447,
     448,   448,   448,   449,   449,   450,   450,   451,   451,   452,
     452,   453,   453,   454,   454,   454,   454,   455,   455,   455,
     456,   456,   456,   456,   456,   456,   457,   457,   457,   458,
     458,   458,   458,   459,   459,   460,   460,   461,   461,   462,
     462,   462,   462,   463,   464,   464,   464,   465,   465,   466,
     466,   466,   466,   467,   467,   468,   468,   468,   468,   468,
     468,   468,   469,   469,   470,   470,   471,   471,   471,   471,
     471,   472,   472,   473,   473,   474,   474,   474,   475,   475,
     475,   475,   476,   476,   477,   478,   478,   478,   478,   478,
     478,   478,   478,   478,   479,   479,   480,   480,   480,   481,
     482,   482,   483,   484,   485,   486,   486,   487,   487,   488,
     488,   489,   489,   489,   490,   490,   490,   490,   490,   490,
     491,   491,   492,   492,   493,   494,   494,   495,   495,   496,
     496,   497,   497,   497,   497,   498,   498,   499,   499,   499,
     499,   500,   500,   501,   501,   502,   502,   502,   502,   503,
     503,   503,   503,   504,   504,   505,   505,   506,   507,   507,
     507,   507,   507,   507,   508,   509,   509,   509,   509,   510,
     510,   510,   510,   511,   512,   513,   513,   513,   513,   514,
     514,   515,   516,   516,   516,   517,   517,   517,   518,   518,
     518,   518,   518,   519,   519,   520,   521,   521,   521,   521,
     521,   521,   521,   521,   521,   522,   523,   523,   523,   524,
     525,   526,   526,   526,   527,   527,   527,   527,   527,   528,
     529,   529,   529,   529,   529,   529,   529,   530,   531,   532,
     533,   534,   534,   535,   536,   537,   537,   538,   539,   539,
     540,   541,   541,   541,   542,   542,   542,   542,   542,   542,
     542,   542,   542,   542,   543,   543,   544,   544,   545,   546,
     547,   547,   548,   549,   550,   550,   551,   551,   551,   551,
     552,   552,   553,   554,   554,   555,   555,   556,   557,   557,
     558,   558,   559,   559,   560,   560,   561,   561,   562,   562,
     563,   564,   564,   565,   565,   566,   567,   567,   567,   568,
     568,   569,   570,   570,   571,   572,   572,   573,   573,   574,
     574,   574,   575,   575,   576,   576,   577,   577,   577,   577,
     577,   578,   579,   580,   581,   581,   581,   582,   582,   583,
     583,   583,   583,   583,   583,   583,   583,   584,   584,   584,
     584,   585,   585,   586,   587,   587,   588,   588,   588,   589,
     589,   590,   590,   591,   591,   592,   593,   593,   594,   594,
     595,   595,   595,   596,   596,   597,   597,   598,   598,   599,
     599,   600,   600,   601,   602,   602,   603,   603,   603,   604,
     605,   605,   605,   605,   606,   606,   607,   607,   608,   609,
     609,   610,   610,   610,   610,   610,   610,   610,   610,   610,
     610,   610,   610,   610,   610,   610,   610,   610,   610,   610,
     610,   610,   610,   610,   610,   610,   610,   610,   610,   610,
     610,   610,   610,   610,   610,   610,   610,   610,   610,   610,
     610,   610,   610,   610,   610,   610,   610,   610,   610,   610,
     610,   610,   610,   610,   610,   610,   610,   610,   610,   610,
     610,   610,   610,   610,   610,   610,   610,   610,   610,   610,
     610,   610,   610,   610,   610,   610,   610,   610,   610,   610,
     610,   610,   610,   610,   610,   610,   610,   610,   610,   610,
     610,   610,   610,   610,   610,   610,   610,   610,   610,   610,
     610,   610,   610,   610,   610,   610,   610,   610,   610,   610,
     610,   610,   610,   610,   610,   610,   610,   610,   610,   610,
     610,   610,   610,   610,   610,   610,   610,   610,   610,   610,
     610,   610,   610,   610,   610,   610,   610,   610,   610,   610,
     610,   610,   610,   610,   610,   610,   610,   610,   610,   610,
     610,   610,   610,   610,   610,   610,   610,   610,   610,   610,
     610,   610,   610,   610,   610,   610,   610,   610,   610,   610,
     610,   610,   610,   610,   610,   610,   610,   610,   610,   610,
     610,   610,   610,   610,   610,   610,   610,   610,   610,   610,
     610,   610,   610,   610,   610,   610,   610,   610,   610,   610,
     610,   610,   610,   610,   610,   610,   610,   610,   610,   610,
     610,   610,   610,   610,   610
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  xquery_parser::yyr2_[] =
  {
         0,     2,     1,     2,     1,     2,     2,     3,     1,     1,
       2,     1,     2,     4,     6,     2,     1,     1,     2,     6,
       2,     2,     4,     1,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     1,     2,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     3,     3,     5,     5,
       4,     3,     3,     3,     5,     5,     5,     5,     5,     5,
       4,     3,     3,     4,     5,     6,     1,     3,     3,     3,
       3,     6,     5,     8,     4,     3,     1,     1,     1,     2,
       2,     2,     3,     5,     4,     6,     1,     2,     1,     1,
       1,     1,     1,     1,     2,     2,     2,     2,     1,     2,
       2,     2,     3,     4,     5,     6,     4,     5,     6,     7,
       1,     2,     3,     3,     8,     9,     1,     3,     3,     4,
      11,    14,    13,    22,     3,     3,     2,     3,     4,     5,
       2,     4,     3,     0,     3,     2,     1,     3,     5,     3,
       5,     2,     2,     2,     3,     3,     1,     2,     1,     1,
       4,     4,     5,     5,     7,     5,     1,     3,     2,     3,
       3,     3,     1,     1,     2,     1,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     2,
       2,     1,     1,     2,     4,     3,     5,     4,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       3,     2,     1,     4,     3,     4,     4,     5,     4,     5,
       5,     6,     3,     3,     3,     1,     4,     1,     4,     3,
       4,     4,     5,     4,     5,     1,     2,     3,     1,     2,
       1,     6,     3,     3,     1,     2,     3,     1,     3,     2,
       3,     2,     3,     4,     1,     3,     1,     2,     1,     1,
       1,     2,     2,     2,     3,     1,     1,     2,     2,     2,
       5,     5,     1,     4,     3,     4,     8,     1,     2,     3,
       2,     3,     8,    10,     1,     2,     4,     7,     8,     1,
       3,     1,     3,     1,     3,     3,     3,     3,     0,     4,
       3,     3,     3,     1,     5,     0,     1,     1,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     1,     4,     1,     4,     1,     4,     1,
       4,     1,     2,     1,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       5,     5,     6,     3,     4,     1,     2,     3,     2,     1,
       2,     2,     1,     1,     1,     3,     3,     1,     1,     1,
       2,     1,     2,     2,     1,     2,     2,     2,     2,     2,
       2,     2,     1,     2,     2,     1,     2,     2,     2,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       3,     4,     1,     2,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     3,     1,     4,     4,     3,     4,     1,     3,     1,
       1,     1,     1,     1,     4,     5,     8,     9,     9,    10,
       1,     2,     1,     2,     6,     0,     1,     3,     3,     0,
       1,     1,     1,     2,     2,     0,     1,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     2,     3,     3,     2,     1,     1,
       1,     1,     1,     1,     4,     4,     5,     6,     7,     4,
       5,     6,     7,     4,     4,     4,     5,     6,     7,     1,
       2,     2,     1,     2,     3,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     4,     4,     3,
       3,     3,     4,     4,     3,     4,     6,     4,     6,     3,
       3,     4,     6,     6,     4,     6,     6,     4,     1,     2,
       1,     1,     1,     3,     3,     1,     1,     4,     5,     6,
       3,     3,     3,     3,     5,     7,     7,     5,     5,     5,
       7,     7,     5,     5,     3,     3,     5,     7,     5,     7,
       1,     4,     3,     5,     1,     2,     3,     7,    10,    13,
       1,     3,     1,     1,     1,     7,     4,     2,     0,     1,
       1,     2,     1,     3,     1,     3,     1,     4,     1,     2,
       3,     0,     1,     0,     1,     4,     2,     3,     1,     0,
       1,     4,     0,     1,     2,     1,     3,     0,     1,     2,
       2,     1,     0,     1,     0,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     1,     1,     1,     2,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     1,
       1,     2,     2,     3,     1,     2,     2,     5,     2,     1,
       1,     0,     1,     1,     3,     4,     0,     2,     0,     2,
       4,     4,     3,     2,     3,     1,     3,     0,     1,     1,
       2,     2,     2,     2,     1,     2,     2,     2,     2,     3,
       2,     3,     3,     4,     2,     2,     1,     1,     3,     1,
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
       1,     1,     1,     1,     1
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const xquery_parser::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined", "\"'unrecognized'\"",
  "\"'apos attribute content'\"", "\"'char literal'\"",
  "\"'char literal]]>'\"", "\"'char literal and pi end'\"",
  "\"'#charref;'\"", "\"'element content'\"", "\"'pref:*'\"",
  "\"'&entity;'\"", "\"'comment literal'\"", "\"'pi <NCName {>'\"",
  "\"'NCName_sval'\"", "\"'pragma literal'\"", "\"'QName #)'\"",
  "\"'*:QName'\"", "\"'QName'\"", "\"'quote attribute content'\"",
  "\"'STRING'\"", "\"'XML comment'\"", "\"'URI'\"", "\"'NCName'\"",
  "\"'KEYWORD'\"", "\"'declare'\"", "\"'module'\"", "\"<blank>\"",
  "\"'base-uri'\"", "\"'boundary-space'\"", "\"'comment'\"",
  "\"'construction'\"", "\"'copy-namespaces'\"", "\"'count'\"",
  "\"'deterministic'\"", "\"'document'\"", "\"'document-node'\"",
  "\"'element'\"", "\"'eval'\"", "\"'for'\"", "\"'function'\"", "\"'if'\"",
  "\"'import'\"", "\"'instance'\"", "\"'let'\"", "\"'most'\"",
  "\"'next'\"", "\"'no'\"", "\"'nondeterministic'\"", "\"'only'\"",
  "\"'option'\"", "\"'ordering'\"", "\"'outer'\"", "\"'previous'\"",
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
  "\"'::'\"", "\"'{{'\"", "\"'DOUBLE'\"", "\"'<double {>'\"", "\"'else'\"",
  "\"'empty'\"", "\"'greatest'\"", "\"'least'\"", "\"'/>'\"",
  "\"'encoding'\"", "\"'='\"", "\"''''\"", "\"'\\\"\\\"'\"", "\"'every'\"",
  "\"'except'\"", "\"'external'\"", "\"'following'\"",
  "\"'following-sibling'\"", "\"'follows'\"", "\"'>='\"", "\"':='\"",
  "\"'>'\"", "\"'?'\"", "\"'#'\"", "\"'idiv'\"", "\"'in'\"",
  "\"'inherit'\"", "\"'INTEGER'\"", "\"'intersect'\"", "\"'is'\"",
  "\"'item'\"", "\"'{'\"", "\"'['\"", "\"'<='\"", "\"'('\"", "\"'<'\"",
  "\"'-'\"", "\"'mod'\"", "\"'namespace'\"", "\"'nan'\"", "\"'!='\"",
  "\"'nodecomp'\"", "\"'?""?'\"", "\"'<no inherit>'\"",
  "\"'<no preserve>'\"", "\"'or'\"", "\"'order'\"", "\"'ordered'\"",
  "\"'by'\"", "\"'group'\"", "\"'parent'\"", "\"'<?'\"", "\"'?>'\"",
  "\"'+'\"", "\"'PRAGMA BEGIN'\"", "\"'PRAGMA END'\"", "\"'<<'\"",
  "\"'preceding'\"", "\"'preceding-sibling'\"", "\"'preserve'\"",
  "\"'\\\"'\"", "\"'}'\"", "\"']'\"", "\"'return'\"", "\"')'\"",
  "\"'satisfies'\"", "\"'<schema attribute ('\"", "\"'self'\"", "\"';'\"",
  "\"'/'\"", "\"'//'\"", "\"'*'\"", "\"</ (start tag end)\"",
  "\"'strip'\"", "\"'> (tag end)'\"", "\"'then'\"", "\"'to'\"",
  "\"'treat'\"", "\"'union'\"", "\"'unordered'\"", "\"'eq'\"", "\"'ge'\"",
  "\"'gt'\"", "\"'le'\"", "\"'lt'\"", "\"'ne'\"", "\"'VALUECOMP'\"",
  "\"'|'\"", "\"'empty-sequence'\"", "\"'where'\"", "\"'<!--'\"",
  "\"'-->'\"", "\"'xquery'\"", "\"'version'\"", "\"'#)'\"", "\"'start'\"",
  "\"'after'\"", "\"'before'\"", "\"'revalidation'\"", "\"'strict'\"",
  "\"'lax'\"", "\"'skip'\"", "\"'delete'\"", "\"'node'\"", "\"'insert'\"",
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
  "STEP_REDUCE", "$accept", "Module", "UnrecognizedToken",
  "ModuleWithoutBOM", "VersionDecl", "MainModule", "LibraryModule",
  "ModuleDecl", "Prolog", "SIND_DeclList", "VFO_DeclList", "SIND_Decl",
  "VFO_Decl", "DecimalFormatDecl", "DecimalFormatParamList",
  "DecimalFormatParam", "DecimalFormatParamName", "Setter", "Import",
  "NamespaceDecl", "BoundarySpaceDecl", "DefaultNamespaceDecl",
  "OptionDecl", "FTOptionDecl", "OrderingModeDecl", "EmptyOrderDecl",
  "CopyNamespacesDecl", "DefaultCollationDecl", "BaseURIDecl",
  "SchemaImport", "URILiteralList", "SchemaPrefix", "ModuleImport",
  "CtxItemDecl", "CtxItemDecl2", "CtxItemDecl3", "CtxItemDecl4",
  "VarNameAndType", "VarDecl", "DeclPropertyList", "DeclProperty",
  "CollectionDecl", "CollectionTypeDecl", "NodeModifier", "IndexDecl",
  "IndexKeyList", "IndexKeySpec", "IntegrityConstraintDecl",
  "ConstructionDecl", "FunctionSig", "BlockExpr", "Block", "BlockDecls",
  "BlockVarDeclList", "BlockVarDecl", "AssignExpr", "ExitExpr",
  "WhileExpr", "FlowCtlStatement", "FunctionDecl", "FunctionDecl2",
  "FunctionDeclSimple", "FunctionDeclSequential", "FunctionDeclUpdating",
  "ParamList", "Param", "EnclosedExpr", "BracedExpr", "QueryBody", "Expr",
  "ApplyExpr", "ConcatExpr", "ExprSingle", "FLWORExpr", "ReturnExpr",
  "WindowType", "FLWORWinCondType", "FLWORWinCond", "WindowClause",
  "CountClause", "ForLetWinClause", "FLWORClause", "FLWORClauseList",
  "ForDollar", "ForClause", "VarInDeclList", "VarInDecl", "PositionalVar",
  "FTScoreVar", "LetClause", "VarGetsDeclList", "EvalVarDeclList",
  "VarGetsDecl", "WindowVarDecl", "WindowVars", "WindowVars3",
  "WindowVars2", "EvalVarDecl", "WhereClause", "GroupByClause",
  "GroupSpecList", "GroupSpec", "GroupCollationSpec", "OrderByClause",
  "OrderSpecList", "OrderSpec", "OrderModifier", "OrderDirSpec",
  "OrderEmptySpec", "OrderCollationSpec", "QuantifiedExpr",
  "QVarInDeclList", "QVarInDecl", "SwitchExpr", "SwitchCaseClauseList",
  "SwitchCaseClause", "SwitchCaseOperandList", "TypeswitchExpr",
  "CaseClauseList", "CaseClause", "IfExpr", "OrExpr", "AndExpr",
  "ComparisonExpr", "$@1", "FTContainsExpr", "opt_FTIgnoreOption",
  "RangeExpr", "AdditiveExpr", "MultiplicativeExpr", "UnionExpr",
  "IntersectExceptExpr", "InstanceofExpr", "TreatExpr", "CastableExpr",
  "CastExpr", "UnaryExpr", "SignList", "ValueExpr", "ValueComp",
  "NodeComp", "ValidateExpr", "ExtensionExpr", "Pragma_list", "Pragma",
  "PathExpr", "LeadingSlash", "RelativePathExpr", "StepExpr", "AxisStep",
  "ForwardStep", "ForwardAxis", "AbbrevForwardStep", "ReverseStep",
  "ReverseAxis", "NodeTest", "NameTest", "Wildcard", "FilterExpr",
  "PredicateList", "Predicate", "PrimaryExpr", "Literal", "NumericLiteral",
  "VarRef", "ParenthesizedExpr", "ContextItemExpr", "OrderedExpr",
  "UnorderedExpr", "FunctionCall", "ArgList", "Constructor",
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
  "CatchListExpr", "CatchExpr", "NameTestList", "URI_LITERAL", "NCNAME",
  "EvalExpr", "FTSelection", "opt_FTPosFilter_list", "FTPosFilter_list",
  "FTOr", "FTAnd", "FTMildNot", "FTUnaryNot", "FTPrimaryWithOptions",
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
  "FTIgnoreOption", "QNAME", "KEYWORD", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const xquery_parser::rhs_number_type
  xquery_parser::yyrhs_[] =
  {
       318,     0,    -1,   320,    -1,   303,   320,    -1,   319,    -1,
     320,   319,    -1,   303,   319,    -1,   303,   320,   319,    -1,
       3,    -1,   322,    -1,   321,   322,    -1,   323,    -1,   321,
     323,    -1,   206,   207,    20,   182,    -1,   206,   207,    20,
     123,    20,   182,    -1,   325,   385,    -1,   385,    -1,   324,
      -1,   324,   325,    -1,    26,   152,   554,   124,   553,   182,
      -1,   326,   182,    -1,   327,   182,    -1,   326,   182,   327,
     182,    -1,   328,    -1,   326,   182,   328,    -1,   329,    -1,
     327,   182,   329,    -1,   334,    -1,   335,    -1,   336,    -1,
     338,    -1,   355,    -1,   358,    -1,   350,    -1,   330,    -1,
     340,    -1,   376,    -1,   361,    -1,   364,    -1,   339,    -1,
      25,   106,    73,   331,    -1,    25,    73,   609,   331,    -1,
     332,    -1,   331,   332,    -1,   333,   124,   533,    -1,    74,
      -1,    82,    -1,    75,    -1,    76,    -1,    77,    -1,    78,
      -1,    83,    -1,    79,    -1,    80,    -1,    81,    -1,   337,
      -1,   344,    -1,   345,    -1,   365,    -1,   341,    -1,   342,
      -1,   343,    -1,   541,    -1,   346,    -1,   349,    -1,    25,
     152,   554,   124,   553,    -1,    25,    29,   173,    -1,    25,
      29,   187,    -1,    25,   106,    37,   152,   553,    -1,    25,
     106,    40,   152,   553,    -1,    25,    50,   609,    20,    -1,
      25,   254,   582,    -1,    25,    51,   161,    -1,    25,    51,
     193,    -1,    25,   106,   160,   119,   120,    -1,    25,   106,
     160,   119,   121,    -1,    25,    32,   173,   100,   140,    -1,
      25,    32,   173,   100,   157,    -1,    25,    32,   158,   100,
     140,    -1,    25,    32,   158,   100,   157,    -1,    25,   106,
      99,   553,    -1,    25,    28,   553,    -1,    42,    55,   553,
      -1,    42,    55,   348,   553,    -1,    42,    55,   553,    90,
     347,    -1,    42,    55,   348,   553,    90,   347,    -1,   553,
      -1,   347,   100,   553,    -1,   152,   554,   124,    -1,   106,
      37,   152,    -1,    42,    26,   553,    -1,    42,    26,   152,
     554,   124,   553,    -1,    42,    26,   553,    90,   347,    -1,
      42,    26,   152,   554,   124,   553,    90,   347,    -1,    25,
     104,   144,   351,    -1,    88,   518,   352,    -1,   352,    -1,
     353,    -1,   129,    -1,   129,   353,    -1,   134,   389,    -1,
     111,   609,    -1,   111,   609,   515,    -1,    25,   105,   354,
     134,   389,    -1,    25,   105,   354,   129,    -1,    25,   105,
     354,   129,   134,   389,    -1,   357,    -1,   356,   357,    -1,
     281,    -1,   282,    -1,   283,    -1,   284,    -1,   161,    -1,
     193,    -1,   222,   294,    -1,   222,   293,    -1,   295,   294,
      -1,   295,   293,    -1,   286,    -1,   287,   286,    -1,   290,
     291,    -1,   289,   291,    -1,    25,   280,   609,    -1,    25,
     280,   609,   360,    -1,    25,   280,   609,    88,   359,    -1,
      25,   280,   609,    88,   359,   360,    -1,    25,   356,   280,
     609,    -1,    25,   356,   280,   609,   360,    -1,    25,   356,
     280,   609,    88,   359,    -1,    25,   356,   280,   609,    88,
     359,   360,    -1,   521,    -1,   521,   517,    -1,   229,   285,
     219,    -1,   229,   284,   219,    -1,    25,   288,   609,   292,
     219,   462,   162,   362,    -1,    25,   356,   288,   609,   292,
     219,   462,   162,   362,    -1,   363,    -1,   362,   100,   363,
      -1,   462,    88,   520,    -1,   462,    88,   520,   426,    -1,
      25,   296,   297,   609,   292,   280,   609,   111,   609,   298,
     389,    -1,    25,   296,   297,   609,   292,   280,   609,   217,
     111,   609,   298,   286,   299,   462,    -1,    25,   296,   297,
     609,   292,   280,   609,   300,   217,   111,   609,   298,   389,
      -1,    25,   296,   297,   609,   301,   299,   250,   280,   609,
     217,   111,   609,   299,   462,   190,   280,   609,   217,   111,
     609,   299,   462,    -1,    25,    31,   173,    -1,    25,    31,
     187,    -1,   148,   178,    -1,   148,   381,   178,    -1,   148,
     178,    88,   516,    -1,   148,   381,   178,    88,   516,    -1,
     230,   368,    -1,   145,   369,   386,   175,    -1,   369,   370,
     182,    -1,    -1,   370,   100,   371,    -1,    25,   371,    -1,
     354,    -1,   354,   134,   389,    -1,    59,   111,   609,   134,
     389,    -1,   233,   235,   389,    -1,   236,   148,   389,   178,
     368,    -1,   231,   234,    -1,   232,   234,    -1,    25,   377,
      -1,    25,    48,   377,    -1,    25,    34,   377,    -1,   378,
      -1,    60,   378,    -1,   380,    -1,   379,    -1,    40,   609,
     366,   384,    -1,    40,   609,   366,   129,    -1,    58,    40,
     609,   366,   368,    -1,    58,    40,   609,   366,   129,    -1,
      69,    40,   609,   366,   145,   388,   175,    -1,    69,    40,
     609,   366,   129,    -1,   382,    -1,   381,   100,   382,    -1,
     111,   609,    -1,   111,   609,   515,    -1,   145,   386,   175,
      -1,   145,   386,   175,    -1,   386,    -1,   388,    -1,   388,
     387,    -1,   182,    -1,   387,   388,   182,    -1,   389,    -1,
     388,   100,   389,    -1,   390,    -1,   427,    -1,   430,    -1,
     434,    -1,   437,    -1,   438,    -1,   542,    -1,   543,    -1,
     545,    -1,   544,    -1,   546,    -1,   549,    -1,   555,    -1,
     373,    -1,   374,    -1,   375,    -1,   372,    -1,   367,    -1,
     399,   391,    -1,   177,   389,    -1,    61,   277,    -1,    66,
     277,    -1,   209,    -1,   247,    -1,    49,   247,    -1,   393,
     411,    71,   389,    -1,   393,    71,   389,    -1,    39,   392,
     410,   394,   394,    -1,    39,   392,   410,   394,    -1,    33,
     111,   609,    -1,   401,    -1,   406,    -1,   395,    -1,   397,
      -1,   415,    -1,   420,    -1,   416,    -1,   396,    -1,   397,
      -1,   399,   398,    -1,    39,   111,    -1,    52,    39,   111,
      -1,   400,   402,    -1,   403,    -1,   402,   100,   111,   403,
      -1,   609,   139,   389,    -1,   609,   515,   139,   389,    -1,
     609,   404,   139,   389,    -1,   609,   515,   404,   139,   389,
      -1,   609,   405,   139,   389,    -1,   609,   515,   405,   139,
     389,    -1,   609,   404,   405,   139,   389,    -1,   609,   515,
     404,   405,   139,   389,    -1,    90,   111,   609,    -1,   266,
     111,   609,    -1,    44,   111,   407,    -1,   409,    -1,   407,
     100,   111,   409,    -1,   414,    -1,   408,   100,   111,   414,
      -1,   609,   134,   389,    -1,   609,   515,   134,   389,    -1,
     609,   405,   134,   389,    -1,   609,   515,   405,   134,   389,
      -1,   111,   609,   139,   389,    -1,   111,   609,   515,   139,
     389,    -1,   412,    -1,   111,   609,    -1,   111,   609,   412,
      -1,   404,    -1,   404,   413,    -1,   413,    -1,    53,   111,
     609,    46,   111,   609,    -1,    46,   111,   609,    -1,    53,
     111,   609,    -1,   609,    -1,   203,   389,    -1,   163,   162,
     417,    -1,   418,    -1,   417,   100,   418,    -1,   111,   609,
      -1,   111,   609,   419,    -1,    99,   553,    -1,   160,   162,
     421,    -1,    64,   160,   162,   421,    -1,   422,    -1,   421,
     100,   422,    -1,   389,    -1,   389,   423,    -1,   424,    -1,
     425,    -1,   426,    -1,   424,   425,    -1,   424,   426,    -1,
     425,   426,    -1,   424,   425,   426,    -1,    89,    -1,   109,
      -1,   119,   120,    -1,   119,   121,    -1,    99,   553,    -1,
      62,   111,   428,   179,   389,    -1,   127,   111,   428,   179,
     389,    -1,   429,    -1,   428,   100,   111,   429,    -1,   609,
     139,   389,    -1,   609,   515,   139,   389,    -1,    67,   148,
     386,   178,   431,   106,   177,   389,    -1,   432,    -1,   431,
     432,    -1,   433,   177,   389,    -1,    93,   389,    -1,   433,
      93,   389,    -1,    68,   148,   386,   178,   435,   106,   177,
     389,    -1,    68,   148,   386,   178,   435,   106,   111,   609,
     177,   389,    -1,   436,    -1,   435,   436,    -1,    93,   516,
     177,   389,    -1,    93,   111,   609,    88,   516,   177,   389,
      -1,    41,   148,   386,   178,   189,   389,   118,   389,    -1,
     439,    -1,   438,   159,   439,    -1,   440,    -1,   439,    86,
     440,    -1,   442,    -1,   442,   456,   442,    -1,   442,   457,
     442,    -1,   442,   124,   442,    -1,   442,   154,   442,    -1,
      -1,   442,   149,   441,   442,    -1,   442,   147,   442,    -1,
     442,   135,   442,    -1,   442,   133,   442,    -1,   444,    -1,
     444,   242,    65,   556,   443,    -1,    -1,   608,    -1,   445,
      -1,   445,   190,   445,    -1,   446,    -1,   445,   167,   446,
      -1,   445,   150,   446,    -1,   447,    -1,   446,   185,   447,
      -1,   446,   110,   447,    -1,   446,   138,   447,    -1,   446,
     151,   447,    -1,   448,    -1,   447,   192,   448,    -1,   447,
     201,   448,    -1,   449,    -1,   448,   142,   449,    -1,   448,
     128,   449,    -1,   450,    -1,   450,    43,   223,   516,    -1,
     451,    -1,   451,   191,    88,   516,    -1,   452,    -1,   452,
      94,    88,   514,    -1,   453,    -1,   453,    95,    88,   514,
      -1,   455,    -1,   454,   455,    -1,   167,    -1,   150,    -1,
     454,   167,    -1,   454,   150,    -1,   458,    -1,   462,    -1,
     459,    -1,   194,    -1,   199,    -1,   198,    -1,   197,    -1,
     196,    -1,   195,    -1,   143,    -1,   170,    -1,   132,    -1,
      70,   145,   386,   175,    -1,    70,   214,   145,   386,   175,
      -1,    70,   213,   145,   386,   175,    -1,    70,    88,   531,
     145,   386,   175,    -1,   460,   145,   175,    -1,   460,   145,
     386,   175,    -1,   461,    -1,   460,   461,    -1,   168,   609,
      15,    -1,   168,    16,    -1,   463,    -1,   463,   464,    -1,
     184,   464,    -1,   464,    -1,   183,    -1,   465,    -1,   465,
     183,   464,    -1,   465,   184,   464,    -1,   466,    -1,   475,
      -1,   467,    -1,   467,   476,    -1,   470,    -1,   470,   476,
      -1,   468,   472,    -1,   469,    -1,    98,   114,    -1,   107,
     114,    -1,    91,   114,    -1,   181,   114,    -1,   108,   114,
      -1,   131,   114,    -1,   130,   114,    -1,   472,    -1,    92,
     472,    -1,   471,   472,    -1,   113,    -1,   164,   114,    -1,
      84,   114,    -1,   172,   114,    -1,   171,   114,    -1,    85,
     114,    -1,   521,    -1,   473,    -1,   609,    -1,   474,    -1,
     185,    -1,    10,    -1,    17,    -1,   478,    -1,   475,   476,
      -1,   475,   148,   178,    -1,   475,   148,   487,   178,    -1,
     477,    -1,   476,   477,    -1,   146,   386,   176,    -1,   479,
      -1,   481,    -1,   482,    -1,   483,    -1,   486,    -1,   488,
      -1,   484,    -1,   485,    -1,   534,    -1,   480,    -1,   533,
      -1,   103,    -1,   141,    -1,   116,    -1,   111,   609,    -1,
     148,   178,    -1,   148,   386,   178,    -1,   112,    -1,   161,
     145,   386,   175,    -1,   193,   145,   386,   175,    -1,   609,
     148,   178,    -1,   609,   148,   487,   178,    -1,   389,    -1,
     487,   100,   389,    -1,   489,    -1,   507,    -1,   490,    -1,
     504,    -1,   505,    -1,   149,   609,   494,   122,    -1,   149,
     609,   492,   494,   122,    -1,   149,   609,   494,   188,   186,
     609,   494,   188,    -1,   149,   609,   494,   188,   491,   186,
     609,   494,   188,    -1,   149,   609,   492,   494,   188,   186,
     609,   494,   188,    -1,   149,   609,   492,   494,   188,   491,
     186,   609,   494,   188,    -1,   502,    -1,   491,   502,    -1,
     493,    -1,   492,   493,    -1,    27,   609,   494,   124,   494,
     495,    -1,    -1,    27,    -1,   174,   496,   174,    -1,    87,
     498,    87,    -1,    -1,   497,    -1,   126,    -1,   500,    -1,
     497,   126,    -1,   497,   500,    -1,    -1,   499,    -1,   125,
      -1,   501,    -1,   499,   125,    -1,   499,   501,    -1,    19,
      -1,   503,    -1,     4,    -1,   503,    -1,   489,    -1,     9,
      -1,   506,    -1,   503,    -1,     8,    -1,   115,    -1,   117,
      -1,   383,    -1,   204,    21,   205,    -1,   204,   205,    -1,
     165,   554,   166,    -1,   165,   554,     7,    -1,    96,     6,
      -1,   508,    -1,   509,    -1,   510,    -1,   511,    -1,   512,
      -1,   513,    -1,    35,   145,   386,   175,    -1,    37,   609,
     145,   175,    -1,    37,   609,   145,   386,   175,    -1,    37,
     145,   386,   175,   145,   175,    -1,    37,   145,   386,   175,
     145,   386,   175,    -1,    91,   609,   145,   175,    -1,    91,
     609,   145,   386,   175,    -1,    91,   145,   386,   175,   145,
     175,    -1,    91,   145,   386,   175,   145,   386,   175,    -1,
      65,   145,   386,   175,    -1,    30,   145,   386,   175,    -1,
      54,   554,   145,   175,    -1,    54,   554,   145,   386,   175,
      -1,    54,   145,   386,   175,   145,   175,    -1,    54,   145,
     386,   175,   145,   386,   175,    -1,   520,    -1,   520,   136,
      -1,    88,   516,    -1,   518,    -1,   518,   517,    -1,   202,
     148,   178,    -1,   136,    -1,   185,    -1,   167,    -1,   520,
      -1,   521,    -1,   144,   148,   178,    -1,   537,    -1,   540,
      -1,   516,    -1,   519,   100,   516,    -1,   609,    -1,   523,
      -1,   529,    -1,   527,    -1,   530,    -1,   528,    -1,   526,
      -1,   525,    -1,   524,    -1,   522,    -1,   217,   148,   178,
      -1,    36,   148,   178,    -1,    36,   148,   529,   178,    -1,
      36,   148,   530,   178,    -1,    65,   148,   178,    -1,    30,
     148,   178,    -1,    54,   148,   178,    -1,    54,   148,   554,
     178,    -1,    54,   148,    20,   178,    -1,    91,   148,   178,
      -1,    91,   148,   609,   178,    -1,    91,   148,   609,   100,
     531,   178,    -1,    91,   148,   185,   178,    -1,    91,   148,
     185,   100,   531,   178,    -1,   180,   609,   178,    -1,    37,
     148,   178,    -1,    37,   148,   609,   178,    -1,    37,   148,
     609,   100,   531,   178,    -1,    37,   148,   609,   100,   532,
     178,    -1,    37,   148,   185,   178,    -1,    37,   148,   185,
     100,   531,   178,    -1,    37,   148,   185,   100,   532,   178,
      -1,    57,   148,   609,   178,    -1,   609,    -1,   609,   136,
      -1,    20,    -1,   535,    -1,   536,    -1,   609,   137,   141,
      -1,    40,   366,   383,    -1,   538,    -1,   539,    -1,    40,
     148,   185,   178,    -1,    40,   148,   178,    88,   516,    -1,
      40,   148,   519,   178,    88,   516,    -1,   148,   518,   178,
      -1,    25,   212,   213,    -1,    25,   212,   214,    -1,    25,
     212,   215,    -1,   218,   217,   389,   225,   389,    -1,   218,
     217,   389,    88,   224,   225,   389,    -1,   218,   217,   389,
      88,   226,   225,   389,    -1,   218,   217,   389,   210,   389,
      -1,   218,   217,   389,   211,   389,    -1,   218,   219,   389,
     225,   389,    -1,   218,   219,   389,    88,   224,   225,   389,
      -1,   218,   219,   389,    88,   226,   225,   389,    -1,   218,
     219,   389,   210,   389,    -1,   218,   219,   389,   211,   389,
      -1,   216,   217,   389,    -1,   216,   219,   389,    -1,   221,
     217,   389,   229,   389,    -1,   221,   222,   223,   217,   389,
     229,   389,    -1,   220,   217,   389,    88,   389,    -1,   228,
     111,   547,   227,   389,   177,   389,    -1,   548,    -1,   547,
     100,   111,   548,    -1,   609,   134,   389,    -1,   237,   145,
     386,   175,   550,    -1,   551,    -1,   550,   551,    -1,   238,
     552,   384,    -1,   238,   552,   148,   111,   609,   178,   384,
      -1,   238,   552,   148,   111,   609,   100,   111,   609,   178,
     384,    -1,   238,   552,   148,   111,   609,   100,   111,   609,
     100,   111,   609,   178,   384,    -1,   473,    -1,   552,   201,
     473,    -1,    20,    -1,    14,    -1,   609,    -1,   239,   111,
     408,    38,   145,   389,   175,    -1,    38,   145,   389,   175,
      -1,   559,   557,    -1,    -1,   558,    -1,   577,    -1,   558,
     577,    -1,   560,    -1,   559,   255,   560,    -1,   561,    -1,
     560,   251,   561,    -1,   562,    -1,   561,   253,   139,   562,
      -1,   563,    -1,   252,   563,    -1,   567,   564,   565,    -1,
      -1,   582,    -1,    -1,   566,    -1,   275,   145,   386,   175,
      -1,   571,   568,    -1,   148,   556,   178,    -1,   569,    -1,
      -1,   604,    -1,   460,   145,   570,   175,    -1,    -1,   556,
      -1,   572,   573,    -1,   479,    -1,   145,   386,   175,    -1,
      -1,   574,    -1,   241,   575,    -1,   240,   576,    -1,   263,
      -1,    -1,    72,    -1,    -1,   279,    -1,   578,    -1,   579,
      -1,   580,    -1,   606,    -1,   603,    -1,   161,    -1,   277,
     445,   581,    -1,   246,   605,   581,    -1,   279,    -1,   269,
      -1,   262,    -1,   239,   583,    -1,   582,   239,   583,    -1,
     584,    -1,   585,    -1,   586,    -1,   601,    -1,   587,    -1,
     595,    -1,   588,    -1,   602,    -1,    93,   267,    -1,    93,
     256,    -1,   259,    -1,   274,    -1,   244,   267,    -1,   244,
     256,    -1,    50,   609,    20,    -1,   270,    -1,    47,   270,
      -1,   272,   589,    -1,   272,   148,   589,   590,   178,    -1,
      47,   272,    -1,   592,    -1,   106,    -1,    -1,   591,    -1,
     592,    -1,   591,   100,   592,    -1,    90,    20,   593,   594,
      -1,    -1,   264,    20,    -1,    -1,   605,   258,    -1,   271,
     279,   596,   598,    -1,   271,   279,   106,   598,    -1,    47,
     271,   279,    -1,    90,    20,    -1,   148,   597,   178,    -1,
      20,    -1,   597,   100,    20,    -1,    -1,   599,    -1,   600,
      -1,   599,   600,    -1,   192,   596,    -1,   128,   596,    -1,
     257,    20,    -1,   276,    -1,    47,   276,    -1,    90,   209,
      -1,    90,   247,    -1,   248,   243,    -1,   260,   605,   273,
      -1,   249,   445,    -1,    90,   121,   445,    -1,    90,    45,
     445,    -1,   250,   445,   190,   445,    -1,   265,   607,    -1,
     245,   607,    -1,   268,    -1,   261,    -1,   278,   243,   447,
      -1,    18,    -1,   610,    -1,   206,    -1,   119,    -1,    91,
      -1,    30,    -1,    36,    -1,    37,    -1,   144,    -1,    41,
      -1,   217,    -1,    54,    -1,    56,    -1,    57,    -1,    65,
      -1,    68,    -1,    67,    -1,   202,    -1,    29,    -1,   254,
      -1,    28,    -1,   214,    -1,   213,    -1,   138,    -1,    35,
      -1,   252,    -1,   253,    -1,   267,    -1,   256,    -1,   244,
      -1,   278,    -1,   270,    -1,   272,    -1,   271,    -1,   276,
      -1,   248,    -1,   243,    -1,    72,    -1,   209,    -1,   247,
      -1,    45,    -1,   215,    -1,   228,    -1,   295,    -1,   222,
      -1,   194,    -1,   199,    -1,   198,    -1,   197,    -1,   196,
      -1,   195,    -1,    90,    -1,   104,    -1,   105,    -1,   177,
      -1,    39,    -1,    52,    -1,    61,    -1,    66,    -1,    53,
      -1,    46,    -1,    49,    -1,    71,    -1,    33,    -1,   139,
      -1,    44,    -1,   203,    -1,   162,    -1,   163,    -1,   160,
      -1,    64,    -1,    89,    -1,   109,    -1,   120,    -1,   121,
      -1,    99,    -1,    62,    -1,   127,    -1,   179,    -1,    93,
      -1,    88,    -1,   189,    -1,   118,    -1,   159,    -1,    86,
      -1,    43,    -1,   223,    -1,    94,    -1,   190,    -1,   110,
      -1,   151,    -1,   192,    -1,   142,    -1,   128,    -1,    70,
      -1,    95,    -1,   191,    -1,   143,    -1,   173,    -1,   187,
      -1,   152,    -1,   129,    -1,   123,    -1,   158,    -1,   140,
      -1,   157,    -1,    25,    -1,    31,    -1,    51,    -1,   106,
      -1,    32,    -1,    50,    -1,   207,    -1,    42,    -1,    55,
      -1,    26,    -1,    40,    -1,   266,    -1,   242,    -1,   275,
      -1,   277,    -1,   246,    -1,   260,    -1,   273,    -1,   265,
      -1,   245,    -1,   259,    -1,   274,    -1,   264,    -1,   258,
      -1,   257,    -1,   241,    -1,   240,    -1,   263,    -1,   249,
      -1,   250,    -1,   279,    -1,   269,    -1,   268,    -1,   261,
      -1,   221,    -1,   227,    -1,   224,    -1,   218,    -1,   211,
      -1,   210,    -1,   212,    -1,   229,    -1,   219,    -1,   220,
      -1,   226,    -1,   216,    -1,   225,    -1,    60,    -1,    58,
      -1,    69,    -1,    34,    -1,    48,    -1,   161,    -1,   193,
      -1,   235,    -1,   230,    -1,   233,    -1,   234,    -1,   236,
      -1,   231,    -1,   232,    -1,   237,    -1,   238,    -1,    38,
      -1,   239,    -1,    59,    -1,   288,    -1,   286,    -1,   287,
      -1,   292,    -1,   293,    -1,   294,    -1,   289,    -1,   290,
      -1,   291,    -1,    73,    -1,    74,    -1,    75,    -1,    76,
      -1,    77,    -1,    78,    -1,    79,    -1,    80,    -1,    81,
      -1,    82,    -1,    83,    -1,   280,    -1,   281,    -1,   282,
      -1,   283,    -1,   284,    -1,   285,    -1,   296,    -1,   297,
      -1,   298,    -1,   299,    -1,   300,    -1,   301,    -1,   302,
      -1,    84,    -1,    98,    -1,   107,    -1,   164,    -1,   171,
      -1,   181,    -1,   130,    -1,    85,    -1,   108,    -1,   131,
      -1,   172,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  xquery_parser::yyprhs_[] =
  {
         0,     0,     3,     5,     8,    10,    13,    16,    20,    22,
      24,    27,    29,    32,    37,    44,    47,    49,    51,    54,
      61,    64,    67,    72,    74,    78,    80,    84,    86,    88,
      90,    92,    94,    96,    98,   100,   102,   104,   106,   108,
     110,   115,   120,   122,   125,   129,   131,   133,   135,   137,
     139,   141,   143,   145,   147,   149,   151,   153,   155,   157,
     159,   161,   163,   165,   167,   169,   175,   179,   183,   189,
     195,   200,   204,   208,   212,   218,   224,   230,   236,   242,
     248,   253,   257,   261,   266,   272,   279,   281,   285,   289,
     293,   297,   304,   310,   319,   324,   328,   330,   332,   334,
     337,   340,   343,   347,   353,   358,   365,   367,   370,   372,
     374,   376,   378,   380,   382,   385,   388,   391,   394,   396,
     399,   402,   405,   409,   414,   420,   427,   432,   438,   445,
     453,   455,   458,   462,   466,   475,   485,   487,   491,   495,
     500,   512,   527,   541,   564,   568,   572,   575,   579,   584,
     590,   593,   598,   602,   603,   607,   610,   612,   616,   622,
     626,   632,   635,   638,   641,   645,   649,   651,   654,   656,
     658,   663,   668,   674,   680,   688,   694,   696,   700,   703,
     707,   711,   715,   717,   719,   722,   724,   728,   730,   734,
     736,   738,   740,   742,   744,   746,   748,   750,   752,   754,
     756,   758,   760,   762,   764,   766,   768,   770,   773,   776,
     779,   782,   784,   786,   789,   794,   798,   804,   809,   813,
     815,   817,   819,   821,   823,   825,   827,   829,   831,   834,
     837,   841,   844,   846,   851,   855,   860,   865,   871,   876,
     882,   888,   895,   899,   903,   907,   909,   914,   916,   921,
     925,   930,   935,   941,   946,   952,   954,   957,   961,   963,
     966,   968,   975,   979,   983,   985,   988,   992,   994,   998,
    1001,  1005,  1008,  1012,  1017,  1019,  1023,  1025,  1028,  1030,
    1032,  1034,  1037,  1040,  1043,  1047,  1049,  1051,  1054,  1057,
    1060,  1066,  1072,  1074,  1079,  1083,  1088,  1097,  1099,  1102,
    1106,  1109,  1113,  1122,  1133,  1135,  1138,  1143,  1151,  1160,
    1162,  1166,  1168,  1172,  1174,  1178,  1182,  1186,  1190,  1191,
    1196,  1200,  1204,  1208,  1210,  1216,  1217,  1219,  1221,  1225,
    1227,  1231,  1235,  1237,  1241,  1245,  1249,  1253,  1255,  1259,
    1263,  1265,  1269,  1273,  1275,  1280,  1282,  1287,  1289,  1294,
    1296,  1301,  1303,  1306,  1308,  1310,  1313,  1316,  1318,  1320,
    1322,  1324,  1326,  1328,  1330,  1332,  1334,  1336,  1338,  1340,
    1345,  1351,  1357,  1364,  1368,  1373,  1375,  1378,  1382,  1385,
    1387,  1390,  1393,  1395,  1397,  1399,  1403,  1407,  1409,  1411,
    1413,  1416,  1418,  1421,  1424,  1426,  1429,  1432,  1435,  1438,
    1441,  1444,  1447,  1449,  1452,  1455,  1457,  1460,  1463,  1466,
    1469,  1472,  1474,  1476,  1478,  1480,  1482,  1484,  1486,  1488,
    1491,  1495,  1500,  1502,  1505,  1509,  1511,  1513,  1515,  1517,
    1519,  1521,  1523,  1525,  1527,  1529,  1531,  1533,  1535,  1537,
    1540,  1543,  1547,  1549,  1554,  1559,  1563,  1568,  1570,  1574,
    1576,  1578,  1580,  1582,  1584,  1589,  1595,  1604,  1614,  1624,
    1635,  1637,  1640,  1642,  1645,  1652,  1653,  1655,  1659,  1663,
    1664,  1666,  1668,  1670,  1673,  1676,  1677,  1679,  1681,  1683,
    1686,  1689,  1691,  1693,  1695,  1697,  1699,  1701,  1703,  1705,
    1707,  1709,  1711,  1713,  1717,  1720,  1724,  1728,  1731,  1733,
    1735,  1737,  1739,  1741,  1743,  1748,  1753,  1759,  1766,  1774,
    1779,  1785,  1792,  1800,  1805,  1810,  1815,  1821,  1828,  1836,
    1838,  1841,  1844,  1846,  1849,  1853,  1855,  1857,  1859,  1861,
    1863,  1867,  1869,  1871,  1873,  1877,  1879,  1881,  1883,  1885,
    1887,  1889,  1891,  1893,  1895,  1897,  1901,  1905,  1910,  1915,
    1919,  1923,  1927,  1932,  1937,  1941,  1946,  1953,  1958,  1965,
    1969,  1973,  1978,  1985,  1992,  1997,  2004,  2011,  2016,  2018,
    2021,  2023,  2025,  2027,  2031,  2035,  2037,  2039,  2044,  2050,
    2057,  2061,  2065,  2069,  2073,  2079,  2087,  2095,  2101,  2107,
    2113,  2121,  2129,  2135,  2141,  2145,  2149,  2155,  2163,  2169,
    2177,  2179,  2184,  2188,  2194,  2196,  2199,  2203,  2211,  2222,
    2236,  2238,  2242,  2244,  2246,  2248,  2256,  2261,  2264,  2265,
    2267,  2269,  2272,  2274,  2278,  2280,  2284,  2286,  2291,  2293,
    2296,  2300,  2301,  2303,  2304,  2306,  2311,  2314,  2318,  2320,
    2321,  2323,  2328,  2329,  2331,  2334,  2336,  2340,  2341,  2343,
    2346,  2349,  2351,  2352,  2354,  2355,  2357,  2359,  2361,  2363,
    2365,  2367,  2369,  2373,  2377,  2379,  2381,  2383,  2386,  2390,
    2392,  2394,  2396,  2398,  2400,  2402,  2404,  2406,  2409,  2412,
    2414,  2416,  2419,  2422,  2426,  2428,  2431,  2434,  2440,  2443,
    2445,  2447,  2448,  2450,  2452,  2456,  2461,  2462,  2465,  2466,
    2469,  2474,  2479,  2483,  2486,  2490,  2492,  2496,  2497,  2499,
    2501,  2504,  2507,  2510,  2513,  2515,  2518,  2521,  2524,  2527,
    2531,  2534,  2538,  2542,  2547,  2550,  2553,  2555,  2557,  2561,
    2563,  2565,  2567,  2569,  2571,  2573,  2575,  2577,  2579,  2581,
    2583,  2585,  2587,  2589,  2591,  2593,  2595,  2597,  2599,  2601,
    2603,  2605,  2607,  2609,  2611,  2613,  2615,  2617,  2619,  2621,
    2623,  2625,  2627,  2629,  2631,  2633,  2635,  2637,  2639,  2641,
    2643,  2645,  2647,  2649,  2651,  2653,  2655,  2657,  2659,  2661,
    2663,  2665,  2667,  2669,  2671,  2673,  2675,  2677,  2679,  2681,
    2683,  2685,  2687,  2689,  2691,  2693,  2695,  2697,  2699,  2701,
    2703,  2705,  2707,  2709,  2711,  2713,  2715,  2717,  2719,  2721,
    2723,  2725,  2727,  2729,  2731,  2733,  2735,  2737,  2739,  2741,
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
    2983,  2985,  2987,  2989,  2991
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,  1053,  1053,  1054,  1059,  1060,  1061,  1062,  1066,  1082,
    1087,  1094,  1099,  1110,  1115,  1123,  1131,  1139,  1145,  1157,
    1166,  1170,  1174,  1186,  1192,  1202,  1208,  1218,  1219,  1220,
    1221,  1226,  1227,  1228,  1229,  1230,  1231,  1232,  1233,  1234,
    1240,  1245,  1254,  1260,  1269,  1278,  1279,  1280,  1281,  1282,
    1283,  1284,  1285,  1286,  1287,  1292,  1293,  1294,  1295,  1296,
    1297,  1298,  1301,  1306,  1307,  1317,  1326,  1332,  1342,  1348,
    1358,  1368,  1376,  1382,  1393,  1398,  1408,  1414,  1420,  1426,
    1443,  1451,  1459,  1463,  1472,  1481,  1494,  1500,  1511,  1515,
    1523,  1528,  1533,  1540,  1553,  1560,  1566,  1573,  1579,  1583,
    1590,  1601,  1605,  1613,  1619,  1625,  1634,  1640,  1649,  1653,
    1659,  1663,  1667,  1671,  1677,  1683,  1689,  1695,  1701,  1705,
    1711,  1717,  1724,  1732,  1740,  1748,  1756,  1768,  1782,  1796,
    1813,  1817,  1824,  1828,  1835,  1843,  1860,  1866,  1874,  1881,
    1891,  1901,  1911,  1921,  1938,  1944,  1955,  1959,  1963,  1967,
    1976,  1983,  2002,  2012,  2018,  2024,  2034,  2041,  2052,  2059,
    2066,  2078,  2082,  2089,  2094,  2109,  2126,  2130,  2134,  2138,
    2146,  2156,  2170,  2180,  2194,  2204,  2219,  2225,  2237,  2241,
    2252,  2259,  2267,  2282,  2286,  2300,  2304,  2313,  2317,  2331,
    2332,  2333,  2334,  2335,  2336,  2339,  2340,  2341,  2342,  2343,
    2345,  2346,  2349,  2350,  2351,  2352,  2353,  2358,  2373,  2380,
    2384,  2391,  2395,  2399,  2406,  2414,  2425,  2435,  2448,  2457,
    2458,  2459,  2463,  2464,  2465,  2466,  2467,  2470,  2476,  2485,
    2489,  2497,  2507,  2513,  2525,  2529,  2537,  2546,  2556,  2564,
    2573,  2582,  2597,  2606,  2616,  2624,  2630,  2639,  2645,  2657,
    2665,  2675,  2683,  2695,  2701,  2712,  2714,  2718,  2726,  2730,
    2735,  2739,  2743,  2747,  2755,  2769,  2777,  2784,  2790,  2801,
    2805,  2814,  2822,  2828,  2838,  2844,  2854,  2858,  2868,  2874,
    2880,  2886,  2895,  2904,  2913,  2926,  2930,  2938,  2944,  2954,
    2962,  2971,  2984,  2991,  3003,  3007,  3019,  3026,  3032,  3041,
    3048,  3054,  3066,  3073,  3086,  3092,  3104,  3110,  3122,  3131,
    3135,  3144,  3148,  3156,  3160,  3170,  3177,  3186,  3196,  3195,
    3209,  3218,  3227,  3240,  3244,  3257,  3260,  3267,  3271,  3280,
    3284,  3288,  3297,  3301,  3307,  3313,  3319,  3330,  3334,  3338,
    3346,  3350,  3356,  3366,  3370,  3380,  3384,  3394,  3398,  3408,
    3412,  3422,  3426,  3434,  3438,  3442,  3446,  3456,  3460,  3464,
    3472,  3476,  3480,  3484,  3488,  3492,  3500,  3504,  3508,  3516,
    3520,  3524,  3528,  3539,  3545,  3555,  3561,  3571,  3575,  3613,
    3619,  3625,  3631,  3642,  3650,  3661,  3667,  3677,  3681,  3689,
    3695,  3703,  3709,  3721,  3727,  3737,  3741,  3745,  3749,  3753,
    3759,  3765,  3773,  3777,  3785,  3789,  3800,  3804,  3808,  3814,
    3818,  3832,  3836,  3844,  3848,  3858,  3862,  3866,  3875,  3879,
    3885,  3889,  3897,  3903,  3913,  3921,  3925,  3929,  3933,  3937,
    3941,  3945,  3949,  3953,  3961,  3965,  3973,  3980,  3987,  3998,
    4006,  4010,  4018,  4026,  4034,  4088,  4092,  4104,  4110,  4120,
    4124,  4132,  4136,  4140,  4148,  4158,  4168,  4178,  4188,  4198,
    4213,  4219,  4230,  4236,  4247,  4258,  4260,  4264,  4269,  4279,
    4282,  4289,  4297,  4303,  4313,  4326,  4329,  4336,  4342,  4348,
    4355,  4366,  4370,  4380,  4384,  4394,  4398,  4402,  4407,  4416,
    4422,  4428,  4434,  4444,  4448,  4460,  4464,  4476,  4488,  4492,
    4496,  4500,  4504,  4508,  4516,  4524,  4530,  4536,  4540,  4557,
    4561,  4565,  4569,  4577,  4585,  4593,  4597,  4601,  4605,  4613,
    4619,  4629,  4637,  4641,  4647,  4682,  4688,  4694,  4704,  4708,
    4712,  4716,  4720,  4727,  4733,  4743,  4751,  4755,  4759,  4763,
    4767,  4771,  4775,  4779,  4783,  4791,  4799,  4803,  4807,  4817,
    4825,  4833,  4837,  4841,  4849,  4853,  4859,  4865,  4869,  4879,
    4887,  4891,  4897,  4906,  4915,  4921,  4927,  4937,  4954,  4961,
    4976,  5012,  5016,  5025,  5034,  5044,  5048,  5057,  5066,  5070,
    5081,  5098,  5104,  5110,  5120,  5124,  5130,  5136,  5140,  5146,
    5150,  5156,  5162,  5169,  5179,  5184,  5192,  5198,  5208,  5230,
    5239,  5245,  5258,  5272,  5279,  5285,  5295,  5300,  5306,  5316,
    5329,  5335,  5345,  5355,  5356,  5375,  5381,  5396,  5405,  5408,
    5415,  5420,  5428,  5432,  5439,  5443,  5450,  5454,  5461,  5465,
    5474,  5487,  5490,  5498,  5501,  5509,  5517,  5525,  5529,  5537,
    5540,  5548,  5560,  5563,  5571,  5583,  5589,  5599,  5602,  5610,
    5614,  5618,  5626,  5629,  5637,  5640,  5648,  5652,  5656,  5660,
    5664,  5672,  5680,  5692,  5704,  5708,  5712,  5720,  5726,  5736,
    5740,  5744,  5748,  5752,  5756,  5760,  5764,  5772,  5776,  5780,
    5784,  5792,  5798,  5808,  5818,  5822,  5830,  5840,  5851,  5858,
    5862,  5870,  5873,  5880,  5885,  5894,  5904,  5907,  5915,  5918,
    5926,  5935,  5942,  5952,  5956,  5963,  5969,  5979,  5982,  5989,
    5994,  6006,  6014,  6026,  6034,  6038,  6046,  6050,  6054,  6062,
    6070,  6074,  6078,  6082,  6090,  6098,  6110,  6114,  6122,  6135,
    6139,  6146,  6147,  6148,  6149,  6150,  6151,  6152,  6153,  6154,
    6155,  6156,  6157,  6158,  6159,  6160,  6161,  6162,  6163,  6164,
    6165,  6166,  6167,  6168,  6169,  6170,  6171,  6172,  6173,  6174,
    6175,  6176,  6177,  6178,  6179,  6180,  6181,  6182,  6183,  6184,
    6185,  6186,  6187,  6188,  6189,  6190,  6191,  6192,  6193,  6194,
    6195,  6196,  6197,  6198,  6199,  6200,  6201,  6202,  6203,  6204,
    6205,  6206,  6207,  6208,  6209,  6210,  6211,  6212,  6213,  6214,
    6215,  6216,  6217,  6218,  6219,  6220,  6221,  6222,  6223,  6224,
    6225,  6226,  6227,  6228,  6229,  6230,  6231,  6232,  6233,  6234,
    6235,  6236,  6237,  6238,  6239,  6240,  6241,  6242,  6243,  6244,
    6245,  6246,  6247,  6248,  6249,  6250,  6251,  6252,  6253,  6254,
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
    6355,  6356,  6357,  6358,  6359
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
     315,   316
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 11460;
  const int xquery_parser::yynnts_ = 294;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 554;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 317;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 571;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


} // zorba

/* Line 1053 of lalr1.cc  */
#line 15487 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.cpp"


/* Line 1055 of lalr1.cc  */
#line 6363 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"


namespace zorba {

namespace parser {

const char *the_tumbling = "tumbling", *the_sliding = "sliding",
  *the_start = "start", *the_end = "end", *the_only_end = "only end",
  *the_ofor = "ofor", *the_declare = "declare", *the_create = "create";

} // namespace parser

/*
 *  The error member function registers the errors to the driver.
 */
void xquery_parser::error(zorba::xquery_parser::location_type const& loc, std::string const& msg)
{
  driver.set_expr(
    new ParseErrorNode (driver.createQueryLoc (loc), XPST0003, msg)
  );
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

