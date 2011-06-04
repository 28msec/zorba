
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
#include "stdafx.h"

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
#line 873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 317 of lalr1.cc  */
#line 973 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"

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
                                       static_cast<zorba::QName*>(qname)->get_qname(),
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
                                       static_cast<zorba::QName*>(qname)->get_qname(),
                                       true));
    return false;
  }
  return true;
}



/* Line 317 of lalr1.cc  */
#line 152 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"

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
#line 221 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
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
#line 871 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 328 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 121: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 870 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 337 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 146: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 869 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 346 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 325: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 355 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 326: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 364 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 373 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 382 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 391 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 400 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 409 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 418 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 427 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 436 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 445 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 454 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 463 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 472 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 481 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 490 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 499 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 508 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 517 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 526 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 535 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 544 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 553 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 562 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 571 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 580 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 589 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 598 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 607 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 616 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 625 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 634 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 643 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 652 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "AnnotationList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 661 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "Annotation" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 670 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "AnnotationLiteralList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 679 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 688 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 697 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "FunctionDeclSimple" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 706 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 715 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 724 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 733 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 742 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "DeclPropertyList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 751 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "DeclProperty" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 760 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 769 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "NodeModifier" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 778 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 787 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 796 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 805 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 814 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 823 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "StatementsAndOptionalExprTop" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 832 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "StatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 841 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "StatementsAndExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 850 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "Statements" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 859 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "Statement" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 868 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "BlockStatement" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 877 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 886 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "EnclosedStatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 895 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "VarDeclStatement" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 904 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "AssignStatement" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 913 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "ApplyStatement" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 922 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "ExitStatement" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 931 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "WhileStatement" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 940 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 949 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "FLWORStatement" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 958 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "ReturnStatement" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 967 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "IfStatement" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 976 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "TryStatement" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 985 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "CatchListStatement" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 994 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "CatchStatement" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1003 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1012 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1021 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "ExprSimple" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1030 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1039 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1048 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1057 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1066 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1075 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1084 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1093 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1102 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1111 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1120 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1129 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1138 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1147 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1156 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1165 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1174 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1183 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1192 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1201 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1210 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1219 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1228 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1237 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1246 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1255 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1264 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1273 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1282 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1291 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1300 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1309 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1318 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1327 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1336 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "SwitchExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1345 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "SwitchCaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1354 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "SwitchCaseClause" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1363 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "SwitchCaseOperandList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1372 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "SwitchStatement" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1381 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1390 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "TypeswitchStatement" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1399 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1408 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1417 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1426 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1435 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1444 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1453 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1462 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1471 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1480 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1489 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1498 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1507 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1516 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1525 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1534 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1543 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1552 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1561 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1570 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1579 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1588 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1597 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1606 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1615 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1624 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1633 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1642 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1651 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1660 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1669 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1678 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1687 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1696 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1705 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1714 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1723 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1732 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1741 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1750 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1759 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1768 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1777 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1786 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1795 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1804 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1813 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1822 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1831 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1840 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1849 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1858 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1867 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1876 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1885 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1894 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1903 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1912 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1921 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1930 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1939 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1948 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1957 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1966 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1975 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1984 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1993 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2002 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2011 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2020 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2029 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2038 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2047 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2056 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2065 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2074 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2083 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2092 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 533: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2101 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 534: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2110 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 535: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2119 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 536: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2128 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 537: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2137 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* "AtomicType" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2146 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 539: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2155 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 540: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2164 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 541: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2173 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2182 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 543: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2191 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 544: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2200 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 545: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2209 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 546: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2218 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 547: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2227 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 548: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2236 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 549: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2245 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 550: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2254 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 551: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2263 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 556: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2272 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 557: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2281 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 560: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2290 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 561: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2299 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 562: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2308 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 563: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2317 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 564: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2326 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 565: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2335 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 566: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2344 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 567: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2353 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 568: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2362 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 569: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2371 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 570: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2380 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 571: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2389 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 572: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2398 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 575: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2407 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 576: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2416 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 577: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2425 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 578: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2434 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 579: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2443 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 580: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2452 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 582: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2461 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 583: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2470 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 584: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2479 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 585: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2488 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 587: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2497 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 588: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2506 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 590: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2515 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 593: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2524 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 594: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2533 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 595: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2542 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 596: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2551 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 597: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2560 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 598: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2569 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 599: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2578 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 600: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2587 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 601: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2596 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 602: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2605 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 603: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2614 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 604: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2623 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 608: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2632 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 611: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2641 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 612: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2650 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 616: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2659 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 617: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2668 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 618: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2677 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 619: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2686 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 620: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2695 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 621: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2704 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 622: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2713 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 623: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2722 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 624: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2731 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 627: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2740 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 628: /* "FUNCTION_NAME" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2749 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 629: /* "EQNAME" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2758 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
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
#line 2843 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"

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
#line 1034 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 1043 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 1052 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 1058 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      MainModule* mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
      mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 1066 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 1072 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      LibraryModule* lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
      lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 1083 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8" );
    }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 1088 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
    }
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 1096 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 1103 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 1110 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
    }
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 1119 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
    }
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 1126 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 1134 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 1142 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (3)]).step();
      error((yylocation_stack_[(5) - (3)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 1150 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (1)]).step();
      error((yylocation_stack_[(5) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 1161 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
    }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 1166 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 1173 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 1180 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
    }
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 1192 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );

      dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
    }
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 1202 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
      sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = sdl;
    }
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 1209 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 1216 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      // error
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 1251 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::preserve_space);
    }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 1256 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::strip_space);
    }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 1264 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
    }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 1272 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 1280 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_preserve);
    }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 1285 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_strip);
    }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 1293 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 1298 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 1306 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_greatest);
    }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 1311 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_least);
    }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 1319 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::preserve_ns,
                                  StaticContextConsts::inherit_ns);
    }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 1326 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::preserve_ns,
                                  StaticContextConsts::no_inherit_ns);
    }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 1333 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::no_preserve_ns,
                                  StaticContextConsts::inherit_ns);
    }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 1340 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::no_preserve_ns,
                                  StaticContextConsts::no_inherit_ns);
    }
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 1355 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yyval.node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (2)]), "syntax error, \"import\" should be followed by either \"schema\" or \"module\".");
      YYERROR;
    }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 1365 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
    }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 1370 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                            NULL);
    }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 1378 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            NULL,
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 1386 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 1397 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      URILiteralList *ull = new URILiteralList( LOC((yyloc)));
      ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
      (yyval.node) = ull;
    }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 1404 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
        ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 1415 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 1420 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
    }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 1428 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 1435 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 1442 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 1451 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(8) - (4)].sval)),
                            SYMTAB((yysemantic_stack_[(8) - (6)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(8) - (8)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(8) - (2)].sval)));
    }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 1464 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
    }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 1472 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_element_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 1479 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_function_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 1489 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
      vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = vdl;
    }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 1496 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 1503 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 1526 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 1532 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<zorba::QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 1541 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.vstrpair) = new vector<string_pair_t>();
      (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
      delete (yysemantic_stack_[(1) - (1)].strpair);
    }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 1548 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
      delete (yysemantic_stack_[(2) - (2)].strpair);
      (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
    }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 1558 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
      delete sl;
    }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 1567 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 1568 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 1569 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 1570 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 1571 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 1572 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 1573 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 1574 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 1575 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 1576 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 1582 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OptionDecl(LOC((yyloc)), static_cast<zorba::QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)));
    }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 1590 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
    }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 1598 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 1606 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
      d->theType = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 1613 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 1621 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
      d->theIsExternal = false;
      (yyval.node) = d;
    }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 1628 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), NULL);
    }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 1633 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 1641 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 1649 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 1664 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 1679 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 1697 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<zorba::QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL, NULL);
    }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 1702 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<zorba::QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 1710 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<zorba::QName*>((yysemantic_stack_[(4) - (4)].expr)),
                              NULL,
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (1)].node)));
    }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 1718 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<zorba::QName*>((yysemantic_stack_[(5) - (4)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)),
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (1)].node)));
    }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 1729 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationListParsenode(LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
    }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 1734 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 1743 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new zorba::QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
    }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 1748 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new zorba::QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 1758 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationLiteralListParsenode(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 1763 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 1772 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 1778 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl* fdecl = static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));

      fdecl->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );

      fdecl->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 1791 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 1796 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 1804 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC((yyloc)),
                            static_cast<zorba::QName*>((yysemantic_stack_[(4) - (2)].expr)),
                            &* (yysemantic_stack_[(4) - (3)].fnsig)->theParams,
                            &* (yysemantic_stack_[(4) - (3)].fnsig)->theReturnType,
                            (yysemantic_stack_[(4) - (4)].expr),      // body
                            false,   // not explicitly updating
                            false);  // not external
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 1815 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC ((yyloc)),
                            static_cast<zorba::QName*>((yysemantic_stack_[(4) - (2)].expr)),
                            (yysemantic_stack_[(4) - (3)].fnsig)->theParams.getp(),
                            (yysemantic_stack_[(4) - (3)].fnsig)->theReturnType.getp(),
                            NULL,   // no body
                            false,   // not explicitly updating
                            true);  // external
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 1830 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC ((yyloc)),
                            static_cast<zorba::QName*>((yysemantic_stack_[(5) - (3)].expr)),
                            (yysemantic_stack_[(5) - (4)].fnsig)->theParams.getp(),
                            (yysemantic_stack_[(5) - (4)].fnsig)->theReturnType.getp(),
                            (yysemantic_stack_[(5) - (5)].expr),    // body
                            true,  // updating
                            false);// not external
      delete (yysemantic_stack_[(5) - (4)].fnsig);
    }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 1842 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC((yyloc)),
                            static_cast<zorba::QName*>((yysemantic_stack_[(5) - (3)].expr)),
                            (yysemantic_stack_[(5) - (4)].fnsig)->theParams.getp(),
                            (yysemantic_stack_[(5) - (4)].fnsig)->theReturnType.getp(),
                            NULL,  // no body
                            true,  // updating
                            true); // external
      delete (yysemantic_stack_[(5) - (4)].fnsig);
    }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 1857 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL);
    }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 1862 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 1867 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 1872 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 1880 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      ParamList *pl = new ParamList( LOC((yyloc)) );
      pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = pl;
    }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 1887 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
        pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 1898 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<zorba::QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 1903 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<zorba::QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 1913 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      DeclPropertyList *dpl = new DeclPropertyList( LOC((yyloc)) );
      dpl->addProperty(dynamic_cast<DeclProperty*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = dpl;
    }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 1919 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      DeclPropertyList *dpl = dynamic_cast<DeclPropertyList*>((yysemantic_stack_[(2) - (1)].node));
      dpl->addProperty( static_cast<DeclProperty*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 1929 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_const );
        }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 1933 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_append_only
            );
        }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 1939 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_queue );
        }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 1943 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_mutable );
        }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1947 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_ordered );
        }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 1951 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_unordered
            );
        }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 1957 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_value_equality
            );
        }
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 1963 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_value_range
            );
        }
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 1969 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_general_equality
            );
        }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 1975 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_general_range
            );
        }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 1981 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_unique );
        }
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 1985 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_non_unique
            );
        }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 1991 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_automatic
            );
        }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 1997 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_manual );
        }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 2004 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<zorba::QName*>((yysemantic_stack_[(3) - (3)].expr)),
                              NULL,
                              NULL,
                              NULL);
    }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 2012 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<zorba::QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              NULL,
                              static_cast<NodeModifier*>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 2020 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<zorba::QName*>((yysemantic_stack_[(5) - (3)].expr)),
                              NULL,
                              NULL,
                              static_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 2028 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<zorba::QName*>((yysemantic_stack_[(6) - (3)].expr)),
                              NULL,
                              static_cast<NodeModifier*>((yysemantic_stack_[(6) - (6)].node)),
                              static_cast<SequenceType*>((yysemantic_stack_[(6) - (5)].node)));
    }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 2036 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      if (!validate_collection_properties((yysemantic_stack_[(4) - (2)].node), (yyloc), (yysemantic_stack_[(4) - (4)].expr), driver)) {
        delete (yysemantic_stack_[(4) - (2)].node); delete (yysemantic_stack_[(4) - (4)].expr); // these need to be deleted explicitly, as bison does not free them
        YYERROR;
      }

      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<zorba::QName*>((yysemantic_stack_[(4) - (4)].expr)),
                               static_cast<DeclPropertyList*>((yysemantic_stack_[(4) - (2)].node)), 0, 0);
      delete (yysemantic_stack_[(4) - (2)].node);
    }
    break;

  case 157:

/* Line 678 of lalr1.cc  */
#line 2048 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      if (!validate_collection_properties((yysemantic_stack_[(5) - (2)].node), (yyloc), (yysemantic_stack_[(5) - (4)].expr), driver )) {
        delete (yysemantic_stack_[(5) - (2)].node); delete (yysemantic_stack_[(5) - (4)].expr);  delete (yysemantic_stack_[(5) - (5)].node); // these need to be deleted explicitly, as bison does not free them
        YYERROR;
      }

      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<zorba::QName*>((yysemantic_stack_[(5) - (4)].expr)),
                               static_cast<DeclPropertyList*>((yysemantic_stack_[(5) - (2)].node)),
                               static_cast<NodeModifier*>((yysemantic_stack_[(5) - (5)].node)),
                               NULL);
      delete (yysemantic_stack_[(5) - (2)].node);
    }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 2062 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      if (!validate_collection_properties((yysemantic_stack_[(6) - (2)].node), (yyloc), (yysemantic_stack_[(6) - (4)].expr), driver)) {
        delete (yysemantic_stack_[(6) - (2)].node); delete (yysemantic_stack_[(6) - (4)].expr); delete (yysemantic_stack_[(6) - (6)].node); // these need to be deleted explicitly, as bison does not free them
        YYERROR;
      }

      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<zorba::QName*>((yysemantic_stack_[(6) - (4)].expr)),
                               static_cast<DeclPropertyList*>((yysemantic_stack_[(6) - (2)].node)),
                               NULL,
                               static_cast<SequenceType*>((yysemantic_stack_[(6) - (6)].node)));
      delete (yysemantic_stack_[(6) - (2)].node);
    }
    break;

  case 159:

/* Line 678 of lalr1.cc  */
#line 2076 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      if (!validate_collection_properties((yysemantic_stack_[(7) - (2)].node), (yyloc), (yysemantic_stack_[(7) - (4)].expr), driver)) {
        delete (yysemantic_stack_[(7) - (2)].node); delete (yysemantic_stack_[(7) - (4)].expr); delete (yysemantic_stack_[(7) - (6)].node); delete (yysemantic_stack_[(7) - (7)].node); // these need to be deleted explicitly, as bison does not free them
        YYERROR;
      }

      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<zorba::QName*>((yysemantic_stack_[(7) - (4)].expr)),
                               static_cast<DeclPropertyList*>((yysemantic_stack_[(7) - (2)].node)),
                               static_cast<NodeModifier*>((yysemantic_stack_[(7) - (7)].node)),
                               static_cast<SequenceType*>((yysemantic_stack_[(7) - (6)].node)));
      delete (yysemantic_stack_[(7) - (2)].node);
    }
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 2093 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 2097 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 2106 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier(LOC((yyloc)), StaticContextConsts::read_only);
    }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 2110 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier(LOC((yyloc)), StaticContextConsts::mutable_node);
    }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 2117 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AST_IndexDecl(LOC((yyloc)),
                             static_cast<zorba::QName*>((yysemantic_stack_[(8) - (3)].expr)),
                             (yysemantic_stack_[(8) - (6)].expr),
                             dynamic_cast<IndexKeyList*>((yysemantic_stack_[(8) - (8)].node)),
                             NULL);
    }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 2125 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      if (!validate_index_properties((yysemantic_stack_[(9) - (2)].node), (yyloc), (yysemantic_stack_[(9) - (4)].expr), driver))
      {
        delete (yysemantic_stack_[(9) - (2)].node); delete (yysemantic_stack_[(9) - (4)].expr); delete (yysemantic_stack_[(9) - (7)].expr); delete (yysemantic_stack_[(9) - (9)].node); // these need to be deleted explicitly, as bison does not free them
        YYERROR;
      }

      (yyval.node) = new AST_IndexDecl(LOC((yyloc)),
                             static_cast<zorba::QName*>((yysemantic_stack_[(9) - (4)].expr)),
                             (yysemantic_stack_[(9) - (7)].expr),
                             dynamic_cast<IndexKeyList*>((yysemantic_stack_[(9) - (9)].node)),
                             dynamic_cast<DeclPropertyList*>((yysemantic_stack_[(9) - (2)].node)));
      delete (yysemantic_stack_[(9) - (2)].node);
    }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 2143 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 2149 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 2158 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 2163 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 2170 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 2177 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 2189 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollSimpleCheck(LOC((yyloc)),
                                 static_cast<zorba::QName*>((yysemantic_stack_[(11) - (4)].expr)),
                                 static_cast<zorba::QName*>((yysemantic_stack_[(11) - (7)].expr)),
                                 static_cast<zorba::QName*>((yysemantic_stack_[(11) - (9)].expr)),
                                 (yysemantic_stack_[(11) - (11)].expr));
    }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 2199 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollUniqueKeyCheck(LOC((yyloc)),
                                    static_cast<zorba::QName*>((yysemantic_stack_[(14) - (4)].expr)),
                                    static_cast<zorba::QName*>((yysemantic_stack_[(14) - (7)].expr)),
                                    static_cast<zorba::QName*>((yysemantic_stack_[(14) - (10)].expr)),
                                    (yysemantic_stack_[(14) - (14)].expr));
    }
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 2209 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollForeachNode(LOC((yyloc)),
                                 static_cast<zorba::QName*>((yysemantic_stack_[(13) - (4)].expr)),
                                 static_cast<zorba::QName*>((yysemantic_stack_[(13) - (7)].expr)),
                                 static_cast<zorba::QName*>((yysemantic_stack_[(13) - (11)].expr)),
                                 (yysemantic_stack_[(13) - (13)].expr));
    }
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 2220 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICForeignKey( LOC((yyloc)),
                            static_cast<zorba::QName*>((yysemantic_stack_[(22) - (4)].expr)),
                            static_cast<zorba::QName*>((yysemantic_stack_[(22) - (9)].expr)),
                            static_cast<zorba::QName*>((yysemantic_stack_[(22) - (12)].expr)),
                            (yysemantic_stack_[(22) - (14)].expr),
                            static_cast<zorba::QName*>((yysemantic_stack_[(22) - (17)].expr)),
                            static_cast<zorba::QName*>((yysemantic_stack_[(22) - (20)].expr)),
                            (yysemantic_stack_[(22) - (22)].expr));
    }
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 2236 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 177:

/* Line 678 of lalr1.cc  */
#line 2256 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 2261 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 2265 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  NULL;
    }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 2273 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 2278 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 182:

/* Line 678 of lalr1.cc  */
#line 2282 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  new BlockBody(LOC((yyloc)));
    }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 2290 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 2295 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 2307 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = new BlockBody(LOC((yyloc)));
      blk->add((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 2314 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 2343 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 2348 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 2356 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 202:

/* Line 678 of lalr1.cc  */
#line 2373 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 2381 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 2389 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = static_cast<VarDeclStmt*>((yysemantic_stack_[(3) - (1)].expr));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 2396 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)));
      vdecl->add((yysemantic_stack_[(2) - (2)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 2403 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 207:

/* Line 678 of lalr1.cc  */
#line 2413 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      VarDecl* vd = new VarDecl(LOC((yyloc)),
                                static_cast<zorba::QName*>((yysemantic_stack_[(2) - (2)].expr)),
                                NULL,  // no type
                                NULL,  // no init expr
                                NULL,  // no annotations
                                false, // not global
                                false);// not external
      vd->set_global(false);
      (yyval.node) = vd;
    }
    break;

  case 208:

/* Line 678 of lalr1.cc  */
#line 2425 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      VarDecl* vd = new VarDecl(LOC((yyloc)),
                                static_cast<zorba::QName*>((yysemantic_stack_[(3) - (2)].expr)),
                                dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)), // type
                                NULL,  // no init expr
                                NULL,  // no annotations
                                false, // not global
                                false);// not external

      vd->set_global(false);
      (yyval.node) = vd;
    }
    break;

  case 209:

/* Line 678 of lalr1.cc  */
#line 2438 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      VarDecl* vd = new VarDecl(LOC((yyloc)),
                                static_cast<zorba::QName*>((yysemantic_stack_[(4) - (2)].expr)),
                                NULL,  // no type
                                (yysemantic_stack_[(4) - (4)].expr),    // init expr
                                NULL,  // no annotations
                                false, // not global
                                false);// not external
      vd->set_global(false);
      (yyval.node) = vd;
    }
    break;

  case 210:

/* Line 678 of lalr1.cc  */
#line 2450 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      VarDecl* vd = new VarDecl(LOC((yyloc)),
                                static_cast<zorba::QName*>((yysemantic_stack_[(5) - (2)].expr)),
                                dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (3)].node)), // type
                                (yysemantic_stack_[(5) - (5)].expr),    // init expr
                                NULL,  // no annotations
                                false, // not global
                                false);// not external
      vd->set_global(false);
      (yyval.node) = vd;
    }
    break;

  case 211:

/* Line 678 of lalr1.cc  */
#line 2466 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<zorba::QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 212:

/* Line 678 of lalr1.cc  */
#line 2474 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ApplyExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr));
    }
    break;

  case 213:

/* Line 678 of lalr1.cc  */
#line 2482 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 214:

/* Line 678 of lalr1.cc  */
#line 2490 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 215:

/* Line 678 of lalr1.cc  */
#line 2505 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement(LOC((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 216:

/* Line 678 of lalr1.cc  */
#line 2510 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
    }
    break;

  case 217:

/* Line 678 of lalr1.cc  */
#line 2518 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 218:

/* Line 678 of lalr1.cc  */
#line 2532 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 219:

/* Line 678 of lalr1.cc  */
#line 2549 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 220:

/* Line 678 of lalr1.cc  */
#line 2574 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TryExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 2582 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* cle = new CatchListExpr( LOC((yyloc)) );
      cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.expr) = cle;
    }
    break;

  case 222:

/* Line 678 of lalr1.cc  */
#line 2589 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 2600 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 2606 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CatchExpr(LOC((yyloc)),*(yysemantic_stack_[(7) - (2)].name_test_list), static_cast<zorba::QName*>((yysemantic_stack_[(7) - (5)].expr)), NULL, NULL, (yysemantic_stack_[(7) - (7)].expr));
       delete (yysemantic_stack_[(7) - (2)].name_test_list);
    }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 2612 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)),
                          *(yysemantic_stack_[(10) - (2)].name_test_list),
                          static_cast<zorba::QName*>((yysemantic_stack_[(10) - (5)].expr)),
                          static_cast<zorba::QName*>((yysemantic_stack_[(10) - (8)].expr)),
                          NULL,
                          (yysemantic_stack_[(10) - (10)].expr));
       delete (yysemantic_stack_[(10) - (2)].name_test_list);
    }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 2623 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          *(yysemantic_stack_[(13) - (2)].name_test_list),
                          static_cast<zorba::QName*>((yysemantic_stack_[(13) - (5)].expr)),
                          static_cast<zorba::QName*>((yysemantic_stack_[(13) - (8)].expr)),
                          static_cast<zorba::QName*>((yysemantic_stack_[(13) - (11)].expr)),
                          (yysemantic_stack_[(13) - (13)].expr));
       delete (yysemantic_stack_[(13) - (2)].name_test_list);
    }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 2638 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 2643 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 242:

/* Line 678 of lalr1.cc  */
#line 2681 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 243:

/* Line 678 of lalr1.cc  */
#line 2695 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
    }
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 2703 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 245:

/* Line 678 of lalr1.cc  */
#line 2708 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 2716 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 2721 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 2726 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
    (yyval.strval) = parser::the_only_end;
  }
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 2734 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            dynamic_cast<WindowVars*>((yysemantic_stack_[(4) - (2)].node)),
                            (yysemantic_stack_[(4) - (4)].expr),
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 2743 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            NULL,
                            (yysemantic_stack_[(3) - (3)].expr),
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 2755 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 252:

/* Line 678 of lalr1.cc  */
#line 2765 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling ?
                              WindowClause::tumbling_window :
                              WindowClause::sliding_window),
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 2778 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<zorba::QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 2802 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 2809 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 2819 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 2827 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      VarInDeclList *vdl = new VarInDeclList( LOC((yyloc)) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = vdl;
    }
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 2834 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      if ( VarInDeclList *vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 2844 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<zorba::QName*>((yysemantic_stack_[(3) - (1)].expr)),
                         NULL,
                         NULL,
                         NULL,
                         (yysemantic_stack_[(3) - (3)].expr),
                         false);
    }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 2854 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<zorba::QName*>((yysemantic_stack_[(5) - (1)].expr)),
                         NULL,
                         NULL,
                         NULL,
                         (yysemantic_stack_[(5) - (5)].expr),
                         true);
    }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 2864 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<zorba::QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                         NULL,
                         NULL,
                         (yysemantic_stack_[(4) - (4)].expr),
                         false);
    }
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 2874 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<zorba::QName*>((yysemantic_stack_[(6) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (2)].node)),
                         NULL,
                         NULL,
                         (yysemantic_stack_[(6) - (6)].expr),
                         true);
    }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 2884 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<zorba::QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         NULL,
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(4) - (2)].node)),
                         NULL,
                         (yysemantic_stack_[(4) - (4)].expr),
                         false);
    }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 2894 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<zorba::QName*>((yysemantic_stack_[(6) - (1)].expr)),
                         NULL,
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(6) - (4)].node)),
                         NULL,
                         (yysemantic_stack_[(6) - (6)].expr),
                         true);
    }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 2904 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), 
                         static_cast<zorba::QName*>((yysemantic_stack_[(5) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (3)].node)),
                         NULL,
                         (yysemantic_stack_[(5) - (5)].expr),
                         false);
    }
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 2914 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<zorba::QName*>((yysemantic_stack_[(7) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(7) - (2)].node)),
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(7) - (5)].node)),
                         NULL,
                         (yysemantic_stack_[(7) - (7)].expr),
                         true);
    }
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 2925 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<zorba::QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         NULL,NULL,
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
                         (yysemantic_stack_[(4) - (4)].expr),
                         false);
    }
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 2934 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<zorba::QName*>((yysemantic_stack_[(5) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
                         NULL,
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
                         (yysemantic_stack_[(5) - (5)].expr),
                         false);
    }
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 2944 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC ((yyloc)),
                         static_cast<zorba::QName*>((yysemantic_stack_[(5) - (1)].expr)),
                         NULL,
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (2)].node)),
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
                         (yysemantic_stack_[(5) - (5)].expr),
                         false);
    }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 2954 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC ((yyloc)),
                         static_cast<zorba::QName*>((yysemantic_stack_[(6) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (2)].node)),
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(6) - (3)].node)),
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
                         (yysemantic_stack_[(6) - (6)].expr),
                         false);
    }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 2970 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<zorba::QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 2979 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<zorba::QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 2988 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 2996 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 3002 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 3014 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<zorba::QName*>((yysemantic_stack_[(4) - (2)].expr)),
                           NULL,
                           NULL,
                           (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 3022 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<zorba::QName*>((yysemantic_stack_[(5) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                           NULL,
                           (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 3032 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node))->get_var_name(),
                           NULL,
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node)),
                           (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 3040 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<zorba::QName*>((yysemantic_stack_[(6) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (3)].node)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
                           (yysemantic_stack_[(6) - (6)].expr));
    }
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 3052 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<zorba::QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 3058 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<zorba::QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 3071 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<zorba::QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 3075 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<zorba::QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 3083 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 3087 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 3096 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<zorba::QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<zorba::QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 3100 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<zorba::QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 3104 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<zorba::QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 3114 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 3122 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 3129 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = new GroupSpecList( LOC((yyloc)) );
            gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 3135 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
            if ( gsl )
                gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 3146 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<zorba::QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 3150 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<zorba::QName*>((yysemantic_stack_[(3) - (2)].expr)),
                         dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 3159 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 3167 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 3173 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 3183 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 3189 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 3199 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 3203 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 3213 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 3219 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 3225 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 3231 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
                NULL
            );
        }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 3240 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                NULL,
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 3249 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                NULL,
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 3258 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 3271 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 3275 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 3283 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 3289 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 3299 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 3307 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_some,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 3316 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_every,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 3329 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 3336 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 3348 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<zorba::QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 3352 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<zorba::QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 3364 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 3371 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 3377 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 3386 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 3393 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 3399 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 3410 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 3417 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 3423 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 3432 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 3441 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 3448 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<zorba::QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 3459 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 3466 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<zorba::QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 3478 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 3484 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 3496 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 3502 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<zorba::QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 3513 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 3519 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 3530 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 3536 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<zorba::QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 3547 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 3556 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 3560 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 3569 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 3573 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 3581 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 3585 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 359:

/* Line 678 of lalr1.cc  */
#line 3595 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 3602 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_eq ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 3611 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ne ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 3620 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 3625 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_lt ),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr)
            );
        }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 3634 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_le ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 3643 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_gt ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 3652 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ge ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 3665 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 3669 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FTContainsExpr(
                LOC((yyloc)),
                (yysemantic_stack_[(5) - (1)].expr),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(5) - (4)].node)),
                dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 3681 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 3685 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 3692 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 3696 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 3705 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 3709 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 3713 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 3722 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 3726 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 3732 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 3738 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 3744 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 3755 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 3759 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 3763 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 3771 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 3775 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 3781 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 3791 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 3795 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 3805 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 3809 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 3819 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 3823 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 3833 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 3837 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 3847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 3851 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 3859 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 3863 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 3867 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 3871 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 3881 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 3885 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 3889 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 3897 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 3901 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 3905 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 3909 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 3913 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 3917 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 3925 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 3929 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 3933 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 3941 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 3945 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 3949 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 3953 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 3964 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 3970 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 3980 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 3986 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 3996 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<zorba::QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 4000 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new zorba::QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 4004 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new zorba::QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 4042 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new PathExpr(LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
    }
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 4046 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, NULL, (yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slash,
                        rpe);
    }
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 4056 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, NULL, (yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slashslash,
                        rpe);
    }
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 4066 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = (!rpe ?
            (yysemantic_stack_[(1) - (1)].expr) :
            new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 4079 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 4088 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 430:

/* Line 678 of lalr1.cc  */
#line 4098 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 4102 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 4111 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 4115 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 4124 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 4130 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 4138 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 4144 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 4156 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 4162 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 4172 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 4176 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 4180 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 4184 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 4188 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 4194 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 4200 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 4208 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 4212 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 4220 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 4224 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 4235 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 4239 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 4243 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 4249 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 4253 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 4267 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 4271 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 4279 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<zorba::QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 4283 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 4293 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all);
    }
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 4297 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem);
    }
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 4301 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix);
    }
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 4310 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 4314 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 4318 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
     }
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 4322 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
     }
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 4330 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 4336 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 4346 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 4354 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 471:

/* Line 678 of lalr1.cc  */
#line 4358 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 472:

/* Line 678 of lalr1.cc  */
#line 4362 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 473:

/* Line 678 of lalr1.cc  */
#line 4366 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 474:

/* Line 678 of lalr1.cc  */
#line 4370 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 4374 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 4378 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 4382 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 4386 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 4396 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 4404 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 4408 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 482:

/* Line 678 of lalr1.cc  */
#line 4416 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 4423 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 4430 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 4441 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<zorba::QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 4449 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 4453 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 4461 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 4469 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 4477 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 4531 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<zorba::QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
        }
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 4535 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall(
                LOC((yyloc)),
                static_cast<zorba::QName*>((yysemantic_stack_[(4) - (1)].expr)),
                dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 4548 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            ArgList *al = new ArgList( LOC((yyloc)) );
            al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
            (yyval.node) = al;
        }
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 4554 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
                al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 4564 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 4568 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 4576 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 4580 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 4584 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 4592 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemConstructor(
                LOC((yyloc)),
                static_cast<zorba::QName*>((yysemantic_stack_[(4) - (2)].expr)),
                NULL,
                NULL,
                NULL
            );
        }
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 4602 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemConstructor(
                LOC((yyloc)),
                static_cast<zorba::QName*>((yysemantic_stack_[(5) - (2)].expr)),
                NULL,
                dynamic_cast<DirAttributeList*>((yysemantic_stack_[(5) - (3)].node)),
                NULL
            );
        }
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 4612 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemConstructor(
                LOC((yyloc)),
                static_cast<zorba::QName*>((yysemantic_stack_[(8) - (2)].expr)),
                static_cast<zorba::QName*>((yysemantic_stack_[(8) - (6)].expr)),
                NULL,
                NULL
            );
        }
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 4622 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemConstructor(
                LOC((yyloc)),
                static_cast<zorba::QName*>((yysemantic_stack_[(9) - (2)].expr)),
                static_cast<zorba::QName*>((yysemantic_stack_[(9) - (7)].expr)),
                NULL,
                dynamic_cast<DirElemContentList*>((yysemantic_stack_[(9) - (5)].node))
            );
        }
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 4632 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemConstructor(
                LOC((yyloc)),
                static_cast<zorba::QName*>((yysemantic_stack_[(9) - (2)].expr)),
                static_cast<zorba::QName*>((yysemantic_stack_[(9) - (7)].expr)),
                dynamic_cast<DirAttributeList*>((yysemantic_stack_[(9) - (3)].node)),
                NULL
            );
        }
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 4642 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemConstructor(
                LOC((yyloc)),
                static_cast<zorba::QName*>((yysemantic_stack_[(10) - (2)].expr)),
                static_cast<zorba::QName*>((yysemantic_stack_[(10) - (8)].expr)),
                dynamic_cast<DirAttributeList*>((yysemantic_stack_[(10) - (3)].node)),
                dynamic_cast<DirElemContentList*>((yysemantic_stack_[(10) - (6)].node))
            );
        }
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 4657 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
            decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = decl;
        }
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 4663 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( decl )
                decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 4674 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
            dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = dal;
        }
    break;

  case 509:

/* Line 678 of lalr1.cc  */
#line 4680 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
            if ( dal )
                dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 510:

/* Line 678 of lalr1.cc  */
#line 4691 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttr(
                LOC((yyloc)),
                static_cast<zorba::QName*>((yysemantic_stack_[(6) - (2)].expr)),
                dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node))
            );
        }
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 4708 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 4713 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 4722 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
        }
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 4726 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 4733 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = qacl;
        }
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 4739 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = qacl;
        }
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 4745 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 4753 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 521:

/* Line 678 of lalr1.cc  */
#line 4765 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
        }
    break;

  case 522:

/* Line 678 of lalr1.cc  */
#line 4769 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 4776 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = aacl;
        }
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 4782 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = aacl;
        }
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 4788 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if (aacl)
                aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 526:

/* Line 678 of lalr1.cc  */
#line 4795 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( aacl )
                aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 4806 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 4810 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 4820 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 4824 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 4834 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 4838 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 4842 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
        }
    break;

  case 534:

/* Line 678 of lalr1.cc  */
#line 4847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
        }
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 4856 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval))
            );
        }
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 4862 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_lbrace
            );
        }
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 4868 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_rbrace
            );
        }
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 4874 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
        }
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 4882 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 4887 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 4895 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 542:

/* Line 678 of lalr1.cc  */
#line 4900 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 543:

/* Line 678 of lalr1.cc  */
#line 4908 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 544:

/* Line 678 of lalr1.cc  */
#line 4916 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 4921 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 4926 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 4931 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 4936 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 549:

/* Line 678 of lalr1.cc  */
#line 4941 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 550:

/* Line 678 of lalr1.cc  */
#line 4950 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 4958 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new zorba::QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
        }
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 4962 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 4979 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new zorba::QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 4983 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 555:

/* Line 678 of lalr1.cc  */
#line 4991 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 556:

/* Line 678 of lalr1.cc  */
#line 4999 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 557:

/* Line 678 of lalr1.cc  */
#line 5007 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 558:

/* Line 678 of lalr1.cc  */
#line 5011 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 559:

/* Line 678 of lalr1.cc  */
#line 5019 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)), false
            );
        }
    break;

  case 560:

/* Line 678 of lalr1.cc  */
#line 5025 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)), true
            );
        }
    break;

  case 561:

/* Line 678 of lalr1.cc  */
#line 5035 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 562:

/* Line 678 of lalr1.cc  */
#line 5043 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 563:

/* Line 678 of lalr1.cc  */
#line 5047 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 564:

/* Line 678 of lalr1.cc  */
#line 5051 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 565:

/* Line 678 of lalr1.cc  */
#line 5086 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 566:

/* Line 678 of lalr1.cc  */
#line 5092 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 567:

/* Line 678 of lalr1.cc  */
#line 5098 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 568:

/* Line 678 of lalr1.cc  */
#line 5108 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 569:

/* Line 678 of lalr1.cc  */
#line 5112 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 570:

/* Line 678 of lalr1.cc  */
#line 5116 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)),true );
        }
    break;

  case 571:

/* Line 678 of lalr1.cc  */
#line 5120 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 572:

/* Line 678 of lalr1.cc  */
#line 5124 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 573:

/* Line 678 of lalr1.cc  */
#line 5131 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 574:

/* Line 678 of lalr1.cc  */
#line 5137 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 575:

/* Line 678 of lalr1.cc  */
#line 5147 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AtomicType( LOC((yyloc)), static_cast<zorba::QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 576:

/* Line 678 of lalr1.cc  */
#line 5155 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 577:

/* Line 678 of lalr1.cc  */
#line 5159 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 578:

/* Line 678 of lalr1.cc  */
#line 5163 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 579:

/* Line 678 of lalr1.cc  */
#line 5167 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 580:

/* Line 678 of lalr1.cc  */
#line 5171 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 581:

/* Line 678 of lalr1.cc  */
#line 5175 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 582:

/* Line 678 of lalr1.cc  */
#line 5179 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 583:

/* Line 678 of lalr1.cc  */
#line 5183 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 584:

/* Line 678 of lalr1.cc  */
#line 5187 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 585:

/* Line 678 of lalr1.cc  */
#line 5195 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyKindTest( LOC((yyloc)) );
        }
    break;

  case 586:

/* Line 678 of lalr1.cc  */
#line 5203 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)) );
        }
    break;

  case 587:

/* Line 678 of lalr1.cc  */
#line 5207 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)) );
        }
    break;

  case 588:

/* Line 678 of lalr1.cc  */
#line 5211 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest(
                LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 589:

/* Line 678 of lalr1.cc  */
#line 5221 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TextTest( LOC((yyloc)) );
        }
    break;

  case 590:

/* Line 678 of lalr1.cc  */
#line 5229 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CommentTest( LOC((yyloc)));
        }
    break;

  case 591:

/* Line 678 of lalr1.cc  */
#line 5237 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 592:

/* Line 678 of lalr1.cc  */
#line 5241 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 593:

/* Line 678 of lalr1.cc  */
#line 5245 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 594:

/* Line 678 of lalr1.cc  */
#line 5253 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 595:

/* Line 678 of lalr1.cc  */
#line 5257 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<zorba::QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 596:

/* Line 678 of lalr1.cc  */
#line 5263 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<zorba::QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 597:

/* Line 678 of lalr1.cc  */
#line 5269 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 598:

/* Line 678 of lalr1.cc  */
#line 5273 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 599:

/* Line 678 of lalr1.cc  */
#line 5283 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<zorba::QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 600:

/* Line 678 of lalr1.cc  */
#line 5291 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 601:

/* Line 678 of lalr1.cc  */
#line 5295 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<zorba::QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 602:

/* Line 678 of lalr1.cc  */
#line 5301 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<zorba::QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 603:

/* Line 678 of lalr1.cc  */
#line 5310 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<zorba::QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 604:

/* Line 678 of lalr1.cc  */
#line 5319 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 605:

/* Line 678 of lalr1.cc  */
#line 5325 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 606:

/* Line 678 of lalr1.cc  */
#line 5331 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 607:

/* Line 678 of lalr1.cc  */
#line 5341 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<zorba::QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 608:

/* Line 678 of lalr1.cc  */
#line 5358 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<zorba::QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 609:

/* Line 678 of lalr1.cc  */
#line 5365 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<zorba::QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 610:

/* Line 678 of lalr1.cc  */
#line 5380 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 611:

/* Line 678 of lalr1.cc  */
#line 5416 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 612:

/* Line 678 of lalr1.cc  */
#line 5420 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 613:

/* Line 678 of lalr1.cc  */
#line 5428 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<zorba::QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 614:

/* Line 678 of lalr1.cc  */
#line 5436 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new InlineFunction(LOC((yyloc)),
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theParams,
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theReturnType,
                              (yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (2)].fnsig);
    }
    break;

  case 615:

/* Line 678 of lalr1.cc  */
#line 5448 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 616:

/* Line 678 of lalr1.cc  */
#line 5452 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 617:

/* Line 678 of lalr1.cc  */
#line 5460 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 618:

/* Line 678 of lalr1.cc  */
#line 5468 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 619:

/* Line 678 of lalr1.cc  */
#line 5472 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 620:

/* Line 678 of lalr1.cc  */
#line 5483 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 621:

/* Line 678 of lalr1.cc  */
#line 5500 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 622:

/* Line 678 of lalr1.cc  */
#line 5506 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 623:

/* Line 678 of lalr1.cc  */
#line 5512 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 624:

/* Line 678 of lalr1.cc  */
#line 5522 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 625:

/* Line 678 of lalr1.cc  */
#line 5526 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 626:

/* Line 678 of lalr1.cc  */
#line 5532 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 627:

/* Line 678 of lalr1.cc  */
#line 5538 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 628:

/* Line 678 of lalr1.cc  */
#line 5542 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 629:

/* Line 678 of lalr1.cc  */
#line 5548 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 630:

/* Line 678 of lalr1.cc  */
#line 5552 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 631:

/* Line 678 of lalr1.cc  */
#line 5558 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 632:

/* Line 678 of lalr1.cc  */
#line 5564 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 633:

/* Line 678 of lalr1.cc  */
#line 5571 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 634:

/* Line 678 of lalr1.cc  */
#line 5581 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 635:

/* Line 678 of lalr1.cc  */
#line 5586 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 636:

/* Line 678 of lalr1.cc  */
#line 5594 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 637:

/* Line 678 of lalr1.cc  */
#line 5600 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 638:

/* Line 678 of lalr1.cc  */
#line 5610 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 639:

/* Line 678 of lalr1.cc  */
#line 5632 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 640:

/* Line 678 of lalr1.cc  */
#line 5641 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 641:

/* Line 678 of lalr1.cc  */
#line 5647 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 642:

/* Line 678 of lalr1.cc  */
#line 5660 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<zorba::QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 643:

/* Line 678 of lalr1.cc  */
#line 5674 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 644:

/* Line 678 of lalr1.cc  */
#line 5681 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 645:

/* Line 678 of lalr1.cc  */
#line 5687 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 646:

/* Line 678 of lalr1.cc  */
#line 5697 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 647:

/* Line 678 of lalr1.cc  */
#line 5702 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CatchExpr(LOC((yyloc)),*(yysemantic_stack_[(7) - (2)].name_test_list), static_cast<zorba::QName*>((yysemantic_stack_[(7) - (5)].expr)), NULL, NULL, (yysemantic_stack_[(7) - (7)].expr));
       delete (yysemantic_stack_[(7) - (2)].name_test_list);
    }
    break;

  case 648:

/* Line 678 of lalr1.cc  */
#line 5707 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)),
                          *(yysemantic_stack_[(10) - (2)].name_test_list),
                          static_cast<zorba::QName*>((yysemantic_stack_[(10) - (5)].expr)),
                          static_cast<zorba::QName*>((yysemantic_stack_[(10) - (8)].expr)),
                          NULL,
                          (yysemantic_stack_[(10) - (10)].expr));
       delete (yysemantic_stack_[(10) - (2)].name_test_list);
    }
    break;

  case 649:

/* Line 678 of lalr1.cc  */
#line 5717 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          *(yysemantic_stack_[(13) - (2)].name_test_list),
                          static_cast<zorba::QName*>((yysemantic_stack_[(13) - (5)].expr)),
                          static_cast<zorba::QName*>((yysemantic_stack_[(13) - (8)].expr)),
                          static_cast<zorba::QName*>((yysemantic_stack_[(13) - (11)].expr)),
                          (yysemantic_stack_[(13) - (13)].expr));
       delete (yysemantic_stack_[(13) - (2)].name_test_list);
    }
    break;

  case 650:

/* Line 678 of lalr1.cc  */
#line 5731 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 651:

/* Line 678 of lalr1.cc  */
#line 5739 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 652:

/* Line 678 of lalr1.cc  */
#line 5745 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 653:

/* Line 678 of lalr1.cc  */
#line 5763 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 654:

/* Line 678 of lalr1.cc  */
#line 5771 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 655:

/* Line 678 of lalr1.cc  */
#line 5775 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 656:

/* Line 678 of lalr1.cc  */
#line 5782 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 657:

/* Line 678 of lalr1.cc  */
#line 5787 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 658:

/* Line 678 of lalr1.cc  */
#line 5795 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 659:

/* Line 678 of lalr1.cc  */
#line 5799 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 660:

/* Line 678 of lalr1.cc  */
#line 5806 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 661:

/* Line 678 of lalr1.cc  */
#line 5810 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 662:

/* Line 678 of lalr1.cc  */
#line 5817 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 663:

/* Line 678 of lalr1.cc  */
#line 5821 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 664:

/* Line 678 of lalr1.cc  */
#line 5828 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 665:

/* Line 678 of lalr1.cc  */
#line 5832 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 666:

/* Line 678 of lalr1.cc  */
#line 5841 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 667:

/* Line 678 of lalr1.cc  */
#line 5853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 668:

/* Line 678 of lalr1.cc  */
#line 5857 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 669:

/* Line 678 of lalr1.cc  */
#line 5864 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 670:

/* Line 678 of lalr1.cc  */
#line 5868 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 671:

/* Line 678 of lalr1.cc  */
#line 5876 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 672:

/* Line 678 of lalr1.cc  */
#line 5884 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 673:

/* Line 678 of lalr1.cc  */
#line 5892 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 674:

/* Line 678 of lalr1.cc  */
#line 5896 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 675:

/* Line 678 of lalr1.cc  */
#line 5903 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 676:

/* Line 678 of lalr1.cc  */
#line 5907 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 677:

/* Line 678 of lalr1.cc  */
#line 5915 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 678:

/* Line 678 of lalr1.cc  */
#line 5926 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 679:

/* Line 678 of lalr1.cc  */
#line 5930 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 680:

/* Line 678 of lalr1.cc  */
#line 5938 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 681:

/* Line 678 of lalr1.cc  */
#line 5950 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 682:

/* Line 678 of lalr1.cc  */
#line 5956 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 683:

/* Line 678 of lalr1.cc  */
#line 5965 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 684:

/* Line 678 of lalr1.cc  */
#line 5969 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 685:

/* Line 678 of lalr1.cc  */
#line 5977 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 686:

/* Line 678 of lalr1.cc  */
#line 5981 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 687:

/* Line 678 of lalr1.cc  */
#line 5985 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 688:

/* Line 678 of lalr1.cc  */
#line 5992 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 689:

/* Line 678 of lalr1.cc  */
#line 5996 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 690:

/* Line 678 of lalr1.cc  */
#line 6003 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 691:

/* Line 678 of lalr1.cc  */
#line 6007 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 692:

/* Line 678 of lalr1.cc  */
#line 6015 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 693:

/* Line 678 of lalr1.cc  */
#line 6019 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 694:

/* Line 678 of lalr1.cc  */
#line 6023 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 695:

/* Line 678 of lalr1.cc  */
#line 6027 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 696:

/* Line 678 of lalr1.cc  */
#line 6031 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 697:

/* Line 678 of lalr1.cc  */
#line 6039 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 698:

/* Line 678 of lalr1.cc  */
#line 6047 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 699:

/* Line 678 of lalr1.cc  */
#line 6059 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 700:

/* Line 678 of lalr1.cc  */
#line 6071 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 701:

/* Line 678 of lalr1.cc  */
#line 6075 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 702:

/* Line 678 of lalr1.cc  */
#line 6079 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 703:

/* Line 678 of lalr1.cc  */
#line 6087 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 704:

/* Line 678 of lalr1.cc  */
#line 6093 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 705:

/* Line 678 of lalr1.cc  */
#line 6103 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 706:

/* Line 678 of lalr1.cc  */
#line 6107 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 707:

/* Line 678 of lalr1.cc  */
#line 6111 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 708:

/* Line 678 of lalr1.cc  */
#line 6115 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 709:

/* Line 678 of lalr1.cc  */
#line 6119 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 710:

/* Line 678 of lalr1.cc  */
#line 6123 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 711:

/* Line 678 of lalr1.cc  */
#line 6127 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 712:

/* Line 678 of lalr1.cc  */
#line 6131 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 713:

/* Line 678 of lalr1.cc  */
#line 6139 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 714:

/* Line 678 of lalr1.cc  */
#line 6143 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 715:

/* Line 678 of lalr1.cc  */
#line 6147 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 716:

/* Line 678 of lalr1.cc  */
#line 6151 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 717:

/* Line 678 of lalr1.cc  */
#line 6159 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 718:

/* Line 678 of lalr1.cc  */
#line 6165 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 719:

/* Line 678 of lalr1.cc  */
#line 6175 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<zorba::QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 720:

/* Line 678 of lalr1.cc  */
#line 6185 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::with );
        }
    break;

  case 721:

/* Line 678 of lalr1.cc  */
#line 6189 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::without );
        }
    break;

  case 722:

/* Line 678 of lalr1.cc  */
#line 6197 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 723:

/* Line 678 of lalr1.cc  */
#line 6207 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 724:

/* Line 678 of lalr1.cc  */
#line 6218 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 725:

/* Line 678 of lalr1.cc  */
#line 6225 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 726:

/* Line 678 of lalr1.cc  */
#line 6229 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 727:

/* Line 678 of lalr1.cc  */
#line 6236 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 728:

/* Line 678 of lalr1.cc  */
#line 6240 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 729:

/* Line 678 of lalr1.cc  */
#line 6247 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 730:

/* Line 678 of lalr1.cc  */
#line 6252 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 731:

/* Line 678 of lalr1.cc  */
#line 6261 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 732:

/* Line 678 of lalr1.cc  */
#line 6270 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = NULL;
        }
    break;

  case 733:

/* Line 678 of lalr1.cc  */
#line 6274 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 734:

/* Line 678 of lalr1.cc  */
#line 6281 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 735:

/* Line 678 of lalr1.cc  */
#line 6285 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 736:

/* Line 678 of lalr1.cc  */
#line 6293 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 737:

/* Line 678 of lalr1.cc  */
#line 6302 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 738:

/* Line 678 of lalr1.cc  */
#line 6309 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 739:

/* Line 678 of lalr1.cc  */
#line 6319 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 740:

/* Line 678 of lalr1.cc  */
#line 6323 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 741:

/* Line 678 of lalr1.cc  */
#line 6330 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 742:

/* Line 678 of lalr1.cc  */
#line 6336 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 743:

/* Line 678 of lalr1.cc  */
#line 6345 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 744:

/* Line 678 of lalr1.cc  */
#line 6349 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 745:

/* Line 678 of lalr1.cc  */
#line 6356 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 746:

/* Line 678 of lalr1.cc  */
#line 6361 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 747:

/* Line 678 of lalr1.cc  */
#line 6373 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 748:

/* Line 678 of lalr1.cc  */
#line 6381 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 749:

/* Line 678 of lalr1.cc  */
#line 6393 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 750:

/* Line 678 of lalr1.cc  */
#line 6401 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 751:

/* Line 678 of lalr1.cc  */
#line 6405 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 752:

/* Line 678 of lalr1.cc  */
#line 6413 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 753:

/* Line 678 of lalr1.cc  */
#line 6417 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 754:

/* Line 678 of lalr1.cc  */
#line 6421 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 755:

/* Line 678 of lalr1.cc  */
#line 6429 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 756:

/* Line 678 of lalr1.cc  */
#line 6437 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 757:

/* Line 678 of lalr1.cc  */
#line 6441 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 758:

/* Line 678 of lalr1.cc  */
#line 6445 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 759:

/* Line 678 of lalr1.cc  */
#line 6449 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 760:

/* Line 678 of lalr1.cc  */
#line 6457 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 761:

/* Line 678 of lalr1.cc  */
#line 6465 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 762:

/* Line 678 of lalr1.cc  */
#line 6477 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 763:

/* Line 678 of lalr1.cc  */
#line 6481 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 764:

/* Line 678 of lalr1.cc  */
#line 6489 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 767:

/* Line 678 of lalr1.cc  */
#line 6507 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          auto_ptr<zorba::QName> lQName( static_cast<zorba::QName*>((yysemantic_stack_[(1) - (1)].expr)) );
          zstring const &tmp = lQName->get_qname();
          if ( tmp.find (':') != string::npos ) {
            error((yylocation_stack_[(1) - (1)]), "A NCName is expected, found a QName");
            YYERROR;
          }
          (yyval.sval) = SYMTAB_PUT(tmp.c_str());
        }
    break;

  case 769:

/* Line 678 of lalr1.cc  */
#line 6520 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 770:

/* Line 678 of lalr1.cc  */
#line 6521 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 771:

/* Line 678 of lalr1.cc  */
#line 6522 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 772:

/* Line 678 of lalr1.cc  */
#line 6523 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 773:

/* Line 678 of lalr1.cc  */
#line 6524 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 774:

/* Line 678 of lalr1.cc  */
#line 6525 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 775:

/* Line 678 of lalr1.cc  */
#line 6526 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 776:

/* Line 678 of lalr1.cc  */
#line 6527 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 777:

/* Line 678 of lalr1.cc  */
#line 6528 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 778:

/* Line 678 of lalr1.cc  */
#line 6529 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 779:

/* Line 678 of lalr1.cc  */
#line 6530 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 780:

/* Line 678 of lalr1.cc  */
#line 6531 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 781:

/* Line 678 of lalr1.cc  */
#line 6532 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 782:

/* Line 678 of lalr1.cc  */
#line 6533 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 783:

/* Line 678 of lalr1.cc  */
#line 6534 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 785:

/* Line 678 of lalr1.cc  */
#line 6539 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 786:

/* Line 678 of lalr1.cc  */
#line 6540 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 787:

/* Line 678 of lalr1.cc  */
#line 6541 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 788:

/* Line 678 of lalr1.cc  */
#line 6542 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 789:

/* Line 678 of lalr1.cc  */
#line 6543 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 790:

/* Line 678 of lalr1.cc  */
#line 6544 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 791:

/* Line 678 of lalr1.cc  */
#line 6545 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 792:

/* Line 678 of lalr1.cc  */
#line 6546 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 793:

/* Line 678 of lalr1.cc  */
#line 6547 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 794:

/* Line 678 of lalr1.cc  */
#line 6548 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 795:

/* Line 678 of lalr1.cc  */
#line 6549 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 796:

/* Line 678 of lalr1.cc  */
#line 6550 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 797:

/* Line 678 of lalr1.cc  */
#line 6551 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 798:

/* Line 678 of lalr1.cc  */
#line 6552 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 799:

/* Line 678 of lalr1.cc  */
#line 6553 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 800:

/* Line 678 of lalr1.cc  */
#line 6554 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 801:

/* Line 678 of lalr1.cc  */
#line 6555 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 802:

/* Line 678 of lalr1.cc  */
#line 6556 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 803:

/* Line 678 of lalr1.cc  */
#line 6557 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 804:

/* Line 678 of lalr1.cc  */
#line 6558 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 805:

/* Line 678 of lalr1.cc  */
#line 6559 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 806:

/* Line 678 of lalr1.cc  */
#line 6560 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 807:

/* Line 678 of lalr1.cc  */
#line 6561 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 808:

/* Line 678 of lalr1.cc  */
#line 6562 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 809:

/* Line 678 of lalr1.cc  */
#line 6563 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 810:

/* Line 678 of lalr1.cc  */
#line 6564 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 811:

/* Line 678 of lalr1.cc  */
#line 6565 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 812:

/* Line 678 of lalr1.cc  */
#line 6566 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 813:

/* Line 678 of lalr1.cc  */
#line 6567 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 814:

/* Line 678 of lalr1.cc  */
#line 6568 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 815:

/* Line 678 of lalr1.cc  */
#line 6569 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 816:

/* Line 678 of lalr1.cc  */
#line 6570 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 817:

/* Line 678 of lalr1.cc  */
#line 6571 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 818:

/* Line 678 of lalr1.cc  */
#line 6572 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 819:

/* Line 678 of lalr1.cc  */
#line 6573 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 820:

/* Line 678 of lalr1.cc  */
#line 6574 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 821:

/* Line 678 of lalr1.cc  */
#line 6575 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 822:

/* Line 678 of lalr1.cc  */
#line 6576 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 823:

/* Line 678 of lalr1.cc  */
#line 6577 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 824:

/* Line 678 of lalr1.cc  */
#line 6578 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 825:

/* Line 678 of lalr1.cc  */
#line 6579 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 826:

/* Line 678 of lalr1.cc  */
#line 6580 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 827:

/* Line 678 of lalr1.cc  */
#line 6581 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 828:

/* Line 678 of lalr1.cc  */
#line 6582 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 829:

/* Line 678 of lalr1.cc  */
#line 6583 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 830:

/* Line 678 of lalr1.cc  */
#line 6584 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 831:

/* Line 678 of lalr1.cc  */
#line 6585 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 832:

/* Line 678 of lalr1.cc  */
#line 6586 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 833:

/* Line 678 of lalr1.cc  */
#line 6587 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 834:

/* Line 678 of lalr1.cc  */
#line 6588 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 835:

/* Line 678 of lalr1.cc  */
#line 6589 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 836:

/* Line 678 of lalr1.cc  */
#line 6590 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 837:

/* Line 678 of lalr1.cc  */
#line 6591 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 838:

/* Line 678 of lalr1.cc  */
#line 6592 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 839:

/* Line 678 of lalr1.cc  */
#line 6593 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 840:

/* Line 678 of lalr1.cc  */
#line 6594 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 841:

/* Line 678 of lalr1.cc  */
#line 6595 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 842:

/* Line 678 of lalr1.cc  */
#line 6596 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 843:

/* Line 678 of lalr1.cc  */
#line 6597 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 844:

/* Line 678 of lalr1.cc  */
#line 6598 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 845:

/* Line 678 of lalr1.cc  */
#line 6599 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 846:

/* Line 678 of lalr1.cc  */
#line 6600 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 847:

/* Line 678 of lalr1.cc  */
#line 6601 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 848:

/* Line 678 of lalr1.cc  */
#line 6602 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 849:

/* Line 678 of lalr1.cc  */
#line 6603 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 850:

/* Line 678 of lalr1.cc  */
#line 6604 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 851:

/* Line 678 of lalr1.cc  */
#line 6605 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 852:

/* Line 678 of lalr1.cc  */
#line 6606 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 853:

/* Line 678 of lalr1.cc  */
#line 6607 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 854:

/* Line 678 of lalr1.cc  */
#line 6608 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 855:

/* Line 678 of lalr1.cc  */
#line 6609 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 856:

/* Line 678 of lalr1.cc  */
#line 6610 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 857:

/* Line 678 of lalr1.cc  */
#line 6611 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 858:

/* Line 678 of lalr1.cc  */
#line 6612 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 859:

/* Line 678 of lalr1.cc  */
#line 6613 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 860:

/* Line 678 of lalr1.cc  */
#line 6614 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 861:

/* Line 678 of lalr1.cc  */
#line 6615 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 862:

/* Line 678 of lalr1.cc  */
#line 6616 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 863:

/* Line 678 of lalr1.cc  */
#line 6617 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 864:

/* Line 678 of lalr1.cc  */
#line 6618 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 865:

/* Line 678 of lalr1.cc  */
#line 6619 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 866:

/* Line 678 of lalr1.cc  */
#line 6620 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 867:

/* Line 678 of lalr1.cc  */
#line 6621 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 868:

/* Line 678 of lalr1.cc  */
#line 6622 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 869:

/* Line 678 of lalr1.cc  */
#line 6623 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 870:

/* Line 678 of lalr1.cc  */
#line 6624 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 871:

/* Line 678 of lalr1.cc  */
#line 6625 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 872:

/* Line 678 of lalr1.cc  */
#line 6626 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 873:

/* Line 678 of lalr1.cc  */
#line 6627 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 874:

/* Line 678 of lalr1.cc  */
#line 6628 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 875:

/* Line 678 of lalr1.cc  */
#line 6629 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 876:

/* Line 678 of lalr1.cc  */
#line 6630 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 877:

/* Line 678 of lalr1.cc  */
#line 6631 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 878:

/* Line 678 of lalr1.cc  */
#line 6632 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 879:

/* Line 678 of lalr1.cc  */
#line 6633 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 880:

/* Line 678 of lalr1.cc  */
#line 6634 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 881:

/* Line 678 of lalr1.cc  */
#line 6635 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 882:

/* Line 678 of lalr1.cc  */
#line 6636 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 883:

/* Line 678 of lalr1.cc  */
#line 6637 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 884:

/* Line 678 of lalr1.cc  */
#line 6638 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 885:

/* Line 678 of lalr1.cc  */
#line 6639 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 886:

/* Line 678 of lalr1.cc  */
#line 6640 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 887:

/* Line 678 of lalr1.cc  */
#line 6641 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 888:

/* Line 678 of lalr1.cc  */
#line 6642 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 889:

/* Line 678 of lalr1.cc  */
#line 6643 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 890:

/* Line 678 of lalr1.cc  */
#line 6644 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 891:

/* Line 678 of lalr1.cc  */
#line 6645 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 892:

/* Line 678 of lalr1.cc  */
#line 6646 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 893:

/* Line 678 of lalr1.cc  */
#line 6647 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 894:

/* Line 678 of lalr1.cc  */
#line 6648 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 895:

/* Line 678 of lalr1.cc  */
#line 6649 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 896:

/* Line 678 of lalr1.cc  */
#line 6650 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 897:

/* Line 678 of lalr1.cc  */
#line 6651 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 898:

/* Line 678 of lalr1.cc  */
#line 6652 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 899:

/* Line 678 of lalr1.cc  */
#line 6653 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 900:

/* Line 678 of lalr1.cc  */
#line 6654 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 901:

/* Line 678 of lalr1.cc  */
#line 6655 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 902:

/* Line 678 of lalr1.cc  */
#line 6656 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 903:

/* Line 678 of lalr1.cc  */
#line 6657 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 904:

/* Line 678 of lalr1.cc  */
#line 6658 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 905:

/* Line 678 of lalr1.cc  */
#line 6659 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 906:

/* Line 678 of lalr1.cc  */
#line 6660 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 907:

/* Line 678 of lalr1.cc  */
#line 6661 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 908:

/* Line 678 of lalr1.cc  */
#line 6662 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 909:

/* Line 678 of lalr1.cc  */
#line 6663 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 910:

/* Line 678 of lalr1.cc  */
#line 6664 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 911:

/* Line 678 of lalr1.cc  */
#line 6665 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 912:

/* Line 678 of lalr1.cc  */
#line 6666 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 913:

/* Line 678 of lalr1.cc  */
#line 6667 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 914:

/* Line 678 of lalr1.cc  */
#line 6668 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 915:

/* Line 678 of lalr1.cc  */
#line 6669 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 916:

/* Line 678 of lalr1.cc  */
#line 6670 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 917:

/* Line 678 of lalr1.cc  */
#line 6671 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 918:

/* Line 678 of lalr1.cc  */
#line 6672 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 919:

/* Line 678 of lalr1.cc  */
#line 6673 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 920:

/* Line 678 of lalr1.cc  */
#line 6674 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 921:

/* Line 678 of lalr1.cc  */
#line 6675 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 922:

/* Line 678 of lalr1.cc  */
#line 6676 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 923:

/* Line 678 of lalr1.cc  */
#line 6677 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 924:

/* Line 678 of lalr1.cc  */
#line 6678 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 925:

/* Line 678 of lalr1.cc  */
#line 6679 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 926:

/* Line 678 of lalr1.cc  */
#line 6680 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 927:

/* Line 678 of lalr1.cc  */
#line 6681 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 928:

/* Line 678 of lalr1.cc  */
#line 6682 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 929:

/* Line 678 of lalr1.cc  */
#line 6683 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("local"))); }
    break;

  case 930:

/* Line 678 of lalr1.cc  */
#line 6684 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 931:

/* Line 678 of lalr1.cc  */
#line 6685 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 932:

/* Line 678 of lalr1.cc  */
#line 6686 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 933:

/* Line 678 of lalr1.cc  */
#line 6687 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 934:

/* Line 678 of lalr1.cc  */
#line 6688 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 935:

/* Line 678 of lalr1.cc  */
#line 6689 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 936:

/* Line 678 of lalr1.cc  */
#line 6690 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eval"))); }
    break;

  case 937:

/* Line 678 of lalr1.cc  */
#line 6691 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 938:

/* Line 678 of lalr1.cc  */
#line 6692 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 939:

/* Line 678 of lalr1.cc  */
#line 6693 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 940:

/* Line 678 of lalr1.cc  */
#line 6694 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 941:

/* Line 678 of lalr1.cc  */
#line 6695 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 942:

/* Line 678 of lalr1.cc  */
#line 6696 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 943:

/* Line 678 of lalr1.cc  */
#line 6697 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 944:

/* Line 678 of lalr1.cc  */
#line 6698 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 945:

/* Line 678 of lalr1.cc  */
#line 6699 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 946:

/* Line 678 of lalr1.cc  */
#line 6700 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 947:

/* Line 678 of lalr1.cc  */
#line 6701 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 948:

/* Line 678 of lalr1.cc  */
#line 6702 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 949:

/* Line 678 of lalr1.cc  */
#line 6703 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 950:

/* Line 678 of lalr1.cc  */
#line 6704 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 951:

/* Line 678 of lalr1.cc  */
#line 6705 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 952:

/* Line 678 of lalr1.cc  */
#line 6706 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 953:

/* Line 678 of lalr1.cc  */
#line 6707 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 954:

/* Line 678 of lalr1.cc  */
#line 6708 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 955:

/* Line 678 of lalr1.cc  */
#line 6709 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 956:

/* Line 678 of lalr1.cc  */
#line 6710 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 957:

/* Line 678 of lalr1.cc  */
#line 6711 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 958:

/* Line 678 of lalr1.cc  */
#line 6712 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 959:

/* Line 678 of lalr1.cc  */
#line 6713 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 960:

/* Line 678 of lalr1.cc  */
#line 6714 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 961:

/* Line 678 of lalr1.cc  */
#line 6715 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 962:

/* Line 678 of lalr1.cc  */
#line 6716 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 963:

/* Line 678 of lalr1.cc  */
#line 6717 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 964:

/* Line 678 of lalr1.cc  */
#line 6718 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 965:

/* Line 678 of lalr1.cc  */
#line 6719 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 966:

/* Line 678 of lalr1.cc  */
#line 6720 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 967:

/* Line 678 of lalr1.cc  */
#line 6721 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 968:

/* Line 678 of lalr1.cc  */
#line 6722 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 969:

/* Line 678 of lalr1.cc  */
#line 6723 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 970:

/* Line 678 of lalr1.cc  */
#line 6724 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 971:

/* Line 678 of lalr1.cc  */
#line 6725 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 972:

/* Line 678 of lalr1.cc  */
#line 6726 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 973:

/* Line 678 of lalr1.cc  */
#line 6727 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 974:

/* Line 678 of lalr1.cc  */
#line 6728 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 975:

/* Line 678 of lalr1.cc  */
#line 6729 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 976:

/* Line 678 of lalr1.cc  */
#line 6730 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 977:

/* Line 678 of lalr1.cc  */
#line 6731 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 978:

/* Line 678 of lalr1.cc  */
#line 6732 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 979:

/* Line 678 of lalr1.cc  */
#line 6733 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 980:

/* Line 678 of lalr1.cc  */
#line 6734 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 981:

/* Line 678 of lalr1.cc  */
#line 6735 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 982:

/* Line 678 of lalr1.cc  */
#line 6736 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 983:

/* Line 678 of lalr1.cc  */
#line 6742 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          // EQName's namespace URI value is whitespace normalized according to the rules for the xs:anyURI type
          std::string uri = "\"" + SYMTAB((yysemantic_stack_[(3) - (1)].sval)) + "\"";
          std::string eqname = SYMTAB(driver.symtab.put_uri(uri.c_str(), uri.size())) + ":" + SYMTAB((yysemantic_stack_[(3) - (3)].sval));
          (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT(eqname.c_str())), true);
        }
    break;

  case 984:

/* Line 678 of lalr1.cc  */
#line 6748 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new zorba::QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;



/* Line 678 of lalr1.cc  */
#line 11900 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1567;
  const short int
  xquery_parser::yypact_[] =
  {
      3054, -1567, -1567,  5719,  5719,  5719, -1567, -1567,   342,   855,
     352, -1567, -1567, -1567,   396, -1567, -1567, -1567,   371,   440,
     621, -1567,   585,   469,   609,   709, -1567,    16, -1567, -1567,
   -1567, -1567, -1567, -1567,   710, -1567,   635,   651, -1567, -1567,
   -1567, -1567,   595, -1567,   717, -1567,   655,   666, -1567,    15,
   -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567,
   -1567, -1567, -1567,   712,   720, -1567, -1567, -1567, -1567,   611,
    8975, -1567, -1567, -1567,   756, -1567, -1567, -1567,   766, -1567,
     764,   786, -1567, -1567, 12701, -1567, -1567, -1567, -1567, -1567,
   -1567, -1567, -1567,   802, -1567, -1567,   796,   808, -1567, -1567,
   -1567, -1567, -1567, -1567, -1567,  3351,  3647, 12701, -1567, -1567,
   -1567, -1567, -1567, -1567, -1567,   769, -1567, -1567,   812,  9855,
   -1567, 10145,   814,   818, -1567, -1567, -1567,   825, -1567,  8679,
   -1567, -1567, -1567, -1567, -1567, -1567,   771, -1567, -1567, -1567,
   -1567, -1567, -1567, -1567, -1567,    45,   747, -1567, -1567, -1567,
   -1567, -1567, -1567, -1567, -1567,   360,   798,   645, -1567,   741,
     450, -1567, -1567, -1567, -1567, -1567, -1567,   845, -1567,   820,
     723,   728,   731, -1567, -1567,   815,   819, -1567, -1567, -1567,
   -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567,
   -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567,
   -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567,
   -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567,
   -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567,
   -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567,  6015,
     972, -1567,  6311, -1567, -1567,   568,    64, -1567, -1567, -1567,
   -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567,
   -1567,    81, -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567,
   -1567, -1567, -1567, -1567, -1567,  5719, -1567, -1567, -1567, -1567,
      19, -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567,   870,
   -1567,   788, -1567, -1567, -1567,   169, -1567, -1567, -1567, -1567,
   -1567, -1567, -1567, -1567,   816,   888, -1567,  1142,   733,   571,
     501,   152,    42, -1567,   932,   787,   884,   885,  6607, -1567,
   -1567, -1567,   166, -1567, -1567,  8679, -1567,   233, -1567,   835,
    8975, -1567,   835,  8975, -1567, -1567, -1567,   524, -1567, -1567,
   -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567,
   -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567,
   -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567,
   -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567,
     869,   846,   836, -1567, -1567, -1567, -1567, -1567,   822, -1567,
    5719,   824,   827,   844,   979,   557,   597,    -1, 12985, 12701,
     -17,   965, 12701,   864,   899,   311,  9855, -1567, -1567,   706,
     348,   772, 12701, -1567, -1567, -1567, -1567, -1567,   732, 12701,
     724,   725,   574,   722,   604,   297, -1567, -1567, -1567, -1567,
     708, -1567,  9855,  5719,   834,  5719,    57,  6903, 10713,   743,
     748, 12701,   915,   -11,   881,  6903,  1045,   119,   110, 12701,
     933,   908,   945, -1567,  6903,  9563, 12701, 12701, 12701,  5719,
     867,  6903,  6903, 12701,  5719,   902,   904, -1567, -1567, -1567,
    6903, 10997, -1567,   903, -1567,   909, -1567, -1567, -1567, -1567,
     910, -1567,   914, -1567, -1567, -1567, -1567, -1567,   916, -1567,
   -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567,
   -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567,
   -1567, -1567, -1567, -1567, -1567, -1567, -1567, 12701, -1567, -1567,
   -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567,
     918, 12701, -1567, -1567, -1567,   880,  3943,   917,   919,   920,
   12701,  5719, -1567,   924,    21, -1567,   592,  1035,  6903, -1567,
   -1567,   122, -1567, -1567, -1567,  1059, -1567, -1567, -1567, -1567,
    6903,   866, -1567,  1050,  6903,  6903,   895,  6903,  6903,  6903,
    6903,   856, 12701,   766,   897,   898,  6903,  6903,  3351,   840,
   -1567, -1567, -1567, -1567,   855,   709,    85,    90,  1084,  7199,
    7199,  7495,  7495, -1567,   870,   766, -1567,  6903, -1567,   973,
     585,    16,   925,   922,   926,  5719,  6903, -1567, -1567, -1567,
   -1567, -1567, -1567, -1567, -1567,  7791,  7791,  7791, -1567,  7791,
    7791, -1567,  7791, -1567,  7791, -1567, -1567, -1567, -1567, -1567,
   -1567, -1567,  7791,  7791,  1022,  7791,  7791,  7791,  7791,  7791,
    7791,  7791,  7791,  7791,  7791,  7791,   865,  1002,  1003,  1004,
   -1567, -1567, -1567,  4239, -1567, -1567,  8679,  8679,  6903,   835,
   -1567, -1567,   835, -1567,  4535,   835,  9855,   951,  4831, -1567,
   -1567, -1567,   279, -1567, -1567, -1567, -1567, -1567,   994,   995,
     469,  1073, -1567, -1567, 12985,   955,   590, 12701,   944,   946,
     955,   979,   978,   975, -1567, -1567, -1567, -1567, -1567,   431,
     862,    67, -1567,   811, -1567, -1567, -1567, -1567, 12701,   967,
    6903,   993, -1567, -1567, 12701, 12701, -1567,   980,   929,  5719,
   -1567,   930,   909,   651, -1567,   928,   931,    47, -1567,    56,
     201, -1567, -1567,  1010, -1567,    27, 12701,     3, 12701,  1024,
     226, -1567,  5719, -1567,   244, -1567,  9855,  1023,  1075,  9855,
     979,  1025,   301, 12701,  6903,    16,   227,   936, -1567,   937,
     938,   939,    32, -1567,    48,   943, -1567,   258,   263,   976,
   -1567,   947,  5719,  5719,   232, -1567,   265,   267,   437,  6903,
     125, -1567, -1567,  6903,  6903,  6903, -1567,  6903, -1567,  6903,
   12701,  1035, -1567,   185,   246, -1567, -1567, -1567,   251, -1567,
     259, -1567, -1567, -1567,    -3,   131,  1033,   894,   911,    43,
   -1567,   990, -1567, -1567, -1567,   948,   271,  5127,   255,  9271,
     840, -1567,   568,   599,  1099,  1099, -1567, -1567,    91, -1567,
   -1567,    96, -1567,    33, -1567, -1567, -1567, -1567, -1567, -1567,
   12701,   964,  6903,  1018, -1567, -1567, -1567,   888, -1567, -1567,
   -1567, -1567, -1567,  7791, -1567, -1567, -1567,    72,   501,   501,
     290,   152,   152,   152,   152,    42,    42, -1567, -1567, 12133,
   12133, 12701, 12701, -1567,   272, -1567, -1567,    25, -1567, -1567,
   -1567,   315, -1567, -1567, -1567,   379, -1567,   386, -1567,   550,
     575,   361, -1567,   469, -1567, -1567, -1567, -1567, -1567, -1567,
   -1567, -1567, -1567, -1567,   955, -1567,  1005, 12417,   998,  6903,
   -1567, -1567, -1567,  1046,   979,   979,   955, -1567,   729,   979,
     638, 12701,  -105,   314,  1117, -1567, -1567,   868,   420, -1567,
   -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567,
     431,    66,   619, -1567,   927,   195,  6903, -1567, 12701,    71,
     857,   979, -1567, -1567, -1567, -1567,  1006, 12701, -1567, 12701,
   -1567,  1037,  1034, 12133,  1047,  6903,   -60,  1016,    28,    58,
     912, -1567, -1567,   665,     3,  1046, 12133,  1049,  1069,   985,
     974,  1038,   979,  1012,  1041,  1078,   979,  6903,   -43, -1567,
   -1567, -1567,  1029, -1567, -1567, -1567, -1567,  1058,  6903,  6903,
    1031, -1567,  1083,  1085,  5719, -1567,  1000,  1008,  1036, 12701,
   -1567, 12701, -1567,  6903,  1044,   997,  6903,   388,   393,   444,
    1152, -1567,   211, -1567,   543, -1567, -1567,  1160, -1567,   654,
    6903,  6903,  6903,   669,  6903,  6903,  6903,  6903,  6903,  6903,
    1076,  6903,  6903, -1567,  8087,  1039,  1040,  1042,  1048,   788,
     678,   952, -1567,   548, -1567,    97,    77,    33,  7495,  7495,
    7495,  1119, -1567,  6903,   689,  1093, -1567, 12701,  1095, -1567,
   -1567,  6903,    72,   506,   179, -1567,   921,    92,   950,   953,
   -1567, -1567,   772, -1567,   949,   553,  1054,  1055, 12417,  1056,
   -1567,   523, -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567,
   -1567,  1060, -1567, -1567, -1567,  6903, -1567, -1567,   279, -1567,
   -1567, -1567, -1567, -1567, -1567, -1567,   490, -1567,  1175,   699,
   -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567,   935,
   -1567, -1567,  1185, -1567, -1567, -1567, -1567, -1567,   580,  1187,
   -1567,   653, -1567, -1567, -1567,   903,   440,   910,   635,   914,
     916,   798,   982,   523,   996,   999,  8383,   940,   913, -1567,
    1046,    66, -1567,  1009,  1051,  5719,  1043,  1053,  1080,  1057,
    1061, 12701,   304, -1567, 12701, -1567,  6903,  1079,  6903,  1101,
    6903,   -27,  1082,  6903,  1087, -1567,  1113,  1114,  6903, 12701,
     799,  1158, -1567, -1567, -1567, -1567, -1567, -1567, 12133, -1567,
    5719,   979,  1131, -1567, -1567, -1567,   979,  1131, -1567,  6903,
    1103,  5719, 12701, -1567, -1567,  6903,  6903,   693, -1567,    55,
     696, -1567, 11281,   730, -1567,   737, -1567,  1063, -1567, -1567,
    5719,  1062,  1064, -1567,  6903, -1567, -1567,  1065,  1083,  1150,
   -1567,  1122, -1567,   694, -1567, -1567,  1245, -1567, -1567,  5719,
   12701, -1567,   776, -1567, -1567, -1567,  1067,  1027,  1028, -1567,
   -1567, -1567,  1032,  1066, -1567, -1567, -1567, -1567, -1567,  1030,
   12701,  1077, -1567, -1567,  6903,  6903,  6903,  5423,  8087,  9271,
     952, -1567,  1147,  9271, -1567,  1099,   391, -1567, -1567, -1567,
    1093, -1567,   979, -1567,   810, -1567,    61,  1161, -1567,  6903,
    1162,  1018,   381,  1086, -1567,    72,  1019, -1567, -1567,   -55,
   -1567,   443,    26,  1021,    72,   443,  7791, -1567,   142, -1567,
   -1567, -1567, -1567, -1567, -1567,    72,  1129,  1007,   862,    26,
   -1567, -1567,   991,  1199, -1567, -1567, -1567, 10429,  1092,  1105,
    1108, -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567,
   -1567, -1567, -1567, -1567,  1258,     1,  1260,     1,  1052,  1189,
   -1567, -1567, -1567, -1567,  1130, 12701,  1071, -1567,   982,  8383,
   -1567,  1118, -1567, -1567, -1567, -1567, -1567, -1567,  6903,  1154,
   -1567, -1567,  6903, -1567,   313, -1567,  6903,  1159,  6903, -1567,
    6903, 12701, 12701, -1567,   664, -1567,  6903, -1567,  1179,  1181,
    1211,   979,  1131, -1567,  6903,  1125, -1567, -1567, -1567,  1124,
   -1567,   212,  6903,  5719,  1126,   214, -1567, 12701,  1128, 11565,
     -14, -1567, 11849,  1132, -1567, -1567,  1127, -1567, -1567, -1567,
    6903,   739,  1152, 12701,   800, -1567,  1133,  1152, 12701, -1567,
   -1567,  6903,  6903,  6903,  6903,  6903, -1567,  6903,   447,   455,
     464,   549, -1567, 12701, -1567, -1567, -1567, -1567,  1161, -1567,
   -1567, -1567,   979, -1567, -1567, -1567, -1567, -1567,  1135,  7791,
   -1567, -1567, -1567, -1567, -1567,    87,  7791,  7791,   562, -1567,
     950, -1567,   288, -1567,   953,    72,  1163, -1567, -1567,  1070,
   -1567, -1567, -1567, -1567,  1220,  1139, -1567,   478, -1567, -1567,
   -1567, -1567,    51,    51, -1567,     1, -1567, -1567,   483, -1567,
    1290,    26,  1232,  1143,  8383,   -47,  1072, -1567,  1165, -1567,
   -1567,  6903, -1567,  6903,  1184, -1567,  6903, -1567, -1567, -1567,
    1277, -1567, -1567,  8087,  6903,   979, -1567, -1567, -1567,  6903,
    6903, -1567, -1567, -1567,  8087,  8087,  1238,  5719, 12701,  1151,
   12701,  6903, 12701,  1153,  8087, -1567,    17,     4,  1152, 12701,
   -1567,  1140,  1152, -1567, -1567, -1567, -1567, -1567, -1567,  1141,
    1083,  1085,  6903,  1222, -1567,   484, -1567, -1567, -1567,   152,
    7791,  7791,   290,   572, -1567, -1567, -1567, -1567, -1567, -1567,
    6903, -1567, 12133, -1567, 12133,  1246, -1567, -1567, -1567,  1313,
   -1567, -1567, -1567,  1088,  1247, -1567, -1567,  1249, -1567,   647,
   12701,  1234,  1134, 12701,  8383, -1567, -1567,  6903, -1567,  1239,
   -1567, -1567,  1131, -1567, -1567, 12133, -1567, -1567,  1265,  6903,
    1176, -1567,  1266,  8087, -1567, 12701,   415,   281, -1567,  1167,
    1152, -1567,  1168,  8087,   740,   453, 12701,  1248,  1048,   290,
     290,  7791,   454, -1567, -1567, 12133, -1567, -1567,  1232,  8383,
   -1567,  1161,  1068, 12701,  1250,  1145,  1249, -1567, 12701,  1186,
   12133,  5719, 12133,  1188, -1567, -1567,  1271,   503, -1567, -1567,
   -1567, -1567,  1192,   400, -1567, -1567, -1567,  1171, -1567,  1252,
   -1567,   499, 12701, -1567,   290, -1567, -1567, -1567, -1567, -1567,
    6903,  1074, 12701,  1253, -1567,  5719,  1190, -1567, -1567,  1191,
    6903, -1567, -1567, -1567, -1567, -1567, -1567, -1567, 12701,  1262,
    1225,   500, -1567,  1089,  1081, 12701, -1567, -1567,  6903,  8087,
    1195, 12701, -1567,  1267,  1048,  1090,  6903,  1091,  8087,   504,
   12701, -1567,  8383, -1567,  8383,  1269,  1225,  1196, -1567,  1193,
   12701, -1567,  1048,  1102,  1201, -1567, 12701,  1225,  1166, -1567,
    1274, 12701,  1094,  8383, -1567
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
       179,   461,   462,   182,   182,   182,   785,   984,   610,   876,
     885,   826,   790,   788,   770,   877,   880,   833,   794,   771,
     772,   936,   825,   886,   774,   883,   855,   835,   810,   830,
     831,   881,   878,   829,   776,   884,   777,   778,   924,   938,
     923,   827,   846,   840,   779,   828,   781,   780,   925,   864,
     832,   807,   948,   949,   950,   951,   952,   953,   954,   955,
     956,   957,   958,   972,   979,   854,   850,   841,   821,   769,
       0,   849,   857,   865,   973,   845,   482,   822,   823,   879,
     974,   980,   842,   859,     0,   488,   450,   484,   852,   787,
     843,   844,   872,   847,   863,   871,   978,   981,   793,   834,
     874,   483,   862,   867,   773,     0,     0,     0,   398,   860,
     870,   875,   873,   853,   839,   926,   837,   838,   975,     0,
     397,     0,   976,   982,   868,   824,   848,   977,   428,     0,
     460,   869,   851,   858,   866,   861,   927,   815,   820,   819,
     818,   817,   816,   782,   836,     0,   786,   882,   808,   915,
     914,   916,   792,   791,   811,   921,   775,   913,   918,   919,
     910,   814,   856,   912,   922,   920,   911,   812,   917,   929,
     932,   933,   930,   931,   928,   783,   934,   935,   937,   902,
     901,   888,   806,   799,   895,   891,   809,   805,   904,   905,
     795,   796,   789,   798,   900,   899,   896,   892,   909,   903,
     898,   894,   887,   797,   908,   907,   801,   803,   802,   893,
     897,   889,   804,   890,   800,   906,   959,   960,   961,   962,
     963,   964,   940,   941,   939,   945,   946,   947,   942,   943,
     944,   813,   965,   966,   967,   968,   969,   970,   971,   179,
       0,     2,   179,     5,     7,    19,     0,    24,    27,    32,
      33,    34,    35,    36,    37,    38,    28,    54,    55,    29,
      30,     0,    72,    75,    76,    31,    77,    78,    79,    80,
      81,    82,    14,   176,   177,   178,   185,   187,   479,   188,
       0,   189,   190,   191,   192,   193,   194,   195,   198,   183,
     227,   234,   229,   256,   262,     0,   254,   255,   236,   230,
     197,   231,   196,   232,   235,   353,   355,   357,   367,   371,
     373,   376,   381,   384,   387,   389,   391,   393,     0,   395,
     401,   403,     0,   419,   402,   424,   427,   429,   432,   434,
       0,   439,   436,     0,   447,   457,   459,   433,   463,   470,
     480,   471,   472,   473,   476,   477,   474,   475,   495,   497,
     498,   499,   496,   544,   545,   546,   547,   548,   549,   456,
     584,   576,   583,   582,   581,   578,   580,   577,   579,   481,
     478,   611,   612,    39,   237,   238,   240,   239,   241,   233,
       0,   458,   768,   784,   876,   885,   883,   786,     0,   180,
     181,     0,     0,   116,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   142,   143,     0,
       0,     0,     0,   138,   139,   140,   141,   148,     0,     0,
       0,     0,     0,     0,     0,     0,   114,   120,   122,   123,
       0,   136,     0,     0,     0,   182,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   281,   282,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   452,   455,   442,
       0,     0,   765,   770,   794,   772,   825,   886,   774,   835,
     776,   846,   779,   781,   780,   864,   972,   979,   769,   973,
     823,   974,   980,   847,   978,   981,   926,   975,   976,   982,
     977,   927,   921,   913,   919,   910,   812,   929,   932,   933,
     930,   783,   934,   448,   458,   768,   440,     0,   205,   441,
     444,   770,   771,   772,   776,   777,   778,   779,   769,   775,
     485,     0,   446,   445,   200,     0,     0,   774,   781,   780,
       0,   182,   486,   934,     0,   234,     0,   511,     0,   451,
     766,     0,   767,   422,   423,     0,   454,   453,   443,   426,
       0,     0,   540,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       3,     1,     6,     8,     0,     0,     0,     0,     0,   179,
     179,   179,   179,   186,   184,     0,   203,     0,   212,     0,
       0,     0,     0,     0,     0,     0,     0,   217,   242,   261,
     257,   263,   258,   260,   259,     0,     0,     0,   412,     0,
       0,   410,     0,   362,     0,   411,   404,   409,   408,   407,
     406,   405,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     400,   399,   396,     0,   420,   425,     0,     0,     0,   435,
     467,   438,   437,   449,     0,   464,     0,     0,     0,   551,
     553,   557,     0,    43,    40,    41,    44,    45,     0,     0,
       0,     0,    46,    47,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   621,   622,   623,   145,   144,     0,
      99,   152,   149,     0,   151,   150,   147,   146,     0,   108,
       0,     0,   115,   121,     0,     0,   137,     0,     0,     0,
     590,     0,     0,     0,   586,     0,     0,     0,   600,     0,
       0,   244,   245,   264,   265,     0,     0,     0,     0,   128,
       0,   132,   182,   614,     0,    56,     0,    65,     0,     0,
       0,    57,     0,     0,     0,     0,     0,   765,   591,     0,
       0,     0,     0,   326,     0,     0,   589,     0,     0,     0,
     608,     0,     0,     0,     0,   594,     0,     0,   207,     0,
       0,   201,   199,     0,     0,     0,   485,     0,   487,     0,
     512,   511,   508,     0,     0,   542,   541,   421,     0,   539,
       0,   634,   635,   585,     0,     0,     0,     0,     0,     0,
     640,     0,   206,   215,   216,     0,     0,     0,     0,     0,
     220,   221,    20,     0,    21,     0,     4,    25,     0,    11,
      26,     0,    15,   876,    73,    12,    74,    16,   204,   228,
       0,     0,     0,     0,   218,   243,   299,   354,   356,   360,
     366,   365,   364,     0,   361,   358,   359,     0,   375,   374,
     372,   378,   379,   380,   377,   382,   383,   386,   385,     0,
       0,     0,     0,   417,     0,   430,   431,     0,   468,   465,
     493,     0,   983,   613,   491,     0,   610,     0,   118,     0,
       0,     0,    98,     0,    88,    90,    91,    92,    93,    95,
      96,    97,    89,    94,    84,    85,     0,     0,   104,     0,
     100,   102,   103,   110,     0,     0,    83,    42,     0,     0,
       0,     0,     0,     0,     0,   715,   720,     0,     0,   716,
     750,   703,   705,   706,   707,   709,   711,   710,   708,   712,
       0,     0,     0,   153,     0,     0,     0,   107,     0,   156,
       0,     0,   556,   550,   587,   588,     0,     0,   604,     0,
     601,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   246,   247,     0,   252,   134,     0,     0,   129,     0,
       0,     0,     0,     0,     0,    58,     0,     0,     0,   280,
     286,   283,     0,   593,   592,   599,   607,     0,     0,     0,
       0,   555,     0,     0,     0,   413,     0,     0,     0,     0,
     597,     0,   595,     0,   208,     0,     0,     0,     0,     0,
     511,   509,     0,   500,     0,   489,   490,     0,     9,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   213,     0,   774,   781,   780,   934,     0,
       0,     0,   651,     0,   222,     0,     0,     0,   179,   179,
     179,     0,   253,     0,   310,   306,   308,     0,   300,   301,
     363,     0,     0,     0,     0,   681,   369,   654,   658,   660,
     662,   664,   667,   674,   675,   683,   886,   773,     0,   782,
     388,   562,   568,   569,   571,   615,   616,   572,   575,   390,
     392,   559,   394,   418,   469,     0,   466,   492,     0,   117,
      52,    53,    50,    51,   125,   124,     0,    86,     0,     0,
     105,   106,   111,    70,    71,    48,    49,    69,   721,     0,
     724,   751,     0,   714,   713,   718,   717,   749,     0,     0,
     726,     0,   722,   725,   704,     0,     0,     0,     0,     0,
       0,     0,   154,   160,     0,     0,     0,     0,     0,   109,
     112,     0,   157,     0,     0,   182,     0,     0,   608,     0,
       0,     0,     0,   561,     0,   267,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   248,     0,     0,     0,     0,
     293,     0,   290,   295,   251,   135,   130,   133,     0,   202,
       0,     0,    67,    61,    64,    63,     0,    59,   284,     0,
       0,   182,     0,   324,   328,     0,     0,     0,   331,     0,
       0,   337,     0,     0,   344,     0,   348,     0,   415,   414,
     182,     0,     0,   209,     0,   211,   325,     0,     0,     0,
     512,     0,   501,     0,   535,   532,     0,   536,   537,     0,
       0,   531,     0,   506,   534,   533,     0,     0,     0,   627,
     628,   624,     0,     0,   632,   633,   629,   638,   636,     0,
       0,     0,   642,   214,     0,     0,     0,     0,     0,     0,
     643,   644,     0,     0,   223,    22,     0,    13,    17,    18,
     307,   319,     0,   320,     0,   311,   312,   313,   314,     0,
     303,     0,     0,     0,   665,   678,     0,   368,   370,     0,
     697,     0,     0,     0,     0,     0,     0,   653,   655,   656,
     692,   693,   694,   696,   695,     0,     0,   669,   668,     0,
     672,   676,   690,   688,   687,   680,   684,     0,     0,     0,
       0,   565,   567,   566,   563,   560,   494,   119,   127,   126,
      87,   101,   738,   719,     0,   743,     0,   743,   732,   727,
     155,   161,   163,   162,     0,     0,     0,   113,   158,     0,
      23,     0,   605,   606,   609,   602,   603,   266,     0,     0,
     279,   271,     0,   275,     0,   269,     0,     0,     0,   288,
       0,     0,     0,   250,   291,   294,     0,   131,     0,     0,
      66,     0,    60,   285,     0,     0,   327,   329,   334,     0,
     332,     0,     0,     0,     0,     0,   338,     0,     0,     0,
       0,   345,     0,     0,   349,   416,     0,   598,   596,   210,
       0,     0,   511,     0,     0,   543,     0,   511,     0,   507,
      10,     0,     0,     0,     0,     0,   641,     0,     0,     0,
       0,     0,   645,     0,   652,   323,   321,   322,   315,   316,
     317,   309,     0,   304,   302,   682,   673,   679,     0,     0,
     752,   753,   763,   762,   761,     0,     0,     0,     0,   754,
     659,   760,     0,   657,   661,     0,     0,   666,   670,     0,
     691,   686,   689,   685,     0,     0,   573,     0,   570,   620,
     564,   739,     0,     0,   737,   744,   745,   741,     0,   736,
       0,   734,     0,     0,     0,     0,     0,   159,     0,   552,
     268,     0,   277,     0,     0,   273,     0,   276,   289,   297,
     298,   292,   249,     0,     0,     0,    62,   287,   558,     0,
       0,   335,   339,   333,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   554,     0,     0,   511,     0,
     538,     0,   511,   625,   626,   630,   631,   637,   639,     0,
       0,     0,     0,     0,   646,     0,   318,   305,   677,   764,
       0,     0,   756,     0,   702,   701,   700,   699,   698,   663,
       0,   755,     0,   617,     0,     0,   748,   747,   746,     0,
     740,   733,   731,     0,   728,   729,   723,   164,   166,   168,
       0,     0,     0,     0,     0,   272,   270,     0,   278,     0,
     219,   352,    68,   330,   336,     0,   350,   346,     0,     0,
       0,   340,     0,     0,   342,     0,   521,   515,   510,     0,
     511,   502,     0,     0,     0,     0,     0,     0,     0,   758,
     757,     0,     0,   618,   574,     0,   742,   735,     0,     0,
     170,   169,     0,     0,     0,     0,   165,   274,     0,     0,
       0,     0,     0,     0,   529,   523,     0,   522,   524,   530,
     527,   517,     0,   516,   518,   528,   504,     0,   503,     0,
     650,     0,     0,   224,   759,   671,   619,   730,   167,   171,
       0,     0,     0,     0,   296,     0,     0,   343,   341,     0,
       0,   514,   525,   526,   513,   519,   520,   505,     0,     0,
       0,     0,   172,     0,     0,     0,   351,   347,     0,     0,
       0,     0,   647,     0,     0,     0,     0,     0,     0,     0,
       0,   225,     0,   174,     0,     0,     0,     0,   173,     0,
       0,   648,     0,     0,     0,   226,     0,     0,     0,   649,
       0,     0,     0,     0,   175
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1567, -1567,  -221,  1157, -1567,  1148,  1149, -1567,  1155,  -520,
   -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567,
    -956, -1567, -1567, -1567, -1567,  -210,  -554, -1567,   702,  -722,
   -1567, -1567, -1567, -1567, -1567,   280,   493, -1567, -1567, -1567,
     977, -1567, -1567,   983, -1567, -1567,  -620, -1567,   421, -1567,
     981, -1567,   242,  -899, -1567,  -209,  -255, -1567,  -543, -1567,
       9,    39,    23,  -223,  -175, -1567,  -827, -1567, -1567,    41,
   -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567,
     587,   -98,  1296,     0, -1567, -1567, -1567, -1567,   435, -1567,
   -1567,  -280, -1567,     6, -1567, -1567,   241,  -706,  -703, -1567,
   -1567,   659, -1567, -1567,    22,   225, -1567, -1567, -1567,   116,
   -1567, -1567,   358,   123, -1567, -1567,   127, -1243, -1567,   893,
     213, -1567, -1567,   209,  -968, -1567, -1567,   207, -1567, -1567,
   -1188, -1167, -1567,   203, -1567, -1567,   821,   813, -1567,  -539,
   -1567, -1567,  -635,   307,  -617,   306,   308, -1567, -1567, -1567,
   -1567, -1567,  1115, -1567, -1567, -1567, -1567,  -812,  -305, -1125,
   -1567,   -90, -1567, -1567, -1567, -1567, -1567, -1567, -1567,   -34,
    -760, -1567, -1567,   521,   230, -1567,  -656, -1567, -1567, -1567,
   -1567, -1567, -1567, -1567,   763, -1567,  -961, -1567,   192, -1567,
     646,  -771, -1567, -1567, -1567, -1567, -1567,  -245,  -238, -1178,
   -1480, -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567,
   -1567,   569,  -745,  -768,   287,  -841, -1567,    84,  -793, -1567,
   -1567, -1567, -1567, -1567, -1567, -1567,  1011,  1013,  -339,   485,
     324, -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567,
   -1567, -1567, -1567, -1567, -1567,   173, -1567, -1567,   165, -1566,
     167, -1017, -1567, -1567, -1567,   136,   126,   -33,   380, -1567,
   -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567, -1567,
   -1567, -1567,   137, -1567, -1567, -1567,   -28,   374,   517, -1567,
   -1567, -1567, -1567, -1567,   317, -1567, -1567, -1437, -1567, -1567,
   -1567,  -545, -1567,   102, -1567,   -42, -1567, -1567, -1567, -1567,
   -1242, -1567,   147, -1567,  -376,  -365,  1311,    69, -1567
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   240,   825,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
    1202,   750,   258,   259,   260,   261,   262,   263,   904,   905,
     906,   264,   265,   266,   910,   911,   912,   267,   424,   425,
     426,   887,   268,   427,   428,   429,   444,   740,   741,   430,
     431,   269,  1152,   943,   270,  1607,  1608,   271,   272,   273,
     535,   274,   275,   276,   277,   278,   743,   279,   280,   518,
     281,   282,   283,   284,   285,   286,   607,   287,   288,   820,
     821,   289,   290,   545,   292,   608,   442,   973,   974,   293,
     609,   294,   611,   546,   296,   733,   734,  1190,   451,   297,
     452,   453,   737,  1191,  1192,  1193,   612,   613,  1068,  1069,
    1463,   614,  1065,  1066,  1295,  1296,  1297,  1298,   298,   762,
     763,   299,  1217,  1218,  1411,   300,  1220,  1221,   301,   302,
    1223,  1224,  1225,  1226,   303,   304,   305,   306,   853,   307,
    1307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   632,   633,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   659,   660,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   881,   347,   348,   349,  1252,   791,
     792,   793,  1638,  1682,  1683,  1676,  1677,  1684,  1678,  1253,
    1254,   350,   351,  1255,   352,   353,   354,   355,   356,   357,
     358,  1100,   968,  1090,  1344,  1091,  1497,  1092,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   769,  1167,
     369,   370,   371,   372,  1094,  1095,  1096,  1097,   373,   374,
     375,   376,   377,   378,   809,   810,   379,  1280,  1281,  1574,
    1053,  1076,  1317,  1318,  1077,  1078,  1079,  1080,  1081,  1327,
    1487,  1488,  1082,  1330,  1083,  1468,  1084,  1085,  1335,  1336,
    1493,  1491,  1319,  1320,  1321,  1322,  1587,   700,   931,   932,
     933,   934,   935,   936,  1142,  1513,  1604,  1143,  1511,  1602,
     937,  1357,  1508,  1504,  1505,  1506,   938,   939,  1323,  1331,
    1478,  1324,  1474,  1308,   380,   551,   381,   382,   383
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int xquery_parser::yytable_ninf_ = -766;
  const short int
  xquery_parser::yytable_[] =
  {
       291,   579,   860,   291,   291,   291,   295,   988,   544,   295,
     295,   295,   388,   391,   392,   610,   888,   654,   673,  1000,
    1022,   861,   862,   863,   864,   590,   390,   390,   390,   966,
    1207,  1364,   967,  1014,  1219,   587,   513,   834,   836,   559,
     592,   693,   389,   389,   389,  1074,   829,   832,   835,   837,
    1162,  1431,   593,  1459,  1460,  1303,  1421,   970,   393,  1052,
     891,   962,  1179,  1251,  1115,   588,  1119,   717,  1610,   827,
     830,   747,   751,   561,  1439,  1605,  1093,  1093,   849,   398,
     850,   851,   588,   852,  1176,   854,   588,  1489,   399,  1029,
     759,   588,   588,   855,   856,  1636,  1209,   588,   588,   886,
     722,  1550,  1099,  1145,   738,   291,   401,   463,  1146,   722,
     402,   295,   394,   395,  1093,   396,   397,  1386,   723,   963,
    1475,   964,   964,   595,  1147,   597,  1148,   723,   536,   597,
     795,   449,  1635,   400,  1502,  1149,   997,   472,  1580,   515,
     963,   403,   404,  1061,   389,  1354,   472,  1040,  1153,   682,
     963,   597,  1412,   515,  1732,  1133,  1679,  1685,  1470,   941,
     957,  1150,   678,  1161,  1292,   464,  1134,   593,  1122,  1551,
    1093,   965,  1180,   739,  1611,   644,   515,   594,   679,    76,
    1751,   683,  1117,  1093,  1637,  1294,  1309,  1286,   515,   645,
     515,  1759,   999,    87,  1117,  1173,  1471,  1679,  1503,   407,
    1551,  1075,  1183,  1685,  1356,   788,   596,  1104,  1196,   599,
     450,  1030,  1031,  1581,   600,  1576,   971,   998,   101,   601,
     748,  1697,  1071,  1033,  1184,  1072,  1032,   450,   956,   997,
    1195,   408,   465,   466,   406,   655,  1309,   602,  1413,   291,
     958,   724,   291,   450,  1518,   295,   121,  1339,   295,  1241,
    1402,   589,  1415,  1360,   972,   562,  1439,  1612,  1310,   410,
    1074,  1074,  1181,  1177,  1421,  1182,   610,   749,   591,  1603,
     834,   836,   822,  1116,  1041,   291,   746,   824,  1058,  1476,
    1477,   295,  1251,  1060,  1285,  1210,   450,  1151,  1467,  1349,
    1244,  1251,   594,   409,   796,  1093,   661,   450,   450,   663,
     942,   882,   827,   830,   942,   959,   886,  1680,  1310,  1412,
    1016,  1412,  1023,   593,  1070,   917,   653,   412,   413,   414,
     415,   416,   393,   417,   418,   419,   420,   421,  1073,  1305,
     977,   597,   422,   423,   603,   411,   597,   604,  1242,   727,
     121,  1311,  1312,   398,  1313,  1034,  1035,   744,   597,   642,
     597,  1314,   605,   121,   688,   597,   756,   689,   643,   597,
    1036,  1315,   597,   767,   768,   823,  1660,   597,  1153,  1009,
     401,  1011,   774,  1316,   985,   597,   597,   606,  1024,   828,
     831,   981,   844,  1644,   984,   960,    76,  1027,   690,  1609,
     291,  1311,  1312,   963,  1313,  1540,   295,  1545,   964,   515,
      87,  1247,   515,  1248,  1243,  1093,   711,   964,   992,  1244,
     978,  1315,  1681,  1008,   691,  1367,  1075,  1075,  1699,  1105,
    1674,   656,   657,  1316,  1244,   101,  1680,  1025,   980,  1093,
    1397,  1249,  1026,   291,   688,   291,  1051,   689,   594,   295,
     987,   295,  1002,   635,   721,   635,  1028,  1003,  1378,  1010,
     794,  1012,  1347,  1103,  1418,  1044,   719,  1523,   390,   291,
    -765,   636,   798,   636,   291,   295,  1379,   680,   515,  1517,
     295,   515,   718,  1251,   389,   515,   692,  1421,  1387,   816,
     818,   515,   719,  1105,   920,   597,   921,   719,   515,  1609,
    1108,  1157,   597,  1074,   691,  1114,   593,   597,   765,  1106,
    1158,   515,  1074,   771,   834,   836,   834,   515,  1674,   432,
     515,   742,  1244,  1074,  1139,  1287,  1288,  1289,   515,  1052,
    1247,   435,  1248,  1454,   515,   515,   515,   515,   922,   963,
    1140,  1715,   515,   886,  1609,  1247,   291,  1248,  1123,  1124,
     515,   291,   295,  1127,  1093,  1675,   433,   295,   597,   434,
    1249,   597,  1244,  1245,  1584,   874,   692,   597,   597,   597,
     877,  1585,  1465,  1107,   390,  1249,   875,   876,   597,  1496,
    1109,  1586,  1237,  1141,  1135,  1164,  1013,  1238,   291,  1622,
     389,   564,  1594,   565,   295,  1136,   515,  1599,  1647,   291,
     291,   291,   291,   436,   593,   295,   295,   295,   295,   584,
     515,   817,  1415,  1719,  1733,   291,  1203,  1059,  1745,   515,
    1203,   295,  1055,    76,   812,   638,   585,  1748,  1166,  1749,
    1169,   594,   443,  1247,  1348,  1248,  1093,    87,  1239,  1093,
    1056,  1569,   599,  1712,  1690,  1695,   838,   600,  1764,  1570,
     742,   515,   601,  1246,   639,   697,   698,   585,  1571,  1075,
     439,  1549,   101,  1249,  1553,   440,  1071,   640,  1075,  1072,
     602,  1557,  1595,  1247,  1341,  1248,  1561,  1600,  1648,  1075,
    1231,   570,  1232,  1074,  1354,   658,   571,   664,  1524,   923,
     121,  1482,   907,  1720,  1734,  1017,  1018,  1019,  1746,   818,
    1355,   641,   924,  1249,   925,  1110,  1342,   107,  1277,  1572,
     441,  1282,  1573,  1244,  1245,   926,   927,   928,  1472,   929,
     458,   930,  1111,  1343,   119,  1473,  1186,  1186,   599,   291,
    1112,  1187,  1187,   600,   908,   295,   635,   635,   601,   909,
     469,   834,   446,  1356,  1250,   515,   674,  1113,   709,   963,
    1188,   447,   291,   710,   636,   636,   602,  1139,   295,   675,
    1292,   979,   145,   893,  1283,  1283,   515,   603,   964,   964,
     604,   470,   445,  1140,   471,   390,   637,  1651,   448,   654,
     610,   437,   291,   291,   438,   789,   676,   515,   295,   295,
    1189,   389,  1291,   515,   515,  1244,  1245,  1639,   456,   677,
    1216,  1642,  1292,  1216,  1246,   719,   719,  1332,  1333,  1093,
     606,  1093,  1293,  1409,   457,   515,  1414,   515,   461,  1244,
    1245,  1006,  1007,  1294,  1247,   515,  1248,  1049,   515,   462,
    1334,  1273,   515,  1050,  1653,  1400,  1654,  1419,  1584,  1075,
    1203,   467,  1093,   908,  1422,  1585,  1419,  1419,   909,   468,
    1420,  1582,  1583,   603,  1249,  1586,   604,  1423,   107,  1556,
    1689,  1186,  1579,   662,  1125,  1126,  1187,  1669,   665,   515,
     454,  1278,  1093,   455,  1661,   119,   567,   459,   568,  1687,
     460,   706,   707,   579,   407,   516,  1246,  1093,  1284,  1093,
     393,   517,  1257,   519,  1258,  1433,   606,  1696,   515,   878,
     394,   395,   878,   396,   397,   878,  1247,  1262,  1248,  1263,
    1246,   398,  1706,   145,  1709,   520,   408,  1154,  1155,   515,
     399,   400,  1128,  1129,  1130,   532,  1455,   531,  1131,   548,
    1247,   560,  1248,   694,   695,   696,  1249,   533,   401,   573,
     107,   549,   402,   556,   410,  1456,  1457,   557,   515,   515,
     515,   515,   858,   859,   558,  1649,  1650,   119,   865,   866,
    1249,   566,   867,   868,   107,  1101,  1101,  1596,  1597,   563,
     572,   574,   569,   403,   404,   405,   575,  1438,   577,   578,
     576,   119,   581,  1302,   597,   598,   515,  1398,   616,   634,
     615,   646,   648,   647,   649,   145,   658,   666,   667,   668,
     515,  1559,   714,   413,   414,   415,   416,   672,   417,   418,
     715,   420,   421,   669,   291,   670,   472,   422,   671,   145,
     295,   684,   406,   686,   687,   699,  1694,   515,   720,   704,
     705,   407,   702,   708,   731,  1536,   515,   719,   515,   732,
     736,   742,   515,   894,   895,   896,   897,   898,   899,   900,
     901,   902,   903,  1227,  1049,   515,   745,   754,   753,   755,
    1050,   766,   772,   408,   773,   844,   434,   779,   291,   291,
     291,   781,   438,   455,   295,   295,   295,   460,   790,   471,
     783,   409,   784,   785,   787,   797,   799,   800,   515,   803,
     515,   410,   819,   808,   813,   814,  1577,   826,   840,   842,
     841,   857,   869,   843,   870,   871,   872,   883,   889,   890,
     892,   914,   918,   915,   919,   940,   946,   944,   948,   951,
     952,   953,   954,   411,   961,   955,   976,   982,   983,   986,
     993,   994,   995,   996,  1001,  1037,  1004,  1038,  1005,  1042,
    1057,  1063,  1039,  1067,  1118,  1043,   515,   909,   963,   412,
     413,   414,   415,   416,  1137,   417,   418,   419,   420,   421,
    1156,  1138,  1171,  1163,   422,   423,  1165,   515,  1172,  1203,
    1178,  1198,  1174,  1185,   738,   291,  1199,  1201,  1200,  1204,
    1205,   295,  1206,  1212,  1371,  1215,  1448,  1449,  1450,  1211,
    1216,  1228,  1222,  1234,  1235,  1240,  1230,  1256,   390,  1229,
    1542,  1270,  1274,  1275,  1279,  1276,   690,  1299,  1277,  1301,
     291,  1345,   886,  1306,   389,  1325,   295,  1337,  1338,  1340,
    1326,   291,  1353,  1329,  1358,   942,  1366,   295,  1352,  1362,
    1405,  1374,  1363,  1382,  1365,  1384,  1388,  1372,  1391,  1392,
     291,  1390,  1369,  1396,   390,  1401,   295,  1373,  1370,  1426,
     515,  1375,  1404,   515,  1425,  1376,  1427,  1419,  1428,   291,
     389,  1432,  1435,   390,  1440,   295,  1441,  1442,   515,  1430,
    1447,  1443,  1453,  1445,  1292,  1462,  1469,   515,  1479,   389,
    1466,   617,   719,  1485,  1490,  1492,  1498,  1049,  1049,   618,
     619,   515,   620,  1050,  1050,  1501,  1486,  1507,  1436,  1499,
     621,   515,  1500,  1512,   622,  1444,   623,  1514,  1521,  1519,
     817,   624,  1533,  1526,  1534,  1535,  1538,  1539,  1555,  1544,
    1620,  1547,  1592,  1590,  1560,  1554,  1578,  1601,   625,   515,
    1510,  1624,  1542,  1593,  1626,  1516,  1139,  1606,  1617,  1619,
    1625,  1634,  1614,  1641,  1629,  1643,  1633,  1646,  1655,   515,
    1656,   626,   627,   628,   629,   630,   631,  1591,   515,  1663,
    1657,  1658,   515,  1659,  1668,  1664,  1613,  1670,  1672,  1671,
    1686,  1688,  1711,  1692,  1717,  1702,  1703,  1718,  1725,  1705,
    1700,  1710,  1714,  1728,  1729,  1572,  1723,  1731,  1738,  1735,
    1752,   514,  1740,  1736,  1750,  1757,  1756,  1760,  1753,  1761,
     582,   583,   916,  1742,  1744,   530,   580,  1763,  1197,  1351,
     586,  1120,   712,  1368,  1698,  1666,   515,  1054,   713,  1194,
    1626,   716,  1377,   291,   991,  1395,  1531,  1464,   547,   295,
    1398,  1290,  1461,  1458,   780,  1406,  1410,  1416,  1424,   848,
     552,   885,   555,   652,   515,  1434,   847,  1021,  1716,  1713,
    1361,  1102,  1350,  1446,  1170,  1452,  1451,   725,  1707,   726,
    1480,  1484,  1589,  1304,  1588,  1483,  1328,  1144,  1359,  1509,
     515,   515,  1481,  1598,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1693,  1645,     0,     0,     0,     0,     0,
       0,     0,  1726,     0,     0,     0,   515,     0,   515,     0,
       0,   515,  1652,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   515,     0,     0,     0,  1726,   515,     0,     0,
       0,     0,     0,     0,     0,  1707,     0,     0,     0,     0,
       0,     0,   515,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1049,     0,     0,     0,     0,     0,  1050,
       0,     0,     0,     0,  1049,  1049,     0,   291,     0,     0,
    1050,  1050,     0,   295,  1049,     0,     0,     0,     0,  1741,
    1050,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1755,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   515,     0,   515,
       0,   515,     0,     0,     0,     0,     0,     0,   515,     0,
       0,     0,     0,  1049,     0,     0,     0,     0,     0,  1050,
       0,   514,     0,  1049,   514,     0,     0,     0,     0,  1050,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   515,     0,   515,     0,     0,     0,     0,     0,     0,
       0,   291,     0,     0,     0,     0,     0,   295,     0,   515,
       0,     0,   515,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   515,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   515,   291,     0,     0,     0,     0,
     681,   295,     0,   685,     0,   515,     0,   552,     0,     0,
       0,     0,     0,   701,   515,     0,     0,     0,     0,  1049,
     703,     0,   515,     0,     0,  1050,     0,   515,  1049,   515,
       0,   515,     0,   552,  1050,     0,     0,     0,     0,   730,
       0,     0,   735,     0,     0,     0,     0,     0,     0,     0,
     752,   515,     0,     0,     0,     0,   552,   760,   761,   764,
       0,   515,     0,     0,   770,     0,     0,     0,     0,     0,
       0,     0,   777,     0,     0,     0,     0,   515,     0,     0,
       0,     0,     0,     0,   515,     0,     0,     0,     0,     0,
     515,     0,     0,     0,     0,     0,     0,     0,     0,   515,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   515,
       0,     0,     0,     0,     0,   515,     0,     0,   778,     0,
     515,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   764,     0,     0,     0,     0,     0,     0,     0,
       0,   786,     0,     0,     0,     0,     0,     0,     0,     0,
     801,   802,     0,   804,   805,   806,   807,     0,     0,     0,
       0,     0,   815,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   811,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   839,     0,     0,     0,     0,     0,     0,
       0,   845,   846,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     880,     0,     0,     0,   880,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   552,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   913,     0,
       0,     0,     0,     0,     0,     0,   947,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   945,
       0,     0,     0,     0,     0,   949,   950,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   969,     0,   975,
     990,     0,     0,     0,     0,     0,     0,   552,     0,     0,
     552,     0,     0,     0,   989,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1015,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   845,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1020,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     514,     0,     0,     0,     0,     0,     0,     0,  1064,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1062,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1098,  1098,  1098,  1098,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1121,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1098,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1132,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1159,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1160,
       0,  1175,     0,     0,     0,     0,     0,     0,  1168,     0,
    1168,     0,     0,     0,  1098,     0,     0,     0,     0,     0,
       0,     0,     0,  1208,     0,     0,     0,  1098,     0,     0,
       0,     0,     0,     0,  1213,  1214,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1233,
       0,     0,  1236,     0,     0,     0,     0,     0,     0,     0,
     770,     0,   770,     0,     0,     0,  1259,  1260,  1261,     0,
    1264,  1265,  1266,  1267,  1268,  1269,     0,  1271,  1272,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1064,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1300,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1098,
       0,  1346,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1381,     0,  1383,     0,  1385,     0,     0,  1389,
       0,     0,   735,     0,  1393,  1380,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1399,     0,     0,     0,
    1394,     0,     0,     0,     0,  1403,     0,     0,     0,  1098,
       0,  1407,  1408,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   764,     0,     0,     0,     0,     0,     0,
    1429,     0,     0,  1098,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1437,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   811,     0,     0,     0,     0,     0,     0,     0,     0,
     514,     0,     0,     0,   514,  1064,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1098,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1520,     0,  1515,     0,  1522,     0,
       0,     0,  1525,     0,  1527,     0,  1528,     0,     0,     0,
       0,     0,  1532,     0,     0,     0,     0,     0,     0,     0,
    1537,     0,  1529,  1530,     0,     0,     0,     0,  1541,  1543,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1399,     0,  1546,     0,
    1098,     0,     0,  1098,     0,     0,     0,  1563,  1564,  1565,
    1566,  1567,     0,  1568,  1558,     0,     0,     0,     0,  1562,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1575,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1615,     0,  1616,
       0,     0,  1618,     0,     0,     0,     0,     0,     0,     0,
    1621,     0,     0,     0,     0,  1623,  1543,     0,     0,     0,
       0,     0,     0,  1627,     0,     0,     0,  1631,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1628,
       0,  1630,     0,  1632,     0,     0,     0,     0,     0,     0,
    1640,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1098,     0,  1098,     0,     0,     0,     0,
       0,     0,     0,  1667,     0,     0,     0,     0,     0,     0,
       0,  1662,     0,     0,  1665,  1627,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1098,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1673,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1691,     0,     0,
       0,     0,     0,     0,     0,     0,  1098,  1708,     0,     0,
       0,     0,     0,     0,  1701,     0,     0,     0,     0,  1704,
       0,  1098,     0,  1098,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1722,     0,     0,     0,
       0,  1727,     0,  1721,     0,     0,  1708,     0,     0,     0,
       0,     0,     0,  1724,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1727,     0,     0,     0,     0,  1730,
       0,     0,  1743,     0,     0,     0,  1737,     0,     0,     0,
       0,     0,  1739,     0,     0,     0,     0,     0,     0,     0,
       0,  1747,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1754,     0,     0,     0,     1,     0,  1758,     0,     0,
       0,     0,  1762,     2,     3,     4,     5,     6,     7,     0,
       0,     8,     0,     0,     0,     9,    10,     0,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,     0,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,     0,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,     0,    66,    67,    68,    69,
      70,    71,    72,    73,     0,     0,    74,    75,     0,     0,
       0,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,     0,     0,     0,    87,     0,    88,    89,    90,
      91,     0,    92,     0,     0,     0,    93,    94,    95,    96,
      97,     0,     0,     0,     0,     0,     0,    98,    99,   100,
     101,   102,   103,   104,   105,     0,     0,   106,   107,   108,
     109,   110,     0,     0,     0,     0,   111,   112,   113,   114,
     115,   116,   117,   118,     0,   119,     0,   120,   121,     0,
       0,   122,   123,   124,     0,     0,     0,   125,     0,   126,
     127,     0,   128,   129,   130,     0,   131,     0,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,     0,
       0,   143,   144,   145,     0,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,     0,
     190,   191,   192,     0,   193,   194,   195,   196,   197,   198,
       0,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,     1,     0,     0,     0,     0,     0,     0,     0,
       2,     3,     4,     5,     6,     7,     0,     0,     8,     0,
       0,     0,   384,   385,     0,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,   386,
      26,    27,    28,    29,     0,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,     0,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,     0,    66,    67,    68,    69,    70,    71,    72,
      73,     0,     0,    74,    75,     0,     0,     0,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,     0,
       0,     0,    87,     0,    88,    89,    90,    91,     0,    92,
       0,     0,     0,    93,    94,    95,    96,    97,     0,     0,
       0,     0,     0,     0,    98,    99,   100,   101,   102,   103,
     104,   105,     0,     0,   106,   107,   108,   109,   110,     0,
       0,     0,     0,   111,   112,   113,   114,   115,   116,   117,
     118,     0,   119,     0,   120,   121,     0,     0,   122,   123,
     124,     0,   534,     0,   125,     0,   126,   127,     0,   128,
     129,   130,     0,   131,     0,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,     0,     0,   143,   144,
     145,     0,   387,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,   192,
       0,   193,   194,   195,   196,   197,   198,     0,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,     1,     0,
       0,     0,     0,     0,     0,     0,     2,     3,     4,     5,
       6,     7,     0,     0,     8,     0,     0,     0,   384,   385,
       0,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,   537,   386,    26,    27,    28,    29,
       0,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,     0,    43,    44,    45,   538,   539,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,     0,    66,
      67,    68,    69,    70,    71,    72,    73,     0,     0,    74,
      75,     0,     0,     0,    76,    77,   490,    79,    80,    81,
      82,    83,   540,    85,    86,     0,     0,     0,    87,     0,
      88,    89,    90,    91,     0,    92,     0,     0,     0,    93,
      94,    95,    96,    97,     0,     0,     0,     0,     0,     0,
      98,    99,   100,   101,   102,   103,   104,   541,     0,     0,
     106,   107,   108,   109,   110,     0,     0,     0,     0,   111,
     112,   113,   114,   115,   116,   117,   118,     0,   119,     0,
     120,   121,     0,     0,   122,   123,   124,     0,     0,     0,
     125,   542,   126,   127,     0,   128,   129,   130,     0,   131,
       0,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,     0,     0,   143,   144,   145,     0,   387,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   507,   508,   509,   510,   173,   174,   511,   543,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,     0,   190,   191,   192,     0,   193,   194,   195,
     196,   197,   198,     0,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,     1,     0,     0,     0,     0,     0,
       0,     0,     2,     3,     4,     5,     6,     7,     0,     0,
       8,     0,     0,     0,   384,   385,     0,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,   386,    26,    27,    28,    29,     0,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
       0,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,     0,    66,    67,    68,    69,    70,
      71,    72,    73,     0,     0,    74,    75,     0,     0,     0,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,     0,     0,     0,    87,     0,    88,    89,    90,    91,
       0,    92,     0,     0,     0,    93,    94,    95,    96,    97,
       0,     0,     0,     0,     0,     0,    98,    99,   100,   101,
     102,   103,   104,   105,     0,     0,   106,   107,   108,   109,
     110,     0,     0,     0,     0,   111,   112,   113,   114,   115,
     116,   117,   118,     0,   119,     0,   120,   121,     0,     0,
     122,   123,   124,     0,   782,     0,   125,     0,   126,   127,
       0,   128,   129,   130,     0,   131,     0,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,     0,     0,
     143,   144,   145,     0,   387,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,   190,
     191,   192,     0,   193,   194,   195,   196,   197,   198,     0,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
       1,     0,     0,     0,     0,     0,     0,     0,     2,     3,
       4,     5,     6,     7,     0,     0,     8,     0,     0,     0,
     384,   385,     0,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,   537,   386,    26,    27,
      28,    29,     0,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,     0,    43,    44,    45,
     538,   539,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
       0,    66,    67,    68,    69,    70,    71,    72,    73,     0,
       0,    74,    75,     0,     0,     0,    76,    77,   490,    79,
      80,    81,    82,    83,   540,    85,    86,     0,     0,     0,
      87,     0,    88,    89,    90,    91,     0,    92,     0,     0,
       0,    93,    94,    95,    96,    97,     0,     0,     0,     0,
       0,     0,    98,    99,   100,   101,   102,   103,   104,   541,
       0,     0,   106,   107,   108,   109,   110,     0,     0,     0,
       0,   111,   112,   113,   114,   115,   116,   117,   118,     0,
     119,     0,   120,   121,     0,     0,   122,   123,   124,     0,
     873,     0,   125,     0,   126,   127,     0,   128,   129,   130,
       0,   131,     0,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,     0,     0,   143,   144,   145,     0,
     387,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   507,   508,   509,   510,   173,   174,   511,
     543,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,   192,     0,   193,
     194,   195,   196,   197,   198,     0,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,     1,     0,     0,     0,
       0,     0,     0,     0,     2,     3,     4,     5,     6,     7,
       0,     0,     8,     0,     0,     0,   384,   385,     0,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,   537,   386,    26,    27,    28,    29,     0,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,     0,    43,    44,    45,   538,   539,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,     0,    66,    67,    68,
      69,    70,    71,    72,    73,     0,     0,    74,    75,     0,
       0,     0,    76,    77,   490,    79,    80,    81,    82,    83,
     540,    85,    86,     0,     0,     0,    87,     0,    88,    89,
      90,    91,     0,    92,     0,     0,     0,    93,    94,    95,
      96,    97,     0,     0,     0,     0,     0,     0,    98,    99,
     100,   101,   102,   103,   104,   541,     0,     0,   106,   107,
     108,   109,   110,     0,     0,     0,     0,   111,   112,   113,
     114,   115,   116,   117,   118,     0,   119,     0,   120,   121,
       0,     0,   122,   123,   124,     0,     0,     0,   125,   879,
     126,   127,     0,   128,   129,   130,     0,   131,     0,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
       0,     0,   143,   144,   145,     0,   387,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   507,
     508,   509,   510,   173,   174,   511,   543,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,   192,     0,   193,   194,   195,   196,   197,
     198,     0,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,     1,     0,     0,     0,     0,     0,     0,     0,
       2,     3,     4,     5,     6,     7,     0,     0,     8,     0,
       0,     0,   384,   385,     0,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,   537,   386,
      26,    27,    28,    29,     0,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,     0,    43,
      44,    45,   538,   539,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,     0,    66,    67,    68,    69,    70,    71,    72,
      73,     0,     0,    74,    75,     0,     0,     0,    76,    77,
     490,    79,    80,    81,    82,    83,   540,    85,    86,     0,
       0,     0,    87,     0,    88,    89,    90,    91,     0,    92,
       0,     0,     0,    93,    94,    95,    96,    97,     0,     0,
       0,     0,     0,     0,    98,    99,   100,   101,   102,   103,
     104,   541,     0,     0,   106,   107,   108,   109,   110,     0,
       0,     0,     0,   111,   112,   113,   114,   115,   116,   117,
     118,     0,   119,     0,   120,   121,     0,     0,   122,   123,
     124,     0,     0,     0,   125,   884,   126,   127,     0,   128,
     129,   130,     0,   131,     0,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,     0,     0,   143,   144,
     145,     0,   387,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   507,   508,   509,   510,   173,
     174,   511,   543,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,   192,
       0,   193,   194,   195,   196,   197,   198,     0,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,     1,     0,
       0,     0,     0,     0,     0,     0,     2,     3,     4,     5,
       6,     7,     0,     0,     8,     0,     0,     0,   384,   385,
       0,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,  1045,   386,    26,    27,    28,    29,
       0,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,     0,    43,    44,    45,  1046,  1047,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,     0,    66,
      67,    68,    69,    70,    71,    72,    73,     0,     0,    74,
      75,     0,     0,     0,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,     0,     0,     0,    87,     0,
      88,    89,    90,    91,     0,    92,     0,     0,     0,    93,
      94,    95,    96,    97,     0,     0,     0,     0,     0,     0,
      98,    99,   100,   101,   102,   103,   104,   105,     0,     0,
     106,   107,   108,   109,   110,     0,     0,     0,     0,   111,
     112,   113,   114,   115,   116,   117,   118,     0,   119,     0,
     120,   121,     0,     0,   122,   123,   124,     0,   782,     0,
     125,     0,   126,   127,     0,   128,   129,   130,     0,   131,
       0,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,     0,     0,   143,   144,   145,     0,   387,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,  1048,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,     0,   190,   191,   192,     0,   193,   194,   195,
     196,   197,   198,     0,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,     1,     0,     0,     0,     0,     0,
       0,     0,     2,     3,     4,     5,     6,     7,     0,     0,
       8,     0,     0,     0,   384,   385,     0,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
    1045,   386,    26,    27,    28,    29,     0,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
       0,    43,    44,    45,  1046,  1047,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,     0,    66,    67,    68,    69,    70,
      71,    72,    73,     0,     0,    74,    75,     0,     0,     0,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,     0,     0,     0,    87,     0,    88,    89,    90,    91,
       0,    92,     0,     0,     0,    93,    94,    95,    96,    97,
       0,     0,     0,     0,     0,     0,    98,    99,   100,   101,
     102,   103,   104,   105,     0,     0,   106,   107,   108,   109,
     110,     0,     0,     0,     0,   111,   112,   113,   114,   115,
     116,   117,   118,     0,   119,     0,   120,   121,     0,     0,
     122,   123,   124,     0,   534,     0,   125,     0,   126,   127,
       0,   128,   129,   130,     0,   131,     0,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,     0,     0,
     143,   144,   145,     0,   387,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,  1048,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,   190,
     191,   192,     0,   193,   194,   195,   196,   197,   198,     0,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
       1,     0,     0,     0,     0,     0,     0,     0,     2,     3,
       4,     5,     6,     7,     0,     0,     8,     0,     0,     0,
     384,   385,     0,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,   386,    26,    27,
      28,    29,     0,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,     0,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
       0,    66,    67,    68,    69,    70,    71,    72,    73,     0,
       0,    74,    75,     0,     0,     0,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,     0,     0,     0,
      87,     0,    88,    89,    90,    91,     0,    92,     0,     0,
       0,    93,    94,    95,    96,    97,     0,     0,     0,     0,
       0,     0,    98,    99,   100,   101,   102,   103,   104,   105,
       0,     0,   106,   107,   108,   109,   110,     0,     0,     0,
       0,   111,   112,   113,   114,   115,   116,   117,   118,     0,
     119,     0,   120,   121,     0,     0,   122,   123,   124,     0,
       0,     0,   125,     0,   126,   127,     0,   128,   129,   130,
       0,   131,     0,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,     0,     0,   143,   144,   145,     0,
     387,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,   192,     0,   193,
     194,   195,   196,   197,   198,     0,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,     1,     0,     0,     0,
       0,     0,     0,     0,     2,     3,     4,     5,     6,     7,
       0,     0,     8,     0,     0,     0,     9,    10,     0,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,     0,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,     0,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,     0,    66,    67,    68,
      69,    70,    71,    72,    73,     0,     0,    74,    75,     0,
       0,     0,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,     0,     0,     0,    87,     0,    88,    89,
      90,    91,     0,    92,     0,     0,     0,    93,    94,    95,
      96,    97,     0,     0,     0,     0,     0,     0,    98,    99,
     100,   101,   102,   103,   104,   105,     0,     0,   106,   107,
     108,   109,   110,     0,     0,     0,     0,   111,   112,   113,
     114,   115,   116,   117,   118,     0,   119,     0,   120,   121,
       0,     0,   122,   123,   124,     0,     0,     0,   125,     0,
     126,   127,     0,   128,   129,   130,     0,   131,     0,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
       0,     0,   143,   144,   145,     0,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,   192,     0,   193,   194,   195,   196,   197,
     198,     0,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,     1,     0,     0,     0,     0,     0,     0,     0,
       2,     3,     4,     5,     6,     7,     0,     0,     8,     0,
       0,     0,     9,    10,     0,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,     0,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,     0,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,     0,    66,    67,    68,    69,    70,    71,    72,
      73,     0,     0,    74,    75,     0,     0,     0,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,     0,
       0,     0,    87,     0,    88,    89,    90,    91,     0,    92,
       0,     0,     0,    93,    94,    95,    96,    97,     0,     0,
       0,     0,     0,     0,    98,    99,   100,   101,   102,   103,
     104,   105,     0,     0,   106,   107,   108,   109,   110,     0,
       0,     0,     0,   111,   112,   113,   114,   115,   116,   117,
     118,     0,   119,     0,   120,   121,     0,     0,   122,   123,
     124,     0,     0,     0,   125,     0,   126,   127,     0,   128,
     129,   130,     0,   131,     0,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,     0,     0,   143,   144,
     145,     0,   387,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,   192,
       0,   193,   194,   195,   196,   197,   198,     0,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,     1,     0,
       0,     0,     0,     0,     0,     0,     2,     3,     4,     5,
       6,     7,     0,     0,     8,     0,     0,     0,   384,   385,
       0,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,   476,    23,   478,   386,    26,   479,    28,    29,
       0,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,   481,     0,    43,    44,    45,   483,   484,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,     0,    66,
      67,    68,    69,    70,    71,    72,    73,     0,     0,    74,
      75,     0,     0,     0,    76,    77,   490,    79,    80,    81,
      82,    83,   540,    85,    86,     0,     0,     0,    87,     0,
      88,    89,    90,    91,     0,    92,     0,     0,     0,   493,
      94,    95,    96,    97,     0,     0,     0,     0,     0,     0,
      98,    99,   100,   101,   102,   103,   104,   541,     0,     0,
     106,   107,   650,   109,   110,     0,     0,     0,     0,   111,
     112,   113,   114,   115,   116,   117,   118,     0,   119,     0,
     651,   121,     0,     0,   122,   123,   124,     0,     0,     0,
     125,     0,   126,   127,     0,   128,   129,   130,     0,   131,
       0,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,     0,     0,   143,   144,   145,     0,   387,   147,
     148,   149,   150,   151,   152,   153,   154,   502,   156,   503,
     158,   504,   505,   161,   162,   163,   164,   165,   166,   506,
     168,   507,   508,   509,   510,   173,   174,   511,   512,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,     0,   190,   191,   192,     0,   193,   194,   195,
     196,   197,   198,     0,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,     1,     0,     0,     0,     0,     0,
       0,     0,     2,     3,     4,     5,     6,     7,     0,     0,
       8,     0,     0,     0,   384,   385,     0,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
     537,   386,    26,    27,    28,    29,     0,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
       0,    43,    44,    45,   538,   539,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,     0,    66,    67,    68,    69,    70,
      71,    72,    73,     0,     0,    74,    75,     0,     0,     0,
      76,    77,   490,    79,    80,    81,    82,    83,   540,    85,
      86,     0,     0,     0,    87,     0,    88,    89,    90,    91,
       0,    92,     0,     0,     0,    93,    94,    95,    96,    97,
       0,     0,     0,     0,     0,     0,    98,    99,   100,   101,
     102,   103,   104,   541,     0,     0,   106,   107,   108,   109,
     110,     0,     0,     0,     0,   111,   112,   113,   114,   115,
     116,   117,   118,     0,   119,     0,   120,   121,     0,     0,
     122,   123,   124,     0,     0,     0,   125,     0,   126,   127,
       0,   128,   129,   130,     0,   131,     0,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,     0,     0,
     143,   144,   145,     0,   387,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   507,   508,   509,
     510,   173,   174,   511,   543,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,   190,
     191,   192,     0,   193,   194,   195,   196,   197,   198,     0,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
       1,     0,     0,     0,     0,     0,     0,     0,     2,     3,
       4,     5,     6,     7,     0,     0,     8,     0,     0,     0,
       9,   385,     0,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,     0,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,     0,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
       0,    66,    67,    68,    69,    70,    71,    72,    73,     0,
       0,    74,    75,     0,     0,     0,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,     0,     0,     0,
      87,     0,    88,    89,    90,    91,     0,    92,     0,     0,
       0,    93,    94,    95,    96,    97,     0,     0,     0,     0,
       0,     0,    98,    99,   100,   101,   102,   103,   104,   105,
       0,     0,   106,   107,   108,   109,   110,     0,     0,     0,
       0,   111,   112,   113,   114,   115,   116,   117,   118,     0,
     119,     0,   120,   121,     0,     0,   122,   123,   124,     0,
       0,     0,   125,     0,   126,   127,     0,   128,   129,   130,
       0,   131,     0,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,     0,     0,   143,   144,   145,     0,
     387,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,   192,     0,   193,
     194,   195,   196,   197,   198,     0,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,     1,     0,     0,     0,
       0,     0,     0,     0,     2,     3,     4,     5,     6,     7,
       0,     0,     8,     0,     0,     0,   833,   385,     0,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,   386,    26,    27,    28,    29,     0,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,     0,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,     0,    66,    67,    68,
      69,    70,    71,    72,    73,     0,     0,    74,    75,     0,
       0,     0,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,     0,     0,     0,    87,     0,    88,    89,
      90,    91,     0,    92,     0,     0,     0,    93,    94,    95,
      96,    97,     0,     0,     0,     0,     0,     0,    98,    99,
     100,   101,   102,   103,   104,   105,     0,     0,   106,   107,
     108,   109,   110,     0,     0,     0,     0,   111,   112,   113,
     114,   115,   116,   117,   118,     0,   119,     0,   120,   121,
       0,     0,   122,   123,   124,     0,     0,     0,   125,     0,
     126,   127,     0,   128,   129,   130,     0,   131,     0,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
       0,     0,   143,   144,   145,     0,   387,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,   192,     0,   193,   194,   195,   196,   197,
     198,     0,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,     1,     0,     0,     0,     0,     0,     0,     0,
       2,     3,     4,     5,     6,     7,     0,     0,     8,     0,
       0,     0,   384,   385,     0,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,   476,    23,   478,   386,
      26,   479,    28,    29,     0,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,   481,     0,    43,
      44,    45,   483,   484,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,     0,    66,    67,    68,    69,    70,    71,    72,
      73,     0,     0,    74,    75,     0,     0,     0,    76,    77,
     490,    79,    80,    81,    82,    83,   540,    85,    86,     0,
       0,     0,    87,     0,    88,    89,    90,    91,     0,    92,
       0,     0,     0,   493,    94,    95,    96,    97,     0,     0,
       0,     0,     0,     0,    98,    99,   100,   101,   102,   103,
     104,   541,     0,     0,   106,   107,   108,   109,   110,     0,
       0,     0,     0,   111,   112,   113,   114,   115,   116,   117,
     118,     0,   119,     0,   120,   121,     0,     0,   122,   123,
     124,     0,     0,     0,   125,     0,   126,   127,     0,   128,
     129,   130,     0,   131,     0,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,     0,     0,   143,   144,
     145,     0,   387,   147,   148,   149,   150,   151,   152,   153,
     154,   502,   156,   503,   158,   504,   505,   161,   162,   163,
     164,   165,   166,   506,   168,   507,   508,   509,   510,   173,
     174,   511,   512,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,   192,
       0,   193,   194,   195,   196,   197,   198,     0,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,     1,     0,
       0,     0,     0,     0,     0,     0,     2,     3,     4,     5,
       6,     7,     0,     0,     8,     0,     0,     0,   384,   385,
       0,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,  1045,   386,    26,    27,    28,    29,
       0,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,     0,    43,    44,    45,  1046,  1047,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,     0,    66,
      67,    68,    69,    70,    71,    72,    73,     0,     0,    74,
      75,     0,     0,     0,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,     0,     0,     0,    87,     0,
      88,    89,    90,    91,     0,    92,     0,     0,     0,    93,
      94,    95,    96,    97,     0,     0,     0,     0,     0,     0,
      98,    99,   100,   101,   102,   103,   104,   105,     0,     0,
     106,   107,   108,   109,   110,     0,     0,     0,     0,   111,
     112,   113,   114,   115,   116,   117,   118,     0,   119,     0,
     120,   121,     0,     0,   122,   123,   124,     0,     0,     0,
     125,     0,   126,   127,     0,   128,   129,   130,     0,   131,
       0,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,     0,     0,   143,   144,   145,     0,   387,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,  1048,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,     0,   190,   191,   192,     0,   193,   194,   195,
     196,   197,   198,     0,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,     1,     0,     0,     0,     0,     0,
       0,     0,     2,     3,     4,     5,     6,     7,     0,     0,
       8,     0,     0,     0,   384,   385,     0,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,   476,    23,
     478,   386,    26,   479,    28,    29,     0,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,   481,
       0,    43,    44,    45,   483,   484,    48,   485,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,     0,    66,    67,    68,    69,    70,
      71,    72,    73,     0,     0,    74,    75,     0,     0,     0,
      76,    77,   490,    79,    80,    81,    82,    83,   540,    85,
      86,     0,     0,     0,    87,     0,    88,    89,    90,    91,
       0,    92,     0,     0,     0,   493,    94,    95,    96,    97,
       0,     0,     0,     0,     0,     0,    98,    99,   100,   101,
     102,   103,   104,   541,     0,     0,   106,   107,     0,   109,
     110,     0,     0,     0,     0,   111,   112,   113,   114,   115,
     116,   117,   118,     0,   119,     0,     0,     0,     0,     0,
     122,   123,   124,     0,     0,     0,   125,     0,   126,   127,
       0,   128,   129,   130,     0,   131,     0,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,     0,     0,
     143,   144,   145,     0,   387,   147,   148,   149,   150,   151,
     152,   153,   154,   502,   156,   503,   158,   504,   505,   161,
     162,   163,   164,   165,   166,   506,   168,   507,   508,   509,
     510,   173,   174,   511,   512,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,   190,
     191,   192,     0,   193,   194,   195,   196,   197,   198,     0,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
       1,     0,     0,     0,     0,     0,     0,     0,     2,     3,
       4,     5,     6,     7,     0,     0,     8,     0,     0,     0,
     384,   385,     0,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,   476,    23,   478,   386,    26,   479,
      28,    29,     0,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,   481,     0,    43,    44,    45,
     483,   484,    48,   485,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
       0,    66,    67,    68,    69,    70,    71,    72,    73,     0,
       0,    74,    75,     0,     0,     0,    76,    77,   490,    79,
      80,    81,    82,    83,   540,    85,    86,     0,     0,     0,
      87,     0,    88,    89,    90,    91,     0,    92,     0,     0,
       0,   493,    94,    95,    96,    97,     0,     0,     0,     0,
       0,     0,    98,    99,   100,   101,   102,   103,   104,   541,
       0,     0,   106,   107,     0,   109,   110,     0,     0,     0,
       0,   111,   112,   113,   114,   115,   116,   117,   118,     0,
     119,     0,     0,     0,     0,     0,   122,   123,   124,     0,
       0,     0,   125,     0,   126,   127,     0,     0,     0,   130,
       0,   131,     0,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,     0,     0,   143,   144,   145,     0,
     387,   147,   148,   149,   150,   151,   152,   153,   154,   502,
     156,   503,   158,   504,   505,   161,   162,   163,   164,   165,
     166,   506,   168,   507,   508,   509,   510,   173,   174,   511,
     512,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,   192,     0,   193,
     194,   195,   196,   197,   198,     0,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,     1,     0,     0,     0,
       0,     0,     0,     0,     2,     0,     0,     0,     6,     7,
       0,     0,   472,     0,     0,     0,   384,   385,     0,    11,
      12,    13,   473,    15,    16,    17,   474,    19,   475,    21,
     476,   477,   478,   386,    26,   479,    28,    29,     0,    30,
      31,    32,    33,   480,    35,    36,    37,    38,    39,    40,
      41,   481,     0,    43,   482,    45,   483,   484,    48,   485,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,   486,   487,    65,     0,    66,    67,    68,
     488,     0,    71,    72,    73,     0,     0,   489,    75,     0,
       0,     0,     0,    77,   490,    79,   491,   492,    82,    83,
       0,     0,     0,     0,     0,     0,     0,     0,    88,    89,
      90,    91,     0,    92,     0,     0,     0,   493,    94,    95,
     494,   495,     0,     0,     0,     0,     0,     0,    98,    99,
     100,     0,   102,   103,   104,     0,     0,     0,     0,     0,
       0,   109,   110,     0,     0,     0,     0,   111,   112,   113,
     114,   496,   116,   117,   497,     0,     0,     0,     0,     0,
       0,     0,   498,   499,   124,     0,     0,     0,   125,     0,
     126,   500,     0,     0,     0,   130,     0,   131,     0,   132,
     133,   134,   135,   501,   137,   138,   139,   140,   141,   142,
       0,     0,   143,   144,     0,     0,   387,   147,   148,   149,
     150,   151,   152,   153,   154,   502,   156,   503,   158,   504,
     505,   161,   162,   163,   164,   165,   166,   506,   168,   507,
     508,   509,   510,   173,   174,   511,   512,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,   192,     0,   193,   194,   195,   196,   197,
     198,     0,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,     1,     0,     0,     0,     0,     0,     0,     0,
       2,     0,     0,     0,     6,     7,     0,     0,   472,     0,
       0,     0,   384,   385,     0,    11,    12,    13,   521,    15,
      16,    17,   474,   522,   523,    21,   476,   477,   478,   386,
      26,   479,    28,    29,     0,    30,    31,    32,    33,   524,
      35,   525,   526,    38,    39,    40,    41,   481,     0,    43,
     527,    45,   483,   484,    48,   485,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,   486,
     487,    65,     0,    66,    67,    68,   528,     0,    71,    72,
      73,     0,     0,   489,    75,     0,     0,     0,     0,    77,
     490,    79,   491,   492,    82,    83,     0,     0,     0,     0,
       0,     0,     0,     0,    88,    89,    90,    91,     0,    92,
       0,     0,     0,   493,    94,    95,   494,   495,     0,     0,
       0,     0,     0,     0,    98,    99,   100,     0,   102,   103,
     104,     0,     0,     0,     0,     0,     0,   109,   110,     0,
       0,     0,     0,   111,   112,   113,   114,   496,   116,   117,
     497,     0,     0,     0,     0,     0,     0,     0,   498,   499,
     124,     0,     0,     0,   125,     0,   126,   500,     0,     0,
       0,   130,     0,   131,     0,   132,   133,   134,   135,   501,
     137,   138,   139,   140,   141,   142,     0,     0,   143,   144,
       0,     0,   387,   147,   148,   149,   150,   151,   152,   153,
     154,   502,   529,   503,   158,   504,   505,   161,   162,   163,
     164,   165,   166,   506,   168,   507,   508,   509,   510,   173,
     174,   511,   512,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,   192,
       0,   193,   194,   195,   196,   197,   198,     0,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   550,     0,
       0,     0,     0,     0,     0,     0,     6,     7,     0,     0,
     757,     0,     0,     0,   384,   385,     0,    11,    12,    13,
     521,    15,    16,    17,   474,   522,   523,    21,   476,   477,
     478,   386,    26,   479,    28,    29,     0,    30,    31,    32,
      33,   524,    35,   525,   526,    38,    39,    40,    41,   481,
       0,    43,   527,    45,   483,   484,    48,   485,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,   486,   487,    65,     0,    66,    67,    68,   528,     0,
      71,    72,    73,     0,     0,   489,    75,     0,     0,     0,
       0,    77,   490,    79,   491,   492,    82,    83,     0,     0,
       0,     0,     0,     0,     0,     0,    88,    89,    90,    91,
       0,    92,     0,     0,     0,   493,    94,    95,   494,   495,
       0,     0,     0,     0,     0,     0,    98,    99,   100,     0,
     102,   103,   104,     0,     0,     0,     0,     0,     0,   109,
     110,     0,     0,     0,     0,   111,   112,   113,   114,   496,
     116,   117,   497,     0,     0,     0,     0,     0,     0,     0,
     498,   499,   124,     0,     0,     0,   125,   758,   126,   500,
       0,     0,     0,     0,     0,   131,     0,   132,   133,   134,
     135,   501,   137,   138,   139,   140,   141,   142,     0,     0,
     143,   144,     0,     0,   387,   147,   148,   149,   150,   151,
     152,   153,   154,   502,   529,   503,   158,   504,   505,   161,
     162,   163,   164,   165,   166,   506,   168,   507,   508,   509,
     510,   173,   174,   511,   512,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,   190,
     191,   192,     0,   193,   194,   195,   196,   197,   198,     0,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     550,     0,     0,     0,     0,     0,     0,     0,     6,     7,
       0,     0,   472,     0,     0,     0,   384,   385,     0,    11,
      12,    13,   521,    15,    16,    17,   474,   522,   523,    21,
     476,   477,   478,   386,    26,   479,    28,    29,     0,    30,
      31,    32,    33,   524,    35,   525,   526,    38,    39,    40,
      41,   481,     0,    43,   527,    45,   483,   484,    48,   485,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,   486,   487,    65,     0,    66,    67,    68,
     528,     0,    71,    72,    73,     0,     0,   489,    75,     0,
       0,     0,     0,    77,   490,    79,   491,   492,    82,    83,
       0,     0,     0,     0,     0,     0,     0,     0,    88,    89,
      90,    91,     0,    92,     0,     0,     0,   493,    94,    95,
     494,   495,     0,     0,     0,     0,     0,     0,    98,    99,
     100,     0,   102,   103,   104,     0,     0,     0,     0,     0,
       0,   109,   110,     0,     0,     0,     0,   111,   112,   113,
     114,   496,   116,   117,   497,     0,     0,     0,     0,     0,
       0,     0,   498,   499,   124,     0,     0,     0,   125,     0,
     126,   500,     0,     0,     0,     0,     0,   131,     0,   132,
     133,   134,   135,   501,   137,   138,   139,   140,   141,   142,
       0,     0,   143,   144,     0,     0,   387,   147,   148,   149,
     150,   151,   152,   153,   154,   502,   529,   503,   158,   504,
     505,   161,   162,   163,   164,   165,   166,   506,   168,   507,
     508,   509,   510,   173,   174,   511,   512,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,   192,     0,   193,   194,   195,   196,   197,
     198,     0,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   553,   554,     0,     0,     0,     0,     6,     7,
       0,     0,   472,     0,     0,     0,   384,   385,     0,    11,
      12,    13,   521,    15,    16,    17,   474,   522,   523,    21,
     476,   477,   478,   386,    26,   479,    28,    29,     0,    30,
      31,    32,    33,   524,    35,   525,   526,    38,    39,    40,
      41,   481,     0,    43,   527,    45,   483,   484,    48,   485,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,   486,   487,    65,     0,    66,    67,    68,
     528,     0,    71,    72,    73,     0,     0,   489,    75,     0,
       0,     0,     0,    77,   490,    79,   491,   492,    82,    83,
       0,     0,     0,     0,     0,     0,     0,     0,    88,    89,
      90,    91,     0,    92,     0,     0,     0,   493,    94,    95,
     494,   495,     0,     0,     0,     0,     0,     0,    98,    99,
     100,     0,   102,   103,   104,     0,     0,     0,     0,     0,
       0,   109,   110,     0,     0,     0,     0,   111,   112,   113,
     114,   496,   116,   117,   497,     0,     0,     0,     0,     0,
       0,     0,   498,   499,   124,     0,     0,     0,   125,     0,
     126,   500,     0,     0,     0,     0,     0,   131,     0,   132,
     133,   134,   135,   501,   137,   138,   139,   140,   141,   142,
       0,     0,   143,   144,     0,     0,   387,   147,   148,   149,
     150,   151,   152,   153,   154,   502,   529,   503,   158,   504,
     505,   161,   162,   163,   164,   165,   166,   506,   168,   507,
     508,   509,   510,   173,   174,   511,   512,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,   192,     0,   193,   194,   195,   196,   197,
     198,     0,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,     6,     7,     0,     0,   472,     0,     0,     0,
     384,   385,     0,    11,    12,    13,   473,    15,    16,    17,
     474,    19,   475,    21,   476,  1086,   478,   386,    26,   479,
      28,    29,     0,    30,    31,    32,    33,   480,    35,    36,
      37,    38,    39,    40,    41,   481,     0,    43,   482,    45,
     483,   484,    48,   485,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,   486,   487,    65,
       0,    66,    67,    68,   488,     0,    71,    72,    73,     0,
       0,   489,    75,     0,     0,     0,     0,    77,   490,    79,
     491,   492,    82,    83,     0,     0,     0,     0,     0,     0,
       0,     0,    88,    89,    90,    91,     0,    92,     0,     0,
       0,   493,    94,    95,   494,   495,     0,     0,     0,     0,
       0,     0,    98,    99,   100,     0,   102,   103,  1087,     0,
       0,     0,  1088,     0,     0,   109,   110,     0,     0,     0,
       0,   111,   112,   113,   114,   496,   116,   117,   497,     0,
       0,     0,     0,     0,     0,     0,   498,   499,   124,     0,
       0,     0,   125,  1494,   126,   500,     0,     0,     0,  1495,
       0,   131,     0,   132,   133,   134,   135,   501,   137,   138,
     139,   140,   141,   142,     0,     0,  1089,   144,     0,     0,
     387,   147,   148,   149,   150,   151,   152,   153,   154,   502,
     156,   503,   158,   504,   505,   161,   162,   163,   164,   165,
     166,   506,   168,   507,   508,   509,   510,   173,   174,   511,
     512,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,   192,     0,   193,
     194,   195,   196,   197,   198,     0,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,     6,     7,     0,     0,
     472,     0,     0,     0,   384,   385,     0,    11,    12,    13,
     521,    15,    16,    17,   474,   522,   523,    21,   476,   477,
     478,   386,    26,   479,    28,    29,     0,    30,    31,    32,
      33,   524,    35,   525,   526,    38,    39,    40,    41,   481,
       0,    43,   527,    45,   483,   484,    48,   485,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,   486,   487,    65,     0,    66,    67,    68,   528,     0,
      71,    72,    73,     0,     0,   489,    75,     0,     0,     0,
       0,    77,   490,    79,   491,   492,    82,    83,     0,     0,
       0,     0,     0,     0,     0,     0,    88,    89,    90,    91,
       0,    92,     0,     0,     0,   493,    94,    95,   494,   495,
       0,     0,     0,     0,     0,     0,    98,    99,   100,     0,
     102,   103,   104,     0,     0,     0,     0,     0,     0,   109,
     110,     0,     0,     0,     0,   111,   112,   113,   114,   496,
     116,   117,   497,     0,     0,     0,     0,     0,     0,     0,
     498,   499,   124,     0,     0,     0,   125,   728,   126,   500,
       0,     0,     0,   729,     0,   131,     0,   132,   133,   134,
     135,   501,   137,   138,   139,   140,   141,   142,     0,     0,
     143,   144,     0,     0,   387,   147,   148,   149,   150,   151,
     152,   153,   154,   502,   529,   503,   158,   504,   505,   161,
     162,   163,   164,   165,   166,   506,   168,   507,   508,   509,
     510,   173,   174,   511,   512,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,   190,
     191,   192,     0,   193,   194,   195,   196,   197,   198,     0,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
       6,     7,     0,     0,   472,     0,     0,     0,   384,   385,
       0,    11,    12,    13,   521,    15,    16,    17,   474,   522,
     523,    21,   476,   477,   478,   386,    26,   479,    28,    29,
       0,    30,    31,    32,    33,   524,    35,   525,   526,    38,
      39,    40,    41,   481,     0,    43,   527,    45,   483,   484,
      48,   485,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,   486,   487,    65,     0,    66,
      67,    68,   528,     0,    71,    72,    73,     0,     0,   489,
      75,     0,     0,     0,     0,    77,   490,    79,   491,   492,
      82,    83,     0,     0,     0,     0,     0,     0,     0,     0,
      88,    89,    90,    91,     0,    92,     0,     0,     0,   493,
      94,    95,   494,   495,     0,     0,     0,     0,     0,     0,
      98,    99,   100,     0,   102,   103,   104,     0,     0,     0,
       0,     0,     0,   109,   110,     0,     0,     0,     0,   111,
     112,   113,   114,   496,   116,   117,   497,     0,     0,     0,
       0,     0,     0,     0,   498,   499,   124,     0,     0,     0,
     125,   775,   126,   500,     0,     0,     0,   776,     0,   131,
       0,   132,   133,   134,   135,   501,   137,   138,   139,   140,
     141,   142,     0,     0,   143,   144,     0,     0,   387,   147,
     148,   149,   150,   151,   152,   153,   154,   502,   529,   503,
     158,   504,   505,   161,   162,   163,   164,   165,   166,   506,
     168,   507,   508,   509,   510,   173,   174,   511,   512,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,     0,   190,   191,   192,     0,   193,   194,   195,
     196,   197,   198,     0,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,     6,     7,     0,     0,   472,     0,
       0,     0,   384,   385,     0,    11,    12,    13,   473,    15,
      16,    17,   474,    19,   475,    21,   476,  1086,   478,   386,
      26,   479,    28,    29,     0,    30,    31,    32,    33,   480,
      35,    36,    37,    38,    39,    40,    41,   481,     0,    43,
     482,    45,   483,   484,    48,   485,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,   486,
     487,    65,     0,    66,    67,    68,   488,     0,    71,    72,
      73,     0,     0,   489,    75,     0,     0,     0,     0,    77,
     490,    79,   491,   492,    82,    83,  1417,     0,     0,     0,
       0,     0,     0,     0,    88,    89,    90,    91,     0,    92,
       0,     0,     0,   493,    94,    95,   494,   495,     0,     0,
       0,     0,     0,     0,    98,    99,   100,     0,   102,   103,
    1087,     0,     0,     0,  1088,     0,     0,   109,   110,     0,
       0,     0,     0,   111,   112,   113,   114,   496,   116,   117,
     497,     0,     0,     0,     0,     0,     0,     0,   498,   499,
     124,     0,     0,     0,   125,     0,   126,   500,     0,     0,
       0,     0,     0,   131,     0,   132,   133,   134,   135,   501,
     137,   138,   139,   140,   141,   142,     0,     0,  1089,   144,
       0,     0,   387,   147,   148,   149,   150,   151,   152,   153,
     154,   502,   156,   503,   158,   504,   505,   161,   162,   163,
     164,   165,   166,   506,   168,   507,   508,   509,   510,   173,
     174,   511,   512,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,   192,
       0,   193,   194,   195,   196,   197,   198,     0,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,     6,     7,
       0,     0,   472,     0,     0,     0,   384,   385,     0,    11,
      12,    13,   473,    15,    16,    17,   474,    19,   475,    21,
     476,  1086,   478,   386,    26,   479,    28,    29,     0,    30,
      31,    32,    33,   480,    35,    36,    37,    38,    39,    40,
      41,   481,     0,    43,   482,    45,   483,   484,    48,   485,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,   486,   487,    65,     0,    66,    67,    68,
     488,     0,    71,    72,    73,     0,     0,   489,    75,     0,
       0,     0,     0,    77,   490,    79,   491,   492,    82,    83,
    1548,     0,     0,     0,     0,     0,     0,     0,    88,    89,
      90,    91,     0,    92,     0,     0,     0,   493,    94,    95,
     494,   495,     0,     0,     0,     0,     0,     0,    98,    99,
     100,     0,   102,   103,  1087,     0,     0,     0,  1088,     0,
       0,   109,   110,     0,     0,     0,     0,   111,   112,   113,
     114,   496,   116,   117,   497,     0,     0,     0,     0,     0,
       0,     0,   498,   499,   124,     0,     0,     0,   125,     0,
     126,   500,     0,     0,     0,     0,     0,   131,     0,   132,
     133,   134,   135,   501,   137,   138,   139,   140,   141,   142,
       0,     0,  1089,   144,     0,     0,   387,   147,   148,   149,
     150,   151,   152,   153,   154,   502,   156,   503,   158,   504,
     505,   161,   162,   163,   164,   165,   166,   506,   168,   507,
     508,   509,   510,   173,   174,   511,   512,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,   192,     0,   193,   194,   195,   196,   197,
     198,     0,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,     6,     7,     0,     0,   472,     0,     0,     0,
     384,   385,     0,    11,    12,    13,   473,    15,    16,    17,
     474,    19,   475,    21,   476,  1086,   478,   386,    26,   479,
      28,    29,     0,    30,    31,    32,    33,   480,    35,    36,
      37,    38,    39,    40,    41,   481,     0,    43,   482,    45,
     483,   484,    48,   485,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,   486,   487,    65,
       0,    66,    67,    68,   488,     0,    71,    72,    73,     0,
       0,   489,    75,     0,     0,     0,     0,    77,   490,    79,
     491,   492,    82,    83,  1552,     0,     0,     0,     0,     0,
       0,     0,    88,    89,    90,    91,     0,    92,     0,     0,
       0,   493,    94,    95,   494,   495,     0,     0,     0,     0,
       0,     0,    98,    99,   100,     0,   102,   103,  1087,     0,
       0,     0,  1088,     0,     0,   109,   110,     0,     0,     0,
       0,   111,   112,   113,   114,   496,   116,   117,   497,     0,
       0,     0,     0,     0,     0,     0,   498,   499,   124,     0,
       0,     0,   125,     0,   126,   500,     0,     0,     0,     0,
       0,   131,     0,   132,   133,   134,   135,   501,   137,   138,
     139,   140,   141,   142,     0,     0,  1089,   144,     0,     0,
     387,   147,   148,   149,   150,   151,   152,   153,   154,   502,
     156,   503,   158,   504,   505,   161,   162,   163,   164,   165,
     166,   506,   168,   507,   508,   509,   510,   173,   174,   511,
     512,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,   192,     0,   193,
     194,   195,   196,   197,   198,     0,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,     6,     7,     0,     0,
     472,     0,     0,     0,   384,   385,     0,    11,    12,    13,
     473,    15,    16,    17,   474,    19,   475,    21,   476,  1086,
     478,   386,    26,   479,    28,    29,     0,    30,    31,    32,
      33,   480,    35,    36,    37,    38,    39,    40,    41,   481,
       0,    43,   482,    45,   483,   484,    48,   485,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,   486,   487,    65,     0,    66,    67,    68,   488,     0,
      71,    72,    73,     0,     0,   489,    75,     0,     0,     0,
       0,    77,   490,    79,   491,   492,    82,    83,     0,     0,
       0,     0,     0,     0,     0,     0,    88,    89,    90,    91,
       0,    92,     0,     0,     0,   493,    94,    95,   494,   495,
       0,     0,     0,     0,     0,     0,    98,    99,   100,     0,
     102,   103,  1087,     0,     0,     0,  1088,     0,     0,   109,
     110,     0,     0,     0,     0,   111,   112,   113,   114,   496,
     116,   117,   497,     0,     0,     0,     0,     0,     0,     0,
     498,   499,   124,     0,     0,     0,   125,     0,   126,   500,
       0,     0,     0,     0,     0,   131,     0,   132,   133,   134,
     135,   501,   137,   138,   139,   140,   141,   142,     0,     0,
    1089,   144,     0,     0,   387,   147,   148,   149,   150,   151,
     152,   153,   154,   502,   156,   503,   158,   504,   505,   161,
     162,   163,   164,   165,   166,   506,   168,   507,   508,   509,
     510,   173,   174,   511,   512,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,   190,
     191,   192,     0,   193,   194,   195,   196,   197,   198,     0,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
       6,     7,     0,     0,   472,     0,     0,     0,   384,   385,
       0,    11,    12,    13,   473,    15,    16,    17,   474,    19,
     475,    21,   476,  1086,   478,   386,    26,   479,    28,    29,
       0,    30,    31,    32,    33,   480,    35,    36,    37,    38,
      39,    40,    41,   481,     0,    43,   482,    45,   483,   484,
      48,   485,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,   486,   487,    65,     0,    66,
      67,    68,   488,     0,    71,    72,    73,     0,     0,   489,
      75,     0,     0,     0,     0,    77,   490,    79,   491,   492,
      82,    83,     0,     0,     0,     0,     0,     0,     0,     0,
      88,    89,    90,    91,     0,    92,     0,     0,     0,   493,
      94,    95,   494,   495,     0,     0,     0,     0,     0,     0,
      98,    99,   100,     0,   102,   103,  1087,     0,     0,     0,
    1088,     0,     0,   109,   110,     0,     0,     0,     0,   111,
     112,   113,   114,   496,   116,   117,   497,     0,     0,     0,
       0,     0,     0,     0,   498,   499,   124,     0,     0,     0,
     125,     0,   126,   500,     0,     0,     0,     0,     0,   131,
       0,   132,   133,   134,   135,   501,   137,   138,   139,   140,
     141,   142,     0,     0,   143,   144,     0,     0,   387,   147,
     148,   149,   150,   151,   152,   153,   154,   502,   156,   503,
     158,   504,   505,   161,   162,   163,   164,   165,   166,   506,
     168,   507,   508,   509,   510,   173,   174,   511,   512,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,     0,   190,   191,   192,     0,   193,   194,   195,
     196,   197,   198,     0,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,     6,     7,     0,     0,   472,     0,
       0,     0,   384,   385,     0,    11,    12,    13,   521,    15,
      16,    17,   474,   522,   523,    21,   476,   477,   478,   386,
      26,   479,    28,    29,     0,    30,    31,    32,    33,   524,
      35,   525,   526,    38,    39,    40,    41,   481,     0,    43,
     527,    45,   483,   484,    48,   485,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,   486,
     487,    65,     0,    66,    67,    68,   528,     0,    71,    72,
      73,     0,     0,   489,    75,     0,     0,     0,     0,    77,
     490,    79,   491,   492,    82,    83,     0,     0,     0,     0,
       0,     0,     0,     0,    88,    89,    90,    91,     0,    92,
       0,     0,     0,   493,    94,    95,   494,   495,     0,     0,
       0,     0,     0,     0,    98,    99,   100,     0,   102,   103,
     104,     0,     0,     0,     0,     0,     0,   109,   110,     0,
       0,     0,     0,   111,   112,   113,   114,   496,   116,   117,
     497,     0,     0,     0,     0,     0,     0,     0,   498,   499,
     124,     0,     0,     0,   125,     0,   126,   500,     0,     0,
       0,     0,     0,   131,     0,   132,   133,   134,   135,   501,
     137,   138,   139,   140,   141,   142,     0,     0,   143,   144,
       0,     0,   387,   147,   148,   149,   150,   151,   152,   153,
     154,   502,   529,   503,   158,   504,   505,   161,   162,   163,
     164,   165,   166,   506,   168,   507,   508,   509,   510,   173,
     174,   511,   512,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,   192,
       0,   193,   194,   195,   196,   197,   198,     0,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,     6,     7,
       0,     0,   472,     0,     0,     0,   384,   385,     0,    11,
      12,    13,     0,    15,    16,    17,   474,     0,     0,    21,
     476,   477,     0,   386,    26,   479,    28,    29,     0,    30,
      31,    32,    33,     0,    35,     0,     0,    38,    39,    40,
      41,   481,     0,    43,     0,    45,     0,     0,    48,   485,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,   486,   487,    65,     0,    66,    67,    68,
       0,     0,    71,    72,    73,     0,     0,   489,    75,     0,
       0,     0,     0,    77,   490,    79,   491,   492,    82,    83,
       0,     0,     0,     0,     0,     0,     0,     0,    88,    89,
      90,    91,     0,    92,     0,     0,     0,   493,    94,    95,
     494,   495,     0,     0,     0,     0,     0,     0,    98,    99,
     100,     0,   102,   103,     0,     0,     0,     0,     0,     0,
       0,   109,   110,     0,     0,     0,     0,   111,   112,   113,
     114,   496,   116,   117,   497,     0,     0,     0,     0,     0,
       0,     0,   498,   499,   124,     0,     0,     0,   125,     0,
     126,   500,     0,     0,     0,     0,     0,   131,     0,   132,
     133,   134,   135,   501,   137,   138,   139,   140,   141,   142,
       0,     0,     0,   144,     0,     0,   387,   147,   148,   149,
     150,   151,   152,   153,   154,   502,     0,   503,   158,   504,
     505,   161,   162,   163,   164,   165,   166,   506,   168,   507,
     508,   509,   510,   173,   174,     0,   512,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,   192,     0,   193,   194,   195,   196,   197,
     198,     0,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         0,   176,   637,     3,     4,     5,     0,   752,   106,     3,
       4,     5,     3,     4,     5,   295,   672,   322,   394,   764,
     791,   638,   639,   640,   641,   246,     3,     4,     5,   735,
     986,  1156,   735,   778,  1002,   245,    70,   591,   592,   129,
     261,   406,     3,     4,     5,   857,   589,   590,   591,   592,
     949,  1239,   275,  1296,  1297,  1072,  1223,    54,    25,   819,
     680,    34,    34,  1024,   891,     1,   907,   432,   115,   589,
     590,   447,   448,    28,  1252,  1512,   869,   870,   617,    46,
     619,   620,     1,   622,   144,   624,     1,  1329,    55,    92,
     455,     1,     1,   632,   633,    91,   139,     1,     1,    27,
      43,   115,   870,    37,   115,   105,    73,    92,    42,    43,
      77,   105,    35,    36,   907,    38,    39,   144,    61,    92,
      94,    94,    94,   104,    58,   104,    60,    61,   105,   104,
       8,   115,   115,    56,   133,    69,   104,    27,    51,    70,
      92,   108,   109,   110,   105,    94,    27,   104,   941,   166,
      92,   104,    97,    84,  1720,   260,  1636,  1637,   213,    92,
     104,    95,   163,    92,   103,   150,   271,   390,   913,   183,
     963,   144,   144,   184,   221,   133,   107,   275,   179,   107,
    1746,   198,   904,   976,   180,   124,    94,   110,   119,   147,
     121,  1757,   144,   121,   916,   963,   251,  1677,   197,   166,
     183,   857,   144,  1683,   153,   184,   187,   182,   976,    40,
     270,   214,   215,   126,    45,  1458,   213,   185,   146,    50,
     110,  1658,   150,    92,   969,   153,   229,   270,   181,   104,
     975,   198,   217,   218,   157,   325,    94,    68,   183,   239,
     184,   184,   242,   270,  1369,   239,   174,  1088,   242,  1020,
    1206,   187,  1220,  1152,   251,   210,  1434,   304,   166,   226,
    1072,  1073,   968,   966,  1431,   968,   546,   157,   187,  1511,
     824,   825,   187,   893,   231,   275,   157,   187,   187,   253,
     254,   275,  1243,   187,   187,   988,   270,   221,  1305,  1116,
       9,  1252,   390,   216,   172,  1088,   330,   270,   270,   333,
     233,   666,   822,   823,   233,   104,    27,    26,   166,    97,
     185,    97,   127,   536,   853,   691,   150,   284,   285,   286,
     287,   288,    25,   290,   291,   292,   293,   294,   256,   150,
     104,   104,   299,   300,   165,   258,   104,   168,   127,   437,
     174,   249,   250,    46,   252,   214,   215,   445,   104,   197,
     104,   259,   183,   174,    43,   104,   454,    46,   206,   104,
     229,   269,   104,   461,   462,   586,  1609,   104,  1161,   104,
      73,   104,   470,   281,   750,   104,   104,   208,   193,   589,
     590,   746,   605,  1571,   749,   184,   107,   128,    77,  1514,
     390,   249,   250,    92,   252,   183,   390,   183,    94,   330,
     121,   120,   333,   122,   193,  1198,   109,    94,   181,     9,
     184,   269,   131,   181,   103,  1160,  1072,  1073,  1661,   104,
       5,   188,   189,   281,     9,   146,    26,   181,   184,  1222,
    1198,   150,   181,   433,    43,   435,   181,    46,   536,   433,
     139,   435,   184,   155,   435,   155,   187,   184,   144,   184,
     548,   184,  1108,   181,  1222,   184,   433,   144,   435,   459,
     118,   173,   560,   173,   464,   459,  1172,   398,   399,  1368,
     464,   402,   433,  1434,   435,   406,   165,  1644,  1181,   577,
     578,   412,   459,   104,    53,   104,    55,   464,   419,  1614,
     104,   296,   104,  1305,   103,   134,   719,   104,   459,   184,
     305,   432,  1314,   464,  1058,  1059,  1060,   438,     5,   157,
     441,   150,     9,  1325,    94,  1058,  1059,  1060,   449,  1279,
     120,   150,   122,  1283,   455,   456,   457,   458,    97,    92,
     110,   131,   463,    27,  1659,   120,   536,   122,   914,   915,
     471,   541,   536,   919,  1337,   130,   150,   541,   104,   153,
     150,   104,     9,    10,   266,   653,   165,   104,   104,   104,
     658,   273,   181,   184,   541,   150,   656,   657,   104,  1337,
     184,   283,   184,   153,   260,   951,   139,   184,   578,  1535,
     541,   221,   104,   223,   578,   271,   517,   104,   104,   589,
     590,   591,   592,   153,   817,   589,   590,   591,   592,    31,
     531,   578,  1570,   104,   104,   605,   982,   828,   104,   540,
     986,   605,   822,   107,   573,   114,    48,  1742,   957,  1744,
     959,   719,   153,   120,   134,   122,  1419,   121,   184,  1422,
      31,   184,    40,   130,   181,   181,   595,    45,  1763,   184,
     150,   572,    50,   100,   143,   297,   298,    48,   184,  1305,
      65,  1419,   146,   150,  1422,    70,   150,   156,  1314,   153,
      68,  1432,   184,   120,   141,   122,  1437,   184,   184,  1325,
    1009,   221,  1011,  1485,    94,   151,   226,   153,  1384,   248,
     174,  1316,    92,   184,   184,   783,   784,   785,   184,   787,
     110,   190,   261,   150,   263,   145,   173,   154,   150,   150,
     115,   153,   153,     9,    10,   274,   275,   276,   265,   278,
     115,   280,   162,   190,   171,   272,    52,    52,    40,   719,
     145,    57,    57,    45,   134,   719,   155,   155,    50,   139,
     119,  1285,    23,   153,   191,   666,   179,   162,   134,    92,
      75,    32,   742,   139,   173,   173,    68,    94,   742,   192,
     103,   742,   209,   684,   206,   206,   687,   165,    94,    94,
     168,   150,   153,   110,   153,   742,   195,   195,    59,  1074,
    1050,   150,   772,   773,   153,   183,   179,   708,   772,   773,
     115,   742,    93,   714,   715,     9,    10,  1558,   153,   192,
      97,  1562,   103,    97,   100,   772,   773,   244,   245,  1592,
     208,  1594,   113,   110,   153,   736,   110,   738,   153,     9,
      10,   772,   773,   124,   120,   746,   122,   817,   749,   153,
     267,  1044,   753,   817,  1592,  1201,  1594,    97,   266,  1485,
    1206,   119,  1625,   134,    97,   273,    97,    97,   139,   119,
     110,  1476,  1477,   165,   150,   283,   168,   110,   154,   110,
     110,    52,  1469,   332,   125,   126,    57,  1625,   337,   790,
     150,   183,  1655,   153,  1609,   171,   221,   150,   223,  1640,
     153,   297,   298,  1048,   166,   119,   100,  1670,  1053,  1672,
      25,   115,   228,   119,   230,   191,   208,  1655,   819,   659,
      35,    36,   662,    38,    39,   665,   120,   228,   122,   230,
     100,    46,  1670,   209,  1672,   119,   198,   288,   289,   840,
      55,    56,   274,   275,   276,   119,  1292,   115,   280,   150,
     120,   150,   122,   217,   218,   219,   150,   119,    73,   109,
     154,   119,    77,   119,   226,   125,   126,   119,   869,   870,
     871,   872,   635,   636,   119,  1580,  1581,   171,   642,   643,
     150,   153,   644,   645,   154,   871,   872,  1502,  1503,   212,
     115,   238,   221,   108,   109,   110,   238,   191,   153,   150,
     239,   171,     0,  1071,   104,   187,   907,  1200,    90,   246,
     164,    49,    98,   196,    99,   209,   151,   118,   142,   153,
     921,   191,   284,   285,   286,   287,   288,   153,   290,   291,
     292,   293,   294,   181,  1004,   181,    27,   299,   181,   209,
    1004,    46,   157,   149,   115,   243,  1651,   948,   184,   295,
     295,   166,   290,   301,   281,  1401,   957,  1004,   959,   281,
     115,   150,   963,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,  1004,  1044,   976,     1,   139,   115,   104,
    1044,   184,   150,   198,   150,  1278,   153,   139,  1058,  1059,
    1060,   181,   153,   153,  1058,  1059,  1060,   153,    33,   153,
     153,   216,   153,   153,   150,    16,   210,    27,  1009,   184,
    1011,   226,   242,   227,   187,   187,  1462,     3,   115,   167,
     165,    69,   227,   167,    92,    92,    92,   146,   104,   104,
      27,   157,   124,   157,   129,   243,   139,   296,   115,   129,
     181,   181,   184,   258,   104,   184,    92,    94,    43,    94,
     184,   184,   184,   184,   181,    92,   150,   233,   181,   139,
      31,   167,   221,   115,   129,   187,  1067,   139,    92,   284,
     285,   286,   287,   288,    27,   290,   291,   292,   293,   294,
     223,   283,   115,   296,   299,   300,   150,  1088,   124,  1535,
     144,    92,   115,   251,   115,  1165,   181,   129,   194,   157,
     129,  1165,    94,   115,  1165,   144,  1274,  1275,  1276,   150,
      97,   181,    97,   139,   187,    33,   150,    27,  1165,   181,
    1413,   115,   153,   153,   242,   153,    77,   104,   150,   104,
    1200,   141,    27,   282,  1165,   255,  1200,   153,   153,   153,
     257,  1211,    27,   264,    27,   233,   303,  1211,   283,   223,
    1211,   141,   223,   144,   284,   124,   144,   184,   115,   115,
    1230,   144,   223,    75,  1211,   104,  1230,   184,   187,  1230,
    1171,   184,   139,  1174,   181,   184,   184,    97,   184,  1249,
    1211,   129,     7,  1230,   187,  1249,   229,   229,  1189,   194,
     183,   229,   115,   233,   103,   103,   247,  1198,   247,  1230,
     184,   129,  1249,   144,   283,    76,   184,  1277,  1278,   137,
     138,  1212,   140,  1277,  1278,    27,   279,    27,  1249,   184,
     148,  1222,   184,   104,   152,   229,   154,   167,   144,   181,
    1277,   159,   123,   144,   123,    94,   181,   183,   181,   183,
    1533,   183,    92,   150,   181,   183,   181,    27,   176,  1250,
     268,  1544,  1545,   184,  1547,   254,    94,   184,   144,    52,
      92,  1554,   167,   193,   183,   194,   183,   115,    92,  1270,
      27,   199,   200,   201,   202,   203,   204,   277,  1279,   115,
     262,   104,  1283,   104,   115,   221,   284,    92,    92,   183,
     193,   193,    91,   115,   193,   115,   221,   115,   115,   183,
     302,   183,   180,   183,   183,   150,   302,   115,   183,   290,
     184,    70,   115,   302,   115,   184,   284,   221,   195,   115,
     242,   242,   690,   303,   303,    84,   239,   303,   977,  1119,
     245,   908,   425,  1161,  1659,  1614,  1337,   820,   425,   974,
    1633,   430,  1171,  1413,   755,  1190,  1394,  1301,   107,  1413,
    1643,  1063,  1299,  1296,   531,  1212,  1217,  1220,  1225,   616,
     119,   668,   121,   318,  1365,  1243,   615,   791,  1683,  1677,
    1153,   872,  1118,  1270,   959,  1280,  1279,   436,  1671,   436,
    1314,  1325,  1485,  1073,  1482,  1318,  1082,   940,  1141,  1357,
    1391,  1392,  1315,  1505,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1648,  1572,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1705,    -1,    -1,    -1,  1417,    -1,  1419,    -1,
      -1,  1422,  1590,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1433,    -1,    -1,    -1,  1729,  1438,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1738,    -1,    -1,    -1,    -1,
      -1,    -1,  1453,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1533,    -1,    -1,    -1,    -1,    -1,  1533,
      -1,    -1,    -1,    -1,  1544,  1545,    -1,  1547,    -1,    -1,
    1544,  1545,    -1,  1547,  1554,    -1,    -1,    -1,    -1,  1734,
    1554,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1752,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1548,    -1,  1550,
      -1,  1552,    -1,    -1,    -1,    -1,    -1,    -1,  1559,    -1,
      -1,    -1,    -1,  1633,    -1,    -1,    -1,    -1,    -1,  1633,
      -1,   330,    -1,  1643,   333,    -1,    -1,    -1,    -1,  1643,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1592,    -1,  1594,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1671,    -1,    -1,    -1,    -1,    -1,  1671,    -1,  1610,
      -1,    -1,  1613,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1625,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1635,  1705,    -1,    -1,    -1,    -1,
     399,  1705,    -1,   402,    -1,  1646,    -1,   406,    -1,    -1,
      -1,    -1,    -1,   412,  1655,    -1,    -1,    -1,    -1,  1729,
     419,    -1,  1663,    -1,    -1,  1729,    -1,  1668,  1738,  1670,
      -1,  1672,    -1,   432,  1738,    -1,    -1,    -1,    -1,   438,
      -1,    -1,   441,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     449,  1692,    -1,    -1,    -1,    -1,   455,   456,   457,   458,
      -1,  1702,    -1,    -1,   463,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   471,    -1,    -1,    -1,    -1,  1718,    -1,    -1,
      -1,    -1,    -1,    -1,  1725,    -1,    -1,    -1,    -1,    -1,
    1731,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1740,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1750,
      -1,    -1,    -1,    -1,    -1,  1756,    -1,    -1,   517,    -1,
    1761,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   531,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   540,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     564,   565,    -1,   567,   568,   569,   570,    -1,    -1,    -1,
      -1,    -1,   576,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   572,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   597,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   605,   606,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     664,    -1,    -1,    -1,   668,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   666,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   687,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   710,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   708,
      -1,    -1,    -1,    -1,    -1,   714,   715,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   736,    -1,   738,
     754,    -1,    -1,    -1,    -1,    -1,    -1,   746,    -1,    -1,
     749,    -1,    -1,    -1,   753,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   779,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   789,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   790,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     819,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   842,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   840,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     869,   870,   871,   872,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   909,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   907,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   921,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   946,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   948,
      -1,   965,    -1,    -1,    -1,    -1,    -1,    -1,   957,    -1,
     959,    -1,    -1,    -1,   963,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   987,    -1,    -1,    -1,   976,    -1,    -1,
      -1,    -1,    -1,    -1,   998,   999,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1013,
      -1,    -1,  1016,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1009,    -1,  1011,    -1,    -1,    -1,  1030,  1031,  1032,    -1,
    1034,  1035,  1036,  1037,  1038,  1039,    -1,  1041,  1042,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1063,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1067,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1088,
      -1,  1105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1176,    -1,  1178,    -1,  1180,    -1,    -1,  1183,
      -1,    -1,  1171,    -1,  1188,  1174,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1200,    -1,    -1,    -1,
    1189,    -1,    -1,    -1,    -1,  1209,    -1,    -1,    -1,  1198,
      -1,  1215,  1216,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1212,    -1,    -1,    -1,    -1,    -1,    -1,
    1234,    -1,    -1,  1222,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1270,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1279,    -1,    -1,    -1,  1283,  1299,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1337,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1378,    -1,  1365,    -1,  1382,    -1,
      -1,    -1,  1386,    -1,  1388,    -1,  1390,    -1,    -1,    -1,
      -1,    -1,  1396,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1404,    -1,  1391,  1392,    -1,    -1,    -1,    -1,  1412,  1413,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1430,    -1,  1417,    -1,
    1419,    -1,    -1,  1422,    -1,    -1,    -1,  1441,  1442,  1443,
    1444,  1445,    -1,  1447,  1433,    -1,    -1,    -1,    -1,  1438,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1453,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1521,    -1,  1523,
      -1,    -1,  1526,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1534,    -1,    -1,    -1,    -1,  1539,  1540,    -1,    -1,    -1,
      -1,    -1,    -1,  1547,    -1,    -1,    -1,  1551,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1548,
      -1,  1550,    -1,  1552,    -1,    -1,    -1,    -1,    -1,    -1,
    1559,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1592,    -1,  1594,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1617,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1610,    -1,    -1,  1613,  1629,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1625,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1635,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1646,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1655,  1671,    -1,    -1,
      -1,    -1,    -1,    -1,  1663,    -1,    -1,    -1,    -1,  1668,
      -1,  1670,    -1,  1672,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1700,    -1,    -1,    -1,
      -1,  1705,    -1,  1692,    -1,    -1,  1710,    -1,    -1,    -1,
      -1,    -1,    -1,  1702,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1728,    -1,    -1,    -1,    -1,  1718,
      -1,    -1,  1736,    -1,    -1,    -1,  1725,    -1,    -1,    -1,
      -1,    -1,  1731,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1740,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1750,    -1,    -1,    -1,    11,    -1,  1756,    -1,    -1,
      -1,    -1,  1761,    19,    20,    21,    22,    23,    24,    -1,
      -1,    27,    -1,    -1,    -1,    31,    32,    -1,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    -1,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    -1,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    -1,    92,    93,    94,    95,
      96,    97,    98,    99,    -1,    -1,   102,   103,    -1,    -1,
      -1,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,    -1,    -1,    -1,   121,    -1,   123,   124,   125,
     126,    -1,   128,    -1,    -1,    -1,   132,   133,   134,   135,
     136,    -1,    -1,    -1,    -1,    -1,    -1,   143,   144,   145,
     146,   147,   148,   149,   150,    -1,    -1,   153,   154,   155,
     156,   157,    -1,    -1,    -1,    -1,   162,   163,   164,   165,
     166,   167,   168,   169,    -1,   171,    -1,   173,   174,    -1,
      -1,   177,   178,   179,    -1,    -1,    -1,   183,    -1,   185,
     186,    -1,   188,   189,   190,    -1,   192,    -1,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,    -1,
      -1,   207,   208,   209,    -1,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,    -1,
     256,   257,   258,    -1,   260,   261,   262,   263,   264,   265,
      -1,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      19,    20,    21,    22,    23,    24,    -1,    -1,    27,    -1,
      -1,    -1,    31,    32,    -1,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    -1,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    -1,    92,    93,    94,    95,    96,    97,    98,
      99,    -1,    -1,   102,   103,    -1,    -1,    -1,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,    -1,
      -1,    -1,   121,    -1,   123,   124,   125,   126,    -1,   128,
      -1,    -1,    -1,   132,   133,   134,   135,   136,    -1,    -1,
      -1,    -1,    -1,    -1,   143,   144,   145,   146,   147,   148,
     149,   150,    -1,    -1,   153,   154,   155,   156,   157,    -1,
      -1,    -1,    -1,   162,   163,   164,   165,   166,   167,   168,
     169,    -1,   171,    -1,   173,   174,    -1,    -1,   177,   178,
     179,    -1,   181,    -1,   183,    -1,   185,   186,    -1,   188,
     189,   190,    -1,   192,    -1,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,    -1,    -1,   207,   208,
     209,    -1,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,    -1,   256,   257,   258,
      -1,   260,   261,   262,   263,   264,   265,    -1,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    21,    22,
      23,    24,    -1,    -1,    27,    -1,    -1,    -1,    31,    32,
      -1,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      -1,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    -1,    92,
      93,    94,    95,    96,    97,    98,    99,    -1,    -1,   102,
     103,    -1,    -1,    -1,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,    -1,    -1,    -1,   121,    -1,
     123,   124,   125,   126,    -1,   128,    -1,    -1,    -1,   132,
     133,   134,   135,   136,    -1,    -1,    -1,    -1,    -1,    -1,
     143,   144,   145,   146,   147,   148,   149,   150,    -1,    -1,
     153,   154,   155,   156,   157,    -1,    -1,    -1,    -1,   162,
     163,   164,   165,   166,   167,   168,   169,    -1,   171,    -1,
     173,   174,    -1,    -1,   177,   178,   179,    -1,    -1,    -1,
     183,   184,   185,   186,    -1,   188,   189,   190,    -1,   192,
      -1,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,    -1,    -1,   207,   208,   209,    -1,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,    -1,   256,   257,   258,    -1,   260,   261,   262,
     263,   264,   265,    -1,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    19,    20,    21,    22,    23,    24,    -1,    -1,
      27,    -1,    -1,    -1,    31,    32,    -1,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    -1,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    -1,    92,    93,    94,    95,    96,
      97,    98,    99,    -1,    -1,   102,   103,    -1,    -1,    -1,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,    -1,    -1,    -1,   121,    -1,   123,   124,   125,   126,
      -1,   128,    -1,    -1,    -1,   132,   133,   134,   135,   136,
      -1,    -1,    -1,    -1,    -1,    -1,   143,   144,   145,   146,
     147,   148,   149,   150,    -1,    -1,   153,   154,   155,   156,
     157,    -1,    -1,    -1,    -1,   162,   163,   164,   165,   166,
     167,   168,   169,    -1,   171,    -1,   173,   174,    -1,    -1,
     177,   178,   179,    -1,   181,    -1,   183,    -1,   185,   186,
      -1,   188,   189,   190,    -1,   192,    -1,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,    -1,    -1,
     207,   208,   209,    -1,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,    -1,   256,
     257,   258,    -1,   260,   261,   262,   263,   264,   265,    -1,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,
      21,    22,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,
      31,    32,    -1,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    -1,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    -1,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      -1,    92,    93,    94,    95,    96,    97,    98,    99,    -1,
      -1,   102,   103,    -1,    -1,    -1,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,    -1,    -1,    -1,
     121,    -1,   123,   124,   125,   126,    -1,   128,    -1,    -1,
      -1,   132,   133,   134,   135,   136,    -1,    -1,    -1,    -1,
      -1,    -1,   143,   144,   145,   146,   147,   148,   149,   150,
      -1,    -1,   153,   154,   155,   156,   157,    -1,    -1,    -1,
      -1,   162,   163,   164,   165,   166,   167,   168,   169,    -1,
     171,    -1,   173,   174,    -1,    -1,   177,   178,   179,    -1,
     181,    -1,   183,    -1,   185,   186,    -1,   188,   189,   190,
      -1,   192,    -1,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,    -1,    -1,   207,   208,   209,    -1,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,    -1,   256,   257,   258,    -1,   260,
     261,   262,   263,   264,   265,    -1,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    19,    20,    21,    22,    23,    24,
      -1,    -1,    27,    -1,    -1,    -1,    31,    32,    -1,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    -1,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    -1,    92,    93,    94,
      95,    96,    97,    98,    99,    -1,    -1,   102,   103,    -1,
      -1,    -1,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,    -1,    -1,    -1,   121,    -1,   123,   124,
     125,   126,    -1,   128,    -1,    -1,    -1,   132,   133,   134,
     135,   136,    -1,    -1,    -1,    -1,    -1,    -1,   143,   144,
     145,   146,   147,   148,   149,   150,    -1,    -1,   153,   154,
     155,   156,   157,    -1,    -1,    -1,    -1,   162,   163,   164,
     165,   166,   167,   168,   169,    -1,   171,    -1,   173,   174,
      -1,    -1,   177,   178,   179,    -1,    -1,    -1,   183,   184,
     185,   186,    -1,   188,   189,   190,    -1,   192,    -1,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
      -1,    -1,   207,   208,   209,    -1,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,   256,   257,   258,    -1,   260,   261,   262,   263,   264,
     265,    -1,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      19,    20,    21,    22,    23,    24,    -1,    -1,    27,    -1,
      -1,    -1,    31,    32,    -1,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    -1,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    -1,    92,    93,    94,    95,    96,    97,    98,
      99,    -1,    -1,   102,   103,    -1,    -1,    -1,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,    -1,
      -1,    -1,   121,    -1,   123,   124,   125,   126,    -1,   128,
      -1,    -1,    -1,   132,   133,   134,   135,   136,    -1,    -1,
      -1,    -1,    -1,    -1,   143,   144,   145,   146,   147,   148,
     149,   150,    -1,    -1,   153,   154,   155,   156,   157,    -1,
      -1,    -1,    -1,   162,   163,   164,   165,   166,   167,   168,
     169,    -1,   171,    -1,   173,   174,    -1,    -1,   177,   178,
     179,    -1,    -1,    -1,   183,   184,   185,   186,    -1,   188,
     189,   190,    -1,   192,    -1,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,    -1,    -1,   207,   208,
     209,    -1,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,    -1,   256,   257,   258,
      -1,   260,   261,   262,   263,   264,   265,    -1,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    21,    22,
      23,    24,    -1,    -1,    27,    -1,    -1,    -1,    31,    32,
      -1,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      -1,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    -1,    92,
      93,    94,    95,    96,    97,    98,    99,    -1,    -1,   102,
     103,    -1,    -1,    -1,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,    -1,    -1,    -1,   121,    -1,
     123,   124,   125,   126,    -1,   128,    -1,    -1,    -1,   132,
     133,   134,   135,   136,    -1,    -1,    -1,    -1,    -1,    -1,
     143,   144,   145,   146,   147,   148,   149,   150,    -1,    -1,
     153,   154,   155,   156,   157,    -1,    -1,    -1,    -1,   162,
     163,   164,   165,   166,   167,   168,   169,    -1,   171,    -1,
     173,   174,    -1,    -1,   177,   178,   179,    -1,   181,    -1,
     183,    -1,   185,   186,    -1,   188,   189,   190,    -1,   192,
      -1,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,    -1,    -1,   207,   208,   209,    -1,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,    -1,   256,   257,   258,    -1,   260,   261,   262,
     263,   264,   265,    -1,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    19,    20,    21,    22,    23,    24,    -1,    -1,
      27,    -1,    -1,    -1,    31,    32,    -1,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    -1,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    -1,    92,    93,    94,    95,    96,
      97,    98,    99,    -1,    -1,   102,   103,    -1,    -1,    -1,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,    -1,    -1,    -1,   121,    -1,   123,   124,   125,   126,
      -1,   128,    -1,    -1,    -1,   132,   133,   134,   135,   136,
      -1,    -1,    -1,    -1,    -1,    -1,   143,   144,   145,   146,
     147,   148,   149,   150,    -1,    -1,   153,   154,   155,   156,
     157,    -1,    -1,    -1,    -1,   162,   163,   164,   165,   166,
     167,   168,   169,    -1,   171,    -1,   173,   174,    -1,    -1,
     177,   178,   179,    -1,   181,    -1,   183,    -1,   185,   186,
      -1,   188,   189,   190,    -1,   192,    -1,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,    -1,    -1,
     207,   208,   209,    -1,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,    -1,   256,
     257,   258,    -1,   260,   261,   262,   263,   264,   265,    -1,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,
      21,    22,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,
      31,    32,    -1,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    -1,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    -1,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      -1,    92,    93,    94,    95,    96,    97,    98,    99,    -1,
      -1,   102,   103,    -1,    -1,    -1,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,    -1,    -1,    -1,
     121,    -1,   123,   124,   125,   126,    -1,   128,    -1,    -1,
      -1,   132,   133,   134,   135,   136,    -1,    -1,    -1,    -1,
      -1,    -1,   143,   144,   145,   146,   147,   148,   149,   150,
      -1,    -1,   153,   154,   155,   156,   157,    -1,    -1,    -1,
      -1,   162,   163,   164,   165,   166,   167,   168,   169,    -1,
     171,    -1,   173,   174,    -1,    -1,   177,   178,   179,    -1,
      -1,    -1,   183,    -1,   185,   186,    -1,   188,   189,   190,
      -1,   192,    -1,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,    -1,    -1,   207,   208,   209,    -1,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,    -1,   256,   257,   258,    -1,   260,
     261,   262,   263,   264,   265,    -1,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    19,    20,    21,    22,    23,    24,
      -1,    -1,    27,    -1,    -1,    -1,    31,    32,    -1,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    -1,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    -1,    92,    93,    94,
      95,    96,    97,    98,    99,    -1,    -1,   102,   103,    -1,
      -1,    -1,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,    -1,    -1,    -1,   121,    -1,   123,   124,
     125,   126,    -1,   128,    -1,    -1,    -1,   132,   133,   134,
     135,   136,    -1,    -1,    -1,    -1,    -1,    -1,   143,   144,
     145,   146,   147,   148,   149,   150,    -1,    -1,   153,   154,
     155,   156,   157,    -1,    -1,    -1,    -1,   162,   163,   164,
     165,   166,   167,   168,   169,    -1,   171,    -1,   173,   174,
      -1,    -1,   177,   178,   179,    -1,    -1,    -1,   183,    -1,
     185,   186,    -1,   188,   189,   190,    -1,   192,    -1,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
      -1,    -1,   207,   208,   209,    -1,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,   256,   257,   258,    -1,   260,   261,   262,   263,   264,
     265,    -1,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      19,    20,    21,    22,    23,    24,    -1,    -1,    27,    -1,
      -1,    -1,    31,    32,    -1,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    -1,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    -1,    92,    93,    94,    95,    96,    97,    98,
      99,    -1,    -1,   102,   103,    -1,    -1,    -1,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,    -1,
      -1,    -1,   121,    -1,   123,   124,   125,   126,    -1,   128,
      -1,    -1,    -1,   132,   133,   134,   135,   136,    -1,    -1,
      -1,    -1,    -1,    -1,   143,   144,   145,   146,   147,   148,
     149,   150,    -1,    -1,   153,   154,   155,   156,   157,    -1,
      -1,    -1,    -1,   162,   163,   164,   165,   166,   167,   168,
     169,    -1,   171,    -1,   173,   174,    -1,    -1,   177,   178,
     179,    -1,    -1,    -1,   183,    -1,   185,   186,    -1,   188,
     189,   190,    -1,   192,    -1,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,    -1,    -1,   207,   208,
     209,    -1,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,    -1,   256,   257,   258,
      -1,   260,   261,   262,   263,   264,   265,    -1,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    21,    22,
      23,    24,    -1,    -1,    27,    -1,    -1,    -1,    31,    32,
      -1,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      -1,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    -1,    92,
      93,    94,    95,    96,    97,    98,    99,    -1,    -1,   102,
     103,    -1,    -1,    -1,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,    -1,    -1,    -1,   121,    -1,
     123,   124,   125,   126,    -1,   128,    -1,    -1,    -1,   132,
     133,   134,   135,   136,    -1,    -1,    -1,    -1,    -1,    -1,
     143,   144,   145,   146,   147,   148,   149,   150,    -1,    -1,
     153,   154,   155,   156,   157,    -1,    -1,    -1,    -1,   162,
     163,   164,   165,   166,   167,   168,   169,    -1,   171,    -1,
     173,   174,    -1,    -1,   177,   178,   179,    -1,    -1,    -1,
     183,    -1,   185,   186,    -1,   188,   189,   190,    -1,   192,
      -1,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,    -1,    -1,   207,   208,   209,    -1,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,    -1,   256,   257,   258,    -1,   260,   261,   262,
     263,   264,   265,    -1,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    19,    20,    21,    22,    23,    24,    -1,    -1,
      27,    -1,    -1,    -1,    31,    32,    -1,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    -1,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    -1,    92,    93,    94,    95,    96,
      97,    98,    99,    -1,    -1,   102,   103,    -1,    -1,    -1,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,    -1,    -1,    -1,   121,    -1,   123,   124,   125,   126,
      -1,   128,    -1,    -1,    -1,   132,   133,   134,   135,   136,
      -1,    -1,    -1,    -1,    -1,    -1,   143,   144,   145,   146,
     147,   148,   149,   150,    -1,    -1,   153,   154,   155,   156,
     157,    -1,    -1,    -1,    -1,   162,   163,   164,   165,   166,
     167,   168,   169,    -1,   171,    -1,   173,   174,    -1,    -1,
     177,   178,   179,    -1,    -1,    -1,   183,    -1,   185,   186,
      -1,   188,   189,   190,    -1,   192,    -1,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,    -1,    -1,
     207,   208,   209,    -1,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,    -1,   256,
     257,   258,    -1,   260,   261,   262,   263,   264,   265,    -1,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,
      21,    22,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,
      31,    32,    -1,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    -1,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    -1,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      -1,    92,    93,    94,    95,    96,    97,    98,    99,    -1,
      -1,   102,   103,    -1,    -1,    -1,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,    -1,    -1,    -1,
     121,    -1,   123,   124,   125,   126,    -1,   128,    -1,    -1,
      -1,   132,   133,   134,   135,   136,    -1,    -1,    -1,    -1,
      -1,    -1,   143,   144,   145,   146,   147,   148,   149,   150,
      -1,    -1,   153,   154,   155,   156,   157,    -1,    -1,    -1,
      -1,   162,   163,   164,   165,   166,   167,   168,   169,    -1,
     171,    -1,   173,   174,    -1,    -1,   177,   178,   179,    -1,
      -1,    -1,   183,    -1,   185,   186,    -1,   188,   189,   190,
      -1,   192,    -1,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,    -1,    -1,   207,   208,   209,    -1,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,    -1,   256,   257,   258,    -1,   260,
     261,   262,   263,   264,   265,    -1,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    19,    20,    21,    22,    23,    24,
      -1,    -1,    27,    -1,    -1,    -1,    31,    32,    -1,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    -1,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    -1,    92,    93,    94,
      95,    96,    97,    98,    99,    -1,    -1,   102,   103,    -1,
      -1,    -1,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,    -1,    -1,    -1,   121,    -1,   123,   124,
     125,   126,    -1,   128,    -1,    -1,    -1,   132,   133,   134,
     135,   136,    -1,    -1,    -1,    -1,    -1,    -1,   143,   144,
     145,   146,   147,   148,   149,   150,    -1,    -1,   153,   154,
     155,   156,   157,    -1,    -1,    -1,    -1,   162,   163,   164,
     165,   166,   167,   168,   169,    -1,   171,    -1,   173,   174,
      -1,    -1,   177,   178,   179,    -1,    -1,    -1,   183,    -1,
     185,   186,    -1,   188,   189,   190,    -1,   192,    -1,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
      -1,    -1,   207,   208,   209,    -1,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,   256,   257,   258,    -1,   260,   261,   262,   263,   264,
     265,    -1,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      19,    20,    21,    22,    23,    24,    -1,    -1,    27,    -1,
      -1,    -1,    31,    32,    -1,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    -1,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    -1,    92,    93,    94,    95,    96,    97,    98,
      99,    -1,    -1,   102,   103,    -1,    -1,    -1,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,    -1,
      -1,    -1,   121,    -1,   123,   124,   125,   126,    -1,   128,
      -1,    -1,    -1,   132,   133,   134,   135,   136,    -1,    -1,
      -1,    -1,    -1,    -1,   143,   144,   145,   146,   147,   148,
     149,   150,    -1,    -1,   153,   154,   155,   156,   157,    -1,
      -1,    -1,    -1,   162,   163,   164,   165,   166,   167,   168,
     169,    -1,   171,    -1,   173,   174,    -1,    -1,   177,   178,
     179,    -1,    -1,    -1,   183,    -1,   185,   186,    -1,   188,
     189,   190,    -1,   192,    -1,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,    -1,    -1,   207,   208,
     209,    -1,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,    -1,   256,   257,   258,
      -1,   260,   261,   262,   263,   264,   265,    -1,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    21,    22,
      23,    24,    -1,    -1,    27,    -1,    -1,    -1,    31,    32,
      -1,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      -1,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    -1,    92,
      93,    94,    95,    96,    97,    98,    99,    -1,    -1,   102,
     103,    -1,    -1,    -1,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,    -1,    -1,    -1,   121,    -1,
     123,   124,   125,   126,    -1,   128,    -1,    -1,    -1,   132,
     133,   134,   135,   136,    -1,    -1,    -1,    -1,    -1,    -1,
     143,   144,   145,   146,   147,   148,   149,   150,    -1,    -1,
     153,   154,   155,   156,   157,    -1,    -1,    -1,    -1,   162,
     163,   164,   165,   166,   167,   168,   169,    -1,   171,    -1,
     173,   174,    -1,    -1,   177,   178,   179,    -1,    -1,    -1,
     183,    -1,   185,   186,    -1,   188,   189,   190,    -1,   192,
      -1,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,    -1,    -1,   207,   208,   209,    -1,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,    -1,   256,   257,   258,    -1,   260,   261,   262,
     263,   264,   265,    -1,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    19,    20,    21,    22,    23,    24,    -1,    -1,
      27,    -1,    -1,    -1,    31,    32,    -1,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    -1,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    -1,    92,    93,    94,    95,    96,
      97,    98,    99,    -1,    -1,   102,   103,    -1,    -1,    -1,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,    -1,    -1,    -1,   121,    -1,   123,   124,   125,   126,
      -1,   128,    -1,    -1,    -1,   132,   133,   134,   135,   136,
      -1,    -1,    -1,    -1,    -1,    -1,   143,   144,   145,   146,
     147,   148,   149,   150,    -1,    -1,   153,   154,    -1,   156,
     157,    -1,    -1,    -1,    -1,   162,   163,   164,   165,   166,
     167,   168,   169,    -1,   171,    -1,    -1,    -1,    -1,    -1,
     177,   178,   179,    -1,    -1,    -1,   183,    -1,   185,   186,
      -1,   188,   189,   190,    -1,   192,    -1,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,    -1,    -1,
     207,   208,   209,    -1,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,    -1,   256,
     257,   258,    -1,   260,   261,   262,   263,   264,   265,    -1,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,
      21,    22,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,
      31,    32,    -1,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    -1,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    -1,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      -1,    92,    93,    94,    95,    96,    97,    98,    99,    -1,
      -1,   102,   103,    -1,    -1,    -1,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,    -1,    -1,    -1,
     121,    -1,   123,   124,   125,   126,    -1,   128,    -1,    -1,
      -1,   132,   133,   134,   135,   136,    -1,    -1,    -1,    -1,
      -1,    -1,   143,   144,   145,   146,   147,   148,   149,   150,
      -1,    -1,   153,   154,    -1,   156,   157,    -1,    -1,    -1,
      -1,   162,   163,   164,   165,   166,   167,   168,   169,    -1,
     171,    -1,    -1,    -1,    -1,    -1,   177,   178,   179,    -1,
      -1,    -1,   183,    -1,   185,   186,    -1,    -1,    -1,   190,
      -1,   192,    -1,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,    -1,    -1,   207,   208,   209,    -1,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,    -1,   256,   257,   258,    -1,   260,
     261,   262,   263,   264,   265,    -1,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    19,    -1,    -1,    -1,    23,    24,
      -1,    -1,    27,    -1,    -1,    -1,    31,    32,    -1,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    -1,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    -1,    92,    93,    94,
      95,    -1,    97,    98,    99,    -1,    -1,   102,   103,    -1,
      -1,    -1,    -1,   108,   109,   110,   111,   112,   113,   114,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,   124,
     125,   126,    -1,   128,    -1,    -1,    -1,   132,   133,   134,
     135,   136,    -1,    -1,    -1,    -1,    -1,    -1,   143,   144,
     145,    -1,   147,   148,   149,    -1,    -1,    -1,    -1,    -1,
      -1,   156,   157,    -1,    -1,    -1,    -1,   162,   163,   164,
     165,   166,   167,   168,   169,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   177,   178,   179,    -1,    -1,    -1,   183,    -1,
     185,   186,    -1,    -1,    -1,   190,    -1,   192,    -1,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
      -1,    -1,   207,   208,    -1,    -1,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,   256,   257,   258,    -1,   260,   261,   262,   263,   264,
     265,    -1,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      19,    -1,    -1,    -1,    23,    24,    -1,    -1,    27,    -1,
      -1,    -1,    31,    32,    -1,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    -1,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    -1,    92,    93,    94,    95,    -1,    97,    98,
      99,    -1,    -1,   102,   103,    -1,    -1,    -1,    -1,   108,
     109,   110,   111,   112,   113,   114,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   123,   124,   125,   126,    -1,   128,
      -1,    -1,    -1,   132,   133,   134,   135,   136,    -1,    -1,
      -1,    -1,    -1,    -1,   143,   144,   145,    -1,   147,   148,
     149,    -1,    -1,    -1,    -1,    -1,    -1,   156,   157,    -1,
      -1,    -1,    -1,   162,   163,   164,   165,   166,   167,   168,
     169,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,   178,
     179,    -1,    -1,    -1,   183,    -1,   185,   186,    -1,    -1,
      -1,   190,    -1,   192,    -1,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,    -1,    -1,   207,   208,
      -1,    -1,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,    -1,   256,   257,   258,
      -1,   260,   261,   262,   263,   264,   265,    -1,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    23,    24,    -1,    -1,
      27,    -1,    -1,    -1,    31,    32,    -1,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    -1,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    -1,    92,    93,    94,    95,    -1,
      97,    98,    99,    -1,    -1,   102,   103,    -1,    -1,    -1,
      -1,   108,   109,   110,   111,   112,   113,   114,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   123,   124,   125,   126,
      -1,   128,    -1,    -1,    -1,   132,   133,   134,   135,   136,
      -1,    -1,    -1,    -1,    -1,    -1,   143,   144,   145,    -1,
     147,   148,   149,    -1,    -1,    -1,    -1,    -1,    -1,   156,
     157,    -1,    -1,    -1,    -1,   162,   163,   164,   165,   166,
     167,   168,   169,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     177,   178,   179,    -1,    -1,    -1,   183,   184,   185,   186,
      -1,    -1,    -1,    -1,    -1,   192,    -1,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,    -1,    -1,
     207,   208,    -1,    -1,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,    -1,   256,
     257,   258,    -1,   260,   261,   262,   263,   264,   265,    -1,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    24,
      -1,    -1,    27,    -1,    -1,    -1,    31,    32,    -1,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    -1,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    -1,    92,    93,    94,
      95,    -1,    97,    98,    99,    -1,    -1,   102,   103,    -1,
      -1,    -1,    -1,   108,   109,   110,   111,   112,   113,   114,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,   124,
     125,   126,    -1,   128,    -1,    -1,    -1,   132,   133,   134,
     135,   136,    -1,    -1,    -1,    -1,    -1,    -1,   143,   144,
     145,    -1,   147,   148,   149,    -1,    -1,    -1,    -1,    -1,
      -1,   156,   157,    -1,    -1,    -1,    -1,   162,   163,   164,
     165,   166,   167,   168,   169,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   177,   178,   179,    -1,    -1,    -1,   183,    -1,
     185,   186,    -1,    -1,    -1,    -1,    -1,   192,    -1,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
      -1,    -1,   207,   208,    -1,    -1,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,   256,   257,   258,    -1,   260,   261,   262,   263,   264,
     265,    -1,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,    17,    18,    -1,    -1,    -1,    -1,    23,    24,
      -1,    -1,    27,    -1,    -1,    -1,    31,    32,    -1,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    -1,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    -1,    92,    93,    94,
      95,    -1,    97,    98,    99,    -1,    -1,   102,   103,    -1,
      -1,    -1,    -1,   108,   109,   110,   111,   112,   113,   114,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,   124,
     125,   126,    -1,   128,    -1,    -1,    -1,   132,   133,   134,
     135,   136,    -1,    -1,    -1,    -1,    -1,    -1,   143,   144,
     145,    -1,   147,   148,   149,    -1,    -1,    -1,    -1,    -1,
      -1,   156,   157,    -1,    -1,    -1,    -1,   162,   163,   164,
     165,   166,   167,   168,   169,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   177,   178,   179,    -1,    -1,    -1,   183,    -1,
     185,   186,    -1,    -1,    -1,    -1,    -1,   192,    -1,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
      -1,    -1,   207,   208,    -1,    -1,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,   256,   257,   258,    -1,   260,   261,   262,   263,   264,
     265,    -1,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,
      31,    32,    -1,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    -1,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    -1,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      -1,    92,    93,    94,    95,    -1,    97,    98,    99,    -1,
      -1,   102,   103,    -1,    -1,    -1,    -1,   108,   109,   110,
     111,   112,   113,   114,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   123,   124,   125,   126,    -1,   128,    -1,    -1,
      -1,   132,   133,   134,   135,   136,    -1,    -1,    -1,    -1,
      -1,    -1,   143,   144,   145,    -1,   147,   148,   149,    -1,
      -1,    -1,   153,    -1,    -1,   156,   157,    -1,    -1,    -1,
      -1,   162,   163,   164,   165,   166,   167,   168,   169,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   177,   178,   179,    -1,
      -1,    -1,   183,   184,   185,   186,    -1,    -1,    -1,   190,
      -1,   192,    -1,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,    -1,    -1,   207,   208,    -1,    -1,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,    -1,   256,   257,   258,    -1,   260,
     261,   262,   263,   264,   265,    -1,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,    23,    24,    -1,    -1,
      27,    -1,    -1,    -1,    31,    32,    -1,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    -1,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    -1,    92,    93,    94,    95,    -1,
      97,    98,    99,    -1,    -1,   102,   103,    -1,    -1,    -1,
      -1,   108,   109,   110,   111,   112,   113,   114,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   123,   124,   125,   126,
      -1,   128,    -1,    -1,    -1,   132,   133,   134,   135,   136,
      -1,    -1,    -1,    -1,    -1,    -1,   143,   144,   145,    -1,
     147,   148,   149,    -1,    -1,    -1,    -1,    -1,    -1,   156,
     157,    -1,    -1,    -1,    -1,   162,   163,   164,   165,   166,
     167,   168,   169,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     177,   178,   179,    -1,    -1,    -1,   183,   184,   185,   186,
      -1,    -1,    -1,   190,    -1,   192,    -1,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,    -1,    -1,
     207,   208,    -1,    -1,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,    -1,   256,
     257,   258,    -1,   260,   261,   262,   263,   264,   265,    -1,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
      23,    24,    -1,    -1,    27,    -1,    -1,    -1,    31,    32,
      -1,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      -1,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    -1,    92,
      93,    94,    95,    -1,    97,    98,    99,    -1,    -1,   102,
     103,    -1,    -1,    -1,    -1,   108,   109,   110,   111,   112,
     113,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     123,   124,   125,   126,    -1,   128,    -1,    -1,    -1,   132,
     133,   134,   135,   136,    -1,    -1,    -1,    -1,    -1,    -1,
     143,   144,   145,    -1,   147,   148,   149,    -1,    -1,    -1,
      -1,    -1,    -1,   156,   157,    -1,    -1,    -1,    -1,   162,
     163,   164,   165,   166,   167,   168,   169,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   177,   178,   179,    -1,    -1,    -1,
     183,   184,   185,   186,    -1,    -1,    -1,   190,    -1,   192,
      -1,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,    -1,    -1,   207,   208,    -1,    -1,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,    -1,   256,   257,   258,    -1,   260,   261,   262,
     263,   264,   265,    -1,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,    23,    24,    -1,    -1,    27,    -1,
      -1,    -1,    31,    32,    -1,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    -1,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    -1,    92,    93,    94,    95,    -1,    97,    98,
      99,    -1,    -1,   102,   103,    -1,    -1,    -1,    -1,   108,
     109,   110,   111,   112,   113,   114,   115,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   123,   124,   125,   126,    -1,   128,
      -1,    -1,    -1,   132,   133,   134,   135,   136,    -1,    -1,
      -1,    -1,    -1,    -1,   143,   144,   145,    -1,   147,   148,
     149,    -1,    -1,    -1,   153,    -1,    -1,   156,   157,    -1,
      -1,    -1,    -1,   162,   163,   164,   165,   166,   167,   168,
     169,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,   178,
     179,    -1,    -1,    -1,   183,    -1,   185,   186,    -1,    -1,
      -1,    -1,    -1,   192,    -1,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,    -1,    -1,   207,   208,
      -1,    -1,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,    -1,   256,   257,   258,
      -1,   260,   261,   262,   263,   264,   265,    -1,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,    23,    24,
      -1,    -1,    27,    -1,    -1,    -1,    31,    32,    -1,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    -1,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    -1,    92,    93,    94,
      95,    -1,    97,    98,    99,    -1,    -1,   102,   103,    -1,
      -1,    -1,    -1,   108,   109,   110,   111,   112,   113,   114,
     115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,   124,
     125,   126,    -1,   128,    -1,    -1,    -1,   132,   133,   134,
     135,   136,    -1,    -1,    -1,    -1,    -1,    -1,   143,   144,
     145,    -1,   147,   148,   149,    -1,    -1,    -1,   153,    -1,
      -1,   156,   157,    -1,    -1,    -1,    -1,   162,   163,   164,
     165,   166,   167,   168,   169,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   177,   178,   179,    -1,    -1,    -1,   183,    -1,
     185,   186,    -1,    -1,    -1,    -1,    -1,   192,    -1,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
      -1,    -1,   207,   208,    -1,    -1,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,   256,   257,   258,    -1,   260,   261,   262,   263,   264,
     265,    -1,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,
      31,    32,    -1,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    -1,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    -1,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      -1,    92,    93,    94,    95,    -1,    97,    98,    99,    -1,
      -1,   102,   103,    -1,    -1,    -1,    -1,   108,   109,   110,
     111,   112,   113,   114,   115,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   123,   124,   125,   126,    -1,   128,    -1,    -1,
      -1,   132,   133,   134,   135,   136,    -1,    -1,    -1,    -1,
      -1,    -1,   143,   144,   145,    -1,   147,   148,   149,    -1,
      -1,    -1,   153,    -1,    -1,   156,   157,    -1,    -1,    -1,
      -1,   162,   163,   164,   165,   166,   167,   168,   169,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   177,   178,   179,    -1,
      -1,    -1,   183,    -1,   185,   186,    -1,    -1,    -1,    -1,
      -1,   192,    -1,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,    -1,    -1,   207,   208,    -1,    -1,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,    -1,   256,   257,   258,    -1,   260,
     261,   262,   263,   264,   265,    -1,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,    23,    24,    -1,    -1,
      27,    -1,    -1,    -1,    31,    32,    -1,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    -1,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    -1,    92,    93,    94,    95,    -1,
      97,    98,    99,    -1,    -1,   102,   103,    -1,    -1,    -1,
      -1,   108,   109,   110,   111,   112,   113,   114,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   123,   124,   125,   126,
      -1,   128,    -1,    -1,    -1,   132,   133,   134,   135,   136,
      -1,    -1,    -1,    -1,    -1,    -1,   143,   144,   145,    -1,
     147,   148,   149,    -1,    -1,    -1,   153,    -1,    -1,   156,
     157,    -1,    -1,    -1,    -1,   162,   163,   164,   165,   166,
     167,   168,   169,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     177,   178,   179,    -1,    -1,    -1,   183,    -1,   185,   186,
      -1,    -1,    -1,    -1,    -1,   192,    -1,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,    -1,    -1,
     207,   208,    -1,    -1,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,    -1,   256,
     257,   258,    -1,   260,   261,   262,   263,   264,   265,    -1,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
      23,    24,    -1,    -1,    27,    -1,    -1,    -1,    31,    32,
      -1,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      -1,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    -1,    92,
      93,    94,    95,    -1,    97,    98,    99,    -1,    -1,   102,
     103,    -1,    -1,    -1,    -1,   108,   109,   110,   111,   112,
     113,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     123,   124,   125,   126,    -1,   128,    -1,    -1,    -1,   132,
     133,   134,   135,   136,    -1,    -1,    -1,    -1,    -1,    -1,
     143,   144,   145,    -1,   147,   148,   149,    -1,    -1,    -1,
     153,    -1,    -1,   156,   157,    -1,    -1,    -1,    -1,   162,
     163,   164,   165,   166,   167,   168,   169,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   177,   178,   179,    -1,    -1,    -1,
     183,    -1,   185,   186,    -1,    -1,    -1,    -1,    -1,   192,
      -1,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,    -1,    -1,   207,   208,    -1,    -1,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,    -1,   256,   257,   258,    -1,   260,   261,   262,
     263,   264,   265,    -1,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,    23,    24,    -1,    -1,    27,    -1,
      -1,    -1,    31,    32,    -1,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    -1,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    -1,    92,    93,    94,    95,    -1,    97,    98,
      99,    -1,    -1,   102,   103,    -1,    -1,    -1,    -1,   108,
     109,   110,   111,   112,   113,   114,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   123,   124,   125,   126,    -1,   128,
      -1,    -1,    -1,   132,   133,   134,   135,   136,    -1,    -1,
      -1,    -1,    -1,    -1,   143,   144,   145,    -1,   147,   148,
     149,    -1,    -1,    -1,    -1,    -1,    -1,   156,   157,    -1,
      -1,    -1,    -1,   162,   163,   164,   165,   166,   167,   168,
     169,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,   178,
     179,    -1,    -1,    -1,   183,    -1,   185,   186,    -1,    -1,
      -1,    -1,    -1,   192,    -1,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,    -1,    -1,   207,   208,
      -1,    -1,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,    -1,   256,   257,   258,
      -1,   260,   261,   262,   263,   264,   265,    -1,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,    23,    24,
      -1,    -1,    27,    -1,    -1,    -1,    31,    32,    -1,    34,
      35,    36,    -1,    38,    39,    40,    41,    -1,    -1,    44,
      45,    46,    -1,    48,    49,    50,    51,    52,    -1,    54,
      55,    56,    57,    -1,    59,    -1,    -1,    62,    63,    64,
      65,    66,    -1,    68,    -1,    70,    -1,    -1,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    -1,    92,    93,    94,
      -1,    -1,    97,    98,    99,    -1,    -1,   102,   103,    -1,
      -1,    -1,    -1,   108,   109,   110,   111,   112,   113,   114,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,   124,
     125,   126,    -1,   128,    -1,    -1,    -1,   132,   133,   134,
     135,   136,    -1,    -1,    -1,    -1,    -1,    -1,   143,   144,
     145,    -1,   147,   148,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   156,   157,    -1,    -1,    -1,    -1,   162,   163,   164,
     165,   166,   167,   168,   169,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   177,   178,   179,    -1,    -1,    -1,   183,    -1,
     185,   186,    -1,    -1,    -1,    -1,    -1,   192,    -1,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
      -1,    -1,    -1,   208,    -1,    -1,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,    -1,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,    -1,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,   256,   257,   258,    -1,   260,   261,   262,   263,   264,
     265,    -1,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  xquery_parser::yystos_[] =
  {
         0,    11,    19,    20,    21,    22,    23,    24,    27,    31,
      32,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    92,    93,    94,    95,
      96,    97,    98,    99,   102,   103,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   121,   123,   124,
     125,   126,   128,   132,   133,   134,   135,   136,   143,   144,
     145,   146,   147,   148,   149,   150,   153,   154,   155,   156,
     157,   162,   163,   164,   165,   166,   167,   168,   169,   171,
     173,   174,   177,   178,   179,   183,   185,   186,   188,   189,
     190,   192,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   207,   208,   209,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     256,   257,   258,   260,   261,   262,   263,   264,   265,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     322,   324,   325,   326,   327,   328,   329,   330,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   340,   343,   344,
     345,   346,   347,   348,   352,   353,   354,   358,   363,   372,
     375,   378,   379,   380,   382,   383,   384,   385,   386,   388,
     389,   391,   392,   393,   394,   395,   396,   398,   399,   402,
     403,   404,   405,   410,   412,   414,   415,   420,   439,   442,
     446,   449,   450,   455,   456,   457,   458,   460,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   496,   497,
     498,   499,   500,   501,   502,   503,   504,   506,   507,   508,
     522,   523,   525,   526,   527,   528,   529,   530,   531,   539,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   551,
     552,   553,   554,   559,   560,   561,   562,   563,   564,   567,
     625,   627,   628,   629,    31,    32,    48,   211,   381,   382,
     383,   381,   381,    25,    35,    36,    38,    39,    46,    55,
      56,    73,    77,   108,   109,   110,   157,   166,   198,   216,
     226,   258,   284,   285,   286,   287,   288,   290,   291,   292,
     293,   294,   299,   300,   359,   360,   361,   364,   365,   366,
     370,   371,   157,   150,   153,   150,   153,   150,   153,    65,
      70,   115,   407,   153,   367,   153,    23,    32,    59,   115,
     270,   419,   421,   422,   150,   153,   153,   153,   115,   150,
     153,   153,   153,    92,   150,   217,   218,   119,   119,   119,
     150,   153,    27,    37,    41,    43,    45,    46,    47,    50,
      58,    66,    69,    71,    72,    74,    88,    89,    95,   102,
     109,   111,   112,   132,   135,   136,   166,   169,   177,   178,
     186,   198,   220,   222,   224,   225,   232,   234,   235,   236,
     237,   240,   241,   490,   627,   628,   119,   115,   390,   119,
     119,    37,    42,    43,    58,    60,    61,    69,    95,   221,
     627,   115,   119,   119,   181,   381,   383,    47,    71,    72,
     115,   150,   184,   241,   402,   404,   414,   627,   150,   119,
      15,   626,   627,    17,    18,   627,   119,   119,   119,   482,
     150,    28,   210,   212,   221,   223,   153,   221,   223,   221,
     221,   226,   115,   109,   238,   238,   239,   153,   150,   385,
     324,     0,   326,   327,    31,    48,   329,   346,     1,   187,
     323,   187,   323,   384,   402,   104,   187,   104,   187,    40,
      45,    50,    68,   165,   168,   183,   208,   397,   406,   411,
     412,   413,   427,   428,   432,   164,    90,   129,   137,   138,
     140,   148,   152,   154,   159,   176,   199,   200,   201,   202,
     203,   204,   474,   475,   246,   155,   173,   195,   114,   143,
     156,   190,   197,   206,   133,   147,    49,   196,    98,    99,
     155,   173,   473,   150,   479,   482,   188,   189,   151,   494,
     495,   490,   494,   490,   153,   494,   118,   142,   153,   181,
     181,   181,   153,   625,   179,   192,   179,   192,   163,   179,
     628,   627,   166,   198,    46,   627,   149,   115,    43,    46,
      77,   103,   165,   626,   217,   218,   219,   297,   298,   243,
     598,   627,   290,   627,   295,   295,   297,   298,   301,   134,
     139,   109,   361,   364,   284,   292,   371,   626,   382,   383,
     184,   381,    43,    61,   184,   547,   548,   402,   184,   190,
     627,   281,   281,   416,   417,   627,   115,   423,   115,   184,
     368,   369,   150,   387,   402,     1,   157,   625,   110,   157,
     342,   625,   627,   115,   139,   104,   402,    27,   184,   626,
     627,   627,   440,   441,   627,   382,   184,   402,   402,   549,
     627,   382,   150,   150,   402,   184,   190,   627,   627,   139,
     440,   181,   181,   153,   153,   153,   627,   150,   184,   183,
      33,   510,   511,   512,   402,     8,   172,    16,   402,   210,
      27,   403,   403,   184,   403,   403,   403,   403,   227,   565,
     566,   627,   390,   187,   187,   403,   402,   383,   402,   242,
     400,   401,   187,   323,   187,   323,     3,   330,   346,   379,
     330,   346,   379,    31,   347,   379,   347,   379,   390,   403,
     115,   165,   167,   167,   384,   403,   403,   457,   458,   460,
     460,   460,   460,   459,   460,   460,   460,    69,   464,   464,
     463,   465,   465,   465,   465,   466,   466,   467,   467,   227,
      92,    92,    92,   181,   402,   482,   482,   402,   495,   184,
     403,   505,   626,   146,   184,   505,    27,   362,   497,   104,
     104,   367,    27,   628,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,   349,   350,   351,    92,   134,   139,
     355,   356,   357,   627,   157,   157,   349,   625,   124,   129,
      53,    55,    97,   248,   261,   263,   274,   275,   276,   278,
     280,   599,   600,   601,   602,   603,   604,   611,   617,   618,
     243,    92,   233,   374,   296,   627,   139,   403,   115,   627,
     627,   129,   181,   181,   184,   184,   181,   104,   184,   104,
     184,   104,    34,    92,    94,   144,   418,   419,   533,   627,
      54,   213,   251,   408,   409,   627,    92,   104,   184,   381,
     184,   626,    94,    43,   626,   625,    94,   139,   533,   627,
     403,   422,   181,   184,   184,   184,   184,   104,   185,   144,
     533,   181,   184,   184,   150,   181,   382,   382,   181,   104,
     184,   104,   184,   139,   533,   403,   185,   402,   402,   402,
     627,   511,   512,   127,   193,   181,   181,   128,   187,    92,
     214,   215,   229,    92,   214,   215,   229,    92,   233,   221,
     104,   231,   139,   187,   184,    47,    71,    72,   241,   404,
     414,   181,   491,   571,   401,   346,    31,    31,   187,   323,
     187,   110,   627,   167,   403,   433,   434,   115,   429,   430,
     460,   150,   153,   256,   478,   497,   572,   575,   576,   577,
     578,   579,   583,   585,   587,   588,    46,   149,   153,   207,
     534,   536,   538,   539,   555,   556,   557,   558,   627,   534,
     532,   538,   532,   181,   182,   104,   184,   184,   104,   184,
     145,   162,   145,   162,   134,   387,   367,   350,   129,   536,
     357,   403,   533,   625,   625,   125,   126,   625,   274,   275,
     276,   280,   627,   260,   271,   260,   271,    27,   283,    94,
     110,   153,   605,   608,   599,    37,    42,    58,    60,    69,
      95,   221,   373,   539,   288,   289,   223,   296,   305,   403,
     627,    92,   374,   296,   625,   150,   549,   550,   627,   549,
     550,   115,   124,   534,   115,   403,   144,   419,   144,    34,
     144,   418,   419,   144,   533,   251,    52,    57,    75,   115,
     418,   424,   425,   426,   409,   533,   534,   369,    92,   181,
     194,   129,   341,   625,   157,   129,    94,   341,   403,   139,
     419,   150,   115,   403,   403,   144,    97,   443,   444,   445,
     447,   448,    97,   451,   452,   453,   454,   382,   181,   181,
     150,   549,   549,   403,   139,   187,   403,   184,   184,   184,
      33,   512,   127,   193,     9,    10,   100,   120,   122,   150,
     191,   507,   509,   520,   521,   524,    27,   228,   230,   403,
     403,   403,   228,   230,   403,   403,   403,   403,   403,   403,
     115,   403,   403,   384,   153,   153,   153,   150,   183,   242,
     568,   569,   153,   206,   385,   187,   110,   379,   379,   379,
     433,    93,   103,   113,   124,   435,   436,   437,   438,   104,
     627,   104,   402,   572,   579,   150,   282,   461,   624,    94,
     166,   249,   250,   252,   259,   269,   281,   573,   574,   593,
     594,   595,   596,   619,   622,   255,   257,   580,   598,   264,
     584,   620,   244,   245,   267,   589,   590,   153,   153,   536,
     153,   141,   173,   190,   535,   141,   403,   497,   134,   387,
     551,   356,   283,    27,    94,   110,   153,   612,    27,   605,
     374,   535,   223,   223,   480,   284,   303,   533,   373,   223,
     187,   381,   184,   184,   141,   184,   184,   417,   144,   418,
     627,   403,   144,   403,   124,   403,   144,   419,   144,   403,
     144,   115,   115,   403,   627,   426,    75,   534,   384,   403,
     625,   104,   341,   403,   139,   381,   441,   403,   403,   110,
     444,   445,    97,   183,   110,   445,   448,   115,   534,    97,
     110,   452,    97,   110,   454,   181,   381,   184,   184,   403,
     194,   451,   129,   191,   509,     7,   382,   627,   191,   520,
     187,   229,   229,   229,   229,   233,   566,   183,   402,   402,
     402,   571,   569,   115,   491,   625,   125,   126,   437,   438,
     438,   434,   103,   431,   430,   181,   184,   572,   586,   247,
     213,   251,   265,   272,   623,    94,   253,   254,   621,   247,
     576,   623,   463,   593,   577,   144,   279,   581,   582,   621,
     283,   592,    76,   591,   184,   190,   534,   537,   184,   184,
     184,    27,   133,   197,   614,   615,   616,    27,   613,   614,
     268,   609,   104,   606,   167,   627,   254,   374,   480,   181,
     403,   144,   403,   144,   418,   403,   144,   403,   403,   627,
     627,   425,   403,   123,   123,    94,   625,   403,   181,   183,
     183,   403,   384,   403,   183,   183,   627,   183,   115,   534,
     115,   183,   115,   534,   183,   181,   110,   512,   627,   191,
     181,   512,   627,   403,   403,   403,   403,   403,   403,   184,
     184,   184,   150,   153,   570,   627,   438,   625,   181,   465,
      51,   126,   463,   463,   266,   273,   283,   597,   597,   578,
     150,   277,    92,   184,   104,   184,   612,   612,   616,   104,
     184,    27,   610,   621,   607,   608,   184,   376,   377,   480,
     115,   221,   304,   284,   167,   403,   403,   144,   403,    52,
     384,   403,   341,   403,   384,    92,   384,   403,   627,   183,
     627,   403,   627,   183,   384,   115,    91,   180,   513,   512,
     627,   193,   512,   194,   451,   402,   115,   104,   184,   463,
     463,   195,   402,   534,   534,    92,    27,   262,   104,   104,
     438,   533,   627,   115,   221,   627,   376,   403,   115,   534,
      92,   183,    92,   627,     5,   130,   516,   517,   519,   521,
      26,   131,   514,   515,   518,   521,   193,   512,   193,   110,
     181,   627,   115,   385,   463,   181,   534,   608,   377,   438,
     302,   627,   115,   221,   627,   183,   534,   384,   403,   534,
     183,    91,   130,   519,   180,   131,   518,   193,   115,   104,
     184,   627,   403,   302,   627,   115,   384,   403,   183,   183,
     627,   115,   570,   104,   184,   290,   302,   627,   183,   627,
     115,   385,   303,   403,   303,   104,   184,   627,   480,   480,
     115,   570,   184,   195,   627,   385,   284,   184,   627,   570,
     221,   115,   627,   303,   480
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
     575
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   321,   322,   322,   323,   324,   324,   324,   324,   325,
     325,   326,   326,   326,   326,   326,   326,   326,   326,   327,
     327,   327,   327,   328,   329,   329,   329,   330,   330,   330,
     330,   330,   331,   331,   331,   331,   331,   331,   331,   331,
     332,   332,   333,   334,   335,   335,   336,   336,   337,   337,
     338,   338,   338,   338,   339,   339,   339,   340,   340,   340,
     340,   341,   341,   342,   342,   343,   343,   343,   343,   344,
     345,   345,   346,   346,   346,   347,   347,   347,   347,   347,
     347,   347,   347,   348,   348,   349,   349,   350,   351,   351,
     351,   351,   351,   351,   351,   351,   351,   351,   352,   353,
     354,   355,   355,   356,   356,   356,   357,   358,   358,   358,
     359,   359,   359,   359,   360,   360,   361,   361,   362,   362,
     363,   363,   364,   364,   365,   365,   366,   366,   367,   367,
     367,   367,   368,   368,   369,   369,   370,   370,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   372,   372,   372,   372,   372,   372,   372,   372,
     373,   373,   374,   374,   375,   375,   376,   376,   377,   377,
     377,   377,   378,   378,   378,   378,   379,   380,   380,   380,
     381,   381,   381,   382,   382,   383,   383,   384,   384,   384,
     384,   384,   384,   384,   384,   384,   384,   384,   384,   385,
     385,   386,   387,   388,   389,   389,   389,   390,   390,   390,
     390,   391,   392,   393,   394,   395,   395,   396,   397,   398,
     399,   400,   400,   401,   401,   401,   401,   402,   402,   403,
     403,   403,   403,   403,   403,   404,   404,   404,   404,   404,
     404,   404,   405,   406,   407,   407,   408,   408,   408,   409,
     409,   410,   410,   411,   412,   412,   412,   413,   413,   413,
     413,   413,   414,   414,   415,   416,   416,   417,   417,   417,
     417,   417,   417,   417,   417,   417,   417,   417,   417,   418,
     419,   420,   421,   421,   422,   422,   422,   422,   423,   423,
     424,   424,   424,   425,   425,   425,   426,   426,   426,   427,
     428,   429,   429,   430,   430,   431,   432,   432,   433,   433,
     434,   434,   435,   435,   435,   435,   435,   435,   435,   436,
     436,   437,   437,   438,   439,   439,   440,   440,   441,   441,
     442,   443,   443,   444,   445,   445,   446,   447,   447,   448,
     449,   449,   450,   450,   451,   451,   452,   452,   453,   453,
     454,   454,   455,   456,   456,   457,   457,   458,   458,   458,
     458,   458,   459,   458,   458,   458,   458,   460,   460,   461,
     461,   462,   462,   463,   463,   463,   464,   464,   464,   464,
     464,   465,   465,   465,   466,   466,   466,   467,   467,   468,
     468,   469,   469,   470,   470,   471,   471,   472,   472,   472,
     472,   473,   473,   473,   474,   474,   474,   474,   474,   474,
     475,   475,   475,   476,   476,   476,   476,   477,   477,   478,
     478,   479,   479,   479,   480,   480,   480,   480,   481,   482,
     482,   482,   483,   483,   484,   484,   484,   484,   485,   485,
     486,   486,   486,   486,   486,   486,   486,   487,   487,   488,
     488,   489,   489,   489,   489,   489,   490,   490,   491,   491,
     492,   492,   492,   493,   493,   493,   493,   494,   494,   495,
     496,   496,   496,   496,   496,   496,   496,   496,   496,   496,
     497,   497,   498,   498,   498,   499,   500,   500,   501,   502,
     503,   504,   504,   505,   505,   506,   506,   507,   507,   507,
     508,   508,   508,   508,   508,   508,   509,   509,   510,   510,
     511,   512,   512,   513,   513,   514,   514,   515,   515,   515,
     515,   516,   516,   517,   517,   517,   517,   518,   518,   519,
     519,   520,   520,   520,   520,   521,   521,   521,   521,   522,
     522,   523,   523,   524,   525,   525,   525,   525,   525,   525,
     526,   527,   527,   528,   528,   529,   530,   531,   531,   532,
     532,   533,   534,   534,   534,   535,   535,   535,   536,   536,
     536,   536,   536,   537,   537,   538,   539,   539,   539,   539,
     539,   539,   539,   539,   539,   540,   541,   541,   541,   542,
     543,   544,   544,   544,   545,   545,   545,   545,   545,   546,
     547,   547,   547,   547,   547,   547,   547,   548,   549,   550,
     551,   552,   552,   553,   554,   555,   555,   556,   557,   557,
     558,   559,   559,   559,   560,   560,   560,   560,   560,   560,
     560,   560,   560,   560,   561,   561,   562,   562,   563,   564,
     565,   565,   566,   567,   568,   568,   569,   569,   569,   569,
     570,   571,   571,   572,   573,   573,   574,   574,   575,   575,
     576,   576,   577,   577,   578,   578,   579,   580,   580,   581,
     581,   582,   583,   583,   583,   584,   584,   585,   586,   586,
     587,   588,   588,   589,   589,   590,   590,   590,   591,   591,
     592,   592,   593,   593,   593,   593,   593,   594,   595,   596,
     597,   597,   597,   598,   598,   599,   599,   599,   599,   599,
     599,   599,   599,   600,   600,   600,   600,   601,   601,   602,
     603,   603,   604,   604,   604,   605,   605,   606,   606,   607,
     607,   608,   609,   609,   610,   610,   611,   611,   611,   612,
     612,   613,   613,   614,   614,   615,   615,   616,   616,   617,
     618,   618,   619,   619,   619,   620,   621,   621,   621,   621,
     622,   622,   623,   623,   624,   625,   626,   626,   627,   627,
     627,   627,   627,   627,   627,   627,   627,   627,   627,   627,
     627,   627,   627,   627,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   629,   629
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
       3,     4,     4,     5,     1,     2,     1,     4,     1,     3,
       2,     3,     1,     1,     4,     4,     5,     5,     2,     3,
       4,     5,     1,     3,     2,     3,     1,     2,     1,     1,
       1,     1,     1,     1,     2,     2,     2,     2,     1,     2,
       2,     2,     3,     4,     5,     6,     4,     5,     6,     7,
       1,     2,     3,     3,     8,     9,     1,     3,     1,     2,
       2,     3,    11,    14,    13,    22,     1,     1,     1,     0,
       1,     1,     0,     1,     2,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       2,     3,     3,     2,     3,     2,     3,     2,     3,     4,
       5,     5,     2,     4,     5,     3,     3,     2,     2,     8,
       3,     1,     2,     3,     7,    10,    13,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     2,     1,     1,     2,     4,
       3,     5,     4,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     3,     1,     4,     3,     5,     4,
       6,     4,     6,     5,     7,     4,     5,     5,     6,     3,
       3,     2,     1,     3,     4,     5,     3,     6,     4,     5,
       1,     2,     3,     1,     2,     1,     6,     3,     3,     2,
       3,     1,     3,     2,     3,     2,     3,     4,     1,     3,
       1,     2,     1,     1,     1,     2,     2,     2,     3,     1,
       1,     2,     2,     2,     5,     5,     1,     4,     3,     4,
       8,     1,     2,     3,     2,     3,     8,     1,     2,     3,
       8,    10,     8,    10,     1,     2,     4,     7,     1,     2,
       4,     7,     8,     1,     3,     1,     3,     1,     3,     3,
       3,     3,     0,     4,     3,     3,     3,     1,     5,     0,
       1,     1,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     1,     4,     1,
       4,     1,     4,     1,     4,     1,     2,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     5,     5,     6,     3,     4,     1,
       2,     3,     2,     2,     1,     2,     2,     1,     1,     1,
       3,     3,     1,     1,     1,     2,     1,     2,     2,     1,
       2,     2,     2,     2,     2,     2,     2,     1,     2,     2,
       1,     2,     2,     2,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     3,     4,     1,     2,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     3,     1,     4,
       4,     3,     4,     1,     3,     1,     1,     1,     1,     1,
       4,     5,     8,     9,     9,    10,     1,     2,     1,     2,
       6,     0,     1,     3,     3,     0,     1,     1,     1,     2,
       2,     0,     1,     1,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       2,     3,     3,     2,     1,     1,     1,     1,     1,     1,
       4,     3,     7,     3,     7,     4,     4,     3,     7,     1,
       2,     2,     1,     2,     3,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     4,     4,     3,
       3,     3,     4,     4,     3,     4,     6,     4,     6,     4,
       3,     4,     6,     6,     4,     6,     6,     4,     1,     2,
       1,     1,     1,     3,     3,     1,     1,     4,     5,     6,
       3,     3,     3,     3,     5,     7,     7,     5,     5,     5,
       7,     7,     5,     5,     3,     3,     5,     7,     5,     7,
       1,     4,     3,     5,     1,     2,     3,     7,    10,    13,
       3,     1,     3,     2,     0,     1,     1,     2,     1,     3,
       1,     3,     1,     4,     1,     2,     3,     0,     1,     0,
       1,     4,     2,     3,     1,     0,     1,     4,     0,     1,
       2,     1,     3,     0,     1,     2,     2,     1,     0,     1,
       0,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       1,     1,     1,     2,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     1,     1,     2,     2,     3,
       1,     2,     2,     5,     2,     1,     1,     0,     2,     1,
       3,     4,     0,     2,     0,     2,     4,     4,     3,     2,
       3,     1,     3,     0,     1,     1,     2,     2,     2,     2,
       1,     2,     2,     2,     2,     3,     2,     3,     3,     4,
       2,     2,     1,     1,     3,     1,     1,     1,     1,     1,
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
  "\"'copy-namespaces'\"", "\"'count'\"", "\"'document'\"",
  "\"'document-node'\"", "\"'element'\"", "\"'eval'\"", "\"'for'\"",
  "\"'function'\"", "\"'if'\"", "\"'import'\"", "\"'instance'\"",
  "\"'let'\"", "\"'most'\"", "\"'next'\"", "\"'no'\"", "\"'only'\"",
  "\"'option'\"", "\"'ordering'\"", "\"'previous'\"",
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
       322,     0,    -1,   324,    -1,   307,   324,    -1,     1,     3,
      -1,   326,    -1,   325,   326,    -1,   327,    -1,   325,   327,
      -1,   211,   212,    27,   187,    -1,   211,   212,    27,   128,
      27,   187,    -1,   329,   187,   379,    -1,   346,   187,   379,
      -1,   329,   187,   346,   187,   379,    -1,   379,    -1,   329,
     323,   379,    -1,   346,   323,   379,    -1,   329,   187,   346,
     323,   379,    -1,   329,   323,   346,   187,   379,    -1,   328,
      -1,   328,   329,   187,    -1,   328,   346,   187,    -1,   328,
     329,   187,   346,   187,    -1,    32,   157,   626,   129,   625,
     187,    -1,   330,    -1,   329,   187,   330,    -1,   329,   323,
     330,    -1,   331,    -1,   339,    -1,   344,    -1,   345,    -1,
     353,    -1,   332,    -1,   333,    -1,   334,    -1,   335,    -1,
     336,    -1,   337,    -1,   338,    -1,   559,    -1,    31,    36,
     179,    -1,    31,    36,   192,    -1,    31,   110,   103,   625,
      -1,    31,    35,   625,    -1,    31,    38,   179,    -1,    31,
      38,   192,    -1,    31,    56,   166,    -1,    31,    56,   198,
      -1,    31,   110,   165,   124,   125,    -1,    31,   110,   165,
     124,   126,    -1,    31,    39,   179,   104,   145,    -1,    31,
      39,   179,   104,   162,    -1,    31,    39,   163,   104,   145,
      -1,    31,    39,   163,   104,   162,    -1,   340,    -1,   343,
      -1,    48,    23,     1,    -1,    48,    59,   625,    -1,    48,
      59,   342,   625,    -1,    48,    59,   625,    94,   341,    -1,
      48,    59,   342,   625,    94,   341,    -1,   625,    -1,   341,
     104,   625,    -1,   157,   626,   129,    -1,   110,    43,   157,
      -1,    48,    32,   625,    -1,    48,    32,   157,   626,   129,
     625,    -1,    48,    32,   625,    94,   341,    -1,    48,    32,
     157,   626,   129,   625,    94,   341,    -1,    31,   157,   626,
     129,   625,    -1,    31,   110,    43,   157,   625,    -1,    31,
     110,    46,   157,   625,    -1,   347,    -1,   346,   187,   347,
      -1,   346,   323,   347,    -1,   348,    -1,   352,    -1,   354,
      -1,   358,    -1,   363,    -1,   372,    -1,   375,    -1,   378,
      -1,    31,   110,    77,   349,    -1,    31,    77,   627,   349,
      -1,   350,    -1,   349,   350,    -1,   351,   129,   551,    -1,
      78,    -1,    86,    -1,    79,    -1,    80,    -1,    81,    -1,
      82,    -1,    87,    -1,    83,    -1,    84,    -1,    85,    -1,
      31,    55,   627,    27,    -1,    31,   258,   598,    -1,    31,
     108,   149,   355,    -1,    92,   536,   356,    -1,   356,    -1,
     357,    -1,   134,    -1,   134,   357,    -1,   139,   403,    -1,
      31,   359,   139,   403,    -1,    31,   359,   134,    -1,    31,
     359,   134,   139,   403,    -1,   109,   115,   627,    -1,   109,
     115,   627,   533,    -1,   360,   109,   115,   627,    -1,   360,
     109,   115,   627,   533,    -1,   361,    -1,   360,   361,    -1,
      25,    -1,    25,   153,   362,   184,    -1,   497,    -1,   362,
     104,   497,    -1,    31,   364,    -1,    31,   360,   364,    -1,
     365,    -1,   366,    -1,    46,   628,   367,   387,    -1,    46,
     628,   367,   134,    -1,    73,    46,   628,   367,   387,    -1,
      73,    46,   628,   367,   134,    -1,   153,   184,    -1,   153,
     368,   184,    -1,   153,   184,    92,   534,    -1,   153,   368,
     184,    92,   534,    -1,   369,    -1,   368,   104,   369,    -1,
     115,   627,    -1,   115,   627,   533,    -1,   371,    -1,   370,
     371,    -1,   285,    -1,   286,    -1,   287,    -1,   288,    -1,
     166,    -1,   198,    -1,   226,   298,    -1,   226,   297,    -1,
     299,   298,    -1,   299,   297,    -1,   290,    -1,   291,   290,
      -1,   294,   295,    -1,   293,   295,    -1,    31,   284,   627,
      -1,    31,   284,   627,   374,    -1,    31,   284,   627,    92,
     373,    -1,    31,   284,   627,    92,   373,   374,    -1,    31,
     370,   284,   627,    -1,    31,   370,   284,   627,   374,    -1,
      31,   370,   284,   627,    92,   373,    -1,    31,   370,   284,
     627,    92,   373,   374,    -1,   539,    -1,   539,   535,    -1,
     233,   289,   223,    -1,   233,   288,   223,    -1,    31,   292,
     627,   296,   223,   480,   167,   376,    -1,    31,   370,   292,
     627,   296,   223,   480,   167,   376,    -1,   377,    -1,   376,
     104,   377,    -1,   480,    -1,   480,   533,    -1,   480,   438,
      -1,   480,   533,   438,    -1,    31,   300,   301,   627,   296,
     284,   627,   115,   627,   302,   403,    -1,    31,   300,   301,
     627,   296,   284,   627,   221,   115,   627,   302,   290,   303,
     480,    -1,    31,   300,   301,   627,   296,   284,   627,   304,
     221,   115,   627,   302,   403,    -1,    31,   300,   301,   627,
     305,   303,   254,   284,   627,   221,   115,   627,   303,   480,
     195,   284,   627,   221,   115,   627,   303,   480,    -1,   380,
      -1,   382,    -1,   383,    -1,    -1,   382,    -1,   383,    -1,
      -1,   402,    -1,   383,   402,    -1,   384,    -1,   383,   384,
      -1,   385,    -1,   388,    -1,   391,    -1,   392,    -1,   393,
      -1,   394,    -1,   395,    -1,   396,    -1,   398,    -1,   450,
      -1,   446,    -1,   399,    -1,   150,   383,   181,    -1,   150,
     181,    -1,   150,   381,   181,    -1,   150,   381,   181,    -1,
     389,   187,    -1,   389,   104,   390,    -1,   109,   390,    -1,
     234,   109,   390,    -1,   115,   627,    -1,   115,   627,   533,
      -1,   115,   627,   139,   403,    -1,   115,   627,   533,   139,
     403,    -1,   115,   627,   139,   403,   187,    -1,   404,   187,
      -1,   237,   239,   403,   187,    -1,   240,   153,   402,   184,
     384,    -1,   235,   238,   187,    -1,   236,   238,   187,    -1,
     414,   397,    -1,   183,   384,    -1,    47,   153,   402,   184,
     194,   384,   123,   384,    -1,   241,   385,   400,    -1,   401,
      -1,   400,   401,    -1,   242,   571,   385,    -1,   242,   571,
     153,   115,   627,   184,   385,    -1,   242,   571,   153,   115,
     627,   104,   115,   627,   184,   385,    -1,   242,   571,   153,
     115,   627,   104,   115,   627,   104,   115,   627,   184,   385,
      -1,   403,    -1,   402,   104,   403,    -1,   405,    -1,   442,
      -1,   449,    -1,   455,    -1,   567,    -1,   404,    -1,   456,
      -1,   439,    -1,   560,    -1,   561,    -1,   563,    -1,   562,
      -1,   564,    -1,   414,   406,    -1,   183,   403,    -1,    65,
     281,    -1,    70,   281,    -1,   213,    -1,   251,    -1,    54,
     251,    -1,   408,   424,    75,   403,    -1,   408,    75,   403,
      -1,    45,   407,   423,   409,   409,    -1,    45,   407,   423,
     409,    -1,    40,   115,   627,    -1,   415,    -1,   420,    -1,
     410,    -1,   412,    -1,   427,    -1,   432,    -1,   428,    -1,
     411,    -1,   412,    -1,   414,   413,    -1,    45,   115,   416,
      -1,   417,    -1,   416,   104,   115,   417,    -1,   627,   144,
     403,    -1,   627,    34,   124,   144,   403,    -1,   627,   533,
     144,   403,    -1,   627,   533,    34,   124,   144,   403,    -1,
     627,   418,   144,   403,    -1,   627,    34,   124,   418,   144,
     403,    -1,   627,   533,   418,   144,   403,    -1,   627,   533,
      34,   124,   418,   144,   403,    -1,   627,   419,   144,   403,
      -1,   627,   533,   419,   144,   403,    -1,   627,   418,   419,
     144,   403,    -1,   627,   533,   418,   419,   144,   403,    -1,
      94,   115,   627,    -1,   270,   115,   627,    -1,    50,   421,
      -1,   422,    -1,   421,   104,   422,    -1,   115,   627,   139,
     403,    -1,   115,   627,   533,   139,   403,    -1,   419,   139,
     403,    -1,   115,   627,   533,   419,   139,   403,    -1,   115,
     627,   144,   403,    -1,   115,   627,   533,   144,   403,    -1,
     425,    -1,   115,   627,    -1,   115,   627,   425,    -1,   418,
      -1,   418,   426,    -1,   426,    -1,    57,   115,   627,    52,
     115,   627,    -1,    52,   115,   627,    -1,    57,   115,   627,
      -1,   208,   403,    -1,   168,   167,   429,    -1,   430,    -1,
     429,   104,   430,    -1,   115,   627,    -1,   115,   627,   431,
      -1,   103,   625,    -1,   165,   167,   433,    -1,    68,   165,
     167,   433,    -1,   434,    -1,   433,   104,   434,    -1,   403,
      -1,   403,   435,    -1,   436,    -1,   437,    -1,   438,    -1,
     436,   437,    -1,   436,   438,    -1,   437,   438,    -1,   436,
     437,   438,    -1,    93,    -1,   113,    -1,   124,   125,    -1,
     124,   126,    -1,   103,   625,    -1,    66,   115,   440,   185,
     403,    -1,   132,   115,   440,   185,   403,    -1,   441,    -1,
     440,   104,   115,   441,    -1,   627,   144,   403,    -1,   627,
     533,   144,   403,    -1,    71,   153,   402,   184,   443,   110,
     183,   403,    -1,   444,    -1,   443,   444,    -1,   445,   183,
     403,    -1,    97,   403,    -1,   445,    97,   403,    -1,    71,
     153,   402,   184,   447,   110,   183,   384,    -1,   448,    -1,
     447,   448,    -1,   445,   183,   384,    -1,    72,   153,   402,
     184,   451,   110,   183,   403,    -1,    72,   153,   402,   184,
     451,   110,   115,   627,   183,   403,    -1,    72,   153,   402,
     184,   453,   110,   183,   384,    -1,    72,   153,   402,   184,
     451,   110,   115,   627,   183,   384,    -1,   452,    -1,   451,
     452,    -1,    97,   534,   183,   403,    -1,    97,   115,   627,
      92,   534,   183,   403,    -1,   454,    -1,   453,   454,    -1,
      97,   534,   183,   384,    -1,    97,   115,   627,    92,   534,
     183,   384,    -1,    47,   153,   402,   184,   194,   403,   123,
     403,    -1,   457,    -1,   456,   164,   457,    -1,   458,    -1,
     457,    90,   458,    -1,   460,    -1,   460,   474,   460,    -1,
     460,   475,   460,    -1,   460,   129,   460,    -1,   460,   159,
     460,    -1,    -1,   460,   154,   459,   460,    -1,   460,   152,
     460,    -1,   460,   140,   460,    -1,   460,   138,   460,    -1,
     462,    -1,   462,   246,    69,   572,   461,    -1,    -1,   624,
      -1,   463,    -1,   463,   195,   463,    -1,   464,    -1,   463,
     173,   464,    -1,   463,   155,   464,    -1,   465,    -1,   464,
     190,   465,    -1,   464,   114,   465,    -1,   464,   143,   465,
      -1,   464,   156,   465,    -1,   466,    -1,   465,   197,   466,
      -1,   465,   206,   466,    -1,   467,    -1,   466,   147,   467,
      -1,   466,   133,   467,    -1,   468,    -1,   468,    49,   227,
     534,    -1,   469,    -1,   469,   196,    92,   534,    -1,   470,
      -1,   470,    98,    92,   532,    -1,   471,    -1,   471,    99,
      92,   532,    -1,   473,    -1,   472,   473,    -1,   173,    -1,
     155,    -1,   472,   173,    -1,   472,   155,    -1,   476,    -1,
     480,    -1,   477,    -1,   199,    -1,   204,    -1,   203,    -1,
     202,    -1,   201,    -1,   200,    -1,   148,    -1,   176,    -1,
     137,    -1,    74,   150,   382,   181,    -1,    74,   218,   150,
     382,   181,    -1,    74,   217,   150,   382,   181,    -1,    74,
      92,   549,   150,   382,   181,    -1,   478,   150,   181,    -1,
     478,   150,   402,   181,    -1,   479,    -1,   478,   479,    -1,
     174,   627,    16,    -1,   174,    17,    -1,   174,    18,    -1,
     481,    -1,   481,   482,    -1,   189,   482,    -1,   482,    -1,
     188,    -1,   483,    -1,   483,   188,   482,    -1,   483,   189,
     482,    -1,   484,    -1,   493,    -1,   485,    -1,   485,   494,
      -1,   488,    -1,   488,   494,    -1,   486,   490,    -1,   487,
      -1,   102,   119,    -1,   111,   119,    -1,    95,   119,    -1,
     186,   119,    -1,   112,   119,    -1,   136,   119,    -1,   135,
     119,    -1,   490,    -1,    96,   490,    -1,   489,   490,    -1,
     117,    -1,   169,   119,    -1,    88,   119,    -1,   178,   119,
      -1,   177,   119,    -1,    89,   119,    -1,   539,    -1,   491,
      -1,   627,    -1,   492,    -1,   190,    -1,    11,    -1,    19,
      -1,   496,    -1,   493,   494,    -1,   493,   153,   184,    -1,
     493,   153,   505,   184,    -1,   495,    -1,   494,   495,    -1,
     151,   402,   182,    -1,   497,    -1,   499,    -1,   500,    -1,
     501,    -1,   504,    -1,   506,    -1,   502,    -1,   503,    -1,
     552,    -1,   386,    -1,   498,    -1,   551,    -1,   107,    -1,
     146,    -1,   121,    -1,   115,   627,    -1,   153,   184,    -1,
     153,   402,   184,    -1,   116,    -1,   166,   150,   402,   181,
      -1,   198,   150,   402,   181,    -1,   628,   153,   184,    -1,
     628,   153,   505,   184,    -1,   403,    -1,   505,   104,   403,
      -1,   507,    -1,   525,    -1,   508,    -1,   522,    -1,   523,
      -1,   154,   627,   512,   127,    -1,   154,   627,   510,   512,
     127,    -1,   154,   627,   512,   193,   191,   627,   512,   193,
      -1,   154,   627,   512,   193,   509,   191,   627,   512,   193,
      -1,   154,   627,   510,   512,   193,   191,   627,   512,   193,
      -1,   154,   627,   510,   512,   193,   509,   191,   627,   512,
     193,    -1,   520,    -1,   509,   520,    -1,   511,    -1,   510,
     511,    -1,    33,   627,   512,   129,   512,   513,    -1,    -1,
      33,    -1,   180,   514,   180,    -1,    91,   516,    91,    -1,
      -1,   515,    -1,   131,    -1,   518,    -1,   515,   131,    -1,
     515,   518,    -1,    -1,   517,    -1,   130,    -1,   519,    -1,
     517,   130,    -1,   517,   519,    -1,    26,    -1,   521,    -1,
       5,    -1,   521,    -1,   507,    -1,    10,    -1,   524,    -1,
     521,    -1,     9,    -1,   120,    -1,   122,    -1,   150,   382,
     181,    -1,   209,    28,   210,    -1,   209,   210,    -1,   171,
     626,   172,    -1,   171,   626,     8,    -1,   100,     7,    -1,
     526,    -1,   527,    -1,   528,    -1,   529,    -1,   530,    -1,
     531,    -1,    41,   150,   381,   181,    -1,    20,   381,   181,
      -1,    43,   150,   402,   181,   150,   381,   181,    -1,    21,
     381,   181,    -1,    95,   150,   402,   181,   150,   381,   181,
      -1,    69,   150,   382,   181,    -1,    37,   150,   382,   181,
      -1,    22,   381,   181,    -1,    58,   150,   402,   181,   150,
     381,   181,    -1,   538,    -1,   538,   141,    -1,    92,   534,
      -1,   536,    -1,   536,   535,    -1,   207,   153,   184,    -1,
     141,    -1,   190,    -1,   173,    -1,   538,    -1,   539,    -1,
     149,   153,   184,    -1,   555,    -1,   558,    -1,   534,    -1,
     537,   104,   534,    -1,   627,    -1,   541,    -1,   547,    -1,
     545,    -1,   548,    -1,   546,    -1,   544,    -1,   543,    -1,
     542,    -1,   540,    -1,   221,   153,   184,    -1,    42,   153,
     184,    -1,    42,   153,   547,   184,    -1,    42,   153,   548,
     184,    -1,    69,   153,   184,    -1,    37,   153,   184,    -1,
      58,   153,   184,    -1,    58,   153,   626,   184,    -1,    58,
     153,    27,   184,    -1,    95,   153,   184,    -1,    95,   153,
     627,   184,    -1,    95,   153,   627,   104,   549,   184,    -1,
      95,   153,   190,   184,    -1,    95,   153,   190,   104,   549,
     184,    -1,    60,   153,   627,   184,    -1,    43,   153,   184,
      -1,    43,   153,   627,   184,    -1,    43,   153,   627,   104,
     549,   184,    -1,    43,   153,   627,   104,   550,   184,    -1,
      43,   153,   190,   184,    -1,    43,   153,   190,   104,   549,
     184,    -1,    43,   153,   190,   104,   550,   184,    -1,    61,
     153,   627,   184,    -1,   627,    -1,   627,   141,    -1,    27,
      -1,   553,    -1,   554,    -1,   627,   142,   146,    -1,    46,
     367,   387,    -1,   556,    -1,   557,    -1,    46,   153,   190,
     184,    -1,    46,   153,   184,    92,   534,    -1,    46,   153,
     537,   184,    92,   534,    -1,   153,   536,   184,    -1,    31,
     216,   217,    -1,    31,   216,   218,    -1,    31,   216,   219,
      -1,   222,   221,   403,   229,   403,    -1,   222,   221,   403,
      92,   228,   229,   403,    -1,   222,   221,   403,    92,   230,
     229,   403,    -1,   222,   221,   403,   214,   403,    -1,   222,
     221,   403,   215,   403,    -1,   222,   223,   403,   229,   403,
      -1,   222,   223,   403,    92,   228,   229,   403,    -1,   222,
     223,   403,    92,   230,   229,   403,    -1,   222,   223,   403,
     214,   403,    -1,   222,   223,   403,   215,   403,    -1,   220,
     221,   403,    -1,   220,   223,   403,    -1,   225,   221,   403,
     233,   403,    -1,   225,   226,   227,   221,   403,   233,   403,
      -1,   224,   221,   403,    92,   403,    -1,   232,   115,   565,
     231,   403,   183,   403,    -1,   566,    -1,   565,   104,   115,
     566,    -1,   627,   139,   403,    -1,   241,   150,   402,   181,
     568,    -1,   569,    -1,   568,   569,    -1,   242,   571,   570,
      -1,   242,   571,   153,   115,   627,   184,   570,    -1,   242,
     571,   153,   115,   627,   104,   115,   627,   184,   570,    -1,
     242,   571,   153,   115,   627,   104,   115,   627,   104,   115,
     627,   184,   570,    -1,   150,   402,   181,    -1,   491,    -1,
     571,   206,   491,    -1,   575,   573,    -1,    -1,   574,    -1,
     593,    -1,   574,   593,    -1,   576,    -1,   575,   259,   576,
      -1,   577,    -1,   576,   255,   577,    -1,   578,    -1,   577,
     257,   144,   578,    -1,   579,    -1,   256,   579,    -1,   583,
     580,   581,    -1,    -1,   598,    -1,    -1,   582,    -1,   279,
     150,   402,   181,    -1,   587,   584,    -1,   153,   572,   184,
      -1,   585,    -1,    -1,   620,    -1,   478,   150,   586,   181,
      -1,    -1,   572,    -1,   588,   589,    -1,   497,    -1,   150,
     402,   181,    -1,    -1,   590,    -1,   245,   591,    -1,   244,
     592,    -1,   267,    -1,    -1,    76,    -1,    -1,   283,    -1,
     594,    -1,   595,    -1,   596,    -1,   622,    -1,   619,    -1,
     166,    -1,   281,   463,   597,    -1,   250,   621,   597,    -1,
     283,    -1,   273,    -1,   266,    -1,   243,   599,    -1,   598,
     243,   599,    -1,   600,    -1,   601,    -1,   602,    -1,   617,
      -1,   603,    -1,   611,    -1,   604,    -1,   618,    -1,    97,
     271,    -1,    97,   260,    -1,   263,    -1,   278,    -1,   248,
     271,    -1,   248,   260,    -1,    55,   627,    27,    -1,   274,
      -1,    53,   274,    -1,   276,   605,    -1,   276,   153,   605,
     606,   184,    -1,    53,   276,    -1,   608,    -1,   110,    -1,
      -1,   104,   607,    -1,   608,    -1,   607,   104,   608,    -1,
      94,    27,   609,   610,    -1,    -1,   268,    27,    -1,    -1,
     621,   262,    -1,   275,   283,   612,   614,    -1,   275,   283,
     110,   614,    -1,    53,   275,   283,    -1,    94,    27,    -1,
     153,   613,   184,    -1,    27,    -1,   613,   104,    27,    -1,
      -1,   615,    -1,   616,    -1,   615,   616,    -1,   197,   612,
      -1,   133,   612,    -1,   261,    27,    -1,   280,    -1,    53,
     280,    -1,    94,   213,    -1,    94,   251,    -1,   252,   247,
      -1,   264,   621,   277,    -1,   253,   463,    -1,    94,   126,
     463,    -1,    94,    51,   463,    -1,   254,   463,   195,   463,
      -1,   269,   623,    -1,   249,   623,    -1,   272,    -1,   265,
      -1,   282,   247,   465,    -1,    27,    -1,    15,    -1,   627,
      -1,   628,    -1,    95,    -1,    37,    -1,    42,    -1,    43,
      -1,   149,    -1,    47,    -1,   221,    -1,    58,    -1,    60,
      -1,    61,    -1,    69,    -1,    72,    -1,    71,    -1,   207,
      -1,   240,    -1,   629,    -1,    23,    -1,   211,    -1,   124,
      -1,    36,    -1,   258,    -1,    35,    -1,   218,    -1,   217,
      -1,   143,    -1,    41,    -1,   256,    -1,   257,    -1,   271,
      -1,   260,    -1,   248,    -1,   282,    -1,   274,    -1,   276,
      -1,   275,    -1,   280,    -1,   252,    -1,   247,    -1,    76,
      -1,   213,    -1,   251,    -1,    51,    -1,   219,    -1,   232,
      -1,   299,    -1,   226,    -1,   199,    -1,   204,    -1,   203,
      -1,   202,    -1,   201,    -1,   200,    -1,    94,    -1,   108,
      -1,   109,    -1,   183,    -1,    45,    -1,    34,    -1,    65,
      -1,    70,    -1,    57,    -1,    52,    -1,    54,    -1,    75,
      -1,    40,    -1,   144,    -1,    50,    -1,   208,    -1,   167,
      -1,   168,    -1,   165,    -1,    68,    -1,    93,    -1,   113,
      -1,   125,    -1,   126,    -1,   103,    -1,    66,    -1,   132,
      -1,   185,    -1,    97,    -1,    92,    -1,   194,    -1,   123,
      -1,   164,    -1,    90,    -1,    49,    -1,   227,    -1,    98,
      -1,   195,    -1,   114,    -1,   156,    -1,   197,    -1,   147,
      -1,   133,    -1,    74,    -1,    99,    -1,   196,    -1,   148,
      -1,   179,    -1,   192,    -1,   157,    -1,   134,    -1,   128,
      -1,   163,    -1,   145,    -1,   162,    -1,    31,    -1,    38,
      -1,    56,    -1,   110,    -1,    39,    -1,    55,    -1,   212,
      -1,    48,    -1,    59,    -1,    32,    -1,    46,    -1,   270,
      -1,   246,    -1,   279,    -1,   281,    -1,   250,    -1,   264,
      -1,   277,    -1,   269,    -1,   249,    -1,   263,    -1,   278,
      -1,   268,    -1,   262,    -1,   261,    -1,   245,    -1,   244,
      -1,   267,    -1,   253,    -1,   254,    -1,   283,    -1,   273,
      -1,   272,    -1,   265,    -1,   225,    -1,   231,    -1,   228,
      -1,   222,    -1,   215,    -1,   214,    -1,   216,    -1,   233,
      -1,   223,    -1,   224,    -1,   230,    -1,   220,    -1,   229,
      -1,    64,    -1,    62,    -1,    73,    -1,   166,    -1,   198,
      -1,   239,    -1,   234,    -1,   237,    -1,   238,    -1,   235,
      -1,   236,    -1,   241,    -1,   242,    -1,    44,    -1,   243,
      -1,    63,    -1,   292,    -1,   290,    -1,   291,    -1,   296,
      -1,   297,    -1,   298,    -1,   293,    -1,   294,    -1,   295,
      -1,    77,    -1,    78,    -1,    79,    -1,    80,    -1,    81,
      -1,    82,    -1,    83,    -1,    84,    -1,    85,    -1,    86,
      -1,    87,    -1,   284,    -1,   285,    -1,   286,    -1,   287,
      -1,   288,    -1,   289,    -1,   300,    -1,   301,    -1,   302,
      -1,   303,    -1,   304,    -1,   305,    -1,   306,    -1,    88,
      -1,   102,    -1,   111,    -1,   169,    -1,   177,    -1,   186,
      -1,   135,    -1,    89,    -1,   112,    -1,   136,    -1,   178,
      -1,   625,   118,   626,    -1,    24,    -1
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
     433,   436,   440,   442,   444,   449,   454,   460,   466,   469,
     473,   478,   484,   486,   490,   493,   497,   499,   502,   504,
     506,   508,   510,   512,   514,   517,   520,   523,   526,   528,
     531,   534,   537,   541,   546,   552,   559,   564,   570,   577,
     585,   587,   590,   594,   598,   607,   617,   619,   623,   625,
     628,   631,   635,   647,   662,   676,   699,   701,   703,   705,
     706,   708,   710,   711,   713,   716,   718,   721,   723,   725,
     727,   729,   731,   733,   735,   737,   739,   741,   743,   745,
     749,   752,   756,   760,   763,   767,   770,   774,   777,   781,
     786,   792,   798,   801,   806,   812,   816,   820,   823,   826,
     835,   839,   841,   844,   848,   856,   867,   881,   883,   887,
     889,   891,   893,   895,   897,   899,   901,   903,   905,   907,
     909,   911,   913,   916,   919,   922,   925,   927,   929,   932,
     937,   941,   947,   952,   956,   958,   960,   962,   964,   966,
     968,   970,   972,   974,   977,   981,   983,   988,   992,   998,
    1003,  1010,  1015,  1022,  1028,  1036,  1041,  1047,  1053,  1060,
    1064,  1068,  1071,  1073,  1077,  1082,  1088,  1092,  1099,  1104,
    1110,  1112,  1115,  1119,  1121,  1124,  1126,  1133,  1137,  1141,
    1144,  1148,  1150,  1154,  1157,  1161,  1164,  1168,  1173,  1175,
    1179,  1181,  1184,  1186,  1188,  1190,  1193,  1196,  1199,  1203,
    1205,  1207,  1210,  1213,  1216,  1222,  1228,  1230,  1235,  1239,
    1244,  1253,  1255,  1258,  1262,  1265,  1269,  1278,  1280,  1283,
    1287,  1296,  1307,  1316,  1327,  1329,  1332,  1337,  1345,  1347,
    1350,  1355,  1363,  1372,  1374,  1378,  1380,  1384,  1386,  1390,
    1394,  1398,  1402,  1403,  1408,  1412,  1416,  1420,  1422,  1428,
    1429,  1431,  1433,  1437,  1439,  1443,  1447,  1449,  1453,  1457,
    1461,  1465,  1467,  1471,  1475,  1477,  1481,  1485,  1487,  1492,
    1494,  1499,  1501,  1506,  1508,  1513,  1515,  1518,  1520,  1522,
    1525,  1528,  1530,  1532,  1534,  1536,  1538,  1540,  1542,  1544,
    1546,  1548,  1550,  1552,  1557,  1563,  1569,  1576,  1580,  1585,
    1587,  1590,  1594,  1597,  1600,  1602,  1605,  1608,  1610,  1612,
    1614,  1618,  1622,  1624,  1626,  1628,  1631,  1633,  1636,  1639,
    1641,  1644,  1647,  1650,  1653,  1656,  1659,  1662,  1664,  1667,
    1670,  1672,  1675,  1678,  1681,  1684,  1687,  1689,  1691,  1693,
    1695,  1697,  1699,  1701,  1703,  1706,  1710,  1715,  1717,  1720,
    1724,  1726,  1728,  1730,  1732,  1734,  1736,  1738,  1740,  1742,
    1744,  1746,  1748,  1750,  1752,  1754,  1757,  1760,  1764,  1766,
    1771,  1776,  1780,  1785,  1787,  1791,  1793,  1795,  1797,  1799,
    1801,  1806,  1812,  1821,  1831,  1841,  1852,  1854,  1857,  1859,
    1862,  1869,  1870,  1872,  1876,  1880,  1881,  1883,  1885,  1887,
    1890,  1893,  1894,  1896,  1898,  1900,  1903,  1906,  1908,  1910,
    1912,  1914,  1916,  1918,  1920,  1922,  1924,  1926,  1928,  1932,
    1936,  1939,  1943,  1947,  1950,  1952,  1954,  1956,  1958,  1960,
    1962,  1967,  1971,  1979,  1983,  1991,  1996,  2001,  2005,  2013,
    2015,  2018,  2021,  2023,  2026,  2030,  2032,  2034,  2036,  2038,
    2040,  2044,  2046,  2048,  2050,  2054,  2056,  2058,  2060,  2062,
    2064,  2066,  2068,  2070,  2072,  2074,  2078,  2082,  2087,  2092,
    2096,  2100,  2104,  2109,  2114,  2118,  2123,  2130,  2135,  2142,
    2147,  2151,  2156,  2163,  2170,  2175,  2182,  2189,  2194,  2196,
    2199,  2201,  2203,  2205,  2209,  2213,  2215,  2217,  2222,  2228,
    2235,  2239,  2243,  2247,  2251,  2257,  2265,  2273,  2279,  2285,
    2291,  2299,  2307,  2313,  2319,  2323,  2327,  2333,  2341,  2347,
    2355,  2357,  2362,  2366,  2372,  2374,  2377,  2381,  2389,  2400,
    2414,  2418,  2420,  2424,  2427,  2428,  2430,  2432,  2435,  2437,
    2441,  2443,  2447,  2449,  2454,  2456,  2459,  2463,  2464,  2466,
    2467,  2469,  2474,  2477,  2481,  2483,  2484,  2486,  2491,  2492,
    2494,  2497,  2499,  2503,  2504,  2506,  2509,  2512,  2514,  2515,
    2517,  2518,  2520,  2522,  2524,  2526,  2528,  2530,  2532,  2536,
    2540,  2542,  2544,  2546,  2549,  2553,  2555,  2557,  2559,  2561,
    2563,  2565,  2567,  2569,  2572,  2575,  2577,  2579,  2582,  2585,
    2589,  2591,  2594,  2597,  2603,  2606,  2608,  2610,  2611,  2614,
    2616,  2620,  2625,  2626,  2629,  2630,  2633,  2638,  2643,  2647,
    2650,  2654,  2656,  2660,  2661,  2663,  2665,  2668,  2671,  2674,
    2677,  2679,  2682,  2685,  2688,  2691,  2695,  2698,  2702,  2706,
    2711,  2714,  2717,  2719,  2721,  2725,  2727,  2729,  2731,  2733,
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
    3155,  3157,  3159,  3161,  3165
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
    1696,  1701,  1709,  1717,  1728,  1733,  1742,  1747,  1757,  1762,
    1771,  1777,  1790,  1795,  1803,  1814,  1829,  1841,  1856,  1861,
    1866,  1871,  1879,  1886,  1897,  1902,  1912,  1918,  1928,  1932,
    1938,  1942,  1946,  1950,  1956,  1962,  1968,  1974,  1980,  1984,
    1990,  1996,  2003,  2011,  2019,  2027,  2035,  2047,  2061,  2075,
    2092,  2096,  2105,  2109,  2116,  2124,  2142,  2148,  2157,  2162,
    2169,  2176,  2187,  2197,  2207,  2217,  2235,  2255,  2260,  2265,
    2272,  2277,  2282,  2289,  2294,  2306,  2313,  2325,  2326,  2327,
    2328,  2329,  2330,  2331,  2333,  2334,  2335,  2336,  2337,  2342,
    2347,  2355,  2372,  2380,  2388,  2395,  2402,  2412,  2424,  2437,
    2449,  2465,  2473,  2481,  2489,  2504,  2509,  2517,  2531,  2548,
    2573,  2581,  2588,  2599,  2605,  2611,  2622,  2637,  2642,  2657,
    2658,  2659,  2660,  2661,  2662,  2667,  2668,  2671,  2672,  2673,
    2674,  2675,  2680,  2694,  2702,  2707,  2715,  2720,  2725,  2733,
    2742,  2754,  2764,  2777,  2785,  2786,  2787,  2792,  2793,  2794,
    2795,  2796,  2801,  2808,  2818,  2826,  2833,  2843,  2853,  2863,
    2873,  2883,  2893,  2903,  2913,  2924,  2933,  2943,  2953,  2969,
    2978,  2987,  2995,  3001,  3013,  3021,  3031,  3039,  3051,  3057,
    3068,  3070,  3074,  3082,  3086,  3091,  3095,  3099,  3103,  3113,
    3121,  3128,  3134,  3145,  3149,  3158,  3166,  3172,  3182,  3188,
    3198,  3202,  3212,  3218,  3224,  3230,  3239,  3248,  3257,  3270,
    3274,  3282,  3288,  3298,  3306,  3315,  3328,  3335,  3347,  3351,
    3363,  3370,  3376,  3385,  3392,  3398,  3409,  3416,  3422,  3431,
    3440,  3447,  3458,  3465,  3477,  3483,  3495,  3501,  3512,  3518,
    3529,  3535,  3546,  3555,  3559,  3568,  3572,  3580,  3584,  3594,
    3601,  3610,  3620,  3619,  3633,  3642,  3651,  3664,  3668,  3681,
    3684,  3691,  3695,  3704,  3708,  3712,  3721,  3725,  3731,  3737,
    3743,  3754,  3758,  3762,  3770,  3774,  3780,  3790,  3794,  3804,
    3808,  3818,  3822,  3832,  3836,  3846,  3850,  3858,  3862,  3866,
    3870,  3880,  3884,  3888,  3896,  3900,  3904,  3908,  3912,  3916,
    3924,  3928,  3932,  3940,  3944,  3948,  3952,  3963,  3969,  3979,
    3985,  3995,  3999,  4003,  4041,  4045,  4055,  4065,  4078,  4087,
    4097,  4101,  4110,  4114,  4123,  4129,  4137,  4143,  4155,  4161,
    4171,  4175,  4179,  4183,  4187,  4193,  4199,  4207,  4211,  4219,
    4223,  4234,  4238,  4242,  4248,  4252,  4266,  4270,  4278,  4282,
    4292,  4296,  4300,  4309,  4313,  4317,  4321,  4329,  4335,  4345,
    4353,  4357,  4361,  4365,  4369,  4373,  4377,  4381,  4385,  4395,
    4403,  4407,  4415,  4422,  4429,  4440,  4448,  4452,  4460,  4468,
    4476,  4530,  4534,  4547,  4553,  4563,  4567,  4575,  4579,  4583,
    4591,  4601,  4611,  4621,  4631,  4641,  4656,  4662,  4673,  4679,
    4690,  4701,  4703,  4707,  4712,  4722,  4725,  4732,  4738,  4744,
    4752,  4765,  4768,  4775,  4781,  4787,  4794,  4805,  4809,  4819,
    4823,  4833,  4837,  4841,  4846,  4855,  4861,  4867,  4873,  4881,
    4886,  4894,  4899,  4907,  4915,  4920,  4925,  4930,  4935,  4940,
    4949,  4957,  4961,  4978,  4982,  4990,  4998,  5006,  5010,  5018,
    5024,  5034,  5042,  5046,  5050,  5085,  5091,  5097,  5107,  5111,
    5115,  5119,  5123,  5130,  5136,  5146,  5154,  5158,  5162,  5166,
    5170,  5174,  5178,  5182,  5186,  5194,  5202,  5206,  5210,  5220,
    5228,  5236,  5240,  5244,  5252,  5256,  5262,  5268,  5272,  5282,
    5290,  5294,  5300,  5309,  5318,  5324,  5330,  5340,  5357,  5364,
    5379,  5415,  5419,  5427,  5435,  5447,  5451,  5459,  5467,  5471,
    5482,  5499,  5505,  5511,  5521,  5525,  5531,  5537,  5541,  5547,
    5551,  5557,  5563,  5570,  5580,  5585,  5593,  5599,  5609,  5631,
    5640,  5646,  5659,  5673,  5680,  5686,  5696,  5701,  5706,  5716,
    5730,  5738,  5744,  5762,  5771,  5774,  5781,  5786,  5794,  5798,
    5805,  5809,  5816,  5820,  5827,  5831,  5840,  5853,  5856,  5864,
    5867,  5875,  5883,  5891,  5895,  5903,  5906,  5914,  5926,  5929,
    5937,  5949,  5955,  5965,  5968,  5976,  5980,  5984,  5992,  5995,
    6003,  6006,  6014,  6018,  6022,  6026,  6030,  6038,  6046,  6058,
    6070,  6074,  6078,  6086,  6092,  6102,  6106,  6110,  6114,  6118,
    6122,  6126,  6130,  6138,  6142,  6146,  6150,  6158,  6164,  6174,
    6184,  6188,  6196,  6206,  6217,  6224,  6228,  6236,  6239,  6246,
    6251,  6260,  6270,  6273,  6281,  6284,  6292,  6301,  6308,  6318,
    6322,  6329,  6335,  6345,  6348,  6355,  6360,  6372,  6380,  6392,
    6400,  6404,  6412,  6416,  6420,  6428,  6436,  6440,  6444,  6448,
    6456,  6464,  6476,  6480,  6488,  6501,  6505,  6506,  6519,  6520,
    6521,  6522,  6523,  6524,  6525,  6526,  6527,  6528,  6529,  6530,
    6531,  6532,  6533,  6534,  6538,  6539,  6540,  6541,  6542,  6543,
    6544,  6545,  6546,  6547,  6548,  6549,  6550,  6551,  6552,  6553,
    6554,  6555,  6556,  6557,  6558,  6559,  6560,  6561,  6562,  6563,
    6564,  6565,  6566,  6567,  6568,  6569,  6570,  6571,  6572,  6573,
    6574,  6575,  6576,  6577,  6578,  6579,  6580,  6581,  6582,  6583,
    6584,  6585,  6586,  6587,  6588,  6589,  6590,  6591,  6592,  6593,
    6594,  6595,  6596,  6597,  6598,  6599,  6600,  6601,  6602,  6603,
    6604,  6605,  6606,  6607,  6608,  6609,  6610,  6611,  6612,  6613,
    6614,  6615,  6616,  6617,  6618,  6619,  6620,  6621,  6622,  6623,
    6624,  6625,  6626,  6627,  6628,  6629,  6630,  6631,  6632,  6633,
    6634,  6635,  6636,  6637,  6638,  6639,  6640,  6641,  6642,  6643,
    6644,  6645,  6646,  6647,  6648,  6649,  6650,  6651,  6652,  6653,
    6654,  6655,  6656,  6657,  6658,  6659,  6660,  6661,  6662,  6663,
    6664,  6665,  6666,  6667,  6668,  6669,  6670,  6671,  6672,  6673,
    6674,  6675,  6676,  6677,  6678,  6679,  6680,  6681,  6682,  6683,
    6684,  6685,  6686,  6687,  6688,  6689,  6690,  6691,  6692,  6693,
    6694,  6695,  6696,  6697,  6698,  6699,  6700,  6701,  6702,  6703,
    6704,  6705,  6706,  6707,  6708,  6709,  6710,  6711,  6712,  6713,
    6714,  6715,  6716,  6717,  6718,  6719,  6720,  6721,  6722,  6723,
    6724,  6725,  6726,  6727,  6728,  6729,  6730,  6731,  6732,  6733,
    6734,  6735,  6736,  6741,  6748
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
     315,   316,   317,   318,   319,   320
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 13291;
  const int xquery_parser::yynnts_ = 309;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 581;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 321;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 575;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // zorba

/* Line 1054 of lalr1.cc  */
#line 16487 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"


/* Line 1056 of lalr1.cc  */
#line 6752 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"


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

