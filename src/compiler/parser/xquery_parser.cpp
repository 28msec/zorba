
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002, 2003, 2004, 2005, 2006, 2007, 2008 Free Software
   Foundation, Inc.
   
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
#line 72 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"


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
#line 79 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"


#include "xquery_parser.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 861 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 317 of lalr1.cc  */
#line 961 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"

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
#line 150 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"

#ifndef YY_
# if YYENABLE_NLS
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


/* Line 380 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

namespace zorba {

/* Line 380 of lalr1.cc  */
#line 219 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
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
#line 859 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 326 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 120: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 858 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 335 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 145: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 857 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 344 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 324: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 353 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 325: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 362 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 326: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 371 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 380 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 389 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 398 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 407 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 416 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 425 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 882 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 434 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 882 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 443 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 452 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 461 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 470 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 479 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 488 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 497 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 506 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 515 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 524 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 533 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 542 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 551 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 560 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 569 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 578 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 587 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 596 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 605 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 614 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 623 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 882 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 632 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 641 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "DeclPropertyList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 650 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "DeclProperty" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 659 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 668 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "NodeModifier" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 677 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 686 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 695 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 704 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 713 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 722 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 882 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 731 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 740 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "Block" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 749 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "BlockDecls" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 758 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "BlockVarDeclList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 767 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "BlockVarDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 776 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "AssignExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 785 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "ExitExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 794 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "WhileExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 803 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "AnnotationList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 821 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "Annotation" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 830 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "AnnotationLiteralList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 839 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 848 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 857 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "FunctionDeclSimple" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 866 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "FunctionDeclSequential" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 875 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 884 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 893 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 902 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "EnclosedExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 911 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 920 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 938 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "ApplyExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 947 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "ConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 956 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 965 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 974 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 983 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 992 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1001 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1010 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1019 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1028 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1037 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1046 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1055 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1064 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1073 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1082 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1091 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "EvalVarDeclList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1100 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1109 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1118 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1127 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1136 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1145 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "EvalVarDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1154 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1163 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1172 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1181 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1190 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1199 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1208 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1217 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1226 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1235 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1244 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1253 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1262 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1271 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1280 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1289 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "SwitchExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1298 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "SwitchCaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1307 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "SwitchCaseClause" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1316 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "SwitchCaseOperandList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1325 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1334 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1343 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1352 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1361 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1370 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1379 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1388 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1397 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1406 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1415 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1424 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1433 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1442 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1451 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1460 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1469 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1478 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1487 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1496 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1505 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1514 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1523 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1532 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1541 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1550 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1559 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1568 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1577 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1586 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1595 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1604 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1613 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1622 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1631 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1640 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1649 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1658 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1667 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1676 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1685 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1694 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1703 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1712 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1721 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1730 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1739 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1748 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1757 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1766 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1775 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1784 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1793 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1802 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1811 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1820 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1829 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1838 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1847 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1856 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1865 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1874 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1883 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1892 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1901 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1910 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1919 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1928 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1937 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1946 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1955 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1964 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1973 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1982 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1991 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2000 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2009 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2018 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2027 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2036 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2045 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2054 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2063 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2072 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "AtomicType" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2081 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2090 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2099 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2108 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2117 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2126 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2135 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2144 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2153 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 533: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2162 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 534: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2171 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 535: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2180 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 536: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2189 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 537: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2198 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2207 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 543: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2216 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 546: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2225 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 547: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2234 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 548: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2243 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 549: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2252 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 550: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2261 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 551: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2270 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 552: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2279 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 553: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2288 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 554: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2297 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 555: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2306 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 556: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 882 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2315 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 557: /* "EvalExpr" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2324 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 558: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2333 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 561: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2342 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 562: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2351 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 563: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2360 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 564: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2369 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 565: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2378 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 566: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2387 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 568: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2396 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 569: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2405 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 570: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2414 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 571: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2423 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 573: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2432 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 574: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2441 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 576: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2450 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 579: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2459 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 580: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2468 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 581: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2477 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 582: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2486 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 583: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2495 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 584: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2504 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 585: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2513 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 586: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2522 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 587: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2531 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 588: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2540 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 589: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2549 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 590: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2558 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 594: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2567 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 597: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2576 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 598: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2585 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 602: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2594 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 603: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2603 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 604: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2612 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 605: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2621 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 606: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2630 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 607: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2639 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 608: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2648 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 609: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2657 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 610: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 876 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2666 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 613: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2675 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 614: /* "FUNCTION_NAME" */

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2684 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
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
    
/* Line 553 of lalr1.cc  */
#line 125 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename2);
}

/* Line 553 of lalr1.cc  */
#line 2769 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"

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
#line 1020 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 1053 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL; YYABORT;
        }
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 1062 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 1067 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            MainModule *mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
            mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 1074 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 1079 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            LibraryModule *lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
            lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 1090 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8" );
        }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 1094 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
        }
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 1102 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);
          (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
        }
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 1107 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));
          (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
        }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 1112 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)), static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));
          (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
        }
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 1117 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
        }
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 1122 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1130 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1138 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1146 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1158 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
        }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 1162 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);
          (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
        }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 1167 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));
          (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
        }
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 1172 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)), static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));
          (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
        }
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 1181 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
            dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
        }
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 1190 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
            sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
            (yyval.node) = sdl;
        }
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 1196 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 1202 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1215 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
            vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
            (yyval.node) = vdl;
        }
    break;

  case 28:

/* Line 678 of lalr1.cc  */
#line 1221 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 29:

/* Line 678 of lalr1.cc  */
#line 1227 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1261 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
          delete (yysemantic_stack_[(4) - (4)].vstrpair);
        }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 1266 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
          delete (yysemantic_stack_[(4) - (4)].vstrpair);
        }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 1275 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.vstrpair) = new vector<string_pair_t>();
          (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
          delete (yysemantic_stack_[(1) - (1)].strpair);
        }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 1281 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
          delete (yysemantic_stack_[(2) - (2)].strpair);
          (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
        }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 1290 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
            (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
            delete sl;
        }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 1298 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 1299 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 1300 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 1301 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 1302 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 1303 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 54:

/* Line 678 of lalr1.cc  */
#line 1304 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 55:

/* Line 678 of lalr1.cc  */
#line 1305 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 1306 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 1307 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 1333 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
        }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 1341 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BoundarySpaceDecl(
                LOC((yyloc)), StaticContextConsts::preserve_space
            );
        }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 1347 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BoundarySpaceDecl(
                LOC((yyloc)), StaticContextConsts::strip_space
            );
        }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 1357 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultNamespaceDecl(
                LOC((yyloc)), ParseConstants::ns_element_default, SYMTAB((yysemantic_stack_[(5) - (5)].sval))
            );
        }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 1363 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultNamespaceDecl(
                LOC((yyloc)), ParseConstants::ns_function_default, SYMTAB((yysemantic_stack_[(5) - (5)].sval))
            );
        }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 1373 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OptionDecl(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval))
            );
        }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 1383 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
        }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 1391 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OrderingModeDecl(
                LOC((yyloc)), StaticContextConsts::ordered
            );
        }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 1397 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OrderingModeDecl(
                LOC((yyloc)), StaticContextConsts::unordered
            );
        }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 1408 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new EmptyOrderDecl( LOC((yyloc)),
                                StaticContextConsts::empty_greatest);
        }
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 1413 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new EmptyOrderDecl( LOC((yyloc)),
                                StaticContextConsts::empty_least);
        }
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 1423 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::preserve_ns,
                                StaticContextConsts::inherit_ns);
        }
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 1429 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::preserve_ns,
                                StaticContextConsts::no_inherit_ns);
        }
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 1435 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::no_preserve_ns,
                                StaticContextConsts::inherit_ns);
        }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 1441 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::no_preserve_ns,
                                StaticContextConsts::no_inherit_ns);
        }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 1458 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
        }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 1466 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 1474 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
        }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 1478 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1487 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1496 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1509 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            URILiteralList *ull = new URILiteralList( LOC((yyloc)));
            ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.node) = ull;
        }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 1515 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
                ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 1526 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 1530 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
        }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 1538 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 1543 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 1548 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 1555 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1568 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
        }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 1575 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            CtxItemDecl *d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
            d->type = (yysemantic_stack_[(3) - (2)].node);
            (yyval.node) = d;
        }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 1581 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 1588 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            CtxItemDecl *d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
            d->ext = false;
            (yyval.node) = d;
        }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 1594 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CtxItemDecl( LOC((yyloc)), NULL );
        }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 1598 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 1605 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CtxItemDecl( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 1616 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)), NULL, NULL);
      dynamic_cast<VarNameAndType*>((yyval.varnametype))->setComment(SYMTAB((yysemantic_stack_[(4) - (1)].sval)));
    }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 1621 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)), NULL);
      dynamic_cast<VarNameAndType*>((yyval.varnametype))->setComment(SYMTAB((yysemantic_stack_[(5) - (1)].sval)));
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 1626 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (5)].expr)), NULL, static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (2)].node)));
      dynamic_cast<VarNameAndType*>((yyval.varnametype))->setComment(SYMTAB((yysemantic_stack_[(5) - (1)].sval)));
    }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 1631 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (5)].expr)), dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)), static_cast<AnnotationListParsenode*>((yysemantic_stack_[(6) - (2)].node)));
      dynamic_cast<VarNameAndType*>((yyval.varnametype))->setComment(SYMTAB((yysemantic_stack_[(6) - (1)].sval)));
    }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 1640 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(3) - (1)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, (yysemantic_stack_[(3) - (3)].expr), nt->get_annotations());
      dynamic_cast<VarDecl*>((yyval.node))->setComment(nt->getCommentString());
    }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 1646 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(2) - (1)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, NULL, nt->get_annotations(), true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(nt->getCommentString());
    }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 1652 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(4) - (1)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, (yysemantic_stack_[(4) - (4)].expr), nt->get_annotations(), true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(nt->getCommentString());
    }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 1661 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            DeclPropertyList *dpl = new DeclPropertyList( LOC((yyloc)) );
            dpl->addProperty(dynamic_cast<DeclProperty*>((yysemantic_stack_[(1) - (1)].node)));
            (yyval.node) = dpl;
        }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 1667 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
        DeclPropertyList *dpl = dynamic_cast<DeclPropertyList*>((yysemantic_stack_[(2) - (1)].node));
        dpl->addProperty( static_cast<DeclProperty*>((yysemantic_stack_[(2) - (2)].node)) );
        (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 1676 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_const );
        }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 1680 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_append_only
            );
        }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 1686 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_queue );
        }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 1690 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_mutable );
        }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 1694 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_ordered );
        }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 1698 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_unordered
            );
        }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 1704 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_value_equality
            );
        }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 1710 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_value_range
            );
        }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 1716 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_general_equality
            );
        }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 1722 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_general_range
            );
        }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 1728 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_unique );
        }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 1732 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_non_unique
            );
        }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 1738 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_automatic
            );
        }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 1744 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_manual );
        }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 1751 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1759 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1767 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1775 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1783 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1795 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1809 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1823 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1840 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 1844 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 1853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier(LOC((yyloc)), StaticContextConsts::read_only);
    }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 1857 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier(LOC((yyloc)), StaticContextConsts::mutable_node);
    }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 1864 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1872 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1890 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1896 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 1904 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 1909 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 1916 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 1923 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 1934 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1944 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1954 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1965 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1980 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ConstructionDecl(
                LOC((yyloc)), StaticContextConsts::cons_preserve
            );
        }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 1986 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ConstructionDecl(
                LOC((yyloc)), StaticContextConsts::cons_strip
            );
        }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 1997 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( NULL );
        }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 2001 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 2005 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)) );
        }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 2009 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 157:

/* Line 678 of lalr1.cc  */
#line 2016 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(2) - (2)].expr);
        }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 2023 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2042 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2051 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 2058 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vfo = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node));
            vfo->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = vfo;
        }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 2064 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vfo = new VFO_DeclList( LOC((yyloc)) );
            vfo->push_back((yysemantic_stack_[(2) - (2)].node));
            (yyval.node) = vfo;
        }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 2074 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      VarDecl* vd = new VarDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL, NULL);
      vd->set_global(false);
      (yyval.node) = vd;
    }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 2080 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      VarDecl* vd = new VarDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)), NULL, NULL);

      vd->set_global(false);
      (yyval.node) = vd;
    }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 2087 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      VarDecl* vd = new VarDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)), NULL, (yysemantic_stack_[(4) - (4)].expr), NULL);
      vd->set_global(false);
      (yyval.node) = vd;
    }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 2093 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      VarDecl* vd = new VarDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (3)].node)), (yysemantic_stack_[(5) - (5)].expr), NULL);
      vd->set_global(false);
      (yyval.node) = vd;
    }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 2103 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 2110 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExitExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 2117 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2129 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::BREAK );
        }
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 2133 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
        }
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 2141 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnnotationListParsenode( LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
        }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 2145 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 2153 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnnotationParsenode( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
        }
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 2157 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnnotationParsenode( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))), static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
        }
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 2164 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnnotationLiteralListParsenode( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
        }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 2168 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 2176 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 2181 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node))->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );
            static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node))->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
            (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
        }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 2190 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 2194 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 182:

/* Line 678 of lalr1.cc  */
#line 2198 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 2202 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 2210 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2221 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2236 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2247 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2262 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2273 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2289 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            ParamList *pl = new ParamList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 191:

/* Line 678 of lalr1.cc  */
#line 2295 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
                pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 192:

/* Line 678 of lalr1.cc  */
#line 2307 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 193:

/* Line 678 of lalr1.cc  */
#line 2311 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 2322 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new EnclosedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 2329 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 2337 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QueryBody( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 2352 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 2356 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2370 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new BlockBody( LOC((yyloc)) );
        }
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 2374 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            BlockBody *bb = dynamic_cast<BlockBody*>((yysemantic_stack_[(3) - (1)].expr));
            bb->add( (yysemantic_stack_[(3) - (2)].expr) );
            (yyval.expr) = bb;
        }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 2383 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 2387 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2442 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2457 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 2464 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_sliding;
        }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 2468 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_tumbling;
        }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 2475 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_start;
        }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 2479 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_end;
        }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 2483 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_only_end;
        }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 2490 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2498 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FLWORWinCond(
                LOC((yyloc)), NULL, (yysemantic_stack_[(3) - (3)].expr),
                (yysemantic_stack_[(3) - (1)].strval) == parser::the_start, (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end
            );
        }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 2509 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2519 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2532 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 2554 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
            fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = fcl;
        }
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 2560 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
            fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = fcl;
        }
    break;

  case 243:

/* Line 678 of lalr1.cc  */
#line 2570 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
        }
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 2578 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            VarInDeclList *vdl = new VarInDeclList( LOC((yyloc)) );
            vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vdl;
        }
    break;

  case 245:

/* Line 678 of lalr1.cc  */
#line 2584 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( VarInDeclList *vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 2596 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 2600 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)), NULL, NULL, NULL, (yysemantic_stack_[(5) - (5)].expr), true);
    }
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 2604 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)), dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)), NULL, NULL, (yysemantic_stack_[(4) - (4)].expr), false);
    }
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 2608 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (1)].expr)), dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (2)].node)), NULL, NULL, (yysemantic_stack_[(6) - (6)].expr), true);
    }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 2612 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)), NULL, dynamic_cast<PositionalVar*>((yysemantic_stack_[(4) - (2)].node)), NULL, (yysemantic_stack_[(4) - (4)].expr), false);
    }
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 2616 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (1)].expr)), NULL, dynamic_cast<PositionalVar*>((yysemantic_stack_[(6) - (4)].node)), NULL, (yysemantic_stack_[(6) - (6)].expr), true);
    }
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 2620 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (3)].node)), NULL, (yysemantic_stack_[(5) - (5)].expr), false);
    }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 2625 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(7) - (1)].expr)), dynamic_cast<SequenceType *>((yysemantic_stack_[(7) - (2)].node)),
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(7) - (5)].node)), NULL, (yysemantic_stack_[(7) - (7)].expr), true);
    }
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 2631 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2640 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2650 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2660 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2676 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 2685 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
    }
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 2695 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (3)].node)) );
        }
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 2703 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 2709 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 2718 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 2724 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 2736 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)),
                           NULL,
                           NULL,
                           (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 2744 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                           NULL,
                           (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 2754 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                           NULL,
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
                           (yysemantic_stack_[(4) - (4)].expr));
     }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 2762 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
                           (yysemantic_stack_[(5) - (5)].expr));
     }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 2774 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 2780 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 2793 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 2797 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 2805 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 2809 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 2818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 2822 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 2826 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 2834 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)),
                           NULL, NULL,
                           new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr))),
                           VarGetsDecl::eval_var);
    }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 2848 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 2856 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 2863 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = new GroupSpecList( LOC((yyloc)) );
            gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 2869 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
            if ( gsl )
                gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 2880 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 2884 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                         dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 2893 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 2901 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 2907 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 2917 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 2923 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 2933 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 2937 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 2947 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 2953 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 2959 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 2965 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2974 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2983 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2992 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3005 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 3009 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 3017 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 3023 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 3033 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 3041 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3050 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3063 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 3070 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 3082 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 3086 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 3098 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 3105 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 3111 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 3120 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 3127 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 3133 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 3145 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 3152 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3165 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 3171 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 3183 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 3189 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 3201 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 3210 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 3214 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 3223 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 3227 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 3235 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 3239 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3249 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 3256 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3265 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3274 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 3279 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3288 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3297 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3306 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3319 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 3323 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3335 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 3339 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 3346 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 3350 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 3359 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 3363 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 3367 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 3376 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 3380 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 3386 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 3392 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 3398 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 3409 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 3413 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 3417 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 3425 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 3429 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 3435 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 3445 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 3449 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 3459 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 3463 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 3473 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 3477 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 3487 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 3491 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 3501 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 3505 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 3513 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 3517 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 3521 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 3525 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 3535 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 3539 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 3543 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 3551 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 3555 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 3559 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 3563 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 3567 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 3571 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 3579 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 3583 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 3587 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 3595 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 3599 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 3603 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 3607 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 3618 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 3624 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 3634 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 3640 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 3650 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 3654 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 3692 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new PathExpr(LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
        }
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 3696 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new PathExpr(
                LOC((yyloc)), ParseConstants::path_leading_slash, (yysemantic_stack_[(2) - (2)].expr)
            );
        }
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 3702 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new PathExpr(
                LOC((yyloc)), ParseConstants::path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr)
            );
        }
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 3708 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            RelativePathExpr *rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = !rpe ?
                (yysemantic_stack_[(1) - (1)].expr) : new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 3719 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NULL;
        }
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 3727 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 401:

/* Line 678 of lalr1.cc  */
#line 3738 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RelativePathExpr(
                LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 3744 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RelativePathExpr(
                LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 3754 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 3758 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 3766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 3772 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3780 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 3786 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3798 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 3804 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 3814 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 3818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 3822 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 3826 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 3830 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 3836 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 3842 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 3865 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 3869 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 3877 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 3881 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 3892 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 3896 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 3900 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 3906 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 3910 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 3924 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 3928 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 3936 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 3940 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 3950 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all);
    }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 3954 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem);
    }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 3958 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix);
    }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 3967 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 3971 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 3975 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
     }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 3979 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
     }
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 3987 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 3993 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 4003 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 4011 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 4015 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 4019 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 4023 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 4027 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 4031 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 4035 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 4039 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 4043 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 4051 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 4055 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 4063 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 4070 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 4077 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 4088 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 4096 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 4100 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 4108 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 4116 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 4124 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 4178 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
        }
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 4182 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4195 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            ArgList *al = new ArgList( LOC((yyloc)) );
            al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
            (yyval.node) = al;
        }
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 4201 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
                al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 4211 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 4215 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 4223 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 4227 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 4231 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 4239 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4249 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4259 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4269 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4279 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4289 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4304 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
            decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = decl;
        }
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 4310 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( decl )
                decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 4321 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
            dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = dal;
        }
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 4327 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
            if ( dal )
                dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 4338 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4355 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 4360 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 4369 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
        }
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 4373 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 4380 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = qacl;
        }
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 4386 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = qacl;
        }
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 4392 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4400 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4412 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
        }
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 4416 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 4423 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = aacl;
        }
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 4429 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = aacl;
        }
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 4435 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if (aacl)
                aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 4442 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( aacl )
                aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 4453 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 4457 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 4467 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 4471 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 4481 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 4485 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 4489 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
        }
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 4494 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
        }
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 4503 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval))
            );
        }
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 4509 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_lbrace
            );
        }
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 4515 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_rbrace
            );
        }
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 4521 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 509:

/* Line 678 of lalr1.cc  */
#line 4531 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 510:

/* Line 678 of lalr1.cc  */
#line 4535 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
        }
    break;

  case 511:

/* Line 678 of lalr1.cc  */
#line 4547 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 512:

/* Line 678 of lalr1.cc  */
#line 4551 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 4563 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 4575 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 4579 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 4583 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 4587 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 4591 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 4595 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 4603 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 521:

/* Line 678 of lalr1.cc  */
#line 4611 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (1)].sval))), NULL);
        }
    break;

  case 522:

/* Line 678 of lalr1.cc  */
#line 4615 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
        }
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 4619 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 4623 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 4640 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (1)].sval))), NULL );
        }
    break;

  case 526:

/* Line 678 of lalr1.cc  */
#line 4644 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 4648 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 4652 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 4660 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 4668 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 4676 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (1)].sval)), NULL );
        }
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 4680 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 4684 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 534:

/* Line 678 of lalr1.cc  */
#line 4688 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 4696 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)), false
            );
        }
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 4702 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)), true
            );
        }
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 4712 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 4720 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 4724 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 4728 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 4763 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 542:

/* Line 678 of lalr1.cc  */
#line 4769 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 543:

/* Line 678 of lalr1.cc  */
#line 4775 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 544:

/* Line 678 of lalr1.cc  */
#line 4785 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 4789 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 4793 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)),true );
        }
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 4797 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 4801 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 549:

/* Line 678 of lalr1.cc  */
#line 4808 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 550:

/* Line 678 of lalr1.cc  */
#line 4814 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 4824 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 4832 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 4836 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 4840 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 555:

/* Line 678 of lalr1.cc  */
#line 4844 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 556:

/* Line 678 of lalr1.cc  */
#line 4848 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 557:

/* Line 678 of lalr1.cc  */
#line 4852 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 558:

/* Line 678 of lalr1.cc  */
#line 4856 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 559:

/* Line 678 of lalr1.cc  */
#line 4860 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 560:

/* Line 678 of lalr1.cc  */
#line 4864 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 561:

/* Line 678 of lalr1.cc  */
#line 4872 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyKindTest( LOC((yyloc)) );
        }
    break;

  case 562:

/* Line 678 of lalr1.cc  */
#line 4880 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)) );
        }
    break;

  case 563:

/* Line 678 of lalr1.cc  */
#line 4884 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)) );
        }
    break;

  case 564:

/* Line 678 of lalr1.cc  */
#line 4888 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest(
                LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 565:

/* Line 678 of lalr1.cc  */
#line 4898 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TextTest( LOC((yyloc)) );
        }
    break;

  case 566:

/* Line 678 of lalr1.cc  */
#line 4906 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CommentTest( LOC((yyloc)));
        }
    break;

  case 567:

/* Line 678 of lalr1.cc  */
#line 4914 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 568:

/* Line 678 of lalr1.cc  */
#line 4918 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 569:

/* Line 678 of lalr1.cc  */
#line 4922 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 570:

/* Line 678 of lalr1.cc  */
#line 4930 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 571:

/* Line 678 of lalr1.cc  */
#line 4934 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 572:

/* Line 678 of lalr1.cc  */
#line 4940 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 573:

/* Line 678 of lalr1.cc  */
#line 4946 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 574:

/* Line 678 of lalr1.cc  */
#line 4950 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 575:

/* Line 678 of lalr1.cc  */
#line 4960 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 576:

/* Line 678 of lalr1.cc  */
#line 4968 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 577:

/* Line 678 of lalr1.cc  */
#line 4972 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 578:

/* Line 678 of lalr1.cc  */
#line 4978 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4987 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4996 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 581:

/* Line 678 of lalr1.cc  */
#line 5002 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 582:

/* Line 678 of lalr1.cc  */
#line 5008 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 583:

/* Line 678 of lalr1.cc  */
#line 5018 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 584:

/* Line 678 of lalr1.cc  */
#line 5035 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 585:

/* Line 678 of lalr1.cc  */
#line 5042 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 586:

/* Line 678 of lalr1.cc  */
#line 5057 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 587:

/* Line 678 of lalr1.cc  */
#line 5093 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 588:

/* Line 678 of lalr1.cc  */
#line 5097 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 589:

/* Line 678 of lalr1.cc  */
#line 5106 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
        }
    break;

  case 590:

/* Line 678 of lalr1.cc  */
#line 5115 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new InlineFunction(LOC ((yyloc)), &*(yysemantic_stack_[(3) - (2)].fnsig)->param, &*(yysemantic_stack_[(3) - (2)].fnsig)->ret, dynamic_cast<EnclosedExpr *>((yysemantic_stack_[(3) - (3)].expr)));
          delete (yysemantic_stack_[(3) - (2)].fnsig);
        }
    break;

  case 591:

/* Line 678 of lalr1.cc  */
#line 5125 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 592:

/* Line 678 of lalr1.cc  */
#line 5129 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 593:

/* Line 678 of lalr1.cc  */
#line 5138 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
        }
    break;

  case 594:

/* Line 678 of lalr1.cc  */
#line 5147 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 595:

/* Line 678 of lalr1.cc  */
#line 5151 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 596:

/* Line 678 of lalr1.cc  */
#line 5162 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 597:

/* Line 678 of lalr1.cc  */
#line 5179 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 598:

/* Line 678 of lalr1.cc  */
#line 5185 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 599:

/* Line 678 of lalr1.cc  */
#line 5191 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 600:

/* Line 678 of lalr1.cc  */
#line 5201 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 601:

/* Line 678 of lalr1.cc  */
#line 5205 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 602:

/* Line 678 of lalr1.cc  */
#line 5211 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 603:

/* Line 678 of lalr1.cc  */
#line 5217 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 604:

/* Line 678 of lalr1.cc  */
#line 5221 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 605:

/* Line 678 of lalr1.cc  */
#line 5227 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 606:

/* Line 678 of lalr1.cc  */
#line 5231 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 607:

/* Line 678 of lalr1.cc  */
#line 5237 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 608:

/* Line 678 of lalr1.cc  */
#line 5243 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 609:

/* Line 678 of lalr1.cc  */
#line 5250 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 610:

/* Line 678 of lalr1.cc  */
#line 5260 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 611:

/* Line 678 of lalr1.cc  */
#line 5265 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 612:

/* Line 678 of lalr1.cc  */
#line 5273 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 613:

/* Line 678 of lalr1.cc  */
#line 5279 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 614:

/* Line 678 of lalr1.cc  */
#line 5289 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 615:

/* Line 678 of lalr1.cc  */
#line 5311 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 616:

/* Line 678 of lalr1.cc  */
#line 5320 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 617:

/* Line 678 of lalr1.cc  */
#line 5326 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 618:

/* Line 678 of lalr1.cc  */
#line 5339 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 619:

/* Line 678 of lalr1.cc  */
#line 5353 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 620:

/* Line 678 of lalr1.cc  */
#line 5360 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 621:

/* Line 678 of lalr1.cc  */
#line 5366 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 622:

/* Line 678 of lalr1.cc  */
#line 5376 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 623:

/* Line 678 of lalr1.cc  */
#line 5381 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CatchExpr(LOC((yyloc)),*(yysemantic_stack_[(7) - (2)].name_test_list), static_cast<QName*>((yysemantic_stack_[(7) - (5)].expr)), NULL, NULL, (yysemantic_stack_[(7) - (7)].expr));
       delete (yysemantic_stack_[(7) - (2)].name_test_list);
    }
    break;

  case 624:

/* Line 678 of lalr1.cc  */
#line 5386 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5396 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5409 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 627:

/* Line 678 of lalr1.cc  */
#line 5415 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 628:

/* Line 678 of lalr1.cc  */
#line 5432 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new EvalExpr(LOC((yyloc)), dynamic_cast<VarGetsDeclList *> ((yysemantic_stack_[(7) - (3)].node)), (yysemantic_stack_[(7) - (6)].expr));
        }
    break;

  case 629:

/* Line 678 of lalr1.cc  */
#line 5436 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new EvalExpr( LOC((yyloc)), new VarGetsDeclList( LOC((yyloc)) ), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 630:

/* Line 678 of lalr1.cc  */
#line 5451 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 631:

/* Line 678 of lalr1.cc  */
#line 5459 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 632:

/* Line 678 of lalr1.cc  */
#line 5463 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 633:

/* Line 678 of lalr1.cc  */
#line 5470 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 634:

/* Line 678 of lalr1.cc  */
#line 5475 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 635:

/* Line 678 of lalr1.cc  */
#line 5483 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 636:

/* Line 678 of lalr1.cc  */
#line 5487 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 637:

/* Line 678 of lalr1.cc  */
#line 5494 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 638:

/* Line 678 of lalr1.cc  */
#line 5498 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 639:

/* Line 678 of lalr1.cc  */
#line 5505 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 640:

/* Line 678 of lalr1.cc  */
#line 5509 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 641:

/* Line 678 of lalr1.cc  */
#line 5516 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 642:

/* Line 678 of lalr1.cc  */
#line 5520 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 643:

/* Line 678 of lalr1.cc  */
#line 5529 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5541 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 645:

/* Line 678 of lalr1.cc  */
#line 5545 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 646:

/* Line 678 of lalr1.cc  */
#line 5552 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 647:

/* Line 678 of lalr1.cc  */
#line 5556 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 648:

/* Line 678 of lalr1.cc  */
#line 5564 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 649:

/* Line 678 of lalr1.cc  */
#line 5572 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5580 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 651:

/* Line 678 of lalr1.cc  */
#line 5584 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 652:

/* Line 678 of lalr1.cc  */
#line 5591 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 653:

/* Line 678 of lalr1.cc  */
#line 5595 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 654:

/* Line 678 of lalr1.cc  */
#line 5603 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5614 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 656:

/* Line 678 of lalr1.cc  */
#line 5618 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 657:

/* Line 678 of lalr1.cc  */
#line 5626 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5638 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 659:

/* Line 678 of lalr1.cc  */
#line 5644 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 660:

/* Line 678 of lalr1.cc  */
#line 5653 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 661:

/* Line 678 of lalr1.cc  */
#line 5657 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 662:

/* Line 678 of lalr1.cc  */
#line 5665 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 663:

/* Line 678 of lalr1.cc  */
#line 5669 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 664:

/* Line 678 of lalr1.cc  */
#line 5673 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 665:

/* Line 678 of lalr1.cc  */
#line 5680 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 666:

/* Line 678 of lalr1.cc  */
#line 5684 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 667:

/* Line 678 of lalr1.cc  */
#line 5691 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 668:

/* Line 678 of lalr1.cc  */
#line 5695 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 669:

/* Line 678 of lalr1.cc  */
#line 5703 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 670:

/* Line 678 of lalr1.cc  */
#line 5707 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 671:

/* Line 678 of lalr1.cc  */
#line 5711 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 672:

/* Line 678 of lalr1.cc  */
#line 5715 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 673:

/* Line 678 of lalr1.cc  */
#line 5719 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 674:

/* Line 678 of lalr1.cc  */
#line 5727 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 675:

/* Line 678 of lalr1.cc  */
#line 5735 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5747 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5759 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 678:

/* Line 678 of lalr1.cc  */
#line 5763 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 679:

/* Line 678 of lalr1.cc  */
#line 5767 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 680:

/* Line 678 of lalr1.cc  */
#line 5775 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 681:

/* Line 678 of lalr1.cc  */
#line 5781 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 682:

/* Line 678 of lalr1.cc  */
#line 5791 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 683:

/* Line 678 of lalr1.cc  */
#line 5795 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 684:

/* Line 678 of lalr1.cc  */
#line 5799 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 685:

/* Line 678 of lalr1.cc  */
#line 5803 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 686:

/* Line 678 of lalr1.cc  */
#line 5807 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 687:

/* Line 678 of lalr1.cc  */
#line 5811 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 688:

/* Line 678 of lalr1.cc  */
#line 5815 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 689:

/* Line 678 of lalr1.cc  */
#line 5819 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 690:

/* Line 678 of lalr1.cc  */
#line 5827 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 691:

/* Line 678 of lalr1.cc  */
#line 5831 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 692:

/* Line 678 of lalr1.cc  */
#line 5835 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 693:

/* Line 678 of lalr1.cc  */
#line 5839 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 694:

/* Line 678 of lalr1.cc  */
#line 5847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 695:

/* Line 678 of lalr1.cc  */
#line 5853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 696:

/* Line 678 of lalr1.cc  */
#line 5863 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 697:

/* Line 678 of lalr1.cc  */
#line 5873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::with );
        }
    break;

  case 698:

/* Line 678 of lalr1.cc  */
#line 5877 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::without );
        }
    break;

  case 699:

/* Line 678 of lalr1.cc  */
#line 5885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5895 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5906 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 702:

/* Line 678 of lalr1.cc  */
#line 5913 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 703:

/* Line 678 of lalr1.cc  */
#line 5917 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 704:

/* Line 678 of lalr1.cc  */
#line 5924 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 705:

/* Line 678 of lalr1.cc  */
#line 5928 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(1) - (1)].thesaurus_id_list);
        }
    break;

  case 706:

/* Line 678 of lalr1.cc  */
#line 5935 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 707:

/* Line 678 of lalr1.cc  */
#line 5940 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 708:

/* Line 678 of lalr1.cc  */
#line 5949 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 709:

/* Line 678 of lalr1.cc  */
#line 5958 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = NULL;
        }
    break;

  case 710:

/* Line 678 of lalr1.cc  */
#line 5962 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 711:

/* Line 678 of lalr1.cc  */
#line 5969 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 712:

/* Line 678 of lalr1.cc  */
#line 5973 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 713:

/* Line 678 of lalr1.cc  */
#line 5981 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5990 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 715:

/* Line 678 of lalr1.cc  */
#line 5997 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 716:

/* Line 678 of lalr1.cc  */
#line 6007 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 717:

/* Line 678 of lalr1.cc  */
#line 6011 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 718:

/* Line 678 of lalr1.cc  */
#line 6018 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 719:

/* Line 678 of lalr1.cc  */
#line 6024 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 720:

/* Line 678 of lalr1.cc  */
#line 6033 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 721:

/* Line 678 of lalr1.cc  */
#line 6037 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 722:

/* Line 678 of lalr1.cc  */
#line 6044 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 723:

/* Line 678 of lalr1.cc  */
#line 6049 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 6061 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 6069 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 6081 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 727:

/* Line 678 of lalr1.cc  */
#line 6089 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 728:

/* Line 678 of lalr1.cc  */
#line 6093 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 729:

/* Line 678 of lalr1.cc  */
#line 6101 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 730:

/* Line 678 of lalr1.cc  */
#line 6105 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 731:

/* Line 678 of lalr1.cc  */
#line 6109 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 732:

/* Line 678 of lalr1.cc  */
#line 6117 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 733:

/* Line 678 of lalr1.cc  */
#line 6125 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 734:

/* Line 678 of lalr1.cc  */
#line 6129 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 735:

/* Line 678 of lalr1.cc  */
#line 6133 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 736:

/* Line 678 of lalr1.cc  */
#line 6137 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 737:

/* Line 678 of lalr1.cc  */
#line 6145 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 6153 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 6165 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 740:

/* Line 678 of lalr1.cc  */
#line 6169 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 741:

/* Line 678 of lalr1.cc  */
#line 6177 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 744:

/* Line 678 of lalr1.cc  */
#line 6195 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 6208 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 747:

/* Line 678 of lalr1.cc  */
#line 6209 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 748:

/* Line 678 of lalr1.cc  */
#line 6210 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 749:

/* Line 678 of lalr1.cc  */
#line 6211 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 750:

/* Line 678 of lalr1.cc  */
#line 6212 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 751:

/* Line 678 of lalr1.cc  */
#line 6213 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 752:

/* Line 678 of lalr1.cc  */
#line 6214 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 753:

/* Line 678 of lalr1.cc  */
#line 6215 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 754:

/* Line 678 of lalr1.cc  */
#line 6216 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 755:

/* Line 678 of lalr1.cc  */
#line 6217 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 756:

/* Line 678 of lalr1.cc  */
#line 6218 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 757:

/* Line 678 of lalr1.cc  */
#line 6219 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 758:

/* Line 678 of lalr1.cc  */
#line 6220 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 759:

/* Line 678 of lalr1.cc  */
#line 6221 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 760:

/* Line 678 of lalr1.cc  */
#line 6222 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 761:

/* Line 678 of lalr1.cc  */
#line 6226 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 762:

/* Line 678 of lalr1.cc  */
#line 6227 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 763:

/* Line 678 of lalr1.cc  */
#line 6228 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 764:

/* Line 678 of lalr1.cc  */
#line 6229 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 765:

/* Line 678 of lalr1.cc  */
#line 6230 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 766:

/* Line 678 of lalr1.cc  */
#line 6231 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 767:

/* Line 678 of lalr1.cc  */
#line 6232 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 768:

/* Line 678 of lalr1.cc  */
#line 6233 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 769:

/* Line 678 of lalr1.cc  */
#line 6234 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 770:

/* Line 678 of lalr1.cc  */
#line 6235 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 771:

/* Line 678 of lalr1.cc  */
#line 6236 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 772:

/* Line 678 of lalr1.cc  */
#line 6237 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 773:

/* Line 678 of lalr1.cc  */
#line 6238 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 774:

/* Line 678 of lalr1.cc  */
#line 6239 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 775:

/* Line 678 of lalr1.cc  */
#line 6240 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 776:

/* Line 678 of lalr1.cc  */
#line 6241 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 777:

/* Line 678 of lalr1.cc  */
#line 6242 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 778:

/* Line 678 of lalr1.cc  */
#line 6243 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 779:

/* Line 678 of lalr1.cc  */
#line 6244 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 780:

/* Line 678 of lalr1.cc  */
#line 6245 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 781:

/* Line 678 of lalr1.cc  */
#line 6246 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 782:

/* Line 678 of lalr1.cc  */
#line 6247 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 783:

/* Line 678 of lalr1.cc  */
#line 6248 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 784:

/* Line 678 of lalr1.cc  */
#line 6249 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 785:

/* Line 678 of lalr1.cc  */
#line 6250 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 786:

/* Line 678 of lalr1.cc  */
#line 6251 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 787:

/* Line 678 of lalr1.cc  */
#line 6252 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 788:

/* Line 678 of lalr1.cc  */
#line 6253 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 789:

/* Line 678 of lalr1.cc  */
#line 6254 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 790:

/* Line 678 of lalr1.cc  */
#line 6255 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 791:

/* Line 678 of lalr1.cc  */
#line 6256 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 792:

/* Line 678 of lalr1.cc  */
#line 6257 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 793:

/* Line 678 of lalr1.cc  */
#line 6258 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 794:

/* Line 678 of lalr1.cc  */
#line 6259 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 795:

/* Line 678 of lalr1.cc  */
#line 6260 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 796:

/* Line 678 of lalr1.cc  */
#line 6261 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 797:

/* Line 678 of lalr1.cc  */
#line 6262 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 798:

/* Line 678 of lalr1.cc  */
#line 6263 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 799:

/* Line 678 of lalr1.cc  */
#line 6264 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 800:

/* Line 678 of lalr1.cc  */
#line 6265 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 801:

/* Line 678 of lalr1.cc  */
#line 6266 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 802:

/* Line 678 of lalr1.cc  */
#line 6267 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 803:

/* Line 678 of lalr1.cc  */
#line 6268 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 804:

/* Line 678 of lalr1.cc  */
#line 6269 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 805:

/* Line 678 of lalr1.cc  */
#line 6270 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 806:

/* Line 678 of lalr1.cc  */
#line 6271 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 807:

/* Line 678 of lalr1.cc  */
#line 6272 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 808:

/* Line 678 of lalr1.cc  */
#line 6273 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 809:

/* Line 678 of lalr1.cc  */
#line 6274 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 810:

/* Line 678 of lalr1.cc  */
#line 6275 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 811:

/* Line 678 of lalr1.cc  */
#line 6276 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 812:

/* Line 678 of lalr1.cc  */
#line 6277 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 813:

/* Line 678 of lalr1.cc  */
#line 6278 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 814:

/* Line 678 of lalr1.cc  */
#line 6279 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 815:

/* Line 678 of lalr1.cc  */
#line 6280 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 816:

/* Line 678 of lalr1.cc  */
#line 6281 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 817:

/* Line 678 of lalr1.cc  */
#line 6282 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 818:

/* Line 678 of lalr1.cc  */
#line 6283 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 819:

/* Line 678 of lalr1.cc  */
#line 6284 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 820:

/* Line 678 of lalr1.cc  */
#line 6285 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 821:

/* Line 678 of lalr1.cc  */
#line 6286 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 822:

/* Line 678 of lalr1.cc  */
#line 6287 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 823:

/* Line 678 of lalr1.cc  */
#line 6288 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 824:

/* Line 678 of lalr1.cc  */
#line 6289 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 825:

/* Line 678 of lalr1.cc  */
#line 6290 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 826:

/* Line 678 of lalr1.cc  */
#line 6291 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 827:

/* Line 678 of lalr1.cc  */
#line 6292 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 828:

/* Line 678 of lalr1.cc  */
#line 6293 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 829:

/* Line 678 of lalr1.cc  */
#line 6294 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 830:

/* Line 678 of lalr1.cc  */
#line 6295 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 831:

/* Line 678 of lalr1.cc  */
#line 6296 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 832:

/* Line 678 of lalr1.cc  */
#line 6297 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 833:

/* Line 678 of lalr1.cc  */
#line 6298 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 834:

/* Line 678 of lalr1.cc  */
#line 6299 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 835:

/* Line 678 of lalr1.cc  */
#line 6300 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 836:

/* Line 678 of lalr1.cc  */
#line 6301 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 837:

/* Line 678 of lalr1.cc  */
#line 6302 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 838:

/* Line 678 of lalr1.cc  */
#line 6303 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 839:

/* Line 678 of lalr1.cc  */
#line 6304 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 840:

/* Line 678 of lalr1.cc  */
#line 6305 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 841:

/* Line 678 of lalr1.cc  */
#line 6306 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 842:

/* Line 678 of lalr1.cc  */
#line 6307 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 843:

/* Line 678 of lalr1.cc  */
#line 6308 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 844:

/* Line 678 of lalr1.cc  */
#line 6309 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 845:

/* Line 678 of lalr1.cc  */
#line 6310 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 846:

/* Line 678 of lalr1.cc  */
#line 6311 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 847:

/* Line 678 of lalr1.cc  */
#line 6312 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 848:

/* Line 678 of lalr1.cc  */
#line 6313 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 849:

/* Line 678 of lalr1.cc  */
#line 6314 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 850:

/* Line 678 of lalr1.cc  */
#line 6315 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 851:

/* Line 678 of lalr1.cc  */
#line 6316 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 852:

/* Line 678 of lalr1.cc  */
#line 6317 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 853:

/* Line 678 of lalr1.cc  */
#line 6318 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 854:

/* Line 678 of lalr1.cc  */
#line 6319 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 855:

/* Line 678 of lalr1.cc  */
#line 6320 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 856:

/* Line 678 of lalr1.cc  */
#line 6321 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 857:

/* Line 678 of lalr1.cc  */
#line 6322 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 858:

/* Line 678 of lalr1.cc  */
#line 6323 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 859:

/* Line 678 of lalr1.cc  */
#line 6324 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 860:

/* Line 678 of lalr1.cc  */
#line 6325 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 861:

/* Line 678 of lalr1.cc  */
#line 6326 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 862:

/* Line 678 of lalr1.cc  */
#line 6327 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 863:

/* Line 678 of lalr1.cc  */
#line 6328 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 864:

/* Line 678 of lalr1.cc  */
#line 6329 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 865:

/* Line 678 of lalr1.cc  */
#line 6330 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 866:

/* Line 678 of lalr1.cc  */
#line 6331 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 867:

/* Line 678 of lalr1.cc  */
#line 6332 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 868:

/* Line 678 of lalr1.cc  */
#line 6333 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 869:

/* Line 678 of lalr1.cc  */
#line 6334 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 870:

/* Line 678 of lalr1.cc  */
#line 6335 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 871:

/* Line 678 of lalr1.cc  */
#line 6336 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 872:

/* Line 678 of lalr1.cc  */
#line 6337 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 873:

/* Line 678 of lalr1.cc  */
#line 6338 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 874:

/* Line 678 of lalr1.cc  */
#line 6339 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 875:

/* Line 678 of lalr1.cc  */
#line 6340 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 876:

/* Line 678 of lalr1.cc  */
#line 6341 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 877:

/* Line 678 of lalr1.cc  */
#line 6342 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 878:

/* Line 678 of lalr1.cc  */
#line 6343 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 879:

/* Line 678 of lalr1.cc  */
#line 6344 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 880:

/* Line 678 of lalr1.cc  */
#line 6345 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 881:

/* Line 678 of lalr1.cc  */
#line 6346 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 882:

/* Line 678 of lalr1.cc  */
#line 6347 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 883:

/* Line 678 of lalr1.cc  */
#line 6348 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 884:

/* Line 678 of lalr1.cc  */
#line 6349 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 885:

/* Line 678 of lalr1.cc  */
#line 6350 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 886:

/* Line 678 of lalr1.cc  */
#line 6351 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 887:

/* Line 678 of lalr1.cc  */
#line 6352 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 888:

/* Line 678 of lalr1.cc  */
#line 6353 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 889:

/* Line 678 of lalr1.cc  */
#line 6354 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 890:

/* Line 678 of lalr1.cc  */
#line 6355 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 891:

/* Line 678 of lalr1.cc  */
#line 6356 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 892:

/* Line 678 of lalr1.cc  */
#line 6357 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 893:

/* Line 678 of lalr1.cc  */
#line 6358 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 894:

/* Line 678 of lalr1.cc  */
#line 6359 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 895:

/* Line 678 of lalr1.cc  */
#line 6360 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 896:

/* Line 678 of lalr1.cc  */
#line 6361 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 897:

/* Line 678 of lalr1.cc  */
#line 6362 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 898:

/* Line 678 of lalr1.cc  */
#line 6363 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 899:

/* Line 678 of lalr1.cc  */
#line 6364 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 900:

/* Line 678 of lalr1.cc  */
#line 6365 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 901:

/* Line 678 of lalr1.cc  */
#line 6366 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 902:

/* Line 678 of lalr1.cc  */
#line 6367 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("deterministic"))); }
    break;

  case 903:

/* Line 678 of lalr1.cc  */
#line 6368 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nondeterministic"))); }
    break;

  case 904:

/* Line 678 of lalr1.cc  */
#line 6369 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 905:

/* Line 678 of lalr1.cc  */
#line 6370 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 906:

/* Line 678 of lalr1.cc  */
#line 6371 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 907:

/* Line 678 of lalr1.cc  */
#line 6372 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("block"))); }
    break;

  case 908:

/* Line 678 of lalr1.cc  */
#line 6373 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 909:

/* Line 678 of lalr1.cc  */
#line 6374 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 910:

/* Line 678 of lalr1.cc  */
#line 6375 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 911:

/* Line 678 of lalr1.cc  */
#line 6376 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 912:

/* Line 678 of lalr1.cc  */
#line 6377 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 913:

/* Line 678 of lalr1.cc  */
#line 6378 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 914:

/* Line 678 of lalr1.cc  */
#line 6379 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eval"))); }
    break;

  case 915:

/* Line 678 of lalr1.cc  */
#line 6380 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 916:

/* Line 678 of lalr1.cc  */
#line 6381 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 917:

/* Line 678 of lalr1.cc  */
#line 6382 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 918:

/* Line 678 of lalr1.cc  */
#line 6383 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 919:

/* Line 678 of lalr1.cc  */
#line 6384 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 920:

/* Line 678 of lalr1.cc  */
#line 6385 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 921:

/* Line 678 of lalr1.cc  */
#line 6386 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 922:

/* Line 678 of lalr1.cc  */
#line 6387 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 923:

/* Line 678 of lalr1.cc  */
#line 6388 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 924:

/* Line 678 of lalr1.cc  */
#line 6389 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 925:

/* Line 678 of lalr1.cc  */
#line 6390 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 926:

/* Line 678 of lalr1.cc  */
#line 6391 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 927:

/* Line 678 of lalr1.cc  */
#line 6392 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 928:

/* Line 678 of lalr1.cc  */
#line 6393 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 929:

/* Line 678 of lalr1.cc  */
#line 6394 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 930:

/* Line 678 of lalr1.cc  */
#line 6395 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 931:

/* Line 678 of lalr1.cc  */
#line 6396 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 932:

/* Line 678 of lalr1.cc  */
#line 6397 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 933:

/* Line 678 of lalr1.cc  */
#line 6398 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 934:

/* Line 678 of lalr1.cc  */
#line 6399 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 935:

/* Line 678 of lalr1.cc  */
#line 6400 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 936:

/* Line 678 of lalr1.cc  */
#line 6401 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 937:

/* Line 678 of lalr1.cc  */
#line 6402 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 938:

/* Line 678 of lalr1.cc  */
#line 6403 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 939:

/* Line 678 of lalr1.cc  */
#line 6404 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 940:

/* Line 678 of lalr1.cc  */
#line 6405 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 941:

/* Line 678 of lalr1.cc  */
#line 6406 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 942:

/* Line 678 of lalr1.cc  */
#line 6407 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 943:

/* Line 678 of lalr1.cc  */
#line 6408 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 944:

/* Line 678 of lalr1.cc  */
#line 6409 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 945:

/* Line 678 of lalr1.cc  */
#line 6410 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 946:

/* Line 678 of lalr1.cc  */
#line 6411 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 947:

/* Line 678 of lalr1.cc  */
#line 6412 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 948:

/* Line 678 of lalr1.cc  */
#line 6413 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 949:

/* Line 678 of lalr1.cc  */
#line 6414 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 950:

/* Line 678 of lalr1.cc  */
#line 6415 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 951:

/* Line 678 of lalr1.cc  */
#line 6416 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 952:

/* Line 678 of lalr1.cc  */
#line 6417 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 953:

/* Line 678 of lalr1.cc  */
#line 6418 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 954:

/* Line 678 of lalr1.cc  */
#line 6419 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 955:

/* Line 678 of lalr1.cc  */
#line 6420 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 956:

/* Line 678 of lalr1.cc  */
#line 6421 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 957:

/* Line 678 of lalr1.cc  */
#line 6422 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 958:

/* Line 678 of lalr1.cc  */
#line 6423 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 959:

/* Line 678 of lalr1.cc  */
#line 6424 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 960:

/* Line 678 of lalr1.cc  */
#line 6425 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;



/* Line 678 of lalr1.cc  */
#line 11520 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1363;
  const short int
  xquery_parser::yypact_[] =
  {
      2341, -1363, -1363,  2637,  2932,  3227, -1363, -1363,  1633,   104,
   -1363, -1363, -1363,   519, -1363, -1363, -1363, -1363,   148,   233,
     524,   255,   375,   391,   476,   533, -1363,   538, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363,   525, -1363,   557,   572, -1363,
     622, -1363, -1363,   642, -1363,   526, -1363,   610,   615, -1363,
      39, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363,   653,   654, -1363, -1363, -1363, -1363,
      14,  8537, -1363, -1363, -1363,   655, -1363, -1363, -1363, -1363,
   -1363,   656,   657, -1363, -1363, 11691, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363,   661, -1363, -1363,   660,   662, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363,  3522, 11691, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363,   632, -1363, -1363,   664,  9414,
   -1363,  9703,   665,   666, -1363, -1363, -1363,   667, -1363,  8242,
   -1363, -1363, -1363, -1363, -1363, -1363,   638, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363,    29,   577, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363,   422,   637,   482, -1363,   570,
     352, -1363, -1363, -1363, -1363, -1363, -1363,   677, -1363,   644,
     559,   562,   563, -1363, -1363,   648,   645, -1363,   688, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,  5587,
     804, -1363,  5882, -1363, -1363,   131,    40,    42, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363,   528, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
     -13, -1363, -1363, -1363, -1363,   364, -1363, -1363, -1363, -1363,
   -1363, -1363,   643,   715, -1363,   737,   566,   319,   407,   262,
      21, -1363,   764,   618,   716,   718,  6177, -1363, -1363, -1363,
     -19, -1363, -1363,  8242, -1363,   495, -1363,   668,  8537, -1363,
     668,  8537, -1363, -1363, -1363,   555, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,   674,
     669, -1363, -1363, -1363, -1363, -1363,   639, -1363,   640, -1363,
     646,   670,   798,   270,   442,   237, 11975, 11691,   321,   779,
     780,   784, 11691,   682,   717,   246,  9414, -1363, -1363,   470,
     437,   589, 11691, -1363, -1363, -1363, -1363, -1363,   544, 11691,
     540,   541,   444,   537,   430, -1363,   313, -1363, -1363, -1363,
   -1363, -1363,  9414,  6472,   658,  6472,    95,  6472, 10271,  6472,
     558,   560, 11691,   724,    -6,   693,  6472,    41,   117, 11691,
    6472,  9123, 11691, 11691, 11691, 11691,  6472,   671,  6472,  6472,
   11691,  6472,   695,   698, -1363, -1363, -1363,  6472, 10555,   696,
   -1363,   697, -1363, -1363, -1363, -1363, -1363,   699, -1363, -1363,
     700, -1363, -1363, -1363, -1363, -1363,   701, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, 11691, -1363, -1363,
   -1363,   672,   829,  6472, -1363, -1363,    91, -1363, -1363,   845,
   -1363, -1363, -1363, -1363,  6472,   663, -1363,   837,  6472,  6472,
     680,  6472,  6472,  6472,  6472,   641, 11691, -1363, -1363, -1363,
   -1363,  6472,  6472,  6472, 11691, -1363, -1363, -1363, -1363,  1633,
     533,    58,    60,   863,  6767,  6767,  7062,  7062,   732,  6472,
    6472, -1363,  6472,   756,   375,   538,   711,   713,   714,  6472,
    6472, -1363, -1363, -1363, -1363, -1363, -1363, -1363,  7357,  7357,
    7357, -1363,  7357,  7357, -1363,  7357, -1363,  7357, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363,  7357,  7357,   808,  7357,  7357,
    7357,  7357,  7357,  7357,  7357,  7357,  7357,  7357,  7357,   678,
     789,   790,   791, -1363, -1363, -1363,  3817, -1363, -1363,  8242,
    8242,  6472,   668, -1363, -1363,   668, -1363,  4112,   668,   741,
    4407, -1363, -1363, -1363,   249, -1363, -1363, -1363, -1363, -1363,
   -1363,   785,   787,   391,   867, -1363, -1363, 11975, -1363, 11975,
     612,   362, 11691,   738,   742,   612,   798,   782,   775, -1363,
   -1363, -1363, -1363, -1363,    32,   673,   -12, -1363,   611, -1363,
   -1363, -1363, -1363, 11691, 11691, 11691, -1363,   793, -1363, -1363,
     781,   730, -1363,   731,   697,   572, -1363,   733,   734,   739,
   -1363,    -1,    36,   740, -1363, -1363,   809, -1363,     2, 11691,
      -5, 11691,   822,    76, -1363,  6472, -1363,   735,  9414,   827,
     880,  9414,   798,   830,   819, -1363,   -27,   745,   743, -1363,
     744,   746,   747,   806,     3, -1363,   -15,   748, -1363,   759,
     762,   800, -1363,   767,  6472,  6472,   770, -1363,   214,   220,
      16, -1363, 11691,   829, -1363,    88,   771, -1363, -1363, -1363,
     772, -1363,   265, -1363, -1363, -1363,   -24,    89,   861,   722,
     749,   -37, -1363,   817,  7652, -1363,   773,   777,   276, -1363,
   -1363,   131,   556,   929,   929, -1363,    63, -1363, -1363,    68,
   -1363, -1363,   823, -1363, -1363, -1363, -1363,  6472, -1363, -1363,
      -2, 11691,   794,  6472,   844, -1363, -1363,   715, -1363, -1363,
   -1363, -1363, -1363,  7357, -1363, -1363, -1363,     6,   407,   407,
     445,   262,   262,   262,   262,    21,    21, -1363, -1363, 11123,
   11123, 11691, 11691, -1363,   783, -1363, -1363,   792, -1363, -1363,
   -1363,   223, -1363, -1363,   228,   256, -1363,     8,   191,   393,
   -1363,   391,   391, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363,   612, -1363,   836, 11407,   828,  6472, -1363,
   -1363, -1363,   873,   798,   798,   612, -1363,   619,   798,   383,
   11691,  -102,   341,   943, -1363, -1363,   689,   340, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,    32,
      75,   459, -1363,   750,   326,   -11,   675, 11691,   798, -1363,
   -1363, -1363, -1363,   825, 11691, -1363, 11691, -1363, -1363,   860,
     853, 11123,   862,  6472,   864,   -60,   835,     7,   298,   751,
   -1363, -1363,   508,    -5,   873, 11123,   865,   889,   803,   796,
     856,   798,   831,   857,   892,   798,   875,  6472,   854,   -53,
     842, -1363, -1363, -1363, -1363,  6472,   878,  6472,  6472,   851,
   -1363,   899,   901,  6472, -1363,   820,   824,   850, 11691, -1363,
   11691, -1363,  6472,   971, -1363,   250, -1363,    43, -1363, -1363,
     978, -1363,   479,  6472,  6472,  6472,   502,  6472,  6472,  6472,
    6472,  6472,  6472,   890,  6472,  6472,   891,     0,   832,   644,
     766,   859,   894,    71,    85,   823,  7062,  7062,  7062,   933,
   -1363, -1363, -1363,  6472,   481,   907, -1363, 11691,   909, -1363,
   -1363,  6472,     6,   402,   420, -1363,   752,   287,   760,   761,
   -1363, -1363,   589, -1363,   755,   -72,   869,   870, 11407,   871,
   -1363,   285, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363,   879, -1363, -1363, -1363,  6472, -1363, -1363,   249, -1363,
   -1363, -1363, -1363, -1363, -1363,  6472, -1363,   419,   456, -1363,
     990,   531, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363,   754, -1363, -1363,   999, -1363, -1363, -1363, -1363, -1363,
     371,  1000, -1363,   515, -1363, -1363, -1363,   696,   233,   699,
     557,   700,   701,   637,   795,   285,   807,   810,  7947,   757,
     726,    75, -1363,   812,   873,   840,  4702,   847,   848,   897,
     855,   858, 11691,   339, -1363, 11691, -1363, 11691,  6472,   896,
    6472,   919,  6472,   -57,   900,  6472,   902, -1363,   931,   932,
    6472, 11691,   603,   974, -1363, -1363, -1363, -1363, -1363, -1363,
   11123, -1363,  6472,   798,   946, -1363, -1363, -1363,   798,   946,
   11691, -1363,  6472,  6472,   914,  4997, -1363, 11691, -1363, -1363,
    6472,  6472,   535, -1363,    -8, 10839,   542, -1363,   877, -1363,
   -1363,  5292,   872,   876, -1363, -1363,   925, -1363,   193, -1363,
   -1363,  1051, -1363, -1363, 11691, -1363, -1363,   408, -1363, -1363,
   -1363,   874,   833,   834, -1363, -1363, -1363,   838,   839, -1363,
   -1363, -1363, -1363, -1363,   841, 11691,   881, -1363, 11691, -1363,
     891, -1363, -1363, -1363,  8832,   766, -1363,  6472, 11691,   929,
     292, -1363, -1363, -1363,   907, -1363,   798, -1363,   625, -1363,
      24,   961, -1363,  6472,   965,   844,   895,   886, -1363,     6,
     826, -1363, -1363,   -89, -1363,   241,    31,   846,     6,   241,
    7357, -1363,   -50, -1363, -1363, -1363, -1363, -1363, -1363,     6,
     928,   799,   673,    31, -1363, -1363,   801,  1002, -1363, -1363,
   -1363,  9987,   893,   898,   903, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363,   904, -1363, -1363, -1363,  6472, -1363, -1363, -1363,
   -1363,  1057,   145,  1060,   145,   821,   993, -1363, -1363, -1363,
   -1363,   924, 11691,   849,   795,  7947, -1363, -1363, -1363,   911,
   -1363, -1363, -1363, -1363, -1363, -1363,  6472,   950, -1363, -1363,
   -1363,  6472, -1363,   353, -1363,  6472,   951,  6472, -1363,  6472,
   11691, 11691, -1363,   513, -1363,  6472, -1363,   973,  1003,   798,
     946, -1363, -1363, -1363,  6472, -1363,   918, -1363, -1363, -1363,
     917, -1363,  6472,  6472, 11691,   921,    -7, -1363, -1363, -1363,
     920, -1363, -1363,   971, 11691,   510, -1363,   971, 11691, -1363,
   -1363,  6472,  6472,  6472,  6472,  6472, -1363,  6472,   206, -1363,
   -1363,   385, -1363,   937, -1363, -1363, -1363, -1363,   961, -1363,
   -1363, -1363,   798, -1363, -1363, -1363, -1363, -1363,   939,  7357,
   -1363, -1363, -1363, -1363, -1363,   141,  7357,  7357,   336, -1363,
     760, -1363,   156, -1363,   761,     6,   952, -1363, -1363,   852,
   -1363, -1363, -1363, -1363,  1013,   941, -1363,   260, -1363, -1363,
   -1363, -1363,    35, -1363,   253,   253, -1363,   145, -1363, -1363,
     261, -1363,  1086,    31,   942,  1016, -1363,  7947,   -55,   843,
   -1363,   963, -1363, -1363,  6472, -1363,  6472,   984, -1363,  6472,
   -1363, -1363, -1363,  1079, -1363, -1363,  6472,   798, -1363, -1363,
   -1363,  6472, -1363, -1363,  1039,  6472, 11691,  6472, -1363,    -3,
     971, 11691,   940,   971, -1363, -1363, -1363, -1363, -1363, -1363,
    6472,   995,  1019,  8832, -1363, -1363, -1363, -1363, -1363,   262,
    7357,  7357,   445,   425, -1363, -1363, -1363, -1363, -1363, -1363,
    6472, -1363, 11123, -1363, 11123,  1043, -1363, -1363, -1363, -1363,
    1111, -1363, -1363, -1363,   882, -1363,   993,  1033, -1363,   545,
   11691,  1023,   922, 11691,  7947, -1363, -1363,  6472, -1363,  1024,
   -1363,   946, -1363, 11123, -1363,   958, -1363,   201,   263, -1363,
     949,   971, -1363,   953, -1363,  6472, 11691, -1363,   445,   445,
    7357,   966, -1363, -1363, 11123, -1363, -1363, -1363,  7947, -1363,
     961,   866, 11691,  1035,   935,  1033, -1363, 11691,   969,  6472,
   -1363, -1363,  1065,   411, -1363, -1363, -1363, -1363,   979,   277,
   -1363, -1363, -1363,   956, -1363, -1363,   296,   445, -1363, -1363,
   -1363, -1363,  6472,   883, 11691,  1044, -1363,  6472, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363,  1045,  1012, -1363,   884,
     885, 11691, -1363, 11691, -1363,   868,  6472,   887,   305,  7947,
   -1363,  7947,  1047,  1012, -1363,   970, 11691, -1363,   888,   980,
   11691,  1012,   954, -1363,  1061, 11691,   905,  7947, -1363
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
      37,    30,    31,    32,    58,    33,    42,    38,    62,    63,
      64,    59,    60,    66,    67,    36,     0,    34,    35,    40,
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
     280,    20,     0,    21,     0,     4,     0,    25,    11,     0,
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
       0,     0,   274,     0,   271,   276,   230,   193,   155,   191,
       0,   194,     0,     0,    95,    89,    92,    91,     0,    87,
       0,   265,     0,     0,     0,     0,   167,     0,   306,   310,
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
     250,     0,   254,     0,   248,     0,     0,     0,   269,     0,
       0,     0,   229,   272,   275,     0,   156,     0,    94,     0,
      88,   262,   267,   266,     0,   533,     0,   309,   311,   316,
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
     255,   270,   278,   279,   273,   228,     0,     0,    90,   268,
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
     142,   146,     0,     0,     0,     0,   277,     0,   319,   484,
     495,   496,   483,   489,   490,   475,     0,     0,   147,     0,
       0,     0,   323,     0,   623,     0,     0,     0,     0,     0,
     149,     0,     0,     0,   148,     0,     0,   624,     0,     0,
       0,     0,     0,   625,     0,     0,     0,     0,   150
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1363, -1363,  -228,   927, -1363,   930,   936, -1363,   934,  -225,
    -518,  -544, -1363,   516,  -567, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,  -924,
   -1363, -1363, -1363, -1363,   109,   308, -1363, -1363, -1363,   768,
   -1363,    72,  -879, -1363,  -356,  -393, -1363, -1363,  -615, -1363,
    -724, -1363, -1363,   -30, -1363, -1363, -1363, -1363, -1363,   776,
   -1363, -1363,   788,   805, -1363, -1363, -1363,   257,   763, -1362,
    -491,    53, -1363,  -561,   736, -1363, -1363, -1363, -1363,   258,
   -1363, -1363,   912, -1363, -1363, -1363, -1363,    74,  -692,  -696,
   -1363, -1363, -1363,    45, -1363, -1363,  -144,    59,   -28, -1363,
   -1363, -1363,   -42, -1363, -1363,   195,   -34, -1363, -1363,   -29,
   -1213, -1363,   702,    46, -1363, -1363,    34, -1363, -1363, -1363,
      38, -1363, -1363,   624,   626, -1363,  -500, -1363, -1363,  -609,
     143,  -607,   139,   146, -1363, -1363, -1363, -1363, -1363,   910,
   -1363, -1363, -1363, -1363,  -755,  -298, -1091, -1363,  -105, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363,   -36, -1199, -1363, -1363,
     347,    11, -1363,  -634, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363,   580, -1363,  -945, -1363,    37, -1363,   464,  -751, -1363,
   -1363, -1363, -1363, -1363,  -377,  -370, -1143, -1060, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,   392,  -723,
    -797,   121,  -815, -1363,   -66,  -821, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363,   802,   811,  -334,   311,   159, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,
   -1363, -1363,    15, -1363, -1363,    10, -1363, -1363,  -980, -1363,
   -1363, -1363,   -26,   -38,  -192,   213, -1363, -1363, -1363, -1363,
   -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363, -1363,   -23,
   -1363, -1363, -1363,  -184,   208,   344, -1363, -1363, -1363, -1363,
   -1363,   151, -1363, -1363, -1266, -1363, -1363, -1363,  -675, -1363,
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
     287,   724,   778,   725,   710,  1143,  1144,  1145,   779,   585,
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
    1540,   563,  1024,   690,   563,   921,   645,   993,   982,   563,
     719,   723,   563,   788,   791,   794,   796,   921,  1429,  1105,
     900,  1111,   730,  1128,   879,  1163,  1335,   880,  1557,  1362,
     809,   570,   810,   811,   921,   812,   922,   814,   502,   757,
    1043,   922,   570,   914,  1220,   815,   816,   956,  1486,   711,
    1097,   947,   516,    77,  1043,  1254,  1098,   694,   382,   383,
     956,   384,   385,  1410,  1124,  1415,    88,  1236,   958,   881,
     626,   450,   456,  1099,   522,  1100,   695,   694,  1148,   570,
     916,   388,   645,  1191,  1101,   923,   527,  1238,   529,  1074,
    1132,   102,  1060,   617,   121,  1021,   695,  1085,  1022,   521,
     559,  1411,  1192,   457,  1193,  1541,   458,   618,  1086,  1061,
    1102,  1276,  1277,   571,  1363,  1487,  1558,   712,   560,   121,
     936,   986,   915,  1025,  1011,  1506,  1221,   957,   451,   983,
     984,  1510,   715,   994,  1278,  1230,   107,   718,  1255,  1256,
     972,  1257,  1189,  1190,   985,  1136,  1590,   930,   628,   924,
    1189,  1147,   924,   119,   976,  1526,   924,  1043,  1259,   917,
     901,   901,  1186,  1283,  1461,  1307,   564,   720,   566,  1129,
    1260,  1134,  1379,  1194,  1350,  1133,  1067,  1068,   536,   793,
     795,   396,   924,  1196,   781,   931,   783,   503,  1542,  1006,
     503,   145,  1196,  1164,  1008,   452,   453,  1229,  1534,   937,
     422,  1023,   758,   787,   790,  1634,  1511,  1024,  1024,  1407,
    1577,   924,  1189,   721,     7,  1223,   924,  1444,   696,   882,
     977,  1647,   634,  1416,  1417,   636,  1189,  1596,   663,  1653,
    1105,   664,   883,  1191,   884,  1103,  1069,   425,   921,   876,
     399,  1596,   987,   988,  1567,   885,   886,   887,  1069,   888,
     608,   889,  1192,  1020,  1193,   653,   503,   989,   968,  1001,
    1192,   503,  1193,   665,   970,   503,  1579,  1055,   609,  1043,
    1591,   503,  1055,   782,   663,  1062,   381,   664,   503,   786,
     789,  1445,   715,  1294,  1500,   502,   107,  1301,   502,   666,
     715,   503,  1063,  1346,  1043,   944,    77,   503,   386,   940,
    1058,   503,   943,   119,  1524,  1530,  1539,  1611,   503,    88,
     503,   503,   503,   503,   503,   389,  1187,   390,  1365,   503,
    1002,  1253,  1192,  1374,  1193,   426,   391,   503,  1025,  1025,
     921,  1316,   980,  1597,   102,   666,  1192,   969,  1193,   651,
    1626,   145,   573,   971,   429,  1303,  1056,  1623,   574,  1642,
     667,  1057,   715,   575,   654,   652,  1590,  1189,  1190,   660,
    1189,  1514,   687,   527,  1291,  1285,   715,     7,  1515,   676,
    1196,  1327,   576,   922,  1091,  1460,   678,  1336,  1516,  1059,
     430,  1135,  1188,  1525,  1531,   431,   503,   922,   647,   527,
    1092,   981,  1254,  1539,   866,   702,   667,  1286,   615,   708,
    1043,   648,   793,   795,   793,  1301,   726,   616,   527,   731,
     732,   733,   736,   608,  1287,   503,   691,   742,   693,  1627,
     699,  1302,  1326,   503,  1436,   749,   655,  1539,  1643,   717,
     432,   609,  1093,   727,  1024,   867,  1466,  1595,  1601,   737,
     868,   739,   740,  1024,   743,  1412,  1075,  1076,  1191,    77,
     746,  1079,  1413,   610,  1024,  1231,  1232,  1233,   656,  1189,
    1190,   611,    88,  1303,   835,   836,  1064,  1192,   577,  1193,
    1192,   578,  1193,  1595,  1065,  1255,  1256,  1502,  1257,  1601,
    1620,  1115,  1065,   434,   736,  1258,   579,   102,  1644,   612,
    1645,  1021,  1293,  1551,  1022,  1259,  1003,   715,  1007,  1138,
     715,   107,   613,   437,  1138,  1139,  1658,  1260,   547,  1249,
    1139,   580,   544,   773,  1235,   121,   756,   545,   119,   608,
    1117,   780,  1120,  1140,  1236,  1004,   851,   760,   852,  1295,
    1503,   503,   438,   121,  1237,   397,   614,   609,  1378,   608,
    1087,  1514,   922,   560,  1238,  1296,   777,   922,  1515,  1091,
    1191,  1088,   503,   503,   503,  1025,   145,   609,  1516,  1570,
     649,  1109,  1489,  1141,  1025,  1092,  1492,   398,   436,  1192,
    1110,  1193,  1171,   650,  1182,  1025,  1183,   921,   503,  1175,
     503,  1467,   538,   838,   539,  1360,   838,   503,  1236,   838,
     503,  1422,  1366,   439,  1138,   400,  1080,  1081,  1082,   715,
    1139,   568,  1083,   107,   867,  1501,   569,   635,   423,   868,
    1024,   424,   638,   427,   440,   446,   428,   441,   447,   834,
     119,   503,   629,   630,   837,   793,   669,   670,   671,   872,
     853,   854,   855,   856,   857,   858,   859,   860,   861,   862,
    1491,  1043,   541,  1043,   542,   631,  1202,   637,  1203,   442,
     904,   905,   906,   684,   403,   404,   405,   406,   145,   407,
     408,   685,   410,   411,   443,  1572,   627,  1573,   412,  1207,
     503,  1208,  1043,   672,   673,  1442,   928,   444,   934,  1560,
     681,   682,  1563,  1077,  1078,   527,  1106,  1107,   527,  1396,
    1397,   818,   819,  1043,   825,   826,  1588,   445,   503,   503,
     503,   503,   448,   827,   828,  1051,  1051,   449,   938,  1527,
    1528,   454,   455,   504,   505,   506,   517,  1609,   518,   973,
     519,   523,   524,   530,   531,   532,  1348,   534,   537,   540,
     543,  1025,   546,   547,   553,   503,   549,   965,   966,   550,
     552,   551,  1509,   554,   556,   589,   588,  1512,  1513,   503,
    1603,   607,   619,   620,   621,   639,  1580,   622,   631,   641,
     642,   640,   644,   645,   657,   386,   643,   998,  1012,   659,
     661,   674,   662,   677,   679,   680,   503,   683,   704,   709,
     705,   692,   715,   503,   744,   503,   381,   745,   424,   428,
     503,   441,   447,   458,   738,   751,  1048,  1048,  1048,  1048,
     752,   759,   762,   765,   503,   590,   785,   770,   386,  1395,
     797,   801,   761,   591,   592,   802,   593,   817,   387,   803,
     804,   830,   831,   832,   594,   389,   842,   390,   595,   847,
     596,   848,   850,  1048,   873,   597,   391,   503,   874,   503,
     392,  1568,  1569,   878,   829,   877,   903,  1084,   907,   908,
     909,   910,   598,   919,   935,   899,   911,   912,   939,   913,
     918,   941,   942,   946,   945,   950,   951,   952,   960,   953,
     954,   393,   394,  1009,  1114,   599,   600,   601,   602,   603,
     604,  1119,   961,  1119,   955,   962,   503,   964,  1048,   963,
     967,   978,   979,   990,   991,   995,   999,  1000,  1005,  1017,
    1013,  1607,  1048,  1053,  1070,   921,   868,   503,  1089,   992,
    1113,  1090,  1108,  1054,  1116,  1122,  1123,  1125,  1130,  1127,
     711,  1150,  1478,  1151,  1153,  1157,  1158,  1156,   397,  1152,
    1160,  1165,  1162,  1167,  1170,   742,  1171,   742,  1175,  1181,
    1179,  1137,  1185,  1201,  1180,  1215,  1218,  1224,  1227,  1228,
     665,  1243,  1222,  1245,  1269,     7,  1178,  1270,  1273,  1289,
     398,  1281,  1282,  1284,  1300,  1305,  1317,   901,  1313,  1309,
    1320,  1321,  1310,  1250,  1315,  1507,  1299,  1322,  1323,  1331,
    1312,  1324,  1333,  1337,  1244,  1339,  1340,  1341,   400,  1345,
    1349,   503,  1354,  1373,   503,  1371,   503,  1368,  1376,  1372,
    1380,  1381,  1382,  1387,  1236,  1048,  1383,  1384,  1402,  1406,
     503,  1425,  1409,  1385,  1246,  1405,  1438,  1426,  1432,   503,
     401,  1439,  1443,  1430,  1441,  1449,  1440,  1091,  1452,   503,
    1457,  1462,  1419,  1464,  1469,  1476,   503,  1477,  1480,  1481,
    1488,  1520,  1459,  1485,   503,  1522,   402,   403,   404,   405,
     406,  1532,   407,   408,   409,   410,   411,  1505,  1292,  1508,
    1536,   412,   413,   503,  1523,  1535,  1543,  1547,  1521,  1544,
    1549,  1553,  1562,  1565,  1566,  1574,  1575,  1578,  1582,  1587,
    1589,  1602,  1583,  1576,   503,  1604,  1608,   503,  1625,   708,
    1614,  1617,  1328,   503,  1329,  1615,  1619,   503,  1622,  1631,
    1633,  1065,  1646,  1651,  1648,   703,   555,  1612,  1343,  1319,
    1639,  1650,   557,  1635,  1654,  1072,  1655,  1048,   558,   561,
    1298,   875,   686,  1314,  1629,  1610,  1636,   726,  1585,  1641,
    1389,  1146,   688,  1149,   736,   658,  1325,   583,   716,  1474,
    1394,  1344,  1048,  1404,   689,  1351,  1361,  1657,  1234,  1401,
     503,  1398,   807,  1357,  1367,   808,   625,   974,  1356,   750,
     844,  1377,  1624,  1621,  1052,  1375,  1308,  1121,   697,  1297,
    1386,  1424,  1420,  1519,  1370,  1392,  1248,   698,  1518,  1423,
    1272,   503,   773,  1096,  1306,  1388,  1451,  1529,     0,  1421,
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
     115,     1,   817,   422,     1,    92,    25,   104,    92,     1,
     437,   438,     1,   564,   565,   566,   567,    92,  1273,   900,
      92,    92,   441,   143,    52,   138,   143,    55,    91,    97,
     590,   104,   592,   593,    92,   595,    94,   597,    71,     8,
     921,    94,   104,   104,   104,   605,   606,   104,   115,   115,
      35,   138,    85,   107,   935,   165,    41,    42,    33,    34,
     104,    36,    37,   212,   921,    94,   120,   103,   143,    97,
     149,    92,   118,    58,   107,    60,    61,    42,   935,   104,
     104,    56,    25,   100,    69,   143,   119,   123,   121,   872,
     143,   145,   144,   132,   173,   149,    61,   259,   152,   106,
      29,   250,   119,   149,   121,   220,   152,   146,   270,   161,
      95,   243,   244,   186,   182,   182,   179,   183,    47,   173,
     104,    92,   183,   817,   186,  1398,   186,   184,   149,   213,
     214,    50,   149,   230,   266,   110,   153,   156,   248,   249,
     184,   251,     9,    10,   228,   928,     5,   212,   313,   269,
       9,   934,   269,   170,   126,   180,   269,  1038,   268,   183,
     232,   232,   973,  1038,  1315,  1104,   186,   110,   186,   925,
     280,   927,  1375,   190,  1158,   927,   851,   852,   209,   783,
     784,   156,   269,  1188,   186,   250,   186,   318,   303,   186,
     321,   208,  1197,   949,   186,   216,   217,   186,  1453,   183,
     156,   255,   171,   781,   782,  1627,   125,  1022,  1023,  1249,
    1536,   269,     9,   156,    25,   999,   269,   132,   183,   247,
     192,  1643,   318,   252,   253,   321,     9,    24,    42,  1651,
    1111,    45,   260,   100,   262,   220,   863,   149,    92,   666,
     215,    24,   213,   214,  1503,   273,   274,   275,   875,   277,
     154,   279,   119,   813,   121,   386,   387,   228,   104,    43,
     119,   392,   121,    77,   104,   396,  1539,   104,   172,  1150,
     129,   402,   104,   561,    42,   144,    23,    45,   409,   564,
     565,   196,   149,  1067,   138,   318,   153,    94,   321,   103,
     149,   422,   161,  1150,  1175,   722,   107,   428,    45,   718,
     104,   432,   721,   170,   104,   104,  1457,  1580,   439,   120,
     441,   442,   443,   444,   445,    62,   126,    64,  1175,   450,
     104,    94,   119,   190,   121,   152,    73,   458,  1022,  1023,
      92,  1114,   127,   130,   145,   103,   119,   183,   121,   162,
     104,   208,    38,   183,   149,   152,   183,   130,    44,   104,
     164,   183,   149,    49,   387,   178,     5,     9,    10,   392,
       9,   265,   109,   396,  1058,   140,   149,    25,   272,   402,
    1375,  1123,    68,    94,    94,  1314,   409,  1133,   282,   183,
      65,   143,   192,   183,   183,    70,   517,    94,   178,   422,
     110,   186,   165,  1544,    92,   428,   164,   172,   196,   432,
    1281,   191,  1006,  1007,  1008,    94,   439,   205,   441,   442,
     443,   444,   445,   154,   189,   546,   423,   450,   425,   183,
     427,   110,   143,   554,  1281,   458,   165,  1578,   183,   436,
     115,   172,   152,   440,  1249,   133,   143,  1557,  1558,   446,
     138,   448,   449,  1258,   451,   264,   873,   874,   100,   107,
     457,   878,   271,   194,  1269,  1006,  1007,  1008,   197,     9,
      10,   114,   120,   152,   629,   630,   133,   119,   164,   121,
     119,   167,   121,  1593,   149,   248,   249,   152,   251,  1599,
     129,   908,   149,   152,   517,   258,   182,   145,  1639,   142,
    1641,   149,   133,  1477,   152,   268,   781,   149,   786,    51,
     149,   153,   155,    30,    51,    57,  1657,   280,   149,   149,
      57,   207,   220,   546,    93,   173,   523,   225,   170,   154,
     914,   554,   916,    75,   103,    29,   657,   534,   659,   133,
     205,   662,    59,   173,   113,   165,   189,   172,   190,   154,
     259,   265,    94,    47,   123,   149,   553,    94,   272,    94,
     100,   270,   683,   684,   685,  1249,   208,   172,   282,   194,
     178,   295,  1373,   115,  1258,   110,  1377,   197,   152,   119,
     304,   121,    97,   191,   968,  1269,   970,    92,   709,    97,
     711,  1333,   220,   632,   222,   110,   635,   718,   103,   638,
     721,  1260,   110,   115,    51,   225,   273,   274,   275,   149,
      57,   133,   279,   153,   133,  1388,   138,   320,   149,   138,
    1425,   152,   325,   149,   149,   149,   152,   152,   152,   626,
     170,   752,   187,   188,   631,  1229,   216,   217,   218,   662,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
     190,  1522,   220,  1524,   222,   150,   227,   152,   229,   152,
     683,   684,   685,   283,   284,   285,   286,   287,   208,   289,
     290,   291,   292,   293,   152,  1522,  1024,  1524,   298,   227,
     801,   229,  1553,   296,   297,  1296,   709,   115,   711,  1490,
     296,   297,  1493,   124,   125,   718,   287,   288,   721,   124,
     125,   608,   609,  1574,   615,   616,  1553,   115,   829,   830,
     831,   832,   152,   617,   618,   831,   832,   152,   715,  1444,
    1445,   118,   118,   118,   118,   118,   115,  1574,   118,   752,
     118,   149,   118,   118,   118,   118,  1153,   149,   211,   152,
     220,  1425,   115,   149,   149,   866,   237,   744,   745,   237,
     152,   238,  1409,   115,     0,    90,   163,  1416,  1417,   880,
    1561,   245,    48,   195,    98,   141,  1539,    99,   150,   180,
     180,   152,   152,    25,    45,    45,   180,   774,   801,    45,
     148,   242,   115,   289,   294,   294,   907,   300,   280,   115,
     280,   183,   149,   914,   149,   916,    23,   149,   152,   152,
     921,   152,   152,   152,   183,   183,   829,   830,   831,   832,
      31,    16,    25,   183,   935,   128,     3,   226,    45,  1236,
     138,   115,   209,   136,   137,   164,   139,    69,    55,   166,
     166,    92,    92,    92,   147,    62,   145,    64,   151,   104,
     153,   104,    25,   866,   156,   158,    73,   968,   156,   970,
      77,  1510,  1511,   128,   226,   123,   295,   880,   115,   128,
     180,   180,   175,   104,    92,   242,   183,   183,   183,   180,
     180,    94,    42,   104,    94,   180,   183,   183,   180,   183,
     183,   108,   109,   110,   907,   198,   199,   200,   201,   202,
     203,   914,   183,   916,   138,   183,  1017,   180,   921,   149,
     180,   180,   180,    92,   232,   138,   183,   180,    29,   115,
     166,  1570,   935,   180,   128,    92,   138,  1038,    25,   220,
     295,   282,   222,   181,   149,   115,   123,   115,   143,   115,
     115,    92,  1349,   180,   128,   128,    94,   156,   165,   193,
     115,   149,   138,   115,   143,   968,    97,   970,    97,   149,
     180,   250,    31,    25,   180,   115,   115,   241,   149,   115,
      77,   104,   180,   104,   254,    25,   963,   256,   263,   140,
     197,   152,   152,   152,    25,    25,   186,   232,   302,   222,
     183,   183,   222,   281,   222,  1402,   282,   140,   183,   143,
     283,   183,   123,   143,  1017,   143,   115,   115,   225,    75,
     104,  1122,   138,   128,  1125,   183,  1127,   180,     7,   183,
     186,   228,   228,   182,   103,  1038,   228,   228,   103,   183,
    1141,   143,   246,   232,  1021,   180,   183,   278,    76,  1150,
     257,   183,    25,   282,   180,    25,   183,    94,   267,  1160,
     166,   180,   246,   143,   143,   122,  1167,    94,   180,   182,
     180,   149,   253,   182,  1175,    92,   283,   284,   285,   286,
     287,    25,   289,   290,   291,   292,   293,   180,  1065,   180,
     104,   298,   299,  1194,   183,   183,   283,   143,   276,   166,
      51,    92,   192,   138,   115,    92,    25,   104,   115,   115,
     182,   192,   220,   261,  1215,   192,   180,  1218,   192,  1122,
     115,   182,  1125,  1224,  1127,   220,    91,  1228,   179,   115,
     115,   149,   115,   183,   194,   429,   239,   301,  1141,  1116,
     302,   283,   242,   289,   220,   867,   115,  1150,   242,   245,
    1071,   665,   414,  1111,   301,  1578,   301,  1160,  1544,   302,
    1220,   933,   416,   936,  1167,   390,  1122,   285,   435,  1343,
    1228,  1142,  1175,  1245,   416,  1160,  1172,   302,  1013,  1243,
    1281,  1240,   588,  1167,  1176,   589,   306,   753,  1165,   517,
     640,  1194,  1599,  1593,   832,  1188,  1105,   916,   426,  1070,
    1215,  1269,  1258,  1425,  1181,  1225,  1023,   426,  1422,  1262,
    1032,  1312,  1215,   899,  1093,  1218,  1304,  1447,    -1,  1259,
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
     414,   115,   183,   386,   387,   149,   388,   391,   156,   611,
     110,   156,   350,   611,   411,   413,   613,   391,    25,   183,
     612,   613,   613,   613,   432,   433,   613,   391,   183,   391,
     391,   535,   613,   391,   149,   149,   391,   183,   189,   613,
     432,   183,    31,   496,   497,   498,   391,     8,   171,    16,
     391,   209,    25,   394,   394,   183,   394,   394,   394,   394,
     226,   551,   552,   613,   371,   394,   394,   391,   412,   418,
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
      75,   115,   408,   415,   416,   417,   399,   519,   520,   387,
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
     115,   115,   394,   613,   417,    75,   520,   394,   611,   104,
     349,   413,   394,   394,   138,   180,   391,   433,   394,   394,
     110,   436,    97,   182,   115,   520,   110,   440,   180,   180,
     391,   183,   183,   128,   190,   495,     7,   613,   190,   506,
     186,   228,   228,   228,   228,   232,   552,   182,   613,   373,
     477,   556,   555,   394,   418,   611,   124,   125,   429,   430,
     430,   426,   103,   423,   422,   180,   183,   558,   572,   246,
     212,   250,   264,   271,   609,    94,   252,   253,   607,   246,
     562,   609,   449,   579,   563,   143,   278,   567,   568,   607,
     282,   578,    76,   577,   183,   189,   520,   523,   183,   183,
     183,   180,   393,    25,   132,   196,   600,   601,   602,    25,
     599,   600,   267,   595,   592,   593,   594,   166,   613,   253,
     362,   466,   180,   394,   143,   394,   143,   408,   394,   143,
     394,   394,   613,   613,   416,   394,   122,    94,   611,   394,
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
     330,   330,   330,   330,   331,   331,   331,   331,   331,   331,
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
     410,   411,   411,   412,   412,   413,   413,   413,   413,   414,
     414,   415,   415,   415,   416,   416,   416,   417,   417,   417,
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
       3,     1,     4,     1,     4,     3,     4,     4,     5,     4,
       5,     1,     2,     3,     1,     2,     1,     6,     3,     3,
       1,     2,     3,     1,     3,     2,     3,     2,     3,     4,
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
  "LetClause", "VarGetsDeclList", "EvalVarDeclList", "VarGetsDecl",
  "WindowVarDecl", "WindowVars", "WindowVars3", "WindowVars2",
  "EvalVarDecl", "WhereClause", "GroupByClause", "GroupSpecList",
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
     357,    -1,   360,    -1,   352,    -1,   332,    -1,   342,    -1,
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
     212,    -1,   250,    -1,    54,   250,    -1,   398,   415,    75,
     394,    -1,   398,    75,   394,    -1,    44,   397,   414,   399,
     399,    -1,    44,   397,   414,   399,    -1,    38,   115,   613,
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
     115,   613,    -1,    49,   115,   411,    -1,   413,    -1,   411,
     104,   115,   413,    -1,   418,    -1,   412,   104,   115,   418,
      -1,   613,   138,   394,    -1,   613,   519,   138,   394,    -1,
     613,   409,   138,   394,    -1,   613,   519,   409,   138,   394,
      -1,   115,   613,   143,   394,    -1,   115,   613,   519,   143,
     394,    -1,   416,    -1,   115,   613,    -1,   115,   613,   416,
      -1,   408,    -1,   408,   417,    -1,   417,    -1,    57,   115,
     613,    51,   115,   613,    -1,    51,   115,   613,    -1,    57,
     115,   613,    -1,   613,    -1,   207,   394,    -1,   167,   166,
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
     993,   997,   999,  1004,  1006,  1011,  1015,  1020,  1025,  1031,
    1036,  1042,  1044,  1047,  1051,  1053,  1056,  1058,  1065,  1069,
    1073,  1075,  1078,  1082,  1084,  1088,  1091,  1095,  1098,  1102,
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
    1238,  1239,  1240,  1241,  1246,  1247,  1248,  1249,  1250,  1251,
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
    2694,  2702,  2708,  2717,  2723,  2735,  2743,  2753,  2761,  2773,
    2779,  2790,  2792,  2796,  2804,  2808,  2813,  2817,  2821,  2825,
    2833,  2847,  2855,  2862,  2868,  2879,  2883,  2892,  2900,  2906,
    2916,  2922,  2932,  2936,  2946,  2952,  2958,  2964,  2973,  2982,
    2991,  3004,  3008,  3016,  3022,  3032,  3040,  3049,  3062,  3069,
    3081,  3085,  3097,  3104,  3110,  3119,  3126,  3132,  3144,  3151,
    3164,  3170,  3182,  3188,  3200,  3209,  3213,  3222,  3226,  3234,
    3238,  3248,  3255,  3264,  3274,  3273,  3287,  3296,  3305,  3318,
    3322,  3335,  3338,  3345,  3349,  3358,  3362,  3366,  3375,  3379,
    3385,  3391,  3397,  3408,  3412,  3416,  3424,  3428,  3434,  3444,
    3448,  3458,  3462,  3472,  3476,  3486,  3490,  3500,  3504,  3512,
    3516,  3520,  3524,  3534,  3538,  3542,  3550,  3554,  3558,  3562,
    3566,  3570,  3578,  3582,  3586,  3594,  3598,  3602,  3606,  3617,
    3623,  3633,  3639,  3649,  3653,  3691,  3695,  3701,  3707,  3718,
    3726,  3737,  3743,  3753,  3757,  3765,  3771,  3779,  3785,  3797,
    3803,  3813,  3817,  3821,  3825,  3829,  3835,  3841,  3864,  3868,
    3876,  3880,  3891,  3895,  3899,  3905,  3909,  3923,  3927,  3935,
    3939,  3949,  3953,  3957,  3966,  3970,  3974,  3978,  3986,  3992,
    4002,  4010,  4014,  4018,  4022,  4026,  4030,  4034,  4038,  4042,
    4050,  4054,  4062,  4069,  4076,  4087,  4095,  4099,  4107,  4115,
    4123,  4177,  4181,  4194,  4200,  4210,  4214,  4222,  4226,  4230,
    4238,  4248,  4258,  4268,  4278,  4288,  4303,  4309,  4320,  4326,
    4337,  4348,  4350,  4354,  4359,  4369,  4372,  4379,  4385,  4391,
    4399,  4412,  4415,  4422,  4428,  4434,  4441,  4452,  4456,  4466,
    4470,  4480,  4484,  4488,  4493,  4502,  4508,  4514,  4520,  4530,
    4534,  4546,  4550,  4562,  4574,  4578,  4582,  4586,  4590,  4594,
    4602,  4610,  4614,  4618,  4622,  4639,  4643,  4647,  4651,  4659,
    4667,  4675,  4679,  4683,  4687,  4695,  4701,  4711,  4719,  4723,
    4727,  4762,  4768,  4774,  4784,  4788,  4792,  4796,  4800,  4807,
    4813,  4823,  4831,  4835,  4839,  4843,  4847,  4851,  4855,  4859,
    4863,  4871,  4879,  4883,  4887,  4897,  4905,  4913,  4917,  4921,
    4929,  4933,  4939,  4945,  4949,  4959,  4967,  4971,  4977,  4986,
    4995,  5001,  5007,  5017,  5034,  5041,  5056,  5092,  5096,  5105,
    5114,  5124,  5128,  5137,  5146,  5150,  5161,  5178,  5184,  5190,
    5200,  5204,  5210,  5216,  5220,  5226,  5230,  5236,  5242,  5249,
    5259,  5264,  5272,  5278,  5288,  5310,  5319,  5325,  5338,  5352,
    5359,  5365,  5375,  5380,  5385,  5395,  5408,  5414,  5431,  5435,
    5450,  5459,  5462,  5469,  5474,  5482,  5486,  5493,  5497,  5504,
    5508,  5515,  5519,  5528,  5541,  5544,  5552,  5555,  5563,  5571,
    5579,  5583,  5591,  5594,  5602,  5614,  5617,  5625,  5637,  5643,
    5653,  5656,  5664,  5668,  5672,  5680,  5683,  5691,  5694,  5702,
    5706,  5710,  5714,  5718,  5726,  5734,  5746,  5758,  5762,  5766,
    5774,  5780,  5790,  5794,  5798,  5802,  5806,  5810,  5814,  5818,
    5826,  5830,  5834,  5838,  5846,  5852,  5862,  5872,  5876,  5884,
    5894,  5905,  5912,  5916,  5924,  5927,  5934,  5939,  5948,  5958,
    5961,  5969,  5972,  5980,  5989,  5996,  6006,  6010,  6017,  6023,
    6033,  6036,  6043,  6048,  6060,  6068,  6080,  6088,  6092,  6100,
    6104,  6108,  6116,  6124,  6128,  6132,  6136,  6144,  6152,  6164,
    6168,  6176,  6189,  6193,  6194,  6207,  6208,  6209,  6210,  6211,
    6212,  6213,  6214,  6215,  6216,  6217,  6218,  6219,  6220,  6221,
    6222,  6226,  6227,  6228,  6229,  6230,  6231,  6232,  6233,  6234,
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
    6355,  6356,  6357,  6358,  6359,  6360,  6361,  6362,  6363,  6364,
    6365,  6366,  6367,  6368,  6369,  6370,  6371,  6372,  6373,  6374,
    6375,  6376,  6377,  6378,  6379,  6380,  6381,  6382,  6383,  6384,
    6385,  6386,  6387,  6388,  6389,  6390,  6391,  6392,  6393,  6394,
    6395,  6396,  6397,  6398,  6399,  6400,  6401,  6402,  6403,  6404,
    6405,  6406,  6407,  6408,  6409,  6410,  6411,  6412,  6413,  6414,
    6415,  6416,  6417,  6418,  6419,  6420,  6421,  6422,  6423,  6424,
    6425
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


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // zorba

/* Line 1054 of lalr1.cc  */
#line 15846 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"


/* Line 1056 of lalr1.cc  */
#line 6429 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"


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

