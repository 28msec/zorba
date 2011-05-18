
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
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
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
      (yyval.node) = new OptionDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)));
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
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL, NULL);
    }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 1702 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 1710 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                              NULL,
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (1)].node)));
    }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 1718 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
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
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
    }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 1748 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))),
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
                            static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
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
                            static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
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
                            static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
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
                            static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
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
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 1903 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
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
                              static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)),
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
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
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
                              static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
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
                              static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
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
                               static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
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
                               static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
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
                               static_cast<QName*>((yysemantic_stack_[(6) - (4)].expr)),
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
                               static_cast<QName*>((yysemantic_stack_[(7) - (4)].expr)),
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
                             static_cast<QName*>((yysemantic_stack_[(8) - (3)].expr)),
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
                             static_cast<QName*>((yysemantic_stack_[(9) - (4)].expr)),
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
                                 static_cast<QName*>((yysemantic_stack_[(11) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (9)].expr)),
                                 (yysemantic_stack_[(11) - (11)].expr));
    }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 2199 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollUniqueKeyCheck(LOC((yyloc)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (4)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (7)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (10)].expr)),
                                    (yysemantic_stack_[(14) - (14)].expr));
    }
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 2209 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollForeachNode(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (11)].expr)),
                                 (yysemantic_stack_[(13) - (13)].expr));
    }
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 2220 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2395 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)));
      vdecl->add((yysemantic_stack_[(2) - (2)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 2405 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 207:

/* Line 678 of lalr1.cc  */
#line 2417 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 208:

/* Line 678 of lalr1.cc  */
#line 2430 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 209:

/* Line 678 of lalr1.cc  */
#line 2442 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 210:

/* Line 678 of lalr1.cc  */
#line 2458 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 211:

/* Line 678 of lalr1.cc  */
#line 2466 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ApplyExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr));
    }
    break;

  case 212:

/* Line 678 of lalr1.cc  */
#line 2474 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 213:

/* Line 678 of lalr1.cc  */
#line 2482 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 214:

/* Line 678 of lalr1.cc  */
#line 2497 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement(LOC((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 215:

/* Line 678 of lalr1.cc  */
#line 2502 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
    }
    break;

  case 216:

/* Line 678 of lalr1.cc  */
#line 2510 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 217:

/* Line 678 of lalr1.cc  */
#line 2526 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
    }
    break;

  case 218:

/* Line 678 of lalr1.cc  */
#line 2534 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 2542 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 220:

/* Line 678 of lalr1.cc  */
#line 2550 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
      cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.expr) = cle;
    }
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 2557 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 222:

/* Line 678 of lalr1.cc  */
#line 2568 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 2574 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CatchExpr(LOC((yyloc)),*(yysemantic_stack_[(7) - (2)].name_test_list), static_cast<QName*>((yysemantic_stack_[(7) - (5)].expr)), NULL, NULL, (yysemantic_stack_[(7) - (7)].expr));
       delete (yysemantic_stack_[(7) - (2)].name_test_list);
    }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 2580 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 225:

/* Line 678 of lalr1.cc  */
#line 2591 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 226:

/* Line 678 of lalr1.cc  */
#line 2606 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 2611 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 241:

/* Line 678 of lalr1.cc  */
#line 2649 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 242:

/* Line 678 of lalr1.cc  */
#line 2664 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 243:

/* Line 678 of lalr1.cc  */
#line 2671 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_sliding;
        }
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 2675 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_tumbling;
        }
    break;

  case 245:

/* Line 678 of lalr1.cc  */
#line 2682 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_start;
        }
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 2686 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_end;
        }
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 2690 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_only_end;
        }
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 2697 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FLWORWinCond(
                LOC((yyloc)),
                dynamic_cast<WindowVars*>((yysemantic_stack_[(4) - (2)].node)), (yysemantic_stack_[(4) - (4)].expr),
                (yysemantic_stack_[(4) - (1)].strval) == parser::the_start, (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end
            );
        }
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 2705 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FLWORWinCond(
                LOC((yyloc)), NULL, (yysemantic_stack_[(3) - (3)].expr),
                (yysemantic_stack_[(3) - (1)].strval) == parser::the_start, (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end
            );
        }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 2716 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 251:

/* Line 678 of lalr1.cc  */
#line 2726 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling ?
                              WindowClause::tumbling_window :
                              WindowClause::sliding_window),
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    }
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 2739 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 2762 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
            fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = fcl;
        }
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 2768 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
            fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = fcl;
        }
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 2778 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
        }
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 2786 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            VarInDeclList *vdl = new VarInDeclList( LOC((yyloc)) );
            vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vdl;
        }
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 2792 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( VarInDeclList *vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 2804 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 2808 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)), NULL, NULL, NULL, (yysemantic_stack_[(5) - (5)].expr), true);
    }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 2812 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)), dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)), NULL, NULL, (yysemantic_stack_[(4) - (4)].expr), false);
    }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 2816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (1)].expr)), dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (2)].node)), NULL, NULL, (yysemantic_stack_[(6) - (6)].expr), true);
    }
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 2820 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)), NULL, dynamic_cast<PositionalVar*>((yysemantic_stack_[(4) - (2)].node)), NULL, (yysemantic_stack_[(4) - (4)].expr), false);
    }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 2824 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (1)].expr)), NULL, dynamic_cast<PositionalVar*>((yysemantic_stack_[(6) - (4)].node)), NULL, (yysemantic_stack_[(6) - (6)].expr), true);
    }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 2828 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (3)].node)), NULL, (yysemantic_stack_[(5) - (5)].expr), false);
    }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 2833 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(7) - (1)].expr)), dynamic_cast<SequenceType *>((yysemantic_stack_[(7) - (2)].node)),
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(7) - (5)].node)), NULL, (yysemantic_stack_[(7) - (7)].expr), true);
    }
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 2839 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         NULL,NULL,
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
                         (yysemantic_stack_[(4) - (4)].expr),
                         false);
    }
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 2848 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 276:

/* Line 678 of lalr1.cc  */
#line 2858 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 277:

/* Line 678 of lalr1.cc  */
#line 2868 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 278:

/* Line 678 of lalr1.cc  */
#line 2884 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 2893 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 2902 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 2910 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 2916 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 2928 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                           NULL,
                           NULL,
                           (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 2936 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                           NULL,
                           (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 2946 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node))->get_var_name(),
                           NULL,
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node)),
                           (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 2954 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (3)].node)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
                           (yysemantic_stack_[(6) - (6)].expr));
    }
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 2966 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 2972 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 2985 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 2989 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 2997 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 3001 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 3010 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 3014 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 3018 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 3028 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 3036 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 3043 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = new GroupSpecList( LOC((yyloc)) );
            gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 3049 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
            if ( gsl )
                gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 3060 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 3064 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                         dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 3073 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 3081 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 3087 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 3097 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 3103 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 3113 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 3117 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 3127 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 3133 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 3139 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 3145 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
                NULL
            );
        }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 3154 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                NULL,
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 3163 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                NULL,
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 3172 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 3185 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 3189 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 3197 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 3203 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 3213 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 3221 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_some,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 3230 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_every,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 3243 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 3250 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 3262 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 3266 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 3278 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 3285 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 3291 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 3300 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 3307 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 3313 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 3324 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 3331 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 3337 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 3346 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 3355 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 3362 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 3373 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 3380 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 3392 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 3398 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 3410 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 3416 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 3427 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 3433 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 3444 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 3450 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 3461 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 3470 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 3474 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 3483 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 3487 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 3495 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 3499 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 358:

/* Line 678 of lalr1.cc  */
#line 3509 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 3516 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_eq ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 3525 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ne ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 3534 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 3539 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_lt ),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr)
            );
        }
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 3548 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_le ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 3557 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_gt ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 3566 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ge ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 3579 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 3583 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FTContainsExpr(
                LOC((yyloc)),
                (yysemantic_stack_[(5) - (1)].expr),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(5) - (4)].node)),
                dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 3595 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 3599 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 3606 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 3610 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 3619 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 3623 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 3627 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 3636 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 3640 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 3646 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 3652 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 3658 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 3669 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 3673 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 3677 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 3685 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 3689 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 3695 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 3705 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 3709 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 3719 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 3723 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 3733 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 3737 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 3747 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 3751 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 3761 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 3765 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 3773 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 3777 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 3781 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 3785 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 3795 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 3799 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 3803 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 3811 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 3815 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 3819 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 3823 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 3827 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 3831 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 3839 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 3843 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 3847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 3855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 3859 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 3863 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 3867 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 3878 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 3884 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 3894 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 3900 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 3910 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 3914 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 3918 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 3956 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new PathExpr(LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
    }
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 3960 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, NULL, (yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slash,
                        rpe);
    }
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 3970 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, NULL, (yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slashslash,
                        rpe);
    }
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 3980 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = (!rpe ?
            (yysemantic_stack_[(1) - (1)].expr) :
            new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 3993 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 4002 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 429:

/* Line 678 of lalr1.cc  */
#line 4012 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 4016 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 4025 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 4029 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 4038 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 4044 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 4052 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 4058 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 4070 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 4076 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 4086 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 4090 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 4094 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 4098 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 4102 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 4108 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 4114 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 4122 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 4126 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 4134 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 4138 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 4149 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 4153 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 4157 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 4163 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 4167 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 4181 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 4185 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 4193 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 4197 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 4207 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all);
    }
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 4211 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem);
    }
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 4215 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix);
    }
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 4224 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 4228 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 4232 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
     }
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 4236 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
     }
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 4244 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 4250 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 4260 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 4268 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 4272 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 471:

/* Line 678 of lalr1.cc  */
#line 4276 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 472:

/* Line 678 of lalr1.cc  */
#line 4280 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 473:

/* Line 678 of lalr1.cc  */
#line 4284 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 474:

/* Line 678 of lalr1.cc  */
#line 4288 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 4292 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 4296 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 4300 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 4310 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 4318 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 4322 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 4330 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 482:

/* Line 678 of lalr1.cc  */
#line 4337 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 4344 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 4355 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 4363 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 4367 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 4375 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 4383 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 4391 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 4445 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
        }
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 4449 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 4462 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            ArgList *al = new ArgList( LOC((yyloc)) );
            al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
            (yyval.node) = al;
        }
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 4468 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
                al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 4478 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 4482 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 4490 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 4494 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 4498 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 4506 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 500:

/* Line 678 of lalr1.cc  */
#line 4516 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 501:

/* Line 678 of lalr1.cc  */
#line 4526 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 502:

/* Line 678 of lalr1.cc  */
#line 4536 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 503:

/* Line 678 of lalr1.cc  */
#line 4546 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 504:

/* Line 678 of lalr1.cc  */
#line 4556 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 505:

/* Line 678 of lalr1.cc  */
#line 4571 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
            decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = decl;
        }
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 4577 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( decl )
                decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 4588 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
            dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = dal;
        }
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 4594 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
            if ( dal )
                dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 509:

/* Line 678 of lalr1.cc  */
#line 4605 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttr(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node))
            );
        }
    break;

  case 512:

/* Line 678 of lalr1.cc  */
#line 4622 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 4627 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 4636 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
        }
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 4640 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 4647 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = qacl;
        }
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 4653 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = qacl;
        }
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 4659 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 4667 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 4679 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
        }
    break;

  case 521:

/* Line 678 of lalr1.cc  */
#line 4683 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 522:

/* Line 678 of lalr1.cc  */
#line 4690 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = aacl;
        }
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 4696 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = aacl;
        }
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 4702 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if (aacl)
                aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 4709 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( aacl )
                aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 526:

/* Line 678 of lalr1.cc  */
#line 4720 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 4724 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 4734 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 4738 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 4748 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 4752 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 4756 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
        }
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 4761 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
        }
    break;

  case 534:

/* Line 678 of lalr1.cc  */
#line 4770 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval))
            );
        }
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 4776 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_lbrace
            );
        }
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 4782 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_rbrace
            );
        }
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 4788 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
        }
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 4796 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 4801 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 4809 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 4814 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 542:

/* Line 678 of lalr1.cc  */
#line 4822 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 543:

/* Line 678 of lalr1.cc  */
#line 4830 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 544:

/* Line 678 of lalr1.cc  */
#line 4835 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 4840 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 4845 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 4850 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 4855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 549:

/* Line 678 of lalr1.cc  */
#line 4864 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 550:

/* Line 678 of lalr1.cc  */
#line 4872 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
        }
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 4876 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 4893 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 4897 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 4905 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 555:

/* Line 678 of lalr1.cc  */
#line 4913 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 556:

/* Line 678 of lalr1.cc  */
#line 4921 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 557:

/* Line 678 of lalr1.cc  */
#line 4925 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 558:

/* Line 678 of lalr1.cc  */
#line 4933 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)), false
            );
        }
    break;

  case 559:

/* Line 678 of lalr1.cc  */
#line 4939 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)), true
            );
        }
    break;

  case 560:

/* Line 678 of lalr1.cc  */
#line 4949 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 561:

/* Line 678 of lalr1.cc  */
#line 4957 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 562:

/* Line 678 of lalr1.cc  */
#line 4961 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 563:

/* Line 678 of lalr1.cc  */
#line 4965 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 564:

/* Line 678 of lalr1.cc  */
#line 5000 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 565:

/* Line 678 of lalr1.cc  */
#line 5006 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 566:

/* Line 678 of lalr1.cc  */
#line 5012 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 567:

/* Line 678 of lalr1.cc  */
#line 5022 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 568:

/* Line 678 of lalr1.cc  */
#line 5026 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 569:

/* Line 678 of lalr1.cc  */
#line 5030 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)),true );
        }
    break;

  case 570:

/* Line 678 of lalr1.cc  */
#line 5034 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 571:

/* Line 678 of lalr1.cc  */
#line 5038 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 572:

/* Line 678 of lalr1.cc  */
#line 5045 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 573:

/* Line 678 of lalr1.cc  */
#line 5051 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 574:

/* Line 678 of lalr1.cc  */
#line 5061 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 575:

/* Line 678 of lalr1.cc  */
#line 5069 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 576:

/* Line 678 of lalr1.cc  */
#line 5073 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 577:

/* Line 678 of lalr1.cc  */
#line 5077 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 578:

/* Line 678 of lalr1.cc  */
#line 5081 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 579:

/* Line 678 of lalr1.cc  */
#line 5085 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 580:

/* Line 678 of lalr1.cc  */
#line 5089 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 581:

/* Line 678 of lalr1.cc  */
#line 5093 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 582:

/* Line 678 of lalr1.cc  */
#line 5097 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 583:

/* Line 678 of lalr1.cc  */
#line 5101 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 584:

/* Line 678 of lalr1.cc  */
#line 5109 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyKindTest( LOC((yyloc)) );
        }
    break;

  case 585:

/* Line 678 of lalr1.cc  */
#line 5117 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)) );
        }
    break;

  case 586:

/* Line 678 of lalr1.cc  */
#line 5121 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)) );
        }
    break;

  case 587:

/* Line 678 of lalr1.cc  */
#line 5125 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest(
                LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 588:

/* Line 678 of lalr1.cc  */
#line 5135 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TextTest( LOC((yyloc)) );
        }
    break;

  case 589:

/* Line 678 of lalr1.cc  */
#line 5143 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CommentTest( LOC((yyloc)));
        }
    break;

  case 590:

/* Line 678 of lalr1.cc  */
#line 5151 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 591:

/* Line 678 of lalr1.cc  */
#line 5155 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 592:

/* Line 678 of lalr1.cc  */
#line 5159 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 593:

/* Line 678 of lalr1.cc  */
#line 5167 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 594:

/* Line 678 of lalr1.cc  */
#line 5171 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 595:

/* Line 678 of lalr1.cc  */
#line 5177 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 596:

/* Line 678 of lalr1.cc  */
#line 5183 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 597:

/* Line 678 of lalr1.cc  */
#line 5187 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 598:

/* Line 678 of lalr1.cc  */
#line 5197 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 599:

/* Line 678 of lalr1.cc  */
#line 5205 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 600:

/* Line 678 of lalr1.cc  */
#line 5209 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 601:

/* Line 678 of lalr1.cc  */
#line 5215 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 602:

/* Line 678 of lalr1.cc  */
#line 5224 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 603:

/* Line 678 of lalr1.cc  */
#line 5233 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 604:

/* Line 678 of lalr1.cc  */
#line 5239 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 605:

/* Line 678 of lalr1.cc  */
#line 5245 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 606:

/* Line 678 of lalr1.cc  */
#line 5255 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 607:

/* Line 678 of lalr1.cc  */
#line 5272 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 608:

/* Line 678 of lalr1.cc  */
#line 5279 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 609:

/* Line 678 of lalr1.cc  */
#line 5294 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 610:

/* Line 678 of lalr1.cc  */
#line 5330 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 611:

/* Line 678 of lalr1.cc  */
#line 5334 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 612:

/* Line 678 of lalr1.cc  */
#line 5342 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 613:

/* Line 678 of lalr1.cc  */
#line 5350 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new InlineFunction(LOC((yyloc)),
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theParams,
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theReturnType,
                              (yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (2)].fnsig);
    }
    break;

  case 614:

/* Line 678 of lalr1.cc  */
#line 5362 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 615:

/* Line 678 of lalr1.cc  */
#line 5366 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 616:

/* Line 678 of lalr1.cc  */
#line 5374 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 617:

/* Line 678 of lalr1.cc  */
#line 5382 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 618:

/* Line 678 of lalr1.cc  */
#line 5386 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 619:

/* Line 678 of lalr1.cc  */
#line 5397 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 620:

/* Line 678 of lalr1.cc  */
#line 5414 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 621:

/* Line 678 of lalr1.cc  */
#line 5420 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 622:

/* Line 678 of lalr1.cc  */
#line 5426 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 623:

/* Line 678 of lalr1.cc  */
#line 5436 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 624:

/* Line 678 of lalr1.cc  */
#line 5440 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 625:

/* Line 678 of lalr1.cc  */
#line 5446 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 626:

/* Line 678 of lalr1.cc  */
#line 5452 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 627:

/* Line 678 of lalr1.cc  */
#line 5456 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 628:

/* Line 678 of lalr1.cc  */
#line 5462 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 629:

/* Line 678 of lalr1.cc  */
#line 5466 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 630:

/* Line 678 of lalr1.cc  */
#line 5472 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 631:

/* Line 678 of lalr1.cc  */
#line 5478 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 632:

/* Line 678 of lalr1.cc  */
#line 5485 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 633:

/* Line 678 of lalr1.cc  */
#line 5495 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 634:

/* Line 678 of lalr1.cc  */
#line 5500 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 635:

/* Line 678 of lalr1.cc  */
#line 5508 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 636:

/* Line 678 of lalr1.cc  */
#line 5514 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 637:

/* Line 678 of lalr1.cc  */
#line 5524 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 638:

/* Line 678 of lalr1.cc  */
#line 5546 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 639:

/* Line 678 of lalr1.cc  */
#line 5555 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 640:

/* Line 678 of lalr1.cc  */
#line 5561 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 641:

/* Line 678 of lalr1.cc  */
#line 5574 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 642:

/* Line 678 of lalr1.cc  */
#line 5588 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 643:

/* Line 678 of lalr1.cc  */
#line 5595 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 644:

/* Line 678 of lalr1.cc  */
#line 5601 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 645:

/* Line 678 of lalr1.cc  */
#line 5611 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 646:

/* Line 678 of lalr1.cc  */
#line 5616 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CatchExpr(LOC((yyloc)),*(yysemantic_stack_[(7) - (2)].name_test_list), static_cast<QName*>((yysemantic_stack_[(7) - (5)].expr)), NULL, NULL, (yysemantic_stack_[(7) - (7)].expr));
       delete (yysemantic_stack_[(7) - (2)].name_test_list);
    }
    break;

  case 647:

/* Line 678 of lalr1.cc  */
#line 5621 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 648:

/* Line 678 of lalr1.cc  */
#line 5631 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 649:

/* Line 678 of lalr1.cc  */
#line 5645 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 650:

/* Line 678 of lalr1.cc  */
#line 5653 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 651:

/* Line 678 of lalr1.cc  */
#line 5659 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 652:

/* Line 678 of lalr1.cc  */
#line 5677 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 653:

/* Line 678 of lalr1.cc  */
#line 5685 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 654:

/* Line 678 of lalr1.cc  */
#line 5689 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 655:

/* Line 678 of lalr1.cc  */
#line 5696 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 656:

/* Line 678 of lalr1.cc  */
#line 5701 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 657:

/* Line 678 of lalr1.cc  */
#line 5709 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 658:

/* Line 678 of lalr1.cc  */
#line 5713 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 659:

/* Line 678 of lalr1.cc  */
#line 5720 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 660:

/* Line 678 of lalr1.cc  */
#line 5724 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 661:

/* Line 678 of lalr1.cc  */
#line 5731 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 662:

/* Line 678 of lalr1.cc  */
#line 5735 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 663:

/* Line 678 of lalr1.cc  */
#line 5742 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 664:

/* Line 678 of lalr1.cc  */
#line 5746 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 665:

/* Line 678 of lalr1.cc  */
#line 5755 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 666:

/* Line 678 of lalr1.cc  */
#line 5767 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 667:

/* Line 678 of lalr1.cc  */
#line 5771 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 668:

/* Line 678 of lalr1.cc  */
#line 5778 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 669:

/* Line 678 of lalr1.cc  */
#line 5782 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 670:

/* Line 678 of lalr1.cc  */
#line 5790 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 671:

/* Line 678 of lalr1.cc  */
#line 5798 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 672:

/* Line 678 of lalr1.cc  */
#line 5806 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 673:

/* Line 678 of lalr1.cc  */
#line 5810 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 674:

/* Line 678 of lalr1.cc  */
#line 5817 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 675:

/* Line 678 of lalr1.cc  */
#line 5821 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 676:

/* Line 678 of lalr1.cc  */
#line 5829 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 677:

/* Line 678 of lalr1.cc  */
#line 5840 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 678:

/* Line 678 of lalr1.cc  */
#line 5844 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 679:

/* Line 678 of lalr1.cc  */
#line 5852 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 680:

/* Line 678 of lalr1.cc  */
#line 5864 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 681:

/* Line 678 of lalr1.cc  */
#line 5870 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 682:

/* Line 678 of lalr1.cc  */
#line 5879 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 683:

/* Line 678 of lalr1.cc  */
#line 5883 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 684:

/* Line 678 of lalr1.cc  */
#line 5891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 685:

/* Line 678 of lalr1.cc  */
#line 5895 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 686:

/* Line 678 of lalr1.cc  */
#line 5899 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 687:

/* Line 678 of lalr1.cc  */
#line 5906 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 688:

/* Line 678 of lalr1.cc  */
#line 5910 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 689:

/* Line 678 of lalr1.cc  */
#line 5917 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 690:

/* Line 678 of lalr1.cc  */
#line 5921 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 691:

/* Line 678 of lalr1.cc  */
#line 5929 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 692:

/* Line 678 of lalr1.cc  */
#line 5933 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 693:

/* Line 678 of lalr1.cc  */
#line 5937 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 694:

/* Line 678 of lalr1.cc  */
#line 5941 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 695:

/* Line 678 of lalr1.cc  */
#line 5945 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 696:

/* Line 678 of lalr1.cc  */
#line 5953 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 697:

/* Line 678 of lalr1.cc  */
#line 5961 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 698:

/* Line 678 of lalr1.cc  */
#line 5973 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 699:

/* Line 678 of lalr1.cc  */
#line 5985 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 700:

/* Line 678 of lalr1.cc  */
#line 5989 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 701:

/* Line 678 of lalr1.cc  */
#line 5993 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 702:

/* Line 678 of lalr1.cc  */
#line 6001 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 703:

/* Line 678 of lalr1.cc  */
#line 6007 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 704:

/* Line 678 of lalr1.cc  */
#line 6017 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 705:

/* Line 678 of lalr1.cc  */
#line 6021 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 706:

/* Line 678 of lalr1.cc  */
#line 6025 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 707:

/* Line 678 of lalr1.cc  */
#line 6029 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 708:

/* Line 678 of lalr1.cc  */
#line 6033 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 709:

/* Line 678 of lalr1.cc  */
#line 6037 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 710:

/* Line 678 of lalr1.cc  */
#line 6041 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 711:

/* Line 678 of lalr1.cc  */
#line 6045 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 712:

/* Line 678 of lalr1.cc  */
#line 6053 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 713:

/* Line 678 of lalr1.cc  */
#line 6057 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 714:

/* Line 678 of lalr1.cc  */
#line 6061 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 715:

/* Line 678 of lalr1.cc  */
#line 6065 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 716:

/* Line 678 of lalr1.cc  */
#line 6073 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 717:

/* Line 678 of lalr1.cc  */
#line 6079 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 718:

/* Line 678 of lalr1.cc  */
#line 6089 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 719:

/* Line 678 of lalr1.cc  */
#line 6099 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::with );
        }
    break;

  case 720:

/* Line 678 of lalr1.cc  */
#line 6103 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::without );
        }
    break;

  case 721:

/* Line 678 of lalr1.cc  */
#line 6111 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 722:

/* Line 678 of lalr1.cc  */
#line 6121 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 723:

/* Line 678 of lalr1.cc  */
#line 6132 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 724:

/* Line 678 of lalr1.cc  */
#line 6139 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 725:

/* Line 678 of lalr1.cc  */
#line 6143 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 726:

/* Line 678 of lalr1.cc  */
#line 6150 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 727:

/* Line 678 of lalr1.cc  */
#line 6154 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 728:

/* Line 678 of lalr1.cc  */
#line 6161 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 729:

/* Line 678 of lalr1.cc  */
#line 6166 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 730:

/* Line 678 of lalr1.cc  */
#line 6175 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 731:

/* Line 678 of lalr1.cc  */
#line 6184 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = NULL;
        }
    break;

  case 732:

/* Line 678 of lalr1.cc  */
#line 6188 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 733:

/* Line 678 of lalr1.cc  */
#line 6195 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 734:

/* Line 678 of lalr1.cc  */
#line 6199 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 735:

/* Line 678 of lalr1.cc  */
#line 6207 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 736:

/* Line 678 of lalr1.cc  */
#line 6216 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 737:

/* Line 678 of lalr1.cc  */
#line 6223 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 738:

/* Line 678 of lalr1.cc  */
#line 6233 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 739:

/* Line 678 of lalr1.cc  */
#line 6237 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 740:

/* Line 678 of lalr1.cc  */
#line 6244 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 741:

/* Line 678 of lalr1.cc  */
#line 6250 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 742:

/* Line 678 of lalr1.cc  */
#line 6259 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 743:

/* Line 678 of lalr1.cc  */
#line 6263 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 744:

/* Line 678 of lalr1.cc  */
#line 6270 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 745:

/* Line 678 of lalr1.cc  */
#line 6275 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 746:

/* Line 678 of lalr1.cc  */
#line 6287 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 747:

/* Line 678 of lalr1.cc  */
#line 6295 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 748:

/* Line 678 of lalr1.cc  */
#line 6307 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 749:

/* Line 678 of lalr1.cc  */
#line 6315 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 750:

/* Line 678 of lalr1.cc  */
#line 6319 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 751:

/* Line 678 of lalr1.cc  */
#line 6327 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 752:

/* Line 678 of lalr1.cc  */
#line 6331 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 753:

/* Line 678 of lalr1.cc  */
#line 6335 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 754:

/* Line 678 of lalr1.cc  */
#line 6343 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 755:

/* Line 678 of lalr1.cc  */
#line 6351 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 756:

/* Line 678 of lalr1.cc  */
#line 6355 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 757:

/* Line 678 of lalr1.cc  */
#line 6359 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 758:

/* Line 678 of lalr1.cc  */
#line 6363 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 759:

/* Line 678 of lalr1.cc  */
#line 6371 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 760:

/* Line 678 of lalr1.cc  */
#line 6379 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 761:

/* Line 678 of lalr1.cc  */
#line 6391 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 762:

/* Line 678 of lalr1.cc  */
#line 6395 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 763:

/* Line 678 of lalr1.cc  */
#line 6403 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 766:

/* Line 678 of lalr1.cc  */
#line 6421 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 768:

/* Line 678 of lalr1.cc  */
#line 6434 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 769:

/* Line 678 of lalr1.cc  */
#line 6435 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 770:

/* Line 678 of lalr1.cc  */
#line 6436 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 771:

/* Line 678 of lalr1.cc  */
#line 6437 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 772:

/* Line 678 of lalr1.cc  */
#line 6438 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 773:

/* Line 678 of lalr1.cc  */
#line 6439 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 774:

/* Line 678 of lalr1.cc  */
#line 6440 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 775:

/* Line 678 of lalr1.cc  */
#line 6441 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 776:

/* Line 678 of lalr1.cc  */
#line 6442 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 777:

/* Line 678 of lalr1.cc  */
#line 6443 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 778:

/* Line 678 of lalr1.cc  */
#line 6444 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 779:

/* Line 678 of lalr1.cc  */
#line 6445 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 780:

/* Line 678 of lalr1.cc  */
#line 6446 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 781:

/* Line 678 of lalr1.cc  */
#line 6447 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 782:

/* Line 678 of lalr1.cc  */
#line 6448 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 784:

/* Line 678 of lalr1.cc  */
#line 6453 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 785:

/* Line 678 of lalr1.cc  */
#line 6454 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 786:

/* Line 678 of lalr1.cc  */
#line 6455 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 787:

/* Line 678 of lalr1.cc  */
#line 6456 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 788:

/* Line 678 of lalr1.cc  */
#line 6457 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 789:

/* Line 678 of lalr1.cc  */
#line 6458 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 790:

/* Line 678 of lalr1.cc  */
#line 6459 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 791:

/* Line 678 of lalr1.cc  */
#line 6460 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 792:

/* Line 678 of lalr1.cc  */
#line 6461 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 793:

/* Line 678 of lalr1.cc  */
#line 6462 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 794:

/* Line 678 of lalr1.cc  */
#line 6463 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 795:

/* Line 678 of lalr1.cc  */
#line 6464 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 796:

/* Line 678 of lalr1.cc  */
#line 6465 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 797:

/* Line 678 of lalr1.cc  */
#line 6466 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 798:

/* Line 678 of lalr1.cc  */
#line 6467 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 799:

/* Line 678 of lalr1.cc  */
#line 6468 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 800:

/* Line 678 of lalr1.cc  */
#line 6469 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 801:

/* Line 678 of lalr1.cc  */
#line 6470 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 802:

/* Line 678 of lalr1.cc  */
#line 6471 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 803:

/* Line 678 of lalr1.cc  */
#line 6472 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 804:

/* Line 678 of lalr1.cc  */
#line 6473 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 805:

/* Line 678 of lalr1.cc  */
#line 6474 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 806:

/* Line 678 of lalr1.cc  */
#line 6475 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 807:

/* Line 678 of lalr1.cc  */
#line 6476 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 808:

/* Line 678 of lalr1.cc  */
#line 6477 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 809:

/* Line 678 of lalr1.cc  */
#line 6478 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 810:

/* Line 678 of lalr1.cc  */
#line 6479 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 811:

/* Line 678 of lalr1.cc  */
#line 6480 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 812:

/* Line 678 of lalr1.cc  */
#line 6481 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 813:

/* Line 678 of lalr1.cc  */
#line 6482 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 814:

/* Line 678 of lalr1.cc  */
#line 6483 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 815:

/* Line 678 of lalr1.cc  */
#line 6484 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 816:

/* Line 678 of lalr1.cc  */
#line 6485 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 817:

/* Line 678 of lalr1.cc  */
#line 6486 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 818:

/* Line 678 of lalr1.cc  */
#line 6487 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 819:

/* Line 678 of lalr1.cc  */
#line 6488 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 820:

/* Line 678 of lalr1.cc  */
#line 6489 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 821:

/* Line 678 of lalr1.cc  */
#line 6490 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 822:

/* Line 678 of lalr1.cc  */
#line 6491 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 823:

/* Line 678 of lalr1.cc  */
#line 6492 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 824:

/* Line 678 of lalr1.cc  */
#line 6493 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 825:

/* Line 678 of lalr1.cc  */
#line 6494 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 826:

/* Line 678 of lalr1.cc  */
#line 6495 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 827:

/* Line 678 of lalr1.cc  */
#line 6496 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 828:

/* Line 678 of lalr1.cc  */
#line 6497 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 829:

/* Line 678 of lalr1.cc  */
#line 6498 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 830:

/* Line 678 of lalr1.cc  */
#line 6499 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 831:

/* Line 678 of lalr1.cc  */
#line 6500 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 832:

/* Line 678 of lalr1.cc  */
#line 6501 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 833:

/* Line 678 of lalr1.cc  */
#line 6502 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 834:

/* Line 678 of lalr1.cc  */
#line 6503 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 835:

/* Line 678 of lalr1.cc  */
#line 6504 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 836:

/* Line 678 of lalr1.cc  */
#line 6505 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 837:

/* Line 678 of lalr1.cc  */
#line 6506 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 838:

/* Line 678 of lalr1.cc  */
#line 6507 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 839:

/* Line 678 of lalr1.cc  */
#line 6508 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 840:

/* Line 678 of lalr1.cc  */
#line 6509 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 841:

/* Line 678 of lalr1.cc  */
#line 6510 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 842:

/* Line 678 of lalr1.cc  */
#line 6511 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 843:

/* Line 678 of lalr1.cc  */
#line 6512 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 844:

/* Line 678 of lalr1.cc  */
#line 6513 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 845:

/* Line 678 of lalr1.cc  */
#line 6514 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 846:

/* Line 678 of lalr1.cc  */
#line 6515 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 847:

/* Line 678 of lalr1.cc  */
#line 6516 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 848:

/* Line 678 of lalr1.cc  */
#line 6517 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 849:

/* Line 678 of lalr1.cc  */
#line 6518 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 850:

/* Line 678 of lalr1.cc  */
#line 6519 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 851:

/* Line 678 of lalr1.cc  */
#line 6520 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 852:

/* Line 678 of lalr1.cc  */
#line 6521 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 853:

/* Line 678 of lalr1.cc  */
#line 6522 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 854:

/* Line 678 of lalr1.cc  */
#line 6523 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 855:

/* Line 678 of lalr1.cc  */
#line 6524 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 856:

/* Line 678 of lalr1.cc  */
#line 6525 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 857:

/* Line 678 of lalr1.cc  */
#line 6526 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 858:

/* Line 678 of lalr1.cc  */
#line 6527 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 859:

/* Line 678 of lalr1.cc  */
#line 6528 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 860:

/* Line 678 of lalr1.cc  */
#line 6529 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 861:

/* Line 678 of lalr1.cc  */
#line 6530 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 862:

/* Line 678 of lalr1.cc  */
#line 6531 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 863:

/* Line 678 of lalr1.cc  */
#line 6532 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 864:

/* Line 678 of lalr1.cc  */
#line 6533 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 865:

/* Line 678 of lalr1.cc  */
#line 6534 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 866:

/* Line 678 of lalr1.cc  */
#line 6535 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 867:

/* Line 678 of lalr1.cc  */
#line 6536 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 868:

/* Line 678 of lalr1.cc  */
#line 6537 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 869:

/* Line 678 of lalr1.cc  */
#line 6538 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 870:

/* Line 678 of lalr1.cc  */
#line 6539 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 871:

/* Line 678 of lalr1.cc  */
#line 6540 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 872:

/* Line 678 of lalr1.cc  */
#line 6541 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 873:

/* Line 678 of lalr1.cc  */
#line 6542 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 874:

/* Line 678 of lalr1.cc  */
#line 6543 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 875:

/* Line 678 of lalr1.cc  */
#line 6544 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 876:

/* Line 678 of lalr1.cc  */
#line 6545 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 877:

/* Line 678 of lalr1.cc  */
#line 6546 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 878:

/* Line 678 of lalr1.cc  */
#line 6547 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 879:

/* Line 678 of lalr1.cc  */
#line 6548 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 880:

/* Line 678 of lalr1.cc  */
#line 6549 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 881:

/* Line 678 of lalr1.cc  */
#line 6550 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 882:

/* Line 678 of lalr1.cc  */
#line 6551 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 883:

/* Line 678 of lalr1.cc  */
#line 6552 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 884:

/* Line 678 of lalr1.cc  */
#line 6553 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 885:

/* Line 678 of lalr1.cc  */
#line 6554 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 886:

/* Line 678 of lalr1.cc  */
#line 6555 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 887:

/* Line 678 of lalr1.cc  */
#line 6556 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 888:

/* Line 678 of lalr1.cc  */
#line 6557 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 889:

/* Line 678 of lalr1.cc  */
#line 6558 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 890:

/* Line 678 of lalr1.cc  */
#line 6559 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 891:

/* Line 678 of lalr1.cc  */
#line 6560 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 892:

/* Line 678 of lalr1.cc  */
#line 6561 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 893:

/* Line 678 of lalr1.cc  */
#line 6562 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 894:

/* Line 678 of lalr1.cc  */
#line 6563 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 895:

/* Line 678 of lalr1.cc  */
#line 6564 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 896:

/* Line 678 of lalr1.cc  */
#line 6565 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 897:

/* Line 678 of lalr1.cc  */
#line 6566 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 898:

/* Line 678 of lalr1.cc  */
#line 6567 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 899:

/* Line 678 of lalr1.cc  */
#line 6568 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 900:

/* Line 678 of lalr1.cc  */
#line 6569 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 901:

/* Line 678 of lalr1.cc  */
#line 6570 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 902:

/* Line 678 of lalr1.cc  */
#line 6571 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 903:

/* Line 678 of lalr1.cc  */
#line 6572 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 904:

/* Line 678 of lalr1.cc  */
#line 6573 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 905:

/* Line 678 of lalr1.cc  */
#line 6574 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 906:

/* Line 678 of lalr1.cc  */
#line 6575 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 907:

/* Line 678 of lalr1.cc  */
#line 6576 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 908:

/* Line 678 of lalr1.cc  */
#line 6577 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 909:

/* Line 678 of lalr1.cc  */
#line 6578 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 910:

/* Line 678 of lalr1.cc  */
#line 6579 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 911:

/* Line 678 of lalr1.cc  */
#line 6580 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 912:

/* Line 678 of lalr1.cc  */
#line 6581 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 913:

/* Line 678 of lalr1.cc  */
#line 6582 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 914:

/* Line 678 of lalr1.cc  */
#line 6583 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 915:

/* Line 678 of lalr1.cc  */
#line 6584 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 916:

/* Line 678 of lalr1.cc  */
#line 6585 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 917:

/* Line 678 of lalr1.cc  */
#line 6586 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 918:

/* Line 678 of lalr1.cc  */
#line 6587 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 919:

/* Line 678 of lalr1.cc  */
#line 6588 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 920:

/* Line 678 of lalr1.cc  */
#line 6589 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 921:

/* Line 678 of lalr1.cc  */
#line 6590 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 922:

/* Line 678 of lalr1.cc  */
#line 6591 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 923:

/* Line 678 of lalr1.cc  */
#line 6592 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 924:

/* Line 678 of lalr1.cc  */
#line 6593 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 925:

/* Line 678 of lalr1.cc  */
#line 6594 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 926:

/* Line 678 of lalr1.cc  */
#line 6595 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 927:

/* Line 678 of lalr1.cc  */
#line 6596 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 928:

/* Line 678 of lalr1.cc  */
#line 6597 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("local"))); }
    break;

  case 929:

/* Line 678 of lalr1.cc  */
#line 6598 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 930:

/* Line 678 of lalr1.cc  */
#line 6599 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 931:

/* Line 678 of lalr1.cc  */
#line 6600 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 932:

/* Line 678 of lalr1.cc  */
#line 6601 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 933:

/* Line 678 of lalr1.cc  */
#line 6602 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 934:

/* Line 678 of lalr1.cc  */
#line 6603 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 935:

/* Line 678 of lalr1.cc  */
#line 6604 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eval"))); }
    break;

  case 936:

/* Line 678 of lalr1.cc  */
#line 6605 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 937:

/* Line 678 of lalr1.cc  */
#line 6606 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 938:

/* Line 678 of lalr1.cc  */
#line 6607 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 939:

/* Line 678 of lalr1.cc  */
#line 6608 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 940:

/* Line 678 of lalr1.cc  */
#line 6609 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 941:

/* Line 678 of lalr1.cc  */
#line 6610 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 942:

/* Line 678 of lalr1.cc  */
#line 6611 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 943:

/* Line 678 of lalr1.cc  */
#line 6612 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 944:

/* Line 678 of lalr1.cc  */
#line 6613 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 945:

/* Line 678 of lalr1.cc  */
#line 6614 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 946:

/* Line 678 of lalr1.cc  */
#line 6615 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 947:

/* Line 678 of lalr1.cc  */
#line 6616 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 948:

/* Line 678 of lalr1.cc  */
#line 6617 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 949:

/* Line 678 of lalr1.cc  */
#line 6618 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 950:

/* Line 678 of lalr1.cc  */
#line 6619 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 951:

/* Line 678 of lalr1.cc  */
#line 6620 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 952:

/* Line 678 of lalr1.cc  */
#line 6621 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 953:

/* Line 678 of lalr1.cc  */
#line 6622 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 954:

/* Line 678 of lalr1.cc  */
#line 6623 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 955:

/* Line 678 of lalr1.cc  */
#line 6624 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 956:

/* Line 678 of lalr1.cc  */
#line 6625 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 957:

/* Line 678 of lalr1.cc  */
#line 6626 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 958:

/* Line 678 of lalr1.cc  */
#line 6627 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 959:

/* Line 678 of lalr1.cc  */
#line 6628 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 960:

/* Line 678 of lalr1.cc  */
#line 6629 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 961:

/* Line 678 of lalr1.cc  */
#line 6630 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 962:

/* Line 678 of lalr1.cc  */
#line 6631 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 963:

/* Line 678 of lalr1.cc  */
#line 6632 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 964:

/* Line 678 of lalr1.cc  */
#line 6633 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 965:

/* Line 678 of lalr1.cc  */
#line 6634 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 966:

/* Line 678 of lalr1.cc  */
#line 6635 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 967:

/* Line 678 of lalr1.cc  */
#line 6636 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 968:

/* Line 678 of lalr1.cc  */
#line 6637 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 969:

/* Line 678 of lalr1.cc  */
#line 6638 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 970:

/* Line 678 of lalr1.cc  */
#line 6639 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 971:

/* Line 678 of lalr1.cc  */
#line 6640 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 972:

/* Line 678 of lalr1.cc  */
#line 6641 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 973:

/* Line 678 of lalr1.cc  */
#line 6642 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 974:

/* Line 678 of lalr1.cc  */
#line 6643 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 975:

/* Line 678 of lalr1.cc  */
#line 6644 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 976:

/* Line 678 of lalr1.cc  */
#line 6645 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 977:

/* Line 678 of lalr1.cc  */
#line 6646 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 978:

/* Line 678 of lalr1.cc  */
#line 6647 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 979:

/* Line 678 of lalr1.cc  */
#line 6648 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 980:

/* Line 678 of lalr1.cc  */
#line 6649 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 981:

/* Line 678 of lalr1.cc  */
#line 6650 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 982:

/* Line 678 of lalr1.cc  */
#line 6656 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
          // EQName's namespace URI value is whitespace normalized according to the rules for the xs:anyURI type
          std::string uri = "\"" + SYMTAB((yysemantic_stack_[(3) - (1)].sval)) + "\"";
          std::string eqname = SYMTAB(driver.symtab.put_uri(uri.c_str(), uri.size())) + ":" + SYMTAB((yysemantic_stack_[(3) - (3)].sval));
          (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT(eqname.c_str())), true);
        }
    break;

  case 983:

/* Line 678 of lalr1.cc  */
#line 6662 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;



/* Line 678 of lalr1.cc  */
#line 11820 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1444;
  const short int
  xquery_parser::yypact_[] =
  {
      2974, -1444, -1444,  5639,  5639,  5639, -1444, -1444,    38,  1715,
     173, -1444, -1444, -1444,   668, -1444, -1444, -1444,   316,   328,
     755, -1444,   644,   383,   475,   785, -1444,   -36, -1444, -1444,
   -1444, -1444, -1444, -1444,   756, -1444,   510,   588, -1444, -1444,
   -1444, -1444,   552, -1444,   764, -1444,   601,   620, -1444,   204,
   -1444, -1444, -1444, -1444, -1444, -1444, -1444, -1444, -1444, -1444,
   -1444, -1444, -1444,    47,   486, -1444, -1444, -1444, -1444,   636,
    8895, -1444, -1444, -1444,   673, -1444, -1444, -1444,   648, -1444,
     693,   720, -1444, -1444, 12621, -1444, -1444, -1444, -1444, -1444,
   -1444, -1444, -1444,   754, -1444, -1444,   757,   780, -1444, -1444,
   -1444, -1444, -1444, -1444, -1444,  3271,  3567, 12621, -1444, -1444,
   -1444, -1444, -1444, -1444, -1444,   765, -1444, -1444,   801,  9775,
   -1444, 10065,   804,   810, -1444, -1444, -1444,   817, -1444,  8599,
   -1444, -1444, -1444, -1444, -1444, -1444,   791, -1444, -1444, -1444,
   -1444, -1444, -1444, -1444, -1444,    63,   735, -1444, -1444, -1444,
   -1444, -1444, -1444, -1444, -1444,   155,   800,   695, -1444,   686,
     127, -1444, -1444, -1444, -1444, -1444, -1444,   846, -1444, -1444,
     731,   745,   743, -1444, -1444,   831,   835, -1444, -1444, -1444,
   -1444, -1444, -1444, -1444, -1444, -1444, -1444, -1444, -1444, -1444,
   -1444, -1444, -1444, -1444, -1444, -1444, -1444, -1444, -1444, -1444,
   -1444, -1444, -1444, -1444, -1444, -1444, -1444, -1444, -1444, -1444,
   -1444, -1444, -1444, -1444, -1444, -1444, -1444, -1444, -1444, -1444,
   -1444, -1444, -1444, -1444, -1444, -1444, -1444, -1444, -1444, -1444,
   -1444, -1444, -1444, -1444, -1444, -1444, -1444, -1444, -1444,  5935,
     987, -1444,  6231, -1444, -1444,   104,    56, -1444, -1444, -1444,
   -1444, -1444, -1444, -1444, -1444, -1444, -1444, -1444, -1444, -1444,
   -1444,    62, -1444, -1444, -1444, -1444, -1444, -1444, -1444, -1444,
   -1444, -1444, -1444, -1444, -1444,  5639, -1444, -1444, -1444, -1444,
      17, -1444, -1444, -1444, -1444, -1444, -1444, -1444, -1444,   884,
   -1444,   803, -1444, -1444, -1444,   153, -1444, -1444, -1444, -1444,
   -1444, -1444, -1444, -1444,   828,   901, -1444,   599,   747,   610,
     534,   590,   226, -1444,   945,   806,   898,   900,  6527, -1444,
   -1444, -1444,   -13, -1444, -1444,  8599, -1444,   513, -1444,   852,
    8895, -1444,   852,  8895, -1444, -1444, -1444,   768, -1444, -1444,
   -1444, -1444, -1444, -1444, -1444, -1444, -1444, -1444, -1444, -1444,
   -1444, -1444, -1444, -1444, -1444, -1444, -1444, -1444, -1444, -1444,
   -1444, -1444, -1444, -1444, -1444, -1444, -1444, -1444, -1444, -1444,
   -1444, -1444, -1444, -1444, -1444, -1444, -1444, -1444, -1444, -1444,
     879,   863,   853, -1444, -1444, -1444, -1444, -1444,   829, -1444,
    5639,   830,   832,   855,   982,   503,   542,    -8, 12905, 12621,
     356,   966, 12621,   866,   904,   133,  9775, -1444, -1444,   674,
     551,   777, 12621, -1444, -1444, -1444, -1444, -1444,   732, 12621,
     726,   728,   646,   723,   627,   411, -1444, -1444, -1444, -1444,
     640, -1444,  9775,  5639,   841,  5639,    99,  6823, 10633,   746,
     752, 12621,   914,    12,   876,  6823,  1033,    65,    49, 12621,
     920,   897,   933, -1444,  6823,  9483, 12621, 12621, 12621,  5639,
     854,  6823,  6823, 12621,  5639,   889,   890, -1444, -1444, -1444,
    6823, 10917, -1444,   891, -1444,   892, -1444, -1444, -1444, -1444,
     895, -1444,   896, -1444, -1444, -1444, -1444, -1444,   906, -1444,
   -1444, -1444, -1444, -1444, -1444, -1444, -1444, -1444, -1444, -1444,
   -1444, -1444, -1444, -1444, -1444, -1444, -1444, -1444, -1444, -1444,
   -1444, -1444, -1444, -1444, -1444, -1444, 12621, -1444, -1444, -1444,
   -1444, -1444, -1444, -1444, -1444, -1444, -1444, -1444, -1444,   903,
   12621, -1444, -1444, -1444,   862,  3863,   907,   912,   913, 12621,
    5639, -1444,   917,   219, -1444,   497,  1013,  6823, -1444, -1444,
      95, -1444, -1444, -1444,  1035, -1444, -1444, -1444, -1444,  6823,
     843, -1444,  1027,  6823,  6823,   880,  6823,  6823,  6823,  6823,
     842, 12621,   881,   883,  6823,  6823,  3271,   844, -1444, -1444,
   -1444, -1444,  1715,   785,    68,    76,  1074,  7119,  7119,  7415,
    7415, -1444,   884,   648, -1444,  6823, -1444,   968,   644,   -36,
     919,   918,   922,  5639,  6823, -1444, -1444, -1444, -1444, -1444,
   -1444, -1444, -1444,  7711,  7711,  7711, -1444,  7711,  7711, -1444,
    7711, -1444,  7711, -1444, -1444, -1444, -1444, -1444, -1444, -1444,
    7711,  7711,  1021,  7711,  7711,  7711,  7711,  7711,  7711,  7711,
    7711,  7711,  7711,  7711,   864,  1001,  1002,  1003, -1444, -1444,
   -1444,  4159, -1444, -1444,  8599,  8599,  6823,   852, -1444, -1444,
     852, -1444,  4455,   852,  9775,   950,  4751, -1444, -1444, -1444,
     280, -1444, -1444, -1444, -1444, -1444,   993,   994,   383,  1072,
   -1444, -1444, 12905,   893,   228, 12621,   943,   944,   893,   982,
     978,   974, -1444, -1444, -1444, -1444, -1444,    51,   861,     7,
   -1444,   809, -1444, -1444, -1444, -1444, 12621,   967,  6823,   992,
   -1444, -1444, 12621, 12621, -1444,   980,   929,  5639, -1444,   930,
     892,   588, -1444,   928,   931,    16, -1444,   220,   229, -1444,
   -1444,  1009, -1444,    24, 12621,    13, 12621,  1022,   234, -1444,
    5639, -1444,   239, -1444,  9775,  1023,  1073,  9775,   982,  1024,
      34, 12621,  6823,   -36,    18,   935, -1444,   936,   937,   938,
      20, -1444,    42,   942, -1444,   248,   264,   975, -1444,   946,
    5639,  5639,   199, -1444,   271,   303,    41,  6823,   166, -1444,
   -1444,  6823,  6823,  6823, -1444,  6823, -1444,  6823, 12621,  1013,
   -1444,   222,   246, -1444, -1444, -1444,   253, -1444,   206, -1444,
   -1444, -1444,   126,   196,  1032,   899,   905,     4, -1444,   989,
   -1444, -1444,   947,   305,  5047,   290,  9191,   844, -1444,   104,
     109,  1099,  1099, -1444, -1444,    82, -1444, -1444,    85, -1444,
     788, -1444, -1444, -1444, -1444, -1444, -1444, 12621,   964,  6823,
    1018, -1444, -1444, -1444,   901, -1444, -1444, -1444, -1444, -1444,
    7711, -1444, -1444, -1444,    37,   534,   534,   -19,   590,   590,
     590,   590,   226,   226, -1444, -1444, 12053, 12053, 12621, 12621,
   -1444,   336, -1444, -1444,   197, -1444, -1444, -1444,   341, -1444,
   -1444, -1444,   368, -1444,   387, -1444,   527,   617,   317, -1444,
     383, -1444, -1444, -1444, -1444, -1444, -1444, -1444, -1444, -1444,
   -1444,   893, -1444,  1006, 12337,   997,  6823, -1444, -1444, -1444,
    1045,   982,   982,   893, -1444,   820,   982,   614, 12621,   544,
     611,  1111, -1444, -1444,   856,    29, -1444, -1444, -1444, -1444,
   -1444, -1444, -1444, -1444, -1444, -1444, -1444,    51,   490,   661,
   -1444,   921,   398,  6823, -1444, 12621,    33,   845,   982, -1444,
   -1444, -1444, -1444,   990, 12621, -1444, 12621, -1444,  1028,  1025,
   12053,  1030,  6823,   -54,   998,    25,   589,   902, -1444, -1444,
     604,    13,  1045, 12053,  1031,  1055,   969,   954,  1026,   982,
     995,  1029,  1060,   982,  6823,   -68, -1444, -1444, -1444,  1007,
   -1444, -1444, -1444, -1444,  1041,  6823,  6823,  1015, -1444,  1063,
    1064,  5639, -1444,   983,   985,  1017, 12621, -1444, 12621, -1444,
    6823,  1037,   976,  6823,   393,   420,   422,  1136, -1444,   311,
   -1444,   137, -1444, -1444,  1143, -1444,   707,  6823,  6823,  6823,
     712,  6823,  6823,  6823,  6823,  6823,  6823,  1057,  6823,  6823,
   -1444,  8007,  1034,  1036,  1038,  1040,   803,   577,   939, -1444,
     507, -1444,    87,    74,   788,  7415,  7415,  7415,  1100, -1444,
    6823,   749,  1075, -1444, 12621,  1076, -1444, -1444,  6823,    37,
      67,   417, -1444,   910,   139,   923,   925, -1444, -1444,   777,
   -1444,   924,   334,  1042,  1043, 12337,  1046, -1444,    -9, -1444,
   -1444, -1444, -1444, -1444, -1444, -1444, -1444, -1444,  1044, -1444,
   -1444, -1444,  6823, -1444, -1444,   280, -1444, -1444, -1444, -1444,
   -1444, -1444, -1444,   557, -1444,  1156,   744, -1444, -1444, -1444,
   -1444, -1444, -1444, -1444, -1444, -1444,   915, -1444, -1444,  1157,
   -1444, -1444, -1444, -1444, -1444,   621,  1159, -1444,   654, -1444,
   -1444, -1444,   891,   328,   895,   510,   896,   906,   800,   960,
      -9,   971,   977,  8303,   926,   908, -1444,  1045,   490, -1444,
     979,  1014,  5639,  1020,  1039,  1065,  1047,  1050, 12621,   251,
   -1444, 12621, -1444,  6823,  1061,  6823,  1083,  6823,     1,  1069,
    6823,  1077, -1444,  1094,  1101,  6823, 12621,   827,  1145, -1444,
   -1444, -1444, -1444, -1444, -1444, 12053, -1444,  5639,   982,  1114,
   -1444, -1444, -1444,   982,  1114, -1444,  6823,  1085,  5639, 12621,
   -1444, -1444,  6823,  6823,   697, -1444,    32,   748, -1444, 11201,
     758, -1444,   762, -1444,  1048, -1444, -1444,  5639,  1051,  1053,
   -1444,  6823, -1444, -1444,  1049,  1063,  1125, -1444,  1096, -1444,
     215, -1444, -1444,  1219, -1444, -1444,  5639, 12621, -1444,   464,
   -1444, -1444, -1444,  1058,   999,  1011, -1444, -1444, -1444,  1019,
    1059, -1444, -1444, -1444, -1444, -1444,  1005, 12621,  1066, -1444,
   -1444,  6823,  6823,  6823,  5343,  8007,  9191,   939, -1444,  1127,
    9191, -1444,  1099,   263, -1444, -1444, -1444,  1075, -1444,   982,
   -1444,   826, -1444,    46,  1144, -1444,  6823,  1147,  1018,   375,
    1067, -1444,    37,  1008, -1444, -1444,    91, -1444,  -122,   -26,
    1010,    37,  -122,  7711, -1444,   150, -1444, -1444, -1444, -1444,
   -1444, -1444,    37,  1110,   981,   861,   -26, -1444, -1444,   973,
    1182, -1444, -1444, -1444, 10349,  1078,  1080,  1082, -1444, -1444,
   -1444, -1444, -1444, -1444, -1444, -1444, -1444, -1444, -1444, -1444,
   -1444,  1232,   272,  1234,   272,  1000,  1163, -1444, -1444, -1444,
   -1444,  1102, 12621,  1016, -1444,   960,  8303, -1444,  1091, -1444,
   -1444, -1444, -1444, -1444, -1444,  6823,  1129, -1444, -1444,  6823,
   -1444,   394, -1444,  6823,  1132,  6823, -1444,  6823, 12621, 12621,
   -1444,   675, -1444,  6823, -1444,  1154,  1164,  1185,   982,  1114,
   -1444,  6823,  1105, -1444, -1444, -1444,  1106, -1444,   117,  6823,
    5639,  1107,   214, -1444, 12621,  1112, 11485,   455, -1444, 11769,
    1113, -1444, -1444,  1117, -1444, -1444, -1444,  6823,   767,  1136,
   12621,   521, -1444,  1118,  1136, 12621, -1444, -1444,  6823,  6823,
    6823,  6823,  6823, -1444,  6823,   439,   453,   462,   546, -1444,
   12621, -1444, -1444, -1444, -1444,  1144, -1444, -1444, -1444,   982,
   -1444, -1444, -1444, -1444, -1444,  1119,  7711, -1444, -1444, -1444,
   -1444, -1444,    66,  7711,  7711,   564, -1444,   923, -1444,   452,
   -1444,   925,    37,  1151, -1444, -1444,  1052, -1444, -1444, -1444,
   -1444,  1201,  1120, -1444,   468, -1444, -1444, -1444, -1444,   386,
     386, -1444,   272, -1444, -1444,   494, -1444,  1267,   -26,  1208,
    1121,  8303,   -43,  1054, -1444,  1139, -1444, -1444,  6823, -1444,
    6823,  1165, -1444,  6823, -1444, -1444, -1444,  1255, -1444, -1444,
    8007,  6823,   982, -1444, -1444, -1444,  6823,  6823, -1444, -1444,
   -1444,  8007,  8007,  1216,  5639, 12621,  1131, 12621,  6823, 12621,
    1135,  8007, -1444,   493,     5,  1136, 12621, -1444,  1122,  1136,
   -1444, -1444, -1444, -1444, -1444, -1444,  1128,  1063,  1064,  6823,
    1197, -1444,   516, -1444, -1444, -1444,   590,  7711,  7711,   -19,
     638, -1444, -1444, -1444, -1444, -1444, -1444,  6823, -1444, 12053,
   -1444, 12053,  1227, -1444, -1444, -1444,  1294, -1444, -1444, -1444,
    1070,  1221, -1444, -1444,  1222, -1444,   782, 12621,  1212,  1115,
   12621,  8303, -1444, -1444,  6823, -1444,  1213, -1444, -1444,  1114,
   -1444, -1444, 12053, -1444, -1444,  1241,  6823,  1152, -1444,  1242,
    8007, -1444, 12621,   509,    69, -1444,  1146,  1136, -1444,  1148,
    8007,   770,   392, 12621,  1225,  1040,   -19,   -19,  7711,   459,
   -1444, -1444, 12053, -1444, -1444,  1208,  8303, -1444,  1144,  1056,
   12621,  1229,  1116,  1222, -1444, 12621,  1162, 12053,  5639, 12053,
    1167, -1444, -1444,  1251,   514, -1444, -1444, -1444, -1444,  1166,
     566, -1444, -1444, -1444,  1155, -1444,  1236, -1444,   520, 12621,
   -1444,   -19, -1444, -1444, -1444, -1444, -1444,  6823,  1062, 12621,
    1238, -1444,  5639,  1171, -1444, -1444,  1172,  6823, -1444, -1444,
   -1444, -1444, -1444, -1444, -1444, 12621,  1244,  1206,   522, -1444,
    1071,  1068, 12621, -1444, -1444,  6823,  8007,  1174, 12621, -1444,
    1247,  1040,  1081,  6823,  1084,  8007,   526, 12621, -1444,  8303,
   -1444,  8303,  1248,  1206,  1181, -1444,  1177, 12621, -1444,  1040,
    1089,  1191, -1444, 12621,  1206,  1126, -1444,  1261, 12621,  1086,
    8303, -1444
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
       179,   460,   461,   182,   182,   182,   784,   983,   609,   875,
     884,   825,   789,   787,   769,   876,   879,   832,   793,   770,
     771,   935,   824,   885,   773,   882,   854,   834,   809,   829,
     830,   880,   877,   828,   775,   883,   776,   777,   923,   937,
     922,   826,   845,   839,   778,   827,   780,   779,   924,   863,
     831,   806,   947,   948,   949,   950,   951,   952,   953,   954,
     955,   956,   957,   971,   978,   853,   849,   840,   820,   768,
       0,   848,   856,   864,   972,   844,   481,   821,   822,   878,
     973,   979,   841,   858,     0,   487,   449,   483,   851,   786,
     842,   843,   871,   846,   862,   870,   977,   980,   792,   833,
     873,   482,   861,   866,   772,     0,     0,     0,   397,   859,
     869,   874,   872,   852,   838,   925,   836,   837,   974,     0,
     396,     0,   975,   981,   867,   823,   847,   976,   427,     0,
     459,   868,   850,   857,   865,   860,   926,   814,   819,   818,
     817,   816,   815,   781,   835,     0,   785,   881,   807,   914,
     913,   915,   791,   790,   810,   920,   774,   912,   917,   918,
     909,   813,   855,   911,   921,   919,   910,   811,   916,   928,
     931,   932,   929,   930,   927,   782,   933,   934,   936,   901,
     900,   887,   805,   798,   894,   890,   808,   804,   903,   904,
     794,   795,   788,   797,   899,   898,   895,   891,   908,   902,
     897,   893,   886,   796,   907,   906,   800,   802,   801,   892,
     896,   888,   803,   889,   799,   905,   958,   959,   960,   961,
     962,   963,   939,   940,   938,   944,   945,   946,   941,   942,
     943,   812,   964,   965,   966,   967,   968,   969,   970,   179,
       0,     2,   179,     5,     7,    19,     0,    24,    27,    32,
      33,    34,    35,    36,    37,    38,    28,    54,    55,    29,
      30,     0,    72,    75,    76,    31,    77,    78,    79,    80,
      81,    82,    14,   176,   177,   178,   185,   187,   478,   188,
       0,   189,   190,   191,   192,   193,   194,   195,   198,   183,
     226,   233,   228,   255,   261,     0,   253,   254,   235,   229,
     197,   230,   196,   231,   234,   352,   354,   356,   366,   370,
     372,   375,   380,   383,   386,   388,   390,   392,     0,   394,
     400,   402,     0,   418,   401,   423,   426,   428,   431,   433,
       0,   438,   435,     0,   446,   456,   458,   432,   462,   469,
     479,   470,   471,   472,   475,   476,   473,   474,   494,   496,
     497,   498,   495,   543,   544,   545,   546,   547,   548,   455,
     583,   575,   582,   581,   580,   577,   579,   576,   578,   480,
     477,   610,   611,    39,   236,   237,   239,   238,   240,   232,
       0,   457,   767,   783,   875,   884,   882,   785,     0,   180,
     181,     0,     0,   116,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   142,   143,     0,
       0,     0,     0,   138,   139,   140,   141,   148,     0,     0,
       0,     0,     0,     0,     0,     0,   114,   120,   122,   123,
       0,   136,     0,     0,     0,   182,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   280,   281,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   451,   454,   441,
       0,     0,   764,   769,   793,   771,   824,   885,   773,   834,
     775,   845,   778,   780,   779,   863,   971,   978,   768,   972,
     822,   973,   979,   846,   977,   980,   925,   974,   975,   981,
     976,   926,   920,   912,   918,   909,   811,   931,   932,   929,
     782,   933,   447,   457,   767,   439,     0,   205,   440,   443,
     769,   770,   771,   775,   776,   777,   778,   768,   774,   484,
       0,   445,   444,   200,     0,     0,   773,   780,   779,     0,
     182,   485,   933,     0,   233,     0,   510,     0,   450,   765,
       0,   766,   421,   422,     0,   453,   452,   442,   425,     0,
       0,   539,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     3,     1,
       6,     8,     0,     0,     0,     0,     0,   179,   179,   179,
     179,   186,   184,     0,   203,     0,   211,     0,     0,     0,
       0,     0,     0,     0,     0,   216,   241,   260,   256,   262,
     257,   259,   258,     0,     0,     0,   411,     0,     0,   409,
       0,   361,     0,   410,   403,   408,   407,   406,   405,   404,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   399,   398,
     395,     0,   419,   424,     0,     0,     0,   434,   466,   437,
     436,   448,     0,   463,     0,     0,     0,   550,   552,   556,
       0,    43,    40,    41,    44,    45,     0,     0,     0,     0,
      46,    47,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   620,   621,   622,   145,   144,     0,    99,   152,
     149,     0,   151,   150,   147,   146,     0,   108,     0,     0,
     115,   121,     0,     0,   137,     0,     0,     0,   589,     0,
       0,     0,   585,     0,     0,     0,   599,     0,     0,   243,
     244,   263,   264,     0,     0,     0,     0,   128,     0,   132,
     182,   613,     0,    56,     0,    65,     0,     0,     0,    57,
       0,     0,     0,     0,     0,   764,   590,     0,     0,     0,
       0,   325,     0,     0,   588,     0,     0,     0,   607,     0,
       0,     0,     0,   593,     0,     0,   206,     0,     0,   201,
     199,     0,     0,     0,   484,     0,   486,     0,   511,   510,
     507,     0,     0,   541,   540,   420,     0,   538,     0,   633,
     634,   584,     0,     0,     0,     0,     0,     0,   639,     0,
     214,   215,     0,     0,     0,     0,     0,   219,   220,    20,
       0,    21,     0,     4,    25,     0,    11,    26,     0,    15,
     875,    73,    12,    74,    16,   204,   227,     0,     0,     0,
       0,   217,   242,   298,   353,   355,   359,   365,   364,   363,
       0,   360,   357,   358,     0,   374,   373,   371,   377,   378,
     379,   376,   381,   382,   385,   384,     0,     0,     0,     0,
     416,     0,   429,   430,     0,   467,   464,   492,     0,   982,
     612,   490,     0,   609,     0,   118,     0,     0,     0,    98,
       0,    88,    90,    91,    92,    93,    95,    96,    97,    89,
      94,    84,    85,     0,     0,   104,     0,   100,   102,   103,
     110,     0,     0,    83,    42,     0,     0,     0,     0,     0,
       0,     0,   714,   719,     0,     0,   715,   749,   702,   704,
     705,   706,   708,   710,   709,   707,   711,     0,     0,     0,
     153,     0,     0,     0,   107,     0,   156,     0,     0,   555,
     549,   586,   587,     0,     0,   603,     0,   600,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   245,   246,
       0,   251,   134,     0,     0,   129,     0,     0,     0,     0,
       0,     0,    58,     0,     0,     0,   279,   285,   282,     0,
     592,   591,   598,   606,     0,     0,     0,     0,   554,     0,
       0,     0,   412,     0,     0,     0,     0,   596,     0,   594,
       0,   207,     0,     0,     0,     0,     0,   510,   508,     0,
     499,     0,   488,   489,     0,     9,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     212,     0,   773,   780,   779,   933,     0,     0,     0,   650,
       0,   221,     0,     0,     0,   179,   179,   179,     0,   252,
       0,   309,   305,   307,     0,   299,   300,   362,     0,     0,
       0,     0,   680,   368,   653,   657,   659,   661,   663,   666,
     673,   674,   682,   885,   772,     0,   781,   387,   561,   567,
     568,   570,   614,   615,   571,   574,   389,   391,   558,   393,
     417,   468,     0,   465,   491,     0,   117,    52,    53,    50,
      51,   125,   124,     0,    86,     0,     0,   105,   106,   111,
      70,    71,    48,    49,    69,   720,     0,   723,   750,     0,
     713,   712,   717,   716,   748,     0,     0,   725,     0,   721,
     724,   703,     0,     0,     0,     0,     0,     0,     0,   154,
     160,     0,     0,     0,     0,     0,   109,   112,     0,   157,
       0,     0,   182,     0,     0,   607,     0,     0,     0,     0,
     560,     0,   266,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   247,     0,     0,     0,     0,   292,     0,   289,
     294,   250,   135,   130,   133,     0,   202,     0,     0,    67,
      61,    64,    63,     0,    59,   283,     0,     0,   182,     0,
     323,   327,     0,     0,     0,   330,     0,     0,   336,     0,
       0,   343,     0,   347,     0,   414,   413,   182,     0,     0,
     208,     0,   210,   324,     0,     0,     0,   511,     0,   500,
       0,   534,   531,     0,   535,   536,     0,     0,   530,     0,
     505,   533,   532,     0,     0,     0,   626,   627,   623,     0,
       0,   631,   632,   628,   637,   635,     0,     0,     0,   641,
     213,     0,     0,     0,     0,     0,     0,   642,   643,     0,
       0,   222,    22,     0,    13,    17,    18,   306,   318,     0,
     319,     0,   310,   311,   312,   313,     0,   302,     0,     0,
       0,   664,   677,     0,   367,   369,     0,   696,     0,     0,
       0,     0,     0,     0,   652,   654,   655,   691,   692,   693,
     695,   694,     0,     0,   668,   667,     0,   671,   675,   689,
     687,   686,   679,   683,     0,     0,     0,     0,   564,   566,
     565,   562,   559,   493,   119,   127,   126,    87,   101,   737,
     718,     0,   742,     0,   742,   731,   726,   155,   161,   163,
     162,     0,     0,     0,   113,   158,     0,    23,     0,   604,
     605,   608,   601,   602,   265,     0,     0,   278,   270,     0,
     274,     0,   268,     0,     0,     0,   287,     0,     0,     0,
     249,   290,   293,     0,   131,     0,     0,    66,     0,    60,
     284,     0,     0,   326,   328,   333,     0,   331,     0,     0,
       0,     0,     0,   337,     0,     0,     0,     0,   344,     0,
       0,   348,   415,     0,   597,   595,   209,     0,     0,   510,
       0,     0,   542,     0,   510,     0,   506,    10,     0,     0,
       0,     0,     0,   640,     0,     0,     0,     0,     0,   644,
       0,   651,   322,   320,   321,   314,   315,   316,   308,     0,
     303,   301,   681,   672,   678,     0,     0,   751,   752,   762,
     761,   760,     0,     0,     0,     0,   753,   658,   759,     0,
     656,   660,     0,     0,   665,   669,     0,   690,   685,   688,
     684,     0,     0,   572,     0,   569,   619,   563,   738,     0,
       0,   736,   743,   744,   740,     0,   735,     0,   733,     0,
       0,     0,     0,     0,   159,     0,   551,   267,     0,   276,
       0,     0,   272,     0,   275,   288,   296,   297,   291,   248,
       0,     0,     0,    62,   286,   557,     0,     0,   334,   338,
     332,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   553,     0,     0,   510,     0,   537,     0,   510,
     624,   625,   629,   630,   636,   638,     0,     0,     0,     0,
       0,   645,     0,   317,   304,   676,   763,     0,     0,   755,
       0,   701,   700,   699,   698,   697,   662,     0,   754,     0,
     616,     0,     0,   747,   746,   745,     0,   739,   732,   730,
       0,   727,   728,   722,   164,   166,   168,     0,     0,     0,
       0,     0,   271,   269,     0,   277,     0,   218,   351,    68,
     329,   335,     0,   349,   345,     0,     0,     0,   339,     0,
       0,   341,     0,   520,   514,   509,     0,   510,   501,     0,
       0,     0,     0,     0,     0,     0,   757,   756,     0,     0,
     617,   573,     0,   741,   734,     0,     0,   170,   169,     0,
       0,     0,     0,   165,   273,     0,     0,     0,     0,     0,
       0,   528,   522,     0,   521,   523,   529,   526,   516,     0,
     515,   517,   527,   503,     0,   502,     0,   649,     0,     0,
     223,   758,   670,   618,   729,   167,   171,     0,     0,     0,
       0,   295,     0,     0,   342,   340,     0,     0,   513,   524,
     525,   512,   518,   519,   504,     0,     0,     0,     0,   172,
       0,     0,     0,   350,   346,     0,     0,     0,     0,   646,
       0,     0,     0,     0,     0,     0,     0,     0,   224,     0,
     174,     0,     0,     0,     0,   173,     0,     0,   647,     0,
       0,     0,   225,     0,     0,     0,   648,     0,     0,     0,
       0,   175
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1444, -1444,  -226,  1138, -1444,  1137,  1141, -1444,  1140,  -534,
   -1444, -1444, -1444, -1444, -1444, -1444, -1444, -1444, -1444, -1444,
    -952, -1444, -1444, -1444, -1444,  -217,  -544, -1444,   692,  -760,
   -1444, -1444, -1444, -1444, -1444,   270,   483, -1444, -1444, -1444,
     965, -1444, -1444,   970, -1444, -1444,  -622, -1444,   418, -1444,
     961, -1444,   235,  -897, -1444,  -215,  -262, -1444,  -547, -1444,
       9,    70,    57,  -259,  -175, -1444,  -833, -1444, -1444,   805,
   -1444, -1444, -1444, -1444, -1444, -1444, -1444, -1444, -1444, -1444,
     580,   -98,  1274,     0, -1444, -1444, -1444, -1444,   428, -1444,
   -1444,  -266, -1444,     6, -1444, -1444,   232,  -707,  -703, -1444,
   -1444,   649, -1444, -1444,    10,   216, -1444, -1444, -1444,   106,
   -1444, -1444,   345,   111, -1444, -1444,   115, -1246, -1444,   882,
     202, -1444, -1444,   200,  -967, -1444, -1444,   198, -1444, -1444,
   -1184, -1181, -1444,   191, -1444, -1444,   807,   808, -1444,  -533,
   -1444, -1444,  -620,   322,  -615,   319,   321, -1444, -1444, -1444,
   -1444, -1444,  1103, -1444, -1444, -1444, -1444,  -816,  -304, -1128,
   -1444,   -93, -1444, -1444, -1444, -1444, -1444, -1444, -1444,   -20,
    -782, -1444, -1444,   563,   159, -1444,  -653, -1444, -1444, -1444,
   -1444, -1444, -1444, -1444,   751, -1444,  -984, -1444,   178, -1444,
     630,  -787, -1444, -1444, -1444, -1444, -1444,  -257,  -250, -1142,
    -890, -1444, -1444, -1444, -1444, -1444, -1444, -1444, -1444, -1444,
   -1444,   556,  -743,  -765,   276,  -839, -1444,    97,  -766, -1444,
   -1444, -1444, -1444, -1444, -1444, -1444,  1004,  1012,  -286,   472,
     314, -1444, -1444, -1444, -1444, -1444, -1444, -1444, -1444, -1444,
   -1444, -1444, -1444, -1444, -1444,   163, -1444, -1444,   154,  -908,
     158, -1018, -1444, -1444, -1444,   124,   114,   -45,   369, -1444,
   -1444, -1444, -1444, -1444, -1444, -1444, -1444, -1444, -1444, -1444,
   -1444, -1444,   123, -1444, -1444, -1444,   -37,   365,   508, -1444,
   -1444, -1444, -1444, -1444,   308, -1444, -1444, -1443, -1444, -1444,
   -1444,  -532, -1444,    93, -1444,   -53, -1444, -1444, -1444, -1444,
   -1211, -1444,   140, -1444,  -367,  -362,   911,    44, -1444
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   240,   822,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
    1199,   748,   258,   259,   260,   261,   262,   263,   901,   902,
     903,   264,   265,   266,   907,   908,   909,   267,   424,   425,
     426,   884,   268,   427,   428,   429,   444,   738,   739,   430,
     431,   269,  1149,   940,   270,  1604,  1605,   271,   272,   273,
     534,   274,   275,   276,   277,   278,   741,   279,   280,   517,
     281,   282,   283,   284,   285,   286,   605,   287,   288,   817,
     818,   289,   290,   544,   292,   606,   442,   970,   971,   293,
     607,   294,   609,   545,   296,   731,   732,  1187,   451,   297,
     452,   453,   735,  1188,  1189,  1190,   610,   611,  1065,  1066,
    1460,   612,  1062,  1063,  1292,  1293,  1294,  1295,   298,   760,
     761,   299,  1214,  1215,  1408,   300,  1217,  1218,   301,   302,
    1220,  1221,  1222,  1223,   303,   304,   305,   306,   850,   307,
    1304,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   630,   631,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   657,   658,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   878,   347,   348,   349,  1249,   789,
     790,   791,  1635,  1679,  1680,  1673,  1674,  1681,  1675,  1250,
    1251,   350,   351,  1252,   352,   353,   354,   355,   356,   357,
     358,  1097,   965,  1087,  1341,  1088,  1494,  1089,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   767,  1164,
     369,   370,   371,   372,  1091,  1092,  1093,  1094,   373,   374,
     375,   376,   377,   378,   807,   808,   379,  1277,  1278,  1571,
    1050,  1073,  1314,  1315,  1074,  1075,  1076,  1077,  1078,  1324,
    1484,  1485,  1079,  1327,  1080,  1465,  1081,  1082,  1332,  1333,
    1490,  1488,  1316,  1317,  1318,  1319,  1584,   698,   928,   929,
     930,   931,   932,   933,  1139,  1510,  1601,  1140,  1508,  1599,
     934,  1354,  1505,  1501,  1502,  1503,   935,   936,  1320,  1328,
    1475,  1321,  1471,  1305,   380,   550,   381,   382,   383
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int xquery_parser::yytable_ninf_ = -765;
  const short int
  xquery_parser::yytable_[] =
  {
       291,   577,  1019,   291,   291,   291,   295,   985,   543,   295,
     295,   295,   388,   391,   392,   857,   591,   885,   652,   997,
     588,   858,   859,   860,   861,  1361,   963,   671,   585,   608,
     964,  1204,  1216,  1011,  1049,   590,   558,  1248,  1071,  1418,
     826,   829,   832,   834,   691,   831,   833,  1456,  1457,  1159,
     512,  1300,  1428,   824,   827,  1112,   888,   586,   959,  1176,
     390,   390,   390,   586,   883,  1116,  1602,   967,  1472,   586,
     715,  1206,  1607,   389,   389,   389,   472,   586,  1241,   449,
     745,   749,   846,   586,   847,   848,   586,   849,   586,   851,
    1173,   560,   472,   757,   883,  1677,  1633,   852,   853,   938,
    1090,  1090,  1096,   793,   917,   291,   918,  1436,  1037,   394,
     395,   295,   396,   397,   514,  1486,   960,  1577,   961,   961,
     595,   593,   595,  1136,   994,  1158,   960,   736,   514,  1409,
     400,   591,  1338,   960,   960,   582,   633,   651,  1090,  1137,
    1053,  1114,   720,  1469,    76,  1383,  1241,  1242,   919,  1289,
    1470,   514,   583,  1114,   634,   676,  -764,   583,    87,   746,
     721,   121,   535,   514,  1339,   514,   467,  1119,   962,  1177,
    1291,   677,  1150,   984,    76,   389,   686,   592,  1608,   687,
    1010,  1340,  1138,   101,  1283,  1634,   996,  1068,    87,  1244,
    1069,  1245,  1578,   597,  1090,  1170,   737,   953,   598,   989,
    1678,  1072,   450,   599,   594,   995,   747,  1090,  1193,  1573,
     688,   121,  1694,   101,  1409,  1410,   450,  1068,  1026,  1246,
    1069,   600,   744,  1181,  1241,  1242,   968,  1473,  1474,  1192,
    1238,   406,   653,  1306,   450,  1038,   689,  1243,  1515,   291,
     939,   121,   291,   587,  1306,   295,  1336,  1418,   295,   589,
    1412,  1399,  1357,  1071,  1071,   819,  1248,  1244,  1178,  1245,
    1174,  1609,  1179,   821,   969,  1248,   939,   794,  1113,  1055,
     994,   450,  1057,   561,  1282,   291,   591,   831,   833,   608,
    1346,   295,  1207,   722,  1464,   824,   827,  1246,  1030,  1436,
     409,   107,   592,  1070,   450,   450,   463,  1600,   690,   920,
    1537,   595,   879,   595,  1467,  1307,   686,   883,   119,   687,
     659,  1409,   921,   661,   922,  1243,  1307,  1067,   601,  1090,
     904,   602,   914,   595,   954,   923,   924,   925,  1247,   926,
     432,   927,   411,   956,  1024,  1244,   603,  1245,   974,   725,
    1027,  1028,  1468,   595,   841,   961,   145,   742,   569,  1020,
     595,  1013,   595,   570,   464,  1029,   754,   595,   820,   642,
    1657,   604,   905,   765,   766,  1246,   689,   906,   595,   107,
     825,   828,   772,   643,   514,  1006,   563,   514,   564,  1101,
    1005,   982,   978,  1606,  1641,   981,   119,    76,  1308,  1309,
     291,  1310,  1150,  1025,   595,  1375,   295,  1542,  1311,  1308,
    1309,    87,  1310,   786,   955,  1499,  1430,  1008,  1312,   595,
    1031,  1032,  1696,   957,  1364,  1021,  1072,  1072,   975,  1312,
    1313,   465,   466,   977,   145,  1033,   101,  1022,   690,  1090,
    1394,  1313,   999,   291,  1023,   291,   393,   592,  1239,   295,
     595,   295,   678,   514,   719,  1102,   514,  1248,  1000,   792,
     514,  1111,  1344,  1090,  1415,  1007,   514,   398,   591,   291,
    1418,   796,  1376,   514,   291,   295,   435,   740,  1514,  1500,
     295,  1048,  1102,  1241,  1242,  1384,   514,   813,   815,   595,
    1351,   436,   514,  1606,   401,   514,  1071,  1009,   961,  1041,
     717,  1105,   390,   514,  1049,  1071,   595,   595,  1451,   514,
     514,   514,   514,   716,  1240,   389,  1071,   514,  1284,  1285,
    1286,   831,   833,   831,  1671,   514,   717,  1100,  1241,  1671,
     709,   717,   680,  1241,   595,  1103,   595,  1142,  1606,   763,
    1241,  1242,  1143,   720,   769,   291,   443,   597,  1520,  1353,
     291,   295,   598,   595,  1120,  1121,   295,   599,  1144,  1124,
    1145,   721,  1104,   871,   681,   591,  1462,   595,   874,  1146,
     514,   872,   873,   595,  1243,   600,   595,  1302,  1090,  1493,
    1547,  1106,  1591,  1687,   514,  1241,   291,  1234,  1329,  1330,
    1619,  1161,   295,   514,  1244,  1147,  1245,   291,   291,   291,
     291,   121,  1677,   295,   295,   295,   295,   390,  1596,  1056,
    1412,  1331,  1052,   291,  1235,   468,  1236,   633,  1632,   295,
     389,  1745,  1200,  1746,  1246,   514,  1200,   597,   107,   592,
    1644,  1243,   598,  1566,  1716,   634,  1730,   599,   445,  1244,
    1742,  1245,  1761,   814,  1244,   119,  1245,  1567,  1548,  1672,
    1692,  1244,  1554,  1245,  1709,   600,  1568,  1558,   636,  1072,
    1090,  1546,  1592,  1090,  1550,  1435,  1183,  1274,  1072,  1246,
    1279,  1184,   601,   456,  1246,   602,  1071,   458,  1163,  1072,
    1166,  1246,  1107,   145,  1521,   107,  1548,   637,  1597,  1185,
     787,   960,   672,  1014,  1015,  1016,  1244,   815,  1245,  1108,
     638,  1345,   119,  1479,  1154,   673,  1569,  1712,   961,  1570,
    1645,   654,   655,  1155,  1717,   604,  1731,   740,   514,   439,
    1743,  1148,  1556,  1280,   440,  1351,  1246,   291,  1581,  1186,
    1228,   674,  1229,   295,   639,  1582,   890,  1183,   615,   514,
     145,  1352,  1184,  1180,   675,  1583,   616,   617,   831,   618,
     291,   457,   601,  1676,  1682,   602,   295,   619,  1136,   976,
     514,   620,  1280,   621,   461,   469,   514,   514,   622,   441,
    1275,   707,  1109,   516,  1137,   633,   708,   652,  1636,   961,
     291,   291,  1639,   462,  1353,   623,   295,   295,   514,  1110,
     514,   608,  1270,   634,  1676,   604,   470,   640,   514,   471,
    1682,   514,   515,   633,  1213,   514,   641,   390,   624,   625,
     626,   627,   628,   629,  1130,   635,   407,  1406,   446,  1729,
     389,   634,   518,   393,  1046,  1131,   875,   447,   433,   875,
    1047,   434,   875,  1090,  1650,  1090,  1651,   717,   717,  1072,
    1581,  1397,   514,  1648,   398,  1748,  1200,  1582,   408,   519,
    1003,  1004,  1288,   399,   448,  1213,  1756,  1583,   695,   696,
    1684,  1576,  1289,  1579,  1580,  1416,  1090,  1666,  1411,  1419,
     514,   401,  1290,  1658,  1416,   402,   410,  1416,  1417,   530,
     577,  1132,  1420,  1291,   960,  1281,   531,  1553,   905,  1183,
    1686,   514,  1133,   906,  1184,  1289,  1090,  1693,  1125,  1126,
    1127,   692,   693,   694,  1128,   660,   403,   404,  1058,   532,
     663,  1090,  1703,  1090,  1706,   437,   454,   568,   438,   455,
     514,   514,   514,   514,   459,   547,   566,   460,   567,   656,
     548,   662,  1452,   555,   712,   413,   414,   415,   416,   556,
     417,   418,   713,   420,   421,  1254,   557,  1255,  1395,   422,
    1259,   559,  1260,   704,   705,  1122,  1123,   562,   514,  1151,
    1152,  1453,  1454,   565,   407,   855,   856,  1646,  1647,   862,
     863,   571,   514,   864,   865,  1098,  1098,  1593,  1594,   572,
    1299,   891,   892,   893,   894,   895,   896,   897,   898,   899,
     900,   513,   574,   573,   575,   576,   408,   579,   595,   514,
     596,   614,   613,   632,   644,   529,   646,   664,   514,   647,
     514,   291,   645,   656,   514,   665,   666,   295,   670,   472,
     667,   668,   682,   669,   410,   684,   841,   514,   546,   685,
     697,   702,   700,   703,   706,   718,   740,   729,  1691,   734,
     551,  1533,   554,   730,   743,   751,   752,   753,   764,   770,
     771,  1046,   777,   779,   434,   438,   788,  1047,   455,   460,
     514,   795,   514,   797,   798,   291,   291,   291,   717,   471,
     781,   295,   295,   295,   801,   782,   783,   785,   810,   806,
     811,  1224,   412,   413,   414,   415,   416,   823,   417,   418,
     419,   420,   421,   837,   838,   839,   816,   422,   423,   840,
     854,   866,  1574,   867,   868,   869,   880,   886,   887,   889,
     911,   912,   915,   916,   937,   941,   943,   945,   514,   948,
     949,   950,   951,   958,   973,   952,   980,   979,   983,   990,
     991,   992,   993,   998,  1034,  1001,  1036,  1002,  1039,   514,
    1054,  1060,  1035,  1064,  1040,  1115,   906,   960,  1134,  1135,
    1162,  1160,  1175,  1168,  1153,  1171,   736,  1195,  1197,  1169,
    1196,  1539,  1201,  1182,  1203,  1198,  1209,  1208,  1202,  1212,
    1213,  1219,   291,  1232,  1225,  1200,  1226,  1227,   295,  1237,
    1253,  1368,  1267,  1445,  1446,  1447,  1231,   688,  1322,  1296,
    1298,  1276,  1323,   883,  1350,  1342,  1355,  1271,  1326,  1272,
    1274,  1273,  1303,   939,  1359,  1334,  1335,   291,  1349,  1337,
    1360,  1367,  1366,   295,  1369,  1379,  1371,  1381,   291,  1388,
    1362,  1363,   514,  1385,   295,   514,  1389,  1402,  1398,   390,
    1393,  1387,  1416,  1370,  1401,  1429,  1432,   291,  1438,  1422,
     514,  1372,   389,   295,  1373,  1424,  1423,  1425,  1442,   514,
    1439,   513,  1450,  1427,   513,  1437,   291,  1289,  1440,  1444,
    1459,  1463,   295,   514,  1482,  1466,  1487,  1476,  1489,  1498,
    1483,  1504,  1495,   514,  1496,   390,  1497,  1509,  1507,  1511,
    1513,  1617,  1516,  1518,  1046,  1046,  1523,  1530,   389,  1532,
    1047,  1047,  1621,  1539,   390,  1623,  1535,  1531,  1441,  1536,
    1541,   514,  1631,  1589,  1598,  1544,  1551,   389,  1552,  1557,
    1575,  1587,  1136,   717,  1590,  1603,  1611,  1616,  1622,  1614,
     679,   514,  1643,   683,  1626,  1638,  1433,   551,  1630,  1652,
     514,  1653,  1640,   699,   514,  1655,  1656,  1660,  1665,  1588,
     701,   814,  1654,  1667,  1669,  1668,  1661,  1700,  1610,  1683,
    1689,  1685,  1708,   551,  1699,  1702,  1711,  1757,  1714,   728,
    1707,  1715,   733,  1722,  1725,  1726,  1569,  1735,  1697,  1728,
     750,  1732,  1737,  1747,  1720,  1749,   551,   758,   759,   762,
    1733,  1623,  1750,  1753,   768,  1754,  1758,   578,   514,   580,
     913,  1395,   775,   581,  1739,   584,  1348,  1741,  1117,  1760,
     710,   714,  1194,  1365,  1695,   711,  1663,  1051,   835,  1191,
    1374,  1528,   988,  1392,  1461,  1287,   514,  1458,  1455,  1704,
     291,  1403,   778,  1421,  1407,  1413,   295,   882,  1431,  1018,
     844,   650,   845,  1713,  1710,  1099,  1358,   776,  1167,  1347,
    1443,  1449,   514,   514,  1448,  1477,  1481,  1586,  1480,  1301,
     723,   762,  1585,  1723,  1325,  1141,  1356,  1506,   724,  1595,
     784,     0,  1478,     0,     0,     0,     0,     0,   514,     0,
     514,     0,     0,   514,     0,     0,     0,  1723,     0,     0,
    1690,  1642,     0,     0,   514,     0,  1704,     0,     0,   514,
       0,     0,   809,     0,     0,     0,     0,     0,     0,  1649,
       0,     0,     0,     0,   514,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1046,     0,     0,     0,     0,     0,  1047,     0,     0,     0,
       0,  1046,  1046,     0,   291,     0,     0,  1047,  1047,     0,
     295,  1046,     0,     0,     0,     0,  1738,  1047,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1752,   551,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   514,
       0,   514,     0,   514,     0,     0,   910,     0,     0,     0,
     514,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   942,     0,     0,
       0,     0,     0,   946,   947,     0,     0,     0,     0,     0,
    1046,     0,     0,   514,     0,   514,  1047,     0,     0,     0,
    1046,     0,     0,     0,     0,   966,  1047,   972,     0,     0,
       0,   514,     0,     0,   514,   551,     0,     0,   551,     0,
       0,     0,   986,     0,     0,     0,   514,     0,   291,     0,
       0,     0,     0,     0,   295,     0,   514,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   514,     0,     0,
       0,     0,     0,     0,     0,     0,   514,     0,     0,  1017,
       0,     0,   291,     0,   514,     0,     0,     0,   295,   514,
       0,   514,     0,   514,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1046,   513,     0,     0,
       0,     0,  1047,   514,     0,  1046,     0,     0,     0,     0,
     393,  1047,     0,   514,     0,     0,     0,     0,  1059,     0,
     394,   395,     0,   396,   397,     0,     0,     0,     0,   514,
       0,   398,     0,     0,     0,     0,   514,     0,     0,     0,
     399,   400,   514,     0,     0,     0,     0,  1095,  1095,  1095,
    1095,   514,     0,     0,     0,     0,     0,     0,   401,     0,
       0,   514,   402,     0,     0,     0,     0,   514,     0,     0,
       0,     0,   514,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1095,     0,     0,     0,     0,
       0,     0,     0,   403,   404,   405,     0,     0,     0,  1129,
       0,     0,     0,     0,     0,     0,     0,   799,   800,     0,
     802,   803,   804,   805,     0,     0,     0,     0,   812,     0,
       0,     0,     0,     0,     0,     0,  1157,     0,     0,     0,
       0,     0,     0,     0,     0,  1165,     0,  1165,     0,   836,
       0,  1095,   406,     0,     0,     0,     0,   842,   843,     0,
       0,   407,     0,     0,  1095,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   408,     0,     0,     0,   768,     0,   768,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   409,     0,     0,     0,     0,   877,     0,     0,     0,
     877,   410,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   411,     0,  1297,     0,     0,     0,     0,
       0,     0,   944,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1095,     0,     0,   412,
     413,   414,   415,   416,     0,   417,   418,   419,   420,   421,
       0,     0,     0,     0,   422,   423,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   987,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1012,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   842,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   733,
       0,     0,  1377,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1391,     0,     0,
       0,     0,     0,     0,     0,     0,  1095,     0,     0,     0,
       0,     0,     0,  1061,     0,     0,     0,     0,     0,     0,
     762,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1095,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1434,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   809,     0,
    1118,     0,     0,     0,     0,     0,     0,   513,     0,     0,
       0,   513,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1156,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1172,     0,     0,     0,
       0,     0,     0,     0,     0,  1095,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1205,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1210,
    1211,     0,     0,  1512,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1230,     0,     0,  1233,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1526,
    1527,  1256,  1257,  1258,     0,  1261,  1262,  1263,  1264,  1265,
    1266,     0,  1268,  1269,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1543,     0,  1095,     0,     0,
    1095,     0,     0,     0,  1061,     0,     0,     0,     0,     0,
       0,  1555,     0,     0,     0,     0,  1559,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1572,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1343,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1378,     0,  1380,
       0,  1382,     0,     0,  1386,     0,  1625,     0,  1627,  1390,
    1629,     0,     0,     0,     0,     0,     0,  1637,     0,     0,
       0,  1396,     0,     0,     0,     0,     0,     0,     0,     0,
    1400,     0,     0,     0,     0,     0,  1404,  1405,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1095,     0,  1095,     0,     0,  1426,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1659,     0,
       0,  1662,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1095,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1670,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1688,     0,     0,     0,     0,     0,
       0,     0,     0,  1095,     0,     0,     0,     0,     0,     0,
    1061,  1698,     0,     0,     0,     0,  1701,     0,  1095,     0,
    1095,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1718,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1721,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1727,     0,     0,     0,
       0,     0,     0,  1734,     0,     0,     0,     0,     0,  1736,
       0,     0,     0,     0,     0,     0,     0,     0,  1744,  1517,
       0,     0,     0,  1519,     0,     0,     0,  1522,  1751,  1524,
       0,  1525,     0,     0,  1755,     0,     0,  1529,     0,  1759,
       0,     0,     0,     0,     0,  1534,     0,     0,     0,     0,
       0,     0,     0,  1538,  1540,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1396,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1560,  1561,  1562,  1563,  1564,     0,  1565,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1612,     0,  1613,     0,     0,  1615,     0,     0,
       0,     0,     0,     0,     0,  1618,     0,     0,     0,     0,
    1620,  1540,     0,     0,     0,     0,     0,     0,  1624,     0,
       0,     0,  1628,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1664,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1624,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1705,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1719,     0,     0,     0,     0,  1724,     0,     0,     0,
       0,  1705,     0,     0,     0,     1,     0,     0,     0,     0,
       0,     0,     0,     2,     3,     4,     5,     6,     7,  1724,
       0,     8,     0,     0,     0,     9,    10,  1740,    11,    12,
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
     124,     0,   533,     0,   125,     0,   126,   127,     0,   128,
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
      20,    21,    22,    23,   536,   386,    26,    27,    28,    29,
       0,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,     0,    43,    44,    45,   537,   538,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,     0,    66,
      67,    68,    69,    70,    71,    72,    73,     0,     0,    74,
      75,     0,     0,     0,    76,    77,   490,    79,    80,    81,
      82,    83,   539,    85,    86,     0,     0,     0,    87,     0,
      88,    89,    90,    91,     0,    92,     0,     0,     0,    93,
      94,    95,    96,    97,     0,     0,     0,     0,     0,     0,
      98,    99,   100,   101,   102,   103,   104,   540,     0,     0,
     106,   107,   108,   109,   110,     0,     0,     0,     0,   111,
     112,   113,   114,   115,   116,   117,   118,     0,   119,     0,
     120,   121,     0,     0,   122,   123,   124,     0,     0,     0,
     125,   541,   126,   127,     0,   128,   129,   130,     0,   131,
       0,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,     0,     0,   143,   144,   145,     0,   387,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   507,   508,   509,   173,   174,   510,   542,   177,
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
     122,   123,   124,     0,   780,     0,   125,     0,   126,   127,
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
      18,    19,    20,    21,    22,    23,   536,   386,    26,    27,
      28,    29,     0,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,     0,    43,    44,    45,
     537,   538,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
       0,    66,    67,    68,    69,    70,    71,    72,    73,     0,
       0,    74,    75,     0,     0,     0,    76,    77,   490,    79,
      80,    81,    82,    83,   539,    85,    86,     0,     0,     0,
      87,     0,    88,    89,    90,    91,     0,    92,     0,     0,
       0,    93,    94,    95,    96,    97,     0,     0,     0,     0,
       0,     0,    98,    99,   100,   101,   102,   103,   104,   540,
       0,     0,   106,   107,   108,   109,   110,     0,     0,     0,
       0,   111,   112,   113,   114,   115,   116,   117,   118,     0,
     119,     0,   120,   121,     0,     0,   122,   123,   124,     0,
     870,     0,   125,     0,   126,   127,     0,   128,   129,   130,
       0,   131,     0,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,     0,     0,   143,   144,   145,     0,
     387,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   507,   508,   509,   173,   174,   510,
     542,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,   192,     0,   193,
     194,   195,   196,   197,   198,     0,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,     1,     0,     0,     0,
       0,     0,     0,     0,     2,     3,     4,     5,     6,     7,
       0,     0,     8,     0,     0,     0,   384,   385,     0,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,   536,   386,    26,    27,    28,    29,     0,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,     0,    43,    44,    45,   537,   538,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,     0,    66,    67,    68,
      69,    70,    71,    72,    73,     0,     0,    74,    75,     0,
       0,     0,    76,    77,   490,    79,    80,    81,    82,    83,
     539,    85,    86,     0,     0,     0,    87,     0,    88,    89,
      90,    91,     0,    92,     0,     0,     0,    93,    94,    95,
      96,    97,     0,     0,     0,     0,     0,     0,    98,    99,
     100,   101,   102,   103,   104,   540,     0,     0,   106,   107,
     108,   109,   110,     0,     0,     0,     0,   111,   112,   113,
     114,   115,   116,   117,   118,     0,   119,     0,   120,   121,
       0,     0,   122,   123,   124,     0,     0,     0,   125,   876,
     126,   127,     0,   128,   129,   130,     0,   131,     0,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
       0,     0,   143,   144,   145,     0,   387,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     507,   508,   509,   173,   174,   510,   542,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,   192,     0,   193,   194,   195,   196,   197,
     198,     0,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,     1,     0,     0,     0,     0,     0,     0,     0,
       2,     3,     4,     5,     6,     7,     0,     0,     8,     0,
       0,     0,   384,   385,     0,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,   536,   386,
      26,    27,    28,    29,     0,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,     0,    43,
      44,    45,   537,   538,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,     0,    66,    67,    68,    69,    70,    71,    72,
      73,     0,     0,    74,    75,     0,     0,     0,    76,    77,
     490,    79,    80,    81,    82,    83,   539,    85,    86,     0,
       0,     0,    87,     0,    88,    89,    90,    91,     0,    92,
       0,     0,     0,    93,    94,    95,    96,    97,     0,     0,
       0,     0,     0,     0,    98,    99,   100,   101,   102,   103,
     104,   540,     0,     0,   106,   107,   108,   109,   110,     0,
       0,     0,     0,   111,   112,   113,   114,   115,   116,   117,
     118,     0,   119,     0,   120,   121,     0,     0,   122,   123,
     124,     0,     0,     0,   125,   881,   126,   127,     0,   128,
     129,   130,     0,   131,     0,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,     0,     0,   143,   144,
     145,     0,   387,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   507,   508,   509,   173,
     174,   510,   542,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,   192,
       0,   193,   194,   195,   196,   197,   198,     0,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,     1,     0,
       0,     0,     0,     0,     0,     0,     2,     3,     4,     5,
       6,     7,     0,     0,     8,     0,     0,     0,   384,   385,
       0,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,  1042,   386,    26,    27,    28,    29,
       0,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,     0,    43,    44,    45,  1043,  1044,
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
     120,   121,     0,     0,   122,   123,   124,     0,   780,     0,
     125,     0,   126,   127,     0,   128,   129,   130,     0,   131,
       0,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,     0,     0,   143,   144,   145,     0,   387,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,  1045,   177,
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
    1042,   386,    26,    27,    28,    29,     0,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
       0,    43,    44,    45,  1043,  1044,    48,    49,    50,    51,
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
     122,   123,   124,     0,   533,     0,   125,     0,   126,   127,
       0,   128,   129,   130,     0,   131,     0,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,     0,     0,
     143,   144,   145,     0,   387,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,  1045,   177,   178,   179,   180,   181,
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
      82,    83,   539,    85,    86,     0,     0,     0,    87,     0,
      88,    89,    90,    91,     0,    92,     0,     0,     0,   493,
      94,    95,    96,    97,     0,     0,     0,     0,     0,     0,
      98,    99,   100,   101,   102,   103,   104,   540,     0,     0,
     106,   107,   648,   109,   110,     0,     0,     0,     0,   111,
     112,   113,   114,   115,   116,   117,   118,     0,   119,     0,
     649,   121,     0,     0,   122,   123,   124,     0,     0,     0,
     125,     0,   126,   127,     0,   128,   129,   130,     0,   131,
       0,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,     0,     0,   143,   144,   145,     0,   387,   147,
     148,   149,   150,   151,   152,   153,   154,   502,   156,   503,
     158,   504,   505,   161,   162,   163,   164,   165,   166,   506,
     168,   169,   507,   508,   509,   173,   174,   510,   511,   177,
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
     536,   386,    26,    27,    28,    29,     0,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
       0,    43,    44,    45,   537,   538,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,     0,    66,    67,    68,    69,    70,
      71,    72,    73,     0,     0,    74,    75,     0,     0,     0,
      76,    77,   490,    79,    80,    81,    82,    83,   539,    85,
      86,     0,     0,     0,    87,     0,    88,    89,    90,    91,
       0,    92,     0,     0,     0,    93,    94,    95,    96,    97,
       0,     0,     0,     0,     0,     0,    98,    99,   100,   101,
     102,   103,   104,   540,     0,     0,   106,   107,   108,   109,
     110,     0,     0,     0,     0,   111,   112,   113,   114,   115,
     116,   117,   118,     0,   119,     0,   120,   121,     0,     0,
     122,   123,   124,     0,     0,     0,   125,     0,   126,   127,
       0,   128,   129,   130,     0,   131,     0,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,     0,     0,
     143,   144,   145,     0,   387,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   507,   508,
     509,   173,   174,   510,   542,   177,   178,   179,   180,   181,
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
       0,     0,     8,     0,     0,     0,   830,   385,     0,    11,
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
     490,    79,    80,    81,    82,    83,   539,    85,    86,     0,
       0,     0,    87,     0,    88,    89,    90,    91,     0,    92,
       0,     0,     0,   493,    94,    95,    96,    97,     0,     0,
       0,     0,     0,     0,    98,    99,   100,   101,   102,   103,
     104,   540,     0,     0,   106,   107,   108,   109,   110,     0,
       0,     0,     0,   111,   112,   113,   114,   115,   116,   117,
     118,     0,   119,     0,   120,   121,     0,     0,   122,   123,
     124,     0,     0,     0,   125,     0,   126,   127,     0,   128,
     129,   130,     0,   131,     0,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,     0,     0,   143,   144,
     145,     0,   387,   147,   148,   149,   150,   151,   152,   153,
     154,   502,   156,   503,   158,   504,   505,   161,   162,   163,
     164,   165,   166,   506,   168,   169,   507,   508,   509,   173,
     174,   510,   511,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,   192,
       0,   193,   194,   195,   196,   197,   198,     0,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,     1,     0,
       0,     0,     0,     0,     0,     0,     2,     3,     4,     5,
       6,     7,     0,     0,     8,     0,     0,     0,   384,   385,
       0,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,  1042,   386,    26,    27,    28,    29,
       0,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,     0,    43,    44,    45,  1043,  1044,
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
     168,   169,   170,   171,   172,   173,   174,   175,  1045,   177,
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
      76,    77,   490,    79,    80,    81,    82,    83,   539,    85,
      86,     0,     0,     0,    87,     0,    88,    89,    90,    91,
       0,    92,     0,     0,     0,   493,    94,    95,    96,    97,
       0,     0,     0,     0,     0,     0,    98,    99,   100,   101,
     102,   103,   104,   540,     0,     0,   106,   107,     0,   109,
     110,     0,     0,     0,     0,   111,   112,   113,   114,   115,
     116,   117,   118,     0,   119,     0,     0,     0,     0,     0,
     122,   123,   124,     0,     0,     0,   125,     0,   126,   127,
       0,   128,   129,   130,     0,   131,     0,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,     0,     0,
     143,   144,   145,     0,   387,   147,   148,   149,   150,   151,
     152,   153,   154,   502,   156,   503,   158,   504,   505,   161,
     162,   163,   164,   165,   166,   506,   168,   169,   507,   508,
     509,   173,   174,   510,   511,   177,   178,   179,   180,   181,
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
      80,    81,    82,    83,   539,    85,    86,     0,     0,     0,
      87,     0,    88,    89,    90,    91,     0,    92,     0,     0,
       0,   493,    94,    95,    96,    97,     0,     0,     0,     0,
       0,     0,    98,    99,   100,   101,   102,   103,   104,   540,
       0,     0,   106,   107,     0,   109,   110,     0,     0,     0,
       0,   111,   112,   113,   114,   115,   116,   117,   118,     0,
     119,     0,     0,     0,     0,     0,   122,   123,   124,     0,
       0,     0,   125,     0,   126,   127,     0,     0,     0,   130,
       0,   131,     0,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,     0,     0,   143,   144,   145,     0,
     387,   147,   148,   149,   150,   151,   152,   153,   154,   502,
     156,   503,   158,   504,   505,   161,   162,   163,   164,   165,
     166,   506,   168,   169,   507,   508,   509,   173,   174,   510,
     511,   177,   178,   179,   180,   181,   182,   183,   184,   185,
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
     505,   161,   162,   163,   164,   165,   166,   506,   168,   169,
     507,   508,   509,   173,   174,   510,   511,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,   192,     0,   193,   194,   195,   196,   197,
     198,     0,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,     1,     0,     0,     0,     0,     0,     0,     0,
       2,     0,     0,     0,     6,     7,     0,     0,   472,     0,
       0,     0,   384,   385,     0,    11,    12,    13,   520,    15,
      16,    17,   474,   521,   522,    21,   476,   477,   478,   386,
      26,   479,    28,    29,     0,    30,    31,    32,    33,   523,
      35,   524,   525,    38,    39,    40,    41,   481,     0,    43,
     526,    45,   483,   484,    48,   485,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,   486,
     487,    65,     0,    66,    67,    68,   527,     0,    71,    72,
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
     154,   502,   528,   503,   158,   504,   505,   161,   162,   163,
     164,   165,   166,   506,   168,   169,   507,   508,   509,   173,
     174,   510,   511,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,   192,
       0,   193,   194,   195,   196,   197,   198,     0,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   549,     0,
       0,     0,     0,     0,     0,     0,     6,     7,     0,     0,
     755,     0,     0,     0,   384,   385,     0,    11,    12,    13,
     520,    15,    16,    17,   474,   521,   522,    21,   476,   477,
     478,   386,    26,   479,    28,    29,     0,    30,    31,    32,
      33,   523,    35,   524,   525,    38,    39,    40,    41,   481,
       0,    43,   526,    45,   483,   484,    48,   485,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,   486,   487,    65,     0,    66,    67,    68,   527,     0,
      71,    72,    73,     0,     0,   489,    75,     0,     0,     0,
       0,    77,   490,    79,   491,   492,    82,    83,     0,     0,
       0,     0,     0,     0,     0,     0,    88,    89,    90,    91,
       0,    92,     0,     0,     0,   493,    94,    95,   494,   495,
       0,     0,     0,     0,     0,     0,    98,    99,   100,     0,
     102,   103,   104,     0,     0,     0,     0,     0,     0,   109,
     110,     0,     0,     0,     0,   111,   112,   113,   114,   496,
     116,   117,   497,     0,     0,     0,     0,     0,     0,     0,
     498,   499,   124,     0,     0,     0,   125,   756,   126,   500,
       0,     0,     0,     0,     0,   131,     0,   132,   133,   134,
     135,   501,   137,   138,   139,   140,   141,   142,     0,     0,
     143,   144,     0,     0,   387,   147,   148,   149,   150,   151,
     152,   153,   154,   502,   528,   503,   158,   504,   505,   161,
     162,   163,   164,   165,   166,   506,   168,   169,   507,   508,
     509,   173,   174,   510,   511,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,   190,
     191,   192,     0,   193,   194,   195,   196,   197,   198,     0,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     549,     0,     0,     0,     0,     0,     0,     0,     6,     7,
       0,     0,   472,     0,     0,     0,   384,   385,     0,    11,
      12,    13,   520,    15,    16,    17,   474,   521,   522,    21,
     476,   477,   478,   386,    26,   479,    28,    29,     0,    30,
      31,    32,    33,   523,    35,   524,   525,    38,    39,    40,
      41,   481,     0,    43,   526,    45,   483,   484,    48,   485,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,   486,   487,    65,     0,    66,    67,    68,
     527,     0,    71,    72,    73,     0,     0,   489,    75,     0,
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
     150,   151,   152,   153,   154,   502,   528,   503,   158,   504,
     505,   161,   162,   163,   164,   165,   166,   506,   168,   169,
     507,   508,   509,   173,   174,   510,   511,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,   192,     0,   193,   194,   195,   196,   197,
     198,     0,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   552,   553,     0,     0,     0,     0,     6,     7,
       0,     0,   472,     0,     0,     0,   384,   385,     0,    11,
      12,    13,   520,    15,    16,    17,   474,   521,   522,    21,
     476,   477,   478,   386,    26,   479,    28,    29,     0,    30,
      31,    32,    33,   523,    35,   524,   525,    38,    39,    40,
      41,   481,     0,    43,   526,    45,   483,   484,    48,   485,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,   486,   487,    65,     0,    66,    67,    68,
     527,     0,    71,    72,    73,     0,     0,   489,    75,     0,
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
     150,   151,   152,   153,   154,   502,   528,   503,   158,   504,
     505,   161,   162,   163,   164,   165,   166,   506,   168,   169,
     507,   508,   509,   173,   174,   510,   511,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,   192,     0,   193,   194,   195,   196,   197,
     198,     0,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,     6,     7,     0,     0,   472,     0,     0,     0,
     384,   385,     0,    11,    12,    13,   473,    15,    16,    17,
     474,    19,   475,    21,   476,  1083,   478,   386,    26,   479,
      28,    29,     0,    30,    31,    32,    33,   480,    35,    36,
      37,    38,    39,    40,    41,   481,     0,    43,   482,    45,
     483,   484,    48,   485,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,   486,   487,    65,
       0,    66,    67,    68,   488,     0,    71,    72,    73,     0,
       0,   489,    75,     0,     0,     0,     0,    77,   490,    79,
     491,   492,    82,    83,     0,     0,     0,     0,     0,     0,
       0,     0,    88,    89,    90,    91,     0,    92,     0,     0,
       0,   493,    94,    95,   494,   495,     0,     0,     0,     0,
       0,     0,    98,    99,   100,     0,   102,   103,  1084,     0,
       0,     0,  1085,     0,     0,   109,   110,     0,     0,     0,
       0,   111,   112,   113,   114,   496,   116,   117,   497,     0,
       0,     0,     0,     0,     0,     0,   498,   499,   124,     0,
       0,     0,   125,  1491,   126,   500,     0,     0,     0,  1492,
       0,   131,     0,   132,   133,   134,   135,   501,   137,   138,
     139,   140,   141,   142,     0,     0,  1086,   144,     0,     0,
     387,   147,   148,   149,   150,   151,   152,   153,   154,   502,
     156,   503,   158,   504,   505,   161,   162,   163,   164,   165,
     166,   506,   168,   169,   507,   508,   509,   173,   174,   510,
     511,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,   192,     0,   193,
     194,   195,   196,   197,   198,     0,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,     6,     7,     0,     0,
     472,     0,     0,     0,   384,   385,     0,    11,    12,    13,
     520,    15,    16,    17,   474,   521,   522,    21,   476,   477,
     478,   386,    26,   479,    28,    29,     0,    30,    31,    32,
      33,   523,    35,   524,   525,    38,    39,    40,    41,   481,
       0,    43,   526,    45,   483,   484,    48,   485,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,   486,   487,    65,     0,    66,    67,    68,   527,     0,
      71,    72,    73,     0,     0,   489,    75,     0,     0,     0,
       0,    77,   490,    79,   491,   492,    82,    83,     0,     0,
       0,     0,     0,     0,     0,     0,    88,    89,    90,    91,
       0,    92,     0,     0,     0,   493,    94,    95,   494,   495,
       0,     0,     0,     0,     0,     0,    98,    99,   100,     0,
     102,   103,   104,     0,     0,     0,     0,     0,     0,   109,
     110,     0,     0,     0,     0,   111,   112,   113,   114,   496,
     116,   117,   497,     0,     0,     0,     0,     0,     0,     0,
     498,   499,   124,     0,     0,     0,   125,   726,   126,   500,
       0,     0,     0,   727,     0,   131,     0,   132,   133,   134,
     135,   501,   137,   138,   139,   140,   141,   142,     0,     0,
     143,   144,     0,     0,   387,   147,   148,   149,   150,   151,
     152,   153,   154,   502,   528,   503,   158,   504,   505,   161,
     162,   163,   164,   165,   166,   506,   168,   169,   507,   508,
     509,   173,   174,   510,   511,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,   190,
     191,   192,     0,   193,   194,   195,   196,   197,   198,     0,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
       6,     7,     0,     0,   472,     0,     0,     0,   384,   385,
       0,    11,    12,    13,   520,    15,    16,    17,   474,   521,
     522,    21,   476,   477,   478,   386,    26,   479,    28,    29,
       0,    30,    31,    32,    33,   523,    35,   524,   525,    38,
      39,    40,    41,   481,     0,    43,   526,    45,   483,   484,
      48,   485,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,   486,   487,    65,     0,    66,
      67,    68,   527,     0,    71,    72,    73,     0,     0,   489,
      75,     0,     0,     0,     0,    77,   490,    79,   491,   492,
      82,    83,     0,     0,     0,     0,     0,     0,     0,     0,
      88,    89,    90,    91,     0,    92,     0,     0,     0,   493,
      94,    95,   494,   495,     0,     0,     0,     0,     0,     0,
      98,    99,   100,     0,   102,   103,   104,     0,     0,     0,
       0,     0,     0,   109,   110,     0,     0,     0,     0,   111,
     112,   113,   114,   496,   116,   117,   497,     0,     0,     0,
       0,     0,     0,     0,   498,   499,   124,     0,     0,     0,
     125,   773,   126,   500,     0,     0,     0,   774,     0,   131,
       0,   132,   133,   134,   135,   501,   137,   138,   139,   140,
     141,   142,     0,     0,   143,   144,     0,     0,   387,   147,
     148,   149,   150,   151,   152,   153,   154,   502,   528,   503,
     158,   504,   505,   161,   162,   163,   164,   165,   166,   506,
     168,   169,   507,   508,   509,   173,   174,   510,   511,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,     0,   190,   191,   192,     0,   193,   194,   195,
     196,   197,   198,     0,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,     6,     7,     0,     0,   472,     0,
       0,     0,   384,   385,     0,    11,    12,    13,   473,    15,
      16,    17,   474,    19,   475,    21,   476,  1083,   478,   386,
      26,   479,    28,    29,     0,    30,    31,    32,    33,   480,
      35,    36,    37,    38,    39,    40,    41,   481,     0,    43,
     482,    45,   483,   484,    48,   485,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,   486,
     487,    65,     0,    66,    67,    68,   488,     0,    71,    72,
      73,     0,     0,   489,    75,     0,     0,     0,     0,    77,
     490,    79,   491,   492,    82,    83,  1414,     0,     0,     0,
       0,     0,     0,     0,    88,    89,    90,    91,     0,    92,
       0,     0,     0,   493,    94,    95,   494,   495,     0,     0,
       0,     0,     0,     0,    98,    99,   100,     0,   102,   103,
    1084,     0,     0,     0,  1085,     0,     0,   109,   110,     0,
       0,     0,     0,   111,   112,   113,   114,   496,   116,   117,
     497,     0,     0,     0,     0,     0,     0,     0,   498,   499,
     124,     0,     0,     0,   125,     0,   126,   500,     0,     0,
       0,     0,     0,   131,     0,   132,   133,   134,   135,   501,
     137,   138,   139,   140,   141,   142,     0,     0,  1086,   144,
       0,     0,   387,   147,   148,   149,   150,   151,   152,   153,
     154,   502,   156,   503,   158,   504,   505,   161,   162,   163,
     164,   165,   166,   506,   168,   169,   507,   508,   509,   173,
     174,   510,   511,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,   192,
       0,   193,   194,   195,   196,   197,   198,     0,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,     6,     7,
       0,     0,   472,     0,     0,     0,   384,   385,     0,    11,
      12,    13,   473,    15,    16,    17,   474,    19,   475,    21,
     476,  1083,   478,   386,    26,   479,    28,    29,     0,    30,
      31,    32,    33,   480,    35,    36,    37,    38,    39,    40,
      41,   481,     0,    43,   482,    45,   483,   484,    48,   485,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,   486,   487,    65,     0,    66,    67,    68,
     488,     0,    71,    72,    73,     0,     0,   489,    75,     0,
       0,     0,     0,    77,   490,    79,   491,   492,    82,    83,
    1545,     0,     0,     0,     0,     0,     0,     0,    88,    89,
      90,    91,     0,    92,     0,     0,     0,   493,    94,    95,
     494,   495,     0,     0,     0,     0,     0,     0,    98,    99,
     100,     0,   102,   103,  1084,     0,     0,     0,  1085,     0,
       0,   109,   110,     0,     0,     0,     0,   111,   112,   113,
     114,   496,   116,   117,   497,     0,     0,     0,     0,     0,
       0,     0,   498,   499,   124,     0,     0,     0,   125,     0,
     126,   500,     0,     0,     0,     0,     0,   131,     0,   132,
     133,   134,   135,   501,   137,   138,   139,   140,   141,   142,
       0,     0,  1086,   144,     0,     0,   387,   147,   148,   149,
     150,   151,   152,   153,   154,   502,   156,   503,   158,   504,
     505,   161,   162,   163,   164,   165,   166,   506,   168,   169,
     507,   508,   509,   173,   174,   510,   511,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,   192,     0,   193,   194,   195,   196,   197,
     198,     0,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,     6,     7,     0,     0,   472,     0,     0,     0,
     384,   385,     0,    11,    12,    13,   473,    15,    16,    17,
     474,    19,   475,    21,   476,  1083,   478,   386,    26,   479,
      28,    29,     0,    30,    31,    32,    33,   480,    35,    36,
      37,    38,    39,    40,    41,   481,     0,    43,   482,    45,
     483,   484,    48,   485,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,   486,   487,    65,
       0,    66,    67,    68,   488,     0,    71,    72,    73,     0,
       0,   489,    75,     0,     0,     0,     0,    77,   490,    79,
     491,   492,    82,    83,  1549,     0,     0,     0,     0,     0,
       0,     0,    88,    89,    90,    91,     0,    92,     0,     0,
       0,   493,    94,    95,   494,   495,     0,     0,     0,     0,
       0,     0,    98,    99,   100,     0,   102,   103,  1084,     0,
       0,     0,  1085,     0,     0,   109,   110,     0,     0,     0,
       0,   111,   112,   113,   114,   496,   116,   117,   497,     0,
       0,     0,     0,     0,     0,     0,   498,   499,   124,     0,
       0,     0,   125,     0,   126,   500,     0,     0,     0,     0,
       0,   131,     0,   132,   133,   134,   135,   501,   137,   138,
     139,   140,   141,   142,     0,     0,  1086,   144,     0,     0,
     387,   147,   148,   149,   150,   151,   152,   153,   154,   502,
     156,   503,   158,   504,   505,   161,   162,   163,   164,   165,
     166,   506,   168,   169,   507,   508,   509,   173,   174,   510,
     511,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,   192,     0,   193,
     194,   195,   196,   197,   198,     0,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,     6,     7,     0,     0,
     472,     0,     0,     0,   384,   385,     0,    11,    12,    13,
     473,    15,    16,    17,   474,    19,   475,    21,   476,  1083,
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
     102,   103,  1084,     0,     0,     0,  1085,     0,     0,   109,
     110,     0,     0,     0,     0,   111,   112,   113,   114,   496,
     116,   117,   497,     0,     0,     0,     0,     0,     0,     0,
     498,   499,   124,     0,     0,     0,   125,     0,   126,   500,
       0,     0,     0,     0,     0,   131,     0,   132,   133,   134,
     135,   501,   137,   138,   139,   140,   141,   142,     0,     0,
    1086,   144,     0,     0,   387,   147,   148,   149,   150,   151,
     152,   153,   154,   502,   156,   503,   158,   504,   505,   161,
     162,   163,   164,   165,   166,   506,   168,   169,   507,   508,
     509,   173,   174,   510,   511,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,   190,
     191,   192,     0,   193,   194,   195,   196,   197,   198,     0,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
       6,     7,     0,     0,   472,     0,     0,     0,   384,   385,
       0,    11,    12,    13,   473,    15,    16,    17,   474,    19,
     475,    21,   476,  1083,   478,   386,    26,   479,    28,    29,
       0,    30,    31,    32,    33,   480,    35,    36,    37,    38,
      39,    40,    41,   481,     0,    43,   482,    45,   483,   484,
      48,   485,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,   486,   487,    65,     0,    66,
      67,    68,   488,     0,    71,    72,    73,     0,     0,   489,
      75,     0,     0,     0,     0,    77,   490,    79,   491,   492,
      82,    83,     0,     0,     0,     0,     0,     0,     0,     0,
      88,    89,    90,    91,     0,    92,     0,     0,     0,   493,
      94,    95,   494,   495,     0,     0,     0,     0,     0,     0,
      98,    99,   100,     0,   102,   103,  1084,     0,     0,     0,
    1085,     0,     0,   109,   110,     0,     0,     0,     0,   111,
     112,   113,   114,   496,   116,   117,   497,     0,     0,     0,
       0,     0,     0,     0,   498,   499,   124,     0,     0,     0,
     125,     0,   126,   500,     0,     0,     0,     0,     0,   131,
       0,   132,   133,   134,   135,   501,   137,   138,   139,   140,
     141,   142,     0,     0,   143,   144,     0,     0,   387,   147,
     148,   149,   150,   151,   152,   153,   154,   502,   156,   503,
     158,   504,   505,   161,   162,   163,   164,   165,   166,   506,
     168,   169,   507,   508,   509,   173,   174,   510,   511,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,     0,   190,   191,   192,     0,   193,   194,   195,
     196,   197,   198,     0,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,     6,     7,     0,     0,   472,     0,
       0,     0,   384,   385,     0,    11,    12,    13,   520,    15,
      16,    17,   474,   521,   522,    21,   476,   477,   478,   386,
      26,   479,    28,    29,     0,    30,    31,    32,    33,   523,
      35,   524,   525,    38,    39,    40,    41,   481,     0,    43,
     526,    45,   483,   484,    48,   485,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,   486,
     487,    65,     0,    66,    67,    68,   527,     0,    71,    72,
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
     154,   502,   528,   503,   158,   504,   505,   161,   162,   163,
     164,   165,   166,   506,   168,   169,   507,   508,   509,   173,
     174,   510,   511,   177,   178,   179,   180,   181,   182,   183,
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
     505,   161,   162,   163,   164,   165,   166,   506,   168,   169,
     507,   508,   509,   173,   174,     0,   511,   177,   178,   179,
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
         0,   176,   789,     3,     4,     5,     0,   750,   106,     3,
       4,     5,     3,     4,     5,   635,   275,   670,   322,   762,
     246,   636,   637,   638,   639,  1153,   733,   394,   245,   295,
     733,   983,   999,   776,   816,   261,   129,  1021,   854,  1220,
     587,   588,   589,   590,   406,   589,   590,  1293,  1294,   946,
      70,  1069,  1236,   587,   588,   888,   678,     1,    34,    34,
       3,     4,     5,     1,    27,   904,  1509,    54,    94,     1,
     432,   139,   115,     3,     4,     5,    27,     1,     9,   115,
     447,   448,   615,     1,   617,   618,     1,   620,     1,   622,
     144,    28,    27,   455,    27,    26,    91,   630,   631,    92,
     866,   867,   867,     8,    53,   105,    55,  1249,   104,    35,
      36,   105,    38,    39,    70,  1326,    92,    51,    94,    94,
     104,   104,   104,    94,   104,    92,    92,   115,    84,    97,
      56,   390,   141,    92,    92,    31,   155,   150,   904,   110,
      31,   901,    43,   265,   107,   144,     9,    10,    97,   103,
     272,   107,    48,   913,   173,   163,   118,    48,   121,   110,
      61,   174,   105,   119,   173,   121,   119,   910,   144,   144,
     124,   179,   938,   139,   107,   105,    43,   275,   221,    46,
     139,   190,   153,   146,   110,   180,   144,   150,   121,   120,
     153,   122,   126,    40,   960,   960,   184,   181,    45,   181,
     131,   854,   270,    50,   187,   185,   157,   973,   973,  1455,
      77,   174,  1655,   146,    97,   183,   270,   150,    92,   150,
     153,    68,   157,   966,     9,    10,   213,   253,   254,   972,
    1017,   157,   325,    94,   270,   231,   103,   100,  1366,   239,
     233,   174,   242,   187,    94,   239,  1085,  1428,   242,   187,
    1217,  1203,  1149,  1069,  1070,   187,  1240,   120,   965,   122,
     963,   304,   965,   187,   251,  1249,   233,   172,   890,   187,
     104,   270,   187,   210,   187,   275,   535,   821,   822,   545,
    1113,   275,   985,   184,  1302,   819,   820,   150,    92,  1431,
     216,   154,   390,   256,   270,   270,    92,  1508,   165,   248,
     183,   104,   664,   104,   213,   166,    43,    27,   171,    46,
     330,    97,   261,   333,   263,   100,   166,   850,   165,  1085,
      92,   168,   689,   104,   104,   274,   275,   276,   191,   278,
     157,   280,   258,   104,   128,   120,   183,   122,   104,   437,
     214,   215,   251,   104,   603,    94,   209,   445,   221,   127,
     104,   185,   104,   226,   150,   229,   454,   104,   584,   133,
    1606,   208,   134,   461,   462,   150,   103,   139,   104,   154,
     587,   588,   470,   147,   330,   104,   221,   333,   223,   182,
     181,   748,   744,  1511,  1568,   747,   171,   107,   249,   250,
     390,   252,  1158,   187,   104,   144,   390,   183,   259,   249,
     250,   121,   252,   184,   184,   133,   191,   104,   269,   104,
     214,   215,  1658,   184,  1157,   193,  1069,  1070,   184,   269,
     281,   217,   218,   184,   209,   229,   146,   181,   165,  1195,
    1195,   281,   184,   433,   181,   435,    25,   535,   127,   433,
     104,   435,   398,   399,   435,   104,   402,  1431,   184,   547,
     406,   134,  1105,  1219,  1219,   184,   412,    46,   717,   459,
    1641,   559,  1169,   419,   464,   459,   150,   150,  1365,   197,
     464,   181,   104,     9,    10,  1178,   432,   575,   576,   104,
      94,   153,   438,  1611,    73,   441,  1302,   184,    94,   184,
     433,   104,   435,   449,  1276,  1311,   104,   104,  1280,   455,
     456,   457,   458,   433,   193,   435,  1322,   463,  1055,  1056,
    1057,  1055,  1056,  1057,     5,   471,   459,   181,     9,     5,
     109,   464,   166,     9,   104,   184,   104,    37,  1656,   459,
       9,    10,    42,    43,   464,   535,   153,    40,   144,   153,
     540,   535,    45,   104,   911,   912,   540,    50,    58,   916,
      60,    61,   184,   651,   198,   814,   181,   104,   656,    69,
     516,   654,   655,   104,   100,    68,   104,   150,  1334,  1334,
     115,   184,   104,   181,   530,     9,   576,   184,   244,   245,
    1532,   948,   576,   539,   120,    95,   122,   587,   588,   589,
     590,   174,    26,   587,   588,   589,   590,   540,   104,   825,
    1567,   267,   819,   603,   184,   119,   184,   155,   115,   603,
     540,  1739,   979,  1741,   150,   571,   983,    40,   154,   717,
     104,   100,    45,   184,   104,   173,   104,    50,   153,   120,
     104,   122,  1760,   576,   120,   171,   122,   184,   183,   130,
     181,   120,  1429,   122,   130,    68,   184,  1434,   114,  1302,
    1416,  1416,   184,  1419,  1419,   191,    52,   150,  1311,   150,
     153,    57,   165,   153,   150,   168,  1482,   115,   954,  1322,
     956,   150,   145,   209,  1381,   154,   183,   143,   184,    75,
     183,    92,   179,   781,   782,   783,   120,   785,   122,   162,
     156,   134,   171,  1313,   296,   192,   150,   131,    94,   153,
     184,   188,   189,   305,   184,   208,   184,   150,   664,    65,
     184,   221,   191,   206,    70,    94,   150,   717,   266,   115,
    1006,   179,  1008,   717,   190,   273,   682,    52,   129,   685,
     209,   110,    57,   144,   192,   283,   137,   138,  1282,   140,
     740,   153,   165,  1633,  1634,   168,   740,   148,    94,   740,
     706,   152,   206,   154,   153,   119,   712,   713,   159,   115,
     183,   134,   145,   115,   110,   155,   139,  1071,  1555,    94,
     770,   771,  1559,   153,   153,   176,   770,   771,   734,   162,
     736,  1047,  1041,   173,  1674,   208,   150,   197,   744,   153,
    1680,   747,   119,   155,    97,   751,   206,   740,   199,   200,
     201,   202,   203,   204,   260,   195,   166,   110,    23,  1717,
     740,   173,   119,    25,   814,   271,   657,    32,   150,   660,
     814,   153,   663,  1589,  1589,  1591,  1591,   770,   771,  1482,
     266,  1198,   788,   195,    46,  1743,  1203,   273,   198,   119,
     770,   771,    93,    55,    59,    97,  1754,   283,   297,   298,
    1637,  1466,   103,  1473,  1474,    97,  1622,  1622,   110,    97,
     816,    73,   113,  1606,    97,    77,   226,    97,   110,   115,
    1045,   260,   110,   124,    92,  1050,   119,   110,   134,    52,
     110,   837,   271,   139,    57,   103,  1652,  1652,   274,   275,
     276,   217,   218,   219,   280,   332,   108,   109,   110,   119,
     337,  1667,  1667,  1669,  1669,   150,   150,   221,   153,   153,
     866,   867,   868,   869,   150,   150,   221,   153,   223,   151,
     119,   153,  1289,   119,   284,   285,   286,   287,   288,   119,
     290,   291,   292,   293,   294,   228,   119,   230,  1197,   299,
     228,   150,   230,   297,   298,   125,   126,   212,   904,   288,
     289,   125,   126,   153,   166,   633,   634,  1577,  1578,   640,
     641,   115,   918,   642,   643,   868,   869,  1499,  1500,   238,
    1068,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    70,   239,   238,   153,   150,   198,     0,   104,   945,
     187,    90,   164,   246,    49,    84,    98,   118,   954,    99,
     956,  1001,   196,   151,   960,   142,   153,  1001,   153,    27,
     181,   181,    46,   181,   226,   149,  1275,   973,   107,   115,
     243,   295,   290,   295,   301,   184,   150,   281,  1648,   115,
     119,  1398,   121,   281,     1,   115,   139,   104,   184,   150,
     150,  1041,   139,   181,   153,   153,    33,  1041,   153,   153,
    1006,    16,  1008,   210,    27,  1055,  1056,  1057,  1001,   153,
     153,  1055,  1056,  1057,   184,   153,   153,   150,   187,   227,
     187,  1001,   284,   285,   286,   287,   288,     3,   290,   291,
     292,   293,   294,   115,   165,   167,   242,   299,   300,   167,
      69,   227,  1459,    92,    92,    92,   146,   104,   104,    27,
     157,   157,   124,   129,   243,   296,   139,   115,  1064,   129,
     181,   181,   184,   104,    92,   184,    43,    94,    94,   184,
     184,   184,   184,   181,    92,   150,   221,   181,   139,  1085,
      31,   167,   233,   115,   187,   129,   139,    92,    27,   283,
     150,   296,   144,   115,   223,   115,   115,    92,   194,   124,
     181,  1410,   157,   251,    94,   129,   115,   150,   129,   144,
      97,    97,  1162,   187,   181,  1532,   181,   150,  1162,    33,
      27,  1162,   115,  1271,  1272,  1273,   139,    77,   255,   104,
     104,   242,   257,    27,    27,   141,    27,   153,   264,   153,
     150,   153,   282,   233,   223,   153,   153,  1197,   283,   153,
     223,   187,   223,  1197,   184,   144,   141,   124,  1208,   115,
     284,   303,  1168,   144,  1208,  1171,   115,  1208,   104,  1162,
      75,   144,    97,   184,   139,   129,     7,  1227,   229,   181,
    1186,   184,  1162,  1227,   184,   184,  1227,   184,   233,  1195,
     229,   330,   115,   194,   333,   187,  1246,   103,   229,   183,
     103,   184,  1246,  1209,   144,   247,   283,   247,    76,    27,
     279,    27,   184,  1219,   184,  1208,   184,   104,   268,   167,
     254,  1530,   181,   144,  1274,  1275,   144,   123,  1208,    94,
    1274,  1275,  1541,  1542,  1227,  1544,   181,   123,   229,   183,
     183,  1247,  1551,    92,    27,   183,   183,  1227,   181,   181,
     181,   150,    94,  1246,   184,   184,   167,    52,    92,   144,
     399,  1267,   115,   402,   183,   193,  1246,   406,   183,    92,
    1276,    27,   194,   412,  1280,   104,   104,   115,   115,   277,
     419,  1274,   262,    92,    92,   183,   221,   221,   284,   193,
     115,   193,    91,   432,   115,   183,   180,   221,   193,   438,
     183,   115,   441,   115,   183,   183,   150,   183,   302,   115,
     449,   290,   115,   115,   302,   184,   455,   456,   457,   458,
     302,  1630,   195,   284,   463,   184,   115,   239,  1334,   242,
     688,  1640,   471,   242,   303,   245,  1116,   303,   905,   303,
     425,   430,   974,  1158,  1656,   425,  1611,   817,   593,   971,
    1168,  1391,   753,  1187,  1298,  1060,  1362,  1296,  1293,  1668,
    1410,  1209,   530,  1222,  1214,  1217,  1410,   666,  1240,   789,
     613,   318,   614,  1680,  1674,   869,  1150,   516,   956,  1115,
    1267,  1277,  1388,  1389,  1276,  1311,  1322,  1482,  1315,  1070,
     436,   530,  1479,  1702,  1079,   937,  1138,  1354,   436,  1502,
     539,    -1,  1312,    -1,    -1,    -1,    -1,    -1,  1414,    -1,
    1416,    -1,    -1,  1419,    -1,    -1,    -1,  1726,    -1,    -1,
    1645,  1569,    -1,    -1,  1430,    -1,  1735,    -1,    -1,  1435,
      -1,    -1,   571,    -1,    -1,    -1,    -1,    -1,    -1,  1587,
      -1,    -1,    -1,    -1,  1450,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1530,    -1,    -1,    -1,    -1,    -1,  1530,    -1,    -1,    -1,
      -1,  1541,  1542,    -1,  1544,    -1,    -1,  1541,  1542,    -1,
    1544,  1551,    -1,    -1,    -1,    -1,  1731,  1551,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1749,   664,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1545,
      -1,  1547,    -1,  1549,    -1,    -1,   685,    -1,    -1,    -1,
    1556,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   706,    -1,    -1,
      -1,    -1,    -1,   712,   713,    -1,    -1,    -1,    -1,    -1,
    1630,    -1,    -1,  1589,    -1,  1591,  1630,    -1,    -1,    -1,
    1640,    -1,    -1,    -1,    -1,   734,  1640,   736,    -1,    -1,
      -1,  1607,    -1,    -1,  1610,   744,    -1,    -1,   747,    -1,
      -1,    -1,   751,    -1,    -1,    -1,  1622,    -1,  1668,    -1,
      -1,    -1,    -1,    -1,  1668,    -1,  1632,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1643,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1652,    -1,    -1,   788,
      -1,    -1,  1702,    -1,  1660,    -1,    -1,    -1,  1702,  1665,
      -1,  1667,    -1,  1669,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1726,   816,    -1,    -1,
      -1,    -1,  1726,  1689,    -1,  1735,    -1,    -1,    -1,    -1,
      25,  1735,    -1,  1699,    -1,    -1,    -1,    -1,   837,    -1,
      35,    36,    -1,    38,    39,    -1,    -1,    -1,    -1,  1715,
      -1,    46,    -1,    -1,    -1,    -1,  1722,    -1,    -1,    -1,
      55,    56,  1728,    -1,    -1,    -1,    -1,   866,   867,   868,
     869,  1737,    -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,
      -1,  1747,    77,    -1,    -1,    -1,    -1,  1753,    -1,    -1,
      -1,    -1,  1758,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   904,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   108,   109,   110,    -1,    -1,    -1,   918,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   563,   564,    -1,
     566,   567,   568,   569,    -1,    -1,    -1,    -1,   574,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   945,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   954,    -1,   956,    -1,   595,
      -1,   960,   157,    -1,    -1,    -1,    -1,   603,   604,    -1,
      -1,   166,    -1,    -1,   973,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   198,    -1,    -1,    -1,  1006,    -1,  1008,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   216,    -1,    -1,    -1,    -1,   662,    -1,    -1,    -1,
     666,   226,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   258,    -1,  1064,    -1,    -1,    -1,    -1,
      -1,    -1,   708,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1085,    -1,    -1,   284,
     285,   286,   287,   288,    -1,   290,   291,   292,   293,   294,
      -1,    -1,    -1,    -1,   299,   300,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   752,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   777,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   787,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1168,
      -1,    -1,  1171,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1186,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1195,    -1,    -1,    -1,
      -1,    -1,    -1,   839,    -1,    -1,    -1,    -1,    -1,    -1,
    1209,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1219,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1247,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1267,    -1,
     906,    -1,    -1,    -1,    -1,    -1,    -1,  1276,    -1,    -1,
      -1,  1280,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   943,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   962,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1334,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   984,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   995,
     996,    -1,    -1,  1362,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1010,    -1,    -1,  1013,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1388,
    1389,  1027,  1028,  1029,    -1,  1031,  1032,  1033,  1034,  1035,
    1036,    -1,  1038,  1039,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1414,    -1,  1416,    -1,    -1,
    1419,    -1,    -1,    -1,  1060,    -1,    -1,    -1,    -1,    -1,
      -1,  1430,    -1,    -1,    -1,    -1,  1435,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1450,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1102,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1173,    -1,  1175,
      -1,  1177,    -1,    -1,  1180,    -1,  1545,    -1,  1547,  1185,
    1549,    -1,    -1,    -1,    -1,    -1,    -1,  1556,    -1,    -1,
      -1,  1197,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1206,    -1,    -1,    -1,    -1,    -1,  1212,  1213,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1589,    -1,  1591,    -1,    -1,  1231,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1607,    -1,
      -1,  1610,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1622,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1632,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1643,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1652,    -1,    -1,    -1,    -1,    -1,    -1,
    1296,  1660,    -1,    -1,    -1,    -1,  1665,    -1,  1667,    -1,
    1669,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1689,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1699,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1715,    -1,    -1,    -1,
      -1,    -1,    -1,  1722,    -1,    -1,    -1,    -1,    -1,  1728,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1737,  1375,
      -1,    -1,    -1,  1379,    -1,    -1,    -1,  1383,  1747,  1385,
      -1,  1387,    -1,    -1,  1753,    -1,    -1,  1393,    -1,  1758,
      -1,    -1,    -1,    -1,    -1,  1401,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1409,  1410,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1427,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1438,  1439,  1440,  1441,  1442,    -1,  1444,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1518,    -1,  1520,    -1,    -1,  1523,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1531,    -1,    -1,    -1,    -1,
    1536,  1537,    -1,    -1,    -1,    -1,    -1,    -1,  1544,    -1,
      -1,    -1,  1548,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1614,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1626,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1668,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1697,    -1,    -1,    -1,    -1,  1702,    -1,    -1,    -1,
      -1,  1707,    -1,    -1,    -1,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    19,    20,    21,    22,    23,    24,  1725,
      -1,    27,    -1,    -1,    -1,    31,    32,  1733,    34,    35,
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
     186,   198,   220,   222,   224,   225,   232,   235,   236,   237,
     240,   241,   490,   627,   628,   119,   115,   390,   119,   119,
      37,    42,    43,    58,    60,    61,    69,    95,   221,   627,
     115,   119,   119,   181,   381,   383,    47,    71,    72,   115,
     150,   184,   241,   402,   404,   414,   627,   150,   119,    15,
     626,   627,    17,    18,   627,   119,   119,   119,   482,   150,
      28,   210,   212,   221,   223,   153,   221,   223,   221,   221,
     226,   115,   238,   238,   239,   153,   150,   385,   324,     0,
     326,   327,    31,    48,   329,   346,     1,   187,   323,   187,
     323,   384,   402,   104,   187,   104,   187,    40,    45,    50,
      68,   165,   168,   183,   208,   397,   406,   411,   412,   413,
     427,   428,   432,   164,    90,   129,   137,   138,   140,   148,
     152,   154,   159,   176,   199,   200,   201,   202,   203,   204,
     474,   475,   246,   155,   173,   195,   114,   143,   156,   190,
     197,   206,   133,   147,    49,   196,    98,    99,   155,   173,
     473,   150,   479,   482,   188,   189,   151,   494,   495,   490,
     494,   490,   153,   494,   118,   142,   153,   181,   181,   181,
     153,   625,   179,   192,   179,   192,   163,   179,   628,   627,
     166,   198,    46,   627,   149,   115,    43,    46,    77,   103,
     165,   626,   217,   218,   219,   297,   298,   243,   598,   627,
     290,   627,   295,   295,   297,   298,   301,   134,   139,   109,
     361,   364,   284,   292,   371,   626,   382,   383,   184,   381,
      43,    61,   184,   547,   548,   402,   184,   190,   627,   281,
     281,   416,   417,   627,   115,   423,   115,   184,   368,   369,
     150,   387,   402,     1,   157,   625,   110,   157,   342,   625,
     627,   115,   139,   104,   402,    27,   184,   626,   627,   627,
     440,   441,   627,   382,   184,   402,   402,   549,   627,   382,
     150,   150,   402,   184,   190,   627,   627,   139,   440,   181,
     181,   153,   153,   153,   627,   150,   184,   183,    33,   510,
     511,   512,   402,     8,   172,    16,   402,   210,    27,   403,
     403,   184,   403,   403,   403,   403,   227,   565,   566,   627,
     187,   187,   403,   402,   383,   402,   242,   400,   401,   187,
     323,   187,   323,     3,   330,   346,   379,   330,   346,   379,
      31,   347,   379,   347,   379,   390,   403,   115,   165,   167,
     167,   384,   403,   403,   457,   458,   460,   460,   460,   460,
     459,   460,   460,   460,    69,   464,   464,   463,   465,   465,
     465,   465,   466,   466,   467,   467,   227,    92,    92,    92,
     181,   402,   482,   482,   402,   495,   184,   403,   505,   626,
     146,   184,   505,    27,   362,   497,   104,   104,   367,    27,
     628,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,   349,   350,   351,    92,   134,   139,   355,   356,   357,
     627,   157,   157,   349,   625,   124,   129,    53,    55,    97,
     248,   261,   263,   274,   275,   276,   278,   280,   599,   600,
     601,   602,   603,   604,   611,   617,   618,   243,    92,   233,
     374,   296,   627,   139,   403,   115,   627,   627,   129,   181,
     181,   184,   184,   181,   104,   184,   104,   184,   104,    34,
      92,    94,   144,   418,   419,   533,   627,    54,   213,   251,
     408,   409,   627,    92,   104,   184,   381,   184,   626,    94,
      43,   626,   625,    94,   139,   533,   627,   403,   422,   181,
     184,   184,   184,   184,   104,   185,   144,   533,   181,   184,
     184,   150,   181,   382,   382,   181,   104,   184,   104,   184,
     139,   533,   403,   185,   402,   402,   402,   627,   511,   512,
     127,   193,   181,   181,   128,   187,    92,   214,   215,   229,
      92,   214,   215,   229,    92,   233,   221,   104,   231,   139,
     187,   184,    47,    71,    72,   241,   404,   414,   181,   491,
     571,   401,   346,    31,    31,   187,   323,   187,   110,   627,
     167,   403,   433,   434,   115,   429,   430,   460,   150,   153,
     256,   478,   497,   572,   575,   576,   577,   578,   579,   583,
     585,   587,   588,    46,   149,   153,   207,   534,   536,   538,
     539,   555,   556,   557,   558,   627,   534,   532,   538,   532,
     181,   182,   104,   184,   184,   104,   184,   145,   162,   145,
     162,   134,   387,   367,   350,   129,   536,   357,   403,   533,
     625,   625,   125,   126,   625,   274,   275,   276,   280,   627,
     260,   271,   260,   271,    27,   283,    94,   110,   153,   605,
     608,   599,    37,    42,    58,    60,    69,    95,   221,   373,
     539,   288,   289,   223,   296,   305,   403,   627,    92,   374,
     296,   625,   150,   549,   550,   627,   549,   550,   115,   124,
     534,   115,   403,   144,   419,   144,    34,   144,   418,   419,
     144,   533,   251,    52,    57,    75,   115,   418,   424,   425,
     426,   409,   533,   534,   369,    92,   181,   194,   129,   341,
     625,   157,   129,    94,   341,   403,   139,   419,   150,   115,
     403,   403,   144,    97,   443,   444,   445,   447,   448,    97,
     451,   452,   453,   454,   382,   181,   181,   150,   549,   549,
     403,   139,   187,   403,   184,   184,   184,    33,   512,   127,
     193,     9,    10,   100,   120,   122,   150,   191,   507,   509,
     520,   521,   524,    27,   228,   230,   403,   403,   403,   228,
     230,   403,   403,   403,   403,   403,   403,   115,   403,   403,
     384,   153,   153,   153,   150,   183,   242,   568,   569,   153,
     206,   385,   187,   110,   379,   379,   379,   433,    93,   103,
     113,   124,   435,   436,   437,   438,   104,   627,   104,   402,
     572,   579,   150,   282,   461,   624,    94,   166,   249,   250,
     252,   259,   269,   281,   573,   574,   593,   594,   595,   596,
     619,   622,   255,   257,   580,   598,   264,   584,   620,   244,
     245,   267,   589,   590,   153,   153,   536,   153,   141,   173,
     190,   535,   141,   403,   497,   134,   387,   551,   356,   283,
      27,    94,   110,   153,   612,    27,   605,   374,   535,   223,
     223,   480,   284,   303,   533,   373,   223,   187,   381,   184,
     184,   141,   184,   184,   417,   144,   418,   627,   403,   144,
     403,   124,   403,   144,   419,   144,   403,   144,   115,   115,
     403,   627,   426,    75,   534,   384,   403,   625,   104,   341,
     403,   139,   381,   441,   403,   403,   110,   444,   445,    97,
     183,   110,   445,   448,   115,   534,    97,   110,   452,    97,
     110,   454,   181,   381,   184,   184,   403,   194,   451,   129,
     191,   509,     7,   382,   627,   191,   520,   187,   229,   229,
     229,   229,   233,   566,   183,   402,   402,   402,   571,   569,
     115,   491,   625,   125,   126,   437,   438,   438,   434,   103,
     431,   430,   181,   184,   572,   586,   247,   213,   251,   265,
     272,   623,    94,   253,   254,   621,   247,   576,   623,   463,
     593,   577,   144,   279,   581,   582,   621,   283,   592,    76,
     591,   184,   190,   534,   537,   184,   184,   184,    27,   133,
     197,   614,   615,   616,    27,   613,   614,   268,   609,   104,
     606,   167,   627,   254,   374,   480,   181,   403,   144,   403,
     144,   418,   403,   144,   403,   403,   627,   627,   425,   403,
     123,   123,    94,   625,   403,   181,   183,   183,   403,   384,
     403,   183,   183,   627,   183,   115,   534,   115,   183,   115,
     534,   183,   181,   110,   512,   627,   191,   181,   512,   627,
     403,   403,   403,   403,   403,   403,   184,   184,   184,   150,
     153,   570,   627,   438,   625,   181,   465,    51,   126,   463,
     463,   266,   273,   283,   597,   597,   578,   150,   277,    92,
     184,   104,   184,   612,   612,   616,   104,   184,    27,   610,
     621,   607,   608,   184,   376,   377,   480,   115,   221,   304,
     284,   167,   403,   403,   144,   403,    52,   384,   403,   341,
     403,   384,    92,   384,   403,   627,   183,   627,   403,   627,
     183,   384,   115,    91,   180,   513,   512,   627,   193,   512,
     194,   451,   402,   115,   104,   184,   463,   463,   195,   402,
     534,   534,    92,    27,   262,   104,   104,   438,   533,   627,
     115,   221,   627,   376,   403,   115,   534,    92,   183,    92,
     627,     5,   130,   516,   517,   519,   521,    26,   131,   514,
     515,   518,   521,   193,   512,   193,   110,   181,   627,   115,
     385,   463,   181,   534,   608,   377,   438,   302,   627,   115,
     221,   627,   183,   534,   384,   403,   534,   183,    91,   130,
     519,   180,   131,   518,   193,   115,   104,   184,   627,   403,
     302,   627,   115,   384,   403,   183,   183,   627,   115,   570,
     104,   184,   290,   302,   627,   183,   627,   115,   385,   303,
     403,   303,   104,   184,   627,   480,   480,   115,   570,   184,
     195,   627,   385,   284,   184,   627,   570,   221,   115,   627,
     303,   480
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
     385,   386,   387,   388,   389,   389,   390,   390,   390,   390,
     391,   392,   393,   394,   395,   395,   396,   397,   398,   399,
     400,   400,   401,   401,   401,   401,   402,   402,   403,   403,
     403,   403,   403,   403,   404,   404,   404,   404,   404,   404,
     404,   405,   406,   407,   407,   408,   408,   408,   409,   409,
     410,   410,   411,   412,   412,   412,   413,   413,   413,   413,
     413,   414,   414,   415,   416,   416,   417,   417,   417,   417,
     417,   417,   417,   417,   417,   417,   417,   417,   418,   419,
     420,   421,   421,   422,   422,   422,   422,   423,   423,   424,
     424,   424,   425,   425,   425,   426,   426,   426,   427,   428,
     429,   429,   430,   430,   431,   432,   432,   433,   433,   434,
     434,   435,   435,   435,   435,   435,   435,   435,   436,   436,
     437,   437,   438,   439,   439,   440,   440,   441,   441,   442,
     443,   443,   444,   445,   445,   446,   447,   447,   448,   449,
     449,   450,   450,   451,   451,   452,   452,   453,   453,   454,
     454,   455,   456,   456,   457,   457,   458,   458,   458,   458,
     458,   459,   458,   458,   458,   458,   460,   460,   461,   461,
     462,   462,   463,   463,   463,   464,   464,   464,   464,   464,
     465,   465,   465,   466,   466,   466,   467,   467,   468,   468,
     469,   469,   470,   470,   471,   471,   472,   472,   472,   472,
     473,   473,   473,   474,   474,   474,   474,   474,   474,   475,
     475,   475,   476,   476,   476,   476,   477,   477,   478,   478,
     479,   479,   479,   480,   480,   480,   480,   481,   482,   482,
     482,   483,   483,   484,   484,   484,   484,   485,   485,   486,
     486,   486,   486,   486,   486,   486,   487,   487,   488,   488,
     489,   489,   489,   489,   489,   490,   490,   491,   491,   492,
     492,   492,   493,   493,   493,   493,   494,   494,   495,   496,
     496,   496,   496,   496,   496,   496,   496,   496,   496,   497,
     497,   498,   498,   498,   499,   500,   500,   501,   502,   503,
     504,   504,   505,   505,   506,   506,   507,   507,   507,   508,
     508,   508,   508,   508,   508,   509,   509,   510,   510,   511,
     512,   512,   513,   513,   514,   514,   515,   515,   515,   515,
     516,   516,   517,   517,   517,   517,   518,   518,   519,   519,
     520,   520,   520,   520,   521,   521,   521,   521,   522,   522,
     523,   523,   524,   525,   525,   525,   525,   525,   525,   526,
     527,   527,   528,   528,   529,   530,   531,   531,   532,   532,
     533,   534,   534,   534,   535,   535,   535,   536,   536,   536,
     536,   536,   537,   537,   538,   539,   539,   539,   539,   539,
     539,   539,   539,   539,   540,   541,   541,   541,   542,   543,
     544,   544,   544,   545,   545,   545,   545,   545,   546,   547,
     547,   547,   547,   547,   547,   547,   548,   549,   550,   551,
     552,   552,   553,   554,   555,   555,   556,   557,   557,   558,
     559,   559,   559,   560,   560,   560,   560,   560,   560,   560,
     560,   560,   560,   561,   561,   562,   562,   563,   564,   565,
     565,   566,   567,   568,   568,   569,   569,   569,   569,   570,
     571,   571,   572,   573,   573,   574,   574,   575,   575,   576,
     576,   577,   577,   578,   578,   579,   580,   580,   581,   581,
     582,   583,   583,   583,   584,   584,   585,   586,   586,   587,
     588,   588,   589,   589,   590,   590,   590,   591,   591,   592,
     592,   593,   593,   593,   593,   593,   594,   595,   596,   597,
     597,   597,   598,   598,   599,   599,   599,   599,   599,   599,
     599,   599,   600,   600,   600,   600,   601,   601,   602,   603,
     603,   604,   604,   604,   605,   605,   606,   606,   607,   607,
     608,   609,   609,   610,   610,   611,   611,   611,   612,   612,
     613,   613,   614,   614,   615,   615,   616,   616,   617,   618,
     618,   619,   619,   619,   620,   621,   621,   621,   621,   622,
     622,   623,   623,   624,   625,   626,   626,   627,   627,   627,
     627,   627,   627,   627,   627,   627,   627,   627,   627,   627,
     627,   627,   627,   628,   628,   628,   628,   628,   628,   628,
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
     628,   628,   629,   629
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
       2,     3,     3,     2,     3,     2,     2,     3,     4,     5,
       5,     2,     4,     5,     3,     3,     2,     2,     8,     3,
       1,     2,     3,     7,    10,    13,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     1,     1,     2,     4,     3,
       5,     4,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     3,     1,     4,     3,     5,     4,     6,
       4,     6,     5,     7,     4,     5,     5,     6,     3,     3,
       2,     1,     3,     4,     5,     3,     6,     4,     5,     1,
       2,     3,     1,     2,     1,     6,     3,     3,     2,     3,
       1,     3,     2,     3,     2,     3,     4,     1,     3,     1,
       2,     1,     1,     1,     2,     2,     2,     3,     1,     1,
       2,     2,     2,     5,     5,     1,     4,     3,     4,     8,
       1,     2,     3,     2,     3,     8,     1,     2,     3,     8,
      10,     8,    10,     1,     2,     4,     7,     1,     2,     4,
       7,     8,     1,     3,     1,     3,     1,     3,     3,     3,
       3,     0,     4,     3,     3,     3,     1,     5,     0,     1,
       1,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     4,     1,     4,
       1,     4,     1,     4,     1,     2,     1,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     5,     5,     6,     3,     4,     1,     2,
       3,     2,     2,     1,     2,     2,     1,     1,     1,     3,
       3,     1,     1,     1,     2,     1,     2,     2,     1,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     2,     1,
       2,     2,     2,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     3,     4,     1,     2,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     3,     1,     4,     4,
       3,     4,     1,     3,     1,     1,     1,     1,     1,     4,
       5,     8,     9,     9,    10,     1,     2,     1,     2,     6,
       0,     1,     3,     3,     0,     1,     1,     1,     2,     2,
       0,     1,     1,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     2,
       3,     3,     2,     1,     1,     1,     1,     1,     1,     4,
       3,     7,     3,     7,     4,     4,     3,     7,     1,     2,
       2,     1,     2,     3,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     4,     4,     3,     3,
       3,     4,     4,     3,     4,     6,     4,     6,     4,     3,
       4,     6,     6,     4,     6,     6,     4,     1,     2,     1,
       1,     1,     3,     3,     1,     1,     4,     5,     6,     3,
       3,     3,     3,     5,     7,     7,     5,     5,     5,     7,
       7,     5,     5,     3,     3,     5,     7,     5,     7,     1,
       4,     3,     5,     1,     2,     3,     7,    10,    13,     3,
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
     115,   627,    -1,   115,   627,   533,    -1,   115,   627,   139,
     403,    -1,   115,   627,   533,   139,   403,    -1,   115,   627,
     139,   403,   187,    -1,   404,   187,    -1,   237,   239,   403,
     187,    -1,   240,   153,   402,   184,   384,    -1,   235,   238,
     187,    -1,   236,   238,   187,    -1,   414,   397,    -1,   183,
     384,    -1,    47,   153,   402,   184,   194,   384,   123,   384,
      -1,   241,   385,   400,    -1,   401,    -1,   400,   401,    -1,
     242,   571,   385,    -1,   242,   571,   153,   115,   627,   184,
     385,    -1,   242,   571,   153,   115,   627,   104,   115,   627,
     184,   385,    -1,   242,   571,   153,   115,   627,   104,   115,
     627,   104,   115,   627,   184,   385,    -1,   403,    -1,   402,
     104,   403,    -1,   405,    -1,   442,    -1,   449,    -1,   455,
      -1,   567,    -1,   404,    -1,   456,    -1,   439,    -1,   560,
      -1,   561,    -1,   563,    -1,   562,    -1,   564,    -1,   414,
     406,    -1,   183,   403,    -1,    65,   281,    -1,    70,   281,
      -1,   213,    -1,   251,    -1,    54,   251,    -1,   408,   424,
      75,   403,    -1,   408,    75,   403,    -1,    45,   407,   423,
     409,   409,    -1,    45,   407,   423,   409,    -1,    40,   115,
     627,    -1,   415,    -1,   420,    -1,   410,    -1,   412,    -1,
     427,    -1,   432,    -1,   428,    -1,   411,    -1,   412,    -1,
     414,   413,    -1,    45,   115,   416,    -1,   417,    -1,   416,
     104,   115,   417,    -1,   627,   144,   403,    -1,   627,    34,
     124,   144,   403,    -1,   627,   533,   144,   403,    -1,   627,
     533,    34,   124,   144,   403,    -1,   627,   418,   144,   403,
      -1,   627,    34,   124,   418,   144,   403,    -1,   627,   533,
     418,   144,   403,    -1,   627,   533,    34,   124,   418,   144,
     403,    -1,   627,   419,   144,   403,    -1,   627,   533,   419,
     144,   403,    -1,   627,   418,   419,   144,   403,    -1,   627,
     533,   418,   419,   144,   403,    -1,    94,   115,   627,    -1,
     270,   115,   627,    -1,    50,   421,    -1,   422,    -1,   421,
     104,   422,    -1,   115,   627,   139,   403,    -1,   115,   627,
     533,   139,   403,    -1,   419,   139,   403,    -1,   115,   627,
     533,   419,   139,   403,    -1,   115,   627,   144,   403,    -1,
     115,   627,   533,   144,   403,    -1,   425,    -1,   115,   627,
      -1,   115,   627,   425,    -1,   418,    -1,   418,   426,    -1,
     426,    -1,    57,   115,   627,    52,   115,   627,    -1,    52,
     115,   627,    -1,    57,   115,   627,    -1,   208,   403,    -1,
     168,   167,   429,    -1,   430,    -1,   429,   104,   430,    -1,
     115,   627,    -1,   115,   627,   431,    -1,   103,   625,    -1,
     165,   167,   433,    -1,    68,   165,   167,   433,    -1,   434,
      -1,   433,   104,   434,    -1,   403,    -1,   403,   435,    -1,
     436,    -1,   437,    -1,   438,    -1,   436,   437,    -1,   436,
     438,    -1,   437,   438,    -1,   436,   437,   438,    -1,    93,
      -1,   113,    -1,   124,   125,    -1,   124,   126,    -1,   103,
     625,    -1,    66,   115,   440,   185,   403,    -1,   132,   115,
     440,   185,   403,    -1,   441,    -1,   440,   104,   115,   441,
      -1,   627,   144,   403,    -1,   627,   533,   144,   403,    -1,
      71,   153,   402,   184,   443,   110,   183,   403,    -1,   444,
      -1,   443,   444,    -1,   445,   183,   403,    -1,    97,   403,
      -1,   445,    97,   403,    -1,    71,   153,   402,   184,   447,
     110,   183,   384,    -1,   448,    -1,   447,   448,    -1,   445,
     183,   384,    -1,    72,   153,   402,   184,   451,   110,   183,
     403,    -1,    72,   153,   402,   184,   451,   110,   115,   627,
     183,   403,    -1,    72,   153,   402,   184,   453,   110,   183,
     384,    -1,    72,   153,   402,   184,   451,   110,   115,   627,
     183,   384,    -1,   452,    -1,   451,   452,    -1,    97,   534,
     183,   403,    -1,    97,   115,   627,    92,   534,   183,   403,
      -1,   454,    -1,   453,   454,    -1,    97,   534,   183,   384,
      -1,    97,   115,   627,    92,   534,   183,   384,    -1,    47,
     153,   402,   184,   194,   403,   123,   403,    -1,   457,    -1,
     456,   164,   457,    -1,   458,    -1,   457,    90,   458,    -1,
     460,    -1,   460,   474,   460,    -1,   460,   475,   460,    -1,
     460,   129,   460,    -1,   460,   159,   460,    -1,    -1,   460,
     154,   459,   460,    -1,   460,   152,   460,    -1,   460,   140,
     460,    -1,   460,   138,   460,    -1,   462,    -1,   462,   246,
      69,   572,   461,    -1,    -1,   624,    -1,   463,    -1,   463,
     195,   463,    -1,   464,    -1,   463,   173,   464,    -1,   463,
     155,   464,    -1,   465,    -1,   464,   190,   465,    -1,   464,
     114,   465,    -1,   464,   143,   465,    -1,   464,   156,   465,
      -1,   466,    -1,   465,   197,   466,    -1,   465,   206,   466,
      -1,   467,    -1,   466,   147,   467,    -1,   466,   133,   467,
      -1,   468,    -1,   468,    49,   227,   534,    -1,   469,    -1,
     469,   196,    92,   534,    -1,   470,    -1,   470,    98,    92,
     532,    -1,   471,    -1,   471,    99,    92,   532,    -1,   473,
      -1,   472,   473,    -1,   173,    -1,   155,    -1,   472,   173,
      -1,   472,   155,    -1,   476,    -1,   480,    -1,   477,    -1,
     199,    -1,   204,    -1,   203,    -1,   202,    -1,   201,    -1,
     200,    -1,   148,    -1,   176,    -1,   137,    -1,    74,   150,
     382,   181,    -1,    74,   218,   150,   382,   181,    -1,    74,
     217,   150,   382,   181,    -1,    74,    92,   549,   150,   382,
     181,    -1,   478,   150,   181,    -1,   478,   150,   402,   181,
      -1,   479,    -1,   478,   479,    -1,   174,   627,    16,    -1,
     174,    17,    -1,   174,    18,    -1,   481,    -1,   481,   482,
      -1,   189,   482,    -1,   482,    -1,   188,    -1,   483,    -1,
     483,   188,   482,    -1,   483,   189,   482,    -1,   484,    -1,
     493,    -1,   485,    -1,   485,   494,    -1,   488,    -1,   488,
     494,    -1,   486,   490,    -1,   487,    -1,   102,   119,    -1,
     111,   119,    -1,    95,   119,    -1,   186,   119,    -1,   112,
     119,    -1,   136,   119,    -1,   135,   119,    -1,   490,    -1,
      96,   490,    -1,   489,   490,    -1,   117,    -1,   169,   119,
      -1,    88,   119,    -1,   178,   119,    -1,   177,   119,    -1,
      89,   119,    -1,   539,    -1,   491,    -1,   627,    -1,   492,
      -1,   190,    -1,    11,    -1,    19,    -1,   496,    -1,   493,
     494,    -1,   493,   153,   184,    -1,   493,   153,   505,   184,
      -1,   495,    -1,   494,   495,    -1,   151,   402,   182,    -1,
     497,    -1,   499,    -1,   500,    -1,   501,    -1,   504,    -1,
     506,    -1,   502,    -1,   503,    -1,   552,    -1,   386,    -1,
     498,    -1,   551,    -1,   107,    -1,   146,    -1,   121,    -1,
     115,   627,    -1,   153,   184,    -1,   153,   402,   184,    -1,
     116,    -1,   166,   150,   402,   181,    -1,   198,   150,   402,
     181,    -1,   628,   153,   184,    -1,   628,   153,   505,   184,
      -1,   403,    -1,   505,   104,   403,    -1,   507,    -1,   525,
      -1,   508,    -1,   522,    -1,   523,    -1,   154,   627,   512,
     127,    -1,   154,   627,   510,   512,   127,    -1,   154,   627,
     512,   193,   191,   627,   512,   193,    -1,   154,   627,   512,
     193,   509,   191,   627,   512,   193,    -1,   154,   627,   510,
     512,   193,   191,   627,   512,   193,    -1,   154,   627,   510,
     512,   193,   509,   191,   627,   512,   193,    -1,   520,    -1,
     509,   520,    -1,   511,    -1,   510,   511,    -1,    33,   627,
     512,   129,   512,   513,    -1,    -1,    33,    -1,   180,   514,
     180,    -1,    91,   516,    91,    -1,    -1,   515,    -1,   131,
      -1,   518,    -1,   515,   131,    -1,   515,   518,    -1,    -1,
     517,    -1,   130,    -1,   519,    -1,   517,   130,    -1,   517,
     519,    -1,    26,    -1,   521,    -1,     5,    -1,   521,    -1,
     507,    -1,    10,    -1,   524,    -1,   521,    -1,     9,    -1,
     120,    -1,   122,    -1,   150,   382,   181,    -1,   209,    28,
     210,    -1,   209,   210,    -1,   171,   626,   172,    -1,   171,
     626,     8,    -1,   100,     7,    -1,   526,    -1,   527,    -1,
     528,    -1,   529,    -1,   530,    -1,   531,    -1,    41,   150,
     381,   181,    -1,    20,   381,   181,    -1,    43,   150,   402,
     181,   150,   381,   181,    -1,    21,   381,   181,    -1,    95,
     150,   402,   181,   150,   381,   181,    -1,    69,   150,   382,
     181,    -1,    37,   150,   382,   181,    -1,    22,   381,   181,
      -1,    58,   150,   402,   181,   150,   381,   181,    -1,   538,
      -1,   538,   141,    -1,    92,   534,    -1,   536,    -1,   536,
     535,    -1,   207,   153,   184,    -1,   141,    -1,   190,    -1,
     173,    -1,   538,    -1,   539,    -1,   149,   153,   184,    -1,
     555,    -1,   558,    -1,   534,    -1,   537,   104,   534,    -1,
     627,    -1,   541,    -1,   547,    -1,   545,    -1,   548,    -1,
     546,    -1,   544,    -1,   543,    -1,   542,    -1,   540,    -1,
     221,   153,   184,    -1,    42,   153,   184,    -1,    42,   153,
     547,   184,    -1,    42,   153,   548,   184,    -1,    69,   153,
     184,    -1,    37,   153,   184,    -1,    58,   153,   184,    -1,
      58,   153,   626,   184,    -1,    58,   153,    27,   184,    -1,
      95,   153,   184,    -1,    95,   153,   627,   184,    -1,    95,
     153,   627,   104,   549,   184,    -1,    95,   153,   190,   184,
      -1,    95,   153,   190,   104,   549,   184,    -1,    60,   153,
     627,   184,    -1,    43,   153,   184,    -1,    43,   153,   627,
     184,    -1,    43,   153,   627,   104,   549,   184,    -1,    43,
     153,   627,   104,   550,   184,    -1,    43,   153,   190,   184,
      -1,    43,   153,   190,   104,   549,   184,    -1,    43,   153,
     190,   104,   550,   184,    -1,    61,   153,   627,   184,    -1,
     627,    -1,   627,   141,    -1,    27,    -1,   553,    -1,   554,
      -1,   627,   142,   146,    -1,    46,   367,   387,    -1,   556,
      -1,   557,    -1,    46,   153,   190,   184,    -1,    46,   153,
     184,    92,   534,    -1,    46,   153,   537,   184,    92,   534,
      -1,   153,   536,   184,    -1,    31,   216,   217,    -1,    31,
     216,   218,    -1,    31,   216,   219,    -1,   222,   221,   403,
     229,   403,    -1,   222,   221,   403,    92,   228,   229,   403,
      -1,   222,   221,   403,    92,   230,   229,   403,    -1,   222,
     221,   403,   214,   403,    -1,   222,   221,   403,   215,   403,
      -1,   222,   223,   403,   229,   403,    -1,   222,   223,   403,
      92,   228,   229,   403,    -1,   222,   223,   403,    92,   230,
     229,   403,    -1,   222,   223,   403,   214,   403,    -1,   222,
     223,   403,   215,   403,    -1,   220,   221,   403,    -1,   220,
     223,   403,    -1,   225,   221,   403,   233,   403,    -1,   225,
     226,   227,   221,   403,   233,   403,    -1,   224,   221,   403,
      92,   403,    -1,   232,   115,   565,   231,   403,   183,   403,
      -1,   566,    -1,   565,   104,   115,   566,    -1,   627,   139,
     403,    -1,   241,   150,   402,   181,   568,    -1,   569,    -1,
     568,   569,    -1,   242,   571,   570,    -1,   242,   571,   153,
     115,   627,   184,   570,    -1,   242,   571,   153,   115,   627,
     104,   115,   627,   184,   570,    -1,   242,   571,   153,   115,
     627,   104,   115,   627,   104,   115,   627,   184,   570,    -1,
     150,   402,   181,    -1,   491,    -1,   571,   206,   491,    -1,
     575,   573,    -1,    -1,   574,    -1,   593,    -1,   574,   593,
      -1,   576,    -1,   575,   259,   576,    -1,   577,    -1,   576,
     255,   577,    -1,   578,    -1,   577,   257,   144,   578,    -1,
     579,    -1,   256,   579,    -1,   583,   580,   581,    -1,    -1,
     598,    -1,    -1,   582,    -1,   279,   150,   402,   181,    -1,
     587,   584,    -1,   153,   572,   184,    -1,   585,    -1,    -1,
     620,    -1,   478,   150,   586,   181,    -1,    -1,   572,    -1,
     588,   589,    -1,   497,    -1,   150,   402,   181,    -1,    -1,
     590,    -1,   245,   591,    -1,   244,   592,    -1,   267,    -1,
      -1,    76,    -1,    -1,   283,    -1,   594,    -1,   595,    -1,
     596,    -1,   622,    -1,   619,    -1,   166,    -1,   281,   463,
     597,    -1,   250,   621,   597,    -1,   283,    -1,   273,    -1,
     266,    -1,   243,   599,    -1,   598,   243,   599,    -1,   600,
      -1,   601,    -1,   602,    -1,   617,    -1,   603,    -1,   611,
      -1,   604,    -1,   618,    -1,    97,   271,    -1,    97,   260,
      -1,   263,    -1,   278,    -1,   248,   271,    -1,   248,   260,
      -1,    55,   627,    27,    -1,   274,    -1,    53,   274,    -1,
     276,   605,    -1,   276,   153,   605,   606,   184,    -1,    53,
     276,    -1,   608,    -1,   110,    -1,    -1,   104,   607,    -1,
     608,    -1,   607,   104,   608,    -1,    94,    27,   609,   610,
      -1,    -1,   268,    27,    -1,    -1,   621,   262,    -1,   275,
     283,   612,   614,    -1,   275,   283,   110,   614,    -1,    53,
     275,   283,    -1,    94,    27,    -1,   153,   613,   184,    -1,
      27,    -1,   613,   104,    27,    -1,    -1,   615,    -1,   616,
      -1,   615,   616,    -1,   197,   612,    -1,   133,   612,    -1,
     261,    27,    -1,   280,    -1,    53,   280,    -1,    94,   213,
      -1,    94,   251,    -1,   252,   247,    -1,   264,   621,   277,
      -1,   253,   463,    -1,    94,   126,   463,    -1,    94,    51,
     463,    -1,   254,   463,   195,   463,    -1,   269,   623,    -1,
     249,   623,    -1,   272,    -1,   265,    -1,   282,   247,   465,
      -1,    27,    -1,    15,    -1,   627,    -1,   628,    -1,    95,
      -1,    37,    -1,    42,    -1,    43,    -1,   149,    -1,    47,
      -1,   221,    -1,    58,    -1,    60,    -1,    61,    -1,    69,
      -1,    72,    -1,    71,    -1,   207,    -1,   240,    -1,   629,
      -1,    23,    -1,   211,    -1,   124,    -1,    36,    -1,   258,
      -1,    35,    -1,   218,    -1,   217,    -1,   143,    -1,    41,
      -1,   256,    -1,   257,    -1,   271,    -1,   260,    -1,   248,
      -1,   282,    -1,   274,    -1,   276,    -1,   275,    -1,   280,
      -1,   252,    -1,   247,    -1,    76,    -1,   213,    -1,   251,
      -1,    51,    -1,   219,    -1,   232,    -1,   299,    -1,   226,
      -1,   199,    -1,   204,    -1,   203,    -1,   202,    -1,   201,
      -1,   200,    -1,    94,    -1,   108,    -1,   109,    -1,   183,
      -1,    45,    -1,    34,    -1,    65,    -1,    70,    -1,    57,
      -1,    52,    -1,    54,    -1,    75,    -1,    40,    -1,   144,
      -1,    50,    -1,   208,    -1,   167,    -1,   168,    -1,   165,
      -1,    68,    -1,    93,    -1,   113,    -1,   125,    -1,   126,
      -1,   103,    -1,    66,    -1,   132,    -1,   185,    -1,    97,
      -1,    92,    -1,   194,    -1,   123,    -1,   164,    -1,    90,
      -1,    49,    -1,   227,    -1,    98,    -1,   195,    -1,   114,
      -1,   156,    -1,   197,    -1,   147,    -1,   133,    -1,    74,
      -1,    99,    -1,   196,    -1,   148,    -1,   179,    -1,   192,
      -1,   157,    -1,   134,    -1,   128,    -1,   163,    -1,   145,
      -1,   162,    -1,    31,    -1,    38,    -1,    56,    -1,   110,
      -1,    39,    -1,    55,    -1,   212,    -1,    48,    -1,    59,
      -1,    32,    -1,    46,    -1,   270,    -1,   246,    -1,   279,
      -1,   281,    -1,   250,    -1,   264,    -1,   277,    -1,   269,
      -1,   249,    -1,   263,    -1,   278,    -1,   268,    -1,   262,
      -1,   261,    -1,   245,    -1,   244,    -1,   267,    -1,   253,
      -1,   254,    -1,   283,    -1,   273,    -1,   272,    -1,   265,
      -1,   225,    -1,   231,    -1,   228,    -1,   222,    -1,   215,
      -1,   214,    -1,   216,    -1,   233,    -1,   223,    -1,   224,
      -1,   230,    -1,   220,    -1,   229,    -1,    64,    -1,    62,
      -1,    73,    -1,   166,    -1,   198,    -1,   239,    -1,   234,
      -1,   237,    -1,   238,    -1,   235,    -1,   236,    -1,   241,
      -1,   242,    -1,    44,    -1,   243,    -1,    63,    -1,   292,
      -1,   290,    -1,   291,    -1,   296,    -1,   297,    -1,   298,
      -1,   293,    -1,   294,    -1,   295,    -1,    77,    -1,    78,
      -1,    79,    -1,    80,    -1,    81,    -1,    82,    -1,    83,
      -1,    84,    -1,    85,    -1,    86,    -1,    87,    -1,   284,
      -1,   285,    -1,   286,    -1,   287,    -1,   288,    -1,   289,
      -1,   300,    -1,   301,    -1,   302,    -1,   303,    -1,   304,
      -1,   305,    -1,   306,    -1,    88,    -1,   102,    -1,   111,
      -1,   169,    -1,   177,    -1,   186,    -1,   135,    -1,    89,
      -1,   112,    -1,   136,    -1,   178,    -1,   625,   118,   626,
      -1,    24,    -1
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
     749,   752,   756,   760,   763,   767,   770,   773,   777,   782,
     788,   794,   797,   802,   808,   812,   816,   819,   822,   831,
     835,   837,   840,   844,   852,   863,   877,   879,   883,   885,
     887,   889,   891,   893,   895,   897,   899,   901,   903,   905,
     907,   909,   912,   915,   918,   921,   923,   925,   928,   933,
     937,   943,   948,   952,   954,   956,   958,   960,   962,   964,
     966,   968,   970,   973,   977,   979,   984,   988,   994,   999,
    1006,  1011,  1018,  1024,  1032,  1037,  1043,  1049,  1056,  1060,
    1064,  1067,  1069,  1073,  1078,  1084,  1088,  1095,  1100,  1106,
    1108,  1111,  1115,  1117,  1120,  1122,  1129,  1133,  1137,  1140,
    1144,  1146,  1150,  1153,  1157,  1160,  1164,  1169,  1171,  1175,
    1177,  1180,  1182,  1184,  1186,  1189,  1192,  1195,  1199,  1201,
    1203,  1206,  1209,  1212,  1218,  1224,  1226,  1231,  1235,  1240,
    1249,  1251,  1254,  1258,  1261,  1265,  1274,  1276,  1279,  1283,
    1292,  1303,  1312,  1323,  1325,  1328,  1333,  1341,  1343,  1346,
    1351,  1359,  1368,  1370,  1374,  1376,  1380,  1382,  1386,  1390,
    1394,  1398,  1399,  1404,  1408,  1412,  1416,  1418,  1424,  1425,
    1427,  1429,  1433,  1435,  1439,  1443,  1445,  1449,  1453,  1457,
    1461,  1463,  1467,  1471,  1473,  1477,  1481,  1483,  1488,  1490,
    1495,  1497,  1502,  1504,  1509,  1511,  1514,  1516,  1518,  1521,
    1524,  1526,  1528,  1530,  1532,  1534,  1536,  1538,  1540,  1542,
    1544,  1546,  1548,  1553,  1559,  1565,  1572,  1576,  1581,  1583,
    1586,  1590,  1593,  1596,  1598,  1601,  1604,  1606,  1608,  1610,
    1614,  1618,  1620,  1622,  1624,  1627,  1629,  1632,  1635,  1637,
    1640,  1643,  1646,  1649,  1652,  1655,  1658,  1660,  1663,  1666,
    1668,  1671,  1674,  1677,  1680,  1683,  1685,  1687,  1689,  1691,
    1693,  1695,  1697,  1699,  1702,  1706,  1711,  1713,  1716,  1720,
    1722,  1724,  1726,  1728,  1730,  1732,  1734,  1736,  1738,  1740,
    1742,  1744,  1746,  1748,  1750,  1753,  1756,  1760,  1762,  1767,
    1772,  1776,  1781,  1783,  1787,  1789,  1791,  1793,  1795,  1797,
    1802,  1808,  1817,  1827,  1837,  1848,  1850,  1853,  1855,  1858,
    1865,  1866,  1868,  1872,  1876,  1877,  1879,  1881,  1883,  1886,
    1889,  1890,  1892,  1894,  1896,  1899,  1902,  1904,  1906,  1908,
    1910,  1912,  1914,  1916,  1918,  1920,  1922,  1924,  1928,  1932,
    1935,  1939,  1943,  1946,  1948,  1950,  1952,  1954,  1956,  1958,
    1963,  1967,  1975,  1979,  1987,  1992,  1997,  2001,  2009,  2011,
    2014,  2017,  2019,  2022,  2026,  2028,  2030,  2032,  2034,  2036,
    2040,  2042,  2044,  2046,  2050,  2052,  2054,  2056,  2058,  2060,
    2062,  2064,  2066,  2068,  2070,  2074,  2078,  2083,  2088,  2092,
    2096,  2100,  2105,  2110,  2114,  2119,  2126,  2131,  2138,  2143,
    2147,  2152,  2159,  2166,  2171,  2178,  2185,  2190,  2192,  2195,
    2197,  2199,  2201,  2205,  2209,  2211,  2213,  2218,  2224,  2231,
    2235,  2239,  2243,  2247,  2253,  2261,  2269,  2275,  2281,  2287,
    2295,  2303,  2309,  2315,  2319,  2323,  2329,  2337,  2343,  2351,
    2353,  2358,  2362,  2368,  2370,  2373,  2377,  2385,  2396,  2410,
    2414,  2416,  2420,  2423,  2424,  2426,  2428,  2431,  2433,  2437,
    2439,  2443,  2445,  2450,  2452,  2455,  2459,  2460,  2462,  2463,
    2465,  2470,  2473,  2477,  2479,  2480,  2482,  2487,  2488,  2490,
    2493,  2495,  2499,  2500,  2502,  2505,  2508,  2510,  2511,  2513,
    2514,  2516,  2518,  2520,  2522,  2524,  2526,  2528,  2532,  2536,
    2538,  2540,  2542,  2545,  2549,  2551,  2553,  2555,  2557,  2559,
    2561,  2563,  2565,  2568,  2571,  2573,  2575,  2578,  2581,  2585,
    2587,  2590,  2593,  2599,  2602,  2604,  2606,  2607,  2610,  2612,
    2616,  2621,  2622,  2625,  2626,  2629,  2634,  2639,  2643,  2646,
    2650,  2652,  2656,  2657,  2659,  2661,  2664,  2667,  2670,  2673,
    2675,  2678,  2681,  2684,  2687,  2691,  2694,  2698,  2702,  2707,
    2710,  2713,  2715,  2717,  2721,  2723,  2725,  2727,  2729,  2731,
    2733,  2735,  2737,  2739,  2741,  2743,  2745,  2747,  2749,  2751,
    2753,  2755,  2757,  2759,  2761,  2763,  2765,  2767,  2769,  2771,
    2773,  2775,  2777,  2779,  2781,  2783,  2785,  2787,  2789,  2791,
    2793,  2795,  2797,  2799,  2801,  2803,  2805,  2807,  2809,  2811,
    2813,  2815,  2817,  2819,  2821,  2823,  2825,  2827,  2829,  2831,
    2833,  2835,  2837,  2839,  2841,  2843,  2845,  2847,  2849,  2851,
    2853,  2855,  2857,  2859,  2861,  2863,  2865,  2867,  2869,  2871,
    2873,  2875,  2877,  2879,  2881,  2883,  2885,  2887,  2889,  2891,
    2893,  2895,  2897,  2899,  2901,  2903,  2905,  2907,  2909,  2911,
    2913,  2915,  2917,  2919,  2921,  2923,  2925,  2927,  2929,  2931,
    2933,  2935,  2937,  2939,  2941,  2943,  2945,  2947,  2949,  2951,
    2953,  2955,  2957,  2959,  2961,  2963,  2965,  2967,  2969,  2971,
    2973,  2975,  2977,  2979,  2981,  2983,  2985,  2987,  2989,  2991,
    2993,  2995,  2997,  2999,  3001,  3003,  3005,  3007,  3009,  3011,
    3013,  3015,  3017,  3019,  3021,  3023,  3025,  3027,  3029,  3031,
    3033,  3035,  3037,  3039,  3041,  3043,  3045,  3047,  3049,  3051,
    3053,  3055,  3057,  3059,  3061,  3063,  3065,  3067,  3069,  3071,
    3073,  3075,  3077,  3079,  3081,  3083,  3085,  3087,  3089,  3091,
    3093,  3095,  3097,  3099,  3101,  3103,  3105,  3107,  3109,  3111,
    3113,  3115,  3117,  3119,  3121,  3123,  3125,  3127,  3129,  3131,
    3133,  3135,  3137,  3139,  3141,  3143,  3145,  3147,  3149,  3151,
    3153,  3155,  3157,  3161
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
    2347,  2355,  2372,  2380,  2388,  2394,  2404,  2416,  2429,  2441,
    2457,  2465,  2473,  2481,  2496,  2501,  2509,  2525,  2533,  2541,
    2549,  2556,  2567,  2573,  2579,  2590,  2605,  2610,  2625,  2626,
    2627,  2628,  2629,  2630,  2635,  2636,  2639,  2640,  2641,  2642,
    2643,  2648,  2663,  2670,  2674,  2681,  2685,  2689,  2696,  2704,
    2715,  2725,  2738,  2747,  2748,  2749,  2753,  2754,  2755,  2756,
    2757,  2761,  2767,  2777,  2785,  2791,  2803,  2807,  2811,  2815,
    2819,  2823,  2827,  2832,  2838,  2847,  2857,  2867,  2883,  2892,
    2901,  2909,  2915,  2927,  2935,  2945,  2953,  2965,  2971,  2982,
    2984,  2988,  2996,  3000,  3005,  3009,  3013,  3017,  3027,  3035,
    3042,  3048,  3059,  3063,  3072,  3080,  3086,  3096,  3102,  3112,
    3116,  3126,  3132,  3138,  3144,  3153,  3162,  3171,  3184,  3188,
    3196,  3202,  3212,  3220,  3229,  3242,  3249,  3261,  3265,  3277,
    3284,  3290,  3299,  3306,  3312,  3323,  3330,  3336,  3345,  3354,
    3361,  3372,  3379,  3391,  3397,  3409,  3415,  3426,  3432,  3443,
    3449,  3460,  3469,  3473,  3482,  3486,  3494,  3498,  3508,  3515,
    3524,  3534,  3533,  3547,  3556,  3565,  3578,  3582,  3595,  3598,
    3605,  3609,  3618,  3622,  3626,  3635,  3639,  3645,  3651,  3657,
    3668,  3672,  3676,  3684,  3688,  3694,  3704,  3708,  3718,  3722,
    3732,  3736,  3746,  3750,  3760,  3764,  3772,  3776,  3780,  3784,
    3794,  3798,  3802,  3810,  3814,  3818,  3822,  3826,  3830,  3838,
    3842,  3846,  3854,  3858,  3862,  3866,  3877,  3883,  3893,  3899,
    3909,  3913,  3917,  3955,  3959,  3969,  3979,  3992,  4001,  4011,
    4015,  4024,  4028,  4037,  4043,  4051,  4057,  4069,  4075,  4085,
    4089,  4093,  4097,  4101,  4107,  4113,  4121,  4125,  4133,  4137,
    4148,  4152,  4156,  4162,  4166,  4180,  4184,  4192,  4196,  4206,
    4210,  4214,  4223,  4227,  4231,  4235,  4243,  4249,  4259,  4267,
    4271,  4275,  4279,  4283,  4287,  4291,  4295,  4299,  4309,  4317,
    4321,  4329,  4336,  4343,  4354,  4362,  4366,  4374,  4382,  4390,
    4444,  4448,  4461,  4467,  4477,  4481,  4489,  4493,  4497,  4505,
    4515,  4525,  4535,  4545,  4555,  4570,  4576,  4587,  4593,  4604,
    4615,  4617,  4621,  4626,  4636,  4639,  4646,  4652,  4658,  4666,
    4679,  4682,  4689,  4695,  4701,  4708,  4719,  4723,  4733,  4737,
    4747,  4751,  4755,  4760,  4769,  4775,  4781,  4787,  4795,  4800,
    4808,  4813,  4821,  4829,  4834,  4839,  4844,  4849,  4854,  4863,
    4871,  4875,  4892,  4896,  4904,  4912,  4920,  4924,  4932,  4938,
    4948,  4956,  4960,  4964,  4999,  5005,  5011,  5021,  5025,  5029,
    5033,  5037,  5044,  5050,  5060,  5068,  5072,  5076,  5080,  5084,
    5088,  5092,  5096,  5100,  5108,  5116,  5120,  5124,  5134,  5142,
    5150,  5154,  5158,  5166,  5170,  5176,  5182,  5186,  5196,  5204,
    5208,  5214,  5223,  5232,  5238,  5244,  5254,  5271,  5278,  5293,
    5329,  5333,  5341,  5349,  5361,  5365,  5373,  5381,  5385,  5396,
    5413,  5419,  5425,  5435,  5439,  5445,  5451,  5455,  5461,  5465,
    5471,  5477,  5484,  5494,  5499,  5507,  5513,  5523,  5545,  5554,
    5560,  5573,  5587,  5594,  5600,  5610,  5615,  5620,  5630,  5644,
    5652,  5658,  5676,  5685,  5688,  5695,  5700,  5708,  5712,  5719,
    5723,  5730,  5734,  5741,  5745,  5754,  5767,  5770,  5778,  5781,
    5789,  5797,  5805,  5809,  5817,  5820,  5828,  5840,  5843,  5851,
    5863,  5869,  5879,  5882,  5890,  5894,  5898,  5906,  5909,  5917,
    5920,  5928,  5932,  5936,  5940,  5944,  5952,  5960,  5972,  5984,
    5988,  5992,  6000,  6006,  6016,  6020,  6024,  6028,  6032,  6036,
    6040,  6044,  6052,  6056,  6060,  6064,  6072,  6078,  6088,  6098,
    6102,  6110,  6120,  6131,  6138,  6142,  6150,  6153,  6160,  6165,
    6174,  6184,  6187,  6195,  6198,  6206,  6215,  6222,  6232,  6236,
    6243,  6249,  6259,  6262,  6269,  6274,  6286,  6294,  6306,  6314,
    6318,  6326,  6330,  6334,  6342,  6350,  6354,  6358,  6362,  6370,
    6378,  6390,  6394,  6402,  6415,  6419,  6420,  6433,  6434,  6435,
    6436,  6437,  6438,  6439,  6440,  6441,  6442,  6443,  6444,  6445,
    6446,  6447,  6448,  6452,  6453,  6454,  6455,  6456,  6457,  6458,
    6459,  6460,  6461,  6462,  6463,  6464,  6465,  6466,  6467,  6468,
    6469,  6470,  6471,  6472,  6473,  6474,  6475,  6476,  6477,  6478,
    6479,  6480,  6481,  6482,  6483,  6484,  6485,  6486,  6487,  6488,
    6489,  6490,  6491,  6492,  6493,  6494,  6495,  6496,  6497,  6498,
    6499,  6500,  6501,  6502,  6503,  6504,  6505,  6506,  6507,  6508,
    6509,  6510,  6511,  6512,  6513,  6514,  6515,  6516,  6517,  6518,
    6519,  6520,  6521,  6522,  6523,  6524,  6525,  6526,  6527,  6528,
    6529,  6530,  6531,  6532,  6533,  6534,  6535,  6536,  6537,  6538,
    6539,  6540,  6541,  6542,  6543,  6544,  6545,  6546,  6547,  6548,
    6549,  6550,  6551,  6552,  6553,  6554,  6555,  6556,  6557,  6558,
    6559,  6560,  6561,  6562,  6563,  6564,  6565,  6566,  6567,  6568,
    6569,  6570,  6571,  6572,  6573,  6574,  6575,  6576,  6577,  6578,
    6579,  6580,  6581,  6582,  6583,  6584,  6585,  6586,  6587,  6588,
    6589,  6590,  6591,  6592,  6593,  6594,  6595,  6596,  6597,  6598,
    6599,  6600,  6601,  6602,  6603,  6604,  6605,  6606,  6607,  6608,
    6609,  6610,  6611,  6612,  6613,  6614,  6615,  6616,  6617,  6618,
    6619,  6620,  6621,  6622,  6623,  6624,  6625,  6626,  6627,  6628,
    6629,  6630,  6631,  6632,  6633,  6634,  6635,  6636,  6637,  6638,
    6639,  6640,  6641,  6642,  6643,  6644,  6645,  6646,  6647,  6648,
    6649,  6650,  6655,  6662
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
  const int xquery_parser::yylast_ = 13211;
  const int xquery_parser::yynnts_ = 309;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 579;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 321;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 575;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // zorba

/* Line 1054 of lalr1.cc  */
#line 16391 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"


/* Line 1056 of lalr1.cc  */
#line 6666 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"


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

