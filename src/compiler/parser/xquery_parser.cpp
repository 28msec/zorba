/* A Bison parser, made by GNU Bison 2.4.3.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009, 2010 Free
   Software Foundation, Inc.
   
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

/* Line 311 of lalr1.cc  */
#line 72 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"


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



/* Line 311 of lalr1.cc  */
#line 78 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"


#include "xquery_parser.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 861 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 317 of lalr1.cc  */
#line 961 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"

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



/* Line 317 of lalr1.cc  */
#line 149 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"

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

/* Line 380 of lalr1.cc  */
#line 215 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
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
        case 107: /* "\"'DECIMAL'\"" */

/* Line 480 of lalr1.cc  */
#line 859 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 322 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 120: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 858 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 331 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 145: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 857 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 340 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 324: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 349 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 325: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 358 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 326: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 367 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 376 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 385 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 394 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 403 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 412 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 421 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 882 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 430 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 882 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 439 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 448 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 457 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 466 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 475 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 484 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 493 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 502 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 511 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 520 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 529 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 538 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 547 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 556 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 565 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 574 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 583 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 592 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 601 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 610 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 619 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 882 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 628 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 637 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "DeclPropertyList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 646 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "DeclProperty" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 655 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 664 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "NodeModifier" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 673 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 682 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 691 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 700 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 709 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 718 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 882 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 727 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 736 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "Block" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 745 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "BlockDecls" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 754 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "BlockVarDeclList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 763 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "BlockVarDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 772 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "AssignExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 781 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "ExitExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 790 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "WhileExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 799 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 808 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "AnnotationList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "Annotation" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 826 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "AnnotationLiteralList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 835 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 844 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 853 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "FunctionDeclSimple" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 862 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "FunctionDeclSequential" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 871 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 880 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 889 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 898 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "EnclosedExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 907 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 916 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 934 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "ApplyExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "ConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 952 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 961 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 970 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 979 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 988 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 997 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1006 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1015 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1024 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1033 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1042 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1051 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1060 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1069 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1078 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1087 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "EvalVarDeclList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1096 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "EvalVarDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1105 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1114 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1123 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1132 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1141 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1150 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1159 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1168 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1177 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1186 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1195 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1204 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1213 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1222 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1231 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1240 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1249 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1258 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1267 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1276 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1285 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "SwitchExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1294 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "SwitchCaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1303 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "SwitchCaseClause" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1312 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "SwitchCaseOperandList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1321 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1330 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1339 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1348 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1357 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1366 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1375 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1384 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1393 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1402 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1411 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1420 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1429 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1438 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1447 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1456 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1465 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1474 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1483 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1492 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1501 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1510 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1519 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1528 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1537 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1546 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1555 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1564 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1573 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1582 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1591 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1600 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1609 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1618 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1627 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1636 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1645 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1654 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1663 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1672 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1681 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1690 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1699 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1708 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1717 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1726 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1735 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1744 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1753 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1762 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1771 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1780 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1789 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1798 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1807 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1816 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1825 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1834 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1843 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1852 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1861 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1870 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1879 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1888 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1897 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1906 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1915 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1924 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1933 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1942 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1951 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1960 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1969 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1978 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1987 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1996 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2005 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2014 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2023 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2032 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2041 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2050 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2059 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2068 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "AtomicType" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2077 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2086 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2095 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2104 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2113 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2122 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2131 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2140 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2149 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 533: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2158 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 534: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2167 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 535: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2176 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 536: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2185 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 537: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2194 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2203 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 543: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2212 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 546: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2221 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 547: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2230 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 548: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2239 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 549: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2248 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 550: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2257 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 551: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2266 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 552: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2275 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 553: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2284 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 554: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2293 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 555: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2302 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 556: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 882 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2311 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 557: /* "EvalExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2320 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 558: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2329 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 561: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2338 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 562: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2347 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 563: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2356 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 564: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2365 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 565: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2374 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 566: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2383 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 568: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2392 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 569: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2401 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 570: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2410 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 571: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2419 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 573: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2428 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 574: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2437 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 576: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2446 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 579: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2455 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 580: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2464 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 581: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2473 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 582: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2482 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 583: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2491 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 584: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2500 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 585: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2509 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 586: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2518 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 587: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2527 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 588: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2536 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 589: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2545 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 590: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2554 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 594: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2563 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 597: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2572 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 598: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2581 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 602: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2590 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 603: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2599 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 604: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2608 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 605: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2617 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 606: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2626 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 607: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2635 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 608: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2644 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 609: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2653 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 610: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2662 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 613: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2671 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 614: /* "FUNCTION_NAME" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2680 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
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
    location_type yyerror_range[3];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    YYCDEBUG << "Starting parse" << std::endl;


    /* User initialization code.  */
    
/* Line 553 of lalr1.cc  */
#line 125 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename2);
}

/* Line 553 of lalr1.cc  */
#line 2765 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"

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

/* Line 678 of lalr1.cc  */
#line 1020 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 1053 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL; YYABORT;
        }
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 1062 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 1067 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            MainModule *mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
            mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 1074 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 1079 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            LibraryModule *lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
            lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 1090 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8" );
        }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 1094 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
        }
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 1102 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);
          (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
        }
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 1107 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));
          (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
        }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 1112 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)), static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));
          (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
        }
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 1117 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
        }
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 1122 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
          (yylocation_stack_[(3) - (1)]).step();
          driver.parserErr("syntax error, missing semicolon \";\" after statement", (yylocation_stack_[(3) - (1)]));
          error((yyloc), ""); // The error message will be taken from the driver
          YYERROR;
        }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 1130 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
          (yylocation_stack_[(3) - (1)]).step();
          driver.parserErr("syntax error, missing semicolon \";\" after declaration", (yylocation_stack_[(3) - (1)]));
          error((yyloc), ""); // The error message will be taken from the driver
          YYERROR;
        }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 1138 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
          (yylocation_stack_[(5) - (3)]).step();
          driver.parserErr("syntax error, missing semicolon \";\" after declaration", (yylocation_stack_[(5) - (3)]));
          error((yyloc), ""); // The error message will be taken from the driver
          YYERROR;
        }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 1146 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
          (yylocation_stack_[(5) - (1)]).step();
          driver.parserErr("syntax error, missing semicolon \";\" after statement", (yylocation_stack_[(5) - (1)]));
          error((yyloc), ""); // The error message will be taken from the driver
          YYERROR;
        }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 1158 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
        }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 1162 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);
          (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
        }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 1167 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));
          (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
        }
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 1172 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)), static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));
          (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
        }
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 1181 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
            dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
        }
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 1190 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
            sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
            (yyval.node) = sdl;
        }
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 1196 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 1202 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 1215 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
            vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
            (yyval.node) = vdl;
        }
    break;

  case 28:

/* Line 678 of lalr1.cc  */
#line 1221 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 29:

/* Line 678 of lalr1.cc  */
#line 1227 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
            (yylocation_stack_[(3) - (1)]).step();
            driver.parserErr("syntax error, missing semicolon \";\" after declaration", (yylocation_stack_[(3) - (1)]));
            error((yyloc), ""); // The error message will be taken from the driver
            YYERROR;
        }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 1261 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
          delete (yysemantic_stack_[(4) - (4)].vstrpair);
        }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 1266 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
          delete (yysemantic_stack_[(4) - (4)].vstrpair);
        }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 1275 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.vstrpair) = new vector<string_pair_t>();
          (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
          delete (yysemantic_stack_[(1) - (1)].strpair);
        }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 1281 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
          delete (yysemantic_stack_[(2) - (2)].strpair);
          (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
        }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 1290 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
            (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
            delete sl;
        }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 1298 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 1299 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 1300 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 1301 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 1302 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 1303 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 54:

/* Line 678 of lalr1.cc  */
#line 1304 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 55:

/* Line 678 of lalr1.cc  */
#line 1305 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 1306 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 1307 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 1333 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
        }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 1341 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BoundarySpaceDecl(
                LOC((yyloc)), StaticContextConsts::preserve_space
            );
        }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 1347 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BoundarySpaceDecl(
                LOC((yyloc)), StaticContextConsts::strip_space
            );
        }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 1357 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultNamespaceDecl(
                LOC((yyloc)), ParseConstants::ns_element_default, SYMTAB((yysemantic_stack_[(5) - (5)].sval))
            );
        }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 1363 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultNamespaceDecl(
                LOC((yyloc)), ParseConstants::ns_function_default, SYMTAB((yysemantic_stack_[(5) - (5)].sval))
            );
        }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 1373 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OptionDecl(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval))
            );
        }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 1383 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
        }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 1391 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OrderingModeDecl(
                LOC((yyloc)), StaticContextConsts::ordered
            );
        }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 1397 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OrderingModeDecl(
                LOC((yyloc)), StaticContextConsts::unordered
            );
        }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 1408 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new EmptyOrderDecl( LOC((yyloc)),
                                StaticContextConsts::empty_greatest);
        }
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 1413 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new EmptyOrderDecl( LOC((yyloc)),
                                StaticContextConsts::empty_least);
        }
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 1423 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::preserve_ns,
                                StaticContextConsts::inherit_ns);
        }
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 1429 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::preserve_ns,
                                StaticContextConsts::no_inherit_ns);
        }
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 1435 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::no_preserve_ns,
                                StaticContextConsts::inherit_ns);
        }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 1441 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::no_preserve_ns,
                                StaticContextConsts::no_inherit_ns);
        }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 1458 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
        }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 1466 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 1474 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
        }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 1478 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 1487 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 1496 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 1509 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            URILiteralList *ull = new URILiteralList( LOC((yyloc)));
            ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.node) = ull;
        }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 1515 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
                ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 1526 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 1530 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
        }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 1538 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 1543 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 1548 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 1555 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(8) - (4)].sval)),
                            SYMTAB((yysemantic_stack_[(8) - (6)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(8) - (8)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(8) - (2)].sval)));
    }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 1568 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
        }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 1575 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            CtxItemDecl *d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
            d->type = (yysemantic_stack_[(3) - (2)].node);
            (yyval.node) = d;
        }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 1581 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 1588 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            CtxItemDecl *d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
            d->ext = false;
            (yyval.node) = d;
        }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 1594 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CtxItemDecl( LOC((yyloc)), NULL );
        }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 1598 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 1605 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CtxItemDecl( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 1616 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)), NULL, NULL);
      dynamic_cast<VarNameAndType*>((yyval.varnametype))->setComment(SYMTAB((yysemantic_stack_[(4) - (1)].sval)));
    }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 1621 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)), NULL);
      dynamic_cast<VarNameAndType*>((yyval.varnametype))->setComment(SYMTAB((yysemantic_stack_[(5) - (1)].sval)));
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 1626 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (5)].expr)), NULL, static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (2)].node)));
      dynamic_cast<VarNameAndType*>((yyval.varnametype))->setComment(SYMTAB((yysemantic_stack_[(5) - (1)].sval)));
    }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 1631 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (5)].expr)), dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)), static_cast<AnnotationListParsenode*>((yysemantic_stack_[(6) - (2)].node)));
      dynamic_cast<VarNameAndType*>((yyval.varnametype))->setComment(SYMTAB((yysemantic_stack_[(6) - (1)].sval)));
    }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 1640 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(3) - (1)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, (yysemantic_stack_[(3) - (3)].expr), nt->get_annotations());
      dynamic_cast<VarDecl*>((yyval.node))->setComment(nt->getCommentString());
    }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 1646 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(2) - (1)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, NULL, nt->get_annotations(), true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(nt->getCommentString());
    }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 1652 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(4) - (1)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, (yysemantic_stack_[(4) - (4)].expr), nt->get_annotations(), true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(nt->getCommentString());
    }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 1661 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            DeclPropertyList *dpl = new DeclPropertyList( LOC((yyloc)) );
            dpl->addProperty(dynamic_cast<DeclProperty*>((yysemantic_stack_[(1) - (1)].node)));
            (yyval.node) = dpl;
        }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 1667 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
        DeclPropertyList *dpl = dynamic_cast<DeclPropertyList*>((yysemantic_stack_[(2) - (1)].node));
        dpl->addProperty( static_cast<DeclProperty*>((yysemantic_stack_[(2) - (2)].node)) );
        (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 1676 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_const );
        }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 1680 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_append_only
            );
        }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 1686 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_queue );
        }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 1690 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_mutable );
        }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 1694 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_ordered );
        }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 1698 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_unordered
            );
        }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 1704 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_value_equality
            );
        }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 1710 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_value_range
            );
        }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 1716 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_general_equality
            );
        }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 1722 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_general_range
            );
        }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 1728 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_unique );
        }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 1732 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_non_unique
            );
        }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 1738 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_automatic
            );
        }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 1744 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_manual );
        }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 1751 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)),
                              NULL,
                              NULL,
                              NULL);
    }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 1759 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              NULL,
                              static_cast<NodeModifier*>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 1767 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                              NULL,
                              NULL,
                              static_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 1775 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                              NULL,
                              static_cast<NodeModifier*>((yysemantic_stack_[(6) - (6)].node)),
                              static_cast<SequenceType*>((yysemantic_stack_[(6) - (5)].node)));
    }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 1783 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 1795 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 1809 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 1823 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 1840 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 1844 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 1853 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier(LOC((yyloc)), StaticContextConsts::read_only);
    }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 1857 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier(LOC((yyloc)), StaticContextConsts::mutable_node);
    }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 1864 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AST_IndexDecl(LOC((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(8) - (3)].expr)),
                             (yysemantic_stack_[(8) - (6)].expr),
                             dynamic_cast<IndexKeyList*>((yysemantic_stack_[(8) - (8)].node)),
                             NULL);
    }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 1872 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 1890 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1896 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 1904 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 1909 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 1916 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 1923 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 1934 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollSimpleCheck(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (9)].expr)),
                                 (yysemantic_stack_[(11) - (11)].expr));
    }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 1944 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollUniqueKeyCheck(LOC((yyloc)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (4)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (7)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (10)].expr)),
                                    (yysemantic_stack_[(14) - (14)].expr));
    }
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 1954 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollForeachNode(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (11)].expr)),
                                 (yysemantic_stack_[(13) - (13)].expr));
    }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 1965 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 1980 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ConstructionDecl(
                LOC((yyloc)), StaticContextConsts::cons_preserve
            );
        }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 1986 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ConstructionDecl(
                LOC((yyloc)), StaticContextConsts::cons_strip
            );
        }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 1997 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( NULL );
        }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 2001 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 2005 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)) );
        }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 2009 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 157:

/* Line 678 of lalr1.cc  */
#line 2016 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(2) - (2)].expr);
        }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 2023 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2042 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2051 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 2058 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vfo = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node));
            vfo->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = vfo;
        }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 2064 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vfo = new VFO_DeclList( LOC((yyloc)) );
            vfo->push_back((yysemantic_stack_[(2) - (2)].node));
            (yyval.node) = vfo;
        }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 2074 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      VarDecl* vd = new VarDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL, NULL);
      vd->set_global(false);
      (yyval.node) = vd;
    }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 2080 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      VarDecl* vd = new VarDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)), NULL, NULL);

      vd->set_global(false);
      (yyval.node) = vd;
    }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 2087 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      VarDecl* vd = new VarDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)), NULL, (yysemantic_stack_[(4) - (4)].expr), NULL);
      vd->set_global(false);
      (yyval.node) = vd;
    }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 2093 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      VarDecl* vd = new VarDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (3)].node)), (yysemantic_stack_[(5) - (5)].expr), NULL);
      vd->set_global(false);
      (yyval.node) = vd;
    }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 2103 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 2110 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExitExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 2117 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2129 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::BREAK );
        }
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 2133 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
        }
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 2141 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnnotationListParsenode( LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
        }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 2145 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 2153 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnnotationParsenode( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
        }
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 2157 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnnotationParsenode( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))), static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
        }
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 2164 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnnotationLiteralListParsenode( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
        }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 2168 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 2176 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 2181 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node))->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );
            static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node))->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
            (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
        }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 2190 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 2194 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 182:

/* Line 678 of lalr1.cc  */
#line 2198 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 2202 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 2210 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2221 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2236 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2247 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2262 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2273 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2289 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            ParamList *pl = new ParamList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 191:

/* Line 678 of lalr1.cc  */
#line 2295 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
                pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 192:

/* Line 678 of lalr1.cc  */
#line 2307 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 193:

/* Line 678 of lalr1.cc  */
#line 2311 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 2322 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new EnclosedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 2329 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 2337 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QueryBody( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 2352 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 2356 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            auto_ptr<BlockBody> blk( dynamic_cast<BlockBody*>((yysemantic_stack_[(2) - (2)].expr)) );
            BlockBody *blk2 = new BlockBody( LOC((yyloc)) );
            blk2->add( (yysemantic_stack_[(2) - (1)].expr) );

            for ( int i = 0; i < blk->size(); ++i )
                blk2->add( (*blk)[i] );

            (yyval.expr) = blk2;
        }
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 2370 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new BlockBody( LOC((yyloc)) );
        }
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 2374 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            BlockBody *bb = dynamic_cast<BlockBody*>((yysemantic_stack_[(3) - (1)].expr));
            bb->add( (yysemantic_stack_[(3) - (2)].expr) );
            (yyval.expr) = bb;
        }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 2383 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 2387 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2442 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2457 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 2464 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_sliding;
        }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 2468 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_tumbling;
        }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 2475 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_start;
        }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 2479 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_end;
        }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 2483 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_only_end;
        }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 2490 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FLWORWinCond(
                LOC((yyloc)),
                dynamic_cast<WindowVars*>((yysemantic_stack_[(4) - (2)].node)), (yysemantic_stack_[(4) - (4)].expr),
                (yysemantic_stack_[(4) - (1)].strval) == parser::the_start, (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end
            );
        }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 2498 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FLWORWinCond(
                LOC((yyloc)), NULL, (yysemantic_stack_[(3) - (3)].expr),
                (yysemantic_stack_[(3) - (1)].strval) == parser::the_start, (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end
            );
        }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 2509 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2519 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2532 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 2554 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
            fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = fcl;
        }
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 2560 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
            fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = fcl;
        }
    break;

  case 243:

/* Line 678 of lalr1.cc  */
#line 2570 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
        }
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 2578 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            VarInDeclList *vdl = new VarInDeclList( LOC((yyloc)) );
            vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vdl;
        }
    break;

  case 245:

/* Line 678 of lalr1.cc  */
#line 2584 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( VarInDeclList *vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 2596 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 2600 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)), NULL, NULL, NULL, (yysemantic_stack_[(5) - (5)].expr), true);
    }
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 2604 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)), dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)), NULL, NULL, (yysemantic_stack_[(4) - (4)].expr), false);
    }
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 2608 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (1)].expr)), dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (2)].node)), NULL, NULL, (yysemantic_stack_[(6) - (6)].expr), true);
    }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 2612 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)), NULL, dynamic_cast<PositionalVar*>((yysemantic_stack_[(4) - (2)].node)), NULL, (yysemantic_stack_[(4) - (4)].expr), false);
    }
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 2616 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (1)].expr)), NULL, dynamic_cast<PositionalVar*>((yysemantic_stack_[(6) - (4)].node)), NULL, (yysemantic_stack_[(6) - (6)].expr), true);
    }
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 2620 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (3)].node)), NULL, (yysemantic_stack_[(5) - (5)].expr), false);
    }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 2625 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(7) - (1)].expr)), dynamic_cast<SequenceType *>((yysemantic_stack_[(7) - (2)].node)),
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(7) - (5)].node)), NULL, (yysemantic_stack_[(7) - (7)].expr), true);
    }
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 2631 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2640 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2650 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2660 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2676 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 2685 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
    }
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 2695 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (3)].node)) );
        }
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 2703 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 2709 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 2718 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 2724 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 2733 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)),
                           NULL, NULL,
                           new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr))),
                           VarGetsDecl::eval_var);
    }
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 2747 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)),
                           NULL,
                           NULL,
                           (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 2755 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                           NULL,
                           (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 2765 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                           NULL,
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
                           (yysemantic_stack_[(4) - (4)].expr));
     }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 2773 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
                           (yysemantic_stack_[(5) - (5)].expr));
     }
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 2785 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 2791 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 2804 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 2808 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 2816 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 2820 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 2829 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 2833 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 2837 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 2847 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 2855 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 2862 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = new GroupSpecList( LOC((yyloc)) );
            gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 2868 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
            if ( gsl )
                gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 2879 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 2883 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                         dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 2892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 2900 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 2906 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 2916 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 2922 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 2932 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 2936 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 2946 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 2952 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 2958 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 2964 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2973 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2982 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 2991 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 3004 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 3008 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 3016 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 3022 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 3032 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 3040 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 3049 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 3062 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 3069 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 3081 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 3085 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 3097 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 3104 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 3110 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 3119 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 3126 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 3132 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 3144 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 3151 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 3164 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 3170 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 3182 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 3188 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 3200 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 3209 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 3213 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 3222 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 3226 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 3234 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 3238 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 3248 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 3255 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 3264 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 3273 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 3278 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 3287 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 3296 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 3305 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 3318 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 3322 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 3334 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 3338 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 3345 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 3349 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 3358 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 3362 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 3366 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 3375 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 3379 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 3385 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 3391 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 3397 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 3408 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 3412 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 3416 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 3424 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 3428 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 3434 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 3444 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 3448 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 3458 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 3462 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 3472 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 3476 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 3486 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 3490 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 3500 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 3504 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 3512 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 3516 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 3520 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 3524 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 3534 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 3538 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 3542 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 3550 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 3554 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 3558 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 3562 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 3566 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 3570 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 3578 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 3582 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 3586 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 3594 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 3598 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 3602 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 3606 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 3617 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 3623 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 3633 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 3639 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 3649 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 3653 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 3692 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new PathExpr(LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
    }
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 3696 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, NULL, (yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slash,
                        rpe);
    }
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 3706 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, NULL, (yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slashslash,
                        rpe);
    }
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 3716 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = (!rpe ?
            (yysemantic_stack_[(1) - (1)].expr) :
            new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 3730 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 3740 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 401:

/* Line 678 of lalr1.cc  */
#line 3750 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 3754 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 3764 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 3768 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 3777 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 3783 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 3791 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 3797 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 3809 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 3815 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 3825 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 3829 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 3833 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 3837 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 3841 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 3847 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 3853 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 3876 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 3880 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 3888 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 3892 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 3903 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 3907 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 3911 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 3917 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 3921 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 3935 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 3939 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 3947 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 3951 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 3961 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all);
    }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 3965 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem);
    }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 3969 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix);
    }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 3978 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 3982 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 3986 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
     }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 3990 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
     }
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 3998 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 4004 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 4014 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 4022 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 4026 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 4030 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 4034 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 4038 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 4042 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 4046 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 4050 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 4054 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 4062 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 4066 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 4074 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 4081 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 4088 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 4099 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 4107 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 4111 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 4119 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 4127 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 4135 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 4189 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
        }
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 4193 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 4206 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            ArgList *al = new ArgList( LOC((yyloc)) );
            al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
            (yyval.node) = al;
        }
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 4212 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
                al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 4222 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 4226 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 4234 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 4238 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 4242 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 4250 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 471:

/* Line 678 of lalr1.cc  */
#line 4260 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 472:

/* Line 678 of lalr1.cc  */
#line 4270 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 473:

/* Line 678 of lalr1.cc  */
#line 4280 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 474:

/* Line 678 of lalr1.cc  */
#line 4290 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 475:

/* Line 678 of lalr1.cc  */
#line 4300 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 476:

/* Line 678 of lalr1.cc  */
#line 4315 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
            decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = decl;
        }
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 4321 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( decl )
                decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 4332 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
            dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = dal;
        }
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 4338 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
            if ( dal )
                dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 4349 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttr(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node))
            );
        }
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 4366 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 4371 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 4380 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
        }
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 4384 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 4391 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = qacl;
        }
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 4397 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = qacl;
        }
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 4403 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 4411 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 4423 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
        }
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 4427 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 4434 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = aacl;
        }
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 4440 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = aacl;
        }
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 4446 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if (aacl)
                aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 4453 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( aacl )
                aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 4464 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 4468 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 4478 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 4482 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 4492 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 4496 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 4500 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
        }
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 4505 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
        }
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 4514 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval))
            );
        }
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 4520 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_lbrace
            );
        }
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 4526 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_rbrace
            );
        }
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 4532 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 509:

/* Line 678 of lalr1.cc  */
#line 4542 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 510:

/* Line 678 of lalr1.cc  */
#line 4546 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
        }
    break;

  case 511:

/* Line 678 of lalr1.cc  */
#line 4558 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 512:

/* Line 678 of lalr1.cc  */
#line 4562 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 4574 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 4586 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 4590 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 4594 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 4598 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 4602 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 4606 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 4614 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 521:

/* Line 678 of lalr1.cc  */
#line 4622 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (1)].sval))), NULL);
        }
    break;

  case 522:

/* Line 678 of lalr1.cc  */
#line 4626 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
        }
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 4630 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 4634 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 4651 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (1)].sval))), NULL );
        }
    break;

  case 526:

/* Line 678 of lalr1.cc  */
#line 4655 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 4659 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 4663 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 4671 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 4679 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 4687 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (1)].sval)), NULL );
        }
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 4691 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 4695 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 534:

/* Line 678 of lalr1.cc  */
#line 4699 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 4707 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)), false
            );
        }
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 4713 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)), true
            );
        }
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 4723 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 4731 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 4735 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 4739 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 4774 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 542:

/* Line 678 of lalr1.cc  */
#line 4780 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 543:

/* Line 678 of lalr1.cc  */
#line 4786 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 544:

/* Line 678 of lalr1.cc  */
#line 4796 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 4800 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 4804 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)),true );
        }
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 4808 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 4812 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 549:

/* Line 678 of lalr1.cc  */
#line 4819 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 550:

/* Line 678 of lalr1.cc  */
#line 4825 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 4835 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 4843 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 4847 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 4851 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 555:

/* Line 678 of lalr1.cc  */
#line 4855 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 556:

/* Line 678 of lalr1.cc  */
#line 4859 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 557:

/* Line 678 of lalr1.cc  */
#line 4863 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 558:

/* Line 678 of lalr1.cc  */
#line 4867 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 559:

/* Line 678 of lalr1.cc  */
#line 4871 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 560:

/* Line 678 of lalr1.cc  */
#line 4875 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 561:

/* Line 678 of lalr1.cc  */
#line 4883 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyKindTest( LOC((yyloc)) );
        }
    break;

  case 562:

/* Line 678 of lalr1.cc  */
#line 4891 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)) );
        }
    break;

  case 563:

/* Line 678 of lalr1.cc  */
#line 4895 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)) );
        }
    break;

  case 564:

/* Line 678 of lalr1.cc  */
#line 4899 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest(
                LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 565:

/* Line 678 of lalr1.cc  */
#line 4909 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TextTest( LOC((yyloc)) );
        }
    break;

  case 566:

/* Line 678 of lalr1.cc  */
#line 4917 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CommentTest( LOC((yyloc)));
        }
    break;

  case 567:

/* Line 678 of lalr1.cc  */
#line 4925 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 568:

/* Line 678 of lalr1.cc  */
#line 4929 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 569:

/* Line 678 of lalr1.cc  */
#line 4933 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 570:

/* Line 678 of lalr1.cc  */
#line 4941 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 571:

/* Line 678 of lalr1.cc  */
#line 4945 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 572:

/* Line 678 of lalr1.cc  */
#line 4951 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 573:

/* Line 678 of lalr1.cc  */
#line 4957 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 574:

/* Line 678 of lalr1.cc  */
#line 4961 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 575:

/* Line 678 of lalr1.cc  */
#line 4971 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 576:

/* Line 678 of lalr1.cc  */
#line 4979 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 577:

/* Line 678 of lalr1.cc  */
#line 4983 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 578:

/* Line 678 of lalr1.cc  */
#line 4989 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 579:

/* Line 678 of lalr1.cc  */
#line 4998 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 580:

/* Line 678 of lalr1.cc  */
#line 5007 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 581:

/* Line 678 of lalr1.cc  */
#line 5013 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 582:

/* Line 678 of lalr1.cc  */
#line 5019 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 583:

/* Line 678 of lalr1.cc  */
#line 5029 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 584:

/* Line 678 of lalr1.cc  */
#line 5046 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 585:

/* Line 678 of lalr1.cc  */
#line 5053 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 586:

/* Line 678 of lalr1.cc  */
#line 5068 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 587:

/* Line 678 of lalr1.cc  */
#line 5104 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 588:

/* Line 678 of lalr1.cc  */
#line 5108 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 589:

/* Line 678 of lalr1.cc  */
#line 5117 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
        }
    break;

  case 590:

/* Line 678 of lalr1.cc  */
#line 5126 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new InlineFunction(LOC ((yyloc)), &*(yysemantic_stack_[(3) - (2)].fnsig)->param, &*(yysemantic_stack_[(3) - (2)].fnsig)->ret, dynamic_cast<EnclosedExpr *>((yysemantic_stack_[(3) - (3)].expr)));
          delete (yysemantic_stack_[(3) - (2)].fnsig);
        }
    break;

  case 591:

/* Line 678 of lalr1.cc  */
#line 5136 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 592:

/* Line 678 of lalr1.cc  */
#line 5140 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 593:

/* Line 678 of lalr1.cc  */
#line 5149 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
        }
    break;

  case 594:

/* Line 678 of lalr1.cc  */
#line 5158 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 595:

/* Line 678 of lalr1.cc  */
#line 5162 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 596:

/* Line 678 of lalr1.cc  */
#line 5173 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 597:

/* Line 678 of lalr1.cc  */
#line 5190 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 598:

/* Line 678 of lalr1.cc  */
#line 5196 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 599:

/* Line 678 of lalr1.cc  */
#line 5202 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 600:

/* Line 678 of lalr1.cc  */
#line 5212 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 601:

/* Line 678 of lalr1.cc  */
#line 5216 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 602:

/* Line 678 of lalr1.cc  */
#line 5222 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 603:

/* Line 678 of lalr1.cc  */
#line 5228 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 604:

/* Line 678 of lalr1.cc  */
#line 5232 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 605:

/* Line 678 of lalr1.cc  */
#line 5238 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 606:

/* Line 678 of lalr1.cc  */
#line 5242 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 607:

/* Line 678 of lalr1.cc  */
#line 5248 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 608:

/* Line 678 of lalr1.cc  */
#line 5254 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 609:

/* Line 678 of lalr1.cc  */
#line 5261 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 610:

/* Line 678 of lalr1.cc  */
#line 5271 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 611:

/* Line 678 of lalr1.cc  */
#line 5276 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 612:

/* Line 678 of lalr1.cc  */
#line 5284 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 613:

/* Line 678 of lalr1.cc  */
#line 5290 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 614:

/* Line 678 of lalr1.cc  */
#line 5300 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 615:

/* Line 678 of lalr1.cc  */
#line 5322 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 616:

/* Line 678 of lalr1.cc  */
#line 5331 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 617:

/* Line 678 of lalr1.cc  */
#line 5337 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 618:

/* Line 678 of lalr1.cc  */
#line 5350 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 619:

/* Line 678 of lalr1.cc  */
#line 5364 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 620:

/* Line 678 of lalr1.cc  */
#line 5371 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 621:

/* Line 678 of lalr1.cc  */
#line 5377 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 622:

/* Line 678 of lalr1.cc  */
#line 5387 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 623:

/* Line 678 of lalr1.cc  */
#line 5392 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CatchExpr(LOC((yyloc)),*(yysemantic_stack_[(7) - (2)].name_test_list), static_cast<QName*>((yysemantic_stack_[(7) - (5)].expr)), NULL, NULL, (yysemantic_stack_[(7) - (7)].expr));
       delete (yysemantic_stack_[(7) - (2)].name_test_list);
    }
    break;

  case 624:

/* Line 678 of lalr1.cc  */
#line 5397 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 625:

/* Line 678 of lalr1.cc  */
#line 5407 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

  case 626:

/* Line 678 of lalr1.cc  */
#line 5420 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 627:

/* Line 678 of lalr1.cc  */
#line 5426 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 628:

/* Line 678 of lalr1.cc  */
#line 5443 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new EvalExpr(LOC((yyloc)), dynamic_cast<VarGetsDeclList *> ((yysemantic_stack_[(7) - (3)].node)), (yysemantic_stack_[(7) - (6)].expr));
        }
    break;

  case 629:

/* Line 678 of lalr1.cc  */
#line 5447 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new EvalExpr( LOC((yyloc)), new VarGetsDeclList( LOC((yyloc)) ), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 630:

/* Line 678 of lalr1.cc  */
#line 5462 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 631:

/* Line 678 of lalr1.cc  */
#line 5470 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 632:

/* Line 678 of lalr1.cc  */
#line 5474 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 633:

/* Line 678 of lalr1.cc  */
#line 5481 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 634:

/* Line 678 of lalr1.cc  */
#line 5486 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 635:

/* Line 678 of lalr1.cc  */
#line 5494 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 636:

/* Line 678 of lalr1.cc  */
#line 5498 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 637:

/* Line 678 of lalr1.cc  */
#line 5505 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 638:

/* Line 678 of lalr1.cc  */
#line 5509 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 639:

/* Line 678 of lalr1.cc  */
#line 5516 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 640:

/* Line 678 of lalr1.cc  */
#line 5520 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 641:

/* Line 678 of lalr1.cc  */
#line 5527 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 642:

/* Line 678 of lalr1.cc  */
#line 5531 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 643:

/* Line 678 of lalr1.cc  */
#line 5540 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 5552 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 645:

/* Line 678 of lalr1.cc  */
#line 5556 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 646:

/* Line 678 of lalr1.cc  */
#line 5563 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 647:

/* Line 678 of lalr1.cc  */
#line 5567 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 648:

/* Line 678 of lalr1.cc  */
#line 5575 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 649:

/* Line 678 of lalr1.cc  */
#line 5583 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 650:

/* Line 678 of lalr1.cc  */
#line 5591 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 651:

/* Line 678 of lalr1.cc  */
#line 5595 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 652:

/* Line 678 of lalr1.cc  */
#line 5602 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 653:

/* Line 678 of lalr1.cc  */
#line 5606 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 654:

/* Line 678 of lalr1.cc  */
#line 5614 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 655:

/* Line 678 of lalr1.cc  */
#line 5625 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 656:

/* Line 678 of lalr1.cc  */
#line 5629 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 657:

/* Line 678 of lalr1.cc  */
#line 5637 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 658:

/* Line 678 of lalr1.cc  */
#line 5649 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 659:

/* Line 678 of lalr1.cc  */
#line 5655 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 660:

/* Line 678 of lalr1.cc  */
#line 5664 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 661:

/* Line 678 of lalr1.cc  */
#line 5668 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 662:

/* Line 678 of lalr1.cc  */
#line 5676 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 663:

/* Line 678 of lalr1.cc  */
#line 5680 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 664:

/* Line 678 of lalr1.cc  */
#line 5684 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 665:

/* Line 678 of lalr1.cc  */
#line 5691 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 666:

/* Line 678 of lalr1.cc  */
#line 5695 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 667:

/* Line 678 of lalr1.cc  */
#line 5702 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 668:

/* Line 678 of lalr1.cc  */
#line 5706 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 669:

/* Line 678 of lalr1.cc  */
#line 5714 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 670:

/* Line 678 of lalr1.cc  */
#line 5718 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 671:

/* Line 678 of lalr1.cc  */
#line 5722 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 672:

/* Line 678 of lalr1.cc  */
#line 5726 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 673:

/* Line 678 of lalr1.cc  */
#line 5730 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 674:

/* Line 678 of lalr1.cc  */
#line 5738 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 675:

/* Line 678 of lalr1.cc  */
#line 5746 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 676:

/* Line 678 of lalr1.cc  */
#line 5758 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 677:

/* Line 678 of lalr1.cc  */
#line 5770 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 678:

/* Line 678 of lalr1.cc  */
#line 5774 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 679:

/* Line 678 of lalr1.cc  */
#line 5778 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 680:

/* Line 678 of lalr1.cc  */
#line 5786 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 681:

/* Line 678 of lalr1.cc  */
#line 5792 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 682:

/* Line 678 of lalr1.cc  */
#line 5802 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 683:

/* Line 678 of lalr1.cc  */
#line 5806 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 684:

/* Line 678 of lalr1.cc  */
#line 5810 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 685:

/* Line 678 of lalr1.cc  */
#line 5814 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 686:

/* Line 678 of lalr1.cc  */
#line 5818 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 687:

/* Line 678 of lalr1.cc  */
#line 5822 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 688:

/* Line 678 of lalr1.cc  */
#line 5826 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 689:

/* Line 678 of lalr1.cc  */
#line 5830 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 690:

/* Line 678 of lalr1.cc  */
#line 5838 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 691:

/* Line 678 of lalr1.cc  */
#line 5842 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 692:

/* Line 678 of lalr1.cc  */
#line 5846 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 693:

/* Line 678 of lalr1.cc  */
#line 5850 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 694:

/* Line 678 of lalr1.cc  */
#line 5858 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 695:

/* Line 678 of lalr1.cc  */
#line 5864 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 696:

/* Line 678 of lalr1.cc  */
#line 5874 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 697:

/* Line 678 of lalr1.cc  */
#line 5884 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::with );
        }
    break;

  case 698:

/* Line 678 of lalr1.cc  */
#line 5888 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::without );
        }
    break;

  case 699:

/* Line 678 of lalr1.cc  */
#line 5896 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 5906 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 5917 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 702:

/* Line 678 of lalr1.cc  */
#line 5924 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 703:

/* Line 678 of lalr1.cc  */
#line 5928 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 704:

/* Line 678 of lalr1.cc  */
#line 5935 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 705:

/* Line 678 of lalr1.cc  */
#line 5939 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(1) - (1)].thesaurus_id_list);
        }
    break;

  case 706:

/* Line 678 of lalr1.cc  */
#line 5946 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 707:

/* Line 678 of lalr1.cc  */
#line 5951 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 708:

/* Line 678 of lalr1.cc  */
#line 5960 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 709:

/* Line 678 of lalr1.cc  */
#line 5969 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = NULL;
        }
    break;

  case 710:

/* Line 678 of lalr1.cc  */
#line 5973 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 711:

/* Line 678 of lalr1.cc  */
#line 5980 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 712:

/* Line 678 of lalr1.cc  */
#line 5984 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 713:

/* Line 678 of lalr1.cc  */
#line 5992 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 6001 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 715:

/* Line 678 of lalr1.cc  */
#line 6008 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 716:

/* Line 678 of lalr1.cc  */
#line 6018 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 717:

/* Line 678 of lalr1.cc  */
#line 6022 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 718:

/* Line 678 of lalr1.cc  */
#line 6029 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 719:

/* Line 678 of lalr1.cc  */
#line 6035 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 720:

/* Line 678 of lalr1.cc  */
#line 6044 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 721:

/* Line 678 of lalr1.cc  */
#line 6048 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 722:

/* Line 678 of lalr1.cc  */
#line 6055 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 723:

/* Line 678 of lalr1.cc  */
#line 6060 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 724:

/* Line 678 of lalr1.cc  */
#line 6072 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 725:

/* Line 678 of lalr1.cc  */
#line 6080 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 726:

/* Line 678 of lalr1.cc  */
#line 6092 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 727:

/* Line 678 of lalr1.cc  */
#line 6100 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 728:

/* Line 678 of lalr1.cc  */
#line 6104 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 729:

/* Line 678 of lalr1.cc  */
#line 6112 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 730:

/* Line 678 of lalr1.cc  */
#line 6116 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 731:

/* Line 678 of lalr1.cc  */
#line 6120 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 732:

/* Line 678 of lalr1.cc  */
#line 6128 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 733:

/* Line 678 of lalr1.cc  */
#line 6136 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 734:

/* Line 678 of lalr1.cc  */
#line 6140 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 735:

/* Line 678 of lalr1.cc  */
#line 6144 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 736:

/* Line 678 of lalr1.cc  */
#line 6148 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 737:

/* Line 678 of lalr1.cc  */
#line 6156 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 738:

/* Line 678 of lalr1.cc  */
#line 6164 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 739:

/* Line 678 of lalr1.cc  */
#line 6176 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 740:

/* Line 678 of lalr1.cc  */
#line 6180 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 741:

/* Line 678 of lalr1.cc  */
#line 6188 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 744:

/* Line 678 of lalr1.cc  */
#line 6206 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 6219 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 747:

/* Line 678 of lalr1.cc  */
#line 6220 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 748:

/* Line 678 of lalr1.cc  */
#line 6221 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 749:

/* Line 678 of lalr1.cc  */
#line 6222 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 750:

/* Line 678 of lalr1.cc  */
#line 6223 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 751:

/* Line 678 of lalr1.cc  */
#line 6224 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 752:

/* Line 678 of lalr1.cc  */
#line 6225 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 753:

/* Line 678 of lalr1.cc  */
#line 6226 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 754:

/* Line 678 of lalr1.cc  */
#line 6227 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 755:

/* Line 678 of lalr1.cc  */
#line 6228 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 756:

/* Line 678 of lalr1.cc  */
#line 6229 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 757:

/* Line 678 of lalr1.cc  */
#line 6230 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 758:

/* Line 678 of lalr1.cc  */
#line 6231 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 759:

/* Line 678 of lalr1.cc  */
#line 6232 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 760:

/* Line 678 of lalr1.cc  */
#line 6233 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 761:

/* Line 678 of lalr1.cc  */
#line 6237 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 762:

/* Line 678 of lalr1.cc  */
#line 6238 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 763:

/* Line 678 of lalr1.cc  */
#line 6239 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 764:

/* Line 678 of lalr1.cc  */
#line 6240 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 765:

/* Line 678 of lalr1.cc  */
#line 6241 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 766:

/* Line 678 of lalr1.cc  */
#line 6242 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 767:

/* Line 678 of lalr1.cc  */
#line 6243 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 768:

/* Line 678 of lalr1.cc  */
#line 6244 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 769:

/* Line 678 of lalr1.cc  */
#line 6245 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 770:

/* Line 678 of lalr1.cc  */
#line 6246 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 771:

/* Line 678 of lalr1.cc  */
#line 6247 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 772:

/* Line 678 of lalr1.cc  */
#line 6248 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 773:

/* Line 678 of lalr1.cc  */
#line 6249 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 774:

/* Line 678 of lalr1.cc  */
#line 6250 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 775:

/* Line 678 of lalr1.cc  */
#line 6251 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 776:

/* Line 678 of lalr1.cc  */
#line 6252 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 777:

/* Line 678 of lalr1.cc  */
#line 6253 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 778:

/* Line 678 of lalr1.cc  */
#line 6254 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 779:

/* Line 678 of lalr1.cc  */
#line 6255 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 780:

/* Line 678 of lalr1.cc  */
#line 6256 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 781:

/* Line 678 of lalr1.cc  */
#line 6257 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 782:

/* Line 678 of lalr1.cc  */
#line 6258 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 783:

/* Line 678 of lalr1.cc  */
#line 6259 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 784:

/* Line 678 of lalr1.cc  */
#line 6260 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 785:

/* Line 678 of lalr1.cc  */
#line 6261 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 786:

/* Line 678 of lalr1.cc  */
#line 6262 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 787:

/* Line 678 of lalr1.cc  */
#line 6263 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 788:

/* Line 678 of lalr1.cc  */
#line 6264 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 789:

/* Line 678 of lalr1.cc  */
#line 6265 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 790:

/* Line 678 of lalr1.cc  */
#line 6266 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 791:

/* Line 678 of lalr1.cc  */
#line 6267 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 792:

/* Line 678 of lalr1.cc  */
#line 6268 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 793:

/* Line 678 of lalr1.cc  */
#line 6269 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 794:

/* Line 678 of lalr1.cc  */
#line 6270 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 795:

/* Line 678 of lalr1.cc  */
#line 6271 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 796:

/* Line 678 of lalr1.cc  */
#line 6272 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 797:

/* Line 678 of lalr1.cc  */
#line 6273 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 798:

/* Line 678 of lalr1.cc  */
#line 6274 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 799:

/* Line 678 of lalr1.cc  */
#line 6275 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 800:

/* Line 678 of lalr1.cc  */
#line 6276 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 801:

/* Line 678 of lalr1.cc  */
#line 6277 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 802:

/* Line 678 of lalr1.cc  */
#line 6278 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 803:

/* Line 678 of lalr1.cc  */
#line 6279 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 804:

/* Line 678 of lalr1.cc  */
#line 6280 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 805:

/* Line 678 of lalr1.cc  */
#line 6281 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 806:

/* Line 678 of lalr1.cc  */
#line 6282 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 807:

/* Line 678 of lalr1.cc  */
#line 6283 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 808:

/* Line 678 of lalr1.cc  */
#line 6284 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 809:

/* Line 678 of lalr1.cc  */
#line 6285 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 810:

/* Line 678 of lalr1.cc  */
#line 6286 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 811:

/* Line 678 of lalr1.cc  */
#line 6287 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 812:

/* Line 678 of lalr1.cc  */
#line 6288 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 813:

/* Line 678 of lalr1.cc  */
#line 6289 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 814:

/* Line 678 of lalr1.cc  */
#line 6290 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 815:

/* Line 678 of lalr1.cc  */
#line 6291 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 816:

/* Line 678 of lalr1.cc  */
#line 6292 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 817:

/* Line 678 of lalr1.cc  */
#line 6293 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 818:

/* Line 678 of lalr1.cc  */
#line 6294 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 819:

/* Line 678 of lalr1.cc  */
#line 6295 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 820:

/* Line 678 of lalr1.cc  */
#line 6296 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 821:

/* Line 678 of lalr1.cc  */
#line 6297 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 822:

/* Line 678 of lalr1.cc  */
#line 6298 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 823:

/* Line 678 of lalr1.cc  */
#line 6299 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 824:

/* Line 678 of lalr1.cc  */
#line 6300 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 825:

/* Line 678 of lalr1.cc  */
#line 6301 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 826:

/* Line 678 of lalr1.cc  */
#line 6302 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 827:

/* Line 678 of lalr1.cc  */
#line 6303 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 828:

/* Line 678 of lalr1.cc  */
#line 6304 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 829:

/* Line 678 of lalr1.cc  */
#line 6305 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 830:

/* Line 678 of lalr1.cc  */
#line 6306 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 831:

/* Line 678 of lalr1.cc  */
#line 6307 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 832:

/* Line 678 of lalr1.cc  */
#line 6308 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 833:

/* Line 678 of lalr1.cc  */
#line 6309 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 834:

/* Line 678 of lalr1.cc  */
#line 6310 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 835:

/* Line 678 of lalr1.cc  */
#line 6311 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 836:

/* Line 678 of lalr1.cc  */
#line 6312 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 837:

/* Line 678 of lalr1.cc  */
#line 6313 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 838:

/* Line 678 of lalr1.cc  */
#line 6314 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 839:

/* Line 678 of lalr1.cc  */
#line 6315 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 840:

/* Line 678 of lalr1.cc  */
#line 6316 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 841:

/* Line 678 of lalr1.cc  */
#line 6317 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 842:

/* Line 678 of lalr1.cc  */
#line 6318 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 843:

/* Line 678 of lalr1.cc  */
#line 6319 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 844:

/* Line 678 of lalr1.cc  */
#line 6320 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 845:

/* Line 678 of lalr1.cc  */
#line 6321 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 846:

/* Line 678 of lalr1.cc  */
#line 6322 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 847:

/* Line 678 of lalr1.cc  */
#line 6323 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 848:

/* Line 678 of lalr1.cc  */
#line 6324 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 849:

/* Line 678 of lalr1.cc  */
#line 6325 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 850:

/* Line 678 of lalr1.cc  */
#line 6326 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 851:

/* Line 678 of lalr1.cc  */
#line 6327 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 852:

/* Line 678 of lalr1.cc  */
#line 6328 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 853:

/* Line 678 of lalr1.cc  */
#line 6329 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 854:

/* Line 678 of lalr1.cc  */
#line 6330 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 855:

/* Line 678 of lalr1.cc  */
#line 6331 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 856:

/* Line 678 of lalr1.cc  */
#line 6332 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 857:

/* Line 678 of lalr1.cc  */
#line 6333 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 858:

/* Line 678 of lalr1.cc  */
#line 6334 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 859:

/* Line 678 of lalr1.cc  */
#line 6335 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 860:

/* Line 678 of lalr1.cc  */
#line 6336 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 861:

/* Line 678 of lalr1.cc  */
#line 6337 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 862:

/* Line 678 of lalr1.cc  */
#line 6338 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 863:

/* Line 678 of lalr1.cc  */
#line 6339 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 864:

/* Line 678 of lalr1.cc  */
#line 6340 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 865:

/* Line 678 of lalr1.cc  */
#line 6341 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 866:

/* Line 678 of lalr1.cc  */
#line 6342 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 867:

/* Line 678 of lalr1.cc  */
#line 6343 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 868:

/* Line 678 of lalr1.cc  */
#line 6344 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 869:

/* Line 678 of lalr1.cc  */
#line 6345 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 870:

/* Line 678 of lalr1.cc  */
#line 6346 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 871:

/* Line 678 of lalr1.cc  */
#line 6347 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 872:

/* Line 678 of lalr1.cc  */
#line 6348 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 873:

/* Line 678 of lalr1.cc  */
#line 6349 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 874:

/* Line 678 of lalr1.cc  */
#line 6350 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 875:

/* Line 678 of lalr1.cc  */
#line 6351 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 876:

/* Line 678 of lalr1.cc  */
#line 6352 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 877:

/* Line 678 of lalr1.cc  */
#line 6353 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 878:

/* Line 678 of lalr1.cc  */
#line 6354 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 879:

/* Line 678 of lalr1.cc  */
#line 6355 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 880:

/* Line 678 of lalr1.cc  */
#line 6356 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 881:

/* Line 678 of lalr1.cc  */
#line 6357 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 882:

/* Line 678 of lalr1.cc  */
#line 6358 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 883:

/* Line 678 of lalr1.cc  */
#line 6359 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 884:

/* Line 678 of lalr1.cc  */
#line 6360 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 885:

/* Line 678 of lalr1.cc  */
#line 6361 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 886:

/* Line 678 of lalr1.cc  */
#line 6362 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 887:

/* Line 678 of lalr1.cc  */
#line 6363 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 888:

/* Line 678 of lalr1.cc  */
#line 6364 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 889:

/* Line 678 of lalr1.cc  */
#line 6365 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 890:

/* Line 678 of lalr1.cc  */
#line 6366 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 891:

/* Line 678 of lalr1.cc  */
#line 6367 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 892:

/* Line 678 of lalr1.cc  */
#line 6368 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 893:

/* Line 678 of lalr1.cc  */
#line 6369 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 894:

/* Line 678 of lalr1.cc  */
#line 6370 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 895:

/* Line 678 of lalr1.cc  */
#line 6371 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 896:

/* Line 678 of lalr1.cc  */
#line 6372 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 897:

/* Line 678 of lalr1.cc  */
#line 6373 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 898:

/* Line 678 of lalr1.cc  */
#line 6374 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 899:

/* Line 678 of lalr1.cc  */
#line 6375 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 900:

/* Line 678 of lalr1.cc  */
#line 6376 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 901:

/* Line 678 of lalr1.cc  */
#line 6377 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 902:

/* Line 678 of lalr1.cc  */
#line 6378 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("deterministic"))); }
    break;

  case 903:

/* Line 678 of lalr1.cc  */
#line 6379 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nondeterministic"))); }
    break;

  case 904:

/* Line 678 of lalr1.cc  */
#line 6380 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 905:

/* Line 678 of lalr1.cc  */
#line 6381 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 906:

/* Line 678 of lalr1.cc  */
#line 6382 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 907:

/* Line 678 of lalr1.cc  */
#line 6383 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("block"))); }
    break;

  case 908:

/* Line 678 of lalr1.cc  */
#line 6384 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 909:

/* Line 678 of lalr1.cc  */
#line 6385 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 910:

/* Line 678 of lalr1.cc  */
#line 6386 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 911:

/* Line 678 of lalr1.cc  */
#line 6387 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 912:

/* Line 678 of lalr1.cc  */
#line 6388 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 913:

/* Line 678 of lalr1.cc  */
#line 6389 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 914:

/* Line 678 of lalr1.cc  */
#line 6390 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eval"))); }
    break;

  case 915:

/* Line 678 of lalr1.cc  */
#line 6391 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 916:

/* Line 678 of lalr1.cc  */
#line 6392 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 917:

/* Line 678 of lalr1.cc  */
#line 6393 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 918:

/* Line 678 of lalr1.cc  */
#line 6394 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 919:

/* Line 678 of lalr1.cc  */
#line 6395 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 920:

/* Line 678 of lalr1.cc  */
#line 6396 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 921:

/* Line 678 of lalr1.cc  */
#line 6397 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 922:

/* Line 678 of lalr1.cc  */
#line 6398 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 923:

/* Line 678 of lalr1.cc  */
#line 6399 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 924:

/* Line 678 of lalr1.cc  */
#line 6400 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 925:

/* Line 678 of lalr1.cc  */
#line 6401 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 926:

/* Line 678 of lalr1.cc  */
#line 6402 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 927:

/* Line 678 of lalr1.cc  */
#line 6403 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 928:

/* Line 678 of lalr1.cc  */
#line 6404 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 929:

/* Line 678 of lalr1.cc  */
#line 6405 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 930:

/* Line 678 of lalr1.cc  */
#line 6406 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 931:

/* Line 678 of lalr1.cc  */
#line 6407 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 932:

/* Line 678 of lalr1.cc  */
#line 6408 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 933:

/* Line 678 of lalr1.cc  */
#line 6409 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 934:

/* Line 678 of lalr1.cc  */
#line 6410 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 935:

/* Line 678 of lalr1.cc  */
#line 6411 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 936:

/* Line 678 of lalr1.cc  */
#line 6412 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 937:

/* Line 678 of lalr1.cc  */
#line 6413 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 938:

/* Line 678 of lalr1.cc  */
#line 6414 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 939:

/* Line 678 of lalr1.cc  */
#line 6415 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 940:

/* Line 678 of lalr1.cc  */
#line 6416 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 941:

/* Line 678 of lalr1.cc  */
#line 6417 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 942:

/* Line 678 of lalr1.cc  */
#line 6418 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 943:

/* Line 678 of lalr1.cc  */
#line 6419 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 944:

/* Line 678 of lalr1.cc  */
#line 6420 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 945:

/* Line 678 of lalr1.cc  */
#line 6421 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 946:

/* Line 678 of lalr1.cc  */
#line 6422 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 947:

/* Line 678 of lalr1.cc  */
#line 6423 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 948:

/* Line 678 of lalr1.cc  */
#line 6424 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 949:

/* Line 678 of lalr1.cc  */
#line 6425 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 950:

/* Line 678 of lalr1.cc  */
#line 6426 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 951:

/* Line 678 of lalr1.cc  */
#line 6427 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 952:

/* Line 678 of lalr1.cc  */
#line 6428 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 953:

/* Line 678 of lalr1.cc  */
#line 6429 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 954:

/* Line 678 of lalr1.cc  */
#line 6430 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 955:

/* Line 678 of lalr1.cc  */
#line 6431 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 956:

/* Line 678 of lalr1.cc  */
#line 6432 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 957:

/* Line 678 of lalr1.cc  */
#line 6433 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 958:

/* Line 678 of lalr1.cc  */
#line 6434 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 959:

/* Line 678 of lalr1.cc  */
#line 6435 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 960:

/* Line 678 of lalr1.cc  */
#line 6436 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;



/* Line 678 of lalr1.cc  */
#line 11520 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1363;
  const short int
  xquery_parser::yypact_[] =
  {
      2341, -1363, -1363,  2637,  2932,  3227, -1363, -1363,  1633,   -23,
   -1363, -1363, -1363,   469, -1363, -1363, -1363, -1363,   -26,   126,
     538,    61,   375,   136,   386,   101, -1363,   208, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363,   544, -1363,   468,   493, -1363,
     229, -1363, -1363,   419, -1363,   546, -1363,   506,   531, -1363,
     188, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363,   464,   512, -1363, -1363, -1363, -1363,
      14,  8537, -1363, -1363, -1363,   560, -1363, -1363, -1363, -1363,
   -1363,   591,   606, -1363, -1363, 11691, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363,   453, -1363, -1363,   611,   613, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363,  3522, 11691, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363,   588, -1363, -1363,   639,  9414,
   -1363,  9703,   645,   655, -1363, -1363, -1363,   656, -1363,  8242,
   -1363, -1363, -1363, -1363, -1363, -1363,   626, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363,    29,   565, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363,   372,   628,   477, -1363,   558,
     444, -1363, -1363, -1363, -1363, -1363, -1363,   666, -1363,   633,
     548,   550,   545, -1363, -1363,   632,   640, -1363,   673, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,  5587,
     790, -1363,  5882, -1363, -1363,   513,    40,    42, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363,   534, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
     -39, -1363, -1363, -1363, -1363,   364, -1363, -1363, -1363, -1363,
   -1363, -1363,   629,   703, -1363,   737,   549,   280,   381,   242,
     171, -1363,   748,   604,   702,   704,  6177, -1363, -1363, -1363,
     236, -1363, -1363,  8242, -1363,   553, -1363,   651,  8537, -1363,
     651,  8537, -1363, -1363, -1363,   552, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,   663,
     653, -1363, -1363, -1363, -1363, -1363,   631, -1363,   634, -1363,
     635,   654,   787,   322,   441,   401, 11975, 11691,   268,   768,
     784,   785, 11691,   684,   718,   522,  9414, -1363, -1363,   458,
     447,   592, 11691, -1363, -1363, -1363, -1363, -1363,   551, 11691,
     541,   543,   450,   539,   430, -1363,   377, -1363, -1363, -1363,
   -1363, -1363,  9414,  6472,   658,  6472,    38,  6472, 10271,  6472,
     562,   564, 11691,   723,   -22,   697,  6472,   100,    85, 11691,
    6472,  9123, 11691, 11691, 11691, 11691,  6472,   664,  6472,  6472,
   11691,  6472,   699,   700, -1363, -1363, -1363,  6472, 10555,   708,
   -1363,   709, -1363, -1363, -1363, -1363, -1363,   710, -1363, -1363,
     714, -1363, -1363, -1363, -1363, -1363,   715, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, 11691, -1363, -1363,
   -1363,   668,   821,  6472, -1363, -1363,    84, -1363, -1363,   838,
   -1363, -1363, -1363, -1363,  6472,   646, -1363,   843,  6472,  6472,
     688,  6472,  6472,  6472,  6472,   649, 11691, -1363, -1363, -1363,
   -1363,  6472,  6472,  6472, 11691, -1363, -1363, -1363, -1363,  1633,
     101,    58,    60,   874,  6767,  6767,  7062,  7062,   740,  6472,
    6472, -1363,  6472,   764,   375,   208,   716,   717,   720,  6472,
    6472, -1363, -1363, -1363, -1363, -1363, -1363, -1363,  7357,  7357,
    7357, -1363,  7357,  7357, -1363,  7357, -1363,  7357, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363,  7357,  7357,   813,  7357,  7357,
    7357,  7357,  7357,  7357,  7357,  7357,  7357,  7357,  7357,   661,
     797,   799,   800, -1363, -1363, -1363,  3817, -1363, -1363,  8242,
    8242,  6472,   651, -1363, -1363,   651, -1363,  4112,   651,   749,
    4407, -1363, -1363, -1363,   270, -1363, -1363, -1363, -1363, -1363,
   -1363,   792,   794,   136,   875, -1363, -1363, 11975, -1363, 11975,
     739,   359, 11691,   747,   750,   739,   787,   781,   777, -1363,
   -1363, -1363, -1363, -1363,    32,   667,   -20, -1363,   615, -1363,
   -1363, -1363, -1363, 11691, 11691, 11691, -1363,   793, -1363, -1363,
     783,   733, -1363,   734,   709,   493, -1363,   732,   738,   742,
   -1363,    -1,    17,   743, -1363, -1363,   815, -1363,     2, 11691,
      -5, 11691,   828,    37, -1363,  6472, -1363,   741,  9414,   831,
     884,  9414,   787,   833,   824, -1363,    -3,   751,   746, -1363,
     759,   761,   762,   795,    -9, -1363,   251,   752, -1363,   766,
     767,   798, -1363,   771,  6472,  6472,   772, -1363,   115,   169,
      -7, -1363, 11691,   821, -1363,   -24,   773, -1363, -1363, -1363,
     774, -1363,     3, -1363, -1363, -1363,   122,   167,   863,   698,
     744,   -37, -1363,   818,  7652, -1363,   775,   779,   111, -1363,
   -1363,   513,   533,   928,   928, -1363,    63, -1363, -1363,    68,
   -1363, -1363,   808, -1363, -1363, -1363, -1363,  6472, -1363, -1363,
     -16, 11691,   802,  6472,   845, -1363, -1363,   703, -1363, -1363,
   -1363, -1363, -1363,  7357, -1363, -1363, -1363,     6,   381,   381,
     418,   242,   242,   242,   242,   171,   171, -1363, -1363, 11123,
   11123, 11691, 11691, -1363,   786, -1363, -1363,   782, -1363, -1363,
   -1363,   173, -1363, -1363,   192,   215, -1363,   -33,   382,    55,
   -1363,   136,   136, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363,   739, -1363,   837, 11407,   832,  6472, -1363,
   -1363, -1363,   877,   787,   787,   739, -1363,   609,   787,   387,
   11691,   326,   383,   946, -1363, -1363,   690,   224, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,    32,
     542,   462, -1363,   753,   163,    25,   679, 11691,   787, -1363,
   -1363, -1363, -1363,   827, 11691, -1363, 11691, -1363, -1363,   862,
     855, 11123,   864,  6472,   865,   -75,   840,     7,   300,   731,
   -1363, -1363,   577,    -5,   877, 11123,   869,   893,   806,   796,
     859,   787,   834,   860,   897,   787,   878,  6472,   854,   -53,
     847, -1363, -1363, -1363, -1363,  6472,   879,  6472,  6472,   856,
   -1363,   901,   903,  6472, -1363,   822,   823,   852, 11691, -1363,
   11691, -1363,  6472,   973, -1363,    -8, -1363,    43, -1363, -1363,
     981, -1363,   478,  6472,  6472,  6472,   479,  6472,  6472,  6472,
    6472,  6472,  6472,   892,  6472,  6472,   894,   -14,   830,   633,
     770,   866,   898,    76,    71,   808,  7062,  7062,  7062,   931,
   -1363, -1363, -1363,  6472,   446,   908, -1363, 11691,   910, -1363,
   -1363,  6472,     6,   402,   308, -1363,   745,   148,   763,   765,
   -1363, -1363,   592, -1363,   755,   289,   867,   868, 11407,   870,
   -1363,   316, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363,   883, -1363, -1363, -1363,  6472, -1363, -1363,   270, -1363,
   -1363, -1363, -1363, -1363, -1363,  6472, -1363,   456,   460, -1363,
     999,   535, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363,   754, -1363, -1363,  1000, -1363, -1363, -1363, -1363, -1363,
     255,  1002, -1363,   523, -1363, -1363, -1363,   708,   126,   710,
     468,   714,   715,   628,   805,   316,   807,   809,  7947,   756,
     726,   542, -1363,   810,   877,   844,  4702,   851,   857,   902,
     858,   872, 11691,    26, -1363, 11691, -1363, 11691,  6472,   895,
    6472,   920,  6472,   -60,   904,  6472,   905, -1363,   930,   934,
    6472, 11691,   597,   971, -1363, -1363, -1363, -1363, -1363, -1363,
   11123, -1363,  6472,   787,   948, -1363, -1363, -1363,   787,   948,
   11691, -1363,  6472,  6472,   912,  4997, -1363, 11691, -1363, -1363,
    6472,  6472,   526, -1363,   -11, 10839,   547, -1363,   873, -1363,
   -1363,  5292,   876,   880, -1363, -1363,   929, -1363,   193, -1363,
   -1363,  1051, -1363, -1363, 11691, -1363, -1363,   408, -1363, -1363,
   -1363,   881,   836,   841, -1363, -1363, -1363,   848,   849, -1363,
   -1363, -1363, -1363, -1363,   829, 11691,   886, -1363, 11691, -1363,
     894, -1363, -1363, -1363,  8832,   770, -1363,  6472, 11691,   928,
     437, -1363, -1363, -1363,   908, -1363,   787, -1363,   627, -1363,
      33,   957, -1363,  6472,   959,   845,   891,   889, -1363,     6,
     820, -1363, -1363,   -93, -1363,   333,    22,   835,     6,   333,
    7357, -1363,   -50, -1363, -1363, -1363, -1363, -1363, -1363,     6,
     932,   804,   667,    22, -1363, -1363,   791,  1004, -1363, -1363,
   -1363,  9987,   900,   907,   919, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363,   906, -1363, -1363, -1363,  6472, -1363, -1363, -1363,
   -1363,  1053,   190,  1059,   190,   842,   991, -1363, -1363, -1363,
   -1363,   921, 11691,   850,   805,  7947, -1363, -1363, -1363,   925,
   -1363, -1363, -1363, -1363, -1363, -1363,  6472,   945, -1363, -1363,
   -1363,  6472, -1363,   226, -1363,  6472,   965,  6472, -1363,  6472,
   11691, 11691, -1363,   397, -1363,  6472, -1363,   988,  1017,   787,
     948, -1363, -1363, -1363,  6472, -1363,   933, -1363, -1363, -1363,
     935, -1363,  6472,  6472, 11691,   937,   145, -1363, -1363, -1363,
     936, -1363, -1363,   973, 11691,   510, -1363,   973, 11691, -1363,
   -1363,  6472,  6472,  6472,  6472,  6472, -1363,  6472,   272, -1363,
   -1363,   369, -1363,   940, -1363, -1363, -1363, -1363,   957, -1363,
   -1363, -1363,   787, -1363, -1363, -1363, -1363, -1363,   941,  7357,
   -1363, -1363, -1363, -1363, -1363,   233,  7357,  7357,   374, -1363,
     763, -1363,    19, -1363,   765,     6,   963, -1363, -1363,   839,
   -1363, -1363, -1363, -1363,  1022,   939, -1363,   220, -1363, -1363,
   -1363, -1363,   -13, -1363,    28,    28, -1363,   190, -1363, -1363,
     228, -1363,  1099,    22,   942,  1023, -1363,  7947,   -55,   846,
   -1363,   960, -1363, -1363,  6472, -1363,  6472,   985, -1363,  6472,
   -1363, -1363, -1363,  1079, -1363, -1363,  6472,   787, -1363, -1363,
   -1363,  6472, -1363, -1363,  1039,  6472, 11691,  6472, -1363,    18,
     973, 11691,   943,   973, -1363, -1363, -1363, -1363, -1363, -1363,
    6472,   994,  1018,  8832, -1363, -1363, -1363, -1363, -1363,   242,
    7357,  7357,   418,   358, -1363, -1363, -1363, -1363, -1363, -1363,
    6472, -1363, 11123, -1363, 11123,  1042, -1363, -1363, -1363, -1363,
    1111, -1363, -1363, -1363,   882, -1363,   991,  1033, -1363,   205,
   11691,  1024,   918, 11691,  7947, -1363, -1363,  6472, -1363,  1025,
   -1363,   948, -1363, 11123, -1363,   964, -1363,   181,    57, -1363,
     949,   973, -1363,   950, -1363,  6472, 11691, -1363,   418,   418,
    7357,   968, -1363, -1363, 11123, -1363, -1363, -1363,  7947, -1363,
     957,   861, 11691,  1030,   938,  1033, -1363, 11691,   969,  6472,
   -1363, -1363,  1064,   416, -1363, -1363, -1363, -1363,   977,   263,
   -1363, -1363, -1363,   958, -1363, -1363,   237,   418, -1363, -1363,
   -1363, -1363,  6472,   871, 11691,  1044, -1363,  6472, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363,  1045,  1012, -1363,   885,
     887, 11691, -1363, 11691, -1363,   888,  6472,   890,   243,  7947,
   -1363,  7947,  1048,  1012, -1363,   970, 11691, -1363,   896,   983,
   11691,  1012,   947, -1363,  1055, 11691,   899,  7947, -1363
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
         0,   432,   433,     0,     0,     0,   761,   586,   852,   861,
     802,   766,   764,   747,   853,   856,   809,   902,   770,   748,
     749,   914,   801,   862,   751,   859,   831,   811,   786,   806,
     903,   807,   857,   854,   805,   753,   860,   754,   755,   900,
     916,   899,   803,   822,   816,   756,   804,   758,   757,   901,
     840,   808,   783,   926,   927,   928,   929,   930,   931,   932,
     933,   934,   935,   936,   950,   957,   830,   826,   817,   797,
     746,     0,   825,   833,   841,   951,   821,   452,   798,   799,
     855,   952,   958,   818,   835,     0,   458,   421,   454,   828,
     763,   819,   820,   848,   823,   839,   847,   956,   959,   769,
     810,   850,   453,   838,   843,   750,     0,     0,   370,   836,
     846,   851,   849,   829,   815,   904,   813,   814,   953,     0,
     369,     0,   954,   960,   844,   800,   824,   955,   399,     0,
     431,   845,   827,   834,   842,   837,   905,   791,   796,   795,
     794,   793,   792,   759,   812,     0,   762,   858,   784,   891,
     890,   892,   768,   767,   787,   897,   752,   889,   894,   895,
     886,   790,   832,   888,   898,   896,   887,   788,   893,   907,
     910,   911,   908,   909,   906,   760,   912,   913,   915,   878,
     877,   864,   782,   775,   871,   867,   785,   781,   880,   881,
     771,   772,   765,   774,   876,   875,   872,   868,   885,   879,
     874,   870,   863,   773,   884,   883,   777,   779,   778,   869,
     873,   865,   780,   866,   776,   882,   937,   938,   939,   940,
     941,   942,   918,   919,   917,   923,   924,   925,   920,   921,
     922,   789,   943,   944,   945,   946,   947,   948,   949,     0,
       0,     2,     0,     5,     7,    19,     0,     0,    24,    27,
      38,    30,    31,    32,    58,    33,    42,    34,    62,    63,
      64,    59,    60,    66,    67,    37,     0,    35,    36,    40,
      41,    61,   220,   219,   216,   217,   218,    39,    14,   196,
     197,   201,   203,   235,   241,     0,   233,   234,   204,   205,
     206,   207,   208,   325,   327,   329,   339,   343,   345,   348,
     353,   356,   359,   361,   363,   365,     0,   367,   373,   375,
       0,   391,   374,   395,   398,   400,   403,   405,     0,   410,
     407,     0,   418,   428,   430,   404,   434,   441,   450,   442,
     443,   444,   447,   448,   445,   446,   465,   467,   468,   469,
     466,   514,   515,   516,   517,   518,   519,   427,   560,   552,
     559,   558,   557,   554,   556,   553,   555,   451,   449,   587,
     588,    65,   209,   210,   212,   211,   213,   214,   215,   429,
     745,   852,   861,   859,   521,   762,     0,   525,     0,   531,
       0,   174,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   117,   118,     0,
       0,     0,     0,   113,   114,   115,   116,   123,     0,     0,
       0,     0,     0,     0,     0,   111,     0,   172,   178,   180,
     183,   182,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   423,   426,   413,     0,     0,   747,
     770,   749,   914,   801,   862,   751,   811,   753,   916,   822,
     756,   758,   757,   840,   950,   957,   746,   951,   952,   958,
     823,   956,   959,   904,   953,   954,   960,   955,   905,   897,
     889,   895,   886,   788,   907,   910,   911,   908,   760,   912,
     915,   419,   429,   745,   411,   412,   415,   747,   748,   749,
     753,   754,   755,   756,   746,   752,   455,     0,   417,   416,
     456,     0,   481,     0,   422,   743,     0,   744,   394,     0,
     425,   424,   414,   397,     0,     0,   510,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   160,   157,   170,
     171,     0,     0,     0,     0,     3,     1,     6,     8,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   109,     0,
       0,   199,   198,     0,     0,     0,     0,     0,     0,     0,
       0,   221,   240,   236,   242,   237,   239,   238,     0,     0,
       0,   384,     0,     0,   382,     0,   334,     0,   383,   376,
     381,   380,   379,   378,   377,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   372,   371,   368,     0,   392,   396,     0,
       0,     0,   406,   438,   409,   408,   420,     0,   435,     0,
       0,   522,   526,   532,     0,   742,    84,    69,    70,   151,
     152,     0,     0,     0,     0,    75,    76,     0,   181,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   597,
     598,   599,   120,   119,     0,    74,   127,   124,     0,   126,
     125,   122,   121,     0,     0,     0,   112,     0,   173,   179,
       0,     0,   566,     0,     0,     0,   562,     0,     0,     0,
     576,     0,     0,     0,   223,   224,   243,   244,     0,     0,
       0,     0,   153,     0,   190,     0,   590,     0,     0,    93,
       0,     0,     0,    85,   260,   261,     0,     0,     0,   567,
       0,     0,     0,     0,     0,   308,     0,     0,   565,     0,
       0,     0,   584,     0,     0,     0,     0,   570,     0,     0,
       0,   457,   482,   481,   478,     0,     0,   512,   511,   393,
       0,   509,     0,   610,   611,   561,     0,     0,     0,     0,
       0,     0,   616,     0,     0,   168,     0,     0,     0,   263,
     265,    20,     0,    21,     0,     4,     0,    25,    11,     0,
      26,    15,   852,    28,    12,    29,    16,     0,   108,   202,
       0,     0,     0,     0,     0,   222,   281,   326,   328,   332,
     338,   337,   336,     0,   333,   330,   331,     0,   347,   346,
     344,   350,   351,   352,   349,   354,   355,   358,   357,     0,
       0,     0,     0,   389,     0,   401,   402,     0,   439,   436,
     463,     0,   589,   461,     0,     0,   176,     0,     0,     0,
      73,     0,     0,    48,    50,    51,    52,    53,    55,    56,
      57,    49,    54,    44,    45,     0,     0,   101,     0,    97,
      99,   100,   104,     0,     0,    43,    83,     0,     0,     0,
       0,     0,     0,     0,   692,   697,     0,     0,   693,   727,
     680,   682,   683,   684,   686,   688,   687,   685,   689,     0,
       0,     0,   128,     0,     0,   131,     0,     0,     0,   530,
     520,   563,   564,     0,     0,   580,     0,   577,   629,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     225,   226,     0,   231,   192,     0,     0,   154,     0,     0,
       0,     0,     0,     0,    86,     0,     0,     0,     0,     0,
       0,   569,   568,   575,   583,     0,     0,     0,     0,     0,
     529,     0,     0,     0,   385,     0,     0,     0,     0,   573,
       0,   571,     0,   481,   479,     0,   470,     0,   459,   460,
       0,     9,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   852,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     110,   200,   232,     0,   292,   288,   290,     0,   282,   283,
     335,     0,     0,     0,     0,   658,   341,   631,   635,   637,
     639,   641,   644,   651,   652,   660,   862,   750,     0,   759,
     360,   538,   544,   545,   547,   591,   592,   548,   551,   362,
     364,   535,   366,   390,   440,     0,   437,   462,     0,   175,
      81,    82,    79,    80,   185,     0,   184,     0,     0,    46,
       0,     0,   102,   103,   105,    71,    72,    77,    78,    68,
     698,     0,   701,   728,     0,   691,   690,   695,   694,   726,
       0,     0,   703,     0,   699,   702,   681,     0,     0,     0,
       0,     0,     0,     0,   129,   135,     0,     0,     0,     0,
       0,     0,   132,     0,   106,     0,     0,     0,     0,   584,
       0,     0,     0,     0,   537,     0,   246,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   227,     0,     0,
       0,     0,   275,     0,   272,   277,   230,   193,   155,   191,
       0,   194,     0,     0,    95,    89,    92,    91,     0,    87,
       0,   266,     0,     0,     0,     0,   167,     0,   306,   310,
       0,     0,     0,   313,     0,     0,     0,   320,     0,   387,
     386,     0,     0,     0,   307,   482,     0,   471,     0,   505,
     502,     0,   506,   507,     0,   508,   501,     0,   476,   504,
     503,     0,     0,     0,   603,   604,   600,     0,     0,   608,
     609,   605,   614,   612,     0,     0,     0,   618,     0,   162,
       0,   159,   158,   169,     0,   619,   620,     0,     0,    22,
       0,    13,    17,    18,   289,   301,     0,   302,     0,   293,
     294,   295,   296,     0,   285,     0,     0,     0,   642,   655,
       0,   340,   342,     0,   674,     0,     0,     0,     0,     0,
       0,   630,   632,   633,   669,   670,   671,   673,   672,     0,
       0,   646,   645,     0,   649,   653,   667,   665,   664,   657,
     661,     0,     0,     0,     0,   541,   543,   542,   539,   536,
     464,   177,     0,   187,   186,   189,     0,    47,    98,   715,
     696,     0,   720,     0,   720,   709,   704,   130,   136,   138,
     137,     0,     0,     0,   133,     0,   107,    23,   523,     0,
     581,   582,   585,   578,   579,   245,     0,     0,   258,   259,
     250,     0,   254,     0,   248,     0,     0,     0,   270,     0,
       0,     0,   229,   273,   276,     0,   156,     0,    94,     0,
      88,   262,   268,   267,     0,   533,     0,   309,   311,   316,
       0,   314,     0,     0,     0,     0,     0,   321,   388,   527,
       0,   574,   572,   481,     0,     0,   513,   481,     0,   477,
      10,     0,     0,     0,     0,     0,   617,     0,   163,   161,
     626,     0,   621,     0,   264,   305,   303,   304,   297,   298,
     299,   291,     0,   286,   284,   659,   650,   656,     0,     0,
     729,   730,   740,   739,   738,     0,     0,     0,     0,   731,
     636,   737,     0,   634,   638,     0,     0,   643,   647,     0,
     668,   663,   666,   662,     0,     0,   549,     0,   546,   596,
     540,   195,     0,   716,     0,     0,   714,   721,   722,   718,
       0,   713,     0,   711,     0,   705,   706,     0,     0,     0,
     134,     0,   524,   247,     0,   256,     0,     0,   252,     0,
     255,   271,   279,   280,   274,   228,     0,     0,    90,   269,
     534,     0,   317,   315,     0,     0,     0,     0,   528,     0,
     481,     0,     0,   481,   601,   602,   606,   607,   613,   615,
       0,   164,     0,     0,   622,   628,   300,   287,   654,   741,
       0,     0,   733,     0,   679,   678,   677,   676,   675,   640,
       0,   732,     0,   593,     0,     0,   188,   725,   724,   723,
       0,   717,   710,   708,     0,   700,     0,   139,   141,   143,
       0,     0,     0,     0,     0,   251,   249,     0,   257,     0,
     324,    96,   312,     0,   322,     0,   318,   491,   485,   480,
       0,   481,   472,     0,   165,     0,     0,   627,   735,   734,
       0,     0,   594,   550,     0,   719,   712,   707,     0,   145,
     144,     0,     0,     0,     0,   140,   253,     0,     0,     0,
     499,   493,     0,   492,   494,   500,   497,   487,     0,   486,
     488,   498,   474,     0,   473,   166,     0,   736,   648,   595,
     142,   146,     0,     0,     0,     0,   278,     0,   319,   484,
     495,   496,   483,   489,   490,   475,     0,     0,   147,     0,
       0,     0,   323,     0,   623,     0,     0,     0,     0,     0,
     149,     0,     0,     0,   148,     0,     0,   624,     0,     0,
       0,     0,     0,   625,     0,     0,     0,     0,   150
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1363, -1363,  -228,   944, -1363,   951,   953, -1363,   926,  -225,
    -518,  -544, -1363,   508,  -402, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,  -924,
   -1363, -1363, -1363, -1363,   104,   309, -1363, -1363, -1363,   789,
   -1363,    67,  -879, -1363,  -364,  -397, -1363, -1363,  -615, -1363,
    -893, -1363, -1363,   -38, -1363, -1363, -1363, -1363, -1363,   769,
   -1363, -1363,   780,   801, -1363, -1363, -1363,   248,   776, -1362,
    -491,    53, -1363,  -561,   736, -1363, -1363, -1363, -1363,   253,
   -1363, -1363,   913, -1363, -1363, -1363, -1363,    75,  -692,  -696,
   -1363, -1363, -1363,   -29,    44, -1363, -1363,  -154,    64, -1363,
   -1363, -1363,   -45, -1363, -1363,   194,   -35, -1363, -1363,   -31,
   -1213, -1363,   695,    46, -1363, -1363,    45, -1363, -1363, -1363,
      39, -1363, -1363,   617,   625, -1363,  -453, -1363, -1363,  -609,
     146,  -607,   149,   152, -1363, -1363, -1363, -1363, -1363,   914,
   -1363, -1363, -1363, -1363,  -755,  -298, -1091, -1363,  -105, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363,   -36, -1199, -1363, -1363,
     357,    56, -1363,  -634, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363,   576, -1363,  -945, -1363,    31, -1363,   470,  -751, -1363,
   -1363, -1363, -1363, -1363,  -377,  -369, -1143,  -950, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,   393,  -723,
    -797,   121,  -815, -1363,   -65,  -821, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363,   803,   811,  -472,   311,   158, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363,    15, -1363, -1363,     8, -1363, -1363,  -980, -1363,
   -1363, -1363,   -27,   -34,  -193,   213, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,   -19,
   -1363, -1363, -1363,  -184,   207,   341, -1363, -1363, -1363, -1363,
   -1363,   151, -1363, -1363, -1266, -1363, -1363, -1363,  -673, -1363,
     -58, -1363,  -200, -1363, -1363, -1363, -1363, -1195, -1363,   -10,
   -1363,  -367,  -359,    27,   -71
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   240,   784,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   863,   864,   865,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,  1154,
     722,   264,   265,   869,   870,   871,   266,   267,   414,   415,
     268,  1104,   902,   269,  1537,  1538,   270,   271,   435,   272,
     548,   774,   997,  1219,   273,   274,   275,   276,   416,   417,
     845,   277,   418,   419,   420,   421,   713,   714,  1195,  1066,
     278,   279,   572,   280,   281,   282,   581,   433,   932,   933,
     283,   582,   284,   584,   285,   286,   706,   707,  1142,   926,
     287,   724,   778,   779,   725,   710,  1143,  1144,  1145,   585,
     586,  1018,  1019,  1403,   587,  1015,  1016,  1239,  1240,  1241,
    1242,   288,   734,   735,   289,  1172,  1173,  1174,   290,  1176,
    1177,   291,   292,   293,   294,   813,   295,  1251,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     605,   606,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     632,   633,   326,   327,   328,   329,   330,   331,   332,   333,
     334,   841,   335,   336,   337,  1197,   753,   754,   755,  1559,
    1598,  1599,  1592,  1593,  1600,  1594,  1198,  1199,   338,   339,
    1200,   340,   341,   342,   343,   344,   345,   346,  1050,   927,
    1040,  1288,  1041,  1437,  1042,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   741,  1118,   357,   358,   359,
     360,  1044,  1045,  1046,  1047,   361,   362,   363,   364,   365,
     366,   771,   772,   367,  1225,  1226,  1391,   368,  1026,  1261,
    1262,  1027,  1028,  1029,  1030,  1031,  1271,  1427,  1428,  1032,
    1274,  1033,  1408,  1034,  1035,  1279,  1280,  1433,  1431,  1263,
    1264,  1265,  1266,  1517,   675,   890,   891,   892,   893,   894,
     895,  1094,  1454,  1455,  1095,  1453,  1533,   896,  1304,  1450,
    1446,  1447,  1448,   897,   898,  1267,  1275,  1418,  1268,  1414,
    1252,  1155,   526,   369,   370
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       503,   820,   975,   949,   821,   822,   823,   824,  1043,  1043,
     846,   800,   627,   959,   503,   646,   925,  1311,   565,   567,
     562,  1159,   793,   795,   533,  1390,  1112,  1399,  1400,  1504,
     948,     7,  1196,  1049,   920,   501,   503,   668,   849,  1131,
    1456,   563,  1247,   563,  1253,  1043,   787,   790,   503,   929,
     503,  1071,  1189,  1190,  1379,   535,   376,   378,   380,   563,
    1540,   563,  1024,   690,   563,   570,  1189,   993,  1128,   563,
     719,   723,   900,   788,   791,   794,   796,   563,  1429,  1105,
     694,  1596,   730,  1335,   879,  1163,  1362,   880,   570,   921,
    1220,   570,   757,   711,   921,   956,   922,   956,   502,   695,
    1043,   922,   976,   914,   382,   383,  1223,   384,   385,  1557,
     645,  1060,   516,    77,  1043,  1254,  1415,  1111,  1187,  1410,
     922,   916,  1301,   425,  1124,   645,    88,   388,  1061,   881,
     980,   437,   456,   422,   522,   947,  1236,   809,  1148,   810,
     811,   936,   812,  1191,   814,   923,   527,   571,   529,  1074,
    1132,   102,   815,   816,  1001,  1021,  1238,  1411,  1022,   521,
     438,   712,  1192,   457,  1193,  1541,   458,  1526,   977,  1326,
    1011,  1363,  1221,   608,  1294,   957,  1192,   972,  1193,   121,
    1303,  1230,   915,  1025,  1188,  1506,  1590,  1597,  1064,   981,
    1189,   609,   715,   994,   924,   720,   107,  1558,  1255,  1256,
     917,  1257,  1189,  1190,  1065,  1136,   715,   930,   628,   924,
     429,  1147,   901,   119,   982,  1002,   924,  1043,  1259,   968,
     937,   696,  1186,  1283,  1461,  1307,   564,   396,   566,  1129,
    1260,  1134,  1379,  1194,  1350,  1133,  1067,  1068,   536,   793,
     795,   721,  1253,  1196,   781,   931,   783,   503,  1542,  1006,
     503,   145,  1196,  1164,  1008,   758,   718,   901,  1534,   986,
    1486,  1023,  1229,   787,   790,  1634,   924,  1024,  1024,  1407,
    1577,   924,  1189,   970,  1416,  1417,   924,  1055,   426,   882,
     450,  1647,   634,  1510,  1514,   636,   399,  1596,   434,  1653,
    1105,  1515,   883,  1191,   884,     7,  1055,   921,   969,   876,
    1192,  1516,  1193,   617,  1567,   885,   886,   887,  1236,   888,
    1591,   889,  1192,  1254,  1193,   653,   503,   618,  1091,  1058,
     922,   503,  1444,   439,  1524,   503,  1579,  1487,   401,  1043,
     715,   503,  1530,   782,  1092,   983,   984,   451,   503,   786,
     789,  1626,   715,   921,   444,   502,   107,  1642,   502,  1301,
     985,   503,   971,  1346,  1043,   944,  1056,   503,  1511,   940,
    1020,   503,   943,   119,   921,  1302,  1539,  1611,   503,  1466,
     503,   503,   503,   503,   503,  1057,  1093,    77,  1365,   503,
     987,   988,  1192,  1374,  1193,   626,  1445,   503,  1025,  1025,
      88,  1316,   921,  1623,   958,   989,  1255,  1256,  1059,  1257,
     381,   145,   573,  1525,   452,   453,  1258,  1303,   574,   121,
    1500,  1531,   715,   575,   654,   102,  1259,  1189,  1190,   660,
    1627,  1590,   386,   527,  1291,  1189,  1643,     7,  1260,   676,
    1196,  1327,   576,   655,   608,  1460,   678,  1336,   615,   389,
     430,   390,  1117,  1135,  1120,   431,   503,   616,  1138,   527,
     391,   866,   609,  1539,  1139,   702,  1285,  1249,  1109,   708,
    1043,  1069,   793,   795,   793,   656,   726,  1110,   527,   731,
     732,   733,   736,  1069,   610,   503,   691,   742,   693,   663,
     699,   121,   664,   503,  1436,   749,   687,  1539,  1286,   717,
     432,   922,   867,   727,  1024,   611,  1182,   868,  1183,   737,
     647,   739,   740,  1024,   743,  1287,  1075,  1076,  1191,    77,
     746,  1079,   608,   648,  1024,  1231,  1232,  1233,  1065,  1189,
    1190,  1502,    88,   612,   835,   836,  1062,  1192,   577,  1193,
     609,   578,  1276,  1277,   445,  1192,   613,  1193,   436,  1235,
     666,  1115,   559,  1063,   736,  1620,   579,   102,  1644,  1236,
    1645,  1021,  1570,  1551,  1022,  1278,  1003,   715,  1007,  1237,
     560,   107,  1004,   651,   663,   715,  1658,   664,   517,  1238,
     614,   580,   608,   773,  1503,   121,   756,  1097,   119,   652,
     560,   780,   454,  1098,   694,  1085,   851,   760,   852,  1293,
     609,   503,   538,  1295,   539,   397,  1086,  1412,  1378,   665,
    1099,   667,  1100,   695,  1413,   547,   777,  1595,  1601,  1296,
    1191,  1101,   503,   503,   503,  1025,   145,  1091,   423,   649,
     442,   424,  1489,  1171,  1025,   666,  1492,   398,  1138,  1192,
     455,  1193,   650,  1092,  1139,  1025,  1360,  1102,   503,  1514,
     503,  1467,  1087,  1595,  1175,   443,  1515,   503,  1138,  1601,
     503,  1422,  1140,  1088,  1139,   400,  1516,  1366,   448,   715,
    1080,  1081,  1082,   107,   544,  1501,  1083,   568,   867,   545,
    1024,   922,   569,   868,   669,   670,   671,   635,   504,   834,
     119,   503,   638,   449,   837,   793,   667,   427,   838,   872,
     428,   838,  1141,   440,   838,   446,   441,   541,   447,   542,
    1491,  1043,   631,  1043,   637,  1202,  1207,  1203,  1208,   505,
     904,   905,   906,   684,   403,   404,   405,   406,   145,   407,
     408,   685,   410,   411,   506,  1572,   627,  1573,   412,   518,
     503,   519,  1043,  1077,  1078,  1442,   928,   523,   934,  1560,
     629,   630,  1563,   672,   673,   527,   681,   682,   527,  1106,
    1107,  1396,  1397,  1043,   818,   819,  1588,   524,   503,   503,
     503,   503,  1103,   530,   825,   826,  1051,  1051,   938,   827,
     828,  1527,  1528,   531,   532,   534,   537,  1609,   543,   973,
     540,   546,   547,   551,   552,   549,  1348,   550,   554,   553,
     556,  1025,   588,   589,   607,   503,   619,   965,   966,   620,
     621,   631,  1509,   622,   639,   640,   644,  1512,  1513,   503,
    1603,   641,   645,   657,   642,   643,  1580,   853,   854,   855,
     856,   857,   858,   859,   860,   861,   862,   998,  1012,   386,
     659,   381,   661,   662,   674,   679,   503,   680,   709,   683,
     677,   692,   704,   503,   705,   503,   715,   738,   744,   745,
     503,   751,   752,   386,   759,   761,  1048,  1048,  1048,  1048,
     424,   428,   441,   387,   503,   590,   447,   458,   762,  1395,
     389,   765,   390,   591,   592,   770,   593,   785,   797,   801,
     802,   391,   817,   803,   594,   392,   804,   829,   595,   830,
     596,   831,   832,  1048,   842,   597,   847,   503,   848,   503,
     850,  1568,  1569,   873,   877,   878,   874,  1084,   907,   899,
     903,   908,   598,   909,   910,   911,   393,   394,  1009,   919,
     935,   912,   913,   918,   939,   941,   942,   945,   946,   951,
     991,   950,   960,   955,  1114,   599,   600,   601,   602,   603,
     604,  1119,   952,  1119,   953,   954,   503,   963,  1048,   961,
     962,   964,   967,   978,   979,   990,   995,  1005,   999,  1000,
    1017,  1607,  1048,  1054,   992,  1070,  1053,   503,  1013,   921,
     868,  1089,  1090,   397,  1113,  1108,  1116,  1122,  1123,  1125,
    1127,  1137,  1478,  1130,   711,  1150,  1151,  1153,  1157,  1152,
    1156,  1158,  1162,  1160,  1167,   742,  1165,   742,  1171,  1170,
    1175,  1181,  1179,  1180,  1185,   398,  1201,  1215,   665,  1218,
    1222,  1224,  1243,  1228,  1245,  1227,  1178,  1269,  1273,  1281,
    1282,  1270,  1284,  1289,     7,  1300,  1250,  1305,  1313,  1309,
    1317,  1310,  1315,   400,  1320,  1507,  1299,   901,  1331,  1312,
    1321,  1323,  1322,  1333,  1244,  1340,  1345,  1337,  1339,  1341,
    1354,   503,  1349,  1368,   503,  1324,   503,  1373,  1376,  1371,
    1236,  1385,  1402,  1372,  1381,  1048,  1409,  1380,  1387,  1382,
     503,  1405,  1406,  1430,  1246,  1425,  1383,  1384,  1443,   503,
    1432,  1419,  1426,  1438,  1449,  1091,  1441,  1457,  1464,   503,
    1439,   402,   403,   404,   405,   406,   503,   407,   408,   409,
     410,   411,  1440,  1459,   503,  1462,   412,   413,  1469,  1452,
    1476,  1477,  1520,  1480,  1522,  1521,  1488,  1481,  1292,  1485,
    1505,  1508,  1523,   503,  1532,  1535,  1544,  1536,  1547,  1543,
    1549,  1553,  1565,  1566,  1574,  1562,  1575,  1578,  1583,  1582,
    1587,  1602,  1604,  1576,   503,  1614,  1589,   503,  1608,   708,
    1625,  1617,  1328,   503,  1329,  1619,  1622,   503,  1615,  1631,
    1633,  1065,  1612,  1646,  1648,   703,  1651,  1654,  1343,  1319,
    1655,   561,  1629,   875,  1635,  1298,  1072,  1048,  1314,  1650,
    1585,  1610,  1389,   555,  1149,   688,  1146,   726,  1636,  1474,
    1639,   658,  1641,   557,   736,   558,   689,  1325,   583,  1394,
    1404,  1657,  1048,   686,  1351,   807,  1344,  1234,  1401,  1398,
     503,   716,   750,  1357,   808,  1367,   844,  1361,  1356,  1375,
     625,  1377,  1624,   974,  1621,  1052,  1308,  1121,  1297,   697,
    1386,  1420,  1519,  1392,  1370,  1424,  1248,   698,  1518,  1272,
    1096,   503,   773,  1423,  1306,  1388,  1451,  1529,     0,  1421,
       0,   502,     0,     0,     0,   780,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   503,
     503,     0,     0,     0,   763,   764,     0,   766,   767,   768,
     769,     0,     0,     0,     0,     0,     0,   775,   776,     0,
       0,     0,     0,   503,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   503,     0,   798,   799,   503,  1048,     0,
       0,     0,     0,     0,     0,   805,   806,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1458,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1472,  1473,     0,
       0,     0,     0,   840,     0,     0,   840,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1484,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1490,     0,     0,     0,  1493,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   503,     0,     0,     0,     0,
     503,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   503,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   503,     0,   503,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   503,
       0,     0,   503,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   503,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   503,     0,     0,     0,     0,
       0,     0,     0,   503,     0,     0,     0,     0,     0,     0,
       0,   503,     0,  1555,     0,     0,   503,     0,  1561,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     502,     0,     0,  1010,     0,     0,     0,     0,     0,  1014,
       0,     0,     0,   503,     0,     0,     0,     0,     0,  1048,
       0,  1048,     0,     0,     0,     0,     0,     0,     0,     0,
     503,     0,   503,     0,     0,     0,     0,  1581,     0,     0,
    1584,     0,     0,  1571,     0,   503,     0,     0,     0,   503,
    1048,     0,     0,     0,   503,     0,     0,     0,     0,     0,
       0,     0,     0,  1606,     0,     0,     0,     0,     0,     0,
       0,  1048,     0,     0,  1073,     0,     0,     0,     0,  1613,
       0,     0,     0,     0,  1616,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1630,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   381,     0,  1637,  1126,
    1638,     0,     0,     0,     0,     0,   382,   383,     0,   384,
     385,     0,     0,  1649,     0,     0,     0,  1652,   386,     0,
       0,     0,  1656,  1161,     0,     0,     0,     0,   387,   388,
       0,  1166,     0,  1168,  1169,   389,     0,   390,     0,     0,
       0,     0,     0,     0,     0,     0,   391,     0,  1184,     0,
     392,     0,     0,     0,     0,     0,     0,     0,     0,  1204,
    1205,  1206,     0,  1209,  1210,  1211,  1212,  1213,  1214,     0,
    1216,  1217,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   393,   394,   395,     0,     0,     0,     0,     0,  1014,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   396,
       0,  1290,     0,     0,     0,     0,     0,     0,   397,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     398,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   399,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   400,     0,
       0,     0,     0,     0,  1330,     0,  1332,     0,  1334,     0,
       0,  1338,     0,     0,     0,     0,  1342,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1347,     0,
     401,     0,     0,     0,     0,     0,     0,     0,  1352,  1353,
       0,     0,     0,     0,     0,     0,  1358,  1359,     0,     0,
       0,     0,     0,     0,     0,     0,   402,   403,   404,   405,
     406,     0,   407,   408,   409,   410,   411,     0,     0,     0,
       0,   412,   413,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1393,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1014,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1463,     0,     0,     0,     0,  1465,     0,     0,
       0,  1468,     0,  1470,     0,  1471,     0,     0,     0,     0,
       0,  1475,     0,     0,     0,     0,     0,     0,     0,     0,
    1479,     0,     0,     0,     0,     0,     0,     0,  1482,  1483,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1494,  1495,  1496,
    1497,  1498,     0,  1499,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1545,     0,  1546,     0,     0,  1548,     0,     0,     0,     0,
       0,     0,  1550,     0,     0,     0,     0,  1552,     0,     0,
       0,  1554,     0,  1556,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1564,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1586,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1605,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1618,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1628,     0,
       0,     0,     1,  1632,     0,     0,     0,     0,     0,     2,
       3,     4,     5,     6,     0,     0,     7,     0,     0,     0,
       8,     9,  1640,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,     0,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,     0,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,     0,    67,    68,    69,    70,    71,    72,    73,
      74,     0,     0,    75,    76,     0,     0,     0,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,     0,
       0,    88,     0,    89,    90,    91,    92,     0,    93,     0,
       0,     0,    94,    95,    96,    97,    98,     0,     0,     0,
       0,     0,     0,    99,   100,   101,   102,   103,   104,   105,
       0,     0,     0,   106,   107,   108,   109,   110,     0,     0,
       0,     0,   111,   112,   113,   114,   115,   116,   117,   118,
       0,   119,     0,   120,   121,     0,     0,   122,   123,   124,
       0,     0,     0,   125,     0,   126,   127,     0,   128,   129,
     130,     0,   131,     0,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,     0,     0,   143,   144,   145,
       0,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,     0,   190,   191,   192,     0,
     193,   194,   195,   196,   197,   198,     0,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,     1,     0,
       0,     0,     0,     0,     0,     2,     3,     4,     5,     6,
       0,     0,     7,     0,     0,     0,   371,   372,     0,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,   373,    26,    27,    28,    29,     0,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,     0,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,     0,    67,
      68,    69,    70,    71,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,     0,     0,    88,     0,    89,
      90,    91,    92,     0,    93,     0,     0,     0,    94,    95,
      96,    97,    98,     0,     0,     0,     0,     0,     0,    99,
     100,   101,   102,   103,   104,   105,     0,     0,     0,   106,
     107,   108,   109,   110,     0,     0,     0,     0,   111,   112,
     113,   114,   115,   116,   117,   118,     0,   119,     0,   120,
     121,     0,     0,   122,   123,   124,     0,   374,     0,   125,
       0,   126,   127,     0,   128,   129,   130,     0,   131,     0,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,     0,     0,   143,   144,   145,     0,   375,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,     0,   190,   191,   192,     0,   193,   194,   195,   196,
     197,   198,     0,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     4,     5,     6,     0,     0,     7,     0,     0,
       0,   371,   372,     0,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,   373,
      26,    27,    28,    29,     0,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,     0,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,     0,    67,    68,    69,    70,    71,    72,
      73,    74,     0,     0,    75,    76,     0,     0,     0,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
       0,     0,    88,     0,    89,    90,    91,    92,     0,    93,
       0,     0,     0,    94,    95,    96,    97,    98,     0,     0,
       0,     0,     0,     0,    99,   100,   101,   102,   103,   104,
     105,     0,     0,     0,   106,   107,   108,   109,   110,     0,
       0,     0,     0,   111,   112,   113,   114,   115,   116,   117,
     118,     0,   119,     0,   120,   121,     0,     0,   122,   123,
     124,     0,   377,     0,   125,     0,   126,   127,     0,   128,
     129,   130,     0,   131,     0,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,     0,     0,   143,   144,
     145,     0,   375,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,   192,
       0,   193,   194,   195,   196,   197,   198,     0,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,     1,     0,
       0,     0,     0,     0,     0,     2,     3,     4,     5,     6,
       0,     0,     7,     0,     0,     0,   371,   372,     0,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,   373,    26,    27,    28,    29,     0,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,     0,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,     0,    67,
      68,    69,    70,    71,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,     0,     0,    88,     0,    89,
      90,    91,    92,     0,    93,     0,     0,     0,    94,    95,
      96,    97,    98,     0,     0,     0,     0,     0,     0,    99,
     100,   101,   102,   103,   104,   105,     0,     0,     0,   106,
     107,   108,   109,   110,     0,     0,     0,     0,   111,   112,
     113,   114,   115,   116,   117,   118,     0,   119,     0,   120,
     121,     0,     0,   122,   123,   124,     0,   379,     0,   125,
       0,   126,   127,     0,   128,   129,   130,     0,   131,     0,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,     0,     0,   143,   144,   145,     0,   375,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,     0,   190,   191,   192,     0,   193,   194,   195,   196,
     197,   198,     0,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     4,     5,     6,     0,     0,     7,     0,     0,
       0,   371,   372,     0,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,   373,
      26,    27,    28,    29,     0,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,     0,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,     0,    67,    68,    69,    70,    71,    72,
      73,    74,     0,     0,    75,    76,     0,     0,     0,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
       0,     0,    88,     0,    89,    90,    91,    92,     0,    93,
       0,     0,     0,    94,    95,    96,    97,    98,     0,     0,
       0,     0,     0,     0,    99,   100,   101,   102,   103,   104,
     105,     0,     0,     0,   106,   107,   108,   109,   110,     0,
       0,     0,     0,   111,   112,   113,   114,   115,   116,   117,
     118,     0,   119,     0,   120,   121,     0,     0,   122,   123,
     124,     0,     0,     0,   125,   520,   126,   127,     0,   128,
     129,   130,     0,   131,     0,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,     0,     0,   143,   144,
     145,     0,   375,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,   192,
       0,   193,   194,   195,   196,   197,   198,     0,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,     1,     0,
       0,     0,     0,     0,     0,     2,     3,     4,     5,     6,
       0,     0,     7,     0,     0,     0,   371,   372,     0,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,   373,    26,    27,    28,    29,     0,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,     0,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,     0,    67,
      68,    69,    70,    71,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,     0,     0,    88,     0,    89,
      90,    91,    92,     0,    93,     0,     0,     0,    94,    95,
      96,    97,    98,     0,     0,     0,     0,     0,     0,    99,
     100,   101,   102,   103,   104,   105,     0,     0,     0,   106,
     107,   108,   109,   110,     0,     0,     0,     0,   111,   112,
     113,   114,   115,   116,   117,   118,     0,   119,     0,   120,
     121,     0,     0,   122,   123,   124,     0,   833,     0,   125,
       0,   126,   127,     0,   128,   129,   130,     0,   131,     0,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,     0,     0,   143,   144,   145,     0,   375,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,     0,   190,   191,   192,     0,   193,   194,   195,   196,
     197,   198,     0,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     4,     5,     6,     0,     0,     7,     0,     0,
       0,   371,   372,     0,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,   373,
      26,    27,    28,    29,     0,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,     0,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,     0,    67,    68,    69,    70,    71,    72,
      73,    74,     0,     0,    75,    76,     0,     0,     0,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
       0,     0,    88,     0,    89,    90,    91,    92,     0,    93,
       0,     0,     0,    94,    95,    96,    97,    98,     0,     0,
       0,     0,     0,     0,    99,   100,   101,   102,   103,   104,
     105,     0,     0,     0,   106,   107,   108,   109,   110,     0,
       0,     0,     0,   111,   112,   113,   114,   115,   116,   117,
     118,     0,   119,     0,   120,   121,     0,     0,   122,   123,
     124,     0,     0,     0,   125,   839,   126,   127,     0,   128,
     129,   130,     0,   131,     0,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,     0,     0,   143,   144,
     145,     0,   375,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,   192,
       0,   193,   194,   195,   196,   197,   198,     0,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,     1,     0,
       0,     0,     0,     0,     0,     2,     3,     4,     5,     6,
       0,     0,     7,     0,     0,     0,   371,   372,     0,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,   373,    26,    27,    28,    29,     0,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,     0,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,     0,    67,
      68,    69,    70,    71,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,     0,     0,    88,     0,    89,
      90,    91,    92,     0,    93,     0,     0,     0,    94,    95,
      96,    97,    98,     0,     0,     0,     0,     0,     0,    99,
     100,   101,   102,   103,   104,   105,     0,     0,     0,   106,
     107,   108,   109,   110,     0,     0,     0,     0,   111,   112,
     113,   114,   115,   116,   117,   118,     0,   119,     0,   120,
     121,     0,     0,   122,   123,   124,     0,     0,     0,   125,
     843,   126,   127,     0,   128,   129,   130,     0,   131,     0,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,     0,     0,   143,   144,   145,     0,   375,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,     0,   190,   191,   192,     0,   193,   194,   195,   196,
     197,   198,     0,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     4,     5,     6,     0,     0,     7,     0,     0,
       0,   371,   372,     0,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,   373,
      26,    27,    28,    29,     0,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,     0,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,     0,    67,    68,    69,    70,    71,    72,
      73,    74,     0,     0,    75,    76,     0,     0,     0,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
       0,     0,    88,     0,    89,    90,    91,    92,     0,    93,
       0,     0,     0,    94,    95,    96,    97,    98,     0,     0,
       0,     0,     0,     0,    99,   100,   101,   102,   103,   104,
     105,     0,     0,     0,   106,   107,   108,   109,   110,     0,
       0,     0,     0,   111,   112,   113,   114,   115,   116,   117,
     118,     0,   119,     0,   120,   121,     0,     0,   122,   123,
     124,     0,  1318,     0,   125,     0,   126,   127,     0,   128,
     129,   130,     0,   131,     0,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,     0,     0,   143,   144,
     145,     0,   375,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,   192,
       0,   193,   194,   195,   196,   197,   198,     0,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,     1,     0,
       0,     0,     0,     0,     0,     2,     3,     4,     5,     6,
       0,     0,     7,     0,     0,     0,   371,   372,     0,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,   373,    26,    27,    28,    29,     0,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,     0,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,     0,    67,
      68,    69,    70,    71,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,     0,     0,    88,     0,    89,
      90,    91,    92,     0,    93,     0,     0,     0,    94,    95,
      96,    97,    98,     0,     0,     0,     0,     0,     0,    99,
     100,   101,   102,   103,   104,   105,     0,     0,     0,   106,
     107,   108,   109,   110,     0,     0,     0,     0,   111,   112,
     113,   114,   115,   116,   117,   118,     0,   119,     0,   120,
     121,     0,     0,   122,   123,   124,     0,  1355,     0,   125,
       0,   126,   127,     0,   128,   129,   130,     0,   131,     0,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,     0,     0,   143,   144,   145,     0,   375,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,     0,   190,   191,   192,     0,   193,   194,   195,   196,
     197,   198,     0,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     4,     5,     6,     0,     0,     7,     0,     0,
       0,   371,   372,     0,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,   373,
      26,    27,    28,    29,     0,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,     0,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,     0,    67,    68,    69,    70,    71,    72,
      73,    74,     0,     0,    75,    76,     0,     0,     0,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
       0,     0,    88,     0,    89,    90,    91,    92,     0,    93,
       0,     0,     0,    94,    95,    96,    97,    98,     0,     0,
       0,     0,     0,     0,    99,   100,   101,   102,   103,   104,
     105,     0,     0,     0,   106,   107,   108,   109,   110,     0,
       0,     0,     0,   111,   112,   113,   114,   115,   116,   117,
     118,     0,   119,     0,   120,   121,     0,     0,   122,   123,
     124,     0,  1369,     0,   125,     0,   126,   127,     0,   128,
     129,   130,     0,   131,     0,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,     0,     0,   143,   144,
     145,     0,   375,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,   192,
       0,   193,   194,   195,   196,   197,   198,     0,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,     1,     0,
       0,     0,     0,     0,     0,     2,     3,     4,     5,     6,
       0,     0,     7,     0,     0,     0,     8,     9,     0,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,     0,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,     0,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,     0,    67,
      68,    69,    70,    71,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,     0,     0,    88,     0,    89,
      90,    91,    92,     0,    93,     0,     0,     0,    94,    95,
      96,    97,    98,     0,     0,     0,     0,     0,     0,    99,
     100,   101,   102,   103,   104,   105,     0,     0,     0,   106,
     107,   108,   109,   110,     0,     0,     0,     0,   111,   112,
     113,   114,   115,   116,   117,   118,     0,   119,     0,   120,
     121,     0,     0,   122,   123,   124,     0,     0,     0,   125,
       0,   126,   127,     0,   128,   129,   130,     0,   131,     0,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,     0,     0,   143,   144,   145,     0,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,     0,   190,   191,   192,     0,   193,   194,   195,   196,
     197,   198,     0,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     4,     5,     6,     0,     0,     7,     0,     0,
       0,     8,     9,     0,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,     0,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,     0,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,     0,    67,    68,    69,    70,    71,    72,
      73,    74,     0,     0,    75,    76,     0,     0,     0,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
       0,     0,    88,     0,    89,    90,    91,    92,     0,    93,
       0,     0,     0,    94,    95,    96,    97,    98,     0,     0,
       0,     0,     0,     0,    99,   100,   101,   102,   103,   104,
     105,     0,     0,     0,   106,   107,   108,   109,   110,     0,
       0,     0,     0,   111,   112,   113,   114,   115,   116,   117,
     118,     0,   119,     0,   120,   121,     0,     0,   122,   123,
     124,     0,     0,     0,   125,     0,   126,   127,     0,   128,
     129,   130,     0,   131,     0,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,     0,     0,   143,   144,
     145,     0,   375,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,   192,
       0,   193,   194,   195,   196,   197,   198,     0,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,     1,     0,
       0,     0,     0,     0,     0,     2,     3,     4,     5,     6,
       0,     0,     7,     0,     0,     0,   371,   372,     0,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
     462,   463,    23,   465,   373,    26,   466,    28,    29,     0,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
     468,    41,    42,   469,     0,    44,    45,    46,   471,   472,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,     0,    67,
      68,    69,    70,    71,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,     0,     0,    88,     0,    89,
      90,    91,    92,     0,    93,     0,     0,     0,   480,    95,
      96,    97,    98,     0,     0,     0,     0,     0,     0,    99,
     100,   101,   102,   103,   104,   105,     0,     0,     0,   106,
     107,   623,   109,   110,     0,     0,     0,     0,   111,   112,
     113,   114,   115,   116,   117,   118,     0,   119,     0,   624,
     121,     0,     0,   122,   123,   124,     0,     0,     0,   125,
       0,   126,   127,     0,   128,   129,   130,     0,   131,     0,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,     0,     0,   143,   144,   145,     0,   375,   147,   148,
     149,   150,   151,   152,   153,   154,   489,   156,   490,   158,
     491,   492,   161,   162,   163,   164,   165,   166,   493,   168,
     494,   495,   496,   497,   173,   174,   498,   499,   177,   500,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,     0,   190,   191,   192,     0,   193,   194,   195,   196,
     197,   198,     0,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     4,     5,     6,     0,     0,     7,     0,     0,
       0,   371,   372,     0,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,   373,
      26,    27,    28,    29,     0,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,     0,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,     0,    67,    68,    69,    70,    71,    72,
      73,    74,     0,     0,    75,    76,     0,     0,     0,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
       0,     0,    88,     0,    89,    90,    91,    92,     0,    93,
       0,     0,     0,    94,    95,    96,    97,    98,     0,     0,
       0,     0,     0,     0,    99,   100,   101,   102,   103,   104,
     105,     0,     0,     0,   106,   107,   108,   109,   110,     0,
       0,     0,     0,   111,   112,   113,   114,   115,   116,   117,
     118,     0,   119,     0,   120,   121,     0,     0,   122,   123,
     124,     0,     0,     0,   125,     0,   126,   127,     0,   128,
     129,   130,     0,   131,     0,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,     0,     0,   143,   144,
     145,     0,   375,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,   192,
       0,   193,   194,   195,   196,   197,   198,     0,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,     1,     0,
       0,     0,     0,     0,     0,     2,     3,     4,     5,     6,
       0,     0,     7,     0,     0,     0,     8,   372,     0,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,     0,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,     0,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,     0,    67,
      68,    69,    70,    71,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,     0,     0,    88,     0,    89,
      90,    91,    92,     0,    93,     0,     0,     0,    94,    95,
      96,    97,    98,     0,     0,     0,     0,     0,     0,    99,
     100,   101,   102,   103,   104,   105,     0,     0,     0,   106,
     107,   108,   109,   110,     0,     0,     0,     0,   111,   112,
     113,   114,   115,   116,   117,   118,     0,   119,     0,   120,
     121,     0,     0,   122,   123,   124,     0,     0,     0,   125,
       0,   126,   127,     0,   128,   129,   130,     0,   131,     0,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,     0,     0,   143,   144,   145,     0,   375,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,     0,   190,   191,   192,     0,   193,   194,   195,   196,
     197,   198,     0,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     4,     5,     6,     0,     0,     7,     0,     0,
       0,   792,   372,     0,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,   373,
      26,    27,    28,    29,     0,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,     0,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,     0,    67,    68,    69,    70,    71,    72,
      73,    74,     0,     0,    75,    76,     0,     0,     0,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
       0,     0,    88,     0,    89,    90,    91,    92,     0,    93,
       0,     0,     0,    94,    95,    96,    97,    98,     0,     0,
       0,     0,     0,     0,    99,   100,   101,   102,   103,   104,
     105,     0,     0,     0,   106,   107,   108,   109,   110,     0,
       0,     0,     0,   111,   112,   113,   114,   115,   116,   117,
     118,     0,   119,     0,   120,   121,     0,     0,   122,   123,
     124,     0,     0,     0,   125,     0,   126,   127,     0,   128,
     129,   130,     0,   131,     0,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,     0,     0,   143,   144,
     145,     0,   375,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,   192,
       0,   193,   194,   195,   196,   197,   198,     0,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,     1,     0,
       0,     0,     0,     0,     0,     2,     3,     4,     5,     6,
       0,     0,     7,     0,     0,     0,   371,   372,     0,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
     462,   463,    23,   465,   373,    26,   466,    28,    29,     0,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
     468,    41,    42,   469,     0,    44,    45,    46,   471,   472,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,     0,    67,
      68,    69,    70,    71,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,     0,     0,    88,     0,    89,
      90,    91,    92,     0,    93,     0,     0,     0,   480,    95,
      96,    97,    98,     0,     0,     0,     0,     0,     0,    99,
     100,   101,   102,   103,   104,   105,     0,     0,     0,   106,
     107,   108,   109,   110,     0,     0,     0,     0,   111,   112,
     113,   114,   115,   116,   117,   118,     0,   119,     0,   120,
     121,     0,     0,   122,   123,   124,     0,     0,     0,   125,
       0,   126,   127,     0,   128,   129,   130,     0,   131,     0,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,     0,     0,   143,   144,   145,     0,   375,   147,   148,
     149,   150,   151,   152,   153,   154,   489,   156,   490,   158,
     491,   492,   161,   162,   163,   164,   165,   166,   493,   168,
     494,   495,   496,   497,   173,   174,   498,   499,   177,   500,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,     0,   190,   191,   192,     0,   193,   194,   195,   196,
     197,   198,     0,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     4,     5,     6,     0,     0,     7,     0,     0,
       0,   996,   372,     0,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,   373,
      26,    27,    28,    29,     0,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,     0,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,     0,    67,    68,    69,    70,    71,    72,
      73,    74,     0,     0,    75,    76,     0,     0,     0,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
       0,     0,    88,     0,    89,    90,    91,    92,     0,    93,
       0,     0,     0,    94,    95,    96,    97,    98,     0,     0,
       0,     0,     0,     0,    99,   100,   101,   102,   103,   104,
     105,     0,     0,     0,   106,   107,   108,   109,   110,     0,
       0,     0,     0,   111,   112,   113,   114,   115,   116,   117,
     118,     0,   119,     0,   120,   121,     0,     0,   122,   123,
     124,     0,     0,     0,   125,     0,   126,   127,     0,   128,
     129,   130,     0,   131,     0,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,     0,     0,   143,   144,
     145,     0,   375,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,   192,
       0,   193,   194,   195,   196,   197,   198,     0,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,     1,     0,
       0,     0,     0,     0,     0,     2,     3,     4,     5,     6,
       0,     0,     7,     0,     0,     0,   371,   372,     0,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
     462,   463,    23,   465,   373,    26,   466,    28,    29,     0,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
     468,    41,    42,   469,     0,    44,    45,    46,   471,   472,
      49,   473,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,     0,    67,
      68,    69,    70,    71,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,     0,     0,    88,     0,    89,
      90,    91,    92,     0,    93,     0,     0,     0,   480,    95,
      96,    97,    98,     0,     0,     0,     0,     0,     0,    99,
     100,   101,   102,   103,   104,   105,     0,     0,     0,   106,
     107,     0,   109,   110,     0,     0,     0,     0,   111,   112,
     113,   114,   115,   116,   117,   118,     0,   119,     0,     0,
       0,     0,     0,   122,   123,   124,     0,     0,     0,   125,
       0,   126,   127,     0,   128,   129,   130,     0,   131,     0,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,     0,     0,   143,   144,   145,     0,   375,   147,   148,
     149,   150,   151,   152,   153,   154,   489,   156,   490,   158,
     491,   492,   161,   162,   163,   164,   165,   166,   493,   168,
     494,   495,   496,   497,   173,   174,   498,   499,   177,   500,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,     0,   190,   191,   192,     0,   193,   194,   195,   196,
     197,   198,     0,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     4,     5,     6,     0,     0,     7,     0,     0,
       0,   371,   372,     0,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,   462,   463,    23,   465,   373,
      26,   466,    28,    29,     0,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,   468,    41,    42,   469,     0,
      44,    45,    46,   471,   472,    49,   473,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,     0,    67,    68,    69,    70,    71,    72,
      73,    74,     0,     0,    75,    76,     0,     0,     0,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
       0,     0,    88,     0,    89,    90,    91,    92,     0,    93,
       0,     0,     0,   480,    95,    96,    97,    98,     0,     0,
       0,     0,     0,     0,    99,   100,   101,   102,   103,   104,
     105,     0,     0,     0,   106,   107,     0,   109,   110,     0,
       0,     0,     0,   111,   112,   113,   114,   115,   116,   117,
     118,     0,   119,     0,     0,     0,     0,     0,   122,   123,
     124,     0,     0,     0,   125,     0,   126,   127,     0,     0,
       0,   130,     0,   131,     0,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,     0,     0,   143,   144,
     145,     0,   375,   147,   148,   149,   150,   151,   152,   153,
     154,   489,   156,   490,   158,   491,   492,   161,   162,   163,
     164,   165,   166,   493,   168,   494,   495,   496,   497,   173,
     174,   498,   499,   177,   500,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,   192,
       0,   193,   194,   195,   196,   197,   198,     0,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,     1,     0,
       0,     0,     0,     0,     0,     2,     0,     0,     0,     6,
       0,     0,     0,     0,     0,     0,   371,   372,     0,    10,
      11,    12,   459,    14,    15,    16,    17,   460,    19,   461,
     462,   463,   464,   465,   373,    26,   466,    28,    29,     0,
      30,    31,    32,    33,    34,   467,    36,    37,    38,    39,
     468,    41,    42,   469,     0,    44,   470,    46,   471,   472,
      49,   473,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,   474,   475,    66,     0,    67,
      68,    69,   476,     0,    72,    73,    74,     0,     0,   477,
      76,     0,     0,     0,     0,    78,    79,    80,   478,   479,
      83,    84,     0,     0,     0,     0,     0,     0,     0,    89,
      90,    91,    92,     0,    93,     0,     0,     0,   480,    95,
      96,   481,   482,     0,     0,     0,     0,     0,     0,    99,
     100,   101,     0,   103,   104,   105,     0,     0,     0,     0,
       0,     0,   109,   110,     0,     0,     0,     0,   111,   112,
     113,   114,   483,   116,   117,   484,     0,     0,     0,     0,
       0,     0,     0,   485,   486,   124,     0,     0,     0,   125,
       0,   126,   487,     0,     0,     0,   130,     0,   131,     0,
     132,   133,   134,   135,   488,   137,   138,   139,   140,   141,
     142,     0,     0,   143,   144,     0,     0,   375,   147,   148,
     149,   150,   151,   152,   153,   154,   489,   156,   490,   158,
     491,   492,   161,   162,   163,   164,   165,   166,   493,   168,
     494,   495,   496,   497,   173,   174,   498,   499,   177,   500,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,     0,   190,   191,   192,     0,   193,   194,   195,   196,
     197,   198,     0,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,     1,     0,     0,     0,     0,     0,     0,
       2,     0,     0,     0,     6,     0,     0,     0,     0,     0,
       0,   371,   372,     0,    10,    11,    12,   507,    14,    15,
      16,    17,   460,   508,   509,   462,   463,   464,   465,   373,
      26,   466,    28,    29,     0,    30,    31,    32,    33,    34,
     510,    36,   511,   512,    39,   468,    41,    42,   469,     0,
      44,   513,    46,   471,   472,    49,   473,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
     474,   475,    66,     0,    67,    68,    69,   514,     0,    72,
      73,    74,     0,     0,   477,    76,     0,     0,     0,     0,
      78,    79,    80,   478,   479,    83,    84,     0,     0,     0,
       0,     0,     0,     0,    89,    90,    91,    92,     0,    93,
       0,     0,     0,   480,    95,    96,   481,   482,     0,     0,
       0,     0,     0,     0,    99,   100,   101,     0,   103,   104,
     105,     0,     0,     0,     0,     0,     0,   109,   110,     0,
       0,     0,     0,   111,   112,   113,   114,   483,   116,   117,
     484,     0,     0,     0,     0,     0,     0,     0,   485,   486,
     124,     0,     0,     0,   125,     0,   126,   487,     0,     0,
       0,   130,     0,   131,     0,   132,   133,   134,   135,   488,
     137,   138,   139,   140,   141,   142,     0,     0,   143,   144,
       0,     0,   375,   147,   148,   149,   150,   151,   152,   153,
     154,   489,   515,   490,   158,   491,   492,   161,   162,   163,
     164,   165,   166,   493,   168,   494,   495,   496,   497,   173,
     174,   498,   499,   177,   500,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,   192,
       0,   193,   194,   195,   196,   197,   198,     0,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   525,     0,
       0,     0,     0,     0,     0,     6,     0,     0,   728,     0,
       0,     0,   371,   372,     0,    10,    11,    12,   507,    14,
      15,    16,    17,   460,   508,   509,   462,   463,   464,   465,
     373,    26,   466,    28,    29,     0,    30,    31,    32,    33,
      34,   510,    36,   511,   512,    39,   468,    41,    42,   469,
       0,    44,   513,    46,   471,   472,    49,   473,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,   474,   475,    66,     0,    67,    68,    69,   514,     0,
      72,    73,    74,     0,     0,   477,    76,     0,     0,     0,
       0,    78,    79,    80,   478,   479,    83,    84,     0,     0,
       0,     0,     0,     0,     0,    89,    90,    91,    92,     0,
      93,     0,     0,     0,   480,    95,    96,   481,   482,     0,
       0,     0,     0,     0,     0,    99,   100,   101,     0,   103,
     104,   105,     0,     0,     0,     0,     0,     0,   109,   110,
       0,     0,     0,     0,   111,   112,   113,   114,   483,   116,
     117,   484,     0,     0,     0,     0,     0,     0,     0,   485,
     486,   124,     0,     0,     0,   125,   729,   126,   487,     0,
       0,     0,     0,     0,   131,     0,   132,   133,   134,   135,
     488,   137,   138,   139,   140,   141,   142,     0,     0,   143,
     144,     0,     0,   375,   147,   148,   149,   150,   151,   152,
     153,   154,   489,   515,   490,   158,   491,   492,   161,   162,
     163,   164,   165,   166,   493,   168,   494,   495,   496,   497,
     173,   174,   498,   499,   177,   500,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,     0,   190,   191,
     192,     0,   193,   194,   195,   196,   197,   198,     0,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   525,
       0,     0,     0,     0,     0,     0,     6,     0,     0,     0,
       0,     0,     0,   371,   372,     0,    10,    11,    12,   507,
      14,    15,    16,    17,   460,   508,   509,   462,   463,   464,
     465,   373,    26,   466,    28,    29,     0,    30,    31,    32,
      33,    34,   510,    36,   511,   512,    39,   468,    41,    42,
     469,     0,    44,   513,    46,   471,   472,    49,   473,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,   474,   475,    66,     0,    67,    68,    69,   514,
       0,    72,    73,    74,     0,     0,   477,    76,     0,     0,
       0,     0,    78,    79,    80,   478,   479,    83,    84,     0,
       0,     0,     0,     0,     0,     0,    89,    90,    91,    92,
       0,    93,     0,     0,     0,   480,    95,    96,   481,   482,
       0,     0,     0,     0,     0,     0,    99,   100,   101,     0,
     103,   104,   105,     0,     0,     0,     0,     0,     0,   109,
     110,     0,     0,     0,     0,   111,   112,   113,   114,   483,
     116,   117,   484,     0,     0,     0,     0,     0,     0,     0,
     485,   486,   124,     0,     0,     0,   125,     0,   126,   487,
       0,     0,     0,     0,     0,   131,     0,   132,   133,   134,
     135,   488,   137,   138,   139,   140,   141,   142,     0,     0,
     143,   144,     0,     0,   375,   147,   148,   149,   150,   151,
     152,   153,   154,   489,   515,   490,   158,   491,   492,   161,
     162,   163,   164,   165,   166,   493,   168,   494,   495,   496,
     497,   173,   174,   498,   499,   177,   500,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,   190,
     191,   192,     0,   193,   194,   195,   196,   197,   198,     0,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     528,     0,     0,     0,     0,     6,     0,     0,     0,     0,
       0,     0,   371,   372,     0,    10,    11,    12,   507,    14,
      15,    16,    17,   460,   508,   509,   462,   463,   464,   465,
     373,    26,   466,    28,    29,     0,    30,    31,    32,    33,
      34,   510,    36,   511,   512,    39,   468,    41,    42,   469,
       0,    44,   513,    46,   471,   472,    49,   473,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,   474,   475,    66,     0,    67,    68,    69,   514,     0,
      72,    73,    74,     0,     0,   477,    76,     0,     0,     0,
       0,    78,    79,    80,   478,   479,    83,    84,     0,     0,
       0,     0,     0,     0,     0,    89,    90,    91,    92,     0,
      93,     0,     0,     0,   480,    95,    96,   481,   482,     0,
       0,     0,     0,     0,     0,    99,   100,   101,     0,   103,
     104,   105,     0,     0,     0,     0,     0,     0,   109,   110,
       0,     0,     0,     0,   111,   112,   113,   114,   483,   116,
     117,   484,     0,     0,     0,     0,     0,     0,     0,   485,
     486,   124,     0,     0,     0,   125,     0,   126,   487,     0,
       0,     0,     0,     0,   131,     0,   132,   133,   134,   135,
     488,   137,   138,   139,   140,   141,   142,     0,     0,   143,
     144,     0,     0,   375,   147,   148,   149,   150,   151,   152,
     153,   154,   489,   515,   490,   158,   491,   492,   161,   162,
     163,   164,   165,   166,   493,   168,   494,   495,   496,   497,
     173,   174,   498,   499,   177,   500,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,     0,   190,   191,
     192,     0,   193,   194,   195,   196,   197,   198,     0,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,     6,
       0,     0,     0,     0,     0,     0,   371,   372,     0,    10,
      11,    12,   459,    14,    15,    16,    17,   460,    19,   461,
     462,   463,  1036,   465,   373,    26,   466,    28,    29,     0,
      30,    31,    32,    33,    34,   467,    36,    37,    38,    39,
     468,    41,    42,   469,     0,    44,   470,    46,   471,   472,
      49,   473,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,   474,   475,    66,     0,    67,
      68,    69,   476,     0,    72,    73,    74,     0,     0,   477,
      76,     0,     0,     0,     0,    78,    79,    80,   478,   479,
      83,    84,     0,     0,     0,     0,     0,     0,     0,    89,
      90,    91,    92,     0,    93,     0,     0,     0,   480,    95,
      96,   481,   482,     0,     0,     0,     0,     0,     0,    99,
     100,   101,     0,   103,   104,  1037,     0,     0,     0,  1038,
       0,     0,   109,   110,     0,     0,     0,     0,   111,   112,
     113,   114,   483,   116,   117,   484,     0,     0,     0,     0,
       0,     0,     0,   485,   486,   124,     0,     0,     0,   125,
    1434,   126,   487,     0,     0,     0,  1435,     0,   131,     0,
     132,   133,   134,   135,   488,   137,   138,   139,   140,   141,
     142,     0,     0,  1039,   144,     0,     0,   375,   147,   148,
     149,   150,   151,   152,   153,   154,   489,   156,   490,   158,
     491,   492,   161,   162,   163,   164,   165,   166,   493,   168,
     494,   495,   496,   497,   173,   174,   498,   499,   177,   500,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,     0,   190,   191,   192,     0,   193,   194,   195,   196,
     197,   198,     0,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,     6,     0,     0,     0,     0,     0,     0,
     371,   372,     0,    10,    11,    12,   507,    14,    15,    16,
      17,   460,   508,   509,   462,   463,   464,   465,   373,    26,
     466,    28,    29,     0,    30,    31,    32,    33,    34,   510,
      36,   511,   512,    39,   468,    41,    42,   469,     0,    44,
     513,    46,   471,   472,    49,   473,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,   474,
     475,    66,     0,    67,    68,    69,   514,     0,    72,    73,
      74,     0,     0,   477,    76,     0,     0,     0,     0,    78,
      79,    80,   478,   479,    83,    84,     0,     0,     0,     0,
       0,     0,     0,    89,    90,    91,    92,     0,    93,     0,
       0,     0,   480,    95,    96,   481,   482,     0,     0,     0,
       0,     0,     0,    99,   100,   101,     0,   103,   104,   105,
       0,     0,     0,     0,     0,     0,   109,   110,     0,     0,
       0,     0,   111,   112,   113,   114,   483,   116,   117,   484,
       0,     0,     0,     0,     0,     0,     0,   485,   486,   124,
       0,     0,     0,   125,   700,   126,   487,     0,     0,     0,
     701,     0,   131,     0,   132,   133,   134,   135,   488,   137,
     138,   139,   140,   141,   142,     0,     0,   143,   144,     0,
       0,   375,   147,   148,   149,   150,   151,   152,   153,   154,
     489,   515,   490,   158,   491,   492,   161,   162,   163,   164,
     165,   166,   493,   168,   494,   495,   496,   497,   173,   174,
     498,   499,   177,   500,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,     0,   190,   191,   192,     0,
     193,   194,   195,   196,   197,   198,     0,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,     6,     0,     0,
       0,     0,     0,     0,   371,   372,     0,    10,    11,    12,
     507,    14,    15,    16,    17,   460,   508,   509,   462,   463,
     464,   465,   373,    26,   466,    28,    29,     0,    30,    31,
      32,    33,    34,   510,    36,   511,   512,    39,   468,    41,
      42,   469,     0,    44,   513,    46,   471,   472,    49,   473,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,   474,   475,    66,     0,    67,    68,    69,
     514,     0,    72,    73,    74,     0,     0,   477,    76,     0,
       0,     0,     0,    78,    79,    80,   478,   479,    83,    84,
       0,     0,     0,     0,     0,     0,     0,    89,    90,    91,
      92,     0,    93,     0,     0,     0,   480,    95,    96,   481,
     482,     0,     0,     0,     0,     0,     0,    99,   100,   101,
       0,   103,   104,   105,     0,     0,     0,     0,     0,     0,
     109,   110,     0,     0,     0,     0,   111,   112,   113,   114,
     483,   116,   117,   484,     0,     0,     0,     0,     0,     0,
       0,   485,   486,   124,     0,     0,     0,   125,   747,   126,
     487,     0,     0,     0,   748,     0,   131,     0,   132,   133,
     134,   135,   488,   137,   138,   139,   140,   141,   142,     0,
       0,   143,   144,     0,     0,   375,   147,   148,   149,   150,
     151,   152,   153,   154,   489,   515,   490,   158,   491,   492,
     161,   162,   163,   164,   165,   166,   493,   168,   494,   495,
     496,   497,   173,   174,   498,   499,   177,   500,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,     0,
     190,   191,   192,     0,   193,   194,   195,   196,   197,   198,
       0,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,     6,     0,     0,     0,     0,     0,     0,   371,   372,
       0,    10,    11,    12,   459,    14,    15,    16,    17,   460,
      19,   461,   462,   463,  1036,   465,   373,    26,   466,    28,
      29,     0,    30,    31,    32,    33,    34,   467,    36,    37,
      38,    39,   468,    41,    42,   469,     0,    44,   470,    46,
     471,   472,    49,   473,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,   474,   475,    66,
       0,    67,    68,    69,   476,     0,    72,    73,    74,     0,
       0,   477,    76,     0,     0,     0,     0,    78,    79,    80,
     478,   479,    83,    84,  1364,     0,     0,     0,     0,     0,
       0,    89,    90,    91,    92,     0,    93,     0,     0,     0,
     480,    95,    96,   481,   482,     0,     0,     0,     0,     0,
       0,    99,   100,   101,     0,   103,   104,  1037,     0,     0,
       0,  1038,     0,     0,   109,   110,     0,     0,     0,     0,
     111,   112,   113,   114,   483,   116,   117,   484,     0,     0,
       0,     0,     0,     0,     0,   485,   486,   124,     0,     0,
       0,   125,     0,   126,   487,     0,     0,     0,     0,     0,
     131,     0,   132,   133,   134,   135,   488,   137,   138,   139,
     140,   141,   142,     0,     0,  1039,   144,     0,     0,   375,
     147,   148,   149,   150,   151,   152,   153,   154,   489,   156,
     490,   158,   491,   492,   161,   162,   163,   164,   165,   166,
     493,   168,   494,   495,   496,   497,   173,   174,   498,   499,
     177,   500,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,     0,   190,   191,   192,     0,   193,   194,
     195,   196,   197,   198,     0,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,     6,     0,     0,     0,     0,
       0,     0,   371,   372,     0,    10,    11,    12,   459,    14,
      15,    16,    17,   460,    19,   461,   462,   463,  1036,   465,
     373,    26,   466,    28,    29,     0,    30,    31,    32,    33,
      34,   467,    36,    37,    38,    39,   468,    41,    42,   469,
       0,    44,   470,    46,   471,   472,    49,   473,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,   474,   475,    66,     0,    67,    68,    69,   476,     0,
      72,    73,    74,     0,     0,   477,    76,     0,     0,     0,
       0,    78,    79,    80,   478,   479,    83,    84,     0,     0,
       0,     0,     0,     0,     0,    89,    90,    91,    92,     0,
      93,     0,     0,     0,   480,    95,    96,   481,   482,     0,
       0,     0,     0,     0,     0,    99,   100,   101,     0,   103,
     104,  1037,     0,     0,     0,  1038,     0,     0,   109,   110,
       0,     0,     0,     0,   111,   112,   113,   114,   483,   116,
     117,   484,     0,     0,     0,     0,     0,     0,     0,   485,
     486,   124,     0,     0,     0,   125,     0,   126,   487,     0,
       0,     0,     0,     0,   131,     0,   132,   133,   134,   135,
     488,   137,   138,   139,   140,   141,   142,     0,     0,  1039,
     144,     0,     0,   375,   147,   148,   149,   150,   151,   152,
     153,   154,   489,   156,   490,   158,   491,   492,   161,   162,
     163,   164,   165,   166,   493,   168,   494,   495,   496,   497,
     173,   174,   498,   499,   177,   500,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,     0,   190,   191,
     192,     0,   193,   194,   195,   196,   197,   198,     0,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,     6,
       0,     0,     0,     0,     0,     0,   371,   372,     0,    10,
      11,    12,   459,    14,    15,    16,    17,   460,    19,   461,
     462,   463,  1036,   465,   373,    26,   466,    28,    29,     0,
      30,    31,    32,    33,    34,   467,    36,    37,    38,    39,
     468,    41,    42,   469,     0,    44,   470,    46,   471,   472,
      49,   473,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,   474,   475,    66,     0,    67,
      68,    69,   476,     0,    72,    73,    74,     0,     0,   477,
      76,     0,     0,     0,     0,    78,    79,    80,   478,   479,
      83,    84,     0,     0,     0,     0,     0,     0,     0,    89,
      90,    91,    92,     0,    93,     0,     0,     0,   480,    95,
      96,   481,   482,     0,     0,     0,     0,     0,     0,    99,
     100,   101,     0,   103,   104,  1037,     0,     0,     0,  1038,
       0,     0,   109,   110,     0,     0,     0,     0,   111,   112,
     113,   114,   483,   116,   117,   484,     0,     0,     0,     0,
       0,     0,     0,   485,   486,   124,     0,     0,     0,   125,
       0,   126,   487,     0,     0,     0,     0,     0,   131,     0,
     132,   133,   134,   135,   488,   137,   138,   139,   140,   141,
     142,     0,     0,   143,   144,     0,     0,   375,   147,   148,
     149,   150,   151,   152,   153,   154,   489,   156,   490,   158,
     491,   492,   161,   162,   163,   164,   165,   166,   493,   168,
     494,   495,   496,   497,   173,   174,   498,   499,   177,   500,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,     0,   190,   191,   192,     0,   193,   194,   195,   196,
     197,   198,     0,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,     6,     0,     0,     0,     0,     0,     0,
     371,   372,     0,    10,    11,    12,   507,    14,    15,    16,
      17,   460,   508,   509,   462,   463,   464,   465,   373,    26,
     466,    28,    29,     0,    30,    31,    32,    33,    34,   510,
      36,   511,   512,    39,   468,    41,    42,   469,     0,    44,
     513,    46,   471,   472,    49,   473,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,   474,
     475,    66,     0,    67,    68,    69,   514,     0,    72,    73,
      74,     0,     0,   477,    76,     0,     0,     0,     0,    78,
      79,    80,   478,   479,    83,    84,     0,     0,     0,     0,
       0,     0,     0,    89,    90,    91,    92,     0,    93,     0,
       0,     0,   480,    95,    96,   481,   482,     0,     0,     0,
       0,     0,     0,    99,   100,   101,     0,   103,   104,   105,
       0,     0,     0,     0,     0,     0,   109,   110,     0,     0,
       0,     0,   111,   112,   113,   114,   483,   116,   117,   484,
       0,     0,     0,     0,     0,     0,     0,   485,   486,   124,
       0,     0,     0,   125,     0,   126,   487,     0,     0,     0,
       0,     0,   131,     0,   132,   133,   134,   135,   488,   137,
     138,   139,   140,   141,   142,     0,     0,   143,   144,     0,
       0,   375,   147,   148,   149,   150,   151,   152,   153,   154,
     489,   515,   490,   158,   491,   492,   161,   162,   163,   164,
     165,   166,   493,   168,   494,   495,   496,   497,   173,   174,
     498,   499,   177,   500,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,     0,   190,   191,   192,     0,
     193,   194,   195,   196,   197,   198,     0,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,     6,     0,     0,
       0,     0,     0,     0,   371,   372,     0,    10,    11,    12,
       0,    14,    15,    16,    17,   460,     0,     0,   462,   463,
     464,     0,   373,    26,   466,    28,    29,     0,    30,    31,
      32,    33,    34,     0,    36,     0,     0,    39,   468,    41,
      42,   469,     0,    44,     0,    46,     0,     0,    49,   473,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,   474,   475,    66,     0,    67,    68,    69,
       0,     0,    72,    73,    74,     0,     0,   477,    76,     0,
       0,     0,     0,    78,    79,    80,   478,   479,    83,    84,
       0,     0,     0,     0,     0,     0,     0,    89,    90,    91,
      92,     0,    93,     0,     0,     0,   480,    95,    96,   481,
     482,     0,     0,     0,     0,     0,     0,    99,   100,   101,
       0,   103,   104,     0,     0,     0,     0,     0,     0,     0,
     109,   110,     0,     0,     0,     0,   111,   112,   113,   114,
     483,   116,   117,   484,     0,     0,     0,     0,     0,     0,
       0,   485,   486,   124,     0,     0,     0,   125,     0,   126,
     487,     0,     0,     0,     0,     0,   131,     0,   132,   133,
     134,   135,   488,   137,   138,   139,   140,   141,   142,     0,
       0,     0,   144,     0,     0,   375,   147,   148,   149,   150,
     151,   152,   153,   154,   489,     0,   490,   158,   491,   492,
     161,   162,   163,   164,   165,   166,   493,   168,   494,   495,
     496,   497,   173,   174,     0,   499,   177,   500,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,     0,
     190,   191,   192,     0,   193,   194,   195,   196,   197,   198,
       0,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
        71,   610,   753,   726,   611,   612,   613,   614,   829,   830,
     644,   572,   310,   736,    85,   382,   708,  1108,   246,   247,
     245,   945,   566,   567,   129,  1224,   905,  1240,  1241,  1391,
     726,    25,   977,   830,    32,    71,   107,   396,   653,    32,
    1306,     1,  1022,     1,    94,   866,   564,   565,   119,    54,
     121,   866,     9,    10,  1197,    26,     3,     4,     5,     1,
     115,     1,   817,   422,     1,   104,     9,   104,   143,     1,
     437,   438,    92,   564,   565,   566,   567,     1,  1273,   900,
      42,    24,   441,   143,    52,   138,    97,    55,   104,    92,
     104,   104,     8,   115,    92,   104,    94,   104,    71,    61,
     921,    94,   126,   104,    33,    34,   999,    36,    37,    91,
      25,   144,    85,   107,   935,   165,    94,    92,   126,   212,
      94,   104,    94,   149,   921,    25,   120,    56,   161,    97,
     127,    30,   118,   156,   107,   138,   103,   590,   935,   592,
     593,   104,   595,   100,   597,   143,   119,   186,   121,   872,
     143,   145,   605,   606,    43,   149,   123,   250,   152,   106,
      59,   183,   119,   149,   121,   220,   152,   180,   192,   143,
     186,   182,   186,   154,  1067,   184,   119,   184,   121,   173,
     152,   110,   183,   817,   192,  1398,     5,   130,   133,   186,
       9,   172,   149,   230,   269,   110,   153,   179,   248,   249,
     183,   251,     9,    10,   149,   928,   149,   212,   313,   269,
     149,   934,   232,   170,    92,   104,   269,  1038,   268,   104,
     183,   183,   973,  1038,  1315,  1104,   186,   156,   186,   925,
     280,   927,  1375,   190,  1158,   927,   851,   852,   209,   783,
     784,   156,    94,  1188,   186,   250,   186,   318,   303,   186,
     321,   208,  1197,   949,   186,   171,   156,   232,  1453,    92,
     115,   255,   186,   781,   782,  1627,   269,  1022,  1023,  1249,
    1536,   269,     9,   104,   252,   253,   269,   104,   152,   247,
      92,  1643,   318,    50,   265,   321,   215,    24,   152,  1651,
    1111,   272,   260,   100,   262,    25,   104,    92,   183,   666,
     119,   282,   121,   132,  1503,   273,   274,   275,   103,   277,
     129,   279,   119,   165,   121,   386,   387,   146,    94,   104,
      94,   392,   132,   115,   104,   396,  1539,   182,   257,  1150,
     149,   402,   104,   561,   110,   213,   214,   149,   409,   564,
     565,   104,   149,    92,   115,   318,   153,   104,   321,    94,
     228,   422,   183,  1150,  1175,   722,   183,   428,   125,   718,
     813,   432,   721,   170,    92,   110,  1457,  1580,   439,   143,
     441,   442,   443,   444,   445,   183,   152,   107,  1175,   450,
     213,   214,   119,   190,   121,   149,   196,   458,  1022,  1023,
     120,  1114,    92,   130,   143,   228,   248,   249,   183,   251,
      23,   208,    38,   183,   216,   217,   258,   152,    44,   173,
     138,   183,   149,    49,   387,   145,   268,     9,    10,   392,
     183,     5,    45,   396,  1058,     9,   183,    25,   280,   402,
    1375,  1123,    68,   165,   154,  1314,   409,  1133,   196,    62,
      65,    64,   914,   143,   916,    70,   517,   205,    51,   422,
      73,    92,   172,  1544,    57,   428,   140,   149,   295,   432,
    1281,   863,  1006,  1007,  1008,   197,   439,   304,   441,   442,
     443,   444,   445,   875,   194,   546,   423,   450,   425,    42,
     427,   173,    45,   554,  1281,   458,   109,  1578,   172,   436,
     115,    94,   133,   440,  1249,   114,   968,   138,   970,   446,
     178,   448,   449,  1258,   451,   189,   873,   874,   100,   107,
     457,   878,   154,   191,  1269,  1006,  1007,  1008,   149,     9,
      10,   152,   120,   142,   629,   630,   144,   119,   164,   121,
     172,   167,   243,   244,   115,   119,   155,   121,   152,    93,
     103,   908,    29,   161,   517,   129,   182,   145,  1639,   103,
    1641,   149,   194,  1477,   152,   266,   781,   149,   786,   113,
      47,   153,    29,   162,    42,   149,  1657,    45,   115,   123,
     189,   207,   154,   546,   205,   173,   523,    35,   170,   178,
      47,   554,   118,    41,    42,   259,   657,   534,   659,   133,
     172,   662,   220,   133,   222,   165,   270,   264,   190,    77,
      58,   164,    60,    61,   271,   149,   553,  1557,  1558,   149,
     100,    69,   683,   684,   685,  1249,   208,    94,   149,   178,
     152,   152,  1373,    97,  1258,   103,  1377,   197,    51,   119,
     118,   121,   191,   110,    57,  1269,   110,    95,   709,   265,
     711,  1333,   259,  1593,    97,   152,   272,   718,    51,  1599,
     721,  1260,    75,   270,    57,   225,   282,   110,   152,   149,
     273,   274,   275,   153,   220,  1388,   279,   133,   133,   225,
    1425,    94,   138,   138,   216,   217,   218,   320,   118,   626,
     170,   752,   325,   152,   631,  1229,   164,   149,   632,   662,
     152,   635,   115,   149,   638,   149,   152,   220,   152,   222,
     190,  1522,   150,  1524,   152,   227,   227,   229,   229,   118,
     683,   684,   685,   283,   284,   285,   286,   287,   208,   289,
     290,   291,   292,   293,   118,  1522,  1024,  1524,   298,   118,
     801,   118,  1553,   124,   125,  1296,   709,   149,   711,  1490,
     187,   188,  1493,   296,   297,   718,   296,   297,   721,   287,
     288,   124,   125,  1574,   608,   609,  1553,   118,   829,   830,
     831,   832,   220,   118,   615,   616,   831,   832,   715,   617,
     618,  1444,  1445,   118,   118,   149,   211,  1574,   220,   752,
     152,   115,   149,   238,   152,   237,  1153,   237,   115,   149,
       0,  1425,   163,    90,   245,   866,    48,   744,   745,   195,
      98,   150,  1409,    99,   141,   152,   152,  1416,  1417,   880,
    1561,   180,    25,    45,   180,   180,  1539,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,   774,   801,    45,
      45,    23,   148,   115,   242,   294,   907,   294,   115,   300,
     289,   183,   280,   914,   280,   916,   149,   183,   149,   149,
     921,   183,    31,    45,    16,   209,   829,   830,   831,   832,
     152,   152,   152,    55,   935,   128,   152,   152,    25,  1236,
      62,   183,    64,   136,   137,   226,   139,     3,   138,   115,
     164,    73,    69,   166,   147,    77,   166,   226,   151,    92,
     153,    92,    92,   866,   145,   158,   104,   968,   104,   970,
      25,  1510,  1511,   156,   123,   128,   156,   880,   115,   242,
     295,   128,   175,   180,   180,   183,   108,   109,   110,   104,
      92,   183,   180,   180,   183,    94,    42,    94,   104,   183,
     232,   180,   180,   138,   907,   198,   199,   200,   201,   202,
     203,   914,   183,   916,   183,   183,  1017,   149,   921,   183,
     183,   180,   180,   180,   180,    92,   138,    29,   183,   180,
     115,  1570,   935,   181,   220,   128,   180,  1038,   166,    92,
     138,    25,   282,   165,   295,   222,   149,   115,   123,   115,
     115,   250,  1349,   143,   115,    92,   180,   128,   128,   193,
     156,    94,   138,   115,   115,   968,   149,   970,    97,   143,
      97,   149,   180,   180,    31,   197,    25,   115,    77,   115,
     180,   241,   104,   115,   104,   149,   963,   254,   263,   152,
     152,   256,   152,   140,    25,    25,   281,    25,   302,   222,
     186,   222,   222,   225,   183,  1402,   282,   232,   143,   283,
     183,   183,   140,   123,  1017,   115,    75,   143,   143,   115,
     138,  1122,   104,   180,  1125,   183,  1127,   128,     7,   183,
     103,   232,   103,   183,   228,  1038,   246,   186,   182,   228,
    1141,   180,   183,   282,  1021,   143,   228,   228,    25,  1150,
      76,   246,   278,   183,    25,    94,   180,   166,   143,  1160,
     183,   283,   284,   285,   286,   287,  1167,   289,   290,   291,
     292,   293,   183,   253,  1175,   180,   298,   299,   143,   267,
     122,    94,   149,   180,    92,   276,   180,   182,  1065,   182,
     180,   180,   183,  1194,    25,   183,   166,   104,   143,   283,
      51,    92,   138,   115,    92,   192,    25,   104,   220,   115,
     115,   192,   192,   261,  1215,   115,   182,  1218,   180,  1122,
     192,   182,  1125,  1224,  1127,    91,   179,  1228,   220,   115,
     115,   149,   301,   115,   194,   429,   183,   220,  1141,  1116,
     115,   245,   301,   665,   289,  1071,   867,  1150,  1111,   283,
    1544,  1578,  1220,   239,   936,   416,   933,  1160,   301,  1343,
     302,   390,   302,   242,  1167,   242,   416,  1122,   285,  1228,
    1245,   302,  1175,   414,  1160,   588,  1142,  1013,  1243,  1240,
    1281,   435,   517,  1167,   589,  1176,   640,  1172,  1165,  1188,
     306,  1194,  1599,   753,  1593,   832,  1105,   916,  1070,   426,
    1215,  1258,  1425,  1225,  1181,  1269,  1023,   426,  1422,  1032,
     899,  1312,  1215,  1262,  1093,  1218,  1304,  1447,    -1,  1259,
      -1,  1224,    -1,    -1,    -1,  1228,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1340,
    1341,    -1,    -1,    -1,   538,   539,    -1,   541,   542,   543,
     544,    -1,    -1,    -1,    -1,    -1,    -1,   551,   552,    -1,
      -1,    -1,    -1,  1364,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1374,    -1,   569,   570,  1378,  1281,    -1,
      -1,    -1,    -1,    -1,    -1,   579,   580,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1312,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1340,  1341,    -1,
      -1,    -1,    -1,   637,    -1,    -1,   640,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1364,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1374,    -1,    -1,    -1,  1378,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1486,    -1,    -1,    -1,    -1,
    1491,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1503,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1522,    -1,  1524,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1540,
      -1,    -1,  1543,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1553,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1566,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1574,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1582,    -1,  1486,    -1,    -1,  1587,    -1,  1491,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1503,    -1,    -1,   797,    -1,    -1,    -1,    -1,    -1,   803,
      -1,    -1,    -1,  1614,    -1,    -1,    -1,    -1,    -1,  1522,
      -1,  1524,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1631,    -1,  1633,    -1,    -1,    -1,    -1,  1540,    -1,    -1,
    1543,    -1,    -1,  1520,    -1,  1646,    -1,    -1,    -1,  1650,
    1553,    -1,    -1,    -1,  1655,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1566,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1574,    -1,    -1,   868,    -1,    -1,    -1,    -1,  1582,
      -1,    -1,    -1,    -1,  1587,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1614,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    23,    -1,  1631,   923,
    1633,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    36,
      37,    -1,    -1,  1646,    -1,    -1,    -1,  1650,    45,    -1,
      -1,    -1,  1655,   947,    -1,    -1,    -1,    -1,    55,    56,
      -1,   955,    -1,   957,   958,    62,    -1,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,   972,    -1,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   983,
     984,   985,    -1,   987,   988,   989,   990,   991,   992,    -1,
     994,   995,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   108,   109,   110,    -1,    -1,    -1,    -1,    -1,  1013,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,
      -1,  1055,    -1,    -1,    -1,    -1,    -1,    -1,   165,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     197,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   215,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,    -1,
      -1,    -1,    -1,    -1,  1128,    -1,  1130,    -1,  1132,    -1,
      -1,  1135,    -1,    -1,    -1,    -1,  1140,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1152,    -1,
     257,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1162,  1163,
      -1,    -1,    -1,    -1,    -1,    -1,  1170,  1171,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   283,   284,   285,   286,
     287,    -1,   289,   290,   291,   292,   293,    -1,    -1,    -1,
      -1,   298,   299,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1227,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1243,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1326,    -1,    -1,    -1,    -1,  1331,    -1,    -1,
      -1,  1335,    -1,  1337,    -1,  1339,    -1,    -1,    -1,    -1,
      -1,  1345,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1354,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1362,  1363,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1381,  1382,  1383,
    1384,  1385,    -1,  1387,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1464,    -1,  1466,    -1,    -1,  1469,    -1,    -1,    -1,    -1,
      -1,    -1,  1476,    -1,    -1,    -1,    -1,  1481,    -1,    -1,
      -1,  1485,    -1,  1487,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1500,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1547,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1565,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1589,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1612,    -1,
      -1,    -1,    11,  1617,    -1,    -1,    -1,    -1,    -1,    18,
      19,    20,    21,    22,    -1,    -1,    25,    -1,    -1,    -1,
      29,    30,  1636,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    -1,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    -1,    92,    93,    94,    95,    96,    97,    98,
      99,    -1,    -1,   102,   103,    -1,    -1,    -1,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,    -1,
      -1,   120,    -1,   122,   123,   124,   125,    -1,   127,    -1,
      -1,    -1,   131,   132,   133,   134,   135,    -1,    -1,    -1,
      -1,    -1,    -1,   142,   143,   144,   145,   146,   147,   148,
      -1,    -1,    -1,   152,   153,   154,   155,   156,    -1,    -1,
      -1,    -1,   161,   162,   163,   164,   165,   166,   167,   168,
      -1,   170,    -1,   172,   173,    -1,    -1,   176,   177,   178,
      -1,    -1,    -1,   182,    -1,   184,   185,    -1,   187,   188,
     189,    -1,   191,    -1,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,    -1,    -1,   206,   207,   208,
      -1,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,    -1,   255,   256,   257,    -1,
     259,   260,   261,   262,   263,   264,    -1,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    19,    20,    21,    22,
      -1,    -1,    25,    -1,    -1,    -1,    29,    30,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    -1,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    -1,    92,
      93,    94,    95,    96,    97,    98,    99,    -1,    -1,   102,
     103,    -1,    -1,    -1,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,    -1,    -1,   120,    -1,   122,
     123,   124,   125,    -1,   127,    -1,    -1,    -1,   131,   132,
     133,   134,   135,    -1,    -1,    -1,    -1,    -1,    -1,   142,
     143,   144,   145,   146,   147,   148,    -1,    -1,    -1,   152,
     153,   154,   155,   156,    -1,    -1,    -1,    -1,   161,   162,
     163,   164,   165,   166,   167,   168,    -1,   170,    -1,   172,
     173,    -1,    -1,   176,   177,   178,    -1,   180,    -1,   182,
      -1,   184,   185,    -1,   187,   188,   189,    -1,   191,    -1,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,    -1,    -1,   206,   207,   208,    -1,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,    -1,   255,   256,   257,    -1,   259,   260,   261,   262,
     263,   264,    -1,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    19,    20,    21,    22,    -1,    -1,    25,    -1,    -1,
      -1,    29,    30,    -1,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    -1,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    -1,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    -1,    92,    93,    94,    95,    96,    97,
      98,    99,    -1,    -1,   102,   103,    -1,    -1,    -1,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
      -1,    -1,   120,    -1,   122,   123,   124,   125,    -1,   127,
      -1,    -1,    -1,   131,   132,   133,   134,   135,    -1,    -1,
      -1,    -1,    -1,    -1,   142,   143,   144,   145,   146,   147,
     148,    -1,    -1,    -1,   152,   153,   154,   155,   156,    -1,
      -1,    -1,    -1,   161,   162,   163,   164,   165,   166,   167,
     168,    -1,   170,    -1,   172,   173,    -1,    -1,   176,   177,
     178,    -1,   180,    -1,   182,    -1,   184,   185,    -1,   187,
     188,   189,    -1,   191,    -1,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,    -1,    -1,   206,   207,
     208,    -1,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,    -1,   255,   256,   257,
      -1,   259,   260,   261,   262,   263,   264,    -1,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    19,    20,    21,    22,
      -1,    -1,    25,    -1,    -1,    -1,    29,    30,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    -1,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    -1,    92,
      93,    94,    95,    96,    97,    98,    99,    -1,    -1,   102,
     103,    -1,    -1,    -1,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,    -1,    -1,   120,    -1,   122,
     123,   124,   125,    -1,   127,    -1,    -1,    -1,   131,   132,
     133,   134,   135,    -1,    -1,    -1,    -1,    -1,    -1,   142,
     143,   144,   145,   146,   147,   148,    -1,    -1,    -1,   152,
     153,   154,   155,   156,    -1,    -1,    -1,    -1,   161,   162,
     163,   164,   165,   166,   167,   168,    -1,   170,    -1,   172,
     173,    -1,    -1,   176,   177,   178,    -1,   180,    -1,   182,
      -1,   184,   185,    -1,   187,   188,   189,    -1,   191,    -1,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,    -1,    -1,   206,   207,   208,    -1,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,    -1,   255,   256,   257,    -1,   259,   260,   261,   262,
     263,   264,    -1,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    19,    20,    21,    22,    -1,    -1,    25,    -1,    -1,
      -1,    29,    30,    -1,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    -1,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    -1,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    -1,    92,    93,    94,    95,    96,    97,
      98,    99,    -1,    -1,   102,   103,    -1,    -1,    -1,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
      -1,    -1,   120,    -1,   122,   123,   124,   125,    -1,   127,
      -1,    -1,    -1,   131,   132,   133,   134,   135,    -1,    -1,
      -1,    -1,    -1,    -1,   142,   143,   144,   145,   146,   147,
     148,    -1,    -1,    -1,   152,   153,   154,   155,   156,    -1,
      -1,    -1,    -1,   161,   162,   163,   164,   165,   166,   167,
     168,    -1,   170,    -1,   172,   173,    -1,    -1,   176,   177,
     178,    -1,    -1,    -1,   182,   183,   184,   185,    -1,   187,
     188,   189,    -1,   191,    -1,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,    -1,    -1,   206,   207,
     208,    -1,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,    -1,   255,   256,   257,
      -1,   259,   260,   261,   262,   263,   264,    -1,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    19,    20,    21,    22,
      -1,    -1,    25,    -1,    -1,    -1,    29,    30,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    -1,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    -1,    92,
      93,    94,    95,    96,    97,    98,    99,    -1,    -1,   102,
     103,    -1,    -1,    -1,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,    -1,    -1,   120,    -1,   122,
     123,   124,   125,    -1,   127,    -1,    -1,    -1,   131,   132,
     133,   134,   135,    -1,    -1,    -1,    -1,    -1,    -1,   142,
     143,   144,   145,   146,   147,   148,    -1,    -1,    -1,   152,
     153,   154,   155,   156,    -1,    -1,    -1,    -1,   161,   162,
     163,   164,   165,   166,   167,   168,    -1,   170,    -1,   172,
     173,    -1,    -1,   176,   177,   178,    -1,   180,    -1,   182,
      -1,   184,   185,    -1,   187,   188,   189,    -1,   191,    -1,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,    -1,    -1,   206,   207,   208,    -1,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,    -1,   255,   256,   257,    -1,   259,   260,   261,   262,
     263,   264,    -1,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    19,    20,    21,    22,    -1,    -1,    25,    -1,    -1,
      -1,    29,    30,    -1,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    -1,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    -1,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    -1,    92,    93,    94,    95,    96,    97,
      98,    99,    -1,    -1,   102,   103,    -1,    -1,    -1,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
      -1,    -1,   120,    -1,   122,   123,   124,   125,    -1,   127,
      -1,    -1,    -1,   131,   132,   133,   134,   135,    -1,    -1,
      -1,    -1,    -1,    -1,   142,   143,   144,   145,   146,   147,
     148,    -1,    -1,    -1,   152,   153,   154,   155,   156,    -1,
      -1,    -1,    -1,   161,   162,   163,   164,   165,   166,   167,
     168,    -1,   170,    -1,   172,   173,    -1,    -1,   176,   177,
     178,    -1,    -1,    -1,   182,   183,   184,   185,    -1,   187,
     188,   189,    -1,   191,    -1,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,    -1,    -1,   206,   207,
     208,    -1,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,    -1,   255,   256,   257,
      -1,   259,   260,   261,   262,   263,   264,    -1,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    19,    20,    21,    22,
      -1,    -1,    25,    -1,    -1,    -1,    29,    30,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    -1,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    -1,    92,
      93,    94,    95,    96,    97,    98,    99,    -1,    -1,   102,
     103,    -1,    -1,    -1,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,    -1,    -1,   120,    -1,   122,
     123,   124,   125,    -1,   127,    -1,    -1,    -1,   131,   132,
     133,   134,   135,    -1,    -1,    -1,    -1,    -1,    -1,   142,
     143,   144,   145,   146,   147,   148,    -1,    -1,    -1,   152,
     153,   154,   155,   156,    -1,    -1,    -1,    -1,   161,   162,
     163,   164,   165,   166,   167,   168,    -1,   170,    -1,   172,
     173,    -1,    -1,   176,   177,   178,    -1,    -1,    -1,   182,
     183,   184,   185,    -1,   187,   188,   189,    -1,   191,    -1,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,    -1,    -1,   206,   207,   208,    -1,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,    -1,   255,   256,   257,    -1,   259,   260,   261,   262,
     263,   264,    -1,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    19,    20,    21,    22,    -1,    -1,    25,    -1,    -1,
      -1,    29,    30,    -1,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    -1,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    -1,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    -1,    92,    93,    94,    95,    96,    97,
      98,    99,    -1,    -1,   102,   103,    -1,    -1,    -1,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
      -1,    -1,   120,    -1,   122,   123,   124,   125,    -1,   127,
      -1,    -1,    -1,   131,   132,   133,   134,   135,    -1,    -1,
      -1,    -1,    -1,    -1,   142,   143,   144,   145,   146,   147,
     148,    -1,    -1,    -1,   152,   153,   154,   155,   156,    -1,
      -1,    -1,    -1,   161,   162,   163,   164,   165,   166,   167,
     168,    -1,   170,    -1,   172,   173,    -1,    -1,   176,   177,
     178,    -1,   180,    -1,   182,    -1,   184,   185,    -1,   187,
     188,   189,    -1,   191,    -1,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,    -1,    -1,   206,   207,
     208,    -1,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,    -1,   255,   256,   257,
      -1,   259,   260,   261,   262,   263,   264,    -1,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    19,    20,    21,    22,
      -1,    -1,    25,    -1,    -1,    -1,    29,    30,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    -1,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    -1,    92,
      93,    94,    95,    96,    97,    98,    99,    -1,    -1,   102,
     103,    -1,    -1,    -1,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,    -1,    -1,   120,    -1,   122,
     123,   124,   125,    -1,   127,    -1,    -1,    -1,   131,   132,
     133,   134,   135,    -1,    -1,    -1,    -1,    -1,    -1,   142,
     143,   144,   145,   146,   147,   148,    -1,    -1,    -1,   152,
     153,   154,   155,   156,    -1,    -1,    -1,    -1,   161,   162,
     163,   164,   165,   166,   167,   168,    -1,   170,    -1,   172,
     173,    -1,    -1,   176,   177,   178,    -1,   180,    -1,   182,
      -1,   184,   185,    -1,   187,   188,   189,    -1,   191,    -1,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,    -1,    -1,   206,   207,   208,    -1,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,    -1,   255,   256,   257,    -1,   259,   260,   261,   262,
     263,   264,    -1,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    19,    20,    21,    22,    -1,    -1,    25,    -1,    -1,
      -1,    29,    30,    -1,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    -1,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    -1,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    -1,    92,    93,    94,    95,    96,    97,
      98,    99,    -1,    -1,   102,   103,    -1,    -1,    -1,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
      -1,    -1,   120,    -1,   122,   123,   124,   125,    -1,   127,
      -1,    -1,    -1,   131,   132,   133,   134,   135,    -1,    -1,
      -1,    -1,    -1,    -1,   142,   143,   144,   145,   146,   147,
     148,    -1,    -1,    -1,   152,   153,   154,   155,   156,    -1,
      -1,    -1,    -1,   161,   162,   163,   164,   165,   166,   167,
     168,    -1,   170,    -1,   172,   173,    -1,    -1,   176,   177,
     178,    -1,   180,    -1,   182,    -1,   184,   185,    -1,   187,
     188,   189,    -1,   191,    -1,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,    -1,    -1,   206,   207,
     208,    -1,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,    -1,   255,   256,   257,
      -1,   259,   260,   261,   262,   263,   264,    -1,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    19,    20,    21,    22,
      -1,    -1,    25,    -1,    -1,    -1,    29,    30,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    -1,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    -1,    92,
      93,    94,    95,    96,    97,    98,    99,    -1,    -1,   102,
     103,    -1,    -1,    -1,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,    -1,    -1,   120,    -1,   122,
     123,   124,   125,    -1,   127,    -1,    -1,    -1,   131,   132,
     133,   134,   135,    -1,    -1,    -1,    -1,    -1,    -1,   142,
     143,   144,   145,   146,   147,   148,    -1,    -1,    -1,   152,
     153,   154,   155,   156,    -1,    -1,    -1,    -1,   161,   162,
     163,   164,   165,   166,   167,   168,    -1,   170,    -1,   172,
     173,    -1,    -1,   176,   177,   178,    -1,    -1,    -1,   182,
      -1,   184,   185,    -1,   187,   188,   189,    -1,   191,    -1,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,    -1,    -1,   206,   207,   208,    -1,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,    -1,   255,   256,   257,    -1,   259,   260,   261,   262,
     263,   264,    -1,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    19,    20,    21,    22,    -1,    -1,    25,    -1,    -1,
      -1,    29,    30,    -1,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    -1,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    -1,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    -1,    92,    93,    94,    95,    96,    97,
      98,    99,    -1,    -1,   102,   103,    -1,    -1,    -1,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
      -1,    -1,   120,    -1,   122,   123,   124,   125,    -1,   127,
      -1,    -1,    -1,   131,   132,   133,   134,   135,    -1,    -1,
      -1,    -1,    -1,    -1,   142,   143,   144,   145,   146,   147,
     148,    -1,    -1,    -1,   152,   153,   154,   155,   156,    -1,
      -1,    -1,    -1,   161,   162,   163,   164,   165,   166,   167,
     168,    -1,   170,    -1,   172,   173,    -1,    -1,   176,   177,
     178,    -1,    -1,    -1,   182,    -1,   184,   185,    -1,   187,
     188,   189,    -1,   191,    -1,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,    -1,    -1,   206,   207,
     208,    -1,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,    -1,   255,   256,   257,
      -1,   259,   260,   261,   262,   263,   264,    -1,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    19,    20,    21,    22,
      -1,    -1,    25,    -1,    -1,    -1,    29,    30,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    -1,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    -1,    92,
      93,    94,    95,    96,    97,    98,    99,    -1,    -1,   102,
     103,    -1,    -1,    -1,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,    -1,    -1,   120,    -1,   122,
     123,   124,   125,    -1,   127,    -1,    -1,    -1,   131,   132,
     133,   134,   135,    -1,    -1,    -1,    -1,    -1,    -1,   142,
     143,   144,   145,   146,   147,   148,    -1,    -1,    -1,   152,
     153,   154,   155,   156,    -1,    -1,    -1,    -1,   161,   162,
     163,   164,   165,   166,   167,   168,    -1,   170,    -1,   172,
     173,    -1,    -1,   176,   177,   178,    -1,    -1,    -1,   182,
      -1,   184,   185,    -1,   187,   188,   189,    -1,   191,    -1,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,    -1,    -1,   206,   207,   208,    -1,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,    -1,   255,   256,   257,    -1,   259,   260,   261,   262,
     263,   264,    -1,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    19,    20,    21,    22,    -1,    -1,    25,    -1,    -1,
      -1,    29,    30,    -1,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    -1,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    -1,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    -1,    92,    93,    94,    95,    96,    97,
      98,    99,    -1,    -1,   102,   103,    -1,    -1,    -1,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
      -1,    -1,   120,    -1,   122,   123,   124,   125,    -1,   127,
      -1,    -1,    -1,   131,   132,   133,   134,   135,    -1,    -1,
      -1,    -1,    -1,    -1,   142,   143,   144,   145,   146,   147,
     148,    -1,    -1,    -1,   152,   153,   154,   155,   156,    -1,
      -1,    -1,    -1,   161,   162,   163,   164,   165,   166,   167,
     168,    -1,   170,    -1,   172,   173,    -1,    -1,   176,   177,
     178,    -1,    -1,    -1,   182,    -1,   184,   185,    -1,   187,
     188,   189,    -1,   191,    -1,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,    -1,    -1,   206,   207,
     208,    -1,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,    -1,   255,   256,   257,
      -1,   259,   260,   261,   262,   263,   264,    -1,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    19,    20,    21,    22,
      -1,    -1,    25,    -1,    -1,    -1,    29,    30,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    -1,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    -1,    92,
      93,    94,    95,    96,    97,    98,    99,    -1,    -1,   102,
     103,    -1,    -1,    -1,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,    -1,    -1,   120,    -1,   122,
     123,   124,   125,    -1,   127,    -1,    -1,    -1,   131,   132,
     133,   134,   135,    -1,    -1,    -1,    -1,    -1,    -1,   142,
     143,   144,   145,   146,   147,   148,    -1,    -1,    -1,   152,
     153,   154,   155,   156,    -1,    -1,    -1,    -1,   161,   162,
     163,   164,   165,   166,   167,   168,    -1,   170,    -1,   172,
     173,    -1,    -1,   176,   177,   178,    -1,    -1,    -1,   182,
      -1,   184,   185,    -1,   187,   188,   189,    -1,   191,    -1,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,    -1,    -1,   206,   207,   208,    -1,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,    -1,   255,   256,   257,    -1,   259,   260,   261,   262,
     263,   264,    -1,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    19,    20,    21,    22,    -1,    -1,    25,    -1,    -1,
      -1,    29,    30,    -1,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    -1,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    -1,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    -1,    92,    93,    94,    95,    96,    97,
      98,    99,    -1,    -1,   102,   103,    -1,    -1,    -1,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
      -1,    -1,   120,    -1,   122,   123,   124,   125,    -1,   127,
      -1,    -1,    -1,   131,   132,   133,   134,   135,    -1,    -1,
      -1,    -1,    -1,    -1,   142,   143,   144,   145,   146,   147,
     148,    -1,    -1,    -1,   152,   153,   154,   155,   156,    -1,
      -1,    -1,    -1,   161,   162,   163,   164,   165,   166,   167,
     168,    -1,   170,    -1,   172,   173,    -1,    -1,   176,   177,
     178,    -1,    -1,    -1,   182,    -1,   184,   185,    -1,   187,
     188,   189,    -1,   191,    -1,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,    -1,    -1,   206,   207,
     208,    -1,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,    -1,   255,   256,   257,
      -1,   259,   260,   261,   262,   263,   264,    -1,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    19,    20,    21,    22,
      -1,    -1,    25,    -1,    -1,    -1,    29,    30,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    -1,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    -1,    92,
      93,    94,    95,    96,    97,    98,    99,    -1,    -1,   102,
     103,    -1,    -1,    -1,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,    -1,    -1,   120,    -1,   122,
     123,   124,   125,    -1,   127,    -1,    -1,    -1,   131,   132,
     133,   134,   135,    -1,    -1,    -1,    -1,    -1,    -1,   142,
     143,   144,   145,   146,   147,   148,    -1,    -1,    -1,   152,
     153,   154,   155,   156,    -1,    -1,    -1,    -1,   161,   162,
     163,   164,   165,   166,   167,   168,    -1,   170,    -1,   172,
     173,    -1,    -1,   176,   177,   178,    -1,    -1,    -1,   182,
      -1,   184,   185,    -1,   187,   188,   189,    -1,   191,    -1,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,    -1,    -1,   206,   207,   208,    -1,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,    -1,   255,   256,   257,    -1,   259,   260,   261,   262,
     263,   264,    -1,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    19,    20,    21,    22,    -1,    -1,    25,    -1,    -1,
      -1,    29,    30,    -1,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    -1,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    -1,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    -1,    92,    93,    94,    95,    96,    97,
      98,    99,    -1,    -1,   102,   103,    -1,    -1,    -1,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
      -1,    -1,   120,    -1,   122,   123,   124,   125,    -1,   127,
      -1,    -1,    -1,   131,   132,   133,   134,   135,    -1,    -1,
      -1,    -1,    -1,    -1,   142,   143,   144,   145,   146,   147,
     148,    -1,    -1,    -1,   152,   153,   154,   155,   156,    -1,
      -1,    -1,    -1,   161,   162,   163,   164,   165,   166,   167,
     168,    -1,   170,    -1,   172,   173,    -1,    -1,   176,   177,
     178,    -1,    -1,    -1,   182,    -1,   184,   185,    -1,   187,
     188,   189,    -1,   191,    -1,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,    -1,    -1,   206,   207,
     208,    -1,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,    -1,   255,   256,   257,
      -1,   259,   260,   261,   262,   263,   264,    -1,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    19,    20,    21,    22,
      -1,    -1,    25,    -1,    -1,    -1,    29,    30,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    -1,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    -1,    92,
      93,    94,    95,    96,    97,    98,    99,    -1,    -1,   102,
     103,    -1,    -1,    -1,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,    -1,    -1,   120,    -1,   122,
     123,   124,   125,    -1,   127,    -1,    -1,    -1,   131,   132,
     133,   134,   135,    -1,    -1,    -1,    -1,    -1,    -1,   142,
     143,   144,   145,   146,   147,   148,    -1,    -1,    -1,   152,
     153,    -1,   155,   156,    -1,    -1,    -1,    -1,   161,   162,
     163,   164,   165,   166,   167,   168,    -1,   170,    -1,    -1,
      -1,    -1,    -1,   176,   177,   178,    -1,    -1,    -1,   182,
      -1,   184,   185,    -1,   187,   188,   189,    -1,   191,    -1,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,    -1,    -1,   206,   207,   208,    -1,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,    -1,   255,   256,   257,    -1,   259,   260,   261,   262,
     263,   264,    -1,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    19,    20,    21,    22,    -1,    -1,    25,    -1,    -1,
      -1,    29,    30,    -1,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    -1,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    -1,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    -1,    92,    93,    94,    95,    96,    97,
      98,    99,    -1,    -1,   102,   103,    -1,    -1,    -1,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
      -1,    -1,   120,    -1,   122,   123,   124,   125,    -1,   127,
      -1,    -1,    -1,   131,   132,   133,   134,   135,    -1,    -1,
      -1,    -1,    -1,    -1,   142,   143,   144,   145,   146,   147,
     148,    -1,    -1,    -1,   152,   153,    -1,   155,   156,    -1,
      -1,    -1,    -1,   161,   162,   163,   164,   165,   166,   167,
     168,    -1,   170,    -1,    -1,    -1,    -1,    -1,   176,   177,
     178,    -1,    -1,    -1,   182,    -1,   184,   185,    -1,    -1,
      -1,   189,    -1,   191,    -1,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,    -1,    -1,   206,   207,
     208,    -1,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,    -1,   255,   256,   257,
      -1,   259,   260,   261,   262,   263,   264,    -1,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    -1,    -1,    -1,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    -1,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    -1,    92,
      93,    94,    95,    -1,    97,    98,    99,    -1,    -1,   102,
     103,    -1,    -1,    -1,    -1,   108,   109,   110,   111,   112,
     113,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   122,
     123,   124,   125,    -1,   127,    -1,    -1,    -1,   131,   132,
     133,   134,   135,    -1,    -1,    -1,    -1,    -1,    -1,   142,
     143,   144,    -1,   146,   147,   148,    -1,    -1,    -1,    -1,
      -1,    -1,   155,   156,    -1,    -1,    -1,    -1,   161,   162,
     163,   164,   165,   166,   167,   168,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   176,   177,   178,    -1,    -1,    -1,   182,
      -1,   184,   185,    -1,    -1,    -1,   189,    -1,   191,    -1,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,    -1,    -1,   206,   207,    -1,    -1,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,    -1,   255,   256,   257,    -1,   259,   260,   261,   262,
     263,   264,    -1,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    30,    -1,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    -1,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    -1,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    -1,    92,    93,    94,    95,    -1,    97,
      98,    99,    -1,    -1,   102,   103,    -1,    -1,    -1,    -1,
     108,   109,   110,   111,   112,   113,   114,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   122,   123,   124,   125,    -1,   127,
      -1,    -1,    -1,   131,   132,   133,   134,   135,    -1,    -1,
      -1,    -1,    -1,    -1,   142,   143,   144,    -1,   146,   147,
     148,    -1,    -1,    -1,    -1,    -1,    -1,   155,   156,    -1,
      -1,    -1,    -1,   161,   162,   163,   164,   165,   166,   167,
     168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   176,   177,
     178,    -1,    -1,    -1,   182,    -1,   184,   185,    -1,    -1,
      -1,   189,    -1,   191,    -1,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,    -1,    -1,   206,   207,
      -1,    -1,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,    -1,   255,   256,   257,
      -1,   259,   260,   261,   262,   263,   264,    -1,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    22,    -1,    -1,    25,    -1,
      -1,    -1,    29,    30,    -1,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    -1,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    -1,    92,    93,    94,    95,    -1,
      97,    98,    99,    -1,    -1,   102,   103,    -1,    -1,    -1,
      -1,   108,   109,   110,   111,   112,   113,   114,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   122,   123,   124,   125,    -1,
     127,    -1,    -1,    -1,   131,   132,   133,   134,   135,    -1,
      -1,    -1,    -1,    -1,    -1,   142,   143,   144,    -1,   146,
     147,   148,    -1,    -1,    -1,    -1,    -1,    -1,   155,   156,
      -1,    -1,    -1,    -1,   161,   162,   163,   164,   165,   166,
     167,   168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   176,
     177,   178,    -1,    -1,    -1,   182,   183,   184,   185,    -1,
      -1,    -1,    -1,    -1,   191,    -1,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,    -1,    -1,   206,
     207,    -1,    -1,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,    -1,   255,   256,
     257,    -1,   259,   260,   261,   262,   263,   264,    -1,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    30,    -1,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    -1,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    -1,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    -1,    92,    93,    94,    95,
      -1,    97,    98,    99,    -1,    -1,   102,   103,    -1,    -1,
      -1,    -1,   108,   109,   110,   111,   112,   113,   114,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   122,   123,   124,   125,
      -1,   127,    -1,    -1,    -1,   131,   132,   133,   134,   135,
      -1,    -1,    -1,    -1,    -1,    -1,   142,   143,   144,    -1,
     146,   147,   148,    -1,    -1,    -1,    -1,    -1,    -1,   155,
     156,    -1,    -1,    -1,    -1,   161,   162,   163,   164,   165,
     166,   167,   168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     176,   177,   178,    -1,    -1,    -1,   182,    -1,   184,   185,
      -1,    -1,    -1,    -1,    -1,   191,    -1,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,    -1,    -1,
     206,   207,    -1,    -1,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,    -1,   255,
     256,   257,    -1,   259,   260,   261,   262,   263,   264,    -1,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
      17,    -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    30,    -1,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    -1,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    -1,    92,    93,    94,    95,    -1,
      97,    98,    99,    -1,    -1,   102,   103,    -1,    -1,    -1,
      -1,   108,   109,   110,   111,   112,   113,   114,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   122,   123,   124,   125,    -1,
     127,    -1,    -1,    -1,   131,   132,   133,   134,   135,    -1,
      -1,    -1,    -1,    -1,    -1,   142,   143,   144,    -1,   146,
     147,   148,    -1,    -1,    -1,    -1,    -1,    -1,   155,   156,
      -1,    -1,    -1,    -1,   161,   162,   163,   164,   165,   166,
     167,   168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   176,
     177,   178,    -1,    -1,    -1,   182,    -1,   184,   185,    -1,
      -1,    -1,    -1,    -1,   191,    -1,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,    -1,    -1,   206,
     207,    -1,    -1,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,    -1,   255,   256,
     257,    -1,   259,   260,   261,   262,   263,   264,    -1,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    -1,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    -1,    92,
      93,    94,    95,    -1,    97,    98,    99,    -1,    -1,   102,
     103,    -1,    -1,    -1,    -1,   108,   109,   110,   111,   112,
     113,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   122,
     123,   124,   125,    -1,   127,    -1,    -1,    -1,   131,   132,
     133,   134,   135,    -1,    -1,    -1,    -1,    -1,    -1,   142,
     143,   144,    -1,   146,   147,   148,    -1,    -1,    -1,   152,
      -1,    -1,   155,   156,    -1,    -1,    -1,    -1,   161,   162,
     163,   164,   165,   166,   167,   168,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   176,   177,   178,    -1,    -1,    -1,   182,
     183,   184,   185,    -1,    -1,    -1,   189,    -1,   191,    -1,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,    -1,    -1,   206,   207,    -1,    -1,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,    -1,   255,   256,   257,    -1,   259,   260,   261,   262,
     263,   264,    -1,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    30,    -1,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    -1,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    -1,    92,    93,    94,    95,    -1,    97,    98,
      99,    -1,    -1,   102,   103,    -1,    -1,    -1,    -1,   108,
     109,   110,   111,   112,   113,   114,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   122,   123,   124,   125,    -1,   127,    -1,
      -1,    -1,   131,   132,   133,   134,   135,    -1,    -1,    -1,
      -1,    -1,    -1,   142,   143,   144,    -1,   146,   147,   148,
      -1,    -1,    -1,    -1,    -1,    -1,   155,   156,    -1,    -1,
      -1,    -1,   161,   162,   163,   164,   165,   166,   167,   168,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   176,   177,   178,
      -1,    -1,    -1,   182,   183,   184,   185,    -1,    -1,    -1,
     189,    -1,   191,    -1,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,    -1,    -1,   206,   207,    -1,
      -1,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,    -1,   255,   256,   257,    -1,
     259,   260,   261,   262,   263,   264,    -1,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    30,    -1,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    -1,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    -1,    92,    93,    94,
      95,    -1,    97,    98,    99,    -1,    -1,   102,   103,    -1,
      -1,    -1,    -1,   108,   109,   110,   111,   112,   113,   114,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   122,   123,   124,
     125,    -1,   127,    -1,    -1,    -1,   131,   132,   133,   134,
     135,    -1,    -1,    -1,    -1,    -1,    -1,   142,   143,   144,
      -1,   146,   147,   148,    -1,    -1,    -1,    -1,    -1,    -1,
     155,   156,    -1,    -1,    -1,    -1,   161,   162,   163,   164,
     165,   166,   167,   168,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   176,   177,   178,    -1,    -1,    -1,   182,   183,   184,
     185,    -1,    -1,    -1,   189,    -1,   191,    -1,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,    -1,
      -1,   206,   207,    -1,    -1,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,    -1,
     255,   256,   257,    -1,   259,   260,   261,   262,   263,   264,
      -1,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,    22,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,
      -1,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    -1,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    -1,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      -1,    92,    93,    94,    95,    -1,    97,    98,    99,    -1,
      -1,   102,   103,    -1,    -1,    -1,    -1,   108,   109,   110,
     111,   112,   113,   114,   115,    -1,    -1,    -1,    -1,    -1,
      -1,   122,   123,   124,   125,    -1,   127,    -1,    -1,    -1,
     131,   132,   133,   134,   135,    -1,    -1,    -1,    -1,    -1,
      -1,   142,   143,   144,    -1,   146,   147,   148,    -1,    -1,
      -1,   152,    -1,    -1,   155,   156,    -1,    -1,    -1,    -1,
     161,   162,   163,   164,   165,   166,   167,   168,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   176,   177,   178,    -1,    -1,
      -1,   182,    -1,   184,   185,    -1,    -1,    -1,    -1,    -1,
     191,    -1,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,    -1,    -1,   206,   207,    -1,    -1,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,    -1,   255,   256,   257,    -1,   259,   260,
     261,   262,   263,   264,    -1,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    30,    -1,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    -1,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    -1,    92,    93,    94,    95,    -1,
      97,    98,    99,    -1,    -1,   102,   103,    -1,    -1,    -1,
      -1,   108,   109,   110,   111,   112,   113,   114,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   122,   123,   124,   125,    -1,
     127,    -1,    -1,    -1,   131,   132,   133,   134,   135,    -1,
      -1,    -1,    -1,    -1,    -1,   142,   143,   144,    -1,   146,
     147,   148,    -1,    -1,    -1,   152,    -1,    -1,   155,   156,
      -1,    -1,    -1,    -1,   161,   162,   163,   164,   165,   166,
     167,   168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   176,
     177,   178,    -1,    -1,    -1,   182,    -1,   184,   185,    -1,
      -1,    -1,    -1,    -1,   191,    -1,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,    -1,    -1,   206,
     207,    -1,    -1,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,    -1,   255,   256,
     257,    -1,   259,   260,   261,   262,   263,   264,    -1,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    -1,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    -1,    92,
      93,    94,    95,    -1,    97,    98,    99,    -1,    -1,   102,
     103,    -1,    -1,    -1,    -1,   108,   109,   110,   111,   112,
     113,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   122,
     123,   124,   125,    -1,   127,    -1,    -1,    -1,   131,   132,
     133,   134,   135,    -1,    -1,    -1,    -1,    -1,    -1,   142,
     143,   144,    -1,   146,   147,   148,    -1,    -1,    -1,   152,
      -1,    -1,   155,   156,    -1,    -1,    -1,    -1,   161,   162,
     163,   164,   165,   166,   167,   168,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   176,   177,   178,    -1,    -1,    -1,   182,
      -1,   184,   185,    -1,    -1,    -1,    -1,    -1,   191,    -1,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,    -1,    -1,   206,   207,    -1,    -1,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,    -1,   255,   256,   257,    -1,   259,   260,   261,   262,
     263,   264,    -1,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    30,    -1,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    -1,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    -1,    92,    93,    94,    95,    -1,    97,    98,
      99,    -1,    -1,   102,   103,    -1,    -1,    -1,    -1,   108,
     109,   110,   111,   112,   113,   114,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   122,   123,   124,   125,    -1,   127,    -1,
      -1,    -1,   131,   132,   133,   134,   135,    -1,    -1,    -1,
      -1,    -1,    -1,   142,   143,   144,    -1,   146,   147,   148,
      -1,    -1,    -1,    -1,    -1,    -1,   155,   156,    -1,    -1,
      -1,    -1,   161,   162,   163,   164,   165,   166,   167,   168,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   176,   177,   178,
      -1,    -1,    -1,   182,    -1,   184,   185,    -1,    -1,    -1,
      -1,    -1,   191,    -1,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,    -1,    -1,   206,   207,    -1,
      -1,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,    -1,   255,   256,   257,    -1,
     259,   260,   261,   262,   263,   264,    -1,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    30,    -1,    32,    33,    34,
      -1,    36,    37,    38,    39,    40,    -1,    -1,    43,    44,
      45,    -1,    47,    48,    49,    50,    51,    -1,    53,    54,
      55,    56,    57,    -1,    59,    -1,    -1,    62,    63,    64,
      65,    66,    -1,    68,    -1,    70,    -1,    -1,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    -1,    92,    93,    94,
      -1,    -1,    97,    98,    99,    -1,    -1,   102,   103,    -1,
      -1,    -1,    -1,   108,   109,   110,   111,   112,   113,   114,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   122,   123,   124,
     125,    -1,   127,    -1,    -1,    -1,   131,   132,   133,   134,
     135,    -1,    -1,    -1,    -1,    -1,    -1,   142,   143,   144,
      -1,   146,   147,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     155,   156,    -1,    -1,    -1,    -1,   161,   162,   163,   164,
     165,   166,   167,   168,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   176,   177,   178,    -1,    -1,    -1,   182,    -1,   184,
     185,    -1,    -1,    -1,    -1,    -1,   191,    -1,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,    -1,
      -1,    -1,   207,    -1,    -1,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,    -1,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,    -1,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,    -1,
     255,   256,   257,    -1,   259,   260,   261,   262,   263,   264,
      -1,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  xquery_parser::yystos_[] =
  {
         0,    11,    18,    19,    20,    21,    22,    25,    29,    30,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    92,    93,    94,
      95,    96,    97,    98,    99,   102,   103,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   120,   122,
     123,   124,   125,   127,   131,   132,   133,   134,   135,   142,
     143,   144,   145,   146,   147,   148,   152,   153,   154,   155,
     156,   161,   162,   163,   164,   165,   166,   167,   168,   170,
     172,   173,   176,   177,   178,   182,   184,   185,   187,   188,
     189,   191,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   206,   207,   208,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     255,   256,   257,   259,   260,   261,   262,   263,   264,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     321,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   351,   352,   356,   357,   360,   363,
     366,   367,   369,   374,   375,   376,   377,   381,   390,   391,
     393,   394,   395,   400,   402,   404,   405,   410,   431,   434,
     438,   441,   442,   443,   444,   446,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   492,   493,   494,   508,   509,
     511,   512,   513,   514,   515,   516,   517,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   537,   538,   539,
     540,   545,   546,   547,   548,   549,   550,   553,   557,   613,
     614,    29,    30,    47,   180,   210,   391,   180,   391,   180,
     391,    23,    33,    34,    36,    37,    45,    55,    56,    62,
      64,    73,    77,   108,   109,   110,   156,   165,   197,   215,
     225,   257,   283,   284,   285,   286,   287,   289,   290,   291,
     292,   293,   298,   299,   358,   359,   378,   379,   382,   383,
     384,   385,   156,   149,   152,   149,   152,   149,   152,   149,
      65,    70,   115,   397,   152,   368,   152,    30,    59,   115,
     149,   152,   152,   152,   115,   115,   149,   152,   152,   152,
      92,   149,   216,   217,   118,   118,   118,   149,   152,    35,
      40,    42,    43,    44,    45,    46,    49,    58,    63,    66,
      69,    71,    72,    74,    88,    89,    95,   102,   111,   112,
     131,   134,   135,   165,   168,   176,   177,   185,   197,   219,
     221,   223,   224,   231,   233,   234,   235,   236,   239,   240,
     242,   476,   613,   614,   118,   118,   118,    35,    41,    42,
      58,    60,    61,    69,    95,   220,   613,   115,   118,   118,
     183,   391,   613,   149,   118,    15,   612,   613,    17,   613,
     118,   118,   118,   468,   149,    26,   209,   211,   220,   222,
     152,   220,   222,   220,   220,   225,   115,   149,   370,   237,
     237,   238,   152,   149,   115,   323,     0,   325,   326,    29,
      47,   328,   329,     1,   186,   322,   186,   322,   133,   138,
     104,   186,   392,    38,    44,    49,    68,   164,   167,   182,
     207,   396,   401,   402,   403,   419,   420,   424,   163,    90,
     128,   136,   137,   139,   147,   151,   153,   158,   175,   198,
     199,   200,   201,   202,   203,   460,   461,   245,   154,   172,
     194,   114,   142,   155,   189,   196,   205,   132,   146,    48,
     195,    98,    99,   154,   172,   459,   149,   465,   468,   187,
     188,   150,   480,   481,   476,   480,   476,   152,   480,   141,
     152,   180,   180,   180,   152,    25,   611,   178,   191,   178,
     191,   162,   178,   614,   613,   165,   197,    45,   383,    45,
     613,   148,   115,    42,    45,    77,   103,   164,   612,   216,
     217,   218,   296,   297,   242,   584,   613,   289,   613,   294,
     294,   296,   297,   300,   283,   291,   359,   109,   379,   382,
     612,   391,   183,   391,    42,    61,   183,   533,   534,   391,
     183,   189,   613,   394,   280,   280,   406,   407,   613,   115,
     415,   115,   183,   386,   387,   149,   388,   391,   156,   611,
     110,   156,   350,   611,   411,   414,   613,   391,    25,   183,
     612,   613,   613,   613,   432,   433,   613,   391,   183,   391,
     391,   535,   613,   391,   149,   149,   391,   183,   189,   613,
     432,   183,    31,   496,   497,   498,   391,     8,   171,    16,
     391,   209,    25,   394,   394,   183,   394,   394,   394,   394,
     226,   551,   552,   613,   371,   394,   394,   391,   412,   413,
     613,   186,   322,   186,   322,     3,   329,   330,   390,   329,
     330,   390,    29,   331,   390,   331,   390,   138,   394,   394,
     393,   115,   164,   166,   166,   394,   394,   443,   444,   446,
     446,   446,   446,   445,   446,   446,   446,    69,   450,   450,
     449,   451,   451,   451,   451,   452,   452,   453,   453,   226,
      92,    92,    92,   180,   391,   468,   468,   391,   481,   183,
     394,   491,   145,   183,   491,   380,   483,   104,   104,   368,
      25,   614,   614,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,   333,   334,   335,    92,   133,   138,   353,
     354,   355,   613,   156,   156,   333,   611,   123,   128,    52,
      55,    97,   247,   260,   262,   273,   274,   275,   277,   279,
     585,   586,   587,   588,   589,   590,   597,   603,   604,   242,
      92,   232,   362,   295,   613,   613,   613,   115,   128,   180,
     180,   183,   183,   180,   104,   183,   104,   183,   180,   104,
      32,    92,    94,   143,   269,   408,   409,   519,   613,    54,
     212,   250,   398,   399,   613,    92,   104,   183,   391,   183,
     612,    94,    42,   612,   611,    94,   104,   138,   409,   519,
     180,   183,   183,   183,   183,   138,   104,   184,   143,   519,
     180,   183,   183,   149,   180,   391,   391,   180,   104,   183,
     104,   183,   184,   613,   497,   498,   126,   192,   180,   180,
     127,   186,    92,   213,   214,   228,    92,   213,   214,   228,
      92,   232,   220,   104,   230,   138,    29,   372,   391,   183,
     180,    43,   104,   329,    29,    29,   186,   322,   186,   110,
     394,   186,   613,   166,   394,   425,   426,   115,   421,   422,
     446,   149,   152,   255,   464,   483,   558,   561,   562,   563,
     564,   565,   569,   571,   573,   574,    45,   148,   152,   206,
     520,   522,   524,   525,   541,   542,   543,   544,   613,   520,
     518,   524,   518,   180,   181,   104,   183,   183,   104,   183,
     144,   161,   144,   161,   133,   149,   389,   368,   368,   334,
     128,   522,   355,   394,   519,   611,   611,   124,   125,   611,
     273,   274,   275,   279,   613,   259,   270,   259,   270,    25,
     282,    94,   110,   152,   591,   594,   585,    35,    41,    58,
      60,    69,    95,   220,   361,   525,   287,   288,   222,   295,
     304,    92,   362,   295,   613,   611,   149,   535,   536,   613,
     535,   536,   115,   123,   520,   115,   394,   115,   143,   409,
     143,    32,   143,   408,   409,   143,   519,   250,    51,    57,
      75,   115,   408,   416,   417,   418,   399,   519,   520,   387,
      92,   180,   193,   128,   349,   611,   156,   128,    94,   349,
     115,   394,   138,   138,   409,   149,   394,   115,   394,   394,
     143,    97,   435,   436,   437,    97,   439,   440,   391,   180,
     180,   149,   535,   535,   394,    31,   498,   126,   192,     9,
      10,   100,   119,   121,   190,   388,   493,   495,   506,   507,
     510,    25,   227,   229,   394,   394,   394,   227,   229,   394,
     394,   394,   394,   394,   394,   115,   394,   394,   115,   373,
     104,   186,   180,   370,   241,   554,   555,   149,   115,   186,
     110,   390,   390,   390,   425,    93,   103,   113,   123,   427,
     428,   429,   430,   104,   613,   104,   391,   558,   565,   149,
     281,   447,   610,    94,   165,   248,   249,   251,   258,   268,
     280,   559,   560,   579,   580,   581,   582,   605,   608,   254,
     256,   566,   584,   263,   570,   606,   243,   244,   266,   575,
     576,   152,   152,   522,   152,   140,   172,   189,   521,   140,
     394,   483,   391,   133,   370,   133,   149,   537,   354,   282,
      25,    94,   110,   152,   598,    25,   591,   362,   521,   222,
     222,   466,   283,   302,   361,   222,   519,   186,   180,   391,
     183,   183,   140,   183,   183,   407,   143,   408,   613,   613,
     394,   143,   394,   123,   394,   143,   409,   143,   394,   143,
     115,   115,   394,   613,   418,    75,   520,   394,   611,   104,
     349,   414,   394,   394,   138,   180,   391,   433,   394,   394,
     110,   436,    97,   182,   115,   520,   110,   440,   180,   180,
     391,   183,   183,   128,   190,   495,     7,   613,   190,   506,
     186,   228,   228,   228,   228,   232,   552,   182,   613,   373,
     477,   556,   555,   394,   413,   611,   124,   125,   429,   430,
     430,   426,   103,   423,   422,   180,   183,   558,   572,   246,
     212,   250,   264,   271,   609,    94,   252,   253,   607,   246,
     562,   609,   449,   579,   563,   143,   278,   567,   568,   607,
     282,   578,    76,   577,   183,   189,   520,   523,   183,   183,
     183,   180,   393,    25,   132,   196,   600,   601,   602,    25,
     599,   600,   267,   595,   592,   593,   594,   166,   613,   253,
     362,   466,   180,   394,   143,   394,   143,   408,   394,   143,
     394,   394,   613,   613,   417,   394,   122,    94,   611,   394,
     180,   182,   394,   394,   613,   182,   115,   182,   180,   498,
     613,   190,   498,   613,   394,   394,   394,   394,   394,   394,
     138,   519,   152,   205,   389,   180,   430,   611,   180,   451,
      50,   125,   449,   449,   265,   272,   282,   583,   583,   564,
     149,   276,    92,   183,   104,   183,   180,   598,   598,   602,
     104,   183,    25,   596,   607,   183,   104,   364,   365,   466,
     115,   220,   303,   283,   166,   394,   394,   143,   394,    51,
     394,   349,   394,    92,   394,   613,   394,    91,   179,   499,
     498,   613,   192,   498,   394,   138,   115,   477,   449,   449,
     194,   391,   520,   520,    92,    25,   261,   594,   104,   430,
     519,   613,   115,   220,   613,   364,   394,   115,   520,   182,
       5,   129,   502,   503,   505,   507,    24,   130,   500,   501,
     504,   507,   192,   498,   192,   394,   613,   449,   180,   520,
     365,   430,   301,   613,   115,   220,   613,   182,   394,    91,
     129,   505,   179,   130,   504,   192,   104,   183,   394,   301,
     613,   115,   394,   115,   389,   289,   301,   613,   613,   302,
     394,   302,   104,   183,   466,   466,   115,   389,   194,   613,
     283,   183,   613,   389,   220,   115,   613,   302,   466
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
     330,   330,   330,   330,   330,   331,   331,   331,   331,   331,
     331,   331,   331,   332,   332,   333,   333,   334,   335,   335,
     335,   335,   335,   335,   335,   335,   335,   335,   336,   336,
     336,   336,   336,   336,   336,   336,   337,   337,   338,   339,
     339,   340,   340,   341,   342,   343,   343,   344,   344,   345,
     345,   345,   345,   346,   347,   348,   348,   348,   348,   349,
     349,   350,   350,   351,   351,   351,   351,   352,   353,   353,
     354,   354,   354,   355,   356,   356,   356,   356,   357,   357,
     357,   358,   358,   359,   359,   359,   359,   359,   359,   359,
     359,   359,   359,   359,   359,   359,   359,   360,   360,   360,
     360,   360,   360,   360,   360,   361,   361,   362,   362,   363,
     363,   364,   364,   365,   365,   365,   365,   366,   366,   366,
     366,   367,   367,   368,   368,   368,   368,   369,   370,   371,
     371,   372,   372,   373,   373,   373,   373,   374,   375,   376,
     377,   377,   378,   378,   379,   379,   380,   380,   381,   381,
     382,   382,   382,   382,   383,   383,   384,   384,   385,   385,
     386,   386,   387,   387,   388,   389,   390,   391,   391,   392,
     392,   393,   393,   394,   394,   394,   394,   394,   394,   394,
     394,   394,   394,   394,   394,   394,   394,   394,   394,   394,
     394,   395,   396,   397,   397,   398,   398,   398,   399,   399,
     400,   400,   401,   402,   402,   402,   403,   403,   403,   403,
     403,   404,   404,   405,   406,   406,   407,   407,   407,   407,
     407,   407,   407,   407,   407,   407,   407,   407,   408,   409,
     410,   411,   411,   412,   412,   413,   414,   414,   414,   414,
     415,   415,   416,   416,   416,   417,   417,   417,   418,   418,
     418,   419,   420,   421,   421,   422,   422,   423,   424,   424,
     425,   425,   426,   426,   427,   427,   427,   427,   427,   427,
     427,   428,   428,   429,   429,   430,   431,   431,   432,   432,
     433,   433,   434,   435,   435,   436,   437,   437,   438,   438,
     439,   439,   440,   440,   441,   442,   442,   443,   443,   444,
     444,   444,   444,   444,   445,   444,   444,   444,   444,   446,
     446,   447,   447,   448,   448,   449,   449,   449,   450,   450,
     450,   450,   450,   451,   451,   451,   452,   452,   452,   453,
     453,   454,   454,   455,   455,   456,   456,   457,   457,   458,
     458,   458,   458,   459,   459,   459,   460,   460,   460,   460,
     460,   460,   461,   461,   461,   462,   462,   462,   462,   463,
     463,   464,   464,   465,   465,   466,   466,   466,   466,   467,
     468,   468,   468,   469,   469,   470,   470,   470,   470,   471,
     471,   472,   472,   472,   472,   472,   472,   472,   473,   473,
     474,   474,   475,   475,   475,   475,   475,   476,   476,   477,
     477,   478,   478,   478,   479,   479,   479,   479,   480,   480,
     481,   482,   482,   482,   482,   482,   482,   482,   482,   482,
     483,   483,   484,   484,   484,   485,   486,   486,   487,   488,
     489,   490,   490,   491,   491,   492,   492,   493,   493,   493,
     494,   494,   494,   494,   494,   494,   495,   495,   496,   496,
     497,   498,   498,   499,   499,   500,   500,   501,   501,   501,
     501,   502,   502,   503,   503,   503,   503,   504,   504,   505,
     505,   506,   506,   506,   506,   507,   507,   507,   507,   508,
     508,   509,   509,   510,   511,   511,   511,   511,   511,   511,
     512,   513,   513,   513,   513,   514,   514,   514,   514,   515,
     516,   517,   517,   517,   517,   518,   518,   519,   520,   520,
     520,   521,   521,   521,   522,   522,   522,   522,   522,   523,
     523,   524,   525,   525,   525,   525,   525,   525,   525,   525,
     525,   526,   527,   527,   527,   528,   529,   530,   530,   530,
     531,   531,   531,   531,   531,   532,   533,   533,   533,   533,
     533,   533,   533,   534,   535,   536,   537,   538,   538,   539,
     540,   541,   541,   542,   543,   543,   544,   545,   545,   545,
     546,   546,   546,   546,   546,   546,   546,   546,   546,   546,
     547,   547,   548,   548,   549,   550,   551,   551,   552,   553,
     554,   554,   555,   555,   555,   555,   556,   556,   557,   557,
     558,   559,   559,   560,   560,   561,   561,   562,   562,   563,
     563,   564,   564,   565,   566,   566,   567,   567,   568,   569,
     569,   569,   570,   570,   571,   572,   572,   573,   574,   574,
     575,   575,   576,   576,   576,   577,   577,   578,   578,   579,
     579,   579,   579,   579,   580,   581,   582,   583,   583,   583,
     584,   584,   585,   585,   585,   585,   585,   585,   585,   585,
     586,   586,   586,   586,   587,   587,   588,   589,   589,   590,
     590,   590,   591,   591,   592,   592,   593,   593,   594,   595,
     595,   596,   596,   597,   597,   597,   598,   598,   599,   599,
     600,   600,   601,   601,   602,   602,   603,   604,   604,   605,
     605,   605,   606,   607,   607,   607,   607,   608,   608,   609,
     609,   610,   611,   612,   612,   613,   613,   613,   613,   613,
     613,   613,   613,   613,   613,   613,   613,   613,   613,   613,
     613,   614,   614,   614,   614,   614,   614,   614,   614,   614,
     614,   614,   614,   614,   614,   614,   614,   614,   614,   614,
     614,   614,   614,   614,   614,   614,   614,   614,   614,   614,
     614,   614,   614,   614,   614,   614,   614,   614,   614,   614,
     614,   614,   614,   614,   614,   614,   614,   614,   614,   614,
     614,   614,   614,   614,   614,   614,   614,   614,   614,   614,
     614,   614,   614,   614,   614,   614,   614,   614,   614,   614,
     614,   614,   614,   614,   614,   614,   614,   614,   614,   614,
     614,   614,   614,   614,   614,   614,   614,   614,   614,   614,
     614,   614,   614,   614,   614,   614,   614,   614,   614,   614,
     614,   614,   614,   614,   614,   614,   614,   614,   614,   614,
     614,   614,   614,   614,   614,   614,   614,   614,   614,   614,
     614,   614,   614,   614,   614,   614,   614,   614,   614,   614,
     614,   614,   614,   614,   614,   614,   614,   614,   614,   614,
     614,   614,   614,   614,   614,   614,   614,   614,   614,   614,
     614,   614,   614,   614,   614,   614,   614,   614,   614,   614,
     614,   614,   614,   614,   614,   614,   614,   614,   614,   614,
     614,   614,   614,   614,   614,   614,   614,   614,   614,   614,
     614,   614,   614,   614,   614,   614,   614,   614,   614,   614,
     614,   614,   614,   614,   614,   614,   614,   614,   614,   614,
     614
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
       3,     1,     4,     1,     4,     1,     3,     4,     4,     5,
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
       4,     1,     2,     3,     2,     1,     2,     2,     1,     1,
       1,     3,     3,     1,     1,     1,     2,     1,     2,     2,
       1,     2,     2,     2,     2,     2,     2,     2,     1,     2,
       2,     1,     2,     2,     2,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     3,     4,     1,     2,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     3,     1,     4,
       4,     3,     4,     1,     3,     1,     1,     1,     1,     1,
       4,     5,     8,     9,     9,    10,     1,     2,     1,     2,
       6,     0,     1,     3,     3,     0,     1,     1,     1,     2,
       2,     0,     1,     1,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       2,     3,     3,     2,     1,     1,     1,     1,     1,     1,
       4,     2,     3,     6,     7,     2,     3,     6,     7,     4,
       4,     2,     3,     6,     7,     1,     2,     2,     1,     2,
       3,     1,     1,     1,     1,     1,     3,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     4,     4,     3,     3,     3,     4,     4,
       3,     4,     6,     4,     6,     4,     3,     4,     6,     6,
       4,     6,     6,     4,     1,     2,     1,     1,     1,     3,
       3,     1,     1,     4,     5,     6,     3,     3,     3,     3,
       5,     7,     7,     5,     5,     5,     7,     7,     5,     5,
       3,     3,     5,     7,     5,     7,     1,     4,     3,     5,
       1,     2,     3,     7,    10,    13,     1,     3,     7,     4,
       2,     0,     1,     1,     2,     1,     3,     1,     3,     1,
       4,     1,     2,     3,     0,     1,     0,     1,     4,     2,
       3,     1,     0,     1,     4,     0,     1,     2,     1,     3,
       0,     1,     2,     2,     1,     0,     1,     0,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     1,     1,     1,
       2,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     1,     1,     2,     2,     3,     1,     2,     2,
       5,     2,     1,     1,     0,     1,     1,     3,     4,     0,
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
  "\"'&entity;'\"", "\"'comment literal'\"", "\"'pi <NCName {>'\"",
  "\"'NCName_sval'\"", "\"'pragma literal'\"", "\"'QName #)'\"",
  "\"'*:QName'\"", "\"'element QName {'\"", "\"'attribute QName {'\"",
  "\"'processing-instruction NCName {'\"", "\"'QName'\"", "\"'%QName'\"",
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
  "FUNCTION_NAME", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const xquery_parser::rhs_number_type
  xquery_parser::yyrhs_[] =
  {
       321,     0,    -1,   323,    -1,   306,   323,    -1,     1,     3,
      -1,   325,    -1,   324,   325,    -1,   326,    -1,   324,   326,
      -1,   210,   211,    25,   186,    -1,   210,   211,    25,   127,
      25,   186,    -1,   328,   186,   390,    -1,   329,   186,   390,
      -1,   328,   186,   329,   186,   390,    -1,   390,    -1,   328,
     322,   390,    -1,   329,   322,   390,    -1,   328,   186,   329,
     322,   390,    -1,   328,   322,   329,   186,   390,    -1,   327,
      -1,   327,   328,   186,    -1,   327,   329,   186,    -1,   327,
     328,   186,   329,   186,    -1,    30,   156,   612,   128,   611,
     186,    -1,   330,    -1,   328,   186,   330,    -1,   328,   322,
     330,    -1,   331,    -1,   329,   186,   331,    -1,   329,   322,
     331,    -1,   336,    -1,   337,    -1,   338,    -1,   340,    -1,
     342,    -1,   357,    -1,   360,    -1,   352,    -1,   332,    -1,
     381,    -1,   363,    -1,   366,    -1,   341,    -1,    29,   110,
      77,   333,    -1,    29,    77,   613,   333,    -1,   334,    -1,
     333,   334,    -1,   335,   128,   537,    -1,    78,    -1,    86,
      -1,    79,    -1,    80,    -1,    81,    -1,    82,    -1,    87,
      -1,    83,    -1,    84,    -1,    85,    -1,   339,    -1,   346,
      -1,   347,    -1,   367,    -1,   343,    -1,   344,    -1,   345,
      -1,   545,    -1,   348,    -1,   351,    -1,    29,   156,   612,
     128,   611,    -1,    29,    34,   178,    -1,    29,    34,   191,
      -1,    29,   110,    42,   156,   611,    -1,    29,   110,    45,
     156,   611,    -1,    29,    55,   613,    25,    -1,    29,   257,
     584,    -1,    29,    56,   165,    -1,    29,    56,   197,    -1,
      29,   110,   164,   123,   124,    -1,    29,   110,   164,   123,
     125,    -1,    29,    37,   178,   104,   144,    -1,    29,    37,
     178,   104,   161,    -1,    29,    37,   162,   104,   144,    -1,
      29,    37,   162,   104,   161,    -1,    29,   110,   103,   611,
      -1,    29,    33,   611,    -1,    47,    59,   611,    -1,    47,
      59,   350,   611,    -1,    47,    59,   611,    94,   349,    -1,
      47,    59,   350,   611,    94,   349,    -1,   611,    -1,   349,
     104,   611,    -1,   156,   612,   128,    -1,   110,    42,   156,
      -1,    47,    30,   611,    -1,    47,    30,   156,   612,   128,
     611,    -1,    47,    30,   611,    94,   349,    -1,    47,    30,
     156,   612,   128,   611,    94,   349,    -1,    29,   108,   148,
     353,    -1,    92,   522,   354,    -1,   354,    -1,   355,    -1,
     133,    -1,   133,   355,    -1,   138,   394,    -1,    29,   109,
     115,   613,    -1,    29,   109,   115,   613,   519,    -1,    29,
     378,   109,   115,   613,    -1,    29,   378,   109,   115,   613,
     519,    -1,   356,   138,   394,    -1,   356,   133,    -1,   356,
     133,   138,   394,    -1,   359,    -1,   358,   359,    -1,   284,
      -1,   285,    -1,   286,    -1,   287,    -1,   165,    -1,   197,
      -1,   225,   297,    -1,   225,   296,    -1,   298,   297,    -1,
     298,   296,    -1,   289,    -1,   290,   289,    -1,   293,   294,
      -1,   292,   294,    -1,    29,   283,   613,    -1,    29,   283,
     613,   362,    -1,    29,   283,   613,    92,   361,    -1,    29,
     283,   613,    92,   361,   362,    -1,    29,   358,   283,   613,
      -1,    29,   358,   283,   613,   362,    -1,    29,   358,   283,
     613,    92,   361,    -1,    29,   358,   283,   613,    92,   361,
     362,    -1,   525,    -1,   525,   521,    -1,   232,   288,   222,
      -1,   232,   287,   222,    -1,    29,   291,   613,   295,   222,
     466,   166,   364,    -1,    29,   358,   291,   613,   295,   222,
     466,   166,   364,    -1,   365,    -1,   364,   104,   365,    -1,
     466,    -1,   466,   519,    -1,   466,   430,    -1,   466,   519,
     430,    -1,    29,   299,   300,   613,   295,   283,   613,   115,
     613,   301,   394,    -1,    29,   299,   300,   613,   295,   283,
     613,   220,   115,   613,   301,   289,   302,   466,    -1,    29,
     299,   300,   613,   295,   283,   613,   303,   220,   115,   613,
     301,   394,    -1,    29,   299,   300,   613,   304,   302,   253,
     283,   613,   220,   115,   613,   302,   466,   194,   283,   613,
     220,   115,   613,   302,   466,    -1,    29,    36,   178,    -1,
      29,    36,   191,    -1,   152,   183,    -1,   152,   386,   183,
      -1,   152,   183,    92,   520,    -1,   152,   386,   183,    92,
     520,    -1,   233,   370,    -1,   149,   371,   391,   180,    -1,
     371,   372,   186,    -1,    -1,   372,   104,   373,    -1,    29,
     373,    -1,   115,   613,    -1,   115,   613,   519,    -1,   115,
     613,   138,   394,    -1,   115,   613,   519,   138,   394,    -1,
      63,   115,   613,   138,   394,    -1,   236,   238,   394,    -1,
     239,   152,   394,   183,   370,    -1,   234,   237,    -1,   235,
     237,    -1,   379,    -1,   378,   379,    -1,    23,    -1,    23,
     152,   380,   183,    -1,   483,    -1,   380,   104,   483,    -1,
      29,   382,    -1,    29,   378,   382,    -1,   383,    -1,    64,
     383,    -1,   385,    -1,   384,    -1,    45,   614,   368,   389,
      -1,    45,   614,   368,   133,    -1,    62,    45,   614,   368,
     370,    -1,    62,    45,   614,   368,   133,    -1,    73,    45,
     614,   368,   149,   393,   180,    -1,    73,    45,   614,   368,
     133,    -1,   387,    -1,   386,   104,   387,    -1,   115,   613,
      -1,   115,   613,   519,    -1,   149,   391,   180,    -1,   149,
     391,   180,    -1,   391,    -1,   393,    -1,   393,   392,    -1,
     186,    -1,   392,   393,   186,    -1,   394,    -1,   393,   104,
     394,    -1,   395,    -1,   431,    -1,   434,    -1,   438,    -1,
     441,    -1,   442,    -1,   546,    -1,   547,    -1,   549,    -1,
     548,    -1,   550,    -1,   553,    -1,   557,    -1,   375,    -1,
     376,    -1,   377,    -1,   374,    -1,   369,    -1,   404,   396,
      -1,   182,   394,    -1,    65,   280,    -1,    70,   280,    -1,
     212,    -1,   250,    -1,    54,   250,    -1,   398,   416,    75,
     394,    -1,   398,    75,   394,    -1,    44,   397,   415,   399,
     399,    -1,    44,   397,   415,   399,    -1,    38,   115,   613,
      -1,   405,    -1,   410,    -1,   400,    -1,   402,    -1,   419,
      -1,   424,    -1,   420,    -1,   401,    -1,   402,    -1,   404,
     403,    -1,    44,   115,   406,    -1,   407,    -1,   406,   104,
     115,   407,    -1,   613,   143,   394,    -1,   613,    32,   123,
     143,   394,    -1,   613,   519,   143,   394,    -1,   613,   519,
      32,   123,   143,   394,    -1,   613,   408,   143,   394,    -1,
     613,    32,   123,   408,   143,   394,    -1,   613,   519,   408,
     143,   394,    -1,   613,   519,    32,   123,   408,   143,   394,
      -1,   613,   409,   143,   394,    -1,   613,   519,   409,   143,
     394,    -1,   613,   408,   409,   143,   394,    -1,   613,   519,
     408,   409,   143,   394,    -1,    94,   115,   613,    -1,   269,
     115,   613,    -1,    49,   115,   411,    -1,   414,    -1,   411,
     104,   115,   414,    -1,   413,    -1,   412,   104,   115,   413,
      -1,   613,    -1,   613,   138,   394,    -1,   613,   519,   138,
     394,    -1,   613,   409,   138,   394,    -1,   613,   519,   409,
     138,   394,    -1,   115,   613,   143,   394,    -1,   115,   613,
     519,   143,   394,    -1,   417,    -1,   115,   613,    -1,   115,
     613,   417,    -1,   408,    -1,   408,   418,    -1,   418,    -1,
      57,   115,   613,    51,   115,   613,    -1,    51,   115,   613,
      -1,    57,   115,   613,    -1,   207,   394,    -1,   167,   166,
     421,    -1,   422,    -1,   421,   104,   422,    -1,   115,   613,
      -1,   115,   613,   423,    -1,   103,   611,    -1,   164,   166,
     425,    -1,    68,   164,   166,   425,    -1,   426,    -1,   425,
     104,   426,    -1,   394,    -1,   394,   427,    -1,   428,    -1,
     429,    -1,   430,    -1,   428,   429,    -1,   428,   430,    -1,
     429,   430,    -1,   428,   429,   430,    -1,    93,    -1,   113,
      -1,   123,   124,    -1,   123,   125,    -1,   103,   611,    -1,
      66,   115,   432,   184,   394,    -1,   131,   115,   432,   184,
     394,    -1,   433,    -1,   432,   104,   115,   433,    -1,   613,
     143,   394,    -1,   613,   519,   143,   394,    -1,    71,   152,
     391,   183,   435,   110,   182,   394,    -1,   436,    -1,   435,
     436,    -1,   437,   182,   394,    -1,    97,   394,    -1,   437,
      97,   394,    -1,    72,   152,   391,   183,   439,   110,   182,
     394,    -1,    72,   152,   391,   183,   439,   110,   115,   613,
     182,   394,    -1,   440,    -1,   439,   440,    -1,    97,   520,
     182,   394,    -1,    97,   115,   613,    92,   520,   182,   394,
      -1,    46,   152,   391,   183,   193,   394,   122,   394,    -1,
     443,    -1,   442,   163,   443,    -1,   444,    -1,   443,    90,
     444,    -1,   446,    -1,   446,   460,   446,    -1,   446,   461,
     446,    -1,   446,   128,   446,    -1,   446,   158,   446,    -1,
      -1,   446,   153,   445,   446,    -1,   446,   151,   446,    -1,
     446,   139,   446,    -1,   446,   137,   446,    -1,   448,    -1,
     448,   245,    69,   558,   447,    -1,    -1,   610,    -1,   449,
      -1,   449,   194,   449,    -1,   450,    -1,   449,   172,   450,
      -1,   449,   154,   450,    -1,   451,    -1,   450,   189,   451,
      -1,   450,   114,   451,    -1,   450,   142,   451,    -1,   450,
     155,   451,    -1,   452,    -1,   451,   196,   452,    -1,   451,
     205,   452,    -1,   453,    -1,   452,   146,   453,    -1,   452,
     132,   453,    -1,   454,    -1,   454,    48,   226,   520,    -1,
     455,    -1,   455,   195,    92,   520,    -1,   456,    -1,   456,
      98,    92,   518,    -1,   457,    -1,   457,    99,    92,   518,
      -1,   459,    -1,   458,   459,    -1,   172,    -1,   154,    -1,
     458,   172,    -1,   458,   154,    -1,   462,    -1,   466,    -1,
     463,    -1,   198,    -1,   203,    -1,   202,    -1,   201,    -1,
     200,    -1,   199,    -1,   147,    -1,   175,    -1,   136,    -1,
      74,   149,   391,   180,    -1,    74,   217,   149,   391,   180,
      -1,    74,   216,   149,   391,   180,    -1,    74,    92,   535,
     149,   391,   180,    -1,   464,   149,   180,    -1,   464,   149,
     391,   180,    -1,   465,    -1,   464,   465,    -1,   173,   613,
      16,    -1,   173,    17,    -1,   467,    -1,   467,   468,    -1,
     188,   468,    -1,   468,    -1,   187,    -1,   469,    -1,   469,
     187,   468,    -1,   469,   188,   468,    -1,   470,    -1,   479,
      -1,   471,    -1,   471,   480,    -1,   474,    -1,   474,   480,
      -1,   472,   476,    -1,   473,    -1,   102,   118,    -1,   111,
     118,    -1,    95,   118,    -1,   185,   118,    -1,   112,   118,
      -1,   135,   118,    -1,   134,   118,    -1,   476,    -1,    96,
     476,    -1,   475,   476,    -1,   117,    -1,   168,   118,    -1,
      88,   118,    -1,   177,   118,    -1,   176,   118,    -1,    89,
     118,    -1,   525,    -1,   477,    -1,   613,    -1,   478,    -1,
     189,    -1,    11,    -1,    18,    -1,   482,    -1,   479,   480,
      -1,   479,   152,   183,    -1,   479,   152,   491,   183,    -1,
     481,    -1,   480,   481,    -1,   150,   391,   181,    -1,   483,
      -1,   485,    -1,   486,    -1,   487,    -1,   490,    -1,   492,
      -1,   488,    -1,   489,    -1,   538,    -1,   484,    -1,   537,
      -1,   107,    -1,   145,    -1,   120,    -1,   115,   613,    -1,
     152,   183,    -1,   152,   391,   183,    -1,   116,    -1,   165,
     149,   391,   180,    -1,   197,   149,   391,   180,    -1,   614,
     152,   183,    -1,   614,   152,   491,   183,    -1,   394,    -1,
     491,   104,   394,    -1,   493,    -1,   511,    -1,   494,    -1,
     508,    -1,   509,    -1,   153,   613,   498,   126,    -1,   153,
     613,   496,   498,   126,    -1,   153,   613,   498,   192,   190,
     613,   498,   192,    -1,   153,   613,   498,   192,   495,   190,
     613,   498,   192,    -1,   153,   613,   496,   498,   192,   190,
     613,   498,   192,    -1,   153,   613,   496,   498,   192,   495,
     190,   613,   498,   192,    -1,   506,    -1,   495,   506,    -1,
     497,    -1,   496,   497,    -1,    31,   613,   498,   128,   498,
     499,    -1,    -1,    31,    -1,   179,   500,   179,    -1,    91,
     502,    91,    -1,    -1,   501,    -1,   130,    -1,   504,    -1,
     501,   130,    -1,   501,   504,    -1,    -1,   503,    -1,   129,
      -1,   505,    -1,   503,   129,    -1,   503,   505,    -1,    24,
      -1,   507,    -1,     5,    -1,   507,    -1,   493,    -1,    10,
      -1,   510,    -1,   507,    -1,     9,    -1,   119,    -1,   121,
      -1,   388,    -1,   208,    26,   209,    -1,   208,   209,    -1,
     170,   612,   171,    -1,   170,   612,     8,    -1,   100,     7,
      -1,   512,    -1,   513,    -1,   514,    -1,   515,    -1,   516,
      -1,   517,    -1,    40,   149,   391,   180,    -1,    19,   180,
      -1,    19,   391,   180,    -1,    42,   149,   391,   180,   149,
     180,    -1,    42,   149,   391,   180,   149,   391,   180,    -1,
      20,   180,    -1,    20,   391,   180,    -1,    95,   149,   391,
     180,   149,   180,    -1,    95,   149,   391,   180,   149,   391,
     180,    -1,    69,   149,   391,   180,    -1,    35,   149,   391,
     180,    -1,    21,   180,    -1,    21,   391,   180,    -1,    58,
     149,   391,   180,   149,   180,    -1,    58,   149,   391,   180,
     149,   391,   180,    -1,   524,    -1,   524,   140,    -1,    92,
     520,    -1,   522,    -1,   522,   521,    -1,   206,   152,   183,
      -1,   140,    -1,   189,    -1,   172,    -1,   524,    -1,   525,
      -1,   148,   152,   183,    -1,   541,    -1,   544,    -1,   520,
      -1,   523,   104,   520,    -1,   613,    -1,   527,    -1,   533,
      -1,   531,    -1,   534,    -1,   532,    -1,   530,    -1,   529,
      -1,   528,    -1,   526,    -1,   220,   152,   183,    -1,    41,
     152,   183,    -1,    41,   152,   533,   183,    -1,    41,   152,
     534,   183,    -1,    69,   152,   183,    -1,    35,   152,   183,
      -1,    58,   152,   183,    -1,    58,   152,   612,   183,    -1,
      58,   152,    25,   183,    -1,    95,   152,   183,    -1,    95,
     152,   613,   183,    -1,    95,   152,   613,   104,   535,   183,
      -1,    95,   152,   189,   183,    -1,    95,   152,   189,   104,
     535,   183,    -1,    60,   152,   613,   183,    -1,    42,   152,
     183,    -1,    42,   152,   613,   183,    -1,    42,   152,   613,
     104,   535,   183,    -1,    42,   152,   613,   104,   536,   183,
      -1,    42,   152,   189,   183,    -1,    42,   152,   189,   104,
     535,   183,    -1,    42,   152,   189,   104,   536,   183,    -1,
      61,   152,   613,   183,    -1,   613,    -1,   613,   140,    -1,
      25,    -1,   539,    -1,   540,    -1,   613,   141,   145,    -1,
      45,   368,   388,    -1,   542,    -1,   543,    -1,    45,   152,
     189,   183,    -1,    45,   152,   183,    92,   520,    -1,    45,
     152,   523,   183,    92,   520,    -1,   152,   522,   183,    -1,
      29,   215,   216,    -1,    29,   215,   217,    -1,    29,   215,
     218,    -1,   221,   220,   394,   228,   394,    -1,   221,   220,
     394,    92,   227,   228,   394,    -1,   221,   220,   394,    92,
     229,   228,   394,    -1,   221,   220,   394,   213,   394,    -1,
     221,   220,   394,   214,   394,    -1,   221,   222,   394,   228,
     394,    -1,   221,   222,   394,    92,   227,   228,   394,    -1,
     221,   222,   394,    92,   229,   228,   394,    -1,   221,   222,
     394,   213,   394,    -1,   221,   222,   394,   214,   394,    -1,
     219,   220,   394,    -1,   219,   222,   394,    -1,   224,   220,
     394,   232,   394,    -1,   224,   225,   226,   220,   394,   232,
     394,    -1,   223,   220,   394,    92,   394,    -1,   231,   115,
     551,   230,   394,   182,   394,    -1,   552,    -1,   551,   104,
     115,   552,    -1,   613,   138,   394,    -1,   240,   149,   391,
     180,   554,    -1,   555,    -1,   554,   555,    -1,   241,   556,
     389,    -1,   241,   556,   152,   115,   613,   183,   389,    -1,
     241,   556,   152,   115,   613,   104,   115,   613,   183,   389,
      -1,   241,   556,   152,   115,   613,   104,   115,   613,   104,
     115,   613,   183,   389,    -1,   477,    -1,   556,   205,   477,
      -1,   242,   115,   412,    43,   149,   394,   180,    -1,    43,
     149,   394,   180,    -1,   561,   559,    -1,    -1,   560,    -1,
     579,    -1,   560,   579,    -1,   562,    -1,   561,   258,   562,
      -1,   563,    -1,   562,   254,   563,    -1,   564,    -1,   563,
     256,   143,   564,    -1,   565,    -1,   255,   565,    -1,   569,
     566,   567,    -1,    -1,   584,    -1,    -1,   568,    -1,   278,
     149,   391,   180,    -1,   573,   570,    -1,   152,   558,   183,
      -1,   571,    -1,    -1,   606,    -1,   464,   149,   572,   180,
      -1,    -1,   558,    -1,   574,   575,    -1,   483,    -1,   149,
     391,   180,    -1,    -1,   576,    -1,   244,   577,    -1,   243,
     578,    -1,   266,    -1,    -1,    76,    -1,    -1,   282,    -1,
     580,    -1,   581,    -1,   582,    -1,   608,    -1,   605,    -1,
     165,    -1,   280,   449,   583,    -1,   249,   607,   583,    -1,
     282,    -1,   272,    -1,   265,    -1,   242,   585,    -1,   584,
     242,   585,    -1,   586,    -1,   587,    -1,   588,    -1,   603,
      -1,   589,    -1,   597,    -1,   590,    -1,   604,    -1,    97,
     270,    -1,    97,   259,    -1,   262,    -1,   277,    -1,   247,
     270,    -1,   247,   259,    -1,    55,   613,    25,    -1,   273,
      -1,    52,   273,    -1,   275,   591,    -1,   275,   152,   591,
     592,   183,    -1,    52,   275,    -1,   594,    -1,   110,    -1,
      -1,   593,    -1,   594,    -1,   593,   104,   594,    -1,    94,
      25,   595,   596,    -1,    -1,   267,    25,    -1,    -1,   607,
     261,    -1,   274,   282,   598,   600,    -1,   274,   282,   110,
     600,    -1,    52,   274,   282,    -1,    94,    25,    -1,   152,
     599,   183,    -1,    25,    -1,   599,   104,    25,    -1,    -1,
     601,    -1,   602,    -1,   601,   602,    -1,   196,   598,    -1,
     132,   598,    -1,   260,    25,    -1,   279,    -1,    52,   279,
      -1,    94,   212,    -1,    94,   250,    -1,   251,   246,    -1,
     263,   607,   276,    -1,   252,   449,    -1,    94,   125,   449,
      -1,    94,    50,   449,    -1,   253,   449,   194,   449,    -1,
     268,   609,    -1,   248,   609,    -1,   271,    -1,   264,    -1,
     281,   246,   451,    -1,    25,    -1,    15,    -1,   613,    -1,
     614,    -1,    95,    -1,    35,    -1,    41,    -1,    42,    -1,
     148,    -1,    46,    -1,   220,    -1,    58,    -1,    60,    -1,
      61,    -1,    69,    -1,    72,    -1,    71,    -1,   206,    -1,
     239,    -1,    22,    -1,   210,    -1,   123,    -1,    34,    -1,
     257,    -1,    33,    -1,   217,    -1,   216,    -1,   142,    -1,
      40,    -1,   255,    -1,   256,    -1,   270,    -1,   259,    -1,
     247,    -1,   281,    -1,   273,    -1,   275,    -1,   274,    -1,
     279,    -1,   251,    -1,   246,    -1,    76,    -1,   212,    -1,
     250,    -1,    50,    -1,   218,    -1,   231,    -1,   298,    -1,
     225,    -1,   198,    -1,   203,    -1,   202,    -1,   201,    -1,
     200,    -1,   199,    -1,    94,    -1,   108,    -1,   109,    -1,
     182,    -1,    44,    -1,    32,    -1,    65,    -1,    70,    -1,
      57,    -1,    51,    -1,    54,    -1,    75,    -1,    38,    -1,
     143,    -1,    49,    -1,   207,    -1,   166,    -1,   167,    -1,
     164,    -1,    68,    -1,    93,    -1,   113,    -1,   124,    -1,
     125,    -1,   103,    -1,    66,    -1,   131,    -1,   184,    -1,
      97,    -1,    92,    -1,   193,    -1,   122,    -1,   163,    -1,
      90,    -1,    48,    -1,   226,    -1,    98,    -1,   194,    -1,
     114,    -1,   155,    -1,   196,    -1,   146,    -1,   132,    -1,
      74,    -1,    99,    -1,   195,    -1,   147,    -1,   178,    -1,
     191,    -1,   156,    -1,   133,    -1,   127,    -1,   162,    -1,
     144,    -1,   161,    -1,    29,    -1,    36,    -1,    56,    -1,
     110,    -1,    37,    -1,    55,    -1,   211,    -1,    47,    -1,
      59,    -1,    30,    -1,    45,    -1,   269,    -1,   245,    -1,
     278,    -1,   280,    -1,   249,    -1,   263,    -1,   276,    -1,
     268,    -1,   248,    -1,   262,    -1,   277,    -1,   267,    -1,
     261,    -1,   260,    -1,   244,    -1,   243,    -1,   266,    -1,
     252,    -1,   253,    -1,   282,    -1,   272,    -1,   271,    -1,
     264,    -1,   224,    -1,   230,    -1,   227,    -1,   221,    -1,
     214,    -1,   213,    -1,   215,    -1,   232,    -1,   222,    -1,
     223,    -1,   229,    -1,   219,    -1,   228,    -1,    64,    -1,
      62,    -1,    73,    -1,    39,    -1,    53,    -1,   165,    -1,
     197,    -1,   238,    -1,   233,    -1,   236,    -1,   237,    -1,
     234,    -1,   235,    -1,   240,    -1,   241,    -1,    43,    -1,
     242,    -1,    63,    -1,   291,    -1,   289,    -1,   290,    -1,
     295,    -1,   296,    -1,   297,    -1,   292,    -1,   293,    -1,
     294,    -1,    77,    -1,    78,    -1,    79,    -1,    80,    -1,
      81,    -1,    82,    -1,    83,    -1,    84,    -1,    85,    -1,
      86,    -1,    87,    -1,   283,    -1,   284,    -1,   285,    -1,
     286,    -1,   287,    -1,   288,    -1,   299,    -1,   300,    -1,
     301,    -1,   302,    -1,   303,    -1,   304,    -1,   305,    -1,
      88,    -1,   102,    -1,   111,    -1,   168,    -1,   176,    -1,
     185,    -1,   134,    -1,    89,    -1,   112,    -1,   135,    -1,
     177,    -1
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
     993,   997,   999,  1004,  1006,  1011,  1013,  1017,  1022,  1027,
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
    1458,  1463,  1465,  1468,  1472,  1475,  1477,  1480,  1483,  1485,
    1487,  1489,  1493,  1497,  1499,  1501,  1503,  1506,  1508,  1511,
    1514,  1516,  1519,  1522,  1525,  1528,  1531,  1534,  1537,  1539,
    1542,  1545,  1547,  1550,  1553,  1556,  1559,  1562,  1564,  1566,
    1568,  1570,  1572,  1574,  1576,  1578,  1581,  1585,  1590,  1592,
    1595,  1599,  1601,  1603,  1605,  1607,  1609,  1611,  1613,  1615,
    1617,  1619,  1621,  1623,  1625,  1627,  1630,  1633,  1637,  1639,
    1644,  1649,  1653,  1658,  1660,  1664,  1666,  1668,  1670,  1672,
    1674,  1679,  1685,  1694,  1704,  1714,  1725,  1727,  1730,  1732,
    1735,  1742,  1743,  1745,  1749,  1753,  1754,  1756,  1758,  1760,
    1763,  1766,  1767,  1769,  1771,  1773,  1776,  1779,  1781,  1783,
    1785,  1787,  1789,  1791,  1793,  1795,  1797,  1799,  1801,  1803,
    1807,  1810,  1814,  1818,  1821,  1823,  1825,  1827,  1829,  1831,
    1833,  1838,  1841,  1845,  1852,  1860,  1863,  1867,  1874,  1882,
    1887,  1892,  1895,  1899,  1906,  1914,  1916,  1919,  1922,  1924,
    1927,  1931,  1933,  1935,  1937,  1939,  1941,  1945,  1947,  1949,
    1951,  1955,  1957,  1959,  1961,  1963,  1965,  1967,  1969,  1971,
    1973,  1975,  1979,  1983,  1988,  1993,  1997,  2001,  2005,  2010,
    2015,  2019,  2024,  2031,  2036,  2043,  2048,  2052,  2057,  2064,
    2071,  2076,  2083,  2090,  2095,  2097,  2100,  2102,  2104,  2106,
    2110,  2114,  2116,  2118,  2123,  2129,  2136,  2140,  2144,  2148,
    2152,  2158,  2166,  2174,  2180,  2186,  2192,  2200,  2208,  2214,
    2220,  2224,  2228,  2234,  2242,  2248,  2256,  2258,  2263,  2267,
    2273,  2275,  2278,  2282,  2290,  2301,  2315,  2317,  2321,  2329,
    2334,  2337,  2338,  2340,  2342,  2345,  2347,  2351,  2353,  2357,
    2359,  2364,  2366,  2369,  2373,  2374,  2376,  2377,  2379,  2384,
    2387,  2391,  2393,  2394,  2396,  2401,  2402,  2404,  2407,  2409,
    2413,  2414,  2416,  2419,  2422,  2424,  2425,  2427,  2428,  2430,
    2432,  2434,  2436,  2438,  2440,  2442,  2446,  2450,  2452,  2454,
    2456,  2459,  2463,  2465,  2467,  2469,  2471,  2473,  2475,  2477,
    2479,  2482,  2485,  2487,  2489,  2492,  2495,  2499,  2501,  2504,
    2507,  2513,  2516,  2518,  2520,  2521,  2523,  2525,  2529,  2534,
    2535,  2538,  2539,  2542,  2547,  2552,  2556,  2559,  2563,  2565,
    2569,  2570,  2572,  2574,  2577,  2580,  2583,  2586,  2588,  2591,
    2594,  2597,  2600,  2604,  2607,  2611,  2615,  2620,  2623,  2626,
    2628,  2630,  2634,  2636,  2638,  2640,  2642,  2644,  2646,  2648,
    2650,  2652,  2654,  2656,  2658,  2660,  2662,  2664,  2666,  2668,
    2670,  2672,  2674,  2676,  2678,  2680,  2682,  2684,  2686,  2688,
    2690,  2692,  2694,  2696,  2698,  2700,  2702,  2704,  2706,  2708,
    2710,  2712,  2714,  2716,  2718,  2720,  2722,  2724,  2726,  2728,
    2730,  2732,  2734,  2736,  2738,  2740,  2742,  2744,  2746,  2748,
    2750,  2752,  2754,  2756,  2758,  2760,  2762,  2764,  2766,  2768,
    2770,  2772,  2774,  2776,  2778,  2780,  2782,  2784,  2786,  2788,
    2790,  2792,  2794,  2796,  2798,  2800,  2802,  2804,  2806,  2808,
    2810,  2812,  2814,  2816,  2818,  2820,  2822,  2824,  2826,  2828,
    2830,  2832,  2834,  2836,  2838,  2840,  2842,  2844,  2846,  2848,
    2850,  2852,  2854,  2856,  2858,  2860,  2862,  2864,  2866,  2868,
    2870,  2872,  2874,  2876,  2878,  2880,  2882,  2884,  2886,  2888,
    2890,  2892,  2894,  2896,  2898,  2900,  2902,  2904,  2906,  2908,
    2910,  2912,  2914,  2916,  2918,  2920,  2922,  2924,  2926,  2928,
    2930,  2932,  2934,  2936,  2938,  2940,  2942,  2944,  2946,  2948,
    2950,  2952,  2954,  2956,  2958,  2960,  2962,  2964,  2966,  2968,
    2970,  2972,  2974,  2976,  2978,  2980,  2982,  2984,  2986,  2988,
    2990,  2992,  2994,  2996,  2998,  3000,  3002,  3004,  3006,  3008,
    3010,  3012,  3014,  3016,  3018,  3020,  3022,  3024,  3026,  3028,
    3030,  3032,  3034,  3036,  3038,  3040,  3042,  3044,  3046,  3048,
    3050,  3052,  3054,  3056,  3058,  3060,  3062,  3064,  3066,  3068,
    3070
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,  1018,  1018,  1019,  1052,  1061,  1066,  1073,  1078,  1089,
    1093,  1101,  1106,  1111,  1116,  1121,  1129,  1137,  1145,  1157,
    1161,  1166,  1171,  1180,  1189,  1195,  1201,  1214,  1220,  1226,
    1238,  1239,  1240,  1241,  1242,  1247,  1248,  1249,  1250,  1251,
    1252,  1253,  1254,  1260,  1265,  1274,  1280,  1289,  1298,  1299,
    1300,  1301,  1302,  1303,  1304,  1305,  1306,  1307,  1312,  1313,
    1314,  1315,  1316,  1317,  1318,  1321,  1326,  1327,  1332,  1340,
    1346,  1356,  1362,  1372,  1382,  1390,  1396,  1407,  1412,  1422,
    1428,  1434,  1440,  1457,  1465,  1473,  1477,  1486,  1495,  1508,
    1514,  1525,  1529,  1537,  1542,  1547,  1554,  1567,  1574,  1580,
    1587,  1593,  1597,  1604,  1615,  1620,  1625,  1630,  1639,  1645,
    1651,  1660,  1666,  1675,  1679,  1685,  1689,  1693,  1697,  1703,
    1709,  1715,  1721,  1727,  1731,  1737,  1743,  1750,  1758,  1766,
    1774,  1782,  1794,  1808,  1822,  1839,  1843,  1852,  1856,  1863,
    1871,  1889,  1895,  1903,  1908,  1915,  1922,  1932,  1942,  1952,
    1962,  1979,  1985,  1996,  2000,  2004,  2008,  2015,  2022,  2041,
    2051,  2057,  2063,  2073,  2079,  2086,  2092,  2102,  2109,  2116,
    2128,  2132,  2140,  2144,  2152,  2156,  2163,  2167,  2175,  2180,
    2189,  2193,  2197,  2201,  2209,  2220,  2235,  2246,  2261,  2272,
    2288,  2294,  2306,  2310,  2321,  2328,  2336,  2351,  2355,  2369,
    2373,  2382,  2386,  2414,  2415,  2416,  2417,  2418,  2419,  2422,
    2423,  2424,  2425,  2426,  2428,  2429,  2432,  2433,  2434,  2435,
    2436,  2441,  2456,  2463,  2467,  2474,  2478,  2482,  2489,  2497,
    2508,  2518,  2531,  2540,  2541,  2542,  2546,  2547,  2548,  2549,
    2550,  2553,  2559,  2569,  2577,  2583,  2595,  2599,  2603,  2607,
    2611,  2615,  2619,  2624,  2630,  2639,  2649,  2659,  2675,  2684,
    2694,  2702,  2708,  2717,  2723,  2732,  2746,  2754,  2764,  2772,
    2784,  2790,  2801,  2803,  2807,  2815,  2819,  2824,  2828,  2832,
    2836,  2846,  2854,  2861,  2867,  2878,  2882,  2891,  2899,  2905,
    2915,  2921,  2931,  2935,  2945,  2951,  2957,  2963,  2972,  2981,
    2990,  3003,  3007,  3015,  3021,  3031,  3039,  3048,  3061,  3068,
    3080,  3084,  3096,  3103,  3109,  3118,  3125,  3131,  3143,  3150,
    3163,  3169,  3181,  3187,  3199,  3208,  3212,  3221,  3225,  3233,
    3237,  3247,  3254,  3263,  3273,  3272,  3286,  3295,  3304,  3317,
    3321,  3334,  3337,  3344,  3348,  3357,  3361,  3365,  3374,  3378,
    3384,  3390,  3396,  3407,  3411,  3415,  3423,  3427,  3433,  3443,
    3447,  3457,  3461,  3471,  3475,  3485,  3489,  3499,  3503,  3511,
    3515,  3519,  3523,  3533,  3537,  3541,  3549,  3553,  3557,  3561,
    3565,  3569,  3577,  3581,  3585,  3593,  3597,  3601,  3605,  3616,
    3622,  3632,  3638,  3648,  3652,  3691,  3695,  3705,  3715,  3729,
    3739,  3749,  3753,  3763,  3767,  3776,  3782,  3790,  3796,  3808,
    3814,  3824,  3828,  3832,  3836,  3840,  3846,  3852,  3875,  3879,
    3887,  3891,  3902,  3906,  3910,  3916,  3920,  3934,  3938,  3946,
    3950,  3960,  3964,  3968,  3977,  3981,  3985,  3989,  3997,  4003,
    4013,  4021,  4025,  4029,  4033,  4037,  4041,  4045,  4049,  4053,
    4061,  4065,  4073,  4080,  4087,  4098,  4106,  4110,  4118,  4126,
    4134,  4188,  4192,  4205,  4211,  4221,  4225,  4233,  4237,  4241,
    4249,  4259,  4269,  4279,  4289,  4299,  4314,  4320,  4331,  4337,
    4348,  4359,  4361,  4365,  4370,  4380,  4383,  4390,  4396,  4402,
    4410,  4423,  4426,  4433,  4439,  4445,  4452,  4463,  4467,  4477,
    4481,  4491,  4495,  4499,  4504,  4513,  4519,  4525,  4531,  4541,
    4545,  4557,  4561,  4573,  4585,  4589,  4593,  4597,  4601,  4605,
    4613,  4621,  4625,  4629,  4633,  4650,  4654,  4658,  4662,  4670,
    4678,  4686,  4690,  4694,  4698,  4706,  4712,  4722,  4730,  4734,
    4738,  4773,  4779,  4785,  4795,  4799,  4803,  4807,  4811,  4818,
    4824,  4834,  4842,  4846,  4850,  4854,  4858,  4862,  4866,  4870,
    4874,  4882,  4890,  4894,  4898,  4908,  4916,  4924,  4928,  4932,
    4940,  4944,  4950,  4956,  4960,  4970,  4978,  4982,  4988,  4997,
    5006,  5012,  5018,  5028,  5045,  5052,  5067,  5103,  5107,  5116,
    5125,  5135,  5139,  5148,  5157,  5161,  5172,  5189,  5195,  5201,
    5211,  5215,  5221,  5227,  5231,  5237,  5241,  5247,  5253,  5260,
    5270,  5275,  5283,  5289,  5299,  5321,  5330,  5336,  5349,  5363,
    5370,  5376,  5386,  5391,  5396,  5406,  5419,  5425,  5442,  5446,
    5461,  5470,  5473,  5480,  5485,  5493,  5497,  5504,  5508,  5515,
    5519,  5526,  5530,  5539,  5552,  5555,  5563,  5566,  5574,  5582,
    5590,  5594,  5602,  5605,  5613,  5625,  5628,  5636,  5648,  5654,
    5664,  5667,  5675,  5679,  5683,  5691,  5694,  5702,  5705,  5713,
    5717,  5721,  5725,  5729,  5737,  5745,  5757,  5769,  5773,  5777,
    5785,  5791,  5801,  5805,  5809,  5813,  5817,  5821,  5825,  5829,
    5837,  5841,  5845,  5849,  5857,  5863,  5873,  5883,  5887,  5895,
    5905,  5916,  5923,  5927,  5935,  5938,  5945,  5950,  5959,  5969,
    5972,  5980,  5983,  5991,  6000,  6007,  6017,  6021,  6028,  6034,
    6044,  6047,  6054,  6059,  6071,  6079,  6091,  6099,  6103,  6111,
    6115,  6119,  6127,  6135,  6139,  6143,  6147,  6155,  6163,  6175,
    6179,  6187,  6200,  6204,  6205,  6218,  6219,  6220,  6221,  6222,
    6223,  6224,  6225,  6226,  6227,  6228,  6229,  6230,  6231,  6232,
    6233,  6237,  6238,  6239,  6240,  6241,  6242,  6243,  6244,  6245,
    6246,  6247,  6248,  6249,  6250,  6251,  6252,  6253,  6254,  6255,
    6256,  6257,  6258,  6259,  6260,  6261,  6262,  6263,  6264,  6265,
    6266,  6267,  6268,  6269,  6270,  6271,  6272,  6273,  6274,  6275,
    6276,  6277,  6278,  6279,  6280,  6281,  6282,  6283,  6284,  6285,
    6286,  6287,  6288,  6289,  6290,  6291,  6292,  6293,  6294,  6295,
    6296,  6297,  6298,  6299,  6300,  6301,  6302,  6303,  6304,  6305,
    6306,  6307,  6308,  6309,  6310,  6311,  6312,  6313,  6314,  6315,
    6316,  6317,  6318,  6319,  6320,  6321,  6322,  6323,  6324,  6325,
    6326,  6327,  6328,  6329,  6330,  6331,  6332,  6333,  6334,  6335,
    6336,  6337,  6338,  6339,  6340,  6341,  6342,  6343,  6344,  6345,
    6346,  6347,  6348,  6349,  6350,  6351,  6352,  6353,  6354,  6355,
    6356,  6357,  6358,  6359,  6360,  6361,  6362,  6363,  6364,  6365,
    6366,  6367,  6368,  6369,  6370,  6371,  6372,  6373,  6374,  6375,
    6376,  6377,  6378,  6379,  6380,  6381,  6382,  6383,  6384,  6385,
    6386,  6387,  6388,  6389,  6390,  6391,  6392,  6393,  6394,  6395,
    6396,  6397,  6398,  6399,  6400,  6401,  6402,  6403,  6404,  6405,
    6406,  6407,  6408,  6409,  6410,  6411,  6412,  6413,  6414,  6415,
    6416,  6417,  6418,  6419,  6420,  6421,  6422,  6423,  6424,  6425,
    6426,  6427,  6428,  6429,  6430,  6431,  6432,  6433,  6434,  6435,
    6436
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
  const int xquery_parser::yylast_ = 12280;
  const int xquery_parser::yynnts_ = 295;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 556;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 320;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 574;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


} // zorba

/* Line 1054 of lalr1.cc  */
#line 15843 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.cpp"


/* Line 1056 of lalr1.cc  */
#line 6440 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"


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
    driver.set_expr(new ParseErrorNode(driver.parserError->loc, XPST0003, driver.parserError->msg));
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

