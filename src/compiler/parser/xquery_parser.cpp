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
#line 106 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"


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
#line 83 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"


#include "xquery_parser.hpp"

/* User implementation prologue.  */

/* Line 316 of lalr1.cc  */
#line 890 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 316 of lalr1.cc  */
#line 1006 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"

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
#line 139 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"

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
#line 205 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
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
#line 886 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 479 of lalr1.cc  */
#line 312 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 116: /* "\"'DOUBLE'\"" */

/* Line 479 of lalr1.cc  */
#line 885 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 479 of lalr1.cc  */
#line 321 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 141: /* "\"'INTEGER'\"" */

/* Line 479 of lalr1.cc  */
#line 884 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 479 of lalr1.cc  */
#line 330 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 321: /* "VersionDecl" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 339 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 322: /* "MainModule" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 348 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 323: /* "LibraryModule" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 357 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 324: /* "ModuleDecl" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 366 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 325: /* "Prolog" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 375 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 326: /* "SIND_DeclList" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 384 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "VFO_DeclList" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 393 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "SIND_Decl" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 402 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "VFO_Decl" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 411 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "DecimalFormatDecl" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 420 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "DecimalFormatParamList" */

/* Line 479 of lalr1.cc  */
#line 911 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 479 of lalr1.cc  */
#line 429 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "DecimalFormatParam" */

/* Line 479 of lalr1.cc  */
#line 911 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 479 of lalr1.cc  */
#line 438 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "Setter" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 447 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "Import" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 456 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "NamespaceDecl" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 465 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "BoundarySpaceDecl" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 474 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "DefaultNamespaceDecl" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 483 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "OptionDecl" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 492 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "FTOptionDecl" */

/* Line 479 of lalr1.cc  */
#line 905 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 501 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "OrderingModeDecl" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 510 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "EmptyOrderDecl" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 519 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "CopyNamespacesDecl" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 528 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "DefaultCollationDecl" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 537 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "BaseURIDecl" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 546 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "SchemaImport" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 555 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "URILiteralList" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 564 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "SchemaPrefix" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 573 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "ModuleImport" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 582 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "CtxItemDecl" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 591 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "CtxItemDecl2" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 600 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "CtxItemDecl3" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 609 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "CtxItemDecl4" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 618 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "VarNameAndType" */

/* Line 479 of lalr1.cc  */
#line 911 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 479 of lalr1.cc  */
#line 627 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "VarDecl" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 636 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "DeclPropertyList" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 645 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "DeclProperty" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 654 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "CollectionDecl" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 663 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "NodeModifier" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 672 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "IndexDecl" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 681 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "IndexKeyList" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 690 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "IndexKeySpec" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 699 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "IntegrityConstraintDecl" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 708 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "ConstructionDecl" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 717 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "FunctionSig" */

/* Line 479 of lalr1.cc  */
#line 911 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 479 of lalr1.cc  */
#line 726 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "BlockExpr" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 735 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "Block" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 744 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "BlockDecls" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 753 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "BlockVarDeclList" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 762 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "BlockVarDecl" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 771 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "AssignExpr" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 780 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "ExitExpr" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 789 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "WhileExpr" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 798 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "FlowCtlStatement" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 807 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "FunctionDecl" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 816 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "FunctionDecl2" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 825 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "FunctionDeclSimple" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 834 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "FunctionDeclSequential" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 843 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "FunctionDeclUpdating" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 852 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "ParamList" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "Param" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 870 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "EnclosedExpr" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "BracedExpr" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 888 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "QueryBody" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 897 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "Expr" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 906 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "ApplyExpr" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 915 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "ConcatExpr" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 924 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "ExprSingle" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 933 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "FLWORExpr" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 942 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "ReturnExpr" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 951 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "FLWORWinCond" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 960 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "WindowClause" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 969 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "CountClause" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 978 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "ForLetWinClause" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 987 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "FLWORClauseList" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 996 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "ForClause" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1005 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "VarInDeclList" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1014 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "VarInDecl" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1023 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "PositionalVar" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1032 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "FTScoreVar" */

/* Line 479 of lalr1.cc  */
#line 905 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1041 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "LetClause" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1050 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "VarGetsDeclList" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1059 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "EvalVarDeclList" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1068 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "VarGetsDecl" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1077 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "WindowVarDecl" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1086 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "WindowVars" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1095 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "WindowVars3" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1104 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "WindowVars2" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1113 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "EvalVarDecl" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1122 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "WhereClause" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1131 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "GroupByClause" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1140 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "GroupSpecList" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1149 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "GroupSpec" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1158 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "GroupCollationSpec" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1167 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "OrderByClause" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1176 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "OrderSpecList" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1185 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "OrderSpec" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1194 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "OrderModifier" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1203 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "OrderDirSpec" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1212 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "OrderEmptySpec" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1221 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "OrderCollationSpec" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1230 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "QuantifiedExpr" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1239 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "QVarInDeclList" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1248 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "QVarInDecl" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1257 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "SwitchExpr" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1266 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "SwitchCaseClauseList" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1275 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "SwitchCaseClause" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1284 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "SwitchCaseOperandList" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1293 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "TypeswitchExpr" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1302 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "CaseClauseList" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1311 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "CaseClause" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1320 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "IfExpr" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1329 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "OrExpr" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1338 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "AndExpr" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1347 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "ComparisonExpr" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1356 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "FTContainsExpr" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1365 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "opt_FTIgnoreOption" */

/* Line 479 of lalr1.cc  */
#line 905 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1374 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "RangeExpr" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1383 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "AdditiveExpr" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1392 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "MultiplicativeExpr" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1401 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "UnionExpr" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1410 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "IntersectExceptExpr" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1419 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "InstanceofExpr" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1428 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "TreatExpr" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1437 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "CastableExpr" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1446 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "CastExpr" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1455 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "UnaryExpr" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1464 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "SignList" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1473 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "ValueExpr" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1482 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "ValueComp" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1491 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "NodeComp" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1500 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "ValidateExpr" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1509 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "ExtensionExpr" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1518 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "Pragma_list" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1527 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "Pragma" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1536 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "PathExpr" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1545 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "RelativePathExpr" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1554 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "StepExpr" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1563 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "AxisStep" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1572 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "ForwardStep" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1581 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "ForwardAxis" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1590 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "AbbrevForwardStep" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1599 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "ReverseStep" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1608 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "ReverseAxis" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1617 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "NodeTest" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1626 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "NameTest" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1635 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "Wildcard" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1644 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "FilterExpr" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1653 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "PredicateList" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1662 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "Predicate" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1671 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "PrimaryExpr" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1680 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "Literal" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1689 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "NumericLiteral" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1698 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "VarRef" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1707 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "ParenthesizedExpr" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1716 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "ContextItemExpr" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1725 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "OrderedExpr" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1734 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "UnorderedExpr" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1743 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "FunctionCall" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1752 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "ArgList" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1761 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "Constructor" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1770 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "DirectConstructor" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1779 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "DirElemConstructor" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1788 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "DirElemContentList" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1797 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "DirAttributeList" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1806 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "DirAttr" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1815 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "DirAttributeValue" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1824 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "opt_QuoteAttrContentList" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1833 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "QuoteAttrContentList" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1842 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "opt_AposAttrContentList" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1851 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "AposAttrContentList" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1860 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "QuoteAttrValueContent" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1869 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "AposAttrValueContent" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1878 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "DirElemContent" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1887 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "CommonContent" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1896 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "DirCommentConstructor" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1905 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "DirPIConstructor" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1914 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "CDataSection" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1923 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "ComputedConstructor" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1932 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "CompDocConstructor" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1941 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "CompElemConstructor" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1950 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "CompAttrConstructor" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1959 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "CompTextConstructor" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1968 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "CompCommentConstructor" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1977 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "CompPIConstructor" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 1986 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "SingleType" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 1995 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "TypeDeclaration" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2004 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "SequenceType" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2013 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "OccurrenceIndicator" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2022 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "ItemType" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2031 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "TypeList" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2040 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "AtomicType" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2049 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "KindTest" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2058 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "AnyKindTest" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2067 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "DocumentTest" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2076 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "TextTest" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2085 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "CommentTest" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2094 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "PITest" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2103 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* "AttributeTest" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2112 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* "SchemaAttributeTest" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2121 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* "ElementTest" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2130 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* "SchemaElementTest" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2139 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "TypeName" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2148 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* "TypeName_WITH_HOOK" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2157 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 533: /* "StringLiteral" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2166 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* "AnyFunctionTest" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2175 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 539: /* "TypedFunctionTest" */

/* Line 479 of lalr1.cc  */
#line 902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2184 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* "InsertExpr" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2193 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 543: /* "DeleteExpr" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2202 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 544: /* "ReplaceExpr" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2211 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 545: /* "RenameExpr" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2220 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 546: /* "TransformExpr" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2229 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 547: /* "VarNameList" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2238 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 548: /* "VarNameDecl" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2247 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 549: /* "TryExpr" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2256 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 550: /* "CatchListExpr" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2265 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 551: /* "CatchExpr" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2274 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 552: /* "NameTestList" */

/* Line 479 of lalr1.cc  */
#line 911 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 479 of lalr1.cc  */
#line 2283 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 555: /* "EvalExpr" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2292 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 556: /* "FTSelection" */

/* Line 479 of lalr1.cc  */
#line 905 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2301 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 559: /* "FTOr" */

/* Line 479 of lalr1.cc  */
#line 905 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2310 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 560: /* "FTAnd" */

/* Line 479 of lalr1.cc  */
#line 905 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2319 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 561: /* "FTMildNot" */

/* Line 479 of lalr1.cc  */
#line 905 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2328 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 562: /* "FTUnaryNot" */

/* Line 479 of lalr1.cc  */
#line 905 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2337 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 563: /* "FTPrimaryWithOptions" */

/* Line 479 of lalr1.cc  */
#line 905 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2346 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 564: /* "opt_FTMatchOptions" */

/* Line 479 of lalr1.cc  */
#line 905 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2355 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 566: /* "FTWeight" */

/* Line 479 of lalr1.cc  */
#line 905 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2364 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 567: /* "FTPrimary" */

/* Line 479 of lalr1.cc  */
#line 905 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2373 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 568: /* "opt_FTTimes" */

/* Line 479 of lalr1.cc  */
#line 905 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2382 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 569: /* "FTExtensionSelection" */

/* Line 479 of lalr1.cc  */
#line 905 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2391 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 571: /* "FTWords" */

/* Line 479 of lalr1.cc  */
#line 905 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2400 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 572: /* "FTWordsValue" */

/* Line 479 of lalr1.cc  */
#line 905 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2409 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 574: /* "FTAnyallOption" */

/* Line 479 of lalr1.cc  */
#line 905 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2418 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 577: /* "FTPosFilter" */

/* Line 479 of lalr1.cc  */
#line 905 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2427 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 578: /* "FTOrder" */

/* Line 479 of lalr1.cc  */
#line 905 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2436 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 579: /* "FTWindow" */

/* Line 479 of lalr1.cc  */
#line 905 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2445 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 580: /* "FTDistance" */

/* Line 479 of lalr1.cc  */
#line 905 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2454 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 581: /* "FTUnit" */

/* Line 479 of lalr1.cc  */
#line 905 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2463 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 582: /* "FTMatchOptions" */

/* Line 479 of lalr1.cc  */
#line 905 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2472 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 583: /* "FTMatchOption" */

/* Line 479 of lalr1.cc  */
#line 905 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2481 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 584: /* "FTCaseOption" */

/* Line 479 of lalr1.cc  */
#line 905 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2490 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 585: /* "FTDiacriticsOption" */

/* Line 479 of lalr1.cc  */
#line 905 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2499 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 586: /* "FTExtensionOption" */

/* Line 479 of lalr1.cc  */
#line 905 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2508 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 587: /* "FTStemOption" */

/* Line 479 of lalr1.cc  */
#line 905 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2517 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 588: /* "FTThesaurusOption" */

/* Line 479 of lalr1.cc  */
#line 905 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2526 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 592: /* "FTThesaurusID" */

/* Line 479 of lalr1.cc  */
#line 905 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2535 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 595: /* "FTStopWordOption" */

/* Line 479 of lalr1.cc  */
#line 905 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2544 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 596: /* "FTStopWords" */

/* Line 479 of lalr1.cc  */
#line 905 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2553 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 600: /* "FTStopWordsInclExcl" */

/* Line 479 of lalr1.cc  */
#line 905 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2562 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 601: /* "FTLanguageOption" */

/* Line 479 of lalr1.cc  */
#line 905 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2571 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 602: /* "FTWildCardOption" */

/* Line 479 of lalr1.cc  */
#line 905 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2580 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 603: /* "FTContent" */

/* Line 479 of lalr1.cc  */
#line 905 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2589 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 604: /* "FTTimes" */

/* Line 479 of lalr1.cc  */
#line 905 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2598 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 605: /* "FTRange" */

/* Line 479 of lalr1.cc  */
#line 905 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2607 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 606: /* "FTScope" */

/* Line 479 of lalr1.cc  */
#line 905 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2616 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 607: /* "FTBigUnit" */

/* Line 479 of lalr1.cc  */
#line 905 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2625 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 608: /* "FTIgnoreOption" */

/* Line 479 of lalr1.cc  */
#line 905 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 479 of lalr1.cc  */
#line 2634 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 609: /* "QNAME" */

/* Line 479 of lalr1.cc  */
#line 908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 479 of lalr1.cc  */
#line 2643 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
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
#line 165 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename);
}

/* Line 552 of lalr1.cc  */
#line 2728 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"

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
#line 1050 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 4:

/* Line 677 of lalr1.cc  */
#line 1054 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.node) = NULL; }
    break;

  case 5:

/* Line 677 of lalr1.cc  */
#line 1055 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.node) = NULL; }
    break;

  case 6:

/* Line 677 of lalr1.cc  */
#line 1056 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.node) = NULL; }
    break;

  case 7:

/* Line 677 of lalr1.cc  */
#line 1057 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.node) = NULL; }
    break;

  case 8:

/* Line 677 of lalr1.cc  */
#line 1062 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1078 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 10:

/* Line 677 of lalr1.cc  */
#line 1083 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            MainModule *mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
            mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 11:

/* Line 677 of lalr1.cc  */
#line 1090 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 12:

/* Line 677 of lalr1.cc  */
#line 1095 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            LibraryModule *lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
            lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 13:

/* Line 677 of lalr1.cc  */
#line 1106 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            std::string encoding = "utf-8";
            (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), encoding );
        }
    break;

  case 14:

/* Line 677 of lalr1.cc  */
#line 1111 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
        }
    break;

  case 15:

/* Line 677 of lalr1.cc  */
#line 1119 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1127 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
        }
    break;

  case 17:

/* Line 677 of lalr1.cc  */
#line 1135 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LibraryModule(
                LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 18:

/* Line 677 of lalr1.cc  */
#line 1141 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1153 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
            dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
        }
    break;

  case 20:

/* Line 677 of lalr1.cc  */
#line 1162 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Prolog( LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(2) - (1)].node)), NULL );
        }
    break;

  case 21:

/* Line 677 of lalr1.cc  */
#line 1166 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Prolog( LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(2) - (1)].node)) );
        }
    break;

  case 22:

/* Line 677 of lalr1.cc  */
#line 1170 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1182 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
            sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
            (yyval.node) = sdl;
        }
    break;

  case 24:

/* Line 677 of lalr1.cc  */
#line 1188 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( SIND_DeclList *sdl = static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                sdl->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 25:

/* Line 677 of lalr1.cc  */
#line 1198 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
            vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
            (yyval.node) = vdl;
        }
    break;

  case 26:

/* Line 677 of lalr1.cc  */
#line 1204 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( VFO_DeclList *vdl = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vdl->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 40:

/* Line 677 of lalr1.cc  */
#line 1236 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
         (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
         delete (yysemantic_stack_[(4) - (4)].vstrpair);
       }
    break;

  case 41:

/* Line 677 of lalr1.cc  */
#line 1241 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
         (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
         delete (yysemantic_stack_[(4) - (4)].vstrpair);
       }
    break;

  case 42:

/* Line 677 of lalr1.cc  */
#line 1250 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.vstrpair) = new vector<string_pair_t>();
          (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
          delete (yysemantic_stack_[(1) - (1)].strpair);
        }
    break;

  case 43:

/* Line 677 of lalr1.cc  */
#line 1256 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
          delete (yysemantic_stack_[(2) - (2)].strpair);
          (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
        }
    break;

  case 44:

/* Line 677 of lalr1.cc  */
#line 1265 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
            (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval() );
            delete sl;
        }
    break;

  case 45:

/* Line 677 of lalr1.cc  */
#line 1273 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 46:

/* Line 677 of lalr1.cc  */
#line 1274 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 47:

/* Line 677 of lalr1.cc  */
#line 1275 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 48:

/* Line 677 of lalr1.cc  */
#line 1276 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 49:

/* Line 677 of lalr1.cc  */
#line 1277 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 50:

/* Line 677 of lalr1.cc  */
#line 1278 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 51:

/* Line 677 of lalr1.cc  */
#line 1279 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 52:

/* Line 677 of lalr1.cc  */
#line 1280 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 53:

/* Line 677 of lalr1.cc  */
#line 1281 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 54:

/* Line 677 of lalr1.cc  */
#line 1282 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 65:

/* Line 677 of lalr1.cc  */
#line 1313 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
        }
    break;

  case 66:

/* Line 677 of lalr1.cc  */
#line 1322 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BoundarySpaceDecl(
                LOC((yyloc)), StaticContextConsts::preserve_space
            );
        }
    break;

  case 67:

/* Line 677 of lalr1.cc  */
#line 1328 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BoundarySpaceDecl(
                LOC((yyloc)), StaticContextConsts::strip_space
            );
        }
    break;

  case 68:

/* Line 677 of lalr1.cc  */
#line 1338 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultNamespaceDecl(
                LOC((yyloc)), ParseConstants::ns_element_default, SYMTAB((yysemantic_stack_[(5) - (5)].sval))
            );
        }
    break;

  case 69:

/* Line 677 of lalr1.cc  */
#line 1344 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultNamespaceDecl(
                LOC((yyloc)), ParseConstants::ns_function_default, SYMTAB((yysemantic_stack_[(5) - (5)].sval))
            );
        }
    break;

  case 70:

/* Line 677 of lalr1.cc  */
#line 1354 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OptionDecl(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval))
            );
        }
    break;

  case 71:

/* Line 677 of lalr1.cc  */
#line 1364 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
        }
    break;

  case 72:

/* Line 677 of lalr1.cc  */
#line 1372 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OrderingModeDecl(
                LOC((yyloc)), StaticContextConsts::ordered
            );
        }
    break;

  case 73:

/* Line 677 of lalr1.cc  */
#line 1378 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OrderingModeDecl(
                LOC((yyloc)), StaticContextConsts::unordered
            );
        }
    break;

  case 74:

/* Line 677 of lalr1.cc  */
#line 1389 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new EmptyOrderDecl( LOC((yyloc)),
                                StaticContextConsts::empty_greatest);
        }
    break;

  case 75:

/* Line 677 of lalr1.cc  */
#line 1394 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new EmptyOrderDecl( LOC((yyloc)),
                                StaticContextConsts::empty_least);
        }
    break;

  case 76:

/* Line 677 of lalr1.cc  */
#line 1404 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::preserve_ns,
                                StaticContextConsts::inherit_ns);
        }
    break;

  case 77:

/* Line 677 of lalr1.cc  */
#line 1410 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::preserve_ns,
                                StaticContextConsts::no_inherit_ns);
        }
    break;

  case 78:

/* Line 677 of lalr1.cc  */
#line 1416 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::no_preserve_ns,
                                StaticContextConsts::inherit_ns);
        }
    break;

  case 79:

/* Line 677 of lalr1.cc  */
#line 1422 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::no_preserve_ns,
                                StaticContextConsts::no_inherit_ns);
        }
    break;

  case 80:

/* Line 677 of lalr1.cc  */
#line 1439 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
        }
    break;

  case 81:

/* Line 677 of lalr1.cc  */
#line 1447 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 82:

/* Line 677 of lalr1.cc  */
#line 1455 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
        }
    break;

  case 83:

/* Line 677 of lalr1.cc  */
#line 1459 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1468 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1477 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1490 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            URILiteralList *ull = new URILiteralList( LOC((yyloc)));
            ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.node) = ull;
        }
    break;

  case 87:

/* Line 677 of lalr1.cc  */
#line 1496 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
                ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 88:

/* Line 677 of lalr1.cc  */
#line 1507 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 89:

/* Line 677 of lalr1.cc  */
#line 1511 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
        }
    break;

  case 90:

/* Line 677 of lalr1.cc  */
#line 1519 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 91:

/* Line 677 of lalr1.cc  */
#line 1524 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 92:

/* Line 677 of lalr1.cc  */
#line 1529 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 93:

/* Line 677 of lalr1.cc  */
#line 1536 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1549 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
        }
    break;

  case 95:

/* Line 677 of lalr1.cc  */
#line 1556 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            CtxItemDecl *d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
            d->type = (yysemantic_stack_[(3) - (2)].node);
            (yyval.node) = d;
        }
    break;

  case 96:

/* Line 677 of lalr1.cc  */
#line 1562 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 97:

/* Line 677 of lalr1.cc  */
#line 1569 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            CtxItemDecl *d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
            d->ext = false;
            (yyval.node) = d;
        }
    break;

  case 98:

/* Line 677 of lalr1.cc  */
#line 1575 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CtxItemDecl( LOC((yyloc)), NULL );
        }
    break;

  case 99:

/* Line 677 of lalr1.cc  */
#line 1579 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 100:

/* Line 677 of lalr1.cc  */
#line 1586 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CtxItemDecl( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 101:

/* Line 677 of lalr1.cc  */
#line 1597 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 102:

/* Line 677 of lalr1.cc  */
#line 1601 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 103:

/* Line 677 of lalr1.cc  */
#line 1609 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(5) - (3)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, (yysemantic_stack_[(5) - (5)].expr));
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (1)].sval)));
    }
    break;

  case 104:

/* Line 677 of lalr1.cc  */
#line 1615 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(4) - (3)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, NULL, true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(4) - (1)].sval)));
    }
    break;

  case 105:

/* Line 677 of lalr1.cc  */
#line 1621 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(6) - (3)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, (yysemantic_stack_[(6) - (6)].expr), true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (1)].sval)));
    }
    break;

  case 106:

/* Line 677 of lalr1.cc  */
#line 1630 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            DeclPropertyList *dpl = new DeclPropertyList( LOC((yyloc)) );
            dpl->addProperty(dynamic_cast<DeclProperty*>((yysemantic_stack_[(1) - (1)].node)));
            (yyval.node) = dpl;
        }
    break;

  case 107:

/* Line 677 of lalr1.cc  */
#line 1636 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
        DeclPropertyList *dpl = dynamic_cast<DeclPropertyList*>((yysemantic_stack_[(2) - (1)].node));
        dpl->addProperty( static_cast<DeclProperty*>((yysemantic_stack_[(2) - (2)].node)) );
        (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 108:

/* Line 677 of lalr1.cc  */
#line 1645 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_const );
        }
    break;

  case 109:

/* Line 677 of lalr1.cc  */
#line 1649 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_append_only
            );
        }
    break;

  case 110:

/* Line 677 of lalr1.cc  */
#line 1655 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_queue );
        }
    break;

  case 111:

/* Line 677 of lalr1.cc  */
#line 1659 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_mutable );
        }
    break;

  case 112:

/* Line 677 of lalr1.cc  */
#line 1663 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_ordered );
        }
    break;

  case 113:

/* Line 677 of lalr1.cc  */
#line 1667 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_unordered
            );
        }
    break;

  case 114:

/* Line 677 of lalr1.cc  */
#line 1673 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_value_equality
            );
        }
    break;

  case 115:

/* Line 677 of lalr1.cc  */
#line 1679 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_value_range
            );
        }
    break;

  case 116:

/* Line 677 of lalr1.cc  */
#line 1685 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_general_equality
            );
        }
    break;

  case 117:

/* Line 677 of lalr1.cc  */
#line 1691 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_general_range
            );
        }
    break;

  case 118:

/* Line 677 of lalr1.cc  */
#line 1697 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_unique );
        }
    break;

  case 119:

/* Line 677 of lalr1.cc  */
#line 1701 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_non_unique
            );
        }
    break;

  case 120:

/* Line 677 of lalr1.cc  */
#line 1707 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_automatic
            );
        }
    break;

  case 121:

/* Line 677 of lalr1.cc  */
#line 1713 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_manual );
        }
    break;

  case 122:

/* Line 677 of lalr1.cc  */
#line 1720 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1728 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1736 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1744 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1752 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1764 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1778 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1792 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1809 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 131:

/* Line 677 of lalr1.cc  */
#line 1813 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 132:

/* Line 677 of lalr1.cc  */
#line 1820 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier( LOC((yyloc)), StaticContextConsts::read_only);
    }
    break;

  case 133:

/* Line 677 of lalr1.cc  */
#line 1824 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier( LOC((yyloc)), StaticContextConsts::mutable_node);
    }
    break;

  case 134:

/* Line 677 of lalr1.cc  */
#line 1831 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1839 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1856 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList( LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 137:

/* Line 677 of lalr1.cc  */
#line 1862 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 138:

/* Line 677 of lalr1.cc  */
#line 1870 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec( LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<AtomicType*>((yysemantic_stack_[(3) - (3)].node)),
                            NULL);
    }
    break;

  case 139:

/* Line 677 of lalr1.cc  */
#line 1877 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec( LOC((yyloc)),
                            (yysemantic_stack_[(4) - (1)].expr),
                            dynamic_cast<AtomicType*>((yysemantic_stack_[(4) - (3)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 140:

/* Line 677 of lalr1.cc  */
#line 1888 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1898 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1908 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1919 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1934 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ConstructionDecl(
                LOC((yyloc)), StaticContextConsts::cons_preserve
            );
        }
    break;

  case 145:

/* Line 677 of lalr1.cc  */
#line 1940 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ConstructionDecl(
                LOC((yyloc)), StaticContextConsts::cons_strip
            );
        }
    break;

  case 146:

/* Line 677 of lalr1.cc  */
#line 1951 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( NULL );
        }
    break;

  case 147:

/* Line 677 of lalr1.cc  */
#line 1955 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 148:

/* Line 677 of lalr1.cc  */
#line 1959 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)) );
        }
    break;

  case 149:

/* Line 677 of lalr1.cc  */
#line 1963 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig(
                dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 150:

/* Line 677 of lalr1.cc  */
#line 1972 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(2) - (2)].expr);
        }
    break;

  case 151:

/* Line 677 of lalr1.cc  */
#line 1979 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 1998 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2007 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 154:

/* Line 677 of lalr1.cc  */
#line 2014 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vfo = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node));
            vfo->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = vfo;
        }
    break;

  case 155:

/* Line 677 of lalr1.cc  */
#line 2020 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vfo = new VFO_DeclList( LOC((yyloc)) );
            vfo->push_back((yysemantic_stack_[(2) - (2)].node));
            (yyval.node) = vfo;
        }
    break;

  case 156:

/* Line 677 of lalr1.cc  */
#line 2030 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(1) - (1)].varnametype)));
      VarDecl* vd = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, NULL);
      vd->set_global(false);
      (yyval.node) = vd;
    }
    break;

  case 157:

/* Line 677 of lalr1.cc  */
#line 2037 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(3) - (1)].varnametype)));
      VarDecl* vd = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, (yysemantic_stack_[(3) - (3)].expr));
      vd->set_global(false);
      (yyval.node) = vd;
        }
    break;

  case 158:

/* Line 677 of lalr1.cc  */
#line 2048 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 159:

/* Line 677 of lalr1.cc  */
#line 2055 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExitExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 160:

/* Line 677 of lalr1.cc  */
#line 2062 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2074 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::BREAK );
        }
    break;

  case 162:

/* Line 677 of lalr1.cc  */
#line 2078 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
        }
    break;

  case 163:

/* Line 677 of lalr1.cc  */
#line 2085 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            dynamic_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 164:

/* Line 677 of lalr1.cc  */
#line 2090 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2105 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2122 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 167:

/* Line 677 of lalr1.cc  */
#line 2126 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 168:

/* Line 677 of lalr1.cc  */
#line 2130 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 169:

/* Line 677 of lalr1.cc  */
#line 2134 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 170:

/* Line 677 of lalr1.cc  */
#line 2142 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2152 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2166 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2176 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2190 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2200 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2215 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            ParamList *pl = new ParamList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 177:

/* Line 677 of lalr1.cc  */
#line 2221 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
                pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 178:

/* Line 677 of lalr1.cc  */
#line 2233 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 179:

/* Line 677 of lalr1.cc  */
#line 2237 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 180:

/* Line 677 of lalr1.cc  */
#line 2248 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new EnclosedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 181:

/* Line 677 of lalr1.cc  */
#line 2255 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 182:

/* Line 677 of lalr1.cc  */
#line 2263 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QueryBody( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 183:

/* Line 677 of lalr1.cc  */
#line 2278 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 184:

/* Line 677 of lalr1.cc  */
#line 2282 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2296 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new BlockBody( LOC((yyloc)) );
        }
    break;

  case 186:

/* Line 677 of lalr1.cc  */
#line 2300 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            BlockBody *bb = dynamic_cast<BlockBody*>((yysemantic_stack_[(3) - (1)].expr));
            bb->add( (yysemantic_stack_[(3) - (2)].expr) );
            (yyval.expr) = bb;
        }
    break;

  case 187:

/* Line 677 of lalr1.cc  */
#line 2309 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 188:

/* Line 677 of lalr1.cc  */
#line 2313 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2354 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2369 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 209:

/* Line 677 of lalr1.cc  */
#line 2376 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_sliding;
        }
    break;

  case 210:

/* Line 677 of lalr1.cc  */
#line 2380 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_tumbling;
        }
    break;

  case 211:

/* Line 677 of lalr1.cc  */
#line 2387 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_start;
        }
    break;

  case 212:

/* Line 677 of lalr1.cc  */
#line 2391 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_end;
        }
    break;

  case 213:

/* Line 677 of lalr1.cc  */
#line 2395 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_only_end;
        }
    break;

  case 214:

/* Line 677 of lalr1.cc  */
#line 2402 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2410 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FLWORWinCond(
                LOC((yyloc)), NULL, (yysemantic_stack_[(3) - (3)].expr),
                (yysemantic_stack_[(3) - (1)].strval) == parser::the_start, (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end
            );
        }
    break;

  case 216:

/* Line 677 of lalr1.cc  */
#line 2421 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2431 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2444 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 227:

/* Line 677 of lalr1.cc  */
#line 2466 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
            fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = fcl;
        }
    break;

  case 228:

/* Line 677 of lalr1.cc  */
#line 2472 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
            fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = fcl;
        }
    break;

  case 229:

/* Line 677 of lalr1.cc  */
#line 2481 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = NULL;
        }
    break;

  case 230:

/* Line 677 of lalr1.cc  */
#line 2485 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_ofor;
        }
    break;

  case 231:

/* Line 677 of lalr1.cc  */
#line 2493 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForClause(
                LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(2) - (2)].node)), (yysemantic_stack_[(2) - (1)].strval) != NULL
            );
        }
    break;

  case 232:

/* Line 677 of lalr1.cc  */
#line 2503 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            VarInDeclList *vdl = new VarInDeclList( LOC((yyloc)) );
            vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vdl;
        }
    break;

  case 233:

/* Line 677 of lalr1.cc  */
#line 2509 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( VarInDeclList *vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 234:

/* Line 677 of lalr1.cc  */
#line 2521 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 235:

/* Line 677 of lalr1.cc  */
#line 2525 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2533 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2542 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2552 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2560 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2569 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2578 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2593 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 243:

/* Line 677 of lalr1.cc  */
#line 2602 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
    }
    break;

  case 244:

/* Line 677 of lalr1.cc  */
#line 2612 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (3)].node)) );
        }
    break;

  case 245:

/* Line 677 of lalr1.cc  */
#line 2620 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 246:

/* Line 677 of lalr1.cc  */
#line 2626 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 247:

/* Line 677 of lalr1.cc  */
#line 2635 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 248:

/* Line 677 of lalr1.cc  */
#line 2641 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 249:

/* Line 677 of lalr1.cc  */
#line 2653 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2661 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2671 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2679 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2691 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 254:

/* Line 677 of lalr1.cc  */
#line 2697 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 256:

/* Line 677 of lalr1.cc  */
#line 2710 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 257:

/* Line 677 of lalr1.cc  */
#line 2714 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 258:

/* Line 677 of lalr1.cc  */
#line 2722 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 259:

/* Line 677 of lalr1.cc  */
#line 2726 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 261:

/* Line 677 of lalr1.cc  */
#line 2735 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 262:

/* Line 677 of lalr1.cc  */
#line 2739 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 263:

/* Line 677 of lalr1.cc  */
#line 2743 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 264:

/* Line 677 of lalr1.cc  */
#line 2751 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2765 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 266:

/* Line 677 of lalr1.cc  */
#line 2773 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 267:

/* Line 677 of lalr1.cc  */
#line 2780 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = new GroupSpecList( LOC((yyloc)) );
            gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 268:

/* Line 677 of lalr1.cc  */
#line 2786 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
            if ( gsl )
                gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 269:

/* Line 677 of lalr1.cc  */
#line 2797 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 270:

/* Line 677 of lalr1.cc  */
#line 2801 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                         dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 271:

/* Line 677 of lalr1.cc  */
#line 2810 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 272:

/* Line 677 of lalr1.cc  */
#line 2818 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 273:

/* Line 677 of lalr1.cc  */
#line 2824 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 274:

/* Line 677 of lalr1.cc  */
#line 2834 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 275:

/* Line 677 of lalr1.cc  */
#line 2840 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 276:

/* Line 677 of lalr1.cc  */
#line 2850 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 277:

/* Line 677 of lalr1.cc  */
#line 2854 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 278:

/* Line 677 of lalr1.cc  */
#line 2864 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 279:

/* Line 677 of lalr1.cc  */
#line 2870 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 280:

/* Line 677 of lalr1.cc  */
#line 2876 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 281:

/* Line 677 of lalr1.cc  */
#line 2882 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2891 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2900 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2909 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2922 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 286:

/* Line 677 of lalr1.cc  */
#line 2926 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 287:

/* Line 677 of lalr1.cc  */
#line 2934 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 288:

/* Line 677 of lalr1.cc  */
#line 2940 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 289:

/* Line 677 of lalr1.cc  */
#line 2950 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 290:

/* Line 677 of lalr1.cc  */
#line 2958 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2967 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 2980 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 293:

/* Line 677 of lalr1.cc  */
#line 2987 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 294:

/* Line 677 of lalr1.cc  */
#line 2999 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 295:

/* Line 677 of lalr1.cc  */
#line 3003 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 296:

/* Line 677 of lalr1.cc  */
#line 3015 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 297:

/* Line 677 of lalr1.cc  */
#line 3022 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 298:

/* Line 677 of lalr1.cc  */
#line 3028 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 299:

/* Line 677 of lalr1.cc  */
#line 3037 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 300:

/* Line 677 of lalr1.cc  */
#line 3044 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 301:

/* Line 677 of lalr1.cc  */
#line 3050 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 302:

/* Line 677 of lalr1.cc  */
#line 3062 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 303:

/* Line 677 of lalr1.cc  */
#line 3069 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3082 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 305:

/* Line 677 of lalr1.cc  */
#line 3088 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 306:

/* Line 677 of lalr1.cc  */
#line 3100 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 307:

/* Line 677 of lalr1.cc  */
#line 3106 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 308:

/* Line 677 of lalr1.cc  */
#line 3118 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 309:

/* Line 677 of lalr1.cc  */
#line 3127 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 310:

/* Line 677 of lalr1.cc  */
#line 3131 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 311:

/* Line 677 of lalr1.cc  */
#line 3140 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 312:

/* Line 677 of lalr1.cc  */
#line 3144 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 313:

/* Line 677 of lalr1.cc  */
#line 3152 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 314:

/* Line 677 of lalr1.cc  */
#line 3156 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3166 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 316:

/* Line 677 of lalr1.cc  */
#line 3173 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3182 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3191 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 319:

/* Line 677 of lalr1.cc  */
#line 3196 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3205 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3214 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3223 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3236 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 324:

/* Line 677 of lalr1.cc  */
#line 3240 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3252 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 326:

/* Line 677 of lalr1.cc  */
#line 3256 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 327:

/* Line 677 of lalr1.cc  */
#line 3263 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 328:

/* Line 677 of lalr1.cc  */
#line 3267 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 329:

/* Line 677 of lalr1.cc  */
#line 3276 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 330:

/* Line 677 of lalr1.cc  */
#line 3280 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 331:

/* Line 677 of lalr1.cc  */
#line 3284 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 332:

/* Line 677 of lalr1.cc  */
#line 3293 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 333:

/* Line 677 of lalr1.cc  */
#line 3297 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 334:

/* Line 677 of lalr1.cc  */
#line 3303 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 335:

/* Line 677 of lalr1.cc  */
#line 3309 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 336:

/* Line 677 of lalr1.cc  */
#line 3315 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 337:

/* Line 677 of lalr1.cc  */
#line 3326 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 338:

/* Line 677 of lalr1.cc  */
#line 3330 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 339:

/* Line 677 of lalr1.cc  */
#line 3334 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 340:

/* Line 677 of lalr1.cc  */
#line 3342 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 341:

/* Line 677 of lalr1.cc  */
#line 3346 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 342:

/* Line 677 of lalr1.cc  */
#line 3352 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 343:

/* Line 677 of lalr1.cc  */
#line 3362 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 344:

/* Line 677 of lalr1.cc  */
#line 3366 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 345:

/* Line 677 of lalr1.cc  */
#line 3376 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 346:

/* Line 677 of lalr1.cc  */
#line 3380 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 347:

/* Line 677 of lalr1.cc  */
#line 3390 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 348:

/* Line 677 of lalr1.cc  */
#line 3394 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 349:

/* Line 677 of lalr1.cc  */
#line 3404 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 350:

/* Line 677 of lalr1.cc  */
#line 3408 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 351:

/* Line 677 of lalr1.cc  */
#line 3418 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 352:

/* Line 677 of lalr1.cc  */
#line 3422 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 353:

/* Line 677 of lalr1.cc  */
#line 3430 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 354:

/* Line 677 of lalr1.cc  */
#line 3434 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 355:

/* Line 677 of lalr1.cc  */
#line 3438 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 356:

/* Line 677 of lalr1.cc  */
#line 3442 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 357:

/* Line 677 of lalr1.cc  */
#line 3452 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 358:

/* Line 677 of lalr1.cc  */
#line 3456 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 359:

/* Line 677 of lalr1.cc  */
#line 3460 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 360:

/* Line 677 of lalr1.cc  */
#line 3468 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 361:

/* Line 677 of lalr1.cc  */
#line 3472 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 362:

/* Line 677 of lalr1.cc  */
#line 3476 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 363:

/* Line 677 of lalr1.cc  */
#line 3480 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 364:

/* Line 677 of lalr1.cc  */
#line 3484 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 365:

/* Line 677 of lalr1.cc  */
#line 3488 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 366:

/* Line 677 of lalr1.cc  */
#line 3496 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 367:

/* Line 677 of lalr1.cc  */
#line 3500 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 368:

/* Line 677 of lalr1.cc  */
#line 3504 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 369:

/* Line 677 of lalr1.cc  */
#line 3512 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 370:

/* Line 677 of lalr1.cc  */
#line 3516 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 371:

/* Line 677 of lalr1.cc  */
#line 3520 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 372:

/* Line 677 of lalr1.cc  */
#line 3524 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 373:

/* Line 677 of lalr1.cc  */
#line 3535 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 374:

/* Line 677 of lalr1.cc  */
#line 3541 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 375:

/* Line 677 of lalr1.cc  */
#line 3551 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 376:

/* Line 677 of lalr1.cc  */
#line 3557 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 377:

/* Line 677 of lalr1.cc  */
#line 3567 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 378:

/* Line 677 of lalr1.cc  */
#line 3571 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 379:

/* Line 677 of lalr1.cc  */
#line 3609 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new PathExpr(
                LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL
            );
        }
    break;

  case 380:

/* Line 677 of lalr1.cc  */
#line 3615 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new PathExpr(
                LOC((yyloc)), ParseConstants::path_leading_slash, (yysemantic_stack_[(2) - (2)].expr)
            );
        }
    break;

  case 381:

/* Line 677 of lalr1.cc  */
#line 3621 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new PathExpr(
                LOC((yyloc)), ParseConstants::path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr)
            );
        }
    break;

  case 382:

/* Line 677 of lalr1.cc  */
#line 3627 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            RelativePathExpr *rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = !rpe ?
                (yysemantic_stack_[(1) - (1)].expr) : new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 383:

/* Line 677 of lalr1.cc  */
#line 3638 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NULL;
        }
    break;

  case 384:

/* Line 677 of lalr1.cc  */
#line 3646 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3657 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RelativePathExpr(
                LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 386:

/* Line 677 of lalr1.cc  */
#line 3663 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RelativePathExpr(
                LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 387:

/* Line 677 of lalr1.cc  */
#line 3673 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 388:

/* Line 677 of lalr1.cc  */
#line 3677 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 389:

/* Line 677 of lalr1.cc  */
#line 3685 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 390:

/* Line 677 of lalr1.cc  */
#line 3691 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3699 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 392:

/* Line 677 of lalr1.cc  */
#line 3705 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 3717 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 394:

/* Line 677 of lalr1.cc  */
#line 3723 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 395:

/* Line 677 of lalr1.cc  */
#line 3733 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 396:

/* Line 677 of lalr1.cc  */
#line 3737 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 397:

/* Line 677 of lalr1.cc  */
#line 3741 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 398:

/* Line 677 of lalr1.cc  */
#line 3745 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 399:

/* Line 677 of lalr1.cc  */
#line 3749 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 400:

/* Line 677 of lalr1.cc  */
#line 3755 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 401:

/* Line 677 of lalr1.cc  */
#line 3761 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 402:

/* Line 677 of lalr1.cc  */
#line 3769 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 403:

/* Line 677 of lalr1.cc  */
#line 3773 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 404:

/* Line 677 of lalr1.cc  */
#line 3781 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 405:

/* Line 677 of lalr1.cc  */
#line 3785 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 406:

/* Line 677 of lalr1.cc  */
#line 3796 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 407:

/* Line 677 of lalr1.cc  */
#line 3800 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 408:

/* Line 677 of lalr1.cc  */
#line 3804 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 409:

/* Line 677 of lalr1.cc  */
#line 3810 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 410:

/* Line 677 of lalr1.cc  */
#line 3814 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 411:

/* Line 677 of lalr1.cc  */
#line 3828 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 412:

/* Line 677 of lalr1.cc  */
#line 3832 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 413:

/* Line 677 of lalr1.cc  */
#line 3840 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 414:

/* Line 677 of lalr1.cc  */
#line 3844 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 415:

/* Line 677 of lalr1.cc  */
#line 3854 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all);
    }
    break;

  case 416:

/* Line 677 of lalr1.cc  */
#line 3858 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem);
    }
    break;

  case 417:

/* Line 677 of lalr1.cc  */
#line 3862 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix);
    }
    break;

  case 418:

/* Line 677 of lalr1.cc  */
#line 3871 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 419:

/* Line 677 of lalr1.cc  */
#line 3875 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FilterExpr(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 420:

/* Line 677 of lalr1.cc  */
#line 3881 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
        }
    break;

  case 421:

/* Line 677 of lalr1.cc  */
#line 3885 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
        }
    break;

  case 422:

/* Line 677 of lalr1.cc  */
#line 3893 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 423:

/* Line 677 of lalr1.cc  */
#line 3899 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 424:

/* Line 677 of lalr1.cc  */
#line 3909 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 425:

/* Line 677 of lalr1.cc  */
#line 3917 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 426:

/* Line 677 of lalr1.cc  */
#line 3921 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 427:

/* Line 677 of lalr1.cc  */
#line 3925 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 428:

/* Line 677 of lalr1.cc  */
#line 3929 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 429:

/* Line 677 of lalr1.cc  */
#line 3933 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 430:

/* Line 677 of lalr1.cc  */
#line 3937 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 431:

/* Line 677 of lalr1.cc  */
#line 3941 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 432:

/* Line 677 of lalr1.cc  */
#line 3945 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 433:

/* Line 677 of lalr1.cc  */
#line 3949 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 434:

/* Line 677 of lalr1.cc  */
#line 3957 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 435:

/* Line 677 of lalr1.cc  */
#line 3961 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 436:

/* Line 677 of lalr1.cc  */
#line 3969 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 437:

/* Line 677 of lalr1.cc  */
#line 3976 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 438:

/* Line 677 of lalr1.cc  */
#line 3983 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 439:

/* Line 677 of lalr1.cc  */
#line 3994 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 440:

/* Line 677 of lalr1.cc  */
#line 4002 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 441:

/* Line 677 of lalr1.cc  */
#line 4006 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 442:

/* Line 677 of lalr1.cc  */
#line 4014 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 443:

/* Line 677 of lalr1.cc  */
#line 4022 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 444:

/* Line 677 of lalr1.cc  */
#line 4030 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 445:

/* Line 677 of lalr1.cc  */
#line 4084 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
        }
    break;

  case 446:

/* Line 677 of lalr1.cc  */
#line 4088 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4100 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            ArgList *al = new ArgList( LOC((yyloc)) );
            al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
            (yyval.node) = al;
        }
    break;

  case 448:

/* Line 677 of lalr1.cc  */
#line 4106 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
                al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 449:

/* Line 677 of lalr1.cc  */
#line 4116 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 450:

/* Line 677 of lalr1.cc  */
#line 4120 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 451:

/* Line 677 of lalr1.cc  */
#line 4128 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 452:

/* Line 677 of lalr1.cc  */
#line 4132 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 453:

/* Line 677 of lalr1.cc  */
#line 4136 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 454:

/* Line 677 of lalr1.cc  */
#line 4144 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4154 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4164 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4174 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4184 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4194 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4209 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
            decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = decl;
        }
    break;

  case 461:

/* Line 677 of lalr1.cc  */
#line 4215 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( decl )
                decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 462:

/* Line 677 of lalr1.cc  */
#line 4226 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
            dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = dal;
        }
    break;

  case 463:

/* Line 677 of lalr1.cc  */
#line 4232 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
            if ( dal )
                dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 464:

/* Line 677 of lalr1.cc  */
#line 4243 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4260 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 468:

/* Line 677 of lalr1.cc  */
#line 4265 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 469:

/* Line 677 of lalr1.cc  */
#line 4274 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
        }
    break;

  case 470:

/* Line 677 of lalr1.cc  */
#line 4278 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 471:

/* Line 677 of lalr1.cc  */
#line 4285 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4293 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = qacl;
        }
    break;

  case 473:

/* Line 677 of lalr1.cc  */
#line 4299 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4309 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4321 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
        }
    break;

  case 476:

/* Line 677 of lalr1.cc  */
#line 4325 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 477:

/* Line 677 of lalr1.cc  */
#line 4332 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = aacl;
        }
    break;

  case 478:

/* Line 677 of lalr1.cc  */
#line 4338 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = aacl;
        }
    break;

  case 479:

/* Line 677 of lalr1.cc  */
#line 4344 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if (aacl)
                aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 480:

/* Line 677 of lalr1.cc  */
#line 4351 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( aacl )
                aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 481:

/* Line 677 of lalr1.cc  */
#line 4362 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 482:

/* Line 677 of lalr1.cc  */
#line 4366 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 483:

/* Line 677 of lalr1.cc  */
#line 4376 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 484:

/* Line 677 of lalr1.cc  */
#line 4380 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 485:

/* Line 677 of lalr1.cc  */
#line 4390 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 486:

/* Line 677 of lalr1.cc  */
#line 4394 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 487:

/* Line 677 of lalr1.cc  */
#line 4398 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
        }
    break;

  case 488:

/* Line 677 of lalr1.cc  */
#line 4403 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
        }
    break;

  case 489:

/* Line 677 of lalr1.cc  */
#line 4412 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval))
            );
        }
    break;

  case 490:

/* Line 677 of lalr1.cc  */
#line 4418 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_lbrace
            );
        }
    break;

  case 491:

/* Line 677 of lalr1.cc  */
#line 4424 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_rbrace
            );
        }
    break;

  case 492:

/* Line 677 of lalr1.cc  */
#line 4430 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 493:

/* Line 677 of lalr1.cc  */
#line 4440 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 494:

/* Line 677 of lalr1.cc  */
#line 4444 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
        }
    break;

  case 495:

/* Line 677 of lalr1.cc  */
#line 4456 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 496:

/* Line 677 of lalr1.cc  */
#line 4460 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 497:

/* Line 677 of lalr1.cc  */
#line 4472 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 498:

/* Line 677 of lalr1.cc  */
#line 4484 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 499:

/* Line 677 of lalr1.cc  */
#line 4488 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 500:

/* Line 677 of lalr1.cc  */
#line 4492 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 501:

/* Line 677 of lalr1.cc  */
#line 4496 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 502:

/* Line 677 of lalr1.cc  */
#line 4500 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 503:

/* Line 677 of lalr1.cc  */
#line 4504 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 504:

/* Line 677 of lalr1.cc  */
#line 4512 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 505:

/* Line 677 of lalr1.cc  */
#line 4520 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)), NULL
            );
        }
    break;

  case 506:

/* Line 677 of lalr1.cc  */
#line 4526 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr)
            );
        }
    break;

  case 507:

/* Line 677 of lalr1.cc  */
#line 4532 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 508:

/* Line 677 of lalr1.cc  */
#line 4536 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 509:

/* Line 677 of lalr1.cc  */
#line 4553 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (2)].expr), NULL );
        }
    break;

  case 510:

/* Line 677 of lalr1.cc  */
#line 4557 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(5) - (2)].expr), (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 511:

/* Line 677 of lalr1.cc  */
#line 4561 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 512:

/* Line 677 of lalr1.cc  */
#line 4565 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 513:

/* Line 677 of lalr1.cc  */
#line 4573 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 514:

/* Line 677 of lalr1.cc  */
#line 4581 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 515:

/* Line 677 of lalr1.cc  */
#line 4589 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), NULL );
        }
    break;

  case 516:

/* Line 677 of lalr1.cc  */
#line 4593 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (2)].sval)), (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 517:

/* Line 677 of lalr1.cc  */
#line 4597 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 518:

/* Line 677 of lalr1.cc  */
#line 4601 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 519:

/* Line 677 of lalr1.cc  */
#line 4609 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)), false
            );
        }
    break;

  case 520:

/* Line 677 of lalr1.cc  */
#line 4615 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)), true
            );
        }
    break;

  case 521:

/* Line 677 of lalr1.cc  */
#line 4625 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 522:

/* Line 677 of lalr1.cc  */
#line 4633 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 523:

/* Line 677 of lalr1.cc  */
#line 4637 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 524:

/* Line 677 of lalr1.cc  */
#line 4643 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 525:

/* Line 677 of lalr1.cc  */
#line 4678 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 526:

/* Line 677 of lalr1.cc  */
#line 4684 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 527:

/* Line 677 of lalr1.cc  */
#line 4690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 528:

/* Line 677 of lalr1.cc  */
#line 4700 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 529:

/* Line 677 of lalr1.cc  */
#line 4704 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 530:

/* Line 677 of lalr1.cc  */
#line 4708 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)),true );
        }
    break;

  case 531:

/* Line 677 of lalr1.cc  */
#line 4712 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 532:

/* Line 677 of lalr1.cc  */
#line 4716 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 533:

/* Line 677 of lalr1.cc  */
#line 4723 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 534:

/* Line 677 of lalr1.cc  */
#line 4729 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 535:

/* Line 677 of lalr1.cc  */
#line 4739 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 536:

/* Line 677 of lalr1.cc  */
#line 4747 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 537:

/* Line 677 of lalr1.cc  */
#line 4751 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 538:

/* Line 677 of lalr1.cc  */
#line 4755 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 539:

/* Line 677 of lalr1.cc  */
#line 4759 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 540:

/* Line 677 of lalr1.cc  */
#line 4763 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 541:

/* Line 677 of lalr1.cc  */
#line 4767 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 542:

/* Line 677 of lalr1.cc  */
#line 4771 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 543:

/* Line 677 of lalr1.cc  */
#line 4775 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 544:

/* Line 677 of lalr1.cc  */
#line 4779 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 545:

/* Line 677 of lalr1.cc  */
#line 4787 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyKindTest( LOC((yyloc)) );
        }
    break;

  case 546:

/* Line 677 of lalr1.cc  */
#line 4795 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)) );
        }
    break;

  case 547:

/* Line 677 of lalr1.cc  */
#line 4799 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)) );
        }
    break;

  case 548:

/* Line 677 of lalr1.cc  */
#line 4803 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest(
                LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 549:

/* Line 677 of lalr1.cc  */
#line 4813 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TextTest( LOC((yyloc)) );
        }
    break;

  case 550:

/* Line 677 of lalr1.cc  */
#line 4821 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CommentTest( LOC((yyloc)));
        }
    break;

  case 551:

/* Line 677 of lalr1.cc  */
#line 4829 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 552:

/* Line 677 of lalr1.cc  */
#line 4833 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 553:

/* Line 677 of lalr1.cc  */
#line 4837 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 554:

/* Line 677 of lalr1.cc  */
#line 4845 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 555:

/* Line 677 of lalr1.cc  */
#line 4849 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 556:

/* Line 677 of lalr1.cc  */
#line 4855 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 557:

/* Line 677 of lalr1.cc  */
#line 4861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 558:

/* Line 677 of lalr1.cc  */
#line 4865 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 559:

/* Line 677 of lalr1.cc  */
#line 4875 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)) );
        }
    break;

  case 560:

/* Line 677 of lalr1.cc  */
#line 4883 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 561:

/* Line 677 of lalr1.cc  */
#line 4887 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 562:

/* Line 677 of lalr1.cc  */
#line 4893 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4902 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 4911 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 565:

/* Line 677 of lalr1.cc  */
#line 4917 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 566:

/* Line 677 of lalr1.cc  */
#line 4923 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 567:

/* Line 677 of lalr1.cc  */
#line 4933 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 568:

/* Line 677 of lalr1.cc  */
#line 4950 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 569:

/* Line 677 of lalr1.cc  */
#line 4957 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 570:

/* Line 677 of lalr1.cc  */
#line 4972 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 571:

/* Line 677 of lalr1.cc  */
#line 5008 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 572:

/* Line 677 of lalr1.cc  */
#line 5012 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 573:

/* Line 677 of lalr1.cc  */
#line 5021 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
        }
    break;

  case 574:

/* Line 677 of lalr1.cc  */
#line 5030 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new InlineFunction(LOC ((yyloc)), &*(yysemantic_stack_[(3) - (2)].fnsig)->param, &*(yysemantic_stack_[(3) - (2)].fnsig)->ret, dynamic_cast<EnclosedExpr *>((yysemantic_stack_[(3) - (3)].expr)));
          delete (yysemantic_stack_[(3) - (2)].fnsig);
        }
    break;

  case 575:

/* Line 677 of lalr1.cc  */
#line 5040 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 576:

/* Line 677 of lalr1.cc  */
#line 5044 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 577:

/* Line 677 of lalr1.cc  */
#line 5053 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
        }
    break;

  case 578:

/* Line 677 of lalr1.cc  */
#line 5062 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 579:

/* Line 677 of lalr1.cc  */
#line 5066 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 580:

/* Line 677 of lalr1.cc  */
#line 5077 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 581:

/* Line 677 of lalr1.cc  */
#line 5094 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 582:

/* Line 677 of lalr1.cc  */
#line 5100 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 583:

/* Line 677 of lalr1.cc  */
#line 5106 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 584:

/* Line 677 of lalr1.cc  */
#line 5116 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 585:

/* Line 677 of lalr1.cc  */
#line 5120 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 586:

/* Line 677 of lalr1.cc  */
#line 5126 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 587:

/* Line 677 of lalr1.cc  */
#line 5132 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 588:

/* Line 677 of lalr1.cc  */
#line 5136 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 589:

/* Line 677 of lalr1.cc  */
#line 5142 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 590:

/* Line 677 of lalr1.cc  */
#line 5146 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 591:

/* Line 677 of lalr1.cc  */
#line 5152 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 592:

/* Line 677 of lalr1.cc  */
#line 5158 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 593:

/* Line 677 of lalr1.cc  */
#line 5165 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 594:

/* Line 677 of lalr1.cc  */
#line 5175 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 595:

/* Line 677 of lalr1.cc  */
#line 5180 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 596:

/* Line 677 of lalr1.cc  */
#line 5188 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 597:

/* Line 677 of lalr1.cc  */
#line 5194 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 598:

/* Line 677 of lalr1.cc  */
#line 5204 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 599:

/* Line 677 of lalr1.cc  */
#line 5226 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 600:

/* Line 677 of lalr1.cc  */
#line 5235 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 601:

/* Line 677 of lalr1.cc  */
#line 5241 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 602:

/* Line 677 of lalr1.cc  */
#line 5254 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 603:

/* Line 677 of lalr1.cc  */
#line 5268 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 604:

/* Line 677 of lalr1.cc  */
#line 5275 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 605:

/* Line 677 of lalr1.cc  */
#line 5281 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 606:

/* Line 677 of lalr1.cc  */
#line 5291 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 607:

/* Line 677 of lalr1.cc  */
#line 5296 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CatchExpr(LOC((yyloc)),*(yysemantic_stack_[(7) - (2)].name_test_list), static_cast<QName*>((yysemantic_stack_[(7) - (5)].expr)), NULL, NULL, (yysemantic_stack_[(7) - (7)].expr));
       delete (yysemantic_stack_[(7) - (2)].name_test_list);
    }
    break;

  case 608:

/* Line 677 of lalr1.cc  */
#line 5302 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5312 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5325 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 611:

/* Line 677 of lalr1.cc  */
#line 5331 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 614:

/* Line 677 of lalr1.cc  */
#line 5352 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5371 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new EvalExpr(
        LOC((yyloc)), dynamic_cast<VarGetsDeclList *> ((yysemantic_stack_[(7) - (3)].node)), (yysemantic_stack_[(7) - (6)].expr)
        );
    }
    break;

  case 616:

/* Line 677 of lalr1.cc  */
#line 5377 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new EvalExpr( LOC((yyloc)), new VarGetsDeclList( LOC((yyloc)) ), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 617:

/* Line 677 of lalr1.cc  */
#line 5392 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 618:

/* Line 677 of lalr1.cc  */
#line 5400 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 619:

/* Line 677 of lalr1.cc  */
#line 5404 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 620:

/* Line 677 of lalr1.cc  */
#line 5411 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 621:

/* Line 677 of lalr1.cc  */
#line 5416 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 622:

/* Line 677 of lalr1.cc  */
#line 5424 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 623:

/* Line 677 of lalr1.cc  */
#line 5428 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 624:

/* Line 677 of lalr1.cc  */
#line 5435 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 625:

/* Line 677 of lalr1.cc  */
#line 5439 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 626:

/* Line 677 of lalr1.cc  */
#line 5446 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 627:

/* Line 677 of lalr1.cc  */
#line 5450 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 628:

/* Line 677 of lalr1.cc  */
#line 5457 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 629:

/* Line 677 of lalr1.cc  */
#line 5461 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 630:

/* Line 677 of lalr1.cc  */
#line 5470 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5482 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 632:

/* Line 677 of lalr1.cc  */
#line 5486 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 633:

/* Line 677 of lalr1.cc  */
#line 5493 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 634:

/* Line 677 of lalr1.cc  */
#line 5497 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 635:

/* Line 677 of lalr1.cc  */
#line 5505 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 636:

/* Line 677 of lalr1.cc  */
#line 5513 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5521 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 638:

/* Line 677 of lalr1.cc  */
#line 5525 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 639:

/* Line 677 of lalr1.cc  */
#line 5532 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 640:

/* Line 677 of lalr1.cc  */
#line 5536 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 641:

/* Line 677 of lalr1.cc  */
#line 5544 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5555 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 643:

/* Line 677 of lalr1.cc  */
#line 5559 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 644:

/* Line 677 of lalr1.cc  */
#line 5567 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5579 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 646:

/* Line 677 of lalr1.cc  */
#line 5585 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 647:

/* Line 677 of lalr1.cc  */
#line 5594 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 648:

/* Line 677 of lalr1.cc  */
#line 5598 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 649:

/* Line 677 of lalr1.cc  */
#line 5606 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 650:

/* Line 677 of lalr1.cc  */
#line 5610 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 651:

/* Line 677 of lalr1.cc  */
#line 5614 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 652:

/* Line 677 of lalr1.cc  */
#line 5621 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 653:

/* Line 677 of lalr1.cc  */
#line 5625 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 654:

/* Line 677 of lalr1.cc  */
#line 5632 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 655:

/* Line 677 of lalr1.cc  */
#line 5636 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 656:

/* Line 677 of lalr1.cc  */
#line 5644 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 657:

/* Line 677 of lalr1.cc  */
#line 5648 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 658:

/* Line 677 of lalr1.cc  */
#line 5652 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 659:

/* Line 677 of lalr1.cc  */
#line 5656 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 660:

/* Line 677 of lalr1.cc  */
#line 5660 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 661:

/* Line 677 of lalr1.cc  */
#line 5668 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 662:

/* Line 677 of lalr1.cc  */
#line 5676 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5688 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5700 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 665:

/* Line 677 of lalr1.cc  */
#line 5704 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 666:

/* Line 677 of lalr1.cc  */
#line 5708 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 667:

/* Line 677 of lalr1.cc  */
#line 5716 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 668:

/* Line 677 of lalr1.cc  */
#line 5722 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 669:

/* Line 677 of lalr1.cc  */
#line 5732 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 670:

/* Line 677 of lalr1.cc  */
#line 5736 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 671:

/* Line 677 of lalr1.cc  */
#line 5740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 672:

/* Line 677 of lalr1.cc  */
#line 5744 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 673:

/* Line 677 of lalr1.cc  */
#line 5748 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 674:

/* Line 677 of lalr1.cc  */
#line 5752 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 675:

/* Line 677 of lalr1.cc  */
#line 5756 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 676:

/* Line 677 of lalr1.cc  */
#line 5760 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 677:

/* Line 677 of lalr1.cc  */
#line 5768 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 678:

/* Line 677 of lalr1.cc  */
#line 5772 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 679:

/* Line 677 of lalr1.cc  */
#line 5776 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 680:

/* Line 677 of lalr1.cc  */
#line 5780 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 681:

/* Line 677 of lalr1.cc  */
#line 5788 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 682:

/* Line 677 of lalr1.cc  */
#line 5794 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 683:

/* Line 677 of lalr1.cc  */
#line 5804 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 684:

/* Line 677 of lalr1.cc  */
#line 5814 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::with );
        }
    break;

  case 685:

/* Line 677 of lalr1.cc  */
#line 5818 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::without );
        }
    break;

  case 686:

/* Line 677 of lalr1.cc  */
#line 5826 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5836 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5847 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 689:

/* Line 677 of lalr1.cc  */
#line 5854 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 690:

/* Line 677 of lalr1.cc  */
#line 5858 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 691:

/* Line 677 of lalr1.cc  */
#line 5865 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 692:

/* Line 677 of lalr1.cc  */
#line 5869 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(1) - (1)].thesaurus_id_list);
        }
    break;

  case 693:

/* Line 677 of lalr1.cc  */
#line 5876 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 694:

/* Line 677 of lalr1.cc  */
#line 5881 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 695:

/* Line 677 of lalr1.cc  */
#line 5890 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 696:

/* Line 677 of lalr1.cc  */
#line 5899 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = NULL;
        }
    break;

  case 697:

/* Line 677 of lalr1.cc  */
#line 5903 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 698:

/* Line 677 of lalr1.cc  */
#line 5910 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 699:

/* Line 677 of lalr1.cc  */
#line 5914 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 700:

/* Line 677 of lalr1.cc  */
#line 5922 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 5931 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 702:

/* Line 677 of lalr1.cc  */
#line 5938 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 703:

/* Line 677 of lalr1.cc  */
#line 5948 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 704:

/* Line 677 of lalr1.cc  */
#line 5952 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), NULL, (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 705:

/* Line 677 of lalr1.cc  */
#line 5959 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 706:

/* Line 677 of lalr1.cc  */
#line 5965 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 707:

/* Line 677 of lalr1.cc  */
#line 5974 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 708:

/* Line 677 of lalr1.cc  */
#line 5978 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 709:

/* Line 677 of lalr1.cc  */
#line 5985 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 710:

/* Line 677 of lalr1.cc  */
#line 5990 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 6002 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 6010 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 6022 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 714:

/* Line 677 of lalr1.cc  */
#line 6030 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 715:

/* Line 677 of lalr1.cc  */
#line 6034 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 716:

/* Line 677 of lalr1.cc  */
#line 6042 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 717:

/* Line 677 of lalr1.cc  */
#line 6046 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 718:

/* Line 677 of lalr1.cc  */
#line 6050 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 719:

/* Line 677 of lalr1.cc  */
#line 6058 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 720:

/* Line 677 of lalr1.cc  */
#line 6066 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 721:

/* Line 677 of lalr1.cc  */
#line 6070 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 722:

/* Line 677 of lalr1.cc  */
#line 6074 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 723:

/* Line 677 of lalr1.cc  */
#line 6078 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 724:

/* Line 677 of lalr1.cc  */
#line 6086 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 6094 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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
#line 6106 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 727:

/* Line 677 of lalr1.cc  */
#line 6110 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 728:

/* Line 677 of lalr1.cc  */
#line 6118 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 729:

/* Line 677 of lalr1.cc  */
#line 6131 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 730:

/* Line 677 of lalr1.cc  */
#line 6135 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 731:

/* Line 677 of lalr1.cc  */
#line 6141 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("xquery"); }
    break;

  case 732:

/* Line 677 of lalr1.cc  */
#line 6142 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("empty"); }
    break;

  case 733:

/* Line 677 of lalr1.cc  */
#line 6143 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("attribute"); }
    break;

  case 734:

/* Line 677 of lalr1.cc  */
#line 6144 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("comment"); }
    break;

  case 735:

/* Line 677 of lalr1.cc  */
#line 6145 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("document-node"); }
    break;

  case 736:

/* Line 677 of lalr1.cc  */
#line 6146 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("element"); }
    break;

  case 737:

/* Line 677 of lalr1.cc  */
#line 6147 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("item"); }
    break;

  case 738:

/* Line 677 of lalr1.cc  */
#line 6148 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("if"); }
    break;

  case 739:

/* Line 677 of lalr1.cc  */
#line 6149 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("node"); }
    break;

  case 740:

/* Line 677 of lalr1.cc  */
#line 6150 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("processing-instruction"); }
    break;

  case 741:

/* Line 677 of lalr1.cc  */
#line 6151 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("schema-attribute"); }
    break;

  case 742:

/* Line 677 of lalr1.cc  */
#line 6152 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("schema-element"); }
    break;

  case 743:

/* Line 677 of lalr1.cc  */
#line 6153 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("text"); }
    break;

  case 744:

/* Line 677 of lalr1.cc  */
#line 6154 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("typeswitch"); }
    break;

  case 745:

/* Line 677 of lalr1.cc  */
#line 6155 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("empty-sequence"); }
    break;

  case 746:

/* Line 677 of lalr1.cc  */
#line 6156 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("boundary-space"); }
    break;

  case 747:

/* Line 677 of lalr1.cc  */
#line 6157 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ft-option"); }
    break;

  case 748:

/* Line 677 of lalr1.cc  */
#line 6158 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("base-uri"); }
    break;

  case 749:

/* Line 677 of lalr1.cc  */
#line 6159 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("lax"); }
    break;

  case 750:

/* Line 677 of lalr1.cc  */
#line 6160 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("strict"); }
    break;

  case 751:

/* Line 677 of lalr1.cc  */
#line 6161 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("idiv"); }
    break;

  case 752:

/* Line 677 of lalr1.cc  */
#line 6162 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("document"); }
    break;

  case 753:

/* Line 677 of lalr1.cc  */
#line 6163 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ftnot"); }
    break;

  case 754:

/* Line 677 of lalr1.cc  */
#line 6164 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("not"); }
    break;

  case 755:

/* Line 677 of lalr1.cc  */
#line 6165 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("sensitive"); }
    break;

  case 756:

/* Line 677 of lalr1.cc  */
#line 6166 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("insensitive"); }
    break;

  case 757:

/* Line 677 of lalr1.cc  */
#line 6167 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("diacritics"); }
    break;

  case 758:

/* Line 677 of lalr1.cc  */
#line 6168 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("without"); }
    break;

  case 759:

/* Line 677 of lalr1.cc  */
#line 6169 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("stemming"); }
    break;

  case 760:

/* Line 677 of lalr1.cc  */
#line 6170 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("thesaurus"); }
    break;

  case 761:

/* Line 677 of lalr1.cc  */
#line 6171 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("stop"); }
    break;

  case 762:

/* Line 677 of lalr1.cc  */
#line 6172 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("wildcards"); }
    break;

  case 763:

/* Line 677 of lalr1.cc  */
#line 6173 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("entire"); }
    break;

  case 764:

/* Line 677 of lalr1.cc  */
#line 6174 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("content"); }
    break;

  case 765:

/* Line 677 of lalr1.cc  */
#line 6175 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("word"); }
    break;

  case 766:

/* Line 677 of lalr1.cc  */
#line 6176 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("start"); }
    break;

  case 767:

/* Line 677 of lalr1.cc  */
#line 6177 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("end"); }
    break;

  case 768:

/* Line 677 of lalr1.cc  */
#line 6178 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("most"); }
    break;

  case 769:

/* Line 677 of lalr1.cc  */
#line 6179 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("skip"); }
    break;

  case 770:

/* Line 677 of lalr1.cc  */
#line 6180 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("copy"); }
    break;

  case 771:

/* Line 677 of lalr1.cc  */
#line 6181 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("general"); }
    break;

  case 772:

/* Line 677 of lalr1.cc  */
#line 6182 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("value"); }
    break;

  case 773:

/* Line 677 of lalr1.cc  */
#line 6183 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("eq"); }
    break;

  case 774:

/* Line 677 of lalr1.cc  */
#line 6184 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ne"); }
    break;

  case 775:

/* Line 677 of lalr1.cc  */
#line 6185 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("lt"); }
    break;

  case 776:

/* Line 677 of lalr1.cc  */
#line 6186 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("le"); }
    break;

  case 777:

/* Line 677 of lalr1.cc  */
#line 6187 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("gt"); }
    break;

  case 778:

/* Line 677 of lalr1.cc  */
#line 6188 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ge"); }
    break;

  case 779:

/* Line 677 of lalr1.cc  */
#line 6189 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("at"); }
    break;

  case 780:

/* Line 677 of lalr1.cc  */
#line 6190 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("context"); }
    break;

  case 781:

/* Line 677 of lalr1.cc  */
#line 6191 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("variable"); }
    break;

  case 782:

/* Line 677 of lalr1.cc  */
#line 6192 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("return"); }
    break;

  case 783:

/* Line 677 of lalr1.cc  */
#line 6193 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("for"); }
    break;

  case 784:

/* Line 677 of lalr1.cc  */
#line 6194 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("outer"); }
    break;

  case 785:

/* Line 677 of lalr1.cc  */
#line 6195 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("sliding"); }
    break;

  case 786:

/* Line 677 of lalr1.cc  */
#line 6196 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("tumbling"); }
    break;

  case 787:

/* Line 677 of lalr1.cc  */
#line 6197 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("previous"); }
    break;

  case 788:

/* Line 677 of lalr1.cc  */
#line 6198 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("next"); }
    break;

  case 789:

/* Line 677 of lalr1.cc  */
#line 6199 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("only"); }
    break;

  case 790:

/* Line 677 of lalr1.cc  */
#line 6200 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("when"); }
    break;

  case 791:

/* Line 677 of lalr1.cc  */
#line 6201 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("count"); }
    break;

  case 792:

/* Line 677 of lalr1.cc  */
#line 6202 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("in"); }
    break;

  case 793:

/* Line 677 of lalr1.cc  */
#line 6203 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("let"); }
    break;

  case 794:

/* Line 677 of lalr1.cc  */
#line 6204 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("where"); }
    break;

  case 795:

/* Line 677 of lalr1.cc  */
#line 6205 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("by"); }
    break;

  case 796:

/* Line 677 of lalr1.cc  */
#line 6206 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("group"); }
    break;

  case 797:

/* Line 677 of lalr1.cc  */
#line 6207 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("order"); }
    break;

  case 798:

/* Line 677 of lalr1.cc  */
#line 6208 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("stable"); }
    break;

  case 799:

/* Line 677 of lalr1.cc  */
#line 6209 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ascending"); }
    break;

  case 800:

/* Line 677 of lalr1.cc  */
#line 6210 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("descending"); }
    break;

  case 801:

/* Line 677 of lalr1.cc  */
#line 6211 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("greatest"); }
    break;

  case 802:

/* Line 677 of lalr1.cc  */
#line 6212 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("least"); }
    break;

  case 803:

/* Line 677 of lalr1.cc  */
#line 6213 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("collation"); }
    break;

  case 804:

/* Line 677 of lalr1.cc  */
#line 6214 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("some"); }
    break;

  case 805:

/* Line 677 of lalr1.cc  */
#line 6215 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("every"); }
    break;

  case 806:

/* Line 677 of lalr1.cc  */
#line 6216 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("satisfies"); }
    break;

  case 807:

/* Line 677 of lalr1.cc  */
#line 6217 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("case"); }
    break;

  case 808:

/* Line 677 of lalr1.cc  */
#line 6218 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("as"); }
    break;

  case 809:

/* Line 677 of lalr1.cc  */
#line 6219 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("then"); }
    break;

  case 810:

/* Line 677 of lalr1.cc  */
#line 6220 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("else"); }
    break;

  case 811:

/* Line 677 of lalr1.cc  */
#line 6221 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("or"); }
    break;

  case 812:

/* Line 677 of lalr1.cc  */
#line 6222 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("and"); }
    break;

  case 813:

/* Line 677 of lalr1.cc  */
#line 6223 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("instance"); }
    break;

  case 814:

/* Line 677 of lalr1.cc  */
#line 6224 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("of"); }
    break;

  case 815:

/* Line 677 of lalr1.cc  */
#line 6225 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("castable"); }
    break;

  case 816:

/* Line 677 of lalr1.cc  */
#line 6226 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("to"); }
    break;

  case 817:

/* Line 677 of lalr1.cc  */
#line 6227 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("div"); }
    break;

  case 818:

/* Line 677 of lalr1.cc  */
#line 6228 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("mod"); }
    break;

  case 819:

/* Line 677 of lalr1.cc  */
#line 6229 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("union"); }
    break;

  case 820:

/* Line 677 of lalr1.cc  */
#line 6230 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("intersect"); }
    break;

  case 821:

/* Line 677 of lalr1.cc  */
#line 6231 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("except"); }
    break;

  case 822:

/* Line 677 of lalr1.cc  */
#line 6232 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("validate"); }
    break;

  case 823:

/* Line 677 of lalr1.cc  */
#line 6233 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("cast"); }
    break;

  case 824:

/* Line 677 of lalr1.cc  */
#line 6234 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("treat"); }
    break;

  case 825:

/* Line 677 of lalr1.cc  */
#line 6235 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("is"); }
    break;

  case 826:

/* Line 677 of lalr1.cc  */
#line 6236 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("preserve"); }
    break;

  case 827:

/* Line 677 of lalr1.cc  */
#line 6237 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("strip"); }
    break;

  case 828:

/* Line 677 of lalr1.cc  */
#line 6238 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("namespace"); }
    break;

  case 829:

/* Line 677 of lalr1.cc  */
#line 6239 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("external"); }
    break;

  case 830:

/* Line 677 of lalr1.cc  */
#line 6240 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("encoding"); }
    break;

  case 831:

/* Line 677 of lalr1.cc  */
#line 6241 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("no-preserve"); }
    break;

  case 832:

/* Line 677 of lalr1.cc  */
#line 6242 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("inherit"); }
    break;

  case 833:

/* Line 677 of lalr1.cc  */
#line 6243 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("no-inherit"); }
    break;

  case 834:

/* Line 677 of lalr1.cc  */
#line 6244 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("declare"); }
    break;

  case 835:

/* Line 677 of lalr1.cc  */
#line 6245 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("construction"); }
    break;

  case 836:

/* Line 677 of lalr1.cc  */
#line 6246 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ordering"); }
    break;

  case 837:

/* Line 677 of lalr1.cc  */
#line 6247 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("default"); }
    break;

  case 838:

/* Line 677 of lalr1.cc  */
#line 6248 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("copy-namespaces"); }
    break;

  case 839:

/* Line 677 of lalr1.cc  */
#line 6249 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("option"); }
    break;

  case 840:

/* Line 677 of lalr1.cc  */
#line 6250 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("version"); }
    break;

  case 841:

/* Line 677 of lalr1.cc  */
#line 6251 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("import"); }
    break;

  case 842:

/* Line 677 of lalr1.cc  */
#line 6252 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("schema"); }
    break;

  case 843:

/* Line 677 of lalr1.cc  */
#line 6253 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("module"); }
    break;

  case 844:

/* Line 677 of lalr1.cc  */
#line 6254 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("function"); }
    break;

  case 845:

/* Line 677 of lalr1.cc  */
#line 6255 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("score"); }
    break;

  case 846:

/* Line 677 of lalr1.cc  */
#line 6256 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("contains"); }
    break;

  case 847:

/* Line 677 of lalr1.cc  */
#line 6257 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("weight"); }
    break;

  case 848:

/* Line 677 of lalr1.cc  */
#line 6258 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("window"); }
    break;

  case 849:

/* Line 677 of lalr1.cc  */
#line 6259 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("distance"); }
    break;

  case 850:

/* Line 677 of lalr1.cc  */
#line 6260 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("occurs"); }
    break;

  case 851:

/* Line 677 of lalr1.cc  */
#line 6261 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("times"); }
    break;

  case 852:

/* Line 677 of lalr1.cc  */
#line 6262 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("same"); }
    break;

  case 853:

/* Line 677 of lalr1.cc  */
#line 6263 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("different"); }
    break;

  case 854:

/* Line 677 of lalr1.cc  */
#line 6264 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("lowercase"); }
    break;

  case 855:

/* Line 677 of lalr1.cc  */
#line 6265 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("uppercase"); }
    break;

  case 856:

/* Line 677 of lalr1.cc  */
#line 6266 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("relationship"); }
    break;

  case 857:

/* Line 677 of lalr1.cc  */
#line 6267 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("levels"); }
    break;

  case 858:

/* Line 677 of lalr1.cc  */
#line 6268 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("language"); }
    break;

  case 859:

/* Line 677 of lalr1.cc  */
#line 6269 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("any"); }
    break;

  case 860:

/* Line 677 of lalr1.cc  */
#line 6270 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("all"); }
    break;

  case 861:

/* Line 677 of lalr1.cc  */
#line 6271 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("phrase"); }
    break;

  case 862:

/* Line 677 of lalr1.cc  */
#line 6272 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("exactly"); }
    break;

  case 863:

/* Line 677 of lalr1.cc  */
#line 6273 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("from"); }
    break;

  case 864:

/* Line 677 of lalr1.cc  */
#line 6274 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("words"); }
    break;

  case 865:

/* Line 677 of lalr1.cc  */
#line 6275 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("sentences"); }
    break;

  case 866:

/* Line 677 of lalr1.cc  */
#line 6276 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("sentence"); }
    break;

  case 867:

/* Line 677 of lalr1.cc  */
#line 6277 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("paragraph"); }
    break;

  case 868:

/* Line 677 of lalr1.cc  */
#line 6278 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("replace"); }
    break;

  case 869:

/* Line 677 of lalr1.cc  */
#line 6279 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("modify"); }
    break;

  case 870:

/* Line 677 of lalr1.cc  */
#line 6280 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("first"); }
    break;

  case 871:

/* Line 677 of lalr1.cc  */
#line 6281 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("insert"); }
    break;

  case 872:

/* Line 677 of lalr1.cc  */
#line 6282 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("before"); }
    break;

  case 873:

/* Line 677 of lalr1.cc  */
#line 6283 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("after"); }
    break;

  case 874:

/* Line 677 of lalr1.cc  */
#line 6284 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("revalidation"); }
    break;

  case 875:

/* Line 677 of lalr1.cc  */
#line 6285 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("with"); }
    break;

  case 876:

/* Line 677 of lalr1.cc  */
#line 6286 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("nodes"); }
    break;

  case 877:

/* Line 677 of lalr1.cc  */
#line 6287 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("rename"); }
    break;

  case 878:

/* Line 677 of lalr1.cc  */
#line 6288 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("last"); }
    break;

  case 879:

/* Line 677 of lalr1.cc  */
#line 6289 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("delete"); }
    break;

  case 880:

/* Line 677 of lalr1.cc  */
#line 6290 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("into"); }
    break;

  case 881:

/* Line 677 of lalr1.cc  */
#line 6291 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("simple"); }
    break;

  case 882:

/* Line 677 of lalr1.cc  */
#line 6292 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("sequential"); }
    break;

  case 883:

/* Line 677 of lalr1.cc  */
#line 6293 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("updating"); }
    break;

  case 884:

/* Line 677 of lalr1.cc  */
#line 6294 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("deterministic"); }
    break;

  case 885:

/* Line 677 of lalr1.cc  */
#line 6295 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("nondeterministic"); }
    break;

  case 886:

/* Line 677 of lalr1.cc  */
#line 6296 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ordered"); }
    break;

  case 887:

/* Line 677 of lalr1.cc  */
#line 6297 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("unordered"); }
    break;

  case 888:

/* Line 677 of lalr1.cc  */
#line 6298 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("returning"); }
    break;

  case 889:

/* Line 677 of lalr1.cc  */
#line 6299 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("block"); }
    break;

  case 890:

/* Line 677 of lalr1.cc  */
#line 6300 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("exit"); }
    break;

  case 891:

/* Line 677 of lalr1.cc  */
#line 6301 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("loop"); }
    break;

  case 892:

/* Line 677 of lalr1.cc  */
#line 6302 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("while"); }
    break;

  case 893:

/* Line 677 of lalr1.cc  */
#line 6303 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("break"); }
    break;

  case 894:

/* Line 677 of lalr1.cc  */
#line 6304 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("continue"); }
    break;

  case 895:

/* Line 677 of lalr1.cc  */
#line 6305 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("try"); }
    break;

  case 896:

/* Line 677 of lalr1.cc  */
#line 6306 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("catch"); }
    break;

  case 897:

/* Line 677 of lalr1.cc  */
#line 6307 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("eval"); }
    break;

  case 898:

/* Line 677 of lalr1.cc  */
#line 6308 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("using"); }
    break;

  case 899:

/* Line 677 of lalr1.cc  */
#line 6309 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("set"); }
    break;

  case 900:

/* Line 677 of lalr1.cc  */
#line 6310 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("index"); }
    break;

  case 901:

/* Line 677 of lalr1.cc  */
#line 6311 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("unique"); }
    break;

  case 902:

/* Line 677 of lalr1.cc  */
#line 6312 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("non"); }
    break;

  case 903:

/* Line 677 of lalr1.cc  */
#line 6313 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("on"); }
    break;

  case 904:

/* Line 677 of lalr1.cc  */
#line 6314 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("range"); }
    break;

  case 905:

/* Line 677 of lalr1.cc  */
#line 6315 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("equality"); }
    break;

  case 906:

/* Line 677 of lalr1.cc  */
#line 6316 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("manually"); }
    break;

  case 907:

/* Line 677 of lalr1.cc  */
#line 6317 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("automatically"); }
    break;

  case 908:

/* Line 677 of lalr1.cc  */
#line 6318 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("maintained"); }
    break;

  case 909:

/* Line 677 of lalr1.cc  */
#line 6319 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("decimal-format"); }
    break;

  case 910:

/* Line 677 of lalr1.cc  */
#line 6320 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("decimal-separator"); }
    break;

  case 911:

/* Line 677 of lalr1.cc  */
#line 6321 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("grouping-separator"); }
    break;

  case 912:

/* Line 677 of lalr1.cc  */
#line 6322 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("infinity"); }
    break;

  case 913:

/* Line 677 of lalr1.cc  */
#line 6323 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("minus-sign"); }
    break;

  case 914:

/* Line 677 of lalr1.cc  */
#line 6324 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("NaN"); }
    break;

  case 915:

/* Line 677 of lalr1.cc  */
#line 6325 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("percent"); }
    break;

  case 916:

/* Line 677 of lalr1.cc  */
#line 6326 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("per-mille"); }
    break;

  case 917:

/* Line 677 of lalr1.cc  */
#line 6327 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("zero-digit"); }
    break;

  case 918:

/* Line 677 of lalr1.cc  */
#line 6328 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("digit"); }
    break;

  case 919:

/* Line 677 of lalr1.cc  */
#line 6329 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("pattern-separator"); }
    break;

  case 920:

/* Line 677 of lalr1.cc  */
#line 6330 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("collection"); }
    break;

  case 921:

/* Line 677 of lalr1.cc  */
#line 6331 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("const"); }
    break;

  case 922:

/* Line 677 of lalr1.cc  */
#line 6332 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("append-only"); }
    break;

  case 923:

/* Line 677 of lalr1.cc  */
#line 6333 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("queue"); }
    break;

  case 924:

/* Line 677 of lalr1.cc  */
#line 6334 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("mutable"); }
    break;

  case 925:

/* Line 677 of lalr1.cc  */
#line 6335 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("read-only"); }
    break;

  case 926:

/* Line 677 of lalr1.cc  */
#line 6336 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("integrity"); }
    break;

  case 927:

/* Line 677 of lalr1.cc  */
#line 6337 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("constraint"); }
    break;

  case 928:

/* Line 677 of lalr1.cc  */
#line 6338 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("check"); }
    break;

  case 929:

/* Line 677 of lalr1.cc  */
#line 6339 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("key"); }
    break;

  case 930:

/* Line 677 of lalr1.cc  */
#line 6340 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("foreach"); }
    break;

  case 931:

/* Line 677 of lalr1.cc  */
#line 6341 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("foreign"); }
    break;

  case 932:

/* Line 677 of lalr1.cc  */
#line 6342 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("keys"); }
    break;

  case 933:

/* Line 677 of lalr1.cc  */
#line 6343 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ancestor"); }
    break;

  case 934:

/* Line 677 of lalr1.cc  */
#line 6344 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("child"); }
    break;

  case 935:

/* Line 677 of lalr1.cc  */
#line 6345 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("descendant"); }
    break;

  case 936:

/* Line 677 of lalr1.cc  */
#line 6346 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("parent"); }
    break;

  case 937:

/* Line 677 of lalr1.cc  */
#line 6347 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("preceding"); }
    break;

  case 938:

/* Line 677 of lalr1.cc  */
#line 6348 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("self"); }
    break;

  case 939:

/* Line 677 of lalr1.cc  */
#line 6349 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("following"); }
    break;

  case 940:

/* Line 677 of lalr1.cc  */
#line 6350 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ancestor-or-self"); }
    break;

  case 941:

/* Line 677 of lalr1.cc  */
#line 6351 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("descendant-or-self"); }
    break;

  case 942:

/* Line 677 of lalr1.cc  */
#line 6352 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("following-sibling"); }
    break;

  case 943:

/* Line 677 of lalr1.cc  */
#line 6353 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("preceding-sibling"); }
    break;



/* Line 677 of lalr1.cc  */
#line 11351 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1326;
  const short int
  xquery_parser::yypact_[] =
  {
      1580, -1326, -1326, -1326, -1326, -1326,  1182,   123, -1326, -1326,
     444, -1326, -1326, -1326, -1326,    51,   196,  9742,   243,   383,
     230,   258,   100, -1326,   314, -1326, -1326, -1326, -1326, -1326,
   -1326,   373, -1326,  7737, -1326, -1326,   313, -1326,   369, -1326,
   -1326,   420, -1326,   448, -1326,   399,   440, -1326,   237, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326,   500,   503, -1326, -1326, -1326, -1326,  9172,  7155,
   -1326, -1326, -1326,   512, -1326, -1326, -1326, -1326, -1326,   514,
     517, -1326, -1326, 11167, -1326, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326,   525, -1326, -1326,   536,   538, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326,  2174, 11167, -1326, -1326, -1326, -1326,
   -1326, -1326, -1326,   509, -1326, -1326,   544,  8315, -1326,  8602,
     545,   551, -1326, -1326, -1326, 11167,   552, -1326,  6862, -1326,
   -1326, -1326, -1326, -1326, -1326,   522, -1326, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326,    39,   461, -1326, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326,   302,   523,   394, -1326,   453,   276,
   -1326, -1326, -1326, -1326, -1326, -1326,   563, -1326,   533,   445,
     446,   447, -1326, -1326,   539,   541, -1326,   570, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,  1881,   684,
   -1326,   685,  5104, -1326, -1326,   454,  5397,   511,   515, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
      -5, -1326, -1326, -1326, -1326,   350, 11167, -1326, -1326, -1326,
   -1326, -1326, -1326,   535,   610, -1326,   506,   456,   229,   223,
     351,   142, -1326,   656,   516,   612,   613,  5983, -1326, -1326,
   -1326,   195, -1326, -1326,  6862, -1326,   317, -1326,   565,  7155,
   -1326,   565,  7155, -1326, -1326, -1326,   472, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
     262, -1326,   689,   247,   361,   -30,   395, 11167,   395, 11167,
     -40,   672,   674,   676, 11167,   573,   607,   308,  8315, -1326,
   -1326,   389,   274,   480, 11167, -1326, -1326, -1326, -1326, -1326,
     434, 11167,   430,   431,   301,   429,   468, -1326, -1326, -1326,
   -1326, -1326,  8315,  5397,   549,  5397,    30, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326,  5397, 10027, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,   584,  5397,
     455,   458, -1326,   622,     9,   589,  5397,   109,    72, 11167,
     625, -1326,  5397,  8026,   592, -1326, 11167, 11167, 11167,  5397,
     560,  5397,  5397, 11167,  5397,   594,   595, -1326, -1326, -1326,
    5397, 10312,   596,   597,   599,   605,   611,   614, -1326, -1326,
   -1326, -1326, -1326, -1326, 11167, -1326, -1326, -1326,   564,   716,
    5397, -1326,    62, -1326,   729, -1326, -1326,   582, -1326, -1326,
    5397,   556, -1326,   744,  5397,  5397,   588,  5397,  5397,  5397,
    5397,   546, 11167, -1326, -1326, -1326, -1326,  5397,  5397,  5397,
   11167, -1326,   685, -1326, -1326, -1326, -1326,  1182,   100, -1326,
   -1326,   454,   742,  5397, -1326,  5397,   657,   383,   314,   373,
     615,   608,   609,  5397,  5397, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326,   678, -1326,   -33,  6276,  6276,  6276, -1326,  6276,
    6276, -1326,  6276, -1326,  6276, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326,  6276,  6276,   709,  6276,  6276,  6276,  6276,  6276,
    6276,  6276,  6276,  6276,  6276,  6276,   553,   691,   692,   693,
   -1326, -1326, -1326,  2467, -1326, -1326,  6862,  6862,  5397,   565,
   -1326, -1326,   565, -1326,  2760,   565,   641,  3053, -1326, -1326,
   -1326, -1326, -1326, -1326,   686,   687, -1326,   230, -1326,   764,
   -1326, -1326, 11167, -1326, 11167,   483,   263, 11167,   415,   633,
     636,   483,   689,   673,   667, -1326, -1326, -1326, -1326, -1326,
      -8,   554,   -18, -1326,   502, -1326, -1326, -1326, -1326, 11167,
   11167, 11167, -1326,   671,   621, -1326,   623,   599,   313, -1326,
     619,   627,   624, -1326,    -6,    -4,  3346,   631, -1326, -1326,
   11167,    -9, 11167,   712,     4, -1326,  5397, -1326,   629,  8315,
     718,   772,  8315,   689,   720,   711, -1326,   -41, -1326,   637,
     635, -1326,   638,  3639,   639,   680,   -19, -1326,    17,   640,
   -1326,   642,   643,   677, -1326,   648,  5397,  5397,   649, -1326,
      10,    12,  3932,   -11, -1326, 11167,   716, -1326,   -24,   650,
   -1326, -1326, -1326, -1326,   652, -1326,    -7, -1326, -1326, -1326,
      66,    88,   730,   600,   616,   -32, -1326,   694,  5690, -1326,
     653,   655,   112, -1326, -1326, -1326,   658, -1326, 11436, -1326,
   -1326,    -3, 11167,   670,  5397,   723, -1326, -1326,   724, 10597,
     726,  5397,   727,   -49,   700,   -12,   610, -1326, -1326, -1326,
   -1326, -1326,  6276, -1326, -1326, -1326,    21,   223,   223,   356,
     351,   351,   351,   351,   142,   142, -1326, -1326, 10597, 10597,
   11167, 11167, -1326,   666, -1326, -1326,   668, -1326, -1326, -1326,
      13, -1326, -1326,    14,   -15,   371,   328, -1326,   230,   230,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
     483, -1326,   719, 10882,   708,  5397, -1326, -1326, -1326,   757,
     713,  5397,   689,   689,   483, -1326,   457,   689,   309, 11167,
     283,   284,   826, -1326, -1326,   569,    45, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,    -8,    26,
     315, -1326,   630,   254,    27,   558,   689, -1326, -1326, -1326,
   -1326,   706, 11167, -1326, 11167, -1326, -1326,   681, -1326,   233,
     617, -1326, -1326,   370,    -9,   757, 10597,   746,   767,   683,
     679,   735,   689,   710,   736,   771,   689,   752,  5397,   731,
     -59,   721, -1326, -1326, -1326,   695, -1326,  5397,   756,  5397,
    5397,   732, -1326,   776,   781,  5397, -1326,   701,   702,   733,
   11167, -1326, 11167, -1326, -1326,   704,  5397,   848, -1326,   -23,
   -1326,    56, -1326, -1326,   860, -1326,   397,  5397,  5397,  5397,
     398,  5397,  5397,  5397,  5397,  5397,  5397,   770,  5397,  5397,
     607,     1,   707,   533,   645,   739,   775,   742,   815, -1326,
   -1326,  5397,   386,   789, -1326, 11167,   791, -1326, 11167,   745,
     747, 10882,   749, -1326,   156, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326, 11167, -1326, 11167,  5397,   753,  5397,  5397,    -1,
     755, -1326,  5397,    21,   270,   268, -1326,   620,    55,   651,
     647, -1326, -1326,   480, -1326,   644,   251, -1326, -1326, -1326,
     765, -1326, -1326, -1326,  5397, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326,  5397, -1326,   358,   393, -1326,   883,   442, -1326,
   -1326, -1326,  5397, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
     626, -1326, -1326,   886, -1326, -1326, -1326, -1326, -1326,   182,
     887, -1326,   439, -1326, -1326, -1326,   597,   196,   605,   611,
     614,   523,   682,   156,   690,   696,  6569,   628,   618,    26,
   -1326,   697,   728,  4225,   734,   740,   777,   741,   743, -1326,
    5397,   783, -1326,   803,   809,  5397, 11167,    93,   852, -1326,
   -1326, -1326, -1326, -1326, -1326, 10597, -1326,  5397,   689,   824,
   -1326, -1326, -1326,   689,   824, 11167, -1326,  5397,  5397,   792,
    4518, -1326, -1326, 11167, -1326, -1326,  5397,  5397,    43, -1326,
     -14,  9457,   264, -1326,   754, -1326, -1326,  4811,   750,   758,
   -1326, -1326, -1326,   806, -1326,   122, -1326, -1326,   921, -1326,
   -1326, 11167, -1326, -1326,   189, -1326, -1326, -1326,   759,   714,
     715, -1326, -1326, -1326,   717,   722, -1326, -1326, -1326, -1326,
   -1326,   703, 11167,   760, -1326,   800, -1326,   607, -1326, -1326,
   -1326,  7448,   645, -1326,  5397, 11167,   789, -1326,   689, -1326,
     486, -1326,   210,   839, -1326,  5397,   844,   723, -1326,  8887,
     766,   768,   773, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
    5397, -1326, -1326,  5397,   810,  5397,   778,   774, -1326,    21,
     705, -1326, -1326,   -77, -1326,  -121,    29,   725,    21,  -121,
    6276, -1326,    91, -1326, -1326, -1326, -1326, -1326, -1326,    21,
     811,   698,   554,    29, -1326, -1326,   675,   873, -1326, -1326,
   -1326, -1326, -1326,   780, -1326, -1326, -1326,  5397, -1326, -1326,
   -1326, -1326, -1326,   936,   -25,   937,   -25,   737,   868, -1326,
   -1326, -1326, -1326,   797, 11167,   738,   682,  6569, -1326, -1326,
     785, -1326, -1326, -1326, -1326, -1326, -1326,  5397, 11167, 11167,
   -1326,    95, -1326,  5397, -1326,   846,   875,   689,   824, -1326,
   -1326, -1326,  5397, -1326,   794, -1326, -1326, -1326,   790, -1326,
    5397,  5397, 11167,   793,    22, -1326, -1326, -1326,   796, -1326,
   -1326,   848, 11167,   201, -1326,   848, 11167, -1326, -1326,  5397,
    5397,  5397,  5397,  5397, -1326,  5397,  5397, -1326, -1326,   148,
   -1326,   801, -1326, -1326, -1326, -1326,   839, -1326, -1326, -1326,
     689, -1326, -1326,   878,   799, -1326,   134, -1326, -1326, -1326,
   -1326, -1326,  5397, -1326, -1326, -1326, -1326,   804,  6276, -1326,
   -1326, -1326, -1326, -1326,    37,  6276,  6276,   220, -1326,   651,
   -1326,   164, -1326,   647,    21,   835, -1326, -1326,   748, -1326,
   -1326, -1326, -1326, -1326,   -16, -1326,   199,   199, -1326,   -25,
   -1326, -1326,   150, -1326,   962,    29,   805,   885, -1326,  6569,
     -73,   751, -1326,   825, -1326, -1326, -1326,   940, -1326, -1326,
    5397,   689, -1326, -1326, -1326,  5397, -1326, -1326,   901,  5397,
   11167,  5397, -1326,   -13,   848, 11167,   802,   848, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326,   881,  7448, -1326, -1326, -1326,
   -1326, 10597, -1326, 10597,   905, -1326, -1326,   351,  6276,  6276,
     356,   296, -1326, -1326, -1326, -1326, -1326, -1326,  5397, -1326,
   -1326, -1326, -1326, -1326,   974, -1326, -1326, -1326,   761, -1326,
     868,   896, -1326,   910, 11167,   888,   788, 11167,  6569,   889,
   -1326,   824, -1326, 10597, -1326,   840, -1326,    69,   357, -1326,
     828,   848, -1326,   830, 11167, -1326, -1326, -1326, 10597,   356,
     356,  6276,   845, -1326, -1326, -1326,  6569, 11167,   762, 11167,
     911,   807,   896, 11167,   850,  5397, -1326, -1326,   938,   307,
   -1326, -1326, -1326, -1326,   849,   409, -1326, -1326, -1326,   841,
   -1326,   181, -1326,   356, -1326, -1326,   839,  5397,   763, 11167,
     917, -1326,  5397, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
   -1326,   919,   890, -1326, -1326,   769,   779, 11167, -1326, 11167,
   -1326,   782,  5397,   784,   186,  6569, -1326,  6569,   922,   890,
   -1326,   842, 11167, -1326,   787,   856, 11167,   890,   819, -1326,
     926, 11167,   786,  6569, -1326
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
         0,     8,   416,   417,   729,   570,   834,   843,   748,   746,
     734,   835,   838,   791,   884,   752,   735,   736,   897,   783,
     844,   738,   841,   813,   793,   768,   788,   885,   789,   839,
     836,   784,   787,   740,   842,   741,   742,   882,   899,   881,
     785,   804,   798,   743,   786,     0,   744,   883,   822,   790,
     765,   909,   910,   911,   912,   913,   914,   915,   916,   917,
     918,   919,   933,   940,   812,   808,   799,   779,   733,     0,
     807,   815,   823,   934,   803,   436,   780,   781,   837,   935,
     941,   800,   817,     0,   442,   405,   438,   810,   732,   801,
     802,   830,   805,   821,   829,   939,   942,   751,   792,   832,
     437,   820,   825,   737,     0,     0,   354,   818,   828,   833,
     831,   811,   797,   886,   795,   796,   936,     0,   353,     0,
     937,   943,   826,   782,   806,     0,   938,   383,     0,   415,
     827,   809,   816,   824,   819,   887,   773,   778,   777,   776,
     775,   774,   745,   794,     0,   731,   840,   766,   873,   872,
     874,   750,   749,   769,   879,   739,   871,   876,   877,   868,
     772,   814,   870,   880,   878,   869,   770,   875,   889,   893,
     894,   890,   891,   888,   892,   895,   896,   898,   860,   859,
     846,   764,   757,   853,   849,   767,   763,   862,   863,   753,
     754,   747,   756,   858,   857,   854,   850,   867,   861,   856,
     852,   845,   755,   866,   865,   759,   761,   760,   851,   855,
     847,   762,   848,   758,   864,   920,   921,   922,   923,   924,
     925,   901,   902,   900,   906,   907,   908,   903,   904,   905,
     771,   926,   927,   928,   929,   930,   931,   932,     0,     0,
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
     169,   168,     0,     0,     0,     0,     0,   834,   843,   734,
     752,   735,   736,   897,   783,   844,   738,   841,   793,   784,
     740,   742,   899,   804,   743,   744,   822,   933,   940,   733,
     934,   935,   941,   805,   939,   942,     0,     0,   886,   936,
     937,   943,   938,   887,   731,   879,   739,   871,   877,   868,
     770,   889,   893,   894,   890,   892,   895,   898,     0,     0,
       0,     0,   229,     0,     0,     0,     0,     0,     0,     0,
       0,   613,     0,     0,     0,   614,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   407,   410,   397,
       0,     0,     0,   734,   736,   740,   743,   733,   403,   413,
     395,   396,   399,   439,     0,   401,   400,   440,     0,   465,
       0,   406,     0,   378,     0,   409,   408,     0,   398,   381,
       0,     0,   494,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   153,   150,   161,   162,     0,     0,     0,
       0,     6,     3,     1,     5,    10,    12,     0,     0,    18,
      15,    20,    21,     0,   185,   184,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   207,   226,   222,   228,   223,
     225,   224,   231,   232,     0,     0,     0,     0,   368,     0,
       0,   366,     0,   318,     0,   367,   360,   365,   364,   363,
     362,   361,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     356,   355,   352,     0,   376,   380,     0,     0,     0,   390,
     422,   393,   392,   404,     0,   419,     0,     0,   612,    81,
      66,    67,   144,   145,     0,     0,   165,     0,   164,     0,
      72,    73,     0,   167,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   581,   582,   583,   115,   114,
       0,    71,   122,   119,     0,   121,   120,   117,   116,     0,
       0,     0,   107,     0,     0,   550,     0,     0,     0,   546,
       0,     0,     0,   560,     0,     0,     0,     0,   209,   210,
       0,     0,     0,   146,     0,   176,     0,   574,     0,     0,
      90,     0,     0,     0,    82,   244,   245,     0,   230,     0,
       0,   551,     0,     0,     0,     0,     0,   292,     0,     0,
     549,     0,     0,     0,   568,     0,     0,     0,     0,   554,
       0,     0,     0,     0,   441,   466,   465,   462,     0,     0,
     496,   495,   377,   559,     0,   493,     0,   594,   595,   545,
       0,     0,     0,     0,     0,     0,   600,     0,     0,   159,
       0,     0,     0,   247,   264,     7,     0,    24,     0,    26,
     188,     0,     0,     0,     0,     0,   208,   265,     0,     0,
       0,     0,     0,     0,     0,     0,   310,   312,   316,   322,
     321,   320,     0,   317,   314,   315,     0,   331,   330,   328,
     334,   335,   336,   333,   338,   339,   342,   341,     0,     0,
       0,     0,   373,     0,   385,   386,     0,   423,   420,   447,
       0,   573,   445,     0,     0,     0,     0,    70,     0,     0,
      45,    47,    48,    49,    50,    52,    53,    54,    46,    51,
      41,    42,     0,     0,    98,     0,    94,    96,    97,   101,
     104,     0,     0,     0,    40,    80,     0,     0,     0,     0,
       0,     0,     0,   679,   684,     0,     0,   680,   714,   667,
     669,   670,   671,   673,   675,   674,   672,   676,     0,     0,
       0,   123,     0,     0,   126,     0,     0,   514,   504,   547,
     548,     0,     0,   564,     0,   561,   505,     0,   616,     0,
       0,   211,   212,     0,   217,   178,     0,     0,   147,     0,
       0,     0,     0,     0,     0,    83,     0,     0,     0,     0,
       0,     0,   553,   552,   515,     0,   567,     0,     0,     0,
       0,     0,   513,     0,     0,     0,   369,     0,     0,     0,
       0,   557,     0,   555,   509,     0,     0,   465,   463,     0,
     454,     0,   443,   444,     0,    13,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     834,     0,     0,     0,     0,     0,     0,    22,     0,   186,
     218,     0,   276,   272,   274,     0,   266,   267,     0,   844,
     737,     0,   745,   521,   522,   528,   529,   531,   575,   576,
     532,   535,     0,   234,     0,     0,     0,     0,     0,     0,
       0,   319,     0,     0,     0,     0,   645,   325,   618,   622,
     624,   626,   628,   631,   638,   639,   647,   344,   346,   348,
     519,   350,   374,   424,     0,   421,   446,    78,    79,    76,
      77,   171,     0,   170,     0,     0,    43,     0,     0,    99,
     100,   102,     0,   103,    68,    69,    74,    75,    65,   685,
       0,   688,   715,     0,   678,   677,   682,   681,   713,     0,
       0,   690,     0,   686,   689,   668,     0,     0,     0,     0,
       0,     0,   124,   130,     0,     0,     0,     0,     0,     0,
     127,     0,     0,     0,     0,     0,   568,     0,     0,   506,
       0,     0,   213,     0,     0,     0,     0,   258,     0,   255,
     260,   216,   179,   148,   177,     0,   180,     0,     0,    92,
      86,    89,    88,     0,    84,     0,   249,     0,     0,     0,
       0,   516,   158,     0,   290,   294,     0,     0,     0,   297,
       0,     0,     0,   304,     0,   371,   370,     0,     0,     0,
     510,   291,   466,     0,   455,     0,   489,   486,     0,   490,
     491,     0,   492,   485,     0,   460,   488,   487,     0,     0,
       0,   587,   588,   584,     0,     0,   592,   593,   589,   598,
     596,     0,     0,     0,   602,   156,   155,     0,   152,   151,
     160,     0,   603,   604,     0,     0,   273,   285,     0,   286,
       0,   277,   278,   279,   280,     0,   269,     0,   233,     0,
       0,     0,     0,   525,   527,   526,   523,   242,   243,   236,
       0,   238,   235,     0,     0,     0,     0,     0,   629,   642,
       0,   324,   326,     0,   661,     0,     0,     0,     0,     0,
       0,   617,   619,   620,   656,   657,   658,   660,   659,     0,
       0,   633,   632,     0,   636,   640,   654,   652,   651,   644,
     648,   520,   448,     0,   173,   172,   175,     0,    44,    95,
     105,   702,   683,     0,   707,     0,   707,   696,   691,   125,
     131,   133,   132,     0,     0,     0,   128,     0,    19,   507,
       0,   565,   566,   569,   562,   563,   253,     0,     0,     0,
     215,   256,   259,     0,   149,     0,    91,     0,    85,   246,
     251,   250,     0,   517,     0,   293,   295,   300,     0,   298,
       0,     0,     0,     0,     0,   305,   372,   511,     0,   558,
     556,   465,     0,     0,   497,   465,     0,   461,    14,     0,
       0,     0,     0,     0,   601,     0,     0,   154,   610,     0,
     605,     0,   248,   289,   287,   288,   281,   282,   283,   275,
       0,   270,   268,     0,     0,   533,     0,   530,   580,   524,
     240,   237,     0,   239,   646,   637,   643,     0,     0,   716,
     717,   727,   726,   725,     0,     0,     0,     0,   718,   623,
     724,     0,   621,   625,     0,     0,   630,   634,     0,   655,
     650,   653,   649,   181,     0,   703,     0,     0,   701,   708,
     709,   705,     0,   700,     0,   698,     0,   692,   693,     0,
       0,     0,   129,     0,   508,   254,   262,   263,   257,   214,
       0,     0,    87,   252,   518,     0,   301,   299,     0,     0,
       0,     0,   512,     0,   465,     0,     0,   465,   585,   586,
     590,   591,   597,   599,   157,     0,     0,   606,   615,   284,
     271,     0,   577,     0,     0,   241,   641,   728,     0,     0,
     720,     0,   666,   665,   664,   663,   662,   627,     0,   719,
     174,   712,   711,   710,     0,   704,   697,   695,     0,   687,
       0,   134,   136,     0,     0,     0,     0,     0,     0,     0,
     308,    93,   296,     0,   306,     0,   302,   475,   469,   464,
       0,   465,   456,     0,     0,   611,   578,   534,     0,   722,
     721,     0,     0,   706,   699,   694,     0,     0,     0,     0,
       0,     0,   135,     0,     0,     0,   483,   477,     0,   476,
     478,   484,   481,   471,     0,   470,   472,   482,   458,     0,
     457,     0,   579,   723,   635,   137,   138,     0,     0,     0,
       0,   261,     0,   303,   468,   479,   480,   467,   473,   474,
     459,     0,     0,   139,   140,     0,     0,     0,   307,     0,
     607,     0,     0,     0,     0,     0,   142,     0,     0,     0,
     141,     0,     0,   608,     0,     0,     0,     0,     0,   609,
       0,     0,     0,     0,   143
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1326, -1326,  -210,   808, -1326,   798,   812, -1326,   813, -1326,
     477,   478,  -539, -1326,   380,  -308, -1326, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
    -911, -1326, -1326, -1326, -1326,   -10,   188,   659, -1326, -1326,
     662, -1326,   -56,  -869, -1326,  -464,  -489, -1326, -1326,  -598,
   -1326,  -897, -1326, -1326,  -146, -1326, -1326, -1326, -1326, -1326,
     249,   688, -1326, -1326, -1326,   139,   587, -1325,   817,   -91,
   -1326,  -554,    35, -1326, -1326, -1326, -1326,   143, -1326, -1326,
     795, -1326, -1326, -1326, -1326, -1326,    61,  -540,  -684, -1326,
   -1326, -1326,   -71, -1326, -1326,  -246,   -48,  -134, -1326, -1326,
   -1326,  -145, -1326, -1326,    82,  -141, -1326, -1326,  -137, -1186,
   -1326,   562,   -65, -1326, -1326,   -66, -1326, -1326, -1326,   -68,
   -1326, -1326,   501,   504, -1326,  -544, -1326, -1326,  -606,    28,
    -605,    44,    33, -1326, -1326, -1326, -1326, -1326,   814, -1326,
   -1326, -1326, -1326,  -794,  -301, -1077, -1326,  -110, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326,   -39, -1172, -1326, -1326,   265,
     -45, -1326,  -792, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
     450, -1326,  -939, -1326,   -76, -1326,   342,  -744, -1326, -1326,
   -1326, -1326, -1326,  -463,  -458, -1098, -1040, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326,   272,  -656,  -798,
       2,  -799, -1326,  -812,  -782, -1326, -1326, -1326, -1326, -1326,
   -1326, -1326,   699,   818,  -462,   190,    41, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
   -1326,   -96, -1326, -1326,  -102, -1326,  -355,   -93, -1326,  -991,
   -1326, -1326, -1326,  -147,  -157,  -300,    79, -1326, -1326, -1326,
   -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326, -1326,
    -143, -1326, -1326, -1326,  -296,    73,   219, -1326, -1326, -1326,
   -1326, -1326,    31, -1326, -1326, -1253, -1326, -1326, -1326,  -774,
   -1326,  -176, -1326,  -307, -1326, -1326, -1326, -1326, -1210, -1326,
    -138, -1326,   -17, -1326
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   850,   851,   852,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
    1129,   713,   265,   266,   856,   857,   858,  1195,   267,   406,
     407,   268,  1092,   891,   269,  1501,  1502,   270,   271,   475,
     272,   544,   768,   981,  1196,   273,   274,   275,   276,   277,
     408,   409,   410,   411,   704,   705,  1172,  1053,   278,   279,
     565,   280,   281,   282,   575,   473,   913,   914,   283,   576,
     284,   578,   285,   286,   287,   582,   583,  1117,   794,   288,
     715,   772,   716,   701,  1118,  1119,  1120,   773,   579,   580,
     996,   997,  1371,   581,   993,   994,  1211,  1212,  1213,  1214,
     289,   726,   727,   290,  1148,  1149,  1150,   291,  1152,  1153,
     292,   293,   294,   295,   802,   296,  1241,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   602,
     603,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   322,   323,   324,   325,   326,   629,
     630,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     830,   336,   337,   338,  1174,   746,   747,   748,  1519,  1554,
    1555,  1548,  1549,  1556,  1550,  1175,  1176,   339,   340,  1177,
     341,   342,   343,   344,   345,   346,   347,  1039,   795,  1003,
    1226,  1004,  1376,  1005,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   733,  1105,   358,   359,   360,   361,
    1007,  1008,  1009,  1010,   362,   363,   364,   365,   366,   367,
     765,   766,   368,  1202,  1203,  1359,  1130,   484,   369,  1027,
    1251,  1252,  1028,  1029,  1030,  1031,  1032,  1261,  1406,  1407,
    1033,  1264,  1034,  1387,  1035,  1036,  1269,  1270,  1412,  1410,
    1253,  1254,  1255,  1256,  1485,   671,   879,   880,   881,   882,
     883,   884,  1083,  1426,  1427,  1084,  1425,  1497,   885,  1286,
    1422,  1418,  1419,  1420,   886,   887,  1257,  1265,  1397,  1258,
    1393,  1242,   370,   371
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       468,   809,   959,   810,   811,   812,   813,  1006,  1040,  1040,
     624,   781,  1025,   518,  1026,  1134,   485,   639,   529,  1293,
    1037,  1038,  1173,   779,   522,  1100,  1367,  1368,   551,  1358,
     508,   554,  1237,   929,  1467,  1428,  1006,  1006,  1504,   868,
     910,     5,   869,   798,   793,   799,   800,   789,   801,   836,
     803,   502,   509,  1408,  1058,   789,  1086,   790,   804,   805,
     531,   930,  1087,   687,  1166,  1167,   513,   687,   977,   750,
     889,  1006,   941,  1546,  1517,  1138,  1347,  1166,   790,  1330,
    1088,   938,  1478,   688,   563,   870,  1200,   688,   519,   938,
    1015,  1089,   638,   928,   902,   563,   904,   563,   960,  1164,
     485,  1197,   524,  1416,   917,   789,   791,  1093,   527,  1016,
     950,  1020,   952,  1044,  1044,  1099,   964,  1090,  1123,  1394,
     702,   650,   710,   714,    75,  1047,   477,  1018,   644,   638,
    1166,  1167,  1389,  1450,  1006,  1080,  1147,    86,  1233,  1113,
    1391,  1113,  1048,   645,  1505,  1243,  1114,  1392,  1114,  1328,
     985,  1081,  1168,   651,   966,   478,   940,  1275,  1479,  1490,
     939,  1518,   100,  1331,   961,  1165,  1022,  1417,   956,  1023,
    1390,  1169,   903,  1170,   905,   965,   970,   564,   711,   989,
    1469,  1243,   918,  1198,  1169,   790,  1170,   703,   951,   119,
     953,  1045,  1046,  1082,  1547,   978,   415,  1166,  1167,  1451,
     911,   706,  1221,  1061,   625,   105,   125,   792,   689,  1166,
    1167,   890,   986,  1163,   706,  1498,  1244,   792,  1168,  1006,
    1433,   117,  1318,  1289,   712,   792,  1173,  1506,   751,  1025,
    1025,  1026,  1026,   792,  1473,  1173,   871,  1169,   912,  1170,
    1054,  1055,  1171,  1091,   532,  1347,  1139,  1535,  1386,   872,
    1494,   873,  1244,  1111,   792,  1019,   890,  1590,  1021,  1122,
     144,   709,   874,   875,   876,   792,   877,   706,   878,   584,
     614,   105,  1283,  1024,  1603,   412,   967,   968,  1395,  1396,
     631,  1581,  1609,   633,   615,  1168,  1598,   117,  1284,  1283,
       5,   969,  1223,  1052,  1525,   664,  1465,  1168,   971,   972,
    1245,  1246,   509,  1247,  1169,   509,  1170,   865,  1342,  1208,
    1248,  1546,  1474,   973,   605,  1166,  1169,  1093,  1170,   683,
    1249,   789,   684,  1224,   686,   493,   144,  1314,  1495,  1210,
    1285,   606,  1250,   608,   706,  1234,  1245,  1246,   105,  1247,
     623,  1225,   775,  1006,   416,   659,   706,  1285,   660,  1466,
     105,   853,  1503,  1333,   117,   692,  1249,  1151,   925,  1582,
     647,   609,   649,   119,  1599,  1166,   117,   655,  1250,  1006,
    1334,   485,  1110,    75,   610,  1346,  1552,   672,   474,   605,
    1583,   661,   494,   566,   674,   708,    86,  1455,   469,   567,
     722,   719,   854,   144,   568,   485,   606,   855,   729,   636,
     731,   732,   569,   735,  1173,   144,   476,   662,   611,   738,
     637,   100,   480,  1239,   570,  1022,  1113,  1166,  1023,   607,
     640,  1375,  1169,  1114,  1170,   479,  1482,  1432,  1552,   749,
     695,  1503,  1575,  1483,   641,   377,   119,  1006,   119,   754,
    1104,  1115,  1107,  1484,   470,  1025,   605,  1026,   779,   471,
     495,   496,   706,   381,  1025,   382,  1026,  1051,   771,  1503,
     790,   486,   717,   606,   383,  1025,   485,  1026,   663,   724,
     725,   728,  1169,  1052,  1170,  1207,   734,  1551,  1557,   557,
     487,  1116,  1482,  1553,   741,  1208,  1531,  1274,  1158,  1483,
    1159,  1266,  1267,   540,   472,  1209,   558,   728,   541,  1484,
     626,   627,   706,   543,   697,  1210,   605,  1064,  1065,  1551,
     571,  1049,  1068,   572,  1268,  1557,   824,   825,  1600,   534,
    1601,   535,  1276,   606,  1169,   767,  1170,   573,  1050,  1080,
    1511,   488,   823,   774,   642,  1578,  1614,   826,  1277,  1074,
    1076,  1102,  1056,   612,   860,  1081,  1097,   491,   643,   861,
    1075,  1077,   613,   574,   706,  1098,  1056,   840,   841,   842,
     843,   844,   845,   846,   847,   848,   849,   668,   669,   757,
     758,   854,   760,   761,   762,   763,   855,  1066,  1067,  1069,
    1070,  1071,   769,   770,   827,  1072,   632,   827,   492,   413,
     827,   635,   414,   489,   677,   678,   490,  1453,   780,  1094,
    1095,  1456,   665,   666,   667,   907,  1364,  1365,   786,   787,
    1025,   537,  1026,   538,   497,   919,   921,   498,   628,   924,
     634,  1179,  1184,  1180,  1185,   646,   510,   648,   511,   389,
     587,   512,   935,   807,   808,   838,   514,   839,   588,   589,
     859,   590,  1491,  1492,  1401,   947,   948,   816,   817,   591,
     515,   955,   516,   592,   520,   593,   814,   815,   521,   525,
     594,   390,   893,   894,   895,   526,   528,   530,   533,   829,
     539,   536,   829,  1526,   542,  1527,   595,   982,   543,   545,
     546,   550,   547,   909,   553,   915,   549,   548,     1,  1006,
     392,  1006,   485,   561,   585,   485,   586,   562,   604,   616,
     596,   597,   598,   599,   600,   601,   618,   617,   619,   638,
    1520,   628,   652,  1523,   377,  1544,   654,   656,   657,   670,
     673,   675,   676,  1414,   624,  1566,   679,   685,   957,   696,
    1562,  1006,   698,   700,   706,   699,   718,   723,   730,   736,
     737,   742,   744,   745,   752,   414,  1006,   447,   680,   395,
     396,   397,   398,   483,   399,   400,   681,   402,   403,   490,
     753,   755,   501,   404,   756,   990,   759,   778,   782,   764,
     784,   785,  1011,  1316,   806,   783,   818,  1559,   788,   819,
     820,   821,   831,  1477,   837,   862,   834,   835,   863,  1480,
    1481,   867,   866,   888,   892,   896,   897,   899,   898,   901,
     916,  1011,  1011,  1011,  1011,   900,   908,   920,   922,   923,
     926,   927,   931,   932,   937,   942,   933,   936,   974,   992,
     943,   944,   945,   946,   949,   962,  1013,   963,   979,   975,
     984,   983,   991,   976,   995,   998,  1011,  1012,  1014,  1017,
     987,  1042,   855,  1057,  1043,   789,  1078,  1062,  1079,  1096,
    1101,  1103,  1073,  1363,  1154,  1125,  1109,   702,  1126,  1128,
    1132,  1133,  1131,  1135,  1112,  1137,  1140,  1143,  1127,  1147,
    1141,  1146,  1529,  1530,  1151,  1162,  1155,  1156,  1157,  1160,
    1178,  1192,  1199,  1201,  1204,  1106,  1205,  1106,   661,  1215,
    1060,  1217,  1230,  1219,  1235,  1220,  1063,  1222,  1240,  1011,
    1260,  1271,  1259,     5,  1263,  1281,  1282,  1287,  1294,  1291,
    1298,   890,  1301,  1303,  1308,  1292,  1297,  1295,  1302,  1304,
    1309,  1305,  1307,  1313,  1317,  1563,  1322,  1344,  1339,  1336,
    1341,  1236,  1353,   734,  1356,   734,  1340,  1355,  1208,  1349,
    1350,  1348,  1351,  1370,  1377,  1411,  1378,  1352,  1388,  1382,
    1404,  1379,  1385,  1384,  1409,  1413,  1415,  1421,  1080,  1429,
    1434,  1273,  1442,  1136,  1440,  1441,  1471,  1445,  1398,  1444,
    1449,  1452,  1142,  1405,  1144,  1145,  1468,  1472,  1216,  1476,
    1488,   584,  1496,  1499,  1011,  1500,  1509,  1508,  1431,  1513,
    1522,  1161,  1524,  1528,  1533,  1227,  1536,  1228,  1537,  1539,
    1543,  1424,  1181,  1182,  1183,  1540,  1186,  1187,  1188,  1189,
    1190,  1191,  1300,  1193,  1194,  1470,  1558,  1545,  1560,  1534,
    1564,  1489,  1569,  1577,  1570,  1574,   992,  1572,  1587,  1580,
    1589,  1507,  1604,  1602,  1607,  1052,  1610,  1611,   776,   777,
     555,   864,  1059,  1296,  1542,   658,   552,  1565,  1279,  1324,
    1229,  1357,  1231,  1232,   556,  1591,  1124,  1121,   559,  1218,
    1567,  1585,   707,   560,  1319,  1438,  1338,  1606,   682,  1312,
     653,  1362,  1372,  1206,  1369,  1366,   743,  1592,  1325,  1272,
     577,  1595,  1329,  1597,  1335,  1613,   796,   833,   958,  1343,
     797,  1576,  1579,  1041,  1108,  1290,  1354,  1280,  1278,  1311,
    1360,  1399,  1403,  1238,  1487,  1486,  1262,  1085,  1011,  1402,
    1423,  1400,  1493,  1288,     0,   690,     0,     0,   717,     0,
       0,   622,     0,     0,     0,     0,   728,     0,     0,     0,
       0,     0,     0,     0,  1011,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1306,     0,     0,     0,     0,
    1310,     0,     0,     0,  1345,     0,     0,     0,     0,     0,
       0,     0,  1315,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1320,  1321,     0,   767,     0,     0,     0,     0,
       0,  1326,  1327,     0,   509,     0,     0,     0,   774,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1011,     0,     0,     0,     0,     0,     0,     0,
     372,   373,     0,   374,   375,     0,   376,     0,     0,     0,
       0,     0,   377,     0,     0,     0,     0,     0,     0,     0,
     378,     0,   379,   380,   691,     0,     0,     0,     0,  1361,
     381,     0,   382,     0,     0,     0,     0,     0,     0,     0,
     992,   383,     0,     0,     0,   384,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1380,     0,     0,  1381,     0,
    1383,     0,     0,     0,     0,     0,     0,  1430,     0,     0,
       0,     0,     0,     0,     0,     0,   385,   386,   387,     0,
       0,  1436,  1437,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1448,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1454,     0,     0,     0,  1457,
       0,     0,     0,     0,   388,     0,     0,     0,     0,     0,
       0,     0,  1435,   389,     0,     0,     0,     0,  1439,     0,
       0,     0,     0,     0,     0,     0,     0,  1443,     0,     0,
       0,     0,     0,     0,     0,  1446,  1447,     0,     0,     0,
       0,     0,     0,     0,     0,   390,     0,     0,     0,     0,
       0,     0,     0,     0,  1458,  1459,  1460,  1461,  1462,     0,
    1463,  1464,     0,     0,   391,     0,     0,  1532,     0,     0,
       0,     0,     0,     0,   392,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1475,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1515,     0,     0,   393,     0,  1521,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   509,
       0,     0,     0,     0,  1011,     0,  1011,     0,     0,     0,
       0,     0,   394,   395,   396,   397,   398,     0,   399,   400,
     401,   402,   403,     0,     0,  1510,     0,   404,   405,     0,
    1512,     0,     0,     0,  1514,     0,  1516,  1538,     0,     0,
    1541,     0,     0,     0,     0,     0,  1011,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1561,     0,     0,
       0,  1011,     0,     0,     0,     0,     0,     0,     0,     0,
    1011,     0,  1568,     0,     0,     0,  1571,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1586,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1593,     0,  1594,     0,     0,     0,     0,     0,     0,     0,
    1573,     0,     0,     1,     0,  1605,     0,     0,     0,  1608,
       2,     0,     0,     0,  1612,     0,     0,     3,     4,     0,
       5,     0,  1584,     0,     0,     6,     7,  1588,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,  1596,    27,    28,
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
       0,   120,   121,   122,     0,     0,     0,   123,     0,   124,
     125,   126,     0,   127,   128,   129,     0,   130,     0,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
       0,     0,   142,   143,   144,     0,   145,   146,     0,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,     0,   189,   190,   191,     0,   192,   193,   194,   195,
     196,   197,     0,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,     1,     0,     0,     0,     0,     0,
       0,     2,     0,     0,     0,     0,     0,     0,     3,     4,
       0,     5,     0,     0,     0,     0,     6,     7,     0,     8,
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
       0,   123,   517,   124,   125,   126,     0,   127,   128,   129,
       0,   130,     0,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,     0,     0,   142,   143,   144,     0,
     454,   146,     0,   147,   148,   149,   150,   151,   152,   153,
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
     122,     0,   822,     0,   123,     0,   124,   125,   126,     0,
     127,   128,   129,     0,   130,     0,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,     0,     0,   142,
     143,   144,     0,   454,   146,     0,   147,   148,   149,   150,
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
       0,   120,   121,   122,     0,     0,     0,   123,   828,   124,
     125,   126,     0,   127,   128,   129,     0,   130,     0,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
       0,     0,   142,   143,   144,     0,   454,   146,     0,   147,
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
     118,   119,     0,     0,   120,   121,   122,     0,     0,     0,
     123,   832,   124,   125,   126,     0,   127,   128,   129,     0,
     130,     0,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,     0,     0,   142,   143,   144,     0,   454,
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
       0,   906,     0,   123,     0,   124,   125,   126,     0,   127,
     128,   129,     0,   130,     0,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,     0,     0,   142,   143,
     144,     0,   454,   146,     0,   147,   148,   149,   150,   151,
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
     120,   121,   122,     0,   934,     0,   123,     0,   124,   125,
     126,     0,   127,   128,   129,     0,   130,     0,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,     0,
       0,   142,   143,   144,     0,   454,   146,     0,   147,   148,
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
     119,     0,     0,   120,   121,   122,     0,   954,     0,   123,
       0,   124,   125,   126,     0,   127,   128,   129,     0,   130,
       0,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,     0,     0,   142,   143,   144,     0,   454,   146,
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
    1299,     0,   123,     0,   124,   125,   126,     0,   127,   128,
     129,     0,   130,     0,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,     0,     0,   142,   143,   144,
       0,   454,   146,     0,   147,   148,   149,   150,   151,   152,
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
     121,   122,     0,  1323,     0,   123,     0,   124,   125,   126,
       0,   127,   128,   129,     0,   130,     0,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,     0,     0,
     142,   143,   144,     0,   454,   146,     0,   147,   148,   149,
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
       0,     0,   120,   121,   122,     0,  1337,     0,   123,     0,
     124,   125,   126,     0,   127,   128,   129,     0,   130,     0,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,     0,     0,   142,   143,   144,     0,   454,   146,     0,
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
       0,     3,     4,     0,     5,     0,     0,     0,     0,     6,
       7,     0,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
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
       0,   123,     0,   124,   125,   126,     0,   127,   128,   129,
       0,   130,     0,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,     0,     0,   142,   143,   144,     0,
     454,   146,     0,   147,   148,   149,   150,   151,   152,   153,
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
     122,     0,     0,     0,   123,     0,   124,   125,   126,     0,
     127,   128,   129,     0,   130,     0,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,     0,     0,   142,
     143,   144,     0,   454,   146,     0,   147,   148,   149,   150,
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
       5,     0,     0,     0,     0,   980,   418,     0,     8,     9,
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
       0,   120,   121,   122,     0,     0,     0,   123,     0,   124,
     125,   126,     0,   127,   128,   129,     0,   130,     0,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
       0,     0,   142,   143,   144,     0,   454,   146,     0,   147,
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
      17,   423,   424,    20,   426,   427,    23,   428,    25,    26,
       0,    27,    28,    29,    30,   429,    32,    33,    34,    35,
      36,    37,   432,    39,    40,   433,     0,    42,    43,    44,
       0,   435,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
       0,    65,    66,    67,    68,    69,    70,    71,    72,     0,
       0,    73,    74,     0,     0,     0,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,     0,     0,    86,
       0,    87,    88,    89,    90,     0,    91,     0,     0,     0,
     443,    93,    94,    95,    96,     0,     0,     0,     0,     0,
       0,    97,    98,    99,   100,   101,   102,   103,     0,     0,
       0,   104,   105,   620,   107,   108,     0,     0,     0,     0,
     109,   110,   111,   112,   113,   114,   115,   116,   117,     0,
     621,   119,     0,     0,   120,   121,   122,     0,     0,     0,
     123,     0,   124,   125,   126,     0,   127,   128,   129,     0,
     130,     0,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,     0,     0,   142,   143,   144,     0,   454,
     146,     0,   147,   148,   149,   150,   151,   152,   153,   455,
     155,   457,   157,   458,   459,   160,   161,   162,   163,   164,
     165,   460,   167,   461,   462,   463,   464,   172,   173,   465,
     466,   176,   467,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,     0,   189,   190,   191,     0,   192,
     193,   194,   195,   196,   197,     0,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,     2,     0,     0,     0,
       0,     0,     0,     3,     4,     0,     5,     0,     0,     0,
       0,   417,   418,     0,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,   423,   424,    20,   426,   427,    23,
     428,    25,    26,     0,    27,    28,    29,    30,   429,    32,
      33,    34,    35,    36,    37,   432,    39,    40,   433,     0,
      42,    43,    44,     0,   435,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,     0,    65,    66,    67,    68,    69,    70,
      71,    72,     0,     0,    73,    74,     0,     0,     0,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
       0,     0,    86,     0,    87,    88,    89,    90,     0,    91,
       0,     0,     0,   443,    93,    94,    95,    96,     0,     0,
       0,     0,     0,     0,    97,    98,    99,   100,   101,   102,
     103,     0,     0,     0,   104,   105,   106,   107,   108,     0,
       0,     0,     0,   109,   110,   111,   112,   113,   114,   115,
     116,   117,     0,   118,   119,     0,     0,   120,   121,   122,
       0,     0,     0,   123,     0,   124,   125,   126,     0,   127,
     128,   129,     0,   130,     0,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,     0,     0,   142,   143,
     144,     0,   454,   146,     0,   147,   148,   149,   150,   151,
     152,   153,   455,   155,   457,   157,   458,   459,   160,   161,
     162,   163,   164,   165,   460,   167,   461,   462,   463,   464,
     172,   173,   465,   466,   176,   467,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,     0,   189,   190,
     191,     0,   192,   193,   194,   195,   196,   197,     0,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,     2,
       0,     0,     0,     0,     0,     0,     3,     4,     0,     5,
       0,     0,     0,     0,   417,   418,     0,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,   423,   424,    20,
     426,   427,    23,   428,    25,    26,     0,    27,    28,    29,
      30,   429,    32,    33,    34,    35,    36,    37,   432,    39,
      40,   433,     0,    42,    43,    44,     0,   435,    47,   436,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,     0,    65,    66,    67,
      68,    69,    70,    71,    72,     0,     0,    73,    74,     0,
       0,     0,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,     0,     0,    86,     0,    87,    88,    89,
      90,     0,    91,     0,     0,     0,   443,    93,    94,    95,
      96,     0,     0,     0,     0,     0,     0,    97,    98,    99,
     100,   101,   102,   103,     0,     0,     0,   104,   105,     0,
     107,   108,     0,     0,     0,     0,   109,   110,   111,   112,
     113,   114,   115,   116,   117,     0,     0,     0,     0,     0,
     120,   121,   122,     0,     0,     0,   123,     0,   124,   125,
     126,     0,   127,   128,   129,     0,   130,     0,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,     0,
       0,   142,   143,   144,     0,   454,   146,     0,   147,   148,
     149,   150,   151,   152,   153,   455,   155,   457,   157,   458,
     459,   160,   161,   162,   163,   164,   165,   460,   167,   461,
     462,   463,   464,   172,   173,   465,   466,   176,   467,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
       0,   189,   190,   191,     0,   192,   193,   194,   195,   196,
     197,     0,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,     2,     0,     0,     0,     0,     0,     0,     3,
       4,     0,     5,     0,     0,     0,     0,   417,   418,     0,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
     423,   424,    20,   426,   427,    23,   428,    25,    26,     0,
      27,    28,    29,    30,   429,    32,    33,    34,    35,    36,
      37,   432,    39,    40,   433,     0,    42,    43,    44,     0,
     435,    47,   436,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,     0,
      65,    66,    67,    68,    69,    70,    71,    72,     0,     0,
      73,    74,     0,     0,     0,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,     0,     0,    86,     0,
      87,    88,    89,    90,     0,    91,     0,     0,     0,   443,
      93,    94,    95,    96,     0,     0,     0,     0,     0,     0,
      97,    98,    99,   100,   101,   102,   103,     0,     0,     0,
     104,   105,     0,   107,   108,     0,     0,     0,     0,   109,
     110,   111,   112,   113,   114,   115,   116,   117,     0,     0,
       0,     0,     0,   120,   121,   122,     0,     0,     0,   123,
       0,   124,   125,   126,     0,     0,     0,   129,     0,   130,
       0,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,     0,     0,   142,   143,   144,     0,   454,   146,
       0,   147,   148,   149,   150,   151,   152,   153,   455,   155,
     457,   157,   458,   459,   160,   161,   162,   163,   164,   165,
     460,   167,   461,   462,   463,   464,   172,   173,   465,   466,
     176,   467,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,     0,   189,   190,   191,     0,   192,   193,
     194,   195,   196,   197,     0,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,     2,     0,     0,     0,     0,
       0,     0,     3,     4,     0,     0,     0,     0,     0,     0,
     417,   418,     0,     8,     9,   503,    11,    12,    13,    14,
     420,    16,   504,   423,   424,   425,   426,   427,    23,   428,
      25,    26,     0,    27,    28,    29,    30,   429,    32,   505,
      34,    35,    36,    37,   432,    39,    40,   433,     0,    42,
     506,    44,     0,   435,    47,   436,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,   437,
     438,    64,     0,    65,    66,    67,   507,     0,    70,    71,
      72,     0,     0,   440,    74,     0,     0,     0,     0,    76,
      77,    78,   441,   442,    81,    82,     0,     0,     0,     0,
       0,     0,     0,    87,    88,    89,    90,     0,    91,     0,
       0,     0,   443,    93,    94,   444,   445,     0,     0,     0,
       0,     0,     0,    97,    98,    99,     0,   101,   102,   103,
       0,     0,     0,     0,     0,     0,   107,   108,     0,     0,
       0,     0,   109,   110,   111,   112,   448,   114,   115,   449,
       0,     0,     0,     0,     0,     0,   450,   451,   122,     0,
       0,     0,   123,     0,   124,   125,   452,     0,     0,     0,
     129,     0,   130,     0,   131,   132,   133,   134,   453,   136,
     137,   138,   139,   140,   141,     0,     0,   142,   143,     0,
       0,   454,   146,     0,   147,   148,   149,   150,   151,   152,
     153,   455,   155,   457,   157,   458,   459,   160,   161,   162,
     163,   164,   165,   460,   167,   461,   462,   463,   464,   172,
     173,   465,   466,   176,   467,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,     0,   189,   190,   191,
       0,   192,   193,   194,   195,   196,   197,     0,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,     2,     0,
       0,     0,     0,     0,     0,     3,     4,     0,     0,     0,
       0,     0,     0,   417,   418,     0,     8,     9,   419,    11,
      12,    13,    14,   420,   421,   422,   423,   424,   425,   426,
     427,    23,   428,    25,    26,     0,    27,    28,    29,    30,
     429,    32,   430,    34,    35,   431,    37,   432,    39,    40,
     433,     0,    42,   434,    44,     0,   435,    47,   436,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,   437,   438,    64,     0,    65,    66,    67,   439,
       0,    70,    71,    72,     0,     0,   440,    74,     0,     0,
       0,     0,    76,    77,    78,   441,   442,    81,    82,     0,
       0,     0,     0,     0,     0,     0,    87,    88,    89,    90,
       0,    91,     0,     0,     0,   443,    93,    94,   444,   445,
       0,     0,     0,     0,     0,     0,    97,    98,    99,     0,
     101,   102,   103,     0,     0,     0,     0,     0,     0,   107,
     108,     0,     0,     0,     0,   109,   110,   111,   112,   448,
     114,   115,   449,     0,     0,     0,     0,     0,     0,   450,
     451,   122,     0,     0,     0,   123,     0,   124,     0,   452,
       0,     0,     0,   129,     0,   130,     0,   131,   132,   133,
     134,   453,   136,   137,   138,   139,   140,   141,     0,     0,
     142,   143,     0,     0,   454,   146,     0,   147,   148,   149,
     150,   151,   152,   153,   455,   456,   457,   157,   458,   459,
     160,   161,   162,   163,   164,   165,   460,   167,   461,   462,
     463,   464,   172,   173,   465,   466,   176,   467,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,     0,
     189,   190,   191,     0,   192,   193,   194,   195,   196,   197,
       0,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   481,     0,     0,     0,     4,     0,     0,     0,     0,
       0,     0,   417,   418,     0,     8,     9,   419,    11,    12,
      13,    14,   420,   421,   422,   423,   424,   425,   426,   427,
      23,   428,    25,    26,     0,    27,    28,    29,    30,   429,
      32,   430,    34,    35,   431,    37,   432,    39,    40,   433,
       0,    42,   434,    44,     0,   435,    47,   436,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,   437,   438,    64,     0,    65,    66,    67,   439,     0,
      70,    71,    72,     0,     0,   440,    74,     0,     0,     0,
       0,    76,    77,    78,   441,   442,    81,    82,     0,     0,
       0,     0,     0,     0,     0,    87,    88,    89,    90,     0,
      91,     0,     0,     0,   443,    93,    94,   444,   445,     0,
       0,     0,     0,     0,     0,    97,    98,    99,     0,   101,
     102,   103,   482,     0,     0,   483,     0,     0,   107,   108,
       0,     0,     0,     0,   109,   110,   111,   112,   448,   114,
     115,   449,     0,     0,     0,     0,     0,     0,   450,   451,
     122,     0,     0,     0,   123,     0,   124,     0,   452,     0,
       0,     0,     0,     0,   130,     0,   131,   132,   133,   134,
     453,   136,   137,   138,   139,   140,   141,     0,     0,   142,
     143,     0,     0,   454,   146,     0,   147,   148,   149,   150,
     151,   152,   153,   455,   456,   457,   157,   458,   459,   160,
     161,   162,   163,   164,   165,   460,   167,   461,   462,   463,
     464,   172,   173,   465,   466,   176,   467,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,     0,   189,
     190,   191,     0,   192,   193,   194,   195,   196,   197,     0,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     481,     0,     0,     0,     4,     0,   720,     0,     0,     0,
       0,   417,   418,     0,     8,     9,   419,    11,    12,    13,
      14,   420,   421,   422,   423,   424,   425,   426,   427,    23,
     428,    25,    26,     0,    27,    28,    29,    30,   429,    32,
     430,    34,    35,   431,    37,   432,    39,    40,   433,     0,
      42,   434,    44,     0,   435,    47,   436,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
     437,   438,    64,     0,    65,    66,    67,   439,     0,    70,
      71,    72,     0,     0,   440,    74,     0,     0,     0,     0,
      76,    77,    78,   441,   442,    81,    82,     0,     0,     0,
       0,     0,     0,     0,    87,    88,    89,    90,     0,    91,
       0,     0,     0,   443,    93,    94,   444,   445,     0,     0,
       0,     0,     0,     0,    97,    98,    99,     0,   101,   102,
     103,     0,     0,     0,     0,     0,     0,   107,   108,     0,
       0,     0,     0,   109,   110,   111,   112,   448,   114,   115,
     449,     0,     0,     0,     0,     0,     0,   450,   451,   122,
       0,     0,     0,   123,   721,   124,     0,   452,     0,     0,
       0,     0,     0,   130,     0,   131,   132,   133,   134,   453,
     136,   137,   138,   139,   140,   141,     0,     0,   142,   143,
       0,     0,   454,   146,     0,   147,   148,   149,   150,   151,
     152,   153,   455,   456,   457,   157,   458,   459,   160,   161,
     162,   163,   164,   165,   460,   167,   461,   462,   463,   464,
     172,   173,   465,   466,   176,   467,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,     0,   189,   190,
     191,     0,   192,   193,   194,   195,   196,   197,     0,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   481,
       0,     0,     0,     4,     0,     0,     0,     0,     0,     0,
     417,   418,     0,     8,     9,   419,    11,    12,    13,    14,
     420,   421,   422,   423,   424,   425,   426,   427,    23,   428,
      25,    26,     0,    27,    28,    29,    30,   429,    32,   430,
      34,    35,   431,    37,   432,    39,    40,   433,     0,    42,
     434,    44,     0,   435,    47,   436,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,   437,
     438,    64,     0,    65,    66,    67,   439,     0,    70,    71,
      72,     0,     0,   440,    74,     0,     0,     0,     0,    76,
      77,    78,   441,   442,    81,    82,     0,     0,     0,     0,
       0,     0,     0,    87,    88,    89,    90,     0,    91,     0,
       0,     0,   443,    93,    94,   444,   445,     0,     0,     0,
       0,     0,     0,    97,    98,    99,     0,   101,   102,   103,
       0,     0,     0,     0,     0,     0,   107,   108,     0,     0,
       0,     0,   109,   110,   111,   112,   448,   114,   115,   449,
       0,     0,     0,     0,     0,     0,   450,   451,   122,     0,
       0,     0,   123,     0,   124,     0,   452,     0,     0,     0,
       0,     0,   130,     0,   131,   132,   133,   134,   453,   136,
     137,   138,   139,   140,   141,     0,     0,   142,   143,     0,
       0,   454,   146,     0,   147,   148,   149,   150,   151,   152,
     153,   455,   456,   457,   157,   458,   459,   160,   161,   162,
     163,   164,   165,   460,   167,   461,   462,   463,   464,   172,
     173,   465,   466,   176,   467,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,     0,   189,   190,   191,
       0,   192,   193,   194,   195,   196,   197,     0,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   523,     0,
       4,     0,     0,     0,     0,     0,     0,   417,   418,     0,
       8,     9,   419,    11,    12,    13,    14,   420,   421,   422,
     423,   424,   425,   426,   427,    23,   428,    25,    26,     0,
      27,    28,    29,    30,   429,    32,   430,    34,    35,   431,
      37,   432,    39,    40,   433,     0,    42,   434,    44,     0,
     435,    47,   436,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,   437,   438,    64,     0,
      65,    66,    67,   439,     0,    70,    71,    72,     0,     0,
     440,    74,     0,     0,     0,     0,    76,    77,    78,   441,
     442,    81,    82,     0,     0,     0,     0,     0,     0,     0,
      87,    88,    89,    90,     0,    91,     0,     0,     0,   443,
      93,    94,   444,   445,     0,     0,     0,     0,     0,     0,
      97,    98,    99,     0,   101,   102,   103,     0,     0,     0,
       0,     0,     0,   107,   108,     0,     0,     0,     0,   109,
     110,   111,   112,   448,   114,   115,   449,     0,     0,     0,
       0,     0,     0,   450,   451,   122,     0,     0,     0,   123,
       0,   124,     0,   452,     0,     0,     0,     0,     0,   130,
       0,   131,   132,   133,   134,   453,   136,   137,   138,   139,
     140,   141,     0,     0,   142,   143,     0,     0,   454,   146,
       0,   147,   148,   149,   150,   151,   152,   153,   455,   456,
     457,   157,   458,   459,   160,   161,   162,   163,   164,   165,
     460,   167,   461,   462,   463,   464,   172,   173,   465,   466,
     176,   467,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,     0,   189,   190,   191,     0,   192,   193,
     194,   195,   196,   197,     0,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,     4,     0,     0,     0,     0,
       0,     0,   417,   418,     0,     8,     9,   503,    11,    12,
      13,    14,   420,    16,   504,   423,   424,   999,   426,   427,
      23,   428,    25,    26,     0,    27,    28,    29,    30,   429,
      32,   505,    34,    35,    36,    37,   432,    39,    40,   433,
       0,    42,   506,    44,     0,   435,    47,   436,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,   437,   438,    64,     0,    65,    66,    67,   507,     0,
      70,    71,    72,     0,     0,   440,    74,     0,     0,     0,
       0,    76,    77,    78,   441,   442,    81,    82,     0,     0,
       0,     0,     0,     0,     0,    87,    88,    89,    90,     0,
      91,     0,     0,     0,   443,    93,    94,   444,   445,     0,
       0,     0,     0,     0,     0,    97,    98,    99,     0,   101,
     102,  1000,     0,     0,     0,  1001,     0,     0,   107,   108,
       0,     0,     0,     0,   109,   110,   111,   112,   448,   114,
     115,   449,     0,     0,     0,     0,     0,     0,   450,   451,
     122,     0,     0,     0,   123,  1373,   124,   125,   452,     0,
       0,     0,  1374,     0,   130,     0,   131,   132,   133,   134,
     453,   136,   137,   138,   139,   140,   141,     0,     0,  1002,
     143,     0,     0,   454,   146,     0,   147,   148,   149,   150,
     151,   152,   153,   455,   155,   457,   157,   458,   459,   160,
     161,   162,   163,   164,   165,   460,   167,   461,   462,   463,
     464,   172,   173,   465,   466,   176,   467,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,     0,   189,
     190,   191,     0,   192,   193,   194,   195,   196,   197,     0,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
       4,     0,     0,     0,     0,     0,     0,   417,   418,     0,
       8,     9,   419,    11,    12,    13,    14,   420,   421,   422,
     423,   424,   425,   426,   427,    23,   428,    25,    26,     0,
      27,    28,    29,    30,   429,    32,   430,    34,    35,   431,
      37,   432,    39,    40,   433,     0,    42,   434,    44,     0,
     435,    47,   436,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,   437,   438,    64,     0,
      65,    66,    67,   439,     0,    70,    71,    72,     0,     0,
     440,    74,     0,     0,     0,     0,    76,    77,    78,   441,
     442,    81,    82,     0,     0,     0,   499,     0,     0,     0,
      87,    88,    89,    90,     0,    91,     0,     0,     0,   443,
      93,    94,   444,   445,     0,     0,     0,     0,     0,     0,
      97,    98,    99,     0,   101,   102,   103,   500,     0,     0,
     501,     0,     0,   107,   108,     0,     0,     0,     0,   109,
     110,   111,   112,   448,   114,   115,   449,     0,     0,     0,
       0,     0,     0,   450,   451,   122,     0,     0,     0,   123,
       0,   124,     0,   452,     0,     0,     0,     0,     0,   130,
       0,   131,   132,   133,   134,   453,   136,   137,   138,   139,
     140,   141,     0,     0,   142,   143,     0,     0,   454,   146,
       0,   147,   148,   149,   150,   151,   152,   153,   455,   456,
     457,   157,   458,   459,   160,   161,   162,   163,   164,   165,
     460,   167,   461,   462,   463,   464,   172,   173,   465,   466,
     176,   467,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,     0,   189,   190,   191,     0,   192,   193,
     194,   195,   196,   197,     0,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,     4,     0,     0,     0,     0,
       0,     0,   417,   418,     0,     8,     9,   503,    11,    12,
      13,    14,   420,    16,   504,   423,   424,   999,   426,   427,
      23,   428,    25,    26,     0,    27,    28,    29,    30,   429,
      32,   505,    34,    35,    36,    37,   432,    39,    40,   433,
       0,    42,   506,    44,     0,   435,    47,   436,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,   437,   438,    64,     0,    65,    66,    67,   507,     0,
      70,    71,    72,     0,     0,   440,    74,     0,     0,     0,
       0,    76,    77,    78,   441,   442,    81,    82,  1332,     0,
       0,     0,     0,     0,     0,    87,    88,    89,    90,     0,
      91,     0,     0,     0,   443,    93,    94,   444,   445,     0,
       0,     0,     0,     0,     0,    97,    98,    99,     0,   101,
     102,  1000,     0,     0,     0,  1001,     0,     0,   107,   108,
       0,     0,     0,     0,   109,   110,   111,   112,   448,   114,
     115,   449,     0,     0,     0,     0,     0,     0,   450,   451,
     122,     0,     0,     0,   123,     0,   124,   125,   452,     0,
       0,     0,     0,     0,   130,     0,   131,   132,   133,   134,
     453,   136,   137,   138,   139,   140,   141,     0,     0,  1002,
     143,     0,     0,   454,   146,     0,   147,   148,   149,   150,
     151,   152,   153,   455,   155,   457,   157,   458,   459,   160,
     161,   162,   163,   164,   165,   460,   167,   461,   462,   463,
     464,   172,   173,   465,   466,   176,   467,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,     0,   189,
     190,   191,     0,   192,   193,   194,   195,   196,   197,     0,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
       4,     0,     0,     0,     0,     0,     0,   417,   418,     0,
       8,     9,   419,    11,    12,    13,    14,   420,   421,   422,
     423,   424,   425,   426,   427,    23,   428,    25,    26,     0,
      27,    28,    29,    30,   429,    32,   430,    34,    35,   431,
      37,   432,    39,    40,   433,     0,    42,   434,    44,     0,
     435,    47,   436,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,   437,   438,    64,     0,
      65,    66,    67,   439,     0,    70,    71,    72,     0,     0,
     440,    74,     0,     0,     0,     0,    76,    77,    78,   441,
     442,    81,    82,     0,     0,     0,     0,     0,     0,     0,
      87,    88,    89,    90,     0,    91,     0,     0,     0,   443,
      93,    94,   444,   445,     0,     0,     0,     0,     0,     0,
      97,    98,    99,     0,   101,   102,   103,   446,     0,     0,
     447,     0,     0,   107,   108,     0,     0,     0,     0,   109,
     110,   111,   112,   448,   114,   115,   449,     0,     0,     0,
       0,     0,     0,   450,   451,   122,     0,     0,     0,   123,
       0,   124,     0,   452,     0,     0,     0,     0,     0,   130,
       0,   131,   132,   133,   134,   453,   136,   137,   138,   139,
     140,   141,     0,     0,   142,   143,     0,     0,   454,   146,
       0,   147,   148,   149,   150,   151,   152,   153,   455,   456,
     457,   157,   458,   459,   160,   161,   162,   163,   164,   165,
     460,   167,   461,   462,   463,   464,   172,   173,   465,   466,
     176,   467,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,     0,   189,   190,   191,     0,   192,   193,
     194,   195,   196,   197,     0,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,     4,     0,     0,     0,     0,
       0,     0,   417,   418,     0,     8,     9,   419,    11,    12,
      13,    14,   420,   421,   422,   423,   424,   425,   426,   427,
      23,   428,    25,    26,     0,    27,    28,    29,    30,   429,
      32,   430,    34,    35,   431,    37,   432,    39,    40,   433,
       0,    42,   434,    44,     0,   435,    47,   436,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,   437,   438,    64,     0,    65,    66,    67,   439,     0,
      70,    71,    72,     0,     0,   440,    74,     0,     0,     0,
       0,    76,    77,    78,   441,   442,    81,    82,     0,     0,
       0,     0,     0,     0,     0,    87,    88,    89,    90,     0,
      91,     0,     0,     0,   443,    93,    94,   444,   445,     0,
       0,     0,     0,     0,     0,    97,    98,    99,     0,   101,
     102,   103,     0,     0,     0,     0,     0,     0,   107,   108,
       0,     0,     0,     0,   109,   110,   111,   112,   448,   114,
     115,   449,     0,     0,     0,     0,     0,     0,   450,   451,
     122,     0,     0,     0,   123,   693,   124,     0,   452,     0,
       0,     0,   694,     0,   130,     0,   131,   132,   133,   134,
     453,   136,   137,   138,   139,   140,   141,     0,     0,   142,
     143,     0,     0,   454,   146,     0,   147,   148,   149,   150,
     151,   152,   153,   455,   456,   457,   157,   458,   459,   160,
     161,   162,   163,   164,   165,   460,   167,   461,   462,   463,
     464,   172,   173,   465,   466,   176,   467,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,     0,   189,
     190,   191,     0,   192,   193,   194,   195,   196,   197,     0,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
       4,     0,     0,     0,     0,     0,     0,   417,   418,     0,
       8,     9,   419,    11,    12,    13,    14,   420,   421,   422,
     423,   424,   425,   426,   427,    23,   428,    25,    26,     0,
      27,    28,    29,    30,   429,    32,   430,    34,    35,   431,
      37,   432,    39,    40,   433,     0,    42,   434,    44,     0,
     435,    47,   436,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,   437,   438,    64,     0,
      65,    66,    67,   439,     0,    70,    71,    72,     0,     0,
     440,    74,     0,     0,     0,     0,    76,    77,    78,   441,
     442,    81,    82,     0,     0,     0,     0,     0,     0,     0,
      87,    88,    89,    90,     0,    91,     0,     0,     0,   443,
      93,    94,   444,   445,     0,     0,     0,     0,     0,     0,
      97,    98,    99,     0,   101,   102,   103,     0,     0,     0,
       0,     0,     0,   107,   108,     0,     0,     0,     0,   109,
     110,   111,   112,   448,   114,   115,   449,     0,     0,     0,
       0,     0,     0,   450,   451,   122,     0,     0,     0,   123,
     739,   124,     0,   452,     0,     0,     0,   740,     0,   130,
       0,   131,   132,   133,   134,   453,   136,   137,   138,   139,
     140,   141,     0,     0,   142,   143,     0,     0,   454,   146,
       0,   147,   148,   149,   150,   151,   152,   153,   455,   456,
     457,   157,   458,   459,   160,   161,   162,   163,   164,   165,
     460,   167,   461,   462,   463,   464,   172,   173,   465,   466,
     176,   467,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,     0,   189,   190,   191,     0,   192,   193,
     194,   195,   196,   197,     0,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,     4,     0,     0,     0,     0,
       0,     0,   417,   418,     0,     8,     9,   503,    11,    12,
      13,    14,   420,    16,   504,   423,   424,   999,   426,   427,
      23,   428,    25,    26,     0,    27,    28,    29,    30,   429,
      32,   505,    34,    35,    36,    37,   432,    39,    40,   433,
       0,    42,   506,    44,     0,   435,    47,   436,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,   437,   438,    64,     0,    65,    66,    67,   507,     0,
      70,    71,    72,     0,     0,   440,    74,     0,     0,     0,
       0,    76,    77,    78,   441,   442,    81,    82,     0,     0,
       0,     0,     0,     0,     0,    87,    88,    89,    90,     0,
      91,     0,     0,     0,   443,    93,    94,   444,   445,     0,
       0,     0,     0,     0,     0,    97,    98,    99,     0,   101,
     102,  1000,     0,     0,     0,  1001,     0,     0,   107,   108,
       0,     0,     0,     0,   109,   110,   111,   112,   448,   114,
     115,   449,     0,     0,     0,     0,     0,     0,   450,   451,
     122,     0,     0,     0,   123,     0,   124,   125,   452,     0,
       0,     0,     0,     0,   130,     0,   131,   132,   133,   134,
     453,   136,   137,   138,   139,   140,   141,     0,     0,  1002,
     143,     0,     0,   454,   146,     0,   147,   148,   149,   150,
     151,   152,   153,   455,   155,   457,   157,   458,   459,   160,
     161,   162,   163,   164,   165,   460,   167,   461,   462,   463,
     464,   172,   173,   465,   466,   176,   467,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,     0,   189,
     190,   191,     0,   192,   193,   194,   195,   196,   197,     0,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
       4,     0,     0,     0,     0,     0,     0,   417,   418,     0,
       8,     9,   503,    11,    12,    13,    14,   420,    16,   504,
     423,   424,   999,   426,   427,    23,   428,    25,    26,     0,
      27,    28,    29,    30,   429,    32,   505,    34,    35,    36,
      37,   432,    39,    40,   433,     0,    42,   506,    44,     0,
     435,    47,   436,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,   437,   438,    64,     0,
      65,    66,    67,   507,     0,    70,    71,    72,     0,     0,
     440,    74,     0,     0,     0,     0,    76,    77,    78,   441,
     442,    81,    82,     0,     0,     0,     0,     0,     0,     0,
      87,    88,    89,    90,     0,    91,     0,     0,     0,   443,
      93,    94,   444,   445,     0,     0,     0,     0,     0,     0,
      97,    98,    99,     0,   101,   102,  1000,     0,     0,     0,
    1001,     0,     0,   107,   108,     0,     0,     0,     0,   109,
     110,   111,   112,   448,   114,   115,   449,     0,     0,     0,
       0,     0,     0,   450,   451,   122,     0,     0,     0,   123,
       0,   124,   125,   452,     0,     0,     0,     0,     0,   130,
       0,   131,   132,   133,   134,   453,   136,   137,   138,   139,
     140,   141,     0,     0,   142,   143,     0,     0,   454,   146,
       0,   147,   148,   149,   150,   151,   152,   153,   455,   155,
     457,   157,   458,   459,   160,   161,   162,   163,   164,   165,
     460,   167,   461,   462,   463,   464,   172,   173,   465,   466,
     176,   467,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,     0,   189,   190,   191,     0,   192,   193,
     194,   195,   196,   197,     0,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,     4,     0,     0,     0,     0,
       0,     0,   417,   418,     0,     8,     9,   419,    11,    12,
      13,    14,   420,   421,   422,   423,   424,   425,   426,   427,
      23,   428,    25,    26,     0,    27,    28,    29,    30,   429,
      32,   430,    34,    35,   431,    37,   432,    39,    40,   433,
       0,    42,   434,    44,     0,   435,    47,   436,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,   437,   438,    64,     0,    65,    66,    67,   439,     0,
      70,    71,    72,     0,     0,   440,    74,     0,     0,     0,
       0,    76,    77,    78,   441,   442,    81,    82,     0,     0,
       0,     0,     0,     0,     0,    87,    88,    89,    90,     0,
      91,     0,     0,     0,   443,    93,    94,   444,   445,     0,
       0,     0,     0,     0,     0,    97,    98,    99,     0,   101,
     102,   103,     0,     0,     0,     0,     0,     0,   107,   108,
       0,     0,     0,     0,   109,   110,   111,   112,   448,   114,
     115,   449,     0,     0,     0,     0,     0,     0,   450,   451,
     122,     0,     0,     0,   123,     0,   124,     0,   452,     0,
       0,     0,     0,     0,   130,     0,   131,   132,   133,   134,
     453,   136,   137,   138,   139,   140,   141,     0,     0,   142,
     143,     0,     0,   454,   146,     0,   147,   148,   149,   150,
     151,   152,   153,   455,   456,   457,   157,   458,   459,   160,
     161,   162,   163,   164,   165,   460,   167,   461,   462,   463,
     464,   172,   173,   465,   466,   176,   467,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,     0,   189,
     190,   191,     0,   192,   193,   194,   195,   196,   197,     0,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     376,     0,     0,     0,     0,     0,   377,     0,     0,     0,
       0,     0,     0,     0,   378,     0,   379,     0,     0,     0,
       0,     0,     0,     0,   381,     0,   382,     0,     0,     0,
       0,     0,     0,     0,     0,   383,     0,     0,     0,   384,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     385,   386,   988,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   389,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   390,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   392,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     393,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   394,   395,   396,   397,
     398,     0,   399,   400,   401,   402,   403,     0,     0,     0,
       0,   404,   405
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
        17,   607,   746,   608,   609,   610,   611,   789,   820,   821,
     311,   565,   806,   104,   806,   926,    33,   372,   128,  1096,
     818,   819,   961,   562,   117,   894,  1212,  1213,   238,  1201,
      69,   241,  1023,   717,  1359,  1288,   818,   819,   111,    47,
      49,    20,    50,   587,   584,   589,   590,    88,   592,   647,
     594,    68,    69,  1263,   853,    88,    30,    90,   602,   603,
      21,   717,    36,    37,     8,     9,    83,    37,   100,     7,
      88,   853,   728,     4,    87,   134,  1174,     8,    90,    93,
      54,   100,    45,    57,   100,    93,   983,    57,   105,   100,
     139,    65,    20,   134,   100,   100,   100,   100,   122,   122,
     117,   100,   119,   128,   100,    88,   139,   889,   125,   793,
     100,   795,   100,   100,   100,    88,   123,    91,   916,    90,
     111,   161,   477,   478,   103,   140,    26,   139,   158,    20,
       8,     9,   209,   111,   916,    90,    93,   116,   139,    46,
     261,    46,   157,   173,   217,    90,    53,   268,    53,   106,
      38,   106,    96,   193,    88,    55,   139,  1054,   121,   175,
     179,   174,   141,   177,   188,   188,   145,   192,   179,   148,
     247,   115,   178,   117,   178,   182,    88,   182,   106,   182,
    1366,    90,   178,   182,   115,    90,   117,   178,   178,   168,
     178,   178,   178,   148,   125,   227,   145,     8,     9,   177,
     209,   145,  1001,   859,   314,   149,   180,   266,   178,     8,
       9,   229,   100,   957,   145,  1425,   161,   266,    96,  1001,
    1297,   165,  1133,  1092,   152,   266,  1165,   300,   166,  1023,
    1024,  1023,  1024,   266,   100,  1174,   244,   115,   247,   117,
     838,   839,   186,   217,   205,  1343,   930,  1500,  1239,   257,
     100,   259,   161,   909,   266,   795,   229,  1582,   802,   915,
     204,   152,   270,   271,   272,   266,   274,   145,   276,   286,
     128,   149,    90,   252,  1599,   152,   210,   211,   249,   250,
     319,   100,  1607,   322,   142,    96,   100,   165,   106,    90,
      20,   225,   136,   145,  1466,   388,   148,    96,   210,   211,
     245,   246,   319,   248,   115,   322,   117,   662,   186,    99,
     255,     4,   178,   225,   150,     8,   115,  1099,   117,   412,
     265,    88,   413,   167,   415,    88,   204,  1125,   178,   119,
     148,   167,   277,   110,   145,  1019,   245,   246,   149,   248,
     145,   185,   552,  1125,   148,    37,   145,   148,    40,   201,
     149,    88,  1429,  1151,   165,   446,   265,    93,   713,   178,
     377,   138,   379,   168,   178,     8,   165,   384,   277,  1151,
     106,   388,   139,   103,   151,   186,    19,   394,   148,   150,
    1566,    73,   145,    33,   401,   476,   116,   186,   145,    39,
     483,   482,   129,   204,    44,   412,   167,   134,   489,   137,
     491,   492,    52,   494,  1343,   204,   148,    99,   185,   500,
     148,   141,    39,   145,    64,   145,    46,     8,   148,   190,
     173,  1219,   115,    53,   117,   111,   262,  1296,    19,   520,
     447,  1508,   125,   269,   187,    40,   168,  1219,   168,   530,
     902,    71,   904,   279,    61,  1239,   150,  1239,   987,    66,
     213,   214,   145,    58,  1248,    60,  1248,   129,   549,  1536,
      90,   148,   479,   167,    69,  1259,   483,  1259,   160,   486,
     487,   488,   115,   145,   117,    89,   493,  1517,  1518,    25,
     111,   111,   262,   126,   501,    99,   190,   129,   950,   269,
     952,   240,   241,   217,   111,   109,    42,   514,   222,   279,
     183,   184,   145,   145,   469,   119,   150,   862,   863,  1549,
     160,   140,   867,   163,   263,  1555,   626,   627,  1595,   217,
    1597,   219,   129,   167,   115,   542,   117,   177,   157,    90,
    1441,   111,   623,   550,   173,   126,  1613,   628,   145,   256,
     256,   896,   850,   192,   129,   106,   292,   148,   187,   134,
     267,   267,   201,   203,   145,   301,   864,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,   293,   294,   534,
     535,   129,   537,   538,   539,   540,   134,   120,   121,   270,
     271,   272,   547,   548,   629,   276,   321,   632,   148,   145,
     635,   326,   148,   145,   293,   294,   148,  1341,   563,   284,
     285,  1345,   213,   214,   215,   696,   120,   121,   573,   574,
    1404,   217,  1404,   219,   114,   706,   709,   114,   146,   712,
     148,   224,   224,   226,   226,   376,   114,   378,   114,   161,
     124,   114,   723,   605,   606,   652,   111,   654,   132,   133,
     657,   135,  1416,  1417,  1250,   736,   737,   614,   615,   143,
     114,   742,   114,   147,   145,   149,   612,   613,   114,   114,
     154,   193,   679,   680,   681,   114,   114,   145,   207,   634,
     217,   148,   637,  1471,   111,  1473,   170,   768,   145,   234,
     234,   111,   235,   700,     0,   702,   145,   148,     3,  1471,
     222,  1473,   709,   182,   159,   712,    86,   182,   242,    43,
     194,   195,   196,   197,   198,   199,    94,   191,    95,    20,
    1454,   146,    40,  1457,    40,  1513,    40,   144,   111,   239,
     286,   291,   291,  1277,  1025,  1537,   297,   178,   745,   145,
    1528,  1513,   277,   111,   145,   277,   111,   145,   178,   145,
     145,   145,   178,    27,    15,   148,  1528,   148,   280,   281,
     282,   283,   284,   148,   286,   287,   288,   289,   290,   148,
     178,   205,   148,   295,    20,   782,   178,    25,   111,   223,
     162,   162,   789,  1128,    65,   160,   223,  1521,   100,    88,
      88,    88,   141,  1388,    20,   152,   100,   100,   152,  1395,
    1396,   124,   119,   239,   292,   124,   175,   178,   175,   175,
      88,   818,   819,   820,   821,   178,   175,   178,    90,    37,
      90,   100,   175,   178,   134,   175,   178,   178,    88,   784,
     178,   178,   145,   175,   175,   175,   791,   175,   134,   229,
     175,   178,   162,   217,   111,   111,   853,   111,   111,   139,
     182,   175,   134,   124,   176,    88,    20,   134,   279,   219,
     292,   145,   869,  1208,   945,    88,   175,   111,   175,   124,
     124,    90,   152,   111,   247,   134,   145,   111,   189,    93,
     175,   139,  1478,  1479,    93,    27,   175,   175,   145,   175,
      20,   111,   175,   238,   145,   902,   111,   904,    73,   100,
     855,   100,   139,   148,   139,   148,   861,   148,   278,   916,
     253,   136,   251,    20,   260,   279,    20,    20,   280,   219,
     182,   229,   178,   136,   111,   219,   219,   299,   178,   178,
     111,   178,   139,    71,   100,  1531,   134,     6,   178,   175,
     124,  1022,   229,   950,   134,   952,   178,   177,    99,   225,
     225,   182,   225,    99,   178,    72,   178,   225,   243,   139,
     139,   178,   178,   175,   279,   175,    20,    20,    90,   162,
     175,  1052,  1317,   928,   118,    90,    88,   177,   243,   175,
     177,   175,   937,   275,   939,   940,   175,   178,   995,   175,
     145,   998,    20,   178,  1001,   100,    46,   162,   250,    88,
     188,   956,   111,    88,    20,  1012,   100,  1014,    88,   111,
     111,   264,   967,   968,   969,   217,   971,   972,   973,   974,
     975,   976,  1103,   978,   979,  1370,   188,   177,   188,   258,
     175,   273,   111,   174,   217,    87,   991,   177,   111,   188,
     111,   280,   190,   111,   178,   145,   217,   111,   561,   561,
     242,   661,   854,  1099,  1508,   386,   238,  1536,  1058,  1140,
    1015,  1197,  1017,  1018,   242,   286,   917,   914,   245,   998,
     298,   298,   475,   246,  1135,  1311,  1157,   280,   406,  1117,
     382,  1205,  1217,   991,  1215,  1212,   514,   298,  1143,  1044,
     285,   299,  1148,   299,  1152,   299,   585,   637,   746,  1165,
     586,  1549,  1555,   821,   904,  1093,  1192,  1062,  1057,  1116,
    1202,  1248,  1259,  1024,  1404,  1401,  1033,   888,  1125,  1252,
    1286,  1249,  1419,  1082,    -1,   416,    -1,    -1,  1135,    -1,
      -1,   307,    -1,    -1,    -1,    -1,  1143,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1151,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1110,    -1,    -1,    -1,    -1,
    1115,    -1,    -1,    -1,  1171,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1137,  1138,    -1,  1192,    -1,    -1,    -1,    -1,
      -1,  1146,  1147,    -1,  1201,    -1,    -1,    -1,  1205,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1219,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    29,    -1,    31,    32,    -1,    34,    -1,    -1,    -1,
      -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      48,    -1,    50,    51,   416,    -1,    -1,    -1,    -1,  1204,
      58,    -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1215,    69,    -1,    -1,    -1,    73,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1230,    -1,    -1,  1233,    -1,
    1235,    -1,    -1,    -1,    -1,    -1,    -1,  1294,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   104,   105,   106,    -1,
      -1,  1308,  1309,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1332,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1342,    -1,    -1,    -1,  1346,
      -1,    -1,    -1,    -1,   152,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1307,   161,    -1,    -1,    -1,    -1,  1313,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1322,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1330,  1331,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1349,  1350,  1351,  1352,  1353,    -1,
    1355,  1356,    -1,    -1,   212,    -1,    -1,  1488,    -1,    -1,
      -1,    -1,    -1,    -1,   222,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1382,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1450,    -1,    -1,   254,    -1,  1455,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1466,
      -1,    -1,    -1,    -1,  1471,    -1,  1473,    -1,    -1,    -1,
      -1,    -1,   280,   281,   282,   283,   284,    -1,   286,   287,
     288,   289,   290,    -1,    -1,  1440,    -1,   295,   296,    -1,
    1445,    -1,    -1,    -1,  1449,    -1,  1451,  1504,    -1,    -1,
    1507,    -1,    -1,    -1,    -1,    -1,  1513,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1524,    -1,    -1,
      -1,  1528,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1537,    -1,  1539,    -1,    -1,    -1,  1543,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1569,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1587,    -1,  1589,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1545,    -1,    -1,     3,    -1,  1602,    -1,    -1,    -1,  1606,
      10,    -1,    -1,    -1,  1611,    -1,    -1,    17,    18,    -1,
      20,    -1,  1567,    -1,    -1,    25,    26,  1572,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,  1592,    48,    49,
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
     300,   301,   302,   303,     3,    -1,    -1,    -1,    -1,    -1,
      -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
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
      -1,   171,   172,   173,    -1,    -1,    -1,   177,   178,   179,
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
     167,   168,    -1,    -1,   171,   172,   173,    -1,    -1,    -1,
     177,   178,   179,   180,   181,    -1,   183,   184,   185,    -1,
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
     175,    -1,   177,    -1,   179,   180,   181,    -1,   183,   184,
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
      -1,    -1,   171,   172,   173,    -1,   175,    -1,   177,    -1,
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
     150,   151,   152,    -1,    -1,    -1,    -1,   157,   158,   159,
     160,   161,   162,   163,   164,   165,    -1,   167,   168,    -1,
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
      -1,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      -1,    88,    89,    90,    91,    92,    93,    94,    95,    -1,
      -1,    98,    99,    -1,    -1,    -1,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,    -1,    -1,   116,
      -1,   118,   119,   120,   121,    -1,   123,    -1,    -1,    -1,
     127,   128,   129,   130,   131,    -1,    -1,    -1,    -1,    -1,
      -1,   138,   139,   140,   141,   142,   143,   144,    -1,    -1,
      -1,   148,   149,   150,   151,   152,    -1,    -1,    -1,    -1,
     157,   158,   159,   160,   161,   162,   163,   164,   165,    -1,
     167,   168,    -1,    -1,   171,   172,   173,    -1,    -1,    -1,
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
      64,    65,    66,    -1,    68,    69,    70,    71,    72,    73,
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
      -1,    -1,    -1,   177,    -1,   179,   180,   181,    -1,   183,
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
      61,    62,    -1,    64,    65,    66,    -1,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    -1,    88,    89,    90,
      91,    92,    93,    94,    95,    -1,    -1,    98,    99,    -1,
      -1,    -1,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,    -1,    -1,   116,    -1,   118,   119,   120,
     121,    -1,   123,    -1,    -1,    -1,   127,   128,   129,   130,
     131,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,   140,
     141,   142,   143,   144,    -1,    -1,    -1,   148,   149,    -1,
     151,   152,    -1,    -1,    -1,    -1,   157,   158,   159,   160,
     161,   162,   163,   164,   165,    -1,    -1,    -1,    -1,    -1,
     171,   172,   173,    -1,    -1,    -1,   177,    -1,   179,   180,
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
      58,    59,    60,    61,    62,    -1,    64,    65,    66,    -1,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    -1,
      88,    89,    90,    91,    92,    93,    94,    95,    -1,    -1,
      98,    99,    -1,    -1,    -1,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,    -1,    -1,   116,    -1,
     118,   119,   120,   121,    -1,   123,    -1,    -1,    -1,   127,
     128,   129,   130,   131,    -1,    -1,    -1,    -1,    -1,    -1,
     138,   139,   140,   141,   142,   143,   144,    -1,    -1,    -1,
     148,   149,    -1,   151,   152,    -1,    -1,    -1,    -1,   157,
     158,   159,   160,   161,   162,   163,   164,   165,    -1,    -1,
      -1,    -1,    -1,   171,   172,   173,    -1,    -1,    -1,   177,
      -1,   179,   180,   181,    -1,    -1,    -1,   185,    -1,   187,
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
      -1,    -1,    17,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    64,
      65,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    -1,    88,    89,    90,    91,    -1,    93,    94,
      95,    -1,    -1,    98,    99,    -1,    -1,    -1,    -1,   104,
     105,   106,   107,   108,   109,   110,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   118,   119,   120,   121,    -1,   123,    -1,
      -1,    -1,   127,   128,   129,   130,   131,    -1,    -1,    -1,
      -1,    -1,    -1,   138,   139,   140,    -1,   142,   143,   144,
      -1,    -1,    -1,    -1,    -1,    -1,   151,   152,    -1,    -1,
      -1,    -1,   157,   158,   159,   160,   161,   162,   163,   164,
      -1,    -1,    -1,    -1,    -1,    -1,   171,   172,   173,    -1,
      -1,    -1,   177,    -1,   179,   180,   181,    -1,    -1,    -1,
     185,    -1,   187,    -1,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,    -1,    -1,   202,   203,    -1,
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
      -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    -1,    64,    65,    66,    -1,    68,    69,    70,    71,
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
     302,    14,    -1,    -1,    -1,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    25,    26,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      -1,    64,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    -1,    88,    89,    90,    91,    -1,
      93,    94,    95,    -1,    -1,    98,    99,    -1,    -1,    -1,
      -1,   104,   105,   106,   107,   108,   109,   110,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   118,   119,   120,   121,    -1,
     123,    -1,    -1,    -1,   127,   128,   129,   130,   131,    -1,
      -1,    -1,    -1,    -1,    -1,   138,   139,   140,    -1,   142,
     143,   144,   145,    -1,    -1,   148,    -1,    -1,   151,   152,
      -1,    -1,    -1,    -1,   157,   158,   159,   160,   161,   162,
     163,   164,    -1,    -1,    -1,    -1,    -1,    -1,   171,   172,
     173,    -1,    -1,    -1,   177,    -1,   179,    -1,   181,    -1,
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
      14,    -1,    -1,    -1,    18,    -1,    20,    -1,    -1,    -1,
      -1,    25,    26,    -1,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    -1,
      64,    65,    66,    -1,    68,    69,    70,    71,    72,    73,
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
      -1,    -1,    -1,   177,   178,   179,    -1,   181,    -1,    -1,
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
     294,   295,   296,   297,   298,   299,   300,   301,   302,    14,
      -1,    -1,    -1,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    64,
      65,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    -1,    88,    89,    90,    91,    -1,    93,    94,
      95,    -1,    -1,    98,    99,    -1,    -1,    -1,    -1,   104,
     105,   106,   107,   108,   109,   110,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   118,   119,   120,   121,    -1,   123,    -1,
      -1,    -1,   127,   128,   129,   130,   131,    -1,    -1,    -1,
      -1,    -1,    -1,   138,   139,   140,    -1,   142,   143,   144,
      -1,    -1,    -1,    -1,    -1,    -1,   151,   152,    -1,    -1,
      -1,    -1,   157,   158,   159,   160,   161,   162,   163,   164,
      -1,    -1,    -1,    -1,    -1,    -1,   171,   172,   173,    -1,
      -1,    -1,   177,    -1,   179,    -1,   181,    -1,    -1,    -1,
      -1,    -1,   187,    -1,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,    -1,    -1,   202,   203,    -1,
      -1,   206,   207,    -1,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,    -1,   252,   253,   254,
      -1,   256,   257,   258,   259,   260,   261,    -1,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,    16,    -1,
      18,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    -1,    64,    65,    66,    -1,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    -1,
      88,    89,    90,    91,    -1,    93,    94,    95,    -1,    -1,
      98,    99,    -1,    -1,    -1,    -1,   104,   105,   106,   107,
     108,   109,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     118,   119,   120,   121,    -1,   123,    -1,    -1,    -1,   127,
     128,   129,   130,   131,    -1,    -1,    -1,    -1,    -1,    -1,
     138,   139,   140,    -1,   142,   143,   144,    -1,    -1,    -1,
      -1,    -1,    -1,   151,   152,    -1,    -1,    -1,    -1,   157,
     158,   159,   160,   161,   162,   163,   164,    -1,    -1,    -1,
      -1,    -1,    -1,   171,   172,   173,    -1,    -1,    -1,   177,
      -1,   179,    -1,   181,    -1,    -1,    -1,    -1,    -1,   187,
      -1,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,    -1,    -1,   202,   203,    -1,    -1,   206,   207,
      -1,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,    -1,   252,   253,   254,    -1,   256,   257,
     258,   259,   260,   261,    -1,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    25,    26,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      -1,    64,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    -1,    88,    89,    90,    91,    -1,
      93,    94,    95,    -1,    -1,    98,    99,    -1,    -1,    -1,
      -1,   104,   105,   106,   107,   108,   109,   110,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   118,   119,   120,   121,    -1,
     123,    -1,    -1,    -1,   127,   128,   129,   130,   131,    -1,
      -1,    -1,    -1,    -1,    -1,   138,   139,   140,    -1,   142,
     143,   144,    -1,    -1,    -1,   148,    -1,    -1,   151,   152,
      -1,    -1,    -1,    -1,   157,   158,   159,   160,   161,   162,
     163,   164,    -1,    -1,    -1,    -1,    -1,    -1,   171,   172,
     173,    -1,    -1,    -1,   177,   178,   179,   180,   181,    -1,
      -1,    -1,   185,    -1,   187,    -1,   189,   190,   191,   192,
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
      18,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    -1,    64,    65,    66,    -1,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    -1,
      88,    89,    90,    91,    -1,    93,    94,    95,    -1,    -1,
      98,    99,    -1,    -1,    -1,    -1,   104,   105,   106,   107,
     108,   109,   110,    -1,    -1,    -1,   114,    -1,    -1,    -1,
     118,   119,   120,   121,    -1,   123,    -1,    -1,    -1,   127,
     128,   129,   130,   131,    -1,    -1,    -1,    -1,    -1,    -1,
     138,   139,   140,    -1,   142,   143,   144,   145,    -1,    -1,
     148,    -1,    -1,   151,   152,    -1,    -1,    -1,    -1,   157,
     158,   159,   160,   161,   162,   163,   164,    -1,    -1,    -1,
      -1,    -1,    -1,   171,   172,   173,    -1,    -1,    -1,   177,
      -1,   179,    -1,   181,    -1,    -1,    -1,    -1,    -1,   187,
      -1,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,    -1,    -1,   202,   203,    -1,    -1,   206,   207,
      -1,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,    -1,   252,   253,   254,    -1,   256,   257,
     258,   259,   260,   261,    -1,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    25,    26,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      -1,    64,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    -1,    88,    89,    90,    91,    -1,
      93,    94,    95,    -1,    -1,    98,    99,    -1,    -1,    -1,
      -1,   104,   105,   106,   107,   108,   109,   110,   111,    -1,
      -1,    -1,    -1,    -1,    -1,   118,   119,   120,   121,    -1,
     123,    -1,    -1,    -1,   127,   128,   129,   130,   131,    -1,
      -1,    -1,    -1,    -1,    -1,   138,   139,   140,    -1,   142,
     143,   144,    -1,    -1,    -1,   148,    -1,    -1,   151,   152,
      -1,    -1,    -1,    -1,   157,   158,   159,   160,   161,   162,
     163,   164,    -1,    -1,    -1,    -1,    -1,    -1,   171,   172,
     173,    -1,    -1,    -1,   177,    -1,   179,   180,   181,    -1,
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
      18,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    -1,    64,    65,    66,    -1,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    -1,
      88,    89,    90,    91,    -1,    93,    94,    95,    -1,    -1,
      98,    99,    -1,    -1,    -1,    -1,   104,   105,   106,   107,
     108,   109,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     118,   119,   120,   121,    -1,   123,    -1,    -1,    -1,   127,
     128,   129,   130,   131,    -1,    -1,    -1,    -1,    -1,    -1,
     138,   139,   140,    -1,   142,   143,   144,   145,    -1,    -1,
     148,    -1,    -1,   151,   152,    -1,    -1,    -1,    -1,   157,
     158,   159,   160,   161,   162,   163,   164,    -1,    -1,    -1,
      -1,    -1,    -1,   171,   172,   173,    -1,    -1,    -1,   177,
      -1,   179,    -1,   181,    -1,    -1,    -1,    -1,    -1,   187,
      -1,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,    -1,    -1,   202,   203,    -1,    -1,   206,   207,
      -1,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,    -1,   252,   253,   254,    -1,   256,   257,
     258,   259,   260,   261,    -1,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    25,    26,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      -1,    64,    65,    66,    -1,    68,    69,    70,    71,    72,
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
      -1,    -1,   185,    -1,   187,    -1,   189,   190,   191,   192,
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
      18,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    -1,    64,    65,    66,    -1,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    -1,
      88,    89,    90,    91,    -1,    93,    94,    95,    -1,    -1,
      98,    99,    -1,    -1,    -1,    -1,   104,   105,   106,   107,
     108,   109,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     118,   119,   120,   121,    -1,   123,    -1,    -1,    -1,   127,
     128,   129,   130,   131,    -1,    -1,    -1,    -1,    -1,    -1,
     138,   139,   140,    -1,   142,   143,   144,    -1,    -1,    -1,
      -1,    -1,    -1,   151,   152,    -1,    -1,    -1,    -1,   157,
     158,   159,   160,   161,   162,   163,   164,    -1,    -1,    -1,
      -1,    -1,    -1,   171,   172,   173,    -1,    -1,    -1,   177,
     178,   179,    -1,   181,    -1,    -1,    -1,   185,    -1,   187,
      -1,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,    -1,    -1,   202,   203,    -1,    -1,   206,   207,
      -1,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,    -1,   252,   253,   254,    -1,   256,   257,
     258,   259,   260,   261,    -1,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    25,    26,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      -1,    64,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    -1,    88,    89,    90,    91,    -1,
      93,    94,    95,    -1,    -1,    98,    99,    -1,    -1,    -1,
      -1,   104,   105,   106,   107,   108,   109,   110,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   118,   119,   120,   121,    -1,
     123,    -1,    -1,    -1,   127,   128,   129,   130,   131,    -1,
      -1,    -1,    -1,    -1,    -1,   138,   139,   140,    -1,   142,
     143,   144,    -1,    -1,    -1,   148,    -1,    -1,   151,   152,
      -1,    -1,    -1,    -1,   157,   158,   159,   160,   161,   162,
     163,   164,    -1,    -1,    -1,    -1,    -1,    -1,   171,   172,
     173,    -1,    -1,    -1,   177,    -1,   179,   180,   181,    -1,
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
      18,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    -1,    64,    65,    66,    -1,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    -1,
      88,    89,    90,    91,    -1,    93,    94,    95,    -1,    -1,
      98,    99,    -1,    -1,    -1,    -1,   104,   105,   106,   107,
     108,   109,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     118,   119,   120,   121,    -1,   123,    -1,    -1,    -1,   127,
     128,   129,   130,   131,    -1,    -1,    -1,    -1,    -1,    -1,
     138,   139,   140,    -1,   142,   143,   144,    -1,    -1,    -1,
     148,    -1,    -1,   151,   152,    -1,    -1,    -1,    -1,   157,
     158,   159,   160,   161,   162,   163,   164,    -1,    -1,    -1,
      -1,    -1,    -1,   171,   172,   173,    -1,    -1,    -1,   177,
      -1,   179,   180,   181,    -1,    -1,    -1,    -1,    -1,   187,
      -1,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,    -1,    -1,   202,   203,    -1,    -1,   206,   207,
      -1,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,    -1,   252,   253,   254,    -1,   256,   257,
     258,   259,   260,   261,    -1,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    25,    26,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      -1,    64,    65,    66,    -1,    68,    69,    70,    71,    72,
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
     173,    -1,    -1,    -1,   177,    -1,   179,    -1,   181,    -1,
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
      34,    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    -1,    50,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    58,    -1,    60,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,    73,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     104,   105,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   193,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   222,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   280,   281,   282,   283,
     284,    -1,   286,   287,   288,   289,   290,    -1,    -1,    -1,
      -1,   295,   296
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
      54,    57,    59,    62,    65,    68,    70,    84,    85,    91,
      98,   107,   108,   127,   130,   131,   145,   148,   161,   164,
     171,   172,   181,   193,   206,   216,   217,   218,   220,   221,
     228,   230,   231,   232,   233,   236,   237,   239,   609,   145,
      61,    66,   111,   392,   148,   366,   148,    26,    55,   111,
      39,    14,   145,   148,   554,   609,   148,   111,   111,   145,
     148,   148,   148,    88,   145,   213,   214,   114,   114,   114,
     145,   148,   609,    30,    37,    54,    65,    91,   472,   609,
     114,   114,   114,   609,   111,   114,   114,   178,   386,   609,
     145,   114,   554,    16,   609,   114,   114,   609,   114,   464,
     145,    21,   205,   207,   217,   219,   148,   217,   219,   217,
     217,   222,   111,   145,   368,   234,   234,   235,   148,   145,
     111,   319,   320,     0,   319,   322,   323,    25,    42,   325,
     385,   182,   182,   100,   182,   387,    33,    39,    44,    52,
      64,   160,   163,   177,   203,   391,   396,   397,   398,   415,
     416,   420,   402,   403,   609,   159,    86,   124,   132,   133,
     135,   143,   147,   149,   154,   170,   194,   195,   196,   197,
     198,   199,   456,   457,   242,   150,   167,   190,   110,   138,
     151,   185,   192,   201,   128,   142,    43,   191,    94,    95,
     150,   167,   455,   145,   461,   464,   183,   184,   146,   476,
     477,   472,   476,   472,   148,   476,   137,   148,    20,   553,
     173,   187,   173,   187,   158,   173,   377,   609,   377,   609,
     161,   193,    40,   378,    40,   609,   144,   111,   354,    37,
      40,    73,    99,   160,   554,   213,   214,   215,   293,   294,
     239,   582,   609,   286,   609,   291,   291,   293,   294,   297,
     280,   288,   357,   554,   386,   178,   386,    37,    57,   178,
     529,   530,   386,   178,   185,   609,   145,   389,   277,   277,
     111,   410,   111,   178,   381,   382,   145,   383,   386,   152,
     553,   106,   152,   348,   553,   407,   409,   609,   111,   386,
      20,   178,   554,   145,   609,   609,   428,   429,   609,   386,
     178,   386,   386,   531,   609,   386,   145,   145,   386,   178,
     185,   609,   145,   428,   178,    27,   492,   493,   494,   386,
       7,   166,    15,   178,   386,   205,    20,   389,   389,   178,
     389,   389,   389,   389,   223,   547,   548,   609,   369,   389,
     389,   386,   408,   414,   609,   319,   327,   328,    25,   329,
     389,   388,   111,   160,   162,   162,   389,   389,   100,    88,
      90,   139,   266,   404,   405,   515,   439,   440,   442,   442,
     442,   442,   441,   442,   442,   442,    65,   446,   446,   445,
     447,   447,   447,   447,   448,   448,   449,   449,   223,    88,
      88,    88,   175,   386,   464,   464,   386,   477,   178,   389,
     487,   141,   178,   487,   100,   100,   366,    20,   609,   609,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
     331,   332,   333,    88,   129,   134,   351,   352,   353,   609,
     129,   134,   152,   152,   331,   553,   119,   124,    47,    50,
      93,   244,   257,   259,   270,   271,   272,   274,   276,   583,
     584,   585,   586,   587,   588,   595,   601,   602,   239,    88,
     229,   360,   292,   609,   609,   609,   124,   175,   175,   178,
     178,   175,   100,   178,   100,   178,   175,   386,   175,   609,
      49,   209,   247,   393,   394,   609,    88,   100,   178,   386,
     178,   554,    90,    37,   554,   553,    90,   100,   134,   405,
     515,   175,   178,   178,   175,   386,   178,   134,   100,   179,
     139,   515,   175,   178,   178,   145,   175,   386,   386,   175,
     100,   178,   100,   178,   175,   386,   179,   609,   493,   494,
     122,   188,   175,   175,   123,   182,    88,   210,   211,   225,
      88,   210,   211,   225,    88,   229,   217,   100,   227,   134,
      25,   370,   386,   178,   175,    38,   100,   182,   106,   182,
     609,   162,   389,   421,   422,   111,   417,   418,   111,    40,
     144,   148,   202,   516,   518,   520,   521,   537,   538,   539,
     540,   609,   111,   389,   111,   139,   405,   139,   139,   404,
     405,   442,   145,   148,   252,   460,   479,   556,   559,   560,
     561,   562,   563,   567,   569,   571,   572,   516,   516,   514,
     520,   514,   175,   176,   100,   178,   178,   140,   157,   140,
     157,   129,   145,   384,   366,   366,   332,   124,   518,   353,
     389,   515,   134,   389,   553,   553,   120,   121,   553,   270,
     271,   272,   276,   609,   256,   267,   256,   267,    20,   279,
      90,   106,   148,   589,   592,   583,    30,    36,    54,    65,
      91,   217,   359,   521,   284,   285,   219,   292,   301,    88,
     360,   292,   553,   145,   531,   532,   609,   531,   532,   175,
     139,   515,   247,    46,    53,    71,   111,   404,   411,   412,
     413,   394,   515,   516,   382,    88,   175,   189,   124,   347,
     553,   152,   124,    90,   347,   111,   389,   134,   134,   405,
     145,   175,   389,   111,   389,   389,   139,    93,   431,   432,
     433,    93,   435,   436,   386,   175,   175,   145,   531,   531,
     175,   389,    27,   494,   122,   188,     8,     9,    96,   115,
     117,   186,   383,   489,   491,   502,   503,   506,    20,   224,
     226,   389,   389,   389,   224,   226,   389,   389,   389,   389,
     389,   389,   111,   389,   389,   354,   371,   100,   182,   175,
     368,   238,   550,   551,   145,   111,   421,    89,    99,   109,
     119,   423,   424,   425,   426,   100,   609,   100,   403,   148,
     148,   518,   148,   136,   167,   185,   517,   609,   609,   389,
     139,   389,   389,   139,   405,   139,   386,   556,   563,   145,
     278,   443,   608,    90,   161,   245,   246,   248,   255,   265,
     277,   557,   558,   577,   578,   579,   580,   603,   606,   251,
     253,   564,   582,   260,   568,   604,   240,   241,   263,   573,
     574,   136,   389,   386,   129,   368,   129,   145,   533,   352,
     389,   279,    20,    90,   106,   148,   596,    20,   589,   360,
     517,   219,   219,   462,   280,   299,   359,   219,   182,   175,
     386,   178,   178,   136,   178,   178,   389,   139,   111,   111,
     389,   609,   413,    71,   516,   389,   553,   100,   347,   409,
     389,   389,   134,   175,   386,   429,   389,   389,   106,   432,
      93,   177,   111,   516,   106,   436,   175,   175,   386,   178,
     178,   124,   186,   491,     6,   609,   186,   502,   182,   225,
     225,   225,   225,   229,   548,   177,   134,   371,   473,   552,
     551,   389,   414,   553,   120,   121,   425,   426,   426,   422,
      99,   419,   418,   178,   185,   516,   519,   178,   178,   178,
     389,   389,   139,   389,   175,   178,   556,   570,   243,   209,
     247,   261,   268,   607,    90,   249,   250,   605,   243,   560,
     607,   445,   577,   561,   139,   275,   565,   566,   605,   279,
     576,    72,   575,   175,   388,    20,   128,   192,   598,   599,
     600,    20,   597,   598,   264,   593,   590,   591,   592,   162,
     609,   250,   360,   462,   175,   389,   609,   609,   412,   389,
     118,    90,   553,   389,   175,   177,   389,   389,   609,   177,
     111,   177,   175,   494,   609,   186,   494,   609,   389,   389,
     389,   389,   389,   389,   389,   148,   201,   384,   175,   426,
     553,    88,   178,   100,   178,   389,   175,   447,    45,   121,
     445,   445,   262,   269,   279,   581,   581,   562,   145,   273,
     175,   596,   596,   600,   100,   178,    20,   594,   605,   178,
     100,   362,   363,   462,   111,   217,   300,   280,   162,    46,
     389,   347,   389,    88,   389,   609,   389,    87,   174,   495,
     494,   609,   188,   494,   111,   473,   516,   516,    88,   445,
     445,   190,   386,    20,   258,   592,   100,    88,   609,   111,
     217,   609,   362,   111,   516,   177,     4,   125,   498,   499,
     501,   503,    19,   126,   496,   497,   500,   503,   188,   494,
     188,   609,   516,   445,   175,   363,   520,   298,   609,   111,
     217,   609,   177,   389,    87,   125,   501,   174,   126,   500,
     188,   100,   178,   426,   389,   298,   609,   111,   389,   111,
     384,   286,   298,   609,   609,   299,   389,   299,   100,   178,
     462,   462,   111,   384,   190,   609,   280,   178,   609,   384,
     217,   111,   609,   299,   462
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
     610,   610,   610,   610
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
       1,     1,     1,     1
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
      -1,    68,    -1,   202,    -1,    29,    -1,   254,    -1,    28,
      -1,   214,    -1,   213,    -1,   138,    -1,    35,    -1,   252,
      -1,   253,    -1,   267,    -1,   256,    -1,   244,    -1,   278,
      -1,   270,    -1,   272,    -1,   271,    -1,   276,    -1,   248,
      -1,   243,    -1,    72,    -1,   209,    -1,   247,    -1,    45,
      -1,   215,    -1,   228,    -1,   295,    -1,   222,    -1,   194,
      -1,   199,    -1,   198,    -1,   197,    -1,   196,    -1,   195,
      -1,    90,    -1,   104,    -1,   105,    -1,   177,    -1,    39,
      -1,    52,    -1,    61,    -1,    66,    -1,    53,    -1,    46,
      -1,    49,    -1,    71,    -1,    33,    -1,   139,    -1,    44,
      -1,   203,    -1,   162,    -1,   163,    -1,   160,    -1,    64,
      -1,    89,    -1,   109,    -1,   120,    -1,   121,    -1,    99,
      -1,    62,    -1,   127,    -1,   179,    -1,    93,    -1,    88,
      -1,   189,    -1,   118,    -1,   159,    -1,    86,    -1,    43,
      -1,   223,    -1,    94,    -1,   190,    -1,   110,    -1,   151,
      -1,   192,    -1,   142,    -1,   128,    -1,    70,    -1,    95,
      -1,   191,    -1,   143,    -1,   173,    -1,   187,    -1,   152,
      -1,   129,    -1,   123,    -1,   158,    -1,   140,    -1,   157,
      -1,    25,    -1,    31,    -1,    51,    -1,   106,    -1,    32,
      -1,    50,    -1,   207,    -1,    42,    -1,    55,    -1,    26,
      -1,    40,    -1,   266,    -1,   242,    -1,   275,    -1,   277,
      -1,   246,    -1,   260,    -1,   273,    -1,   265,    -1,   245,
      -1,   259,    -1,   274,    -1,   264,    -1,   258,    -1,   257,
      -1,   241,    -1,   240,    -1,   263,    -1,   249,    -1,   250,
      -1,   279,    -1,   269,    -1,   268,    -1,   261,    -1,   221,
      -1,   227,    -1,   224,    -1,   218,    -1,   211,    -1,   210,
      -1,   212,    -1,   229,    -1,   219,    -1,   220,    -1,   226,
      -1,   216,    -1,   225,    -1,    60,    -1,    58,    -1,    69,
      -1,    34,    -1,    48,    -1,   161,    -1,   193,    -1,   235,
      -1,   230,    -1,   233,    -1,   234,    -1,   236,    -1,   231,
      -1,   232,    -1,   237,    -1,   238,    -1,    38,    -1,   239,
      -1,    59,    -1,   288,    -1,   286,    -1,   287,    -1,   292,
      -1,   293,    -1,   294,    -1,   289,    -1,   290,    -1,   291,
      -1,    73,    -1,    74,    -1,    75,    -1,    76,    -1,    77,
      -1,    78,    -1,    79,    -1,    80,    -1,    81,    -1,    82,
      -1,    83,    -1,   280,    -1,   281,    -1,   282,    -1,   283,
      -1,   284,    -1,   285,    -1,   296,    -1,   297,    -1,   298,
      -1,   299,    -1,   300,    -1,   301,    -1,   302,    -1,    84,
      -1,    98,    -1,   107,    -1,   164,    -1,   171,    -1,   181,
      -1,   130,    -1,    85,    -1,   108,    -1,   131,    -1,   172,
      -1
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
    2983,  2985,  2987,  2989
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,  1048,  1048,  1049,  1054,  1055,  1056,  1057,  1061,  1077,
    1082,  1089,  1094,  1105,  1110,  1118,  1126,  1134,  1140,  1152,
    1161,  1165,  1169,  1181,  1187,  1197,  1203,  1213,  1214,  1215,
    1216,  1221,  1222,  1223,  1224,  1225,  1226,  1227,  1228,  1229,
    1235,  1240,  1249,  1255,  1264,  1273,  1274,  1275,  1276,  1277,
    1278,  1279,  1280,  1281,  1282,  1287,  1288,  1289,  1290,  1291,
    1292,  1293,  1296,  1301,  1302,  1312,  1321,  1327,  1337,  1343,
    1353,  1363,  1371,  1377,  1388,  1393,  1403,  1409,  1415,  1421,
    1438,  1446,  1454,  1458,  1467,  1476,  1489,  1495,  1506,  1510,
    1518,  1523,  1528,  1535,  1548,  1555,  1561,  1568,  1574,  1578,
    1585,  1596,  1600,  1608,  1614,  1620,  1629,  1635,  1644,  1648,
    1654,  1658,  1662,  1666,  1672,  1678,  1684,  1690,  1696,  1700,
    1706,  1712,  1719,  1727,  1735,  1743,  1751,  1763,  1777,  1791,
    1808,  1812,  1819,  1823,  1830,  1838,  1855,  1861,  1869,  1876,
    1886,  1896,  1906,  1916,  1933,  1939,  1950,  1954,  1958,  1962,
    1971,  1978,  1997,  2007,  2013,  2019,  2029,  2036,  2047,  2054,
    2061,  2073,  2077,  2084,  2089,  2104,  2121,  2125,  2129,  2133,
    2141,  2151,  2165,  2175,  2189,  2199,  2214,  2220,  2232,  2236,
    2247,  2254,  2262,  2277,  2281,  2295,  2299,  2308,  2312,  2326,
    2327,  2328,  2329,  2330,  2331,  2334,  2335,  2336,  2337,  2338,
    2340,  2341,  2344,  2345,  2346,  2347,  2348,  2353,  2368,  2375,
    2379,  2386,  2390,  2394,  2401,  2409,  2420,  2430,  2443,  2452,
    2453,  2454,  2458,  2459,  2460,  2461,  2462,  2465,  2471,  2480,
    2484,  2492,  2502,  2508,  2520,  2524,  2532,  2541,  2551,  2559,
    2568,  2577,  2592,  2601,  2611,  2619,  2625,  2634,  2640,  2652,
    2660,  2670,  2678,  2690,  2696,  2707,  2709,  2713,  2721,  2725,
    2730,  2734,  2738,  2742,  2750,  2764,  2772,  2779,  2785,  2796,
    2800,  2809,  2817,  2823,  2833,  2839,  2849,  2853,  2863,  2869,
    2875,  2881,  2890,  2899,  2908,  2921,  2925,  2933,  2939,  2949,
    2957,  2966,  2979,  2986,  2998,  3002,  3014,  3021,  3027,  3036,
    3043,  3049,  3061,  3068,  3081,  3087,  3099,  3105,  3117,  3126,
    3130,  3139,  3143,  3151,  3155,  3165,  3172,  3181,  3191,  3190,
    3204,  3213,  3222,  3235,  3239,  3252,  3255,  3262,  3266,  3275,
    3279,  3283,  3292,  3296,  3302,  3308,  3314,  3325,  3329,  3333,
    3341,  3345,  3351,  3361,  3365,  3375,  3379,  3389,  3393,  3403,
    3407,  3417,  3421,  3429,  3433,  3437,  3441,  3451,  3455,  3459,
    3467,  3471,  3475,  3479,  3483,  3487,  3495,  3499,  3503,  3511,
    3515,  3519,  3523,  3534,  3540,  3550,  3556,  3566,  3570,  3608,
    3614,  3620,  3626,  3637,  3645,  3656,  3662,  3672,  3676,  3684,
    3690,  3698,  3704,  3716,  3722,  3732,  3736,  3740,  3744,  3748,
    3754,  3760,  3768,  3772,  3780,  3784,  3795,  3799,  3803,  3809,
    3813,  3827,  3831,  3839,  3843,  3853,  3857,  3861,  3870,  3874,
    3880,  3884,  3892,  3898,  3908,  3916,  3920,  3924,  3928,  3932,
    3936,  3940,  3944,  3948,  3956,  3960,  3968,  3975,  3982,  3993,
    4001,  4005,  4013,  4021,  4029,  4083,  4087,  4099,  4105,  4115,
    4119,  4127,  4131,  4135,  4143,  4153,  4163,  4173,  4183,  4193,
    4208,  4214,  4225,  4231,  4242,  4253,  4255,  4259,  4264,  4274,
    4277,  4284,  4292,  4298,  4308,  4321,  4324,  4331,  4337,  4343,
    4350,  4361,  4365,  4375,  4379,  4389,  4393,  4397,  4402,  4411,
    4417,  4423,  4429,  4439,  4443,  4455,  4459,  4471,  4483,  4487,
    4491,  4495,  4499,  4503,  4511,  4519,  4525,  4531,  4535,  4552,
    4556,  4560,  4564,  4572,  4580,  4588,  4592,  4596,  4600,  4608,
    4614,  4624,  4632,  4636,  4642,  4677,  4683,  4689,  4699,  4703,
    4707,  4711,  4715,  4722,  4728,  4738,  4746,  4750,  4754,  4758,
    4762,  4766,  4770,  4774,  4778,  4786,  4794,  4798,  4802,  4812,
    4820,  4828,  4832,  4836,  4844,  4848,  4854,  4860,  4864,  4874,
    4882,  4886,  4892,  4901,  4910,  4916,  4922,  4932,  4949,  4956,
    4971,  5007,  5011,  5020,  5029,  5039,  5043,  5052,  5061,  5065,
    5076,  5093,  5099,  5105,  5115,  5119,  5125,  5131,  5135,  5141,
    5145,  5151,  5157,  5164,  5174,  5179,  5187,  5193,  5203,  5225,
    5234,  5240,  5253,  5267,  5274,  5280,  5290,  5295,  5301,  5311,
    5324,  5330,  5340,  5350,  5351,  5370,  5376,  5391,  5400,  5403,
    5410,  5415,  5423,  5427,  5434,  5438,  5445,  5449,  5456,  5460,
    5469,  5482,  5485,  5493,  5496,  5504,  5512,  5520,  5524,  5532,
    5535,  5543,  5555,  5558,  5566,  5578,  5584,  5594,  5597,  5605,
    5609,  5613,  5621,  5624,  5632,  5635,  5643,  5647,  5651,  5655,
    5659,  5667,  5675,  5687,  5699,  5703,  5707,  5715,  5721,  5731,
    5735,  5739,  5743,  5747,  5751,  5755,  5759,  5767,  5771,  5775,
    5779,  5787,  5793,  5803,  5813,  5817,  5825,  5835,  5846,  5853,
    5857,  5865,  5868,  5875,  5880,  5889,  5899,  5902,  5910,  5913,
    5921,  5930,  5937,  5947,  5951,  5958,  5964,  5974,  5977,  5984,
    5989,  6001,  6009,  6021,  6029,  6033,  6041,  6045,  6049,  6057,
    6065,  6069,  6073,  6077,  6085,  6093,  6105,  6109,  6117,  6130,
    6134,  6141,  6142,  6143,  6144,  6145,  6146,  6147,  6148,  6149,
    6150,  6151,  6152,  6153,  6154,  6155,  6156,  6157,  6158,  6159,
    6160,  6161,  6162,  6163,  6164,  6165,  6166,  6167,  6168,  6169,
    6170,  6171,  6172,  6173,  6174,  6175,  6176,  6177,  6178,  6179,
    6180,  6181,  6182,  6183,  6184,  6185,  6186,  6187,  6188,  6189,
    6190,  6191,  6192,  6193,  6194,  6195,  6196,  6197,  6198,  6199,
    6200,  6201,  6202,  6203,  6204,  6205,  6206,  6207,  6208,  6209,
    6210,  6211,  6212,  6213,  6214,  6215,  6216,  6217,  6218,  6219,
    6220,  6221,  6222,  6223,  6224,  6225,  6226,  6227,  6228,  6229,
    6230,  6231,  6232,  6233,  6234,  6235,  6236,  6237,  6238,  6239,
    6240,  6241,  6242,  6243,  6244,  6245,  6246,  6247,  6248,  6249,
    6250,  6251,  6252,  6253,  6254,  6255,  6256,  6257,  6258,  6259,
    6260,  6261,  6262,  6263,  6264,  6265,  6266,  6267,  6268,  6269,
    6270,  6271,  6272,  6273,  6274,  6275,  6276,  6277,  6278,  6279,
    6280,  6281,  6282,  6283,  6284,  6285,  6286,  6287,  6288,  6289,
    6290,  6291,  6292,  6293,  6294,  6295,  6296,  6297,  6298,  6299,
    6300,  6301,  6302,  6303,  6304,  6305,  6306,  6307,  6308,  6309,
    6310,  6311,  6312,  6313,  6314,  6315,  6316,  6317,  6318,  6319,
    6320,  6321,  6322,  6323,  6324,  6325,  6326,  6327,  6328,  6329,
    6330,  6331,  6332,  6333,  6334,  6335,  6336,  6337,  6338,  6339,
    6340,  6341,  6342,  6343,  6344,  6345,  6346,  6347,  6348,  6349,
    6350,  6351,  6352,  6353
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
  const int xquery_parser::yylast_ = 11732;
  const int xquery_parser::yynnts_ = 294;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 553;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 317;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 571;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


} // zorba

/* Line 1053 of lalr1.cc  */
#line 15534 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"


/* Line 1055 of lalr1.cc  */
#line 6357 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"


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

