
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
#line 68 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"


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

using namespace std;

namespace zorba
{
namespace parser
{
  extern const char *the_tumbling, *the_sliding, *the_start, *the_end, *the_only_end, *the_ofor, *the_declare, *the_create;
}
}

#define YYDEBUG 1

using namespace zorba;



/* Line 311 of lalr1.cc  */
#line 77 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"


#include "xquery_parser.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 834 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 317 of lalr1.cc  */
#line 959 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"

#include "compiler/parser/xquery_driver.h"
#include "compiler/parser/xquery_scanner.h"
#undef yylex
#define yylex driver.lexer->lex


/* Line 317 of lalr1.cc  */
#line 106 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"

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
#line 175 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
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
        case 102: /* "\"'DECIMAL'\"" */

/* Line 480 of lalr1.cc  */
#line 830 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 282 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 114: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 829 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 291 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 139: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 828 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 300 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 317: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 309 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 318: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 318 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 319: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 327 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 320: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 336 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 321: /* "Prolog" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 345 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 322: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 354 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 323: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 363 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 324: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 372 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 325: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 381 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 326: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 390 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 399 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 408 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 417 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 426 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 435 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 444 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 453 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 462 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 471 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 480 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 489 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 498 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 507 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 516 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 525 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 534 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 543 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 552 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 561 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 570 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 579 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 588 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 597 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 606 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "DeclPropertyList" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 615 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "DeclProperty" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 624 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 633 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "NodeModifier" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 642 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 651 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 660 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 669 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 678 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 687 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 696 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 705 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "Block" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 714 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "BlockDecls" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 723 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "BlockVarDeclList" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 732 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "BlockVarDecl" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 741 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "AssignExpr" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 750 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "ExitExpr" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 759 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "WhileExpr" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 768 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 777 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 786 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 795 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "FunctionDecl3" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 804 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "FunctionDecl4" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 813 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 822 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 831 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 840 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "EnclosedExpr" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 849 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 858 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 867 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 876 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "ApplyExpr" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 885 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "ConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 894 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 903 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 912 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 921 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 930 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 939 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 948 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 957 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 966 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 975 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 984 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 993 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1002 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1011 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1020 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1029 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "EvalVarDeclList" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1038 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1047 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1056 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1065 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1074 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1083 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "EvalVarDecl" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1092 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1101 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1110 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1119 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1128 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1137 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1146 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1155 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1164 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1173 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1182 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1191 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1200 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1209 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1218 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1227 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1236 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1245 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1254 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1263 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1272 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1281 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1290 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1299 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1308 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1317 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1326 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1335 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1344 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1353 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1362 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1371 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1380 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1389 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1398 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1407 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1416 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1425 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1434 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1443 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1452 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1461 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1470 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1479 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1488 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1497 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1506 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1515 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1524 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1533 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1542 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1551 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1560 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1569 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1578 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1587 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1596 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1605 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1614 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1623 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1632 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1641 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1650 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1659 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1668 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1677 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1686 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1695 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1704 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1713 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1722 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1731 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1740 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1749 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1758 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1767 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1776 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1785 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1794 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1803 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1812 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1821 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1830 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1839 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1848 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1857 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1866 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1875 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1884 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1893 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1902 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1911 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1920 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1929 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1938 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1947 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1956 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1965 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1974 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "AtomicType" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1983 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1992 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2001 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2010 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2019 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2028 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2037 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2046 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2055 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2064 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2073 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2082 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2091 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2100 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2109 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2118 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 534: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2127 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 535: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2136 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 536: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2145 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 537: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2154 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2163 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 539: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2172 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 540: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2181 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 541: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2190 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2199 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 543: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2208 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 544: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 855 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2217 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 547: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2226 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 548: /* "EvalExpr" */

/* Line 480 of lalr1.cc  */
#line 852 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2235 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 550: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2244 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 553: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2253 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 554: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2262 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 555: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2271 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 556: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2280 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 557: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2289 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 558: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2298 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 560: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2307 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 561: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2316 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 562: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2325 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 563: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2334 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 564: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2343 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 565: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2352 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 567: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2361 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 570: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2370 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 571: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2379 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 572: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2388 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 573: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2397 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 574: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2406 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 575: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2415 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 576: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2424 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 577: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2433 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 578: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2442 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 579: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2451 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 580: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2460 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 581: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2469 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 585: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2478 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 588: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2487 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 589: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2496 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 593: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2505 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 594: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2514 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 595: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2523 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 596: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2532 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 597: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2541 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 598: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2550 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 599: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2559 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 600: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2568 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 601: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 849 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2577 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
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
#line 119 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename);
}

/* Line 553 of lalr1.cc  */
#line 2662 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"

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
#line 976 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 985 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 990 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            MainModule *mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
            mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 997 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 1002 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            LibraryModule *lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
            lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
            driver.set_expr( (yyval.node) );
        }
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 1013 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            std::string encoding = "utf-8";
            (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), encoding );
        }
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 1018 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
        }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 1026 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1034 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
        }
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 1042 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LibraryModule(
                LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 1048 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1060 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
            dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
        }
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 1069 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Prolog( LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(2) - (1)].node)), NULL );
        }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 1073 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Prolog( LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(2) - (1)].node)) );
        }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 1077 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1089 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
            sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
            (yyval.node) = sdl;
        }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 1095 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( SIND_DeclList *sdl = static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                sdl->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 1105 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
            vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
            (yyval.node) = vdl;
        }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 1111 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( VFO_DeclList *vdl = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vdl->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 1143 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
         (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
         delete (yysemantic_stack_[(4) - (4)].vstrpair);
       }
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 1148 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
         (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
         delete (yysemantic_stack_[(4) - (4)].vstrpair);
       }
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 1157 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.vstrpair) = new vector<string_pair_t>();
          (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
          delete (yysemantic_stack_[(1) - (1)].strpair);
        }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 1163 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
          delete (yysemantic_stack_[(2) - (2)].strpair);
          (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
        }
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 1172 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
            (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval() );
            delete sl;
        }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 1180 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 1181 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 1182 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 1183 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 1184 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 1185 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 1186 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 1187 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 1188 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 1189 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 1220 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
        }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 1229 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BoundarySpaceDecl(
                LOC((yyloc)), StaticContextConsts::preserve_space
            );
        }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 1235 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BoundarySpaceDecl(
                LOC((yyloc)), StaticContextConsts::strip_space
            );
        }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 1245 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultNamespaceDecl(
                LOC((yyloc)), ParseConstants::ns_element_default, SYMTAB((yysemantic_stack_[(5) - (5)].sval))
            );
        }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 1251 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultNamespaceDecl(
                LOC((yyloc)), ParseConstants::ns_function_default, SYMTAB((yysemantic_stack_[(5) - (5)].sval))
            );
        }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 1261 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OptionDecl(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval))
            );
        }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 1271 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new FTOptionDecl( LOC((yyloc)), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 1279 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OrderingModeDecl(
                LOC((yyloc)), StaticContextConsts::ordered
            );
        }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 1285 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new OrderingModeDecl(
                LOC((yyloc)), StaticContextConsts::unordered
            );
        }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 1296 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new EmptyOrderDecl( LOC((yyloc)),
                                StaticContextConsts::empty_greatest);
        }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 1301 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new EmptyOrderDecl( LOC((yyloc)),
                                StaticContextConsts::empty_least);
        }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 1311 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::preserve_ns,
                                StaticContextConsts::inherit_ns);
        }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 1317 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::preserve_ns,
                                StaticContextConsts::no_inherit_ns);
        }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 1323 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::no_preserve_ns,
                                StaticContextConsts::inherit_ns);
        }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 1329 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new CopyNamespacesDecl( LOC((yyloc)),
                                StaticContextConsts::no_preserve_ns,
                                StaticContextConsts::no_inherit_ns);
        }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 1346 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
        }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 1354 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 1362 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
        }
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 1366 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1375 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1384 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1397 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            URILiteralList *ull = new URILiteralList( LOC((yyloc)));
            ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.node) = ull;
        }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 1403 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
                ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 1414 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 1418 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
        }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 1426 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 1431 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 1436 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), 
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 1443 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1456 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
        }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 1463 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            CtxItemDecl *d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
            d->type = (yysemantic_stack_[(3) - (2)].node);
            (yyval.node) = d;
        }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 1469 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 1476 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            CtxItemDecl *d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
            d->ext = false;
            (yyval.node) = d;
        }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 1482 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CtxItemDecl( LOC((yyloc)), NULL );
        }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 1486 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 1493 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CtxItemDecl( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 1504 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 1508 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 1516 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(5) - (3)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, (yysemantic_stack_[(5) - (5)].expr));
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (1)].sval)));
    }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 1522 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(4) - (3)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, NULL, true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(4) - (1)].sval)));
    }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 1528 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(6) - (3)].varnametype)));
      (yyval.node) = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, (yysemantic_stack_[(6) - (6)].expr), true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (1)].sval)));
    }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 1537 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            DeclPropertyList *dpl = new DeclPropertyList( LOC((yyloc)) );
            dpl->addProperty(dynamic_cast<DeclProperty*>((yysemantic_stack_[(1) - (1)].node)));
            (yyval.node) = dpl;
        }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 1543 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
        DeclPropertyList *dpl = dynamic_cast<DeclPropertyList*>((yysemantic_stack_[(2) - (1)].node));
        dpl->addProperty( static_cast<DeclProperty*>((yysemantic_stack_[(2) - (2)].node)) );
        (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 1552 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_const );
        }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 1556 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_append_only
            );
        }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 1562 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_queue );
        }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 1566 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_mutable );
        }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 1570 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_ordered );
        }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 1574 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_unordered
            );
        }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 1580 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_value_equality
            );
        }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 1586 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_value_range
            );
        }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 1592 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_unique );
        }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 1596 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_non_unique
            );
        }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 1602 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty(
                LOC((yyloc)), StaticContextConsts::decl_automatic
            );
        }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 1608 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DeclProperty( LOC((yyloc)), StaticContextConsts::decl_manual );
        }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 1615 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)),
                              0,
                              0,
                              0);
    }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 1623 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              0,
                              static_cast<NodeModifier*>((yysemantic_stack_[(4) - (4)].node)),
                              0);
    }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 1631 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                              0,
                              0,
                              static_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 1639 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                              0,
                              static_cast<NodeModifier*>((yysemantic_stack_[(6) - (6)].node)),
                              static_cast<SequenceType*>((yysemantic_stack_[(6) - (5)].node)));
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 1647 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                               static_cast<DeclPropertyList*>((yysemantic_stack_[(4) - (2)].node)), 0, 0);
    }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 1653 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                               static_cast<DeclPropertyList*>((yysemantic_stack_[(5) - (2)].node)),
                               static_cast<NodeModifier*>((yysemantic_stack_[(5) - (5)].node)),
                               0);
    }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 1661 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(6) - (4)].expr)),
                               static_cast<DeclPropertyList*>((yysemantic_stack_[(6) - (2)].node)),
                               0,
                               static_cast<SequenceType*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 1669 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(7) - (4)].expr)),
                               static_cast<DeclPropertyList*>((yysemantic_stack_[(7) - (2)].node)),
                               static_cast<NodeModifier*>((yysemantic_stack_[(7) - (7)].node)),
                               static_cast<SequenceType*>((yysemantic_stack_[(7) - (6)].node)));
    }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 1680 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = static_cast<parsenode*>(
           new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 1685 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = static_cast<parsenode*>(
           new SequenceType( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 1693 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier( LOC((yyloc)), StaticContextConsts::read_only);
    }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 1697 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier( LOC((yyloc)), StaticContextConsts::mutable_node);
    }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 1704 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexDecl( LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(8) - (3)].expr)),
                         (yysemantic_stack_[(8) - (6)].expr),
                         dynamic_cast<IndexKeyList*>((yysemantic_stack_[(8) - (8)].node)),
                         new DeclPropertyList( LOC((yyloc))));
    }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 1712 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexDecl( LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(9) - (4)].expr)),
                         (yysemantic_stack_[(9) - (7)].expr),
                         dynamic_cast<IndexKeyList*>((yysemantic_stack_[(9) - (9)].node)),
                         dynamic_cast<DeclPropertyList*>((yysemantic_stack_[(9) - (2)].node)));
    }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 1723 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList( LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 1729 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 1737 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec( LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<AtomicType*>((yysemantic_stack_[(3) - (3)].node)),
                            NULL);
    }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 1744 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec( LOC((yyloc)),
                            (yysemantic_stack_[(4) - (1)].expr),
                            dynamic_cast<AtomicType*>((yysemantic_stack_[(4) - (3)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 1755 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollSimpleCheck( LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (9)].expr)),
                                 (yysemantic_stack_[(11) - (11)].expr));
    }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 1765 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollUniqueKeyCheck( LOC((yyloc)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (4)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (7)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (10)].expr)),
                                    (yysemantic_stack_[(14) - (14)].expr));
    }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 1775 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollForeachNode( LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (11)].expr)),
                                 (yysemantic_stack_[(13) - (13)].expr));
    }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 1786 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
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

  case 137:

/* Line 678 of lalr1.cc  */
#line 1801 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ConstructionDecl(
                LOC((yyloc)), StaticContextConsts::cons_preserve
            );
        }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 1807 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ConstructionDecl(
                LOC((yyloc)), StaticContextConsts::cons_strip
            );
        }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 1818 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( NULL );
        }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 1822 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 1826 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig( NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)) );
        }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1830 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.fnsig) = new FunctionSig(
                dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 1839 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(2) - (2)].expr);
        }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 1846 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
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

  case 145:

/* Line 678 of lalr1.cc  */
#line 1865 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vfo = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node));
            std::auto_ptr<VFO_DeclList> vfo2( dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)) );
            if ( !(yysemantic_stack_[(3) - (1)].node) )
                vfo = new VFO_DeclList( LOC((yyloc)) );
            vfo->push_back( *vfo2.get() );
            (yyval.node) = vfo;
        }
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 1874 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 1881 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vfo = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node));
            vfo->push_back( (yysemantic_stack_[(3) - (3)].node) );
            (yyval.node) = vfo;
        }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 1887 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList *vfo = new VFO_DeclList( LOC((yyloc)) );
            vfo->push_back((yysemantic_stack_[(2) - (2)].node));
            (yyval.node) = vfo;
        }
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 1897 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(1) - (1)].varnametype)));
      VarDecl* vd = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, NULL);
      vd->set_global(false);
      (yyval.node) = vd;
    }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 1904 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(3) - (1)].varnametype)));
      VarDecl* vd = new VarDecl(LOC((yyloc)), nt->theName, nt->theType, (yysemantic_stack_[(3) - (3)].expr));
      vd->set_global(false);
      (yyval.node) = vd;
        }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 1915 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AssignExpr(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr))->get_qname(), (yysemantic_stack_[(5) - (5)].expr)
            );
            delete (yysemantic_stack_[(5) - (3)].expr);
        }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 1925 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExitExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 1932 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            BlockBody *bb = dynamic_cast<BlockBody *>((yysemantic_stack_[(5) - (5)].expr));
            if ( !bb ) {
                bb = new BlockBody( (yysemantic_stack_[(5) - (5)].expr)->get_location() );
                bb->add((yysemantic_stack_[(5) - (5)].expr));
            }
            (yyval.expr) = new WhileExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), bb );
        }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 1944 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::BREAK );
        }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 1948 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
        }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 1955 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            dynamic_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 157:

/* Line 678 of lalr1.cc  */
#line 1960 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            FunctionDecl *fd = dynamic_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));
            fd->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );
            fd->deterministic = false;
            (yyval.node) = fd;
        }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 1967 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            dynamic_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node))->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );
            (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
        }
    break;

  case 159:

/* Line 678 of lalr1.cc  */
#line 1975 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 1979 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 1983 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl *fd = dynamic_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node));
      fd->type = (fd->type == ParseConstants::fn_extern ?
                  ParseConstants::fn_extern_update :
                  ParseConstants::fn_update);
      (yyval.node) = fd;
    }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 1991 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 1999 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
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

  case 164:

/* Line 678 of lalr1.cc  */
#line 2009 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
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

  case 165:

/* Line 678 of lalr1.cc  */
#line 2023 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
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

  case 166:

/* Line 678 of lalr1.cc  */
#line 2033 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
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

  case 167:

/* Line 678 of lalr1.cc  */
#line 2047 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC ((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                            &* (yysemantic_stack_[(6) - (3)].fnsig)->param, &* (yysemantic_stack_[(6) - (3)].fnsig)->ret,
                            (yysemantic_stack_[(6) - (5)].expr),
                            ParseConstants::fn_read);
      delete (yysemantic_stack_[(6) - (3)].fnsig);
    }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 2056 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
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

  case 169:

/* Line 678 of lalr1.cc  */
#line 2071 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            ParamList *pl = new ParamList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 2077 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
                pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 2089 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 2093 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 2104 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new EnclosedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 2111 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 2119 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QueryBody( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 2134 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 2138 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            std::auto_ptr<BlockBody> blk( dynamic_cast<BlockBody*>((yysemantic_stack_[(2) - (2)].expr)) );
            BlockBody *blk2 = new BlockBody( LOC((yyloc)) );
            blk2->add( (yysemantic_stack_[(2) - (1)].expr) );

            for ( int i = 0; i < blk->size(); ++i )
                blk2->add( (*blk)[i] );

            (yyval.expr) = blk2;
        }
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 2152 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new BlockBody( LOC((yyloc)) );
        }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 2156 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            BlockBody *bb = dynamic_cast<BlockBody*>((yysemantic_stack_[(3) - (1)].expr));
            bb->add( (yysemantic_stack_[(3) - (2)].expr) );
            (yyval.expr) = bb;
        }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 2165 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 2169 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
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

  case 199:

/* Line 678 of lalr1.cc  */
#line 2209 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
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

  case 200:

/* Line 678 of lalr1.cc  */
#line 2224 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 2231 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_sliding;
        }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 2235 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_tumbling;
        }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 2242 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_start;
        }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 2246 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_end;
        }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 2250 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_only_end;
        }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 2257 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FLWORWinCond(
                LOC((yyloc)),
                dynamic_cast<WindowVars*>((yysemantic_stack_[(4) - (2)].node)), (yysemantic_stack_[(4) - (4)].expr),
                (yysemantic_stack_[(4) - (1)].strval) == parser::the_start, (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end
            );
        }
    break;

  case 207:

/* Line 678 of lalr1.cc  */
#line 2265 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FLWORWinCond(
                LOC((yyloc)), NULL, (yysemantic_stack_[(3) - (3)].expr),
                (yysemantic_stack_[(3) - (1)].strval) == parser::the_start, (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end
            );
        }
    break;

  case 208:

/* Line 678 of lalr1.cc  */
#line 2276 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
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

  case 209:

/* Line 678 of lalr1.cc  */
#line 2286 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling ?
                              WindowClause::tumbling_window :
                              WindowClause::sliding_window),
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    }
    break;

  case 210:

/* Line 678 of lalr1.cc  */
#line 2299 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 2321 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
            fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = fcl;
        }
    break;

  case 220:

/* Line 678 of lalr1.cc  */
#line 2327 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
            fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = fcl;
        }
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 2336 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = NULL;
        }
    break;

  case 222:

/* Line 678 of lalr1.cc  */
#line 2340 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.strval) = parser::the_ofor;
        }
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 2348 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForClause(
                LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(2) - (2)].node)), (yysemantic_stack_[(2) - (1)].strval) != NULL
            );
        }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 2358 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            VarInDeclList *vdl = new VarInDeclList( LOC((yyloc)) );
            vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vdl;
        }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 2364 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( VarInDeclList *vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 2376 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 2380 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                         NULL,NULL,
                         (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 2388 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         NULL,
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(4) - (2)].node)),
                         NULL,
                         (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 2397 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (3)].node)),
                         NULL,
                         (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 2407 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         NULL,NULL,
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
                         (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 2415 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
                         NULL,
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
                         (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 2424 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC ((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)),
                         NULL,
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (2)].node)),
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
                         (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 2433 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC ((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(6) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (2)].node)),
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(6) - (3)].node)),
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
                         (yysemantic_stack_[(6) - (6)].expr));
    }
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 2448 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 2457 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
    }
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 2467 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (3)].node)) );
        }
    break;

  case 237:

/* Line 678 of lalr1.cc  */
#line 2475 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 238:

/* Line 678 of lalr1.cc  */
#line 2481 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 239:

/* Line 678 of lalr1.cc  */
#line 2490 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 240:

/* Line 678 of lalr1.cc  */
#line 2496 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 2508 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)),
                           NULL,
                           NULL,
                           (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 2516 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                           NULL,
                           (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 243:

/* Line 678 of lalr1.cc  */
#line 2526 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                           NULL,
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
                           (yysemantic_stack_[(4) - (4)].expr));
     }
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 2534 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
                           (yysemantic_stack_[(5) - (5)].expr));
     }
    break;

  case 245:

/* Line 678 of lalr1.cc  */
#line 2546 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 2552 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 2565 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 2569 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 2577 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 2581 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 2590 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 2594 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 2598 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 256:

/* Line 678 of lalr1.cc  */
#line 2606 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      std::string name = static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr))->get_qname();
      (yyval.node) = new VarGetsDecl(LOC((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)),
                           NULL, NULL,
                           new VarRef(LOC((yyloc)), name),
                           VarGetsDecl::eval_var);
    }
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 2621 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 2629 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 2636 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = new GroupSpecList( LOC((yyloc)) );
            gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 2642 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            GroupSpecList *gsl = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
            if ( gsl )
                gsl->push_back( dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = gsl;
        }
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 2653 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 2657 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                         dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 2666 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 2674 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 2680 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 2690 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 2696 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 2706 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 2710 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 2720 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 2726 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 2732 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 2738 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
                NULL
            );
        }
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 2747 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                NULL,
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 2756 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                NULL,
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 2765 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 2778 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 2782 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 2790 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 2796 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 2806 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 2814 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_some,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 2823 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_every,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 2836 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
            qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = qvidl;

        }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 2843 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
            qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 2855 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 2859 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 2872 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 2879 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 2892 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 2898 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 2910 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 2916 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 2928 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 2937 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 2941 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 2950 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 2954 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 2962 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 2966 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
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

  case 301:

/* Line 678 of lalr1.cc  */
#line 2976 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 2983 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_eq ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 2992 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ne ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 3001 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 3006 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_lt ),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr)
            );
        }
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 3015 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_le ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 3024 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_gt ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 3033 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ge ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 3046 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 3050 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FTContainsExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node)),
                dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 3061 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 3065 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 3073 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 3077 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 3086 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 3090 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 3094 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 3103 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 3107 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 3113 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 3119 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 3125 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 3136 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 3140 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 3144 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 3152 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 3156 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 3162 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 3172 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 3176 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 3186 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 3190 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 3200 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 3204 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 3214 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 3218 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 3228 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 3232 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 3240 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 3244 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 3248 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 3252 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 3262 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 3266 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 3270 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 3278 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 3282 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 3286 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 3290 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 3294 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 3298 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 3306 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 3310 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 3314 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 3322 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 3326 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 3330 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 3334 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
        }
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 3344 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 3350 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 3360 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 3366 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 3376 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 3380 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 3418 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new PathExpr(
                LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL
            );
        }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 3424 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new PathExpr(
                LOC((yyloc)), ParseConstants::path_leading_slash, (yysemantic_stack_[(2) - (2)].expr)
            );
        }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 3430 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new PathExpr(
                LOC((yyloc)), ParseConstants::path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr)
            );
        }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 3436 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            RelativePathExpr *rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = !rpe ?
                (yysemantic_stack_[(1) - (1)].expr) : new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 3447 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NULL;
        }
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 3455 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
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

  case 371:

/* Line 678 of lalr1.cc  */
#line 3466 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RelativePathExpr(
                LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 3472 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RelativePathExpr(
                LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 3482 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 3486 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 3494 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 3500 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 3508 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 3514 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 3526 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 3532 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 3542 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 3546 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 3550 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 3554 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 3558 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 3564 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 3570 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 3578 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 3582 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 3590 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 3594 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 3605 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 3609 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 3613 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 3619 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 3623 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 3637 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 3641 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 3649 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 3653 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 3663 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all);
    }
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 3667 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem);
    }
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 3671 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix);
    }
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 3680 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 3684 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FilterExpr(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 3690 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
        }
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 3694 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
        }
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 3702 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 3708 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 3718 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 3726 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 3730 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 3734 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 3738 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 3742 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 3746 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 3750 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 3754 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 3758 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 3766 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 3770 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 3778 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 3785 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 3792 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 3803 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname() );
            delete (yysemantic_stack_[(2) - (2)].expr);
        }
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 3812 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 3816 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 3824 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 3832 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 3840 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 3894 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
        }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 3898 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 3910 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            ArgList *al = new ArgList( LOC((yyloc)) );
            al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
            (yyval.node) = al;
        }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 3916 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
                al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 3926 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 3930 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 3938 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 3942 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 3946 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 3954 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
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

  case 441:

/* Line 678 of lalr1.cc  */
#line 3964 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
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

  case 442:

/* Line 678 of lalr1.cc  */
#line 3974 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
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

  case 443:

/* Line 678 of lalr1.cc  */
#line 3984 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
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

  case 444:

/* Line 678 of lalr1.cc  */
#line 3994 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
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

  case 445:

/* Line 678 of lalr1.cc  */
#line 4004 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
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

  case 446:

/* Line 678 of lalr1.cc  */
#line 4019 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
            decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = decl;
        }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 4025 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( decl )
                decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 4036 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
            dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = dal;
        }
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 4042 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
            if ( dal )
                dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 4053 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttr(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node))
            );
        }
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 4070 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 4075 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 4084 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
        }
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 4088 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 4095 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back(
                new QuoteAttrValueContent( LOC((yyloc)),std::string("\"") )
            );
            (yyval.node) = qacl;
        }
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 4103 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = qacl;
        }
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 4109 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
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

  case 460:

/* Line 678 of lalr1.cc  */
#line 4119 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 4131 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
        }
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 4135 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 4142 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = aacl;
        }
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 4148 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = aacl;
        }
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 4154 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if (aacl)
                aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 4161 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( aacl )
                aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 4172 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 4176 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 4186 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 4190 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 471:

/* Line 678 of lalr1.cc  */
#line 4200 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 472:

/* Line 678 of lalr1.cc  */
#line 4204 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 473:

/* Line 678 of lalr1.cc  */
#line 4208 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
        }
    break;

  case 474:

/* Line 678 of lalr1.cc  */
#line 4213 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
        }
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 4222 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval))
            );
        }
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 4228 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_lbrace
            );
        }
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 4234 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_rbrace
            );
        }
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 4240 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 4250 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 4254 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
        }
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 4266 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
        }
    break;

  case 482:

/* Line 678 of lalr1.cc  */
#line 4270 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 4282 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 4294 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 4298 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 4302 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 4306 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 4310 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 4314 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 4322 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 4330 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)), NULL
            );
        }
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 4336 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr)
            );
        }
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 4342 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 4346 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 4363 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (2)].expr), NULL );
        }
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 4367 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(5) - (2)].expr), (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 4371 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 4375 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 4383 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 4391 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 4399 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), NULL );
        }
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 4403 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (2)].sval)), (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 4407 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), NULL );
        }
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 4411 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 4419 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)), false
            );
        }
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 4425 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)), true
            );
        }
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 4435 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 4443 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 509:

/* Line 678 of lalr1.cc  */
#line 4447 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 510:

/* Line 678 of lalr1.cc  */
#line 4453 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 511:

/* Line 678 of lalr1.cc  */
#line 4488 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 512:

/* Line 678 of lalr1.cc  */
#line 4494 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 4500 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 4510 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 4514 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 4518 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)),true );
        }
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 4522 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 4526 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 4533 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back((yysemantic_stack_[(1) - (1)].node));
          (yyval.node) = aTypeList;
        }
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 4539 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          if (aTypeList) aTypeList->push_back((yysemantic_stack_[(3) - (3)].node));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 521:

/* Line 678 of lalr1.cc  */
#line 4549 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 522:

/* Line 678 of lalr1.cc  */
#line 4557 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 4561 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 4565 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 4569 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 526:

/* Line 678 of lalr1.cc  */
#line 4573 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 4577 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 4581 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 4585 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 4589 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 4597 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyKindTest( LOC((yyloc)) );
        }
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 4605 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)) );
        }
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 4609 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)) );
        }
    break;

  case 534:

/* Line 678 of lalr1.cc  */
#line 4613 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest(
                LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 4623 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TextTest( LOC((yyloc)) );
        }
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 4631 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CommentTest( LOC((yyloc)));
        }
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 4639 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 4643 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 4647 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 4655 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 4659 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 542:

/* Line 678 of lalr1.cc  */
#line 4665 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 543:

/* Line 678 of lalr1.cc  */
#line 4671 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 544:

/* Line 678 of lalr1.cc  */
#line 4675 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 4685 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)) );
        }
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 4693 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 4697 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 4703 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 549:

/* Line 678 of lalr1.cc  */
#line 4712 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 550:

/* Line 678 of lalr1.cc  */
#line 4721 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 4727 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 4733 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 4743 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 4760 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 555:

/* Line 678 of lalr1.cc  */
#line 4767 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 556:

/* Line 678 of lalr1.cc  */
#line 4782 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 557:

/* Line 678 of lalr1.cc  */
#line 4818 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 558:

/* Line 678 of lalr1.cc  */
#line 4822 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 559:

/* Line 678 of lalr1.cc  */
#line 4831 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), *(yysemantic_stack_[(3) - (3)].ival));
        }
    break;

  case 560:

/* Line 678 of lalr1.cc  */
#line 4840 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new InlineFunction(LOC ((yyloc)), &*(yysemantic_stack_[(3) - (2)].fnsig)->param, &*(yysemantic_stack_[(3) - (2)].fnsig)->ret, dynamic_cast<EnclosedExpr *>((yysemantic_stack_[(3) - (3)].expr)));
        }
    break;

  case 561:

/* Line 678 of lalr1.cc  */
#line 4849 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 562:

/* Line 678 of lalr1.cc  */
#line 4853 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 563:

/* Line 678 of lalr1.cc  */
#line 4862 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
        }
    break;

  case 564:

/* Line 678 of lalr1.cc  */
#line 4871 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 565:

/* Line 678 of lalr1.cc  */
#line 4875 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)), dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 566:

/* Line 678 of lalr1.cc  */
#line 4884 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 567:

/* Line 678 of lalr1.cc  */
#line 4901 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 568:

/* Line 678 of lalr1.cc  */
#line 4907 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 569:

/* Line 678 of lalr1.cc  */
#line 4913 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 570:

/* Line 678 of lalr1.cc  */
#line 4923 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 571:

/* Line 678 of lalr1.cc  */
#line 4927 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 572:

/* Line 678 of lalr1.cc  */
#line 4933 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 573:

/* Line 678 of lalr1.cc  */
#line 4939 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 574:

/* Line 678 of lalr1.cc  */
#line 4943 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 575:

/* Line 678 of lalr1.cc  */
#line 4949 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 576:

/* Line 678 of lalr1.cc  */
#line 4953 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 577:

/* Line 678 of lalr1.cc  */
#line 4959 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 578:

/* Line 678 of lalr1.cc  */
#line 4965 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 579:

/* Line 678 of lalr1.cc  */
#line 4972 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 580:

/* Line 678 of lalr1.cc  */
#line 4982 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 581:

/* Line 678 of lalr1.cc  */
#line 4987 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 582:

/* Line 678 of lalr1.cc  */
#line 4995 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 583:

/* Line 678 of lalr1.cc  */
#line 5001 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 584:

/* Line 678 of lalr1.cc  */
#line 5011 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 585:

/* Line 678 of lalr1.cc  */
#line 5033 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 586:

/* Line 678 of lalr1.cc  */
#line 5042 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 587:

/* Line 678 of lalr1.cc  */
#line 5048 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 588:

/* Line 678 of lalr1.cc  */
#line 5061 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 589:

/* Line 678 of lalr1.cc  */
#line 5075 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 590:

/* Line 678 of lalr1.cc  */
#line 5082 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 591:

/* Line 678 of lalr1.cc  */
#line 5088 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 592:

/* Line 678 of lalr1.cc  */
#line 5098 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), NULL, NULL, NULL, (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 593:

/* Line 678 of lalr1.cc  */
#line 5103 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CatchExpr(LOC((yyloc)),*(yysemantic_stack_[(7) - (2)].name_test_list), static_cast<QName*>((yysemantic_stack_[(7) - (5)].expr)), NULL, NULL, (yysemantic_stack_[(7) - (7)].expr));
       delete (yysemantic_stack_[(7) - (2)].name_test_list);
    }
    break;

  case 594:

/* Line 678 of lalr1.cc  */
#line 5109 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
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

  case 595:

/* Line 678 of lalr1.cc  */
#line 5119 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
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

  case 596:

/* Line 678 of lalr1.cc  */
#line 5132 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 597:

/* Line 678 of lalr1.cc  */
#line 5138 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 600:

/* Line 678 of lalr1.cc  */
#line 5159 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
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

  case 601:

/* Line 678 of lalr1.cc  */
#line 5177 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 602:

/* Line 678 of lalr1.cc  */
#line 5181 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 603:

/* Line 678 of lalr1.cc  */
#line 5194 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new EvalExpr(
                LOC((yyloc)), dynamic_cast<VarGetsDeclList *> ((yysemantic_stack_[(7) - (3)].node)), (yysemantic_stack_[(7) - (6)].expr)
            );
        }
    break;

  case 604:

/* Line 678 of lalr1.cc  */
#line 5200 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new EvalExpr( LOC((yyloc)), new VarGetsDeclList( LOC((yyloc)) ), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 605:

/* Line 678 of lalr1.cc  */
#line 5206 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("xquery"); }
    break;

  case 606:

/* Line 678 of lalr1.cc  */
#line 5207 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("empty"); }
    break;

  case 607:

/* Line 678 of lalr1.cc  */
#line 5208 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("attribute"); }
    break;

  case 608:

/* Line 678 of lalr1.cc  */
#line 5209 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("comment"); }
    break;

  case 609:

/* Line 678 of lalr1.cc  */
#line 5210 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("document-node"); }
    break;

  case 610:

/* Line 678 of lalr1.cc  */
#line 5211 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("element"); }
    break;

  case 611:

/* Line 678 of lalr1.cc  */
#line 5212 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("item"); }
    break;

  case 612:

/* Line 678 of lalr1.cc  */
#line 5213 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("if"); }
    break;

  case 613:

/* Line 678 of lalr1.cc  */
#line 5214 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("node"); }
    break;

  case 614:

/* Line 678 of lalr1.cc  */
#line 5215 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("processing-instruction"); }
    break;

  case 615:

/* Line 678 of lalr1.cc  */
#line 5216 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("schema-attribute"); }
    break;

  case 616:

/* Line 678 of lalr1.cc  */
#line 5217 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("schema-element"); }
    break;

  case 617:

/* Line 678 of lalr1.cc  */
#line 5218 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("text"); }
    break;

  case 618:

/* Line 678 of lalr1.cc  */
#line 5219 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("typeswitch"); }
    break;

  case 619:

/* Line 678 of lalr1.cc  */
#line 5220 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("empty-sequence"); }
    break;

  case 620:

/* Line 678 of lalr1.cc  */
#line 5221 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("boundary-space"); }
    break;

  case 621:

/* Line 678 of lalr1.cc  */
#line 5222 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ft-option"); }
    break;

  case 622:

/* Line 678 of lalr1.cc  */
#line 5223 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("base-uri"); }
    break;

  case 623:

/* Line 678 of lalr1.cc  */
#line 5224 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("lax"); }
    break;

  case 624:

/* Line 678 of lalr1.cc  */
#line 5225 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("strict"); }
    break;

  case 625:

/* Line 678 of lalr1.cc  */
#line 5226 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("idiv"); }
    break;

  case 626:

/* Line 678 of lalr1.cc  */
#line 5227 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("document"); }
    break;

  case 627:

/* Line 678 of lalr1.cc  */
#line 5228 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("not"); }
    break;

  case 628:

/* Line 678 of lalr1.cc  */
#line 5229 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("sensitive"); }
    break;

  case 629:

/* Line 678 of lalr1.cc  */
#line 5230 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("insensitive"); }
    break;

  case 630:

/* Line 678 of lalr1.cc  */
#line 5231 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("diacritics"); }
    break;

  case 631:

/* Line 678 of lalr1.cc  */
#line 5232 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("without"); }
    break;

  case 632:

/* Line 678 of lalr1.cc  */
#line 5233 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("stemming"); }
    break;

  case 633:

/* Line 678 of lalr1.cc  */
#line 5234 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("thesaurus"); }
    break;

  case 634:

/* Line 678 of lalr1.cc  */
#line 5235 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("stop"); }
    break;

  case 635:

/* Line 678 of lalr1.cc  */
#line 5236 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("wildcards"); }
    break;

  case 636:

/* Line 678 of lalr1.cc  */
#line 5237 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("entire"); }
    break;

  case 637:

/* Line 678 of lalr1.cc  */
#line 5238 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("content"); }
    break;

  case 638:

/* Line 678 of lalr1.cc  */
#line 5239 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("word"); }
    break;

  case 639:

/* Line 678 of lalr1.cc  */
#line 5240 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("start"); }
    break;

  case 640:

/* Line 678 of lalr1.cc  */
#line 5241 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("end"); }
    break;

  case 641:

/* Line 678 of lalr1.cc  */
#line 5242 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("most"); }
    break;

  case 642:

/* Line 678 of lalr1.cc  */
#line 5243 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("skip"); }
    break;

  case 643:

/* Line 678 of lalr1.cc  */
#line 5244 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("copy"); }
    break;

  case 644:

/* Line 678 of lalr1.cc  */
#line 5245 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("value"); }
    break;

  case 645:

/* Line 678 of lalr1.cc  */
#line 5246 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("eq"); }
    break;

  case 646:

/* Line 678 of lalr1.cc  */
#line 5247 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ne"); }
    break;

  case 647:

/* Line 678 of lalr1.cc  */
#line 5248 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("lt"); }
    break;

  case 648:

/* Line 678 of lalr1.cc  */
#line 5249 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("le"); }
    break;

  case 649:

/* Line 678 of lalr1.cc  */
#line 5250 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("gt"); }
    break;

  case 650:

/* Line 678 of lalr1.cc  */
#line 5251 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ge"); }
    break;

  case 651:

/* Line 678 of lalr1.cc  */
#line 5252 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("at"); }
    break;

  case 652:

/* Line 678 of lalr1.cc  */
#line 5253 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("context"); }
    break;

  case 653:

/* Line 678 of lalr1.cc  */
#line 5254 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("variable"); }
    break;

  case 654:

/* Line 678 of lalr1.cc  */
#line 5255 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("return"); }
    break;

  case 655:

/* Line 678 of lalr1.cc  */
#line 5256 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("for"); }
    break;

  case 656:

/* Line 678 of lalr1.cc  */
#line 5257 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("outer"); }
    break;

  case 657:

/* Line 678 of lalr1.cc  */
#line 5258 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("sliding"); }
    break;

  case 658:

/* Line 678 of lalr1.cc  */
#line 5259 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("tumbling"); }
    break;

  case 659:

/* Line 678 of lalr1.cc  */
#line 5260 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("previous"); }
    break;

  case 660:

/* Line 678 of lalr1.cc  */
#line 5261 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("next"); }
    break;

  case 661:

/* Line 678 of lalr1.cc  */
#line 5262 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("only"); }
    break;

  case 662:

/* Line 678 of lalr1.cc  */
#line 5263 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("when"); }
    break;

  case 663:

/* Line 678 of lalr1.cc  */
#line 5264 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("count"); }
    break;

  case 664:

/* Line 678 of lalr1.cc  */
#line 5265 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("in"); }
    break;

  case 665:

/* Line 678 of lalr1.cc  */
#line 5266 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("let"); }
    break;

  case 666:

/* Line 678 of lalr1.cc  */
#line 5267 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("where"); }
    break;

  case 667:

/* Line 678 of lalr1.cc  */
#line 5268 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("by"); }
    break;

  case 668:

/* Line 678 of lalr1.cc  */
#line 5269 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("group"); }
    break;

  case 669:

/* Line 678 of lalr1.cc  */
#line 5270 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("order"); }
    break;

  case 670:

/* Line 678 of lalr1.cc  */
#line 5271 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("stable"); }
    break;

  case 671:

/* Line 678 of lalr1.cc  */
#line 5272 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ascending"); }
    break;

  case 672:

/* Line 678 of lalr1.cc  */
#line 5273 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("descending"); }
    break;

  case 673:

/* Line 678 of lalr1.cc  */
#line 5274 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("greatest"); }
    break;

  case 674:

/* Line 678 of lalr1.cc  */
#line 5275 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("least"); }
    break;

  case 675:

/* Line 678 of lalr1.cc  */
#line 5276 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("collation"); }
    break;

  case 676:

/* Line 678 of lalr1.cc  */
#line 5277 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("some"); }
    break;

  case 677:

/* Line 678 of lalr1.cc  */
#line 5278 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("every"); }
    break;

  case 678:

/* Line 678 of lalr1.cc  */
#line 5279 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("satisfies"); }
    break;

  case 679:

/* Line 678 of lalr1.cc  */
#line 5280 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("case"); }
    break;

  case 680:

/* Line 678 of lalr1.cc  */
#line 5281 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("as"); }
    break;

  case 681:

/* Line 678 of lalr1.cc  */
#line 5282 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("then"); }
    break;

  case 682:

/* Line 678 of lalr1.cc  */
#line 5283 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("else"); }
    break;

  case 683:

/* Line 678 of lalr1.cc  */
#line 5284 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("or"); }
    break;

  case 684:

/* Line 678 of lalr1.cc  */
#line 5285 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("and"); }
    break;

  case 685:

/* Line 678 of lalr1.cc  */
#line 5286 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("instance"); }
    break;

  case 686:

/* Line 678 of lalr1.cc  */
#line 5287 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("of"); }
    break;

  case 687:

/* Line 678 of lalr1.cc  */
#line 5288 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("castable"); }
    break;

  case 688:

/* Line 678 of lalr1.cc  */
#line 5289 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("to"); }
    break;

  case 689:

/* Line 678 of lalr1.cc  */
#line 5290 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("div"); }
    break;

  case 690:

/* Line 678 of lalr1.cc  */
#line 5291 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("mod"); }
    break;

  case 691:

/* Line 678 of lalr1.cc  */
#line 5292 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("union"); }
    break;

  case 692:

/* Line 678 of lalr1.cc  */
#line 5293 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("intersect"); }
    break;

  case 693:

/* Line 678 of lalr1.cc  */
#line 5294 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("except"); }
    break;

  case 694:

/* Line 678 of lalr1.cc  */
#line 5295 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("validate"); }
    break;

  case 695:

/* Line 678 of lalr1.cc  */
#line 5296 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("cast"); }
    break;

  case 696:

/* Line 678 of lalr1.cc  */
#line 5297 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("treat"); }
    break;

  case 697:

/* Line 678 of lalr1.cc  */
#line 5298 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("is"); }
    break;

  case 698:

/* Line 678 of lalr1.cc  */
#line 5299 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("preserve"); }
    break;

  case 699:

/* Line 678 of lalr1.cc  */
#line 5300 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("strip"); }
    break;

  case 700:

/* Line 678 of lalr1.cc  */
#line 5301 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("namespace"); }
    break;

  case 701:

/* Line 678 of lalr1.cc  */
#line 5302 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("external"); }
    break;

  case 702:

/* Line 678 of lalr1.cc  */
#line 5303 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("encoding"); }
    break;

  case 703:

/* Line 678 of lalr1.cc  */
#line 5304 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("no-preserve"); }
    break;

  case 704:

/* Line 678 of lalr1.cc  */
#line 5305 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("inherit"); }
    break;

  case 705:

/* Line 678 of lalr1.cc  */
#line 5306 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("no-inherit"); }
    break;

  case 706:

/* Line 678 of lalr1.cc  */
#line 5307 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("declare"); }
    break;

  case 707:

/* Line 678 of lalr1.cc  */
#line 5308 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("construction"); }
    break;

  case 708:

/* Line 678 of lalr1.cc  */
#line 5309 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ordering"); }
    break;

  case 709:

/* Line 678 of lalr1.cc  */
#line 5310 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("default"); }
    break;

  case 710:

/* Line 678 of lalr1.cc  */
#line 5311 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("copy-namespaces"); }
    break;

  case 711:

/* Line 678 of lalr1.cc  */
#line 5312 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("option"); }
    break;

  case 712:

/* Line 678 of lalr1.cc  */
#line 5313 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("version"); }
    break;

  case 713:

/* Line 678 of lalr1.cc  */
#line 5314 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("import"); }
    break;

  case 714:

/* Line 678 of lalr1.cc  */
#line 5315 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("schema"); }
    break;

  case 715:

/* Line 678 of lalr1.cc  */
#line 5316 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("module"); }
    break;

  case 716:

/* Line 678 of lalr1.cc  */
#line 5317 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("function"); }
    break;

  case 717:

/* Line 678 of lalr1.cc  */
#line 5318 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("score"); }
    break;

  case 718:

/* Line 678 of lalr1.cc  */
#line 5319 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ftcontains"); }
    break;

  case 719:

/* Line 678 of lalr1.cc  */
#line 5320 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("weight"); }
    break;

  case 720:

/* Line 678 of lalr1.cc  */
#line 5321 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("window"); }
    break;

  case 721:

/* Line 678 of lalr1.cc  */
#line 5322 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("distance"); }
    break;

  case 722:

/* Line 678 of lalr1.cc  */
#line 5323 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("occurs"); }
    break;

  case 723:

/* Line 678 of lalr1.cc  */
#line 5324 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("times"); }
    break;

  case 724:

/* Line 678 of lalr1.cc  */
#line 5325 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("same"); }
    break;

  case 725:

/* Line 678 of lalr1.cc  */
#line 5326 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("different"); }
    break;

  case 726:

/* Line 678 of lalr1.cc  */
#line 5327 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("lowercase"); }
    break;

  case 727:

/* Line 678 of lalr1.cc  */
#line 5328 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("uppercase"); }
    break;

  case 728:

/* Line 678 of lalr1.cc  */
#line 5329 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("relationship"); }
    break;

  case 729:

/* Line 678 of lalr1.cc  */
#line 5330 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("levels"); }
    break;

  case 730:

/* Line 678 of lalr1.cc  */
#line 5331 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("language"); }
    break;

  case 731:

/* Line 678 of lalr1.cc  */
#line 5332 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("any"); }
    break;

  case 732:

/* Line 678 of lalr1.cc  */
#line 5333 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("all"); }
    break;

  case 733:

/* Line 678 of lalr1.cc  */
#line 5334 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("phrase"); }
    break;

  case 734:

/* Line 678 of lalr1.cc  */
#line 5335 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("exactly"); }
    break;

  case 735:

/* Line 678 of lalr1.cc  */
#line 5336 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("from"); }
    break;

  case 736:

/* Line 678 of lalr1.cc  */
#line 5337 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("words"); }
    break;

  case 737:

/* Line 678 of lalr1.cc  */
#line 5338 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("sentences"); }
    break;

  case 738:

/* Line 678 of lalr1.cc  */
#line 5339 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("sentence"); }
    break;

  case 739:

/* Line 678 of lalr1.cc  */
#line 5340 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("paragraph"); }
    break;

  case 740:

/* Line 678 of lalr1.cc  */
#line 5341 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("replace"); }
    break;

  case 741:

/* Line 678 of lalr1.cc  */
#line 5342 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("modify"); }
    break;

  case 742:

/* Line 678 of lalr1.cc  */
#line 5343 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("first"); }
    break;

  case 743:

/* Line 678 of lalr1.cc  */
#line 5344 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("insert"); }
    break;

  case 744:

/* Line 678 of lalr1.cc  */
#line 5345 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("before"); }
    break;

  case 745:

/* Line 678 of lalr1.cc  */
#line 5346 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("after"); }
    break;

  case 746:

/* Line 678 of lalr1.cc  */
#line 5347 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("revalidation"); }
    break;

  case 747:

/* Line 678 of lalr1.cc  */
#line 5348 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("with"); }
    break;

  case 748:

/* Line 678 of lalr1.cc  */
#line 5349 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("nodes"); }
    break;

  case 749:

/* Line 678 of lalr1.cc  */
#line 5350 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("rename"); }
    break;

  case 750:

/* Line 678 of lalr1.cc  */
#line 5351 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("last"); }
    break;

  case 751:

/* Line 678 of lalr1.cc  */
#line 5352 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("delete"); }
    break;

  case 752:

/* Line 678 of lalr1.cc  */
#line 5353 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("into"); }
    break;

  case 753:

/* Line 678 of lalr1.cc  */
#line 5354 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("simple"); }
    break;

  case 754:

/* Line 678 of lalr1.cc  */
#line 5355 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("sequential"); }
    break;

  case 755:

/* Line 678 of lalr1.cc  */
#line 5356 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("updating"); }
    break;

  case 756:

/* Line 678 of lalr1.cc  */
#line 5357 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("deterministic"); }
    break;

  case 757:

/* Line 678 of lalr1.cc  */
#line 5358 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("nondeterministic"); }
    break;

  case 758:

/* Line 678 of lalr1.cc  */
#line 5359 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("ordered"); }
    break;

  case 759:

/* Line 678 of lalr1.cc  */
#line 5360 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("unordered"); }
    break;

  case 760:

/* Line 678 of lalr1.cc  */
#line 5361 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("returning"); }
    break;

  case 761:

/* Line 678 of lalr1.cc  */
#line 5362 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("block"); }
    break;

  case 762:

/* Line 678 of lalr1.cc  */
#line 5363 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("exit"); }
    break;

  case 763:

/* Line 678 of lalr1.cc  */
#line 5364 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("loop"); }
    break;

  case 764:

/* Line 678 of lalr1.cc  */
#line 5365 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("while"); }
    break;

  case 765:

/* Line 678 of lalr1.cc  */
#line 5366 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("break"); }
    break;

  case 766:

/* Line 678 of lalr1.cc  */
#line 5367 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("continue"); }
    break;

  case 767:

/* Line 678 of lalr1.cc  */
#line 5368 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("try"); }
    break;

  case 768:

/* Line 678 of lalr1.cc  */
#line 5369 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("catch"); }
    break;

  case 769:

/* Line 678 of lalr1.cc  */
#line 5370 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("eval"); }
    break;

  case 770:

/* Line 678 of lalr1.cc  */
#line 5371 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("using"); }
    break;

  case 771:

/* Line 678 of lalr1.cc  */
#line 5372 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("set"); }
    break;

  case 772:

/* Line 678 of lalr1.cc  */
#line 5373 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("index"); }
    break;

  case 773:

/* Line 678 of lalr1.cc  */
#line 5374 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("unique"); }
    break;

  case 774:

/* Line 678 of lalr1.cc  */
#line 5375 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("non"); }
    break;

  case 775:

/* Line 678 of lalr1.cc  */
#line 5376 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("on"); }
    break;

  case 776:

/* Line 678 of lalr1.cc  */
#line 5377 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("range"); }
    break;

  case 777:

/* Line 678 of lalr1.cc  */
#line 5378 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("equality"); }
    break;

  case 778:

/* Line 678 of lalr1.cc  */
#line 5379 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("manually"); }
    break;

  case 779:

/* Line 678 of lalr1.cc  */
#line 5380 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("automatically"); }
    break;

  case 780:

/* Line 678 of lalr1.cc  */
#line 5381 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("maintained"); }
    break;

  case 781:

/* Line 678 of lalr1.cc  */
#line 5382 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("decimal-format"); }
    break;

  case 782:

/* Line 678 of lalr1.cc  */
#line 5383 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("decimal-separator"); }
    break;

  case 783:

/* Line 678 of lalr1.cc  */
#line 5384 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("grouping-separator"); }
    break;

  case 784:

/* Line 678 of lalr1.cc  */
#line 5385 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("infinity"); }
    break;

  case 785:

/* Line 678 of lalr1.cc  */
#line 5386 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("minus-sign"); }
    break;

  case 786:

/* Line 678 of lalr1.cc  */
#line 5387 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("NaN"); }
    break;

  case 787:

/* Line 678 of lalr1.cc  */
#line 5388 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("percent"); }
    break;

  case 788:

/* Line 678 of lalr1.cc  */
#line 5389 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("per-mille"); }
    break;

  case 789:

/* Line 678 of lalr1.cc  */
#line 5390 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("zero-digit"); }
    break;

  case 790:

/* Line 678 of lalr1.cc  */
#line 5391 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("digit"); }
    break;

  case 791:

/* Line 678 of lalr1.cc  */
#line 5392 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("pattern-separator"); }
    break;

  case 792:

/* Line 678 of lalr1.cc  */
#line 5393 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("collection"); }
    break;

  case 793:

/* Line 678 of lalr1.cc  */
#line 5394 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("const"); }
    break;

  case 794:

/* Line 678 of lalr1.cc  */
#line 5395 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("append-only"); }
    break;

  case 795:

/* Line 678 of lalr1.cc  */
#line 5396 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("queue"); }
    break;

  case 796:

/* Line 678 of lalr1.cc  */
#line 5397 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("mutable"); }
    break;

  case 797:

/* Line 678 of lalr1.cc  */
#line 5398 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("read-only"); }
    break;

  case 798:

/* Line 678 of lalr1.cc  */
#line 5399 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("integrity"); }
    break;

  case 799:

/* Line 678 of lalr1.cc  */
#line 5400 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("constraint"); }
    break;

  case 800:

/* Line 678 of lalr1.cc  */
#line 5401 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("check"); }
    break;

  case 801:

/* Line 678 of lalr1.cc  */
#line 5402 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("key"); }
    break;

  case 802:

/* Line 678 of lalr1.cc  */
#line 5403 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("foreach"); }
    break;

  case 803:

/* Line 678 of lalr1.cc  */
#line 5404 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("foreign"); }
    break;

  case 804:

/* Line 678 of lalr1.cc  */
#line 5405 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT("keys"); }
    break;

  case 805:

/* Line 678 of lalr1.cc  */
#line 5418 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), dynamic_cast<FTOr*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 806:

/* Line 678 of lalr1.cc  */
#line 5426 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 807:

/* Line 678 of lalr1.cc  */
#line 5430 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 808:

/* Line 678 of lalr1.cc  */
#line 5437 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 809:

/* Line 678 of lalr1.cc  */
#line 5442 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 810:

/* Line 678 of lalr1.cc  */
#line 5451 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 811:

/* Line 678 of lalr1.cc  */
#line 5455 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr(
                LOC((yyloc)), dynamic_cast<FTOr*>((yysemantic_stack_[(3) - (1)].node)), dynamic_cast<FTAnd*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 812:

/* Line 678 of lalr1.cc  */
#line 5465 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 813:

/* Line 678 of lalr1.cc  */
#line 5469 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd(
                LOC((yyloc)), dynamic_cast<FTAnd*>((yysemantic_stack_[(3) - (1)].node)), dynamic_cast<FTMildNot*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 814:

/* Line 678 of lalr1.cc  */
#line 5479 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 815:

/* Line 678 of lalr1.cc  */
#line 5483 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot(
                LOC((yyloc)),
                dynamic_cast<FTMildNot*>((yysemantic_stack_[(4) - (1)].node)), dynamic_cast<FTUnaryNot*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 816:

/* Line 678 of lalr1.cc  */
#line 5494 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 817:

/* Line 678 of lalr1.cc  */
#line 5498 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 818:

/* Line 678 of lalr1.cc  */
#line 5508 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 819:

/* Line 678 of lalr1.cc  */
#line 5520 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 820:

/* Line 678 of lalr1.cc  */
#line 5524 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 821:

/* Line 678 of lalr1.cc  */
#line 5531 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 822:

/* Line 678 of lalr1.cc  */
#line 5535 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 823:

/* Line 678 of lalr1.cc  */
#line 5543 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<RangeExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
        }
    break;

  case 824:

/* Line 678 of lalr1.cc  */
#line 5551 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTPrimary(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 825:

/* Line 678 of lalr1.cc  */
#line 5559 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 826:

/* Line 678 of lalr1.cc  */
#line 5563 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 827:

/* Line 678 of lalr1.cc  */
#line 5570 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 828:

/* Line 678 of lalr1.cc  */
#line 5574 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 829:

/* Line 678 of lalr1.cc  */
#line 5582 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 830:

/* Line 678 of lalr1.cc  */
#line 5590 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 831:

/* Line 678 of lalr1.cc  */
#line 5602 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 832:

/* Line 678 of lalr1.cc  */
#line 5608 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue( LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr)) );
        }
    break;

  case 833:

/* Line 678 of lalr1.cc  */
#line 5615 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ParseConstants::ft_opt_any );
        }
    break;

  case 834:

/* Line 678 of lalr1.cc  */
#line 5619 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 835:

/* Line 678 of lalr1.cc  */
#line 5627 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_option) );
        }
    break;

  case 836:

/* Line 678 of lalr1.cc  */
#line 5631 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_option) );
        }
    break;

  case 837:

/* Line 678 of lalr1.cc  */
#line 5635 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ParseConstants::ft_opt_phrase );
        }
    break;

  case 838:

/* Line 678 of lalr1.cc  */
#line 5642 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_option) = ParseConstants::ft_opt_any;
        }
    break;

  case 839:

/* Line 678 of lalr1.cc  */
#line 5646 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_option) = ParseConstants::ft_opt_any_word;
        }
    break;

  case 840:

/* Line 678 of lalr1.cc  */
#line 5653 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_option) = ParseConstants::ft_opt_all;
        }
    break;

  case 841:

/* Line 678 of lalr1.cc  */
#line 5657 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_option) = ParseConstants::ft_opt_all_words;
        }
    break;

  case 842:

/* Line 678 of lalr1.cc  */
#line 5665 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 843:

/* Line 678 of lalr1.cc  */
#line 5669 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 844:

/* Line 678 of lalr1.cc  */
#line 5673 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 845:

/* Line 678 of lalr1.cc  */
#line 5677 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 846:

/* Line 678 of lalr1.cc  */
#line 5681 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 847:

/* Line 678 of lalr1.cc  */
#line 5689 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 848:

/* Line 678 of lalr1.cc  */
#line 5697 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<UnionExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 849:

/* Line 678 of lalr1.cc  */
#line 5709 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 850:

/* Line 678 of lalr1.cc  */
#line 5721 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ParseConstants::ft_unit_words );
        }
    break;

  case 851:

/* Line 678 of lalr1.cc  */
#line 5725 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ParseConstants::ft_unit_sentences );
        }
    break;

  case 852:

/* Line 678 of lalr1.cc  */
#line 5729 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ParseConstants::ft_unit_paragraphs );
        }
    break;

  case 853:

/* Line 678 of lalr1.cc  */
#line 5737 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 854:

/* Line 678 of lalr1.cc  */
#line 5743 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(2) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 855:

/* Line 678 of lalr1.cc  */
#line 5753 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 856:

/* Line 678 of lalr1.cc  */
#line 5757 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 857:

/* Line 678 of lalr1.cc  */
#line 5761 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 858:

/* Line 678 of lalr1.cc  */
#line 5765 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 859:

/* Line 678 of lalr1.cc  */
#line 5769 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 860:

/* Line 678 of lalr1.cc  */
#line 5773 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 861:

/* Line 678 of lalr1.cc  */
#line 5777 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 862:

/* Line 678 of lalr1.cc  */
#line 5781 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 863:

/* Line 678 of lalr1.cc  */
#line 5789 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption(
                LOC((yyloc)), ParseConstants::ft_case_sensitive
            );
        }
    break;

  case 864:

/* Line 678 of lalr1.cc  */
#line 5795 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption(
                LOC((yyloc)), ParseConstants::ft_case_insensitive
            );
        }
    break;

  case 865:

/* Line 678 of lalr1.cc  */
#line 5801 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ParseConstants::ft_case_lower );
        }
    break;

  case 866:

/* Line 678 of lalr1.cc  */
#line 5805 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ParseConstants::ft_case_upper );
        }
    break;

  case 867:

/* Line 678 of lalr1.cc  */
#line 5813 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ParseConstants::ft_diacritics_senstive
            );
        }
    break;

  case 868:

/* Line 678 of lalr1.cc  */
#line 5819 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ParseConstants::ft_diacritics_insensitive
            );
        }
    break;

  case 869:

/* Line 678 of lalr1.cc  */
#line 5829 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 870:

/* Line 678 of lalr1.cc  */
#line 5839 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption(
                LOC((yyloc)), ParseConstants::ft_stemmode_with
            );
        }
    break;

  case 871:

/* Line 678 of lalr1.cc  */
#line 5845 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption(
                LOC((yyloc)), ParseConstants::ft_stemmode_without
            );
        }
    break;

  case 872:

/* Line 678 of lalr1.cc  */
#line 5855 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            FTThesaurusOption::thesaurus_id_list_t *til = NULL;
            if ( (yysemantic_stack_[(3) - (3)].node) ) {
                til = new FTThesaurusOption::thesaurus_id_list_t;
                til->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            }
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), til, !til );
            delete til;
        }
    break;

  case 873:

/* Line 678 of lalr1.cc  */
#line 5865 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            FTThesaurusOption::thesaurus_id_list_t *til = (yysemantic_stack_[(6) - (5)].thesaurus_id_list);
            if ( (yysemantic_stack_[(6) - (4)].node) ) {
                if ( !til )
                    til = new FTThesaurusOption::thesaurus_id_list_t;
                til->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(6) - (4)].node)) );
            }
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), til, !(yysemantic_stack_[(6) - (4)].node) );
            delete til;
        }
    break;

  case 874:

/* Line 678 of lalr1.cc  */
#line 5876 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 875:

/* Line 678 of lalr1.cc  */
#line 5883 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 876:

/* Line 678 of lalr1.cc  */
#line 5887 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 877:

/* Line 678 of lalr1.cc  */
#line 5894 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 878:

/* Line 678 of lalr1.cc  */
#line 5898 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(1) - (1)].thesaurus_id_list);
        }
    break;

  case 879:

/* Line 678 of lalr1.cc  */
#line 5905 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 880:

/* Line 678 of lalr1.cc  */
#line 5910 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 881:

/* Line 678 of lalr1.cc  */
#line 5919 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 882:

/* Line 678 of lalr1.cc  */
#line 5928 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = NULL;
        }
    break;

  case 883:

/* Line 678 of lalr1.cc  */
#line 5932 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 884:

/* Line 678 of lalr1.cc  */
#line 5939 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 885:

/* Line 678 of lalr1.cc  */
#line 5943 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 886:

/* Line 678 of lalr1.cc  */
#line 5951 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(5) - (4)].node)), (yysemantic_stack_[(5) - (5)].incl_excl_list),
                ParseConstants::ft_stop_words_with
            );
            delete (yysemantic_stack_[(5) - (5)].incl_excl_list);
        }
    break;

  case 887:

/* Line 678 of lalr1.cc  */
#line 5960 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(5) - (5)].incl_excl_list), ParseConstants::ft_stop_words_with_default
            );
            delete (yysemantic_stack_[(5) - (5)].incl_excl_list);
        }
    break;

  case 888:

/* Line 678 of lalr1.cc  */
#line 5967 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ParseConstants::ft_stop_words_without
            );
        }
    break;

  case 889:

/* Line 678 of lalr1.cc  */
#line 5977 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 890:

/* Line 678 of lalr1.cc  */
#line 5981 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), NULL, (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 891:

/* Line 678 of lalr1.cc  */
#line 5988 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 892:

/* Line 678 of lalr1.cc  */
#line 5994 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 893:

/* Line 678 of lalr1.cc  */
#line 6003 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 894:

/* Line 678 of lalr1.cc  */
#line 6007 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 895:

/* Line 678 of lalr1.cc  */
#line 6014 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 896:

/* Line 678 of lalr1.cc  */
#line 6019 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 897:

/* Line 678 of lalr1.cc  */
#line 6031 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ParseConstants::ft_stop_words_union
            );
        }
    break;

  case 898:

/* Line 678 of lalr1.cc  */
#line 6039 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ParseConstants::ft_stop_words_except
            );
        }
    break;

  case 899:

/* Line 678 of lalr1.cc  */
#line 6051 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 900:

/* Line 678 of lalr1.cc  */
#line 6059 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), true );
        }
    break;

  case 901:

/* Line 678 of lalr1.cc  */
#line 6063 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), false );
        }
    break;

  case 902:

/* Line 678 of lalr1.cc  */
#line 6071 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent(
                LOC((yyloc)), ParseConstants::ft_contentmode_at_start
            );
        }
    break;

  case 903:

/* Line 678 of lalr1.cc  */
#line 6077 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent(
                LOC((yyloc)), ParseConstants::ft_contentmode_at_end
            );
        }
    break;

  case 904:

/* Line 678 of lalr1.cc  */
#line 6083 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent(
                LOC((yyloc)), ParseConstants::ft_contentmode_entire
            );
        }
    break;

  case 905:

/* Line 678 of lalr1.cc  */
#line 6093 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 906:

/* Line 678 of lalr1.cc  */
#line 6101 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), FTRange::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 907:

/* Line 678 of lalr1.cc  */
#line 6105 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), FTRange::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 908:

/* Line 678 of lalr1.cc  */
#line 6109 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), FTRange::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 909:

/* Line 678 of lalr1.cc  */
#line 6113 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), FTRange::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 910:

/* Line 678 of lalr1.cc  */
#line 6121 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ParseConstants::ft_scope_same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 911:

/* Line 678 of lalr1.cc  */
#line 6129 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ParseConstants::ft_scope_different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 912:

/* Line 678 of lalr1.cc  */
#line 6141 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ParseConstants::ft_bigunit_sentence );
        }
    break;

  case 913:

/* Line 678 of lalr1.cc  */
#line 6145 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ParseConstants::ft_bigunit_paragraph );
        }
    break;

  case 914:

/* Line 678 of lalr1.cc  */
#line 6153 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;



/* Line 678 of lalr1.cc  */
#line 11021 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1302;
  const short int
  xquery_parser::yypact_[] =
  {
      1522, -1302, -1302, -1302, -1302,   881,   -61,   192,    36,  9284,
      89,   248,   408,   188, -1302, -1302, -1302, -1302, -1302,   220,
      79,  7588, -1302,    13, -1302, -1302, -1302, -1302,   311,   317,
   -1302,   307,   366,   402, -1302, -1302, -1302, -1302, -1302, -1302,
   -1302, -1302, -1302,   358,   388, -1302, -1302, -1302, -1302, -1302,
   -1302, -1302, -1302, -1302, -1302, -1302, -1302, -1302, -1302, -1302,
   -1302, -1302, -1302, -1302, -1302, -1302,  9565, -1302,  7014, -1302,
   -1302, -1302, -1302, -1302, -1302, -1302, -1302, -1302, -1302, -1302,
   -1302, -1302, 10970, -1302, -1302, -1302, -1302, -1302, -1302, -1302,
   -1302,   452, -1302, -1302, -1302, -1302, -1302, -1302, -1302, -1302,
   -1302, -1302, -1302,  1812, 10970, -1302, -1302, -1302, -1302, -1302,
   -1302, -1302,   429, -1302, -1302, -1302,  8158, -1302,  8441, -1302,
   -1302, -1302, -1302, -1302, 10970, -1302, -1302,  6725, -1302, -1302,
   -1302, -1302, -1302, -1302,   450, -1302, -1302, -1302, -1302, -1302,
   -1302, -1302, -1302,    11,   394, -1302, -1302, -1302, -1302, -1302,
   -1302, -1302, -1302,   335,   478,   396, -1302,   417,    66, -1302,
   -1302, -1302, -1302, -1302, -1302,   525, -1302,   497,   415,   427,
     439, -1302, -1302,   532,   541, -1302,   576, -1302, -1302, -1302,
   -1302, -1302, -1302, -1302, -1302, -1302, -1302, -1302, -1302, -1302,
   -1302, -1302, -1302, -1302, -1302, -1302, -1302, -1302, -1302, -1302,
   -1302, -1302, -1302, -1302, -1302, -1302, -1302, -1302, -1302, -1302,
   -1302, -1302, -1302, -1302, -1302, -1302, -1302, -1302, -1302, -1302,
   -1302, -1302, -1302, -1302, -1302, -1302, -1302, -1302, -1302, -1302,
   -1302, -1302, -1302, -1302, -1302,  4702,   691, -1302,  4991, -1302,
   -1302,    88,  5280,   509,   514, -1302, -1302, -1302, -1302, -1302,
   -1302, -1302, -1302, -1302, -1302, -1302, -1302, -1302, -1302, -1302,
   -1302, -1302, -1302, -1302, -1302, -1302, -1302, -1302, -1302, -1302,
   -1302, -1302, -1302, -1302, -1302, -1302,   -33, -1302, -1302, -1302,
   -1302,   385, 10970, -1302, -1302, -1302, -1302, -1302,   538,   620,
   -1302,   426,   456,   191,   189,   359,   217, -1302,   638,   518,
     617,   618,  5569, -1302, -1302, -1302,   193, -1302, -1302,  6725,
   -1302,   469, -1302,   567,  7014, -1302,   567,  7014, -1302, -1302,
   -1302,   481, -1302, -1302, -1302, -1302, -1302, -1302, -1302, -1302,
   -1302, -1302, -1302, -1302, -1302, -1302, -1302, -1302, -1302, -1302,
   -1302, -1302, -1302, -1302, -1302, -1302, -1302, -1302, -1302, -1302,
   -1302, -1302, -1302, -1302, -1302, -1302, -1302, -1302, -1302, -1302,
   -1302, -1302, -1302, -1302,   255, -1302, -1302, 10970,   679,   680,
     540,   540,   681, 10970,   182,   169,   696,   328,   301, 10970,
     577,   608,   437,  8158, -1302, -1302,   397,   324,    16, 10970,
   -1302, -1302, -1302, -1302, -1302,   438, 10970,   432,   441,   431,
     304, -1302, -1302, -1302,  8158, 10970,  5280,   582,   583,  5280,
   -1302, -1302, -1302, -1302, -1302, -1302, -1302, -1302, -1302, -1302,
   -1302, -1302, -1302, -1302, -1302, -1302, -1302, -1302, -1302, -1302,
   -1302, -1302,  5280,  9846, -1302, -1302, -1302, -1302, -1302, -1302,
   -1302, -1302, -1302, -1302, -1302, -1302, -1302, -1302, -1302, -1302,
     584,  5280,  5280,   552,  5280,   554,   -36,   588,  5280,   111,
      76, -1302,  5280,  7873,   589, -1302, 10970, 10970, 10970,  5280,
     461,   462, -1302,   627,   628, 10970,    72,  5280, 10127,   596,
     594,   597,   598,   599,   602, -1302, -1302, -1302, 10970, -1302,
     566,   722,  5280,    49, -1302,   735,   579, -1302,  5280,   550,
   -1302,   736,  5280,  5280,   581,  5280,  5280,  5280,  5280,   553,
   10970, -1302, -1302, -1302, -1302,  5280,  5280,  5280, 10970, -1302,
   -1302, -1302, -1302,   881,    79, -1302, -1302,    88,   733,  5280,
   -1302,  5280,   601,   317,   366,   402,   661,   613,   615,  5280,
    5280, -1302, -1302, -1302, -1302, -1302, -1302, -1302,   677, -1302,
       6,  5858,  5858,  5858, -1302,  5858,  5858, -1302,  5858, -1302,
    5858, -1302, -1302, -1302, -1302, -1302, -1302, -1302,  5858,  5858,
      10,  5858,  5858,  5858,  5858,  5858,  5858,  5858,  5858,  5858,
    5858,  5858,   562,   698,   699,   700, -1302, -1302, -1302,  2101,
   -1302, -1302,  6725,  6725,  5280,   567, -1302, -1302,   567, -1302,
    2390,   567,   648,  2679,   188, 10970, -1302, 10970, -1302, -1302,
   -1302, -1302,   768, -1302, -1302, -1302, -1302, -1302, -1302,   692,
     693, -1302, -1302,   689,   244, 10970,   436,   640,   645,   689,
     696,   682,   674, -1302, -1302, -1302, -1302, -1302, 10970,   277,
      27,   291,   777, -1302, -1302,   297,    16, -1302, -1302, -1302,
   -1302, -1302, -1302, -1302, -1302, -1302,   -31, -1302,   511, -1302,
   -1302, 10970, 10970, 10970, -1302,   676,   658, -1302,   634,  5280,
    5280,   632,   637, -1302,   -35,   -32,  2968,   639,   643, -1302,
     644, -1302, 10970,   725,   -12, -1302,  5280, -1302,   642,  8158,
     737,   783,  8158,   696,   738,   650,   652, -1302,   654,  3257,
     -27, -1302,    24,   701,   732, -1302,   -51,   651, -1302, -1302,
   10970,   -29, -1302,   656,   594,   358, -1302,   659,   660,   664,
   -1302,    -8,     4,  3546,   -19, -1302, 10970,   722, -1302,   168,
     666, -1302, -1302, -1302, -1302,   667, -1302,   -50, -1302, -1302,
   -1302,    81,    93,   748,   614,   606,   -15, -1302,   710,  6147,
   -1302,   668,   670,    22, -1302, -1302,   665, -1302,   743, -1302,
   -1302,   -21,   690, 10970,  5280,   739, -1302, -1302,   741, 10408,
     742,  5280,   744,    17,   716,   -23,   620, -1302, -1302, -1302,
   -1302, -1302,  5858, -1302, -1302, -1302,  5280,    10,   298,   694,
   -1302,   580,   -43,   609,   611, -1302, -1302,    16, -1302,   605,
     267,   189,   189,   185,   359,   359,   359,   359,   217,   217,
   -1302, -1302, 10408, 10408, 10970, 10970, -1302,   683, -1302, -1302,
     684, -1302, -1302, -1302,     7, -1302, -1302,   165,   205,   188,
     188, -1302,   288,   381, -1302, -1302, -1302, -1302, -1302, -1302,
   -1302, -1302, -1302, -1302,   689, -1302,   746, 10689,   727,  5280,
   -1302, -1302, -1302,   778,   731,  5280,   696,   696,   689, -1302,
     537,   696,   845, -1302, -1302,   603, -1302,   590,   235, -1302,
   -1302, -1302, -1302, -1302,   593, -1302, -1302, -1302,   106,   376,
   -1302,   653,   264,   -26,   585,   696,  5280, -1302,   702,   703,
     780,   730, 10970, -1302, 10970, -1302, -1302,   704, -1302, -1302,
   -1302,   778, 10408,   769,   792,   707,   695,   762,   696,   740,
     764,   799,   696,   745, -1302, -1302, -1302,   718,   779,  5280,
    5280,   757,  5280,   785,  5280,   765,   -89, -1302,    32,   655,
   -1302, -1302,   459,   -29, -1302, -1302, -1302,   753, 10970, -1302,
   10970, -1302, -1302,   728,  5280,   871, -1302,   197, -1302,    60,
   -1302, -1302,   880, -1302,   406,  5280,  5280,  5280,   409,  5280,
    5280,  5280,  5280,  5280,  5280,   793,  5280,  5280,   608,   -20,
     749,   497,   669,   761,   796,   733,   837, -1302,  5280, -1302,
     425,   812, -1302, 10970,   814, -1302, 10970,   775,   782, 10689,
     784, -1302,   190, -1302, -1302, -1302, -1302, -1302, -1302, -1302,
   10970, -1302, 10970,  5280,   786,  5280,  5280,    20,   787, -1302,
     759,   750, -1302,   697, -1302, -1302,  -124, -1302,   -95,     5,
     706,    10,   -95,  5858, -1302,   -25, -1302, -1302, -1302, -1302,
   -1302, -1302,    10,   798,   671,    16,     5, -1302, -1302,   662,
     867, -1302, -1302, -1302, -1302, -1302, -1302,   802, -1302, -1302,
   -1302,  5280, -1302, -1302, -1302,  5280, -1302,   271,   322, -1302,
   -1302, -1302, -1302, -1302,   919,   465, -1302, -1302, -1302,  5280,
   -1302, -1302, -1302, -1302, -1302, -1302, -1302,   673,   -18,   920,
   -1302,   440, -1302, -1302, -1302,   597,   598,   599,   388,   602,
     478,   714,   190,   747,   751,  6436,   678,   647,   106, -1302,
     752,   767,   781, -1302, -1302,  9003,   433, -1302,  3835,   774,
     789,   819,   790,   791, -1302, -1302, -1302, -1302, 10408, -1302,
    5280,   696,   857, -1302, -1302, -1302,   696,   857,  4124, -1302,
   10970, -1302, -1302,  5280, -1302, 10970, -1302,  5280,  5280,   825,
    5280,   821, -1302,   849,   850,  5280, 10970,   604,   900, -1302,
   -1302, -1302,  4413,   794,   795, -1302, -1302, -1302,   840, -1302,
      91, -1302, -1302,   966, -1302, -1302, 10970, -1302, -1302,   184,
   -1302, -1302, -1302,   801,   755,   756, -1302, -1302, -1302,   760,
     766, -1302, -1302, -1302, -1302, -1302,   770, 10970,   800, -1302,
     841, -1302,   608, -1302, -1302, -1302,  7303,   669, -1302,  5280,
   10970,   812, -1302,   696, -1302,   546, -1302,     0,   884, -1302,
    5280,   889,   739, -1302,  8722,   820,   823,   824, -1302, -1302,
   -1302, -1302, -1302, -1302, -1302,  5280, -1302, -1302,  5280,   851,
    5280, -1302, -1302,  5858, -1302, -1302, -1302, -1302, -1302,    58,
    5858,  5858,   263, -1302,   609, -1302,   237, -1302,   611,    10,
    5858, -1302, -1302,   734, -1302, -1302, -1302, -1302, -1302, -1302,
     822, -1302,  5280, -1302, -1302, -1302, -1302, -1302,   -44,   981,
     982,   -44,   758,   915, -1302, -1302, -1302, -1302,   846, 10970,
     763,   714,  6436, -1302, -1302, 10970,   830,   -13, -1302, -1302,
     834, -1302, -1302, -1302, -1302, -1302, -1302,   892,   921,   696,
     857, -1302,   843, -1302, -1302, -1302, -1302, -1302,  5280, -1302,
    5280, 10970, 10970, -1302,   319, -1302,  5280, -1302,   852, -1302,
   -1302,   871, 10970,   250, -1302,   871, 10970, -1302, -1302,  5280,
    5280,  5280,  5280,  5280, -1302,  5280,  5280, -1302, -1302,   206,
   -1302,   859, -1302, -1302, -1302, -1302,   884, -1302, -1302, -1302,
     696, -1302, -1302,   947,   858, -1302,   166, -1302, -1302, -1302,
   -1302, -1302,  5280, -1302,   359,  5858,  5858,   185,   196, -1302,
   -1302, -1302, -1302, -1302, -1302, -1302, -1302, -1302,   -38,   -18,
     -18, -1302,   -44, -1302, -1302, -1302,   212, -1302,  1016,     5,
     861,   939, -1302,  6436,   -63,   771, -1302,   879,   955,  5280,
   10970,  5280, -1302,  5280,   696, -1302, -1302, -1302, -1302,   983,
   -1302, -1302, -1302, -1302,   -39,   871, 10970,   860,   871, -1302,
   -1302, -1302, -1302, -1302, -1302, -1302,   933,  7303, -1302, -1302,
   -1302, -1302, 10408, -1302, 10408,   959, -1302,   185,   185,  5858,
   -1302, -1302, -1302, -1302,  1027, -1302, -1302, -1302,   797, -1302,
     915,   950, -1302,   964, 10970,   941,   838, 10970,  6436, 10408,
   -1302,   882, -1302, -1302,   857,   944,   302,   295, -1302,   869,
     871, -1302,   870, 10970, -1302, -1302, -1302, 10408,   185, -1302,
   -1302, -1302,  6436, 10970,   772, 10970,   948,   844,   950,   885,
    5280, 10970, -1302, -1302,   976,   305, -1302, -1302, -1302, -1302,
     890,   318, -1302, -1302, -1302,   877, -1302,   213, -1302, -1302,
     884,  5280,   773, 10970,   954,  5280, -1302, -1302, -1302, -1302,
   -1302, -1302, -1302, -1302, -1302,   958,   922, -1302, -1302,   788,
     776, 10970, -1302, 10970, -1302,   803,  5280,   804,   216,  6436,
   -1302,  6436,   963,   922, -1302,   886, 10970, -1302,   805,   893,
   10970,   922,   862, -1302,   965, 10970,   807,  6436, -1302
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
         0,   402,   403,   601,   556,   706,   715,   694,   618,   610,
     626,   617,   608,   716,   755,   754,   756,   757,   753,   612,
     713,   614,   641,   676,   670,   711,   638,   714,   771,   665,
     707,   769,   655,   656,   657,   658,   659,   660,   661,   662,
     663,   708,   622,   616,   609,   710,   685,   615,   620,   781,
     782,   783,   784,   785,   786,   787,   788,   789,   790,   791,
     393,   396,   684,   680,   671,   651,   607,   383,     0,   679,
     687,   695,   381,   675,   422,   652,   653,   709,   382,   385,
     672,   689,     0,   428,   391,   424,   682,   606,   673,   674,
     702,   677,   693,   701,   387,   386,   625,   664,   704,   423,
     692,   697,   611,     0,     0,   340,   690,   700,   705,   703,
     683,   669,   758,   667,   668,   392,     0,   339,     0,   395,
     394,   698,   654,   678,     0,   384,   369,     0,   401,   699,
     681,   688,   696,   691,   759,   645,   650,   649,   648,   647,
     646,   619,   666,     0,   605,   712,   639,   745,   744,   746,
     624,   623,   642,   751,   613,   743,   748,   749,   740,   644,
     686,   742,   752,   750,   741,   643,   747,   761,   765,   766,
     762,   763,   760,   764,   767,   768,   770,   732,   731,   637,
     630,   725,   721,   640,   636,   734,   735,   718,   627,   621,
     629,   730,   729,   726,   722,   739,   733,   728,   724,   717,
     628,   738,   737,   632,   634,   633,   723,   727,   719,   635,
     720,   631,   736,   792,   793,   794,   795,   796,   797,   773,
     774,   772,   778,   779,   780,   775,   776,   777,   798,   799,
     800,   801,   802,   803,   804,     0,     0,     2,     0,     4,
       6,    12,     0,     0,     0,    18,    20,    29,    22,    23,
      24,    50,    25,    34,    30,    54,    55,    56,    51,    52,
      58,    59,    28,    26,    27,    32,    33,    53,   198,   197,
     194,   195,   196,    31,    11,   175,   176,   180,   182,   213,
     219,     0,     0,   211,   212,   183,   184,   185,   186,   295,
     297,   299,   309,   313,   315,   318,   323,   326,   329,   331,
     333,   335,     0,   337,   343,   345,     0,   361,   344,   365,
     368,   370,   373,   375,     0,   380,   377,     0,   388,   398,
     400,   374,   404,   411,   420,   412,   413,   414,   417,   418,
     415,   416,   435,   437,   438,   439,   436,   484,   485,   486,
     487,   488,   489,   397,   530,   522,   529,   528,   527,   524,
     526,   523,   525,   421,   419,   557,   558,    57,   187,   188,
     190,   189,   191,   192,   399,   193,   602,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   107,   108,     0,     0,     0,     0,
     103,   104,   105,   106,   111,     0,     0,     0,     0,     0,
       0,   101,   156,   159,     0,     0,     0,     0,     0,     0,
     706,   715,   694,   618,   610,   626,   617,   608,   716,   612,
     713,   614,   676,   771,   665,   769,   655,   656,   616,   609,
     607,   677,     0,     0,   758,   759,   605,   751,   613,   743,
     749,   740,   643,   761,   765,   766,   762,   764,   767,   770,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   599,     0,     0,     0,   600,     0,     0,     0,     0,
       0,     0,   221,     0,     0,     0,     0,     0,     0,     0,
     610,   617,   608,   614,   607,   389,   399,   425,     0,   426,
       0,   451,     0,     0,   364,     0,     0,   367,     0,     0,
     480,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   146,   143,   154,   155,     0,     0,     0,     0,     3,
       1,     5,     7,     0,     0,    13,    10,    15,    16,     0,
     178,   177,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   199,   218,   214,   220,   215,   217,   216,   223,   224,
       0,     0,     0,     0,   354,     0,     0,   352,     0,   304,
       0,   353,   346,   351,   350,   349,   348,   347,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   342,   341,   338,     0,
     362,   366,     0,     0,     0,   376,   408,   379,   378,   390,
       0,   405,     0,     0,     0,     0,   161,     0,   162,   158,
     157,   160,     0,   137,   138,    67,    68,   598,    76,     0,
       0,    61,    62,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   567,   568,   569,   110,   109,     0,     0,
       0,     0,     0,   865,   866,     0,    66,   853,   855,   856,
     857,   859,   861,   860,   858,   862,   115,   112,     0,   114,
     113,     0,     0,     0,   102,     0,     0,   554,     0,     0,
       0,     0,     0,   546,     0,     0,     0,     0,     0,   535,
       0,   536,     0,   139,     0,   169,     0,   560,     0,     0,
      85,     0,     0,     0,    77,     0,     0,   537,     0,     0,
       0,   284,     0,     0,   236,   237,     0,     0,   201,   202,
       0,     0,   222,     0,     0,     0,   532,     0,     0,     0,
     540,     0,     0,     0,     0,   427,   452,   451,   448,     0,
       0,   482,   481,   363,   545,     0,   479,     0,   580,   581,
     531,     0,     0,     0,     0,     0,     0,   586,     0,     0,
     152,     0,     0,     0,   239,   256,     0,    19,     0,    21,
     181,     0,     0,     0,     0,     0,   200,   257,     0,     0,
       0,     0,     0,     0,     0,     0,   296,   298,   302,   308,
     307,   306,     0,   303,   300,   301,     0,     0,     0,   829,
     831,   311,   806,   810,   812,   814,   816,   819,   826,   827,
     833,   317,   316,   314,   320,   321,   322,   319,   324,   325,
     328,   327,     0,     0,     0,     0,   359,     0,   371,   372,
       0,   409,   406,   433,     0,   559,   431,     0,     0,     0,
       0,    65,     0,     0,    40,    42,    43,    44,    45,    47,
      48,    49,    41,    46,    36,    37,     0,     0,    93,     0,
      89,    91,    92,    96,    99,     0,     0,     0,    35,    75,
       0,     0,     0,   864,   863,     0,   870,     0,     0,   900,
     868,   867,   899,   871,     0,   874,   901,   854,     0,     0,
     116,     0,     0,   119,     0,     0,     0,   355,     0,     0,
       0,     0,     0,   550,     0,   547,   491,     0,   490,   499,
     500,   171,     0,     0,   140,     0,     0,     0,     0,     0,
       0,    78,     0,     0,   539,   538,   501,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   604,     0,     0,
     203,   204,     0,   209,   553,   533,   534,     0,     0,   543,
       0,   541,   495,     0,     0,   451,   449,     0,   440,     0,
     429,   430,     0,     8,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   706,     0,
       0,     0,     0,     0,     0,    17,     0,   179,     0,   210,
     268,   264,   266,     0,   258,   259,     0,   716,   611,     0,
     619,   507,   508,   514,   515,   517,   561,   562,   518,   521,
       0,   226,     0,     0,     0,     0,     0,     0,     0,   305,
       0,     0,   817,     0,   310,   312,     0,   847,     0,     0,
       0,     0,     0,     0,   805,   807,   808,   842,   843,   844,
     846,   845,     0,     0,   821,   820,     0,   824,   828,   840,
     838,   837,   830,   834,   330,   332,   334,   505,   336,   360,
     410,     0,   407,   432,   164,     0,   163,     0,     0,    73,
      74,    71,    72,    38,     0,     0,    94,    95,    97,     0,
      98,    63,    64,    69,    70,    60,   869,     0,     0,     0,
     876,     0,   872,   875,   888,     0,     0,     0,     0,     0,
       0,   117,   123,     0,     0,     0,     0,     0,     0,   120,
       0,     0,     0,   357,   356,     0,     0,   290,     0,     0,
       0,   554,     0,     0,   492,   172,   141,   170,     0,   173,
       0,     0,    87,    81,    84,    83,     0,    79,     0,   502,
       0,   282,   286,     0,   151,     0,   241,     0,     0,     0,
       0,     0,   205,     0,     0,     0,     0,   250,     0,   247,
     252,   208,     0,     0,     0,   496,   283,   452,     0,   441,
       0,   475,   472,     0,   476,   477,     0,   478,   471,     0,
     446,   474,   473,     0,     0,     0,   573,   574,   570,     0,
       0,   578,   579,   575,   584,   582,     0,     0,     0,   588,
     149,   148,     0,   145,   144,   153,     0,   589,   590,     0,
       0,   265,   277,     0,   278,     0,   269,   270,   271,   272,
       0,   261,     0,   225,     0,     0,     0,     0,   511,   513,
     512,   509,   234,   235,   228,     0,   230,   227,     0,     0,
       0,   832,   825,     0,   902,   903,   913,   912,   911,     0,
       0,     0,     0,   904,   811,   910,     0,   809,   813,     0,
       0,   818,   822,     0,   841,   836,   839,   835,   506,   434,
       0,   168,     0,   166,   165,    39,    90,   100,   893,     0,
       0,   893,   882,   877,   118,   124,   126,   125,     0,     0,
       0,   121,     0,    14,   358,     0,     0,     0,   291,   493,
       0,   551,   552,   555,   548,   549,   142,     0,    86,     0,
      80,   503,     0,   285,   287,   238,   243,   242,     0,   245,
       0,     0,     0,   207,   248,   251,     0,   497,     0,   544,
     542,   451,     0,     0,   483,   451,     0,   447,     9,     0,
       0,     0,     0,     0,   587,     0,     0,   147,   596,     0,
     591,     0,   240,   281,   279,   280,   273,   274,   275,   267,
       0,   262,   260,     0,     0,   519,     0,   516,   566,   510,
     232,   229,     0,   231,   914,     0,     0,   906,     0,   852,
     851,   850,   849,   848,   815,   823,   905,   174,     0,     0,
       0,   887,   894,   895,   889,   891,     0,   886,     0,   884,
       0,   878,   879,     0,     0,     0,   122,     0,     0,     0,
       0,     0,   494,     0,     0,    82,   504,   244,   246,   255,
     254,   249,   206,   498,     0,   451,     0,     0,   451,   571,
     572,   576,   577,   583,   585,   150,     0,     0,   592,   603,
     276,   263,     0,   563,     0,     0,   233,   908,   907,     0,
     167,   898,   897,   896,     0,   890,   883,   881,     0,   873,
       0,   127,   129,     0,     0,     0,     0,     0,     0,     0,
     292,     0,   288,   294,    88,     0,   461,   455,   450,     0,
     451,   442,     0,     0,   597,   564,   520,     0,   909,   892,
     885,   880,     0,     0,     0,     0,     0,     0,   128,     0,
       0,     0,   469,   463,     0,   462,   464,   470,   467,   457,
       0,   456,   458,   468,   444,     0,   443,     0,   565,   130,
     131,     0,     0,     0,     0,     0,   289,   253,   454,   465,
     466,   453,   459,   460,   445,     0,     0,   132,   133,     0,
       0,     0,   293,     0,   593,     0,     0,     0,     0,     0,
     135,     0,     0,     0,   134,     0,     0,   594,     0,     0,
       0,     0,     0,   595,     0,     0,     0,     0,   136
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1302, -1302,   853, -1302,   842,   848, -1302,   835, -1302,   557,
     560,  -515, -1302,   460,  -351, -1302, -1302, -1302, -1302, -1302,
   -1302, -1302, -1302, -1302, -1302, -1302, -1302, -1302, -1302,  -902,
   -1302, -1302, -1302, -1302,    14,   242,   711, -1302, -1302,   705,
   -1302,    -5,  -875, -1302,  -364,  -387, -1302, -1302,  -562, -1302,
    -913, -1302, -1302,   -92, -1302, -1302, -1302, -1302, -1302,   296,
     808, -1302, -1302, -1302,   194,   646, -1301,   864,    23, -1302,
    -528,  -318, -1302, -1302, -1302, -1302,   171, -1302, -1302,   826,
   -1302, -1302, -1302, -1302, -1302,   122,  -499,  -685, -1302, -1302,
   -1302,   -24, -1302, -1302,  -204,   -34,   -88, -1302, -1302, -1302,
     -98, -1302, -1302,   137,   -94, -1302, -1302,   -90, -1181, -1302,
     630,   -11, -1302, -1302,    18, -1302, -1302,   569,   570, -1302,
    -519, -1302,  -127,  -572,    99,  -558,    98,   101, -1302, -1302,
   -1302, -1302, -1302,   827, -1302, -1302, -1302, -1302,  -559,  -299,
   -1047, -1302,  -104, -1302, -1302, -1302, -1302, -1302, -1302, -1302,
     -40, -1172, -1302, -1302,   284,  -476, -1302,  -541, -1302, -1302,
   -1302, -1302, -1302, -1302, -1302,   522, -1302,  -924, -1302,   -30,
   -1302,   400,  -718, -1302, -1302, -1302, -1302, -1302,  -373,  -362,
   -1115,  -969, -1302, -1302, -1302, -1302, -1302, -1302, -1302, -1302,
   -1302, -1302,   320,  -662,  -798,    42,  -795, -1302,  -809,  -736,
   -1302, -1302, -1302, -1302, -1302, -1302, -1302,   663,   672,  -424,
     246,    74, -1302, -1302, -1302, -1302, -1302, -1302, -1302, -1302,
   -1302, -1302, -1302, -1302, -1302, -1302,   -46, -1302, -1302,   -55,
   -1302,  -374,  -112,    -9, -1302, -1302,   349, -1302, -1302, -1302,
     123,   113,  -106,   361, -1302, -1302, -1302, -1302, -1302, -1302,
   -1302, -1302, -1302, -1302, -1302, -1302,   121, -1302, -1302, -1302,
     -99,   353,  -626, -1302, -1302, -1302, -1302, -1302,    71, -1302,
   -1302, -1220, -1302, -1302, -1302,  -677, -1302,  -118, -1302,  -228,
   -1302, -1302, -1302, -1302, -1014, -1302,   133, -1302
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   844,   845,   846,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,  1122,
     693,   261,   262,   850,   851,   852,  1190,   263,   400,   401,
     264,  1091,   880,   265,  1451,  1452,   266,   267,   457,   268,
     512,   749,   969,  1191,   269,   270,   271,   272,   273,   402,
     403,   608,   606,   684,   685,  1167,  1056,   274,   275,   531,
     276,   277,   278,   541,   473,   932,   933,   279,   542,   280,
     544,   281,   282,   283,   548,   549,  1147,   774,   284,   704,
     753,   705,   711,  1148,  1149,  1150,   754,   545,   546,   984,
     985,  1351,   547,   981,   982,  1206,  1207,  1208,  1209,   285,
     700,   701,   286,  1106,  1107,   287,   288,   289,   290,   782,
     291,  1014,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   568,   569,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   595,   596,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   824,   331,   332,   333,  1169,
     727,   728,   729,  1468,  1500,  1501,  1494,  1495,  1502,  1496,
    1170,  1171,   334,   335,  1172,   336,   337,   338,   339,   340,
     341,   342,  1046,   775,   991,  1221,   992,  1356,   993,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   666,
    1110,   353,   354,   355,   356,   995,   996,   997,   998,   357,
     358,   359,   360,   361,   362,   746,   747,   363,  1197,  1198,
    1339,  1123,   464,   364,   365,   366,   791,  1024,  1025,   792,
     793,   794,   795,   796,  1034,  1251,  1252,   797,  1037,   798,
     799,   800,  1042,  1043,  1257,  1255,  1026,  1027,  1028,  1029,
    1372,   646,   647,   648,   649,   650,   651,   652,  1082,  1390,
    1391,  1083,  1389,  1447,   653,  1271,  1386,  1381,  1382,  1383,
     654,   655,  1030,  1038,  1242,  1031,  1238,  1015
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       450,   803,   618,   761,   493,  1047,  1047,   590,  1099,   947,
    1127,   789,   465,   759,  1044,  1045,   804,   805,   806,   807,
     877,   925,  1253,   497,  1338,  1168,  1347,  1348,   485,   790,
       4,   929,   499,   994,   778,   769,   779,   780,  1428,   781,
     921,   783,   828,  1138,   926,  1016,  1466,  1454,  1278,   784,
     785,   773,  1065,  1392,  1327,   878,   731,   479,  1195,   486,
    1098,   529,   638,  1016,   892,   770,   529,   894,  1161,  1162,
    1269,   952,   918,   487,   682,   973,   994,   994,   529,  1192,
     918,   924,  1379,  1234,   965,   690,   694,   903,  1004,   404,
    1008,   938,   769,  1239,   770,   491,   617,  1400,  1203,  1161,
    1162,  1365,   714,   940,  1116,   459,  1051,   465,   639,   495,
     769,   994,    74,   523,  1006,   496,  1017,  1205,   769,   821,
    1235,   974,   821,   466,    85,   821,   490,   460,  1270,   524,
     953,   617,   865,  1467,  1017,  1440,   714,   715,  1085,  1086,
     683,   893,  1092,   771,   895,  1264,  1380,   530,  1087,    99,
     919,   707,  1455,   786,  1003,  1163,   787,  1228,   944,   977,
    1193,   920,  1401,  1236,   904,  1430,   994,   954,   939,  1140,
    1237,   715,  1088,  1164,   772,  1165,   118,  1366,   930,   958,
     941,   691,   409,  1052,   738,   739,  1163,   741,   742,   743,
     744,  1068,  1161,  1162,  1216,  1089,   879,   750,   751,  1018,
    1019,   879,  1020,   686,  1164,   591,  1165,   104,  1327,  1021,
     966,   760,   772,   732,   500,   931,  1274,  1018,  1019,  1022,
    1020,   766,   767,   116,  1300,  1534,   692,  1158,   789,   789,
    1481,  1023,   451,  1456,   686,  1397,  1168,  1022,   104,  1115,
     772,  1139,  1547,   640,  1166,  1168,   790,   790,   716,  1023,
    1553,  1240,  1241,   994,   116,  1474,   859,   641,  1161,  1162,
     788,   689,   143,  1009,  1051,  1434,  1141,  1057,  1058,   772,
     642,   632,   643,   550,   597,  1322,  1007,   599,   405,  1163,
     772,   508,   823,   772,   124,   823,   509,   644,   948,   955,
     956,   645,   665,   143,   866,   867,   868,  1164,   574,  1165,
     869,   959,   960,  1161,   957,   486,  1492,  1286,   486,  1492,
    1161,  1444,  1525,  1161,  1498,  1542,   961,  1159,     4,   911,
    1296,  1090,  1229,  1079,  1218,   575,  1161,   686,   615,  1527,
     847,   104,  1054,   571,   456,   406,   589,  1498,   576,   571,
    1080,  1053,  1435,   580,   571,  1163,  1453,   116,  1055,  1055,
     572,   698,  1426,   613,   949,  1219,   572,   581,   604,   118,
     616,   572,  1092,  1164,   612,  1165,   458,   614,  1326,   994,
     623,   848,   577,  1220,   465,  1448,   849,  1143,  1144,   573,
     656,  1081,   994,  1160,  1439,   571,   143,   658,  1445,  1526,
     602,   452,  1543,   686,   453,   465,   667,   104,  1261,  1168,
      74,   603,   572,   407,   408,  1427,  1396,   770,  1164,   877,
    1165,  1453,    85,   116,  1262,  1164,  1355,  1165,  1164,  1499,
    1165,   467,   470,   471,   675,  1493,  1059,   468,  1519,   668,
     532,  1164,   671,  1165,  1416,  1453,   533,    99,   686,   534,
     535,   786,  1522,  1060,   787,   686,   980,   536,   686,  1263,
     469,  1246,   143,  1001,   465,   672,   474,   702,   703,   706,
     759,   686,   789,   384,   118,   511,   713,   627,  1109,   722,
    1112,   628,   621,   789,   677,   678,   472,   680,   994,   702,
     790,   688,  1071,  1072,   619,   695,   622,  1075,   818,   819,
     590,   790,  1544,  1063,  1545,   385,  1369,  1497,  1503,   620,
     719,   748,  1464,  1370,   475,  1039,  1040,  1063,   629,   755,
    1558,  1101,  1202,  1371,  1153,   730,  1154,  1143,  1144,  1061,
    1145,   735,  1369,  1203,   387,  1105,  1497,  1041,  1079,  1370,
     863,  1067,  1503,  1204,   476,   630,  1062,  1070,  1287,  1371,
     752,   864,  1205,   537,   870,  1080,   538,   770,   553,   578,
     502,   454,   503,  1096,   455,   871,   554,   555,   579,   556,
     539,  1097,   488,   854,   873,   874,   875,   557,   855,  1146,
     876,   558,   492,   559,   367,   368,   369,   907,   560,   372,
     910,   662,   390,   391,   392,   393,   540,   394,   395,   663,
     397,   398,   848,   498,   561,   631,   829,   849,   830,   501,
     598,  1131,  1132,  1414,  1134,   601,  1136,  1417,   633,   634,
     635,   505,   817,   506,   636,   637,   853,   820,   562,   563,
     564,   565,   566,   567,   504,   594,  1156,   600,  1174,   862,
    1175,  1179,   507,  1180,  1475,   510,  1476,  1176,  1177,  1178,
     511,  1181,  1182,  1183,  1184,  1185,  1186,   513,  1188,  1189,
     592,   593,   882,   883,   884,  1073,  1074,  1093,  1094,   514,
     980,  1489,  1143,  1144,  1344,  1345,   609,   610,  1367,  1368,
     801,   802,   515,   901,  1510,  1364,   808,   809,   516,  1508,
     465,   810,   811,   465,   517,  1224,   518,  1226,  1227,   527,
     789,   520,   888,   889,   528,   551,   994,  1469,   994,   897,
    1472,   928,  1441,  1442,   552,   570,   582,   583,   790,   905,
     584,   594,   585,   605,   607,   367,   617,   945,   625,   624,
     659,   657,   917,   994,   661,   669,   670,   676,   679,   660,
     681,   686,   699,  1259,  1378,   708,   709,   710,   712,   723,
     433,   994,   725,   453,   455,   463,   943,  1298,   478,   726,
     733,  1267,  1505,   736,   979,   734,   737,   740,   758,   762,
     999,   834,   835,   836,   837,   838,   839,   840,   841,   842,
     843,   763,   970,   764,   745,   765,   768,   367,   368,   369,
     370,   371,   372,   812,   813,   814,   815,   825,   831,   373,
     856,   832,   833,  1437,  1438,   857,   861,   872,   885,   860,
     881,   886,  1297,   999,   999,   999,   999,   887,   890,  1010,
     891,   902,   898,   909,   379,  1304,   899,   900,   906,  1306,
    1307,   964,  1309,   913,   927,   908,   912,  1313,   914,  1343,
     915,   923,   934,   922,   962,   935,   936,   937,   999,   950,
     951,   963,   967,   972,   971,   975,   380,   381,   976,   983,
     978,   986,  1000,  1005,  1002,  1013,  1049,  1032,  1050,   849,
     118,  1033,  1036,  1069,   769,  1076,  1078,  1478,  1064,  1084,
    1095,  1077,  1105,  1108,  1100,  1103,  1104,  1114,  1118,   682,
    1119,  1341,  1120,  1111,  1121,  1111,  1125,  1126,  1128,  1130,
    1124,  1129,   980,   999,  1133,  1135,  1152,  1137,  1157,  1142,
    1173,  1155,   384,  1187,  1199,  1196,  1200,  1360,   629,  1102,
    1361,  1210,  1363,  1212,  1256,   367,   368,   369,   370,   371,
     372,  1214,  1194,  1225,  1230,  1405,  1232,   373,  1215,   667,
    1217,   667,  1231,   374,   385,  1249,  1258,  1233,  1254,     4,
    1272,   879,  1280,  1250,   375,   376,  1243,  1283,   377,  1268,
    1291,   378,   379,  1293,  1284,  1279,  1299,  1308,  1310,  1311,
    1312,  1316,  1321,   387,  1276,  1292,  1294,  1295,  1277,  1282,
    1319,  1320,  1324,  1336,  1211,  1335,  1431,   550,  1329,  1330,
     999,  1328,  1203,  1331,   380,   381,   382,  1350,  1362,  1332,
    1407,  1222,  1408,  1223,   388,  1377,  1357,  1333,  1412,  1358,
    1359,  1384,  1385,  1079,  1376,  1399,  1393,  1402,  1403,  1404,
    1395,  1419,  1420,  1421,  1422,  1423,  1406,  1424,  1425,  1388,
     389,   390,   391,   392,   393,  1413,   394,   395,   396,   397,
     398,   383,  1429,  1432,  1433,   399,  1446,  1449,  1450,  1458,
     384,  1459,  1465,  1473,  1436,  1477,  1471,  1479,  1457,  1482,
    1483,  1485,  1480,  1486,  1491,  1504,  1506,  1490,  1513,  1514,
    1515,  1518,  1521,  1524,  1531,  1055,  1511,  1529,  1533,  1551,
    1536,  1535,   385,  1546,  1548,  1555,   525,  1554,  1260,  1266,
     521,  1460,  1550,  1462,   756,  1463,   522,   757,   519,   858,
    1066,   386,   626,  1281,  1488,  1509,   999,  1117,  1539,  1541,
    1337,   387,  1557,   687,  1151,   664,   526,   543,  1213,   999,
    1411,  1305,  1342,  1315,  1352,  1201,  1349,  1346,   724,  1303,
     776,   702,   777,  1375,  1288,   827,   706,   946,  1523,   588,
    1323,  1290,   388,  1520,  1275,  1048,  1011,  1314,  1265,   717,
    1113,  1334,  1340,  1374,  1244,  1248,  1247,  1373,   718,  1012,
    1035,  1302,  1273,  1387,  1443,  1245,     0,  1325,   389,   390,
     391,   392,   393,     0,   394,   395,   396,   397,   398,     0,
       0,     0,  1516,   399,     0,  1318,     0,     0,   748,     0,
     611,     0,     0,     0,     0,     0,     0,   486,     0,     0,
       0,   755,     0,  1528,     0,     0,     0,  1532,     0,     0,
       0,     0,     0,     0,     0,   999,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1540,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1394,     0,     0,     0,     0,     0,  1398,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1409,  1410,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1415,     0,     0,     0,  1418,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1461,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1470,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   486,     0,
       0,     0,     0,   999,     0,   999,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1484,     0,     0,  1487,     0,
     999,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1507,     0,     0,     0,   999,     0,
       0,     0,     0,     0,   999,     0,  1512,     0,     0,     0,
       0,     0,  1517,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1530,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1537,     0,  1538,     0,     0,     0,     0,     0,
       0,     0,     1,     0,     0,     0,     0,  1549,     0,     2,
       3,  1552,     4,     0,     0,     0,  1556,     5,     6,     0,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,     0,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
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
       0,     0,   141,   142,   143,     0,   144,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
       0,   187,   188,   189,     0,   190,   191,   192,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     4,     0,     0,     0,     0,   410,   411,     0,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,   420,    21,    22,    23,    24,    25,    26,
      27,     0,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
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
       0,   119,   120,   121,     0,     0,     0,   122,   489,   123,
     124,   125,     0,   126,   127,   128,     0,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,   143,     0,   436,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
       0,   187,   188,   189,     0,   190,   191,   192,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     4,     0,     0,     0,     0,   410,   411,     0,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,   420,    21,    22,    23,    24,    25,    26,    27,
       0,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,     0,    63,    64,    65,
      66,    67,    68,    69,    70,    71,     0,     0,    72,    73,
       0,     0,     0,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,     0,    85,     0,    86,    87,    88,
      89,     0,    90,     0,     0,     0,    91,    92,    93,    94,
      95,     0,     0,     0,     0,     0,     0,    96,    97,    98,
      99,   100,   101,   102,     0,     0,     0,   103,   104,   105,
     106,   107,     0,     0,     0,     0,   108,   109,   110,   111,
     112,   113,   114,   115,   116,     0,   117,   118,     0,     0,
     119,   120,   121,     0,   816,     0,   122,     0,   123,   124,
     125,     0,   126,   127,   128,     0,   129,     0,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,     0,
       0,   141,   142,   143,     0,   436,   145,     0,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,     0,
     187,   188,   189,     0,   190,   191,   192,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
       1,     0,     0,     0,     0,     0,     0,     2,     3,     0,
       4,     0,     0,     0,     0,   410,   411,     0,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,   420,    21,    22,    23,    24,    25,    26,    27,     0,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
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
     120,   121,     0,     0,     0,   122,   822,   123,   124,   125,
       0,   126,   127,   128,     0,   129,     0,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,   143,     0,   436,   145,     0,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,     0,   187,
     188,   189,     0,   190,   191,   192,   193,   194,   195,     0,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,     1,
       0,     0,     0,     0,     0,     0,     2,     3,     0,     4,
       0,     0,     0,     0,   410,   411,     0,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
     420,    21,    22,    23,    24,    25,    26,    27,     0,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,     0,    63,    64,    65,    66,    67,
      68,    69,    70,    71,     0,     0,    72,    73,     0,     0,
       0,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,     0,    85,     0,    86,    87,    88,    89,     0,
      90,     0,     0,     0,    91,    92,    93,    94,    95,     0,
       0,     0,     0,     0,     0,    96,    97,    98,    99,   100,
     101,   102,     0,     0,     0,   103,   104,   105,   106,   107,
       0,     0,     0,     0,   108,   109,   110,   111,   112,   113,
     114,   115,   116,     0,   117,   118,     0,     0,   119,   120,
     121,     0,     0,     0,   122,   826,   123,   124,   125,     0,
     126,   127,   128,     0,   129,     0,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,     0,     0,   141,
     142,   143,     0,   436,   145,     0,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,     0,   187,   188,
     189,     0,   190,   191,   192,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,     1,     0,
       0,     0,     0,     0,     0,     2,     3,     0,     4,     0,
       0,     0,     0,   410,   411,     0,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,   420,
      21,    22,    23,    24,    25,    26,    27,     0,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
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
       0,   896,     0,   122,     0,   123,   124,   125,     0,   126,
     127,   128,     0,   129,     0,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,     0,     0,   141,   142,
     143,     0,   436,   145,     0,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,     0,   187,   188,   189,
       0,   190,   191,   192,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,     1,     0,     0,
       0,     0,     0,     0,     2,     3,     0,     4,     0,     0,
       0,     0,   410,   411,     0,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,   420,    21,
      22,    23,    24,    25,    26,    27,     0,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
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
     916,     0,   122,     0,   123,   124,   125,     0,   126,   127,
     128,     0,   129,     0,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,     0,     0,   141,   142,   143,
       0,   436,   145,     0,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,     0,   187,   188,   189,     0,
     190,   191,   192,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,     1,     0,     0,     0,
       0,     0,     0,     2,     3,     0,     4,     0,     0,     0,
       0,   410,   411,     0,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,   420,    21,    22,
      23,    24,    25,    26,    27,     0,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
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
       0,   117,   118,     0,     0,   119,   120,   121,     0,   942,
       0,   122,     0,   123,   124,   125,     0,   126,   127,   128,
       0,   129,     0,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,   143,     0,
     436,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,     0,   187,   188,   189,     0,   190,
     191,   192,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     4,     0,     0,     0,     0,
     410,   411,     0,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,   420,    21,    22,    23,
      24,    25,    26,    27,     0,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
       0,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,     0,    72,    73,     0,     0,     0,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,     0,    85,
       0,    86,    87,    88,    89,     0,    90,     0,     0,     0,
      91,    92,    93,    94,    95,     0,     0,     0,     0,     0,
       0,    96,    97,    98,    99,   100,   101,   102,     0,     0,
       0,   103,   104,   105,   106,   107,     0,     0,     0,     0,
     108,   109,   110,   111,   112,   113,   114,   115,   116,     0,
     117,   118,     0,     0,   119,   120,   121,     0,  1289,     0,
     122,     0,   123,   124,   125,     0,   126,   127,   128,     0,
     129,     0,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,   143,     0,   436,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,     0,   187,   188,   189,     0,   190,   191,
     192,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,     1,     0,     0,     0,     0,     0,
       0,     2,     3,     0,     4,     0,     0,     0,     0,   410,
     411,     0,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,   420,    21,    22,    23,    24,
      25,    26,    27,     0,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
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
     118,     0,     0,   119,   120,   121,     0,  1301,     0,   122,
       0,   123,   124,   125,     0,   126,   127,   128,     0,   129,
       0,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,     0,     0,   141,   142,   143,     0,   436,   145,
       0,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,     0,   187,   188,   189,     0,   190,   191,   192,
     193,   194,   195,     0,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     0,     4,     0,     0,     0,     0,   410,   411,
       0,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,   420,    21,    22,    23,    24,    25,
      26,    27,     0,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,     0,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,     0,
      72,    73,     0,     0,     0,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,     0,    85,     0,    86,
      87,    88,    89,     0,    90,     0,     0,     0,    91,    92,
      93,    94,    95,     0,     0,     0,     0,     0,     0,    96,
      97,    98,    99,   100,   101,   102,     0,     0,     0,   103,
     104,   105,   106,   107,     0,     0,     0,     0,   108,   109,
     110,   111,   112,   113,   114,   115,   116,     0,   117,   118,
       0,     0,   119,   120,   121,     0,  1317,     0,   122,     0,
     123,   124,   125,     0,   126,   127,   128,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   436,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,     0,   187,   188,   189,     0,   190,   191,   192,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     4,     0,     0,     0,     0,     5,     6,     0,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,     0,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
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
       0,     0,   141,   142,   143,     0,   144,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
       0,   187,   188,   189,     0,   190,   191,   192,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     4,     0,     0,     0,     0,     5,     6,     0,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
       0,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,     0,    63,    64,    65,
      66,    67,    68,    69,    70,    71,     0,     0,    72,    73,
       0,     0,     0,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,     0,    85,     0,    86,    87,    88,
      89,     0,    90,     0,     0,     0,    91,    92,    93,    94,
      95,     0,     0,     0,     0,     0,     0,    96,    97,    98,
      99,   100,   101,   102,     0,     0,     0,   103,   104,   105,
     106,   107,     0,     0,     0,     0,   108,   109,   110,   111,
     112,   113,   114,   115,   116,     0,   117,   118,     0,     0,
     119,   120,   121,     0,     0,     0,   122,     0,   123,   124,
     125,     0,   126,   127,   128,     0,   129,     0,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,     0,
       0,   141,   142,   143,     0,   436,   145,     0,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,     0,
     187,   188,   189,     0,   190,   191,   192,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
       1,     0,     0,     0,     0,     0,     0,     2,     3,     0,
       4,     0,     0,     0,     0,   410,   411,     0,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,   420,    21,    22,    23,    24,    25,    26,    27,     0,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
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
     141,   142,   143,     0,   436,   145,     0,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,     0,   187,
     188,   189,     0,   190,   191,   192,   193,   194,   195,     0,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,     1,
       0,     0,     0,     0,     0,     0,     2,     3,     0,     4,
       0,     0,     0,     0,   410,   411,     0,     7,   413,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,   419,
     420,    21,    22,   422,    24,    25,    26,    27,     0,   423,
     424,    30,   425,   426,   427,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,     0,    63,    64,    65,    66,    67,
      68,    69,    70,    71,     0,     0,    72,    73,     0,     0,
       0,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,     0,    85,     0,    86,    87,    88,    89,     0,
      90,     0,     0,     0,   431,    92,    93,    94,    95,     0,
       0,     0,     0,     0,     0,    96,    97,    98,    99,   100,
     101,   102,     0,     0,     0,   103,   104,   586,   106,   107,
       0,     0,     0,     0,   108,   109,   110,   111,   112,   113,
     114,   115,   116,     0,   587,   118,     0,     0,   119,   120,
     121,     0,     0,     0,   122,     0,   123,   124,   125,     0,
     126,   127,   128,     0,   129,     0,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,     0,     0,   141,
     142,   143,     0,   436,   145,     0,   146,   147,   148,   149,
     150,   151,   152,   437,   154,   439,   156,   440,   441,   159,
     160,   161,   162,   163,   164,   442,   166,   443,   444,   445,
     446,   171,   172,   447,   448,   175,   449,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,     0,   187,   188,
     189,     0,   190,   191,   192,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,     1,     0,
       0,     0,     0,     0,     0,     2,     3,     0,     4,     0,
       0,     0,     0,   410,   411,     0,     7,   413,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,   419,   420,
      21,    22,   422,    24,    25,    26,    27,     0,   423,   424,
      30,   425,   426,   427,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,     0,    63,    64,    65,    66,    67,    68,
      69,    70,    71,     0,     0,    72,    73,     0,     0,     0,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,     0,    85,     0,    86,    87,    88,    89,     0,    90,
       0,     0,     0,   431,    92,    93,    94,    95,     0,     0,
       0,     0,     0,     0,    96,    97,    98,    99,   100,   101,
     102,     0,     0,     0,   103,   104,   105,   106,   107,     0,
       0,     0,     0,   108,   109,   110,   111,   112,   113,   114,
     115,   116,     0,   117,   118,     0,     0,   119,   120,   121,
       0,     0,     0,   122,     0,   123,   124,   125,     0,   126,
     127,   128,     0,   129,     0,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,     0,     0,   141,   142,
     143,     0,   436,   145,     0,   146,   147,   148,   149,   150,
     151,   152,   437,   154,   439,   156,   440,   441,   159,   160,
     161,   162,   163,   164,   442,   166,   443,   444,   445,   446,
     171,   172,   447,   448,   175,   449,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,     0,   187,   188,   189,
       0,   190,   191,   192,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,     1,     0,     0,
       0,     0,     0,     0,     2,     3,     0,     4,     0,     0,
       0,     0,   968,   411,     0,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,   420,    21,
      22,    23,    24,    25,    26,    27,     0,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
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
       0,   436,   145,     0,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,     0,   187,   188,   189,     0,
     190,   191,   192,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,     1,     0,     0,     0,
       0,     0,     0,     2,     3,     0,     4,     0,     0,     0,
       0,   410,   411,     0,   412,   413,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,   419,   420,    21,    22,
     422,    24,    25,    26,    27,     0,   423,   424,    30,   425,
     426,   427,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,     0,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,     0,    72,    73,     0,     0,     0,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,     0,
      85,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,   431,    92,    93,    94,    95,     0,     0,     0,     0,
       0,     0,    96,    97,    98,    99,   100,   101,   102,     0,
       0,     0,   103,   104,     0,   106,   107,     0,     0,     0,
       0,   108,   109,   110,   111,   112,   113,   114,   115,   116,
       0,     0,     0,     0,     0,   119,   120,   121,     0,     0,
       0,   122,     0,   123,   124,   125,     0,   126,   127,   128,
       0,   129,     0,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,   143,     0,
     436,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     437,   154,   439,   156,   440,   441,   159,   160,   161,   162,
     163,   164,   442,   166,   443,   444,   445,   446,   171,   172,
     447,   448,   175,   449,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,     0,   187,   188,   189,     0,   190,
     191,   192,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     4,     0,     0,     0,     0,
     410,   411,     0,   412,   413,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,   419,   420,    21,    22,   422,
      24,    25,    26,    27,     0,   423,   424,    30,   425,   426,
     427,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
       0,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,     0,    72,    73,     0,     0,     0,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,     0,    85,
       0,    86,    87,    88,    89,     0,    90,     0,     0,     0,
     431,    92,    93,    94,    95,     0,     0,     0,     0,     0,
       0,    96,    97,    98,    99,   100,   101,   102,     0,     0,
       0,   103,   104,     0,   106,   107,     0,     0,     0,     0,
     108,   109,   110,   111,   112,   113,   114,   115,   116,     0,
       0,     0,     0,     0,   119,   120,   121,     0,     0,     0,
     122,     0,   123,   124,   125,     0,     0,     0,   128,     0,
     129,     0,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,   143,     0,   436,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   437,
     154,   439,   156,   440,   441,   159,   160,   161,   162,   163,
     164,   442,   166,   443,   444,   445,   446,   171,   172,   447,
     448,   175,   449,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,     0,   187,   188,   189,     0,   190,   191,
     192,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,     1,     0,     0,     0,     0,     0,
       0,     2,     3,     0,     0,     0,     0,     0,     0,   410,
     411,     0,   412,   413,   480,   415,   481,   482,   418,    14,
      15,    16,    17,    18,   419,   420,   483,    22,   422,    24,
      25,    26,    27,     0,   423,   424,    30,   425,   426,   427,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,     0,     0,    62,     0,
      63,    64,    65,   484,     0,     0,    69,    70,    71,     0,
       0,     0,    73,     0,     0,     0,     0,    75,    76,    77,
       0,     0,    80,    81,     0,     0,     0,     0,     0,     0,
      86,    87,    88,    89,     0,    90,     0,     0,     0,   431,
      92,    93,     0,     0,     0,     0,     0,     0,     0,     0,
      96,    97,    98,     0,   100,   101,   102,     0,     0,     0,
       0,     0,     0,   106,   107,     0,     0,     0,     0,   108,
     109,   110,   111,   434,   113,   114,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   121,     0,     0,     0,   122,
       0,   123,   124,     0,     0,     0,     0,   128,     0,   129,
       0,   130,   131,   132,   133,   435,   135,   136,   137,   138,
     139,   140,     0,     0,   141,   142,     0,     0,   436,   145,
       0,   146,   147,   148,   149,   150,   151,   152,   437,   154,
     439,   156,   440,   441,   159,   160,   161,   162,   163,   164,
     442,   166,   443,   444,   445,   446,   171,   172,   447,   448,
     175,   449,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,     0,   187,   188,   189,     0,   190,   191,   192,
     193,   194,   195,     0,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     0,     0,     0,     0,     0,     0,   410,   411,
       0,   412,   413,   414,   415,   416,   417,   418,    14,    15,
      16,    17,    18,   419,   420,   421,    22,   422,    24,    25,
      26,    27,     0,   423,   424,    30,   425,   426,   427,    34,
      35,    36,    37,    38,    39,    40,    41,    42,   428,   429,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,     0,     0,    62,     0,    63,
      64,    65,   430,     0,     0,    69,    70,    71,     0,     0,
       0,    73,     0,     0,     0,     0,    75,    76,    77,     0,
       0,    80,    81,     0,     0,     0,     0,     0,     0,    86,
      87,    88,    89,     0,    90,     0,     0,     0,   431,    92,
      93,     0,     0,     0,     0,     0,     0,     0,     0,    96,
      97,    98,     0,   100,   101,   102,     0,     0,     0,     0,
       0,     0,   106,   107,     0,     0,     0,     0,   108,   109,
     110,   111,   434,   113,   114,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   121,     0,     0,     0,   122,     0,
     123,     0,     0,     0,     0,     0,   128,     0,   129,     0,
     130,   131,   132,   133,   435,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,     0,     0,   436,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   437,   438,   439,
     156,   440,   441,   159,   160,   161,   162,   163,   164,   442,
     166,   443,   444,   445,   446,   171,   172,   447,   448,   175,
     449,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,     0,   187,   188,   189,     0,   190,   191,   192,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   461,     0,     0,     0,     3,     0,     0,     0,
       0,     0,     0,   410,   411,     0,   412,   413,   414,   415,
     416,   417,   418,    14,    15,    16,    17,    18,   419,   420,
     421,    22,   422,    24,    25,    26,    27,     0,   423,   424,
      30,   425,   426,   427,    34,    35,    36,    37,    38,    39,
      40,    41,    42,   428,   429,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
       0,     0,    62,     0,    63,    64,    65,   430,     0,     0,
      69,    70,    71,     0,     0,     0,    73,     0,     0,     0,
       0,    75,    76,    77,     0,     0,    80,    81,     0,     0,
       0,     0,     0,     0,    86,    87,    88,    89,     0,    90,
       0,     0,     0,   431,    92,    93,     0,     0,     0,     0,
       0,     0,     0,     0,    96,    97,    98,     0,   100,   101,
     102,   462,     0,     0,   463,     0,     0,   106,   107,     0,
       0,     0,     0,   108,   109,   110,   111,   434,   113,   114,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   121,
       0,     0,     0,   122,     0,   123,     0,     0,     0,     0,
       0,     0,     0,   129,     0,   130,   131,   132,   133,   435,
     135,   136,   137,   138,   139,   140,     0,     0,   141,   142,
       0,     0,   436,   145,     0,   146,   147,   148,   149,   150,
     151,   152,   437,   438,   439,   156,   440,   441,   159,   160,
     161,   162,   163,   164,   442,   166,   443,   444,   445,   446,
     171,   172,   447,   448,   175,   449,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,     0,   187,   188,   189,
       0,   190,   191,   192,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   461,     0,     0,
       0,     3,     0,   696,     0,     0,     0,     0,   410,   411,
       0,   412,   413,   414,   415,   416,   417,   418,    14,    15,
      16,    17,    18,   419,   420,   421,    22,   422,    24,    25,
      26,    27,     0,   423,   424,    30,   425,   426,   427,    34,
      35,    36,    37,    38,    39,    40,    41,    42,   428,   429,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,     0,     0,    62,     0,    63,
      64,    65,   430,     0,     0,    69,    70,    71,     0,     0,
       0,    73,     0,     0,     0,     0,    75,    76,    77,     0,
       0,    80,    81,     0,     0,     0,     0,     0,     0,    86,
      87,    88,    89,     0,    90,     0,     0,     0,   431,    92,
      93,     0,     0,     0,     0,     0,     0,     0,     0,    96,
      97,    98,     0,   100,   101,   102,     0,     0,     0,     0,
       0,     0,   106,   107,     0,     0,     0,     0,   108,   109,
     110,   111,   434,   113,   114,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   121,     0,     0,     0,   122,   697,
     123,     0,     0,     0,     0,     0,     0,     0,   129,     0,
     130,   131,   132,   133,   435,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,     0,     0,   436,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   437,   438,   439,
     156,   440,   441,   159,   160,   161,   162,   163,   164,   442,
     166,   443,   444,   445,   446,   171,   172,   447,   448,   175,
     449,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,     0,   187,   188,   189,     0,   190,   191,   192,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   461,     0,     0,     0,     3,     0,     0,     0,
       0,     0,     0,   410,   411,     0,   412,   413,   414,   415,
     416,   417,   418,    14,    15,    16,    17,    18,   419,   420,
     421,    22,   422,    24,    25,    26,    27,     0,   423,   424,
      30,   425,   426,   427,    34,    35,    36,    37,    38,    39,
      40,    41,    42,   428,   429,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
       0,     0,    62,     0,    63,    64,    65,   430,     0,     0,
      69,    70,    71,     0,     0,     0,    73,     0,     0,     0,
       0,    75,    76,    77,     0,     0,    80,    81,     0,     0,
       0,     0,     0,     0,    86,    87,    88,    89,     0,    90,
       0,     0,     0,   431,    92,    93,     0,     0,     0,     0,
       0,     0,     0,     0,    96,    97,    98,     0,   100,   101,
     102,     0,     0,     0,     0,     0,     0,   106,   107,     0,
       0,     0,     0,   108,   109,   110,   111,   434,   113,   114,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   121,
       0,     0,     0,   122,     0,   123,     0,     0,     0,     0,
       0,     0,     0,   129,     0,   130,   131,   132,   133,   435,
     135,   136,   137,   138,   139,   140,     0,     0,   141,   142,
       0,     0,   436,   145,     0,   146,   147,   148,   149,   150,
     151,   152,   437,   438,   439,   156,   440,   441,   159,   160,
     161,   162,   163,   164,   442,   166,   443,   444,   445,   446,
     171,   172,   447,   448,   175,   449,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,     0,   187,   188,   189,
       0,   190,   191,   192,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   494,     0,     3,
       0,     0,     0,     0,     0,     0,   410,   411,     0,   412,
     413,   414,   415,   416,   417,   418,    14,    15,    16,    17,
      18,   419,   420,   421,    22,   422,    24,    25,    26,    27,
       0,   423,   424,    30,   425,   426,   427,    34,    35,    36,
      37,    38,    39,    40,    41,    42,   428,   429,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,     0,     0,    62,     0,    63,    64,    65,
     430,     0,     0,    69,    70,    71,     0,     0,     0,    73,
       0,     0,     0,     0,    75,    76,    77,     0,     0,    80,
      81,     0,     0,     0,     0,     0,     0,    86,    87,    88,
      89,     0,    90,     0,     0,     0,   431,    92,    93,     0,
       0,     0,     0,     0,     0,     0,     0,    96,    97,    98,
       0,   100,   101,   102,     0,     0,     0,     0,     0,     0,
     106,   107,     0,     0,     0,     0,   108,   109,   110,   111,
     434,   113,   114,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   121,     0,     0,     0,   122,     0,   123,     0,
       0,     0,     0,     0,     0,     0,   129,     0,   130,   131,
     132,   133,   435,   135,   136,   137,   138,   139,   140,     0,
       0,   141,   142,     0,     0,   436,   145,     0,   146,   147,
     148,   149,   150,   151,   152,   437,   438,   439,   156,   440,
     441,   159,   160,   161,   162,   163,   164,   442,   166,   443,
     444,   445,   446,   171,   172,   447,   448,   175,   449,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,     0,
     187,   188,   189,     0,   190,   191,   192,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
       3,     0,     0,     0,     0,     0,     0,   410,   411,     0,
     412,   413,   480,   415,   481,   482,   987,    14,    15,    16,
      17,    18,   419,   420,   483,    22,   422,    24,    25,    26,
      27,     0,   423,   424,    30,   425,   426,   427,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,     0,     0,    62,     0,    63,    64,
      65,   484,     0,     0,    69,    70,    71,     0,     0,     0,
      73,     0,     0,     0,     0,    75,    76,    77,     0,     0,
      80,    81,     0,     0,     0,     0,     0,     0,    86,    87,
      88,    89,     0,    90,     0,     0,     0,   431,    92,    93,
       0,     0,     0,     0,     0,     0,     0,     0,    96,    97,
      98,     0,   100,   101,   988,     0,     0,     0,   989,     0,
       0,   106,   107,     0,     0,     0,     0,   108,   109,   110,
     111,   434,   113,   114,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   121,     0,     0,     0,   122,  1353,   123,
     124,     0,     0,     0,     0,  1354,     0,   129,     0,   130,
     131,   132,   133,   435,   135,   136,   137,   138,   139,   140,
       0,     0,   990,   142,     0,     0,   436,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   437,   154,   439,   156,
     440,   441,   159,   160,   161,   162,   163,   164,   442,   166,
     443,   444,   445,   446,   171,   172,   447,   448,   175,   449,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
       0,   187,   188,   189,     0,   190,   191,   192,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,     3,     0,     0,     0,     0,     0,     0,   410,   411,
       0,   412,   413,   480,   415,   481,   482,   987,    14,    15,
      16,    17,    18,   419,   420,   483,    22,   422,    24,    25,
      26,    27,     0,   423,   424,    30,   425,   426,   427,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,     0,     0,    62,     0,    63,
      64,    65,   484,     0,     0,    69,    70,    71,     0,     0,
       0,    73,     0,     0,     0,     0,    75,    76,    77,     0,
       0,    80,    81,  1285,     0,     0,     0,     0,     0,    86,
      87,    88,    89,     0,    90,     0,     0,     0,   431,    92,
      93,     0,     0,     0,     0,     0,     0,     0,     0,    96,
      97,    98,     0,   100,   101,   988,     0,     0,     0,   989,
       0,     0,   106,   107,     0,     0,     0,     0,   108,   109,
     110,   111,   434,   113,   114,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   121,     0,     0,     0,   122,     0,
     123,   124,     0,     0,     0,     0,     0,     0,   129,     0,
     130,   131,   132,   133,   435,   135,   136,   137,   138,   139,
     140,     0,     0,   990,   142,     0,     0,   436,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   437,   154,   439,
     156,   440,   441,   159,   160,   161,   162,   163,   164,   442,
     166,   443,   444,   445,   446,   171,   172,   447,   448,   175,
     449,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,     0,   187,   188,   189,     0,   190,   191,   192,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,     3,     0,     0,     0,     0,     0,     0,   410,
     411,     0,   412,   413,   414,   415,   416,   417,   418,    14,
      15,    16,    17,    18,   419,   420,   421,    22,   422,    24,
      25,    26,    27,     0,   423,   424,    30,   425,   426,   427,
      34,    35,    36,    37,    38,    39,    40,    41,    42,   428,
     429,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,     0,     0,    62,     0,
      63,    64,    65,   430,     0,     0,    69,    70,    71,     0,
       0,     0,    73,     0,     0,     0,     0,    75,    76,    77,
       0,     0,    80,    81,     0,     0,     0,     0,     0,     0,
      86,    87,    88,    89,     0,    90,     0,     0,     0,   431,
      92,    93,     0,     0,     0,     0,     0,     0,     0,     0,
      96,    97,    98,     0,   100,   101,   102,   432,     0,     0,
     433,     0,     0,   106,   107,     0,     0,     0,     0,   108,
     109,   110,   111,   434,   113,   114,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   121,     0,     0,     0,   122,
       0,   123,     0,     0,     0,     0,     0,     0,     0,   129,
       0,   130,   131,   132,   133,   435,   135,   136,   137,   138,
     139,   140,     0,     0,   141,   142,     0,     0,   436,   145,
       0,   146,   147,   148,   149,   150,   151,   152,   437,   438,
     439,   156,   440,   441,   159,   160,   161,   162,   163,   164,
     442,   166,   443,   444,   445,   446,   171,   172,   447,   448,
     175,   449,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,     0,   187,   188,   189,     0,   190,   191,   192,
     193,   194,   195,     0,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,     3,     0,     0,     0,     0,     0,     0,
     410,   411,     0,   412,   413,   414,   415,   416,   417,   418,
      14,    15,    16,    17,    18,   419,   420,   421,    22,   422,
      24,    25,    26,    27,     0,   423,   424,    30,   425,   426,
     427,    34,    35,    36,    37,    38,    39,    40,    41,    42,
     428,   429,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,     0,     0,    62,
       0,    63,    64,    65,   430,     0,     0,    69,    70,    71,
       0,     0,     0,    73,     0,     0,     0,     0,    75,    76,
      77,     0,     0,    80,    81,     0,     0,     0,     0,     0,
       0,    86,    87,    88,    89,     0,    90,     0,     0,     0,
     431,    92,    93,     0,     0,     0,     0,     0,     0,     0,
       0,    96,    97,    98,     0,   100,   101,   102,   477,     0,
       0,   478,     0,     0,   106,   107,     0,     0,     0,     0,
     108,   109,   110,   111,   434,   113,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121,     0,     0,     0,
     122,     0,   123,     0,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   435,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,     0,     0,   436,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   437,
     438,   439,   156,   440,   441,   159,   160,   161,   162,   163,
     164,   442,   166,   443,   444,   445,   446,   171,   172,   447,
     448,   175,   449,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,     0,   187,   188,   189,     0,   190,   191,
     192,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,     3,     0,     0,     0,     0,     0,
       0,   410,   411,     0,   412,   413,   414,   415,   416,   417,
     418,    14,    15,    16,    17,    18,   419,   420,   421,    22,
     422,    24,    25,    26,    27,     0,   423,   424,    30,   425,
     426,   427,    34,    35,    36,    37,    38,    39,    40,    41,
      42,   428,   429,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,     0,     0,
      62,     0,    63,    64,    65,   430,     0,     0,    69,    70,
      71,     0,     0,     0,    73,     0,     0,     0,     0,    75,
      76,    77,     0,     0,    80,    81,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,   431,    92,    93,     0,     0,     0,     0,     0,     0,
       0,     0,    96,    97,    98,     0,   100,   101,   102,     0,
       0,     0,     0,     0,     0,   106,   107,     0,     0,     0,
       0,   108,   109,   110,   111,   434,   113,   114,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   121,     0,     0,
       0,   122,   673,   123,     0,     0,     0,     0,     0,   674,
       0,   129,     0,   130,   131,   132,   133,   435,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,     0,     0,
     436,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     437,   438,   439,   156,   440,   441,   159,   160,   161,   162,
     163,   164,   442,   166,   443,   444,   445,   446,   171,   172,
     447,   448,   175,   449,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,     0,   187,   188,   189,     0,   190,
     191,   192,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,     3,     0,     0,     0,     0,
       0,     0,   410,   411,     0,   412,   413,   414,   415,   416,
     417,   418,    14,    15,    16,    17,    18,   419,   420,   421,
      22,   422,    24,    25,    26,    27,     0,   423,   424,    30,
     425,   426,   427,    34,    35,    36,    37,    38,    39,    40,
      41,    42,   428,   429,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,     0,
       0,    62,     0,    63,    64,    65,   430,     0,     0,    69,
      70,    71,     0,     0,     0,    73,     0,     0,     0,     0,
      75,    76,    77,     0,     0,    80,    81,     0,     0,     0,
       0,     0,     0,    86,    87,    88,    89,     0,    90,     0,
       0,     0,   431,    92,    93,     0,     0,     0,     0,     0,
       0,     0,     0,    96,    97,    98,     0,   100,   101,   102,
       0,     0,     0,     0,     0,     0,   106,   107,     0,     0,
       0,     0,   108,   109,   110,   111,   434,   113,   114,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   121,     0,
       0,     0,   122,   720,   123,     0,     0,     0,     0,     0,
     721,     0,   129,     0,   130,   131,   132,   133,   435,   135,
     136,   137,   138,   139,   140,     0,     0,   141,   142,     0,
       0,   436,   145,     0,   146,   147,   148,   149,   150,   151,
     152,   437,   438,   439,   156,   440,   441,   159,   160,   161,
     162,   163,   164,   442,   166,   443,   444,   445,   446,   171,
     172,   447,   448,   175,   449,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,     0,   187,   188,   189,     0,
     190,   191,   192,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,     3,     0,     0,     0,
       0,     0,     0,   410,   411,     0,   412,   413,   480,   415,
     481,   482,   987,    14,    15,    16,    17,    18,   419,   420,
     483,    22,   422,    24,    25,    26,    27,     0,   423,   424,
      30,   425,   426,   427,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
       0,     0,    62,     0,    63,    64,    65,   484,     0,     0,
      69,    70,    71,     0,     0,     0,    73,     0,     0,     0,
       0,    75,    76,    77,     0,     0,    80,    81,     0,     0,
       0,     0,     0,     0,    86,    87,    88,    89,     0,    90,
       0,     0,     0,   431,    92,    93,     0,     0,     0,     0,
       0,     0,     0,     0,    96,    97,    98,     0,   100,   101,
     988,     0,     0,     0,   989,     0,     0,   106,   107,     0,
       0,     0,     0,   108,   109,   110,   111,   434,   113,   114,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   121,
       0,     0,     0,   122,     0,   123,   124,     0,     0,     0,
       0,     0,     0,   129,     0,   130,   131,   132,   133,   435,
     135,   136,   137,   138,   139,   140,     0,     0,   990,   142,
       0,     0,   436,   145,     0,   146,   147,   148,   149,   150,
     151,   152,   437,   154,   439,   156,   440,   441,   159,   160,
     161,   162,   163,   164,   442,   166,   443,   444,   445,   446,
     171,   172,   447,   448,   175,   449,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,     0,   187,   188,   189,
       0,   190,   191,   192,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,     3,     0,     0,
       0,     0,     0,     0,   410,   411,     0,   412,   413,   480,
     415,   481,   482,   987,    14,    15,    16,    17,    18,   419,
     420,   483,    22,   422,    24,    25,    26,    27,     0,   423,
     424,    30,   425,   426,   427,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,     0,     0,    62,     0,    63,    64,    65,   484,     0,
       0,    69,    70,    71,     0,     0,     0,    73,     0,     0,
       0,     0,    75,    76,    77,     0,     0,    80,    81,     0,
       0,     0,     0,     0,     0,    86,    87,    88,    89,     0,
      90,     0,     0,     0,   431,    92,    93,     0,     0,     0,
       0,     0,     0,     0,     0,    96,    97,    98,     0,   100,
     101,   988,     0,     0,     0,   989,     0,     0,   106,   107,
       0,     0,     0,     0,   108,   109,   110,   111,   434,   113,
     114,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     121,     0,     0,     0,   122,     0,   123,   124,     0,     0,
       0,     0,     0,     0,   129,     0,   130,   131,   132,   133,
     435,   135,   136,   137,   138,   139,   140,     0,     0,   141,
     142,     0,     0,   436,   145,     0,   146,   147,   148,   149,
     150,   151,   152,   437,   154,   439,   156,   440,   441,   159,
     160,   161,   162,   163,   164,   442,   166,   443,   444,   445,
     446,   171,   172,   447,   448,   175,   449,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,     0,   187,   188,
     189,     0,   190,   191,   192,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,     3,     0,
       0,     0,     0,     0,     0,   410,   411,     0,   412,   413,
     414,   415,   416,   417,   418,    14,    15,    16,    17,    18,
     419,   420,   421,    22,   422,    24,    25,    26,    27,     0,
     423,   424,    30,   425,   426,   427,    34,    35,    36,    37,
      38,    39,    40,    41,    42,   428,   429,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,     0,     0,    62,     0,    63,    64,    65,   430,
       0,     0,    69,    70,    71,     0,     0,     0,    73,     0,
       0,     0,     0,    75,    76,    77,     0,     0,    80,    81,
       0,     0,     0,     0,     0,     0,    86,    87,    88,    89,
       0,    90,     0,     0,     0,   431,    92,    93,     0,     0,
       0,     0,     0,     0,     0,     0,    96,    97,    98,     0,
     100,   101,   102,     0,     0,     0,     0,     0,     0,   106,
     107,     0,     0,     0,     0,   108,   109,   110,   111,   434,
     113,   114,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   121,     0,     0,     0,   122,     0,   123,     0,     0,
       0,     0,     0,     0,     0,   129,     0,   130,   131,   132,
     133,   435,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,     0,     0,   436,   145,     0,   146,   147,   148,
     149,   150,   151,   152,   437,   438,   439,   156,   440,   441,
     159,   160,   161,   162,   163,   164,   442,   166,   443,   444,
     445,   446,   171,   172,   447,   448,   175,   449,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,     0,   187,
     188,   189,     0,   190,   191,   192,   193,   194,   195,     0,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         9,   573,   376,   531,   116,   814,   815,   306,   883,   727,
     912,   570,    21,   528,   812,   813,   574,   575,   576,   577,
     646,   706,  1036,   127,  1196,   949,  1207,  1208,    68,   570,
      20,    60,    21,   769,   553,    86,   555,   556,  1339,   558,
     702,   560,   604,   132,   706,    88,    85,   110,  1095,   568,
     569,   550,   847,  1273,  1169,    86,     7,    66,   971,    68,
      86,    99,    46,    88,    99,    88,    99,    99,     8,     9,
      88,   121,    99,    82,   110,    53,   812,   813,    99,    99,
      99,   132,   126,   207,    99,   459,   460,    99,   773,   150,
     775,    99,    86,    88,    88,   104,    20,   110,    98,     8,
       9,    43,    30,    99,   902,    26,    99,   116,    92,   118,
      86,   847,   102,    25,   137,   124,   159,   117,    86,   595,
     244,    99,   598,   110,   114,   601,   103,    48,   146,    41,
     180,    20,   105,   172,   159,   173,    30,    65,    32,    33,
     176,   176,   878,   137,   176,  1058,   190,   180,    42,   139,
     177,   469,   215,   143,   137,    95,   146,   137,   177,   180,
     180,   137,   175,   258,   176,  1346,   902,    86,   176,   137,
     265,    65,    66,   113,   263,   115,   166,   119,   207,    86,
     176,   105,   146,   176,   502,   503,    95,   505,   506,   507,
     508,   853,     8,     9,   989,    89,   227,   515,   516,   242,
     243,   227,   245,   143,   113,   309,   115,   147,  1323,   252,
     225,   529,   263,   164,   203,   244,  1091,   242,   243,   262,
     245,   539,   540,   163,  1126,  1526,   150,   945,   787,   788,
    1450,   274,   143,   296,   143,  1282,  1160,   262,   147,   901,
     263,   926,  1543,   227,   184,  1169,   787,   788,   176,   274,
    1551,   246,   247,   989,   163,  1427,   630,   241,     8,     9,
     250,   150,   202,   782,    99,    99,   928,   829,   830,   263,
     254,   383,   256,   282,   314,   184,   775,   317,    86,    95,
     263,   215,   600,   263,   178,   603,   220,   271,   120,   208,
     209,   275,   404,   202,   267,   268,   269,   113,   109,   115,
     273,   208,   209,     8,   223,   314,     4,  1105,   317,     4,
       8,    99,    99,     8,    19,    99,   223,   120,    20,   693,
    1118,   215,  1007,    88,   134,   136,     8,   143,   159,  1510,
      86,   147,   127,   148,   146,   143,   143,    19,   149,   148,
     105,   176,   176,   126,   148,    95,  1393,   163,   143,   143,
     165,   463,   146,   171,   186,   165,   165,   140,   367,   166,
     191,   165,  1098,   113,   373,   115,   146,   185,   184,  1105,
     379,   127,   183,   183,   383,  1389,   132,    58,    59,   188,
     389,   146,  1118,   186,   188,   148,   202,   396,   176,   176,
     135,   143,   176,   143,   146,   404,   405,   147,   127,  1323,
     102,   146,   165,   211,   212,   199,  1281,    88,   113,  1035,
     115,  1458,   114,   163,   143,   113,  1214,   115,   113,   124,
     115,   110,    56,    57,   433,   123,   138,   110,   123,   406,
      45,   113,   409,   115,   184,  1482,    51,   139,   143,    54,
      55,   143,   124,   155,   146,   143,   764,    62,   143,   127,
     143,  1023,   202,   771,   463,   432,    54,   466,   467,   468,
     975,   143,  1021,   159,   166,   143,   475,    30,   892,   478,
     894,    34,   171,  1032,   451,   452,   110,   454,  1214,   488,
    1021,   458,   856,   857,   156,   462,   185,   861,   592,   593,
     789,  1032,  1539,   844,  1541,   191,   259,  1466,  1467,   171,
     477,   510,  1404,   266,   146,   238,   239,   858,    71,   518,
    1557,   885,    87,   276,   938,   492,   940,    58,    59,   138,
      61,   498,   259,    98,   220,    92,  1495,   260,    88,   266,
     253,   849,  1501,   108,   146,    98,   155,   855,   105,   276,
     517,   264,   117,   158,   253,   105,   161,    88,   122,   190,
     215,   143,   217,   289,   146,   264,   130,   131,   199,   133,
     175,   297,   110,   127,   267,   268,   269,   141,   132,   110,
     273,   145,   143,   147,    34,    35,    36,   689,   152,    39,
     692,   277,   278,   279,   280,   281,   201,   283,   284,   285,
     286,   287,   127,   143,   168,   158,   605,   132,   607,   205,
     316,   919,   920,  1321,   922,   321,   924,  1325,   211,   212,
     213,   215,   589,   217,   290,   291,   625,   594,   192,   193,
     194,   195,   196,   197,   146,   144,   944,   146,   222,   638,
     224,   222,   215,   224,  1432,   110,  1434,   955,   956,   957,
     143,   959,   960,   961,   962,   963,   964,   232,   966,   967,
     181,   182,   661,   662,   663,   118,   119,   281,   282,   232,
     978,  1459,    58,    59,   118,   119,   370,   371,  1240,  1241,
     571,   572,   233,   682,  1483,  1233,   578,   579,   146,  1477,
     689,   580,   581,   692,   143,  1003,   110,  1005,  1006,   180,
    1249,     0,   669,   670,   180,   157,  1432,  1415,  1434,   676,
    1418,   710,  1379,  1380,    84,   249,    68,   189,  1249,   686,
      93,   144,    94,    34,    34,    34,    20,   726,   110,   142,
     288,   283,   699,  1459,   293,   143,   143,   143,   176,   288,
     176,   143,   143,  1051,  1262,   274,   274,   110,   110,   143,
     146,  1477,   176,   146,   146,   146,   723,  1121,   146,    27,
      15,  1069,  1470,   203,   763,   176,    20,   176,    25,   158,
     769,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,   110,   749,   160,   221,   160,    99,    34,    35,    36,
      37,    38,    39,   221,    86,    86,    86,   139,    20,    46,
     150,    99,    99,  1365,  1366,   150,   122,    20,   122,   117,
     289,   143,  1120,   812,   813,   814,   815,   173,   176,   786,
     173,    86,   173,    30,    71,  1133,   173,   173,   176,  1137,
    1138,   215,  1140,   173,   173,    88,    88,  1145,   176,  1203,
     176,    99,   176,   132,    86,   176,   176,   173,   847,   173,
     173,   227,   132,   173,   176,   180,   103,   104,   105,   110,
     160,   110,   110,   137,   110,   275,   173,   248,   174,   132,
     166,   250,   257,   132,    86,    20,   276,  1439,   122,   276,
     217,   268,    92,   143,   289,   173,   173,   173,    86,   110,
     173,  1199,   187,   892,   122,   894,   122,    88,   143,   110,
     150,   173,  1210,   902,   137,   110,   143,   132,    27,   244,
      20,   173,   159,   110,   143,   236,   110,  1225,    71,   886,
    1228,    99,  1230,    99,    47,    34,    35,    36,    37,    38,
      39,   146,   173,   137,   137,  1299,   176,    46,   146,   938,
     146,   940,   173,    52,   191,   137,   134,   240,   276,    20,
      20,   227,   295,   272,    63,    64,   240,   180,    67,   276,
     176,    70,    71,   134,   173,   277,    99,   132,   137,   110,
     110,    61,   122,   220,   217,   176,   176,   176,   217,   217,
     176,   176,     6,   132,   983,   175,  1350,   986,   223,   223,
     989,   180,    98,   223,   103,   104,   105,    98,   137,   223,
    1308,  1000,  1310,  1002,   251,   173,   176,   227,  1316,   176,
     176,    20,    20,    88,   270,   175,   160,   173,   116,    88,
     247,  1329,  1330,  1331,  1332,  1333,   173,  1335,  1336,   261,
     277,   278,   279,   280,   281,   173,   283,   284,   285,   286,
     287,   150,   173,    86,   176,   292,    20,   176,    99,   160,
     159,    86,    59,   110,  1362,    86,   186,    20,   277,    99,
      86,   110,   255,   215,   110,   186,   186,   175,   110,   215,
     175,    85,   172,   186,   110,   143,   294,   294,   110,   176,
     294,   283,   191,   110,   188,   110,   241,   215,  1055,  1065,
     238,  1399,   277,  1401,   527,  1403,   238,   527,   235,   629,
     848,   210,   381,  1098,  1458,  1482,  1105,   903,   295,   295,
    1192,   220,   295,   457,   933,   400,   242,   281,   986,  1118,
    1314,  1135,  1200,  1147,  1212,   978,  1210,  1207,   488,  1130,
     551,  1130,   552,  1250,  1106,   603,  1135,   727,  1501,   302,
    1160,  1108,   251,  1495,  1092,   815,   787,  1146,  1064,   476,
     894,  1187,  1197,  1249,  1021,  1032,  1025,  1246,   476,   788,
     797,  1128,  1081,  1271,  1382,  1022,    -1,  1166,   277,   278,
     279,   280,   281,    -1,   283,   284,   285,   286,   287,    -1,
      -1,    -1,  1490,   292,    -1,  1152,    -1,    -1,  1187,    -1,
     372,    -1,    -1,    -1,    -1,    -1,    -1,  1196,    -1,    -1,
      -1,  1200,    -1,  1511,    -1,    -1,    -1,  1515,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1214,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1536,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1279,    -1,    -1,    -1,    -1,    -1,  1285,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1311,  1312,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1322,    -1,    -1,    -1,  1326,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1400,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1416,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1427,    -1,
      -1,    -1,    -1,  1432,    -1,  1434,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1454,    -1,    -1,  1457,    -1,
    1459,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1473,    -1,    -1,    -1,  1477,    -1,
      -1,    -1,    -1,    -1,  1483,    -1,  1485,    -1,    -1,    -1,
      -1,    -1,  1491,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1513,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1531,    -1,  1533,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    10,    -1,    -1,    -1,    -1,  1546,    -1,    17,
      18,  1550,    20,    -1,    -1,    -1,  1555,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    -1,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    -1,    97,
      98,    -1,    -1,    -1,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,    -1,   114,    -1,   116,   117,
     118,   119,    -1,   121,    -1,    -1,    -1,   125,   126,   127,
     128,   129,    -1,    -1,    -1,    -1,    -1,    -1,   136,   137,
     138,   139,   140,   141,   142,    -1,    -1,    -1,   146,   147,
     148,   149,   150,    -1,    -1,    -1,    -1,   155,   156,   157,
     158,   159,   160,   161,   162,   163,    -1,   165,   166,    -1,
      -1,   169,   170,   171,    -1,    -1,    -1,   175,    -1,   177,
     178,   179,    -1,   181,   182,   183,    -1,   185,    -1,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
      -1,    -1,   200,   201,   202,    -1,   204,   205,    -1,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
      -1,   249,   250,   251,    -1,   253,   254,   255,   256,   257,
     258,    -1,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    20,    -1,    -1,    -1,    -1,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    -1,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    -1,    97,
      98,    -1,    -1,    -1,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,    -1,   114,    -1,   116,   117,
     118,   119,    -1,   121,    -1,    -1,    -1,   125,   126,   127,
     128,   129,    -1,    -1,    -1,    -1,    -1,    -1,   136,   137,
     138,   139,   140,   141,   142,    -1,    -1,    -1,   146,   147,
     148,   149,   150,    -1,    -1,    -1,    -1,   155,   156,   157,
     158,   159,   160,   161,   162,   163,    -1,   165,   166,    -1,
      -1,   169,   170,   171,    -1,    -1,    -1,   175,   176,   177,
     178,   179,    -1,   181,   182,   183,    -1,   185,    -1,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
      -1,    -1,   200,   201,   202,    -1,   204,   205,    -1,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
      -1,   249,   250,   251,    -1,   253,   254,   255,   256,   257,
     258,    -1,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      -1,    20,    -1,    -1,    -1,    -1,    25,    26,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    -1,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    -1,    97,    98,
      -1,    -1,    -1,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,    -1,   114,    -1,   116,   117,   118,
     119,    -1,   121,    -1,    -1,    -1,   125,   126,   127,   128,
     129,    -1,    -1,    -1,    -1,    -1,    -1,   136,   137,   138,
     139,   140,   141,   142,    -1,    -1,    -1,   146,   147,   148,
     149,   150,    -1,    -1,    -1,    -1,   155,   156,   157,   158,
     159,   160,   161,   162,   163,    -1,   165,   166,    -1,    -1,
     169,   170,   171,    -1,   173,    -1,   175,    -1,   177,   178,
     179,    -1,   181,   182,   183,    -1,   185,    -1,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,    -1,
      -1,   200,   201,   202,    -1,   204,   205,    -1,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,    -1,
     249,   250,   251,    -1,   253,   254,   255,   256,   257,   258,
      -1,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,
      20,    -1,    -1,    -1,    -1,    25,    26,    -1,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    -1,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    -1,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    -1,    -1,    97,    98,    -1,
      -1,    -1,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,    -1,   114,    -1,   116,   117,   118,   119,
      -1,   121,    -1,    -1,    -1,   125,   126,   127,   128,   129,
      -1,    -1,    -1,    -1,    -1,    -1,   136,   137,   138,   139,
     140,   141,   142,    -1,    -1,    -1,   146,   147,   148,   149,
     150,    -1,    -1,    -1,    -1,   155,   156,   157,   158,   159,
     160,   161,   162,   163,    -1,   165,   166,    -1,    -1,   169,
     170,   171,    -1,    -1,    -1,   175,   176,   177,   178,   179,
      -1,   181,   182,   183,    -1,   185,    -1,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,    -1,    -1,
     200,   201,   202,    -1,   204,   205,    -1,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,    -1,   249,
     250,   251,    -1,   253,   254,   255,   256,   257,   258,    -1,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,
      -1,    -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    -1,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    -1,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    -1,    -1,    97,    98,    -1,    -1,
      -1,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,    -1,   114,    -1,   116,   117,   118,   119,    -1,
     121,    -1,    -1,    -1,   125,   126,   127,   128,   129,    -1,
      -1,    -1,    -1,    -1,    -1,   136,   137,   138,   139,   140,
     141,   142,    -1,    -1,    -1,   146,   147,   148,   149,   150,
      -1,    -1,    -1,    -1,   155,   156,   157,   158,   159,   160,
     161,   162,   163,    -1,   165,   166,    -1,    -1,   169,   170,
     171,    -1,    -1,    -1,   175,   176,   177,   178,   179,    -1,
     181,   182,   183,    -1,   185,    -1,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,    -1,    -1,   200,
     201,   202,    -1,   204,   205,    -1,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    -1,   249,   250,
     251,    -1,   253,   254,   255,   256,   257,   258,    -1,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,
      -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    -1,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    -1,    -1,    97,    98,    -1,    -1,    -1,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,    -1,   114,    -1,   116,   117,   118,   119,    -1,   121,
      -1,    -1,    -1,   125,   126,   127,   128,   129,    -1,    -1,
      -1,    -1,    -1,    -1,   136,   137,   138,   139,   140,   141,
     142,    -1,    -1,    -1,   146,   147,   148,   149,   150,    -1,
      -1,    -1,    -1,   155,   156,   157,   158,   159,   160,   161,
     162,   163,    -1,   165,   166,    -1,    -1,   169,   170,   171,
      -1,   173,    -1,   175,    -1,   177,   178,   179,    -1,   181,
     182,   183,    -1,   185,    -1,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,    -1,    -1,   200,   201,
     202,    -1,   204,   205,    -1,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,    -1,   249,   250,   251,
      -1,   253,   254,   255,   256,   257,   258,    -1,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,
      -1,    -1,    25,    26,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    -1,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,    -1,    97,    98,    -1,    -1,    -1,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
      -1,   114,    -1,   116,   117,   118,   119,    -1,   121,    -1,
      -1,    -1,   125,   126,   127,   128,   129,    -1,    -1,    -1,
      -1,    -1,    -1,   136,   137,   138,   139,   140,   141,   142,
      -1,    -1,    -1,   146,   147,   148,   149,   150,    -1,    -1,
      -1,    -1,   155,   156,   157,   158,   159,   160,   161,   162,
     163,    -1,   165,   166,    -1,    -1,   169,   170,   171,    -1,
     173,    -1,   175,    -1,   177,   178,   179,    -1,   181,   182,
     183,    -1,   185,    -1,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,    -1,    -1,   200,   201,   202,
      -1,   204,   205,    -1,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,    -1,   249,   250,   251,    -1,
     253,   254,   255,   256,   257,   258,    -1,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,
      -1,    25,    26,    -1,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    -1,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    -1,    97,    98,    -1,    -1,    -1,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,    -1,
     114,    -1,   116,   117,   118,   119,    -1,   121,    -1,    -1,
      -1,   125,   126,   127,   128,   129,    -1,    -1,    -1,    -1,
      -1,    -1,   136,   137,   138,   139,   140,   141,   142,    -1,
      -1,    -1,   146,   147,   148,   149,   150,    -1,    -1,    -1,
      -1,   155,   156,   157,   158,   159,   160,   161,   162,   163,
      -1,   165,   166,    -1,    -1,   169,   170,   171,    -1,   173,
      -1,   175,    -1,   177,   178,   179,    -1,   181,   182,   183,
      -1,   185,    -1,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,    -1,    -1,   200,   201,   202,    -1,
     204,   205,    -1,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,    -1,   249,   250,   251,    -1,   253,
     254,   255,   256,   257,   258,    -1,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    -1,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      -1,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    -1,    97,    98,    -1,    -1,    -1,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,    -1,   114,
      -1,   116,   117,   118,   119,    -1,   121,    -1,    -1,    -1,
     125,   126,   127,   128,   129,    -1,    -1,    -1,    -1,    -1,
      -1,   136,   137,   138,   139,   140,   141,   142,    -1,    -1,
      -1,   146,   147,   148,   149,   150,    -1,    -1,    -1,    -1,
     155,   156,   157,   158,   159,   160,   161,   162,   163,    -1,
     165,   166,    -1,    -1,   169,   170,   171,    -1,   173,    -1,
     175,    -1,   177,   178,   179,    -1,   181,   182,   183,    -1,
     185,    -1,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,    -1,    -1,   200,   201,   202,    -1,   204,
     205,    -1,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,    -1,   249,   250,   251,    -1,   253,   254,
     255,   256,   257,   258,    -1,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,    25,
      26,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    -1,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      -1,    97,    98,    -1,    -1,    -1,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,    -1,   114,    -1,
     116,   117,   118,   119,    -1,   121,    -1,    -1,    -1,   125,
     126,   127,   128,   129,    -1,    -1,    -1,    -1,    -1,    -1,
     136,   137,   138,   139,   140,   141,   142,    -1,    -1,    -1,
     146,   147,   148,   149,   150,    -1,    -1,    -1,    -1,   155,
     156,   157,   158,   159,   160,   161,   162,   163,    -1,   165,
     166,    -1,    -1,   169,   170,   171,    -1,   173,    -1,   175,
      -1,   177,   178,   179,    -1,   181,   182,   183,    -1,   185,
      -1,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,    -1,    -1,   200,   201,   202,    -1,   204,   205,
      -1,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,    -1,   249,   250,   251,    -1,   253,   254,   255,
     256,   257,   258,    -1,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    20,    -1,    -1,    -1,    -1,    25,    26,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    -1,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    -1,    -1,
      97,    98,    -1,    -1,    -1,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,    -1,   114,    -1,   116,
     117,   118,   119,    -1,   121,    -1,    -1,    -1,   125,   126,
     127,   128,   129,    -1,    -1,    -1,    -1,    -1,    -1,   136,
     137,   138,   139,   140,   141,   142,    -1,    -1,    -1,   146,
     147,   148,   149,   150,    -1,    -1,    -1,    -1,   155,   156,
     157,   158,   159,   160,   161,   162,   163,    -1,   165,   166,
      -1,    -1,   169,   170,   171,    -1,   173,    -1,   175,    -1,
     177,   178,   179,    -1,   181,   182,   183,    -1,   185,    -1,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,    -1,    -1,   200,   201,   202,    -1,   204,   205,    -1,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,    -1,   249,   250,   251,    -1,   253,   254,   255,   256,
     257,   258,    -1,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    20,    -1,    -1,    -1,    -1,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    -1,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    -1,    97,
      98,    -1,    -1,    -1,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,    -1,   114,    -1,   116,   117,
     118,   119,    -1,   121,    -1,    -1,    -1,   125,   126,   127,
     128,   129,    -1,    -1,    -1,    -1,    -1,    -1,   136,   137,
     138,   139,   140,   141,   142,    -1,    -1,    -1,   146,   147,
     148,   149,   150,    -1,    -1,    -1,    -1,   155,   156,   157,
     158,   159,   160,   161,   162,   163,    -1,   165,   166,    -1,
      -1,   169,   170,   171,    -1,    -1,    -1,   175,    -1,   177,
     178,   179,    -1,   181,   182,   183,    -1,   185,    -1,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
      -1,    -1,   200,   201,   202,    -1,   204,   205,    -1,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
      -1,   249,   250,   251,    -1,   253,   254,   255,   256,   257,
     258,    -1,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      -1,    20,    -1,    -1,    -1,    -1,    25,    26,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    -1,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    -1,    97,    98,
      -1,    -1,    -1,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,    -1,   114,    -1,   116,   117,   118,
     119,    -1,   121,    -1,    -1,    -1,   125,   126,   127,   128,
     129,    -1,    -1,    -1,    -1,    -1,    -1,   136,   137,   138,
     139,   140,   141,   142,    -1,    -1,    -1,   146,   147,   148,
     149,   150,    -1,    -1,    -1,    -1,   155,   156,   157,   158,
     159,   160,   161,   162,   163,    -1,   165,   166,    -1,    -1,
     169,   170,   171,    -1,    -1,    -1,   175,    -1,   177,   178,
     179,    -1,   181,   182,   183,    -1,   185,    -1,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,    -1,
      -1,   200,   201,   202,    -1,   204,   205,    -1,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,    -1,
     249,   250,   251,    -1,   253,   254,   255,   256,   257,   258,
      -1,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,
      20,    -1,    -1,    -1,    -1,    25,    26,    -1,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    -1,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    -1,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    -1,    -1,    97,    98,    -1,
      -1,    -1,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,    -1,   114,    -1,   116,   117,   118,   119,
      -1,   121,    -1,    -1,    -1,   125,   126,   127,   128,   129,
      -1,    -1,    -1,    -1,    -1,    -1,   136,   137,   138,   139,
     140,   141,   142,    -1,    -1,    -1,   146,   147,   148,   149,
     150,    -1,    -1,    -1,    -1,   155,   156,   157,   158,   159,
     160,   161,   162,   163,    -1,   165,   166,    -1,    -1,   169,
     170,   171,    -1,    -1,    -1,   175,    -1,   177,   178,   179,
      -1,   181,   182,   183,    -1,   185,    -1,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,    -1,    -1,
     200,   201,   202,    -1,   204,   205,    -1,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,    -1,   249,
     250,   251,    -1,   253,   254,   255,   256,   257,   258,    -1,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,
      -1,    -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    -1,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    -1,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    -1,    -1,    97,    98,    -1,    -1,
      -1,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,    -1,   114,    -1,   116,   117,   118,   119,    -1,
     121,    -1,    -1,    -1,   125,   126,   127,   128,   129,    -1,
      -1,    -1,    -1,    -1,    -1,   136,   137,   138,   139,   140,
     141,   142,    -1,    -1,    -1,   146,   147,   148,   149,   150,
      -1,    -1,    -1,    -1,   155,   156,   157,   158,   159,   160,
     161,   162,   163,    -1,   165,   166,    -1,    -1,   169,   170,
     171,    -1,    -1,    -1,   175,    -1,   177,   178,   179,    -1,
     181,   182,   183,    -1,   185,    -1,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,    -1,    -1,   200,
     201,   202,    -1,   204,   205,    -1,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    -1,   249,   250,
     251,    -1,   253,   254,   255,   256,   257,   258,    -1,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,
      -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    -1,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    -1,    -1,    97,    98,    -1,    -1,    -1,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,    -1,   114,    -1,   116,   117,   118,   119,    -1,   121,
      -1,    -1,    -1,   125,   126,   127,   128,   129,    -1,    -1,
      -1,    -1,    -1,    -1,   136,   137,   138,   139,   140,   141,
     142,    -1,    -1,    -1,   146,   147,   148,   149,   150,    -1,
      -1,    -1,    -1,   155,   156,   157,   158,   159,   160,   161,
     162,   163,    -1,   165,   166,    -1,    -1,   169,   170,   171,
      -1,    -1,    -1,   175,    -1,   177,   178,   179,    -1,   181,
     182,   183,    -1,   185,    -1,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,    -1,    -1,   200,   201,
     202,    -1,   204,   205,    -1,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,    -1,   249,   250,   251,
      -1,   253,   254,   255,   256,   257,   258,    -1,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,
      -1,    -1,    25,    26,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    -1,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,    -1,    97,    98,    -1,    -1,    -1,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
      -1,   114,    -1,   116,   117,   118,   119,    -1,   121,    -1,
      -1,    -1,   125,   126,   127,   128,   129,    -1,    -1,    -1,
      -1,    -1,    -1,   136,   137,   138,   139,   140,   141,   142,
      -1,    -1,    -1,   146,   147,   148,   149,   150,    -1,    -1,
      -1,    -1,   155,   156,   157,   158,   159,   160,   161,   162,
     163,    -1,   165,   166,    -1,    -1,   169,   170,   171,    -1,
      -1,    -1,   175,    -1,   177,   178,   179,    -1,   181,   182,
     183,    -1,   185,    -1,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,    -1,    -1,   200,   201,   202,
      -1,   204,   205,    -1,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,    -1,   249,   250,   251,    -1,
     253,   254,   255,   256,   257,   258,    -1,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,
      -1,    25,    26,    -1,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    -1,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    -1,    97,    98,    -1,    -1,    -1,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,    -1,
     114,    -1,   116,   117,   118,   119,    -1,   121,    -1,    -1,
      -1,   125,   126,   127,   128,   129,    -1,    -1,    -1,    -1,
      -1,    -1,   136,   137,   138,   139,   140,   141,   142,    -1,
      -1,    -1,   146,   147,    -1,   149,   150,    -1,    -1,    -1,
      -1,   155,   156,   157,   158,   159,   160,   161,   162,   163,
      -1,    -1,    -1,    -1,    -1,   169,   170,   171,    -1,    -1,
      -1,   175,    -1,   177,   178,   179,    -1,   181,   182,   183,
      -1,   185,    -1,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,    -1,    -1,   200,   201,   202,    -1,
     204,   205,    -1,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,    -1,   249,   250,   251,    -1,   253,
     254,   255,   256,   257,   258,    -1,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    -1,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      -1,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    -1,    97,    98,    -1,    -1,    -1,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,    -1,   114,
      -1,   116,   117,   118,   119,    -1,   121,    -1,    -1,    -1,
     125,   126,   127,   128,   129,    -1,    -1,    -1,    -1,    -1,
      -1,   136,   137,   138,   139,   140,   141,   142,    -1,    -1,
      -1,   146,   147,    -1,   149,   150,    -1,    -1,    -1,    -1,
     155,   156,   157,   158,   159,   160,   161,   162,   163,    -1,
      -1,    -1,    -1,    -1,   169,   170,   171,    -1,    -1,    -1,
     175,    -1,   177,   178,   179,    -1,    -1,    -1,   183,    -1,
     185,    -1,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,    -1,    -1,   200,   201,   202,    -1,   204,
     205,    -1,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,    -1,   249,   250,   251,    -1,   253,   254,
     255,   256,   257,   258,    -1,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    -1,    -1,    -1,    -1,    -1,    -1,    25,
      26,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    -1,    -1,    84,    -1,
      86,    87,    88,    89,    -1,    -1,    92,    93,    94,    -1,
      -1,    -1,    98,    -1,    -1,    -1,    -1,   103,   104,   105,
      -1,    -1,   108,   109,    -1,    -1,    -1,    -1,    -1,    -1,
     116,   117,   118,   119,    -1,   121,    -1,    -1,    -1,   125,
     126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     136,   137,   138,    -1,   140,   141,   142,    -1,    -1,    -1,
      -1,    -1,    -1,   149,   150,    -1,    -1,    -1,    -1,   155,
     156,   157,   158,   159,   160,   161,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   171,    -1,    -1,    -1,   175,
      -1,   177,   178,    -1,    -1,    -1,    -1,   183,    -1,   185,
      -1,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,    -1,    -1,   200,   201,    -1,    -1,   204,   205,
      -1,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,    -1,   249,   250,   251,    -1,   253,   254,   255,
     256,   257,   258,    -1,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    -1,    -1,    84,    -1,    86,
      87,    88,    89,    -1,    -1,    92,    93,    94,    -1,    -1,
      -1,    98,    -1,    -1,    -1,    -1,   103,   104,   105,    -1,
      -1,   108,   109,    -1,    -1,    -1,    -1,    -1,    -1,   116,
     117,   118,   119,    -1,   121,    -1,    -1,    -1,   125,   126,
     127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,
     137,   138,    -1,   140,   141,   142,    -1,    -1,    -1,    -1,
      -1,    -1,   149,   150,    -1,    -1,    -1,    -1,   155,   156,
     157,   158,   159,   160,   161,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   171,    -1,    -1,    -1,   175,    -1,
     177,    -1,    -1,    -1,    -1,    -1,   183,    -1,   185,    -1,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,    -1,    -1,   200,   201,    -1,    -1,   204,   205,    -1,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,    -1,   249,   250,   251,    -1,   253,   254,   255,   256,
     257,   258,    -1,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,    14,    -1,    -1,    -1,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      -1,    -1,    84,    -1,    86,    87,    88,    89,    -1,    -1,
      92,    93,    94,    -1,    -1,    -1,    98,    -1,    -1,    -1,
      -1,   103,   104,   105,    -1,    -1,   108,   109,    -1,    -1,
      -1,    -1,    -1,    -1,   116,   117,   118,   119,    -1,   121,
      -1,    -1,    -1,   125,   126,   127,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   136,   137,   138,    -1,   140,   141,
     142,   143,    -1,    -1,   146,    -1,    -1,   149,   150,    -1,
      -1,    -1,    -1,   155,   156,   157,   158,   159,   160,   161,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   171,
      -1,    -1,    -1,   175,    -1,   177,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   185,    -1,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,    -1,    -1,   200,   201,
      -1,    -1,   204,   205,    -1,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,    -1,   249,   250,   251,
      -1,   253,   254,   255,   256,   257,   258,    -1,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,    14,    -1,    -1,
      -1,    18,    -1,    20,    -1,    -1,    -1,    -1,    25,    26,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    -1,    -1,    84,    -1,    86,
      87,    88,    89,    -1,    -1,    92,    93,    94,    -1,    -1,
      -1,    98,    -1,    -1,    -1,    -1,   103,   104,   105,    -1,
      -1,   108,   109,    -1,    -1,    -1,    -1,    -1,    -1,   116,
     117,   118,   119,    -1,   121,    -1,    -1,    -1,   125,   126,
     127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,
     137,   138,    -1,   140,   141,   142,    -1,    -1,    -1,    -1,
      -1,    -1,   149,   150,    -1,    -1,    -1,    -1,   155,   156,
     157,   158,   159,   160,   161,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   171,    -1,    -1,    -1,   175,   176,
     177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   185,    -1,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,    -1,    -1,   200,   201,    -1,    -1,   204,   205,    -1,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,    -1,   249,   250,   251,    -1,   253,   254,   255,   256,
     257,   258,    -1,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,    14,    -1,    -1,    -1,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      -1,    -1,    84,    -1,    86,    87,    88,    89,    -1,    -1,
      92,    93,    94,    -1,    -1,    -1,    98,    -1,    -1,    -1,
      -1,   103,   104,   105,    -1,    -1,   108,   109,    -1,    -1,
      -1,    -1,    -1,    -1,   116,   117,   118,   119,    -1,   121,
      -1,    -1,    -1,   125,   126,   127,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   136,   137,   138,    -1,   140,   141,
     142,    -1,    -1,    -1,    -1,    -1,    -1,   149,   150,    -1,
      -1,    -1,    -1,   155,   156,   157,   158,   159,   160,   161,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   171,
      -1,    -1,    -1,   175,    -1,   177,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   185,    -1,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,    -1,    -1,   200,   201,
      -1,    -1,   204,   205,    -1,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,    -1,   249,   250,   251,
      -1,   253,   254,   255,   256,   257,   258,    -1,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,    16,    -1,    18,
      -1,    -1,    -1,    -1,    -1,    -1,    25,    26,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    -1,    -1,    84,    -1,    86,    87,    88,
      89,    -1,    -1,    92,    93,    94,    -1,    -1,    -1,    98,
      -1,    -1,    -1,    -1,   103,   104,   105,    -1,    -1,   108,
     109,    -1,    -1,    -1,    -1,    -1,    -1,   116,   117,   118,
     119,    -1,   121,    -1,    -1,    -1,   125,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,   137,   138,
      -1,   140,   141,   142,    -1,    -1,    -1,    -1,    -1,    -1,
     149,   150,    -1,    -1,    -1,    -1,   155,   156,   157,   158,
     159,   160,   161,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   171,    -1,    -1,    -1,   175,    -1,   177,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   185,    -1,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,    -1,
      -1,   200,   201,    -1,    -1,   204,   205,    -1,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,    -1,
     249,   250,   251,    -1,   253,   254,   255,   256,   257,   258,
      -1,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
      18,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    -1,    -1,    84,    -1,    86,    87,
      88,    89,    -1,    -1,    92,    93,    94,    -1,    -1,    -1,
      98,    -1,    -1,    -1,    -1,   103,   104,   105,    -1,    -1,
     108,   109,    -1,    -1,    -1,    -1,    -1,    -1,   116,   117,
     118,   119,    -1,   121,    -1,    -1,    -1,   125,   126,   127,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,   137,
     138,    -1,   140,   141,   142,    -1,    -1,    -1,   146,    -1,
      -1,   149,   150,    -1,    -1,    -1,    -1,   155,   156,   157,
     158,   159,   160,   161,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   171,    -1,    -1,    -1,   175,   176,   177,
     178,    -1,    -1,    -1,    -1,   183,    -1,   185,    -1,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
      -1,    -1,   200,   201,    -1,    -1,   204,   205,    -1,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
      -1,   249,   250,   251,    -1,   253,   254,   255,   256,   257,
     258,    -1,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,    18,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    -1,    -1,    84,    -1,    86,
      87,    88,    89,    -1,    -1,    92,    93,    94,    -1,    -1,
      -1,    98,    -1,    -1,    -1,    -1,   103,   104,   105,    -1,
      -1,   108,   109,   110,    -1,    -1,    -1,    -1,    -1,   116,
     117,   118,   119,    -1,   121,    -1,    -1,    -1,   125,   126,
     127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,
     137,   138,    -1,   140,   141,   142,    -1,    -1,    -1,   146,
      -1,    -1,   149,   150,    -1,    -1,    -1,    -1,   155,   156,
     157,   158,   159,   160,   161,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   171,    -1,    -1,    -1,   175,    -1,
     177,   178,    -1,    -1,    -1,    -1,    -1,    -1,   185,    -1,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,    -1,    -1,   200,   201,    -1,    -1,   204,   205,    -1,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,    -1,   249,   250,   251,    -1,   253,   254,   255,   256,
     257,   258,    -1,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,    18,    -1,    -1,    -1,    -1,    -1,    -1,    25,
      26,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    -1,    -1,    84,    -1,
      86,    87,    88,    89,    -1,    -1,    92,    93,    94,    -1,
      -1,    -1,    98,    -1,    -1,    -1,    -1,   103,   104,   105,
      -1,    -1,   108,   109,    -1,    -1,    -1,    -1,    -1,    -1,
     116,   117,   118,   119,    -1,   121,    -1,    -1,    -1,   125,
     126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     136,   137,   138,    -1,   140,   141,   142,   143,    -1,    -1,
     146,    -1,    -1,   149,   150,    -1,    -1,    -1,    -1,   155,
     156,   157,   158,   159,   160,   161,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   171,    -1,    -1,    -1,   175,
      -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   185,
      -1,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,    -1,    -1,   200,   201,    -1,    -1,   204,   205,
      -1,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,    -1,   249,   250,   251,    -1,   253,   254,   255,
     256,   257,   258,    -1,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    -1,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    -1,    -1,    84,
      -1,    86,    87,    88,    89,    -1,    -1,    92,    93,    94,
      -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,   103,   104,
     105,    -1,    -1,   108,   109,    -1,    -1,    -1,    -1,    -1,
      -1,   116,   117,   118,   119,    -1,   121,    -1,    -1,    -1,
     125,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   136,   137,   138,    -1,   140,   141,   142,   143,    -1,
      -1,   146,    -1,    -1,   149,   150,    -1,    -1,    -1,    -1,
     155,   156,   157,   158,   159,   160,   161,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   171,    -1,    -1,    -1,
     175,    -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     185,    -1,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,    -1,    -1,   200,   201,    -1,    -1,   204,
     205,    -1,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,    -1,   249,   250,   251,    -1,   253,   254,
     255,   256,   257,   258,    -1,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,    18,    -1,    -1,    -1,    -1,    -1,
      -1,    25,    26,    -1,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    -1,    -1,
      84,    -1,    86,    87,    88,    89,    -1,    -1,    92,    93,
      94,    -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,   103,
     104,   105,    -1,    -1,   108,   109,    -1,    -1,    -1,    -1,
      -1,    -1,   116,   117,   118,   119,    -1,   121,    -1,    -1,
      -1,   125,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   136,   137,   138,    -1,   140,   141,   142,    -1,
      -1,    -1,    -1,    -1,    -1,   149,   150,    -1,    -1,    -1,
      -1,   155,   156,   157,   158,   159,   160,   161,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   171,    -1,    -1,
      -1,   175,   176,   177,    -1,    -1,    -1,    -1,    -1,   183,
      -1,   185,    -1,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,    -1,    -1,   200,   201,    -1,    -1,
     204,   205,    -1,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,    -1,   249,   250,   251,    -1,   253,
     254,   255,   256,   257,   258,    -1,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    25,    26,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    -1,
      -1,    84,    -1,    86,    87,    88,    89,    -1,    -1,    92,
      93,    94,    -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,
     103,   104,   105,    -1,    -1,   108,   109,    -1,    -1,    -1,
      -1,    -1,    -1,   116,   117,   118,   119,    -1,   121,    -1,
      -1,    -1,   125,   126,   127,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   136,   137,   138,    -1,   140,   141,   142,
      -1,    -1,    -1,    -1,    -1,    -1,   149,   150,    -1,    -1,
      -1,    -1,   155,   156,   157,   158,   159,   160,   161,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   171,    -1,
      -1,    -1,   175,   176,   177,    -1,    -1,    -1,    -1,    -1,
     183,    -1,   185,    -1,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,    -1,    -1,   200,   201,    -1,
      -1,   204,   205,    -1,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,    -1,   249,   250,   251,    -1,
     253,   254,   255,   256,   257,   258,    -1,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      -1,    -1,    84,    -1,    86,    87,    88,    89,    -1,    -1,
      92,    93,    94,    -1,    -1,    -1,    98,    -1,    -1,    -1,
      -1,   103,   104,   105,    -1,    -1,   108,   109,    -1,    -1,
      -1,    -1,    -1,    -1,   116,   117,   118,   119,    -1,   121,
      -1,    -1,    -1,   125,   126,   127,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   136,   137,   138,    -1,   140,   141,
     142,    -1,    -1,    -1,   146,    -1,    -1,   149,   150,    -1,
      -1,    -1,    -1,   155,   156,   157,   158,   159,   160,   161,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   171,
      -1,    -1,    -1,   175,    -1,   177,   178,    -1,    -1,    -1,
      -1,    -1,    -1,   185,    -1,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,    -1,    -1,   200,   201,
      -1,    -1,   204,   205,    -1,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,    -1,   249,   250,   251,
      -1,   253,   254,   255,   256,   257,   258,    -1,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    -1,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    -1,    -1,    84,    -1,    86,    87,    88,    89,    -1,
      -1,    92,    93,    94,    -1,    -1,    -1,    98,    -1,    -1,
      -1,    -1,   103,   104,   105,    -1,    -1,   108,   109,    -1,
      -1,    -1,    -1,    -1,    -1,   116,   117,   118,   119,    -1,
     121,    -1,    -1,    -1,   125,   126,   127,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   136,   137,   138,    -1,   140,
     141,   142,    -1,    -1,    -1,   146,    -1,    -1,   149,   150,
      -1,    -1,    -1,    -1,   155,   156,   157,   158,   159,   160,
     161,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     171,    -1,    -1,    -1,   175,    -1,   177,   178,    -1,    -1,
      -1,    -1,    -1,    -1,   185,    -1,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,    -1,    -1,   200,
     201,    -1,    -1,   204,   205,    -1,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    -1,   249,   250,
     251,    -1,   253,   254,   255,   256,   257,   258,    -1,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,    18,    -1,
      -1,    -1,    -1,    -1,    -1,    25,    26,    -1,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    -1,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    -1,    -1,    84,    -1,    86,    87,    88,    89,
      -1,    -1,    92,    93,    94,    -1,    -1,    -1,    98,    -1,
      -1,    -1,    -1,   103,   104,   105,    -1,    -1,   108,   109,
      -1,    -1,    -1,    -1,    -1,    -1,   116,   117,   118,   119,
      -1,   121,    -1,    -1,    -1,   125,   126,   127,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   136,   137,   138,    -1,
     140,   141,   142,    -1,    -1,    -1,    -1,    -1,    -1,   149,
     150,    -1,    -1,    -1,    -1,   155,   156,   157,   158,   159,
     160,   161,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   171,    -1,    -1,    -1,   175,    -1,   177,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   185,    -1,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,    -1,    -1,
     200,   201,    -1,    -1,   204,   205,    -1,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,    -1,   249,
     250,   251,    -1,   253,   254,   255,   256,   257,   258,    -1,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  xquery_parser::yystos_[] =
  {
         0,    10,    17,    18,    20,    25,    26,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    97,    98,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   114,   116,   117,   118,   119,
     121,   125,   126,   127,   128,   129,   136,   137,   138,   139,
     140,   141,   142,   146,   147,   148,   149,   150,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   165,   166,   169,
     170,   171,   175,   177,   178,   179,   181,   182,   183,   185,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   200,   201,   202,   204,   205,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   249,   250,   251,
     253,   254,   255,   256,   257,   258,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   339,   340,   341,
     342,   345,   346,   351,   354,   357,   360,   361,   363,   368,
     369,   370,   371,   372,   381,   382,   384,   385,   386,   391,
     393,   395,   396,   397,   402,   423,   426,   429,   430,   431,
     432,   434,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   480,   481,   482,   496,   497,   499,   500,   501,   502,
     503,   504,   505,   513,   514,   515,   516,   517,   518,   519,
     520,   521,   522,   525,   526,   527,   528,   533,   534,   535,
     536,   537,   538,   541,   547,   548,   549,    34,    35,    36,
      37,    38,    39,    46,    52,    63,    64,    67,    70,    71,
     103,   104,   105,   150,   159,   191,   210,   220,   251,   277,
     278,   279,   280,   281,   283,   284,   285,   286,   287,   292,
     352,   353,   373,   374,   150,    86,   143,   211,   212,   146,
      25,    26,    28,    29,    30,    31,    32,    33,    34,    40,
      41,    42,    44,    50,    51,    53,    54,    55,    65,    66,
      89,   125,   143,   146,   159,   191,   204,   214,   215,   216,
     218,   219,   226,   228,   229,   230,   231,   234,   235,   237,
     547,   143,   143,   146,   143,   146,   146,   362,   146,    26,
      48,    14,   143,   146,   546,   547,   110,   110,   110,   143,
      56,    57,   110,   388,    54,   146,   146,   143,   146,   547,
      30,    32,    33,    42,    89,   464,   547,   547,   110,   176,
     382,   547,   143,   546,    16,   547,   547,   456,   143,    21,
     203,   205,   215,   217,   146,   215,   217,   215,   215,   220,
     110,   143,   364,   232,   232,   233,   146,   143,   110,   316,
       0,   318,   319,    25,    41,   321,   381,   180,   180,    99,
     180,   383,    45,    51,    54,    55,    62,   158,   161,   175,
     201,   387,   392,   393,   394,   411,   412,   416,   398,   399,
     547,   157,    84,   122,   130,   131,   133,   141,   145,   147,
     152,   168,   192,   193,   194,   195,   196,   197,   448,   449,
     249,   148,   165,   188,   109,   136,   149,   183,   190,   199,
     126,   140,    68,   189,    93,    94,   148,   165,   447,   143,
     453,   456,   181,   182,   144,   468,   469,   464,   468,   464,
     146,   468,   135,   146,   547,    34,   376,    34,   375,   373,
     373,   374,   547,   171,   185,   159,   191,    20,   545,   156,
     171,   171,   185,   547,   142,   110,   350,    30,    34,    71,
      98,   158,   546,   211,   212,   213,   290,   291,    46,    92,
     227,   241,   254,   256,   271,   275,   575,   576,   577,   578,
     579,   580,   581,   588,   594,   595,   547,   283,   547,   288,
     288,   293,   277,   285,   353,   546,   523,   547,   382,   143,
     143,   382,   382,   176,   183,   547,   143,   382,   382,   176,
     382,   176,   110,   176,   377,   378,   143,   379,   382,   150,
     545,   105,   150,   344,   545,   382,    20,   176,   546,   143,
     424,   425,   547,   547,   403,   405,   547,   385,   274,   274,
     110,   406,   110,   547,    30,    65,   176,   521,   522,   382,
     176,   183,   547,   143,   424,   176,    27,   484,   485,   486,
     382,     7,   164,    15,   176,   382,   203,    20,   385,   385,
     176,   385,   385,   385,   385,   221,   539,   540,   547,   365,
     385,   385,   382,   404,   410,   547,   323,   324,    25,   325,
     385,   384,   158,   110,   160,   160,   385,   385,    99,    86,
      88,   137,   263,   400,   401,   507,   431,   432,   434,   434,
     434,   434,   433,   434,   434,   434,   143,   146,   250,   452,
     471,   550,   553,   554,   555,   556,   557,   561,   563,   564,
     565,   438,   438,   437,   439,   439,   439,   439,   440,   440,
     441,   441,   221,    86,    86,    86,   173,   382,   456,   456,
     382,   469,   176,   385,   479,   139,   176,   479,   362,   547,
     547,    20,    99,    99,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,   327,   328,   329,    86,   127,   132,
     347,   348,   349,   547,   127,   132,   150,   150,   327,   545,
     117,   122,   547,   253,   264,   105,   267,   268,   269,   273,
     253,   264,    20,   267,   268,   269,   273,   576,    86,   227,
     356,   289,   547,   547,   547,   122,   143,   173,   382,   382,
     176,   173,    99,   176,    99,   176,   173,   382,   173,   173,
     173,   547,    86,    99,   176,   382,   176,   546,    88,    30,
     546,   545,    88,   173,   176,   176,   173,   382,    99,   177,
     137,   507,   132,    99,   132,   401,   507,   173,   547,    60,
     207,   244,   389,   390,   176,   176,   176,   173,    99,   176,
      99,   176,   173,   382,   177,   547,   485,   486,   120,   186,
     173,   173,   121,   180,    86,   208,   209,   223,    86,   208,
     209,   223,    86,   227,   215,    99,   225,   132,    25,   366,
     382,   176,   173,    53,    99,   180,   105,   180,   160,   547,
     385,   417,   418,   110,   413,   414,   110,    34,   142,   146,
     200,   508,   510,   512,   513,   529,   530,   531,   532,   547,
     110,   385,   110,   137,   401,   137,   137,   400,   401,   434,
     382,   550,   557,   275,   435,   601,    88,   159,   242,   243,
     245,   252,   262,   274,   551,   552,   570,   571,   572,   573,
     596,   599,   248,   250,   558,   575,   257,   562,   597,   238,
     239,   260,   566,   567,   508,   508,   506,   512,   506,   173,
     174,    99,   176,   176,   127,   143,   380,   362,   362,   138,
     155,   138,   155,   328,   122,   510,   349,   385,   507,   132,
     385,   545,   545,   118,   119,   545,    20,   268,   276,    88,
     105,   146,   582,   585,   276,    32,    33,    42,    66,    89,
     215,   355,   513,   281,   282,   217,   289,   297,    86,   356,
     289,   545,   382,   173,   173,    92,   427,   428,   143,   523,
     524,   547,   523,   524,   173,   507,   508,   378,    86,   173,
     187,   122,   343,   545,   150,   122,    88,   343,   143,   173,
     110,   385,   385,   137,   385,   110,   385,   132,   132,   401,
     137,   507,   244,    58,    59,    61,   110,   400,   407,   408,
     409,   390,   143,   523,   523,   173,   385,    27,   486,   120,
     186,     8,     9,    95,   113,   115,   184,   379,   481,   483,
     494,   495,   498,    20,   222,   224,   385,   385,   385,   222,
     224,   385,   385,   385,   385,   385,   385,   110,   385,   385,
     350,   367,    99,   180,   173,   364,   236,   542,   543,   143,
     110,   417,    87,    98,   108,   117,   419,   420,   421,   422,
      99,   547,    99,   399,   146,   146,   510,   146,   134,   165,
     183,   509,   547,   547,   385,   137,   385,   385,   137,   401,
     137,   173,   176,   240,   207,   244,   258,   265,   600,    88,
     246,   247,   598,   240,   554,   600,   437,   570,   555,   137,
     272,   559,   560,   598,   276,   569,    47,   568,   134,   385,
     382,   127,   143,   127,   364,   525,   348,   385,   276,    88,
     146,   589,    20,   582,   356,   509,   217,   217,   454,   277,
     295,   355,   217,   180,   173,   110,   508,   105,   428,   173,
     382,   176,   176,   134,   176,   176,   508,   385,   545,    99,
     343,   173,   382,   425,   385,   405,   385,   385,   132,   385,
     137,   110,   110,   385,   547,   409,    61,   173,   382,   176,
     176,   122,   184,   483,     6,   547,   184,   494,   180,   223,
     223,   223,   223,   227,   540,   175,   132,   367,   465,   544,
     543,   385,   410,   545,   118,   119,   421,   422,   422,   418,
      98,   415,   414,   176,   183,   508,   511,   176,   176,   176,
     385,   385,   137,   385,   439,    43,   119,   437,   437,   259,
     266,   276,   574,   574,   556,   436,   270,   173,   384,   126,
     190,   591,   592,   593,    20,    20,   590,   591,   261,   586,
     583,   584,   585,   160,   547,   247,   356,   454,   547,   175,
     110,   175,   173,   116,    88,   545,   173,   385,   385,   547,
     547,   408,   385,   173,   486,   547,   184,   486,   547,   385,
     385,   385,   385,   385,   385,   385,   146,   199,   380,   173,
     422,   545,    86,   176,    99,   176,   385,   437,   437,   188,
     173,   589,   589,   593,    99,   176,    20,   587,   598,   176,
      99,   358,   359,   454,   110,   215,   296,   277,   160,    86,
     385,   547,   385,   385,   343,    59,    85,   172,   487,   486,
     547,   186,   486,   110,   465,   508,   508,    86,   437,    20,
     255,   585,    99,    86,   547,   110,   215,   547,   358,   508,
     175,   110,     4,   123,   490,   491,   493,   495,    19,   124,
     488,   489,   492,   495,   186,   486,   186,   547,   508,   359,
     512,   294,   547,   110,   215,   175,   385,   547,    85,   123,
     493,   172,   124,   492,   186,    99,   176,   422,   385,   294,
     547,   110,   385,   110,   380,   283,   294,   547,   547,   295,
     385,   295,    99,   176,   454,   454,   110,   380,   188,   547,
     277,   176,   547,   380,   215,   110,   547,   295,   454
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
     565,   566,   567,   568
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   314,   315,   315,   316,   316,   316,   316,   317,   317,
     318,   318,   319,   319,   320,   321,   321,   321,   322,   322,
     323,   323,   324,   324,   324,   324,   325,   325,   325,   325,
     325,   325,   325,   325,   325,   326,   326,   327,   327,   328,
     329,   329,   329,   329,   329,   329,   329,   329,   329,   329,
     330,   330,   330,   330,   330,   330,   330,   330,   331,   331,
     332,   333,   333,   334,   334,   335,   336,   337,   337,   338,
     338,   339,   339,   339,   339,   340,   341,   342,   342,   342,
     342,   343,   343,   344,   344,   345,   345,   345,   345,   346,
     347,   347,   348,   348,   348,   349,   350,   350,   351,   351,
     351,   352,   352,   353,   353,   353,   353,   353,   353,   353,
     353,   353,   353,   353,   353,   354,   354,   354,   354,   354,
     354,   354,   354,   355,   355,   356,   356,   357,   357,   358,
     358,   359,   359,   360,   360,   360,   360,   361,   361,   362,
     362,   362,   362,   363,   364,   365,   365,   366,   366,   367,
     367,   368,   369,   370,   371,   371,   372,   372,   372,   373,
     373,   373,   373,   374,   374,   375,   375,   376,   376,   377,
     377,   378,   378,   379,   380,   381,   382,   382,   383,   383,
     384,   384,   385,   385,   385,   385,   385,   385,   385,   385,
     385,   385,   385,   385,   385,   385,   385,   385,   385,   386,
     387,   388,   388,   389,   389,   389,   390,   390,   391,   391,
     392,   393,   393,   393,   394,   394,   394,   394,   394,   395,
     395,   396,   396,   397,   398,   398,   399,   399,   399,   399,
     399,   399,   399,   399,   400,   401,   402,   403,   403,   404,
     404,   405,   405,   405,   405,   406,   406,   407,   407,   407,
     408,   408,   408,   409,   409,   409,   410,   411,   412,   413,
     413,   414,   414,   415,   416,   416,   417,   417,   418,   418,
     419,   419,   419,   419,   419,   419,   419,   420,   420,   421,
     421,   422,   423,   423,   424,   424,   425,   425,   426,   426,
     427,   427,   428,   428,   429,   430,   430,   431,   431,   432,
     432,   432,   432,   432,   433,   432,   432,   432,   432,   434,
     434,   435,   435,   436,   436,   437,   437,   437,   438,   438,
     438,   438,   438,   439,   439,   439,   440,   440,   440,   441,
     441,   442,   442,   443,   443,   444,   444,   445,   445,   446,
     446,   446,   446,   447,   447,   447,   448,   448,   448,   448,
     448,   448,   449,   449,   449,   450,   450,   450,   450,   451,
     451,   452,   452,   453,   453,   454,   454,   454,   454,   455,
     456,   456,   456,   457,   457,   458,   458,   458,   458,   459,
     459,   460,   460,   460,   460,   460,   460,   460,   461,   461,
     462,   462,   463,   463,   463,   463,   463,   464,   464,   465,
     465,   466,   466,   466,   467,   467,   467,   467,   468,   468,
     469,   470,   470,   470,   470,   470,   470,   470,   470,   470,
     471,   471,   472,   472,   472,   473,   474,   474,   475,   476,
     477,   478,   478,   479,   479,   480,   480,   481,   481,   481,
     482,   482,   482,   482,   482,   482,   483,   483,   484,   484,
     485,   486,   486,   487,   487,   488,   488,   489,   489,   489,
     489,   490,   490,   491,   491,   491,   491,   492,   492,   493,
     493,   494,   494,   494,   494,   495,   495,   495,   495,   496,
     496,   497,   497,   498,   499,   499,   499,   499,   499,   499,
     500,   501,   501,   501,   501,   502,   502,   502,   502,   503,
     504,   505,   505,   505,   505,   506,   506,   507,   508,   508,
     508,   509,   509,   509,   510,   510,   510,   510,   510,   511,
     511,   512,   513,   513,   513,   513,   513,   513,   513,   513,
     513,   514,   515,   515,   515,   516,   517,   518,   518,   518,
     519,   519,   519,   519,   519,   520,   521,   521,   521,   521,
     521,   521,   521,   522,   523,   524,   525,   526,   526,   527,
     528,   529,   529,   530,   531,   531,   532,   533,   533,   533,
     534,   534,   534,   534,   534,   534,   534,   534,   534,   534,
     535,   535,   536,   536,   537,   538,   539,   539,   540,   541,
     542,   542,   543,   543,   543,   543,   544,   544,   545,   546,
     546,   547,   547,   548,   548,   549,   549,   549,   549,   549,
     549,   549,   549,   549,   549,   549,   549,   549,   549,   549,
     549,   549,   549,   549,   549,   549,   549,   549,   549,   549,
     549,   549,   549,   549,   549,   549,   549,   549,   549,   549,
     549,   549,   549,   549,   549,   549,   549,   549,   549,   549,
     549,   549,   549,   549,   549,   549,   549,   549,   549,   549,
     549,   549,   549,   549,   549,   549,   549,   549,   549,   549,
     549,   549,   549,   549,   549,   549,   549,   549,   549,   549,
     549,   549,   549,   549,   549,   549,   549,   549,   549,   549,
     549,   549,   549,   549,   549,   549,   549,   549,   549,   549,
     549,   549,   549,   549,   549,   549,   549,   549,   549,   549,
     549,   549,   549,   549,   549,   549,   549,   549,   549,   549,
     549,   549,   549,   549,   549,   549,   549,   549,   549,   549,
     549,   549,   549,   549,   549,   549,   549,   549,   549,   549,
     549,   549,   549,   549,   549,   549,   549,   549,   549,   549,
     549,   549,   549,   549,   549,   549,   549,   549,   549,   549,
     549,   549,   549,   549,   549,   549,   549,   549,   549,   549,
     549,   549,   549,   549,   549,   549,   549,   549,   549,   549,
     549,   549,   549,   549,   549,   549,   549,   549,   549,   549,
     549,   549,   549,   549,   549,   549,   549,   549,   549,   549,
     549,   549,   549,   549,   549,   550,   551,   551,   552,   552,
     553,   553,   554,   554,   555,   555,   556,   556,   557,   558,
     558,   559,   559,   560,   561,   561,   561,   562,   562,   563,
     564,   565,   565,   566,   566,   567,   567,   567,   568,   568,
     569,   569,   570,   570,   570,   570,   570,   571,   572,   573,
     574,   574,   574,   575,   575,   576,   576,   576,   576,   576,
     576,   576,   576,   577,   577,   577,   577,   578,   578,   579,
     580,   580,   581,   581,   581,   582,   582,   583,   583,   584,
     584,   585,   586,   586,   587,   587,   588,   588,   588,   589,
     589,   590,   590,   591,   591,   592,   592,   593,   593,   594,
     595,   595,   596,   596,   596,   597,   598,   598,   598,   598,
     599,   599,   600,   600,   601
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
       2,     1,     2,     2,     2,     3,     4,     5,     6,     4,
       5,     6,     7,     1,     2,     3,     3,     8,     9,     1,
       3,     3,     4,    11,    14,    13,    22,     3,     3,     2,
       3,     4,     5,     2,     4,     3,     0,     3,     2,     1,
       3,     5,     3,     5,     2,     2,     2,     3,     3,     1,
       2,     2,     2,     4,     4,     4,     4,     6,     4,     1,
       3,     2,     3,     3,     3,     1,     1,     2,     1,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     2,     1,     1,     2,     4,     3,     5,     4,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     3,     2,     1,     4,     3,     4,     4,     5,
       4,     5,     5,     6,     3,     3,     3,     1,     4,     1,
       4,     3,     4,     4,     5,     4,     5,     1,     2,     3,
       1,     2,     1,     6,     3,     3,     1,     2,     3,     1,
       3,     2,     3,     2,     3,     4,     1,     3,     1,     2,
       1,     1,     1,     2,     2,     2,     3,     1,     1,     2,
       2,     2,     5,     5,     1,     4,     3,     4,     8,    10,
       1,     2,     4,     7,     8,     1,     3,     1,     3,     1,
       3,     3,     3,     3,     0,     4,     3,     3,     3,     1,
       4,     0,     1,     1,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     1,
       4,     1,     4,     1,     4,     1,     4,     1,     2,     1,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     5,     5,     6,     3,
       4,     1,     2,     3,     2,     1,     2,     2,     1,     1,
       1,     3,     3,     1,     1,     1,     2,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     3,     4,     1,     2,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     3,     1,     4,
       4,     3,     4,     1,     3,     1,     1,     1,     1,     1,
       4,     5,     8,     9,     9,    10,     1,     2,     1,     2,
       6,     0,     1,     3,     3,     0,     1,     1,     1,     2,
       2,     0,     1,     1,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       2,     3,     3,     2,     1,     1,     1,     1,     1,     1,
       4,     4,     5,     6,     7,     4,     5,     6,     7,     4,
       4,     4,     5,     6,     7,     1,     2,     2,     1,     2,
       3,     1,     1,     1,     1,     1,     3,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     4,     4,     3,     3,     3,     4,     4,
       3,     4,     6,     4,     6,     3,     3,     4,     6,     6,
       4,     6,     6,     4,     1,     2,     1,     1,     1,     3,
       3,     1,     1,     4,     5,     6,     3,     3,     3,     3,
       5,     7,     7,     5,     5,     5,     7,     7,     5,     5,
       3,     3,     5,     7,     5,     7,     1,     4,     3,     5,
       1,     2,     3,     7,    10,    13,     1,     3,     1,     1,
       1,     1,     1,     7,     4,     1,     1,     1,     1,     1,
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
       1,     1,     1,     1,     1,     2,     0,     1,     1,     2,
       1,     3,     1,     3,     1,     4,     1,     2,     3,     0,
       1,     0,     1,     2,     2,     3,     1,     0,     1,     1,
       2,     1,     3,     0,     1,     2,     2,     1,     0,     1,
       0,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       1,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     1,     1,     2,     2,     3,
       2,     2,     3,     6,     2,     1,     1,     0,     1,     1,
       3,     4,     0,     2,     0,     2,     5,     5,     3,     2,
       3,     1,     3,     0,     1,     1,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     3,     2,     3,     3,     4,
       2,     2,     1,     1,     3
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
  "\"'validate'\"", "\"'typeswitch'\"", "\"'element'\"", "\"'document'\"",
  "\"'text'\"", "\"'comment'\"", "\"'function'\"", "\"'updating'\"",
  "\"'sequential'\"", "\"'deterministic'\"", "\"'nondeterministic'\"",
  "\"'simple'\"", "\"'if'\"", "\"'import'\"",
  "\"'processing-instruction'\"", "\"'most'\"", "\"'some'\"",
  "\"'stable'\"", "\"'option'\"", "\"'word'\"", "\"'schema'\"",
  "\"'space'\"", "\"'set'\"", "\"'let'\"", "\"'construction'\"",
  "\"'eval'\"", "\"'for'\"", "\"'outer'\"", "\"'sliding'\"",
  "\"'tumbling'\"", "\"'previous'\"", "\"'next'\"", "\"'only'\"",
  "\"'when'\"", "\"'count'\"", "\"'ordering'\"", "\"'base-uri'\"",
  "\"'schema-element'\"", "\"'document-node'\"", "\"'copy-namespaces'\"",
  "\"'instance'\"", "\"'schema-attribute'\"", "\"'boundary-space'\"",
  "\"'decimal-format'\"", "\"'decimal-separator'\"",
  "\"'grouping-separator'\"", "\"'infinity'\"", "\"'minus-sign'\"",
  "\"'NaN'\"", "\"'percent'\"", "\"'per-mille'\"", "\"'zero-digit'\"",
  "\"'digit'\"", "\"'pattern-separator'\"", "\"'ancestor::'\"",
  "\"'ancestor-or-self::'\"", "\"'and'\"", "\"'''\"", "\"'as'\"",
  "\"'ascending'\"", "\"'at'\"", "\"'attribute'\"", "\"'attribute::'\"",
  "\"'@'\"", "\"'case'\"", "\"'castable'\"", "\"'cast'\"", "\"'CDATA[['\"",
  "\"']]'\"", "\"'child::'\"", "\"'collation'\"", "\"','\"", "\"'(:'\"",
  "\"':)'\"", "\"'DECIMAL'\"", "\"'context'\"", "\"'variable'\"",
  "\"'default'\"", "\"'descendant::'\"", "\"'descendant-or-self::'\"",
  "\"'descending'\"", "\"'div'\"", "\"'$'\"", "\"'.'\"", "\"'..'\"",
  "\"'{{'\"", "\"'DOUBLE'\"", "\"'<double {>'\"", "\"'else'\"",
  "\"'empty'\"", "\"'greatest'\"", "\"'least'\"", "\"'/>'\"",
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
  "\"'any'\"", "\"'content'\"", "\"'diacritics'\"", "\"'different'\"",
  "\"'distance'\"", "\"'end'\"", "\"'entire'\"", "\"'exactly'\"",
  "\"'from'\"", "\"'ftand'\"", "\"'ftcontains'\"", "\"'not'\"",
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
  "\"'equality'\"", "\"'integrity'\"", "\"'constraint'\"", "\"'check'\"",
  "\"'key'\"", "\"'foreach'\"", "\"'foreign'\"", "\"'keys'\"",
  "\"'BOM_UTF8'\"", "FTCONTAINS_REDUCE", "RANGE_REDUCE", "ADDITIVE_REDUCE",
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
  "FTPrimary", "opt_FTTimes", "FTExtensionSelection", "FTWords",
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
  "FTIgnoreOption", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const xquery_parser::rhs_number_type
  xquery_parser::yyrhs_[] =
  {
       315,     0,    -1,   316,    -1,   299,   316,    -1,   318,    -1,
     317,   318,    -1,   319,    -1,   317,   319,    -1,   204,   205,
      20,   180,    -1,   204,   205,    20,   121,    20,   180,    -1,
     321,   381,    -1,   381,    -1,   320,    -1,   320,   321,    -1,
      26,   150,   546,   122,   545,   180,    -1,   322,   180,    -1,
     323,   180,    -1,   322,   180,   323,   180,    -1,   324,    -1,
     322,   180,   324,    -1,   325,    -1,   323,   180,   325,    -1,
     330,    -1,   331,    -1,   332,    -1,   334,    -1,   351,    -1,
     354,    -1,   346,    -1,   326,    -1,   336,    -1,   372,    -1,
     357,    -1,   360,    -1,   335,    -1,    25,   105,    71,   327,
      -1,    25,    71,   547,   327,    -1,   328,    -1,   327,   328,
      -1,   329,   122,   525,    -1,    72,    -1,    80,    -1,    73,
      -1,    74,    -1,    75,    -1,    76,    -1,    81,    -1,    77,
      -1,    78,    -1,    79,    -1,   333,    -1,   340,    -1,   341,
      -1,   361,    -1,   337,    -1,   338,    -1,   339,    -1,   533,
      -1,   342,    -1,   345,    -1,    25,   150,   546,   122,   545,
      -1,    25,    70,   171,    -1,    25,    70,   185,    -1,    25,
     105,    30,   150,   545,    -1,    25,   105,    34,   150,   545,
      -1,    25,    46,   547,    20,    -1,    25,   251,   575,    -1,
      25,    63,   159,    -1,    25,    63,   191,    -1,    25,   105,
     158,   117,   118,    -1,    25,   105,   158,   117,   119,    -1,
      25,    67,   171,    99,   138,    -1,    25,    67,   171,    99,
     155,    -1,    25,    67,   156,    99,   138,    -1,    25,    67,
     156,    99,   155,    -1,    25,   105,    98,   545,    -1,    25,
      64,   545,    -1,    41,    48,   545,    -1,    41,    48,   344,
     545,    -1,    41,    48,   545,    88,   343,    -1,    41,    48,
     344,   545,    88,   343,    -1,   545,    -1,   343,    99,   545,
      -1,   150,   546,   122,    -1,   105,    30,   150,    -1,    41,
      26,   545,    -1,    41,    26,   150,   546,   122,   545,    -1,
      41,    26,   545,    88,   343,    -1,    41,    26,   150,   546,
     122,   545,    88,   343,    -1,    25,   103,   142,   347,    -1,
      86,   510,   348,    -1,   348,    -1,   349,    -1,   127,    -1,
     127,   349,    -1,   132,   385,    -1,   110,   547,    -1,   110,
     547,   507,    -1,    25,   104,   350,   132,   385,    -1,    25,
     104,   350,   127,    -1,    25,   104,   350,   127,   132,   385,
      -1,   353,    -1,   352,   353,    -1,   278,    -1,   279,    -1,
     280,    -1,   281,    -1,   159,    -1,   191,    -1,   220,   291,
      -1,   220,   290,    -1,   283,    -1,   284,   283,    -1,   287,
     288,    -1,   286,   288,    -1,    25,   277,   547,    -1,    25,
     277,   547,   356,    -1,    25,   277,   547,    86,   355,    -1,
      25,   277,   547,    86,   355,   356,    -1,    25,   352,   277,
     547,    -1,    25,   352,   277,   547,   356,    -1,    25,   352,
     277,   547,    86,   355,    -1,    25,   352,   277,   547,    86,
     355,   356,    -1,   513,    -1,   513,   509,    -1,   227,   282,
     217,    -1,   227,   281,   217,    -1,    25,   285,   547,   289,
     217,   454,   160,   358,    -1,    25,   352,   285,   547,   289,
     217,   454,   160,   358,    -1,   359,    -1,   358,    99,   359,
      -1,   454,    86,   512,    -1,   454,    86,   512,   422,    -1,
      25,   292,   293,   547,   289,   277,   547,   110,   547,   294,
     385,    -1,    25,   292,   293,   547,   289,   277,   547,   215,
     110,   547,   294,   283,   295,   454,    -1,    25,   292,   293,
     547,   289,   277,   547,   296,   215,   110,   547,   294,   385,
      -1,    25,   292,   293,   547,   297,   295,   247,   277,   547,
     215,   110,   547,   295,   454,   188,   277,   547,   215,   110,
     547,   295,   454,    -1,    25,    52,   171,    -1,    25,    52,
     185,    -1,   146,   176,    -1,   146,   377,   176,    -1,   146,
     176,    86,   508,    -1,   146,   377,   176,    86,   508,    -1,
     228,   364,    -1,   143,   365,   382,   173,    -1,   365,   366,
     180,    -1,    -1,   366,    99,   367,    -1,    25,   367,    -1,
     350,    -1,   350,   132,   385,    -1,    50,   110,   547,   132,
     385,    -1,   231,   233,   385,    -1,   234,   146,   385,   176,
     364,    -1,   229,   232,    -1,   230,   232,    -1,    25,   373,
      -1,    25,    38,   373,    -1,    25,    37,   373,    -1,   374,
      -1,    39,   374,    -1,    35,   376,    -1,    36,   375,    -1,
      34,   547,   362,   380,    -1,    34,   547,   362,   127,    -1,
      34,   547,   362,   364,    -1,    34,   547,   362,   127,    -1,
      34,   547,   362,   143,   384,   173,    -1,    34,   547,   362,
     127,    -1,   378,    -1,   377,    99,   378,    -1,   110,   547,
      -1,   110,   547,   507,    -1,   143,   382,   173,    -1,   143,
     382,   173,    -1,   382,    -1,   384,    -1,   384,   383,    -1,
     180,    -1,   383,   384,   180,    -1,   385,    -1,   384,    99,
     385,    -1,   386,    -1,   423,    -1,   426,    -1,   429,    -1,
     430,    -1,   534,    -1,   535,    -1,   537,    -1,   536,    -1,
     538,    -1,   541,    -1,   548,    -1,   369,    -1,   370,    -1,
     371,    -1,   368,    -1,   363,    -1,   395,   387,    -1,   175,
     385,    -1,    56,   274,    -1,    57,   274,    -1,   207,    -1,
     244,    -1,    60,   244,    -1,   389,   407,    61,   385,    -1,
     389,    61,   385,    -1,    54,   388,   406,   390,   390,    -1,
      54,   388,   406,   390,    -1,    62,   110,   547,    -1,   397,
      -1,   402,    -1,   391,    -1,   393,    -1,   411,    -1,   416,
      -1,   412,    -1,   392,    -1,   393,    -1,   395,   394,    -1,
      54,   110,    -1,    55,    54,   110,    -1,   396,   398,    -1,
     399,    -1,   398,    99,   110,   399,    -1,   547,   137,   385,
      -1,   547,   507,   137,   385,    -1,   547,   400,   137,   385,
      -1,   547,   507,   400,   137,   385,    -1,   547,   401,   137,
     385,    -1,   547,   507,   401,   137,   385,    -1,   547,   400,
     401,   137,   385,    -1,   547,   507,   400,   401,   137,   385,
      -1,    88,   110,   547,    -1,   263,   110,   547,    -1,    51,
     110,   403,    -1,   405,    -1,   403,    99,   110,   405,    -1,
     410,    -1,   404,    99,   110,   410,    -1,   547,   132,   385,
      -1,   547,   507,   132,   385,    -1,   547,   401,   132,   385,
      -1,   547,   507,   401,   132,   385,    -1,   110,   547,   137,
     385,    -1,   110,   547,   507,   137,   385,    -1,   408,    -1,
     110,   547,    -1,   110,   547,   408,    -1,   400,    -1,   400,
     409,    -1,   409,    -1,    58,   110,   547,    59,   110,   547,
      -1,    59,   110,   547,    -1,    58,   110,   547,    -1,   547,
      -1,   201,   385,    -1,   161,   160,   413,    -1,   414,    -1,
     413,    99,   414,    -1,   110,   547,    -1,   110,   547,   415,
      -1,    98,   545,    -1,   158,   160,   417,    -1,    45,   158,
     160,   417,    -1,   418,    -1,   417,    99,   418,    -1,   385,
      -1,   385,   419,    -1,   420,    -1,   421,    -1,   422,    -1,
     420,   421,    -1,   420,   422,    -1,   421,   422,    -1,   420,
     421,   422,    -1,    87,    -1,   108,    -1,   117,   118,    -1,
     117,   119,    -1,    98,   545,    -1,    44,   110,   424,   177,
     385,    -1,   125,   110,   424,   177,   385,    -1,   425,    -1,
     424,    99,   110,   425,    -1,   547,   137,   385,    -1,   547,
     507,   137,   385,    -1,    29,   146,   382,   176,   427,   105,
     175,   385,    -1,    29,   146,   382,   176,   427,   105,   110,
     547,   175,   385,    -1,   428,    -1,   427,   428,    -1,    92,
     508,   175,   385,    -1,    92,   110,   547,    86,   508,   175,
     385,    -1,    40,   146,   382,   176,   187,   385,   116,   385,
      -1,   431,    -1,   430,   157,   431,    -1,   432,    -1,   431,
      84,   432,    -1,   434,    -1,   434,   448,   434,    -1,   434,
     449,   434,    -1,   434,   122,   434,    -1,   434,   152,   434,
      -1,    -1,   434,   147,   433,   434,    -1,   434,   145,   434,
      -1,   434,   133,   434,    -1,   434,   131,   434,    -1,   436,
      -1,   436,   249,   550,   435,    -1,    -1,   601,    -1,   437,
      -1,   437,   188,   437,    -1,   438,    -1,   437,   165,   438,
      -1,   437,   148,   438,    -1,   439,    -1,   438,   183,   439,
      -1,   438,   109,   439,    -1,   438,   136,   439,    -1,   438,
     149,   439,    -1,   440,    -1,   439,   190,   440,    -1,   439,
     199,   440,    -1,   441,    -1,   440,   140,   441,    -1,   440,
     126,   441,    -1,   442,    -1,   442,    68,   221,   508,    -1,
     443,    -1,   443,   189,    86,   508,    -1,   444,    -1,   444,
      93,    86,   506,    -1,   445,    -1,   445,    94,    86,   506,
      -1,   447,    -1,   446,   447,    -1,   165,    -1,   148,    -1,
     446,   165,    -1,   446,   148,    -1,   450,    -1,   454,    -1,
     451,    -1,   192,    -1,   197,    -1,   196,    -1,   195,    -1,
     194,    -1,   193,    -1,   141,    -1,   168,    -1,   130,    -1,
      28,   143,   382,   173,    -1,    28,   212,   143,   382,   173,
      -1,    28,   211,   143,   382,   173,    -1,    28,    86,   523,
     143,   382,   173,    -1,   452,   143,   173,    -1,   452,   143,
     382,   173,    -1,   453,    -1,   452,   453,    -1,   166,   547,
      15,    -1,   166,    16,    -1,   455,    -1,   455,   456,    -1,
     182,   456,    -1,   456,    -1,   181,    -1,   457,    -1,   457,
     181,   456,    -1,   457,   182,   456,    -1,   458,    -1,   467,
      -1,   459,    -1,   459,   468,    -1,   462,    -1,   462,   468,
      -1,   460,   464,    -1,   461,    -1,    97,    -1,   106,    -1,
      90,    -1,   179,    -1,   107,    -1,   129,    -1,   128,    -1,
     464,    -1,    91,   464,    -1,   463,   464,    -1,   112,    -1,
     162,    -1,    82,    -1,   170,    -1,   169,    -1,    83,    -1,
     513,    -1,   465,    -1,   547,    -1,   466,    -1,   183,    -1,
      10,    -1,    17,    -1,   470,    -1,   467,   468,    -1,   467,
     146,   176,    -1,   467,   146,   479,   176,    -1,   469,    -1,
     468,   469,    -1,   144,   382,   174,    -1,   471,    -1,   473,
      -1,   474,    -1,   475,    -1,   478,    -1,   480,    -1,   476,
      -1,   477,    -1,   526,    -1,   472,    -1,   525,    -1,   102,
      -1,   139,    -1,   114,    -1,   110,   547,    -1,   146,   176,
      -1,   146,   382,   176,    -1,   111,    -1,   159,   143,   382,
     173,    -1,   191,   143,   382,   173,    -1,   547,   146,   176,
      -1,   547,   146,   479,   176,    -1,   385,    -1,   479,    99,
     385,    -1,   481,    -1,   499,    -1,   482,    -1,   496,    -1,
     497,    -1,   147,   547,   486,   120,    -1,   147,   547,   484,
     486,   120,    -1,   147,   547,   486,   186,   184,   547,   486,
     186,    -1,   147,   547,   486,   186,   483,   184,   547,   486,
     186,    -1,   147,   547,   484,   486,   186,   184,   547,   486,
     186,    -1,   147,   547,   484,   486,   186,   483,   184,   547,
     486,   186,    -1,   494,    -1,   483,   494,    -1,   485,    -1,
     484,   485,    -1,    27,   547,   486,   122,   486,   487,    -1,
      -1,    27,    -1,   172,   488,   172,    -1,    85,   490,    85,
      -1,    -1,   489,    -1,   124,    -1,   492,    -1,   489,   124,
      -1,   489,   492,    -1,    -1,   491,    -1,   123,    -1,   493,
      -1,   491,   123,    -1,   491,   493,    -1,    19,    -1,   495,
      -1,     4,    -1,   495,    -1,   481,    -1,     9,    -1,   498,
      -1,   495,    -1,     8,    -1,   113,    -1,   115,    -1,   379,
      -1,   202,    21,   203,    -1,   202,   203,    -1,   163,   546,
     164,    -1,   163,   546,     7,    -1,    95,     6,    -1,   500,
      -1,   501,    -1,   502,    -1,   503,    -1,   504,    -1,   505,
      -1,    31,   143,   382,   173,    -1,    30,   547,   143,   173,
      -1,    30,   547,   143,   382,   173,    -1,    30,   143,   382,
     173,   143,   173,    -1,    30,   143,   382,   173,   143,   382,
     173,    -1,    89,   547,   143,   173,    -1,    89,   547,   143,
     382,   173,    -1,    89,   143,   382,   173,   143,   173,    -1,
      89,   143,   382,   173,   143,   382,   173,    -1,    32,   143,
     382,   173,    -1,    33,   143,   382,   173,    -1,    42,   546,
     143,   173,    -1,    42,   546,   143,   382,   173,    -1,    42,
     143,   382,   173,   143,   173,    -1,    42,   143,   382,   173,
     143,   382,   173,    -1,   512,    -1,   512,   134,    -1,    86,
     508,    -1,   510,    -1,   510,   509,    -1,   200,   146,   176,
      -1,   134,    -1,   183,    -1,   165,    -1,   512,    -1,   513,
      -1,   142,   146,   176,    -1,   529,    -1,   532,    -1,   508,
      -1,   511,    99,   508,    -1,   547,    -1,   515,    -1,   521,
      -1,   519,    -1,   522,    -1,   520,    -1,   518,    -1,   517,
      -1,   516,    -1,   514,    -1,   215,   146,   176,    -1,    66,
     146,   176,    -1,    66,   146,   521,   176,    -1,    66,   146,
     522,   176,    -1,    32,   146,   176,    -1,    33,   146,   176,
      -1,    42,   146,   176,    -1,    42,   146,   546,   176,    -1,
      42,   146,    20,   176,    -1,    89,   146,   176,    -1,    89,
     146,   547,   176,    -1,    89,   146,   547,    99,   523,   176,
      -1,    89,   146,   183,   176,    -1,    89,   146,   183,    99,
     523,   176,    -1,   178,   547,   176,    -1,    30,   146,   176,
      -1,    30,   146,   547,   176,    -1,    30,   146,   547,    99,
     523,   176,    -1,    30,   146,   547,    99,   524,   176,    -1,
      30,   146,   183,   176,    -1,    30,   146,   183,    99,   523,
     176,    -1,    30,   146,   183,    99,   524,   176,    -1,    65,
     146,   547,   176,    -1,   547,    -1,   547,   134,    -1,    20,
      -1,   527,    -1,   528,    -1,   547,   135,   139,    -1,    34,
     362,   379,    -1,   530,    -1,   531,    -1,    34,   146,   183,
     176,    -1,    34,   146,   176,    86,   508,    -1,    34,   146,
     511,   176,    86,   508,    -1,   146,   510,   176,    -1,    25,
     210,   211,    -1,    25,   210,   212,    -1,    25,   210,   213,
      -1,   216,   215,   385,   223,   385,    -1,   216,   215,   385,
      86,   222,   223,   385,    -1,   216,   215,   385,    86,   224,
     223,   385,    -1,   216,   215,   385,   208,   385,    -1,   216,
     215,   385,   209,   385,    -1,   216,   217,   385,   223,   385,
      -1,   216,   217,   385,    86,   222,   223,   385,    -1,   216,
     217,   385,    86,   224,   223,   385,    -1,   216,   217,   385,
     208,   385,    -1,   216,   217,   385,   209,   385,    -1,   214,
     215,   385,    -1,   214,   217,   385,    -1,   219,   215,   385,
     227,   385,    -1,   219,   220,   221,   215,   385,   227,   385,
      -1,   218,   215,   385,    86,   385,    -1,   226,   110,   539,
     225,   385,   175,   385,    -1,   540,    -1,   539,    99,   110,
     540,    -1,   547,   132,   385,    -1,   235,   143,   382,   173,
     542,    -1,   543,    -1,   542,   543,    -1,   236,   544,   380,
      -1,   236,   544,   146,   110,   547,   176,   380,    -1,   236,
     544,   146,   110,   547,    99,   110,   547,   176,   380,    -1,
     236,   544,   146,   110,   547,    99,   110,   547,    99,   110,
     547,   176,   380,    -1,   465,    -1,   544,   199,   465,    -1,
      20,    -1,    14,    -1,   547,    -1,    18,    -1,   549,    -1,
     237,   110,   404,    53,   143,   385,   173,    -1,    53,   143,
     385,   173,    -1,   204,    -1,   117,    -1,    89,    -1,    33,
      -1,    66,    -1,    30,    -1,   142,    -1,    40,    -1,   215,
      -1,    42,    -1,    69,    -1,    65,    -1,    32,    -1,    29,
      -1,   200,    -1,    70,    -1,   251,    -1,    64,    -1,   212,
      -1,   211,    -1,   136,    -1,    31,    -1,   250,    -1,   264,
      -1,   253,    -1,   241,    -1,   275,    -1,   267,    -1,   269,
      -1,   268,    -1,   273,    -1,   245,    -1,   240,    -1,    47,
      -1,   207,    -1,   244,    -1,    43,    -1,   213,    -1,   226,
      -1,   220,    -1,   192,    -1,   197,    -1,   196,    -1,   195,
      -1,   194,    -1,   193,    -1,    88,    -1,   103,    -1,   104,
      -1,   175,    -1,    54,    -1,    55,    -1,    56,    -1,    57,
      -1,    58,    -1,    59,    -1,    60,    -1,    61,    -1,    62,
      -1,   137,    -1,    51,    -1,   201,    -1,   160,    -1,   161,
      -1,   158,    -1,    45,    -1,    87,    -1,   108,    -1,   118,
      -1,   119,    -1,    98,    -1,    44,    -1,   125,    -1,   177,
      -1,    92,    -1,    86,    -1,   187,    -1,   116,    -1,   157,
      -1,    84,    -1,    68,    -1,   221,    -1,    93,    -1,   188,
      -1,   109,    -1,   149,    -1,   190,    -1,   140,    -1,   126,
      -1,    28,    -1,    94,    -1,   189,    -1,   141,    -1,   171,
      -1,   185,    -1,   150,    -1,   127,    -1,   121,    -1,   156,
      -1,   138,    -1,   155,    -1,    25,    -1,    52,    -1,    63,
      -1,   105,    -1,    67,    -1,    46,    -1,   205,    -1,    41,
      -1,    48,    -1,    26,    -1,    34,    -1,   263,    -1,   249,
      -1,   272,    -1,   274,    -1,   243,    -1,   257,    -1,   270,
      -1,   262,    -1,   242,    -1,   256,    -1,   271,    -1,   261,
      -1,   255,    -1,   254,    -1,   239,    -1,   238,    -1,   260,
      -1,   246,    -1,   247,    -1,   276,    -1,   266,    -1,   265,
      -1,   258,    -1,   219,    -1,   225,    -1,   222,    -1,   216,
      -1,   209,    -1,   208,    -1,   210,    -1,   227,    -1,   217,
      -1,   218,    -1,   224,    -1,   214,    -1,   223,    -1,    39,
      -1,    36,    -1,    35,    -1,    37,    -1,    38,    -1,   159,
      -1,   191,    -1,   233,    -1,   228,    -1,   231,    -1,   232,
      -1,   234,    -1,   229,    -1,   230,    -1,   235,    -1,   236,
      -1,    53,    -1,   237,    -1,    50,    -1,   285,    -1,   283,
      -1,   284,    -1,   289,    -1,   290,    -1,   291,    -1,   286,
      -1,   287,    -1,   288,    -1,    71,    -1,    72,    -1,    73,
      -1,    74,    -1,    75,    -1,    76,    -1,    77,    -1,    78,
      -1,    79,    -1,    80,    -1,    81,    -1,   277,    -1,   278,
      -1,   279,    -1,   280,    -1,   281,    -1,   282,    -1,   292,
      -1,   293,    -1,   294,    -1,   295,    -1,   296,    -1,   297,
      -1,   298,    -1,   553,   551,    -1,    -1,   552,    -1,   570,
      -1,   552,   570,    -1,   554,    -1,   553,   252,   554,    -1,
     555,    -1,   554,   248,   555,    -1,   556,    -1,   555,   250,
     137,   556,    -1,   557,    -1,   250,   557,    -1,   561,   558,
     559,    -1,    -1,   575,    -1,    -1,   560,    -1,   272,   436,
      -1,   564,   562,    -1,   146,   550,   176,    -1,   563,    -1,
      -1,   597,    -1,   452,    -1,   565,   566,    -1,   471,    -1,
     143,   382,   173,    -1,    -1,   567,    -1,   239,   568,    -1,
     238,   569,    -1,   260,    -1,    -1,    47,    -1,    -1,   276,
      -1,   571,    -1,   572,    -1,   573,    -1,   599,    -1,   596,
      -1,   159,    -1,   274,   437,   574,    -1,   243,   598,   574,
      -1,   276,    -1,   266,    -1,   259,    -1,   576,    -1,   575,
     576,    -1,   577,    -1,   578,    -1,   579,    -1,   594,    -1,
     580,    -1,   588,    -1,   581,    -1,   595,    -1,    92,   264,
      -1,    92,   253,    -1,   256,    -1,   271,    -1,   241,   264,
      -1,   241,   253,    -1,    46,   547,    20,    -1,   227,   267,
      -1,   275,   267,    -1,   227,   269,   582,    -1,   227,   269,
     146,   582,   583,   176,    -1,   275,   269,    -1,   585,    -1,
     105,    -1,    -1,   584,    -1,   585,    -1,   584,    99,   585,
      -1,    88,    20,   586,   587,    -1,    -1,   261,    20,    -1,
      -1,   598,   255,    -1,   227,   268,   276,   589,   591,    -1,
     227,   105,   268,   276,   591,    -1,   275,   268,   276,    -1,
      88,    20,    -1,   146,   590,   176,    -1,    20,    -1,   590,
      99,    20,    -1,    -1,   592,    -1,   593,    -1,   592,   593,
      -1,   190,   589,    -1,   126,   589,    -1,   254,    20,    -1,
     227,   273,    -1,   275,   273,    -1,    88,   207,    -1,    88,
     244,    -1,   245,   240,    -1,   257,   598,   270,    -1,   246,
     437,    -1,    88,   119,   437,    -1,    88,    43,   437,    -1,
     247,   437,   188,   437,    -1,   262,   600,    -1,   242,   600,
      -1,   265,    -1,   258,    -1,   275,   240,   439,    -1
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
     371,   374,   376,   379,   382,   385,   389,   394,   400,   407,
     412,   418,   425,   433,   435,   438,   442,   446,   455,   465,
     467,   471,   475,   480,   492,   507,   521,   544,   548,   552,
     555,   559,   564,   570,   573,   578,   582,   583,   587,   590,
     592,   596,   602,   606,   612,   615,   618,   621,   625,   629,
     631,   634,   637,   640,   645,   650,   655,   660,   667,   672,
     674,   678,   681,   685,   689,   693,   695,   697,   700,   702,
     706,   708,   712,   714,   716,   718,   720,   722,   724,   726,
     728,   730,   732,   734,   736,   738,   740,   742,   744,   746,
     749,   752,   755,   758,   760,   762,   765,   770,   774,   780,
     785,   789,   791,   793,   795,   797,   799,   801,   803,   805,
     807,   810,   813,   817,   820,   822,   827,   831,   836,   841,
     847,   852,   858,   864,   871,   875,   879,   883,   885,   890,
     892,   897,   901,   906,   911,   917,   922,   928,   930,   933,
     937,   939,   942,   944,   951,   955,   959,   961,   964,   968,
     970,   974,   977,   981,   984,   988,   993,   995,   999,  1001,
    1004,  1006,  1008,  1010,  1013,  1016,  1019,  1023,  1025,  1027,
    1030,  1033,  1036,  1042,  1048,  1050,  1055,  1059,  1064,  1073,
    1084,  1086,  1089,  1094,  1102,  1111,  1113,  1117,  1119,  1123,
    1125,  1129,  1133,  1137,  1141,  1142,  1147,  1151,  1155,  1159,
    1161,  1166,  1167,  1169,  1171,  1175,  1177,  1181,  1185,  1187,
    1191,  1195,  1199,  1203,  1205,  1209,  1213,  1215,  1219,  1223,
    1225,  1230,  1232,  1237,  1239,  1244,  1246,  1251,  1253,  1256,
    1258,  1260,  1263,  1266,  1268,  1270,  1272,  1274,  1276,  1278,
    1280,  1282,  1284,  1286,  1288,  1290,  1295,  1301,  1307,  1314,
    1318,  1323,  1325,  1328,  1332,  1335,  1337,  1340,  1343,  1345,
    1347,  1349,  1353,  1357,  1359,  1361,  1363,  1366,  1368,  1371,
    1374,  1376,  1378,  1380,  1382,  1384,  1386,  1388,  1390,  1392,
    1395,  1398,  1400,  1402,  1404,  1406,  1408,  1410,  1412,  1414,
    1416,  1418,  1420,  1422,  1424,  1426,  1429,  1433,  1438,  1440,
    1443,  1447,  1449,  1451,  1453,  1455,  1457,  1459,  1461,  1463,
    1465,  1467,  1469,  1471,  1473,  1475,  1478,  1481,  1485,  1487,
    1492,  1497,  1501,  1506,  1508,  1512,  1514,  1516,  1518,  1520,
    1522,  1527,  1533,  1542,  1552,  1562,  1573,  1575,  1578,  1580,
    1583,  1590,  1591,  1593,  1597,  1601,  1602,  1604,  1606,  1608,
    1611,  1614,  1615,  1617,  1619,  1621,  1624,  1627,  1629,  1631,
    1633,  1635,  1637,  1639,  1641,  1643,  1645,  1647,  1649,  1651,
    1655,  1658,  1662,  1666,  1669,  1671,  1673,  1675,  1677,  1679,
    1681,  1686,  1691,  1697,  1704,  1712,  1717,  1723,  1730,  1738,
    1743,  1748,  1753,  1759,  1766,  1774,  1776,  1779,  1782,  1784,
    1787,  1791,  1793,  1795,  1797,  1799,  1801,  1805,  1807,  1809,
    1811,  1815,  1817,  1819,  1821,  1823,  1825,  1827,  1829,  1831,
    1833,  1835,  1839,  1843,  1848,  1853,  1857,  1861,  1865,  1870,
    1875,  1879,  1884,  1891,  1896,  1903,  1907,  1911,  1916,  1923,
    1930,  1935,  1942,  1949,  1954,  1956,  1959,  1961,  1963,  1965,
    1969,  1973,  1975,  1977,  1982,  1988,  1995,  1999,  2003,  2007,
    2011,  2017,  2025,  2033,  2039,  2045,  2051,  2059,  2067,  2073,
    2079,  2083,  2087,  2093,  2101,  2107,  2115,  2117,  2122,  2126,
    2132,  2134,  2137,  2141,  2149,  2160,  2174,  2176,  2180,  2182,
    2184,  2186,  2188,  2190,  2198,  2203,  2205,  2207,  2209,  2211,
    2213,  2215,  2217,  2219,  2221,  2223,  2225,  2227,  2229,  2231,
    2233,  2235,  2237,  2239,  2241,  2243,  2245,  2247,  2249,  2251,
    2253,  2255,  2257,  2259,  2261,  2263,  2265,  2267,  2269,  2271,
    2273,  2275,  2277,  2279,  2281,  2283,  2285,  2287,  2289,  2291,
    2293,  2295,  2297,  2299,  2301,  2303,  2305,  2307,  2309,  2311,
    2313,  2315,  2317,  2319,  2321,  2323,  2325,  2327,  2329,  2331,
    2333,  2335,  2337,  2339,  2341,  2343,  2345,  2347,  2349,  2351,
    2353,  2355,  2357,  2359,  2361,  2363,  2365,  2367,  2369,  2371,
    2373,  2375,  2377,  2379,  2381,  2383,  2385,  2387,  2389,  2391,
    2393,  2395,  2397,  2399,  2401,  2403,  2405,  2407,  2409,  2411,
    2413,  2415,  2417,  2419,  2421,  2423,  2425,  2427,  2429,  2431,
    2433,  2435,  2437,  2439,  2441,  2443,  2445,  2447,  2449,  2451,
    2453,  2455,  2457,  2459,  2461,  2463,  2465,  2467,  2469,  2471,
    2473,  2475,  2477,  2479,  2481,  2483,  2485,  2487,  2489,  2491,
    2493,  2495,  2497,  2499,  2501,  2503,  2505,  2507,  2509,  2511,
    2513,  2515,  2517,  2519,  2521,  2523,  2525,  2527,  2529,  2531,
    2533,  2535,  2537,  2539,  2541,  2543,  2545,  2547,  2549,  2551,
    2553,  2555,  2557,  2559,  2561,  2563,  2565,  2567,  2569,  2571,
    2573,  2575,  2577,  2579,  2581,  2583,  2585,  2587,  2589,  2591,
    2593,  2595,  2597,  2599,  2601,  2603,  2606,  2607,  2609,  2611,
    2614,  2616,  2620,  2622,  2626,  2628,  2633,  2635,  2638,  2642,
    2643,  2645,  2646,  2648,  2651,  2654,  2658,  2660,  2661,  2663,
    2665,  2668,  2670,  2674,  2675,  2677,  2680,  2683,  2685,  2686,
    2688,  2689,  2691,  2693,  2695,  2697,  2699,  2701,  2703,  2707,
    2711,  2713,  2715,  2717,  2719,  2722,  2724,  2726,  2728,  2730,
    2732,  2734,  2736,  2738,  2741,  2744,  2746,  2748,  2751,  2754,
    2758,  2761,  2764,  2768,  2775,  2778,  2780,  2782,  2783,  2785,
    2787,  2791,  2796,  2797,  2800,  2801,  2804,  2810,  2816,  2820,
    2823,  2827,  2829,  2833,  2834,  2836,  2838,  2841,  2844,  2847,
    2850,  2853,  2856,  2859,  2862,  2865,  2869,  2872,  2876,  2880,
    2885,  2888,  2891,  2893,  2895
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,   974,   974,   975,   984,   989,   996,  1001,  1012,  1017,
    1025,  1033,  1041,  1047,  1059,  1068,  1072,  1076,  1088,  1094,
    1104,  1110,  1120,  1121,  1122,  1123,  1128,  1129,  1130,  1131,
    1132,  1133,  1134,  1135,  1136,  1142,  1147,  1156,  1162,  1171,
    1180,  1181,  1182,  1183,  1184,  1185,  1186,  1187,  1188,  1189,
    1194,  1195,  1196,  1197,  1198,  1199,  1200,  1203,  1208,  1209,
    1219,  1228,  1234,  1244,  1250,  1260,  1270,  1278,  1284,  1295,
    1300,  1310,  1316,  1322,  1328,  1345,  1353,  1361,  1365,  1374,
    1383,  1396,  1402,  1413,  1417,  1425,  1430,  1435,  1442,  1455,
    1462,  1468,  1475,  1481,  1485,  1492,  1503,  1507,  1515,  1521,
    1527,  1536,  1542,  1551,  1555,  1561,  1565,  1569,  1573,  1579,
    1585,  1591,  1595,  1601,  1607,  1614,  1622,  1630,  1638,  1646,
    1652,  1660,  1668,  1679,  1684,  1692,  1696,  1703,  1711,  1722,
    1728,  1736,  1743,  1753,  1763,  1773,  1783,  1800,  1806,  1817,
    1821,  1825,  1829,  1838,  1845,  1864,  1874,  1880,  1886,  1896,
    1903,  1914,  1924,  1931,  1943,  1947,  1954,  1959,  1966,  1974,
    1978,  1982,  1990,  1998,  2008,  2022,  2032,  2046,  2055,  2070,
    2076,  2088,  2092,  2103,  2110,  2118,  2133,  2137,  2151,  2155,
    2164,  2168,  2182,  2183,  2184,  2185,  2186,  2189,  2190,  2191,
    2192,  2193,  2195,  2196,  2199,  2200,  2201,  2202,  2203,  2208,
    2223,  2230,  2234,  2241,  2245,  2249,  2256,  2264,  2275,  2285,
    2298,  2307,  2308,  2309,  2313,  2314,  2315,  2316,  2317,  2320,
    2326,  2335,  2339,  2347,  2357,  2363,  2375,  2379,  2387,  2396,
    2406,  2414,  2423,  2432,  2447,  2456,  2466,  2474,  2480,  2489,
    2495,  2507,  2515,  2525,  2533,  2545,  2551,  2562,  2564,  2568,
    2576,  2580,  2585,  2589,  2593,  2597,  2605,  2620,  2628,  2635,
    2641,  2652,  2656,  2665,  2673,  2679,  2689,  2695,  2705,  2709,
    2719,  2725,  2731,  2737,  2746,  2755,  2764,  2777,  2781,  2789,
    2795,  2805,  2813,  2822,  2835,  2842,  2854,  2858,  2871,  2878,
    2891,  2897,  2909,  2915,  2927,  2936,  2940,  2949,  2953,  2961,
    2965,  2975,  2982,  2991,  3001,  3000,  3014,  3023,  3032,  3045,
    3049,  3061,  3064,  3072,  3076,  3085,  3089,  3093,  3102,  3106,
    3112,  3118,  3124,  3135,  3139,  3143,  3151,  3155,  3161,  3171,
    3175,  3185,  3189,  3199,  3203,  3213,  3217,  3227,  3231,  3239,
    3243,  3247,  3251,  3261,  3265,  3269,  3277,  3281,  3285,  3289,
    3293,  3297,  3305,  3309,  3313,  3321,  3325,  3329,  3333,  3343,
    3349,  3359,  3365,  3375,  3379,  3417,  3423,  3429,  3435,  3446,
    3454,  3465,  3471,  3481,  3485,  3493,  3499,  3507,  3513,  3525,
    3531,  3541,  3545,  3549,  3553,  3557,  3563,  3569,  3577,  3581,
    3589,  3593,  3604,  3608,  3612,  3618,  3622,  3636,  3640,  3648,
    3652,  3662,  3666,  3670,  3679,  3683,  3689,  3693,  3701,  3707,
    3717,  3725,  3729,  3733,  3737,  3741,  3745,  3749,  3753,  3757,
    3765,  3769,  3777,  3784,  3791,  3802,  3811,  3815,  3823,  3831,
    3839,  3893,  3897,  3909,  3915,  3925,  3929,  3937,  3941,  3945,
    3953,  3963,  3973,  3983,  3993,  4003,  4018,  4024,  4035,  4041,
    4052,  4063,  4065,  4069,  4074,  4084,  4087,  4094,  4102,  4108,
    4118,  4131,  4134,  4141,  4147,  4153,  4160,  4171,  4175,  4185,
    4189,  4199,  4203,  4207,  4212,  4221,  4227,  4233,  4239,  4249,
    4253,  4265,  4269,  4281,  4293,  4297,  4301,  4305,  4309,  4313,
    4321,  4329,  4335,  4341,  4345,  4362,  4366,  4370,  4374,  4382,
    4390,  4398,  4402,  4406,  4410,  4418,  4424,  4434,  4442,  4446,
    4452,  4487,  4493,  4499,  4509,  4513,  4517,  4521,  4525,  4532,
    4538,  4548,  4556,  4560,  4564,  4568,  4572,  4576,  4580,  4584,
    4588,  4596,  4604,  4608,  4612,  4622,  4630,  4638,  4642,  4646,
    4654,  4658,  4664,  4670,  4674,  4684,  4692,  4696,  4702,  4711,
    4720,  4726,  4732,  4742,  4759,  4766,  4781,  4817,  4821,  4830,
    4839,  4848,  4852,  4861,  4870,  4874,  4883,  4900,  4906,  4912,
    4922,  4926,  4932,  4938,  4942,  4948,  4952,  4958,  4964,  4971,
    4981,  4986,  4994,  5000,  5010,  5032,  5041,  5047,  5060,  5074,
    5081,  5087,  5097,  5102,  5108,  5118,  5131,  5137,  5147,  5157,
    5158,  5176,  5180,  5193,  5199,  5206,  5207,  5208,  5209,  5210,
    5211,  5212,  5213,  5214,  5215,  5216,  5217,  5218,  5219,  5220,
    5221,  5222,  5223,  5224,  5225,  5226,  5227,  5228,  5229,  5230,
    5231,  5232,  5233,  5234,  5235,  5236,  5237,  5238,  5239,  5240,
    5241,  5242,  5243,  5244,  5245,  5246,  5247,  5248,  5249,  5250,
    5251,  5252,  5253,  5254,  5255,  5256,  5257,  5258,  5259,  5260,
    5261,  5262,  5263,  5264,  5265,  5266,  5267,  5268,  5269,  5270,
    5271,  5272,  5273,  5274,  5275,  5276,  5277,  5278,  5279,  5280,
    5281,  5282,  5283,  5284,  5285,  5286,  5287,  5288,  5289,  5290,
    5291,  5292,  5293,  5294,  5295,  5296,  5297,  5298,  5299,  5300,
    5301,  5302,  5303,  5304,  5305,  5306,  5307,  5308,  5309,  5310,
    5311,  5312,  5313,  5314,  5315,  5316,  5317,  5318,  5319,  5320,
    5321,  5322,  5323,  5324,  5325,  5326,  5327,  5328,  5329,  5330,
    5331,  5332,  5333,  5334,  5335,  5336,  5337,  5338,  5339,  5340,
    5341,  5342,  5343,  5344,  5345,  5346,  5347,  5348,  5349,  5350,
    5351,  5352,  5353,  5354,  5355,  5356,  5357,  5358,  5359,  5360,
    5361,  5362,  5363,  5364,  5365,  5366,  5367,  5368,  5369,  5370,
    5371,  5372,  5373,  5374,  5375,  5376,  5377,  5378,  5379,  5380,
    5381,  5382,  5383,  5384,  5385,  5386,  5387,  5388,  5389,  5390,
    5391,  5392,  5393,  5394,  5395,  5396,  5397,  5398,  5399,  5400,
    5401,  5402,  5403,  5404,  5405,  5417,  5426,  5429,  5436,  5441,
    5450,  5454,  5464,  5468,  5478,  5482,  5493,  5497,  5507,  5520,
    5523,  5531,  5534,  5542,  5550,  5558,  5562,  5570,  5573,  5581,
    5589,  5601,  5607,  5615,  5618,  5626,  5630,  5634,  5642,  5645,
    5653,  5656,  5664,  5668,  5672,  5676,  5680,  5688,  5696,  5708,
    5720,  5724,  5728,  5736,  5742,  5752,  5756,  5760,  5764,  5768,
    5772,  5776,  5780,  5788,  5794,  5800,  5804,  5812,  5818,  5828,
    5838,  5844,  5854,  5864,  5875,  5882,  5886,  5894,  5897,  5904,
    5909,  5918,  5928,  5931,  5939,  5942,  5950,  5959,  5966,  5976,
    5980,  5987,  5993,  6003,  6006,  6013,  6018,  6030,  6038,  6050,
    6058,  6062,  6070,  6076,  6082,  6092,  6100,  6104,  6108,  6112,
    6120,  6128,  6140,  6144,  6152
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
     305,   306,   307,   308,   309,   310,   311,   312,   313
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 11268;
  const int xquery_parser::yynnts_ = 288;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 520;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 314;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 568;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // zorba

/* Line 1054 of lalr1.cc  */
#line 15067 "/home/sausalito/wcandillon/zorba/build/src/compiler/parser/xquery_parser.cpp"


/* Line 1056 of lalr1.cc  */
#line 6158 "/home/sausalito/wcandillon/zorba/src/compiler/parser/xquery_parser.y"


namespace zorba {

namespace parser {

const char *the_tumbling = "tumbling", *the_sliding = "sliding",
  *the_start = "start", *the_end = "end", *the_only_end = "only end",
  *the_ofor = "ofor", *the_declare = "declare", *the_create = "create";

} // namespace parser

/*
    The error member function registers the errors to the driver.
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

