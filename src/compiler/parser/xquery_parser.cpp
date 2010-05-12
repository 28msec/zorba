
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
#line 68 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"


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



/* Line 311 of lalr1.cc  */
#line 77 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"


#include "xquery_parser.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 837 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 317 of lalr1.cc  */
#line 953 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"

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



/* Line 317 of lalr1.cc  */
#line 133 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"

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
#line 202 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
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

/* Line 480 of lalr1.cc  */
#line 833 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 309 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 115: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 832 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 318 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 140: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 831 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 327 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 319: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 336 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 320: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 345 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 321: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 354 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 322: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 363 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 323: /* "Prolog" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 372 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 324: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 381 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 325: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 390 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 326: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 399 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 408 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 417 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 858 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 426 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 858 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 435 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 444 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 453 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 462 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 471 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 480 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 489 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 498 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 507 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 516 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 525 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 534 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 543 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 552 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 561 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 570 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 579 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 588 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 597 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 606 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 615 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 858 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 624 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 633 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "DeclPropertyList" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 642 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "DeclProperty" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 651 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 660 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "NodeModifier" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 669 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 678 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 687 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 696 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 705 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 714 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 858 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 723 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 732 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "Block" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 741 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "BlockDecls" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 750 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "BlockVarDeclList" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 759 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "BlockVarDecl" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 768 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "AssignExpr" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 777 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "ExitExpr" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 786 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "WhileExpr" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 795 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 804 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 813 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 822 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "FunctionDecl3" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 831 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "FunctionDecl4" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 840 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 858 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 867 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "EnclosedExpr" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 876 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 885 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 894 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 903 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "ApplyExpr" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 912 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "ConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 939 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 948 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 957 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 966 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 975 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 984 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 993 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1002 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1011 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1020 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1029 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1038 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1047 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1056 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "EvalVarDeclList" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1065 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1074 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1083 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1092 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1101 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1110 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "EvalVarDecl" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1119 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1128 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1137 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1146 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1155 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1164 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1173 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1182 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1191 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1200 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1209 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1218 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1227 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1236 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1245 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1254 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1263 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1272 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1281 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1290 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1299 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1308 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1317 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1326 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1335 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1344 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1353 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1362 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1371 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1380 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1389 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1398 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1407 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1416 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1425 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1434 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1443 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1452 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1461 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1470 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1479 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1488 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1497 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1506 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1515 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1524 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1533 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1542 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1551 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1560 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1569 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1578 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1587 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1596 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1605 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1614 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1623 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1632 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1641 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1650 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1659 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1668 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1677 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1686 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1695 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1704 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1713 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1722 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1731 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1740 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1749 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1758 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1767 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1776 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1785 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1794 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1803 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1812 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1821 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1830 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1839 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1848 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1857 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1866 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1875 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1884 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1893 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1902 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1911 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1920 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1929 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1938 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1947 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1956 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1965 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1974 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1983 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1992 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2001 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "AtomicType" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2010 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2019 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2028 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2037 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2046 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2055 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2064 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2073 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2082 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2091 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2100 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2109 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2118 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2127 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2136 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 533: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2145 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 536: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2154 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 537: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2163 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2172 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 539: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2181 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 540: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2190 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 541: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2199 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2208 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 543: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2217 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 544: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2226 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 545: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2235 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 546: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 858 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2244 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 549: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2253 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 550: /* "EvalExpr" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2262 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 552: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2271 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 555: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2280 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 556: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2289 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 557: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2298 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 558: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2307 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 559: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2316 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 560: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2325 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 562: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2334 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 563: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2343 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 564: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2352 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 565: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2361 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 567: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2370 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 568: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2379 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 570: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2388 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 573: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2397 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 574: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2406 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 575: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2415 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 576: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2424 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 577: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2433 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 578: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2442 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 579: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2451 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 580: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2460 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 581: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2469 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 582: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2478 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 583: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2487 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 584: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2496 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 588: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2505 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 591: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2514 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 592: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2523 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 596: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2532 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 597: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2541 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 598: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2550 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 599: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2559 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 600: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2568 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 601: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2577 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 602: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2586 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 603: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2595 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 604: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2604 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
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
#line 119 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename);
}

/* Line 553 of lalr1.cc  */
#line 2689 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"

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
#line 997 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 1006 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 1011 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            MainModule *mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
            mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 1018 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 1023 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            LibraryModule *lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
            lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 1034 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            std::string encoding = "utf-8";
            (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), encoding );
        }
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 1039 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
        }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 1047 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new MainModule(
                LOC((yyloc)),
                static_cast<QueryBody*>((yysemantic_stack_[(2) - (2)].expr)),
                static_cast<Prolog*>((yysemantic_stack_[(2) - (1)].node))
            );
        }
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 1055 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
        }
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 1063 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LibraryModule(
                LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 1069 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LibraryModule(
                LOC((yyloc)),
                static_cast<ModuleDecl*>((yysemantic_stack_[(2) - (1)].node)),
                static_cast<Prolog*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 1081 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
            dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
        }
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 1090 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Prolog( LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(2) - (1)].node)), NULL );
        }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 1094 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Prolog( LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(2) - (1)].node)) );
        }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 1098 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Prolog(
                LOC((yyloc)),
                static_cast<SIND_DeclList*>((yysemantic_stack_[(4) - (1)].node)),
                static_cast<VFO_DeclList*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 1110 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
            sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
            (yyval.node) = sdl;
        }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 1116 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( SIND_DeclList *sdl = static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                sdl->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 1126 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
            vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
            (yyval.node) = vdl;
        }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 1132 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( VFO_DeclList *vdl = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vdl->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 1164 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
         (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
         delete (yysemantic_stack_[(4) - (4)].vstrpair);
       }
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 1169 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
         (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
         delete (yysemantic_stack_[(4) - (4)].vstrpair);
       }
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 1178 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.vstrpair) = new vector<string_pair_t>();
          (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
          delete (yysemantic_stack_[(1) - (1)].strpair);
        }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 1184 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
          delete (yysemantic_stack_[(2) - (2)].strpair);
          (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
        }
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 1193 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
            (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval() );
            delete sl;
        }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 1201 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 1202 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 1203 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 1204 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 1205 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 1206 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 1207 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 1208 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 1209 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 1210 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 1241 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
        }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 1250 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BoundarySpaceDecl(
                LOC((yyloc)), StaticContextConsts::preserve_space
            );
        }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 1256 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BoundarySpaceDecl(
                LOC((yyloc)), StaticContextConsts::strip_space
            );
        }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 1266 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultNamespaceDecl(
                LOC((yyloc)), ParseConstants::ns_element_default, SYMTAB((yysemantic_stack_[(5) - (5)].sval))
            );
        }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 1272 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultNamespaceDecl(
                LOC((yyloc)), ParseConstants::ns_function_default, SYMTAB((yysemantic_stack_[(5) - (5)].sval))
            );
        }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 1282 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OptionDecl(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval))
            );
        }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 1292 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
        }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 1300 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OrderingModeDecl(
                LOC((yyloc)), StaticContextConsts::ordered
            );
        }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 1306 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OrderingModeDecl(
                LOC((yyloc)), StaticContextConsts::unordered
            );
        }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 1317 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new EmptyOrderDecl( LOC((yyloc)),
                                StaticContextConsts::empty_greatest);
        }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 1322 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new EmptyOrderDecl( LOC((yyloc)),
                                StaticContextConsts::empty_least);
        }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 1332 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::preserve_ns,
                                StaticContextConsts::inherit_ns);
        }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 1338 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::preserve_ns,
                                StaticContextConsts::no_inherit_ns);
        }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 1344 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::no_preserve_ns,
                                StaticContextConsts::inherit_ns);
        }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 1350 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::no_preserve_ns,
                                StaticContextConsts::no_inherit_ns);
        }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 1367 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
        }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 1375 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 1383 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
        }
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 1387 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new SchemaImport(
                LOC((yyloc)),
                dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                NULL
            );
        }
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 1396 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new SchemaImport(
                LOC((yyloc)),
                NULL,
                SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 1405 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new SchemaImport(
                LOC((yyloc)),
                dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node))
            );
        }
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 1418 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            URILiteralList *ull = new URILiteralList( LOC((yyloc)));
            ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.node) = ull;
        }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 1424 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
                ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 1435 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 1439 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
        }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 1447 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 1452 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 1457 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 1464 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(8) - (4)].sval)),
                            SYMTAB((yysemantic_stack_[(8) - (6)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(8) - (8)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(8) - (2)].sval)));
    }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 1477 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
        }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 1484 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            CtxItemDecl *d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
            d->type = (yysemantic_stack_[(3) - (2)].node);
            (yyval.node) = d;
        }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 1490 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 1497 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            CtxItemDecl *d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
            d->ext = false;
            (yyval.node) = d;
        }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 1503 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CtxItemDecl( LOC((yyloc)), NULL );
        }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 1507 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 1514 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CtxItemDecl( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 1525 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 1529 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 1537 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(5) - (3)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, (yysemantic_stack_[(5) - (5)].expr));
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (1)].sval)));
    }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 1543 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(4) - (3)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, NULL, true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(4) - (1)].sval)));
    }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 1549 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(6) - (3)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, (yysemantic_stack_[(6) - (6)].expr), true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (1)].sval)));
    }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 1558 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            DeclPropertyList *dpl = new DeclPropertyList( LOC((yyloc)) );
            dpl->addProperty(dynamic_cast<DeclProperty*>((yysemantic_stack_[(1) - (1)].node)));
            (yyval.node) = dpl;
        }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 1564 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
        DeclPropertyList *dpl = dynamic_cast<DeclPropertyList*>((yysemantic_stack_[(2) - (1)].node));
        dpl->addProperty( static_cast<DeclProperty*>((yysemantic_stack_[(2) - (2)].node)) );
        (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 1573 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_const );
        }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 1577 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_append_only
            );
        }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 1583 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_queue );
        }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 1587 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_mutable );
        }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 1591 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_ordered );
        }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 1595 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_unordered
            );
        }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 1601 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_value_equality
            );
        }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 1607 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_value_range
            );
        }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 1613 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_general_equality
            );
        }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 1619 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_general_range
            );
        }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 1625 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_unique );
        }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 1629 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_non_unique
            );
        }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 1635 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_automatic
            );
        }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 1641 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_manual );
        }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 1648 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)),
                              NULL,
                              NULL,
                              NULL);
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 1656 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              NULL,
                              static_cast<NodeModifier*>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 1664 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                              NULL,
                              NULL,
                              static_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 1672 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                              NULL,
                              static_cast<NodeModifier*>((yysemantic_stack_[(6) - (6)].node)),
                              static_cast<SequenceType*>((yysemantic_stack_[(6) - (5)].node)));
    }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 1680 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 122:

/* Line 678 of lalr1.cc  */
#line 1692 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 123:

/* Line 678 of lalr1.cc  */
#line 1706 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 124:

/* Line 678 of lalr1.cc  */
#line 1720 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 125:

/* Line 678 of lalr1.cc  */
#line 1737 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 1741 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 1748 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier( LOC((yyloc)), StaticContextConsts::read_only);
    }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 1752 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier( LOC((yyloc)), StaticContextConsts::mutable_node);
    }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 1759 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexDecl( LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(8) - (3)].expr)),
                         (yysemantic_stack_[(8) - (6)].expr),
                         dynamic_cast<IndexKeyList*>((yysemantic_stack_[(8) - (8)].node)),
                         NULL);
    }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 1767 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 131:

/* Line 678 of lalr1.cc  */
#line 1784 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList( LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 1790 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 1798 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec( LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<AtomicType*>((yysemantic_stack_[(3) - (3)].node)),
                            NULL);
    }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 1805 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec( LOC((yyloc)),
                            (yysemantic_stack_[(4) - (1)].expr),
                            dynamic_cast<AtomicType*>((yysemantic_stack_[(4) - (3)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 1816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollSimpleCheck( LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (9)].expr)),
                                 (yysemantic_stack_[(11) - (11)].expr));
    }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 1826 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollUniqueKeyCheck( LOC((yyloc)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (4)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (7)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (10)].expr)),
                                    (yysemantic_stack_[(14) - (14)].expr));
    }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 1836 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollForeachNode( LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (11)].expr)),
                                 (yysemantic_stack_[(13) - (13)].expr));
    }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 1847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 139:

/* Line 678 of lalr1.cc  */
#line 1862 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ConstructionDecl(
                LOC((yyloc)), StaticContextConsts::cons_preserve
            );
        }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 1868 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ConstructionDecl(
                LOC((yyloc)), StaticContextConsts::cons_strip
            );
        }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 1879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( NULL );
        }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1883 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 1887 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)) );
        }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 1891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig(
                dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 1900 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(2) - (2)].expr);
        }
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 1907 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 147:

/* Line 678 of lalr1.cc  */
#line 1926 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vfo = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node));
            std::auto_ptr<VFO_DeclList> vfo2( dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)) );
            if ( !(yysemantic_stack_[(3) - (1)].node) )
                vfo = new VFO_DeclList( LOC((yyloc)) );
            vfo->push_back( *vfo2.get() );
            (yyval.node) = vfo;
        }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 1935 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 1942 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vfo = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node));
            vfo->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = vfo;
        }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 1948 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vfo = new VFO_DeclList( LOC((yyloc)) );
            vfo->push_back((yysemantic_stack_[(2) - (2)].node));
            (yyval.node) = vfo;
        }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 1958 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(1) - (1)].varnametype)));
      VarDecl* vd = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, NULL);
      vd->set_global(false);
      (yyval.node) = vd;
    }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 1965 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(3) - (1)].varnametype)));
      VarDecl* vd = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, (yysemantic_stack_[(3) - (3)].expr));
      vd->set_global(false);
      (yyval.node) = vd;
        }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 1976 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 1983 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExitExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 1990 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            BlockBody *bb = dynamic_cast<BlockBody *>((yysemantic_stack_[(5) - (5)].expr));
            if ( !bb ) {
                bb = new BlockBody( (yysemantic_stack_[(5) - (5)].expr)->get_location() );
                bb->add((yysemantic_stack_[(5) - (5)].expr));
            }
            (yyval.expr) = new WhileExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), bb );
        }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 2002 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::BREAK );
        }
    break;

  case 157:

/* Line 678 of lalr1.cc  */
#line 2006 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
        }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 2013 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            dynamic_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 159:

/* Line 678 of lalr1.cc  */
#line 2018 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            FunctionDecl *fd = dynamic_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));
            fd->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );
            fd->deterministic = false;
            (yyval.node) = fd;
        }
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 2025 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            dynamic_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node))->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );
            (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
        }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 2033 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 2037 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 2041 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl *fd = dynamic_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node));
      fd->type = (fd->type == ParseConstants::fn_extern ?
                  ParseConstants::fn_extern_update :
                  ParseConstants::fn_update);
      (yyval.node) = fd;
    }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 2049 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 2057 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 166:

/* Line 678 of lalr1.cc  */
#line 2067 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 167:

/* Line 678 of lalr1.cc  */
#line 2081 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC ((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                            &* (yysemantic_stack_[(4) - (3)].fnsig)->param,
                            &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
                            (yysemantic_stack_[(4) - (4)].expr),
                            ParseConstants::fn_sequential);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 2091 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC ((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                            &* (yysemantic_stack_[(4) - (3)].fnsig)->param,
                            &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
                            NULL,
                            ParseConstants::fn_extern_sequential);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 2105 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC ((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                            &* (yysemantic_stack_[(6) - (3)].fnsig)->param, &* (yysemantic_stack_[(6) - (3)].fnsig)->ret,
                            (yysemantic_stack_[(6) - (5)].expr),
                            ParseConstants::fn_read);
      delete (yysemantic_stack_[(6) - (3)].fnsig);
    }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 2114 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 171:

/* Line 678 of lalr1.cc  */
#line 2129 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            ParamList *pl = new ParamList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 2135 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
                pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 2147 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 2151 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 2162 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new EnclosedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 2169 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 2177 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QueryBody( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 2192 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 2196 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            std::auto_ptr<BlockBody> blk( dynamic_cast<BlockBody*>((yysemantic_stack_[(2) - (2)].expr)) );
            BlockBody *blk2 = new BlockBody( LOC((yyloc)) );
            blk2->add( (yysemantic_stack_[(2) - (1)].expr) );

            for ( int i = 0; i < blk->size(); ++i )
                blk2->add( (*blk)[i] );

            (yyval.expr) = blk2;
        }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 2210 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new BlockBody( LOC((yyloc)) );
        }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 2214 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            BlockBody *bb = dynamic_cast<BlockBody*>((yysemantic_stack_[(3) - (1)].expr));
            bb->add( (yysemantic_stack_[(3) - (2)].expr) );
            (yyval.expr) = bb;
        }
    break;

  case 182:

/* Line 678 of lalr1.cc  */
#line 2223 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 2227 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 201:

/* Line 678 of lalr1.cc  */
#line 2267 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 202:

/* Line 678 of lalr1.cc  */
#line 2282 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 2289 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_sliding;
        }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 2293 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_tumbling;
        }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 2300 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_start;
        }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 2304 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_end;
        }
    break;

  case 207:

/* Line 678 of lalr1.cc  */
#line 2308 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_only_end;
        }
    break;

  case 208:

/* Line 678 of lalr1.cc  */
#line 2315 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FLWORWinCond(
                LOC((yyloc)),
                dynamic_cast<WindowVars*>((yysemantic_stack_[(4) - (2)].node)), (yysemantic_stack_[(4) - (4)].expr),
                (yysemantic_stack_[(4) - (1)].strval) == parser::the_start, (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end
            );
        }
    break;

  case 209:

/* Line 678 of lalr1.cc  */
#line 2323 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FLWORWinCond(
                LOC((yyloc)), NULL, (yysemantic_stack_[(3) - (3)].expr),
                (yysemantic_stack_[(3) - (1)].strval) == parser::the_start, (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end
            );
        }
    break;

  case 210:

/* Line 678 of lalr1.cc  */
#line 2334 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 211:

/* Line 678 of lalr1.cc  */
#line 2344 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling ?
                              WindowClause::tumbling_window :
                              WindowClause::sliding_window),
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    }
    break;

  case 212:

/* Line 678 of lalr1.cc  */
#line 2357 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 2379 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
            fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = fcl;
        }
    break;

  case 222:

/* Line 678 of lalr1.cc  */
#line 2385 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
            fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = fcl;
        }
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 2394 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = NULL;
        }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 2398 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_ofor;
        }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 2406 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForClause(
                LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(2) - (2)].node)), (yysemantic_stack_[(2) - (1)].strval) != NULL
            );
        }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 2416 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            VarInDeclList *vdl = new VarInDeclList( LOC((yyloc)) );
            vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vdl;
        }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 2422 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( VarInDeclList *vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 2434 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 2438 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                         NULL,NULL,
                         (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 2446 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         NULL,
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(4) - (2)].node)),
                         NULL,
                         (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 2455 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (3)].node)),
                         NULL,
                         (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 2465 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         NULL,NULL,
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
                         (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 2473 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
                         NULL,
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
                         (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 2482 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC ((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)),
                         NULL,
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (2)].node)),
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
                         (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 2491 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC ((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(6) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (2)].node)),
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(6) - (3)].node)),
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
                         (yysemantic_stack_[(6) - (6)].expr));
    }
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 2506 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 237:

/* Line 678 of lalr1.cc  */
#line 2515 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
    }
    break;

  case 238:

/* Line 678 of lalr1.cc  */
#line 2525 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (3)].node)) );
        }
    break;

  case 239:

/* Line 678 of lalr1.cc  */
#line 2533 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 240:

/* Line 678 of lalr1.cc  */
#line 2539 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 2548 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 2554 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 243:

/* Line 678 of lalr1.cc  */
#line 2566 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)),
                           NULL,
                           NULL,
                           (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 2574 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                           NULL,
                           (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 245:

/* Line 678 of lalr1.cc  */
#line 2584 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                           NULL,
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
                           (yysemantic_stack_[(4) - (4)].expr));
     }
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 2592 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
                           (yysemantic_stack_[(5) - (5)].expr));
     }
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 2604 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 2610 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 2623 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 2627 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 2635 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 2639 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 2648 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 256:

/* Line 678 of lalr1.cc  */
#line 2652 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 2656 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 2664 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)),
                           NULL, NULL,
                           new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr))),
                           VarGetsDecl::eval_var);
    }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 2678 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 2686 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 2693 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = new GroupSpecList( LOC((yyloc)) );
            gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 2699 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
            if ( gsl )
                gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 2710 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 2714 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                         dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 2723 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 2731 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 2737 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 2747 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 2753 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 2763 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 2767 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 2777 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 2783 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 2789 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 2795 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
                NULL
            );
        }
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 2804 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                NULL,
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 2813 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                NULL,
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 2822 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 2835 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 2839 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 2847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 2853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 2863 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 2871 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_some,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 2880 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_every,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 2893 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
            qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = qvidl;

        }
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 2900 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
            qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 2912 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 2916 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 2929 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 2936 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 2949 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 2955 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 2967 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 2973 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 2985 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 2994 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 2998 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 3007 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 3011 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 3019 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 3023 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 303:

/* Line 678 of lalr1.cc  */
#line 3033 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 3040 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_eq ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 3049 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ne ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 3058 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 3063 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_lt ),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr)
            );
        }
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 3072 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_le ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 3081 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_gt ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 3090 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ge ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 3103 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 3107 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FTContainsExpr(
                LOC((yyloc)),
                (yysemantic_stack_[(5) - (1)].expr),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(5) - (4)].node)),
                dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 3119 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 3123 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 3130 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 3134 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 3143 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 3147 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 3151 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 3160 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 3164 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 3170 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 3176 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 3182 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 3193 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 3197 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 3201 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 3209 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 3213 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 3219 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 3229 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 3233 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 3243 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 3247 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 3257 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 3261 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 3271 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 3275 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 3285 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 3289 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 3297 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 3301 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 3305 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 3309 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 3319 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 3323 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 3327 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 3335 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 3339 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 3343 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 3347 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 3351 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 3355 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 3363 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 3367 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 3371 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 3379 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 3383 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 3387 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 3391 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 3402 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 3408 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 3418 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 3424 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 3434 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 3438 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 3476 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new PathExpr(
                LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL
            );
        }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 3482 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new PathExpr(
                LOC((yyloc)), ParseConstants::path_leading_slash, (yysemantic_stack_[(2) - (2)].expr)
            );
        }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 3488 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new PathExpr(
                LOC((yyloc)), ParseConstants::path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr)
            );
        }
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 3494 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            RelativePathExpr *rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = !rpe ?
                (yysemantic_stack_[(1) - (1)].expr) : new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 3505 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NULL;
        }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 3513 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 373:

/* Line 678 of lalr1.cc  */
#line 3524 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RelativePathExpr(
                LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 3530 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RelativePathExpr(
                LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 3540 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 3544 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 3552 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 3558 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 3566 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 3572 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 3584 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 3590 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 3600 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 3604 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 3608 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 3612 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 3616 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 3622 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 3628 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 3636 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 3640 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 3648 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 3652 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 3663 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 3667 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 3671 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 3677 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 3681 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 3695 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 3699 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 3707 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 3711 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 3721 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all);
    }
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 3725 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem);
    }
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 3729 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix);
    }
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 3738 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 3742 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FilterExpr(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 3748 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
        }
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 3752 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
        }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 3760 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 3766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 3776 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 3784 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 3788 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 3792 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 3796 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 3800 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 3804 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 3808 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 3812 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 3816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 3824 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 3828 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 3836 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 3843 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 3850 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 3861 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 3869 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 3873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 3881 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 3889 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 3897 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 3951 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
        }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 3955 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 3967 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            ArgList *al = new ArgList( LOC((yyloc)) );
            al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
            (yyval.node) = al;
        }
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 3973 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
                al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 3983 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 3987 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 3995 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 3999 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 4003 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 4011 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 443:

/* Line 678 of lalr1.cc  */
#line 4021 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 444:

/* Line 678 of lalr1.cc  */
#line 4031 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 445:

/* Line 678 of lalr1.cc  */
#line 4041 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 446:

/* Line 678 of lalr1.cc  */
#line 4051 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 447:

/* Line 678 of lalr1.cc  */
#line 4061 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 448:

/* Line 678 of lalr1.cc  */
#line 4076 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
            decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = decl;
        }
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 4082 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( decl )
                decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 4093 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
            dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = dal;
        }
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 4099 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
            if ( dal )
                dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 4110 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttr(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node))
            );
        }
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 4127 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 4132 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 4141 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
        }
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 4145 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 4152 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back(
                new QuoteAttrValueContent( LOC((yyloc)),std::string("\"") )
            );
            (yyval.node) = qacl;
        }
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 4160 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = qacl;
        }
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 4166 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 462:

/* Line 678 of lalr1.cc  */
#line 4176 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 4188 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
        }
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 4192 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 4199 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = aacl;
        }
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 4205 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = aacl;
        }
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 4211 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if (aacl)
                aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 4218 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( aacl )
                aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 4229 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 4233 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 471:

/* Line 678 of lalr1.cc  */
#line 4243 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 472:

/* Line 678 of lalr1.cc  */
#line 4247 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 473:

/* Line 678 of lalr1.cc  */
#line 4257 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 474:

/* Line 678 of lalr1.cc  */
#line 4261 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 4265 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
        }
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 4270 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
        }
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 4279 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval))
            );
        }
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 4285 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_lbrace
            );
        }
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 4291 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_rbrace
            );
        }
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 4297 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 4307 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 482:

/* Line 678 of lalr1.cc  */
#line 4311 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
        }
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 4323 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 4327 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 4339 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 4351 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 4355 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 4359 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 4363 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 4367 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 4371 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 4379 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 4387 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)), NULL
            );
        }
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 4393 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr)
            );
        }
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 4399 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 4403 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 4420 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (2)].expr), NULL );
        }
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 4424 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(5) - (2)].expr), (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 4428 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 4432 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 4440 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 4448 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 4456 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), NULL );
        }
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 4460 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (2)].sval)), (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 4464 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 4468 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 4476 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)), false
            );
        }
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 4482 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)), true
            );
        }
    break;

  case 509:

/* Line 678 of lalr1.cc  */
#line 4492 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 510:

/* Line 678 of lalr1.cc  */
#line 4500 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 511:

/* Line 678 of lalr1.cc  */
#line 4504 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 512:

/* Line 678 of lalr1.cc  */
#line 4510 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 4545 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 4551 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 4557 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 4567 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 4571 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 4575 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)),true );
        }
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 4579 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 4583 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 521:

/* Line 678 of lalr1.cc  */
#line 4590 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 522:

/* Line 678 of lalr1.cc  */
#line 4596 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 4606 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 4614 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 4618 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 526:

/* Line 678 of lalr1.cc  */
#line 4622 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 4626 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 4630 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 4634 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 4638 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 4642 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 4646 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 4654 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyKindTest( LOC((yyloc)) );
        }
    break;

  case 534:

/* Line 678 of lalr1.cc  */
#line 4662 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)) );
        }
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 4666 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)) );
        }
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 4670 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest(
                LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 4680 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TextTest( LOC((yyloc)) );
        }
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 4688 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CommentTest( LOC((yyloc)));
        }
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 4696 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 4700 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 4704 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 542:

/* Line 678 of lalr1.cc  */
#line 4712 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 543:

/* Line 678 of lalr1.cc  */
#line 4716 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 544:

/* Line 678 of lalr1.cc  */
#line 4722 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 4728 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 4732 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 4742 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)) );
        }
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 4750 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 549:

/* Line 678 of lalr1.cc  */
#line 4754 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 550:

/* Line 678 of lalr1.cc  */
#line 4760 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 4769 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 4778 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 4784 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 4790 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 555:

/* Line 678 of lalr1.cc  */
#line 4800 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 556:

/* Line 678 of lalr1.cc  */
#line 4817 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 557:

/* Line 678 of lalr1.cc  */
#line 4824 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 558:

/* Line 678 of lalr1.cc  */
#line 4839 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 559:

/* Line 678 of lalr1.cc  */
#line 4875 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 560:

/* Line 678 of lalr1.cc  */
#line 4879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 561:

/* Line 678 of lalr1.cc  */
#line 4888 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
        }
    break;

  case 562:

/* Line 678 of lalr1.cc  */
#line 4897 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new InlineFunction(LOC ((yyloc)), &*(yysemantic_stack_[(3) - (2)].fnsig)->param, &*(yysemantic_stack_[(3) - (2)].fnsig)->ret, dynamic_cast<EnclosedExpr *>((yysemantic_stack_[(3) - (3)].expr)));
          delete (yysemantic_stack_[(3) - (2)].fnsig);
        }
    break;

  case 563:

/* Line 678 of lalr1.cc  */
#line 4907 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 564:

/* Line 678 of lalr1.cc  */
#line 4911 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 565:

/* Line 678 of lalr1.cc  */
#line 4920 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
        }
    break;

  case 566:

/* Line 678 of lalr1.cc  */
#line 4929 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 567:

/* Line 678 of lalr1.cc  */
#line 4933 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 568:

/* Line 678 of lalr1.cc  */
#line 4944 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 569:

/* Line 678 of lalr1.cc  */
#line 4961 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 570:

/* Line 678 of lalr1.cc  */
#line 4967 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 571:

/* Line 678 of lalr1.cc  */
#line 4973 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 572:

/* Line 678 of lalr1.cc  */
#line 4983 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 573:

/* Line 678 of lalr1.cc  */
#line 4987 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 574:

/* Line 678 of lalr1.cc  */
#line 4993 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 575:

/* Line 678 of lalr1.cc  */
#line 4999 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 576:

/* Line 678 of lalr1.cc  */
#line 5003 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 577:

/* Line 678 of lalr1.cc  */
#line 5009 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 578:

/* Line 678 of lalr1.cc  */
#line 5013 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 579:

/* Line 678 of lalr1.cc  */
#line 5019 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 580:

/* Line 678 of lalr1.cc  */
#line 5025 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 581:

/* Line 678 of lalr1.cc  */
#line 5032 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 582:

/* Line 678 of lalr1.cc  */
#line 5042 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 583:

/* Line 678 of lalr1.cc  */
#line 5047 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 584:

/* Line 678 of lalr1.cc  */
#line 5055 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 585:

/* Line 678 of lalr1.cc  */
#line 5061 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 586:

/* Line 678 of lalr1.cc  */
#line 5071 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 587:

/* Line 678 of lalr1.cc  */
#line 5093 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 588:

/* Line 678 of lalr1.cc  */
#line 5102 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 589:

/* Line 678 of lalr1.cc  */
#line 5108 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 590:

/* Line 678 of lalr1.cc  */
#line 5121 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 591:

/* Line 678 of lalr1.cc  */
#line 5135 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 592:

/* Line 678 of lalr1.cc  */
#line 5142 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 593:

/* Line 678 of lalr1.cc  */
#line 5148 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 594:

/* Line 678 of lalr1.cc  */
#line 5158 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 595:

/* Line 678 of lalr1.cc  */
#line 5163 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CatchExpr(LOC((yyloc)),*(yysemantic_stack_[(7) - (2)].name_test_list), static_cast<QName*>((yysemantic_stack_[(7) - (5)].expr)), NULL, NULL, (yysemantic_stack_[(7) - (7)].expr));
       delete (yysemantic_stack_[(7) - (2)].name_test_list);
    }
    break;

  case 596:

/* Line 678 of lalr1.cc  */
#line 5169 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 597:

/* Line 678 of lalr1.cc  */
#line 5179 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 598:

/* Line 678 of lalr1.cc  */
#line 5192 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 599:

/* Line 678 of lalr1.cc  */
#line 5198 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 602:

/* Line 678 of lalr1.cc  */
#line 5219 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 603:

/* Line 678 of lalr1.cc  */
#line 5237 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 604:

/* Line 678 of lalr1.cc  */
#line 5241 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 605:

/* Line 678 of lalr1.cc  */
#line 5254 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new EvalExpr(
                LOC((yyloc)), dynamic_cast<VarGetsDeclList *> ((yysemantic_stack_[(7) - (3)].node)), (yysemantic_stack_[(7) - (6)].expr)
            );
        }
    break;

  case 606:

/* Line 678 of lalr1.cc  */
#line 5260 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new EvalExpr( LOC((yyloc)), new VarGetsDeclList( LOC((yyloc)) ), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 607:

/* Line 678 of lalr1.cc  */
#line 5266 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("xquery"); }
    break;

  case 608:

/* Line 678 of lalr1.cc  */
#line 5267 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("empty"); }
    break;

  case 609:

/* Line 678 of lalr1.cc  */
#line 5268 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("attribute"); }
    break;

  case 610:

/* Line 678 of lalr1.cc  */
#line 5269 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("comment"); }
    break;

  case 611:

/* Line 678 of lalr1.cc  */
#line 5270 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("document-node"); }
    break;

  case 612:

/* Line 678 of lalr1.cc  */
#line 5271 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("element"); }
    break;

  case 613:

/* Line 678 of lalr1.cc  */
#line 5272 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("item"); }
    break;

  case 614:

/* Line 678 of lalr1.cc  */
#line 5273 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("if"); }
    break;

  case 615:

/* Line 678 of lalr1.cc  */
#line 5274 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("node"); }
    break;

  case 616:

/* Line 678 of lalr1.cc  */
#line 5275 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("processing-instruction"); }
    break;

  case 617:

/* Line 678 of lalr1.cc  */
#line 5276 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("schema-attribute"); }
    break;

  case 618:

/* Line 678 of lalr1.cc  */
#line 5277 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("schema-element"); }
    break;

  case 619:

/* Line 678 of lalr1.cc  */
#line 5278 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("text"); }
    break;

  case 620:

/* Line 678 of lalr1.cc  */
#line 5279 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("typeswitch"); }
    break;

  case 621:

/* Line 678 of lalr1.cc  */
#line 5280 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("empty-sequence"); }
    break;

  case 622:

/* Line 678 of lalr1.cc  */
#line 5281 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("boundary-space"); }
    break;

  case 623:

/* Line 678 of lalr1.cc  */
#line 5282 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ft-option"); }
    break;

  case 624:

/* Line 678 of lalr1.cc  */
#line 5283 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("base-uri"); }
    break;

  case 625:

/* Line 678 of lalr1.cc  */
#line 5284 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("lax"); }
    break;

  case 626:

/* Line 678 of lalr1.cc  */
#line 5285 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("strict"); }
    break;

  case 627:

/* Line 678 of lalr1.cc  */
#line 5286 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("idiv"); }
    break;

  case 628:

/* Line 678 of lalr1.cc  */
#line 5287 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("document"); }
    break;

  case 629:

/* Line 678 of lalr1.cc  */
#line 5288 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ftnot"); }
    break;

  case 630:

/* Line 678 of lalr1.cc  */
#line 5289 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("not"); }
    break;

  case 631:

/* Line 678 of lalr1.cc  */
#line 5290 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("sensitive"); }
    break;

  case 632:

/* Line 678 of lalr1.cc  */
#line 5291 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("insensitive"); }
    break;

  case 633:

/* Line 678 of lalr1.cc  */
#line 5292 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("diacritics"); }
    break;

  case 634:

/* Line 678 of lalr1.cc  */
#line 5293 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("without"); }
    break;

  case 635:

/* Line 678 of lalr1.cc  */
#line 5294 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("stemming"); }
    break;

  case 636:

/* Line 678 of lalr1.cc  */
#line 5295 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("thesaurus"); }
    break;

  case 637:

/* Line 678 of lalr1.cc  */
#line 5296 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("stop"); }
    break;

  case 638:

/* Line 678 of lalr1.cc  */
#line 5297 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("wildcards"); }
    break;

  case 639:

/* Line 678 of lalr1.cc  */
#line 5298 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("entire"); }
    break;

  case 640:

/* Line 678 of lalr1.cc  */
#line 5299 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("content"); }
    break;

  case 641:

/* Line 678 of lalr1.cc  */
#line 5300 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("word"); }
    break;

  case 642:

/* Line 678 of lalr1.cc  */
#line 5301 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("start"); }
    break;

  case 643:

/* Line 678 of lalr1.cc  */
#line 5302 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("end"); }
    break;

  case 644:

/* Line 678 of lalr1.cc  */
#line 5303 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("most"); }
    break;

  case 645:

/* Line 678 of lalr1.cc  */
#line 5304 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("skip"); }
    break;

  case 646:

/* Line 678 of lalr1.cc  */
#line 5305 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("copy"); }
    break;

  case 647:

/* Line 678 of lalr1.cc  */
#line 5306 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("general"); }
    break;

  case 648:

/* Line 678 of lalr1.cc  */
#line 5307 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("value"); }
    break;

  case 649:

/* Line 678 of lalr1.cc  */
#line 5308 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("eq"); }
    break;

  case 650:

/* Line 678 of lalr1.cc  */
#line 5309 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ne"); }
    break;

  case 651:

/* Line 678 of lalr1.cc  */
#line 5310 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("lt"); }
    break;

  case 652:

/* Line 678 of lalr1.cc  */
#line 5311 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("le"); }
    break;

  case 653:

/* Line 678 of lalr1.cc  */
#line 5312 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("gt"); }
    break;

  case 654:

/* Line 678 of lalr1.cc  */
#line 5313 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ge"); }
    break;

  case 655:

/* Line 678 of lalr1.cc  */
#line 5314 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("at"); }
    break;

  case 656:

/* Line 678 of lalr1.cc  */
#line 5315 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("context"); }
    break;

  case 657:

/* Line 678 of lalr1.cc  */
#line 5316 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("variable"); }
    break;

  case 658:

/* Line 678 of lalr1.cc  */
#line 5317 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("return"); }
    break;

  case 659:

/* Line 678 of lalr1.cc  */
#line 5318 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("for"); }
    break;

  case 660:

/* Line 678 of lalr1.cc  */
#line 5319 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("outer"); }
    break;

  case 661:

/* Line 678 of lalr1.cc  */
#line 5320 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("sliding"); }
    break;

  case 662:

/* Line 678 of lalr1.cc  */
#line 5321 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("tumbling"); }
    break;

  case 663:

/* Line 678 of lalr1.cc  */
#line 5322 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("previous"); }
    break;

  case 664:

/* Line 678 of lalr1.cc  */
#line 5323 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("next"); }
    break;

  case 665:

/* Line 678 of lalr1.cc  */
#line 5324 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("only"); }
    break;

  case 666:

/* Line 678 of lalr1.cc  */
#line 5325 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("when"); }
    break;

  case 667:

/* Line 678 of lalr1.cc  */
#line 5326 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("count"); }
    break;

  case 668:

/* Line 678 of lalr1.cc  */
#line 5327 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("in"); }
    break;

  case 669:

/* Line 678 of lalr1.cc  */
#line 5328 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("let"); }
    break;

  case 670:

/* Line 678 of lalr1.cc  */
#line 5329 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("where"); }
    break;

  case 671:

/* Line 678 of lalr1.cc  */
#line 5330 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("by"); }
    break;

  case 672:

/* Line 678 of lalr1.cc  */
#line 5331 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("group"); }
    break;

  case 673:

/* Line 678 of lalr1.cc  */
#line 5332 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("order"); }
    break;

  case 674:

/* Line 678 of lalr1.cc  */
#line 5333 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("stable"); }
    break;

  case 675:

/* Line 678 of lalr1.cc  */
#line 5334 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ascending"); }
    break;

  case 676:

/* Line 678 of lalr1.cc  */
#line 5335 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("descending"); }
    break;

  case 677:

/* Line 678 of lalr1.cc  */
#line 5336 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("greatest"); }
    break;

  case 678:

/* Line 678 of lalr1.cc  */
#line 5337 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("least"); }
    break;

  case 679:

/* Line 678 of lalr1.cc  */
#line 5338 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("collation"); }
    break;

  case 680:

/* Line 678 of lalr1.cc  */
#line 5339 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("some"); }
    break;

  case 681:

/* Line 678 of lalr1.cc  */
#line 5340 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("every"); }
    break;

  case 682:

/* Line 678 of lalr1.cc  */
#line 5341 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("satisfies"); }
    break;

  case 683:

/* Line 678 of lalr1.cc  */
#line 5342 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("case"); }
    break;

  case 684:

/* Line 678 of lalr1.cc  */
#line 5343 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("as"); }
    break;

  case 685:

/* Line 678 of lalr1.cc  */
#line 5344 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("then"); }
    break;

  case 686:

/* Line 678 of lalr1.cc  */
#line 5345 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("else"); }
    break;

  case 687:

/* Line 678 of lalr1.cc  */
#line 5346 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("or"); }
    break;

  case 688:

/* Line 678 of lalr1.cc  */
#line 5347 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("and"); }
    break;

  case 689:

/* Line 678 of lalr1.cc  */
#line 5348 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("instance"); }
    break;

  case 690:

/* Line 678 of lalr1.cc  */
#line 5349 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("of"); }
    break;

  case 691:

/* Line 678 of lalr1.cc  */
#line 5350 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("castable"); }
    break;

  case 692:

/* Line 678 of lalr1.cc  */
#line 5351 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("to"); }
    break;

  case 693:

/* Line 678 of lalr1.cc  */
#line 5352 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("div"); }
    break;

  case 694:

/* Line 678 of lalr1.cc  */
#line 5353 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("mod"); }
    break;

  case 695:

/* Line 678 of lalr1.cc  */
#line 5354 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("union"); }
    break;

  case 696:

/* Line 678 of lalr1.cc  */
#line 5355 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("intersect"); }
    break;

  case 697:

/* Line 678 of lalr1.cc  */
#line 5356 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("except"); }
    break;

  case 698:

/* Line 678 of lalr1.cc  */
#line 5357 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("validate"); }
    break;

  case 699:

/* Line 678 of lalr1.cc  */
#line 5358 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("cast"); }
    break;

  case 700:

/* Line 678 of lalr1.cc  */
#line 5359 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("treat"); }
    break;

  case 701:

/* Line 678 of lalr1.cc  */
#line 5360 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("is"); }
    break;

  case 702:

/* Line 678 of lalr1.cc  */
#line 5361 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("preserve"); }
    break;

  case 703:

/* Line 678 of lalr1.cc  */
#line 5362 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("strip"); }
    break;

  case 704:

/* Line 678 of lalr1.cc  */
#line 5363 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("namespace"); }
    break;

  case 705:

/* Line 678 of lalr1.cc  */
#line 5364 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("external"); }
    break;

  case 706:

/* Line 678 of lalr1.cc  */
#line 5365 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("encoding"); }
    break;

  case 707:

/* Line 678 of lalr1.cc  */
#line 5366 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("no-preserve"); }
    break;

  case 708:

/* Line 678 of lalr1.cc  */
#line 5367 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("inherit"); }
    break;

  case 709:

/* Line 678 of lalr1.cc  */
#line 5368 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("no-inherit"); }
    break;

  case 710:

/* Line 678 of lalr1.cc  */
#line 5369 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("declare"); }
    break;

  case 711:

/* Line 678 of lalr1.cc  */
#line 5370 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("construction"); }
    break;

  case 712:

/* Line 678 of lalr1.cc  */
#line 5371 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ordering"); }
    break;

  case 713:

/* Line 678 of lalr1.cc  */
#line 5372 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("default"); }
    break;

  case 714:

/* Line 678 of lalr1.cc  */
#line 5373 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("copy-namespaces"); }
    break;

  case 715:

/* Line 678 of lalr1.cc  */
#line 5374 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("option"); }
    break;

  case 716:

/* Line 678 of lalr1.cc  */
#line 5375 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("version"); }
    break;

  case 717:

/* Line 678 of lalr1.cc  */
#line 5376 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("import"); }
    break;

  case 718:

/* Line 678 of lalr1.cc  */
#line 5377 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("schema"); }
    break;

  case 719:

/* Line 678 of lalr1.cc  */
#line 5378 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("module"); }
    break;

  case 720:

/* Line 678 of lalr1.cc  */
#line 5379 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("function"); }
    break;

  case 721:

/* Line 678 of lalr1.cc  */
#line 5380 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("score"); }
    break;

  case 722:

/* Line 678 of lalr1.cc  */
#line 5381 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("contains"); }
    break;

  case 723:

/* Line 678 of lalr1.cc  */
#line 5382 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("weight"); }
    break;

  case 724:

/* Line 678 of lalr1.cc  */
#line 5383 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("window"); }
    break;

  case 725:

/* Line 678 of lalr1.cc  */
#line 5384 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("distance"); }
    break;

  case 726:

/* Line 678 of lalr1.cc  */
#line 5385 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("occurs"); }
    break;

  case 727:

/* Line 678 of lalr1.cc  */
#line 5386 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("times"); }
    break;

  case 728:

/* Line 678 of lalr1.cc  */
#line 5387 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("same"); }
    break;

  case 729:

/* Line 678 of lalr1.cc  */
#line 5388 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("different"); }
    break;

  case 730:

/* Line 678 of lalr1.cc  */
#line 5389 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("lowercase"); }
    break;

  case 731:

/* Line 678 of lalr1.cc  */
#line 5390 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("uppercase"); }
    break;

  case 732:

/* Line 678 of lalr1.cc  */
#line 5391 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("relationship"); }
    break;

  case 733:

/* Line 678 of lalr1.cc  */
#line 5392 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("levels"); }
    break;

  case 734:

/* Line 678 of lalr1.cc  */
#line 5393 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("language"); }
    break;

  case 735:

/* Line 678 of lalr1.cc  */
#line 5394 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("any"); }
    break;

  case 736:

/* Line 678 of lalr1.cc  */
#line 5395 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("all"); }
    break;

  case 737:

/* Line 678 of lalr1.cc  */
#line 5396 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("phrase"); }
    break;

  case 738:

/* Line 678 of lalr1.cc  */
#line 5397 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("exactly"); }
    break;

  case 739:

/* Line 678 of lalr1.cc  */
#line 5398 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("from"); }
    break;

  case 740:

/* Line 678 of lalr1.cc  */
#line 5399 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("words"); }
    break;

  case 741:

/* Line 678 of lalr1.cc  */
#line 5400 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("sentences"); }
    break;

  case 742:

/* Line 678 of lalr1.cc  */
#line 5401 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("sentence"); }
    break;

  case 743:

/* Line 678 of lalr1.cc  */
#line 5402 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("paragraph"); }
    break;

  case 744:

/* Line 678 of lalr1.cc  */
#line 5403 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("replace"); }
    break;

  case 745:

/* Line 678 of lalr1.cc  */
#line 5404 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("modify"); }
    break;

  case 746:

/* Line 678 of lalr1.cc  */
#line 5405 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("first"); }
    break;

  case 747:

/* Line 678 of lalr1.cc  */
#line 5406 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("insert"); }
    break;

  case 748:

/* Line 678 of lalr1.cc  */
#line 5407 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("before"); }
    break;

  case 749:

/* Line 678 of lalr1.cc  */
#line 5408 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("after"); }
    break;

  case 750:

/* Line 678 of lalr1.cc  */
#line 5409 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("revalidation"); }
    break;

  case 751:

/* Line 678 of lalr1.cc  */
#line 5410 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("with"); }
    break;

  case 752:

/* Line 678 of lalr1.cc  */
#line 5411 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("nodes"); }
    break;

  case 753:

/* Line 678 of lalr1.cc  */
#line 5412 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("rename"); }
    break;

  case 754:

/* Line 678 of lalr1.cc  */
#line 5413 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("last"); }
    break;

  case 755:

/* Line 678 of lalr1.cc  */
#line 5414 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("delete"); }
    break;

  case 756:

/* Line 678 of lalr1.cc  */
#line 5415 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("into"); }
    break;

  case 757:

/* Line 678 of lalr1.cc  */
#line 5416 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("simple"); }
    break;

  case 758:

/* Line 678 of lalr1.cc  */
#line 5417 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("sequential"); }
    break;

  case 759:

/* Line 678 of lalr1.cc  */
#line 5418 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("updating"); }
    break;

  case 760:

/* Line 678 of lalr1.cc  */
#line 5419 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("deterministic"); }
    break;

  case 761:

/* Line 678 of lalr1.cc  */
#line 5420 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("nondeterministic"); }
    break;

  case 762:

/* Line 678 of lalr1.cc  */
#line 5421 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ordered"); }
    break;

  case 763:

/* Line 678 of lalr1.cc  */
#line 5422 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("unordered"); }
    break;

  case 764:

/* Line 678 of lalr1.cc  */
#line 5423 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("returning"); }
    break;

  case 765:

/* Line 678 of lalr1.cc  */
#line 5424 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("block"); }
    break;

  case 766:

/* Line 678 of lalr1.cc  */
#line 5425 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("exit"); }
    break;

  case 767:

/* Line 678 of lalr1.cc  */
#line 5426 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("loop"); }
    break;

  case 768:

/* Line 678 of lalr1.cc  */
#line 5427 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("while"); }
    break;

  case 769:

/* Line 678 of lalr1.cc  */
#line 5428 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("break"); }
    break;

  case 770:

/* Line 678 of lalr1.cc  */
#line 5429 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("continue"); }
    break;

  case 771:

/* Line 678 of lalr1.cc  */
#line 5430 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("try"); }
    break;

  case 772:

/* Line 678 of lalr1.cc  */
#line 5431 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("catch"); }
    break;

  case 773:

/* Line 678 of lalr1.cc  */
#line 5432 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("eval"); }
    break;

  case 774:

/* Line 678 of lalr1.cc  */
#line 5433 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("using"); }
    break;

  case 775:

/* Line 678 of lalr1.cc  */
#line 5434 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("set"); }
    break;

  case 776:

/* Line 678 of lalr1.cc  */
#line 5435 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("index"); }
    break;

  case 777:

/* Line 678 of lalr1.cc  */
#line 5436 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("unique"); }
    break;

  case 778:

/* Line 678 of lalr1.cc  */
#line 5437 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("non"); }
    break;

  case 779:

/* Line 678 of lalr1.cc  */
#line 5438 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("on"); }
    break;

  case 780:

/* Line 678 of lalr1.cc  */
#line 5439 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("range"); }
    break;

  case 781:

/* Line 678 of lalr1.cc  */
#line 5440 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("equality"); }
    break;

  case 782:

/* Line 678 of lalr1.cc  */
#line 5441 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("manually"); }
    break;

  case 783:

/* Line 678 of lalr1.cc  */
#line 5442 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("automatically"); }
    break;

  case 784:

/* Line 678 of lalr1.cc  */
#line 5443 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("maintained"); }
    break;

  case 785:

/* Line 678 of lalr1.cc  */
#line 5444 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("decimal-format"); }
    break;

  case 786:

/* Line 678 of lalr1.cc  */
#line 5445 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("decimal-separator"); }
    break;

  case 787:

/* Line 678 of lalr1.cc  */
#line 5446 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("grouping-separator"); }
    break;

  case 788:

/* Line 678 of lalr1.cc  */
#line 5447 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("infinity"); }
    break;

  case 789:

/* Line 678 of lalr1.cc  */
#line 5448 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("minus-sign"); }
    break;

  case 790:

/* Line 678 of lalr1.cc  */
#line 5449 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("NaN"); }
    break;

  case 791:

/* Line 678 of lalr1.cc  */
#line 5450 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("percent"); }
    break;

  case 792:

/* Line 678 of lalr1.cc  */
#line 5451 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("per-mille"); }
    break;

  case 793:

/* Line 678 of lalr1.cc  */
#line 5452 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("zero-digit"); }
    break;

  case 794:

/* Line 678 of lalr1.cc  */
#line 5453 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("digit"); }
    break;

  case 795:

/* Line 678 of lalr1.cc  */
#line 5454 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("pattern-separator"); }
    break;

  case 796:

/* Line 678 of lalr1.cc  */
#line 5455 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("collection"); }
    break;

  case 797:

/* Line 678 of lalr1.cc  */
#line 5456 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("const"); }
    break;

  case 798:

/* Line 678 of lalr1.cc  */
#line 5457 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("append-only"); }
    break;

  case 799:

/* Line 678 of lalr1.cc  */
#line 5458 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("queue"); }
    break;

  case 800:

/* Line 678 of lalr1.cc  */
#line 5459 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("mutable"); }
    break;

  case 801:

/* Line 678 of lalr1.cc  */
#line 5460 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("read-only"); }
    break;

  case 802:

/* Line 678 of lalr1.cc  */
#line 5461 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("integrity"); }
    break;

  case 803:

/* Line 678 of lalr1.cc  */
#line 5462 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("constraint"); }
    break;

  case 804:

/* Line 678 of lalr1.cc  */
#line 5463 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("check"); }
    break;

  case 805:

/* Line 678 of lalr1.cc  */
#line 5464 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("key"); }
    break;

  case 806:

/* Line 678 of lalr1.cc  */
#line 5465 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("foreach"); }
    break;

  case 807:

/* Line 678 of lalr1.cc  */
#line 5466 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("foreign"); }
    break;

  case 808:

/* Line 678 of lalr1.cc  */
#line 5467 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("keys"); }
    break;

  case 809:

/* Line 678 of lalr1.cc  */
#line 5479 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 810:

/* Line 678 of lalr1.cc  */
#line 5487 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 811:

/* Line 678 of lalr1.cc  */
#line 5491 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 812:

/* Line 678 of lalr1.cc  */
#line 5498 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 813:

/* Line 678 of lalr1.cc  */
#line 5503 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 814:

/* Line 678 of lalr1.cc  */
#line 5511 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 815:

/* Line 678 of lalr1.cc  */
#line 5515 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 816:

/* Line 678 of lalr1.cc  */
#line 5522 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 817:

/* Line 678 of lalr1.cc  */
#line 5526 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 818:

/* Line 678 of lalr1.cc  */
#line 5533 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 819:

/* Line 678 of lalr1.cc  */
#line 5537 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 820:

/* Line 678 of lalr1.cc  */
#line 5544 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 821:

/* Line 678 of lalr1.cc  */
#line 5548 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 822:

/* Line 678 of lalr1.cc  */
#line 5557 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 823:

/* Line 678 of lalr1.cc  */
#line 5569 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 824:

/* Line 678 of lalr1.cc  */
#line 5573 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 825:

/* Line 678 of lalr1.cc  */
#line 5580 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 826:

/* Line 678 of lalr1.cc  */
#line 5584 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 827:

/* Line 678 of lalr1.cc  */
#line 5592 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 828:

/* Line 678 of lalr1.cc  */
#line 5600 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 829:

/* Line 678 of lalr1.cc  */
#line 5608 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 830:

/* Line 678 of lalr1.cc  */
#line 5612 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 831:

/* Line 678 of lalr1.cc  */
#line 5619 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 832:

/* Line 678 of lalr1.cc  */
#line 5623 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 833:

/* Line 678 of lalr1.cc  */
#line 5631 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 834:

/* Line 678 of lalr1.cc  */
#line 5642 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 835:

/* Line 678 of lalr1.cc  */
#line 5646 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 836:

/* Line 678 of lalr1.cc  */
#line 5654 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 837:

/* Line 678 of lalr1.cc  */
#line 5666 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 838:

/* Line 678 of lalr1.cc  */
#line 5672 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 839:

/* Line 678 of lalr1.cc  */
#line 5681 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 840:

/* Line 678 of lalr1.cc  */
#line 5685 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 841:

/* Line 678 of lalr1.cc  */
#line 5693 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 842:

/* Line 678 of lalr1.cc  */
#line 5697 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 843:

/* Line 678 of lalr1.cc  */
#line 5701 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 844:

/* Line 678 of lalr1.cc  */
#line 5708 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 845:

/* Line 678 of lalr1.cc  */
#line 5712 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 846:

/* Line 678 of lalr1.cc  */
#line 5719 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 847:

/* Line 678 of lalr1.cc  */
#line 5723 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 848:

/* Line 678 of lalr1.cc  */
#line 5731 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 849:

/* Line 678 of lalr1.cc  */
#line 5735 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 850:

/* Line 678 of lalr1.cc  */
#line 5739 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 851:

/* Line 678 of lalr1.cc  */
#line 5743 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 852:

/* Line 678 of lalr1.cc  */
#line 5747 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 853:

/* Line 678 of lalr1.cc  */
#line 5755 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 854:

/* Line 678 of lalr1.cc  */
#line 5763 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 855:

/* Line 678 of lalr1.cc  */
#line 5775 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 856:

/* Line 678 of lalr1.cc  */
#line 5787 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 857:

/* Line 678 of lalr1.cc  */
#line 5791 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 858:

/* Line 678 of lalr1.cc  */
#line 5795 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 859:

/* Line 678 of lalr1.cc  */
#line 5803 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 860:

/* Line 678 of lalr1.cc  */
#line 5809 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 861:

/* Line 678 of lalr1.cc  */
#line 5819 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 862:

/* Line 678 of lalr1.cc  */
#line 5823 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 863:

/* Line 678 of lalr1.cc  */
#line 5827 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 864:

/* Line 678 of lalr1.cc  */
#line 5831 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 865:

/* Line 678 of lalr1.cc  */
#line 5835 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 866:

/* Line 678 of lalr1.cc  */
#line 5839 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 867:

/* Line 678 of lalr1.cc  */
#line 5843 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 868:

/* Line 678 of lalr1.cc  */
#line 5847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 869:

/* Line 678 of lalr1.cc  */
#line 5855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 870:

/* Line 678 of lalr1.cc  */
#line 5859 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 871:

/* Line 678 of lalr1.cc  */
#line 5863 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 872:

/* Line 678 of lalr1.cc  */
#line 5867 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 873:

/* Line 678 of lalr1.cc  */
#line 5875 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::senstive
            );
        }
    break;

  case 874:

/* Line 678 of lalr1.cc  */
#line 5881 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 875:

/* Line 678 of lalr1.cc  */
#line 5891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 876:

/* Line 678 of lalr1.cc  */
#line 5901 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::with );
        }
    break;

  case 877:

/* Line 678 of lalr1.cc  */
#line 5905 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::without );
        }
    break;

  case 878:

/* Line 678 of lalr1.cc  */
#line 5913 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 879:

/* Line 678 of lalr1.cc  */
#line 5923 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 880:

/* Line 678 of lalr1.cc  */
#line 5934 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 881:

/* Line 678 of lalr1.cc  */
#line 5941 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 882:

/* Line 678 of lalr1.cc  */
#line 5945 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 883:

/* Line 678 of lalr1.cc  */
#line 5952 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 884:

/* Line 678 of lalr1.cc  */
#line 5956 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(1) - (1)].thesaurus_id_list);
        }
    break;

  case 885:

/* Line 678 of lalr1.cc  */
#line 5963 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 886:

/* Line 678 of lalr1.cc  */
#line 5968 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 887:

/* Line 678 of lalr1.cc  */
#line 5977 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 888:

/* Line 678 of lalr1.cc  */
#line 5986 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = NULL;
        }
    break;

  case 889:

/* Line 678 of lalr1.cc  */
#line 5990 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 890:

/* Line 678 of lalr1.cc  */
#line 5997 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 891:

/* Line 678 of lalr1.cc  */
#line 6001 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 892:

/* Line 678 of lalr1.cc  */
#line 6009 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 893:

/* Line 678 of lalr1.cc  */
#line 6018 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 894:

/* Line 678 of lalr1.cc  */
#line 6025 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 895:

/* Line 678 of lalr1.cc  */
#line 6035 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 896:

/* Line 678 of lalr1.cc  */
#line 6039 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), NULL, (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 897:

/* Line 678 of lalr1.cc  */
#line 6046 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 898:

/* Line 678 of lalr1.cc  */
#line 6052 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 899:

/* Line 678 of lalr1.cc  */
#line 6061 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 900:

/* Line 678 of lalr1.cc  */
#line 6065 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 901:

/* Line 678 of lalr1.cc  */
#line 6072 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 902:

/* Line 678 of lalr1.cc  */
#line 6077 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 903:

/* Line 678 of lalr1.cc  */
#line 6089 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 904:

/* Line 678 of lalr1.cc  */
#line 6097 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 905:

/* Line 678 of lalr1.cc  */
#line 6109 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 906:

/* Line 678 of lalr1.cc  */
#line 6117 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 907:

/* Line 678 of lalr1.cc  */
#line 6121 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 908:

/* Line 678 of lalr1.cc  */
#line 6129 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 909:

/* Line 678 of lalr1.cc  */
#line 6133 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 910:

/* Line 678 of lalr1.cc  */
#line 6137 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 911:

/* Line 678 of lalr1.cc  */
#line 6145 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 912:

/* Line 678 of lalr1.cc  */
#line 6153 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange(
                LOC((yyloc)),
                ft_range_mode::exactly,
                dynamic_cast<AdditiveExpr*>((yysemantic_stack_[(2) - (2)].expr))
            );
        }
    break;

  case 913:

/* Line 678 of lalr1.cc  */
#line 6161 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange(
                LOC((yyloc)),
                ft_range_mode::at_least,
                dynamic_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (3)].expr))
            );
        }
    break;

  case 914:

/* Line 678 of lalr1.cc  */
#line 6169 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange(
                LOC((yyloc)),
                ft_range_mode::at_most,
                dynamic_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (3)].expr))
            );
        }
    break;

  case 915:

/* Line 678 of lalr1.cc  */
#line 6177 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange(
                LOC((yyloc)),
                ft_range_mode::from_to,
                dynamic_cast<AdditiveExpr*>((yysemantic_stack_[(4) - (2)].expr)),
                dynamic_cast<AdditiveExpr*>((yysemantic_stack_[(4) - (4)].expr))
            );
        }
    break;

  case 916:

/* Line 678 of lalr1.cc  */
#line 6190 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 917:

/* Line 678 of lalr1.cc  */
#line 6198 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 918:

/* Line 678 of lalr1.cc  */
#line 6210 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 919:

/* Line 678 of lalr1.cc  */
#line 6214 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 920:

/* Line 678 of lalr1.cc  */
#line 6222 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;



/* Line 678 of lalr1.cc  */
#line 11132 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1294;
  const short int
  xquery_parser::yypact_[] =
  {
      1526, -1294, -1294, -1294, -1294,   945,   -58, -1294, -1294,   430,
   -1294, -1294, -1294, -1294,     4,    33,  9369,    40,    60,   171,
     187,   109, -1294,   277, -1294, -1294, -1294, -1294, -1294, -1294,
     362, -1294,  7655, -1294, -1294,   316, -1294,   365, -1294, -1294,
     383, -1294,   431, -1294,   429, -1294,   256, -1294, -1294, -1294,
   -1294, -1294, -1294, -1294, -1294, -1294, -1294, -1294, -1294, -1294,
   -1294, -1294, -1294, -1294, -1294, -1294,  9653, -1294,  7075, -1294,
   -1294, -1294, -1294, -1294, -1294, -1294, -1294, -1294, -1294, -1294,
   -1294, -1294, 11073, -1294, -1294, -1294, -1294, -1294, -1294, -1294,
   -1294,   491, -1294, -1294, -1294, -1294, -1294, -1294, -1294, -1294,
   -1294, -1294, -1294,  1819, 11073, -1294, -1294, -1294, -1294, -1294,
   -1294, -1294,   462, -1294, -1294, -1294,  8231, -1294,  8517, -1294,
   -1294, -1294, -1294, -1294, 11073, -1294, -1294,  6783, -1294, -1294,
   -1294, -1294, -1294, -1294,   471, -1294, -1294, -1294, -1294, -1294,
   -1294, -1294, -1294,    32,   416, -1294, -1294, -1294, -1294, -1294,
   -1294, -1294, -1294,   311,   497,   412, -1294,   438,   372, -1294,
   -1294, -1294, -1294, -1294, -1294,   537, -1294,   512,   445,   448,
     449, -1294, -1294,   516,   543, -1294,   578, -1294, -1294, -1294,
   -1294, -1294, -1294, -1294, -1294, -1294, -1294, -1294, -1294, -1294,
   -1294, -1294, -1294, -1294, -1294, -1294, -1294, -1294, -1294, -1294,
   -1294, -1294, -1294, -1294, -1294, -1294, -1294, -1294, -1294, -1294,
   -1294, -1294, -1294, -1294, -1294, -1294, -1294, -1294, -1294, -1294,
   -1294, -1294, -1294, -1294, -1294, -1294, -1294, -1294, -1294, -1294,
   -1294, -1294, -1294, -1294, -1294, -1294, -1294,  4739,   690, -1294,
    5031, -1294, -1294,   324,  5323,   510,   519, -1294, -1294, -1294,
   -1294, -1294, -1294, -1294, -1294, -1294, -1294, -1294, -1294, -1294,
   -1294, -1294, -1294, -1294, -1294, -1294, -1294, -1294, -1294, -1294,
   -1294, -1294, -1294, -1294, -1294, -1294, -1294, -1294,   -36, -1294,
   -1294, -1294, -1294,   359, 11073, -1294, -1294, -1294, -1294, -1294,
     534,   608, -1294,   636,   453,   117,   -19,   153,    13, -1294,
     654,   514,   607,   610,  5615, -1294, -1294, -1294,   242, -1294,
   -1294,  6783, -1294,   115, -1294,   557,  7075, -1294,   557,  7075,
   -1294, -1294, -1294,   492, -1294, -1294, -1294, -1294, -1294, -1294,
   -1294, -1294, -1294, -1294, -1294, -1294, -1294, -1294, -1294, -1294,
   -1294, -1294, -1294, -1294, -1294, -1294, -1294, -1294, -1294, -1294,
   -1294, -1294, -1294, -1294, -1294, -1294, -1294, -1294, -1294, -1294,
   -1294, -1294, -1294, -1294, -1294, -1294,   -49, -1294, -1294,   683,
     248,   381,   393,   432, 11073,   432, 11073,   -56,   671,   673,
     674, 11073,   584,   617,   230,  8231, -1294, -1294,   413,   298,
     494, 11073, -1294, -1294, -1294, -1294, -1294,   444, 11073,   440,
     443,   348,   441,   437, -1294, -1294, -1294,  8231,  5323,   561,
    5323,    37, -1294, -1294, -1294, -1294, -1294, -1294, -1294, -1294,
   -1294, -1294, -1294, -1294, -1294, -1294, -1294, -1294, -1294, -1294,
   -1294, -1294, -1294, -1294,  5323,  9937, -1294, -1294, -1294, -1294,
   -1294, -1294, -1294, -1294, -1294, -1294, -1294, -1294, -1294, -1294,
   -1294, -1294,   590,  5323,   463,   464, -1294,   630,    51,   599,
    5323,    66,    45, 11073,   633, -1294,  5323,  7943,   601, -1294,
   11073, 11073, 11073,  5323,   569,  5323, 11073,  5323,   603,   606,
    5323, 10221,   609,   604,   605,   611,   613,   615, -1294, -1294,
   -1294, 11073, -1294,   577,   728,  5323,    44, -1294,   741,   580,
   -1294,  5323,   559, -1294,   745,  5323,  5323,   589,  5323,  5323,
    5323,  5323,   553, 11073, -1294, -1294, -1294, -1294,  5323,  5323,
    5323, 11073, -1294, -1294, -1294, -1294,   945,   109, -1294, -1294,
     324,   751,  5323, -1294,  5323,   666,    60,   277,   362,   620,
     622,   624,  5323,  5323, -1294, -1294, -1294, -1294, -1294, -1294,
   -1294,   688, -1294,    -6,  5907,  5907,  5907, -1294,  5907,  5907,
   -1294,  5907, -1294,  5907, -1294, -1294, -1294, -1294, -1294, -1294,
   -1294,  5907,  5907,   725,  5907,  5907,  5907,  5907,  5907,  5907,
    5907,  5907,  5907,  5907,  5907,   570,   704,   706,   707, -1294,
   -1294, -1294,  2111, -1294, -1294,  6783,  6783,  5323,   557, -1294,
   -1294,   557, -1294,  2403,   557,   656,  2695, -1294, -1294, -1294,
   -1294, -1294, -1294,   697,   699, -1294,   171, -1294,   781, -1294,
   -1294, 11073, -1294, -1294, 11073, -1294,   595,   387, 11073,   481,
     651,   652,   595,   683,   686,   684, -1294, -1294, -1294, -1294,
   -1294,   -17,   571,   -25, -1294,   517, -1294, -1294, -1294, -1294,
   11073, 11073, 11073, -1294,   687,   637, -1294,   639,   605,   316,
   -1294,   638,   642,   640, -1294,     1,   149,  2987,   646, -1294,
   -1294, 11073,   -14, 11073,   729,   155, -1294,  5323, -1294,   644,
    8231,   734,   788,  8231,   683,   738,   735, -1294,   -28, -1294,
     663,   662, -1294,   664,  3279,   665,   710,   -15, -1294,    29,
     670, -1294,   668,   696, -1294,   675,  5323,  5323,   677, -1294,
     160,   186,  3571,   -10, -1294, 11073,   728, -1294,   -26,   678,
   -1294, -1294, -1294, -1294,   679, -1294,    -5, -1294, -1294, -1294,
      38,   100,   760,   626,   632,   -37, -1294,   723,  6199, -1294,
     681,   685,    42, -1294, -1294,   680, -1294,   778, -1294, -1294,
     -23, 11073,   701,  5323,   749, -1294, -1294,   752, 10505,   753,
    5323,   754,   -68,   730,   -46,   608, -1294, -1294, -1294, -1294,
   -1294,  5907, -1294, -1294, -1294,    12,   -19,   -19,   236,   153,
     153,   153,   153,    13,    13, -1294, -1294, 10505, 10505, 11073,
   11073, -1294,   700, -1294, -1294,   695, -1294, -1294, -1294,   190,
   -1294, -1294,   201,   303,   374,     6, -1294,   171,   171, -1294,
   -1294, -1294, -1294, -1294, -1294, -1294, -1294, -1294, -1294,   595,
   -1294,   748, 10789,   740,  5323, -1294, -1294, -1294,   789,   742,
    5323,   683,   683,   595, -1294,   513,   683,   325, 11073,   297,
     304,   857, -1294, -1294,   602,   340, -1294, -1294, -1294, -1294,
   -1294, -1294, -1294, -1294, -1294, -1294, -1294,   -17,    92,   367,
   -1294,   661,   182,   -20,   594,   683, -1294, -1294, -1294, -1294,
     737, 11073, -1294, 11073, -1294, -1294,   712, -1294,    36,   643,
   -1294, -1294,   360,   -14,   789, 10505,   777,   803,   717,   705,
     769,   683,   744,   773,   808,   683,   787,  5323,   766,   -73,
     756, -1294, -1294, -1294,   727, -1294,  5323,   792,  5323,  5323,
     767, -1294,   813,  5323, -1294,   733,   743,   764, 11073, -1294,
   11073, -1294, -1294,   746,  5323,   887, -1294,    48, -1294,   177,
   -1294, -1294,   899, -1294,   333,  5323,  5323,  5323,   420,  5323,
    5323,  5323,  5323,  5323,  5323,   810,  5323,  5323,   617,   -11,
     755,   512,   689,   779,   811,   751,   853, -1294, -1294,  5323,
     349,   827, -1294, 11073,   828, -1294, 11073,   783,   784, 10789,
     785, -1294,   269, -1294, -1294, -1294, -1294, -1294, -1294, -1294,
   11073, -1294, 11073,  5323,   796,  5323,  5323,   -42,   797, -1294,
    5323,    12,   173,   271, -1294,   659,    35,   691,   692, -1294,
   -1294,   494, -1294,   693,   284, -1294, -1294, -1294,   802, -1294,
   -1294, -1294,  5323, -1294, -1294, -1294, -1294, -1294, -1294, -1294,
    5323, -1294,   375,   411, -1294,   919,   490, -1294, -1294, -1294,
    5323, -1294, -1294, -1294, -1294, -1294, -1294, -1294,   667, -1294,
   -1294,   920, -1294, -1294, -1294, -1294, -1294,   344,   923, -1294,
     427, -1294, -1294, -1294,   604,    33,   611,   613,   615,   497,
     718,   269,   731,   736,  6491,   669,   653,    92, -1294,   739,
     774,  3863,   782,   786,   821,   790,   791, -1294,  5323,   820,
   -1294,   849,   850,  5323, 11073,   511,   892, -1294, -1294, -1294,
   -1294, -1294, -1294, 10505, -1294,  5323,   683,   865, -1294, -1294,
   -1294,   683,   865, 11073, -1294,  5323,  5323,   836,  4155, -1294,
   -1294, 11073, -1294, -1294,  5323,  9085,   158, -1294,   798, -1294,
   -1294,  4447,   794,   801, -1294, -1294, -1294,   859, -1294,   191,
   -1294, -1294,   974, -1294, -1294, 11073, -1294, -1294,   418, -1294,
   -1294, -1294,   805,   759,   763, -1294, -1294, -1294,   765,   768,
   -1294, -1294, -1294, -1294, -1294,   762, 11073,   812, -1294,   851,
   -1294,   617, -1294, -1294, -1294,  7367,   689, -1294,  5323, 11073,
     827, -1294,   683, -1294,   533, -1294,   166,   895, -1294,  5323,
     898,   749, -1294,  8801,   814,   824,   825, -1294, -1294, -1294,
   -1294, -1294, -1294, -1294,  5323, -1294, -1294,  5323,   860,  5323,
     830,   832, -1294,    12,   772, -1294, -1294,    73, -1294,   313,
     -43,   776,    12,   313,  5907, -1294,    83, -1294, -1294, -1294,
   -1294, -1294, -1294,    12,   869,   747,   571,   -43, -1294, -1294,
     732,   940, -1294, -1294, -1294, -1294, -1294,   841, -1294, -1294,
   -1294,  5323, -1294, -1294, -1294, -1294, -1294,   996,   196,   999,
     196,   757,   933, -1294, -1294, -1294, -1294,   862, 11073,   775,
     718,  6491, -1294, -1294,   852, -1294, -1294, -1294, -1294, -1294,
   -1294,  5323, 11073, 11073, -1294,    84, -1294,  5323, -1294,   910,
     939,   683,   865, -1294, -1294, -1294,  5323, -1294,   855, -1294,
   -1294, 11073,   854,   181, -1294, -1294, -1294,   858, -1294, -1294,
     887, 11073,   435, -1294,   887, 11073, -1294, -1294,  5323,  5323,
    5323,  5323,  5323, -1294,  5323,  5323, -1294, -1294,   270, -1294,
     861, -1294, -1294, -1294, -1294,   895, -1294, -1294, -1294,   683,
   -1294, -1294,   946,   863, -1294,   216, -1294, -1294, -1294, -1294,
   -1294,  5323, -1294, -1294, -1294, -1294,   864,  5907, -1294, -1294,
   -1294, -1294, -1294,    27,  5907,  5907,   234, -1294,   691, -1294,
     129, -1294,   692,    12,   890, -1294, -1294,   770, -1294, -1294,
   -1294, -1294, -1294,   -21, -1294,   205,   205, -1294,   196, -1294,
   -1294,   231, -1294,  1016,   -43,   866,   937, -1294,  6491,   -75,
     795, -1294,   878, -1294, -1294, -1294,   995, -1294, -1294,  5323,
     683, -1294, -1294, -1294,   957,  5323, 11073,  5323, -1294,   -13,
     887, 11073,   867,   887, -1294, -1294, -1294, -1294, -1294, -1294,
   -1294,   934,  7367, -1294, -1294, -1294, -1294, 10505, -1294, 10505,
     959, -1294, -1294,   153,  5907,  5907,   236,   184, -1294, -1294,
   -1294, -1294, -1294, -1294,  5323, -1294, -1294, -1294, -1294, -1294,
    1027, -1294, -1294, -1294,   799, -1294,   933,   948, -1294,   965,
   11073,   942,   839, 11073,  6491,   951, -1294,   865, 10505, -1294,
     893, -1294,    67,   296, -1294,   883,   887, -1294,   884, 11073,
   -1294, -1294, -1294, 10505,   236,   236,  5907,   901, -1294, -1294,
   -1294,  6491, 11073,   793, 11073,   967,   868,   948, 11073,   900,
    5323, -1294, -1294,   993,    74, -1294, -1294, -1294, -1294,   907,
     364, -1294, -1294, -1294,   894, -1294,   245, -1294,   236, -1294,
   -1294,   895,  5323,   800, 11073,   971, -1294,  5323, -1294, -1294,
   -1294, -1294, -1294, -1294, -1294, -1294,   972,   941, -1294, -1294,
     804,   806, 11073, -1294, 11073, -1294,   809,  5323,   815,   251,
    6491, -1294,  6491,   975,   941, -1294,   902, 11073, -1294,   819,
     911, 11073,   941,   876, -1294,   982, 11073,   816,  6491, -1294
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
         0,   404,   405,   603,   558,   710,   719,   624,   622,   610,
     711,   714,   667,   760,   628,   611,   612,   773,   659,   720,
     614,   717,   689,   669,   644,   664,   761,   665,   715,   712,
     660,   663,   616,   718,   617,   618,   758,   775,   757,   661,
     680,   674,   619,   662,   620,   759,   698,   666,   641,   785,
     786,   787,   788,   789,   790,   791,   792,   793,   794,   795,
     395,   398,   688,   684,   675,   655,   609,   385,     0,   683,
     691,   699,   383,   679,   424,   656,   657,   713,   384,   387,
     676,   693,     0,   430,   393,   426,   686,   608,   677,   678,
     706,   681,   697,   705,   389,   388,   627,   668,   708,   425,
     696,   701,   613,     0,     0,   342,   694,   704,   709,   707,
     687,   673,   762,   671,   672,   394,     0,   341,     0,   397,
     396,   702,   658,   682,     0,   386,   371,     0,   403,   703,
     685,   692,   700,   695,   763,   649,   654,   653,   652,   651,
     650,   621,   670,     0,   607,   716,   642,   749,   748,   750,
     626,   625,   645,   755,   615,   747,   752,   753,   744,   648,
     690,   746,   756,   754,   745,   646,   751,   765,   769,   770,
     766,   767,   764,   768,   771,   772,   774,   736,   735,   722,
     640,   633,   729,   725,   643,   639,   738,   739,   629,   630,
     623,   632,   734,   733,   730,   726,   743,   737,   732,   728,
     721,   631,   742,   741,   635,   637,   636,   727,   731,   723,
     638,   724,   634,   740,   796,   797,   798,   799,   800,   801,
     777,   778,   776,   782,   783,   784,   779,   780,   781,   647,
     802,   803,   804,   805,   806,   807,   808,     0,     0,     2,
       0,     4,     6,    12,     0,     0,     0,    18,    20,    29,
      22,    23,    24,    50,    25,    34,    30,    54,    55,    56,
      51,    52,    58,    59,    28,    26,    27,    32,    33,    53,
     200,   199,   196,   197,   198,    31,    11,   177,   178,   182,
     184,   215,   221,     0,     0,   213,   214,   185,   186,   187,
     188,   297,   299,   301,   311,   315,   317,   320,   325,   328,
     331,   333,   335,   337,     0,   339,   345,   347,     0,   363,
     346,   367,   370,   372,   375,   377,     0,   382,   379,     0,
     390,   400,   402,   376,   406,   413,   422,   414,   415,   416,
     419,   420,   417,   418,   437,   439,   440,   441,   438,   486,
     487,   488,   489,   490,   491,   399,   532,   524,   531,   530,
     529,   526,   528,   525,   527,   423,   421,   559,   560,    57,
     189,   190,   192,   191,   193,   194,   401,   195,   604,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   107,   108,     0,     0,
       0,     0,   103,   104,   105,   106,   113,     0,     0,     0,
       0,     0,     0,     0,   101,   158,   161,     0,     0,     0,
       0,     0,   710,   719,   610,   628,   611,   612,   773,   659,
     720,   614,   717,   669,   660,   616,   618,   775,   680,   619,
     620,   698,   609,   681,     0,     0,   762,   763,   607,   755,
     615,   747,   753,   744,   646,   765,   769,   770,   766,   768,
     771,   774,     0,     0,     0,     0,   223,     0,     0,     0,
       0,     0,     0,     0,     0,   601,     0,     0,     0,   602,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   610,   612,   616,   619,   609,   391,   401,
     427,     0,   428,     0,   453,     0,     0,   366,     0,     0,
     369,     0,     0,   482,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   148,   145,   156,   157,     0,     0,
       0,     0,     3,     1,     5,     7,     0,     0,    13,    10,
      15,    16,     0,   180,   179,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   201,   220,   216,   222,   217,   219,
     218,   225,   226,     0,     0,     0,     0,   356,     0,     0,
     354,     0,   306,     0,   355,   348,   353,   352,   351,   350,
     349,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   344,
     343,   340,     0,   364,   368,     0,     0,     0,   378,   410,
     381,   380,   392,     0,   407,     0,     0,   600,    76,    61,
      62,   139,   140,     0,     0,   160,     0,   159,     0,    67,
      68,     0,   164,   162,     0,   163,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   569,   570,   571,   110,
     109,     0,    66,   117,   114,     0,   116,   115,   112,   111,
       0,     0,     0,   102,     0,     0,   538,     0,     0,     0,
     534,     0,     0,     0,   548,     0,     0,     0,     0,   203,
     204,     0,     0,     0,   141,     0,   171,     0,   562,     0,
       0,    85,     0,     0,     0,    77,   238,   239,     0,   224,
       0,     0,   539,     0,     0,     0,     0,     0,   286,     0,
       0,   537,     0,     0,   556,     0,     0,     0,     0,   542,
       0,     0,     0,     0,   429,   454,   453,   450,     0,     0,
     484,   483,   365,   547,     0,   481,     0,   582,   583,   533,
       0,     0,     0,     0,     0,     0,   588,     0,     0,   154,
       0,     0,     0,   241,   258,     0,    19,     0,    21,   183,
       0,     0,     0,     0,     0,   202,   259,     0,     0,     0,
       0,     0,     0,     0,     0,   298,   300,   304,   310,   309,
     308,     0,   305,   302,   303,     0,   319,   318,   316,   322,
     323,   324,   321,   326,   327,   330,   329,     0,     0,     0,
       0,   361,     0,   373,   374,     0,   411,   408,   435,     0,
     561,   433,     0,     0,     0,     0,    65,     0,     0,    40,
      42,    43,    44,    45,    47,    48,    49,    41,    46,    36,
      37,     0,     0,    93,     0,    89,    91,    92,    96,    99,
       0,     0,     0,    35,    75,     0,     0,     0,     0,     0,
       0,     0,   871,   876,     0,     0,   872,   906,   859,   861,
     862,   863,   865,   867,   866,   864,   868,     0,     0,     0,
     118,     0,     0,   121,     0,     0,   502,   492,   535,   536,
       0,     0,   552,     0,   549,   493,     0,   606,     0,     0,
     205,   206,     0,   211,   173,     0,     0,   142,     0,     0,
       0,     0,     0,     0,    78,     0,     0,     0,     0,     0,
       0,   541,   540,   503,     0,   555,     0,     0,     0,     0,
       0,   501,     0,     0,   357,     0,     0,     0,     0,   545,
       0,   543,   497,     0,     0,   453,   451,     0,   442,     0,
     431,   432,     0,     8,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   710,     0,
       0,     0,     0,     0,     0,    17,     0,   181,   212,     0,
     270,   266,   268,     0,   260,   261,     0,   720,   613,     0,
     621,   509,   510,   516,   517,   519,   563,   564,   520,   523,
       0,   228,     0,     0,     0,     0,     0,     0,     0,   307,
       0,     0,     0,     0,   837,   313,   810,   814,   816,   818,
     820,   823,   830,   831,   839,   332,   334,   336,   507,   338,
     362,   412,     0,   409,   434,    73,    74,    71,    72,   166,
       0,   165,     0,     0,    38,     0,     0,    94,    95,    97,
       0,    98,    63,    64,    69,    70,    60,   877,     0,   880,
     907,     0,   870,   869,   874,   873,   905,     0,     0,   882,
       0,   878,   881,   860,     0,     0,     0,     0,     0,     0,
     119,   125,     0,     0,     0,     0,     0,     0,   122,     0,
       0,     0,     0,     0,   556,     0,     0,   494,     0,     0,
     207,     0,     0,     0,     0,   252,     0,   249,   254,   210,
     174,   143,   172,     0,   175,     0,     0,    87,    81,    84,
      83,     0,    79,     0,   243,     0,     0,     0,     0,   504,
     153,     0,   284,   288,     0,     0,     0,   292,     0,   359,
     358,     0,     0,     0,   498,   285,   454,     0,   443,     0,
     477,   474,     0,   478,   479,     0,   480,   473,     0,   448,
     476,   475,     0,     0,     0,   575,   576,   572,     0,     0,
     580,   581,   577,   586,   584,     0,     0,     0,   590,   151,
     150,     0,   147,   146,   155,     0,   591,   592,     0,     0,
     267,   279,     0,   280,     0,   271,   272,   273,   274,     0,
     263,     0,   227,     0,     0,     0,     0,   513,   515,   514,
     511,   236,   237,   230,     0,   232,   229,     0,     0,     0,
       0,     0,   821,   834,     0,   312,   314,     0,   853,     0,
       0,     0,     0,     0,     0,   809,   811,   812,   848,   849,
     850,   852,   851,     0,     0,   825,   824,     0,   828,   832,
     846,   844,   843,   836,   840,   508,   436,     0,   168,   167,
     170,     0,    39,    90,   100,   894,   875,     0,   899,     0,
     899,   888,   883,   120,   126,   128,   127,     0,     0,     0,
     123,     0,    14,   495,     0,   553,   554,   557,   550,   551,
     247,     0,     0,     0,   209,   250,   253,     0,   144,     0,
      86,     0,    80,   240,   245,   244,     0,   505,     0,   287,
     289,     0,     0,     0,   293,   360,   499,     0,   546,   544,
     453,     0,     0,   485,   453,     0,   449,     9,     0,     0,
       0,     0,     0,   589,     0,     0,   149,   598,     0,   593,
       0,   242,   283,   281,   282,   275,   276,   277,   269,     0,
     264,   262,     0,     0,   521,     0,   518,   568,   512,   234,
     231,     0,   233,   838,   829,   835,     0,     0,   908,   909,
     919,   918,   917,     0,     0,     0,     0,   910,   815,   916,
       0,   813,   817,     0,     0,   822,   826,     0,   847,   842,
     845,   841,   176,     0,   895,     0,     0,   893,   900,   901,
     897,     0,   892,     0,   890,     0,   884,   885,     0,     0,
       0,   124,     0,   496,   248,   256,   257,   251,   208,     0,
       0,    82,   246,   506,     0,     0,     0,     0,   500,     0,
     453,     0,     0,   453,   573,   574,   578,   579,   585,   587,
     152,     0,     0,   594,   605,   278,   265,     0,   565,     0,
       0,   235,   833,   920,     0,     0,   912,     0,   858,   857,
     856,   855,   854,   819,     0,   911,   169,   904,   903,   902,
       0,   896,   889,   887,     0,   879,     0,   129,   131,     0,
       0,     0,     0,     0,     0,     0,   296,    88,     0,   294,
       0,   290,   463,   457,   452,     0,   453,   444,     0,     0,
     599,   566,   522,     0,   914,   913,     0,     0,   898,   891,
     886,     0,     0,     0,     0,     0,     0,   130,     0,     0,
       0,   471,   465,     0,   464,   466,   472,   469,   459,     0,
     458,   460,   470,   446,     0,   445,     0,   567,   915,   827,
     132,   133,     0,     0,     0,     0,   255,     0,   291,   456,
     467,   468,   455,   461,   462,   447,     0,     0,   134,   135,
       0,     0,     0,   295,     0,   595,     0,     0,     0,     0,
       0,   137,     0,     0,     0,   136,     0,     0,   596,     0,
       0,     0,     0,     0,   597,     0,     0,     0,     0,   138
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1294, -1294,   871, -1294,   870,   872, -1294,   873, -1294,   564,
     572,  -516, -1294,   468,  -265, -1294, -1294, -1294, -1294, -1294,
   -1294, -1294, -1294, -1294, -1294, -1294, -1294, -1294, -1294,  -889,
   -1294, -1294, -1294, -1294,    78,   283,   726, -1294, -1294,   708,
   -1294,    50,  -844, -1294,  -349,  -373, -1294, -1294,  -578, -1294,
    -867, -1294, -1294,   -41, -1294, -1294, -1294, -1294, -1294,   274,
     750, -1294, -1294, -1294,   235,   672, -1293,   880,   -96, -1294,
    -532,  -399, -1294, -1294, -1294, -1294,   239, -1294, -1294,   842,
   -1294, -1294, -1294, -1294, -1294,   161,  -522,  -665, -1294, -1294,
   -1294,    23, -1294, -1294,  -145,    47,   -35, -1294, -1294, -1294,
     -48, -1294, -1294,   176,   -40, -1294, -1294,   -38, -1150, -1294,
     645,    30, -1294, -1294,    26, -1294, -1294,   591,   588, -1294,
    -514, -1294, -1294,  -568,    85,  -566,    80,    82, -1294, -1294,
   -1294, -1294, -1294,   840, -1294, -1294, -1294, -1294,  -771,  -305,
   -1046, -1294,  -110, -1294, -1294, -1294, -1294, -1294, -1294, -1294,
     -44, -1145, -1294, -1294,   301,     3, -1294,  -746, -1294, -1294,
   -1294, -1294, -1294, -1294, -1294,   540, -1294,  -907, -1294,    18,
   -1294,   434,  -715, -1294, -1294, -1294, -1294, -1294,  -359,  -352,
   -1077, -1011, -1294, -1294, -1294, -1294, -1294, -1294, -1294, -1294,
   -1294, -1294,   368,  -651,  -747,    93,  -767, -1294,  -780,  -719,
   -1294, -1294, -1294, -1294, -1294, -1294, -1294,   758,   761,  -392,
     282,   132, -1294, -1294, -1294, -1294, -1294, -1294, -1294, -1294,
   -1294, -1294, -1294, -1294, -1294, -1294,     5, -1294, -1294,    -7,
   -1294,  -348,  -111,   -16, -1294, -1294,  -963, -1294, -1294, -1294,
     -52,   -61,  -200,   172, -1294, -1294, -1294, -1294, -1294, -1294,
   -1294, -1294, -1294, -1294, -1294, -1294, -1294,   -51, -1294, -1294,
   -1294,  -192,   169,   314, -1294, -1294, -1294, -1294, -1294,   123,
   -1294, -1294, -1218, -1294, -1294, -1294,  -690, -1294,   -76, -1294,
    -203, -1294, -1294, -1294, -1294, -1171, -1294,   -34, -1294
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   819,   820,   821,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,  1097,
     684,   263,   264,   825,   826,   827,  1159,   265,   403,   404,
     266,  1060,   860,   267,  1457,  1458,   268,   269,   459,   270,
     515,   738,   949,  1160,   271,   272,   273,   274,   275,   405,
     406,   622,   625,   675,   676,  1136,  1021,   276,   277,   534,
     278,   279,   280,   544,   457,   882,   883,   281,   545,   282,
     547,   283,   284,   285,   551,   552,  1085,   763,   286,   686,
     742,   687,   672,  1086,  1087,  1088,   743,   548,   549,   964,
     965,  1330,   550,   961,   962,  1175,  1176,  1177,  1178,   287,
     697,   698,   288,  1116,  1117,   289,   290,   291,   292,   771,
     293,  1205,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   571,   572,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   598,   599,   324,   325,   326,   327,
     328,   329,   330,   331,   332,   799,   333,   334,   335,  1138,
     716,   717,   718,  1474,  1509,  1510,  1503,  1504,  1511,  1505,
    1139,  1140,   336,   337,  1141,   338,   339,   340,   341,   342,
     343,   344,  1007,   764,   971,  1190,   972,  1335,   973,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   703,
    1073,   355,   356,   357,   358,   975,   976,   977,   978,   359,
     360,   361,   362,   363,   364,   735,   736,   365,  1166,  1167,
    1318,  1098,   468,   366,   367,   368,   995,  1215,  1216,   996,
     997,   998,   999,  1000,  1225,  1365,  1366,  1001,  1228,  1002,
    1346,  1003,  1004,  1233,  1234,  1371,  1369,  1217,  1218,  1219,
    1220,  1441,   642,   848,   849,   850,   851,   852,   853,  1051,
    1385,  1386,  1052,  1384,  1453,   854,  1250,  1381,  1377,  1378,
    1379,   855,   856,  1221,  1229,  1356,  1222,  1352,  1206
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       452,   927,   750,   593,   993,   496,  1102,   493,   778,  1008,
    1008,   779,   780,   781,   782,   748,   469,   500,  1257,  1068,
    1317,   608,  1137,   898,   488,  1423,  1326,  1327,  1201,   994,
     837,   762,     4,   838,  1387,   879,  1460,   899,   805,   974,
    1005,  1006,   767,   759,   768,   769,  1353,   770,   910,   772,
     482,   720,   489,   502,   668,  1026,  1367,   773,   774,   758,
    1106,  1306,   858,   945,   532,   607,   490,  1067,   974,   974,
     983,  1501,  1434,  1472,   658,  1130,   839,   532,  1501,   532,
     953,   758,  1130,   759,  1164,   907,   607,   605,   494,  1161,
     907,   577,   986,   407,   659,   928,  1197,   984,   606,   988,
     469,   871,   498,   974,   619,   897,   727,   728,   499,   730,
     731,   732,   733,   681,   685,    74,   758,   932,   578,   739,
     740,   454,  1054,   758,  1207,   934,   455,    85,  1055,   658,
    1081,   579,   760,   749,  1019,   461,   620,  1082,  1091,  1061,
     583,  1461,   954,   755,   756,   533,  1056,  1435,   410,   659,
    1020,   682,    99,  1446,   584,  1239,   990,  1057,   957,   991,
    1473,   929,   673,   908,   462,   580,   974,   909,   924,  1128,
    1162,   456,  1207,   759,  1078,  1425,   933,  1029,   872,   118,
     411,  1133,  1058,  1134,   453,  1130,  1131,   938,  1133,   946,
    1134,  1502,   761,     4,   880,  1208,   683,   761,  1530,  1130,
    1131,   594,  1185,   859,   798,  1354,  1355,   798,   859,   721,
    1127,   677,  1282,  1454,   660,  1392,  1253,   680,   677,   761,
     993,   993,  1137,   761,  1462,  1306,   840,  1079,   674,  1022,
    1023,  1137,   881,  1090,  1107,  1129,   503,   761,  1490,   841,
    1345,   842,   987,  1208,  1545,   994,   994,   935,   936,   873,
     974,  1115,   843,   844,   845,   886,   846,   989,   847,   761,
     918,  1558,   937,   992,  1293,  1172,   574,   630,   553,  1564,
     631,   124,   600,  1132,   635,   602,    74,  1480,   574,  1209,
    1210,  1348,  1211,   575,  1174,   834,   920,  1132,    85,  1212,
    1012,  1133,  1406,  1134,  1247,   575,   654,   595,   596,  1213,
     489,  1012,   632,   489,  1130,  1133,   576,  1134,  1059,   939,
     940,  1214,   655,    99,   657,  1507,  1429,   990,   458,  1349,
     991,   677,  1198,  1375,   941,   104,   874,  1209,  1210,   633,
    1211,  1450,   887,   574,   460,   677,   894,   919,   663,   104,
     118,   116,  1459,   476,   581,  1536,  1278,  1213,  1061,   526,
     575,  1553,  1249,   582,   960,   116,   693,  1407,   616,  1214,
     618,   981,  1135,   921,   679,   626,   527,  1013,  1292,   469,
     690,  1538,  1130,  1486,   974,   643,  1301,   700,  1014,   702,
     143,   705,   645,  1507,   708,   574,   592,  1376,   463,   634,
    1438,   469,   535,  1430,   143,  1137,   974,  1439,   536,   719,
     477,   464,   575,   537,  1187,   724,  1081,  1440,  1451,   118,
    1133,   538,  1134,  1082,  1020,  1203,  1391,  1421,  1459,   666,
     609,  1508,  1537,   539,   741,  1028,  1130,  1131,  1554,  1048,
    1083,  1031,   993,  1247,   610,  1188,  1334,  1171,   118,   748,
     677,   993,  1015,  1130,  1131,  1459,  1049,   688,  1172,   759,
    1248,   469,   993,  1189,   695,   696,   699,   994,  1173,  1016,
     704,  1506,  1512,   470,   974,   711,   994,  1174,   478,   479,
    1422,  1084,   374,  1065,   822,   699,   471,   994,  1133,  1072,
    1134,  1075,  1066,  1032,  1033,   793,   794,  1050,  1036,  1533,
     378,  1249,   379,  1506,   472,  1438,   792,   737,  1104,  1512,
     380,   795,  1439,  1238,  1555,   744,  1556,  1110,   677,  1112,
    1113,  1467,  1440,  1017,  1132,   823,  1048,  1070,   540,   514,
     824,   541,  1569,  1230,  1231,  1125,  1122,   505,  1123,   506,
    1018,  1132,  1133,  1049,  1134,   542,  1145,  1146,  1147,  1240,
    1150,  1151,  1152,  1153,  1154,  1155,  1232,  1157,  1158,  1133,
     613,  1134,  1042,   611,  1024,  1241,  1143,  1081,  1144,  1044,
     960,   543,   677,  1043,  1082,   614,   104,   612,  1024,   890,
    1045,   876,   893,  1350,   408,   473,   475,   409,   474,   677,
    1351,   888,   116,   104,  1193,  1409,  1195,  1196,   511,  1412,
     639,   640,   993,   512,  1037,  1038,  1039,   386,   904,   116,
    1040,   796,   491,  1305,   796,   807,   495,   796,   808,   829,
     915,   916,   828,  1236,   830,   501,   923,   994,   823,   601,
    1411,   143,   504,   824,   604,   636,   637,   638,   508,   387,
     509,  1244,  1034,  1035,   862,   863,   864,   597,   143,   603,
     648,   649,   950,  1148,   507,  1149,  1360,   615,   513,   617,
    1062,  1063,  1323,  1324,   510,   878,   514,   884,   389,   776,
     777,   783,   784,   519,   469,   785,   786,   469,   809,   810,
     811,   812,   813,   814,   815,   816,   817,   818,   516,  1270,
    1481,   517,  1482,   518,  1274,  1447,  1448,   520,   593,   521,
     523,   530,   554,   555,   573,  1475,  1279,   585,  1478,   925,
     531,   587,   597,   607,   586,   588,  1284,  1285,   974,  1373,
     974,   621,  1521,   374,   624,  1290,   651,   392,   393,   394,
     395,  1499,   396,   397,   652,   399,   400,   627,   628,   644,
     646,   401,   641,   647,   667,   958,  1517,   650,   656,   669,
     670,   671,   979,   677,   689,   694,   701,   706,  1280,   974,
     707,   409,   435,   712,   714,   715,   722,   723,   467,   556,
     474,  1514,   481,   725,   974,   726,   729,   557,   558,  1320,
     559,   979,   979,   979,   979,   734,   747,   751,   560,   752,
     960,  1433,   561,   753,   562,   754,  1436,  1437,   757,   563,
     775,   788,   787,   789,   790,  1339,   800,   803,  1340,   804,
    1342,   806,   831,   832,   835,   564,   979,   836,   861,   857,
     865,   866,   373,   867,   870,   868,   885,  1118,   374,   869,
     877,   889,  1041,   891,  1322,   892,   375,   895,   376,   565,
     566,   567,   568,   569,   570,   896,   378,   900,   379,   901,
     913,   902,   905,   906,   911,   912,   380,   942,   944,   914,
     381,   917,   930,   931,   943,  1074,   947,  1074,   951,   952,
     963,   955,   959,   966,   980,   982,  1484,  1485,   985,   979,
    1011,  1025,  1394,   824,  1010,  1030,   758,  1046,  1398,  1064,
    1047,  1071,   382,   383,   956,  1069,  1077,  1402,   673,  1080,
    1093,  1094,  1096,  1095,  1200,  1099,  1100,  1101,  1103,  1105,
    1108,  1109,   704,  1111,   704,  1114,  1115,  1119,  1121,  1414,
    1415,  1416,  1417,  1418,  1126,  1419,  1420,  1120,  1518,  1142,
    1124,  1156,  1169,  1168,  1237,   632,  1165,  1179,  1181,  1163,
    1183,  1184,  1186,  1401,  1194,  1199,  1204,  1235,   386,     4,
    1246,  1223,  1431,  1251,  1224,  1245,   859,  1180,  1258,  1255,
     553,  1259,  1227,   979,  1256,  1262,  1267,  1261,  1271,  1265,
    1272,  1273,  1277,  1266,  1191,  1281,  1192,  1268,  1269,  1286,
     387,  1298,  1295,   369,   370,  1264,   371,   372,  1299,   373,
    1303,  1426,  1300,  1308,  1315,   374,  1307,  1309,  1314,  1310,
    1312,  1336,  1311,   375,  1172,   376,   377,  1329,  1341,   389,
    1466,  1337,  1338,   378,  1343,   379,  1469,  1363,  1471,  1344,
    1368,  1370,  1288,   380,  1347,  1372,  1374,   381,  1357,  1380,
    1383,  1364,  1048,  1388,  1390,  1297,  1393,  1399,  1400,  1403,
    1405,   390,  1408,  1427,  1444,  1424,  1452,  1456,  1432,  1464,
    1428,  1465,  1445,  1455,  1468,  1479,  1483,  1488,  1491,   382,
     383,   384,  1492,  1494,  1477,  1495,  1489,   391,   392,   393,
     394,   395,  1498,   396,   397,   398,   399,   400,  1275,  1500,
    1513,  1515,   401,   402,  1463,  1519,  1527,   979,  1524,  1529,
    1532,  1535,  1542,  1544,  1525,  1020,  1557,   688,  1562,  1546,
    1522,  1559,  1565,  1566,   745,   699,   385,  1540,  1561,   979,
     833,  1528,   746,  1547,  1243,   386,  1027,  1550,   522,   629,
     524,   653,   525,  1552,  1568,  1497,   528,  1260,  1520,  1304,
    1316,  1092,  1089,  1539,   529,   546,  1283,  1182,  1543,   623,
    1397,   678,  1276,  1331,  1321,  1170,   713,   387,  1325,  1328,
     737,  1289,  1294,   766,   591,   765,   802,  1302,  1551,   489,
     926,  1534,  1531,   744,  1254,  1076,   388,  1242,  1009,  1319,
    1358,  1313,  1362,  1443,  1202,  1361,   389,   979,  1442,   661,
    1226,  1053,   662,  1252,  1382,  1449,     0,     0,     0,  1359,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   390,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   391,   392,   393,   394,   395,     0,
     396,   397,   398,   399,   400,     0,     0,     0,     0,   401,
     402,     0,  1389,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1395,  1396,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1404,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1410,     0,     0,     0,  1413,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1487,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1470,     0,     0,     0,     0,  1476,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   489,     0,     0,     0,
       0,   979,     0,   979,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1493,     0,     0,  1496,     0,     0,
       0,     0,   979,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1516,     0,     0,     0,   979,     0,     0,
       0,     0,     0,     0,     0,     0,   979,     0,  1523,     0,
       0,     0,  1526,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1541,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1548,     0,  1549,     0,
       0,     0,     0,     0,     0,     0,     1,     0,     0,     0,
       0,  1560,     0,     2,     3,  1563,     4,     0,     0,     0,
    1567,     5,     6,     0,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,     0,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,     0,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,     0,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,     0,    72,    73,     0,     0,     0,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
       0,    85,     0,    86,    87,    88,    89,     0,    90,     0,
       0,     0,    91,    92,    93,    94,    95,     0,     0,     0,
       0,     0,     0,    96,    97,    98,    99,   100,   101,   102,
       0,     0,     0,   103,   104,   105,   106,   107,     0,     0,
       0,     0,   108,   109,   110,   111,   112,   113,   114,   115,
     116,     0,   117,   118,     0,     0,   119,   120,   121,     0,
       0,     0,   122,     0,   123,   124,   125,     0,   126,   127,
     128,     0,   129,     0,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,     0,     0,   141,   142,   143,
       0,   144,   145,     0,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,     0,   188,   189,   190,
       0,   191,   192,   193,   194,   195,   196,     0,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,     1,
       0,     0,     0,     0,     0,     0,     2,     3,     0,     4,
       0,     0,     0,     0,   412,   413,     0,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,   422,    22,    23,    24,    25,     0,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,     0,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,     0,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,     0,    72,    73,     0,
       0,     0,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,     0,    85,     0,    86,    87,    88,    89,
       0,    90,     0,     0,     0,    91,    92,    93,    94,    95,
       0,     0,     0,     0,     0,     0,    96,    97,    98,    99,
     100,   101,   102,     0,     0,     0,   103,   104,   105,   106,
     107,     0,     0,     0,     0,   108,   109,   110,   111,   112,
     113,   114,   115,   116,     0,   117,   118,     0,     0,   119,
     120,   121,     0,     0,     0,   122,   492,   123,   124,   125,
       0,   126,   127,   128,     0,   129,     0,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,   143,     0,   438,   145,     0,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,     0,
     188,   189,   190,     0,   191,   192,   193,   194,   195,   196,
       0,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     4,     0,     0,     0,     0,   412,   413,     0,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,   422,    22,    23,    24,    25,     0,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,     0,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,     0,    63,    64,
      65,    66,    67,    68,    69,    70,    71,     0,     0,    72,
      73,     0,     0,     0,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,     0,    85,     0,    86,    87,
      88,    89,     0,    90,     0,     0,     0,    91,    92,    93,
      94,    95,     0,     0,     0,     0,     0,     0,    96,    97,
      98,    99,   100,   101,   102,     0,     0,     0,   103,   104,
     105,   106,   107,     0,     0,     0,     0,   108,   109,   110,
     111,   112,   113,   114,   115,   116,     0,   117,   118,     0,
       0,   119,   120,   121,     0,   791,     0,   122,     0,   123,
     124,   125,     0,   126,   127,   128,     0,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,   143,     0,   438,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,     0,   188,   189,   190,     0,   191,   192,   193,   194,
     195,   196,     0,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     0,     4,     0,     0,     0,     0,   412,   413,
       0,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,   422,    22,    23,    24,    25,
       0,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,     0,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,     0,
      63,    64,    65,    66,    67,    68,    69,    70,    71,     0,
       0,    72,    73,     0,     0,     0,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,     0,    85,     0,
      86,    87,    88,    89,     0,    90,     0,     0,     0,    91,
      92,    93,    94,    95,     0,     0,     0,     0,     0,     0,
      96,    97,    98,    99,   100,   101,   102,     0,     0,     0,
     103,   104,   105,   106,   107,     0,     0,     0,     0,   108,
     109,   110,   111,   112,   113,   114,   115,   116,     0,   117,
     118,     0,     0,   119,   120,   121,     0,     0,     0,   122,
     797,   123,   124,   125,     0,   126,   127,   128,     0,   129,
       0,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,     0,     0,   141,   142,   143,     0,   438,   145,
       0,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,     0,   188,   189,   190,     0,   191,   192,
     193,   194,   195,   196,     0,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     4,     0,     0,     0,     0,
     412,   413,     0,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,   422,    22,    23,
      24,    25,     0,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,     0,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,     0,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,     0,    72,    73,     0,     0,     0,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,     0,
      85,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,    91,    92,    93,    94,    95,     0,     0,     0,     0,
       0,     0,    96,    97,    98,    99,   100,   101,   102,     0,
       0,     0,   103,   104,   105,   106,   107,     0,     0,     0,
       0,   108,   109,   110,   111,   112,   113,   114,   115,   116,
       0,   117,   118,     0,     0,   119,   120,   121,     0,     0,
       0,   122,   801,   123,   124,   125,     0,   126,   127,   128,
       0,   129,     0,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,   143,     0,
     438,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,     0,   188,   189,   190,     0,
     191,   192,   193,   194,   195,   196,     0,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,     1,     0,     0,
       0,     0,     0,     0,     2,     3,     0,     4,     0,     0,
       0,     0,   412,   413,     0,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,   422,
      22,    23,    24,    25,     0,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
       0,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,     0,    63,    64,    65,    66,    67,    68,
      69,    70,    71,     0,     0,    72,    73,     0,     0,     0,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,     0,    85,     0,    86,    87,    88,    89,     0,    90,
       0,     0,     0,    91,    92,    93,    94,    95,     0,     0,
       0,     0,     0,     0,    96,    97,    98,    99,   100,   101,
     102,     0,     0,     0,   103,   104,   105,   106,   107,     0,
       0,     0,     0,   108,   109,   110,   111,   112,   113,   114,
     115,   116,     0,   117,   118,     0,     0,   119,   120,   121,
       0,   875,     0,   122,     0,   123,   124,   125,     0,   126,
     127,   128,     0,   129,     0,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,     0,     0,   141,   142,
     143,     0,   438,   145,     0,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,     0,   188,   189,
     190,     0,   191,   192,   193,   194,   195,   196,     0,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,     1,
       0,     0,     0,     0,     0,     0,     2,     3,     0,     4,
       0,     0,     0,     0,   412,   413,     0,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,   422,    22,    23,    24,    25,     0,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,     0,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,     0,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,     0,    72,    73,     0,
       0,     0,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,     0,    85,     0,    86,    87,    88,    89,
       0,    90,     0,     0,     0,    91,    92,    93,    94,    95,
       0,     0,     0,     0,     0,     0,    96,    97,    98,    99,
     100,   101,   102,     0,     0,     0,   103,   104,   105,   106,
     107,     0,     0,     0,     0,   108,   109,   110,   111,   112,
     113,   114,   115,   116,     0,   117,   118,     0,     0,   119,
     120,   121,     0,   903,     0,   122,     0,   123,   124,   125,
       0,   126,   127,   128,     0,   129,     0,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,   143,     0,   438,   145,     0,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,     0,
     188,   189,   190,     0,   191,   192,   193,   194,   195,   196,
       0,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     4,     0,     0,     0,     0,   412,   413,     0,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,   422,    22,    23,    24,    25,     0,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,     0,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,     0,    63,    64,
      65,    66,    67,    68,    69,    70,    71,     0,     0,    72,
      73,     0,     0,     0,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,     0,    85,     0,    86,    87,
      88,    89,     0,    90,     0,     0,     0,    91,    92,    93,
      94,    95,     0,     0,     0,     0,     0,     0,    96,    97,
      98,    99,   100,   101,   102,     0,     0,     0,   103,   104,
     105,   106,   107,     0,     0,     0,     0,   108,   109,   110,
     111,   112,   113,   114,   115,   116,     0,   117,   118,     0,
       0,   119,   120,   121,     0,   922,     0,   122,     0,   123,
     124,   125,     0,   126,   127,   128,     0,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,   143,     0,   438,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,     0,   188,   189,   190,     0,   191,   192,   193,   194,
     195,   196,     0,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     0,     4,     0,     0,     0,     0,   412,   413,
       0,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,   422,    22,    23,    24,    25,
       0,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,     0,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,     0,
      63,    64,    65,    66,    67,    68,    69,    70,    71,     0,
       0,    72,    73,     0,     0,     0,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,     0,    85,     0,
      86,    87,    88,    89,     0,    90,     0,     0,     0,    91,
      92,    93,    94,    95,     0,     0,     0,     0,     0,     0,
      96,    97,    98,    99,   100,   101,   102,     0,     0,     0,
     103,   104,   105,   106,   107,     0,     0,     0,     0,   108,
     109,   110,   111,   112,   113,   114,   115,   116,     0,   117,
     118,     0,     0,   119,   120,   121,     0,  1263,     0,   122,
       0,   123,   124,   125,     0,   126,   127,   128,     0,   129,
       0,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,     0,     0,   141,   142,   143,     0,   438,   145,
       0,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,     0,   188,   189,   190,     0,   191,   192,
     193,   194,   195,   196,     0,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     4,     0,     0,     0,     0,
     412,   413,     0,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,   422,    22,    23,
      24,    25,     0,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,     0,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,     0,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,     0,    72,    73,     0,     0,     0,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,     0,
      85,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,    91,    92,    93,    94,    95,     0,     0,     0,     0,
       0,     0,    96,    97,    98,    99,   100,   101,   102,     0,
       0,     0,   103,   104,   105,   106,   107,     0,     0,     0,
       0,   108,   109,   110,   111,   112,   113,   114,   115,   116,
       0,   117,   118,     0,     0,   119,   120,   121,     0,  1287,
       0,   122,     0,   123,   124,   125,     0,   126,   127,   128,
       0,   129,     0,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,   143,     0,
     438,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,     0,   188,   189,   190,     0,
     191,   192,   193,   194,   195,   196,     0,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,     1,     0,     0,
       0,     0,     0,     0,     2,     3,     0,     4,     0,     0,
       0,     0,   412,   413,     0,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,   422,
      22,    23,    24,    25,     0,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
       0,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,     0,    63,    64,    65,    66,    67,    68,
      69,    70,    71,     0,     0,    72,    73,     0,     0,     0,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,     0,    85,     0,    86,    87,    88,    89,     0,    90,
       0,     0,     0,    91,    92,    93,    94,    95,     0,     0,
       0,     0,     0,     0,    96,    97,    98,    99,   100,   101,
     102,     0,     0,     0,   103,   104,   105,   106,   107,     0,
       0,     0,     0,   108,   109,   110,   111,   112,   113,   114,
     115,   116,     0,   117,   118,     0,     0,   119,   120,   121,
       0,  1296,     0,   122,     0,   123,   124,   125,     0,   126,
     127,   128,     0,   129,     0,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,     0,     0,   141,   142,
     143,     0,   438,   145,     0,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,     0,   188,   189,
     190,     0,   191,   192,   193,   194,   195,   196,     0,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,     1,
       0,     0,     0,     0,     0,     0,     2,     3,     0,     4,
       0,     0,     0,     0,     5,     6,     0,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,     0,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,     0,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,     0,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,     0,    72,    73,     0,
       0,     0,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,     0,    85,     0,    86,    87,    88,    89,
       0,    90,     0,     0,     0,    91,    92,    93,    94,    95,
       0,     0,     0,     0,     0,     0,    96,    97,    98,    99,
     100,   101,   102,     0,     0,     0,   103,   104,   105,   106,
     107,     0,     0,     0,     0,   108,   109,   110,   111,   112,
     113,   114,   115,   116,     0,   117,   118,     0,     0,   119,
     120,   121,     0,     0,     0,   122,     0,   123,   124,   125,
       0,   126,   127,   128,     0,   129,     0,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,   143,     0,   144,   145,     0,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,     0,
     188,   189,   190,     0,   191,   192,   193,   194,   195,   196,
       0,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     4,     0,     0,     0,     0,     5,     6,     0,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,     0,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,     0,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,     0,    63,    64,
      65,    66,    67,    68,    69,    70,    71,     0,     0,    72,
      73,     0,     0,     0,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,     0,    85,     0,    86,    87,
      88,    89,     0,    90,     0,     0,     0,    91,    92,    93,
      94,    95,     0,     0,     0,     0,     0,     0,    96,    97,
      98,    99,   100,   101,   102,     0,     0,     0,   103,   104,
     105,   106,   107,     0,     0,     0,     0,   108,   109,   110,
     111,   112,   113,   114,   115,   116,     0,   117,   118,     0,
       0,   119,   120,   121,     0,     0,     0,   122,     0,   123,
     124,   125,     0,   126,   127,   128,     0,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,   143,     0,   438,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,     0,   188,   189,   190,     0,   191,   192,   193,   194,
     195,   196,     0,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     0,     4,     0,     0,     0,     0,   412,   413,
       0,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,   422,    22,    23,    24,    25,
       0,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,     0,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,     0,
      63,    64,    65,    66,    67,    68,    69,    70,    71,     0,
       0,    72,    73,     0,     0,     0,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,     0,    85,     0,
      86,    87,    88,    89,     0,    90,     0,     0,     0,    91,
      92,    93,    94,    95,     0,     0,     0,     0,     0,     0,
      96,    97,    98,    99,   100,   101,   102,     0,     0,     0,
     103,   104,   105,   106,   107,     0,     0,     0,     0,   108,
     109,   110,   111,   112,   113,   114,   115,   116,     0,   117,
     118,     0,     0,   119,   120,   121,     0,     0,     0,   122,
       0,   123,   124,   125,     0,   126,   127,   128,     0,   129,
       0,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,     0,     0,   141,   142,   143,     0,   438,   145,
       0,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,     0,   188,   189,   190,     0,   191,   192,
     193,   194,   195,   196,     0,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     4,     0,     0,     0,     0,
     412,   413,     0,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,   418,   419,    19,   421,   422,    22,   423,
      24,    25,     0,    26,    27,    28,    29,   424,    31,    32,
      33,    34,    35,    36,   427,    38,    39,   428,     0,    41,
      42,    43,   430,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,     0,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,     0,    72,    73,     0,     0,     0,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,     0,
      85,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,   433,    92,    93,    94,    95,     0,     0,     0,     0,
       0,     0,    96,    97,    98,    99,   100,   101,   102,     0,
       0,     0,   103,   104,   589,   106,   107,     0,     0,     0,
       0,   108,   109,   110,   111,   112,   113,   114,   115,   116,
       0,   590,   118,     0,     0,   119,   120,   121,     0,     0,
       0,   122,     0,   123,   124,   125,     0,   126,   127,   128,
       0,   129,     0,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,   143,     0,
     438,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     439,   154,   441,   156,   442,   443,   159,   160,   161,   162,
     163,   164,   444,   166,   445,   446,   447,   448,   171,   172,
     449,   450,   175,   451,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,     0,   188,   189,   190,     0,
     191,   192,   193,   194,   195,   196,     0,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,     1,     0,     0,
       0,     0,     0,     0,     2,     3,     0,     4,     0,     0,
       0,     0,   412,   413,     0,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,   418,   419,    19,   421,   422,
      22,   423,    24,    25,     0,    26,    27,    28,    29,   424,
      31,    32,    33,    34,    35,    36,   427,    38,    39,   428,
       0,    41,    42,    43,   430,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,     0,    63,    64,    65,    66,    67,    68,
      69,    70,    71,     0,     0,    72,    73,     0,     0,     0,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,     0,    85,     0,    86,    87,    88,    89,     0,    90,
       0,     0,     0,   433,    92,    93,    94,    95,     0,     0,
       0,     0,     0,     0,    96,    97,    98,    99,   100,   101,
     102,     0,     0,     0,   103,   104,   105,   106,   107,     0,
       0,     0,     0,   108,   109,   110,   111,   112,   113,   114,
     115,   116,     0,   117,   118,     0,     0,   119,   120,   121,
       0,     0,     0,   122,     0,   123,   124,   125,     0,   126,
     127,   128,     0,   129,     0,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,     0,     0,   141,   142,
     143,     0,   438,   145,     0,   146,   147,   148,   149,   150,
     151,   152,   439,   154,   441,   156,   442,   443,   159,   160,
     161,   162,   163,   164,   444,   166,   445,   446,   447,   448,
     171,   172,   449,   450,   175,   451,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,     0,   188,   189,
     190,     0,   191,   192,   193,   194,   195,   196,     0,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,     1,
       0,     0,     0,     0,     0,     0,     2,     3,     0,     4,
       0,     0,     0,     0,   948,   413,     0,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,   422,    22,    23,    24,    25,     0,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,     0,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,     0,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,     0,    72,    73,     0,
       0,     0,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,     0,    85,     0,    86,    87,    88,    89,
       0,    90,     0,     0,     0,    91,    92,    93,    94,    95,
       0,     0,     0,     0,     0,     0,    96,    97,    98,    99,
     100,   101,   102,     0,     0,     0,   103,   104,   105,   106,
     107,     0,     0,     0,     0,   108,   109,   110,   111,   112,
     113,   114,   115,   116,     0,   117,   118,     0,     0,   119,
     120,   121,     0,     0,     0,   122,     0,   123,   124,   125,
       0,   126,   127,   128,     0,   129,     0,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,   143,     0,   438,   145,     0,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,     0,
     188,   189,   190,     0,   191,   192,   193,   194,   195,   196,
       0,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     4,     0,     0,     0,     0,   412,   413,     0,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,   418,
     419,    19,   421,   422,    22,   423,    24,    25,     0,    26,
      27,    28,    29,   424,    31,    32,    33,    34,    35,    36,
     427,    38,    39,   428,     0,    41,    42,    43,   430,    45,
     431,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,     0,    63,    64,
      65,    66,    67,    68,    69,    70,    71,     0,     0,    72,
      73,     0,     0,     0,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,     0,    85,     0,    86,    87,
      88,    89,     0,    90,     0,     0,     0,   433,    92,    93,
      94,    95,     0,     0,     0,     0,     0,     0,    96,    97,
      98,    99,   100,   101,   102,     0,     0,     0,   103,   104,
       0,   106,   107,     0,     0,     0,     0,   108,   109,   110,
     111,   112,   113,   114,   115,   116,     0,     0,     0,     0,
       0,   119,   120,   121,     0,     0,     0,   122,     0,   123,
     124,   125,     0,   126,   127,   128,     0,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,   143,     0,   438,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   439,   154,   441,   156,
     442,   443,   159,   160,   161,   162,   163,   164,   444,   166,
     445,   446,   447,   448,   171,   172,   449,   450,   175,   451,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,     0,   188,   189,   190,     0,   191,   192,   193,   194,
     195,   196,     0,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     0,     4,     0,     0,     0,     0,   412,   413,
       0,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,   418,   419,    19,   421,   422,    22,   423,    24,    25,
       0,    26,    27,    28,    29,   424,    31,    32,    33,    34,
      35,    36,   427,    38,    39,   428,     0,    41,    42,    43,
     430,    45,   431,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,     0,
      63,    64,    65,    66,    67,    68,    69,    70,    71,     0,
       0,    72,    73,     0,     0,     0,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,     0,    85,     0,
      86,    87,    88,    89,     0,    90,     0,     0,     0,   433,
      92,    93,    94,    95,     0,     0,     0,     0,     0,     0,
      96,    97,    98,    99,   100,   101,   102,     0,     0,     0,
     103,   104,     0,   106,   107,     0,     0,     0,     0,   108,
     109,   110,   111,   112,   113,   114,   115,   116,     0,     0,
       0,     0,     0,   119,   120,   121,     0,     0,     0,   122,
       0,   123,   124,   125,     0,     0,     0,   128,     0,   129,
       0,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,     0,     0,   141,   142,   143,     0,   438,   145,
       0,   146,   147,   148,   149,   150,   151,   152,   439,   154,
     441,   156,   442,   443,   159,   160,   161,   162,   163,   164,
     444,   166,   445,   446,   447,   448,   171,   172,   449,   450,
     175,   451,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,     0,   188,   189,   190,     0,   191,   192,
     193,   194,   195,   196,     0,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     0,     0,     0,     0,     0,
     412,   413,     0,     7,     8,   483,    10,    11,    12,    13,
     415,    15,   484,   418,   419,   420,   421,   422,    22,   423,
      24,    25,     0,    26,    27,    28,    29,   424,    31,   485,
      33,    34,    35,    36,   427,    38,    39,   428,     0,    41,
     486,    43,   430,    45,   431,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,     0,     0,
      62,     0,    63,    64,    65,   487,     0,     0,    69,    70,
      71,     0,     0,     0,    73,     0,     0,     0,     0,    75,
      76,    77,     0,     0,    80,    81,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,   433,    92,    93,     0,     0,     0,     0,     0,     0,
       0,     0,    96,    97,    98,     0,   100,   101,   102,     0,
       0,     0,     0,     0,     0,   106,   107,     0,     0,     0,
       0,   108,   109,   110,   111,   436,   113,   114,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   121,     0,     0,
       0,   122,     0,   123,   124,     0,     0,     0,     0,   128,
       0,   129,     0,   130,   131,   132,   133,   437,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,     0,     0,
     438,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     439,   154,   441,   156,   442,   443,   159,   160,   161,   162,
     163,   164,   444,   166,   445,   446,   447,   448,   171,   172,
     449,   450,   175,   451,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,     0,   188,   189,   190,     0,
     191,   192,   193,   194,   195,   196,     0,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,     1,     0,     0,
       0,     0,     0,     0,     2,     3,     0,     0,     0,     0,
       0,     0,   412,   413,     0,     7,     8,   414,    10,    11,
      12,    13,   415,   416,   417,   418,   419,   420,   421,   422,
      22,   423,    24,    25,     0,    26,    27,    28,    29,   424,
      31,   425,    33,    34,   426,    36,   427,    38,    39,   428,
       0,    41,   429,    43,   430,    45,   431,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
       0,     0,    62,     0,    63,    64,    65,   432,     0,     0,
      69,    70,    71,     0,     0,     0,    73,     0,     0,     0,
       0,    75,    76,    77,     0,     0,    80,    81,     0,     0,
       0,     0,     0,     0,    86,    87,    88,    89,     0,    90,
       0,     0,     0,   433,    92,    93,     0,     0,     0,     0,
       0,     0,     0,     0,    96,    97,    98,     0,   100,   101,
     102,     0,     0,     0,     0,     0,     0,   106,   107,     0,
       0,     0,     0,   108,   109,   110,   111,   436,   113,   114,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   121,
       0,     0,     0,   122,     0,   123,     0,     0,     0,     0,
       0,   128,     0,   129,     0,   130,   131,   132,   133,   437,
     135,   136,   137,   138,   139,   140,     0,     0,   141,   142,
       0,     0,   438,   145,     0,   146,   147,   148,   149,   150,
     151,   152,   439,   440,   441,   156,   442,   443,   159,   160,
     161,   162,   163,   164,   444,   166,   445,   446,   447,   448,
     171,   172,   449,   450,   175,   451,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,     0,   188,   189,
     190,     0,   191,   192,   193,   194,   195,   196,     0,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   465,
       0,     0,     0,     3,     0,     0,     0,     0,     0,     0,
     412,   413,     0,     7,     8,   414,    10,    11,    12,    13,
     415,   416,   417,   418,   419,   420,   421,   422,    22,   423,
      24,    25,     0,    26,    27,    28,    29,   424,    31,   425,
      33,    34,   426,    36,   427,    38,    39,   428,     0,    41,
     429,    43,   430,    45,   431,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,     0,     0,
      62,     0,    63,    64,    65,   432,     0,     0,    69,    70,
      71,     0,     0,     0,    73,     0,     0,     0,     0,    75,
      76,    77,     0,     0,    80,    81,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,   433,    92,    93,     0,     0,     0,     0,     0,     0,
       0,     0,    96,    97,    98,     0,   100,   101,   102,   466,
       0,     0,   467,     0,     0,   106,   107,     0,     0,     0,
       0,   108,   109,   110,   111,   436,   113,   114,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   121,     0,     0,
       0,   122,     0,   123,     0,     0,     0,     0,     0,     0,
       0,   129,     0,   130,   131,   132,   133,   437,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,     0,     0,
     438,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     439,   440,   441,   156,   442,   443,   159,   160,   161,   162,
     163,   164,   444,   166,   445,   446,   447,   448,   171,   172,
     449,   450,   175,   451,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,     0,   188,   189,   190,     0,
     191,   192,   193,   194,   195,   196,     0,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   465,     0,     0,
       0,     3,     0,   691,     0,     0,     0,     0,   412,   413,
       0,     7,     8,   414,    10,    11,    12,    13,   415,   416,
     417,   418,   419,   420,   421,   422,    22,   423,    24,    25,
       0,    26,    27,    28,    29,   424,    31,   425,    33,    34,
     426,    36,   427,    38,    39,   428,     0,    41,   429,    43,
     430,    45,   431,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,     0,     0,    62,     0,
      63,    64,    65,   432,     0,     0,    69,    70,    71,     0,
       0,     0,    73,     0,     0,     0,     0,    75,    76,    77,
       0,     0,    80,    81,     0,     0,     0,     0,     0,     0,
      86,    87,    88,    89,     0,    90,     0,     0,     0,   433,
      92,    93,     0,     0,     0,     0,     0,     0,     0,     0,
      96,    97,    98,     0,   100,   101,   102,     0,     0,     0,
       0,     0,     0,   106,   107,     0,     0,     0,     0,   108,
     109,   110,   111,   436,   113,   114,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   121,     0,     0,     0,   122,
     692,   123,     0,     0,     0,     0,     0,     0,     0,   129,
       0,   130,   131,   132,   133,   437,   135,   136,   137,   138,
     139,   140,     0,     0,   141,   142,     0,     0,   438,   145,
       0,   146,   147,   148,   149,   150,   151,   152,   439,   440,
     441,   156,   442,   443,   159,   160,   161,   162,   163,   164,
     444,   166,   445,   446,   447,   448,   171,   172,   449,   450,
     175,   451,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,     0,   188,   189,   190,     0,   191,   192,
     193,   194,   195,   196,     0,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   465,     0,     0,     0,     3,
       0,     0,     0,     0,     0,     0,   412,   413,     0,     7,
       8,   414,    10,    11,    12,    13,   415,   416,   417,   418,
     419,   420,   421,   422,    22,   423,    24,    25,     0,    26,
      27,    28,    29,   424,    31,   425,    33,    34,   426,    36,
     427,    38,    39,   428,     0,    41,   429,    43,   430,    45,
     431,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,     0,     0,    62,     0,    63,    64,
      65,   432,     0,     0,    69,    70,    71,     0,     0,     0,
      73,     0,     0,     0,     0,    75,    76,    77,     0,     0,
      80,    81,     0,     0,     0,     0,     0,     0,    86,    87,
      88,    89,     0,    90,     0,     0,     0,   433,    92,    93,
       0,     0,     0,     0,     0,     0,     0,     0,    96,    97,
      98,     0,   100,   101,   102,     0,     0,     0,     0,     0,
       0,   106,   107,     0,     0,     0,     0,   108,   109,   110,
     111,   436,   113,   114,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   121,     0,     0,     0,   122,     0,   123,
       0,     0,     0,     0,     0,     0,     0,   129,     0,   130,
     131,   132,   133,   437,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,     0,     0,   438,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   439,   440,   441,   156,
     442,   443,   159,   160,   161,   162,   163,   164,   444,   166,
     445,   446,   447,   448,   171,   172,   449,   450,   175,   451,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,     0,   188,   189,   190,     0,   191,   192,   193,   194,
     195,   196,     0,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   497,     0,     3,     0,     0,     0,     0,
       0,     0,   412,   413,     0,     7,     8,   414,    10,    11,
      12,    13,   415,   416,   417,   418,   419,   420,   421,   422,
      22,   423,    24,    25,     0,    26,    27,    28,    29,   424,
      31,   425,    33,    34,   426,    36,   427,    38,    39,   428,
       0,    41,   429,    43,   430,    45,   431,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
       0,     0,    62,     0,    63,    64,    65,   432,     0,     0,
      69,    70,    71,     0,     0,     0,    73,     0,     0,     0,
       0,    75,    76,    77,     0,     0,    80,    81,     0,     0,
       0,     0,     0,     0,    86,    87,    88,    89,     0,    90,
       0,     0,     0,   433,    92,    93,     0,     0,     0,     0,
       0,     0,     0,     0,    96,    97,    98,     0,   100,   101,
     102,     0,     0,     0,     0,     0,     0,   106,   107,     0,
       0,     0,     0,   108,   109,   110,   111,   436,   113,   114,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   121,
       0,     0,     0,   122,     0,   123,     0,     0,     0,     0,
       0,     0,     0,   129,     0,   130,   131,   132,   133,   437,
     135,   136,   137,   138,   139,   140,     0,     0,   141,   142,
       0,     0,   438,   145,     0,   146,   147,   148,   149,   150,
     151,   152,   439,   440,   441,   156,   442,   443,   159,   160,
     161,   162,   163,   164,   444,   166,   445,   446,   447,   448,
     171,   172,   449,   450,   175,   451,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,     0,   188,   189,
     190,     0,   191,   192,   193,   194,   195,   196,     0,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,     3,
       0,     0,     0,     0,     0,     0,   412,   413,     0,     7,
       8,   483,    10,    11,    12,    13,   415,    15,   484,   418,
     419,   967,   421,   422,    22,   423,    24,    25,     0,    26,
      27,    28,    29,   424,    31,   485,    33,    34,    35,    36,
     427,    38,    39,   428,     0,    41,   486,    43,   430,    45,
     431,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,     0,     0,    62,     0,    63,    64,
      65,   487,     0,     0,    69,    70,    71,     0,     0,     0,
      73,     0,     0,     0,     0,    75,    76,    77,     0,     0,
      80,    81,     0,     0,     0,     0,     0,     0,    86,    87,
      88,    89,     0,    90,     0,     0,     0,   433,    92,    93,
       0,     0,     0,     0,     0,     0,     0,     0,    96,    97,
      98,     0,   100,   101,   968,     0,     0,     0,   969,     0,
       0,   106,   107,     0,     0,     0,     0,   108,   109,   110,
     111,   436,   113,   114,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   121,     0,     0,     0,   122,  1332,   123,
     124,     0,     0,     0,     0,  1333,     0,   129,     0,   130,
     131,   132,   133,   437,   135,   136,   137,   138,   139,   140,
       0,     0,   970,   142,     0,     0,   438,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   439,   154,   441,   156,
     442,   443,   159,   160,   161,   162,   163,   164,   444,   166,
     445,   446,   447,   448,   171,   172,   449,   450,   175,   451,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,     0,   188,   189,   190,     0,   191,   192,   193,   194,
     195,   196,     0,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,     3,     0,     0,     0,     0,     0,     0,
     412,   413,     0,     7,     8,   483,    10,    11,    12,    13,
     415,    15,   484,   418,   419,   967,   421,   422,    22,   423,
      24,    25,     0,    26,    27,    28,    29,   424,    31,   485,
      33,    34,    35,    36,   427,    38,    39,   428,     0,    41,
     486,    43,   430,    45,   431,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,     0,     0,
      62,     0,    63,    64,    65,   487,     0,     0,    69,    70,
      71,     0,     0,     0,    73,     0,     0,     0,     0,    75,
      76,    77,     0,     0,    80,    81,  1291,     0,     0,     0,
       0,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,   433,    92,    93,     0,     0,     0,     0,     0,     0,
       0,     0,    96,    97,    98,     0,   100,   101,   968,     0,
       0,     0,   969,     0,     0,   106,   107,     0,     0,     0,
       0,   108,   109,   110,   111,   436,   113,   114,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   121,     0,     0,
       0,   122,     0,   123,   124,     0,     0,     0,     0,     0,
       0,   129,     0,   130,   131,   132,   133,   437,   135,   136,
     137,   138,   139,   140,     0,     0,   970,   142,     0,     0,
     438,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     439,   154,   441,   156,   442,   443,   159,   160,   161,   162,
     163,   164,   444,   166,   445,   446,   447,   448,   171,   172,
     449,   450,   175,   451,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,     0,   188,   189,   190,     0,
     191,   192,   193,   194,   195,   196,     0,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,     3,     0,     0,
       0,     0,     0,     0,   412,   413,     0,     7,     8,   414,
      10,    11,    12,    13,   415,   416,   417,   418,   419,   420,
     421,   422,    22,   423,    24,    25,     0,    26,    27,    28,
      29,   424,    31,   425,    33,    34,   426,    36,   427,    38,
      39,   428,     0,    41,   429,    43,   430,    45,   431,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,     0,     0,    62,     0,    63,    64,    65,   432,
       0,     0,    69,    70,    71,     0,     0,     0,    73,     0,
       0,     0,     0,    75,    76,    77,     0,     0,    80,    81,
       0,     0,     0,     0,     0,     0,    86,    87,    88,    89,
       0,    90,     0,     0,     0,   433,    92,    93,     0,     0,
       0,     0,     0,     0,     0,     0,    96,    97,    98,     0,
     100,   101,   102,   434,     0,     0,   435,     0,     0,   106,
     107,     0,     0,     0,     0,   108,   109,   110,   111,   436,
     113,   114,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   121,     0,     0,     0,   122,     0,   123,     0,     0,
       0,     0,     0,     0,     0,   129,     0,   130,   131,   132,
     133,   437,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,     0,     0,   438,   145,     0,   146,   147,   148,
     149,   150,   151,   152,   439,   440,   441,   156,   442,   443,
     159,   160,   161,   162,   163,   164,   444,   166,   445,   446,
     447,   448,   171,   172,   449,   450,   175,   451,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,     0,
     188,   189,   190,     0,   191,   192,   193,   194,   195,   196,
       0,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,     3,     0,     0,     0,     0,     0,     0,   412,   413,
       0,     7,     8,   414,    10,    11,    12,    13,   415,   416,
     417,   418,   419,   420,   421,   422,    22,   423,    24,    25,
       0,    26,    27,    28,    29,   424,    31,   425,    33,    34,
     426,    36,   427,    38,    39,   428,     0,    41,   429,    43,
     430,    45,   431,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,     0,     0,    62,     0,
      63,    64,    65,   432,     0,     0,    69,    70,    71,     0,
       0,     0,    73,     0,     0,     0,     0,    75,    76,    77,
       0,     0,    80,    81,     0,     0,     0,     0,     0,     0,
      86,    87,    88,    89,     0,    90,     0,     0,     0,   433,
      92,    93,     0,     0,     0,     0,     0,     0,     0,     0,
      96,    97,    98,     0,   100,   101,   102,   480,     0,     0,
     481,     0,     0,   106,   107,     0,     0,     0,     0,   108,
     109,   110,   111,   436,   113,   114,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   121,     0,     0,     0,   122,
       0,   123,     0,     0,     0,     0,     0,     0,     0,   129,
       0,   130,   131,   132,   133,   437,   135,   136,   137,   138,
     139,   140,     0,     0,   141,   142,     0,     0,   438,   145,
       0,   146,   147,   148,   149,   150,   151,   152,   439,   440,
     441,   156,   442,   443,   159,   160,   161,   162,   163,   164,
     444,   166,   445,   446,   447,   448,   171,   172,   449,   450,
     175,   451,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,     0,   188,   189,   190,     0,   191,   192,
     193,   194,   195,   196,     0,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,     3,     0,     0,     0,     0,
       0,     0,   412,   413,     0,     7,     8,   414,    10,    11,
      12,    13,   415,   416,   417,   418,   419,   420,   421,   422,
      22,   423,    24,    25,     0,    26,    27,    28,    29,   424,
      31,   425,    33,    34,   426,    36,   427,    38,    39,   428,
       0,    41,   429,    43,   430,    45,   431,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
       0,     0,    62,     0,    63,    64,    65,   432,     0,     0,
      69,    70,    71,     0,     0,     0,    73,     0,     0,     0,
       0,    75,    76,    77,     0,     0,    80,    81,     0,     0,
       0,     0,     0,     0,    86,    87,    88,    89,     0,    90,
       0,     0,     0,   433,    92,    93,     0,     0,     0,     0,
       0,     0,     0,     0,    96,    97,    98,     0,   100,   101,
     102,     0,     0,     0,     0,     0,     0,   106,   107,     0,
       0,     0,     0,   108,   109,   110,   111,   436,   113,   114,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   121,
       0,     0,     0,   122,   664,   123,     0,     0,     0,     0,
       0,   665,     0,   129,     0,   130,   131,   132,   133,   437,
     135,   136,   137,   138,   139,   140,     0,     0,   141,   142,
       0,     0,   438,   145,     0,   146,   147,   148,   149,   150,
     151,   152,   439,   440,   441,   156,   442,   443,   159,   160,
     161,   162,   163,   164,   444,   166,   445,   446,   447,   448,
     171,   172,   449,   450,   175,   451,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,     0,   188,   189,
     190,     0,   191,   192,   193,   194,   195,   196,     0,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,     3,
       0,     0,     0,     0,     0,     0,   412,   413,     0,     7,
       8,   414,    10,    11,    12,    13,   415,   416,   417,   418,
     419,   420,   421,   422,    22,   423,    24,    25,     0,    26,
      27,    28,    29,   424,    31,   425,    33,    34,   426,    36,
     427,    38,    39,   428,     0,    41,   429,    43,   430,    45,
     431,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,     0,     0,    62,     0,    63,    64,
      65,   432,     0,     0,    69,    70,    71,     0,     0,     0,
      73,     0,     0,     0,     0,    75,    76,    77,     0,     0,
      80,    81,     0,     0,     0,     0,     0,     0,    86,    87,
      88,    89,     0,    90,     0,     0,     0,   433,    92,    93,
       0,     0,     0,     0,     0,     0,     0,     0,    96,    97,
      98,     0,   100,   101,   102,     0,     0,     0,     0,     0,
       0,   106,   107,     0,     0,     0,     0,   108,   109,   110,
     111,   436,   113,   114,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   121,     0,     0,     0,   122,   709,   123,
       0,     0,     0,     0,     0,   710,     0,   129,     0,   130,
     131,   132,   133,   437,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,     0,     0,   438,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   439,   440,   441,   156,
     442,   443,   159,   160,   161,   162,   163,   164,   444,   166,
     445,   446,   447,   448,   171,   172,   449,   450,   175,   451,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,     0,   188,   189,   190,     0,   191,   192,   193,   194,
     195,   196,     0,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,     3,     0,     0,     0,     0,     0,     0,
     412,   413,     0,     7,     8,   483,    10,    11,    12,    13,
     415,    15,   484,   418,   419,   967,   421,   422,    22,   423,
      24,    25,     0,    26,    27,    28,    29,   424,    31,   485,
      33,    34,    35,    36,   427,    38,    39,   428,     0,    41,
     486,    43,   430,    45,   431,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,     0,     0,
      62,     0,    63,    64,    65,   487,     0,     0,    69,    70,
      71,     0,     0,     0,    73,     0,     0,     0,     0,    75,
      76,    77,     0,     0,    80,    81,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,   433,    92,    93,     0,     0,     0,     0,     0,     0,
       0,     0,    96,    97,    98,     0,   100,   101,   968,     0,
       0,     0,   969,     0,     0,   106,   107,     0,     0,     0,
       0,   108,   109,   110,   111,   436,   113,   114,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   121,     0,     0,
       0,   122,     0,   123,   124,     0,     0,     0,     0,     0,
       0,   129,     0,   130,   131,   132,   133,   437,   135,   136,
     137,   138,   139,   140,     0,     0,   970,   142,     0,     0,
     438,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     439,   154,   441,   156,   442,   443,   159,   160,   161,   162,
     163,   164,   444,   166,   445,   446,   447,   448,   171,   172,
     449,   450,   175,   451,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,     0,   188,   189,   190,     0,
     191,   192,   193,   194,   195,   196,     0,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,     3,     0,     0,
       0,     0,     0,     0,   412,   413,     0,     7,     8,   483,
      10,    11,    12,    13,   415,    15,   484,   418,   419,   967,
     421,   422,    22,   423,    24,    25,     0,    26,    27,    28,
      29,   424,    31,   485,    33,    34,    35,    36,   427,    38,
      39,   428,     0,    41,   486,    43,   430,    45,   431,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,     0,     0,    62,     0,    63,    64,    65,   487,
       0,     0,    69,    70,    71,     0,     0,     0,    73,     0,
       0,     0,     0,    75,    76,    77,     0,     0,    80,    81,
       0,     0,     0,     0,     0,     0,    86,    87,    88,    89,
       0,    90,     0,     0,     0,   433,    92,    93,     0,     0,
       0,     0,     0,     0,     0,     0,    96,    97,    98,     0,
     100,   101,   968,     0,     0,     0,   969,     0,     0,   106,
     107,     0,     0,     0,     0,   108,   109,   110,   111,   436,
     113,   114,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   121,     0,     0,     0,   122,     0,   123,   124,     0,
       0,     0,     0,     0,     0,   129,     0,   130,   131,   132,
     133,   437,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,     0,     0,   438,   145,     0,   146,   147,   148,
     149,   150,   151,   152,   439,   154,   441,   156,   442,   443,
     159,   160,   161,   162,   163,   164,   444,   166,   445,   446,
     447,   448,   171,   172,   449,   450,   175,   451,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,     0,
     188,   189,   190,     0,   191,   192,   193,   194,   195,   196,
       0,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,     3,     0,     0,     0,     0,     0,     0,   412,   413,
       0,     7,     8,   414,    10,    11,    12,    13,   415,   416,
     417,   418,   419,   420,   421,   422,    22,   423,    24,    25,
       0,    26,    27,    28,    29,   424,    31,   425,    33,    34,
     426,    36,   427,    38,    39,   428,     0,    41,   429,    43,
     430,    45,   431,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,     0,     0,    62,     0,
      63,    64,    65,   432,     0,     0,    69,    70,    71,     0,
       0,     0,    73,     0,     0,     0,     0,    75,    76,    77,
       0,     0,    80,    81,     0,     0,     0,     0,     0,     0,
      86,    87,    88,    89,     0,    90,     0,     0,     0,   433,
      92,    93,     0,     0,     0,     0,     0,     0,     0,     0,
      96,    97,    98,     0,   100,   101,   102,     0,     0,     0,
       0,     0,     0,   106,   107,     0,     0,     0,     0,   108,
     109,   110,   111,   436,   113,   114,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   121,     0,     0,     0,   122,
       0,   123,     0,     0,     0,     0,     0,     0,     0,   129,
       0,   130,   131,   132,   133,   437,   135,   136,   137,   138,
     139,   140,     0,     0,   141,   142,     0,     0,   438,   145,
       0,   146,   147,   148,   149,   150,   151,   152,   439,   440,
     441,   156,   442,   443,   159,   160,   161,   162,   163,   164,
     444,   166,   445,   446,   447,   448,   171,   172,   449,   450,
     175,   451,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,     0,   188,   189,   190,     0,   191,   192,
     193,   194,   195,   196,     0,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
        16,   716,   534,   308,   775,   116,   895,   103,   576,   789,
     790,   577,   578,   579,   580,   531,    32,   127,  1064,   863,
    1165,   369,   929,   688,    68,  1318,  1176,  1177,   991,   775,
      47,   553,    20,    50,  1252,    49,   111,   688,   616,   758,
     787,   788,   556,    89,   558,   559,    89,   561,   699,   563,
      66,     7,    68,    21,   453,   822,  1227,   571,   572,    87,
     133,  1138,    87,   100,   100,    20,    82,    87,   787,   788,
     138,     4,    45,    86,    37,     8,    93,   100,     4,   100,
      38,    87,     8,    89,   951,   100,    20,   136,   104,   100,
     100,   110,   138,   151,    57,   121,   138,   762,   147,   764,
     116,   100,   118,   822,   160,   133,   505,   506,   124,   508,
     509,   510,   511,   461,   462,   103,    87,   122,   137,   518,
     519,    61,    30,    87,    89,    87,    66,   115,    36,    37,
      46,   150,   138,   532,   128,    26,   192,    53,   885,   858,
     127,   216,   100,   542,   543,   181,    54,   120,   144,    57,
     144,   106,   140,   174,   141,  1022,   144,    65,   181,   147,
     173,   187,   111,   178,    55,   184,   885,   138,   178,   121,
     181,   111,    89,    89,   138,  1325,   181,   828,   177,   167,
     147,   114,    90,   116,   144,     8,     9,    87,   114,   226,
     116,   124,   265,    20,   208,   160,   151,   265,   124,     8,
       9,   311,   969,   228,   603,   248,   249,   606,   228,   165,
     925,   144,  1101,  1384,   177,  1261,  1060,   151,   144,   265,
     991,   992,  1129,   265,   299,  1302,   243,   878,   177,   807,
     808,  1138,   246,   884,   899,   187,   204,   265,  1456,   256,
    1203,   258,   764,   160,  1537,   991,   992,   209,   210,   100,
     969,    93,   269,   270,   271,   100,   273,   771,   275,   265,
     100,  1554,   224,   251,   106,    99,   149,    37,   284,  1562,
      40,   179,   316,    96,   385,   319,   103,  1422,   149,   244,
     245,   208,   247,   166,   118,   633,   100,    96,   115,   254,
     100,   114,   111,   116,    89,   166,   407,   182,   183,   264,
     316,   100,    72,   319,     8,   114,   189,   116,   216,   209,
     210,   276,   408,   140,   410,    19,   100,   144,   147,   246,
     147,   144,   987,   127,   224,   148,   177,   244,   245,    99,
     247,   100,   177,   149,   147,   144,   684,   177,   434,   148,
     167,   164,  1388,    87,   191,   100,  1093,   264,  1067,    25,
     166,   100,   147,   200,   753,   164,   467,   176,   374,   276,
     376,   760,   185,   177,   460,   381,    42,   177,  1115,   385,
     466,  1521,     8,   189,  1093,   391,   185,   473,   177,   475,
     203,   477,   398,    19,   480,   149,   144,   191,   111,   159,
     261,   407,    33,   177,   203,  1302,  1115,   268,    39,   495,
     144,    39,   166,    44,   135,   501,    46,   278,   177,   167,
     114,    52,   116,    53,   144,   144,  1260,   147,  1464,   435,
     172,   125,   177,    64,   520,   824,     8,     9,   177,    89,
      70,   830,  1203,    89,   186,   166,  1183,    88,   167,   955,
     144,  1212,   139,     8,     9,  1491,   106,   463,    99,    89,
     106,   467,  1223,   184,   470,   471,   472,  1203,   109,   156,
     476,  1472,  1473,   147,  1183,   481,  1212,   118,   212,   213,
     200,   111,    40,   291,    87,   491,   111,  1223,   114,   871,
     116,   873,   300,   831,   832,   595,   596,   147,   836,   125,
      58,   147,    60,  1504,   111,   261,   592,   513,   897,  1510,
      68,   597,   268,   128,  1550,   521,  1552,   906,   144,   908,
     909,  1400,   278,   139,    96,   128,    89,   865,   159,   144,
     133,   162,  1568,   239,   240,   924,   918,   216,   920,   218,
     156,    96,   114,   106,   116,   176,   935,   936,   937,   128,
     939,   940,   941,   942,   943,   944,   262,   946,   947,   114,
     157,   116,   255,   172,   819,   144,   223,    46,   225,   255,
     959,   202,   144,   266,    53,   172,   148,   186,   833,   680,
     266,   667,   683,   260,   144,   144,   147,   147,   147,   144,
     267,   677,   164,   148,   983,  1300,   985,   986,   216,  1304,
     292,   293,  1363,   221,   269,   270,   271,   160,   694,   164,
     275,   598,   111,   185,   601,   621,   144,   604,   624,   128,
     706,   707,   628,  1012,   133,   144,   712,  1363,   128,   318,
     185,   203,   206,   133,   323,   212,   213,   214,   216,   192,
     218,  1030,   119,   120,   650,   651,   652,   145,   203,   147,
     292,   293,   738,   223,   147,   225,  1214,   373,   111,   375,
     283,   284,   119,   120,   216,   671,   144,   673,   221,   574,
     575,   581,   582,   147,   680,   583,   584,   683,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,   233,  1078,
    1427,   233,  1429,   234,  1083,  1375,  1376,   144,   993,   111,
       0,   181,   158,    85,   241,  1410,  1095,    43,  1413,   715,
     181,    94,   145,    20,   190,    95,  1105,  1106,  1427,  1241,
    1429,    40,  1492,    40,    40,  1114,   279,   280,   281,   282,
     283,  1468,   285,   286,   287,   288,   289,   143,   111,   285,
     290,   294,   238,   290,   144,   751,  1483,   296,   177,   276,
     276,   111,   758,   144,   111,   144,   177,   144,  1096,  1468,
     144,   147,   147,   144,   177,    27,    15,   177,   147,   123,
     147,  1476,   147,   204,  1483,    20,   177,   131,   132,  1168,
     134,   787,   788,   789,   790,   222,    25,   111,   142,   159,
    1179,  1347,   146,   161,   148,   161,  1354,  1355,   100,   153,
      65,    87,   222,    87,    87,  1194,   140,   100,  1197,   100,
    1199,    20,   151,   151,   118,   169,   822,   123,   291,   238,
     123,   174,    34,   174,   174,   177,    87,   913,    40,   177,
     174,   177,   838,    89,  1172,    37,    48,    89,    50,   193,
     194,   195,   196,   197,   198,   100,    58,   174,    60,   177,
     144,   177,   177,   133,   174,   177,    68,    87,   216,   174,
      72,   174,   174,   174,   228,   871,   133,   873,   177,   174,
     111,   181,   161,   111,   111,   111,  1434,  1435,   138,   885,
     175,   123,  1271,   133,   174,   133,    87,    20,  1277,   218,
     278,   144,   104,   105,   106,   291,   174,  1286,   111,   246,
      87,   174,   123,   188,   990,   151,   123,    89,   111,   133,
     144,   174,   918,   111,   920,   138,    93,   174,   144,  1308,
    1309,  1310,  1311,  1312,    27,  1314,  1315,   174,  1486,    20,
     174,   111,   111,   144,  1020,    72,   237,   100,   100,   174,
     147,   147,   147,  1281,   138,   138,   277,   135,   160,    20,
      20,   250,  1341,    20,   252,   278,   228,   963,   279,   218,
     966,   298,   259,   969,   218,   181,   135,   218,   138,   177,
     111,   111,    70,   177,   980,   100,   982,   177,   177,   133,
     192,   177,   174,    28,    29,  1071,    31,    32,   177,    34,
       6,  1329,   123,   224,   133,    40,   181,   224,   176,   224,
     228,   177,   224,    48,    99,    50,    51,    99,   138,   221,
    1399,   177,   177,    58,   174,    60,  1405,   138,  1407,   177,
     278,    71,  1108,    68,   242,   174,    20,    72,   242,    20,
     263,   274,    89,   161,   249,  1121,   174,   117,    89,   174,
     176,   253,   174,    87,   144,   174,    20,   100,   174,   161,
     177,    46,   272,   177,    87,   111,    87,    20,   100,   104,
     105,   106,    87,   111,   187,   216,   257,   279,   280,   281,
     282,   283,   111,   285,   286,   287,   288,   289,  1084,   176,
     187,   187,   294,   295,   279,   174,   176,  1093,   111,    86,
     173,   187,   111,   111,   216,   144,   111,  1103,   177,   285,
     297,   189,   216,   111,   530,  1111,   151,   297,   279,  1115,
     632,  1500,   530,   297,  1026,   160,   823,   298,   237,   383,
     240,   403,   240,   298,   298,  1464,   243,  1067,  1491,  1135,
    1161,   886,   883,  1522,   244,   283,  1103,   966,  1527,   379,
    1275,   459,  1085,  1181,  1169,   959,   491,   192,  1176,  1179,
    1156,  1111,  1116,   555,   304,   554,   606,  1129,  1547,  1165,
     716,  1510,  1504,  1169,  1061,   873,   211,  1025,   790,  1166,
    1212,  1156,  1223,  1363,   992,  1216,   221,  1183,  1360,   411,
    1001,   857,   411,  1050,  1250,  1378,    -1,    -1,    -1,  1213,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   253,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   279,   280,   281,   282,   283,    -1,
     285,   286,   287,   288,   289,    -1,    -1,    -1,    -1,   294,
     295,    -1,  1258,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1272,  1273,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1291,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1301,    -1,    -1,    -1,  1305,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1444,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1406,    -1,    -1,    -1,    -1,  1411,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1422,    -1,    -1,    -1,
      -1,  1427,    -1,  1429,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1460,    -1,    -1,  1463,    -1,    -1,
      -1,    -1,  1468,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1479,    -1,    -1,    -1,  1483,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1492,    -1,  1494,    -1,
      -1,    -1,  1498,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1524,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1542,    -1,  1544,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    10,    -1,    -1,    -1,
      -1,  1557,    -1,    17,    18,  1561,    20,    -1,    -1,    -1,
    1566,    25,    26,    -1,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    -1,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    -1,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    -1,    -1,    98,    99,    -1,    -1,    -1,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
      -1,   115,    -1,   117,   118,   119,   120,    -1,   122,    -1,
      -1,    -1,   126,   127,   128,   129,   130,    -1,    -1,    -1,
      -1,    -1,    -1,   137,   138,   139,   140,   141,   142,   143,
      -1,    -1,    -1,   147,   148,   149,   150,   151,    -1,    -1,
      -1,    -1,   156,   157,   158,   159,   160,   161,   162,   163,
     164,    -1,   166,   167,    -1,    -1,   170,   171,   172,    -1,
      -1,    -1,   176,    -1,   178,   179,   180,    -1,   182,   183,
     184,    -1,   186,    -1,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,    -1,    -1,   201,   202,   203,
      -1,   205,   206,    -1,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,   251,   252,   253,
      -1,   255,   256,   257,   258,   259,   260,    -1,   262,   263,
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
      81,    82,    83,    84,    85,    -1,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    -1,    -1,    98,    99,    -1,
      -1,    -1,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,    -1,   115,    -1,   117,   118,   119,   120,
      -1,   122,    -1,    -1,    -1,   126,   127,   128,   129,   130,
      -1,    -1,    -1,    -1,    -1,    -1,   137,   138,   139,   140,
     141,   142,   143,    -1,    -1,    -1,   147,   148,   149,   150,
     151,    -1,    -1,    -1,    -1,   156,   157,   158,   159,   160,
     161,   162,   163,   164,    -1,   166,   167,    -1,    -1,   170,
     171,   172,    -1,    -1,    -1,   176,   177,   178,   179,   180,
      -1,   182,   183,   184,    -1,   186,    -1,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,    -1,    -1,
     201,   202,   203,    -1,   205,   206,    -1,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
     251,   252,   253,    -1,   255,   256,   257,   258,   259,   260,
      -1,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      -1,    20,    -1,    -1,    -1,    -1,    25,    26,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    -1,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    -1,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    -1,    -1,    98,
      99,    -1,    -1,    -1,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,    -1,   115,    -1,   117,   118,
     119,   120,    -1,   122,    -1,    -1,    -1,   126,   127,   128,
     129,   130,    -1,    -1,    -1,    -1,    -1,    -1,   137,   138,
     139,   140,   141,   142,   143,    -1,    -1,    -1,   147,   148,
     149,   150,   151,    -1,    -1,    -1,    -1,   156,   157,   158,
     159,   160,   161,   162,   163,   164,    -1,   166,   167,    -1,
      -1,   170,   171,   172,    -1,   174,    -1,   176,    -1,   178,
     179,   180,    -1,   182,   183,   184,    -1,   186,    -1,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
      -1,    -1,   201,   202,   203,    -1,   205,   206,    -1,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,   251,   252,   253,    -1,   255,   256,   257,   258,
     259,   260,    -1,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    20,    -1,    -1,    -1,    -1,    25,    26,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    -1,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    -1,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    -1,
      -1,    98,    99,    -1,    -1,    -1,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,    -1,   115,    -1,
     117,   118,   119,   120,    -1,   122,    -1,    -1,    -1,   126,
     127,   128,   129,   130,    -1,    -1,    -1,    -1,    -1,    -1,
     137,   138,   139,   140,   141,   142,   143,    -1,    -1,    -1,
     147,   148,   149,   150,   151,    -1,    -1,    -1,    -1,   156,
     157,   158,   159,   160,   161,   162,   163,   164,    -1,   166,
     167,    -1,    -1,   170,   171,   172,    -1,    -1,    -1,   176,
     177,   178,   179,   180,    -1,   182,   183,   184,    -1,   186,
      -1,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,    -1,    -1,   201,   202,   203,    -1,   205,   206,
      -1,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,   251,   252,   253,    -1,   255,   256,
     257,   258,   259,   260,    -1,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    -1,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    -1,    -1,    98,    99,    -1,    -1,    -1,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,    -1,
     115,    -1,   117,   118,   119,   120,    -1,   122,    -1,    -1,
      -1,   126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,
      -1,    -1,   137,   138,   139,   140,   141,   142,   143,    -1,
      -1,    -1,   147,   148,   149,   150,   151,    -1,    -1,    -1,
      -1,   156,   157,   158,   159,   160,   161,   162,   163,   164,
      -1,   166,   167,    -1,    -1,   170,   171,   172,    -1,    -1,
      -1,   176,   177,   178,   179,   180,    -1,   182,   183,   184,
      -1,   186,    -1,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,    -1,    -1,   201,   202,   203,    -1,
     205,   206,    -1,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,   251,   252,   253,    -1,
     255,   256,   257,   258,   259,   260,    -1,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,
      -1,    -1,    25,    26,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      -1,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    -1,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    -1,    -1,    98,    99,    -1,    -1,    -1,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,    -1,   115,    -1,   117,   118,   119,   120,    -1,   122,
      -1,    -1,    -1,   126,   127,   128,   129,   130,    -1,    -1,
      -1,    -1,    -1,    -1,   137,   138,   139,   140,   141,   142,
     143,    -1,    -1,    -1,   147,   148,   149,   150,   151,    -1,
      -1,    -1,    -1,   156,   157,   158,   159,   160,   161,   162,
     163,   164,    -1,   166,   167,    -1,    -1,   170,   171,   172,
      -1,   174,    -1,   176,    -1,   178,   179,   180,    -1,   182,
     183,   184,    -1,   186,    -1,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,    -1,    -1,   201,   202,
     203,    -1,   205,   206,    -1,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,    -1,   251,   252,
     253,    -1,   255,   256,   257,   258,   259,   260,    -1,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,
      -1,    -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    -1,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    -1,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    -1,    -1,    98,    99,    -1,
      -1,    -1,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,    -1,   115,    -1,   117,   118,   119,   120,
      -1,   122,    -1,    -1,    -1,   126,   127,   128,   129,   130,
      -1,    -1,    -1,    -1,    -1,    -1,   137,   138,   139,   140,
     141,   142,   143,    -1,    -1,    -1,   147,   148,   149,   150,
     151,    -1,    -1,    -1,    -1,   156,   157,   158,   159,   160,
     161,   162,   163,   164,    -1,   166,   167,    -1,    -1,   170,
     171,   172,    -1,   174,    -1,   176,    -1,   178,   179,   180,
      -1,   182,   183,   184,    -1,   186,    -1,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,    -1,    -1,
     201,   202,   203,    -1,   205,   206,    -1,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
     251,   252,   253,    -1,   255,   256,   257,   258,   259,   260,
      -1,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      -1,    20,    -1,    -1,    -1,    -1,    25,    26,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    -1,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    -1,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    -1,    -1,    98,
      99,    -1,    -1,    -1,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,    -1,   115,    -1,   117,   118,
     119,   120,    -1,   122,    -1,    -1,    -1,   126,   127,   128,
     129,   130,    -1,    -1,    -1,    -1,    -1,    -1,   137,   138,
     139,   140,   141,   142,   143,    -1,    -1,    -1,   147,   148,
     149,   150,   151,    -1,    -1,    -1,    -1,   156,   157,   158,
     159,   160,   161,   162,   163,   164,    -1,   166,   167,    -1,
      -1,   170,   171,   172,    -1,   174,    -1,   176,    -1,   178,
     179,   180,    -1,   182,   183,   184,    -1,   186,    -1,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
      -1,    -1,   201,   202,   203,    -1,   205,   206,    -1,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,   251,   252,   253,    -1,   255,   256,   257,   258,
     259,   260,    -1,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    20,    -1,    -1,    -1,    -1,    25,    26,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    -1,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    -1,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    -1,
      -1,    98,    99,    -1,    -1,    -1,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,    -1,   115,    -1,
     117,   118,   119,   120,    -1,   122,    -1,    -1,    -1,   126,
     127,   128,   129,   130,    -1,    -1,    -1,    -1,    -1,    -1,
     137,   138,   139,   140,   141,   142,   143,    -1,    -1,    -1,
     147,   148,   149,   150,   151,    -1,    -1,    -1,    -1,   156,
     157,   158,   159,   160,   161,   162,   163,   164,    -1,   166,
     167,    -1,    -1,   170,   171,   172,    -1,   174,    -1,   176,
      -1,   178,   179,   180,    -1,   182,   183,   184,    -1,   186,
      -1,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,    -1,    -1,   201,   202,   203,    -1,   205,   206,
      -1,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,   251,   252,   253,    -1,   255,   256,
     257,   258,   259,   260,    -1,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    -1,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    -1,    -1,    98,    99,    -1,    -1,    -1,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,    -1,
     115,    -1,   117,   118,   119,   120,    -1,   122,    -1,    -1,
      -1,   126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,
      -1,    -1,   137,   138,   139,   140,   141,   142,   143,    -1,
      -1,    -1,   147,   148,   149,   150,   151,    -1,    -1,    -1,
      -1,   156,   157,   158,   159,   160,   161,   162,   163,   164,
      -1,   166,   167,    -1,    -1,   170,   171,   172,    -1,   174,
      -1,   176,    -1,   178,   179,   180,    -1,   182,   183,   184,
      -1,   186,    -1,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,    -1,    -1,   201,   202,   203,    -1,
     205,   206,    -1,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,   251,   252,   253,    -1,
     255,   256,   257,   258,   259,   260,    -1,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,
      -1,    -1,    25,    26,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      -1,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    -1,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    -1,    -1,    98,    99,    -1,    -1,    -1,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,    -1,   115,    -1,   117,   118,   119,   120,    -1,   122,
      -1,    -1,    -1,   126,   127,   128,   129,   130,    -1,    -1,
      -1,    -1,    -1,    -1,   137,   138,   139,   140,   141,   142,
     143,    -1,    -1,    -1,   147,   148,   149,   150,   151,    -1,
      -1,    -1,    -1,   156,   157,   158,   159,   160,   161,   162,
     163,   164,    -1,   166,   167,    -1,    -1,   170,   171,   172,
      -1,   174,    -1,   176,    -1,   178,   179,   180,    -1,   182,
     183,   184,    -1,   186,    -1,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,    -1,    -1,   201,   202,
     203,    -1,   205,   206,    -1,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,    -1,   251,   252,
     253,    -1,   255,   256,   257,   258,   259,   260,    -1,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,
      -1,    -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    -1,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    -1,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    -1,    -1,    98,    99,    -1,
      -1,    -1,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,    -1,   115,    -1,   117,   118,   119,   120,
      -1,   122,    -1,    -1,    -1,   126,   127,   128,   129,   130,
      -1,    -1,    -1,    -1,    -1,    -1,   137,   138,   139,   140,
     141,   142,   143,    -1,    -1,    -1,   147,   148,   149,   150,
     151,    -1,    -1,    -1,    -1,   156,   157,   158,   159,   160,
     161,   162,   163,   164,    -1,   166,   167,    -1,    -1,   170,
     171,   172,    -1,    -1,    -1,   176,    -1,   178,   179,   180,
      -1,   182,   183,   184,    -1,   186,    -1,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,    -1,    -1,
     201,   202,   203,    -1,   205,   206,    -1,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
     251,   252,   253,    -1,   255,   256,   257,   258,   259,   260,
      -1,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      -1,    20,    -1,    -1,    -1,    -1,    25,    26,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    -1,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    -1,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    -1,    -1,    98,
      99,    -1,    -1,    -1,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,    -1,   115,    -1,   117,   118,
     119,   120,    -1,   122,    -1,    -1,    -1,   126,   127,   128,
     129,   130,    -1,    -1,    -1,    -1,    -1,    -1,   137,   138,
     139,   140,   141,   142,   143,    -1,    -1,    -1,   147,   148,
     149,   150,   151,    -1,    -1,    -1,    -1,   156,   157,   158,
     159,   160,   161,   162,   163,   164,    -1,   166,   167,    -1,
      -1,   170,   171,   172,    -1,    -1,    -1,   176,    -1,   178,
     179,   180,    -1,   182,   183,   184,    -1,   186,    -1,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
      -1,    -1,   201,   202,   203,    -1,   205,   206,    -1,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,   251,   252,   253,    -1,   255,   256,   257,   258,
     259,   260,    -1,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    20,    -1,    -1,    -1,    -1,    25,    26,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    -1,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    -1,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    -1,
      -1,    98,    99,    -1,    -1,    -1,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,    -1,   115,    -1,
     117,   118,   119,   120,    -1,   122,    -1,    -1,    -1,   126,
     127,   128,   129,   130,    -1,    -1,    -1,    -1,    -1,    -1,
     137,   138,   139,   140,   141,   142,   143,    -1,    -1,    -1,
     147,   148,   149,   150,   151,    -1,    -1,    -1,    -1,   156,
     157,   158,   159,   160,   161,   162,   163,   164,    -1,   166,
     167,    -1,    -1,   170,   171,   172,    -1,    -1,    -1,   176,
      -1,   178,   179,   180,    -1,   182,   183,   184,    -1,   186,
      -1,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,    -1,    -1,   201,   202,   203,    -1,   205,   206,
      -1,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,   251,   252,   253,    -1,   255,   256,
     257,   258,   259,   260,    -1,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    -1,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    -1,    -1,    98,    99,    -1,    -1,    -1,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,    -1,
     115,    -1,   117,   118,   119,   120,    -1,   122,    -1,    -1,
      -1,   126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,
      -1,    -1,   137,   138,   139,   140,   141,   142,   143,    -1,
      -1,    -1,   147,   148,   149,   150,   151,    -1,    -1,    -1,
      -1,   156,   157,   158,   159,   160,   161,   162,   163,   164,
      -1,   166,   167,    -1,    -1,   170,   171,   172,    -1,    -1,
      -1,   176,    -1,   178,   179,   180,    -1,   182,   183,   184,
      -1,   186,    -1,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,    -1,    -1,   201,   202,   203,    -1,
     205,   206,    -1,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,   251,   252,   253,    -1,
     255,   256,   257,   258,   259,   260,    -1,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,
      -1,    -1,    25,    26,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      -1,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    -1,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    -1,    -1,    98,    99,    -1,    -1,    -1,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,    -1,   115,    -1,   117,   118,   119,   120,    -1,   122,
      -1,    -1,    -1,   126,   127,   128,   129,   130,    -1,    -1,
      -1,    -1,    -1,    -1,   137,   138,   139,   140,   141,   142,
     143,    -1,    -1,    -1,   147,   148,   149,   150,   151,    -1,
      -1,    -1,    -1,   156,   157,   158,   159,   160,   161,   162,
     163,   164,    -1,   166,   167,    -1,    -1,   170,   171,   172,
      -1,    -1,    -1,   176,    -1,   178,   179,   180,    -1,   182,
     183,   184,    -1,   186,    -1,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,    -1,    -1,   201,   202,
     203,    -1,   205,   206,    -1,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,    -1,   251,   252,
     253,    -1,   255,   256,   257,   258,   259,   260,    -1,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,
      -1,    -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    -1,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    -1,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    -1,    -1,    98,    99,    -1,
      -1,    -1,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,    -1,   115,    -1,   117,   118,   119,   120,
      -1,   122,    -1,    -1,    -1,   126,   127,   128,   129,   130,
      -1,    -1,    -1,    -1,    -1,    -1,   137,   138,   139,   140,
     141,   142,   143,    -1,    -1,    -1,   147,   148,   149,   150,
     151,    -1,    -1,    -1,    -1,   156,   157,   158,   159,   160,
     161,   162,   163,   164,    -1,   166,   167,    -1,    -1,   170,
     171,   172,    -1,    -1,    -1,   176,    -1,   178,   179,   180,
      -1,   182,   183,   184,    -1,   186,    -1,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,    -1,    -1,
     201,   202,   203,    -1,   205,   206,    -1,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
     251,   252,   253,    -1,   255,   256,   257,   258,   259,   260,
      -1,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      -1,    20,    -1,    -1,    -1,    -1,    25,    26,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    -1,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    -1,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    -1,    -1,    98,
      99,    -1,    -1,    -1,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,    -1,   115,    -1,   117,   118,
     119,   120,    -1,   122,    -1,    -1,    -1,   126,   127,   128,
     129,   130,    -1,    -1,    -1,    -1,    -1,    -1,   137,   138,
     139,   140,   141,   142,   143,    -1,    -1,    -1,   147,   148,
      -1,   150,   151,    -1,    -1,    -1,    -1,   156,   157,   158,
     159,   160,   161,   162,   163,   164,    -1,    -1,    -1,    -1,
      -1,   170,   171,   172,    -1,    -1,    -1,   176,    -1,   178,
     179,   180,    -1,   182,   183,   184,    -1,   186,    -1,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
      -1,    -1,   201,   202,   203,    -1,   205,   206,    -1,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,   251,   252,   253,    -1,   255,   256,   257,   258,
     259,   260,    -1,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    20,    -1,    -1,    -1,    -1,    25,    26,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    -1,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    -1,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    -1,
      -1,    98,    99,    -1,    -1,    -1,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,    -1,   115,    -1,
     117,   118,   119,   120,    -1,   122,    -1,    -1,    -1,   126,
     127,   128,   129,   130,    -1,    -1,    -1,    -1,    -1,    -1,
     137,   138,   139,   140,   141,   142,   143,    -1,    -1,    -1,
     147,   148,    -1,   150,   151,    -1,    -1,    -1,    -1,   156,
     157,   158,   159,   160,   161,   162,   163,   164,    -1,    -1,
      -1,    -1,    -1,   170,   171,   172,    -1,    -1,    -1,   176,
      -1,   178,   179,   180,    -1,    -1,    -1,   184,    -1,   186,
      -1,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,    -1,    -1,   201,   202,   203,    -1,   205,   206,
      -1,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,   251,   252,   253,    -1,   255,   256,
     257,   258,   259,   260,    -1,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    -1,    -1,
      85,    -1,    87,    88,    89,    90,    -1,    -1,    93,    94,
      95,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,   104,
     105,   106,    -1,    -1,   109,   110,    -1,    -1,    -1,    -1,
      -1,    -1,   117,   118,   119,   120,    -1,   122,    -1,    -1,
      -1,   126,   127,   128,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   137,   138,   139,    -1,   141,   142,   143,    -1,
      -1,    -1,    -1,    -1,    -1,   150,   151,    -1,    -1,    -1,
      -1,   156,   157,   158,   159,   160,   161,   162,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   172,    -1,    -1,
      -1,   176,    -1,   178,   179,    -1,    -1,    -1,    -1,   184,
      -1,   186,    -1,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,    -1,    -1,   201,   202,    -1,    -1,
     205,   206,    -1,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,   251,   252,   253,    -1,
     255,   256,   257,   258,   259,   260,    -1,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    25,    26,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      -1,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      -1,    -1,    85,    -1,    87,    88,    89,    90,    -1,    -1,
      93,    94,    95,    -1,    -1,    -1,    99,    -1,    -1,    -1,
      -1,   104,   105,   106,    -1,    -1,   109,   110,    -1,    -1,
      -1,    -1,    -1,    -1,   117,   118,   119,   120,    -1,   122,
      -1,    -1,    -1,   126,   127,   128,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   137,   138,   139,    -1,   141,   142,
     143,    -1,    -1,    -1,    -1,    -1,    -1,   150,   151,    -1,
      -1,    -1,    -1,   156,   157,   158,   159,   160,   161,   162,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   172,
      -1,    -1,    -1,   176,    -1,   178,    -1,    -1,    -1,    -1,
      -1,   184,    -1,   186,    -1,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,    -1,    -1,   201,   202,
      -1,    -1,   205,   206,    -1,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,    -1,   251,   252,
     253,    -1,   255,   256,   257,   258,   259,   260,    -1,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,    14,
      -1,    -1,    -1,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    -1,    -1,
      85,    -1,    87,    88,    89,    90,    -1,    -1,    93,    94,
      95,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,   104,
     105,   106,    -1,    -1,   109,   110,    -1,    -1,    -1,    -1,
      -1,    -1,   117,   118,   119,   120,    -1,   122,    -1,    -1,
      -1,   126,   127,   128,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   137,   138,   139,    -1,   141,   142,   143,   144,
      -1,    -1,   147,    -1,    -1,   150,   151,    -1,    -1,    -1,
      -1,   156,   157,   158,   159,   160,   161,   162,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   172,    -1,    -1,
      -1,   176,    -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   186,    -1,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,    -1,    -1,   201,   202,    -1,    -1,
     205,   206,    -1,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,   251,   252,   253,    -1,
     255,   256,   257,   258,   259,   260,    -1,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,    14,    -1,    -1,
      -1,    18,    -1,    20,    -1,    -1,    -1,    -1,    25,    26,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    -1,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    -1,    -1,    85,    -1,
      87,    88,    89,    90,    -1,    -1,    93,    94,    95,    -1,
      -1,    -1,    99,    -1,    -1,    -1,    -1,   104,   105,   106,
      -1,    -1,   109,   110,    -1,    -1,    -1,    -1,    -1,    -1,
     117,   118,   119,   120,    -1,   122,    -1,    -1,    -1,   126,
     127,   128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     137,   138,   139,    -1,   141,   142,   143,    -1,    -1,    -1,
      -1,    -1,    -1,   150,   151,    -1,    -1,    -1,    -1,   156,
     157,   158,   159,   160,   161,   162,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   172,    -1,    -1,    -1,   176,
     177,   178,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,
      -1,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,    -1,    -1,   201,   202,    -1,    -1,   205,   206,
      -1,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,   251,   252,   253,    -1,   255,   256,
     257,   258,   259,   260,    -1,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,    14,    -1,    -1,    -1,    18,
      -1,    -1,    -1,    -1,    -1,    -1,    25,    26,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    -1,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    -1,    -1,    85,    -1,    87,    88,
      89,    90,    -1,    -1,    93,    94,    95,    -1,    -1,    -1,
      99,    -1,    -1,    -1,    -1,   104,   105,   106,    -1,    -1,
     109,   110,    -1,    -1,    -1,    -1,    -1,    -1,   117,   118,
     119,   120,    -1,   122,    -1,    -1,    -1,   126,   127,   128,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,   138,
     139,    -1,   141,   142,   143,    -1,    -1,    -1,    -1,    -1,
      -1,   150,   151,    -1,    -1,    -1,    -1,   156,   157,   158,
     159,   160,   161,   162,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   172,    -1,    -1,    -1,   176,    -1,   178,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,    -1,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
      -1,    -1,   201,   202,    -1,    -1,   205,   206,    -1,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,   251,   252,   253,    -1,   255,   256,   257,   258,
     259,   260,    -1,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,    16,    -1,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    25,    26,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      -1,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      -1,    -1,    85,    -1,    87,    88,    89,    90,    -1,    -1,
      93,    94,    95,    -1,    -1,    -1,    99,    -1,    -1,    -1,
      -1,   104,   105,   106,    -1,    -1,   109,   110,    -1,    -1,
      -1,    -1,    -1,    -1,   117,   118,   119,   120,    -1,   122,
      -1,    -1,    -1,   126,   127,   128,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   137,   138,   139,    -1,   141,   142,
     143,    -1,    -1,    -1,    -1,    -1,    -1,   150,   151,    -1,
      -1,    -1,    -1,   156,   157,   158,   159,   160,   161,   162,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   172,
      -1,    -1,    -1,   176,    -1,   178,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   186,    -1,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,    -1,    -1,   201,   202,
      -1,    -1,   205,   206,    -1,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,    -1,   251,   252,
     253,    -1,   255,   256,   257,   258,   259,   260,    -1,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,    18,
      -1,    -1,    -1,    -1,    -1,    -1,    25,    26,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    -1,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    -1,    -1,    85,    -1,    87,    88,
      89,    90,    -1,    -1,    93,    94,    95,    -1,    -1,    -1,
      99,    -1,    -1,    -1,    -1,   104,   105,   106,    -1,    -1,
     109,   110,    -1,    -1,    -1,    -1,    -1,    -1,   117,   118,
     119,   120,    -1,   122,    -1,    -1,    -1,   126,   127,   128,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,   138,
     139,    -1,   141,   142,   143,    -1,    -1,    -1,   147,    -1,
      -1,   150,   151,    -1,    -1,    -1,    -1,   156,   157,   158,
     159,   160,   161,   162,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   172,    -1,    -1,    -1,   176,   177,   178,
     179,    -1,    -1,    -1,    -1,   184,    -1,   186,    -1,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
      -1,    -1,   201,   202,    -1,    -1,   205,   206,    -1,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,   251,   252,   253,    -1,   255,   256,   257,   258,
     259,   260,    -1,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    -1,    -1,
      85,    -1,    87,    88,    89,    90,    -1,    -1,    93,    94,
      95,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,   104,
     105,   106,    -1,    -1,   109,   110,   111,    -1,    -1,    -1,
      -1,    -1,   117,   118,   119,   120,    -1,   122,    -1,    -1,
      -1,   126,   127,   128,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   137,   138,   139,    -1,   141,   142,   143,    -1,
      -1,    -1,   147,    -1,    -1,   150,   151,    -1,    -1,    -1,
      -1,   156,   157,   158,   159,   160,   161,   162,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   172,    -1,    -1,
      -1,   176,    -1,   178,   179,    -1,    -1,    -1,    -1,    -1,
      -1,   186,    -1,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,    -1,    -1,   201,   202,    -1,    -1,
     205,   206,    -1,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,   251,   252,   253,    -1,
     255,   256,   257,   258,   259,   260,    -1,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    -1,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    -1,    -1,    85,    -1,    87,    88,    89,    90,
      -1,    -1,    93,    94,    95,    -1,    -1,    -1,    99,    -1,
      -1,    -1,    -1,   104,   105,   106,    -1,    -1,   109,   110,
      -1,    -1,    -1,    -1,    -1,    -1,   117,   118,   119,   120,
      -1,   122,    -1,    -1,    -1,   126,   127,   128,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   137,   138,   139,    -1,
     141,   142,   143,   144,    -1,    -1,   147,    -1,    -1,   150,
     151,    -1,    -1,    -1,    -1,   156,   157,   158,   159,   160,
     161,   162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   172,    -1,    -1,    -1,   176,    -1,   178,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   186,    -1,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,    -1,    -1,
     201,   202,    -1,    -1,   205,   206,    -1,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
     251,   252,   253,    -1,   255,   256,   257,   258,   259,   260,
      -1,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,    18,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    -1,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    -1,    -1,    85,    -1,
      87,    88,    89,    90,    -1,    -1,    93,    94,    95,    -1,
      -1,    -1,    99,    -1,    -1,    -1,    -1,   104,   105,   106,
      -1,    -1,   109,   110,    -1,    -1,    -1,    -1,    -1,    -1,
     117,   118,   119,   120,    -1,   122,    -1,    -1,    -1,   126,
     127,   128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     137,   138,   139,    -1,   141,   142,   143,   144,    -1,    -1,
     147,    -1,    -1,   150,   151,    -1,    -1,    -1,    -1,   156,
     157,   158,   159,   160,   161,   162,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   172,    -1,    -1,    -1,   176,
      -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,
      -1,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,    -1,    -1,   201,   202,    -1,    -1,   205,   206,
      -1,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,   251,   252,   253,    -1,   255,   256,
     257,   258,   259,   260,    -1,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    25,    26,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      -1,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      -1,    -1,    85,    -1,    87,    88,    89,    90,    -1,    -1,
      93,    94,    95,    -1,    -1,    -1,    99,    -1,    -1,    -1,
      -1,   104,   105,   106,    -1,    -1,   109,   110,    -1,    -1,
      -1,    -1,    -1,    -1,   117,   118,   119,   120,    -1,   122,
      -1,    -1,    -1,   126,   127,   128,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   137,   138,   139,    -1,   141,   142,
     143,    -1,    -1,    -1,    -1,    -1,    -1,   150,   151,    -1,
      -1,    -1,    -1,   156,   157,   158,   159,   160,   161,   162,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   172,
      -1,    -1,    -1,   176,   177,   178,    -1,    -1,    -1,    -1,
      -1,   184,    -1,   186,    -1,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,    -1,    -1,   201,   202,
      -1,    -1,   205,   206,    -1,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,    -1,   251,   252,
     253,    -1,   255,   256,   257,   258,   259,   260,    -1,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,    18,
      -1,    -1,    -1,    -1,    -1,    -1,    25,    26,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    -1,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    -1,    -1,    85,    -1,    87,    88,
      89,    90,    -1,    -1,    93,    94,    95,    -1,    -1,    -1,
      99,    -1,    -1,    -1,    -1,   104,   105,   106,    -1,    -1,
     109,   110,    -1,    -1,    -1,    -1,    -1,    -1,   117,   118,
     119,   120,    -1,   122,    -1,    -1,    -1,   126,   127,   128,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,   138,
     139,    -1,   141,   142,   143,    -1,    -1,    -1,    -1,    -1,
      -1,   150,   151,    -1,    -1,    -1,    -1,   156,   157,   158,
     159,   160,   161,   162,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   172,    -1,    -1,    -1,   176,   177,   178,
      -1,    -1,    -1,    -1,    -1,   184,    -1,   186,    -1,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
      -1,    -1,   201,   202,    -1,    -1,   205,   206,    -1,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,   251,   252,   253,    -1,   255,   256,   257,   258,
     259,   260,    -1,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    -1,    -1,
      85,    -1,    87,    88,    89,    90,    -1,    -1,    93,    94,
      95,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,   104,
     105,   106,    -1,    -1,   109,   110,    -1,    -1,    -1,    -1,
      -1,    -1,   117,   118,   119,   120,    -1,   122,    -1,    -1,
      -1,   126,   127,   128,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   137,   138,   139,    -1,   141,   142,   143,    -1,
      -1,    -1,   147,    -1,    -1,   150,   151,    -1,    -1,    -1,
      -1,   156,   157,   158,   159,   160,   161,   162,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   172,    -1,    -1,
      -1,   176,    -1,   178,   179,    -1,    -1,    -1,    -1,    -1,
      -1,   186,    -1,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,    -1,    -1,   201,   202,    -1,    -1,
     205,   206,    -1,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,   251,   252,   253,    -1,
     255,   256,   257,   258,   259,   260,    -1,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    -1,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    -1,    -1,    85,    -1,    87,    88,    89,    90,
      -1,    -1,    93,    94,    95,    -1,    -1,    -1,    99,    -1,
      -1,    -1,    -1,   104,   105,   106,    -1,    -1,   109,   110,
      -1,    -1,    -1,    -1,    -1,    -1,   117,   118,   119,   120,
      -1,   122,    -1,    -1,    -1,   126,   127,   128,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   137,   138,   139,    -1,
     141,   142,   143,    -1,    -1,    -1,   147,    -1,    -1,   150,
     151,    -1,    -1,    -1,    -1,   156,   157,   158,   159,   160,
     161,   162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   172,    -1,    -1,    -1,   176,    -1,   178,   179,    -1,
      -1,    -1,    -1,    -1,    -1,   186,    -1,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,    -1,    -1,
     201,   202,    -1,    -1,   205,   206,    -1,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
     251,   252,   253,    -1,   255,   256,   257,   258,   259,   260,
      -1,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,    18,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    -1,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    -1,    -1,    85,    -1,
      87,    88,    89,    90,    -1,    -1,    93,    94,    95,    -1,
      -1,    -1,    99,    -1,    -1,    -1,    -1,   104,   105,   106,
      -1,    -1,   109,   110,    -1,    -1,    -1,    -1,    -1,    -1,
     117,   118,   119,   120,    -1,   122,    -1,    -1,    -1,   126,
     127,   128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     137,   138,   139,    -1,   141,   142,   143,    -1,    -1,    -1,
      -1,    -1,    -1,   150,   151,    -1,    -1,    -1,    -1,   156,
     157,   158,   159,   160,   161,   162,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   172,    -1,    -1,    -1,   176,
      -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,
      -1,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,    -1,    -1,   201,   202,    -1,    -1,   205,   206,
      -1,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,   251,   252,   253,    -1,   255,   256,
     257,   258,   259,   260,    -1,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  xquery_parser::yystos_[] =
  {
         0,    10,    17,    18,    20,    25,    26,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    98,    99,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   115,   117,   118,   119,   120,
     122,   126,   127,   128,   129,   130,   137,   138,   139,   140,
     141,   142,   143,   147,   148,   149,   150,   151,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   166,   167,   170,
     171,   172,   176,   178,   179,   180,   182,   183,   184,   186,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   201,   202,   203,   205,   206,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   251,   252,
     253,   255,   256,   257,   258,   259,   260,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     332,   333,   334,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   347,   348,   353,   356,   359,   362,   363,
     365,   370,   371,   372,   373,   374,   383,   384,   386,   387,
     388,   393,   395,   397,   398,   399,   404,   425,   428,   431,
     432,   433,   434,   436,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,   449,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   482,   483,   484,   498,   499,   501,   502,
     503,   504,   505,   506,   507,   515,   516,   517,   518,   519,
     520,   521,   522,   523,   524,   527,   528,   529,   530,   535,
     536,   537,   538,   539,   540,   543,   549,   550,   551,    28,
      29,    31,    32,    34,    40,    48,    50,    51,    58,    60,
      68,    72,   104,   105,   106,   151,   160,   192,   211,   221,
     253,   279,   280,   281,   282,   283,   285,   286,   287,   288,
     289,   294,   295,   354,   355,   375,   376,   151,   144,   147,
     144,   147,    25,    26,    30,    35,    36,    37,    38,    39,
      40,    41,    42,    44,    52,    54,    57,    59,    62,    65,
      67,    69,    90,   126,   144,   147,   160,   192,   205,   215,
     216,   217,   219,   220,   227,   229,   230,   231,   232,   235,
     236,   238,   549,   144,    61,    66,   111,   390,   147,   364,
     147,    26,    55,   111,    39,    14,   144,   147,   548,   549,
     147,   111,   111,   144,   147,   147,    87,   144,   212,   213,
     144,   147,   549,    30,    37,    54,    65,    90,   466,   549,
     549,   111,   177,   384,   549,   144,   548,    16,   549,   549,
     458,   144,    21,   204,   206,   216,   218,   147,   216,   218,
     216,   216,   221,   111,   144,   366,   233,   233,   234,   147,
     144,   111,   318,     0,   320,   321,    25,    42,   323,   383,
     181,   181,   100,   181,   385,    33,    39,    44,    52,    64,
     159,   162,   176,   202,   389,   394,   395,   396,   413,   414,
     418,   400,   401,   549,   158,    85,   123,   131,   132,   134,
     142,   146,   148,   153,   169,   193,   194,   195,   196,   197,
     198,   450,   451,   241,   149,   166,   189,   110,   137,   150,
     184,   191,   200,   127,   141,    43,   190,    94,    95,   149,
     166,   449,   144,   455,   458,   182,   183,   145,   470,   471,
     466,   470,   466,   147,   470,   136,   147,    20,   547,   172,
     186,   172,   186,   157,   172,   375,   549,   375,   549,   160,
     192,    40,   377,   376,    40,   378,   549,   143,   111,   352,
      37,    40,    72,    99,   159,   548,   212,   213,   214,   292,
     293,   238,   578,   549,   285,   549,   290,   290,   292,   293,
     296,   279,   287,   355,   548,   384,   177,   384,    37,    57,
     177,   523,   524,   384,   177,   184,   549,   144,   387,   276,
     276,   111,   408,   111,   177,   379,   380,   144,   381,   384,
     151,   547,   106,   151,   346,   547,   405,   407,   549,   111,
     384,    20,   177,   548,   144,   549,   549,   426,   427,   549,
     384,   177,   384,   525,   549,   384,   144,   144,   384,   177,
     184,   549,   144,   426,   177,    27,   486,   487,   488,   384,
       7,   165,    15,   177,   384,   204,    20,   387,   387,   177,
     387,   387,   387,   387,   222,   541,   542,   549,   367,   387,
     387,   384,   406,   412,   549,   325,   326,    25,   327,   387,
     386,   111,   159,   161,   161,   387,   387,   100,    87,    89,
     138,   265,   402,   403,   509,   433,   434,   436,   436,   436,
     436,   435,   436,   436,   436,    65,   440,   440,   439,   441,
     441,   441,   441,   442,   442,   443,   443,   222,    87,    87,
      87,   174,   384,   458,   458,   384,   471,   177,   387,   481,
     140,   177,   481,   100,   100,   364,    20,   549,   549,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,   329,
     330,   331,    87,   128,   133,   349,   350,   351,   549,   128,
     133,   151,   151,   329,   547,   118,   123,    47,    50,    93,
     243,   256,   258,   269,   270,   271,   273,   275,   579,   580,
     581,   582,   583,   584,   591,   597,   598,   238,    87,   228,
     358,   291,   549,   549,   549,   123,   174,   174,   177,   177,
     174,   100,   177,   100,   177,   174,   384,   174,   549,    49,
     208,   246,   391,   392,   549,    87,   100,   177,   384,   177,
     548,    89,    37,   548,   547,    89,   100,   133,   403,   509,
     174,   177,   177,   174,   384,   177,   133,   100,   178,   138,
     509,   174,   177,   144,   174,   384,   384,   174,   100,   177,
     100,   177,   174,   384,   178,   549,   487,   488,   121,   187,
     174,   174,   122,   181,    87,   209,   210,   224,    87,   209,
     210,   224,    87,   228,   216,   100,   226,   133,    25,   368,
     384,   177,   174,    38,   100,   181,   106,   181,   549,   161,
     387,   419,   420,   111,   415,   416,   111,    40,   143,   147,
     201,   510,   512,   514,   515,   531,   532,   533,   534,   549,
     111,   387,   111,   138,   403,   138,   138,   402,   403,   436,
     144,   147,   251,   454,   473,   552,   555,   556,   557,   558,
     559,   563,   565,   567,   568,   510,   510,   508,   514,   508,
     174,   175,   100,   177,   177,   139,   156,   139,   156,   128,
     144,   382,   364,   364,   330,   123,   512,   351,   387,   509,
     133,   387,   547,   547,   119,   120,   547,   269,   270,   271,
     275,   549,   255,   266,   255,   266,    20,   278,    89,   106,
     147,   585,   588,   579,    30,    36,    54,    65,    90,   216,
     357,   515,   283,   284,   218,   291,   300,    87,   358,   291,
     547,   144,   525,   526,   549,   525,   526,   174,   138,   509,
     246,    46,    53,    70,   111,   402,   409,   410,   411,   392,
     509,   510,   380,    87,   174,   188,   123,   345,   547,   151,
     123,    89,   345,   111,   387,   133,   133,   403,   144,   174,
     387,   111,   387,   387,   138,    93,   429,   430,   384,   174,
     174,   144,   525,   525,   174,   387,    27,   488,   121,   187,
       8,     9,    96,   114,   116,   185,   381,   483,   485,   496,
     497,   500,    20,   223,   225,   387,   387,   387,   223,   225,
     387,   387,   387,   387,   387,   387,   111,   387,   387,   352,
     369,   100,   181,   174,   366,   237,   544,   545,   144,   111,
     419,    88,    99,   109,   118,   421,   422,   423,   424,   100,
     549,   100,   401,   147,   147,   512,   147,   135,   166,   184,
     511,   549,   549,   387,   138,   387,   387,   138,   403,   138,
     384,   552,   559,   144,   277,   437,   604,    89,   160,   244,
     245,   247,   254,   264,   276,   553,   554,   573,   574,   575,
     576,   599,   602,   250,   252,   560,   578,   259,   564,   600,
     239,   240,   262,   569,   570,   135,   387,   384,   128,   366,
     128,   144,   527,   350,   387,   278,    20,    89,   106,   147,
     592,    20,   585,   358,   511,   218,   218,   456,   279,   298,
     357,   218,   181,   174,   384,   177,   177,   135,   177,   177,
     387,   138,   111,   111,   387,   549,   411,    70,   510,   387,
     547,   100,   345,   407,   387,   387,   133,   174,   384,   427,
     387,   111,   510,   106,   430,   174,   174,   384,   177,   177,
     123,   185,   485,     6,   549,   185,   496,   181,   224,   224,
     224,   224,   228,   542,   176,   133,   369,   467,   546,   545,
     387,   412,   547,   119,   120,   423,   424,   424,   420,    99,
     417,   416,   177,   184,   510,   513,   177,   177,   177,   387,
     387,   138,   387,   174,   177,   552,   566,   242,   208,   246,
     260,   267,   603,    89,   248,   249,   601,   242,   556,   603,
     439,   573,   557,   138,   274,   561,   562,   601,   278,   572,
      71,   571,   174,   386,    20,   127,   191,   594,   595,   596,
      20,   593,   594,   263,   589,   586,   587,   588,   161,   549,
     249,   358,   456,   174,   387,   549,   549,   410,   387,   117,
      89,   547,   387,   174,   549,   176,   111,   176,   174,   488,
     549,   185,   488,   549,   387,   387,   387,   387,   387,   387,
     387,   147,   200,   382,   174,   424,   547,    87,   177,   100,
     177,   387,   174,   441,    45,   120,   439,   439,   261,   268,
     278,   577,   577,   558,   144,   272,   174,   592,   592,   596,
     100,   177,    20,   590,   601,   177,   100,   360,   361,   456,
     111,   216,   299,   279,   161,    46,   387,   345,    87,   387,
     549,   387,    86,   173,   489,   488,   549,   187,   488,   111,
     467,   510,   510,    87,   439,   439,   189,   384,    20,   257,
     588,   100,    87,   549,   111,   216,   549,   360,   111,   510,
     176,     4,   124,   492,   493,   495,   497,    19,   125,   490,
     491,   494,   497,   187,   488,   187,   549,   510,   439,   174,
     361,   514,   297,   549,   111,   216,   549,   176,   387,    86,
     124,   495,   173,   125,   494,   187,   100,   177,   424,   387,
     297,   549,   111,   387,   111,   382,   285,   297,   549,   549,
     298,   387,   298,   100,   177,   456,   456,   111,   382,   189,
     549,   279,   177,   549,   382,   216,   111,   549,   298,   456
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
     565,   566,   567,   568,   569,   570
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   316,   317,   317,   318,   318,   318,   318,   319,   319,
     320,   320,   321,   321,   322,   323,   323,   323,   324,   324,
     325,   325,   326,   326,   326,   326,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   328,   328,   329,   329,   330,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     332,   332,   332,   332,   332,   332,   332,   332,   333,   333,
     334,   335,   335,   336,   336,   337,   338,   339,   339,   340,
     340,   341,   341,   341,   341,   342,   343,   344,   344,   344,
     344,   345,   345,   346,   346,   347,   347,   347,   347,   348,
     349,   349,   350,   350,   350,   351,   352,   352,   353,   353,
     353,   354,   354,   355,   355,   355,   355,   355,   355,   355,
     355,   355,   355,   355,   355,   355,   355,   356,   356,   356,
     356,   356,   356,   356,   356,   357,   357,   358,   358,   359,
     359,   360,   360,   361,   361,   362,   362,   362,   362,   363,
     363,   364,   364,   364,   364,   365,   366,   367,   367,   368,
     368,   369,   369,   370,   371,   372,   373,   373,   374,   374,
     374,   375,   375,   375,   375,   376,   376,   377,   377,   378,
     378,   379,   379,   380,   380,   381,   382,   383,   384,   384,
     385,   385,   386,   386,   387,   387,   387,   387,   387,   387,
     387,   387,   387,   387,   387,   387,   387,   387,   387,   387,
     387,   388,   389,   390,   390,   391,   391,   391,   392,   392,
     393,   393,   394,   395,   395,   395,   396,   396,   396,   396,
     396,   397,   397,   398,   398,   399,   400,   400,   401,   401,
     401,   401,   401,   401,   401,   401,   402,   403,   404,   405,
     405,   406,   406,   407,   407,   407,   407,   408,   408,   409,
     409,   409,   410,   410,   410,   411,   411,   411,   412,   413,
     414,   415,   415,   416,   416,   417,   418,   418,   419,   419,
     420,   420,   421,   421,   421,   421,   421,   421,   421,   422,
     422,   423,   423,   424,   425,   425,   426,   426,   427,   427,
     428,   428,   429,   429,   430,   430,   431,   432,   432,   433,
     433,   434,   434,   434,   434,   434,   435,   434,   434,   434,
     434,   436,   436,   437,   437,   438,   438,   439,   439,   439,
     440,   440,   440,   440,   440,   441,   441,   441,   442,   442,
     442,   443,   443,   444,   444,   445,   445,   446,   446,   447,
     447,   448,   448,   448,   448,   449,   449,   449,   450,   450,
     450,   450,   450,   450,   451,   451,   451,   452,   452,   452,
     452,   453,   453,   454,   454,   455,   455,   456,   456,   456,
     456,   457,   458,   458,   458,   459,   459,   460,   460,   460,
     460,   461,   461,   462,   462,   462,   462,   462,   462,   462,
     463,   463,   464,   464,   465,   465,   465,   465,   465,   466,
     466,   467,   467,   468,   468,   468,   469,   469,   469,   469,
     470,   470,   471,   472,   472,   472,   472,   472,   472,   472,
     472,   472,   473,   473,   474,   474,   474,   475,   476,   476,
     477,   478,   479,   480,   480,   481,   481,   482,   482,   483,
     483,   483,   484,   484,   484,   484,   484,   484,   485,   485,
     486,   486,   487,   488,   488,   489,   489,   490,   490,   491,
     491,   491,   491,   492,   492,   493,   493,   493,   493,   494,
     494,   495,   495,   496,   496,   496,   496,   497,   497,   497,
     497,   498,   498,   499,   499,   500,   501,   501,   501,   501,
     501,   501,   502,   503,   503,   503,   503,   504,   504,   504,
     504,   505,   506,   507,   507,   507,   507,   508,   508,   509,
     510,   510,   510,   511,   511,   511,   512,   512,   512,   512,
     512,   513,   513,   514,   515,   515,   515,   515,   515,   515,
     515,   515,   515,   516,   517,   517,   517,   518,   519,   520,
     520,   520,   521,   521,   521,   521,   521,   522,   523,   523,
     523,   523,   523,   523,   523,   524,   525,   526,   527,   528,
     528,   529,   530,   531,   531,   532,   533,   533,   534,   535,
     535,   535,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   537,   537,   538,   538,   539,   540,   541,   541,
     542,   543,   544,   544,   545,   545,   545,   545,   546,   546,
     547,   548,   548,   549,   549,   550,   550,   551,   551,   551,
     551,   551,   551,   551,   551,   551,   551,   551,   551,   551,
     551,   551,   551,   551,   551,   551,   551,   551,   551,   551,
     551,   551,   551,   551,   551,   551,   551,   551,   551,   551,
     551,   551,   551,   551,   551,   551,   551,   551,   551,   551,
     551,   551,   551,   551,   551,   551,   551,   551,   551,   551,
     551,   551,   551,   551,   551,   551,   551,   551,   551,   551,
     551,   551,   551,   551,   551,   551,   551,   551,   551,   551,
     551,   551,   551,   551,   551,   551,   551,   551,   551,   551,
     551,   551,   551,   551,   551,   551,   551,   551,   551,   551,
     551,   551,   551,   551,   551,   551,   551,   551,   551,   551,
     551,   551,   551,   551,   551,   551,   551,   551,   551,   551,
     551,   551,   551,   551,   551,   551,   551,   551,   551,   551,
     551,   551,   551,   551,   551,   551,   551,   551,   551,   551,
     551,   551,   551,   551,   551,   551,   551,   551,   551,   551,
     551,   551,   551,   551,   551,   551,   551,   551,   551,   551,
     551,   551,   551,   551,   551,   551,   551,   551,   551,   551,
     551,   551,   551,   551,   551,   551,   551,   551,   551,   551,
     551,   551,   551,   551,   551,   551,   551,   551,   551,   551,
     551,   551,   551,   551,   551,   551,   551,   551,   551,   551,
     551,   551,   551,   551,   551,   551,   551,   551,   551,   552,
     553,   553,   554,   554,   555,   555,   556,   556,   557,   557,
     558,   558,   559,   560,   560,   561,   561,   562,   563,   563,
     563,   564,   564,   565,   566,   566,   567,   568,   568,   569,
     569,   570,   570,   570,   571,   571,   572,   572,   573,   573,
     573,   573,   573,   574,   575,   576,   577,   577,   577,   578,
     578,   579,   579,   579,   579,   579,   579,   579,   579,   580,
     580,   580,   580,   581,   581,   582,   583,   583,   584,   584,
     584,   585,   585,   586,   586,   587,   587,   588,   589,   589,
     590,   590,   591,   591,   591,   592,   592,   593,   593,   594,
     594,   595,   595,   596,   596,   597,   598,   598,   599,   599,
     599,   600,   601,   601,   601,   601,   602,   602,   603,   603,
     604
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  xquery_parser::yyr2_[] =
  {
         0,     2,     1,     2,     1,     2,     1,     2,     4,     6,
       2,     1,     1,     2,     6,     2,     2,     4,     1,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     1,     2,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     3,     3,     5,     5,     4,     3,     3,     3,     5,
       5,     5,     5,     5,     5,     4,     3,     3,     4,     5,
       6,     1,     3,     3,     3,     3,     6,     5,     8,     4,
       3,     1,     1,     1,     2,     2,     2,     3,     5,     4,
       6,     1,     2,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     2,     1,     2,     2,     2,     3,     4,     5,
       6,     4,     5,     6,     7,     1,     2,     3,     3,     8,
       9,     1,     3,     3,     4,    11,    14,    13,    22,     3,
       3,     2,     3,     4,     5,     2,     4,     3,     0,     3,
       2,     1,     3,     5,     3,     5,     2,     2,     2,     3,
       3,     1,     2,     2,     2,     4,     4,     4,     4,     6,
       4,     1,     3,     2,     3,     3,     3,     1,     1,     2,
       1,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     1,     1,     2,     4,     3,
       5,     4,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     3,     2,     1,     4,     3,     4,
       4,     5,     4,     5,     5,     6,     3,     3,     3,     1,
       4,     1,     4,     3,     4,     4,     5,     4,     5,     1,
       2,     3,     1,     2,     1,     6,     3,     3,     1,     2,
       3,     1,     3,     2,     3,     2,     3,     4,     1,     3,
       1,     2,     1,     1,     1,     2,     2,     2,     3,     1,
       1,     2,     2,     2,     5,     5,     1,     4,     3,     4,
       8,    10,     1,     2,     4,     7,     8,     1,     3,     1,
       3,     1,     3,     3,     3,     3,     0,     4,     3,     3,
       3,     1,     5,     0,     1,     1,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     4,     1,     4,     1,     4,     1,     4,     1,
       2,     1,     1,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     5,     5,
       6,     3,     4,     1,     2,     3,     2,     1,     2,     2,
       1,     1,     1,     3,     3,     1,     1,     1,     2,     1,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     3,     4,
       1,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     3,
       1,     4,     4,     3,     4,     1,     3,     1,     1,     1,
       1,     1,     4,     5,     8,     9,     9,    10,     1,     2,
       1,     2,     6,     0,     1,     3,     3,     0,     1,     1,
       1,     2,     2,     0,     1,     1,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     2,     3,     3,     2,     1,     1,     1,     1,
       1,     1,     4,     4,     5,     6,     7,     4,     5,     6,
       7,     4,     4,     4,     5,     6,     7,     1,     2,     2,
       1,     2,     3,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     4,     4,     3,     3,     3,
       4,     4,     3,     4,     6,     4,     6,     3,     3,     4,
       6,     6,     4,     6,     6,     4,     1,     2,     1,     1,
       1,     3,     3,     1,     1,     4,     5,     6,     3,     3,
       3,     3,     5,     7,     7,     5,     5,     5,     7,     7,
       5,     5,     3,     3,     5,     7,     5,     7,     1,     4,
       3,     5,     1,     2,     3,     7,    10,    13,     1,     3,
       1,     1,     1,     1,     1,     7,     4,     1,     1,     1,
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       0,     1,     1,     2,     1,     3,     1,     3,     1,     4,
       1,     2,     3,     0,     1,     0,     1,     4,     2,     3,
       1,     0,     1,     4,     0,     1,     2,     1,     3,     0,
       1,     2,     2,     1,     0,     1,     0,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     1,     1,     1,     2,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     1,     1,     2,     2,     3,     1,     2,     2,     5,
       2,     1,     1,     0,     1,     1,     3,     4,     0,     2,
       0,     2,     4,     4,     3,     2,     3,     1,     3,     0,
       1,     1,     2,     2,     2,     2,     1,     2,     2,     2,
       2,     3,     2,     3,     3,     4,     2,     2,     1,     1,
       3
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
  "\"'*:QName'\"", "\"'QName_sval'\"", "\"'quote attribute content'\"",
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
  "\"'text'\"", "\"'tumbling'\"", "\"'typeswitch'\"", "\"'updating'\"",
  "\"'validate'\"", "\"'when'\"", "\"'word'\"", "\"'decimal-format'\"",
  "\"'decimal-separator'\"", "\"'grouping-separator'\"", "\"'infinity'\"",
  "\"'minus-sign'\"", "\"'NaN'\"", "\"'percent'\"", "\"'per-mille'\"",
  "\"'zero-digit'\"", "\"'digit'\"", "\"'pattern-separator'\"",
  "\"'ancestor::'\"", "\"'ancestor-or-self::'\"", "\"'and'\"", "\"'''\"",
  "\"'as'\"", "\"'ascending'\"", "\"'at'\"", "\"'attribute'\"",
  "\"'attribute::'\"", "\"'@'\"", "\"'case'\"", "\"'castable'\"",
  "\"'cast'\"", "\"'CDATA[['\"", "\"']]'\"", "\"'child::'\"",
  "\"'collation'\"", "\"','\"", "\"'(:'\"", "\"':)'\"", "\"'DECIMAL'\"",
  "\"'context'\"", "\"'variable'\"", "\"'default'\"", "\"'descendant::'\"",
  "\"'descendant-or-self::'\"", "\"'descending'\"", "\"'div'\"", "\"'$'\"",
  "\"'.'\"", "\"'..'\"", "\"'{{'\"", "\"'DOUBLE'\"", "\"'<double {>'\"",
  "\"'else'\"", "\"'empty'\"", "\"'greatest'\"", "\"'least'\"", "\"'/>'\"",
  "\"'encoding'\"", "\"'='\"", "\"''''\"", "\"'\\\"\\\"'\"", "\"'every'\"",
  "\"'except'\"", "\"'external'\"", "\"'following::'\"",
  "\"'following-sibling::'\"", "\"'follows'\"", "\"'>='\"", "\"':='\"",
  "\"'>'\"", "\"'?'\"", "\"'#'\"", "\"'idiv'\"", "\"'in'\"",
  "\"'inherit'\"", "\"'INTEGER'\"", "\"'intersect'\"", "\"'is'\"",
  "\"'item'\"", "\"'{'\"", "\"'['\"", "\"'<='\"", "\"'('\"", "\"'<'\"",
  "\"'-'\"", "\"'mod'\"", "\"'namespace'\"", "\"'nan'\"", "\"'!='\"",
  "\"'nodecomp'\"", "\"'?""?'\"", "\"'<no inherit>'\"",
  "\"'<no preserve>'\"", "\"'or'\"", "\"'order'\"", "\"'ordered'\"",
  "\"'by'\"", "\"'group'\"", "\"'parent::'\"", "\"'<?'\"", "\"'?>'\"",
  "\"'+'\"", "\"'PRAGMA BEGIN'\"", "\"'PRAGMA END'\"", "\"'<<'\"",
  "\"'preceding::'\"", "\"'preceding-sibling::'\"", "\"'preserve'\"",
  "\"'\\\"'\"", "\"'}'\"", "\"']'\"", "\"'return'\"", "\"')'\"",
  "\"'satisfies'\"", "\"'<schema attribute ('\"", "\"'self::'\"",
  "\"';'\"", "\"'/'\"", "\"'//'\"", "\"'*'\"", "\"</ (start tag end)\"",
  "\"'strip'\"", "\"> (tag end)\"", "\"'then'\"", "\"'to'\"",
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
  "STEP_REDUCE", "$accept", "Module", "ModuleWithoutBOM", "VersionDecl",
  "MainModule", "LibraryModule", "ModuleDecl", "Prolog", "SIND_DeclList",
  "VFO_DeclList", "SIND_Decl", "VFO_Decl", "DecimalFormatDecl",
  "DecimalFormatParamList", "DecimalFormatParam", "DecimalFormatParamName",
  "Setter", "Import", "NamespaceDecl", "BoundarySpaceDecl",
  "DefaultNamespaceDecl", "OptionDecl", "FTOptionDecl", "OrderingModeDecl",
  "EmptyOrderDecl", "CopyNamespacesDecl", "DefaultCollationDecl",
  "BaseURIDecl", "SchemaImport", "URILiteralList", "SchemaPrefix",
  "ModuleImport", "CtxItemDecl", "CtxItemDecl2", "CtxItemDecl3",
  "CtxItemDecl4", "VarNameAndType", "VarDecl", "DeclPropertyList",
  "DeclProperty", "CollectionDecl", "CollectionTypeDecl", "NodeModifier",
  "IndexDecl", "IndexKeyList", "IndexKeySpec", "IntegrityConstraintDecl",
  "ConstructionDecl", "FunctionSig", "BlockExpr", "Block", "BlockDecls",
  "BlockVarDeclList", "BlockVarDecl", "AssignExpr", "ExitExpr",
  "WhileExpr", "FlowCtlStatement", "FunctionDecl", "FunctionDecl2",
  "FunctionDecl3", "FunctionDecl4", "FunctionDeclUpdating", "ParamList",
  "Param", "EnclosedExpr", "BracedExpr", "QueryBody", "Expr", "ApplyExpr",
  "ConcatExpr", "ExprSingle", "FLWORExpr", "ReturnExpr", "WindowType",
  "FLWORWinCondType", "FLWORWinCond", "WindowClause", "CountClause",
  "ForLetWinClause", "FLWORClause", "FLWORClauseList", "ForDollar",
  "ForClause", "VarInDeclList", "VarInDecl", "PositionalVar", "FTScoreVar",
  "LetClause", "VarGetsDeclList", "EvalVarDeclList", "VarGetsDecl",
  "WindowVarDecl", "WindowVars", "WindowVars3", "WindowVars2",
  "EvalVarDecl", "WhereClause", "GroupByClause", "GroupSpecList",
  "GroupSpec", "GroupCollationSpec", "OrderByClause", "OrderSpecList",
  "OrderSpec", "OrderModifier", "OrderDirSpec", "OrderEmptySpec",
  "OrderCollationSpec", "QuantifiedExpr", "QVarInDeclList", "QVarInDecl",
  "TypeswitchExpr", "CaseClauseList", "CaseClause", "IfExpr", "OrExpr",
  "AndExpr", "ComparisonExpr", "$@1", "FTContainsExpr",
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
  "CatchListExpr", "CatchExpr", "NameTestList", "URI_LITERAL", "NCNAME",
  "QNAME", "EvalExpr", "KEYWORD", "FTSelection", "opt_FTPosFilter_list",
  "FTPosFilter_list", "FTOr", "FTAnd", "FTMildNot", "FTUnaryNot",
  "FTPrimaryWithOptions", "opt_FTMatchOptions", "opt_FTWeight", "FTWeight",
  "FTPrimary", "opt_FTTimes", "FTExtensionSelection", "opt_FTSelection",
  "FTWords", "FTWordsValue", "opt_FTAnyallOption", "FTAnyallOption",
  "opt_word", "opt_words", "FTPosFilter", "FTOrder", "FTWindow",
  "FTDistance", "FTUnit", "FTMatchOptions", "FTMatchOption",
  "FTCaseOption", "FTDiacriticsOption", "FTExtensionOption",
  "FTStemOption", "FTThesaurusOption", "FTThesaurusID_or_default",
  "opt_FTThesaurus_list", "FTThesaurus_list", "FTThesaurusID",
  "opt_relationship", "opt_levels", "FTStopWordOption", "FTStopWords",
  "STRING_LITERAL_list", "opt_FTStopWordsInclExcl_list",
  "FTStopWordsInclExcl_list", "FTStopWordsInclExcl", "FTLanguageOption",
  "FTWildCardOption", "FTContent", "FTTimes", "FTRange", "FTScope",
  "FTBigUnit", "FTIgnoreOption", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const xquery_parser::rhs_number_type
  xquery_parser::yyrhs_[] =
  {
       317,     0,    -1,   318,    -1,   302,   318,    -1,   320,    -1,
     319,   320,    -1,   321,    -1,   319,   321,    -1,   205,   206,
      20,   181,    -1,   205,   206,    20,   122,    20,   181,    -1,
     323,   383,    -1,   383,    -1,   322,    -1,   322,   323,    -1,
      26,   151,   548,   123,   547,   181,    -1,   324,   181,    -1,
     325,   181,    -1,   324,   181,   325,   181,    -1,   326,    -1,
     324,   181,   326,    -1,   327,    -1,   325,   181,   327,    -1,
     332,    -1,   333,    -1,   334,    -1,   336,    -1,   353,    -1,
     356,    -1,   348,    -1,   328,    -1,   338,    -1,   374,    -1,
     359,    -1,   362,    -1,   337,    -1,    25,   106,    72,   329,
      -1,    25,    72,   549,   329,    -1,   330,    -1,   329,   330,
      -1,   331,   123,   527,    -1,    73,    -1,    81,    -1,    74,
      -1,    75,    -1,    76,    -1,    77,    -1,    82,    -1,    78,
      -1,    79,    -1,    80,    -1,   335,    -1,   342,    -1,   343,
      -1,   363,    -1,   339,    -1,   340,    -1,   341,    -1,   535,
      -1,   344,    -1,   347,    -1,    25,   151,   548,   123,   547,
      -1,    25,    29,   172,    -1,    25,    29,   186,    -1,    25,
     106,    37,   151,   547,    -1,    25,   106,    40,   151,   547,
      -1,    25,    50,   549,    20,    -1,    25,   253,   578,    -1,
      25,    51,   160,    -1,    25,    51,   192,    -1,    25,   106,
     159,   118,   119,    -1,    25,   106,   159,   118,   120,    -1,
      25,    32,   172,   100,   139,    -1,    25,    32,   172,   100,
     156,    -1,    25,    32,   157,   100,   139,    -1,    25,    32,
     157,   100,   156,    -1,    25,   106,    99,   547,    -1,    25,
      28,   547,    -1,    42,    55,   547,    -1,    42,    55,   346,
     547,    -1,    42,    55,   547,    89,   345,    -1,    42,    55,
     346,   547,    89,   345,    -1,   547,    -1,   345,   100,   547,
      -1,   151,   548,   123,    -1,   106,    37,   151,    -1,    42,
      26,   547,    -1,    42,    26,   151,   548,   123,   547,    -1,
      42,    26,   547,    89,   345,    -1,    42,    26,   151,   548,
     123,   547,    89,   345,    -1,    25,   104,   143,   349,    -1,
      87,   512,   350,    -1,   350,    -1,   351,    -1,   128,    -1,
     128,   351,    -1,   133,   387,    -1,   111,   549,    -1,   111,
     549,   509,    -1,    25,   105,   352,   133,   387,    -1,    25,
     105,   352,   128,    -1,    25,   105,   352,   128,   133,   387,
      -1,   355,    -1,   354,   355,    -1,   280,    -1,   281,    -1,
     282,    -1,   283,    -1,   160,    -1,   192,    -1,   221,   293,
      -1,   221,   292,    -1,   294,   293,    -1,   294,   292,    -1,
     285,    -1,   286,   285,    -1,   289,   290,    -1,   288,   290,
      -1,    25,   279,   549,    -1,    25,   279,   549,   358,    -1,
      25,   279,   549,    87,   357,    -1,    25,   279,   549,    87,
     357,   358,    -1,    25,   354,   279,   549,    -1,    25,   354,
     279,   549,   358,    -1,    25,   354,   279,   549,    87,   357,
      -1,    25,   354,   279,   549,    87,   357,   358,    -1,   515,
      -1,   515,   511,    -1,   228,   284,   218,    -1,   228,   283,
     218,    -1,    25,   287,   549,   291,   218,   456,   161,   360,
      -1,    25,   354,   287,   549,   291,   218,   456,   161,   360,
      -1,   361,    -1,   360,   100,   361,    -1,   456,    87,   514,
      -1,   456,    87,   514,   424,    -1,    25,   295,   296,   549,
     291,   279,   549,   111,   549,   297,   387,    -1,    25,   295,
     296,   549,   291,   279,   549,   216,   111,   549,   297,   285,
     298,   456,    -1,    25,   295,   296,   549,   291,   279,   549,
     299,   216,   111,   549,   297,   387,    -1,    25,   295,   296,
     549,   300,   298,   249,   279,   549,   216,   111,   549,   298,
     456,   189,   279,   549,   216,   111,   549,   298,   456,    -1,
      25,    31,   172,    -1,    25,    31,   186,    -1,   147,   177,
      -1,   147,   379,   177,    -1,   147,   177,    87,   510,    -1,
     147,   379,   177,    87,   510,    -1,   229,   366,    -1,   144,
     367,   384,   174,    -1,   367,   368,   181,    -1,    -1,   368,
     100,   369,    -1,    25,   369,    -1,   352,    -1,   352,   133,
     387,    -1,    59,   111,   549,   133,   387,    -1,   232,   234,
     387,    -1,   235,   147,   387,   177,   366,    -1,   230,   233,
      -1,   231,   233,    -1,    25,   375,    -1,    25,    48,   375,
      -1,    25,    34,   375,    -1,   376,    -1,    60,   376,    -1,
      68,   378,    -1,    58,   377,    -1,    40,   549,   364,   382,
      -1,    40,   549,   364,   128,    -1,    40,   549,   364,   366,
      -1,    40,   549,   364,   128,    -1,    40,   549,   364,   144,
     386,   174,    -1,    40,   549,   364,   128,    -1,   380,    -1,
     379,   100,   380,    -1,   111,   549,    -1,   111,   549,   509,
      -1,   144,   384,   174,    -1,   144,   384,   174,    -1,   384,
      -1,   386,    -1,   386,   385,    -1,   181,    -1,   385,   386,
     181,    -1,   387,    -1,   386,   100,   387,    -1,   388,    -1,
     425,    -1,   428,    -1,   431,    -1,   432,    -1,   536,    -1,
     537,    -1,   539,    -1,   538,    -1,   540,    -1,   543,    -1,
     550,    -1,   371,    -1,   372,    -1,   373,    -1,   370,    -1,
     365,    -1,   397,   389,    -1,   176,   387,    -1,    61,   276,
      -1,    66,   276,    -1,   208,    -1,   246,    -1,    49,   246,
      -1,   391,   409,    70,   387,    -1,   391,    70,   387,    -1,
      39,   390,   408,   392,   392,    -1,    39,   390,   408,   392,
      -1,    33,   111,   549,    -1,   399,    -1,   404,    -1,   393,
      -1,   395,    -1,   413,    -1,   418,    -1,   414,    -1,   394,
      -1,   395,    -1,   397,   396,    -1,    39,   111,    -1,    52,
      39,   111,    -1,   398,   400,    -1,   401,    -1,   400,   100,
     111,   401,    -1,   549,   138,   387,    -1,   549,   509,   138,
     387,    -1,   549,   402,   138,   387,    -1,   549,   509,   402,
     138,   387,    -1,   549,   403,   138,   387,    -1,   549,   509,
     403,   138,   387,    -1,   549,   402,   403,   138,   387,    -1,
     549,   509,   402,   403,   138,   387,    -1,    89,   111,   549,
      -1,   265,   111,   549,    -1,    44,   111,   405,    -1,   407,
      -1,   405,   100,   111,   407,    -1,   412,    -1,   406,   100,
     111,   412,    -1,   549,   133,   387,    -1,   549,   509,   133,
     387,    -1,   549,   403,   133,   387,    -1,   549,   509,   403,
     133,   387,    -1,   111,   549,   138,   387,    -1,   111,   549,
     509,   138,   387,    -1,   410,    -1,   111,   549,    -1,   111,
     549,   410,    -1,   402,    -1,   402,   411,    -1,   411,    -1,
      53,   111,   549,    46,   111,   549,    -1,    46,   111,   549,
      -1,    53,   111,   549,    -1,   549,    -1,   202,   387,    -1,
     162,   161,   415,    -1,   416,    -1,   415,   100,   416,    -1,
     111,   549,    -1,   111,   549,   417,    -1,    99,   547,    -1,
     159,   161,   419,    -1,    64,   159,   161,   419,    -1,   420,
      -1,   419,   100,   420,    -1,   387,    -1,   387,   421,    -1,
     422,    -1,   423,    -1,   424,    -1,   422,   423,    -1,   422,
     424,    -1,   423,   424,    -1,   422,   423,   424,    -1,    88,
      -1,   109,    -1,   118,   119,    -1,   118,   120,    -1,    99,
     547,    -1,    62,   111,   426,   178,   387,    -1,   126,   111,
     426,   178,   387,    -1,   427,    -1,   426,   100,   111,   427,
      -1,   549,   138,   387,    -1,   549,   509,   138,   387,    -1,
      67,   147,   384,   177,   429,   106,   176,   387,    -1,    67,
     147,   384,   177,   429,   106,   111,   549,   176,   387,    -1,
     430,    -1,   429,   430,    -1,    93,   510,   176,   387,    -1,
      93,   111,   549,    87,   510,   176,   387,    -1,    41,   147,
     384,   177,   188,   387,   117,   387,    -1,   433,    -1,   432,
     158,   433,    -1,   434,    -1,   433,    85,   434,    -1,   436,
      -1,   436,   450,   436,    -1,   436,   451,   436,    -1,   436,
     123,   436,    -1,   436,   153,   436,    -1,    -1,   436,   148,
     435,   436,    -1,   436,   146,   436,    -1,   436,   134,   436,
      -1,   436,   132,   436,    -1,   438,    -1,   438,   241,    65,
     552,   437,    -1,    -1,   604,    -1,   439,    -1,   439,   189,
     439,    -1,   440,    -1,   439,   166,   440,    -1,   439,   149,
     440,    -1,   441,    -1,   440,   184,   441,    -1,   440,   110,
     441,    -1,   440,   137,   441,    -1,   440,   150,   441,    -1,
     442,    -1,   441,   191,   442,    -1,   441,   200,   442,    -1,
     443,    -1,   442,   141,   443,    -1,   442,   127,   443,    -1,
     444,    -1,   444,    43,   222,   510,    -1,   445,    -1,   445,
     190,    87,   510,    -1,   446,    -1,   446,    94,    87,   508,
      -1,   447,    -1,   447,    95,    87,   508,    -1,   449,    -1,
     448,   449,    -1,   166,    -1,   149,    -1,   448,   166,    -1,
     448,   149,    -1,   452,    -1,   456,    -1,   453,    -1,   193,
      -1,   198,    -1,   197,    -1,   196,    -1,   195,    -1,   194,
      -1,   142,    -1,   169,    -1,   131,    -1,    69,   144,   384,
     174,    -1,    69,   213,   144,   384,   174,    -1,    69,   212,
     144,   384,   174,    -1,    69,    87,   525,   144,   384,   174,
      -1,   454,   144,   174,    -1,   454,   144,   384,   174,    -1,
     455,    -1,   454,   455,    -1,   167,   549,    15,    -1,   167,
      16,    -1,   457,    -1,   457,   458,    -1,   183,   458,    -1,
     458,    -1,   182,    -1,   459,    -1,   459,   182,   458,    -1,
     459,   183,   458,    -1,   460,    -1,   469,    -1,   461,    -1,
     461,   470,    -1,   464,    -1,   464,   470,    -1,   462,   466,
      -1,   463,    -1,    98,    -1,   107,    -1,    91,    -1,   180,
      -1,   108,    -1,   130,    -1,   129,    -1,   466,    -1,    92,
     466,    -1,   465,   466,    -1,   113,    -1,   163,    -1,    83,
      -1,   171,    -1,   170,    -1,    84,    -1,   515,    -1,   467,
      -1,   549,    -1,   468,    -1,   184,    -1,    10,    -1,    17,
      -1,   472,    -1,   469,   470,    -1,   469,   147,   177,    -1,
     469,   147,   481,   177,    -1,   471,    -1,   470,   471,    -1,
     145,   384,   175,    -1,   473,    -1,   475,    -1,   476,    -1,
     477,    -1,   480,    -1,   482,    -1,   478,    -1,   479,    -1,
     528,    -1,   474,    -1,   527,    -1,   103,    -1,   140,    -1,
     115,    -1,   111,   549,    -1,   147,   177,    -1,   147,   384,
     177,    -1,   112,    -1,   160,   144,   384,   174,    -1,   192,
     144,   384,   174,    -1,   549,   147,   177,    -1,   549,   147,
     481,   177,    -1,   387,    -1,   481,   100,   387,    -1,   483,
      -1,   501,    -1,   484,    -1,   498,    -1,   499,    -1,   148,
     549,   488,   121,    -1,   148,   549,   486,   488,   121,    -1,
     148,   549,   488,   187,   185,   549,   488,   187,    -1,   148,
     549,   488,   187,   485,   185,   549,   488,   187,    -1,   148,
     549,   486,   488,   187,   185,   549,   488,   187,    -1,   148,
     549,   486,   488,   187,   485,   185,   549,   488,   187,    -1,
     496,    -1,   485,   496,    -1,   487,    -1,   486,   487,    -1,
      27,   549,   488,   123,   488,   489,    -1,    -1,    27,    -1,
     173,   490,   173,    -1,    86,   492,    86,    -1,    -1,   491,
      -1,   125,    -1,   494,    -1,   491,   125,    -1,   491,   494,
      -1,    -1,   493,    -1,   124,    -1,   495,    -1,   493,   124,
      -1,   493,   495,    -1,    19,    -1,   497,    -1,     4,    -1,
     497,    -1,   483,    -1,     9,    -1,   500,    -1,   497,    -1,
       8,    -1,   114,    -1,   116,    -1,   381,    -1,   203,    21,
     204,    -1,   203,   204,    -1,   164,   548,   165,    -1,   164,
     548,     7,    -1,    96,     6,    -1,   502,    -1,   503,    -1,
     504,    -1,   505,    -1,   506,    -1,   507,    -1,    35,   144,
     384,   174,    -1,    37,   549,   144,   174,    -1,    37,   549,
     144,   384,   174,    -1,    37,   144,   384,   174,   144,   174,
      -1,    37,   144,   384,   174,   144,   384,   174,    -1,    90,
     549,   144,   174,    -1,    90,   549,   144,   384,   174,    -1,
      90,   144,   384,   174,   144,   174,    -1,    90,   144,   384,
     174,   144,   384,   174,    -1,    65,   144,   384,   174,    -1,
      30,   144,   384,   174,    -1,    54,   548,   144,   174,    -1,
      54,   548,   144,   384,   174,    -1,    54,   144,   384,   174,
     144,   174,    -1,    54,   144,   384,   174,   144,   384,   174,
      -1,   514,    -1,   514,   135,    -1,    87,   510,    -1,   512,
      -1,   512,   511,    -1,   201,   147,   177,    -1,   135,    -1,
     184,    -1,   166,    -1,   514,    -1,   515,    -1,   143,   147,
     177,    -1,   531,    -1,   534,    -1,   510,    -1,   513,   100,
     510,    -1,   549,    -1,   517,    -1,   523,    -1,   521,    -1,
     524,    -1,   522,    -1,   520,    -1,   519,    -1,   518,    -1,
     516,    -1,   216,   147,   177,    -1,    36,   147,   177,    -1,
      36,   147,   523,   177,    -1,    36,   147,   524,   177,    -1,
      65,   147,   177,    -1,    30,   147,   177,    -1,    54,   147,
     177,    -1,    54,   147,   548,   177,    -1,    54,   147,    20,
     177,    -1,    90,   147,   177,    -1,    90,   147,   549,   177,
      -1,    90,   147,   549,   100,   525,   177,    -1,    90,   147,
     184,   177,    -1,    90,   147,   184,   100,   525,   177,    -1,
     179,   549,   177,    -1,    37,   147,   177,    -1,    37,   147,
     549,   177,    -1,    37,   147,   549,   100,   525,   177,    -1,
      37,   147,   549,   100,   526,   177,    -1,    37,   147,   184,
     177,    -1,    37,   147,   184,   100,   525,   177,    -1,    37,
     147,   184,   100,   526,   177,    -1,    57,   147,   549,   177,
      -1,   549,    -1,   549,   135,    -1,    20,    -1,   529,    -1,
     530,    -1,   549,   136,   140,    -1,    40,   364,   381,    -1,
     532,    -1,   533,    -1,    40,   147,   184,   177,    -1,    40,
     147,   177,    87,   510,    -1,    40,   147,   513,   177,    87,
     510,    -1,   147,   512,   177,    -1,    25,   211,   212,    -1,
      25,   211,   213,    -1,    25,   211,   214,    -1,   217,   216,
     387,   224,   387,    -1,   217,   216,   387,    87,   223,   224,
     387,    -1,   217,   216,   387,    87,   225,   224,   387,    -1,
     217,   216,   387,   209,   387,    -1,   217,   216,   387,   210,
     387,    -1,   217,   218,   387,   224,   387,    -1,   217,   218,
     387,    87,   223,   224,   387,    -1,   217,   218,   387,    87,
     225,   224,   387,    -1,   217,   218,   387,   209,   387,    -1,
     217,   218,   387,   210,   387,    -1,   215,   216,   387,    -1,
     215,   218,   387,    -1,   220,   216,   387,   228,   387,    -1,
     220,   221,   222,   216,   387,   228,   387,    -1,   219,   216,
     387,    87,   387,    -1,   227,   111,   541,   226,   387,   176,
     387,    -1,   542,    -1,   541,   100,   111,   542,    -1,   549,
     133,   387,    -1,   236,   144,   384,   174,   544,    -1,   545,
      -1,   544,   545,    -1,   237,   546,   382,    -1,   237,   546,
     147,   111,   549,   177,   382,    -1,   237,   546,   147,   111,
     549,   100,   111,   549,   177,   382,    -1,   237,   546,   147,
     111,   549,   100,   111,   549,   100,   111,   549,   177,   382,
      -1,   467,    -1,   546,   200,   467,    -1,    20,    -1,    14,
      -1,   549,    -1,    18,    -1,   551,    -1,   238,   111,   406,
      38,   144,   387,   174,    -1,    38,   144,   387,   174,    -1,
     205,    -1,   118,    -1,    90,    -1,    30,    -1,    36,    -1,
      37,    -1,   143,    -1,    41,    -1,   216,    -1,    54,    -1,
      56,    -1,    57,    -1,    65,    -1,    67,    -1,   201,    -1,
      29,    -1,   253,    -1,    28,    -1,   213,    -1,   212,    -1,
     137,    -1,    35,    -1,   251,    -1,   252,    -1,   266,    -1,
     255,    -1,   243,    -1,   277,    -1,   269,    -1,   271,    -1,
     270,    -1,   275,    -1,   247,    -1,   242,    -1,    71,    -1,
     208,    -1,   246,    -1,    45,    -1,   214,    -1,   227,    -1,
     294,    -1,   221,    -1,   193,    -1,   198,    -1,   197,    -1,
     196,    -1,   195,    -1,   194,    -1,    89,    -1,   104,    -1,
     105,    -1,   176,    -1,    39,    -1,    52,    -1,    61,    -1,
      66,    -1,    53,    -1,    46,    -1,    49,    -1,    70,    -1,
      33,    -1,   138,    -1,    44,    -1,   202,    -1,   161,    -1,
     162,    -1,   159,    -1,    64,    -1,    88,    -1,   109,    -1,
     119,    -1,   120,    -1,    99,    -1,    62,    -1,   126,    -1,
     178,    -1,    93,    -1,    87,    -1,   188,    -1,   117,    -1,
     158,    -1,    85,    -1,    43,    -1,   222,    -1,    94,    -1,
     189,    -1,   110,    -1,   150,    -1,   191,    -1,   141,    -1,
     127,    -1,    69,    -1,    95,    -1,   190,    -1,   142,    -1,
     172,    -1,   186,    -1,   151,    -1,   128,    -1,   122,    -1,
     157,    -1,   139,    -1,   156,    -1,    25,    -1,    31,    -1,
      51,    -1,   106,    -1,    32,    -1,    50,    -1,   206,    -1,
      42,    -1,    55,    -1,    26,    -1,    40,    -1,   265,    -1,
     241,    -1,   274,    -1,   276,    -1,   245,    -1,   259,    -1,
     272,    -1,   264,    -1,   244,    -1,   258,    -1,   273,    -1,
     263,    -1,   257,    -1,   256,    -1,   240,    -1,   239,    -1,
     262,    -1,   248,    -1,   249,    -1,   278,    -1,   268,    -1,
     267,    -1,   260,    -1,   220,    -1,   226,    -1,   223,    -1,
     217,    -1,   210,    -1,   209,    -1,   211,    -1,   228,    -1,
     218,    -1,   219,    -1,   225,    -1,   215,    -1,   224,    -1,
      60,    -1,    58,    -1,    68,    -1,    34,    -1,    48,    -1,
     160,    -1,   192,    -1,   234,    -1,   229,    -1,   232,    -1,
     233,    -1,   235,    -1,   230,    -1,   231,    -1,   236,    -1,
     237,    -1,    38,    -1,   238,    -1,    59,    -1,   287,    -1,
     285,    -1,   286,    -1,   291,    -1,   292,    -1,   293,    -1,
     288,    -1,   289,    -1,   290,    -1,    72,    -1,    73,    -1,
      74,    -1,    75,    -1,    76,    -1,    77,    -1,    78,    -1,
      79,    -1,    80,    -1,    81,    -1,    82,    -1,   279,    -1,
     280,    -1,   281,    -1,   282,    -1,   283,    -1,   284,    -1,
     295,    -1,   296,    -1,   297,    -1,   298,    -1,   299,    -1,
     300,    -1,   301,    -1,   555,   553,    -1,    -1,   554,    -1,
     573,    -1,   554,   573,    -1,   556,    -1,   555,   254,   556,
      -1,   557,    -1,   556,   250,   557,    -1,   558,    -1,   557,
     252,   138,   558,    -1,   559,    -1,   251,   559,    -1,   563,
     560,   561,    -1,    -1,   578,    -1,    -1,   562,    -1,   274,
     144,   384,   174,    -1,   567,   564,    -1,   147,   552,   177,
      -1,   565,    -1,    -1,   600,    -1,   454,   144,   566,   174,
      -1,    -1,   552,    -1,   568,   569,    -1,   473,    -1,   144,
     384,   174,    -1,    -1,   570,    -1,   240,   571,    -1,   239,
     572,    -1,   262,    -1,    -1,    71,    -1,    -1,   278,    -1,
     574,    -1,   575,    -1,   576,    -1,   602,    -1,   599,    -1,
     160,    -1,   276,   439,   577,    -1,   245,   601,   577,    -1,
     278,    -1,   268,    -1,   261,    -1,   238,   579,    -1,   578,
     238,   579,    -1,   580,    -1,   581,    -1,   582,    -1,   597,
      -1,   583,    -1,   591,    -1,   584,    -1,   598,    -1,    93,
     266,    -1,    93,   255,    -1,   258,    -1,   273,    -1,   243,
     266,    -1,   243,   255,    -1,    50,   549,    20,    -1,   269,
      -1,    47,   269,    -1,   271,   585,    -1,   271,   147,   585,
     586,   177,    -1,    47,   271,    -1,   588,    -1,   106,    -1,
      -1,   587,    -1,   588,    -1,   587,   100,   588,    -1,    89,
      20,   589,   590,    -1,    -1,   263,    20,    -1,    -1,   601,
     257,    -1,   270,   278,   592,   594,    -1,   270,   278,   106,
     594,    -1,    47,   270,   278,    -1,    89,    20,    -1,   147,
     593,   177,    -1,    20,    -1,   593,   100,    20,    -1,    -1,
     595,    -1,   596,    -1,   595,   596,    -1,   191,   592,    -1,
     127,   592,    -1,   256,    20,    -1,   275,    -1,    47,   275,
      -1,    89,   208,    -1,    89,   246,    -1,   247,   242,    -1,
     259,   601,   272,    -1,   248,   439,    -1,    89,   120,   439,
      -1,    89,    45,   439,    -1,   249,   439,   189,   439,    -1,
     264,   603,    -1,   244,   603,    -1,   267,    -1,   260,    -1,
     277,   242,   441,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  xquery_parser::yyprhs_[] =
  {
         0,     0,     3,     5,     8,    10,    13,    15,    18,    23,
      30,    33,    35,    37,    40,    47,    50,    53,    58,    60,
      64,    66,    70,    72,    74,    76,    78,    80,    82,    84,
      86,    88,    90,    92,    94,    96,   101,   106,   108,   111,
     115,   117,   119,   121,   123,   125,   127,   129,   131,   133,
     135,   137,   139,   141,   143,   145,   147,   149,   151,   153,
     155,   161,   165,   169,   175,   181,   186,   190,   194,   198,
     204,   210,   216,   222,   228,   234,   239,   243,   247,   252,
     258,   265,   267,   271,   275,   279,   283,   290,   296,   305,
     310,   314,   316,   318,   320,   323,   326,   329,   333,   339,
     344,   351,   353,   356,   358,   360,   362,   364,   366,   368,
     371,   374,   377,   380,   382,   385,   388,   391,   395,   400,
     406,   413,   418,   424,   431,   439,   441,   444,   448,   452,
     461,   471,   473,   477,   481,   486,   498,   513,   527,   550,
     554,   558,   561,   565,   570,   576,   579,   584,   588,   589,
     593,   596,   598,   602,   608,   612,   618,   621,   624,   627,
     631,   635,   637,   640,   643,   646,   651,   656,   661,   666,
     673,   678,   680,   684,   687,   691,   695,   699,   701,   703,
     706,   708,   712,   714,   718,   720,   722,   724,   726,   728,
     730,   732,   734,   736,   738,   740,   742,   744,   746,   748,
     750,   752,   755,   758,   761,   764,   766,   768,   771,   776,
     780,   786,   791,   795,   797,   799,   801,   803,   805,   807,
     809,   811,   813,   816,   819,   823,   826,   828,   833,   837,
     842,   847,   853,   858,   864,   870,   877,   881,   885,   889,
     891,   896,   898,   903,   907,   912,   917,   923,   928,   934,
     936,   939,   943,   945,   948,   950,   957,   961,   965,   967,
     970,   974,   976,   980,   983,   987,   990,   994,   999,  1001,
    1005,  1007,  1010,  1012,  1014,  1016,  1019,  1022,  1025,  1029,
    1031,  1033,  1036,  1039,  1042,  1048,  1054,  1056,  1061,  1065,
    1070,  1079,  1090,  1092,  1095,  1100,  1108,  1117,  1119,  1123,
    1125,  1129,  1131,  1135,  1139,  1143,  1147,  1148,  1153,  1157,
    1161,  1165,  1167,  1173,  1174,  1176,  1178,  1182,  1184,  1188,
    1192,  1194,  1198,  1202,  1206,  1210,  1212,  1216,  1220,  1222,
    1226,  1230,  1232,  1237,  1239,  1244,  1246,  1251,  1253,  1258,
    1260,  1263,  1265,  1267,  1270,  1273,  1275,  1277,  1279,  1281,
    1283,  1285,  1287,  1289,  1291,  1293,  1295,  1297,  1302,  1308,
    1314,  1321,  1325,  1330,  1332,  1335,  1339,  1342,  1344,  1347,
    1350,  1352,  1354,  1356,  1360,  1364,  1366,  1368,  1370,  1373,
    1375,  1378,  1381,  1383,  1385,  1387,  1389,  1391,  1393,  1395,
    1397,  1399,  1402,  1405,  1407,  1409,  1411,  1413,  1415,  1417,
    1419,  1421,  1423,  1425,  1427,  1429,  1431,  1433,  1436,  1440,
    1445,  1447,  1450,  1454,  1456,  1458,  1460,  1462,  1464,  1466,
    1468,  1470,  1472,  1474,  1476,  1478,  1480,  1482,  1485,  1488,
    1492,  1494,  1499,  1504,  1508,  1513,  1515,  1519,  1521,  1523,
    1525,  1527,  1529,  1534,  1540,  1549,  1559,  1569,  1580,  1582,
    1585,  1587,  1590,  1597,  1598,  1600,  1604,  1608,  1609,  1611,
    1613,  1615,  1618,  1621,  1622,  1624,  1626,  1628,  1631,  1634,
    1636,  1638,  1640,  1642,  1644,  1646,  1648,  1650,  1652,  1654,
    1656,  1658,  1662,  1665,  1669,  1673,  1676,  1678,  1680,  1682,
    1684,  1686,  1688,  1693,  1698,  1704,  1711,  1719,  1724,  1730,
    1737,  1745,  1750,  1755,  1760,  1766,  1773,  1781,  1783,  1786,
    1789,  1791,  1794,  1798,  1800,  1802,  1804,  1806,  1808,  1812,
    1814,  1816,  1818,  1822,  1824,  1826,  1828,  1830,  1832,  1834,
    1836,  1838,  1840,  1842,  1846,  1850,  1855,  1860,  1864,  1868,
    1872,  1877,  1882,  1886,  1891,  1898,  1903,  1910,  1914,  1918,
    1923,  1930,  1937,  1942,  1949,  1956,  1961,  1963,  1966,  1968,
    1970,  1972,  1976,  1980,  1982,  1984,  1989,  1995,  2002,  2006,
    2010,  2014,  2018,  2024,  2032,  2040,  2046,  2052,  2058,  2066,
    2074,  2080,  2086,  2090,  2094,  2100,  2108,  2114,  2122,  2124,
    2129,  2133,  2139,  2141,  2144,  2148,  2156,  2167,  2181,  2183,
    2187,  2189,  2191,  2193,  2195,  2197,  2205,  2210,  2212,  2214,
    2216,  2218,  2220,  2222,  2224,  2226,  2228,  2230,  2232,  2234,
    2236,  2238,  2240,  2242,  2244,  2246,  2248,  2250,  2252,  2254,
    2256,  2258,  2260,  2262,  2264,  2266,  2268,  2270,  2272,  2274,
    2276,  2278,  2280,  2282,  2284,  2286,  2288,  2290,  2292,  2294,
    2296,  2298,  2300,  2302,  2304,  2306,  2308,  2310,  2312,  2314,
    2316,  2318,  2320,  2322,  2324,  2326,  2328,  2330,  2332,  2334,
    2336,  2338,  2340,  2342,  2344,  2346,  2348,  2350,  2352,  2354,
    2356,  2358,  2360,  2362,  2364,  2366,  2368,  2370,  2372,  2374,
    2376,  2378,  2380,  2382,  2384,  2386,  2388,  2390,  2392,  2394,
    2396,  2398,  2400,  2402,  2404,  2406,  2408,  2410,  2412,  2414,
    2416,  2418,  2420,  2422,  2424,  2426,  2428,  2430,  2432,  2434,
    2436,  2438,  2440,  2442,  2444,  2446,  2448,  2450,  2452,  2454,
    2456,  2458,  2460,  2462,  2464,  2466,  2468,  2470,  2472,  2474,
    2476,  2478,  2480,  2482,  2484,  2486,  2488,  2490,  2492,  2494,
    2496,  2498,  2500,  2502,  2504,  2506,  2508,  2510,  2512,  2514,
    2516,  2518,  2520,  2522,  2524,  2526,  2528,  2530,  2532,  2534,
    2536,  2538,  2540,  2542,  2544,  2546,  2548,  2550,  2552,  2554,
    2556,  2558,  2560,  2562,  2564,  2566,  2568,  2570,  2572,  2574,
    2576,  2578,  2580,  2582,  2584,  2586,  2588,  2590,  2592,  2594,
    2596,  2598,  2600,  2602,  2604,  2606,  2608,  2610,  2612,  2614,
    2617,  2618,  2620,  2622,  2625,  2627,  2631,  2633,  2637,  2639,
    2644,  2646,  2649,  2653,  2654,  2656,  2657,  2659,  2664,  2667,
    2671,  2673,  2674,  2676,  2681,  2682,  2684,  2687,  2689,  2693,
    2694,  2696,  2699,  2702,  2704,  2705,  2707,  2708,  2710,  2712,
    2714,  2716,  2718,  2720,  2722,  2726,  2730,  2732,  2734,  2736,
    2739,  2743,  2745,  2747,  2749,  2751,  2753,  2755,  2757,  2759,
    2762,  2765,  2767,  2769,  2772,  2775,  2779,  2781,  2784,  2787,
    2793,  2796,  2798,  2800,  2801,  2803,  2805,  2809,  2814,  2815,
    2818,  2819,  2822,  2827,  2832,  2836,  2839,  2843,  2845,  2849,
    2850,  2852,  2854,  2857,  2860,  2863,  2866,  2868,  2871,  2874,
    2877,  2880,  2884,  2887,  2891,  2895,  2900,  2903,  2906,  2908,
    2910
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,   995,   995,   996,  1005,  1010,  1017,  1022,  1033,  1038,
    1046,  1054,  1062,  1068,  1080,  1089,  1093,  1097,  1109,  1115,
    1125,  1131,  1141,  1142,  1143,  1144,  1149,  1150,  1151,  1152,
    1153,  1154,  1155,  1156,  1157,  1163,  1168,  1177,  1183,  1192,
    1201,  1202,  1203,  1204,  1205,  1206,  1207,  1208,  1209,  1210,
    1215,  1216,  1217,  1218,  1219,  1220,  1221,  1224,  1229,  1230,
    1240,  1249,  1255,  1265,  1271,  1281,  1291,  1299,  1305,  1316,
    1321,  1331,  1337,  1343,  1349,  1366,  1374,  1382,  1386,  1395,
    1404,  1417,  1423,  1434,  1438,  1446,  1451,  1456,  1463,  1476,
    1483,  1489,  1496,  1502,  1506,  1513,  1524,  1528,  1536,  1542,
    1548,  1557,  1563,  1572,  1576,  1582,  1586,  1590,  1594,  1600,
    1606,  1612,  1618,  1624,  1628,  1634,  1640,  1647,  1655,  1663,
    1671,  1679,  1691,  1705,  1719,  1736,  1740,  1747,  1751,  1758,
    1766,  1783,  1789,  1797,  1804,  1814,  1824,  1834,  1844,  1861,
    1867,  1878,  1882,  1886,  1890,  1899,  1906,  1925,  1935,  1941,
    1947,  1957,  1964,  1975,  1982,  1989,  2001,  2005,  2012,  2017,
    2024,  2032,  2036,  2040,  2048,  2056,  2066,  2080,  2090,  2104,
    2113,  2128,  2134,  2146,  2150,  2161,  2168,  2176,  2191,  2195,
    2209,  2213,  2222,  2226,  2240,  2241,  2242,  2243,  2244,  2247,
    2248,  2249,  2250,  2251,  2253,  2254,  2257,  2258,  2259,  2260,
    2261,  2266,  2281,  2288,  2292,  2299,  2303,  2307,  2314,  2322,
    2333,  2343,  2356,  2365,  2366,  2367,  2371,  2372,  2373,  2374,
    2375,  2378,  2384,  2393,  2397,  2405,  2415,  2421,  2433,  2437,
    2445,  2454,  2464,  2472,  2481,  2490,  2505,  2514,  2524,  2532,
    2538,  2547,  2553,  2565,  2573,  2583,  2591,  2603,  2609,  2620,
    2622,  2626,  2634,  2638,  2643,  2647,  2651,  2655,  2663,  2677,
    2685,  2692,  2698,  2709,  2713,  2722,  2730,  2736,  2746,  2752,
    2762,  2766,  2776,  2782,  2788,  2794,  2803,  2812,  2821,  2834,
    2838,  2846,  2852,  2862,  2870,  2879,  2892,  2899,  2911,  2915,
    2928,  2935,  2948,  2954,  2966,  2972,  2984,  2993,  2997,  3006,
    3010,  3018,  3022,  3032,  3039,  3048,  3058,  3057,  3071,  3080,
    3089,  3102,  3106,  3119,  3122,  3129,  3133,  3142,  3146,  3150,
    3159,  3163,  3169,  3175,  3181,  3192,  3196,  3200,  3208,  3212,
    3218,  3228,  3232,  3242,  3246,  3256,  3260,  3270,  3274,  3284,
    3288,  3296,  3300,  3304,  3308,  3318,  3322,  3326,  3334,  3338,
    3342,  3346,  3350,  3354,  3362,  3366,  3370,  3378,  3382,  3386,
    3390,  3401,  3407,  3417,  3423,  3433,  3437,  3475,  3481,  3487,
    3493,  3504,  3512,  3523,  3529,  3539,  3543,  3551,  3557,  3565,
    3571,  3583,  3589,  3599,  3603,  3607,  3611,  3615,  3621,  3627,
    3635,  3639,  3647,  3651,  3662,  3666,  3670,  3676,  3680,  3694,
    3698,  3706,  3710,  3720,  3724,  3728,  3737,  3741,  3747,  3751,
    3759,  3765,  3775,  3783,  3787,  3791,  3795,  3799,  3803,  3807,
    3811,  3815,  3823,  3827,  3835,  3842,  3849,  3860,  3868,  3872,
    3880,  3888,  3896,  3950,  3954,  3966,  3972,  3982,  3986,  3994,
    3998,  4002,  4010,  4020,  4030,  4040,  4050,  4060,  4075,  4081,
    4092,  4098,  4109,  4120,  4122,  4126,  4131,  4141,  4144,  4151,
    4159,  4165,  4175,  4188,  4191,  4198,  4204,  4210,  4217,  4228,
    4232,  4242,  4246,  4256,  4260,  4264,  4269,  4278,  4284,  4290,
    4296,  4306,  4310,  4322,  4326,  4338,  4350,  4354,  4358,  4362,
    4366,  4370,  4378,  4386,  4392,  4398,  4402,  4419,  4423,  4427,
    4431,  4439,  4447,  4455,  4459,  4463,  4467,  4475,  4481,  4491,
    4499,  4503,  4509,  4544,  4550,  4556,  4566,  4570,  4574,  4578,
    4582,  4589,  4595,  4605,  4613,  4617,  4621,  4625,  4629,  4633,
    4637,  4641,  4645,  4653,  4661,  4665,  4669,  4679,  4687,  4695,
    4699,  4703,  4711,  4715,  4721,  4727,  4731,  4741,  4749,  4753,
    4759,  4768,  4777,  4783,  4789,  4799,  4816,  4823,  4838,  4874,
    4878,  4887,  4896,  4906,  4910,  4919,  4928,  4932,  4943,  4960,
    4966,  4972,  4982,  4986,  4992,  4998,  5002,  5008,  5012,  5018,
    5024,  5031,  5041,  5046,  5054,  5060,  5070,  5092,  5101,  5107,
    5120,  5134,  5141,  5147,  5157,  5162,  5168,  5178,  5191,  5197,
    5207,  5217,  5218,  5236,  5240,  5253,  5259,  5266,  5267,  5268,
    5269,  5270,  5271,  5272,  5273,  5274,  5275,  5276,  5277,  5278,
    5279,  5280,  5281,  5282,  5283,  5284,  5285,  5286,  5287,  5288,
    5289,  5290,  5291,  5292,  5293,  5294,  5295,  5296,  5297,  5298,
    5299,  5300,  5301,  5302,  5303,  5304,  5305,  5306,  5307,  5308,
    5309,  5310,  5311,  5312,  5313,  5314,  5315,  5316,  5317,  5318,
    5319,  5320,  5321,  5322,  5323,  5324,  5325,  5326,  5327,  5328,
    5329,  5330,  5331,  5332,  5333,  5334,  5335,  5336,  5337,  5338,
    5339,  5340,  5341,  5342,  5343,  5344,  5345,  5346,  5347,  5348,
    5349,  5350,  5351,  5352,  5353,  5354,  5355,  5356,  5357,  5358,
    5359,  5360,  5361,  5362,  5363,  5364,  5365,  5366,  5367,  5368,
    5369,  5370,  5371,  5372,  5373,  5374,  5375,  5376,  5377,  5378,
    5379,  5380,  5381,  5382,  5383,  5384,  5385,  5386,  5387,  5388,
    5389,  5390,  5391,  5392,  5393,  5394,  5395,  5396,  5397,  5398,
    5399,  5400,  5401,  5402,  5403,  5404,  5405,  5406,  5407,  5408,
    5409,  5410,  5411,  5412,  5413,  5414,  5415,  5416,  5417,  5418,
    5419,  5420,  5421,  5422,  5423,  5424,  5425,  5426,  5427,  5428,
    5429,  5430,  5431,  5432,  5433,  5434,  5435,  5436,  5437,  5438,
    5439,  5440,  5441,  5442,  5443,  5444,  5445,  5446,  5447,  5448,
    5449,  5450,  5451,  5452,  5453,  5454,  5455,  5456,  5457,  5458,
    5459,  5460,  5461,  5462,  5463,  5464,  5465,  5466,  5467,  5478,
    5487,  5490,  5497,  5502,  5510,  5514,  5521,  5525,  5532,  5536,
    5543,  5547,  5556,  5569,  5572,  5580,  5583,  5591,  5599,  5607,
    5611,  5619,  5622,  5630,  5642,  5645,  5653,  5665,  5671,  5681,
    5684,  5692,  5696,  5700,  5708,  5711,  5719,  5722,  5730,  5734,
    5738,  5742,  5746,  5754,  5762,  5774,  5786,  5790,  5794,  5802,
    5808,  5818,  5822,  5826,  5830,  5834,  5838,  5842,  5846,  5854,
    5858,  5862,  5866,  5874,  5880,  5890,  5900,  5904,  5912,  5922,
    5933,  5940,  5944,  5952,  5955,  5962,  5967,  5976,  5986,  5989,
    5997,  6000,  6008,  6017,  6024,  6034,  6038,  6045,  6051,  6061,
    6064,  6071,  6076,  6088,  6096,  6108,  6116,  6120,  6128,  6132,
    6136,  6144,  6152,  6160,  6168,  6176,  6189,  6197,  6209,  6213,
    6221
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
     315
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 11374;
  const int xquery_parser::yynnts_ = 289;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 523;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 316;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 570;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // zorba

/* Line 1054 of lalr1.cc  */
#line 15209 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"


/* Line 1056 of lalr1.cc  */
#line 6227 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"


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

