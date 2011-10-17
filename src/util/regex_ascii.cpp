/*
 * Copyright 2006-2008 The FLWOR Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "stdafx.h"
#include <ctype.h>

#include "diagnostics/xquery_diagnostics.h"

#include "regex_ascii.h"
#include <string.h>
#include "zorbatypes/chartype.h"
#include "util/unicode_categories.h"
#include "util/ascii_util.h"

namespace zorba {
  namespace regex_ascii{
//ascii regular expression matching

/*http://www.w3.org/TR/xmlschema-2/#regexs

~regExp    ::=    branch ( '|' branch )*  
~branch    ::=    piece* 
~piece     ::=    atom quantifier? 
~quantifier    ::=    ( [?*+] | ( '{' quantity '}' ) ) '?'? 
~quantity    ::=    quantRange | quantMin | QuantExact 
~quantRange    ::=    QuantExact ',' QuantExact 
~quantMin    ::=    QuantExact ',' 
~QuantExact    ::=    [0-9]+ 
~atom    ::=    Char | charClass | ( '(' '?:'? regExp ')' ) | backReference
backReference ::= "\" [1-9][0-9]*
~Char    ::=    [^.\?*+{}()|^$#x5B#x5D] 
~charClass    ::=    charClassEsc | charClassExpr | WildcardEsc | "^" | "$"
~charClassExpr    ::=    '[' charGroup ']' 
~charGroup    ::=    posCharGroup | negCharGroup | charClassSub 
~posCharGroup    ::=    ( charRange | charClassEsc )+  
~negCharGroup    ::=    '^' posCharGroup 
~charClassSub    ::=    ( posCharGroup | negCharGroup ) '-' charClassExpr 
~charRange    ::=    seRange | XmlCharIncDash 
~seRange    ::=    charOrEsc '-' charOrEsc 
~charOrEsc    ::=    XmlChar | SingleCharEsc 
~XmlChar    ::=    [^\#x2D#x5B#x5D] 
~XmlCharIncDash    ::=    [^\#x5B#x5D] 
~charClassEsc    ::=    ( SingleCharEsc | MultiCharEsc | catEsc | complEsc )  
~SingleCharEsc    ::=    '\' [nrt\|.?*+(){}$#x2D#x5B#x5D#x5E]
~catEsc    ::=    '\p{' charProp '}' 
~complEsc    ::=    '\P{' charProp '}' 
charProp    ::=    IsCategory | IsBlock 
~MultiCharEsc    ::=    '\' [sSiIcCdDwW] 
~WildcardEsc    ::=    '.' 


+ http://www.w3.org/TR/xquery-operators/#regex-syntax (not implemented)
*/


static bool compare_i(const char *str1, const char *str2)
{
  while(*str1 && *str2)
  {
    if(ascii::to_lower(*str1) != ascii::to_lower(*str2))
      return false;
    str1++;
    str2++;
  }
  if(*str1 || *str2)
    return false;
  return true;
}
static bool compare_ni(const char *str1, const char *str2, unsigned int maxlen)
{
  while(*str1 && *str2 && maxlen)
  {
    if(ascii::to_lower(*str1) != ascii::to_lower(*str2))
      return false;
    str1++;
    str2++;
    maxlen--;
  }
  if(maxlen && (*str1 || *str2))
    return false;
  return true;
}
////////////////////////////////////
////Regular expression parsing and building of the tree
////////////////////////////////////

CRegexAscii_regex* CRegexAscii_parser::parse(const char *pattern, unsigned int flags)
{
  this->flags = flags;
  
  int   regex_len;
  CRegexAscii_regex*  regex = parse_regexp(pattern, &regex_len);
  
  return regex;
}

//until '\0' or ')'
CRegexAscii_regex* CRegexAscii_parser::parse_regexp(const char *pattern, 
                                                    int *regex_len)
{
  *regex_len = 0;
  int   branch_len;
  regex_depth++;
  std::auto_ptr<CRegexAscii_regex>  regex(new CRegexAscii_regex(current_regex));
  if(!current_regex)
    current_regex = regex.get();
  if(regex_depth >= 2)
  {
    //mark this as group if it does not start with ?:
    if(pattern[0] != '?' || pattern[1] != ':')
      current_regex->subregex.push_back(regex.get());
    else
      *regex_len = 2;
  }
  CRegexAscii_branch  *branch;
  bool must_read_another_branch = true;
  while(pattern[*regex_len] && (pattern[*regex_len] != ')'))
  {
    branch = parse_branch(pattern+*regex_len, &branch_len);
    if(!branch)
    {
      regex_depth--;
      return NULL;
    }
    regex->add_branch(branch);
    *regex_len += branch_len;
    if(pattern[*regex_len] == '|')
      (*regex_len)++;
    else
      must_read_another_branch = false;
  }
  if((current_regex == regex.get()) && (pattern[*regex_len] == ')'))
  {
    throw XQUERY_EXCEPTION( err::FORX0002, ERROR_PARAMS(pattern, ZED(REGEX_MISMATCHED_PAREN)) );
  }
  if(pattern[*regex_len])
    (*regex_len)++;
  if(must_read_another_branch)
    regex->add_branch(new CRegexAscii_branch(current_regex));//add empty branch
  regex->flags = 0;//finished initialization
  regex_depth--;
  return regex.release();
}

CRegexAscii_branch* CRegexAscii_parser::parse_branch(const char *pattern, int *branch_len)
{
  int piece_len;

  std::auto_ptr<CRegexAscii_branch>    branch(new CRegexAscii_branch(current_regex));
  CRegexAscii_piece     *piece;
  *branch_len = 0;
  while(pattern[*branch_len] && (pattern[*branch_len] != '|') && (pattern[*branch_len] != ')'))
  {
    piece = parse_piece(pattern+*branch_len, &piece_len);
    if(!piece)
    {
      return NULL;
    }
    if(branch->piece_list.size() && dynamic_cast<CRegexAscii_pinstart*>(piece->atom))
    {
      //found ^ that is not at the beginning of branch
      throw XQUERY_EXCEPTION( err::FORX0002, ERROR_PARAMS(pattern, ZED(REGEX_INVALID_ATOM_CHAR), '^') );
    }
    branch->add_piece(piece);
    *branch_len += piece_len;
  }
  //if(pattern[*branch_len] == '|')
  //  (*branch_len)++;
  return branch.release();
}

//piece = atom + quantifier
CRegexAscii_piece* CRegexAscii_parser::parse_piece(const char *pattern, int *piece_len)
{
  std::auto_ptr<CRegexAscii_piece>  piece(new CRegexAscii_piece);
  IRegexAtom  *atom;
  *piece_len = 0;

  int   atom_len = 0;
  int   quantif_len = 0;
  atom = read_atom(pattern, &atom_len);
  if(!atom)
  {
    return NULL;
  }
  piece->set_atom(atom);
  if(!(flags & REGEX_ASCII_LITERAL))
    read_quantifier(piece.get(), pattern+atom_len, &quantif_len);

  *piece_len += atom_len + quantif_len;

  return piece.release();
}

char CRegexAscii_parser::myishex(char c)
{
  if((c >= '0') && (c <= '9'))
    return c-'0'+1;
  else if((c >= 'a') && (c <= 'f'))
    return c-'a'+10+1;
  else if((c >= 'A') && (c <= 'F'))
    return c-'a'+10+1;
  return 0;//not a hex
}

bool CRegexAscii_parser::myisdigit(char c)
{
  return (c >= '0') && (c <= '9');
}

bool CRegexAscii_parser::myisletterAZ(char c)
{
  return ((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z'));
}

static const unicode::code_point specials_extcp[] = {0xFFF0, 0xFFFD, 0};

static CRegexAscii_parser::block_escape_t block_escape[] = 
{
{{0x0000, 0x007F}, NULL, "BasicLatin"},
{{0x0080, 0x00FF}, NULL, "Latin-1Supplement"},
{{0x0100, 0x017F}, NULL, "LatinExtended-A"},
{{0x0180, 0x024F}, NULL, "LatinExtended-B"},
{{0x0250, 0x02AF}, NULL, "IPAExtensions"},
{{0x02B0, 0x02FF}, NULL, "SpacingModifierLetters"},
{{0x0300, 0x036F}, NULL, "CombiningDiacriticalMarks"},
{{0x0370, 0x03FF}, NULL, "Greek"},
{{0x0400, 0x04FF}, NULL, "Cyrillic"},
{{0x0530, 0x058F}, NULL, "Armenian"},
{{0x0590, 0x05FF}, NULL, "Hebrew"},
{{0x0600, 0x06FF}, NULL, "Arabic"},
{{0x0700, 0x074F}, NULL, "Syriac"},
{{0x0780, 0x07BF}, NULL, "Thaana"},
{{0x0900, 0x097F}, NULL, "Devanagari"},
{{0x0980, 0x09FF}, NULL, "Bengali"},
{{0x0A00, 0x0A7F}, NULL, "Gurmukhi"},
{{0x0A80, 0x0AFF}, NULL, "Gujarati"},
{{0x0B00, 0x0B7F}, NULL, "Oriya"},
{{0x0B80, 0x0BFF}, NULL, "Tamil"},
{{0x0C00, 0x0C7F}, NULL, "Telugu"},
{{0x0C80, 0x0CFF}, NULL, "Kannada"},
{{0x0D00, 0x0D7F}, NULL, "Malayalam"},
{{0x0D80, 0x0DFF}, NULL, "Sinhala"},
{{0x0E00, 0x0E7F}, NULL, "Thai"},
{{0x0E80, 0x0EFF}, NULL, "Lao"},
{{0x0F00, 0x0FFF}, NULL, "Tibetan"},
{{0x1000, 0x109F}, NULL, "Myanmar"},
{{0x10A0, 0x10FF}, NULL, "Georgian"},
{{0x1100, 0x11FF}, NULL, "HangulJamo"},
{{0x1200, 0x137F}, NULL, "Ethiopic"},
{{0x13A0, 0x13FF}, NULL, "Cherokee"},
{{0x1400, 0x167F}, NULL, "UnifiedCanadianAboriginalSyllabics"},
{{0x1680, 0x169F}, NULL, "Ogham"},
{{0x16A0, 0x16FF}, NULL, "Runic"},
{{0x1780, 0x17FF}, NULL, "Khmer"},
{{0x1800, 0x18AF}, NULL, "Mongolian"},
{{0x1E00, 0x1EFF}, NULL, "LatinExtendedAdditional"},
{{0x1F00, 0x1FFF}, NULL, "GreekExtended"},
{{0x2000, 0x206F}, NULL, "GeneralPunctuation"},
{{0x2070, 0x209F}, NULL, "SuperscriptsandSubscripts"},
{{0x20A0, 0x20CF}, NULL, "CurrencySymbols"},
{{0x20D0, 0x20FF}, NULL, "CombiningMarksforSymbols"},
{{0x2100, 0x214F}, NULL, "LetterlikeSymbols"},
{{0x2150, 0x218F}, NULL, "NumberForms"},
{{0x2190, 0x21FF}, NULL, "Arrows"},
{{0x2200, 0x22FF}, NULL, "MathematicalOperators"},
{{0x2300, 0x23FF}, NULL, "MiscellaneousTechnical"},
{{0x2400, 0x243F}, NULL, "ControlPictures"},
{{0x2440, 0x245F}, NULL, "OpticalCharacterRecognition"},
{{0x2460, 0x24FF}, NULL, "EnclosedAlphanumerics"},
{{0x2500, 0x257F}, NULL, "BoxDrawing"},
{{0x2580, 0x259F}, NULL, "BlockElements"},
{{0x25A0, 0x25FF}, NULL, "GeometricShapes"},
{{0x2600, 0x26FF}, NULL, "MiscellaneousSymbols"},
{{0x2700, 0x27BF}, NULL, "Dingbats"},
{{0x2800, 0x28FF}, NULL, "BraillePatterns"},
{{0x2E80, 0x2EFF}, NULL, "CJKRadicalsSupplement"},
{{0x2F00, 0x2FDF}, NULL, "KangxiRadicals"},
{{0x2FF0, 0x2FFF}, NULL, "IdeographicDescriptionCharacters"},
{{0x3000, 0x303F}, NULL, "CJKSymbolsandPunctuation"},
{{0x3040, 0x309F}, NULL, "Hiragana"},
{{0x30A0, 0x30FF}, NULL, "Katakana"},
{{0x3100, 0x312F}, NULL, "Bopomofo"},
{{0x3130, 0x318F}, NULL, "HangulCompatibilityJamo"},
{{0x3190, 0x319F}, NULL, "Kanbun"},
{{0x31A0, 0x31BF}, NULL, "BopomofoExtended"},
{{0x3200, 0x32FF}, NULL, "EnclosedCJKLettersandMonths"},
{{0x3300, 0x33FF}, NULL, "CJKCompatibility"},
{{0x3400, 0x4DB5}, NULL, "CJKUnifiedIdeographsExtensionA"},
{{0x4E00, 0x9FFF}, NULL, "CJKUnifiedIdeographs"},
{{0xA000, 0xA48F}, NULL, "YiSyllables"},
{{0xA490, 0xA4CF}, NULL, "YiRadicals"},
{{0xAC00, 0xD7A3}, NULL, "HangulSyllables"},
{{0xE000, 0xF8FF}, NULL, "PrivateUse"},
{{0xF900, 0xFAFF}, NULL, "CJKCompatibilityIdeographs"},
{{0xFB00, 0xFB4F}, NULL, "AlphabeticPresentationForms"},
{{0xFB50, 0xFDFF}, NULL, "ArabicPresentationForms-A"},
{{0xFE20, 0xFE2F}, NULL, "CombiningHalfMarks"},
{{0xFE30, 0xFE4F}, NULL, "CJKCompatibilityForms"},
{{0xFE50, 0xFE6F}, NULL, "SmallFormVariants"},
{{0xFE70, 0xFEFE}, NULL, "ArabicPresentationForms-B"},
{{0xFEFF, 0xFEFF}, specials_extcp, "Specials"},
{{0xFF00, 0xFFEF}, NULL, "HalfwidthandFullwidthForms"}
};

char CRegexAscii_parser::readChar(const char *pattern, 
                                  bool for_atom, 
                                  int *char_len, CHARGROUP_t *multichar_type)
{
  char  c = 0;
  *char_len = 0;
  *multichar_type = CHARGROUP_NO_MULTICHAR;
  switch(pattern[*char_len])
  {
  case '\\':
  {
    (*char_len)++;
    switch(pattern[*char_len])
    {
    case 'n': c = '\n';break;
    case 'r': c = '\r';break;
    case 't': c = '\t';break;
    case '\\':
    case '/'://+
    case '|':
    case '.':
    case '?':
    case '*':
    case '+':
    case '(':
    case ')':
    case '{':
    case '}':
    case '-'://#x2D
    case '['://#x5B
    case ']'://#x5D
    case '^'://#x5E
    case '$'://+
       c = pattern[*char_len];
       break;
    case 'p'://catEsc
    case 'P'://complEsc
      //ignore the prop for now
      *multichar_type = (CHARGROUP_t)((pattern[*char_len] == 'P') ? 128 : 0);
      if(pattern[(*char_len)+1] != '{')
      {
        throw XQUERY_EXCEPTION( err::FORX0002, ERROR_PARAMS(pattern, ZED(REGEX_BROKEN_P_CONSTRUCT)) );
      }
      (*char_len) += 2;
      switch(pattern[*char_len])
      {//IsCategory
      case 'L':
      {
        unsigned int temp_int = *multichar_type;
        temp_int |= CHARGROUP_FLAGS_MULTICHAR_p;
        *multichar_type = (CHARGROUP_t)temp_int;
        switch(pattern[(*char_len)+1])
        {
        case '}':
          c = unicode::UNICODE_Ll + 50;break;
        case 'u':
          c = unicode::UNICODE_Lu; (*char_len)++;break;
        case 'l':
          c = unicode::UNICODE_Ll; (*char_len)++;break;
        case 't':
          c = unicode::UNICODE_Lt; (*char_len)++;break;
        case 'm':
          c = unicode::UNICODE_Lm; (*char_len)++;break;
        case 'o':
          c = unicode::UNICODE_Lo; (*char_len)++;break;
        default:
          throw XQUERY_EXCEPTION( err::FORX0002, ERROR_PARAMS(pattern, ZED(REGEX_UNKNOWN_PL_CONSTRUCT)) );
        }
      }break;
      case 'M':
      {
        unsigned int temp_int = *multichar_type;
        temp_int |= CHARGROUP_FLAGS_MULTICHAR_p;
        *multichar_type = (CHARGROUP_t)temp_int;
        switch(pattern[(*char_len)+1])
        {
        case '}':
          c = unicode::UNICODE_Mc + 50;break;
        case 'n':
          c = unicode::UNICODE_Mn; (*char_len)++;break;
        case 'c':
          c = unicode::UNICODE_Mc; (*char_len)++;break;
        case 'e':
          c = unicode::UNICODE_Me; (*char_len)++;break;
        default:
          throw XQUERY_EXCEPTION( err::FORX0002, ERROR_PARAMS(pattern, ZED(REGEX_UNKNOWN_PM_CONSTRUCT)) );
        }
      }break;
      case 'N':
      {
        unsigned int temp_int = *multichar_type;
        temp_int |= CHARGROUP_FLAGS_MULTICHAR_p;
        *multichar_type = (CHARGROUP_t)temp_int;
        switch(pattern[(*char_len)+1])
        {
        case '}':
          c = unicode::UNICODE_Nd + 50;break;
        case 'd':
          c = unicode::UNICODE_Nd; (*char_len)++;break;
        case 'l':
          c = unicode::UNICODE_Nl; (*char_len)++;break;
        case 'o':
          c = unicode::UNICODE_No; (*char_len)++;break;
        default:
          throw XQUERY_EXCEPTION( err::FORX0002, ERROR_PARAMS(pattern, ZED(REGEX_UNKNOWN_PN_CONSTRUCT)) );
        }
      }break;
      case 'P':
      {
        unsigned int temp_int = *multichar_type;
        temp_int |= CHARGROUP_FLAGS_MULTICHAR_p;
        *multichar_type = (CHARGROUP_t)temp_int;
        switch(pattern[(*char_len)+1])
        {
        case '}':
          c = unicode::UNICODE_Pc + 50;break;
        case 'c':
          c = unicode::UNICODE_Pc; (*char_len)++;break;
        case 'd':
          c = unicode::UNICODE_Pd; (*char_len)++;break;
        case 's':
          c = unicode::UNICODE_Ps; (*char_len)++;break;
        case 'e':
          c = unicode::UNICODE_Pe; (*char_len)++;break;
        case 'i':
          c = unicode::UNICODE_Pi; (*char_len)++;break;
        case 'f':
          c = unicode::UNICODE_Pf; (*char_len)++;break;
        case 'o':
          c = unicode::UNICODE_Po; (*char_len)++;break;
        default:
          throw XQUERY_EXCEPTION( err::FORX0002, ERROR_PARAMS(pattern, ZED(REGEX_UNKNOWN_PP_CONSTRUCT)) );
        }
      }break;
      case 'Z':
      {
        unsigned int temp_int = *multichar_type;
        temp_int |= CHARGROUP_FLAGS_MULTICHAR_p;
        *multichar_type = (CHARGROUP_t)temp_int;
        switch(pattern[(*char_len)+1])
        {
        case '}':
          c = unicode::UNICODE_Zl + 50;break;
        case 's':
          c = unicode::UNICODE_Zs; (*char_len)++;break;
        case 'l':
          c = unicode::UNICODE_Zl; (*char_len)++;break;
        case 'p':
          c = unicode::UNICODE_Zp; (*char_len)++;break;
        default:
          throw XQUERY_EXCEPTION( err::FORX0002, ERROR_PARAMS(pattern, ZED(REGEX_UNKNOWN_PZ_CONSTRUCT)) );
        }
      }break;
      case 'S':
      {
        unsigned int temp_int = *multichar_type;
        temp_int |= CHARGROUP_FLAGS_MULTICHAR_p;
        *multichar_type = (CHARGROUP_t)temp_int;
        switch(pattern[(*char_len)+1])
        {
        case '}':
          c = unicode::UNICODE_Sc + 50;break;
        case 'm':
          c = unicode::UNICODE_Sm; (*char_len)++;break;
        case 'c':
          c = unicode::UNICODE_Sc; (*char_len)++;break;
        case 'k':
          c = unicode::UNICODE_Sk; (*char_len)++;break;
        case 'o':
          c = unicode::UNICODE_So; (*char_len)++;break;
        default:
          throw XQUERY_EXCEPTION( err::FORX0002, ERROR_PARAMS(pattern, ZED(REGEX_UNKNOWN_PS_CONSTRUCT)) );
        }
      }break;
      case 'C':
      {
        unsigned int temp_int = *multichar_type;
        temp_int |= CHARGROUP_FLAGS_MULTICHAR_p;
        *multichar_type = (CHARGROUP_t)temp_int;
        switch(pattern[(*char_len)+1])
        {
        case '}':
          c = unicode::UNICODE_Cc + 50;break;
        case 'c':
          c = unicode::UNICODE_Cc; (*char_len)++;break;
        case 'f':
          c = unicode::UNICODE_Cf; (*char_len)++;break;
        case 'o':
          c = unicode::UNICODE_Co; (*char_len)++;break;
        case 'n':
          c = unicode::UNICODE_Cn; (*char_len)++;break;
        default:
          throw XQUERY_EXCEPTION( err::FORX0002, ERROR_PARAMS(pattern, ZED(REGEX_UNKNOWN_PC_CONSTRUCT)) );
        }
      }break;
      case 'I':
        switch(pattern[(*char_len)+1])
        {
        case 's'://IsBlock
        {
          unsigned int temp_int = *multichar_type;
          temp_int |= CHARGROUP_FLAGS_MULTICHAR_Is;
          *multichar_type = (CHARGROUP_t)temp_int;
          (*char_len)++;
          zstring block_name;
          char tempc = pattern[(*char_len)+1];
          while(tempc && (tempc != '}'))
          {
            if(!myisletterAZ(tempc) && !myisdigit(tempc) && (tempc != '-'))
              throw XQUERY_EXCEPTION( err::FORX0002, ERROR_PARAMS(pattern, ZED(REGEX_BROKEN_PIs_CONSTRUCT)) );
            block_name.append(1, tempc);
            (*char_len)++;
            tempc = pattern[(*char_len)+1];
          }
          if(!pattern[(*char_len)+1])
            throw XQUERY_EXCEPTION( err::FORX0002, ERROR_PARAMS(pattern, ZED(REGEX_BROKEN_PIs_CONSTRUCT)) );
          //search for the block name
          int i;
          int nr_blocks = sizeof(block_escape)/sizeof(CRegexAscii_parser::block_escape_t);
          for(i=0;i<nr_blocks;i++)
          {
            if(compare_i(block_name.c_str(), block_escape[i].group_name))
            {
              c = i;
              break;
            }
          }
          if(i==nr_blocks)
            throw XQUERY_EXCEPTION( err::FORX0002, ERROR_PARAMS(pattern, ZED(REGEX_UNKNOWN_PIs_CONSTRUCT)) );
        }break;
        default:
          throw XQUERY_EXCEPTION( err::FORX0002, ERROR_PARAMS(pattern, ZED(REGEX_BROKEN_PIs_CONSTRUCT)) );
        }break;
      default:
        throw XQUERY_EXCEPTION( err::FORX0002, ERROR_PARAMS(pattern, ZED(REGEX_BROKEN_P_CONSTRUCT)) );
      }
      if(pattern[(*char_len) + 1] != '}')
          throw XQUERY_EXCEPTION( err::FORX0002, ERROR_PARAMS(pattern, ZED(REGEX_BROKEN_P_CONSTRUCT)) );
      (*char_len)++;
      break;
      //multiCharEsc
    case 's':
    case 'S':
    case 'i':
    case 'I':
    case 'c':
    case 'C':
    case 'd':
    case 'D':
    case 'w':
    case 'W':
       *multichar_type = CHARGROUP_FLAGS_MULTICHAR_OTHER;
       c = pattern[*char_len];
       break;
    default:
      throw XQUERY_EXCEPTION( err::FORX0002, ERROR_PARAMS(pattern, ZED(REGEX_UNKNOWN_ESC_CHAR)) );
    }
    break;
  }
  case '#':///might be #xXX
  {
    if((pattern[*char_len+1] == 'x') &&
      myishex(pattern[*char_len+2]) && myishex(pattern[*char_len+3]))
    {
      c = (myishex(pattern[*char_len+2])-1)<<4 | (myishex(pattern[*char_len+3])-1);
      *char_len += 3;
      break;
    }
  }
  default:
     c = pattern[*char_len];
     break;
  }

  (*char_len)++;
  if((flags & REGEX_ASCII_NO_WHITESPACE) && for_atom &&
    ((c == ' ') || (c == '\t') || (c == '\r') || (c == '\n')))
  {
    //ignore this whitespace
    int char_len2;
    char c2 = readChar(pattern + *char_len, for_atom, &char_len2, multichar_type);
    *char_len += char_len2;
    return c2;
  }
  return c;
}



IRegexAtom* CRegexAscii_parser::read_atom(const char *pattern, int *atom_len)
{
  *atom_len = 0;
  char  c;
  bool is_end_line = false;
  c = pattern[*atom_len];
  if((!(flags & REGEX_ASCII_LITERAL)) && (c == '\\'))
  {
    //check for back reference
    if(myisdigit(pattern[(*atom_len)+1]))
    {
      (*atom_len)++;
      if(pattern[*atom_len] == '0')
      {
        throw XQUERY_EXCEPTION( err::FORX0002, ERROR_PARAMS(pattern, ZED(REGEX_INVALID_BACK_REF), 0, current_regex->subregex.size()) );
      }
      unsigned int backref = pattern[*atom_len] - '0';
      if((backref > current_regex->subregex.size()) ||
        (current_regex->subregex.at(backref-1)->flags != 0))
      {
        throw XQUERY_EXCEPTION( err::FORX0002, ERROR_PARAMS(pattern, ZED(REGEX_INVALID_BACK_REF), backref, current_regex->subregex.size()) );
      }
      while(current_regex->subregex.size() >= backref*10)
      {
        if(myisdigit(pattern[(*atom_len)+1]))
        {
          if(((backref*10+pattern[(*atom_len)+1]-'0') <= current_regex->subregex.size()) &&
            (current_regex->subregex.at(backref*10+pattern[(*atom_len)+1]-'0'-1)->flags == 0))
          {
            (*atom_len)++;
            backref = backref*10 + pattern[*atom_len]-'0';
          }
          else
            break;
        }
      }
      (*atom_len)++;
      return new CRegexAscii_backref(current_regex, backref);
    }
  }
  if((!(flags & REGEX_ASCII_LITERAL)) && (c == '^'))
  {
    (*atom_len)++;
    return new CRegexAscii_pinstart(current_regex);
  }
  if((c == '}') || (c == '{') || (c == '?') || (c == '*') || (c == '+') || (c == '|'))
  {
    throw XQUERY_EXCEPTION( err::FORX0002, ERROR_PARAMS(pattern, ZED(REGEX_INVALID_ATOM_CHAR), c) );
  }
  switch(c)
  {
  case '[':
  {
    if(!(flags & REGEX_ASCII_LITERAL))
    {
      (*atom_len)++;
      CRegexAscii_chargroup *chargroup = NULL;
      int chargroup_len;
      chargroup = readchargroup(pattern+*atom_len, &chargroup_len);
      *atom_len += chargroup_len;
      return chargroup;
    }
  }
  case '.'://WildCharEsc
  {
    if(!(flags & REGEX_ASCII_LITERAL))
    {
      CRegexAscii_wildchar  *wildchar = new CRegexAscii_wildchar(current_regex);
      (*atom_len)++;
      return wildchar;
    }
  }
  case '('://begin an embedded reg exp
  {  
    if(!(flags & REGEX_ASCII_LITERAL))
    {
      (*atom_len)++;
      CRegexAscii_regex *emb_regex = NULL;
      int   regex_len;
      emb_regex = parse_regexp(pattern + *atom_len, &regex_len);
      *atom_len += regex_len;
      return emb_regex;
    }
  }
  case '$'://end line
    if(!(flags & REGEX_ASCII_LITERAL))
    {
      is_end_line = true;
    }
  default:
  {  
    char  c;
    int   c_len;
    CHARGROUP_t   multichar_type = CHARGROUP_NO_MULTICHAR;
    if(!(flags & REGEX_ASCII_LITERAL))
      c = readChar(pattern+*atom_len, true, &c_len, &multichar_type);
    else
    {
      c = pattern[*atom_len];
      c_len = 1;
    }
    std::auto_ptr<CRegexAscii_chargroup> chargroup(new CRegexAscii_chargroup(current_regex));
    if(multichar_type)
      chargroup->addMultiChar(c, multichar_type);
    else if(is_end_line)
      chargroup->addEndLine();
    else
      chargroup->addOneChar(c);
    *atom_len += c_len;
    return chargroup.release();
  }
  }
}

//read until ']'
//posCharGroup  ::=   ( charRange | charClassEsc )+  
//charRange     ::=    seRange | XmlCharIncDash
CRegexAscii_chargroup* CRegexAscii_parser::readchargroup(const char *pattern, int *chargroup_len)
{
  std::auto_ptr<CRegexAscii_chargroup> chargroup;
  *chargroup_len = 0;
  if(pattern[*chargroup_len] == '^')//negative group
  {
    (*chargroup_len)++;
    chargroup.reset(new CRegexAscii_negchargroup(current_regex));
  }
  else
    chargroup.reset(new CRegexAscii_chargroup(current_regex));
  while(pattern[*chargroup_len] && (pattern[*chargroup_len]!=']'))
  {
    char  c1, c2;
    CHARGROUP_t  multichar_type = CHARGROUP_NO_MULTICHAR;
    int   c1_len;
    c1 = pattern[*chargroup_len];
    c2 = pattern[*chargroup_len+1];
    if((c1 == '-') && (c2 == '['))//charClassSub
    {
      int classsub_len;
      CRegexAscii_chargroup *classsub = readchargroup(pattern + *chargroup_len+1 + 1, &classsub_len);
      if(!classsub)
      {
        throw XQUERY_EXCEPTION( err::FORX0002, ERROR_PARAMS(pattern, ZED(REGEX_INVALID_SUBCLASS)) );
      }
      chargroup->addClassSub(classsub);
      *chargroup_len += 2 + classsub_len + 1;
      if(pattern[*chargroup_len-1] != ']')
      {
        throw XQUERY_EXCEPTION( err::FORX0002, ERROR_PARAMS(pattern, ZED(REGEX_INVALID_USE_OF_SUBCLASS)) );
      }
      return chargroup.release();
    }

    c1 = readChar(pattern+*chargroup_len, false, &c1_len, &multichar_type);
    if(multichar_type)//first char is multichar
    {
      if((pattern[*chargroup_len+c1_len] == '-') &&///might be a range
        (pattern[*chargroup_len+c1_len+1] != ']'))
      {
        throw XQUERY_EXCEPTION( err::FORX0002, ERROR_PARAMS(pattern, ZED(REGEX_MULTICHAR_IN_CHAR_RANGE)) );
      }
      chargroup->addMultiChar(c1, multichar_type);
      *chargroup_len += c1_len;
      continue;
    }
    if(pattern[*chargroup_len+c1_len] == '-')///might be a range
    {
      if(pattern[*chargroup_len+c1_len+1] == ']')//no range, just the last char is '-'
      {
        chargroup->addOneChar(c1);
        chargroup->addOneChar('-');
        *chargroup_len += c1_len + 1;
        continue;
      }
      else if(pattern[*chargroup_len+c1_len+1] != '[')
      {
        //it is a range
        char c3;
        int  c3_len;
        c3 = readChar(pattern+*chargroup_len+c1_len+1, false, &c3_len, &multichar_type);
        if(multichar_type)
        {
          throw XQUERY_EXCEPTION( err::FORX0002, ERROR_PARAMS(pattern, ZED(REGEX_MULTICHAR_IN_CHAR_RANGE)) );
        }
        chargroup->addCharRange(c1, c3);
        *chargroup_len += c1_len + 1 + c3_len;
        continue;
      }
    }
    chargroup->addOneChar(c1);
    *chargroup_len += c1_len;
  }
  if(pattern[*chargroup_len])
    (*chargroup_len)++;
  else
  {
    throw XQUERY_EXCEPTION( err::FORX0002, ERROR_PARAMS(pattern, ZED(REGEX_MISSING_CLOSE_BRACKET)) );
  }
  return chargroup.release();
}

void CRegexAscii_parser::read_quantifier(CRegexAscii_piece *piece,
                                         const char *pattern, int *quantif_len)
{
  *quantif_len = 0;
  switch(pattern[*quantif_len])
  {
  case '?':
    piece->set_quantifier_min_max(0, 1, false);
    (*quantif_len)++;
    break;
  case '*':
    piece->set_quantifier_min_max(0, -1, false);
    (*quantif_len)++;
    break;
  case '+':
    piece->set_quantifier_min_max(1, -1, false);
    (*quantif_len)++;
    break;
  case '{':
  {
    int min = 0, max = 0;
    (*quantif_len)++;
    while(pattern[*quantif_len] && (pattern[*quantif_len] != ',') &&
      myisdigit(pattern[*quantif_len]) && (pattern[*quantif_len] != '}'))
    {
      min = min*10 + pattern[*quantif_len] - '0';
      (*quantif_len)++;
    }
    if(pattern[*quantif_len] == '}')
    {
      (*quantif_len)++;
      piece->set_quantifier_min_max(min, min, true);
      break;
    }
    if((pattern[*quantif_len] == ',') && (!isdigit(pattern[*quantif_len+1])))
    {
      (*quantif_len)++;
      piece->set_quantifier_min_max(min, -1, false);
    }
    else
    {
      (*quantif_len)++;
      while(pattern[*quantif_len] &&
        isdigit(pattern[*quantif_len]) && (pattern[*quantif_len] != '}'))
      {
        max = max*10 + pattern[*quantif_len] - '0';
        (*quantif_len)++;
      }
      if(max < min)
      {
        throw XQUERY_EXCEPTION( err::FORX0002, ERROR_PARAMS(pattern, ZED(REGEX_MAX_LT_MIN)) );
      }
      piece->set_quantifier_min_max(min, max, true);
    }
    while(pattern[*quantif_len] && (pattern[*quantif_len] != '}'))
    {
      (*quantif_len)++;
    }
    if(pattern[*quantif_len] == '}')
      (*quantif_len)++;
    break;
  }
  default:
    piece->set_quantifier_min_max(1, 1, false);
    break;
  }
  if(*quantif_len && (pattern[*quantif_len] == '?'))
  {
    piece->set_is_reluctant(true);
    (*quantif_len)++;
  }
  else
    piece->set_is_reluctant(false);
}


////////////////////////////
///Constructors and destructors and internal functions
////////////////////////////

CRegexAscii_regex::CRegexAscii_regex(CRegexAscii_regex *topregex) : IRegexAtom(topregex?topregex:this)
{
  matched_source = NULL;
  matched_len = 0;
//  backup_matched_source = NULL;
//  backup_matched_len = 0;
  flags = 128;//set to 0 after initialization
}

CRegexAscii_regex::~CRegexAscii_regex()
{
  std::list<CRegexAscii_branch*>::iterator  branch_it;

  for(branch_it = branch_list.begin(); branch_it != branch_list.end(); branch_it++)
  {
    delete (*branch_it);
  }
/*
  std::vector<CRegexAscii_regex*>::iterator   subregex_it;
  for(subregex_it = subregex.begin(); subregex_it != subregex.end(); subregex_it++)
  {
    delete (*subregex_it);
  }
*/
}

void CRegexAscii_regex::add_branch(CRegexAscii_branch *branch)
{
  branch_list.push_back(branch);
}

bool  CRegexAscii_regex::get_indexed_match(int index, 
                                           const char **matched_source, 
                                           int *matched_len)
{
  if(!index || index > (int)subregex.size())
    return false;
  CRegexAscii_regex *subr = subregex[index-1];
  *matched_source = subr->matched_source;
  if(!*matched_source)
    return false;
  *matched_len = subr->matched_len;
  return true;
}

unsigned int CRegexAscii_regex::get_indexed_regex_count()
{
  return subregex.size();
}

CRegexAscii_branch::CRegexAscii_branch(CRegexAscii_regex* regex) 
      //:
      //IRegexMatcher(regex)
{
}

CRegexAscii_branch::~CRegexAscii_branch()
{
  std::list<RegexAscii_pieceinfo>::iterator  piece_it;

  for(piece_it = piece_list.begin(); piece_it != piece_list.end(); piece_it++)
  {
    delete (*piece_it).piece;
  }
}

void CRegexAscii_branch::add_piece(CRegexAscii_piece *piece)
{
  piece_list.push_back(piece);
}

CRegexAscii_piece::CRegexAscii_piece()
{
  atom = NULL;
  regex_atom = NULL;
}

CRegexAscii_piece::~CRegexAscii_piece()
{
  delete atom;
}

void CRegexAscii_piece::set_atom(IRegexAtom *atom)
{
  this->atom = atom;
  this->regex_atom = dynamic_cast<CRegexAscii_regex*>(atom);
}

void CRegexAscii_piece::set_quantifier_min_max(int min, int max, bool strict_max)
{
  this->min = min;
  this->max = max;
  this->strict_max = strict_max;
}
void CRegexAscii_piece::set_is_reluctant(bool is_reluctant)
{
  this->is_reluctant = is_reluctant;
}
void CRegexAscii_piece::get_quantifier(int *min, int *max, bool *strict_max)
{
  *min = this->min;
  *max = this->max;
  *strict_max = this->strict_max;
}
bool CRegexAscii_piece::get_is_reluctant()
{
  if(atom->regex_intern->flags & REGEX_ASCII_MINIMAL_MATCH)
    return true;
  return is_reluctant;
}


CRegexAscii_chargroup::CRegexAscii_chargroup(CRegexAscii_regex* regex) :
    IRegexAtom(regex)
{
  classsub = NULL;
}

CRegexAscii_chargroup::~CRegexAscii_chargroup()
{
  delete classsub;
}

void CRegexAscii_chargroup::addMultiChar(char c, CHARGROUP_t multichar_type)
{
  chargroup_t cgt;
  cgt.flags = multichar_type;
  cgt.c1 = c;
  cgt.c2 = 0;
  chargroup_list.push_back(cgt);
}

void CRegexAscii_chargroup::addEndLine()
{
  chargroup_t cgt;
  cgt.flags = CHARGROUP_FLAGS_ENDLINE;
  cgt.c1 = '$';
  cgt.c2 = 0;
  chargroup_list.push_back(cgt);
}

void CRegexAscii_chargroup::addCharRange(char c1, char c2)
{
  chargroup_t cgt;
  cgt.flags = CHARGROUP_FLAGS_CHAR_RANGE;
  cgt.c1 = c1;
  cgt.c2 = c2;
  chargroup_list.push_back(cgt);
}

void CRegexAscii_chargroup::addOneChar(char c)
{
  chargroup_t cgt;
  cgt.flags = CHARGROUP_FLAGS_ONECHAR;
  cgt.c1 = c;
 chargroup_list.push_back(cgt);
}

void CRegexAscii_chargroup::addClassSub(CRegexAscii_chargroup* classsub)
{
  this->classsub = classsub;
}

CRegexAscii_negchargroup::CRegexAscii_negchargroup(CRegexAscii_regex* regex) :
  CRegexAscii_chargroup(regex)
{
}

CRegexAscii_negchargroup::~CRegexAscii_negchargroup()
{
}

CRegexAscii_wildchar::CRegexAscii_wildchar(CRegexAscii_regex* regex) :
      IRegexAtom(regex)
{
}

CRegexAscii_wildchar::~CRegexAscii_wildchar()
{
}

CRegexAscii_backref::CRegexAscii_backref(CRegexAscii_regex* regex, unsigned int backref_) :
      IRegexAtom(regex),
      backref(backref_)
{
}

CRegexAscii_backref::~CRegexAscii_backref()
{
}

CRegexAscii_pinstart::CRegexAscii_pinstart(CRegexAscii_regex* regex):
      IRegexAtom(regex)
{
}

CRegexAscii_parser::CRegexAscii_parser()
{
  current_regex = NULL;
  regex_depth = 0;
}

CRegexAscii_parser::~CRegexAscii_parser()
{
}


//////////////////////////////////////////
////Matching the pattern on a string
/////////////////////////////////////////
static std::list<RegexAscii_pieceinfo> empty_pieces;//empty list of pieces
/*
std::list<RegexAscii_pieceinfo>::iterator  
IRegexAtom::choose_next_piece(const char *source, int *matched_len, 
                              std::list<RegexAscii_pieceinfo>::iterator this_piece,
                              std::list<RegexAscii_pieceinfo>::iterator end_piece)
{
  //if this_piece is repetition, repeat until max, then go to next piece
  int min, max;
  bool strict_max;
  while(this_piece != end_piece)
  {
    (*this_piece).piece->get_quantifier(&min, &max, &strict_max);
    if(max <= ((*this_piece).nr_matches))//finished this piece
    {
      this_piece++;
    }
    else
      break;
  }
  return this_piece;
}
*/

bool IRegexAtom::match(const char *source, int *start_from_branch, int *matched_len,
                  std::list<RegexAscii_pieceinfo>::iterator this_piece,
                  std::list<RegexAscii_pieceinfo>::iterator end_piece)
{
  *start_from_branch = 0;
  bool retmatch;
  retmatch = match_internal(source, start_from_branch, matched_len);
  if(!retmatch)
    return false;

  if(this_piece == end_piece)
    return true;

  (*this_piece).nr_matches++;
  int min,max;
  bool strict_max;
  (*this_piece).piece->get_quantifier(&min, &max, &strict_max);
  std::list<RegexAscii_pieceinfo>::iterator init_piece = this_piece;
  if(((min == 1) && (max == 1)) || //the simple common case
    ((*matched_len == 0) && ((*this_piece).nr_matches>=min)))//to avoid infinite loop
  {
    this_piece++;
    if(this_piece == end_piece)
      return true;
  }
  int matched_len2;
  retmatch = (*this_piece).piece->match_piece(this_piece, end_piece, source + *matched_len, &matched_len2);
  if(!retmatch)
  {
    (*init_piece).nr_matches--;
    return false;
  }
  *matched_len += matched_len2;
  return true;
}

//try every position in source to match the pattern
bool CRegexAscii_regex::match_anywhere(const char *source, unsigned int flags,
                                       int *match_pos, int *matched_len)
{
  *match_pos = 0;
  reachedEnd = false;
  return match_from(source, flags, match_pos, matched_len);
}

bool CRegexAscii_regex::match_from(const char *source, unsigned int flags,
                                       int *match_pos, int *matched_len)
{
  this->flags = flags;
  this->source_start = source;
  reachedEnd = false;

  std::vector<CRegexAscii_regex*>::iterator regex_it;
  for(regex_it = subregex.begin(); regex_it != subregex.end(); regex_it++)
  {
    (*regex_it)->matched_source = NULL;
  }

  std::vector<std::pair<const char*, int> >  saved_subregex;

  if(*match_pos && (flags & REGEX_ASCII_WHOLE_MATCH))
    return false;

  do
  {
    int   start_from_branch = 0;
    int   longest_match = -1;
    while(1)
    {
      if(!match(source + *match_pos, &start_from_branch, matched_len, empty_pieces.begin(), empty_pieces.end()))
        break;
      if(longest_match < *matched_len)
      {
        longest_match = *matched_len;
        if(start_from_branch && (flags & REGEX_ASCII_GET_LONGEST_BRANCH))
          save_subregex_list(saved_subregex);
      }
      if(!start_from_branch || !(flags & REGEX_ASCII_GET_LONGEST_BRANCH))
        break;
      //else try the other branches to see which is longer
    }
    if(longest_match != -1)
    {
      *matched_len = longest_match;
      if(saved_subregex.size())
        load_subregex_list(saved_subregex);
      if(flags & REGEX_ASCII_WHOLE_MATCH)
      {
        if(!source[*match_pos+*matched_len])
          return true;
        if((flags & REGEX_ASCII_MULTILINE) && 
          ((source[*match_pos+*matched_len] == '\n') || (source[*match_pos+*matched_len] == '\r')))
          return true;
        return false;
      }
      return true;
    }

    if(flags & REGEX_ASCII_WHOLE_MATCH)
    {
      if(flags & REGEX_ASCII_MULTILINE)
      {
        //go to next line
        while(source[*match_pos] && (source[*match_pos] != '\n') && (source[*match_pos] != '\r'))
          (*match_pos)++;
        if(source[*match_pos] == '\n')
        {
          (*match_pos)++;
          if(source[*match_pos] == '\r')
            (*match_pos)++;
        }
        else if(source[*match_pos] == '\r')
        {
          (*match_pos)++;
          if(source[*match_pos] == '\n')
            (*match_pos)++;
        }
        if(!source[*match_pos])
          break;
        continue;
      }
      break;
    }
    if(!source[*match_pos])
      break;
    (*match_pos)++;
  }
  while(source[*match_pos]);
  if(!source[*match_pos])
  {
    reachedEnd = true;
  }
  return false;
}

void CRegexAscii_regex::reset_match()
{
//  this->backup_matched_source = this->matched_source;
//  this->backup_matched_len = this->matched_len;
  this->matched_source = NULL;
  this->matched_len = 0;
  std::list<CRegexAscii_branch*>::iterator  branch_it;
  for(branch_it = branch_list.begin(); branch_it != branch_list.end(); branch_it++)
  {
    (*branch_it)->reset();
  }
}
/*
void CRegexAscii_regex::restore_match()
{
  this->matched_source = this->backup_matched_source;
  this->matched_len = this->backup_matched_len;
  std::list<CRegexAscii_branch*>::iterator  branch_it;
  for(branch_it = branch_list.begin(); branch_it != branch_list.end(); branch_it++)
  {
    (*branch_it)->restore();
  }
}
*/
//match any of the branches
bool CRegexAscii_regex::match(const char *source, int *start_from_branch, int *matched_len,
                              std::list<RegexAscii_pieceinfo>::iterator next_piece,
                              std::list<RegexAscii_pieceinfo>::iterator end_piece)
{
  reachedEnd = false;
  if(!(flags & REGEX_ASCII_GROUPING_LEN_WHOLE_PIECE) || 
    (this->matched_source == NULL) || ((this->matched_source + this->matched_len) != source))
    this->matched_source = source;
  *matched_len = 0;
  std::list<CRegexAscii_branch*>::iterator  branch_it;

  if(*start_from_branch == 0)
  {
    for(branch_it = branch_list.begin(); branch_it != branch_list.end(); branch_it++)
    {
      (*branch_it)->reset();
    }
  }

  branch_it = branch_list.begin();
  if(*start_from_branch)
  {
    for(int i=0;i<*start_from_branch;i++)
      branch_it++;
  }
  (*start_from_branch)++;
  for(; branch_it != branch_list.end(); branch_it++,(*start_from_branch)++)
  {
    if((*branch_it)->match(source, matched_len, this, next_piece, end_piece))
    {
      //matched_source = source;
      //this->matched_len = *matched_len;
      return true;
    }
  }
  *start_from_branch = 0;
  if(this->matched_source == source)
    this->matched_source = NULL;
  *matched_len = 0;
  return false;
}

void CRegexAscii_regex::save_subregex_list(std::vector<std::pair<const char*, int> > &saved_subregex)
{
  saved_subregex.resize(0);
  saved_subregex.reserve(subregex.size());
  std::vector<CRegexAscii_regex*>::iterator   it;
  for(it=subregex.begin(); it != subregex.end(); it++)
  {
    saved_subregex.push_back(std::pair<const char*, int>((*it)->matched_source, (*it)->matched_len));
  }
}

void CRegexAscii_regex::load_subregex_list(std::vector<std::pair<const char*, int> > &saved_subregex)
{
  std::vector<std::pair<const char*, int> >::iterator   it;
  std::vector<CRegexAscii_regex*>::iterator            subit;
  for(it=saved_subregex.begin(), subit = subregex.begin(); it != saved_subregex.end(); it++, subit++)
  {
    (*subit)->matched_source = (*it).first;
    (*subit)->matched_len = (*it).second;
  }
}

void CRegexAscii_branch::reset()
{
  std::list<RegexAscii_pieceinfo>::iterator  piece_it;
  for(piece_it = piece_list.begin(); piece_it != piece_list.end(); piece_it++)
  {
    (*piece_it).piece->atom->reset_match();
  }
}
/*
void CRegexAscii_branch::restore()
{
  std::list<RegexAscii_pieceinfo>::iterator  piece_it;
  for(piece_it = piece_list.begin(); piece_it != piece_list.end(); piece_it++)
  {
    (*piece_it).piece->atom->restore_match();
  }
}
*/
//match all the pieces
bool CRegexAscii_branch::match(const char *source, int *matched_len,
                              CRegexAscii_regex* group_regex,
                              std::list<RegexAscii_pieceinfo>::iterator next_piece,
                              std::list<RegexAscii_pieceinfo>::iterator end_piece)
{
  std::list<RegexAscii_pieceinfo>::iterator  piece_it;

  piece_it = piece_list.begin(); 
  //if(piece_it == piece_list.end())
    //if(!source[0])
  //    return true;
    //else
    //  return false;
  if(piece_it == piece_list.end())
  {
    piece_it = next_piece;
    if(next_piece == end_piece)
    {
      group_regex->matched_len = 0;
      return true;
    }
  }

  std::list<RegexAscii_pieceinfo>   temp_pieces(piece_list);
  temp_pieces.push_back(group_regex);//this will be used to store the group match
  temp_pieces.insert(temp_pieces.end(), next_piece, end_piece);

  return (*piece_it).piece->match_piece(temp_pieces.begin(), temp_pieces.end(), source, matched_len);
}

bool CRegexAscii_piece::match_piece(std::list<RegexAscii_pieceinfo>::iterator piece_it,
                                    std::list<RegexAscii_pieceinfo>::iterator end_it,
                                    const char *source, int *matched_len)
{
  if((*piece_it).nr_matches < 0)
  {
    //special case, store the group match
    (*piece_it).group_regex->matched_len = source - (*piece_it).group_regex->matched_source;
    piece_it++;
    if(piece_it == end_it)
      return true;
    else
      return (*piece_it).piece->match_piece(piece_it, end_it, source, matched_len);
  }

  if(!get_is_reluctant())
    return match_piece_iter_normal(piece_it, end_it, source, matched_len);
  else
    return match_piece_iter_reluctant(piece_it, end_it, source, matched_len);
}

int CRegexAscii_piece::choose_another_branch(std::vector<std::pair<int,int> > &match_lens)
{
  int i = match_lens.size()-1;
  i--;
  while((i >= 0) && (match_lens.at(i).second == 0))
    i--;
  if(i < 0)
    return -1;//no more branches
  match_lens.resize(i+1);
  i++;
  return i;
}

bool CRegexAscii_piece::is_regex_atom()
{
  return regex_atom != NULL;
}

//match as less as possible (shortest string)
bool CRegexAscii_piece::match_piece_iter_reluctant(
                                        std::list<RegexAscii_pieceinfo>::iterator piece_it,
                                        std::list<RegexAscii_pieceinfo>::iterator end_it,
                                        const char *source, int *matched_len)
{
  *matched_len = 0;
  if(piece_it == end_it)
    return true;

  int min, max;
  bool  strict_max;
  //std::vector<int>    match_lens;
  (*piece_it).piece->get_quantifier(&min, &max, &strict_max);

  std::vector<std::pair<const char*, int> >  saved_subregex;

  if(is_regex_atom())
  {
    //recursive
    bool retmatch;
    atom->regex_intern->save_subregex_list(saved_subregex);
    if((*piece_it).nr_matches >= min)
    {
      //go to next piece
      std::list<RegexAscii_pieceinfo>::iterator next_it = piece_it;
      next_it++;
      if(next_it == end_it)
        return true;
      retmatch = (*next_it).piece->match_piece(next_it, end_it, source, matched_len);
      if(retmatch)
        return true;
    }
    if(((max == -1) || ((*piece_it).nr_matches < max)) &&//try further with this piece
      (((*piece_it).nr_matches < min) || ((*piece_it).nr_matches == 0) || ((*piece_it).piece->regex_atom->matched_len)))//if matched_len is zero, avoid infinite loop
    {
      int start_from_branch = 0;
      int shortest_len = -1;
      bool branch_saved = false;
      //try all branches to get the shortest len
      (*piece_it).nr_matches++;
      while(atom->match(source, &start_from_branch, matched_len, piece_it, end_it))
      {
        if((shortest_len == -1) || (shortest_len > *matched_len))
        {
          shortest_len = *matched_len;
          if(start_from_branch && (atom->regex_intern->flags & REGEX_ASCII_GET_LONGEST_BRANCH))
          {
            atom->regex_intern->save_subregex_list(saved_subregex);
            branch_saved = true;
          }
        }
        if(!start_from_branch || !(atom->regex_intern->flags & REGEX_ASCII_GET_LONGEST_BRANCH))
          break;
      }
      if(shortest_len != -1)
      {
        *matched_len = shortest_len;
        if(branch_saved)
          atom->regex_intern->load_subregex_list(saved_subregex);
        return true;
      }
      else
      {
        (*piece_it).nr_matches--;
        atom->regex_intern->load_subregex_list(saved_subregex);
        return false;
      }
    }
    else
    {
      atom->regex_intern->load_subregex_list(saved_subregex);
      return false;
    }
  }

  int i=0;
  int shortest_len = -1;
  int otherpieces_shortest = -1;
  int i_shortest = -1;
  std::list<RegexAscii_pieceinfo>::iterator next_it = piece_it;
  std::vector<std::pair<int,int> >    match_lens;
  next_it++;
  int pieceslen = 0;
  while(1)
  {
    int piecelen = 0;
    bool retmatch;
    retmatch = match_piece_times(source, &piecelen, i < min ? min : i, &match_lens);
    i = match_lens.size()-1;//number of matches
    if(i<0)
      i = 0;
    if((i>=min))
    {
      pieceslen = piecelen;
      if((shortest_len >= 0) && (shortest_len <= pieceslen))//this branch is longer
      {//try another branch
        i = choose_another_branch(match_lens);
        if(i >= 0)
          continue;//try another branch
        else
          break;
      }
      int   otherpieces = 0;
      if((next_it == end_it) ||
        (*next_it).piece->match_piece(next_it, end_it, source+pieceslen, &otherpieces)
        )
      {
        if((i == pieceslen) || (match_lens.at(0).second == 0) ||//minimum achieved already, cannot go lower than that
            !(atom->regex_intern->flags & REGEX_ASCII_GET_LONGEST_BRANCH))
        {
          *matched_len = pieceslen + otherpieces;
          return true;
        }
        if((shortest_len < 0) || (shortest_len > pieceslen))
        {
          shortest_len = pieceslen;
          otherpieces_shortest = otherpieces;
          i_shortest = i;
          if(match_lens.at(0).second != 0)
            atom->regex_intern->save_subregex_list(saved_subregex);
        }
        i = choose_another_branch(match_lens);
        if(i >= 0)
          continue;//try another branch
        else
          break;
      }
      else
      {
        //try further
        if(retmatch)
        {
          i++;
          if((max < 0) || (i<=max))
            continue;
          i--;
        }
      }
    }
    
    if(i==0)
    {
      break;
    }
    else
    {
      i = choose_another_branch(match_lens);
      if(i >= 0)
        continue;//try another branch
      else
        break;
    }
  }

  if(shortest_len >= 0)
  {
    if(strict_max && (max>=0) && (i_shortest > max))
      return false;
    *matched_len = shortest_len + otherpieces_shortest;
    if(saved_subregex.size())
      atom->regex_intern->load_subregex_list(saved_subregex);
    return true;
  }
  return false;
}

//match as much as possible
bool CRegexAscii_piece::match_piece_iter_normal(
                                        std::list<RegexAscii_pieceinfo>::iterator piece_it,
                                        std::list<RegexAscii_pieceinfo>::iterator end_it,
                                        const char *source, int *matched_len)
{
  *matched_len = 0;

  int min, max;
  bool  strict_max;
  std::vector<std::pair<int,int> >    match_lens;
  (*piece_it).piece->get_quantifier(&min, &max, &strict_max);
  int   timeslen = 0;
  std::vector<std::pair<const char*, int> >  saved_subregex;

  if(is_regex_atom())
  {
    //recursive
    bool retmatch;
    atom->regex_intern->save_subregex_list(saved_subregex);
    if(((max == -1) || ((*piece_it).nr_matches < max)) && //try further with this piece
      (((*piece_it).nr_matches < min) || ((*piece_it).nr_matches == 0) || ((*piece_it).piece->regex_atom->matched_len)))//if matched_len is zero, avoid infinite loop
    {
      int start_from_branch = 0;
      int longest_len = -1;
      bool branch_saved = false;
      //try all branches to get the longest len
      (*piece_it).nr_matches++;
      while(atom->match(source, &start_from_branch, matched_len, piece_it, end_it))
      {
        if((longest_len < *matched_len))
        {
          longest_len = *matched_len;
          if(start_from_branch && (atom->regex_intern->flags & REGEX_ASCII_GET_LONGEST_BRANCH))
          {
            atom->regex_intern->save_subregex_list(saved_subregex);
            branch_saved = true;
          }
        }
        if(!start_from_branch || !(atom->regex_intern->flags & REGEX_ASCII_GET_LONGEST_BRANCH))
          break;
      }
      if(longest_len != -1)
      {
        *matched_len = longest_len;
        if(branch_saved)
          atom->regex_intern->load_subregex_list(saved_subregex);
        return true;
      }
      else
      {
        atom->regex_intern->load_subregex_list(saved_subregex);
        (*piece_it).nr_matches--;
      }
    }
    if((*piece_it).nr_matches >= min)
    {
      //go to next piece
      std::list<RegexAscii_pieceinfo>::iterator next_it = piece_it;
      next_it++;
      if(next_it == end_it)
        return true;
      retmatch = (*next_it).piece->match_piece(next_it, end_it, source, matched_len);
      if(!retmatch)
        atom->regex_intern->load_subregex_list(saved_subregex);
      return retmatch;
    }
    else
    {
    //  regex_atom->restore_match();
      atom->regex_intern->load_subregex_list(saved_subregex);
      return false;
    }
  }

  int longest_len = -1;
  int otherpieces_longest = -1;
  int i_longest = -1;
  int i = max;
  std::list<RegexAscii_pieceinfo>::iterator next_it = piece_it;
  next_it++;

  bool retmatch;
  while(1)
  {
    retmatch = match_piece_times(source, &timeslen, i, &match_lens);
    i=match_lens.size()-1;//number of matches
    if((i>=min))
    {
      if(timeslen < longest_len)
      {//this branch is no use
        i = choose_another_branch(match_lens);
        if(i >= 0)
        {
          i = max;
          continue;//try another branch
        }
        else
          break;
      }
      //int piecelen = 0;
      int   otherpieces = 0;
      if((next_it == end_it) ||
        (*next_it).piece->match_piece(next_it, end_it, source+timeslen, &otherpieces)
        )
      {
        if(timeslen > longest_len)
        {
          longest_len = timeslen;
          otherpieces_longest = otherpieces;
          i_longest = i;
          if(!(atom->regex_intern->flags & REGEX_ASCII_GET_LONGEST_BRANCH))
          {
            *matched_len = longest_len + otherpieces_longest;
            return true;
          }
          else
          {
            if(match_lens.at(0).second)
              atom->regex_intern->save_subregex_list(saved_subregex);
          }
        }
      }
      else
      {
        if(!match_lens.at(0).second)
        {
          match_lens.resize(match_lens.size()-1);
          i--;
          if(i >= 0)
            continue;//try smaller 
          else
            break;
        }
        else
        {
          i = choose_another_branch(match_lens);
          if(i >= 0)
            continue;//try another branch
          else
            break;
        }
      }
    }
    //now try another branch
    i = choose_another_branch(match_lens);
    if(i >= 0)
    {
      i = max;
      continue;//try another branch
    }
    else
      break;
  }//end while

  if(longest_len >= 0)
  {
    *matched_len = longest_len + otherpieces_longest;
    if(saved_subregex.size())
      atom->regex_intern->load_subregex_list(saved_subregex);
    return true;
  }

  return false;
}

bool CRegexAscii_piece::match_piece_times(const char *source, 
                                          int *piecelen, 
                                          int times,
                                          std::vector<std::pair<int,int> >    *match_lens)
{
  int i=0;
  if(match_lens && match_lens->size())
  {
    i = match_lens->size()-1;
  }
  if(match_lens && match_lens->size())
    *piecelen = match_lens->at(match_lens->size()-1).first;
  else
    *piecelen = 0;
  if((times >= 0) && (i>=times))
    return true;
  for(;(times < 0) || (i<times);i++)
  {
    int   atomlen;
    int   start_from_branch = 0;
    if(match_lens && (i<(int)match_lens->size()))
      start_from_branch = match_lens->at(i).second;
    bool first_branch = (start_from_branch == 0);
    if(!atom->match(source+*piecelen, &start_from_branch, &atomlen, empty_pieces.begin(), empty_pieces.end()))
    {
      if(match_lens)
      {
        if(i >= (int)match_lens->size())
          match_lens->push_back(std::pair<int,int>(*piecelen, 0));
        else
          (*match_lens)[i] = std::pair<int,int>(*piecelen, 0);
      }
      return false;
    }
    if(match_lens)
    {
      if(i >= (int)match_lens->size())
        match_lens->push_back(std::pair<int,int>(*piecelen, start_from_branch));
      else
        (*match_lens)[i] = std::pair<int,int>(*piecelen, start_from_branch);
    }
    *piecelen += atomlen;
    if(!atomlen && !source[*piecelen])
    {
      atom->regex_intern->reachedEnd = true;
      break;
    }
    if(first_branch && (atomlen == 0))//avoid infinite loop
    {
      break;
    }
  }
  if(match_lens)
  {
  //  if(i >= match_lens->size())
      match_lens->push_back(std::pair<int,int>(*piecelen, 0));
  //  else
  //    (*match_lens)[i] = std::pair<int,int>(*piecelen, 0);
  }

  return true;
}

//match any of chargroups
bool CRegexAscii_chargroup::match_internal(const char *source, int *start_from_branch, int *matched_len)
{
  *matched_len = 0;
  std::list<chargroup_t>::iterator  cgt_it;

  if(!source[0])
  {
    regex_intern->reachedEnd = true;
    if(chargroup_list.empty())
      return true;
    else if((chargroup_list.size() == 1) && (chargroup_list.begin()->flags == CHARGROUP_FLAGS_ENDLINE))
      return true;
    else
      return false;
  }

  if((source[0] == 0x0A) || ((source[0] == 0x0D) && (source[1] == 0x0A)))
  {
    if((regex_intern->flags & REGEX_ASCII_MULTILINE) &&
        (chargroup_list.size() == 1) && (chargroup_list.begin()->flags == CHARGROUP_FLAGS_ENDLINE))
    {
      //*matched_len = 1;
      return true;
    }
  }

  bool found = false;
  for(cgt_it = chargroup_list.begin(); cgt_it != chargroup_list.end(); cgt_it++)
  {
    switch(cgt_it->flags&0x7F)
    {
    case CHARGROUP_FLAGS_MULTICHAR_p:
      switch(cgt_it->c1)
      {
      case unicode::UNICODE_Ll + 50:
        if(unicode::check_codepoint_category(source[0], unicode::UNICODE_Ll) ||
           unicode::check_codepoint_category(source[0], unicode::UNICODE_Lm) ||
           unicode::check_codepoint_category(source[0], unicode::UNICODE_Lo) ||
           unicode::check_codepoint_category(source[0], unicode::UNICODE_Lt) ||
           unicode::check_codepoint_category(source[0], unicode::UNICODE_Lu))
        {
          if(!(cgt_it->flags & 0x80))
            found = true;
        }
        else
        {
          if(cgt_it->flags & 0x80)
            found = true;
        }
        break;
      case unicode::UNICODE_Mc + 50:
        if(unicode::check_codepoint_category(source[0], unicode::UNICODE_Mn) ||
           unicode::check_codepoint_category(source[0], unicode::UNICODE_Mc) ||
           unicode::check_codepoint_category(source[0], unicode::UNICODE_Me))
        {
          if(!(cgt_it->flags & 0x80))
            found = true;
        }
        else
        {
          if(cgt_it->flags & 0x80)
            found = true;
        }
        break;
      case unicode::UNICODE_Nd + 50:
        if(unicode::check_codepoint_category(source[0], unicode::UNICODE_Nd) ||
           unicode::check_codepoint_category(source[0], unicode::UNICODE_Nl) ||
           unicode::check_codepoint_category(source[0], unicode::UNICODE_No))
        {
          if(!(cgt_it->flags & 0x80))
            found = true;
        }
        else
        {
          if(cgt_it->flags & 0x80)
            found = true;
        }
        break;
      case unicode::UNICODE_Pc + 50:
        if(unicode::check_codepoint_category(source[0], unicode::UNICODE_Pc) ||
           unicode::check_codepoint_category(source[0], unicode::UNICODE_Pd) ||
           unicode::check_codepoint_category(source[0], unicode::UNICODE_Ps) ||
           unicode::check_codepoint_category(source[0], unicode::UNICODE_Pe) ||
           unicode::check_codepoint_category(source[0], unicode::UNICODE_Pi) ||
           unicode::check_codepoint_category(source[0], unicode::UNICODE_Pf) ||
           unicode::check_codepoint_category(source[0], unicode::UNICODE_Po))
        {
          if(!(cgt_it->flags & 0x80))
            found = true;
        }
        else
        {
          if(cgt_it->flags & 0x80)
            found = true;
        }
        break;
      case unicode::UNICODE_Zl + 50:
        if(unicode::check_codepoint_category(source[0], unicode::UNICODE_Zs) ||
           unicode::check_codepoint_category(source[0], unicode::UNICODE_Zl) ||
           unicode::check_codepoint_category(source[0], unicode::UNICODE_Zp))
        {
          if(!(cgt_it->flags & 0x80))
            found = true;
        }
        else
        {
          if(cgt_it->flags & 0x80)
            found = true;
        }
        break;
      case unicode::UNICODE_Sc + 50:
        if(unicode::check_codepoint_category(source[0], unicode::UNICODE_Sm) ||
           unicode::check_codepoint_category(source[0], unicode::UNICODE_Sc) ||
           unicode::check_codepoint_category(source[0], unicode::UNICODE_Sk) ||
           unicode::check_codepoint_category(source[0], unicode::UNICODE_So))
        {
          if(!(cgt_it->flags & 0x80))
            found = true;
        }
        else
        {
          if(cgt_it->flags & 0x80)
            found = true;
        }
        break;
      case unicode::UNICODE_Cc + 50:
        if(unicode::check_codepoint_category(source[0], unicode::UNICODE_Cc) ||
           unicode::check_codepoint_category(source[0], unicode::UNICODE_Cf) ||
           unicode::check_codepoint_category(source[0], unicode::UNICODE_Co))//ignore unicode::UNICODE_Cn
        {
          if(!(cgt_it->flags & 0x80))
            found = true;
        }
        else
        {
          if(cgt_it->flags & 0x80)
            found = true;
        }
        break;
      default:
        if(unicode::check_codepoint_category(source[0], (unicode::category)cgt_it->c1))
        {
          if(!(cgt_it->flags & 0x80))
            found = true;
        }
        else
        {
          if(cgt_it->flags & 0x80)
            found = true;
        }
        break;
      }break;
    case CHARGROUP_FLAGS_MULTICHAR_Is:
    {
      const unicode::code_point *cp = block_escape[cgt_it->c1].cp;
      if(((unicode::code_point)source[0] >= cp[0]) && 
        ((unicode::code_point)source[0] <= cp[1]))
      {
        if(!(cgt_it->flags & 0x80))
          found = true;
      }
      else if(block_escape[cgt_it->c1].ext_cp)
      {
        cp = block_escape[cgt_it->c1].ext_cp;
        while(*cp)
        {
          if(((unicode::code_point)source[0] >= cp[0]) && 
            ((unicode::code_point)source[0] <= cp[1]))
            break;
          cp += 2;
        }
        if(*cp)
        {
          if(!(cgt_it->flags & 0x80))
            found = true;
        }
        else
        {
          if(cgt_it->flags & 0x80)
            found = true;
        }
      }
      else
      {
        if(cgt_it->flags & 0x80)
          found = true;
      }
    }break;
    case CHARGROUP_FLAGS_MULTICHAR_OTHER:
    {
      bool value_true = true;
      switch(cgt_it->c1)
      {
        case 'S':value_true = false;//[^\s]
        case 's'://[#x20\t\n\r]
          switch(source[0])
          {
          case '\t':
          case '\r':
          case '\n':
          case ' ':
            found = true;
          default:
            break;
          }
          break;
        case 'I':value_true = false;//[^\i]
        case 'i'://the set of initial name characters, those matched by Letter | '_' | ':'
          if((source[0] == '_') ||
            (source[0] == ':') ||
            XQCharType::isLetter(source[0]))
          {
            found = true;
          }
          break;
        case 'C':value_true = false;//[^\c]
        case 'c'://the set of name characters, those matched by NameChar
          if(XQCharType::isNameChar(source[0]))
          {
            found = true;
          }
          break;
        case 'D':value_true = false;//[^\d]
        case 'd':
          if(unicode::check_codepoint_category(source[0], unicode::UNICODE_Nd))
            found = true;
          break;
        case 'W':value_true = false;//[^\w]
        case 'w':
         found = !(unicode::check_codepoint_category(source[0], unicode::UNICODE_Pc) ||
                   unicode::check_codepoint_category(source[0], unicode::UNICODE_Pd) ||
                   unicode::check_codepoint_category(source[0], unicode::UNICODE_Ps) ||
                   unicode::check_codepoint_category(source[0], unicode::UNICODE_Pe) ||
                   unicode::check_codepoint_category(source[0], unicode::UNICODE_Pi) ||
                   unicode::check_codepoint_category(source[0], unicode::UNICODE_Pf) ||
                   unicode::check_codepoint_category(source[0], unicode::UNICODE_Po) ||
                   unicode::check_codepoint_category(source[0], unicode::UNICODE_Zs) ||
                   unicode::check_codepoint_category(source[0], unicode::UNICODE_Zl) ||
                   unicode::check_codepoint_category(source[0], unicode::UNICODE_Zp) ||
                   unicode::check_codepoint_category(source[0], unicode::UNICODE_Cc) ||
                   unicode::check_codepoint_category(source[0], unicode::UNICODE_Cf) ||
                   unicode::check_codepoint_category(source[0], unicode::UNICODE_Co));//ignore unicode::UNICODE_Cn
          break;
        default:
          throw XQUERY_EXCEPTION( err::FORX0002, ERROR_PARAMS(source, ZED(REGEX_UNIMPLEMENTED)) );
      }
      if((found && value_true) || (!found && !value_true))
      {
        if(!source[0])
          regex_intern->reachedEnd = true;
        *matched_len = 1;
        return true;
      }
      else
        return false;
    }
    case CHARGROUP_FLAGS_ENDLINE:
    {
      return false;
    }
    case CHARGROUP_FLAGS_ONECHAR:
    {
      if(regex_intern->flags & REGEX_ASCII_CASE_INSENSITIVE)
      {
        char  sup = toupper(source[0]);
        if(sup == toupper(cgt_it->c1))
          found = true;
      }
      else
      {
        if(source[0] == cgt_it->c1)
          found = true;
      }
      break;
    }
    default:
    {
      if(regex_intern->flags & REGEX_ASCII_CASE_INSENSITIVE)
      {
        char  sup = toupper(source[0]);
        if((sup >= toupper(cgt_it->c1)) &&
          (sup <= toupper(cgt_it->c2)))
          found = true;
      }
      else
      {
        if((source[0] >= cgt_it->c1) &&
          (source[0] <= cgt_it->c2))
          found = true;
      }
      break;
    }
    }
    if(found)
      break;
  }
  if(cgt_it == chargroup_list.end())
    return false;

  if(classsub)
  {
    int   classsub_len;
    if(classsub->match_internal(source, NULL, &classsub_len))
      return false;
  }

  *matched_len = 1;
  return true;
}

bool CRegexAscii_negchargroup::match_internal(const char *source, int *start_from_branch, int *matched_len)
{
  if(!source[0])
  {
    regex_intern->reachedEnd = true;
    return false;
  }
  if(!CRegexAscii_chargroup::match_internal(source, start_from_branch, matched_len))
  {
    *matched_len = 1;
    return true;
  }
  return false;
}

bool CRegexAscii_wildchar::match_internal(const char *source, int *start_from_branch, int *matched_len)
{
  *matched_len = 0;
  if(source[0])
  {
    if((regex_intern->flags & REGEX_ASCII_DOTALL) || 
      (source[0] != '\n') && (source[0] != '\r'))
    {
      *matched_len = 1;
      return true;
    }
    else
      return false;
  }
  else
  {
    if(!source[0])
      regex_intern->reachedEnd = true;
    *matched_len = 0;
    return false;
  }
}

bool CRegexAscii_backref::match_internal(const char *source, int *start_from_branch, int *matched_len)
{
  const char *submatch = regex_intern->subregex.at(backref-1)->matched_source;
  if(!submatch)
  {
    *matched_len = 0;
    return true;
  }
  *matched_len = regex_intern->subregex.at(backref-1)->matched_len;
  if(regex_intern->flags & REGEX_ASCII_CASE_INSENSITIVE)
  {
    if(compare_ni(source, submatch, *matched_len)) 
    {
      return true;
    }
  }
  else
  {
    if(!strncmp(source, submatch, *matched_len))
    {
      return true;
    }
  }
  *matched_len = 0;
  return false;
}

bool CRegexAscii_pinstart::match_internal(const char *source, int *start_from_branch, int *matched_len)
{
  *matched_len = 0;
  if(source == regex_intern->source_start)
    return true;
  if((regex_intern->flags & REGEX_ASCII_MULTILINE) &&
    ((source[-1] == '\n') || (source[-1] == '\r')))
    return true;
  
  return false;
}

  }//end namespace regex_ascii
}//end namespace zorba
/* vim:set et sw=2 ts=2: */
