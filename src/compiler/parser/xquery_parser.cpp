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
#line 87 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"


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
#line 78 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"


#include "xquery_parser.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 876 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 317 of lalr1.cc  */
#line 976 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"

#include "compiler/parser/xquery_scanner.h"

#undef yylex
#define yylex driver.lexer->lex



/* Line 317 of lalr1.cc  */
#line 108 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"

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
#line 174 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
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

/* Line 480 of lalr1.cc  */
#line 874 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 281 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 123: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 290 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 148: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 872 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 299 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 326: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 308 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 317 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 326 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 335 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 344 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 353 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 362 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 371 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 380 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 389 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 398 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 407 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 416 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 425 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 434 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 443 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 452 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 461 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 470 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 479 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 488 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 497 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 506 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 515 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 897 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 524 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 897 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 533 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 542 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 551 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 560 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 569 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 578 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 587 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 596 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 897 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 605 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "AnnotationList" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 614 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "Annotation" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 623 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "AnnotationLiteralList" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 632 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 641 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 650 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "FunctionDeclSimple" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 659 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 668 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 897 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 677 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 686 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 695 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 704 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 713 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 722 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 731 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 740 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 749 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "StatementsAndOptionalExprTop" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 758 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "StatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 767 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "StatementsAndExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 776 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "Statements" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 785 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "Statement" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 794 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "BlockStatement" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 803 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 812 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "EnclosedStatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 821 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "VarDeclStatement" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 830 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "AssignStatement" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 839 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "ApplyStatement" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 848 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "ExitStatement" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 857 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "WhileStatement" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 866 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 875 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "FLWORStatement" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 884 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "ReturnStatement" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 893 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "IfStatement" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 902 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "TryStatement" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 911 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "CatchListStatement" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 920 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "CatchStatement" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 929 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 938 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 947 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "ExprSimple" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 956 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 965 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 974 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 983 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 992 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1001 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1010 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1019 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1028 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1037 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1046 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1055 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1064 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1073 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1082 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1091 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1100 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1109 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1118 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1127 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1136 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1145 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1154 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1163 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1172 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1181 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1190 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1199 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1208 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1217 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1226 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1235 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1244 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1253 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1262 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "SwitchExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1271 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "SwitchCaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1280 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "SwitchCaseClause" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1289 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "SwitchCaseOperandList" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1298 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "SwitchStatement" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1307 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1316 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "TypeswitchStatement" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1325 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1334 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1343 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1352 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1361 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1370 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1379 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1388 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1397 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1406 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1415 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1424 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1433 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1442 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1451 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1460 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1469 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1478 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1487 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1496 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1505 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1514 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1523 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1532 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1541 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1550 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1559 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1568 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1577 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1586 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1595 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1604 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1613 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1622 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1631 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1640 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1649 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1658 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1667 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1676 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1685 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1694 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1703 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1712 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1721 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1730 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1739 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1748 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1757 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1766 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1775 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1784 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1793 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1802 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1811 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1820 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1829 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1838 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1847 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1856 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1865 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1874 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1883 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1892 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1901 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1910 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1919 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1928 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1937 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1946 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1955 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1964 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1973 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1982 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1991 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2000 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2009 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2018 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2027 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2036 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 533: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2045 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 534: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2054 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 535: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2063 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 536: /* "AtomicType" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2072 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 537: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2081 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2090 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 539: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2099 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 540: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2108 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 541: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2117 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2126 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 543: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2135 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 544: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2144 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 545: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2153 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 546: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2162 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 547: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2171 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 548: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2180 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 549: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2189 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 554: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2198 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 555: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2207 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 558: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2216 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 559: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2225 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 560: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2234 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 561: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2243 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 562: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2252 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 563: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2261 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 564: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2270 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 565: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2279 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 566: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2288 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 567: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2297 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 568: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2306 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 569: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 897 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2315 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 570: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2324 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 573: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2333 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 574: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2342 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 575: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2351 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 576: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2360 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 577: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2369 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 578: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2378 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 580: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2387 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 581: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2396 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 582: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2405 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 583: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2414 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 585: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2423 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 586: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2432 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 588: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2441 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 591: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2450 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 592: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2459 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 593: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2468 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 594: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2477 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 595: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2486 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 596: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2495 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 597: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2504 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 598: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2513 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 599: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2522 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 600: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2531 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 601: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2540 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 602: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2549 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 606: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2558 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 609: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2567 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 610: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2576 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 614: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2585 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 615: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2594 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 616: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2603 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 617: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2612 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 618: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2621 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 619: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2630 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 620: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2639 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 621: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2648 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 622: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2657 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 625: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2666 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 626: /* "FUNCTION_NAME" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2675 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 627: /* "EQNAME" */

/* Line 480 of lalr1.cc  */
#line 894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2684 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
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
#line 140 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename2);
}

/* Line 553 of lalr1.cc  */
#line 2769 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"

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
#line 994 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 1003 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 1012 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 1018 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      MainModule* mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
      mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 1026 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 1032 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      LibraryModule* lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
      lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 1043 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8" );
    }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 1048 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
    }
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 1056 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 1063 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 1070 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
    }
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 1079 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
    }
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 1086 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 1094 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 1102 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (3)]).step();
      error((yylocation_stack_[(5) - (3)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 1110 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (1)]).step();
      error((yylocation_stack_[(5) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 1121 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
    }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 1126 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 1133 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 1140 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
    }
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 1152 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );

      dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
    }
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 1162 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
      sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = sdl;
    }
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 1169 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 1176 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 1211 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::preserve_space);
    }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 1216 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::strip_space);
    }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 1224 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
    }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 1232 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 1240 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_preserve);
    }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 1245 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_strip);
    }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 1253 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 1258 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 1266 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_greatest);
    }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 1271 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_least);
    }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 1279 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::preserve_ns,
                                  StaticContextConsts::inherit_ns);
    }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 1286 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::preserve_ns,
                                  StaticContextConsts::no_inherit_ns);
    }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 1293 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::no_preserve_ns,
                                  StaticContextConsts::inherit_ns);
    }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 1300 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::no_preserve_ns,
                                  StaticContextConsts::no_inherit_ns);
    }
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 1315 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yyval.node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (2)]), "syntax error, \"import\" should be followed by either \"schema\" or \"module\".");
      YYERROR;
    }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 1325 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
    }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 1330 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                            NULL);
    }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 1338 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            NULL,
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 1346 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 1357 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      URILiteralList *ull = new URILiteralList( LOC((yyloc)));
      ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
      (yyval.node) = ull;
    }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 1364 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
        ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 1375 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 1380 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
    }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 1388 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 1395 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 1402 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 1411 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 1424 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
    }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 1432 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_element_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 1439 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_function_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 1449 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
      vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = vdl;
    }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 1456 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 1463 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 1486 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 1492 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 1501 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.vstrpair) = new vector<string_pair_t>();
      (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
      delete (yysemantic_stack_[(1) - (1)].strpair);
    }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 1508 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
      delete (yysemantic_stack_[(2) - (2)].strpair);
      (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
    }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 1518 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
      delete sl;
    }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 1527 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 1528 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 1529 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 1530 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 1531 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 1532 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 1533 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 1534 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 1535 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 1536 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 1542 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OptionDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)));
    }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 1550 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
    }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 1558 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 1566 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
      d->theType = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 1573 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 1581 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
      d->theIsExternal = false;
      (yyval.node) = d;
    }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 1588 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), NULL);
    }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 1593 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 1601 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 1609 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 1624 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 1639 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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
#line 1657 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL, NULL);
    }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 1662 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 1670 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                              NULL,
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (1)].node)));
    }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 1678 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)),
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (1)].node)));
    }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 1689 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationListParsenode(LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
    }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 1694 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 1703 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
    }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 1708 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 1715 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true), NULL);
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 1720 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval)), true),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 1730 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationLiteralListParsenode(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 1735 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 1744 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 1750 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl* fdecl = static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));

      fdecl->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );

      fdecl->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 1763 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 1768 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 1776 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 1787 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 1802 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 1814 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 1829 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL);
    }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 1834 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 1839 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 1844 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 1852 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      ParamList *pl = new ParamList( LOC((yyloc)) );
      pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = pl;
    }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 1859 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
        pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 1870 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 1875 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 1885 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)),
                              NULL,
                              NULL);
    }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 1892 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                              0,
                              static_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 1899 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (2)].node)),
                               0);
    }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 1906 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(6) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(6) - (2)].node)),
                               static_cast<SequenceType*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1916 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 1920 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 1930 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AST_IndexDecl(LOC((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(8) - (3)].expr)),
                             (yysemantic_stack_[(8) - (6)].expr),
                             dynamic_cast<IndexKeyList*>((yysemantic_stack_[(8) - (8)].node)),
                             NULL);
    }
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 1938 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AST_IndexDecl(LOC((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(9) - (4)].expr)),
                             (yysemantic_stack_[(9) - (7)].expr),
                             dynamic_cast<IndexKeyList*>((yysemantic_stack_[(9) - (9)].node)),
                             static_cast<AnnotationListParsenode*>((yysemantic_stack_[(9) - (2)].node)));
    }
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 1949 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 1955 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 1964 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 1969 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 1976 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 1983 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 1995 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollSimpleCheck(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (9)].expr)),
                                 (yysemantic_stack_[(11) - (11)].expr));
    }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 2005 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollUniqueKeyCheck(LOC((yyloc)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (4)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (7)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (10)].expr)),
                                    (yysemantic_stack_[(14) - (14)].expr));
    }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 2015 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollForeachNode(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (11)].expr)),
                                 (yysemantic_stack_[(13) - (13)].expr));
    }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 2026 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 156:

/* Line 678 of lalr1.cc  */
#line 2042 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 157:

/* Line 678 of lalr1.cc  */
#line 2062 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 2067 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 159:

/* Line 678 of lalr1.cc  */
#line 2071 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  NULL;
    }
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 2079 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 2084 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 2088 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  new BlockBody(LOC((yyloc)));
    }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 2096 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 2101 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 2113 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = new BlockBody(LOC((yyloc)));
      blk->add((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 2120 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 2149 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 2154 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 2162 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 182:

/* Line 678 of lalr1.cc  */
#line 2179 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 2187 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 2195 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = static_cast<VarDeclStmt*>((yysemantic_stack_[(3) - (1)].expr));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 2202 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(2) - (2)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 2209 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (1)].node)));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 2219 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 188:

/* Line 678 of lalr1.cc  */
#line 2231 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 189:

/* Line 678 of lalr1.cc  */
#line 2244 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 190:

/* Line 678 of lalr1.cc  */
#line 2256 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 191:

/* Line 678 of lalr1.cc  */
#line 2272 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 192:

/* Line 678 of lalr1.cc  */
#line 2280 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ApplyExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr));
    }
    break;

  case 193:

/* Line 678 of lalr1.cc  */
#line 2288 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 2296 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 195:

/* Line 678 of lalr1.cc  */
#line 2311 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement(LOC((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 2316 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
    }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 2324 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 198:

/* Line 678 of lalr1.cc  */
#line 2338 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 199:

/* Line 678 of lalr1.cc  */
#line 2355 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 200:

/* Line 678 of lalr1.cc  */
#line 2380 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TryExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 2388 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* cle = new CatchListExpr( LOC((yyloc)) );
      cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.expr) = cle;
    }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 2395 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 2406 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 2416 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 2421 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 219:

/* Line 678 of lalr1.cc  */
#line 2459 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 220:

/* Line 678 of lalr1.cc  */
#line 2473 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
    }
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 2481 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 222:

/* Line 678 of lalr1.cc  */
#line 2486 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 2494 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 2499 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 2504 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
    (yyval.strval) = parser::the_only_end;
  }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 2512 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            dynamic_cast<WindowVars*>((yysemantic_stack_[(4) - (2)].node)),
                            (yysemantic_stack_[(4) - (4)].expr),
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 2521 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            NULL,
                            (yysemantic_stack_[(3) - (3)].expr),
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 2533 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 229:

/* Line 678 of lalr1.cc  */
#line 2543 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling ?
                              WindowClause::tumbling_window :
                              WindowClause::sliding_window),
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 2556 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 239:

/* Line 678 of lalr1.cc  */
#line 2580 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 240:

/* Line 678 of lalr1.cc  */
#line 2587 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 2597 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 2605 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      VarInDeclList *vdl = new VarInDeclList( LOC((yyloc)) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = vdl;
    }
    break;

  case 243:

/* Line 678 of lalr1.cc  */
#line 2612 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      if ( VarInDeclList *vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 2622 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 245:

/* Line 678 of lalr1.cc  */
#line 2632 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 246:

/* Line 678 of lalr1.cc  */
#line 2642 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 247:

/* Line 678 of lalr1.cc  */
#line 2652 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 248:

/* Line 678 of lalr1.cc  */
#line 2662 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 249:

/* Line 678 of lalr1.cc  */
#line 2672 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 250:

/* Line 678 of lalr1.cc  */
#line 2682 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 251:

/* Line 678 of lalr1.cc  */
#line 2692 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 252:

/* Line 678 of lalr1.cc  */
#line 2703 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         NULL,NULL,
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
                         (yysemantic_stack_[(4) - (4)].expr),
                         false);
    }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 2712 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 254:

/* Line 678 of lalr1.cc  */
#line 2722 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 255:

/* Line 678 of lalr1.cc  */
#line 2732 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 256:

/* Line 678 of lalr1.cc  */
#line 2748 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 2757 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 2766 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 2774 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 2780 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 2792 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                           NULL,
                           NULL,
                           (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 2800 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                           NULL,
                           (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 2810 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node))->get_var_name(),
                           NULL,
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node)),
                           (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 2818 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (3)].node)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
                           (yysemantic_stack_[(6) - (6)].expr));
    }
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 2830 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 2836 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 2849 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 2853 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 2861 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 2865 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 2874 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 2878 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 2882 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 2892 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 2900 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 2907 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = new GroupSpecList( LOC((yyloc)) );
            gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 2913 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
            if ( gsl )
                gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 2924 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 2928 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                         dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 2937 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 2945 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 2951 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 2961 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 2967 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 2977 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 2981 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 2991 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 2997 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 3003 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 3009 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
                NULL
            );
        }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 3018 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                NULL,
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 3027 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                NULL,
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 3036 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 3049 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 3053 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 3061 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 3067 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 3077 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 3085 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_some,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 3094 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_every,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 3107 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 3114 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 3126 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 3130 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 3142 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 3149 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 3155 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 3164 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 3171 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 3177 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 3188 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 3195 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 3201 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 3210 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 3219 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 3226 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 3237 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 3244 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 3256 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 3262 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 3274 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 3280 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 3291 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 3297 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 3308 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 3314 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 3325 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 3334 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 3338 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 3347 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 3351 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 3359 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 3363 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 336:

/* Line 678 of lalr1.cc  */
#line 3373 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 3380 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_eq ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 3389 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ne ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 3398 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 3403 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_lt ),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr)
            );
        }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 3412 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_le ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 3421 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_gt ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 3430 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ge ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 3443 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 3447 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FTContainsExpr(
                LOC((yyloc)),
                (yysemantic_stack_[(5) - (1)].expr),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(5) - (4)].node)),
                dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 3459 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 3463 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 3470 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 3474 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 3483 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 3487 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 3491 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 3500 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 3504 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 3510 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 3516 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 3522 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 3533 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 3537 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 3541 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 3549 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 3553 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 3559 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 3569 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 3573 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 3583 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 3587 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 3597 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 3601 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 3611 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 3615 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 3625 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 3629 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 3637 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 3641 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 3645 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 3649 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 3659 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 3663 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 3667 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 3675 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 3679 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 3683 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 3687 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 3691 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 3695 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 3703 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 3707 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 3711 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 3719 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 3723 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 3727 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 3731 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 3742 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 3748 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 3758 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 3764 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 3774 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 3778 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 3782 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 3820 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new PathExpr(LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
    }
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 3824 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, NULL, (yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slash,
                        rpe);
    }
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 3834 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, NULL, (yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slashslash,
                        rpe);
    }
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 3844 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = (!rpe ?
            (yysemantic_stack_[(1) - (1)].expr) :
            new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 3857 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 3866 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 407:

/* Line 678 of lalr1.cc  */
#line 3876 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 3880 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 3889 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 3893 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 3902 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 3908 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 3916 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 3922 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 3934 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 3940 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 3950 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 3954 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 3958 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 3962 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 3966 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 3972 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 3978 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 3986 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 3990 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 3998 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 4002 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 4013 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 4017 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 4021 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 4027 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 4031 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 4045 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 4049 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 4057 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 4061 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 4071 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all, false);
    }
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 4075 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, false);
    }
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 4079 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, true);
    }
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 4083 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix, false);
    }
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 4092 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 4096 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 4100 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
     }
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 4104 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
     }
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 4112 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 4118 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 4128 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 4136 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 4140 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 4144 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 4148 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 4152 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 4156 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 4160 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 4164 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 4168 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 4178 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 4186 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 4190 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 4198 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 4205 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 4212 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 4223 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 4231 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 4235 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 4243 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 4251 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 4259 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 4313 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
        }
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 4317 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 471:

/* Line 678 of lalr1.cc  */
#line 4330 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            ArgList *al = new ArgList( LOC((yyloc)) );
            al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
            (yyval.node) = al;
        }
    break;

  case 472:

/* Line 678 of lalr1.cc  */
#line 4336 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
                al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 473:

/* Line 678 of lalr1.cc  */
#line 4346 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 474:

/* Line 678 of lalr1.cc  */
#line 4350 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 4358 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 4362 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 4366 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 4374 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 479:

/* Line 678 of lalr1.cc  */
#line 4384 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 480:

/* Line 678 of lalr1.cc  */
#line 4394 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 481:

/* Line 678 of lalr1.cc  */
#line 4404 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 482:

/* Line 678 of lalr1.cc  */
#line 4414 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 483:

/* Line 678 of lalr1.cc  */
#line 4424 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 484:

/* Line 678 of lalr1.cc  */
#line 4439 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
            decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = decl;
        }
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 4445 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( decl )
                decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 4456 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
            dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = dal;
        }
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 4462 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
            if ( dal )
                dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 4473 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttr(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node))
            );
        }
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 4490 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 4495 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 4504 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
        }
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 4508 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 4515 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = qacl;
        }
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 4521 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = qacl;
        }
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 4527 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 4535 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 4547 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
        }
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 4551 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 4558 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = aacl;
        }
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 4564 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = aacl;
        }
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 4570 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if (aacl)
                aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 4577 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( aacl )
                aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 4588 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 4592 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 4602 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 4606 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 509:

/* Line 678 of lalr1.cc  */
#line 4616 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 510:

/* Line 678 of lalr1.cc  */
#line 4620 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 511:

/* Line 678 of lalr1.cc  */
#line 4624 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
        }
    break;

  case 512:

/* Line 678 of lalr1.cc  */
#line 4629 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
        }
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 4638 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval))
            );
        }
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 4644 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_lbrace
            );
        }
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 4650 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_rbrace
            );
        }
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 4656 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
        }
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 4664 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 4669 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 4677 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 4682 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 521:

/* Line 678 of lalr1.cc  */
#line 4690 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 522:

/* Line 678 of lalr1.cc  */
#line 4698 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 4703 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 4708 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 4713 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 526:

/* Line 678 of lalr1.cc  */
#line 4718 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 4723 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 4732 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 4740 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
        }
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 4744 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 4761 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 4765 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 4773 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 534:

/* Line 678 of lalr1.cc  */
#line 4781 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 4789 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 4793 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 4801 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)), false
            );
        }
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 4807 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)), true
            );
        }
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 4817 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 4825 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 4829 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 542:

/* Line 678 of lalr1.cc  */
#line 4833 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 543:

/* Line 678 of lalr1.cc  */
#line 4868 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 544:

/* Line 678 of lalr1.cc  */
#line 4874 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 4880 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 4890 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 4894 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 4898 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)),true );
        }
    break;

  case 549:

/* Line 678 of lalr1.cc  */
#line 4902 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 550:

/* Line 678 of lalr1.cc  */
#line 4906 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 4913 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 4919 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 4929 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 4937 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 555:

/* Line 678 of lalr1.cc  */
#line 4941 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 556:

/* Line 678 of lalr1.cc  */
#line 4945 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 557:

/* Line 678 of lalr1.cc  */
#line 4949 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 558:

/* Line 678 of lalr1.cc  */
#line 4953 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 559:

/* Line 678 of lalr1.cc  */
#line 4957 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 560:

/* Line 678 of lalr1.cc  */
#line 4961 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 561:

/* Line 678 of lalr1.cc  */
#line 4965 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 562:

/* Line 678 of lalr1.cc  */
#line 4969 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 563:

/* Line 678 of lalr1.cc  */
#line 4977 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyKindTest( LOC((yyloc)) );
        }
    break;

  case 564:

/* Line 678 of lalr1.cc  */
#line 4985 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)) );
        }
    break;

  case 565:

/* Line 678 of lalr1.cc  */
#line 4989 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)) );
        }
    break;

  case 566:

/* Line 678 of lalr1.cc  */
#line 4993 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest(
                LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 567:

/* Line 678 of lalr1.cc  */
#line 5003 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TextTest( LOC((yyloc)) );
        }
    break;

  case 568:

/* Line 678 of lalr1.cc  */
#line 5011 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CommentTest( LOC((yyloc)));
        }
    break;

  case 569:

/* Line 678 of lalr1.cc  */
#line 5019 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 570:

/* Line 678 of lalr1.cc  */
#line 5023 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 571:

/* Line 678 of lalr1.cc  */
#line 5027 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 572:

/* Line 678 of lalr1.cc  */
#line 5035 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 573:

/* Line 678 of lalr1.cc  */
#line 5039 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 574:

/* Line 678 of lalr1.cc  */
#line 5045 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 575:

/* Line 678 of lalr1.cc  */
#line 5051 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 576:

/* Line 678 of lalr1.cc  */
#line 5055 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 577:

/* Line 678 of lalr1.cc  */
#line 5065 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 578:

/* Line 678 of lalr1.cc  */
#line 5073 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 579:

/* Line 678 of lalr1.cc  */
#line 5077 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 580:

/* Line 678 of lalr1.cc  */
#line 5083 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 5092 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

/* Line 678 of lalr1.cc  */
#line 5101 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 583:

/* Line 678 of lalr1.cc  */
#line 5107 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 584:

/* Line 678 of lalr1.cc  */
#line 5113 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 585:

/* Line 678 of lalr1.cc  */
#line 5123 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 586:

/* Line 678 of lalr1.cc  */
#line 5140 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 587:

/* Line 678 of lalr1.cc  */
#line 5147 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 588:

/* Line 678 of lalr1.cc  */
#line 5162 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 589:

/* Line 678 of lalr1.cc  */
#line 5198 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 590:

/* Line 678 of lalr1.cc  */
#line 5202 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 591:

/* Line 678 of lalr1.cc  */
#line 5210 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 592:

/* Line 678 of lalr1.cc  */
#line 5218 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new InlineFunction(LOC((yyloc)),
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theParams,
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theReturnType,
                              (yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (2)].fnsig);
    }
    break;

  case 593:

/* Line 678 of lalr1.cc  */
#line 5230 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 594:

/* Line 678 of lalr1.cc  */
#line 5234 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 595:

/* Line 678 of lalr1.cc  */
#line 5242 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 596:

/* Line 678 of lalr1.cc  */
#line 5250 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 597:

/* Line 678 of lalr1.cc  */
#line 5254 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 598:

/* Line 678 of lalr1.cc  */
#line 5265 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 599:

/* Line 678 of lalr1.cc  */
#line 5282 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 600:

/* Line 678 of lalr1.cc  */
#line 5288 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 601:

/* Line 678 of lalr1.cc  */
#line 5294 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 602:

/* Line 678 of lalr1.cc  */
#line 5304 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 603:

/* Line 678 of lalr1.cc  */
#line 5308 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 604:

/* Line 678 of lalr1.cc  */
#line 5314 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 605:

/* Line 678 of lalr1.cc  */
#line 5320 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 606:

/* Line 678 of lalr1.cc  */
#line 5324 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 607:

/* Line 678 of lalr1.cc  */
#line 5330 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 608:

/* Line 678 of lalr1.cc  */
#line 5334 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 609:

/* Line 678 of lalr1.cc  */
#line 5340 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 610:

/* Line 678 of lalr1.cc  */
#line 5346 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 611:

/* Line 678 of lalr1.cc  */
#line 5353 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 612:

/* Line 678 of lalr1.cc  */
#line 5363 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 613:

/* Line 678 of lalr1.cc  */
#line 5368 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 614:

/* Line 678 of lalr1.cc  */
#line 5376 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 615:

/* Line 678 of lalr1.cc  */
#line 5382 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 616:

/* Line 678 of lalr1.cc  */
#line 5392 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 617:

/* Line 678 of lalr1.cc  */
#line 5414 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 618:

/* Line 678 of lalr1.cc  */
#line 5423 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 619:

/* Line 678 of lalr1.cc  */
#line 5429 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 620:

/* Line 678 of lalr1.cc  */
#line 5442 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 621:

/* Line 678 of lalr1.cc  */
#line 5456 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 622:

/* Line 678 of lalr1.cc  */
#line 5463 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 623:

/* Line 678 of lalr1.cc  */
#line 5469 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 624:

/* Line 678 of lalr1.cc  */
#line 5479 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 625:

/* Line 678 of lalr1.cc  */
#line 5488 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 626:

/* Line 678 of lalr1.cc  */
#line 5496 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 627:

/* Line 678 of lalr1.cc  */
#line 5502 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 628:

/* Line 678 of lalr1.cc  */
#line 5520 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 629:

/* Line 678 of lalr1.cc  */
#line 5528 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 630:

/* Line 678 of lalr1.cc  */
#line 5532 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 631:

/* Line 678 of lalr1.cc  */
#line 5539 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 632:

/* Line 678 of lalr1.cc  */
#line 5544 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 633:

/* Line 678 of lalr1.cc  */
#line 5552 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 634:

/* Line 678 of lalr1.cc  */
#line 5556 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 635:

/* Line 678 of lalr1.cc  */
#line 5563 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 636:

/* Line 678 of lalr1.cc  */
#line 5567 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 637:

/* Line 678 of lalr1.cc  */
#line 5574 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 638:

/* Line 678 of lalr1.cc  */
#line 5578 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 639:

/* Line 678 of lalr1.cc  */
#line 5585 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 640:

/* Line 678 of lalr1.cc  */
#line 5589 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 641:

/* Line 678 of lalr1.cc  */
#line 5598 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 642:

/* Line 678 of lalr1.cc  */
#line 5610 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 643:

/* Line 678 of lalr1.cc  */
#line 5614 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 644:

/* Line 678 of lalr1.cc  */
#line 5621 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 645:

/* Line 678 of lalr1.cc  */
#line 5625 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 646:

/* Line 678 of lalr1.cc  */
#line 5633 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 647:

/* Line 678 of lalr1.cc  */
#line 5641 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 648:

/* Line 678 of lalr1.cc  */
#line 5649 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 649:

/* Line 678 of lalr1.cc  */
#line 5653 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 650:

/* Line 678 of lalr1.cc  */
#line 5660 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 651:

/* Line 678 of lalr1.cc  */
#line 5664 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 652:

/* Line 678 of lalr1.cc  */
#line 5672 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 653:

/* Line 678 of lalr1.cc  */
#line 5683 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 654:

/* Line 678 of lalr1.cc  */
#line 5687 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 655:

/* Line 678 of lalr1.cc  */
#line 5695 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 656:

/* Line 678 of lalr1.cc  */
#line 5707 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 657:

/* Line 678 of lalr1.cc  */
#line 5713 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 658:

/* Line 678 of lalr1.cc  */
#line 5722 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 659:

/* Line 678 of lalr1.cc  */
#line 5726 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 660:

/* Line 678 of lalr1.cc  */
#line 5734 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 661:

/* Line 678 of lalr1.cc  */
#line 5738 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 662:

/* Line 678 of lalr1.cc  */
#line 5742 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 663:

/* Line 678 of lalr1.cc  */
#line 5749 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 664:

/* Line 678 of lalr1.cc  */
#line 5753 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 665:

/* Line 678 of lalr1.cc  */
#line 5760 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 666:

/* Line 678 of lalr1.cc  */
#line 5764 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 667:

/* Line 678 of lalr1.cc  */
#line 5772 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 668:

/* Line 678 of lalr1.cc  */
#line 5776 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 669:

/* Line 678 of lalr1.cc  */
#line 5780 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 670:

/* Line 678 of lalr1.cc  */
#line 5784 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 671:

/* Line 678 of lalr1.cc  */
#line 5788 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 672:

/* Line 678 of lalr1.cc  */
#line 5796 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 673:

/* Line 678 of lalr1.cc  */
#line 5804 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 674:

/* Line 678 of lalr1.cc  */
#line 5816 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 675:

/* Line 678 of lalr1.cc  */
#line 5828 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 676:

/* Line 678 of lalr1.cc  */
#line 5832 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 677:

/* Line 678 of lalr1.cc  */
#line 5836 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 678:

/* Line 678 of lalr1.cc  */
#line 5844 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 679:

/* Line 678 of lalr1.cc  */
#line 5850 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 680:

/* Line 678 of lalr1.cc  */
#line 5860 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 681:

/* Line 678 of lalr1.cc  */
#line 5864 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 682:

/* Line 678 of lalr1.cc  */
#line 5868 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 683:

/* Line 678 of lalr1.cc  */
#line 5872 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 684:

/* Line 678 of lalr1.cc  */
#line 5876 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 685:

/* Line 678 of lalr1.cc  */
#line 5880 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 686:

/* Line 678 of lalr1.cc  */
#line 5884 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 687:

/* Line 678 of lalr1.cc  */
#line 5888 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 688:

/* Line 678 of lalr1.cc  */
#line 5896 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 689:

/* Line 678 of lalr1.cc  */
#line 5900 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 690:

/* Line 678 of lalr1.cc  */
#line 5904 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 691:

/* Line 678 of lalr1.cc  */
#line 5908 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 692:

/* Line 678 of lalr1.cc  */
#line 5916 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 693:

/* Line 678 of lalr1.cc  */
#line 5922 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 694:

/* Line 678 of lalr1.cc  */
#line 5932 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 695:

/* Line 678 of lalr1.cc  */
#line 5942 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::with );
        }
    break;

  case 696:

/* Line 678 of lalr1.cc  */
#line 5946 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::without );
        }
    break;

  case 697:

/* Line 678 of lalr1.cc  */
#line 5954 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 698:

/* Line 678 of lalr1.cc  */
#line 5964 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 699:

/* Line 678 of lalr1.cc  */
#line 5975 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 700:

/* Line 678 of lalr1.cc  */
#line 5982 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 701:

/* Line 678 of lalr1.cc  */
#line 5986 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 702:

/* Line 678 of lalr1.cc  */
#line 5993 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 703:

/* Line 678 of lalr1.cc  */
#line 5997 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 704:

/* Line 678 of lalr1.cc  */
#line 6004 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 705:

/* Line 678 of lalr1.cc  */
#line 6009 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 706:

/* Line 678 of lalr1.cc  */
#line 6018 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 707:

/* Line 678 of lalr1.cc  */
#line 6027 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = NULL;
        }
    break;

  case 708:

/* Line 678 of lalr1.cc  */
#line 6031 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 709:

/* Line 678 of lalr1.cc  */
#line 6038 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 710:

/* Line 678 of lalr1.cc  */
#line 6042 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 711:

/* Line 678 of lalr1.cc  */
#line 6050 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 712:

/* Line 678 of lalr1.cc  */
#line 6059 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 713:

/* Line 678 of lalr1.cc  */
#line 6066 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 714:

/* Line 678 of lalr1.cc  */
#line 6076 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 715:

/* Line 678 of lalr1.cc  */
#line 6080 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 716:

/* Line 678 of lalr1.cc  */
#line 6087 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 717:

/* Line 678 of lalr1.cc  */
#line 6093 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 718:

/* Line 678 of lalr1.cc  */
#line 6102 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 719:

/* Line 678 of lalr1.cc  */
#line 6106 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 720:

/* Line 678 of lalr1.cc  */
#line 6113 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 721:

/* Line 678 of lalr1.cc  */
#line 6118 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 722:

/* Line 678 of lalr1.cc  */
#line 6130 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 723:

/* Line 678 of lalr1.cc  */
#line 6138 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 724:

/* Line 678 of lalr1.cc  */
#line 6150 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 725:

/* Line 678 of lalr1.cc  */
#line 6158 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 726:

/* Line 678 of lalr1.cc  */
#line 6162 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 727:

/* Line 678 of lalr1.cc  */
#line 6170 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 728:

/* Line 678 of lalr1.cc  */
#line 6174 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 729:

/* Line 678 of lalr1.cc  */
#line 6178 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 730:

/* Line 678 of lalr1.cc  */
#line 6186 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 731:

/* Line 678 of lalr1.cc  */
#line 6194 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 732:

/* Line 678 of lalr1.cc  */
#line 6198 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 733:

/* Line 678 of lalr1.cc  */
#line 6202 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 734:

/* Line 678 of lalr1.cc  */
#line 6206 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 735:

/* Line 678 of lalr1.cc  */
#line 6214 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 736:

/* Line 678 of lalr1.cc  */
#line 6222 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 737:

/* Line 678 of lalr1.cc  */
#line 6234 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 738:

/* Line 678 of lalr1.cc  */
#line 6238 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 739:

/* Line 678 of lalr1.cc  */
#line 6246 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 742:

/* Line 678 of lalr1.cc  */
#line 6264 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
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

  case 744:

/* Line 678 of lalr1.cc  */
#line 6277 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 745:

/* Line 678 of lalr1.cc  */
#line 6278 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 746:

/* Line 678 of lalr1.cc  */
#line 6279 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 747:

/* Line 678 of lalr1.cc  */
#line 6280 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 748:

/* Line 678 of lalr1.cc  */
#line 6281 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 749:

/* Line 678 of lalr1.cc  */
#line 6282 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 750:

/* Line 678 of lalr1.cc  */
#line 6283 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 751:

/* Line 678 of lalr1.cc  */
#line 6284 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 752:

/* Line 678 of lalr1.cc  */
#line 6285 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 753:

/* Line 678 of lalr1.cc  */
#line 6286 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 754:

/* Line 678 of lalr1.cc  */
#line 6287 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 755:

/* Line 678 of lalr1.cc  */
#line 6288 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 756:

/* Line 678 of lalr1.cc  */
#line 6289 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 757:

/* Line 678 of lalr1.cc  */
#line 6290 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 758:

/* Line 678 of lalr1.cc  */
#line 6291 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 760:

/* Line 678 of lalr1.cc  */
#line 6296 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 761:

/* Line 678 of lalr1.cc  */
#line 6297 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 762:

/* Line 678 of lalr1.cc  */
#line 6298 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 763:

/* Line 678 of lalr1.cc  */
#line 6299 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 764:

/* Line 678 of lalr1.cc  */
#line 6300 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 765:

/* Line 678 of lalr1.cc  */
#line 6301 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 766:

/* Line 678 of lalr1.cc  */
#line 6302 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 767:

/* Line 678 of lalr1.cc  */
#line 6303 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 768:

/* Line 678 of lalr1.cc  */
#line 6304 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 769:

/* Line 678 of lalr1.cc  */
#line 6305 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 770:

/* Line 678 of lalr1.cc  */
#line 6306 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 771:

/* Line 678 of lalr1.cc  */
#line 6307 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 772:

/* Line 678 of lalr1.cc  */
#line 6308 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 773:

/* Line 678 of lalr1.cc  */
#line 6309 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 774:

/* Line 678 of lalr1.cc  */
#line 6310 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 775:

/* Line 678 of lalr1.cc  */
#line 6311 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 776:

/* Line 678 of lalr1.cc  */
#line 6312 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 777:

/* Line 678 of lalr1.cc  */
#line 6313 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 778:

/* Line 678 of lalr1.cc  */
#line 6314 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 779:

/* Line 678 of lalr1.cc  */
#line 6315 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 780:

/* Line 678 of lalr1.cc  */
#line 6316 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 781:

/* Line 678 of lalr1.cc  */
#line 6317 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 782:

/* Line 678 of lalr1.cc  */
#line 6318 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 783:

/* Line 678 of lalr1.cc  */
#line 6319 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 784:

/* Line 678 of lalr1.cc  */
#line 6320 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 785:

/* Line 678 of lalr1.cc  */
#line 6321 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 786:

/* Line 678 of lalr1.cc  */
#line 6322 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 787:

/* Line 678 of lalr1.cc  */
#line 6323 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 788:

/* Line 678 of lalr1.cc  */
#line 6324 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 789:

/* Line 678 of lalr1.cc  */
#line 6325 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 790:

/* Line 678 of lalr1.cc  */
#line 6326 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 791:

/* Line 678 of lalr1.cc  */
#line 6327 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 792:

/* Line 678 of lalr1.cc  */
#line 6328 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 793:

/* Line 678 of lalr1.cc  */
#line 6329 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 794:

/* Line 678 of lalr1.cc  */
#line 6330 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 795:

/* Line 678 of lalr1.cc  */
#line 6331 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 796:

/* Line 678 of lalr1.cc  */
#line 6332 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 797:

/* Line 678 of lalr1.cc  */
#line 6333 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 798:

/* Line 678 of lalr1.cc  */
#line 6334 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 799:

/* Line 678 of lalr1.cc  */
#line 6335 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 800:

/* Line 678 of lalr1.cc  */
#line 6336 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 801:

/* Line 678 of lalr1.cc  */
#line 6337 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 802:

/* Line 678 of lalr1.cc  */
#line 6338 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 803:

/* Line 678 of lalr1.cc  */
#line 6339 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 804:

/* Line 678 of lalr1.cc  */
#line 6340 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 805:

/* Line 678 of lalr1.cc  */
#line 6341 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 806:

/* Line 678 of lalr1.cc  */
#line 6342 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 807:

/* Line 678 of lalr1.cc  */
#line 6343 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 808:

/* Line 678 of lalr1.cc  */
#line 6344 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 809:

/* Line 678 of lalr1.cc  */
#line 6345 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 810:

/* Line 678 of lalr1.cc  */
#line 6346 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 811:

/* Line 678 of lalr1.cc  */
#line 6347 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 812:

/* Line 678 of lalr1.cc  */
#line 6348 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 813:

/* Line 678 of lalr1.cc  */
#line 6349 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 814:

/* Line 678 of lalr1.cc  */
#line 6350 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 815:

/* Line 678 of lalr1.cc  */
#line 6351 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 816:

/* Line 678 of lalr1.cc  */
#line 6352 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 817:

/* Line 678 of lalr1.cc  */
#line 6353 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 818:

/* Line 678 of lalr1.cc  */
#line 6354 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 819:

/* Line 678 of lalr1.cc  */
#line 6355 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 820:

/* Line 678 of lalr1.cc  */
#line 6356 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 821:

/* Line 678 of lalr1.cc  */
#line 6357 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 822:

/* Line 678 of lalr1.cc  */
#line 6358 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 823:

/* Line 678 of lalr1.cc  */
#line 6359 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 824:

/* Line 678 of lalr1.cc  */
#line 6360 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 825:

/* Line 678 of lalr1.cc  */
#line 6361 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 826:

/* Line 678 of lalr1.cc  */
#line 6362 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 827:

/* Line 678 of lalr1.cc  */
#line 6363 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 828:

/* Line 678 of lalr1.cc  */
#line 6364 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 829:

/* Line 678 of lalr1.cc  */
#line 6365 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 830:

/* Line 678 of lalr1.cc  */
#line 6366 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 831:

/* Line 678 of lalr1.cc  */
#line 6367 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 832:

/* Line 678 of lalr1.cc  */
#line 6368 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 833:

/* Line 678 of lalr1.cc  */
#line 6369 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 834:

/* Line 678 of lalr1.cc  */
#line 6370 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 835:

/* Line 678 of lalr1.cc  */
#line 6371 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 836:

/* Line 678 of lalr1.cc  */
#line 6372 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 837:

/* Line 678 of lalr1.cc  */
#line 6373 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 838:

/* Line 678 of lalr1.cc  */
#line 6374 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 839:

/* Line 678 of lalr1.cc  */
#line 6375 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 840:

/* Line 678 of lalr1.cc  */
#line 6376 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("type"))); }
    break;

  case 841:

/* Line 678 of lalr1.cc  */
#line 6377 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 842:

/* Line 678 of lalr1.cc  */
#line 6378 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 843:

/* Line 678 of lalr1.cc  */
#line 6379 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 844:

/* Line 678 of lalr1.cc  */
#line 6380 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 845:

/* Line 678 of lalr1.cc  */
#line 6381 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 846:

/* Line 678 of lalr1.cc  */
#line 6382 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 847:

/* Line 678 of lalr1.cc  */
#line 6383 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 848:

/* Line 678 of lalr1.cc  */
#line 6384 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 849:

/* Line 678 of lalr1.cc  */
#line 6385 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 850:

/* Line 678 of lalr1.cc  */
#line 6386 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 851:

/* Line 678 of lalr1.cc  */
#line 6387 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 852:

/* Line 678 of lalr1.cc  */
#line 6388 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 853:

/* Line 678 of lalr1.cc  */
#line 6389 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 854:

/* Line 678 of lalr1.cc  */
#line 6390 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 855:

/* Line 678 of lalr1.cc  */
#line 6391 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 856:

/* Line 678 of lalr1.cc  */
#line 6392 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 857:

/* Line 678 of lalr1.cc  */
#line 6393 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 858:

/* Line 678 of lalr1.cc  */
#line 6394 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 859:

/* Line 678 of lalr1.cc  */
#line 6395 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 860:

/* Line 678 of lalr1.cc  */
#line 6396 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 861:

/* Line 678 of lalr1.cc  */
#line 6397 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 862:

/* Line 678 of lalr1.cc  */
#line 6398 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 863:

/* Line 678 of lalr1.cc  */
#line 6399 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 864:

/* Line 678 of lalr1.cc  */
#line 6400 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 865:

/* Line 678 of lalr1.cc  */
#line 6401 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 866:

/* Line 678 of lalr1.cc  */
#line 6402 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 867:

/* Line 678 of lalr1.cc  */
#line 6403 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 868:

/* Line 678 of lalr1.cc  */
#line 6404 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 869:

/* Line 678 of lalr1.cc  */
#line 6405 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 870:

/* Line 678 of lalr1.cc  */
#line 6406 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 871:

/* Line 678 of lalr1.cc  */
#line 6407 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 872:

/* Line 678 of lalr1.cc  */
#line 6408 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 873:

/* Line 678 of lalr1.cc  */
#line 6409 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 874:

/* Line 678 of lalr1.cc  */
#line 6410 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 875:

/* Line 678 of lalr1.cc  */
#line 6411 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 876:

/* Line 678 of lalr1.cc  */
#line 6412 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 877:

/* Line 678 of lalr1.cc  */
#line 6413 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 878:

/* Line 678 of lalr1.cc  */
#line 6414 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 879:

/* Line 678 of lalr1.cc  */
#line 6415 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 880:

/* Line 678 of lalr1.cc  */
#line 6416 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 881:

/* Line 678 of lalr1.cc  */
#line 6417 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 882:

/* Line 678 of lalr1.cc  */
#line 6418 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 883:

/* Line 678 of lalr1.cc  */
#line 6419 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 884:

/* Line 678 of lalr1.cc  */
#line 6420 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 885:

/* Line 678 of lalr1.cc  */
#line 6421 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 886:

/* Line 678 of lalr1.cc  */
#line 6422 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraphs"))); }
    break;

  case 887:

/* Line 678 of lalr1.cc  */
#line 6423 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 888:

/* Line 678 of lalr1.cc  */
#line 6424 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 889:

/* Line 678 of lalr1.cc  */
#line 6425 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 890:

/* Line 678 of lalr1.cc  */
#line 6426 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 891:

/* Line 678 of lalr1.cc  */
#line 6427 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 892:

/* Line 678 of lalr1.cc  */
#line 6428 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 893:

/* Line 678 of lalr1.cc  */
#line 6429 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 894:

/* Line 678 of lalr1.cc  */
#line 6430 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 895:

/* Line 678 of lalr1.cc  */
#line 6431 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 896:

/* Line 678 of lalr1.cc  */
#line 6432 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 897:

/* Line 678 of lalr1.cc  */
#line 6433 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 898:

/* Line 678 of lalr1.cc  */
#line 6434 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 899:

/* Line 678 of lalr1.cc  */
#line 6435 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 900:

/* Line 678 of lalr1.cc  */
#line 6436 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 901:

/* Line 678 of lalr1.cc  */
#line 6437 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 902:

/* Line 678 of lalr1.cc  */
#line 6438 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 903:

/* Line 678 of lalr1.cc  */
#line 6439 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 904:

/* Line 678 of lalr1.cc  */
#line 6440 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 905:

/* Line 678 of lalr1.cc  */
#line 6441 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 906:

/* Line 678 of lalr1.cc  */
#line 6442 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 907:

/* Line 678 of lalr1.cc  */
#line 6443 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 908:

/* Line 678 of lalr1.cc  */
#line 6444 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 909:

/* Line 678 of lalr1.cc  */
#line 6445 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 910:

/* Line 678 of lalr1.cc  */
#line 6446 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 911:

/* Line 678 of lalr1.cc  */
#line 6447 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 912:

/* Line 678 of lalr1.cc  */
#line 6448 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 913:

/* Line 678 of lalr1.cc  */
#line 6449 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 914:

/* Line 678 of lalr1.cc  */
#line 6450 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 915:

/* Line 678 of lalr1.cc  */
#line 6451 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 916:

/* Line 678 of lalr1.cc  */
#line 6452 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 917:

/* Line 678 of lalr1.cc  */
#line 6453 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 918:

/* Line 678 of lalr1.cc  */
#line 6454 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 919:

/* Line 678 of lalr1.cc  */
#line 6455 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 920:

/* Line 678 of lalr1.cc  */
#line 6456 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 921:

/* Line 678 of lalr1.cc  */
#line 6457 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 922:

/* Line 678 of lalr1.cc  */
#line 6458 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 923:

/* Line 678 of lalr1.cc  */
#line 6459 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 924:

/* Line 678 of lalr1.cc  */
#line 6460 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 925:

/* Line 678 of lalr1.cc  */
#line 6461 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 926:

/* Line 678 of lalr1.cc  */
#line 6462 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 927:

/* Line 678 of lalr1.cc  */
#line 6463 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 928:

/* Line 678 of lalr1.cc  */
#line 6464 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 929:

/* Line 678 of lalr1.cc  */
#line 6465 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 930:

/* Line 678 of lalr1.cc  */
#line 6466 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 931:

/* Line 678 of lalr1.cc  */
#line 6467 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 932:

/* Line 678 of lalr1.cc  */
#line 6468 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 933:

/* Line 678 of lalr1.cc  */
#line 6469 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 934:

/* Line 678 of lalr1.cc  */
#line 6470 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 935:

/* Line 678 of lalr1.cc  */
#line 6471 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 936:

/* Line 678 of lalr1.cc  */
#line 6472 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 937:

/* Line 678 of lalr1.cc  */
#line 6473 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 938:

/* Line 678 of lalr1.cc  */
#line 6474 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 939:

/* Line 678 of lalr1.cc  */
#line 6475 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 940:

/* Line 678 of lalr1.cc  */
#line 6476 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 941:

/* Line 678 of lalr1.cc  */
#line 6477 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 942:

/* Line 678 of lalr1.cc  */
#line 6478 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 943:

/* Line 678 of lalr1.cc  */
#line 6479 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 944:

/* Line 678 of lalr1.cc  */
#line 6480 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 945:

/* Line 678 of lalr1.cc  */
#line 6481 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 946:

/* Line 678 of lalr1.cc  */
#line 6482 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 947:

/* Line 678 of lalr1.cc  */
#line 6483 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 948:

/* Line 678 of lalr1.cc  */
#line 6484 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 949:

/* Line 678 of lalr1.cc  */
#line 6485 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 950:

/* Line 678 of lalr1.cc  */
#line 6486 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 951:

/* Line 678 of lalr1.cc  */
#line 6487 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 952:

/* Line 678 of lalr1.cc  */
#line 6488 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 953:

/* Line 678 of lalr1.cc  */
#line 6489 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 954:

/* Line 678 of lalr1.cc  */
#line 6490 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 955:

/* Line 678 of lalr1.cc  */
#line 6491 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 956:

/* Line 678 of lalr1.cc  */
#line 6492 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 957:

/* Line 678 of lalr1.cc  */
#line 6493 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 958:

/* Line 678 of lalr1.cc  */
#line 6499 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    {
          // EQName's namespace URI value is whitespace normalized according to the rules for the xs:anyURI type
          std::string uri = "\"" + SYMTAB((yysemantic_stack_[(3) - (1)].sval)) + "\"";
          std::string eqname = SYMTAB(driver.symtab.put_uri(uri.c_str(), uri.size())) + ":" + SYMTAB((yysemantic_stack_[(3) - (3)].sval));
          (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT(eqname.c_str())), true);
        }
    break;

  case 959:

/* Line 678 of lalr1.cc  */
#line 6505 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;



/* Line 678 of lalr1.cc  */
#line 11508 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1394;
  const short int
  xquery_parser::yypact_[] =
  {
      2898, -1394, -1394, -1394,  4384,  4384,  4384, -1394, -1394,   260,
     353,   200,    30,   246, -1394, -1394, -1394,   198, -1394, -1394,
   -1394,   468,   517,   417,   556,   558,   594,   328, -1394,   -32,
   -1394, -1394, -1394, -1394, -1394, -1394,   696, -1394,   612,   627,
   -1394, -1394, -1394, -1394,   672, -1394,   740, -1394,   641,   665,
   -1394,    15, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394,
   -1394, -1394, -1394, -1394, -1394, -1394,   543,   710, -1394, -1394,
   -1394, -1394,   651,  8839, -1394, -1394, -1394,   748, -1394, -1394,
   -1394,   765, -1394,   755,   776, -1394, -1394, 12566, -1394, -1394,
   -1394, -1394, -1394, -1394, -1394, -1394,   787, -1394, -1394,   799,
     801, -1394, -1394, -1394, -1394, -1394, -1394, -1394,  3196,  6166,
   12566, -1394, -1394, -1394, -1394, -1394, -1394, -1394,   775, -1394,
   -1394,   808,  9720, -1394, 10010,   816,   835, -1394, -1394, -1394,
     836, -1394,  8542, -1394, -1394, -1394, -1394, -1394, -1394,   807,
   -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394,    39,   746,
   -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394,   668,   806,
     675, -1394,   739,   576, -1394, -1394, -1394, -1394, -1394, -1394,
     846, -1394,   725,   727,   728, -1394, -1394,   812,   817, -1394,
   -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394,
   -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394,
   -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394,
   -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394,
   -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394,
   -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394,
   -1394, -1394,  4681,   970, -1394,  4978, -1394, -1394,   120,    77,
   -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394,
   -1394, -1394, -1394, -1394,    79, -1394, -1394, -1394, -1394, -1394,
   -1394,   311, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394,
    4384, -1394, -1394, -1394, -1394,    27, -1394, -1394, -1394, -1394,
   -1394, -1394, -1394, -1394,   865, -1394,   784, -1394, -1394, -1394,
     501, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394,   809,
     880, -1394,   870,   729,   548,   259,   -20,   573, -1394,   924,
     779,   878,   879,  7354, -1394, -1394, -1394,   491, -1394, -1394,
    8542, -1394,   670, -1394,   828,  8839, -1394,   828,  8839, -1394,
   -1394, -1394,   477, -1394, -1394, -1394, -1394, -1394, -1394, -1394,
   -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394,
   -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394,
   -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394,
   -1394, -1394, -1394, -1394, -1394,   862,   840,   830, -1394, -1394,
   -1394, -1394, -1394,   803, -1394,  4384,   805,   813,   387,   387,
     960,   -16,   603,   458, 12850, 12566,   431,   943, 12566,   848,
     874,   269,  9720,   694,   753, 12566, 12566,   698,   700,    47,
   -1394, -1394, -1394,  9720,  4384,   818,  4384,   118,  7651, 10578,
     721,   723, 12566,   885,    -3,   855,  7651,  1007,   125,    78,
   12566,   896,   873,   909, -1394,  7651,  9428, 12566, 12566, 12566,
    4384,   831,  7651,  7651, 12566,  4384,   867,   869, -1394, -1394,
   -1394,  7651, 10862, -1394,   868, -1394,   877, -1394, -1394, -1394,
   -1394,   881, -1394,   882, -1394, -1394, -1394, -1394, -1394,   883,
   -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394,
   -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394,
   -1394, -1394, -1394, -1394, -1394, -1394, -1394, 12566, -1394, -1394,
   -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394,
     884, 12566, -1394, -1394, -1394,   839,  3493,   890,   892,   898,
   12566,  4384, -1394,   888,   197, -1394,   507,   994,  7651, -1394,
   -1394,    73, -1394, -1394, -1394,  1016, -1394, -1394, -1394, -1394,
    7651,   822, -1394,  1025,  7651,  7651,   871,  7651,  7651,  7651,
    7651,   826, 12566,   872,   875,  7651,  7651,  3196,   815, -1394,
   -1394, -1394, -1394,    30,   328,    83,    87,  1053,  5275,  5275,
    5572,  5572,   765, -1394, -1394,   865,   765, -1394,  7651, -1394,
     942,   556,   -32,   893,   894,   897,  4384,  7651, -1394, -1394,
   -1394, -1394, -1394, -1394, -1394, -1394,  7948,  7948,  7948, -1394,
    7948,  7948, -1394,  7948, -1394,  7948, -1394, -1394, -1394, -1394,
   -1394, -1394, -1394,  7948,  7948,   992,  7948,  7948,  7948,  7948,
    7948,  7948,  7948,  7948,  7948,  7948,  7948,   838,   971,   974,
     975, -1394, -1394, -1394,  6463, -1394, -1394,  8542,  8542,  7651,
     828, -1394, -1394,   828, -1394,  6760,   828,  9720,   922,  7057,
   -1394, -1394, -1394, -1394,   199, -1394,   239, -1394, -1394, -1394,
   -1394, -1394,   973,   977,   558,  1048, -1394, -1394, 12850,   866,
     601, 12566,   921,   925,   866,   960,   955,   954, -1394, -1394,
   -1394,   165,   842,   993,   791, 12566,   948,  7651,   978, 12566,
   12566, -1394,   959,   908,  4384, -1394,   911,   877,   627, -1394,
     910,   912,    32, -1394,   249,   267, -1394, -1394,   986, -1394,
      24, 12566,    10, 12566,  1003,   288, -1394,  4384, -1394,   296,
   -1394,  9720,  1004,  1056,  9720,   960,  1008,    41, 12566,  7651,
     -32,   407,   917, -1394,   919,   920,   923,     9, -1394,   264,
     927, -1394,   301,   317,   956, -1394,   928,  4384,  4384,   412,
   -1394,   339,   341,   509,  7651,    43, -1394, -1394,  7651,  7651,
    7651, -1394,  7651, -1394,  7651, 12566,   994, -1394,    22,   423,
   -1394, -1394, -1394,   442, -1394,    18, -1394, -1394, -1394,   110,
     112,  1013,   886,   889,    13, -1394,   972, -1394, -1394,   926,
     342,  3790,   451,  9136,   815, -1394,   120,   609,  1081,  1081,
   -1394, -1394,    88, -1394, -1394,    92, -1394,    16, -1394, -1394,
   -1394, -1394, -1394, -1394, -1394, 12566,   947,  7651,  1000, -1394,
   -1394, -1394,   880, -1394, -1394, -1394, -1394, -1394,  7948, -1394,
   -1394, -1394,    50,   259,   259,   437,   -20,   -20,   -20,   -20,
     573,   573, -1394, -1394, 11998, 11998, 12566, 12566, -1394,   471,
   -1394, -1394,    11, -1394, -1394, -1394,   365, -1394, -1394, -1394,
     398,   387, -1394, -1394,    21,   187,   598, -1394,   558, -1394,
   -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394,   866,
   -1394,   987, 12282,   979,  7651, -1394, -1394, -1394,  1028,   960,
     960,   866, -1394,   759,   960,   590, 12566,  -115,   544,  1090,
   -1394, -1394,   841,   523, -1394, -1394, -1394, -1394, -1394, -1394,
   -1394, -1394, -1394, -1394, -1394,   165,   274,   899,   529,  7651,
   -1394, 12566,  1032,   832,   960, -1394, -1394, -1394, -1394,   976,
   12566, -1394, 12566, -1394,  1010,  1005, 11998,  1015,  7651,   -33,
     984,    26,   392,   887, -1394, -1394,   643,    10,  1028, 11998,
    1017,  1039,   952,   940,  1006,   960,   981,  1011,  1042,   960,
    7651,    19, -1394, -1394, -1394,   989, -1394, -1394, -1394, -1394,
    1026,  7651,  7651,   999, -1394,  1047,  1051,  4384, -1394,   964,
     968,  1001, 12566, -1394, 12566, -1394,  7651,  1014,   965,  7651,
     405,   406,   414,  1121, -1394,   217, -1394,   514, -1394, -1394,
    1128, -1394,   686,  7651,  7651,  7651,   689,  7651,  7651,  7651,
    7651,  7651,  7651,  1041,  7651,  7651, -1394,  5869,  1012,  1018,
    1019,  1009,   784,   559,   916, -1394,   -22, -1394,    96,   171,
      16,  5572,  5572,  5572,  1083, -1394,  7651,   659,  1054, -1394,
   12566,  1057, -1394, -1394,  7651,    50,   245,   579, -1394,   895,
     126,   913,   914, -1394, -1394,   753, -1394,   903,   572,  1020,
    1021, 12282,  1022, -1394,   522, -1394, -1394, -1394, -1394, -1394,
   -1394, -1394, -1394, -1394,  1027, -1394, -1394, -1394,  7651, -1394,
   -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394,   635, -1394,
    1151,   744, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394,
   -1394,   900, -1394, -1394,  1152, -1394, -1394, -1394, -1394, -1394,
     588,  1153, -1394,   681, -1394, -1394, -1394,   868,   517,   881,
     612,   882,   883,   806, -1394,   522,  8245,   901,   902, -1394,
    1028,   274,   958,   996,  4384,  1002,  1024,  1046,  1029,  1030,
   12566,   347, -1394, 12566, -1394,  7651,  1045,  7651,  1066,  7651,
      29,  1050,  7651,  1055, -1394,  1076,  1077,  7651, 12566,   789,
    1120, -1394, -1394, -1394, -1394, -1394, -1394, 11998, -1394,  4384,
     960,  1093, -1394, -1394, -1394,   960,  1093, -1394,  7651,  1059,
    4384, 12566, -1394, -1394,  7651,  7651,   591, -1394,    51,   680,
   -1394, 11146,   695, -1394,   711, -1394,  1035, -1394, -1394,  4384,
    1033,  1036, -1394,  7651, -1394, -1394,  1031,  1047,  1104, -1394,
    1073, -1394,   639, -1394, -1394,  1200, -1394, -1394,  4384, 12566,
   -1394,   646, -1394, -1394, -1394,  1023,   980,   982, -1394, -1394,
   -1394,   990,   995, -1394, -1394, -1394, -1394, -1394,   988, 12566,
    1040, -1394, -1394,  7651,  7651,  7651,  4087,  5869,  9136,   916,
   -1394,  9136, -1394,  1081,   154, -1394, -1394, -1394,  1054, -1394,
     960, -1394,   783, -1394,    66,  1103, -1394,  7651,  1119,  1000,
     502,  1044, -1394,    50,   983, -1394, -1394,   -68, -1394,   236,
      70,   985,    50,   236,  7948, -1394,   131, -1394, -1394, -1394,
   -1394, -1394, -1394,    50,  1086,   957,   842,    70, -1394, -1394,
     950,  1157, -1394, -1394, -1394, 10294,  1052,  1060,  1061, -1394,
   -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394,
   -1394,  1211,   -12,  1213,   -12,   991,  1139, -1394,  1079, 12566,
     997, -1394, -1394,  8245, -1394,  1068, -1394, -1394, -1394, -1394,
   -1394, -1394,  7651,  1108, -1394, -1394,  7651, -1394,   545, -1394,
    7651,  1109,  7651, -1394,  7651, 12566, 12566, -1394,   640, -1394,
    7651, -1394,  1124,  1133,  1163,   960,  1093, -1394,  7651,  1078,
   -1394, -1394, -1394,  1082, -1394,    56,  7651,  4384,  1084,   101,
   -1394, 12566,  1085, 11430,    35, -1394, 11714,  1087, -1394, -1394,
    1080, -1394, -1394, -1394,  7651,   712,  1121, 12566,   706, -1394,
    1088,  1121, 12566, -1394, -1394,  7651,  7651,  7651,  7651,  7651,
   -1394,  7651,   416,   427,   438,   -15, -1394, -1394, -1394, -1394,
   -1394,  1103, -1394, -1394, -1394,   960, -1394, -1394, -1394, -1394,
   -1394,  1091,  7948, -1394, -1394, -1394, -1394, -1394,   250,  7948,
    7948,   454, -1394,   913, -1394,   379, -1394,   914,    50,  1110,
   -1394, -1394,   998, -1394, -1394, -1394, -1394,  1174,  1089, -1394,
     459, -1394, -1394, -1394, -1394,   214,   214, -1394,   -12, -1394,
   -1394,   465, -1394,  1244,    70,  1183,  1096,  8245,   -42,  1034,
    1114, -1394, -1394,  7651, -1394,  7651,  1138, -1394,  7651, -1394,
   -1394, -1394,  1233, -1394, -1394,  5869,  7651,   960, -1394, -1394,
   -1394,  7651,  7651, -1394, -1394, -1394,  5869,  5869,  1194,  4384,
   12566,  1105, 12566,  7651, 12566,  1106,  5869, -1394,   195,    31,
    1121, 12566, -1394,  1094,  1121, -1394, -1394, -1394, -1394, -1394,
   -1394,  1097,  1047,  1051,  7651, -1394, -1394, -1394, -1394,   -20,
    7948,  7948,   437,   549, -1394, -1394, -1394, -1394, -1394, -1394,
    7651, -1394, 11998, -1394, 11998,  1198, -1394, -1394, -1394,  1265,
   -1394, -1394, -1394,  1037,  1189, -1394, -1394,  1191, -1394,   720,
   12566,  1181,  1101, 12566,  8245, -1394, -1394,  7651, -1394,  1182,
   -1394, -1394,  1093, -1394, -1394, 11998, -1394, -1394,  1208,  7651,
    1118, -1394,  1212,  5869, -1394, 12566,   287,   750, -1394,  1112,
    1121, -1394,  1113,  5869,   722,   505,   437,   437,  7948,   511,
   -1394, -1394, 11998, -1394, -1394,  1183,  8245, -1394,  1103,  1038,
   12566,  1188,  1102,  1191, -1394, 12566,  1127, 11998,  4384, 11998,
    1131, -1394, -1394,  1216,   537, -1394, -1394, -1394, -1394,  1135,
     772, -1394, -1394, -1394,  1125, -1394,  1209, -1394,   437, -1394,
   -1394, -1394, -1394, -1394,  7651,  1058, 12566,  1210, -1394,  4384,
    1143, -1394, -1394,  1145,  7651, -1394, -1394, -1394, -1394, -1394,
   -1394, -1394, 12566, -1394,  1049,  1062, 12566, -1394, -1394,  7651,
    5869,  1146,  1043,  7651,  1065,  5869,  8245, -1394,  8245, -1394,
    1136,  1063, 12566,  1116,  1215, 12566,  1067,  8245, -1394
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
       159,   438,   439,   440,   162,   162,   162,   760,   959,   116,
     118,   588,   852,   861,   801,   765,   763,   745,   853,   856,
     808,   769,   746,   747,   800,   862,   749,   859,   830,   810,
     785,   805,   806,   857,   854,   804,   751,   860,   752,   753,
     901,   913,   900,   802,   821,   815,   754,   803,   756,   755,
     902,   839,   840,   807,   782,   923,   924,   925,   926,   927,
     928,   929,   930,   931,   932,   933,   947,   954,   829,   825,
     816,   796,   744,     0,   824,   832,   841,   948,   820,   460,
     797,   798,   855,   949,   955,   817,   834,     0,   466,   427,
     462,   827,   762,   818,   819,   848,   822,   838,   847,   953,
     956,   768,   809,   850,   461,   837,   843,   748,     0,     0,
       0,   375,   835,   846,   851,   849,   828,   814,   903,   812,
     813,   950,     0,   374,     0,   951,   957,   844,   799,   823,
     952,   405,     0,   437,   845,   826,   833,   842,   836,   904,
     790,   795,   794,   793,   792,   791,   757,   811,     0,   761,
     858,   783,   892,   891,   893,   767,   766,   786,   898,   750,
     890,   895,   896,   887,   789,   831,   889,   899,   897,   888,
     787,   894,   908,   909,   906,   907,   905,   758,   910,   911,
     912,   878,   877,   864,   781,   774,   871,   867,   784,   780,
     879,   880,   770,   771,   764,   773,   876,   875,   872,   868,
     885,   886,   884,   874,   870,   863,   772,   883,   882,   776,
     778,   777,   869,   873,   865,   779,   866,   775,   881,   934,
     935,   936,   937,   938,   939,   915,   916,   914,   920,   921,
     922,   917,   918,   919,   788,   940,   941,   942,   943,   944,
     945,   946,   159,     0,     2,   159,     5,     7,    19,     0,
      24,    27,    32,    33,    34,    35,    36,    37,    38,    28,
      54,    55,    29,    30,     0,    72,    75,    76,    31,    77,
      78,     0,   114,    79,    80,    81,    82,    14,   156,   157,
     158,   165,   167,   457,   168,     0,   169,   170,   171,   172,
     173,   174,   175,   178,   163,   204,   211,   206,   233,   239,
       0,   231,   232,   213,   207,   177,   208,   176,   209,   212,
     330,   332,   334,   344,   348,   350,   353,   358,   361,   364,
     366,   368,   370,     0,   372,   378,   380,     0,   396,   379,
     401,   404,   406,   409,   411,     0,   416,   413,     0,   424,
     434,   436,   410,   441,   448,   458,   449,   450,   451,   454,
     455,   452,   453,   473,   475,   476,   477,   474,   522,   523,
     524,   525,   526,   527,   433,   562,   554,   561,   560,   559,
     556,   558,   555,   557,   459,   456,   589,   590,    39,   214,
     215,   217,   216,   218,   210,     0,   435,   743,   759,   852,
     861,   859,   761,     0,   160,   161,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     122,   124,   125,     0,     0,     0,   162,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   258,   259,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   429,   432,
     419,     0,     0,   740,   745,   769,   747,   800,   862,   749,
     810,   751,   821,   754,   756,   755,   839,   947,   954,   744,
     948,   798,   949,   955,   822,   953,   956,   903,   950,   951,
     957,   952,   904,   898,   890,   896,   887,   787,   908,   909,
     906,   758,   910,   425,   435,   743,   417,     0,   185,   418,
     421,   745,   746,   747,   751,   752,   753,   754,   744,   750,
     463,     0,   423,   422,   180,     0,     0,   749,   756,   755,
       0,   162,   464,   910,     0,   211,     0,   489,     0,   428,
     741,     0,   742,   399,   400,     0,   431,   430,   420,   403,
       0,     0,   518,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     3,
       1,     6,     8,     0,     0,     0,     0,     0,   159,   159,
     159,   159,     0,   115,   166,   164,     0,   183,     0,   192,
       0,     0,     0,     0,     0,     0,     0,     0,   197,   219,
     238,   234,   240,   235,   237,   236,     0,     0,     0,   389,
       0,     0,   387,     0,   339,     0,   388,   381,   386,   385,
     384,   383,   382,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   377,   376,   373,     0,   397,   402,     0,     0,     0,
     412,   445,   415,   414,   426,     0,   442,     0,     0,     0,
     529,   531,   535,   588,     0,   120,     0,    43,    40,    41,
      44,    45,     0,     0,     0,     0,    46,    47,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   599,   600,
     601,     0,    99,   138,     0,     0,   108,     0,     0,     0,
       0,   123,     0,     0,     0,   568,     0,     0,     0,   564,
       0,     0,     0,   578,     0,     0,   221,   222,   241,   242,
       0,     0,     0,     0,   130,     0,   134,   162,   592,     0,
      56,     0,    65,     0,     0,     0,    57,     0,     0,     0,
       0,     0,   740,   569,     0,     0,     0,     0,   303,     0,
       0,   567,     0,     0,     0,   586,     0,     0,     0,     0,
     572,     0,     0,   187,     0,     0,   181,   179,     0,     0,
       0,   463,     0,   465,     0,   490,   489,   486,     0,     0,
     520,   519,   398,     0,   517,     0,   612,   613,   563,     0,
       0,     0,     0,     0,     0,   618,     0,   195,   196,     0,
       0,     0,     0,     0,   200,   201,    20,     0,    21,     0,
       4,    25,     0,    11,    26,     0,    15,   852,    73,    12,
      74,    16,   186,   184,   205,     0,     0,     0,     0,   198,
     220,   276,   331,   333,   337,   343,   342,   341,     0,   338,
     335,   336,     0,   352,   351,   349,   355,   356,   357,   354,
     359,   360,   363,   362,     0,     0,     0,     0,   394,     0,
     407,   408,     0,   446,   443,   471,     0,   958,   591,   469,
       0,     0,   117,   119,     0,     0,     0,    98,     0,    88,
      90,    91,    92,    93,    95,    96,    97,    89,    94,    84,
      85,     0,     0,   104,     0,   100,   102,   103,   110,     0,
       0,    83,    42,     0,     0,     0,     0,     0,     0,     0,
     690,   695,     0,     0,   691,   725,   678,   680,   681,   682,
     684,   686,   685,   683,   687,     0,     0,     0,     0,     0,
     107,     0,   140,     0,     0,   534,   528,   565,   566,     0,
       0,   582,     0,   579,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   223,   224,     0,   229,   136,     0,
       0,   131,     0,     0,     0,     0,     0,     0,    58,     0,
       0,     0,   257,   263,   260,     0,   571,   570,   577,   585,
       0,     0,     0,     0,   533,     0,     0,     0,   390,     0,
       0,     0,     0,   575,     0,   573,     0,   188,     0,     0,
       0,     0,     0,   489,   487,     0,   478,     0,   467,   468,
       0,     9,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   193,     0,   749,   756,
     755,   910,     0,     0,     0,   626,     0,   202,     0,     0,
       0,   159,   159,   159,     0,   230,     0,   287,   283,   285,
       0,   277,   278,   340,     0,     0,     0,     0,   656,   346,
     629,   633,   635,   637,   639,   642,   649,   650,   658,   862,
     748,     0,   757,   365,   540,   546,   547,   549,   593,   594,
     550,   553,   367,   369,   537,   371,   395,   447,     0,   444,
     470,   121,    52,    53,    50,    51,   127,   126,     0,    86,
       0,     0,   105,   106,   111,    70,    71,    48,    49,    69,
     696,     0,   699,   726,     0,   689,   688,   693,   692,   724,
       0,     0,   701,     0,   697,   700,   679,     0,     0,     0,
       0,     0,     0,     0,   139,   142,     0,     0,     0,   109,
     112,     0,     0,     0,   162,     0,     0,   586,     0,     0,
       0,     0,   539,     0,   244,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   225,     0,     0,     0,     0,   270,
       0,   267,   272,   228,   137,   132,   135,     0,   182,     0,
       0,    67,    61,    64,    63,     0,    59,   261,     0,     0,
     162,     0,   301,   305,     0,     0,     0,   308,     0,     0,
     314,     0,     0,   321,     0,   325,     0,   392,   391,   162,
       0,     0,   189,     0,   191,   302,     0,     0,     0,   490,
       0,   479,     0,   513,   510,     0,   514,   515,     0,     0,
     509,     0,   484,   512,   511,     0,     0,     0,   605,   606,
     602,     0,     0,   610,   611,   607,   616,   614,     0,     0,
       0,   620,   194,     0,     0,     0,     0,     0,     0,   621,
     622,     0,   203,    22,     0,    13,    17,    18,   284,   296,
       0,   297,     0,   288,   289,   290,   291,     0,   280,     0,
       0,     0,   640,   653,     0,   345,   347,     0,   672,     0,
       0,     0,     0,     0,     0,   628,   630,   631,   667,   668,
     669,   671,   670,     0,     0,   644,   643,     0,   647,   651,
     665,   663,   662,   655,   659,     0,     0,     0,     0,   543,
     545,   544,   541,   538,   472,   129,   128,    87,   101,   713,
     694,     0,   718,     0,   718,   707,   702,   143,     0,     0,
       0,   113,   141,     0,    23,     0,   583,   584,   587,   580,
     581,   243,     0,     0,   256,   248,     0,   252,     0,   246,
       0,     0,     0,   265,     0,     0,     0,   227,   268,   271,
       0,   133,     0,     0,    66,     0,    60,   262,     0,     0,
     304,   306,   311,     0,   309,     0,     0,     0,     0,     0,
     315,     0,     0,     0,     0,   322,     0,     0,   326,   393,
       0,   576,   574,   190,     0,     0,   489,     0,     0,   521,
       0,   489,     0,   485,    10,     0,     0,     0,     0,     0,
     619,     0,     0,     0,     0,     0,   623,   627,   300,   298,
     299,   292,   293,   294,   286,     0,   281,   279,   657,   648,
     654,     0,     0,   727,   728,   738,   737,   736,     0,     0,
       0,     0,   729,   634,   735,     0,   632,   636,     0,     0,
     641,   645,     0,   666,   661,   664,   660,     0,     0,   551,
       0,   548,   598,   542,   714,     0,     0,   712,   719,   720,
     716,     0,   711,     0,   709,     0,     0,     0,     0,     0,
       0,   530,   245,     0,   254,     0,     0,   250,     0,   253,
     266,   274,   275,   269,   226,     0,     0,     0,    62,   264,
     536,     0,     0,   312,   316,   310,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   532,     0,     0,
     489,     0,   516,     0,   489,   603,   604,   608,   609,   615,
     617,     0,     0,     0,     0,   624,   295,   282,   652,   739,
       0,     0,   731,     0,   677,   676,   675,   674,   673,   638,
       0,   730,     0,   595,     0,     0,   723,   722,   721,     0,
     715,   708,   706,     0,   703,   704,   698,   144,   146,   148,
       0,     0,     0,     0,     0,   249,   247,     0,   255,     0,
     199,   329,    68,   307,   313,     0,   327,   323,     0,     0,
       0,   317,     0,     0,   319,     0,   499,   493,   488,     0,
     489,   480,     0,     0,     0,     0,   733,   732,     0,     0,
     596,   552,     0,   717,   710,     0,     0,   150,   149,     0,
       0,     0,     0,   145,   251,     0,     0,     0,     0,     0,
       0,   507,   501,     0,   500,   502,   508,   505,   495,     0,
     494,   496,   506,   482,     0,   481,     0,   625,   734,   646,
     597,   705,   147,   151,     0,     0,     0,     0,   273,     0,
       0,   320,   318,     0,     0,   492,   503,   504,   491,   497,
     498,   483,     0,   152,     0,     0,     0,   328,   324,     0,
       0,     0,     0,     0,     0,     0,     0,   154,     0,   153,
       0,     0,     0,     0,     0,     0,     0,     0,   155
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1394, -1394,  -215,  1095, -1394,  1098,  1099, -1394,  1111,  -528,
   -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394,
    -924, -1394, -1394, -1394, -1394,  -213,  -553, -1394,   652,  -435,
   -1394, -1394, -1394, -1394, -1394,   241,   452, -1394, -1394,    12,
    -175,   951, -1394,   930, -1394, -1394,  -608, -1394,   396, -1394,
     216, -1394,  -226,  -264, -1394,  -526, -1394,     5,   106,    95,
    -239,  -177, -1394,  -800, -1394, -1394,  -113, -1394, -1394, -1394,
   -1394, -1394, -1394, -1394, -1394, -1394, -1394,   562,   -89,  1237,
       0, -1394, -1394, -1394, -1394,   413, -1394, -1394,  -293, -1394,
       8, -1394, -1394,   213,  -718,  -680, -1394, -1394,   632, -1394,
   -1394,     7,   204, -1394, -1394, -1394,    97, -1394, -1394,   331,
     102, -1394, -1394,   104, -1237, -1394,   859,   190, -1394, -1394,
     186,  -968, -1394, -1394,   184, -1394, -1394, -1182, -1176, -1394,
     180, -1394, -1394,   780,   778, -1394,  -479, -1394, -1394,  -612,
     299,  -599,   297,   300, -1394, -1394, -1394, -1394, -1394,  1069,
   -1394, -1394, -1394, -1394,  -798,  -304, -1089, -1394,  -107, -1394,
   -1394, -1394, -1394, -1394, -1394, -1394,   -27,  -782, -1394, -1394,
     547,   225, -1394,  -380, -1394, -1394, -1394, -1394, -1394, -1394,
   -1394,   730, -1394,  -949, -1394,   166, -1394,   614,  -754, -1394,
   -1394, -1394, -1394, -1394,  -257,  -250, -1148,  -888, -1394, -1394,
   -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394,   539,  -734,
    -694,   262,  -831, -1394,    76,  -749, -1394, -1394, -1394, -1394,
   -1394, -1394, -1394,  1064,  1070,  -522,   456,   302, -1394, -1394,
   -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394,
   -1394, -1394,   151, -1394, -1394,   142, -1394,   145, -1016, -1394,
   -1394, -1394,   113,   103,   -54,   351, -1394, -1394, -1394, -1394,
   -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394, -1394,   114,
   -1394, -1394, -1394,   -47,   344,   486, -1394, -1394, -1394, -1394,
   -1394,   289, -1394, -1394, -1393, -1394, -1394, -1394,  -534, -1394,
      80, -1394,   -63, -1394, -1394, -1394, -1394, -1209, -1394,   123,
   -1394,  -336,  -364,   906,    52, -1394
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   243,   809,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
    1181,   735,   261,   262,   263,   264,   265,   266,   889,   890,
     891,   267,   268,   269,   895,   896,   897,   270,   418,   271,
     272,   664,   273,   420,   421,   422,   435,   725,   726,   274,
    1134,   275,  1577,  1578,   276,   277,   278,   525,   279,   280,
     281,   282,   283,   728,   284,   285,   508,   286,   287,   288,
     289,   290,   291,   598,   292,   293,   804,   805,   294,   295,
     535,   297,   599,   433,   956,   957,   298,   600,   299,   602,
     536,   301,   718,   719,  1169,   442,   302,   443,   444,   722,
    1170,  1171,  1172,   603,   604,  1051,  1052,  1436,   605,  1048,
    1049,  1273,  1274,  1275,  1276,   303,   747,   748,   304,  1196,
    1197,  1385,   305,  1199,  1200,   306,   307,  1202,  1203,  1204,
    1205,   308,   309,   310,   311,   838,   312,  1285,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     623,   624,   325,   326,   327,   328,   329,   330,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   340,   341,   342,
     650,   651,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   866,   352,   353,   354,  1231,   776,   777,   778,  1608,
    1649,  1650,  1643,  1644,  1651,  1645,  1232,  1233,   355,   356,
    1234,   357,   358,   359,   360,   361,   362,   363,  1083,   951,
    1073,  1322,  1074,  1470,  1075,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   754,  1146,   374,   375,   376,
     377,  1077,  1078,  1079,  1080,   378,   379,   380,   381,   382,
     383,   794,   795,   384,  1259,  1260,  1545,  1036,  1059,  1295,
    1296,  1060,  1061,  1062,  1063,  1064,  1305,  1460,  1461,  1065,
    1308,  1066,  1441,  1067,  1068,  1313,  1314,  1466,  1464,  1297,
    1298,  1299,  1300,  1557,   692,   916,   917,   918,   919,   920,
     921,  1124,  1486,  1574,  1125,  1484,  1572,   922,  1334,  1481,
    1477,  1478,  1479,   923,   924,  1301,  1309,  1451,  1302,  1447,
    1286,   385,   541,   386,   387,   388
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int xquery_parser::yytable_ninf_ = -741;
  const short int
  xquery_parser::yytable_[] =
  {
       296,   568,   949,   971,   296,   296,   296,   601,   300,   393,
     396,   397,   300,   300,   300,   983,   845,  1198,   665,   665,
     534,  1035,  1005,   645,   419,   549,  1395,   818,   820,   997,
     846,   847,   848,   849,   579,   576,  1405,  1432,  1433,  1281,
     950,   584,     9,    10,  1057,  1186,   503,  1338,   687,   581,
     811,   814,   813,   816,   819,   821,     9,    10,  1230,   702,
     945,  1101,  1158,   404,   667,   953,   876,   400,   401,   551,
     402,   403,   405,     9,    10,  1580,  1097,   404,   577,   663,
     577,   780,   744,  1413,   577,   440,   405,   406,   577,   577,
     407,   454,  1575,   577,   404,   408,   583,   577,  1462,   395,
     395,   395,   732,   736,   407,  1076,  1076,   463,   296,   408,
     394,   394,   394,  1155,   723,   980,   300,   588,   946,  1023,
     947,   407,   947,  1475,  1606,   505,   409,   410,  1044,   834,
    1256,   835,   836,   586,   837,   946,   839,  1544,   588,   505,
     409,   410,   411,  1076,   840,   841,  1115,  1443,  1010,   980,
    1386,  1006,  1522,   573,   463,  1386,   584,  1116,   698,    79,
    1188,  1082,   505,   707,  1104,   668,  1448,   455,  1092,   574,
     948,  1270,  1159,    90,   505,  1360,   505,  1135,   669,   633,
     708,  1581,   970,   724,  1444,  1093,  1261,  1476,   634,   412,
     733,   585,  1272,  1261,  1546,  1087,   981,  1076,   104,   682,
    1386,   683,  1054,   526,  1012,  1055,  1016,  1011,   400,   401,
    1076,   402,   403,  1607,   394,   939,   587,  1007,  1163,   905,
    1523,   906,  1287,   646,  1174,   954,   124,  1287,   406,  1395,
     999,  1389,  1661,  1160,   456,   457,  1387,   734,   441,   441,
    1317,  1512,   296,   601,   583,   296,  1024,   781,   413,  1220,
     300,   552,  1152,   300,  1490,   818,   820,  1057,  1057,   685,
    1413,  1376,   955,  1582,   907,  1175,   578,  1440,   580,  1156,
    1098,  1161,   806,  1230,   663,  1573,   808,  1041,   811,   814,
     296,  1043,  1230,  1264,   731,  1263,  1517,   584,   300,   414,
     441,  1189,  1641,   867,  1288,   441,  1223,   441,  1326,  1288,
     441,   415,  1550,   588,   709,   871,   585,  1056,   652,   416,
    1331,   654,  1605,  1127,   682,   415,   683,   417,  1128,   707,
    -740,   686,  1076,   416,  1449,  1450,  1013,  1014,  1017,  1018,
     412,   417,   699,  1129,  1094,  1130,   708,     9,    10,   712,
     700,  1015,  1627,  1019,  1131,   871,  1221,   729,   684,   902,
     424,  1095,   437,   425,    79,   940,   741,   829,   946,  1053,
     807,  1614,   438,   752,   753,   812,   815,   964,    90,  1333,
     967,  1132,   759,   942,   685,   629,  1289,  1290,  1551,  1291,
    1523,  1289,  1290,   773,  1291,   872,  1292,   505,   439,   413,
     505,  1663,  1135,   104,   960,   296,  1293,  1054,  1579,   968,
    1055,  1293,   588,   300,   630,   423,  1341,   588,  1294,  1226,
     982,  1227,  1222,  1294,   908,   398,   663,   631,  1145,  1642,
    1148,   124,   582,   588,   296,   873,   296,   909,  1076,   910,
     414,   706,   300,  1353,   300,   941,   686,   585,  1395,  1228,
     911,   912,   913,   947,   914,   992,   915,   994,   588,   779,
     296,   632,  1076,   943,  1099,   296,   674,   505,   300,  1230,
     505,   783,  1058,   300,   505,   584,  1099,   505,   505,   822,
    1210,  1088,  1211,   823,   961,   505,  1035,   800,   802,  1427,
    1361,   505,   963,  1371,   505,  1057,   946,   985,   818,   820,
     818,  1091,   505,  1352,  1057,  1579,    79,  1133,   505,   505,
     505,   505,  1445,   986,  1088,  1057,   505,  1392,   399,  1446,
      90,   588,   588,   588,   505,  1265,  1266,  1267,   588,   704,
     588,   395,   588,  1223,  1224,   993,   296,   995,  1027,   588,
     703,   296,   394,   588,   300,   104,   626,  1579,  1162,   300,
     860,   861,  1641,   590,   588,   704,  1223,   591,   588,   590,
     704,  1089,   592,   591,   627,   859,   750,   588,   592,   505,
     862,   756,   584,  1105,  1106,  1564,  1076,   296,  1109,   428,
     593,  1569,   429,   505,  1389,   300,   593,   588,   296,   296,
     296,   296,   505,  1592,  1090,   419,   300,   300,   300,   300,
     975,  1216,  1217,  1038,   626,   991,   296,  1042,  1143,   676,
    1218,   590,  1541,   946,   300,   591,  1008,  1699,   588,  1700,
     592,   588,   627,  1542,   505,   585,  1225,   588,  1708,  1121,
     426,  1469,   430,   672,  1543,  1009,   395,   431,   593,  1182,
     649,   677,   655,  1182,  1034,  1122,  1226,   394,  1227,   673,
    1496,   947,  1039,   644,  1076,  1565,  1554,  1076,  1223,  1224,
     996,  1570,  1529,  1555,  1086,  1223,  1224,  1533,   574,  1226,
    1057,  1227,   801,  1556,   458,  1319,  1228,   124,   594,  1676,
     110,   595,   427,   432,   594,  1058,  1058,   595,  1123,  1000,
    1001,  1002,  1455,   802,  1331,  1438,   596,   122,  1657,  1228,
    1195,  1495,   774,  1165,  1659,   892,  1165,  1320,  1166,  1521,
    1332,  1166,  1525,  1383,   296,   626,   626,  1229,   635,   505,
     818,   597,   300,   434,  1321,  1223,  1224,   597,  1646,  1652,
    1167,  1554,   636,   627,   627,   148,   594,   296,  1555,   595,
     878,  1283,   962,   505,  1096,   300,   947,   893,  1556,   947,
     601,  1225,   894,  1333,  1257,   628,  1618,   505,  1225,   436,
     727,   505,   505,   645,  1269,   124,  1646,   296,   296,  1223,
    1168,  1226,  1652,  1227,  1270,   300,   300,   447,  1226,   597,
    1227,  1325,   460,   505,  1271,   505,  1609,  1121,  1647,  1195,
    1612,  1223,   448,   505,   670,  1272,   505,   727,  1252,   449,
     505,  1228,  1388,  1122,  1393,   110,   452,   671,  1228,   560,
    1647,  1032,   110,   461,   561,  1117,   462,  1394,  1225,  1033,
    1396,  1393,   122,  1076,   946,  1076,  1118,  1310,  1311,   122,
     453,  1393,   395,  1397,  1528,  1270,  1137,   505,  1226,   419,
    1227,   459,  1407,   394,  1656,  1138,   696,  1552,  1553,  1412,
    1312,   697,  1165,  1549,  1374,  1628,  1076,  1166,   445,  1182,
     148,   446,   704,   704,   568,   505,  1654,   148,  1228,  1262,
     647,   648,   110,   989,   990,  1110,  1111,  1112,  1620,   506,
    1621,  1113,  1226,  1076,  1227,   863,   509,   505,   863,   122,
     893,   863,   507,  1648,   653,   894,  1107,  1108,  1076,   656,
    1076,   554,   450,   555,  1226,   451,  1227,   510,   557,  1531,
     558,  1636,  1228,  1058,   521,  1679,   505,   505,   505,   505,
    1429,  1430,  1058,   688,   689,   690,  1236,   148,  1237,  1241,
     522,  1242,   523,  1058,  1228,   843,   844,   538,  1660,   539,
     850,   851,  1084,  1084,  1428,   852,   853,   546,  1616,  1617,
    1372,  1566,  1567,  1670,   505,  1673,   879,   880,   881,   882,
     883,   884,   885,   886,   887,   888,   547,   548,   505,   550,
     553,   556,   559,   562,   563,  1280,   564,   566,   565,   567,
     570,   588,   607,   589,   637,   606,   625,   638,   639,   504,
     640,   649,   657,   505,   658,   659,   660,   296,   661,   463,
     678,   681,   505,   520,   505,   300,   662,   691,   505,   680,
     695,   608,   721,   716,   705,   717,  1658,   727,   730,   609,
     610,   505,   611,   738,   739,   740,   537,   751,   829,   757,
     612,   758,   766,   425,   613,   764,   614,  1032,   542,   775,
     545,   615,   429,   782,   784,  1033,   446,   451,   462,  1508,
     772,   296,   296,   296,   505,   768,   505,   769,   616,   300,
     300,   300,   419,   770,   785,   793,   810,   788,   803,   825,
     826,   797,   842,   827,   798,   855,   828,   854,   856,   857,
     868,   617,   618,   619,   620,   621,   622,   877,  1058,   874,
     899,   903,   704,   875,   900,   904,   925,   926,   927,   929,
     934,   935,   944,  1206,   936,   931,   937,   959,   938,  1547,
     965,   966,   505,   976,   969,   977,   978,  1020,   987,   979,
     984,   988,  1022,  1025,  1040,  1026,  1046,  1050,  1100,  1119,
     894,  1021,   946,   505,  1136,  1120,  1141,  1150,  1144,  1142,
    1157,  1151,  1153,  1177,   723,  1178,  1179,  1180,  1185,  1164,
    1183,  1190,  1184,  1191,   296,  1194,  1195,  1207,  1514,  1345,
    1201,  1208,   300,  1209,  1214,  1213,  1219,  1235,  1249,  1258,
    1277,  1256,   684,  1279,  1422,  1423,  1424,  1253,  1307,  1303,
    1323,  1182,  1304,  1254,  1255,  1315,  1316,  1318,  1284,   296,
     663,  1330,  1335,  1343,  1329,  1344,  1339,   300,  1346,  1348,
     296,  1356,  1358,  1365,  1366,  1379,  1362,  1370,   300,  1375,
    1378,  1364,   505,  1393,  1406,   505,  1340,  1409,  1270,   296,
    1347,  1415,  1414,  1416,  1400,  1349,  1350,   300,  1399,  1401,
     505,  1417,  1402,  1419,  1435,  1421,  1418,  1404,   296,   505,
    1439,  1442,  1458,  1452,  1463,  1465,   300,  1459,  1471,   395,
    1474,   504,  1480,   505,   504,  1485,  1472,  1473,  1487,  1505,
     394,  1491,  1489,   505,  1493,  1498,  1032,  1032,  1506,  1507,
    1483,  1510,  1560,  1527,  1033,  1033,  1590,  1511,  1562,  1516,
    1519,  1532,  1526,  1571,  1548,  1563,  1561,  1594,  1514,  1121,
    1596,   505,  1576,  1584,  1587,   395,  1589,  1604,  1595,  1611,
    1599,  1603,  1622,  1613,  1623,  1625,   394,  1626,  1630,  1635,
    1624,   505,  1637,  1638,   395,  1666,  1639,  1653,  1655,  1675,
     505,   675,  1669,   505,   679,   394,  1674,  1678,   542,  1583,
    1681,   693,   694,   704,  1631,  1667,  1682,  1686,  1689,   542,
    1690,  1695,  1705,  1701,  1410,   715,   901,   569,   720,  1704,
    1692,  1664,  1328,   571,   572,  1102,   737,  1696,  1702,   701,
     666,   801,   542,   745,   746,   749,  1176,  1342,  1633,   575,
     755,  1684,  1662,  1351,  1596,  1693,  1037,   505,   762,  1698,
    1173,  1707,   974,  1369,  1372,  1503,  1437,  1268,  1431,  1434,
     765,  1380,  1384,  1390,  1398,   833,   832,   296,  1408,   870,
    1004,   505,   643,  1680,  1677,   300,  1085,  1337,  1149,  1671,
    1420,  1426,  1327,  1425,  1559,  1453,  1457,  1282,  1558,  1306,
    1456,  1126,  1336,   763,  1482,  1568,  1454,   505,   505,     0,
       0,     0,     0,     0,     0,     0,     0,   749,     0,     0,
    1687,     0,     0,     0,     0,     0,   771,     0,     0,     0,
       0,     0,     0,   505,     0,   505,     0,     0,   505,     0,
       0,  1687,     0,     0,     0,  1615,  1671,     0,     0,   505,
       0,     0,     0,     0,   505,     0,     0,     0,   796,     0,
       0,  1619,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   710,     0,     0,     0,     0,     0,   711,     0,     0,
       0,     0,     0,     0,     0,  1032,     0,     0,     0,     0,
       0,     0,     0,  1033,     0,     0,  1032,  1032,     0,   296,
       0,     0,     0,     0,  1033,  1033,  1032,   300,     0,     0,
       0,     0,     0,     0,  1033,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   542,     0,     0,     0,     0,     0,     0,
       0,     0,   505,     0,   505,     0,   505,     0,     0,     0,
       0,     0,     0,   505,     0,     0,     0,   898,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   928,     0,  1032,     0,   932,   933,     0,     0,     0,
       0,  1033,     0,  1032,   505,     0,   505,     0,     0,     0,
       0,  1033,     0,     0,     0,     0,     0,   952,     0,   958,
       0,     0,   505,     0,     0,   505,     0,   542,   296,     0,
     542,     0,     0,     0,   972,     0,   300,   505,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   505,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   296,
       0,     0,     0,     0,   505,     0,     0,   300,     0,     0,
       0,  1003,   505,     0,     0,     0,     0,   505,     0,   505,
    1032,   505,     0,     0,     0,  1032,     0,     0,  1033,     0,
       0,     0,     0,  1033,     0,     0,     0,     0,     0,   504,
       0,     0,     0,     0,     0,     0,     0,     0,   505,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1045,     0,     0,   505,     0,     0,     0,   505,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   505,     0,     0,   505,     0,     0,
    1081,  1081,  1081,  1081,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   786,   787,     0,   789,   790,   791,   792,  1081,     0,
       0,     0,   799,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1114,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   824,     0,     0,     0,     0,
       0,     0,     0,   830,   831,     0,     0,  1140,     0,     0,
       0,     0,     0,     0,     0,     0,  1147,     0,  1147,     0,
       0,     0,  1081,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1081,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   865,     0,     0,     0,   865,     0,   755,     0,
     755,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   930,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1278,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   973,  1081,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   998,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   830,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   720,     0,     0,  1354,
       0,     0,     0,     0,  1047,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1368,     0,     0,     0,     0,     0,
       0,     0,     0,  1081,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   749,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1081,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1103,     0,     0,     0,  1411,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   796,     0,     0,     0,     0,
       0,     0,     0,     0,   504,     0,  1139,   504,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1154,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1187,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1192,  1193,
       0,  1081,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1212,     0,     0,  1215,     0,     0,     0,
       0,     0,     0,     0,     0,  1488,     0,     0,     0,     0,
    1238,  1239,  1240,     0,  1243,  1244,  1245,  1246,  1247,  1248,
       0,  1250,  1251,     0,     0,     0,     0,     0,     0,     0,
       0,  1501,  1502,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1047,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1518,     0,  1081,
       0,     0,  1081,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1530,     0,     0,     0,     0,  1534,     0,
       0,     0,     0,     0,     0,  1324,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1355,     0,  1357,     0,  1359,     0,     0,  1363,
       0,     0,     0,     0,  1367,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1373,     0,     0,     0,
       0,     0,     0,     0,     0,  1377,  1598,     0,  1600,     0,
    1602,  1381,  1382,     0,     0,     0,     0,  1610,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1403,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1081,     0,
    1081,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1629,     0,     0,  1632,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1081,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1640,     0,     0,  1047,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1081,     0,
       0,     0,     0,     0,     0,     0,  1665,     0,     0,     0,
       0,  1668,     0,  1081,     0,  1081,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1685,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1691,  1492,
       0,     0,  1694,  1494,     0,     0,     0,  1497,     0,  1499,
       0,  1500,     0,     0,     0,     0,     0,  1504,  1703,     0,
       0,  1706,     0,     0,     0,  1509,     0,     0,     0,     0,
       0,     0,     0,  1513,  1515,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1373,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1535,  1536,  1537,  1538,  1539,     0,  1540,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1585,     0,  1586,     0,     0,  1588,     0,     0,     0,     0,
       0,     0,     0,  1591,     0,     0,     0,     0,  1593,  1515,
       0,     0,     0,     0,     0,     0,  1597,     0,     0,     0,
    1601,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1634,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1597,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1672,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1683,     0,     0,     0,     0,  1688,     0,     0,     1,
       2,  1672,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     9,    10,  1688,    11,     0,     0,
    1697,    12,    13,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,    74,    75,    76,
       0,     0,    77,    78,     0,     0,     0,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,     0,     0,
       0,    90,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,    96,    97,    98,    99,   100,     0,     0,     0,
       0,     0,     0,   101,   102,   103,   104,   105,   106,   107,
     108,     0,     0,   109,   110,   111,   112,   113,     0,     0,
       0,     0,   114,   115,   116,   117,   118,   119,   120,   121,
       0,   122,     0,   123,   124,     0,     0,   125,   126,   127,
       0,     0,     0,   128,     0,   129,   130,     0,   131,   132,
     133,     0,   134,     0,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,     0,     0,   146,   147,   148,
       0,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,     0,   192,   193,   194,     0,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,     1,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     9,    10,     0,    11,     0,     0,     0,   389,
     390,     0,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,   391,    28,    29,    30,    31,
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,     0,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,     0,
      69,    70,    71,    72,    73,    74,    75,    76,     0,     0,
      77,    78,     0,     0,     0,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,     0,     0,     0,    90,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
      96,    97,    98,    99,   100,     0,     0,     0,     0,     0,
       0,   101,   102,   103,   104,   105,   106,   107,   108,     0,
       0,   109,   110,   111,   112,   113,     0,     0,     0,     0,
     114,   115,   116,   117,   118,   119,   120,   121,     0,   122,
       0,   123,   124,     0,     0,   125,   126,   127,     0,   524,
       0,   128,     0,   129,   130,     0,   131,   132,   133,     0,
     134,     0,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,     0,     0,   146,   147,   148,     0,   392,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,     0,   192,   193,   194,     0,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,     1,     2,     0,     0,     0,     0,
       0,     0,     0,     3,     4,     5,     6,     7,     8,     9,
      10,     0,    11,     0,     0,     0,   389,   390,     0,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,   391,    28,    29,    30,    31,     0,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,     0,    45,    46,    47,    48,    49,    50,    51,    52,
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
       0,     0,   125,   126,   127,     0,   767,     0,   128,     0,
     129,   130,     0,   131,   132,   133,     0,   134,     0,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
       0,     0,   146,   147,   148,     0,   392,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,     0,
     192,   193,   194,     0,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,     1,     2,     0,     0,     0,     0,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     9,    10,     0,    11,
       0,     0,     0,   389,   390,     0,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,  1028,   391,
      28,    29,    30,    31,     0,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,     0,    45,
      46,    47,  1029,  1030,    50,    51,    52,    53,    54,    55,
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
     126,   127,     0,   767,     0,   128,     0,   129,   130,     0,
     131,   132,   133,     0,   134,     0,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,     0,     0,   146,
     147,   148,     0,   392,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,  1031,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,     0,   192,   193,   194,
       0,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,     1,     2,
       0,     0,     0,     0,     0,     0,     0,     3,     4,     5,
       6,     7,     8,     9,    10,     0,    11,     0,     0,     0,
     389,   390,     0,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,  1028,   391,    28,    29,    30,
      31,     0,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,     0,    45,    46,    47,  1029,
    1030,    50,    51,    52,    53,    54,    55,    56,    57,    58,
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
     524,     0,   128,     0,   129,   130,     0,   131,   132,   133,
       0,   134,     0,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,     0,     0,   146,   147,   148,     0,
     392,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,  1031,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,     0,   192,   193,   194,     0,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,     0,     0,     0,   389,   390,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,   391,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,    74,    75,    76,     0,     0,    77,    78,
       0,     0,     0,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,     0,     0,     0,    90,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,    96,    97,
      98,    99,   100,     0,     0,     0,     0,     0,     0,   101,
     102,   103,   104,   105,   106,   107,   108,     0,     0,   109,
     110,   111,   112,   113,     0,     0,     0,     0,   114,   115,
     116,   117,   118,   119,   120,   121,     0,   122,     0,   123,
     124,     0,     0,   125,   126,   127,     0,     0,     0,   128,
       0,   129,   130,     0,   131,   132,   133,     0,   134,     0,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,     0,     0,   146,   147,   148,     0,   392,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
       0,   192,   193,   194,     0,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,     1,     2,     0,     0,     0,     0,     0,     0,
       0,     3,     4,     5,     6,     7,     8,     9,    10,     0,
      11,     0,     0,     0,    12,    13,     0,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,     0,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,     0,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
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
     146,   147,   148,     0,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,     0,   192,   193,
     194,     0,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,     0,     0,
       0,    12,    13,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,    74,    75,    76,
       0,     0,    77,    78,     0,     0,     0,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,     0,     0,
       0,    90,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,    96,    97,    98,    99,   100,     0,     0,     0,
       0,     0,     0,   101,   102,   103,   104,   105,   106,   107,
     108,     0,     0,   109,   110,   111,   112,   113,     0,     0,
       0,     0,   114,   115,   116,   117,   118,   119,   120,   121,
       0,   122,     0,   123,   124,     0,     0,   125,   126,   127,
       0,     0,     0,   128,     0,   129,   130,     0,   131,   132,
     133,     0,   134,     0,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,     0,     0,   146,   147,   148,
       0,   392,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,     0,   192,   193,   194,     0,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,     1,     2,     0,     0,
       0,     0,     0,     0,     0,     3,     4,     5,     6,     7,
       8,     9,    10,     0,    11,     0,     0,     0,    12,   390,
       0,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,     0,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,     0,    45,    46,    47,    48,    49,    50,
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
     144,   145,     0,     0,   146,   147,   148,     0,   392,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,     0,   192,   193,   194,     0,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     9,    10,
       0,    11,     0,     0,     0,   817,   390,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,   391,    28,    29,    30,    31,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       0,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,    69,    70,    71,    72,
      73,    74,    75,    76,     0,     0,    77,    78,     0,     0,
       0,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,     0,     0,     0,    90,     0,    91,    92,    93,
      94,     0,    95,     0,     0,     0,    96,    97,    98,    99,
     100,     0,     0,     0,     0,     0,     0,   101,   102,   103,
     104,   105,   106,   107,   108,     0,     0,   109,   110,   111,
     112,   113,     0,     0,     0,     0,   114,   115,   116,   117,
     118,   119,   120,   121,     0,   122,     0,   123,   124,     0,
       0,   125,   126,   127,     0,     0,     0,   128,     0,   129,
     130,     0,   131,   132,   133,     0,   134,     0,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,     0,
       0,   146,   147,   148,     0,   392,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,     0,   192,
     193,   194,     0,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
       1,     2,     0,     0,     0,     0,     0,     0,     0,     3,
       4,     5,     6,     7,     8,     9,    10,     0,    11,     0,
       0,     0,   389,   390,     0,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,  1028,   391,    28,
      29,    30,    31,     0,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,     0,    45,    46,
      47,  1029,  1030,    50,    51,    52,    53,    54,    55,    56,
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
     148,     0,   392,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,  1031,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,     0,   192,   193,   194,     0,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,     1,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     0,     0,     0,    11,     0,     0,     0,   389,
     390,     0,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,   527,   391,    28,    29,    30,    31,
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,     0,    45,    46,    47,   528,   529,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,     0,
      69,    70,    71,    72,    73,    74,    75,    76,     0,     0,
      77,    78,     0,     0,     0,    79,    80,   481,    82,    83,
      84,    85,    86,   530,    88,    89,     0,     0,     0,    90,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
      96,    97,    98,    99,   100,     0,     0,     0,     0,     0,
       0,   101,   102,   103,   104,   105,   106,   107,   531,     0,
       0,   109,   110,   111,   112,   113,     0,     0,     0,     0,
     114,   115,   116,   117,   118,   119,   120,   121,     0,   122,
       0,   123,   124,     0,     0,   125,   126,   127,     0,     0,
       0,   128,   532,   129,   130,     0,   131,   132,   133,     0,
     134,     0,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,     0,     0,   146,   147,   148,     0,   392,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   498,   499,   500,   175,   176,   501,   533,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,     0,   192,   193,   194,     0,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,     1,     2,     0,     0,     0,     0,
       0,     0,     0,     3,     4,     5,     6,     7,     8,     0,
       0,     0,    11,     0,     0,     0,   389,   390,     0,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,   527,   391,    28,    29,    30,    31,     0,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,     0,    45,    46,    47,   528,   529,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,     0,    69,    70,    71,
      72,    73,    74,    75,    76,     0,     0,    77,    78,     0,
       0,     0,    79,    80,   481,    82,    83,    84,    85,    86,
     530,    88,    89,     0,     0,     0,    90,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,    96,    97,    98,
      99,   100,     0,     0,     0,     0,     0,     0,   101,   102,
     103,   104,   105,   106,   107,   531,     0,     0,   109,   110,
     111,   112,   113,     0,     0,     0,     0,   114,   115,   116,
     117,   118,   119,   120,   121,     0,   122,     0,   123,   124,
       0,     0,   125,   126,   127,     0,   858,     0,   128,     0,
     129,   130,     0,   131,   132,   133,     0,   134,     0,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
       0,     0,   146,   147,   148,     0,   392,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   498,
     499,   500,   175,   176,   501,   533,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,     0,
     192,   193,   194,     0,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,     1,     2,     0,     0,     0,     0,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     0,     0,     0,    11,
       0,     0,     0,   389,   390,     0,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,   527,   391,
      28,    29,    30,    31,     0,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,     0,    45,
      46,    47,   528,   529,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,     0,    69,    70,    71,    72,    73,    74,
      75,    76,     0,     0,    77,    78,     0,     0,     0,    79,
      80,   481,    82,    83,    84,    85,    86,   530,    88,    89,
       0,     0,     0,    90,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,    96,    97,    98,    99,   100,     0,
       0,     0,     0,     0,     0,   101,   102,   103,   104,   105,
     106,   107,   531,     0,     0,   109,   110,   111,   112,   113,
       0,     0,     0,     0,   114,   115,   116,   117,   118,   119,
     120,   121,     0,   122,     0,   123,   124,     0,     0,   125,
     126,   127,     0,     0,     0,   128,   864,   129,   130,     0,
     131,   132,   133,     0,   134,     0,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,     0,     0,   146,
     147,   148,     0,   392,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   498,   499,   500,   175,
     176,   501,   533,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,     0,   192,   193,   194,
       0,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,     1,     2,
       0,     0,     0,     0,     0,     0,     0,     3,     4,     5,
       6,     7,     8,     0,     0,     0,    11,     0,     0,     0,
     389,   390,     0,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,   527,   391,    28,    29,    30,
      31,     0,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,     0,    45,    46,    47,   528,
     529,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
       0,    69,    70,    71,    72,    73,    74,    75,    76,     0,
       0,    77,    78,     0,     0,     0,    79,    80,   481,    82,
      83,    84,    85,    86,   530,    88,    89,     0,     0,     0,
      90,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,    96,    97,    98,    99,   100,     0,     0,     0,     0,
       0,     0,   101,   102,   103,   104,   105,   106,   107,   531,
       0,     0,   109,   110,   111,   112,   113,     0,     0,     0,
       0,   114,   115,   116,   117,   118,   119,   120,   121,     0,
     122,     0,   123,   124,     0,     0,   125,   126,   127,     0,
       0,     0,   128,   869,   129,   130,     0,   131,   132,   133,
       0,   134,     0,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,     0,     0,   146,   147,   148,     0,
     392,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   498,   499,   500,   175,   176,   501,   533,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,     0,   192,   193,   194,     0,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       0,     0,     0,    11,     0,     0,     0,   389,   390,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
     467,    25,   469,   391,    28,   470,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,   472,     0,    45,    46,    47,   474,   475,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,    74,    75,    76,     0,     0,    77,    78,
       0,     0,     0,    79,    80,   481,    82,    83,    84,    85,
      86,   530,    88,    89,     0,     0,     0,    90,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,   484,    97,
      98,    99,   100,     0,     0,     0,     0,     0,     0,   101,
     102,   103,   104,   105,   106,   107,   531,     0,     0,   109,
     110,   641,   112,   113,     0,     0,     0,     0,   114,   115,
     116,   117,   118,   119,   120,   121,     0,   122,     0,   642,
     124,     0,     0,   125,   126,   127,     0,     0,     0,   128,
       0,   129,   130,     0,   131,   132,   133,     0,   134,     0,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,     0,     0,   146,   147,   148,     0,   392,   150,   151,
     152,   153,   154,   155,   156,   157,   493,   159,   494,   161,
     495,   496,   164,   165,   166,   167,   168,   169,   497,   171,
     498,   499,   500,   175,   176,   501,   502,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
       0,   192,   193,   194,     0,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,     1,     2,     0,     0,     0,     0,     0,     0,
       0,     3,     4,     5,     6,     7,     8,     0,     0,     0,
      11,     0,     0,     0,   389,   390,     0,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,   527,
     391,    28,    29,    30,    31,     0,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,     0,
      45,    46,    47,   528,   529,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,     0,    69,    70,    71,    72,    73,
      74,    75,    76,     0,     0,    77,    78,     0,     0,     0,
      79,    80,   481,    82,    83,    84,    85,    86,   530,    88,
      89,     0,     0,     0,    90,     0,    91,    92,    93,    94,
       0,    95,     0,     0,     0,    96,    97,    98,    99,   100,
       0,     0,     0,     0,     0,     0,   101,   102,   103,   104,
     105,   106,   107,   531,     0,     0,   109,   110,   111,   112,
     113,     0,     0,     0,     0,   114,   115,   116,   117,   118,
     119,   120,   121,     0,   122,     0,   123,   124,     0,     0,
     125,   126,   127,     0,     0,     0,   128,     0,   129,   130,
       0,   131,   132,   133,     0,   134,     0,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,     0,     0,
     146,   147,   148,     0,   392,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   498,   499,   500,
     175,   176,   501,   533,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,     0,   192,   193,
     194,     0,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     0,     0,     0,    11,     0,     0,
       0,   389,   390,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,   467,    25,   469,   391,    28,   470,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,   472,     0,    45,    46,    47,
     474,   475,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,    74,    75,    76,
       0,     0,    77,    78,     0,     0,     0,    79,    80,   481,
      82,    83,    84,    85,    86,   530,    88,    89,     0,     0,
       0,    90,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,   484,    97,    98,    99,   100,     0,     0,     0,
       0,     0,     0,   101,   102,   103,   104,   105,   106,   107,
     531,     0,     0,   109,   110,   111,   112,   113,     0,     0,
       0,     0,   114,   115,   116,   117,   118,   119,   120,   121,
       0,   122,     0,   123,   124,     0,     0,   125,   126,   127,
       0,     0,     0,   128,     0,   129,   130,     0,   131,   132,
     133,     0,   134,     0,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,     0,     0,   146,   147,   148,
       0,   392,   150,   151,   152,   153,   154,   155,   156,   157,
     493,   159,   494,   161,   495,   496,   164,   165,   166,   167,
     168,   169,   497,   171,   498,   499,   500,   175,   176,   501,
     502,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,     0,   192,   193,   194,     0,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,     1,     2,     0,     0,
       0,     0,     0,     0,     0,     3,     4,     5,     6,     7,
       8,     0,     0,     0,    11,     0,     0,     0,   389,   390,
       0,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,   467,    25,   469,   391,    28,   470,    30,    31,     0,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,   472,     0,    45,    46,    47,   474,   475,    50,
     476,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,     0,    69,
      70,    71,    72,    73,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,   481,    82,    83,    84,
      85,    86,   530,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,   484,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   531,     0,     0,
     109,   110,     0,   112,   113,     0,     0,     0,     0,   114,
     115,   116,   117,   118,   119,   120,   121,     0,   122,     0,
       0,     0,     0,     0,   125,   126,   127,     0,     0,     0,
     128,     0,   129,   130,     0,   131,   132,   133,     0,   134,
       0,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,     0,     0,   146,   147,   148,     0,   392,   150,
     151,   152,   153,   154,   155,   156,   157,   493,   159,   494,
     161,   495,   496,   164,   165,   166,   167,   168,   169,   497,
     171,   498,   499,   500,   175,   176,   501,   502,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,     0,   192,   193,   194,     0,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     0,     0,
       0,    11,     0,     0,     0,   389,   390,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,   467,    25,
     469,   391,    28,   470,    30,    31,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,   472,
       0,    45,    46,    47,   474,   475,    50,   476,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,    69,    70,    71,    72,
      73,    74,    75,    76,     0,     0,    77,    78,     0,     0,
       0,    79,    80,   481,    82,    83,    84,    85,    86,   530,
      88,    89,     0,     0,     0,    90,     0,    91,    92,    93,
      94,     0,    95,     0,     0,     0,   484,    97,    98,    99,
     100,     0,     0,     0,     0,     0,     0,   101,   102,   103,
     104,   105,   106,   107,   531,     0,     0,   109,   110,     0,
     112,   113,     0,     0,     0,     0,   114,   115,   116,   117,
     118,   119,   120,   121,     0,   122,     0,     0,     0,     0,
       0,   125,   126,   127,     0,     0,     0,   128,     0,   129,
     130,     0,     0,     0,   133,     0,   134,     0,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,     0,
       0,   146,   147,   148,     0,   392,   150,   151,   152,   153,
     154,   155,   156,   157,   493,   159,   494,   161,   495,   496,
     164,   165,   166,   167,   168,   169,   497,   171,   498,   499,
     500,   175,   176,   501,   502,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,     0,   192,
     193,   194,     0,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
       1,     2,     0,     0,     0,     0,     0,     0,     0,     3,
       0,     0,     0,     7,     8,     0,     0,     0,   463,     0,
       0,     0,   389,   390,     0,    14,    15,    16,   464,    18,
      19,    20,   465,    22,   466,   467,   468,   469,   391,    28,
     470,    30,    31,     0,    32,    33,    34,    35,   471,    37,
      38,    39,    40,    41,    42,    43,   472,     0,    45,   473,
      47,   474,   475,    50,   476,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,   477,
     478,    68,     0,    69,    70,    71,   479,     0,    74,    75,
      76,     0,     0,   480,    78,     0,     0,     0,     0,    80,
     481,    82,   482,   483,    85,    86,     0,     0,     0,     0,
       0,     0,     0,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,   484,    97,    98,   485,   486,     0,     0,
       0,     0,     0,     0,   101,   102,   103,     0,   105,   106,
     107,     0,     0,     0,     0,     0,     0,   112,   113,     0,
       0,     0,     0,   114,   115,   116,   117,   487,   119,   120,
     488,     0,     0,     0,     0,     0,     0,     0,   489,   490,
     127,     0,     0,     0,   128,     0,   129,   491,     0,     0,
       0,   133,     0,   134,     0,   135,   136,   137,   138,   492,
     140,   141,   142,   143,   144,   145,     0,     0,   146,   147,
       0,     0,   392,   150,   151,   152,   153,   154,   155,   156,
     157,   493,   159,   494,   161,   495,   496,   164,   165,   166,
     167,   168,   169,   497,   171,   498,   499,   500,   175,   176,
     501,   502,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,     0,   192,   193,   194,     0,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,     1,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     0,     0,     0,
       7,     8,     0,     0,     0,   463,     0,     0,     0,   389,
     390,     0,    14,    15,    16,   511,    18,    19,    20,   465,
     512,   513,   467,   468,   469,   391,    28,   470,    30,    31,
       0,    32,    33,    34,    35,   514,    37,   515,   516,    40,
      41,    42,    43,   472,     0,    45,   517,    47,   474,   475,
      50,   476,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,   477,   478,    68,     0,
      69,    70,    71,   518,     0,    74,    75,    76,     0,     0,
     480,    78,     0,     0,     0,     0,    80,   481,    82,   482,
     483,    85,    86,     0,     0,     0,     0,     0,     0,     0,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
     484,    97,    98,   485,   486,     0,     0,     0,     0,     0,
       0,   101,   102,   103,     0,   105,   106,   107,     0,     0,
       0,     0,     0,     0,   112,   113,     0,     0,     0,     0,
     114,   115,   116,   117,   487,   119,   120,   488,     0,     0,
       0,     0,     0,     0,     0,   489,   490,   127,     0,     0,
       0,   128,     0,   129,   491,     0,     0,     0,   133,     0,
     134,     0,   135,   136,   137,   138,   492,   140,   141,   142,
     143,   144,   145,     0,     0,   146,   147,     0,     0,   392,
     150,   151,   152,   153,   154,   155,   156,   157,   493,   519,
     494,   161,   495,   496,   164,   165,   166,   167,   168,   169,
     497,   171,   498,   499,   500,   175,   176,   501,   502,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,     0,   192,   193,   194,     0,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   540,     0,     0,     0,     0,     0,
       0,     0,     7,     8,     0,     0,     0,   742,     0,     0,
       0,   389,   390,     0,    14,    15,    16,   511,    18,    19,
      20,   465,   512,   513,   467,   468,   469,   391,    28,   470,
      30,    31,     0,    32,    33,    34,    35,   514,    37,   515,
     516,    40,    41,    42,    43,   472,     0,    45,   517,    47,
     474,   475,    50,   476,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,   477,   478,
      68,     0,    69,    70,    71,   518,     0,    74,    75,    76,
       0,     0,   480,    78,     0,     0,     0,     0,    80,   481,
      82,   482,   483,    85,    86,     0,     0,     0,     0,     0,
       0,     0,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,   484,    97,    98,   485,   486,     0,     0,     0,
       0,     0,     0,   101,   102,   103,     0,   105,   106,   107,
       0,     0,     0,     0,     0,     0,   112,   113,     0,     0,
       0,     0,   114,   115,   116,   117,   487,   119,   120,   488,
       0,     0,     0,     0,     0,     0,     0,   489,   490,   127,
       0,     0,     0,   128,   743,   129,   491,     0,     0,     0,
       0,     0,   134,     0,   135,   136,   137,   138,   492,   140,
     141,   142,   143,   144,   145,     0,     0,   146,   147,     0,
       0,   392,   150,   151,   152,   153,   154,   155,   156,   157,
     493,   519,   494,   161,   495,   496,   164,   165,   166,   167,
     168,   169,   497,   171,   498,   499,   500,   175,   176,   501,
     502,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,     0,   192,   193,   194,     0,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   540,     0,     0,     0,
       0,     0,     0,     0,     7,     8,     0,     0,     0,   463,
       0,     0,     0,   389,   390,     0,    14,    15,    16,   511,
      18,    19,    20,   465,   512,   513,   467,   468,   469,   391,
      28,   470,    30,    31,     0,    32,    33,    34,    35,   514,
      37,   515,   516,    40,    41,    42,    43,   472,     0,    45,
     517,    47,   474,   475,    50,   476,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
     477,   478,    68,     0,    69,    70,    71,   518,     0,    74,
      75,    76,     0,     0,   480,    78,     0,     0,     0,     0,
      80,   481,    82,   482,   483,    85,    86,     0,     0,     0,
       0,     0,     0,     0,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,   484,    97,    98,   485,   486,     0,
       0,     0,     0,     0,     0,   101,   102,   103,     0,   105,
     106,   107,     0,     0,     0,     0,     0,     0,   112,   113,
       0,     0,     0,     0,   114,   115,   116,   117,   487,   119,
     120,   488,     0,     0,     0,     0,     0,     0,     0,   489,
     490,   127,     0,     0,     0,   128,     0,   129,   491,     0,
       0,     0,     0,     0,   134,     0,   135,   136,   137,   138,
     492,   140,   141,   142,   143,   144,   145,     0,     0,   146,
     147,     0,     0,   392,   150,   151,   152,   153,   154,   155,
     156,   157,   493,   519,   494,   161,   495,   496,   164,   165,
     166,   167,   168,   169,   497,   171,   498,   499,   500,   175,
     176,   501,   502,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,     0,   192,   193,   194,
       0,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   543,   544,
       0,     0,     0,     0,     7,     8,     0,     0,     0,   463,
       0,     0,     0,   389,   390,     0,    14,    15,    16,   511,
      18,    19,    20,   465,   512,   513,   467,   468,   469,   391,
      28,   470,    30,    31,     0,    32,    33,    34,    35,   514,
      37,   515,   516,    40,    41,    42,    43,   472,     0,    45,
     517,    47,   474,   475,    50,   476,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
     477,   478,    68,     0,    69,    70,    71,   518,     0,    74,
      75,    76,     0,     0,   480,    78,     0,     0,     0,     0,
      80,   481,    82,   482,   483,    85,    86,     0,     0,     0,
       0,     0,     0,     0,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,   484,    97,    98,   485,   486,     0,
       0,     0,     0,     0,     0,   101,   102,   103,     0,   105,
     106,   107,     0,     0,     0,     0,     0,     0,   112,   113,
       0,     0,     0,     0,   114,   115,   116,   117,   487,   119,
     120,   488,     0,     0,     0,     0,     0,     0,     0,   489,
     490,   127,     0,     0,     0,   128,     0,   129,   491,     0,
       0,     0,     0,     0,   134,     0,   135,   136,   137,   138,
     492,   140,   141,   142,   143,   144,   145,     0,     0,   146,
     147,     0,     0,   392,   150,   151,   152,   153,   154,   155,
     156,   157,   493,   519,   494,   161,   495,   496,   164,   165,
     166,   167,   168,   169,   497,   171,   498,   499,   500,   175,
     176,   501,   502,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,     0,   192,   193,   194,
       0,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,     7,     8,
       0,     0,     0,   463,     0,     0,     0,   389,   390,     0,
      14,    15,    16,   464,    18,    19,    20,   465,    22,   466,
     467,  1069,   469,   391,    28,   470,    30,    31,     0,    32,
      33,    34,    35,   471,    37,    38,    39,    40,    41,    42,
      43,   472,     0,    45,   473,    47,   474,   475,    50,   476,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,   477,   478,    68,     0,    69,    70,
      71,   479,     0,    74,    75,    76,     0,     0,   480,    78,
       0,     0,     0,     0,    80,   481,    82,   482,   483,    85,
      86,     0,     0,     0,     0,     0,     0,     0,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,   484,    97,
      98,   485,   486,     0,     0,     0,     0,     0,     0,   101,
     102,   103,     0,   105,   106,  1070,     0,     0,     0,  1071,
       0,     0,   112,   113,     0,     0,     0,     0,   114,   115,
     116,   117,   487,   119,   120,   488,     0,     0,     0,     0,
       0,     0,     0,   489,   490,   127,     0,     0,     0,   128,
    1467,   129,   491,     0,     0,     0,  1468,     0,   134,     0,
     135,   136,   137,   138,   492,   140,   141,   142,   143,   144,
     145,     0,     0,  1072,   147,     0,     0,   392,   150,   151,
     152,   153,   154,   155,   156,   157,   493,   159,   494,   161,
     495,   496,   164,   165,   166,   167,   168,   169,   497,   171,
     498,   499,   500,   175,   176,   501,   502,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
       0,   192,   193,   194,     0,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,     7,     8,     0,     0,     0,   463,     0,     0,
       0,   389,   390,     0,    14,    15,    16,   511,    18,    19,
      20,   465,   512,   513,   467,   468,   469,   391,    28,   470,
      30,    31,     0,    32,    33,    34,    35,   514,    37,   515,
     516,    40,    41,    42,    43,   472,     0,    45,   517,    47,
     474,   475,    50,   476,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,   477,   478,
      68,     0,    69,    70,    71,   518,     0,    74,    75,    76,
       0,     0,   480,    78,     0,     0,     0,     0,    80,   481,
      82,   482,   483,    85,    86,     0,     0,     0,     0,     0,
       0,     0,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,   484,    97,    98,   485,   486,     0,     0,     0,
       0,     0,     0,   101,   102,   103,     0,   105,   106,   107,
       0,     0,     0,     0,     0,     0,   112,   113,     0,     0,
       0,     0,   114,   115,   116,   117,   487,   119,   120,   488,
       0,     0,     0,     0,     0,     0,     0,   489,   490,   127,
       0,     0,     0,   128,   713,   129,   491,     0,     0,     0,
     714,     0,   134,     0,   135,   136,   137,   138,   492,   140,
     141,   142,   143,   144,   145,     0,     0,   146,   147,     0,
       0,   392,   150,   151,   152,   153,   154,   155,   156,   157,
     493,   519,   494,   161,   495,   496,   164,   165,   166,   167,
     168,   169,   497,   171,   498,   499,   500,   175,   176,   501,
     502,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,     0,   192,   193,   194,     0,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,     7,     8,     0,     0,
       0,   463,     0,     0,     0,   389,   390,     0,    14,    15,
      16,   511,    18,    19,    20,   465,   512,   513,   467,   468,
     469,   391,    28,   470,    30,    31,     0,    32,    33,    34,
      35,   514,    37,   515,   516,    40,    41,    42,    43,   472,
       0,    45,   517,    47,   474,   475,    50,   476,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,   477,   478,    68,     0,    69,    70,    71,   518,
       0,    74,    75,    76,     0,     0,   480,    78,     0,     0,
       0,     0,    80,   481,    82,   482,   483,    85,    86,     0,
       0,     0,     0,     0,     0,     0,     0,    91,    92,    93,
      94,     0,    95,     0,     0,     0,   484,    97,    98,   485,
     486,     0,     0,     0,     0,     0,     0,   101,   102,   103,
       0,   105,   106,   107,     0,     0,     0,     0,     0,     0,
     112,   113,     0,     0,     0,     0,   114,   115,   116,   117,
     487,   119,   120,   488,     0,     0,     0,     0,     0,     0,
       0,   489,   490,   127,     0,     0,     0,   128,   760,   129,
     491,     0,     0,     0,   761,     0,   134,     0,   135,   136,
     137,   138,   492,   140,   141,   142,   143,   144,   145,     0,
       0,   146,   147,     0,     0,   392,   150,   151,   152,   153,
     154,   155,   156,   157,   493,   519,   494,   161,   495,   496,
     164,   165,   166,   167,   168,   169,   497,   171,   498,   499,
     500,   175,   176,   501,   502,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,     0,   192,
     193,   194,     0,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
       7,     8,     0,     0,     0,   463,     0,     0,     0,   389,
     390,     0,    14,    15,    16,   464,    18,    19,    20,   465,
      22,   466,   467,  1069,   469,   391,    28,   470,    30,    31,
       0,    32,    33,    34,    35,   471,    37,    38,    39,    40,
      41,    42,    43,   472,     0,    45,   473,    47,   474,   475,
      50,   476,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,   477,   478,    68,     0,
      69,    70,    71,   479,     0,    74,    75,    76,     0,     0,
     480,    78,     0,     0,     0,     0,    80,   481,    82,   482,
     483,    85,    86,  1391,     0,     0,     0,     0,     0,     0,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
     484,    97,    98,   485,   486,     0,     0,     0,     0,     0,
       0,   101,   102,   103,     0,   105,   106,  1070,     0,     0,
       0,  1071,     0,     0,   112,   113,     0,     0,     0,     0,
     114,   115,   116,   117,   487,   119,   120,   488,     0,     0,
       0,     0,     0,     0,     0,   489,   490,   127,     0,     0,
       0,   128,     0,   129,   491,     0,     0,     0,     0,     0,
     134,     0,   135,   136,   137,   138,   492,   140,   141,   142,
     143,   144,   145,     0,     0,  1072,   147,     0,     0,   392,
     150,   151,   152,   153,   154,   155,   156,   157,   493,   159,
     494,   161,   495,   496,   164,   165,   166,   167,   168,   169,
     497,   171,   498,   499,   500,   175,   176,   501,   502,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,     0,   192,   193,   194,     0,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,     7,     8,     0,     0,     0,   463,
       0,     0,     0,   389,   390,     0,    14,    15,    16,   464,
      18,    19,    20,   465,    22,   466,   467,  1069,   469,   391,
      28,   470,    30,    31,     0,    32,    33,    34,    35,   471,
      37,    38,    39,    40,    41,    42,    43,   472,     0,    45,
     473,    47,   474,   475,    50,   476,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
     477,   478,    68,     0,    69,    70,    71,   479,     0,    74,
      75,    76,     0,     0,   480,    78,     0,     0,     0,     0,
      80,   481,    82,   482,   483,    85,    86,  1520,     0,     0,
       0,     0,     0,     0,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,   484,    97,    98,   485,   486,     0,
       0,     0,     0,     0,     0,   101,   102,   103,     0,   105,
     106,  1070,     0,     0,     0,  1071,     0,     0,   112,   113,
       0,     0,     0,     0,   114,   115,   116,   117,   487,   119,
     120,   488,     0,     0,     0,     0,     0,     0,     0,   489,
     490,   127,     0,     0,     0,   128,     0,   129,   491,     0,
       0,     0,     0,     0,   134,     0,   135,   136,   137,   138,
     492,   140,   141,   142,   143,   144,   145,     0,     0,  1072,
     147,     0,     0,   392,   150,   151,   152,   153,   154,   155,
     156,   157,   493,   159,   494,   161,   495,   496,   164,   165,
     166,   167,   168,   169,   497,   171,   498,   499,   500,   175,
     176,   501,   502,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,     0,   192,   193,   194,
       0,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,     7,     8,
       0,     0,     0,   463,     0,     0,     0,   389,   390,     0,
      14,    15,    16,   464,    18,    19,    20,   465,    22,   466,
     467,  1069,   469,   391,    28,   470,    30,    31,     0,    32,
      33,    34,    35,   471,    37,    38,    39,    40,    41,    42,
      43,   472,     0,    45,   473,    47,   474,   475,    50,   476,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,   477,   478,    68,     0,    69,    70,
      71,   479,     0,    74,    75,    76,     0,     0,   480,    78,
       0,     0,     0,     0,    80,   481,    82,   482,   483,    85,
      86,  1524,     0,     0,     0,     0,     0,     0,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,   484,    97,
      98,   485,   486,     0,     0,     0,     0,     0,     0,   101,
     102,   103,     0,   105,   106,  1070,     0,     0,     0,  1071,
       0,     0,   112,   113,     0,     0,     0,     0,   114,   115,
     116,   117,   487,   119,   120,   488,     0,     0,     0,     0,
       0,     0,     0,   489,   490,   127,     0,     0,     0,   128,
       0,   129,   491,     0,     0,     0,     0,     0,   134,     0,
     135,   136,   137,   138,   492,   140,   141,   142,   143,   144,
     145,     0,     0,  1072,   147,     0,     0,   392,   150,   151,
     152,   153,   154,   155,   156,   157,   493,   159,   494,   161,
     495,   496,   164,   165,   166,   167,   168,   169,   497,   171,
     498,   499,   500,   175,   176,   501,   502,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
       0,   192,   193,   194,     0,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,     7,     8,     0,     0,     0,   463,     0,     0,
       0,   389,   390,     0,    14,    15,    16,   464,    18,    19,
      20,   465,    22,   466,   467,  1069,   469,   391,    28,   470,
      30,    31,     0,    32,    33,    34,    35,   471,    37,    38,
      39,    40,    41,    42,    43,   472,     0,    45,   473,    47,
     474,   475,    50,   476,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,   477,   478,
      68,     0,    69,    70,    71,   479,     0,    74,    75,    76,
       0,     0,   480,    78,     0,     0,     0,     0,    80,   481,
      82,   482,   483,    85,    86,     0,     0,     0,     0,     0,
       0,     0,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,   484,    97,    98,   485,   486,     0,     0,     0,
       0,     0,     0,   101,   102,   103,     0,   105,   106,  1070,
       0,     0,     0,  1071,     0,     0,   112,   113,     0,     0,
       0,     0,   114,   115,   116,   117,   487,   119,   120,   488,
       0,     0,     0,     0,     0,     0,     0,   489,   490,   127,
       0,     0,     0,   128,     0,   129,   491,     0,     0,     0,
       0,     0,   134,     0,   135,   136,   137,   138,   492,   140,
     141,   142,   143,   144,   145,     0,     0,  1072,   147,     0,
       0,   392,   150,   151,   152,   153,   154,   155,   156,   157,
     493,   159,   494,   161,   495,   496,   164,   165,   166,   167,
     168,   169,   497,   171,   498,   499,   500,   175,   176,   501,
     502,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,     0,   192,   193,   194,     0,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,     7,     8,     0,     0,
       0,   463,     0,     0,     0,   389,   390,     0,    14,    15,
      16,   464,    18,    19,    20,   465,    22,   466,   467,  1069,
     469,   391,    28,   470,    30,    31,     0,    32,    33,    34,
      35,   471,    37,    38,    39,    40,    41,    42,    43,   472,
       0,    45,   473,    47,   474,   475,    50,   476,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,   477,   478,    68,     0,    69,    70,    71,   479,
       0,    74,    75,    76,     0,     0,   480,    78,     0,     0,
       0,     0,    80,   481,    82,   482,   483,    85,    86,     0,
       0,     0,     0,     0,     0,     0,     0,    91,    92,    93,
      94,     0,    95,     0,     0,     0,   484,    97,    98,   485,
     486,     0,     0,     0,     0,     0,     0,   101,   102,   103,
       0,   105,   106,  1070,     0,     0,     0,  1071,     0,     0,
     112,   113,     0,     0,     0,     0,   114,   115,   116,   117,
     487,   119,   120,   488,     0,     0,     0,     0,     0,     0,
       0,   489,   490,   127,     0,     0,     0,   128,     0,   129,
     491,     0,     0,     0,     0,     0,   134,     0,   135,   136,
     137,   138,   492,   140,   141,   142,   143,   144,   145,     0,
       0,   146,   147,     0,     0,   392,   150,   151,   152,   153,
     154,   155,   156,   157,   493,   159,   494,   161,   495,   496,
     164,   165,   166,   167,   168,   169,   497,   171,   498,   499,
     500,   175,   176,   501,   502,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,     0,   192,
     193,   194,     0,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
       7,     8,     0,     0,     0,   463,     0,     0,     0,   389,
     390,     0,    14,    15,    16,   511,    18,    19,    20,   465,
     512,   513,   467,   468,   469,   391,    28,   470,    30,    31,
       0,    32,    33,    34,    35,   514,    37,   515,   516,    40,
      41,    42,    43,   472,     0,    45,   517,    47,   474,   475,
      50,   476,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,   477,   478,    68,     0,
      69,    70,    71,   518,     0,    74,    75,    76,     0,     0,
     480,    78,     0,     0,     0,     0,    80,   481,    82,   482,
     483,    85,    86,     0,     0,     0,     0,     0,     0,     0,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
     484,    97,    98,   485,   486,     0,     0,     0,     0,     0,
       0,   101,   102,   103,     0,   105,   106,   107,     0,     0,
       0,     0,     0,     0,   112,   113,     0,     0,     0,     0,
     114,   115,   116,   117,   487,   119,   120,   488,     0,     0,
       0,     0,     0,     0,     0,   489,   490,   127,     0,     0,
       0,   128,     0,   129,   491,     0,     0,     0,     0,     0,
     134,     0,   135,   136,   137,   138,   492,   140,   141,   142,
     143,   144,   145,     0,     0,   146,   147,     0,     0,   392,
     150,   151,   152,   153,   154,   155,   156,   157,   493,   519,
     494,   161,   495,   496,   164,   165,   166,   167,   168,   169,
     497,   171,   498,   499,   500,   175,   176,   501,   502,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,     0,   192,   193,   194,     0,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,     7,     8,     0,     0,     0,   463,
       0,     0,     0,   389,   390,     0,    14,    15,    16,     0,
      18,    19,    20,   465,     0,     0,   467,   468,     0,   391,
      28,   470,    30,    31,     0,    32,    33,    34,    35,     0,
      37,     0,     0,    40,    41,    42,    43,   472,     0,    45,
       0,    47,     0,     0,    50,   476,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
     477,   478,    68,     0,    69,    70,    71,     0,     0,    74,
      75,    76,     0,     0,   480,    78,     0,     0,     0,     0,
      80,   481,    82,   482,   483,    85,    86,     0,     0,     0,
       0,     0,     0,     0,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,   484,    97,    98,   485,   486,     0,
       0,     0,     0,     0,     0,   101,   102,   103,     0,   105,
     106,     0,     0,     0,     0,     0,     0,     0,   112,   113,
       0,     0,     0,     0,   114,   115,   116,   117,   487,   119,
     120,   488,     0,     0,     0,     0,     0,     0,     0,   489,
     490,   127,     0,     0,     0,   128,     0,   129,   491,     0,
       0,     0,     0,     0,   134,     0,   135,   136,   137,   138,
     492,   140,   141,   142,   143,   144,   145,     0,     0,     0,
     147,     0,     0,   392,   150,   151,   152,   153,   154,   155,
     156,   157,   493,     0,   494,   161,   495,   496,   164,   165,
     166,   167,   168,   169,   497,   171,   498,   499,   500,   175,
     176,     0,   502,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,     0,   192,   193,   194,
       0,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         0,   178,   720,   737,     4,     5,     6,   300,     0,     4,
       5,     6,     4,     5,     6,   749,   628,   985,   398,   399,
     109,   803,   776,   327,    12,   132,  1202,   580,   581,   763,
     629,   630,   631,   632,   249,   248,  1218,  1274,  1275,  1055,
     720,   280,    26,    27,   842,   969,    73,  1136,   412,   264,
     578,   579,   578,   579,   580,   581,    26,    27,  1007,   423,
      36,   892,    36,    47,   400,    55,   674,    37,    38,    30,
      40,    41,    56,    26,    27,   117,   876,    47,     1,    29,
       1,     8,   446,  1231,     1,   117,    56,    57,     1,     1,
      74,    76,  1485,     1,    47,    79,   271,     1,  1307,     4,
       5,     6,   438,   439,    74,   854,   855,    29,   108,    79,
       4,     5,     6,   146,   117,   106,   108,   106,    94,   106,
      96,    74,    96,   135,    93,    73,   110,   111,   112,   608,
     152,   610,   611,   106,   613,    94,   615,   152,   106,    87,
     110,   111,   112,   892,   623,   624,   261,   215,   130,   106,
      99,   129,   117,    33,    29,    99,   395,   272,   111,   109,
     141,   855,   110,    45,   898,   181,    96,   152,   147,    49,
     146,   105,   146,   123,   122,   146,   124,   926,   194,   199,
      62,   223,   141,   186,   252,   164,   208,   199,   208,   159,
     112,   280,   126,   208,  1431,   184,   187,   946,   148,    45,
      99,    47,   152,   108,    94,   155,    94,   189,    37,    38,
     959,    40,    41,   182,   108,   183,   189,   195,   952,    54,
     185,    56,    96,   330,   958,   215,   176,    96,    57,  1405,
     187,  1199,  1625,   951,   219,   220,   185,   159,   271,   271,
    1071,   185,   242,   536,   419,   245,   233,   174,   218,  1003,
     242,   212,   946,   245,  1343,   808,   809,  1055,  1056,   105,
    1408,  1185,   252,   305,    99,   959,   189,  1283,   189,   949,
     878,   951,   189,  1222,    29,  1484,   189,   189,   806,   807,
     280,   189,  1231,   112,   159,   189,   185,   526,   280,   259,
     271,   971,     5,   657,   168,   271,     9,   271,  1098,   168,
     271,   285,    52,   106,   186,   106,   395,   257,   335,   293,
      96,   338,   117,    39,    45,   285,    47,   301,    44,    45,
     120,   167,  1071,   293,   254,   255,   216,   217,   216,   217,
     159,   301,   285,    59,   147,    61,    62,    26,    27,   428,
     293,   231,  1579,   231,    70,   106,   129,   436,    79,   685,
     152,   164,    24,   155,   109,   106,   445,   596,    94,   838,
     575,  1543,    34,   452,   453,   578,   579,   731,   123,   155,
     734,    97,   461,   106,   105,   116,   250,   251,   128,   253,
     185,   250,   251,   186,   253,   186,   260,   335,    60,   218,
     338,  1628,  1141,   148,   106,   395,   270,   152,  1487,   735,
     155,   270,   106,   395,   145,   159,  1140,   106,   282,   122,
     146,   124,   195,   282,   249,   155,    29,   158,   940,   132,
     942,   176,   111,   106,   424,   186,   426,   262,  1177,   264,
     259,   426,   424,  1151,   426,   186,   167,   526,  1614,   152,
     275,   276,   277,    96,   279,   106,   281,   106,   106,   538,
     450,   192,  1201,   186,   889,   455,   404,   405,   450,  1408,
     408,   550,   842,   455,   412,   704,   901,   415,   416,   582,
     992,   106,   994,   586,   186,   423,  1258,   566,   567,  1261,
    1160,   429,   186,  1177,   432,  1283,    94,   186,  1041,  1042,
    1043,   871,   440,   146,  1292,  1584,   109,   223,   446,   447,
     448,   449,   266,   186,   106,  1303,   454,  1201,   155,   273,
     123,   106,   106,   106,   462,  1041,  1042,  1043,   106,   424,
     106,   426,   106,     9,    10,   186,   526,   186,   186,   106,
     424,   531,   426,   106,   526,   148,   157,  1626,   146,   531,
     647,   648,     5,    42,   106,   450,     9,    46,   106,    42,
     455,   186,    51,    46,   175,   644,   450,   106,    51,   507,
     649,   455,   801,   899,   900,   106,  1315,   567,   904,   152,
      69,   106,   155,   521,  1542,   567,    69,   106,   578,   579,
     580,   581,   530,  1507,   186,   573,   578,   579,   580,   581,
     183,   186,   186,   806,   157,   183,   596,   812,   934,   168,
     186,    42,   186,    94,   596,    46,   183,  1696,   106,  1698,
      51,   106,   175,   186,   562,   704,   102,   106,  1707,    96,
     152,  1315,    66,   165,   186,   183,   531,    71,    69,   965,
     153,   200,   155,   969,   183,   112,   122,   531,   124,   181,
    1358,    96,    33,   152,  1393,   186,   267,  1396,     9,    10,
     141,   186,  1406,   274,   183,     9,    10,  1411,    49,   122,
    1458,   124,   567,   284,   121,   143,   152,   176,   167,   132,
     156,   170,   155,   117,   167,  1055,  1056,   170,   155,   768,
     769,   770,  1294,   772,    96,   183,   185,   173,   183,   152,
      99,   146,   185,    53,   183,    94,    53,   175,    58,  1393,
     112,    58,  1396,   112,   704,   157,   157,   193,   135,   657,
    1263,   210,   704,   155,   192,     9,    10,   210,  1606,  1607,
      77,   267,   149,   175,   175,   211,   167,   727,   274,   170,
     678,   152,   727,   681,   136,   727,    96,   136,   284,    96,
    1033,   102,   141,   155,   185,   197,   197,   695,   102,   155,
     152,   699,   700,  1057,    95,   176,  1644,   757,   758,     9,
     117,   122,  1650,   124,   105,   757,   758,   155,   122,   210,
     124,   136,   121,   721,   115,   723,  1530,    96,    28,    99,
    1534,     9,   155,   731,   181,   126,   734,   152,  1027,   117,
     738,   152,   112,   112,    99,   156,   155,   194,   152,   223,
      28,   801,   156,   152,   228,   261,   155,   112,   102,   801,
      99,    99,   173,  1562,    94,  1564,   272,   245,   246,   173,
     155,    99,   727,   112,   112,   105,   297,   775,   122,   817,
     124,   121,   193,   727,   112,   306,   136,  1449,  1450,   193,
     268,   141,    53,  1442,  1180,  1579,  1595,    58,   152,  1185,
     211,   155,   757,   758,  1031,   803,  1610,   211,   152,  1036,
     190,   191,   156,   757,   758,   275,   276,   277,  1562,   121,
    1564,   281,   122,  1622,   124,   650,   121,   825,   653,   173,
     136,   656,   117,   133,   337,   141,   127,   128,  1637,   342,
    1639,   223,   152,   225,   122,   155,   124,   121,   223,   193,
     225,  1595,   152,  1283,   117,   133,   854,   855,   856,   857,
     127,   128,  1292,   219,   220,   221,   230,   211,   232,   230,
     121,   232,   121,  1303,   152,   626,   627,   152,  1622,   121,
     633,   634,   856,   857,  1270,   635,   636,   121,  1550,  1551,
    1179,  1475,  1476,  1637,   892,  1639,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,   121,   121,   906,   152,
     214,   155,   223,   117,   239,  1054,   239,   155,   240,   152,
       0,   106,    92,   189,    50,   166,   247,   198,   100,    73,
     101,   153,   120,   931,   144,   155,   183,   987,   183,    29,
      47,   117,   940,    87,   942,   987,   183,   244,   946,   151,
     302,   131,   117,   282,   186,   282,  1618,   152,     1,   139,
     140,   959,   142,   117,   141,   106,   110,   186,  1257,   152,
     150,   152,   183,   155,   154,   141,   156,  1027,   122,    35,
     124,   161,   155,    17,   212,  1027,   155,   155,   155,  1375,
     152,  1041,  1042,  1043,   992,   155,   994,   155,   178,  1041,
    1042,  1043,  1040,   155,    29,   229,     3,   186,   243,   117,
     167,   189,    70,   169,   189,    94,   169,   229,    94,    94,
     148,   201,   202,   203,   204,   205,   206,    29,  1458,   106,
     159,   126,   987,   106,   159,   131,   244,    94,   297,   141,
     131,   183,   106,   987,   183,   117,   186,    94,   186,  1435,
      96,    45,  1050,   186,    96,   186,   186,    94,   152,   186,
     183,   183,   223,   141,    33,   189,   169,   117,   131,    29,
     141,   235,    94,  1071,   225,   284,    94,   117,   152,   297,
     146,   126,   117,    94,   117,   183,   196,   131,    96,   252,
     159,   152,   131,   117,  1144,   146,    99,   183,  1387,  1144,
      99,   183,  1144,   152,   189,   141,    35,    29,   117,   243,
     106,   152,    79,   106,  1253,  1254,  1255,   155,   265,   256,
     143,  1507,   258,   155,   155,   155,   155,   155,   283,  1179,
      29,    29,    29,   225,   284,   189,   285,  1179,   186,   143,
    1190,   146,   126,   117,   117,  1190,   146,    77,  1190,   106,
     141,   146,  1150,    99,   131,  1153,   304,     7,   105,  1209,
     186,   231,   189,   231,  1209,   186,   186,  1209,   183,   186,
    1168,   231,   186,   235,   105,   185,   231,   196,  1228,  1177,
     186,   248,   146,   248,   284,    78,  1228,   280,   186,  1144,
      29,   335,    29,  1191,   338,   106,   186,   186,   169,   125,
    1144,   183,   255,  1201,   146,   146,  1256,  1257,   125,    96,
     269,   183,   152,   183,  1256,  1257,  1505,   185,    94,   185,
     185,   183,   185,    29,   183,   186,   278,  1516,  1517,    96,
    1519,  1229,   186,   169,   146,  1190,    53,  1526,    94,   195,
     185,   185,    94,   196,    29,   106,  1190,   106,   117,   117,
     263,  1249,    94,   185,  1209,   117,    94,   195,   195,    93,
    1258,   405,   185,  1261,   408,  1209,   185,   182,   412,   285,
     195,   415,   416,  1228,   223,   223,   117,   117,   185,   423,
     185,   185,   117,   197,  1228,   429,   684,   242,   432,   223,
     291,   303,  1101,   245,   245,   893,   440,   304,   285,   419,
     399,  1256,   446,   447,   448,   449,   960,  1141,  1584,   248,
     454,   303,  1626,  1150,  1603,   303,   804,  1315,   462,   304,
     957,   304,   740,  1169,  1613,  1368,  1279,  1046,  1274,  1277,
     521,  1191,  1196,  1199,  1204,   607,   606,  1387,  1222,   659,
     776,  1339,   323,  1650,  1644,  1387,   857,  1135,   942,  1638,
    1249,  1259,  1100,  1258,  1458,  1292,  1303,  1056,  1455,  1065,
    1296,   925,  1123,   507,  1334,  1478,  1293,  1365,  1366,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   521,    -1,    -1,
    1669,    -1,    -1,    -1,    -1,    -1,   530,    -1,    -1,    -1,
      -1,    -1,    -1,  1391,    -1,  1393,    -1,    -1,  1396,    -1,
      -1,  1690,    -1,    -1,    -1,  1544,  1695,    -1,    -1,  1407,
      -1,    -1,    -1,    -1,  1412,    -1,    -1,    -1,   562,    -1,
      -1,  1560,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   427,    -1,    -1,    -1,    -1,    -1,   427,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1505,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1505,    -1,    -1,  1516,  1517,    -1,  1519,
      -1,    -1,    -1,    -1,  1516,  1517,  1526,  1519,    -1,    -1,
      -1,    -1,    -1,    -1,  1526,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   657,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1520,    -1,  1522,    -1,  1524,    -1,    -1,    -1,
      -1,    -1,    -1,  1531,    -1,    -1,    -1,   681,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   695,    -1,  1603,    -1,   699,   700,    -1,    -1,    -1,
      -1,  1603,    -1,  1613,  1562,    -1,  1564,    -1,    -1,    -1,
      -1,  1613,    -1,    -1,    -1,    -1,    -1,   721,    -1,   723,
      -1,    -1,  1580,    -1,    -1,  1583,    -1,   731,  1638,    -1,
     734,    -1,    -1,    -1,   738,    -1,  1638,  1595,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1605,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1669,
      -1,    -1,    -1,    -1,  1622,    -1,    -1,  1669,    -1,    -1,
      -1,   775,  1630,    -1,    -1,    -1,    -1,  1635,    -1,  1637,
    1690,  1639,    -1,    -1,    -1,  1695,    -1,    -1,  1690,    -1,
      -1,    -1,    -1,  1695,    -1,    -1,    -1,    -1,    -1,   803,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1666,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   825,    -1,    -1,  1682,    -1,    -1,    -1,  1686,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1702,    -1,    -1,  1705,    -1,    -1,
     854,   855,   856,   857,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   554,   555,    -1,   557,   558,   559,   560,   892,    -1,
      -1,    -1,   565,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   906,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   588,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   596,   597,    -1,    -1,   931,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   940,    -1,   942,    -1,
      -1,    -1,   946,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   959,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   655,    -1,    -1,    -1,   659,    -1,   992,    -1,
     994,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   697,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1050,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   739,  1071,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   764,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   774,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1150,    -1,    -1,  1153,
      -1,    -1,    -1,    -1,   827,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1168,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1177,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1191,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1201,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   894,    -1,    -1,    -1,  1229,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1249,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1258,    -1,   929,  1261,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   948,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   970,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   981,   982,
      -1,  1315,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   996,    -1,    -1,   999,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1339,    -1,    -1,    -1,    -1,
    1013,  1014,  1015,    -1,  1017,  1018,  1019,  1020,  1021,  1022,
      -1,  1024,  1025,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1365,  1366,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1046,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1391,    -1,  1393,
      -1,    -1,  1396,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1407,    -1,    -1,    -1,    -1,  1412,    -1,
      -1,    -1,    -1,    -1,    -1,  1088,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1155,    -1,  1157,    -1,  1159,    -1,    -1,  1162,
      -1,    -1,    -1,    -1,  1167,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1179,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1188,  1520,    -1,  1522,    -1,
    1524,  1194,  1195,    -1,    -1,    -1,    -1,  1531,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1213,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1562,    -1,
    1564,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1580,    -1,    -1,  1583,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1595,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1605,    -1,    -1,  1277,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1622,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1630,    -1,    -1,    -1,
      -1,  1635,    -1,  1637,    -1,  1639,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1666,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1682,  1352,
      -1,    -1,  1686,  1356,    -1,    -1,    -1,  1360,    -1,  1362,
      -1,  1364,    -1,    -1,    -1,    -1,    -1,  1370,  1702,    -1,
      -1,  1705,    -1,    -1,    -1,  1378,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1386,  1387,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1404,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1415,  1416,  1417,  1418,  1419,    -1,  1421,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1493,    -1,  1495,    -1,    -1,  1498,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1506,    -1,    -1,    -1,    -1,  1511,  1512,
      -1,    -1,    -1,    -1,    -1,    -1,  1519,    -1,    -1,    -1,
    1523,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1587,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1599,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1638,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1664,    -1,    -1,    -1,    -1,  1669,    -1,    -1,    11,
      12,  1674,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,  1689,    29,    -1,    -1,
    1693,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    97,    98,    99,   100,   101,
      -1,    -1,   104,   105,    -1,    -1,    -1,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,    -1,    -1,
      -1,   123,    -1,   125,   126,   127,   128,    -1,   130,    -1,
      -1,    -1,   134,   135,   136,   137,   138,    -1,    -1,    -1,
      -1,    -1,    -1,   145,   146,   147,   148,   149,   150,   151,
     152,    -1,    -1,   155,   156,   157,   158,   159,    -1,    -1,
      -1,    -1,   164,   165,   166,   167,   168,   169,   170,   171,
      -1,   173,    -1,   175,   176,    -1,    -1,   179,   180,   181,
      -1,    -1,    -1,   185,    -1,   187,   188,    -1,   190,   191,
     192,    -1,   194,    -1,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,    -1,    -1,   209,   210,   211,
      -1,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,   257,   258,   259,    -1,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    25,    26,    27,    -1,    29,    -1,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      94,    95,    96,    97,    98,    99,   100,   101,    -1,    -1,
     104,   105,    -1,    -1,    -1,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,    -1,    -1,    -1,   123,
      -1,   125,   126,   127,   128,    -1,   130,    -1,    -1,    -1,
     134,   135,   136,   137,   138,    -1,    -1,    -1,    -1,    -1,
      -1,   145,   146,   147,   148,   149,   150,   151,   152,    -1,
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
     254,   255,    -1,   257,   258,   259,    -1,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    21,    22,    23,    24,    25,    26,
      27,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,    76,
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
     247,   248,   249,   250,   251,   252,   253,   254,   255,    -1,
     257,   258,   259,    -1,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    26,    27,    -1,    29,
      -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
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
     180,   181,    -1,   183,    -1,   185,    -1,   187,   188,    -1,
     190,   191,   192,    -1,   194,    -1,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,    -1,    -1,   209,
     210,   211,    -1,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,    -1,   257,   258,   259,
      -1,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    27,    -1,    29,    -1,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    69,    70,    71,    72,
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
     253,   254,   255,    -1,   257,   258,   259,    -1,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    98,    99,   100,   101,    -1,    -1,   104,   105,
      -1,    -1,    -1,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,    -1,    -1,    -1,   123,    -1,   125,
     126,   127,   128,    -1,   130,    -1,    -1,    -1,   134,   135,
     136,   137,   138,    -1,    -1,    -1,    -1,    -1,    -1,   145,
     146,   147,   148,   149,   150,   151,   152,    -1,    -1,   155,
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
      -1,   257,   258,   259,    -1,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    20,    21,    22,    23,    24,    25,    26,    27,    -1,
      29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
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
     249,   250,   251,   252,   253,   254,   255,    -1,   257,   258,
     259,    -1,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    97,    98,    99,   100,   101,
      -1,    -1,   104,   105,    -1,    -1,    -1,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,    -1,    -1,
      -1,   123,    -1,   125,   126,   127,   128,    -1,   130,    -1,
      -1,    -1,   134,   135,   136,   137,   138,    -1,    -1,    -1,
      -1,    -1,    -1,   145,   146,   147,   148,   149,   150,   151,
     152,    -1,    -1,   155,   156,   157,   158,   159,    -1,    -1,
      -1,    -1,   164,   165,   166,   167,   168,   169,   170,   171,
      -1,   173,    -1,   175,   176,    -1,    -1,   179,   180,   181,
      -1,    -1,    -1,   185,    -1,   187,   188,    -1,   190,   191,
     192,    -1,   194,    -1,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,    -1,    -1,   209,   210,   211,
      -1,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,   257,   258,   259,    -1,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,
      25,    26,    27,    -1,    29,    -1,    -1,    -1,    33,    34,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    72,    73,    74,
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
     255,    -1,   257,   258,   259,    -1,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    26,    27,
      -1,    29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    -1,    94,    95,    96,    97,
      98,    99,   100,   101,    -1,    -1,   104,   105,    -1,    -1,
      -1,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,    -1,    -1,    -1,   123,    -1,   125,   126,   127,
     128,    -1,   130,    -1,    -1,    -1,   134,   135,   136,   137,
     138,    -1,    -1,    -1,    -1,    -1,    -1,   145,   146,   147,
     148,   149,   150,   151,   152,    -1,    -1,   155,   156,   157,
     158,   159,    -1,    -1,    -1,    -1,   164,   165,   166,   167,
     168,   169,   170,   171,    -1,   173,    -1,   175,   176,    -1,
      -1,   179,   180,   181,    -1,    -1,    -1,   185,    -1,   187,
     188,    -1,   190,   191,   192,    -1,   194,    -1,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,    -1,
      -1,   209,   210,   211,    -1,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,    -1,   257,
     258,   259,    -1,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      21,    22,    23,    24,    25,    26,    27,    -1,    29,    -1,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,    70,
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
     251,   252,   253,   254,   255,    -1,   257,   258,   259,    -1,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      94,    95,    96,    97,    98,    99,   100,   101,    -1,    -1,
     104,   105,    -1,    -1,    -1,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,    -1,    -1,    -1,   123,
      -1,   125,   126,   127,   128,    -1,   130,    -1,    -1,    -1,
     134,   135,   136,   137,   138,    -1,    -1,    -1,    -1,    -1,
      -1,   145,   146,   147,   148,   149,   150,   151,   152,    -1,
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
     254,   255,    -1,   257,   258,   259,    -1,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    21,    22,    23,    24,    25,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,    76,
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
     247,   248,   249,   250,   251,   252,   253,   254,   255,    -1,
     257,   258,   259,    -1,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
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
     180,   181,    -1,    -1,    -1,   185,   186,   187,   188,    -1,
     190,   191,   192,    -1,   194,    -1,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,    -1,    -1,   209,
     210,   211,    -1,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,    -1,   257,   258,   259,
      -1,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    69,    70,    71,    72,
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
      -1,    -1,   185,   186,   187,   188,    -1,   190,   191,   192,
      -1,   194,    -1,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,    -1,    -1,   209,   210,   211,    -1,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,    -1,   257,   258,   259,    -1,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    98,    99,   100,   101,    -1,    -1,   104,   105,
      -1,    -1,    -1,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,    -1,    -1,    -1,   123,    -1,   125,
     126,   127,   128,    -1,   130,    -1,    -1,    -1,   134,   135,
     136,   137,   138,    -1,    -1,    -1,    -1,    -1,    -1,   145,
     146,   147,   148,   149,   150,   151,   152,    -1,    -1,   155,
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
      -1,   257,   258,   259,    -1,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    20,    21,    22,    23,    24,    25,    -1,    -1,    -1,
      29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
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
     249,   250,   251,   252,   253,   254,   255,    -1,   257,   258,
     259,    -1,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    97,    98,    99,   100,   101,
      -1,    -1,   104,   105,    -1,    -1,    -1,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,    -1,    -1,
      -1,   123,    -1,   125,   126,   127,   128,    -1,   130,    -1,
      -1,    -1,   134,   135,   136,   137,   138,    -1,    -1,    -1,
      -1,    -1,    -1,   145,   146,   147,   148,   149,   150,   151,
     152,    -1,    -1,   155,   156,   157,   158,   159,    -1,    -1,
      -1,    -1,   164,   165,   166,   167,   168,   169,   170,   171,
      -1,   173,    -1,   175,   176,    -1,    -1,   179,   180,   181,
      -1,    -1,    -1,   185,    -1,   187,   188,    -1,   190,   191,
     192,    -1,   194,    -1,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,    -1,    -1,   209,   210,   211,
      -1,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,   257,   258,   259,    -1,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,
      25,    -1,    -1,    -1,    29,    -1,    -1,    -1,    33,    34,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    72,    73,    74,
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
     255,    -1,   257,   258,   259,    -1,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    -1,    -1,
      -1,    29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    -1,    94,    95,    96,    97,
      98,    99,   100,   101,    -1,    -1,   104,   105,    -1,    -1,
      -1,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,    -1,    -1,    -1,   123,    -1,   125,   126,   127,
     128,    -1,   130,    -1,    -1,    -1,   134,   135,   136,   137,
     138,    -1,    -1,    -1,    -1,    -1,    -1,   145,   146,   147,
     148,   149,   150,   151,   152,    -1,    -1,   155,   156,    -1,
     158,   159,    -1,    -1,    -1,    -1,   164,   165,   166,   167,
     168,   169,   170,   171,    -1,   173,    -1,    -1,    -1,    -1,
      -1,   179,   180,   181,    -1,    -1,    -1,   185,    -1,   187,
     188,    -1,    -1,    -1,   192,    -1,   194,    -1,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,    -1,
      -1,   209,   210,   211,    -1,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,    -1,   257,
     258,   259,    -1,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      -1,    -1,    -1,    24,    25,    -1,    -1,    -1,    29,    -1,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,    70,
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
     251,   252,   253,   254,   255,    -1,   257,   258,   259,    -1,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,
      24,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    72,    73,
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
     254,   255,    -1,   257,   258,   259,    -1,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
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
     252,   253,   254,   255,    -1,   257,   258,   259,    -1,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    25,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    -1,    94,    95,    96,    97,    -1,    99,
     100,   101,    -1,    -1,   104,   105,    -1,    -1,    -1,    -1,
     110,   111,   112,   113,   114,   115,   116,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   125,   126,   127,   128,    -1,
     130,    -1,    -1,    -1,   134,   135,   136,   137,   138,    -1,
      -1,    -1,    -1,    -1,    -1,   145,   146,   147,    -1,   149,
     150,   151,    -1,    -1,    -1,    -1,    -1,    -1,   158,   159,
      -1,    -1,    -1,    -1,   164,   165,   166,   167,   168,   169,
     170,   171,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,
     180,   181,    -1,    -1,    -1,   185,    -1,   187,   188,    -1,
      -1,    -1,    -1,    -1,   194,    -1,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,    -1,    -1,   209,
     210,    -1,    -1,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,    -1,   257,   258,   259,
      -1,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,    18,    19,
      -1,    -1,    -1,    -1,    24,    25,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    -1,    94,    95,    96,    97,    -1,    99,
     100,   101,    -1,    -1,   104,   105,    -1,    -1,    -1,    -1,
     110,   111,   112,   113,   114,   115,   116,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   125,   126,   127,   128,    -1,
     130,    -1,    -1,    -1,   134,   135,   136,   137,   138,    -1,
      -1,    -1,    -1,    -1,    -1,   145,   146,   147,    -1,   149,
     150,   151,    -1,    -1,    -1,    -1,    -1,    -1,   158,   159,
      -1,    -1,    -1,    -1,   164,   165,   166,   167,   168,   169,
     170,   171,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,
     180,   181,    -1,    -1,    -1,   185,    -1,   187,   188,    -1,
      -1,    -1,    -1,    -1,   194,    -1,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,    -1,    -1,   209,
     210,    -1,    -1,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,    -1,   257,   258,   259,
      -1,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,    24,    25,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
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
     186,   187,   188,    -1,    -1,    -1,   192,    -1,   194,    -1,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,    -1,    -1,   209,   210,    -1,    -1,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
      -1,   257,   258,   259,    -1,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
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
     192,    -1,   194,    -1,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,    -1,    -1,   209,   210,    -1,
      -1,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,   257,   258,   259,    -1,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,    24,    25,    -1,    -1,
      -1,    29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    77,
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
     248,   249,   250,   251,   252,   253,   254,   255,    -1,   257,
     258,   259,    -1,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
      24,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    72,    73,
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
     254,   255,    -1,   257,   258,   259,    -1,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,    24,    25,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    -1,    94,    95,    96,    97,    -1,    99,
     100,   101,    -1,    -1,   104,   105,    -1,    -1,    -1,    -1,
     110,   111,   112,   113,   114,   115,   116,   117,    -1,    -1,
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
     250,   251,   252,   253,   254,   255,    -1,   257,   258,   259,
      -1,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,    24,    25,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    -1,    99,   100,   101,    -1,    -1,   104,   105,
      -1,    -1,    -1,    -1,   110,   111,   112,   113,   114,   115,
     116,   117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,
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
      -1,   257,   258,   259,    -1,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    97,    -1,    99,   100,   101,
      -1,    -1,   104,   105,    -1,    -1,    -1,    -1,   110,   111,
     112,   113,   114,   115,   116,    -1,    -1,    -1,    -1,    -1,
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
     252,   253,   254,   255,    -1,   257,   258,   259,    -1,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,    24,    25,    -1,    -1,
      -1,    29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    -1,    94,    95,    96,    97,
      -1,    99,   100,   101,    -1,    -1,   104,   105,    -1,    -1,
      -1,    -1,   110,   111,   112,   113,   114,   115,   116,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,   126,   127,
     128,    -1,   130,    -1,    -1,    -1,   134,   135,   136,   137,
     138,    -1,    -1,    -1,    -1,    -1,    -1,   145,   146,   147,
      -1,   149,   150,   151,    -1,    -1,    -1,   155,    -1,    -1,
     158,   159,    -1,    -1,    -1,    -1,   164,   165,   166,   167,
     168,   169,   170,   171,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   179,   180,   181,    -1,    -1,    -1,   185,    -1,   187,
     188,    -1,    -1,    -1,    -1,    -1,   194,    -1,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,    -1,
      -1,   209,   210,    -1,    -1,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,    -1,   257,
     258,   259,    -1,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
      24,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    72,    73,
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
     254,   255,    -1,   257,   258,   259,    -1,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,    24,    25,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,    -1,
      40,    41,    42,    43,    -1,    -1,    46,    47,    -1,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    -1,
      60,    -1,    -1,    63,    64,    65,    66,    67,    -1,    69,
      -1,    71,    -1,    -1,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    -1,    94,    95,    96,    -1,    -1,    99,
     100,   101,    -1,    -1,   104,   105,    -1,    -1,    -1,    -1,
     110,   111,   112,   113,   114,   115,   116,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   125,   126,   127,   128,    -1,
     130,    -1,    -1,    -1,   134,   135,   136,   137,   138,    -1,
      -1,    -1,    -1,    -1,    -1,   145,   146,   147,    -1,   149,
     150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,   159,
      -1,    -1,    -1,    -1,   164,   165,   166,   167,   168,   169,
     170,   171,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,
     180,   181,    -1,    -1,    -1,   185,    -1,   187,   188,    -1,
      -1,    -1,    -1,    -1,   194,    -1,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,    -1,    -1,    -1,
     210,    -1,    -1,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,    -1,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,    -1,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,    -1,   257,   258,   259,
      -1,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  xquery_parser::yystos_[] =
  {
         0,    11,    12,    20,    21,    22,    23,    24,    25,    26,
      27,    29,    33,    34,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    69,    70,    71,    72,    73,
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
     254,   255,   257,   258,   259,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   323,   325,   326,   327,   328,   329,   330,
     331,   332,   333,   334,   335,   336,   337,   338,   339,   340,
     341,   344,   345,   346,   347,   348,   349,   353,   354,   355,
     359,   361,   362,   364,   371,   373,   376,   377,   378,   380,
     381,   382,   383,   384,   386,   387,   389,   390,   391,   392,
     393,   394,   396,   397,   400,   401,   402,   403,   408,   410,
     412,   413,   418,   437,   440,   444,   447,   448,   453,   454,
     455,   456,   458,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   504,   505,   506,   520,   521,   523,   524,   525,
     526,   527,   528,   529,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   549,   550,   551,   552,   557,   558,
     559,   560,   561,   562,   565,   623,   625,   626,   627,    33,
      34,    49,   213,   379,   380,   381,   379,   379,   155,   155,
      37,    38,    40,    41,    47,    56,    57,    74,    79,   110,
     111,   112,   159,   218,   259,   285,   293,   301,   360,   361,
     365,   366,   367,   159,   152,   155,   152,   155,   152,   155,
      66,    71,   117,   405,   155,   368,   155,    24,    34,    60,
     117,   271,   417,   419,   420,   152,   155,   155,   155,   117,
     152,   155,   155,   155,    76,   152,   219,   220,   121,   121,
     121,   152,   155,    29,    39,    43,    45,    46,    47,    48,
      51,    59,    67,    70,    72,    73,    75,    90,    91,    97,
     104,   111,   113,   114,   134,   137,   138,   168,   171,   179,
     180,   188,   200,   222,   224,   226,   227,   234,   236,   237,
     238,   241,   242,   488,   625,   626,   121,   117,   388,   121,
     121,    39,    44,    45,    59,    61,    62,    70,    97,   223,
     625,   117,   121,   121,   183,   379,   381,    48,    72,    73,
     117,   152,   186,   242,   400,   402,   412,   625,   152,   121,
      16,   624,   625,    18,    19,   625,   121,   121,   121,   480,
     152,    30,   212,   214,   223,   225,   155,   223,   225,   223,
     223,   228,   117,   239,   239,   240,   155,   152,   383,   325,
       0,   327,   328,    33,    49,   330,   347,     1,   189,   324,
     189,   324,   111,   362,   382,   400,   106,   189,   106,   189,
      42,    46,    51,    69,   167,   170,   185,   210,   395,   404,
     409,   410,   411,   425,   426,   430,   166,    92,   131,   139,
     140,   142,   150,   154,   156,   161,   178,   201,   202,   203,
     204,   205,   206,   472,   473,   247,   157,   175,   197,   116,
     145,   158,   192,   199,   208,   135,   149,    50,   198,   100,
     101,   157,   175,   471,   152,   477,   480,   190,   191,   153,
     492,   493,   488,   492,   488,   155,   492,   120,   144,   155,
     183,   183,   183,    29,   363,   495,   363,   623,   181,   194,
     181,   194,   165,   181,   626,   625,   168,   200,    47,   625,
     151,   117,    45,    47,    79,   105,   167,   624,   219,   220,
     221,   244,   596,   625,   625,   302,   136,   141,   111,   285,
     293,   365,   624,   380,   381,   186,   379,    45,    62,   186,
     545,   546,   400,   186,   192,   625,   282,   282,   414,   415,
     625,   117,   421,   117,   186,   369,   370,   152,   385,   400,
       1,   159,   623,   112,   159,   343,   623,   625,   117,   141,
     106,   400,    29,   186,   624,   625,   625,   438,   439,   625,
     380,   186,   400,   400,   547,   625,   380,   152,   152,   400,
     186,   192,   625,   625,   141,   438,   183,   183,   155,   155,
     155,   625,   152,   186,   185,    35,   508,   509,   510,   400,
       8,   174,    17,   400,   212,    29,   401,   401,   186,   401,
     401,   401,   401,   229,   563,   564,   625,   189,   189,   401,
     400,   381,   400,   243,   398,   399,   189,   324,   189,   324,
       3,   331,   347,   377,   331,   347,   377,    33,   348,   377,
     348,   377,   388,   388,   401,   117,   167,   169,   169,   382,
     401,   401,   455,   456,   458,   458,   458,   458,   457,   458,
     458,   458,    70,   462,   462,   461,   463,   463,   463,   463,
     464,   464,   465,   465,   229,    94,    94,    94,   183,   400,
     480,   480,   400,   493,   186,   401,   503,   624,   148,   186,
     503,   106,   186,   186,   106,   106,   368,    29,   626,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,   350,
     351,   352,    94,   136,   141,   356,   357,   358,   625,   159,
     159,   350,   623,   126,   131,    54,    56,    99,   249,   262,
     264,   275,   276,   277,   279,   281,   597,   598,   599,   600,
     601,   602,   609,   615,   616,   244,    94,   297,   625,   141,
     401,   117,   625,   625,   131,   183,   183,   186,   186,   183,
     106,   186,   106,   186,   106,    36,    94,    96,   146,   416,
     417,   531,   625,    55,   215,   252,   406,   407,   625,    94,
     106,   186,   379,   186,   624,    96,    45,   624,   623,    96,
     141,   531,   625,   401,   420,   183,   186,   186,   186,   186,
     106,   187,   146,   531,   183,   186,   186,   152,   183,   380,
     380,   183,   106,   186,   106,   186,   141,   531,   401,   187,
     400,   400,   400,   625,   509,   510,   129,   195,   183,   183,
     130,   189,    94,   216,   217,   231,    94,   216,   217,   231,
      94,   235,   223,   106,   233,   141,   189,   186,    48,    72,
      73,   242,   402,   412,   183,   489,   569,   399,   347,    33,
      33,   189,   324,   189,   112,   625,   169,   401,   431,   432,
     117,   427,   428,   458,   152,   155,   257,   476,   495,   570,
     573,   574,   575,   576,   577,   581,   583,   585,   586,    47,
     151,   155,   209,   532,   534,   536,   537,   553,   554,   555,
     556,   625,   532,   530,   536,   530,   183,   184,   106,   186,
     186,   495,   147,   164,   147,   164,   136,   385,   368,   351,
     131,   534,   358,   401,   531,   623,   623,   127,   128,   623,
     275,   276,   277,   281,   625,   261,   272,   261,   272,    29,
     284,    96,   112,   155,   603,   606,   597,    39,    44,    59,
      61,    70,    97,   223,   372,   537,   225,   297,   306,   401,
     625,    94,   297,   623,   152,   547,   548,   625,   547,   548,
     117,   126,   532,   117,   401,   146,   417,   146,    36,   146,
     416,   417,   146,   531,   252,    53,    58,    77,   117,   416,
     422,   423,   424,   407,   531,   532,   370,    94,   183,   196,
     131,   342,   623,   159,   131,    96,   342,   401,   141,   417,
     152,   117,   401,   401,   146,    99,   441,   442,   443,   445,
     446,    99,   449,   450,   451,   452,   380,   183,   183,   152,
     547,   547,   401,   141,   189,   401,   186,   186,   186,    35,
     510,   129,   195,     9,    10,   102,   122,   124,   152,   193,
     505,   507,   518,   519,   522,    29,   230,   232,   401,   401,
     401,   230,   232,   401,   401,   401,   401,   401,   401,   117,
     401,   401,   382,   155,   155,   155,   152,   185,   243,   566,
     567,   208,   383,   189,   112,   377,   377,   377,   431,    95,
     105,   115,   126,   433,   434,   435,   436,   106,   625,   106,
     400,   570,   577,   152,   283,   459,   622,    96,   168,   250,
     251,   253,   260,   270,   282,   571,   572,   591,   592,   593,
     594,   617,   620,   256,   258,   578,   596,   265,   582,   618,
     245,   246,   268,   587,   588,   155,   155,   534,   155,   143,
     175,   192,   533,   143,   401,   136,   385,   549,   357,   284,
      29,    96,   112,   155,   610,    29,   603,   533,   478,   285,
     304,   531,   372,   225,   189,   379,   186,   186,   143,   186,
     186,   415,   146,   416,   625,   401,   146,   401,   126,   401,
     146,   417,   146,   401,   146,   117,   117,   401,   625,   424,
      77,   532,   382,   401,   623,   106,   342,   401,   141,   379,
     439,   401,   401,   112,   442,   443,    99,   185,   112,   443,
     446,   117,   532,    99,   112,   450,    99,   112,   452,   183,
     379,   186,   186,   401,   196,   449,   131,   193,   507,     7,
     380,   625,   193,   518,   189,   231,   231,   231,   231,   235,
     564,   185,   400,   400,   400,   569,   567,   489,   623,   127,
     128,   435,   436,   436,   432,   105,   429,   428,   183,   186,
     570,   584,   248,   215,   252,   266,   273,   621,    96,   254,
     255,   619,   248,   574,   621,   461,   591,   575,   146,   280,
     579,   580,   619,   284,   590,    78,   589,   186,   192,   532,
     535,   186,   186,   186,    29,   135,   199,   612,   613,   614,
      29,   611,   612,   269,   607,   106,   604,   169,   625,   255,
     478,   183,   401,   146,   401,   146,   416,   401,   146,   401,
     401,   625,   625,   423,   401,   125,   125,    96,   623,   401,
     183,   185,   185,   401,   382,   401,   185,   185,   625,   185,
     117,   532,   117,   185,   117,   532,   185,   183,   112,   510,
     625,   193,   183,   510,   625,   401,   401,   401,   401,   401,
     401,   186,   186,   186,   152,   568,   436,   623,   183,   463,
      52,   128,   461,   461,   267,   274,   284,   595,   595,   576,
     152,   278,    94,   186,   106,   186,   610,   610,   614,   106,
     186,    29,   608,   619,   605,   606,   186,   374,   375,   478,
     117,   223,   305,   285,   169,   401,   401,   146,   401,    53,
     382,   401,   342,   401,   382,    94,   382,   401,   625,   185,
     625,   401,   625,   185,   382,   117,    93,   182,   511,   510,
     625,   195,   510,   196,   449,   400,   461,   461,   197,   400,
     532,   532,    94,    29,   263,   106,   106,   436,   531,   625,
     117,   223,   625,   374,   401,   117,   532,    94,   185,    94,
     625,     5,   132,   514,   515,   517,   519,    28,   133,   512,
     513,   516,   519,   195,   510,   195,   112,   183,   461,   183,
     532,   606,   375,   436,   303,   625,   117,   223,   625,   185,
     532,   382,   401,   532,   185,    93,   132,   517,   182,   133,
     516,   195,   117,   401,   303,   625,   117,   382,   401,   185,
     185,   625,   291,   303,   625,   185,   304,   401,   304,   478,
     478,   197,   285,   625,   223,   117,   625,   304,   478
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
     575,   576
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   322,   323,   323,   324,   325,   325,   325,   325,   326,
     326,   327,   327,   327,   327,   327,   327,   327,   327,   328,
     328,   328,   328,   329,   330,   330,   330,   331,   331,   331,
     331,   331,   332,   332,   332,   332,   332,   332,   332,   332,
     333,   333,   334,   335,   336,   336,   337,   337,   338,   338,
     339,   339,   339,   339,   340,   340,   340,   341,   341,   341,
     341,   342,   342,   343,   343,   344,   344,   344,   344,   345,
     346,   346,   347,   347,   347,   348,   348,   348,   348,   348,
     348,   348,   348,   349,   349,   350,   350,   351,   352,   352,
     352,   352,   352,   352,   352,   352,   352,   352,   353,   354,
     355,   356,   356,   357,   357,   357,   358,   359,   359,   359,
     360,   360,   360,   360,   361,   361,   362,   362,   362,   362,
     363,   363,   364,   364,   365,   365,   366,   366,   367,   367,
     368,   368,   368,   368,   369,   369,   370,   370,   371,   371,
     371,   371,   372,   372,   373,   373,   374,   374,   375,   375,
     375,   375,   376,   376,   376,   376,   377,   378,   378,   378,
     379,   379,   379,   380,   380,   381,   381,   382,   382,   382,
     382,   382,   382,   382,   382,   382,   382,   382,   382,   383,
     383,   384,   385,   386,   387,   387,   387,   388,   388,   388,
     388,   389,   390,   391,   392,   393,   393,   394,   395,   396,
     397,   398,   398,   399,   400,   400,   401,   401,   401,   401,
     401,   401,   402,   402,   402,   402,   402,   402,   402,   403,
     404,   405,   405,   406,   406,   406,   407,   407,   408,   408,
     409,   410,   410,   410,   411,   411,   411,   411,   411,   412,
     412,   413,   414,   414,   415,   415,   415,   415,   415,   415,
     415,   415,   415,   415,   415,   415,   416,   417,   418,   419,
     419,   420,   420,   420,   420,   421,   421,   422,   422,   422,
     423,   423,   423,   424,   424,   424,   425,   426,   427,   427,
     428,   428,   429,   430,   430,   431,   431,   432,   432,   433,
     433,   433,   433,   433,   433,   433,   434,   434,   435,   435,
     436,   437,   437,   438,   438,   439,   439,   440,   441,   441,
     442,   443,   443,   444,   445,   445,   446,   447,   447,   448,
     448,   449,   449,   450,   450,   451,   451,   452,   452,   453,
     454,   454,   455,   455,   456,   456,   456,   456,   456,   457,
     456,   456,   456,   456,   458,   458,   459,   459,   460,   460,
     461,   461,   461,   462,   462,   462,   462,   462,   463,   463,
     463,   464,   464,   464,   465,   465,   466,   466,   467,   467,
     468,   468,   469,   469,   470,   470,   470,   470,   471,   471,
     471,   472,   472,   472,   472,   472,   472,   473,   473,   473,
     474,   474,   474,   474,   475,   475,   476,   476,   477,   477,
     477,   478,   478,   478,   478,   479,   480,   480,   480,   481,
     481,   482,   482,   482,   482,   483,   483,   484,   484,   484,
     484,   484,   484,   484,   485,   485,   486,   486,   487,   487,
     487,   487,   487,   488,   488,   489,   489,   490,   490,   490,
     490,   491,   491,   491,   491,   492,   492,   493,   494,   494,
     494,   494,   494,   494,   494,   494,   494,   494,   495,   495,
     496,   496,   496,   497,   498,   498,   499,   500,   501,   502,
     502,   503,   503,   504,   504,   505,   505,   505,   506,   506,
     506,   506,   506,   506,   507,   507,   508,   508,   509,   510,
     510,   511,   511,   512,   512,   513,   513,   513,   513,   514,
     514,   515,   515,   515,   515,   516,   516,   517,   517,   518,
     518,   518,   518,   519,   519,   519,   519,   520,   520,   521,
     521,   522,   523,   523,   523,   523,   523,   523,   524,   525,
     525,   526,   526,   527,   528,   529,   529,   530,   530,   531,
     532,   532,   532,   533,   533,   533,   534,   534,   534,   534,
     534,   535,   535,   536,   537,   537,   537,   537,   537,   537,
     537,   537,   537,   538,   539,   539,   539,   540,   541,   542,
     542,   542,   543,   543,   543,   543,   543,   544,   545,   545,
     545,   545,   545,   545,   545,   546,   547,   548,   549,   550,
     550,   551,   552,   553,   553,   554,   555,   555,   556,   557,
     557,   557,   558,   558,   558,   558,   558,   558,   558,   558,
     558,   558,   559,   559,   560,   560,   561,   562,   563,   563,
     564,   565,   566,   566,   567,   568,   569,   569,   570,   571,
     571,   572,   572,   573,   573,   574,   574,   575,   575,   576,
     576,   577,   578,   578,   579,   579,   580,   581,   581,   581,
     582,   582,   583,   584,   584,   585,   586,   586,   587,   587,
     588,   588,   588,   589,   589,   590,   590,   591,   591,   591,
     591,   591,   592,   593,   594,   595,   595,   595,   596,   596,
     597,   597,   597,   597,   597,   597,   597,   597,   598,   598,
     598,   598,   599,   599,   600,   601,   601,   602,   602,   602,
     603,   603,   604,   604,   605,   605,   606,   607,   607,   608,
     608,   609,   609,   609,   610,   610,   611,   611,   612,   612,
     613,   613,   614,   614,   615,   616,   616,   617,   617,   617,
     618,   619,   619,   619,   619,   620,   620,   621,   621,   622,
     623,   624,   624,   625,   625,   625,   625,   625,   625,   625,
     625,   625,   625,   625,   625,   625,   625,   625,   625,   626,
     626,   626,   626,   626,   626,   626,   626,   626,   626,   626,
     626,   626,   626,   626,   626,   626,   626,   626,   626,   626,
     626,   626,   626,   626,   626,   626,   626,   626,   626,   626,
     626,   626,   626,   626,   626,   626,   626,   626,   626,   626,
     626,   626,   626,   626,   626,   626,   626,   626,   626,   626,
     626,   626,   626,   626,   626,   626,   626,   626,   626,   626,
     626,   626,   626,   626,   626,   626,   626,   626,   626,   626,
     626,   626,   626,   626,   626,   626,   626,   626,   626,   626,
     626,   626,   626,   626,   626,   626,   626,   626,   626,   626,
     626,   626,   626,   626,   626,   626,   626,   626,   626,   626,
     626,   626,   626,   626,   626,   626,   626,   626,   626,   626,
     626,   626,   626,   626,   626,   626,   626,   626,   626,   626,
     626,   626,   626,   626,   626,   626,   626,   626,   626,   626,
     626,   626,   626,   626,   626,   626,   626,   626,   626,   626,
     626,   626,   626,   626,   626,   626,   626,   626,   626,   626,
     626,   626,   626,   626,   626,   626,   626,   626,   626,   626,
     626,   626,   626,   626,   626,   626,   626,   626,   626,   626,
     626,   626,   626,   626,   626,   626,   626,   626,   626,   626,
     626,   626,   626,   626,   626,   626,   626,   626,   626,   626,
     626,   626,   626,   626,   626,   626,   626,   626,   627,   627
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
       2,     3,     4,     5,     1,     3,     2,     3,     3,     5,
       4,     6,     1,     2,     8,     9,     1,     3,     1,     2,
       2,     3,    11,    14,    13,    22,     1,     1,     1,     0,
       1,     1,     0,     1,     2,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       2,     3,     3,     2,     3,     2,     3,     2,     3,     4,
       5,     5,     2,     4,     5,     3,     3,     2,     2,     8,
       3,     1,     2,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     2,     1,     1,     2,     4,     3,     5,     4,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     3,     1,     4,     3,     5,     4,     6,     4,     6,
       5,     7,     4,     5,     5,     6,     3,     3,     2,     1,
       3,     4,     5,     3,     6,     4,     5,     1,     2,     3,
       1,     2,     1,     6,     3,     3,     2,     3,     1,     3,
       2,     3,     2,     3,     4,     1,     3,     1,     2,     1,
       1,     1,     2,     2,     2,     3,     1,     1,     2,     2,
       2,     5,     5,     1,     4,     3,     4,     8,     1,     2,
       3,     2,     3,     8,     1,     2,     3,     8,    10,     8,
      10,     1,     2,     4,     7,     1,     2,     4,     7,     8,
       1,     3,     1,     3,     1,     3,     3,     3,     3,     0,
       4,     3,     3,     3,     1,     5,     0,     1,     1,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     1,     4,     1,     4,     1,     4,
       1,     4,     1,     2,     1,     1,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     5,     5,     6,     3,     4,     1,     2,     3,     2,
       2,     1,     2,     2,     1,     1,     1,     3,     3,     1,
       1,     1,     2,     1,     2,     2,     1,     2,     2,     2,
       2,     2,     2,     2,     1,     2,     2,     1,     2,     2,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     3,     4,     1,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     3,     1,     4,     4,     3,
       4,     1,     3,     1,     1,     1,     1,     1,     4,     5,
       8,     9,     9,    10,     1,     2,     1,     2,     6,     0,
       1,     3,     3,     0,     1,     1,     1,     2,     2,     0,
       1,     1,     1,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     2,     3,
       3,     2,     1,     1,     1,     1,     1,     1,     4,     3,
       7,     3,     7,     4,     4,     3,     7,     1,     2,     2,
       1,     2,     3,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     4,     4,     3,     3,     3,
       4,     4,     3,     4,     6,     4,     6,     4,     3,     4,
       6,     6,     4,     6,     6,     4,     1,     2,     1,     1,
       1,     3,     3,     1,     1,     4,     5,     6,     3,     3,
       3,     3,     5,     7,     7,     5,     5,     5,     7,     7,
       5,     5,     3,     3,     5,     7,     5,     7,     1,     4,
       3,     5,     1,     2,     3,     3,     1,     3,     2,     0,
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
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1
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
  "\"'document'\"", "\"'document-node'\"", "\"'element'\"", "\"'for'\"",
  "\"'function'\"", "\"'if'\"", "\"'import'\"", "\"'instance'\"",
  "\"'let'\"", "\"'most'\"", "\"'next'\"", "\"'no'\"", "\"'only'\"",
  "\"'option'\"", "\"'ordering'\"", "\"'previous'\"",
  "\"'processing-instruction'\"", "\"'schema'\"", "\"'schema-attribute'\"",
  "\"'schema-element'\"", "\"'sequential'\"", "\"'set'\"", "\"'simple'\"",
  "\"'sliding'\"", "\"'some'\"", "\"'space'\"", "\"'stable'\"",
  "\"'text'\"", "\"'tumbling'\"", "\"'switch'\"", "\"'typeswitch'\"",
  "\"'updating'\"", "\"'validate'\"", "\"'type'\"", "\"'when'\"",
  "\"'word'\"", "\"'decimal-format'\"", "\"'decimal-separator'\"",
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
  "\"'copy'\"", "\"'with'\"", "\"'break'\"", "\"'continue'\"",
  "\"'exit'\"", "\"'loop'\"", "\"'returning'\"", "\"'while'\"",
  "\"'try'\"", "\"'catch'\"", "\"'using'\"", "\"'all'\"", "\"'any'\"",
  "\"'contains'\"", "\"'content'\"", "\"'diacritics'\"", "\"'different'\"",
  "\"'distance'\"", "\"'end'\"", "\"'entire'\"", "\"'exactly'\"",
  "\"'from'\"", "\"'ftand'\"", "\"'ftnot'\"", "\"'not'\"",
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
  "Param", "CollectionDecl", "CollectionTypeDecl", "IndexDecl",
  "IndexKeyList", "IndexKeySpec", "IntegrityConstraintDecl", "QueryBody",
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
       323,     0,    -1,   325,    -1,   308,   325,    -1,     1,     3,
      -1,   327,    -1,   326,   327,    -1,   328,    -1,   326,   328,
      -1,   213,   214,    29,   189,    -1,   213,   214,    29,   130,
      29,   189,    -1,   330,   189,   377,    -1,   347,   189,   377,
      -1,   330,   189,   347,   189,   377,    -1,   377,    -1,   330,
     324,   377,    -1,   347,   324,   377,    -1,   330,   189,   347,
     324,   377,    -1,   330,   324,   347,   189,   377,    -1,   329,
      -1,   329,   330,   189,    -1,   329,   347,   189,    -1,   329,
     330,   189,   347,   189,    -1,    34,   159,   624,   131,   623,
     189,    -1,   331,    -1,   330,   189,   331,    -1,   330,   324,
     331,    -1,   332,    -1,   340,    -1,   345,    -1,   346,    -1,
     354,    -1,   333,    -1,   334,    -1,   335,    -1,   336,    -1,
     337,    -1,   338,    -1,   339,    -1,   557,    -1,    33,    38,
     181,    -1,    33,    38,   194,    -1,    33,   112,   105,   623,
      -1,    33,    37,   623,    -1,    33,    40,   181,    -1,    33,
      40,   194,    -1,    33,    57,   168,    -1,    33,    57,   200,
      -1,    33,   112,   167,   126,   127,    -1,    33,   112,   167,
     126,   128,    -1,    33,    41,   181,   106,   147,    -1,    33,
      41,   181,   106,   164,    -1,    33,    41,   165,   106,   147,
      -1,    33,    41,   165,   106,   164,    -1,   341,    -1,   344,
      -1,    49,    24,     1,    -1,    49,    60,   623,    -1,    49,
      60,   343,   623,    -1,    49,    60,   623,    96,   342,    -1,
      49,    60,   343,   623,    96,   342,    -1,   623,    -1,   342,
     106,   623,    -1,   159,   624,   131,    -1,   112,    45,   159,
      -1,    49,    34,   623,    -1,    49,    34,   159,   624,   131,
     623,    -1,    49,    34,   623,    96,   342,    -1,    49,    34,
     159,   624,   131,   623,    96,   342,    -1,    33,   159,   624,
     131,   623,    -1,    33,   112,    45,   159,   623,    -1,    33,
     112,    47,   159,   623,    -1,   348,    -1,   347,   189,   348,
      -1,   347,   324,   348,    -1,   349,    -1,   353,    -1,   355,
      -1,   359,    -1,   364,    -1,   371,    -1,   373,    -1,   376,
      -1,    33,   112,    79,   350,    -1,    33,    79,   625,   350,
      -1,   351,    -1,   350,   351,    -1,   352,   131,   549,    -1,
      80,    -1,    88,    -1,    81,    -1,    82,    -1,    83,    -1,
      84,    -1,    89,    -1,    85,    -1,    86,    -1,    87,    -1,
      33,    56,   625,    29,    -1,    33,   259,   596,    -1,    33,
     110,   151,   356,    -1,    94,   534,   357,    -1,   357,    -1,
     358,    -1,   136,    -1,   136,   358,    -1,   141,   401,    -1,
      33,   360,   141,   401,    -1,    33,   360,   136,    -1,    33,
     360,   136,   141,   401,    -1,   111,   117,   625,    -1,   111,
     117,   625,   531,    -1,   361,   111,   117,   625,    -1,   361,
     111,   117,   625,   531,    -1,   362,    -1,   361,   362,    -1,
      26,    -1,    26,   155,   363,   186,    -1,    27,    -1,    27,
     155,   363,   186,    -1,   495,    -1,   363,   106,   495,    -1,
      33,   365,    -1,    33,   361,   365,    -1,   366,    -1,   367,
      -1,    47,   626,   368,   385,    -1,    47,   626,   368,   136,
      -1,    74,    47,   626,   368,   385,    -1,    74,    47,   626,
     368,   136,    -1,   155,   186,    -1,   155,   369,   186,    -1,
     155,   186,    94,   532,    -1,   155,   369,   186,    94,   532,
      -1,   370,    -1,   369,   106,   370,    -1,   117,   625,    -1,
     117,   625,   531,    -1,    33,   285,   625,    -1,    33,   285,
     625,    94,   372,    -1,    33,   361,   285,   625,    -1,    33,
     361,   285,   625,    94,   372,    -1,   537,    -1,   537,   533,
      -1,    33,   293,   625,   297,   225,   478,   169,   374,    -1,
      33,   361,   293,   625,   297,   225,   478,   169,   374,    -1,
     375,    -1,   374,   106,   375,    -1,   478,    -1,   478,   531,
      -1,   478,   436,    -1,   478,   531,   436,    -1,    33,   301,
     302,   625,   297,   285,   625,   117,   625,   303,   401,    -1,
      33,   301,   302,   625,   297,   285,   625,   223,   117,   625,
     303,   291,   304,   478,    -1,    33,   301,   302,   625,   297,
     285,   625,   305,   223,   117,   625,   303,   401,    -1,    33,
     301,   302,   625,   306,   304,   255,   285,   625,   223,   117,
     625,   304,   478,   197,   285,   625,   223,   117,   625,   304,
     478,    -1,   378,    -1,   380,    -1,   381,    -1,    -1,   380,
      -1,   381,    -1,    -1,   400,    -1,   381,   400,    -1,   382,
      -1,   381,   382,    -1,   383,    -1,   386,    -1,   389,    -1,
     390,    -1,   391,    -1,   392,    -1,   393,    -1,   394,    -1,
     396,    -1,   448,    -1,   444,    -1,   397,    -1,   152,   381,
     183,    -1,   152,   183,    -1,   152,   379,   183,    -1,   152,
     379,   183,    -1,   387,   189,    -1,   387,   106,   388,    -1,
     111,   388,    -1,   361,   111,   388,    -1,   117,   625,    -1,
     117,   625,   531,    -1,   117,   625,   141,   401,    -1,   117,
     625,   531,   141,   401,    -1,   117,   625,   141,   401,   189,
      -1,   402,   189,    -1,   238,   240,   401,   189,    -1,   241,
     155,   400,   186,   382,    -1,   236,   239,   189,    -1,   237,
     239,   189,    -1,   412,   395,    -1,   185,   382,    -1,    48,
     155,   400,   186,   196,   382,   125,   382,    -1,   242,   383,
     398,    -1,   399,    -1,   398,   399,    -1,   243,   569,   383,
      -1,   401,    -1,   400,   106,   401,    -1,   403,    -1,   440,
      -1,   447,    -1,   453,    -1,   565,    -1,   402,    -1,   454,
      -1,   437,    -1,   558,    -1,   559,    -1,   561,    -1,   560,
      -1,   562,    -1,   412,   404,    -1,   185,   401,    -1,    66,
     282,    -1,    71,   282,    -1,   215,    -1,   252,    -1,    55,
     252,    -1,   406,   422,    77,   401,    -1,   406,    77,   401,
      -1,    46,   405,   421,   407,   407,    -1,    46,   405,   421,
     407,    -1,    42,   117,   625,    -1,   413,    -1,   418,    -1,
     408,    -1,   410,    -1,   425,    -1,   430,    -1,   426,    -1,
     409,    -1,   410,    -1,   412,   411,    -1,    46,   117,   414,
      -1,   415,    -1,   414,   106,   117,   415,    -1,   625,   146,
     401,    -1,   625,    36,   126,   146,   401,    -1,   625,   531,
     146,   401,    -1,   625,   531,    36,   126,   146,   401,    -1,
     625,   416,   146,   401,    -1,   625,    36,   126,   416,   146,
     401,    -1,   625,   531,   416,   146,   401,    -1,   625,   531,
      36,   126,   416,   146,   401,    -1,   625,   417,   146,   401,
      -1,   625,   531,   417,   146,   401,    -1,   625,   416,   417,
     146,   401,    -1,   625,   531,   416,   417,   146,   401,    -1,
      96,   117,   625,    -1,   271,   117,   625,    -1,    51,   419,
      -1,   420,    -1,   419,   106,   420,    -1,   117,   625,   141,
     401,    -1,   117,   625,   531,   141,   401,    -1,   417,   141,
     401,    -1,   117,   625,   531,   417,   141,   401,    -1,   117,
     625,   146,   401,    -1,   117,   625,   531,   146,   401,    -1,
     423,    -1,   117,   625,    -1,   117,   625,   423,    -1,   416,
      -1,   416,   424,    -1,   424,    -1,    58,   117,   625,    53,
     117,   625,    -1,    53,   117,   625,    -1,    58,   117,   625,
      -1,   210,   401,    -1,   170,   169,   427,    -1,   428,    -1,
     427,   106,   428,    -1,   117,   625,    -1,   117,   625,   429,
      -1,   105,   623,    -1,   167,   169,   431,    -1,    69,   167,
     169,   431,    -1,   432,    -1,   431,   106,   432,    -1,   401,
      -1,   401,   433,    -1,   434,    -1,   435,    -1,   436,    -1,
     434,   435,    -1,   434,   436,    -1,   435,   436,    -1,   434,
     435,   436,    -1,    95,    -1,   115,    -1,   126,   127,    -1,
     126,   128,    -1,   105,   623,    -1,    67,   117,   438,   187,
     401,    -1,   134,   117,   438,   187,   401,    -1,   439,    -1,
     438,   106,   117,   439,    -1,   625,   146,   401,    -1,   625,
     531,   146,   401,    -1,    72,   155,   400,   186,   441,   112,
     185,   401,    -1,   442,    -1,   441,   442,    -1,   443,   185,
     401,    -1,    99,   401,    -1,   443,    99,   401,    -1,    72,
     155,   400,   186,   445,   112,   185,   382,    -1,   446,    -1,
     445,   446,    -1,   443,   185,   382,    -1,    73,   155,   400,
     186,   449,   112,   185,   401,    -1,    73,   155,   400,   186,
     449,   112,   117,   625,   185,   401,    -1,    73,   155,   400,
     186,   451,   112,   185,   382,    -1,    73,   155,   400,   186,
     449,   112,   117,   625,   185,   382,    -1,   450,    -1,   449,
     450,    -1,    99,   532,   185,   401,    -1,    99,   117,   625,
      94,   532,   185,   401,    -1,   452,    -1,   451,   452,    -1,
      99,   532,   185,   382,    -1,    99,   117,   625,    94,   532,
     185,   382,    -1,    48,   155,   400,   186,   196,   401,   125,
     401,    -1,   455,    -1,   454,   166,   455,    -1,   456,    -1,
     455,    92,   456,    -1,   458,    -1,   458,   472,   458,    -1,
     458,   473,   458,    -1,   458,   131,   458,    -1,   458,   161,
     458,    -1,    -1,   458,   156,   457,   458,    -1,   458,   154,
     458,    -1,   458,   142,   458,    -1,   458,   140,   458,    -1,
     460,    -1,   460,   247,    70,   570,   459,    -1,    -1,   622,
      -1,   461,    -1,   461,   197,   461,    -1,   462,    -1,   461,
     175,   462,    -1,   461,   157,   462,    -1,   463,    -1,   462,
     192,   463,    -1,   462,   116,   463,    -1,   462,   145,   463,
      -1,   462,   158,   463,    -1,   464,    -1,   463,   199,   464,
      -1,   463,   208,   464,    -1,   465,    -1,   464,   149,   465,
      -1,   464,   135,   465,    -1,   466,    -1,   466,    50,   229,
     532,    -1,   467,    -1,   467,   198,    94,   532,    -1,   468,
      -1,   468,   100,    94,   530,    -1,   469,    -1,   469,   101,
      94,   530,    -1,   471,    -1,   470,   471,    -1,   175,    -1,
     157,    -1,   470,   175,    -1,   470,   157,    -1,   474,    -1,
     478,    -1,   475,    -1,   201,    -1,   206,    -1,   205,    -1,
     204,    -1,   203,    -1,   202,    -1,   150,    -1,   178,    -1,
     139,    -1,    75,   152,   380,   183,    -1,    75,   220,   152,
     380,   183,    -1,    75,   219,   152,   380,   183,    -1,    75,
      76,   547,   152,   380,   183,    -1,   476,   152,   183,    -1,
     476,   152,   400,   183,    -1,   477,    -1,   476,   477,    -1,
     176,   625,    17,    -1,   176,    18,    -1,   176,    19,    -1,
     479,    -1,   479,   480,    -1,   191,   480,    -1,   480,    -1,
     190,    -1,   481,    -1,   481,   190,   480,    -1,   481,   191,
     480,    -1,   482,    -1,   491,    -1,   483,    -1,   483,   492,
      -1,   486,    -1,   486,   492,    -1,   484,   488,    -1,   485,
      -1,   104,   121,    -1,   113,   121,    -1,    97,   121,    -1,
     188,   121,    -1,   114,   121,    -1,   138,   121,    -1,   137,
     121,    -1,   488,    -1,    98,   488,    -1,   487,   488,    -1,
     119,    -1,   171,   121,    -1,    90,   121,    -1,   180,   121,
      -1,   179,   121,    -1,    91,   121,    -1,   537,    -1,   489,
      -1,   625,    -1,   490,    -1,   192,    -1,    11,    -1,    12,
      -1,    20,    -1,   494,    -1,   491,   492,    -1,   491,   155,
     186,    -1,   491,   155,   503,   186,    -1,   493,    -1,   492,
     493,    -1,   153,   400,   184,    -1,   495,    -1,   497,    -1,
     498,    -1,   499,    -1,   502,    -1,   504,    -1,   500,    -1,
     501,    -1,   550,    -1,   384,    -1,   496,    -1,   549,    -1,
     109,    -1,   148,    -1,   123,    -1,   117,   625,    -1,   155,
     186,    -1,   155,   400,   186,    -1,   118,    -1,   168,   152,
     400,   183,    -1,   200,   152,   400,   183,    -1,   626,   155,
     186,    -1,   626,   155,   503,   186,    -1,   401,    -1,   503,
     106,   401,    -1,   505,    -1,   523,    -1,   506,    -1,   520,
      -1,   521,    -1,   156,   625,   510,   129,    -1,   156,   625,
     508,   510,   129,    -1,   156,   625,   510,   195,   193,   625,
     510,   195,    -1,   156,   625,   510,   195,   507,   193,   625,
     510,   195,    -1,   156,   625,   508,   510,   195,   193,   625,
     510,   195,    -1,   156,   625,   508,   510,   195,   507,   193,
     625,   510,   195,    -1,   518,    -1,   507,   518,    -1,   509,
      -1,   508,   509,    -1,    35,   625,   510,   131,   510,   511,
      -1,    -1,    35,    -1,   182,   512,   182,    -1,    93,   514,
      93,    -1,    -1,   513,    -1,   133,    -1,   516,    -1,   513,
     133,    -1,   513,   516,    -1,    -1,   515,    -1,   132,    -1,
     517,    -1,   515,   132,    -1,   515,   517,    -1,    28,    -1,
     519,    -1,     5,    -1,   519,    -1,   505,    -1,    10,    -1,
     522,    -1,   519,    -1,     9,    -1,   122,    -1,   124,    -1,
     152,   380,   183,    -1,   211,    30,   212,    -1,   211,   212,
      -1,   173,   624,   174,    -1,   173,   624,     8,    -1,   102,
       7,    -1,   524,    -1,   525,    -1,   526,    -1,   527,    -1,
     528,    -1,   529,    -1,    43,   152,   379,   183,    -1,    21,
     379,   183,    -1,    45,   152,   400,   183,   152,   379,   183,
      -1,    22,   379,   183,    -1,    97,   152,   400,   183,   152,
     379,   183,    -1,    70,   152,   380,   183,    -1,    39,   152,
     380,   183,    -1,    23,   379,   183,    -1,    59,   152,   400,
     183,   152,   379,   183,    -1,   536,    -1,   536,   143,    -1,
      94,   532,    -1,   534,    -1,   534,   533,    -1,   209,   155,
     186,    -1,   143,    -1,   192,    -1,   175,    -1,   536,    -1,
     537,    -1,   151,   155,   186,    -1,   553,    -1,   556,    -1,
     532,    -1,   535,   106,   532,    -1,   625,    -1,   539,    -1,
     545,    -1,   543,    -1,   546,    -1,   544,    -1,   542,    -1,
     541,    -1,   540,    -1,   538,    -1,   223,   155,   186,    -1,
      44,   155,   186,    -1,    44,   155,   545,   186,    -1,    44,
     155,   546,   186,    -1,    70,   155,   186,    -1,    39,   155,
     186,    -1,    59,   155,   186,    -1,    59,   155,   624,   186,
      -1,    59,   155,    29,   186,    -1,    97,   155,   186,    -1,
      97,   155,   625,   186,    -1,    97,   155,   625,   106,   547,
     186,    -1,    97,   155,   192,   186,    -1,    97,   155,   192,
     106,   547,   186,    -1,    61,   155,   625,   186,    -1,    45,
     155,   186,    -1,    45,   155,   625,   186,    -1,    45,   155,
     625,   106,   547,   186,    -1,    45,   155,   625,   106,   548,
     186,    -1,    45,   155,   192,   186,    -1,    45,   155,   192,
     106,   547,   186,    -1,    45,   155,   192,   106,   548,   186,
      -1,    62,   155,   625,   186,    -1,   625,    -1,   625,   143,
      -1,    29,    -1,   551,    -1,   552,    -1,   625,   144,   148,
      -1,    47,   368,   385,    -1,   554,    -1,   555,    -1,    47,
     155,   192,   186,    -1,    47,   155,   186,    94,   532,    -1,
      47,   155,   535,   186,    94,   532,    -1,   155,   534,   186,
      -1,    33,   218,   219,    -1,    33,   218,   220,    -1,    33,
     218,   221,    -1,   224,   223,   401,   231,   401,    -1,   224,
     223,   401,    94,   230,   231,   401,    -1,   224,   223,   401,
      94,   232,   231,   401,    -1,   224,   223,   401,   216,   401,
      -1,   224,   223,   401,   217,   401,    -1,   224,   225,   401,
     231,   401,    -1,   224,   225,   401,    94,   230,   231,   401,
      -1,   224,   225,   401,    94,   232,   231,   401,    -1,   224,
     225,   401,   216,   401,    -1,   224,   225,   401,   217,   401,
      -1,   222,   223,   401,    -1,   222,   225,   401,    -1,   227,
     223,   401,   235,   401,    -1,   227,   228,   229,   223,   401,
     235,   401,    -1,   226,   223,   401,    94,   401,    -1,   234,
     117,   563,   233,   401,   185,   401,    -1,   564,    -1,   563,
     106,   117,   564,    -1,   625,   141,   401,    -1,   242,   152,
     400,   183,   566,    -1,   567,    -1,   566,   567,    -1,   243,
     569,   568,    -1,   152,   400,   183,    -1,   489,    -1,   569,
     208,   489,    -1,   573,   571,    -1,    -1,   572,    -1,   591,
      -1,   572,   591,    -1,   574,    -1,   573,   260,   574,    -1,
     575,    -1,   574,   256,   575,    -1,   576,    -1,   575,   258,
     146,   576,    -1,   577,    -1,   257,   577,    -1,   581,   578,
     579,    -1,    -1,   596,    -1,    -1,   580,    -1,   280,   152,
     400,   183,    -1,   585,   582,    -1,   155,   570,   186,    -1,
     583,    -1,    -1,   618,    -1,   476,   152,   584,   183,    -1,
      -1,   570,    -1,   586,   587,    -1,   495,    -1,   152,   400,
     183,    -1,    -1,   588,    -1,   246,   589,    -1,   245,   590,
      -1,   268,    -1,    -1,    78,    -1,    -1,   284,    -1,   592,
      -1,   593,    -1,   594,    -1,   620,    -1,   617,    -1,   168,
      -1,   282,   461,   595,    -1,   251,   619,   595,    -1,   284,
      -1,   274,    -1,   267,    -1,   244,   597,    -1,   596,   244,
     597,    -1,   598,    -1,   599,    -1,   600,    -1,   615,    -1,
     601,    -1,   609,    -1,   602,    -1,   616,    -1,    99,   272,
      -1,    99,   261,    -1,   264,    -1,   279,    -1,   249,   272,
      -1,   249,   261,    -1,    56,   625,    29,    -1,   275,    -1,
      54,   275,    -1,   277,   603,    -1,   277,   155,   603,   604,
     186,    -1,    54,   277,    -1,   606,    -1,   112,    -1,    -1,
     106,   605,    -1,   606,    -1,   605,   106,   606,    -1,    96,
      29,   607,   608,    -1,    -1,   269,    29,    -1,    -1,   619,
     263,    -1,   276,   284,   610,   612,    -1,   276,   284,   112,
     612,    -1,    54,   276,   284,    -1,    96,    29,    -1,   155,
     611,   186,    -1,    29,    -1,   611,   106,    29,    -1,    -1,
     613,    -1,   614,    -1,   613,   614,    -1,   199,   610,    -1,
     135,   610,    -1,   262,    29,    -1,   281,    -1,    54,   281,
      -1,    96,   215,    -1,    96,   252,    -1,   253,   248,    -1,
     265,   619,   278,    -1,   254,   461,    -1,    96,   128,   461,
      -1,    96,    52,   461,    -1,   255,   461,   197,   461,    -1,
     270,   621,    -1,   250,   621,    -1,   273,    -1,   266,    -1,
     283,   248,   463,    -1,    29,    -1,    16,    -1,   625,    -1,
     626,    -1,    97,    -1,    39,    -1,    44,    -1,    45,    -1,
     151,    -1,    48,    -1,   223,    -1,    59,    -1,    61,    -1,
      62,    -1,    70,    -1,    73,    -1,    72,    -1,   209,    -1,
     241,    -1,   627,    -1,    24,    -1,   213,    -1,   126,    -1,
      38,    -1,   259,    -1,    37,    -1,   220,    -1,   219,    -1,
     145,    -1,    43,    -1,   257,    -1,   258,    -1,   272,    -1,
     261,    -1,   249,    -1,   283,    -1,   275,    -1,   277,    -1,
     276,    -1,   281,    -1,   253,    -1,   248,    -1,    78,    -1,
     215,    -1,   252,    -1,    52,    -1,   221,    -1,   234,    -1,
     300,    -1,   228,    -1,   201,    -1,   206,    -1,   205,    -1,
     204,    -1,   203,    -1,   202,    -1,    96,    -1,   110,    -1,
     111,    -1,   185,    -1,    46,    -1,    36,    -1,    66,    -1,
      71,    -1,    58,    -1,    53,    -1,    55,    -1,    77,    -1,
      42,    -1,   146,    -1,    51,    -1,   210,    -1,   169,    -1,
     170,    -1,   167,    -1,    69,    -1,    95,    -1,   115,    -1,
     127,    -1,   128,    -1,   105,    -1,    67,    -1,   134,    -1,
     187,    -1,    99,    -1,    94,    -1,   196,    -1,   125,    -1,
     166,    -1,    92,    -1,    50,    -1,   229,    -1,   100,    -1,
     197,    -1,   116,    -1,   158,    -1,   199,    -1,   149,    -1,
     135,    -1,    75,    -1,    76,    -1,   101,    -1,   198,    -1,
     150,    -1,   181,    -1,   194,    -1,   159,    -1,   136,    -1,
     130,    -1,   165,    -1,   147,    -1,   164,    -1,    33,    -1,
      40,    -1,    57,    -1,   112,    -1,    41,    -1,    56,    -1,
     214,    -1,    49,    -1,    60,    -1,    34,    -1,    47,    -1,
     271,    -1,   247,    -1,   280,    -1,   282,    -1,   251,    -1,
     265,    -1,   278,    -1,   270,    -1,   250,    -1,   264,    -1,
     279,    -1,   269,    -1,   263,    -1,   262,    -1,   246,    -1,
     245,    -1,   254,    -1,   255,    -1,   284,    -1,   274,    -1,
     273,    -1,   268,    -1,   266,    -1,   267,    -1,   227,    -1,
     233,    -1,   230,    -1,   224,    -1,   217,    -1,   216,    -1,
     218,    -1,   235,    -1,   225,    -1,   226,    -1,   232,    -1,
     222,    -1,   231,    -1,    65,    -1,    63,    -1,    74,    -1,
     168,    -1,   200,    -1,   240,    -1,   238,    -1,   239,    -1,
     236,    -1,   237,    -1,   242,    -1,   243,    -1,   244,    -1,
      64,    -1,   293,    -1,   291,    -1,   292,    -1,   297,    -1,
     298,    -1,   299,    -1,   294,    -1,   295,    -1,   296,    -1,
      79,    -1,    80,    -1,    81,    -1,    82,    -1,    83,    -1,
      84,    -1,    85,    -1,    86,    -1,    87,    -1,    88,    -1,
      89,    -1,   285,    -1,   286,    -1,   287,    -1,   288,    -1,
     289,    -1,   290,    -1,   301,    -1,   302,    -1,   303,    -1,
     304,    -1,   305,    -1,   306,    -1,   307,    -1,    90,    -1,
     104,    -1,   113,    -1,   171,    -1,   179,    -1,   188,    -1,
     137,    -1,    91,    -1,   114,    -1,   138,    -1,   180,    -1,
     623,   120,   624,    -1,    25,    -1
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
     473,   476,   480,   485,   491,   493,   497,   500,   504,   508,
     514,   519,   526,   528,   531,   540,   550,   552,   556,   558,
     561,   564,   568,   580,   595,   609,   632,   634,   636,   638,
     639,   641,   643,   644,   646,   649,   651,   654,   656,   658,
     660,   662,   664,   666,   668,   670,   672,   674,   676,   678,
     682,   685,   689,   693,   696,   700,   703,   707,   710,   714,
     719,   725,   731,   734,   739,   745,   749,   753,   756,   759,
     768,   772,   774,   777,   781,   783,   787,   789,   791,   793,
     795,   797,   799,   801,   803,   805,   807,   809,   811,   813,
     816,   819,   822,   825,   827,   829,   832,   837,   841,   847,
     852,   856,   858,   860,   862,   864,   866,   868,   870,   872,
     874,   877,   881,   883,   888,   892,   898,   903,   910,   915,
     922,   928,   936,   941,   947,   953,   960,   964,   968,   971,
     973,   977,   982,   988,   992,   999,  1004,  1010,  1012,  1015,
    1019,  1021,  1024,  1026,  1033,  1037,  1041,  1044,  1048,  1050,
    1054,  1057,  1061,  1064,  1068,  1073,  1075,  1079,  1081,  1084,
    1086,  1088,  1090,  1093,  1096,  1099,  1103,  1105,  1107,  1110,
    1113,  1116,  1122,  1128,  1130,  1135,  1139,  1144,  1153,  1155,
    1158,  1162,  1165,  1169,  1178,  1180,  1183,  1187,  1196,  1207,
    1216,  1227,  1229,  1232,  1237,  1245,  1247,  1250,  1255,  1263,
    1272,  1274,  1278,  1280,  1284,  1286,  1290,  1294,  1298,  1302,
    1303,  1308,  1312,  1316,  1320,  1322,  1328,  1329,  1331,  1333,
    1337,  1339,  1343,  1347,  1349,  1353,  1357,  1361,  1365,  1367,
    1371,  1375,  1377,  1381,  1385,  1387,  1392,  1394,  1399,  1401,
    1406,  1408,  1413,  1415,  1418,  1420,  1422,  1425,  1428,  1430,
    1432,  1434,  1436,  1438,  1440,  1442,  1444,  1446,  1448,  1450,
    1452,  1457,  1463,  1469,  1476,  1480,  1485,  1487,  1490,  1494,
    1497,  1500,  1502,  1505,  1508,  1510,  1512,  1514,  1518,  1522,
    1524,  1526,  1528,  1531,  1533,  1536,  1539,  1541,  1544,  1547,
    1550,  1553,  1556,  1559,  1562,  1564,  1567,  1570,  1572,  1575,
    1578,  1581,  1584,  1587,  1589,  1591,  1593,  1595,  1597,  1599,
    1601,  1603,  1605,  1608,  1612,  1617,  1619,  1622,  1626,  1628,
    1630,  1632,  1634,  1636,  1638,  1640,  1642,  1644,  1646,  1648,
    1650,  1652,  1654,  1656,  1659,  1662,  1666,  1668,  1673,  1678,
    1682,  1687,  1689,  1693,  1695,  1697,  1699,  1701,  1703,  1708,
    1714,  1723,  1733,  1743,  1754,  1756,  1759,  1761,  1764,  1771,
    1772,  1774,  1778,  1782,  1783,  1785,  1787,  1789,  1792,  1795,
    1796,  1798,  1800,  1802,  1805,  1808,  1810,  1812,  1814,  1816,
    1818,  1820,  1822,  1824,  1826,  1828,  1830,  1834,  1838,  1841,
    1845,  1849,  1852,  1854,  1856,  1858,  1860,  1862,  1864,  1869,
    1873,  1881,  1885,  1893,  1898,  1903,  1907,  1915,  1917,  1920,
    1923,  1925,  1928,  1932,  1934,  1936,  1938,  1940,  1942,  1946,
    1948,  1950,  1952,  1956,  1958,  1960,  1962,  1964,  1966,  1968,
    1970,  1972,  1974,  1976,  1980,  1984,  1989,  1994,  1998,  2002,
    2006,  2011,  2016,  2020,  2025,  2032,  2037,  2044,  2049,  2053,
    2058,  2065,  2072,  2077,  2084,  2091,  2096,  2098,  2101,  2103,
    2105,  2107,  2111,  2115,  2117,  2119,  2124,  2130,  2137,  2141,
    2145,  2149,  2153,  2159,  2167,  2175,  2181,  2187,  2193,  2201,
    2209,  2215,  2221,  2225,  2229,  2235,  2243,  2249,  2257,  2259,
    2264,  2268,  2274,  2276,  2279,  2283,  2287,  2289,  2293,  2296,
    2297,  2299,  2301,  2304,  2306,  2310,  2312,  2316,  2318,  2323,
    2325,  2328,  2332,  2333,  2335,  2336,  2338,  2343,  2346,  2350,
    2352,  2353,  2355,  2360,  2361,  2363,  2366,  2368,  2372,  2373,
    2375,  2378,  2381,  2383,  2384,  2386,  2387,  2389,  2391,  2393,
    2395,  2397,  2399,  2401,  2405,  2409,  2411,  2413,  2415,  2418,
    2422,  2424,  2426,  2428,  2430,  2432,  2434,  2436,  2438,  2441,
    2444,  2446,  2448,  2451,  2454,  2458,  2460,  2463,  2466,  2472,
    2475,  2477,  2479,  2480,  2483,  2485,  2489,  2494,  2495,  2498,
    2499,  2502,  2507,  2512,  2516,  2519,  2523,  2525,  2529,  2530,
    2532,  2534,  2537,  2540,  2543,  2546,  2548,  2551,  2554,  2557,
    2560,  2564,  2567,  2571,  2575,  2580,  2583,  2586,  2588,  2590,
    2594,  2596,  2598,  2600,  2602,  2604,  2606,  2608,  2610,  2612,
    2614,  2616,  2618,  2620,  2622,  2624,  2626,  2628,  2630,  2632,
    2634,  2636,  2638,  2640,  2642,  2644,  2646,  2648,  2650,  2652,
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
    3014,  3016,  3018,  3020,  3022,  3024,  3026,  3028,  3030,  3034
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,   992,   992,   993,  1002,  1011,  1017,  1025,  1031,  1042,
    1047,  1055,  1062,  1069,  1078,  1085,  1093,  1101,  1109,  1120,
    1125,  1132,  1139,  1151,  1161,  1168,  1175,  1187,  1188,  1189,
    1190,  1191,  1196,  1197,  1198,  1199,  1200,  1201,  1202,  1205,
    1210,  1215,  1223,  1231,  1239,  1244,  1252,  1257,  1265,  1270,
    1278,  1285,  1292,  1299,  1309,  1311,  1314,  1324,  1329,  1337,
    1345,  1356,  1363,  1374,  1379,  1387,  1394,  1401,  1410,  1423,
    1431,  1438,  1448,  1455,  1462,  1473,  1474,  1475,  1476,  1477,
    1478,  1479,  1480,  1485,  1491,  1500,  1507,  1517,  1527,  1528,
    1529,  1530,  1531,  1532,  1533,  1534,  1535,  1536,  1541,  1549,
    1557,  1565,  1572,  1580,  1587,  1592,  1600,  1608,  1623,  1638,
    1656,  1661,  1669,  1677,  1688,  1693,  1702,  1707,  1714,  1719,
    1729,  1734,  1743,  1749,  1762,  1767,  1775,  1786,  1801,  1813,
    1828,  1833,  1838,  1843,  1851,  1858,  1869,  1874,  1884,  1891,
    1898,  1905,  1915,  1919,  1929,  1937,  1948,  1954,  1963,  1968,
    1975,  1982,  1993,  2003,  2013,  2023,  2041,  2061,  2066,  2071,
    2078,  2083,  2088,  2095,  2100,  2112,  2119,  2131,  2132,  2133,
    2134,  2135,  2136,  2137,  2139,  2140,  2141,  2142,  2143,  2148,
    2153,  2161,  2178,  2186,  2194,  2201,  2208,  2218,  2230,  2243,
    2255,  2271,  2279,  2287,  2295,  2310,  2315,  2323,  2337,  2354,
    2379,  2387,  2394,  2405,  2415,  2420,  2435,  2436,  2437,  2438,
    2439,  2440,  2445,  2446,  2449,  2450,  2451,  2452,  2453,  2458,
    2472,  2480,  2485,  2493,  2498,  2503,  2511,  2520,  2532,  2542,
    2555,  2563,  2564,  2565,  2570,  2571,  2572,  2573,  2574,  2579,
    2586,  2596,  2604,  2611,  2621,  2631,  2641,  2651,  2661,  2671,
    2681,  2691,  2702,  2711,  2721,  2731,  2747,  2756,  2765,  2773,
    2779,  2791,  2799,  2809,  2817,  2829,  2835,  2846,  2848,  2852,
    2860,  2864,  2869,  2873,  2877,  2881,  2891,  2899,  2906,  2912,
    2923,  2927,  2936,  2944,  2950,  2960,  2966,  2976,  2980,  2990,
    2996,  3002,  3008,  3017,  3026,  3035,  3048,  3052,  3060,  3066,
    3076,  3084,  3093,  3106,  3113,  3125,  3129,  3141,  3148,  3154,
    3163,  3170,  3176,  3187,  3194,  3200,  3209,  3218,  3225,  3236,
    3243,  3255,  3261,  3273,  3279,  3290,  3296,  3307,  3313,  3324,
    3333,  3337,  3346,  3350,  3358,  3362,  3372,  3379,  3388,  3398,
    3397,  3411,  3420,  3429,  3442,  3446,  3459,  3462,  3469,  3473,
    3482,  3486,  3490,  3499,  3503,  3509,  3515,  3521,  3532,  3536,
    3540,  3548,  3552,  3558,  3568,  3572,  3582,  3586,  3596,  3600,
    3610,  3614,  3624,  3628,  3636,  3640,  3644,  3648,  3658,  3662,
    3666,  3674,  3678,  3682,  3686,  3690,  3694,  3702,  3706,  3710,
    3718,  3722,  3726,  3730,  3741,  3747,  3757,  3763,  3773,  3777,
    3781,  3819,  3823,  3833,  3843,  3856,  3865,  3875,  3879,  3888,
    3892,  3901,  3907,  3915,  3921,  3933,  3939,  3949,  3953,  3957,
    3961,  3965,  3971,  3977,  3985,  3989,  3997,  4001,  4012,  4016,
    4020,  4026,  4030,  4044,  4048,  4056,  4060,  4070,  4074,  4078,
    4082,  4091,  4095,  4099,  4103,  4111,  4117,  4127,  4135,  4139,
    4143,  4147,  4151,  4155,  4159,  4163,  4167,  4177,  4185,  4189,
    4197,  4204,  4211,  4222,  4230,  4234,  4242,  4250,  4258,  4312,
    4316,  4329,  4335,  4345,  4349,  4357,  4361,  4365,  4373,  4383,
    4393,  4403,  4413,  4423,  4438,  4444,  4455,  4461,  4472,  4483,
    4485,  4489,  4494,  4504,  4507,  4514,  4520,  4526,  4534,  4547,
    4550,  4557,  4563,  4569,  4576,  4587,  4591,  4601,  4605,  4615,
    4619,  4623,  4628,  4637,  4643,  4649,  4655,  4663,  4668,  4676,
    4681,  4689,  4697,  4702,  4707,  4712,  4717,  4722,  4731,  4739,
    4743,  4760,  4764,  4772,  4780,  4788,  4792,  4800,  4806,  4816,
    4824,  4828,  4832,  4867,  4873,  4879,  4889,  4893,  4897,  4901,
    4905,  4912,  4918,  4928,  4936,  4940,  4944,  4948,  4952,  4956,
    4960,  4964,  4968,  4976,  4984,  4988,  4992,  5002,  5010,  5018,
    5022,  5026,  5034,  5038,  5044,  5050,  5054,  5064,  5072,  5076,
    5082,  5091,  5100,  5106,  5112,  5122,  5139,  5146,  5161,  5197,
    5201,  5209,  5217,  5229,  5233,  5241,  5249,  5253,  5264,  5281,
    5287,  5293,  5303,  5307,  5313,  5319,  5323,  5329,  5333,  5339,
    5345,  5352,  5362,  5367,  5375,  5381,  5391,  5413,  5422,  5428,
    5441,  5455,  5462,  5468,  5478,  5487,  5495,  5501,  5519,  5528,
    5531,  5538,  5543,  5551,  5555,  5562,  5566,  5573,  5577,  5584,
    5588,  5597,  5610,  5613,  5621,  5624,  5632,  5640,  5648,  5652,
    5660,  5663,  5671,  5683,  5686,  5694,  5706,  5712,  5722,  5725,
    5733,  5737,  5741,  5749,  5752,  5760,  5763,  5771,  5775,  5779,
    5783,  5787,  5795,  5803,  5815,  5827,  5831,  5835,  5843,  5849,
    5859,  5863,  5867,  5871,  5875,  5879,  5883,  5887,  5895,  5899,
    5903,  5907,  5915,  5921,  5931,  5941,  5945,  5953,  5963,  5974,
    5981,  5985,  5993,  5996,  6003,  6008,  6017,  6027,  6030,  6038,
    6041,  6049,  6058,  6065,  6075,  6079,  6086,  6092,  6102,  6105,
    6112,  6117,  6129,  6137,  6149,  6157,  6161,  6169,  6173,  6177,
    6185,  6193,  6197,  6201,  6205,  6213,  6221,  6233,  6237,  6245,
    6258,  6262,  6263,  6276,  6277,  6278,  6279,  6280,  6281,  6282,
    6283,  6284,  6285,  6286,  6287,  6288,  6289,  6290,  6291,  6295,
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
    6436,  6437,  6438,  6439,  6440,  6441,  6442,  6443,  6444,  6445,
    6446,  6447,  6448,  6449,  6450,  6451,  6452,  6453,  6454,  6455,
    6456,  6457,  6458,  6459,  6460,  6461,  6462,  6463,  6464,  6465,
    6466,  6467,  6468,  6469,  6470,  6471,  6472,  6473,  6474,  6475,
    6476,  6477,  6478,  6479,  6480,  6481,  6482,  6483,  6484,  6485,
    6486,  6487,  6488,  6489,  6490,  6491,  6492,  6493,  6498,  6505
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
     315,   316,   317,   318,   319,   320,   321
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 13157;
  const int xquery_parser::yynnts_ = 306;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 570;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 322;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 576;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


} // zorba

/* Line 1054 of lalr1.cc  */
#line 16020 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.cpp"


/* Line 1056 of lalr1.cc  */
#line 6509 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"


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

