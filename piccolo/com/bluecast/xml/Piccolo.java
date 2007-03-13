//### This file created by BYACC 1.8(/Java extension  1.1)
//### Java capabilities added 7 Jan 97, Bob Jamison
//### Updated : 27 Nov 97  -- Bob Jamison, Joe Nieten
//###           01 Jan 98  -- Bob Jamison -- fixed generic semantic constructor
//###           01 Jun 99  -- Bob Jamison -- added Runnable support
//###           06 Aug 00  -- Bob Jamison -- made state variables class-global
//###           03 Jan 01  -- Bob Jamison -- improved flags, tracing
//###           16 May 01  -- Bob Jamison -- added custom stack sizing
//###           04 Mar 02  -- Yuval Oren  -- improved java performance, added options
//### Please send bug reports to rjamison@lincom-asg.com
//### static char yysccsid[] = "@(#)yaccpar	1.8 (Berkeley) 01/20/90";






//#line 2 "Piccolo.y"
package com.bluecast.xml;

import org.xml.sax.*;
import org.xml.sax.helpers.*;
import org.xml.sax.ext.*;
import java.io.*;
import java.net.MalformedURLException;
import com.bluecast.util.*;
import com.bluecast.io.*;
import java.util.*;

/*
 * $Id: Piccolo.y,v 1.10 2004/07/11 09:37:37 yuvalo Exp $
 *
 * 2003-06-10 - MODIFIED to provide access to <?xml?> definition
 *              and startLocator
 *
 * (C) Copyright 2002-2004 by Yuval Oren. All rights reserved.
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

 /**
  * Piccolo is a small, high-performance SAX1 and SAX2 XML parser.
  * As per the SAX2 specification, namespace handling is on by
  * default. You can improve performance by turning it off.
  *
  * Note that if used in SAX1 mode, namespace handling is
  * automatically turned off.
  */
//#line 57 "Piccolo.java"




public class Piccolo
             implements org.xml.sax.Parser,org.xml.sax.Locator,org.xml.sax.XMLReader
{

boolean yydebug;        //do I want debug output?
int yynerrs;            //number of errors so far
int yyerrflag;          //was there an error?
int yychar;             //the current working character

//########## MESSAGES ##########
//###############################################################
// method: debug
//###############################################################
void debug(String msg)
{
  if (yydebug)
    System.out.println(msg);
}

//########## STATE STACK ##########
final static int YYSTACKSIZE = 500;  //maximum stack size
int statestk[] = new int[YYSTACKSIZE]; //state stack
int stateptr;
int stateptrmax;                     //highest index of stackptr
int statemax;                        //state when highest index reached
//###############################################################
// methods: state stack push,pop,drop,peek
//###############################################################
final void state_push(int state)
{
  try {
		stateptr++;
		statestk[stateptr]=state;
	 }
	 catch (ArrayIndexOutOfBoundsException e) {
     int oldsize = statestk.length;
     int newsize = oldsize * 2;
     int[] newstack = new int[newsize];
     System.arraycopy(statestk,0,newstack,0,oldsize);
     statestk = newstack;
     statestk[stateptr]=state;
  }
}
final int state_pop()
{
  return statestk[stateptr--];
}
final void state_drop(int cnt)
{
  stateptr -= cnt; 
}
final int state_peek(int relative)
{
  return statestk[stateptr-relative];
}
//###############################################################
// method: init_stacks : allocate and prepare stacks
//###############################################################
final boolean init_stacks()
{
  stateptr = -1;
  val_init();
  return true;
}
//###############################################################
// method: dump_stacks : show n levels of the stacks
//###############################################################
void dump_stacks(int count)
{
int i;
  System.out.println("=index==state====value=     s:"+stateptr+"  v:"+valptr);
  for (i=0;i<count;i++)
    System.out.println(" "+i+"    "+statestk[i]+"      "+valstk[i]);
  System.out.println("======================");
}


//########## SEMANTIC VALUES ##########
//## **user defined:String
String   yytext;//user variable to return contextual strings
String yyval; //used to return semantic vals from action routines
String yylval;//the 'lval' (result) I got from yylex()
String valstk[] = new String[YYSTACKSIZE];
int valptr;
//###############################################################
// methods: value stack push,pop,drop,peek.
//###############################################################
final void val_init()
{
  yyval=new String();
  yylval=new String();
  valptr=-1;
}
final void val_push(String val)
{
  try {
    valptr++;
    valstk[valptr]=val;
  }
  catch (ArrayIndexOutOfBoundsException e) {
    int oldsize = valstk.length;
    int newsize = oldsize*2;
    String[] newstack = new String[newsize];
    System.arraycopy(valstk,0,newstack,0,oldsize);
    valstk = newstack;
    valstk[valptr]=val;
  }
}
final String val_pop()
{
  return valstk[valptr--];
}
final void val_drop(int cnt)
{
  valptr -= cnt;
}
final String val_peek(int relative)
{
  return valstk[valptr-relative];
}
//#### end semantic value section ####
public final static short CDATA=257;
public final static short TAG_END=258;
public final static short PI=259;
public final static short NAME=260;
public final static short STRING=261;
public final static short EQ=262;
public final static short OPEN_TAG=263;
public final static short CLOSE_TAG=264;
public final static short EMPTY_TAG=265;
public final static short WHITESPACE=266;
public final static short DTD_START=267;
public final static short DTD_START_SKIPEXTERNAL=268;
public final static short SYSTEM=269;
public final static short PUBLIC=270;
public final static short REQUIRED=271;
public final static short IMPLIED=272;
public final static short FIXED=273;
public final static short LPAREN=274;
public final static short RPAREN=275;
public final static short LBRACKET=276;
public final static short PIPE=277;
public final static short ENTITY_DECL_START=278;
public final static short ATTLIST_START=279;
public final static short NOTATION_START=280;
public final static short RBRACKET_END=281;
public final static short DOUBLE_RBRACKET_END=282;
public final static short PERCENT=283;
public final static short ENUMERATION=284;
public final static short NOTATION=285;
public final static short ID=286;
public final static short IDREF=287;
public final static short IDREFS=288;
public final static short ENTITY=289;
public final static short ENTITIES=290;
public final static short NMTOKEN=291;
public final static short NMTOKENS=292;
public final static short ENTITY_REF=293;
public final static short ENTITY_END=294;
public final static short INTERNAL_ENTITY_REF=295;
public final static short EXTERNAL_ENTITY_REF=296;
public final static short SKIPPED_ENTITY_REF=297;
public final static short PREFIXED_NAME=298;
public final static short UNPREFIXED_NAME=299;
public final static short NDATA=300;
public final static short COMMENT=301;
public final static short CONDITIONAL_START=302;
public final static short IGNORED_CONDITIONAL_START=303;
public final static short INCLUDE=304;
public final static short IGNORE=305;
public final static short MODIFIER=306;
public final static short PCDATA=307;
public final static short ELEMENT_DECL_START=308;
public final static short EMPTY=309;
public final static short ANY=310;
public final static short STAR=311;
public final static short COMMA=312;
public final static short QUESTION=313;
public final static short PLUS=314;
public final static short XML_DOC_DECL=315;
public final static short XML_TEXT_DECL=316;
public final static short XML_DOC_OR_TEXT_DECL=317;
public final static short YYERRCODE=256;
final static short yylhs[] = {                           -1,
    0,    0,    1,    1,    1,    5,    5,    3,    3,    3,
    4,    4,    7,    7,    7,    8,    8,    9,    9,    2,
    2,    2,    2,    2,    2,   12,   12,   14,   14,   10,
   10,   10,   13,   13,   11,   11,   11,   11,   11,   11,
   11,   11,   11,   11,   15,   15,   20,   20,   21,   21,
   22,   22,   16,   16,   16,   16,   16,   16,   18,   18,
   17,   23,   24,   24,   25,   25,   25,   25,   25,   25,
   25,   25,   26,   26,   26,   26,   26,   26,   26,   26,
   26,   26,   27,   27,   19,   28,   28,   28,   28,   29,
   29,   29,   29,   30,   30,   30,   34,   34,   36,   36,
   35,   35,   35,   35,   31,   31,   33,   33,   32,   32,
   32,   32,    6,    6,    6,    6,    6,    6,    6,    6,
    6,    6,
};
final static short yylen[] = {                            2,
    4,    3,    1,    1,    0,    1,    1,    1,    3,    2,
    2,    0,    1,    1,    1,    1,    2,    0,    1,    4,
    3,    4,    3,    6,    2,    2,    4,    7,    9,    3,
    3,    5,    3,    5,    0,    2,    2,    2,    2,    2,
    2,    3,    3,    4,    4,    4,    3,    2,    3,    2,
    0,    4,    7,    7,   11,    8,    8,   11,    7,    9,
    4,    3,    0,    3,    5,    5,    5,    5,    7,    7,
    5,    5,    1,    1,    1,    1,    1,    1,    1,    1,
    5,    7,    1,    5,    7,    1,    1,    1,    1,    6,
    5,   10,    2,    2,    2,    2,    5,    5,    1,    4,
    3,    3,    3,    2,    4,    2,    4,    2,    1,    1,
    1,    0,    0,    4,    4,    5,    4,    2,    2,    2,
    2,    2,
};
final static short yydefred[] = {                         0,
    3,    4,    0,    0,   14,  113,    8,   13,    0,    0,
   15,    0,    0,    0,   35,    0,    0,    0,    0,    0,
    0,    0,    2,    0,   25,   10,    0,    6,    7,   35,
    0,   26,   35,  122,  119,  113,    9,  118,  121,  113,
    0,  120,   16,   30,    0,    0,   31,    0,    1,   11,
    0,    0,    0,   21,   35,    0,    0,    0,   40,   36,
   37,   38,   39,   41,   63,    0,   23,    0,    0,    0,
  113,    0,   17,    0,    0,   20,    0,    0,    0,    0,
    0,    0,    0,   35,    0,    0,    0,    0,   35,   51,
    0,    0,   22,   27,  117,  114,    0,  115,    0,    0,
    0,    0,   32,    0,    0,    0,    0,   62,    0,    0,
    0,    0,   16,   48,   50,    0,    0,    0,    0,    0,
  116,    0,    0,   33,    0,   24,    0,    0,    0,   47,
   49,   45,   46,   51,    0,    0,    0,   64,   61,   28,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   86,   87,    0,   88,   89,    0,    0,    0,    0,
    0,   34,    0,    0,    0,    0,    0,    0,    0,    0,
   52,    0,   93,   96,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  110,  109,  111,   94,
   95,   73,    0,    0,   74,   75,   76,   77,   78,   79,
   80,    0,    0,   29,   53,    0,   54,    0,    0,    0,
    0,   59,    0,    0,    0,    0,  104,    0,    0,    0,
    0,    0,    0,   85,    0,    0,    0,    0,    0,   56,
   57,    0,    0,    0,  101,    0,  102,  103,  105,    0,
    0,  107,   83,    0,    0,   71,   65,   67,    0,   72,
   66,   68,    0,    0,    0,   60,    0,    0,    0,    0,
  100,    0,    0,    0,    0,    0,    0,   90,    0,   98,
    0,    0,   81,    0,    0,   69,   70,   55,   58,    0,
    0,    0,    0,    0,   84,   82,    0,   92,
};
final static short yydgoto[] = {                          3,
    4,   12,   26,   23,   30,   18,   59,  104,   46,   15,
   27,   16,   79,   17,   60,   61,   62,   63,   64,   89,
   90,  117,   65,   92,  138,  202,  244,  154,  173,  174,
  181,  190,  182,  183,  184,  185,
};
final static short yysindex[] = {                      -120,
    0,    0,    0,  181,    0,    0,    0,    0, -213, -166,
    0, -250, -248,  181,    0,  -10, -206, -119, -239, -188,
 -248, -250,    0, -248,    0,    0,  -41,    0,    0,    0,
  -16,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  -10,    0,    0,    0,  165, -237,    0,  225,    0,    0,
 -194, -194, -194,    0,    0,  -10, -223, -194,    0,    0,
    0,    0,    0,    0,    0,   -7,    0,   18,  102,  117,
    0,  127,    0, -194, -194,    0, -194, -194, -137, -146,
  -88,  -54,   77,    0,   77, -194, -194, -209,    0,    0,
  -24, -194,    0,    0,    0,    0,  142,    0, -108,  -76,
  -53,  -15,    0, -135, -117, -194,  -79,    0, -194,   77,
  -66,  -59,    0,    0,    0,   43, -139, -194, -147,  -32,
    0, -194, -194,    0, -194,    0,  204,  227,  232,    0,
    0,    0,    0,    0, -264, -194, -194,    0,    0,    0,
   15,   76, -194, -194,  210, -194, -194, -194, -133, -103,
  -86,    0,    0, -194,    0,    0,  106,  106,  198,  198,
 -194,    0,   16, -235,   35, -194, -194, -192,   97,   92,
    0, -103,    0,    0,  106,  106,  106,  -55,  -55,   55,
  106,  106, -194, -194, -194,  113,    0,    0,    0,    0,
    0,    0, -194, -194,    0,    0,    0,    0,    0,    0,
    0, -194, -194,    0,    0, -194,    0,  123,  130, -194,
 -194,    0, -194,  -55,  106,  106,    0, -194, -194, -194,
   49, -251,  116,    0,  135,  -39,   44,  143,   67,    0,
    0,   68,   76,  144,    0,  -28,    0,    0,    0, -194,
  -55,    0,    0, -194, -194,    0,    0,    0, -194,    0,
    0,    0, -194, -194, -194,    0,   89, -194,  -55, -194,
    0,  112,  135,  103,  109,  148,  152,    0,  135,    0,
 -194,   65,    0, -194, -194,    0,    0,    0,    0, -194,
  168,  169,  119,  150,    0,    0,  131,    0,
};
final static short yyrindex[] = {                       191,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  452,    0,    0,   52,    0,    0,  202,    0,
  452,    0,    0,  452,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  167,    0,    0,    0,  208,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -80,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  202,    0,
    0,    0,  -50,    0,  -12,  193,  193,    0,    0,    0,
    0,  202,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -153,    0,    0,    0,    0,    0,    9,
    0,    0,    0,    0,    0,    0,    0,    0,  208,    0,
    0, -178,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  202,  202,    0,    0,    0,  202,    0,   31,
  160,    0,    0,  202,    0,    0,  -25,  -25,    0,    0,
 -178,    0,    0,  208,    0,  202,  202,    0,    0,    0,
    0,    0,    0,    0,  -13,   17, -263,  170,    0,    0,
 -263, -263,  200, -186,  200,    0,    0,    0,    0,    0,
    0,    0,  218,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  202,    0, -164,    0, -258, -200,    0,  164, -164, -164,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  208,    0,    0,    0,    0,    0,    0, -124,
    0,    0,    0,  164,  218,    0,    0,    0,    0,    0,
    0,    0,    0,  202,  202,    0,   42,  218,    0, -252,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  176,    0,    0,  218,  164,    0,    0,    0,    0,  164,
    0,    0,    0,    0,    0,    0,    0,    0,
};
final static short yygindex[] = {                         0,
    0,  467,  300,  328,   27,  125,  244,  -19,  -51,    0,
   46,    0,   28,    0,    0,    0,    0,    0,    0,  411,
  412,  369,    0,    0,    0,  344,   66,    0,  370,  371,
 -130, -152, -128,  248, -174,  267,
};
final static int YYTABLESIZE=508;
final static short yytable[] = {                         45,
   48,  150,  112,  217,  157,  191,  158,  106,    5,  151,
    5,  112,    6,  112,    7,    8,  106,    8,  106,  175,
   76,  176,   99,  191,  213,  240,   43,  105,  219,  220,
   73,   80,   81,   82,  111,  112,   44,   88,   91,  217,
  120,  175,   43,  176,  152,  153,   19,  215,  112,  216,
   11,   32,   11,  106,   99,  100,  113,  101,  102,   18,
  241,   31,  219,  220,  206,  108,  260,   71,   88,   33,
  140,   43,  119,   73,  108,   66,  108,   43,   68,   18,
   86,   87,   84,  215,  271,  216,  127,   47,   99,  129,
   18,  163,  165,   20,   86,   87,  170,   18,  135,  180,
   83,   85,  186,  141,   19,  142,   19,  210,  145,  204,
   18,  108,   18,  106,  208,  209,  159,  160,   73,   73,
   19,   19,   19,   19,  164,   18,  168,  169,   43,  110,
   73,  221,  222,  223,  116,   18,  107,   34,  103,   35,
  126,  225,  133,   36,   37,   38,   39,   18,  171,   18,
  136,  137,  122,   19,  144,  146,  148,   73,   19,  234,
   69,  235,  172,  134,   70,   72,  236,  237,  238,  134,
  151,  108,  167,  177,  226,   40,   41,   73,   35,  178,
  128,   42,  227,  228,  123,   35,  229,  179,  259,   73,
  232,  233,  262,  263,    1,   97,    2,   35,   35,   35,
   35,   35,  266,  267,  177,  109,  269,  124,  272,  130,
  214,   73,   73,   35,   35,   35,  131,    5,  179,  281,
   35,   35,  282,  283,    8,  139,   73,   35,  284,  264,
   42,   42,  112,  265,  245,  118,   51,   52,   53,   54,
  112,   73,    5,   42,  106,  125,  257,   14,  258,    8,
   73,    5,  106,   55,   56,   22,   24,   14,    8,   11,
   57,   51,   52,   53,   24,   22,   58,   24,   43,   43,
   51,   52,   53,  205,  108,  161,    5,   67,   55,   56,
   73,   43,  108,    8,   11,   57,   93,   55,   56,   44,
   44,   58,  207,   11,   57,   51,   52,   53,   94,   91,
   58,    5,   44,   13,  246,   28,   29,   91,    8,   73,
   35,   21,   55,   56,  247,  248,  249,   35,   11,   57,
   51,   52,   53,  239,  132,   58,  254,  255,  275,   35,
   35,   35,   73,   73,  280,    5,  162,   55,   56,   17,
   17,   73,    8,   11,   57,   35,   35,   35,   49,  212,
   58,   50,   35,   35,   51,   52,   53,  211,   34,   35,
   35,  218,   73,  276,   36,   95,   38,   39,   73,  277,
  224,   55,   56,   34,   73,   35,  241,   11,   57,   36,
  230,   38,   39,   34,   58,   35,  273,  231,  274,   36,
  242,   38,   39,  286,  243,  274,   40,   41,   34,  268,
   35,  256,   42,  250,   36,  278,   38,   39,   73,  279,
   96,   40,   41,  251,  252,  253,  187,   42,  188,  189,
   98,   40,   41,  113,  287,  113,  274,   42,  285,  113,
   73,  113,  113,   74,   75,  121,   40,   41,   18,    5,
   18,  288,   42,    6,  240,    7,    8,    9,   10,    5,
   97,   12,   18,    5,  192,    5,    5,    5,    5,   18,
  113,  113,  113,   73,  143,   19,   18,  113,   18,   73,
  166,  193,   77,   78,   18,   73,   16,   18,   77,   78,
   25,   11,  194,  195,  196,  197,  198,  199,  200,  201,
   73,    5,   43,   77,   78,   77,   78,   73,  114,  115,
   77,  147,  149,  203,  155,  156,  270,  261,
};
final static short yycheck[] = {                         19,
   20,  266,  266,  178,  135,  158,  135,  266,  259,  274,
  259,  275,  263,  277,  265,  266,  275,  266,  277,  150,
  258,  150,  275,  176,  177,  277,  266,   79,  181,  182,
  266,   51,   52,   53,   86,   87,  276,   57,   58,  214,
   92,  172,  266,  172,  309,  310,  260,  178,  312,  178,
  301,  258,  301,  312,   74,   75,  266,   77,   78,  312,
  312,   16,  215,  216,  300,  266,  241,   41,   88,  276,
  122,  266,   92,  266,  275,   30,  277,  266,   33,  258,
  304,  305,   56,  214,  259,  214,  106,  276,  275,  109,
  277,  143,  144,  260,  304,  305,  148,  276,  118,  151,
   55,   56,  154,  123,  258,  125,  260,  300,  128,  161,
  275,  312,  277,  260,  166,  167,  136,  137,  266,  266,
  274,  275,  276,  277,  144,  312,  146,  147,  266,   84,
  266,  183,  184,  185,   89,  260,  283,  257,  276,  259,
  258,  193,  282,  263,  264,  265,  266,  312,  282,  274,
  298,  299,  261,  307,  127,  128,  129,  266,  312,  211,
   36,  213,  266,  303,   40,   41,  218,  219,  220,  303,
  274,  260,  145,  260,  194,  295,  296,  266,  259,  266,
  260,  301,  202,  203,  261,  266,  206,  274,  240,  266,
  210,  211,  244,  245,  315,   71,  317,  278,  279,  280,
  281,  282,  254,  255,  260,  260,  258,  261,  260,  276,
  266,  266,  266,  294,  295,  296,  276,  259,  274,  271,
  301,  302,  274,  275,  266,  258,  266,  308,  280,  249,
  281,  282,  258,  253,  274,  260,  278,  279,  280,  281,
  266,  266,  259,  294,  258,  261,  275,    4,  277,  266,
  266,  259,  266,  295,  296,   12,   13,   14,  266,  301,
  302,  278,  279,  280,   21,   22,  308,   24,  281,  282,
  278,  279,  280,  258,  258,  261,  259,  294,  295,  296,
  266,  294,  266,  266,  301,  302,  294,  295,  296,  281,
  282,  308,  258,  301,  302,  278,  279,  280,  281,  258,
  308,  259,  294,    4,  261,  316,  317,  266,  266,  266,
  259,   12,  295,  296,  271,  272,  273,  266,  301,  302,
  278,  279,  280,  275,  282,  308,  260,  260,  263,  278,
  279,  280,  266,  266,  269,  259,  261,  295,  296,  309,
  310,  266,  266,  301,  302,  294,  295,  296,   21,  258,
  308,   24,  301,  302,  278,  279,  280,  261,  257,  308,
  259,  307,  266,  261,  263,  264,  265,  266,  266,  261,
  258,  295,  296,  257,  266,  259,  312,  301,  302,  263,
  258,  265,  266,  257,  308,  259,  275,  258,  277,  263,
  275,  265,  266,  275,  260,  277,  295,  296,  257,  311,
  259,  258,  301,  261,  263,  258,  265,  266,  266,  258,
  294,  295,  296,  271,  272,  273,  311,  301,  313,  314,
  294,  295,  296,  257,  275,  259,  277,  301,  260,  263,
  266,  265,  266,  269,  270,  294,  295,  296,  275,  259,
  277,  311,  301,  263,  277,  265,  266,  267,  268,  259,
  275,    0,  277,  263,  257,  265,  266,  267,  268,  258,
  294,  295,  296,  266,  261,  258,  307,  301,  276,  266,
  261,  274,  269,  270,  275,  266,  307,  260,  269,  270,
   14,  301,  285,  286,  287,  288,  289,  290,  291,  292,
  266,  301,  266,  269,  270,  269,  270,  266,   88,   88,
  269,  270,  134,  160,  135,  135,  259,  241,
};
final static short YYFINAL=3;
final static short YYMAXTOKEN=317;
final static String yyname[] = {
"end-of-file",null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,
null,null,null,"CDATA","TAG_END","PI","NAME","STRING","EQ","OPEN_TAG",
"CLOSE_TAG","EMPTY_TAG","WHITESPACE","DTD_START","DTD_START_SKIPEXTERNAL",
"SYSTEM","PUBLIC","REQUIRED","IMPLIED","FIXED","LPAREN","RPAREN","LBRACKET",
"PIPE","ENTITY_DECL_START","ATTLIST_START","NOTATION_START","RBRACKET_END",
"DOUBLE_RBRACKET_END","PERCENT","ENUMERATION","NOTATION","ID","IDREF","IDREFS",
"ENTITY","ENTITIES","NMTOKEN","NMTOKENS","ENTITY_REF","ENTITY_END",
"INTERNAL_ENTITY_REF","EXTERNAL_ENTITY_REF","SKIPPED_ENTITY_REF",
"PREFIXED_NAME","UNPREFIXED_NAME","NDATA","COMMENT","CONDITIONAL_START",
"IGNORED_CONDITIONAL_START","INCLUDE","IGNORE","MODIFIER","PCDATA",
"ELEMENT_DECL_START","EMPTY","ANY","STAR","COMMA","QUESTION","PLUS",
"XML_DOC_DECL","XML_TEXT_DECL","XML_DOC_OR_TEXT_DECL",
};
final static String yyrule[] = {
"$accept : document",
"document : xml_decl dtd body epilog",
"document : xml_decl body epilog",
"xml_decl : XML_DOC_DECL",
"xml_decl : XML_DOC_OR_TEXT_DECL",
"xml_decl :",
"xml_text_decl : XML_TEXT_DECL",
"xml_text_decl : XML_DOC_OR_TEXT_DECL",
"body : EMPTY_TAG",
"body : OPEN_TAG content CLOSE_TAG",
"body : misc body",
"epilog : misc epilog",
"epilog :",
"misc : WHITESPACE",
"misc : PI",
"misc : COMMENT",
"ws : WHITESPACE",
"ws : ws WHITESPACE",
"opt_ws :",
"opt_ws : ws",
"dtd : DTD_START NAME opt_ws TAG_END",
"dtd : dtd_only_internal_start dtd_content RBRACKET_END",
"dtd : dtd_with_external xml_text_decl dtd_content ENTITY_END",
"dtd : dtd_with_external dtd_content ENTITY_END",
"dtd : DTD_START_SKIPEXTERNAL NAME ws external_id opt_ws TAG_END",
"dtd : misc dtd",
"dtd_with_external : dtd_with_external_start TAG_END",
"dtd_with_external : dtd_with_external_start LBRACKET dtd_content RBRACKET_END",
"dtd_with_external_start : DTD_START NAME ws SYSTEM ws STRING opt_ws",
"dtd_with_external_start : DTD_START NAME ws PUBLIC ws STRING ws STRING opt_ws",
"dtd_only_internal_start : DTD_START NAME LBRACKET",
"dtd_only_internal_start : DTD_START_SKIPEXTERNAL NAME LBRACKET",
"dtd_only_internal_start : DTD_START_SKIPEXTERNAL NAME ws external_id LBRACKET",
"external_id : SYSTEM ws STRING",
"external_id : PUBLIC ws STRING ws STRING",
"dtd_content :",
"dtd_content : dtd_content dtd_conditional",
"dtd_content : dtd_content dtd_entity",
"dtd_content : dtd_content dtd_attlist",
"dtd_content : dtd_content dtd_notation",
"dtd_content : dtd_content misc",
"dtd_content : dtd_content dtd_element",
"dtd_content : dtd_content INTERNAL_ENTITY_REF dtd_content",
"dtd_content : dtd_content EXTERNAL_ENTITY_REF dtd_content",
"dtd_content : dtd_content EXTERNAL_ENTITY_REF xml_text_decl dtd_content",
"dtd_conditional : CONDITIONAL_START dtd_include dtd_content DOUBLE_RBRACKET_END",
"dtd_conditional : CONDITIONAL_START dtd_ignore ignored_dtd_content DOUBLE_RBRACKET_END",
"dtd_include : INCLUDE opt_ws LBRACKET",
"dtd_include : ws dtd_include",
"dtd_ignore : IGNORE opt_ws LBRACKET",
"dtd_ignore : ws dtd_ignore",
"ignored_dtd_content :",
"ignored_dtd_content : ignored_dtd_content IGNORED_CONDITIONAL_START ignored_dtd_content DOUBLE_RBRACKET_END",
"dtd_entity : ENTITY_DECL_START ws NAME ws STRING opt_ws TAG_END",
"dtd_entity : ENTITY_DECL_START ws NAME ws external_id opt_ws TAG_END",
"dtd_entity : ENTITY_DECL_START ws NAME ws external_id ws NDATA ws NAME opt_ws TAG_END",
"dtd_entity : ENTITY_DECL_START ws PERCENT NAME ws STRING opt_ws TAG_END",
"dtd_entity : ENTITY_DECL_START ws PERCENT NAME ws external_id opt_ws TAG_END",
"dtd_entity : ENTITY_DECL_START ws PERCENT NAME external_id ws NDATA ws NAME opt_ws TAG_END",
"dtd_notation : NOTATION_START ws NAME ws external_id opt_ws TAG_END",
"dtd_notation : NOTATION_START ws NAME ws PUBLIC ws STRING opt_ws TAG_END",
"dtd_attlist : attlist_start att_def_list opt_ws TAG_END",
"attlist_start : ATTLIST_START ws NAME",
"att_def_list :",
"att_def_list : att_def_list ws att_def",
"att_def : PREFIXED_NAME ws att_type ws REQUIRED",
"att_def : UNPREFIXED_NAME ws att_type ws REQUIRED",
"att_def : PREFIXED_NAME ws att_type ws IMPLIED",
"att_def : UNPREFIXED_NAME ws att_type ws IMPLIED",
"att_def : PREFIXED_NAME ws att_type ws FIXED ws STRING",
"att_def : UNPREFIXED_NAME ws att_type ws FIXED ws STRING",
"att_def : PREFIXED_NAME ws att_type ws STRING",
"att_def : UNPREFIXED_NAME ws att_type ws STRING",
"att_type : CDATA",
"att_type : ID",
"att_type : IDREF",
"att_type : IDREFS",
"att_type : ENTITY",
"att_type : ENTITIES",
"att_type : NMTOKEN",
"att_type : NMTOKENS",
"att_type : LPAREN opt_ws word_list opt_ws RPAREN",
"att_type : NOTATION ws LPAREN opt_ws word_list opt_ws RPAREN",
"word_list : NAME",
"word_list : word_list opt_ws PIPE opt_ws NAME",
"dtd_element : ELEMENT_DECL_START ws NAME ws element_spec opt_ws TAG_END",
"element_spec : EMPTY",
"element_spec : ANY",
"element_spec : element_spec_mixed",
"element_spec : element_spec_children",
"element_spec_mixed : LPAREN opt_ws PCDATA opt_ws RPAREN STAR",
"element_spec_mixed : LPAREN opt_ws PCDATA opt_ws RPAREN",
"element_spec_mixed : LPAREN opt_ws PCDATA opt_ws PIPE opt_ws word_list opt_ws RPAREN STAR",
"element_spec_mixed : WHITESPACE element_spec_mixed",
"element_spec_children : element_choice element_modifier",
"element_spec_children : element_seq element_modifier",
"element_spec_children : WHITESPACE element_spec_children",
"element_cp_pipe_list : element_cp opt_ws PIPE opt_ws element_cp",
"element_cp_pipe_list : element_cp opt_ws PIPE opt_ws element_cp_pipe_list",
"element_cp_comma_list : element_cp",
"element_cp_comma_list : element_cp opt_ws COMMA element_cp_comma_list",
"element_cp : NAME element_modifier opt_ws",
"element_cp : element_choice element_modifier opt_ws",
"element_cp : element_seq element_modifier opt_ws",
"element_cp : WHITESPACE element_cp",
"element_choice : LPAREN element_cp_pipe_list opt_ws RPAREN",
"element_choice : WHITESPACE element_choice",
"element_seq : LPAREN element_cp_comma_list opt_ws RPAREN",
"element_seq : WHITESPACE element_seq",
"element_modifier : QUESTION",
"element_modifier : STAR",
"element_modifier : PLUS",
"element_modifier :",
"content :",
"content : content INTERNAL_ENTITY_REF content ENTITY_END",
"content : content EXTERNAL_ENTITY_REF content ENTITY_END",
"content : content EXTERNAL_ENTITY_REF xml_text_decl content ENTITY_END",
"content : content OPEN_TAG content CLOSE_TAG",
"content : content EMPTY_TAG",
"content : content PI",
"content : content COMMENT",
"content : content WHITESPACE",
"content : content CDATA",
};

//#line 556 "Piccolo.y"

DocumentHandler documentHandler = null;
DTDHandler dtdHandler = null;
ErrorHandler errorHandler = null;
ContentHandler contentHandler = null;
int saxVersion = 0;
int attributeType=-1;
StringBuffer modelBuffer = new StringBuffer(100);
ElementDefinition elementDefinition=null;
String pubID=null,sysID=null;
String dtdName=null,dtdPubID=null,dtdSysID=null;
PiccoloLexer lexer = new PiccoloLexer(this);
DocumentEntity docEntity = new DocumentEntity();
LexicalHandler lexHandler = null;
DeclHandler declHandler = null;
boolean parsingInProgress = false;

/// Create an instance of the Piccolo parser
public Piccolo() { }

/**
 * Create an instance with the same configuration
 * as the given instance. ContentHandler, DTDHandler, etc.
 * will not be copied.
 */
public Piccolo(Piccolo template) {
    fNamespaces = template.fNamespaces;
    fNamespacePrefixes = template.fNamespacePrefixes;
    fExternalGeneralEntities = template.fExternalGeneralEntities;
    fExternalParameterEntities = template.fExternalParameterEntities;
    fLexicalParameterEntities = template.fLexicalParameterEntities;
    lexer.enableNamespaces(fNamespaces);
    fResolveDTDURIs = template.fResolveDTDURIs;
}

private void reset() {
    modelBuffer.setLength(0);
    pubID = sysID = dtdName = dtdPubID = dtdSysID = null;
    elementDefinition = null;
}

// Make sure it's okay to start parsing
private void validateParseState() throws SAXException {
    if (!fNamespaces && !fNamespacePrefixes) {
        throw new FatalParsingException("The 'namespaces' and 'namespace-prefixes' features must not both be false");
    }
}
public void setDebug(boolean debug) {
    yydebug = debug;
}


/************************************************************************
 * Methods common to both SAX1 and SAX2
 ************************************************************************/

public void parse(InputSource source) throws IOException, SAXException {
    try {
        reset();
        validateParseState();
        try {
            docEntity.reset(source);
            lexer.reset(docEntity);
        }
        finally {
            reportStartDocument();
        }
        yyparse();
    }
    catch (IllegalCharException e) {
        reportFatalError(e.getMessage(),e);
    }
    catch (FileFormatException e) {
        reportFatalError(e.getMessage(),e);
    }
    catch (FatalParsingException e) {
        reportFatalError(e.getMessage(),e.getException());
    }
    finally {
        reportEndDocument();
    }
}



public void parse(String sysID) throws IOException, SAXException {
    try {
        reset();
        validateParseState();
        try {
            docEntity.reset(sysID);
            lexer.reset(docEntity);
        }
        finally {
            reportStartDocument();
        }
        yyparse();
    }
    catch (IllegalCharException e) {
        reportFatalError(e.getMessage(),e);
    }
    catch (FileFormatException e) {
        reportFatalError(e.getMessage(),e);
    }
    catch (FatalParsingException e) {
        reportFatalError(e.getMessage(),e.getException());
    }
    finally {
        reportEndDocument();
    }
}


/************************************************************************
 * SAX1 methods
 ************************************************************************/

public void setDocumentHandler(DocumentHandler handler) {
    documentHandler = handler;
    if (documentHandler != null) {
      saxVersion = 1;
      fNamespaces = false;
      lexer.enableNamespaces(false);
      fNamespacePrefixes = true;
      documentHandler.setDocumentLocator(this);
    }
    else
      saxVersion = 0;
}


public void setDTDHandler(DTDHandler handler) {
    dtdHandler = handler;
}

public void setEntityResolver(EntityResolver resolver) {
    lexer.entityManager.setResolver(resolver);
}

public void setErrorHandler(ErrorHandler handler) {
    errorHandler = handler;
}

public void setLocale(java.util.Locale locale) 
throws SAXException {
    if (!("en".equals(locale.getLanguage())))
        throw new SAXException("Only English (EN) locales are supported");
}

// Locator
public int getColumnNumber() { return lexer.getColumnNumber(); }
public int getLineNumber() { return lexer.getLineNumber(); }
public String getPublicId() { return lexer.getPublicID(); }
public String getSystemId() { return lexer.getSystemID(); }

// Locator which returns line/col info for the start of the token
private class StartLocator implements org.xml.sax.Locator
{
    public int getLineNumber ( ) { return Piccolo.this.lexer.tokenStartLine; }
    public int getColumnNumber ( ) { return -1; }
    public String getPublicId ( ) { return null; }
    public String getSystemId ( ) { return null; }
}

private StartLocator startLocator;

public Locator getStartLocator ( )
{
    if (startLocator == null)
        startLocator = new StartLocator();

    return startLocator;
}

public String getVersion ( )
{
    return lexer.getVersion();
}

public String getEncoding ( )
{
    return lexer.getEncoding();
}

/************************************************************************
 * SAX2 methods
 ************************************************************************/

public ContentHandler getContentHandler() { return contentHandler; }

public void setContentHandler(ContentHandler handler) {
    contentHandler = handler;

    if (contentHandler != null) {
      // Are we switching from SAX1? If so, turn namespace processing on
      if (saxVersion == 1) {
          fNamespaces = true;
          lexer.enableNamespaces(true);
          fNamespacePrefixes = false;
      }

      saxVersion = 2;
      contentHandler.setDocumentLocator(this);
    }
    else
        saxVersion = 0;
}

public DTDHandler getDTDHandler() { return dtdHandler; }
public EntityResolver getEntityResolver() { return lexer.entityManager.getResolver(); }
public ErrorHandler getErrorHandler() { return errorHandler; }


// SAX2 Features
boolean fNamespaces=true,fNamespacePrefixes=false,fResolveDTDURIs=true;
boolean fExternalGeneralEntities=true,fExternalParameterEntities=true;
boolean fLexicalParameterEntities = true;

public boolean getFeature(String name)
    throws SAXNotSupportedException,SAXNotRecognizedException {
    if (name.equals("http://xml.org/sax/features/namespaces"))
        return fNamespaces;
    else if (name.equals("http://xml.org/sax/features/namespace-prefixes"))
        return fNamespacePrefixes;
    else if (name.equals("http://xml.org/sax/features/external-general-entities"))
        return fExternalGeneralEntities;
    else if (name.equals("http://xml.org/sax/features/external-parameter-entities"))
        return fExternalGeneralEntities;
    else if (name.equals("http://xml.org/sax/features/lexical-handler/parameter-entities"))
        return fLexicalParameterEntities;
    else if (name.equals("http://xml.org/sax/features/string-interning"))
        return true;
    else if (name.equals("http://xml.org/sax/features/is-standalone"))
        return docEntity.isStandalone();
    else if (name.equals("http://xml.org/sax/features/resolve-dtd-uris"))
        return fResolveDTDURIs;
    else if (name.equals("http://xml.org/sax/features/use-attributes2")
          || name.equals("http://xml.org/sax/features/validation")
          || name.equals("http://xml.org/sax/features/use-locator2")
          || name.equals("http://xml.org/sax/features/use-entity2")
          || name.equals("http://xml.org/sax/features/use-locator2"))
          return false;
    else
        throw new SAXNotRecognizedException(name);
}

public void setFeature(String name, boolean value)
throws SAXNotSupportedException,SAXNotRecognizedException {
    if (name.equals("http://xml.org/sax/features/namespaces")) {
        if (parsingInProgress) {
            throw new SAXNotSupportedException("Can't change namespace settings while parsing");
        }
        fNamespaces = value;
        lexer.enableNamespaces(value);
    }
    else if (name.equals("http://xml.org/sax/features/namespace-prefixes")) {
        if (parsingInProgress) {
            throw new SAXNotSupportedException("Can't change namespace settings while parsing");
        }
        fNamespacePrefixes = value;
    }
    else if (name.equals("http://xml.org/sax/features/external-general-entities")) {
        fExternalGeneralEntities = value;
    }
    else if (name.equals("http://xml.org/sax/features/external-parameter-entities")) {
        fExternalParameterEntities = value;
    }
    else if (name.equals("http://xml.org/sax/features/lexical-handler/parameter-entities")) {
        fLexicalParameterEntities = value;
    }
    else if (name.equals("http://xml.org/sax/features/resolve-dtd-uris")) {
        fResolveDTDURIs = value;
    }
    else if (name.equals("http://xml.org/sax/features/validation")) {
        if (value)
            throw new SAXNotSupportedException("validation is not supported");
    }
    else if (name.equals("http://xml.org/sax/features/string-interning")) {
        if (!value)
            throw new SAXNotSupportedException("strings are always internalized");
    }
    else if (name.equals("http://xml.org/sax/features/use-attributes2")
          || name.equals("http://xml.org/sax/features/validation")
          || name.equals("http://xml.org/sax/features/use-locator2")
          || name.equals("http://xml.org/sax/features/use-entity2")
          || name.equals("http://xml.org/sax/features/use-locator2")) {
        if (value)
            throw new SAXNotSupportedException(name);
    }
    else
        throw new SAXNotRecognizedException(name);
}

public Object getProperty(String name)
throws SAXNotRecognizedException, SAXNotSupportedException {
    if (name.equals("http://xml.org/sax/properties/declaration-handler"))
        return declHandler;
    else
    if (name.equals("http://xml.org/sax/properties/lexical-handler"))
        return lexHandler;
    else
        throw new SAXNotRecognizedException(name);
}

public void setProperty(String name,Object value)
throws SAXNotRecognizedException, SAXNotSupportedException {
    if (name.equals("http://xml.org/sax/properties/declaration-handler")) {
        try {
            declHandler = (DeclHandler) value;
        }
        catch (ClassCastException e) {
            throw new SAXNotSupportedException("property value is not a DeclHandler");
        }
    }
    else
    if (name.equals("http://xml.org/sax/properties/lexical-handler")) {
        try {
            lexHandler = (LexicalHandler) value;
        }
        catch (ClassCastException e) {
            throw new SAXNotSupportedException("property value is not a LexicalHandler");
        }
    }
    else
        throw new SAXNotRecognizedException(name);
}


/************************************************************************
 * Methods used to call ContentHandlers or DocumentHandlers
 ************************************************************************/

void reportCdata() throws SAXException {
    reportCdata(lexer.cdataBuffer,lexer.cdataStart,lexer.cdataLength);
}

private char[] oneCharBuffer = new char[1];
void reportCdata(char c) throws SAXException {
    oneCharBuffer[0] = c;
    reportCdata(oneCharBuffer,0,1);
}

void reportCdata(char[] buf, int off, int len) throws SAXException {
    switch (saxVersion) {
        case 2:
            contentHandler.characters(buf,off,len);
            break;
        case 1:
            documentHandler.characters(buf,off,len);
            break;
    }
}


void reportWhitespace() throws SAXException {
    reportWhitespace(lexer.cdataBuffer,lexer.cdataStart,lexer.cdataLength);
}

void reportWhitespace(char[] buf, int off, int len)  throws SAXException {
    switch (saxVersion) {
      case 2:
        contentHandler.characters(buf,off,len);
        break;
      case 1:
        documentHandler.characters(buf,off,len);
        break;
    }
}


void reportError(String msg)  throws SAXException {
    if (errorHandler != null) {
      errorHandler.error(new SAXParseException(msg,getPublicId(),getSystemId(),getLineNumber(),getColumnNumber()));
    }
}


void reportFatalError(String msg)  throws SAXException {
  reportFatalError(msg,null);
}

void reportFatalError(String msg, Exception e)  throws SAXException {
  if (e != null) {
    StringWriter stackTrace = new StringWriter();
    e.printStackTrace(new PrintWriter(stackTrace));
    if (msg != null)
        msg += "\n" + stackTrace.toString();
    else
        msg = stackTrace.toString();
  }

  SAXParseException spe = 
       new SAXParseException(msg,getPublicId(),
                    getSystemId(),getLineNumber(),getColumnNumber(),e);

  if (errorHandler != null)
        errorHandler.fatalError(spe);
  else
        throw spe;
}


void reportSkippedEntity(String entity)  throws SAXException {
    if (saxVersion == 2) {
      contentHandler.skippedEntity(entity);
    }
}


void reportPI(String entity, String data)  throws SAXException {
    switch (saxVersion) {
        case 2:
            contentHandler.processingInstruction(entity,data);
            break;
        case 1:
            documentHandler.processingInstruction(entity,data);
            break;
    }
}

void reportUnparsedEntityDecl(String entity, String pubID, String sysID, String notation)  throws SAXException {
    if (dtdHandler != null) {
      dtdHandler.unparsedEntityDecl(entity,pubID,resolveSystemID(sysID),notation);
    }
}

void reportNotationDecl(String name, String pubID, String sysID)  throws SAXException {
    if (dtdHandler != null)
        dtdHandler.notationDecl(name,pubID,resolveSystemID(sysID));
}


void reportStartTag(String ns, String entity, String qEntity)  throws SAXException {
    switch (saxVersion) {
      case 2:
        contentHandler.startElement(ns,entity,qEntity,lexer.attribs);
        break;
      case 1:
        documentHandler.startElement(qEntity,lexer.attribs);
        break;
    }
}


void reportEndTag(String ns, String entity, String qEntity)  throws SAXException {
    switch (saxVersion) {
      case 2:
        contentHandler.endElement(ns,entity,qEntity);
        break;
      case 1:
        documentHandler.endElement(qEntity);
        break;
    }
}


void reportStartPrefixMapping(String prefix, String uri)  throws SAXException {
    if (saxVersion == 2) {
        contentHandler.startPrefixMapping(prefix,uri);
    }
}

void reportEndPrefixMapping(String prefix)  throws SAXException {
    if (saxVersion == 2) {
        contentHandler.endPrefixMapping(prefix);
    }
}



void reportStartDocument()  throws SAXException {
    parsingInProgress = true;
    switch (saxVersion) {
      case 2:
        contentHandler.startDocument();
        break;
      case 1:
        documentHandler.startDocument();
        break;
    }
}

void reportEndDocument()  throws SAXException {
    parsingInProgress = false;
    switch (saxVersion) {
      case 2:
        contentHandler.endDocument();
        break;
      case 1:
        documentHandler.endDocument();
        break;
    }
}

/************************************************************************
 * Methods used for SAX 2 extensions
 ************************************************************************/

// *** LexicalHandler ***

void reportStartDTD(String name, String pubID, String sysID)
throws SAXException {
    if (lexHandler != null)
        lexHandler.startDTD(name,pubID,sysID);
}

void reportEndDTD()
throws SAXException {
    if (lexHandler != null)
        lexHandler.endDTD();
}

void reportStartEntity(String name)
throws SAXException {
    if (lexHandler != null) {
        if (fLexicalParameterEntities || name.charAt(0) != '%')
            lexHandler.startEntity(name);
    }
}

void reportEndEntity(String name)
throws SAXException {
    if (lexHandler != null) {
        if (fLexicalParameterEntities || name.charAt(0) != '%')
            lexHandler.endEntity(name);
    }
}

void reportStartCdata()
throws SAXException {
    if (lexHandler != null)
        lexHandler.startCDATA();
}

void reportEndCdata()
throws SAXException {
    if (lexHandler != null)
        lexHandler.endCDATA();
}

void reportComment(char[] ch, int start, int length)
throws SAXException {
    if (lexHandler != null)
        lexHandler.comment(ch,start,length);
}


/************************************************************************
 * Miscellaneous methods used internally
 ************************************************************************/

private void addAttributeDefinition(String qName, int valueType, int defaultType, String defaultValue)
throws SAXException, IOException {
    String prefix="", localName="";
    if (fNamespaces) {
        localName = qName;
        if (qName == "xmlns" && defaultValue != null) // Internalize all URIs
            defaultValue.intern();
    }

    saveAttributeDefinition(prefix,localName,qName,valueType,defaultType,defaultValue);
}

private void addPrefixedAttributeDefinition(String qName, int valueType, int defaultType, String defaultValue)
throws SAXException, IOException {
    String prefix, localName;
    if (fNamespaces) {
        int colon = qName.indexOf(':');
        int len = qName.length();
        qName.getChars(0,len,lexer.cbuf,0);
        prefix = lexer.stringConverter.convert(lexer.cbuf,0,colon);
        localName = lexer.stringConverter.convert(lexer.cbuf,colon+1,len-(colon+1));
    }
    else {
        prefix=localName="";
    }

    saveAttributeDefinition(prefix,localName,qName,valueType,defaultType,defaultValue);
}

private void saveAttributeDefinition(String prefix,String localName,
                                     String qName, int valueType, int defaultType, String defaultValue)
throws SAXException, IOException {
    try {
        if (defaultValue != null) {
            if (valueType == AttributeDefinition.NMTOKEN || valueType == AttributeDefinition.NMTOKENS)
                defaultValue = lexer.normalizeValue(defaultValue);

            defaultValue = lexer.rescanAttributeValue(defaultValue);
        }

        if (declHandler != null) {
            String valueTypeString = null;
            if (valueType == AttributeDefinition.NOTATION) {
                modelBuffer.insert(0,"NOTATION (");
                modelBuffer.append(')');
                valueTypeString = modelBuffer.toString();
            }
            else
            if (valueType == AttributeDefinition.ENUMERATION) {
                modelBuffer.insert(0,'(');
                modelBuffer.append(')');
                valueTypeString = modelBuffer.toString();
            }
            else
                valueTypeString = AttributeDefinition.getValueTypeString(valueType);

            declHandler.attributeDecl(elementDefinition.getName(),qName,valueTypeString,
                                AttributeDefinition.getDefaultTypeString(defaultType),
                                defaultValue);

            modelBuffer.setLength(0);
        }


        elementDefinition.addAttribute(
            new AttributeDefinition(prefix,localName,qName,valueType,null,
                                    defaultType,defaultValue));
    }
    catch (DuplicateKeyException e) { // Attribute already exists; XML spec says ignore it
    }
}


private String resolveSystemID(String sysID) {
    String resolvedSysID;
    if (fResolveDTDURIs) {
        try {
            return EntityManager.resolveSystemID(docEntity.getSystemID(),sysID);
        }
        catch (MalformedURLException e) {
            return sysID;
        }
    }
    else 
        return sysID;
}



private int yylex() throws IOException, SAXException
{
    try {
     int tok = lexer.yylex();
     yylval = lexer.stringValue;
     lexer.stringValue = null;

    /* Uncomment for serious debugging
    if (yydebug) {
        if (tok == CDATA)
            System.out.println("Token: CDATA");
        else
            System.out.println("Token: " + yyname[tok] + " (" + yylval + ")");

        System.out.println("\tlexical state is now " + lexer.yystate() + ", line number " + getLineNumber() );
    }
    */

     return tok;
    }
    catch (IOException e) {
        while (lexer.currentEntity == null && lexer.entityStack.size() > 0) {
            lexer.currentEntity = (Entity) lexer.entityStack.pop();
            try {
                if (lexer.yymoreStreams())
                    lexer.yypopStream();
            }
            catch (IOException ie) {}
        }

        throw e;
    }
    catch (SAXException e) {
        while (lexer.currentEntity == null && lexer.entityStack.size() > 0) {
            lexer.currentEntity = (Entity) lexer.entityStack.pop();
            try {
                if (lexer.yymoreStreams())
                    lexer.yypopStream();
            }
            catch (IOException ie) {}
        }

        throw e;
    }


}


void yyerror(String msg) throws SAXException {
    // Check if this is because of an invalid entity reference
    if (yychar <= 0)
        throw new FatalParsingException("Unexpected end of file after " + yylval);
    else
        throw new FatalParsingException("Unexpected element: " + yyname[yychar]);
}








//#line 1300 "Piccolo.java"
//###############################################################
// method: yylexdebug : check lexer state
//###############################################################
void yylexdebug(int state,int ch)
{
String s=null;
  if (ch < 0) ch=0;
  if (ch <= YYMAXTOKEN) //check index bounds
     s = yyname[ch];    //now get it
  if (s==null)
    s = "illegal-symbol";
  debug("state "+state+", reading "+ch+" ("+s+")");
}





//The following are now global, to aid in error reporting
int yyn;       //next next thing to do
int yym;       //
int yystate;   //current parsing state from state table
String yys;    //current token string


//###############################################################
// method: yyparse : parse input and execute indicated items
//###############################################################
int yyparse()
throws SAXException, IOException
{
boolean doaction;
  init_stacks();
  yynerrs = 0;
  yyerrflag = 0;
  yychar = -1;          //impossible char forces a read
  yystate=0;            //initial state
  state_push(yystate);  //save it
  while (true) //until parsing is done, either correctly, or w/error
    {
    doaction=true;
    //if (yydebug) debug("loop"); 
    //#### NEXT ACTION (from reduction table)
    for (yyn=yydefred[yystate];yyn==0;yyn=yydefred[yystate])
      {
      //if (yydebug) debug("yyn:"+yyn+"  state:"+yystate+"  yychar:"+yychar);
      if (yychar < 0)      //we want a char?
        {
        yychar = yylex();  //get next token
        //if (yydebug) debug(" next yychar:"+yychar);
        //#### ERROR CHECK ####
        //if (yychar < 0)    //it it didn't work/error
        //  {
        //  yychar = 0;      //change it to default string (no -1!)
          //if (yydebug)
          //  yylexdebug(yystate,yychar);
        //  }
        }//yychar<0
      yyn = yysindex[yystate];  //get amount to shift by (shift index)
      if ((yyn != 0) && (yyn += yychar) >= 0 &&
          yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
        {
        //if (yydebug)
          //debug("state "+yystate+", shifting to state "+yytable[yyn]);
        //#### NEXT STATE ####
        yystate = yytable[yyn];//we are in a new state
        state_push(yystate);   //save it
        val_push(yylval);      //push our lval as the input for next rule
        yychar = -1;           //since we have 'eaten' a token, say we need another
        if (yyerrflag > 0)     //have we recovered an error?
           --yyerrflag;        //give ourselves credit
        doaction=false;        //but don't process yet
        break;   //quit the yyn=0 loop
        }

    yyn = yyrindex[yystate];  //reduce
    if ((yyn !=0 ) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
      {   //we reduced!
      //if (yydebug) debug("reduce");
      yyn = yytable[yyn];
      doaction=true; //get ready to execute
      break;         //drop down to actions
      }
    else //ERROR RECOVERY
      {
      if (yyerrflag==0)
        {
        yyerror("syntax error");
        yynerrs++;
        }
      if (yyerrflag < 3) //low error count?
        {
        yyerrflag = 3;
        while (true)   //do until break
          {
          yyn = yysindex[state_peek(0)];
          if ((yyn != 0) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
            //if (yydebug)
              //debug("state "+state_peek(0)+", error recovery shifting to state "+yytable[yyn]+" ");
            yystate = yytable[yyn];
            state_push(yystate);
            val_push(yylval);
            doaction=false;
            break;
            }
          else
            {
            //if (yydebug)
              //debug("error recovery discarding state "+state_peek(0)+" ");
            state_pop();
            val_pop();
            }
          }
        }
      else            //discard this token
        {
        if (yychar == 0)
          return 1; //yyabort
        //if (yydebug)
          //{
          //yys = null;
          //if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
          //if (yys == null) yys = "illegal-symbol";
          //debug("state "+yystate+", error recovery discards token "+yychar+" ("+yys+")");
          //}
        yychar = -1;  //read another
        }
      }//end error recovery
    }//yyn=0 loop
    if (!doaction)   //any reason not to proceed?
      continue;      //skip action
    yym = yylen[yyn];          //get count of terminals on rhs
    //if (yydebug)
      //debug("state "+yystate+", reducing "+yym+" by rule "+yyn+" ("+yyrule[yyn]+")");
    if (yym>0)                 //if count of rhs not 'nil'
      yyval = val_peek(yym-1); //get current semantic value
    switch(yyn)
      {
//########## USER-SUPPLIED ACTIONS ##########
case 20:
//#line 113 "Piccolo.y"
{
        dtdName = val_peek(2);
        lexer.yybegin(0);
        reportStartDTD(dtdName,null,null);
        reportEndDTD();
    }
break;
case 21:
//#line 119 "Piccolo.y"
{
        /* Internal subset only*/
        lexer.yybegin(0);
        reportEndDTD();
    }
break;
case 22:
//#line 124 "Piccolo.y"
{
        /* Internal+External or External only with an <?xml?> declaration*/
        lexer.yybegin(0);
        reportEndDTD();
    }
break;
case 23:
//#line 129 "Piccolo.y"
{
        /* Internal+External or External only with no <?xml?> declaration*/
        lexer.yybegin(0);
        reportEndDTD();
    }
break;
case 24:
//#line 134 "Piccolo.y"
{
        /* External subset with no internal subset. Skip external*/
        dtdName = val_peek(4);
        lexer.yybegin(0);
        reportStartDTD(dtdName,pubID,sysID);
        reportEndDTD();
    }
break;
case 26:
//#line 144 "Piccolo.y"
{
        /* External subset with no internal subset*/
        lexer.pushEntity("[dtd]",dtdPubID,dtdSysID,false,true);
        lexer.yybegin(lexer.DTD);
    }
break;
case 27:
//#line 150 "Piccolo.y"
{
        /* Both external and internal subsets. Internal comes first.*/
        lexer.pushEntity("[dtd]",dtdPubID,dtdSysID,false,true);
        lexer.yybegin(lexer.DTD);
    }
break;
case 28:
//#line 159 "Piccolo.y"
{
        dtdName = lexer.normalizeValue(val_peek(5));
        dtdPubID = null;
        dtdSysID = lexer.normalizeValue(val_peek(1));
        reportStartDTD(dtdName,dtdPubID,dtdSysID);
    }
break;
case 29:
//#line 166 "Piccolo.y"
{
        dtdName = val_peek(7);
        dtdPubID = lexer.normalizeValue(val_peek(3));
        dtdSysID = lexer.normalizeValue(val_peek(1));
        reportStartDTD(dtdName,dtdPubID,dtdSysID);
    }
break;
case 30:
//#line 175 "Piccolo.y"
{
        dtdName = val_peek(1);
        reportStartDTD(dtdName,null,null);
    }
break;
case 31:
//#line 179 "Piccolo.y"
{
        dtdName = val_peek(1);
        reportStartDTD(dtdName,null,null);
    }
break;
case 32:
//#line 183 "Piccolo.y"
{
        dtdName = val_peek(3);
        reportStartDTD(dtdName,pubID,sysID);
    }
break;
case 33:
//#line 190 "Piccolo.y"
{ pubID=null; sysID=lexer.normalizeValue(val_peek(0)); }
break;
case 34:
//#line 191 "Piccolo.y"
{
            pubID=lexer.normalizeValue(val_peek(2));
            sysID=lexer.normalizeValue(val_peek(0));
        }
break;
case 46:
//#line 211 "Piccolo.y"
{
        lexer.yybegin(lexer.DTD);
  }
break;
case 47:
//#line 217 "Piccolo.y"
{
    lexer.yybegin(lexer.DTD);
}
break;
case 49:
//#line 223 "Piccolo.y"
{
    lexer.yybegin(lexer.DTD_IGNORE);
}
break;
case 53:
//#line 236 "Piccolo.y"
{
        lexer.entityManager.putInternal(val_peek(4),val_peek(2),EntityManager.GENERAL);
        if (declHandler != null)
            declHandler.internalEntityDecl(val_peek(4),val_peek(2));
    }
break;
case 54:
//#line 241 "Piccolo.y"
{
        try {
            lexer.entityManager.putExternal(lexer.currentEntity,val_peek(4),pubID,sysID,EntityManager.GENERAL);
            if (declHandler != null)
                declHandler.externalEntityDecl(val_peek(4),pubID,resolveSystemID(sysID));
        }
        catch (MalformedURLException e) {
            reportFatalError("Invalid system identifier: "
                         + sysID + "; " + e.getMessage());
        }
    }
break;
case 55:
//#line 252 "Piccolo.y"
{
        try {
            lexer.entityManager.putUnparsed(lexer.currentEntity,val_peek(8),pubID,sysID,val_peek(2),EntityManager.GENERAL);
            reportUnparsedEntityDecl(val_peek(8),pubID,sysID,val_peek(2));

        }
        catch (MalformedURLException e) {
            reportFatalError("Invalid system identifier: "
                         + sysID + "; " + e.getMessage());
        }
    }
break;
case 56:
//#line 263 "Piccolo.y"
{
        lexer.entityManager.putInternal(val_peek(4),val_peek(2),EntityManager.PARAMETER);
        if (declHandler != null)
            declHandler.internalEntityDecl("%"+val_peek(4),val_peek(2));
    }
break;
case 57:
//#line 268 "Piccolo.y"
{
        try {
            lexer.entityManager.putExternal(lexer.currentEntity,val_peek(4),pubID,sysID,EntityManager.PARAMETER);
            if (declHandler != null)
                declHandler.externalEntityDecl("%"+val_peek(4),pubID,resolveSystemID(sysID));
        }
        catch (MalformedURLException e) {
            reportFatalError("Invalid system identifier: "
                         + sysID + "; " + e.getMessage());
        }
    }
break;
case 58:
//#line 279 "Piccolo.y"
{
        try {
            lexer.entityManager.putUnparsed(lexer.currentEntity,val_peek(7),pubID,sysID,val_peek(2),EntityManager.PARAMETER);
            reportUnparsedEntityDecl(val_peek(7),pubID,sysID,val_peek(2));

        }
        catch (MalformedURLException e) {
            reportFatalError("Invalid system identifier: "
                         + sysID + "; " + e.getMessage());
        }
    }
break;
case 59:
//#line 293 "Piccolo.y"
{
                reportNotationDecl(val_peek(4),pubID,sysID);
              }
break;
case 60:
//#line 296 "Piccolo.y"
{
                reportNotationDecl(val_peek(6),lexer.normalizeValue(val_peek(2)),null);
              }
break;
case 61:
//#line 302 "Piccolo.y"
{
	lexer.defineElement(elementDefinition.getName(),elementDefinition);
}
break;
case 62:
//#line 307 "Piccolo.y"
{
	/* Look up this element. If we've seen previous ATTLIST definitions for it, we'll add these to it.*/
	elementDefinition = lexer.getElement(val_peek(0));
	if (elementDefinition == null)
		elementDefinition = new ElementDefinition(val_peek(0));
}
break;
case 65:
//#line 321 "Piccolo.y"
{
        lexer.yybegin(lexer.DTD_ATT_NAME);
        addPrefixedAttributeDefinition(val_peek(4),attributeType,AttributeDefinition.REQUIRED,null);
    }
break;
case 66:
//#line 325 "Piccolo.y"
{
        lexer.yybegin(lexer.DTD_ATT_NAME);
        addAttributeDefinition(val_peek(4),attributeType,AttributeDefinition.REQUIRED,null);
    }
break;
case 67:
//#line 329 "Piccolo.y"
{
        lexer.yybegin(lexer.DTD_ATT_NAME);
        addPrefixedAttributeDefinition(val_peek(4),attributeType,AttributeDefinition.IMPLIED,null);
    }
break;
case 68:
//#line 333 "Piccolo.y"
{
        lexer.yybegin(lexer.DTD_ATT_NAME);
        addAttributeDefinition(val_peek(4),attributeType,AttributeDefinition.IMPLIED,null);
    }
break;
case 69:
//#line 337 "Piccolo.y"
{
        lexer.yybegin(lexer.DTD_ATT_NAME);
        addPrefixedAttributeDefinition(val_peek(6),attributeType,AttributeDefinition.FIXED,val_peek(0));
    }
break;
case 70:
//#line 341 "Piccolo.y"
{
        lexer.yybegin(lexer.DTD_ATT_NAME);
        addAttributeDefinition(val_peek(6),attributeType,AttributeDefinition.FIXED,val_peek(0));
    }
break;
case 71:
//#line 345 "Piccolo.y"
{
        lexer.yybegin(lexer.DTD_ATT_NAME);
        addPrefixedAttributeDefinition(val_peek(4),attributeType,0,val_peek(0));
    }
break;
case 72:
//#line 349 "Piccolo.y"
{
        lexer.yybegin(lexer.DTD_ATT_NAME);
        addAttributeDefinition(val_peek(4),attributeType,0,val_peek(0));
    }
break;
case 73:
//#line 356 "Piccolo.y"
{ attributeType = AttributeDefinition.CDATA; }
break;
case 74:
//#line 357 "Piccolo.y"
{ attributeType = AttributeDefinition.ID; }
break;
case 75:
//#line 358 "Piccolo.y"
{ attributeType = AttributeDefinition.IDREF; }
break;
case 76:
//#line 359 "Piccolo.y"
{ attributeType = AttributeDefinition.IDREFS; }
break;
case 77:
//#line 360 "Piccolo.y"
{ attributeType = AttributeDefinition.ENTITY; }
break;
case 78:
//#line 361 "Piccolo.y"
{ attributeType = AttributeDefinition.ENTITIES; }
break;
case 79:
//#line 362 "Piccolo.y"
{ attributeType = AttributeDefinition.NMTOKEN; }
break;
case 80:
//#line 363 "Piccolo.y"
{ attributeType = AttributeDefinition.NMTOKENS; }
break;
case 81:
//#line 364 "Piccolo.y"
{
                attributeType = AttributeDefinition.ENUMERATION;
          }
break;
case 82:
//#line 367 "Piccolo.y"
{
                attributeType = AttributeDefinition.NOTATION;
          }
break;
case 83:
//#line 373 "Piccolo.y"
{
        if (declHandler != null)
            modelBuffer.append(val_peek(0));
    }
break;
case 84:
//#line 377 "Piccolo.y"
{
        if (declHandler != null) {
            modelBuffer.append('|');
            modelBuffer.append(val_peek(0));
        }
    }
break;
case 85:
//#line 386 "Piccolo.y"
{
    if (declHandler != null)
        declHandler.elementDecl(val_peek(4),val_peek(2));
}
break;
case 86:
//#line 393 "Piccolo.y"
{
        if (declHandler != null)
            yyval = "EMPTY";
      }
break;
case 87:
//#line 397 "Piccolo.y"
{
        if (declHandler != null)
            yyval = "ANY";
    }
break;
case 88:
//#line 401 "Piccolo.y"
{
        if (declHandler != null)
            yyval = val_peek(0);
    }
break;
case 89:
//#line 405 "Piccolo.y"
{
        if (declHandler != null)
            yyval = val_peek(0);
    }
break;
case 90:
//#line 412 "Piccolo.y"
{
        if (declHandler != null)
            yyval = "(#PCDATA)*";
    }
break;
case 91:
//#line 416 "Piccolo.y"
{
        if (declHandler != null)
            yyval = "(#PCDATA)";
    }
break;
case 92:
//#line 420 "Piccolo.y"
{
        if (declHandler != null)
            yyval = "(#PCDATA|" + modelBuffer.toString() + ")*";
    }
break;
case 93:
//#line 424 "Piccolo.y"
{
        if (declHandler != null)
            yyval = val_peek(0);
    }
break;
case 94:
//#line 431 "Piccolo.y"
{
        if (declHandler != null)
            yyval = val_peek(1) + val_peek(0);
    }
break;
case 95:
//#line 435 "Piccolo.y"
{
        if (declHandler != null)
            yyval = val_peek(1) + val_peek(0);
    }
break;
case 96:
//#line 439 "Piccolo.y"
{
        if (declHandler != null)
            yyval = val_peek(0);
    }
break;
case 97:
//#line 446 "Piccolo.y"
{
        if (declHandler != null)
            yyval = val_peek(4) + "|" + val_peek(0);
    }
break;
case 98:
//#line 450 "Piccolo.y"
{
        if (declHandler != null)
            yyval = val_peek(4) + "|" + val_peek(0);
    }
break;
case 99:
//#line 457 "Piccolo.y"
{
        if (declHandler != null)
            yyval = val_peek(0);
    }
break;
case 100:
//#line 461 "Piccolo.y"
{
        if (declHandler != null)
            yyval = val_peek(3) + "," + val_peek(0);
    }
break;
case 101:
//#line 468 "Piccolo.y"
{
        if (declHandler != null)
            yyval = val_peek(2) + val_peek(1);
    }
break;
case 102:
//#line 472 "Piccolo.y"
{
        if (declHandler != null)
            yyval = val_peek(2) + val_peek(1);
    }
break;
case 103:
//#line 476 "Piccolo.y"
{
        if (declHandler != null)
            yyval = val_peek(2) + val_peek(1);
    }
break;
case 104:
//#line 480 "Piccolo.y"
{
        if (declHandler != null)
            yyval = val_peek(0);
    }
break;
case 105:
//#line 488 "Piccolo.y"
{
        if (declHandler != null)
            yyval = "(" + val_peek(2) + ")";
    }
break;
case 106:
//#line 492 "Piccolo.y"
{
        if (declHandler != null)
            yyval = val_peek(0);
    }
break;
case 107:
//#line 499 "Piccolo.y"
{
        if (declHandler != null)
            yyval = "(" + val_peek(2) + ")";
    }
break;
case 108:
//#line 503 "Piccolo.y"
{
        if (declHandler != null)
            yyval = val_peek(0);
    }
break;
case 109:
//#line 510 "Piccolo.y"
{
        if (declHandler != null)
            yyval = "?";
    }
break;
case 110:
//#line 514 "Piccolo.y"
{
        if (declHandler != null)
            yyval = "*";
    }
break;
case 111:
//#line 518 "Piccolo.y"
{
        if (declHandler != null)
            yyval = "+";
    }
break;
case 112:
//#line 522 "Piccolo.y"
{
        if (declHandler != null)
            yyval = "";
    }
break;
case 114:
//#line 532 "Piccolo.y"
{
                lexer.setTokenize(false);
          }
break;
case 115:
//#line 536 "Piccolo.y"
{
                lexer.setTokenize(false);
          }
break;
case 116:
//#line 540 "Piccolo.y"
{
                lexer.setTokenize(false);
          }
break;
case 121:
//#line 547 "Piccolo.y"
{
                reportWhitespace();
          }
break;
//#line 1999 "Piccolo.java"
//########## END OF USER-SUPPLIED ACTIONS ##########
    }//switch
    //#### Now let's reduce... ####
    //if (yydebug) debug("reduce");
    state_drop(yym);             //we just reduced yylen states
    yystate = state_peek(0);     //get new state
    val_drop(yym);               //corresponding value drop
    yym = yylhs[yyn];            //select next TERMINAL(on lhs)
    if (yystate == 0 && yym == 0)//done? 'rest' state and at first TERMINAL
      {
      //if (yydebug) debug("After reduction, shifting from state 0 to state "+YYFINAL+"");
      yystate = YYFINAL;         //explicitly say we're done
      state_push(YYFINAL);       //and save it
      val_push(yyval);           //also save the semantic value of parsing
      if (yychar < 0)            //we want another character?
        {
        yychar = yylex();        //get next character
        //if (yychar<0) yychar=0;  //clean, if necessary
        //if (yydebug)
          //yylexdebug(yystate,yychar);
        }
      if (yychar == 0)          //Good exit (if lex returns 0 ;-)
         break;                 //quit the loop--all DONE
      }//if yystate
    else                        //else not done yet
      {                         //get next state and push, for next yydefred[]
      yyn = yygindex[yym];      //find out where to go
      if ((yyn != 0) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn]; //get new state
      else
        yystate = yydgoto[yym]; //else go to new defred
      //if (yydebug) debug("after reduction, shifting from state "+state_peek(0)+" to state "+yystate+"");
      state_push(yystate);     //going again, so push state & val...
      val_push(yyval);         //for next action
      }
    }//main loop
  return 0;//yyaccept!!
}
//## end of method parse() ######################################



//## run() --- for Thread #######################################
//## The -Jnorun option was used ##
//## end of method run() ########################################



//## Constructors ###############################################
//## The -Jnoconstruct option was used ##
//###############################################################



}
//################### END OF CLASS ##############################
