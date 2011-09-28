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

#include <vector>

#include <zorba/config.h>

#include "common/shared_types.h"

#include "diagnostics/assert.h"
#include "diagnostics/xquery_diagnostics.h"
#include "zorbatypes/zorbatypes_decl.h"
#include "zorbatypes/numconversions.h"

#include "system/globalenv.h"

#include "util/tracer.h"
#include "util/ascii_util.h"
#include "util/utf8_string.h"
#include "util/unicode_categories.h"

#include "types/casting.h"
#include "types/typeconstants.h"
#include "types/typeops.h"

#include "context/static_context.h"

// TODO: remove, debugging purposes only
#include "context/dynamic_context.h"

#include "compiler/api/compilercb.h"

#include "runtime/numerics/numerics.h"
#include "runtime/visitors/planiter_visitor.h"
#include "runtime/core/arithmetic_impl.h"

#include "store/api/item_factory.h"
#include "store/api/item.h"

namespace zorba
{

xs_integer FormatIntegerIterator::StringToXsInteger(const char *str)
{
  return xs_integer(str);
}

void FormatIntegerIterator::checkOptionalModifier(utf8_string<zstring> &utf8_picture, 
                                  unsigned int off, 
                                  bool *is_ordinal, 
                                  bool *is_traditional,
                                  utf8_string<zstring> &word_terminal)
{
  size_t    picture_size = utf8_picture.size();
  *is_ordinal = false;
  *is_traditional = false;
  unsigned int i=0;
  bool is_ordinal_set = false;
  bool is_traditional_set = false;
  utf8_string<zstring>::value_type    c;
  for(i=0;i<2;i++)
  {
    if(picture_size <= (off+i))
      return;
    c = utf8_picture[off+i];
    switch(c)
    {
    case 'c': 
      if(is_ordinal_set)
      {
        throw XQUERY_EXCEPTION(err::FOFI0002, ERROR_PARAMS(ZED(format_integer_duplicated_optional_format_modifier), (char)c));
      }
      is_ordinal_set = true;
      *is_ordinal = false;
      break;
    case 'o': 
      if(is_ordinal_set)
      {
        throw XQUERY_EXCEPTION(err::FOFI0002, ERROR_PARAMS(ZED(format_integer_duplicated_optional_format_modifier), (char)c));
      }
      is_ordinal_set = true;
      *is_ordinal = true;
      break;
    case 'a': 
      if(is_traditional_set)
      {
        throw XQUERY_EXCEPTION(err::FOFI0002, ERROR_PARAMS(ZED(format_integer_duplicated_optional_format_modifier), (char)c));
      }
      is_traditional_set = true;
      *is_traditional = false;
      break;
    case 't': 
      if(is_traditional_set)
      {
        throw XQUERY_EXCEPTION(err::FOFI0002, ERROR_PARAMS(ZED(format_integer_duplicated_optional_format_modifier), (char)c));
      }
      is_traditional_set = true;
      *is_traditional = true;
      break;
    default:
      throw XQUERY_EXCEPTION(err::FOFI0002, ERROR_PARAMS(ZED(format_integer_unknown_optional_format_modifier_character), (char)c));
    }
  }
  if(picture_size <= (off+i))
    return;
  c = utf8_picture[off+i];
  if(c != '(')
  {
    throw XQUERY_EXCEPTION(err::FOFI0002, ERROR_PARAMS(ZED(format_integer_unknown_optional_format_modifier_character), (char)c));
  }
  i++;
  bool has_dash = false;
  while((off+i) < picture_size)
  {
    c = utf8_picture[off+i];
    if(c == ')')
      break;
    if(c == '-')
    {
      if(has_dash)
      {
        throw XQUERY_EXCEPTION(err::FOFI0002, ERROR_PARAMS(ZED(format_integer_unknown_optional_format_modifier_character), (char)c));
      }
      has_dash = true;
    }
    else if(has_dash)
      word_terminal += c;
    i++;
  }
  if((off+i) >= picture_size)
  {
    throw XQUERY_EXCEPTION(err::FOFI0002, ERROR_PARAMS(ZED(format_integer_optional_format_modifier_not_closed), utf8_picture));
  }
  i++;
  if((off+i) < picture_size)
  {
    throw XQUERY_EXCEPTION(err::FOFI0002, ERROR_PARAMS(ZED(format_integer_unknown_optional_format_modifier_character), (char)utf8_picture[off+i]));
  }
}

/*
  represent integer as sequence of letters A, B, ... Z, AA, AB, ....
  'A' is 1
  0 is empty string
  The sequence includes the characters 'I' and 'O'
  There is no upper limit for the input integer
*/
void FormatIntegerIterator::formatIntegerAZ(xs_integer valueInteger, char c0, zstring &resultString)
{
  static const unsigned int letter_range = 'Z' - 'A' + 1;
  static xs_integer integer_digit(letter_range);
  xs_integer  upper_int = valueInteger/integer_digit;
  if(upper_int > xs_integer::zero())
    formatIntegerAZ(upper_int - xs_integer::one(), c0, resultString);
  xs_integer  mod_integer = valueInteger % integer_digit;
  xs_int      mod_int = to_xs_int(mod_integer);
  resultString += (c0 + mod_int);
}

void FormatIntegerIterator::formatIntegerRoman(xs_integer valueInteger, zstring &resultString)
{
  static xs_integer integer_3000(3000);
  static xs_integer integer_1000(1000);
  static xs_integer integer_900(900);
  static xs_integer integer_800(800);
  static xs_integer integer_700(700);
  static xs_integer integer_600(600);
  static xs_integer integer_500(500);
  static xs_integer integer_400(400);
  static xs_integer integer_300(300);
  static xs_integer integer_200(200);
  static xs_integer integer_100(100);
  static xs_integer integer_90(90);
  static xs_integer integer_80(80);
  static xs_integer integer_70(70);
  static xs_integer integer_60(60);
  static xs_integer integer_50(50);
  static xs_integer integer_40(40);
  static xs_integer integer_30(30);
  static xs_integer integer_20(20);
  static xs_integer integer_10(10);
  static xs_integer integer_9(9);
  static xs_integer integer_8(8);
  static xs_integer integer_7(7);
  static xs_integer integer_6(6);
  static xs_integer integer_5(5);
  static xs_integer integer_4(4);
  static xs_integer integer_3(3);
  static xs_integer integer_2(2);
  static xs_integer integer_1(1);

  if (valueInteger > integer_3000)
  {
    throw XQUERY_EXCEPTION(err::FOFI0002, ERROR_PARAMS(ZED(format_integer_value_gt_3000), valueInteger));
  }
  else if (valueInteger >= integer_1000)
  {
    resultString += "M";
    formatIntegerRoman(valueInteger - integer_1000, resultString);
  }
  else if (valueInteger >= integer_900)
  {
    resultString += "CM";
    formatIntegerRoman(valueInteger - integer_900, resultString);
  }
  else if (valueInteger >= integer_800)
  {
    resultString += "DCCC";
    formatIntegerRoman(valueInteger - integer_800, resultString);
  }
  else if (valueInteger >= integer_700)
  {
    resultString += "DCC";
    formatIntegerRoman(valueInteger - integer_700, resultString);
  }
  else if (valueInteger >= integer_600)
  {
    resultString += "DC";
    formatIntegerRoman(valueInteger - integer_600, resultString);
  }
  else if (valueInteger >= integer_500)
  {
    resultString += "D";
    formatIntegerRoman(valueInteger - integer_500, resultString);
  }
  else if (valueInteger >= integer_400)
  {
    resultString += "CD";
    formatIntegerRoman(valueInteger - integer_400, resultString);
  }
  else if (valueInteger >= integer_300)
  {
    resultString += "CCC";
    formatIntegerRoman(valueInteger - integer_300, resultString);
  }
  else if (valueInteger >= integer_200)
  {
    resultString += "CC";
    formatIntegerRoman(valueInteger - integer_200, resultString);
  }
  else if (valueInteger >= integer_100)
  {
    resultString += "C";
    formatIntegerRoman(valueInteger - integer_100, resultString);
  }
  else if (valueInteger >= integer_90)
  {
    resultString += "XC";
    formatIntegerRoman(valueInteger - integer_90, resultString);
  }
  else if (valueInteger >= integer_80)
  {
    resultString += "LXXX";
    formatIntegerRoman(valueInteger - integer_80, resultString);
  }
  else if (valueInteger >= integer_70)
  {
    resultString += "LXX";
    formatIntegerRoman(valueInteger - integer_70, resultString);
  }
  else if (valueInteger >= integer_60)
  {
    resultString += "LX";
    formatIntegerRoman(valueInteger - integer_60, resultString);
  }
  else if (valueInteger >= integer_50)
  {
    resultString += "L";
    formatIntegerRoman(valueInteger - integer_50, resultString);
  }
  else if (valueInteger >= integer_40)
  {
    resultString += "XL";
    formatIntegerRoman(valueInteger - integer_40, resultString);
  }
  else if (valueInteger >= integer_30)
  {
    resultString += "XXX";
    formatIntegerRoman(valueInteger - integer_30, resultString);
  }
  else if (valueInteger >= integer_20)
  {
    resultString += "XX";
    formatIntegerRoman(valueInteger - integer_20, resultString);
  }
  else if (valueInteger >= integer_10)
  {
    resultString += "X";
    formatIntegerRoman(valueInteger - integer_10, resultString);
  }
  else if (valueInteger == integer_9)
  {
    resultString += "IX";
  }
  else if (valueInteger == integer_8)
  {
    resultString += "VIII";
  }
  else if (valueInteger == integer_7)
  {
    resultString += "VII";
  }
  else if (valueInteger == integer_6)
  {
    resultString += "VI";
  }
  else if (valueInteger == integer_5)
  {
    resultString += "V";
  }
  else if (valueInteger == integer_4)
  {
    resultString += "IV";
  }
  else if (valueInteger == integer_3)
  {
    resultString += "III";
  }
  else if (valueInteger == integer_2)
  {
    resultString += "II";
  }
  else if (valueInteger == integer_1)
  {
    resultString += "I";
  }
}

void FormatIntegerIterator::formatIntegerEnglish(xs_integer valueInteger, bool is_ordinal, zstring &resultString)
{
  //10^303
#ifdef ZORBA_WITH_BIG_INTEGER
  static xs_integer integer_centillion =     StringToXsInteger("1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
  //10^63
  static xs_integer integer_vigintillion =   StringToXsInteger("1000000000000000000000000000000000000000000000000000000000000000");
  //10^60
  static xs_integer integer_novemdecillion = StringToXsInteger("1000000000000000000000000000000000000000000000000000000000000");
  //10^57
  static xs_integer integer_octodecillion =  StringToXsInteger("1000000000000000000000000000000000000000000000000000000000");
  //10^54
  static xs_integer integer_septendecillion =StringToXsInteger("1000000000000000000000000000000000000000000000000000000");
  //10^51
  static xs_integer integer_sexdecillion =   StringToXsInteger("1000000000000000000000000000000000000000000000000000");
  //10^48
  static xs_integer integer_quindecillion =  StringToXsInteger("1000000000000000000000000000000000000000000000000");
  //10^45
 static xs_integer integer_quattuordecillion=StringToXsInteger("1000000000000000000000000000000000000000000000");
  //10^42
  static xs_integer integer_tredecillion =   StringToXsInteger("1000000000000000000000000000000000000000000");
  //10^39
  static xs_integer integer_duodecillion =   StringToXsInteger("1000000000000000000000000000000000000000");
  //10^36
  static xs_integer integer_undecillion =    StringToXsInteger("1000000000000000000000000000000000000");
  //10^33
  static xs_integer integer_decillion =      StringToXsInteger("1000000000000000000000000000000000");
  //10^30
  static xs_integer integer_nonillion =      StringToXsInteger("1000000000000000000000000000000");
  //10^27
  static xs_integer integer_octillion =      StringToXsInteger("1000000000000000000000000000");
  //10^24
  static xs_integer integer_septillion =     StringToXsInteger("1000000000000000000000000");
  //10^21
  static xs_integer integer_sextillion =     StringToXsInteger("1000000000000000000000");
#endif /* ZORBA_WITH_BIG_INTEGER */
  //10^18
  static xs_integer integer_quintillion =    StringToXsInteger("1000000000000000000");
  //10^15
  static xs_integer integer_quadrillion =    StringToXsInteger("1000000000000000");
  //10^12
  static xs_integer integer_trillion =       StringToXsInteger("1000000000000");
  //10^9
  static xs_integer integer_billion(1000000000);
  //10^6
  static xs_integer integer_million(1000000);
  //10^3
  static xs_integer integer_thousand(1000);
  //10^2
  static xs_integer integer_hundred(100);
  static xs_integer integer_90(90);
  static xs_integer integer_80(80);
  static xs_integer integer_70(70);
  static xs_integer integer_60(60);
  static xs_integer integer_50(50);
  static xs_integer integer_40(40);
  static xs_integer integer_30(30);
  static xs_integer integer_20(20);
  static xs_integer integer_19(19);
  static xs_integer integer_18(18);
  static xs_integer integer_17(17);
  static xs_integer integer_16(16);
  static xs_integer integer_15(15);
  static xs_integer integer_14(14);
  static xs_integer integer_13(13);
  static xs_integer integer_12(12);
  static xs_integer integer_11(11);
  static xs_integer integer_10(10);
  static xs_integer integer_9(9);
  static xs_integer integer_8(8);
  static xs_integer integer_7(7);
  static xs_integer integer_6(6);
  static xs_integer integer_5(5);
  static xs_integer integer_4(4);
  static xs_integer integer_3(3);
  static xs_integer integer_2(2);
  static xs_integer integer_1(1);

  xs_integer  value_mod;

#define IF_GE(big_number_name)                                                            \
  else if (valueInteger >= integer_##big_number_name)                                      \
  {                                                                                       \
  formatIntegerEnglish(valueInteger/integer_##big_number_name, false, resultString);     \
    resultString += " " #big_number_name;                                                \
    value_mod = valueInteger % integer_##big_number_name;                                  \
    if(value_mod > xs_integer::zero())                                    \
    {                                                                                     \
      resultString += " ";                                                                \
      formatIntegerEnglish(value_mod, is_ordinal, resultString);                          \
    }                                                                                     \
    else if(is_ordinal)                                                                   \
      resultString += "th";                                                               \
  }

#define IF_GE_DECIM(decim, decim_cardinal, decim_ordinal)                       \
  else if (valueInteger >= integer_##decim)                                     \
  {                                                                             \
  value_mod = valueInteger % integer_##decim;                                   \
    if(value_mod > xs_integer::zero())                          \
    {                                                                           \
      resultString += decim_cardinal;                                           \
      resultString += "-";                                                      \
      formatIntegerEnglish(value_mod, is_ordinal, resultString);                \
    }                                                                           \
    else if(!is_ordinal)                                                        \
      resultString += decim_cardinal;                                           \
    else                                                                        \
      resultString += decim_ordinal;                                            \
  }

  if(0);
#ifdef ZORBA_WITH_BIG_INTEGER
  IF_GE(centillion)
  IF_GE(vigintillion)
  IF_GE(novemdecillion)
  IF_GE(octodecillion)
  IF_GE(septendecillion)
  IF_GE(sexdecillion)
  IF_GE(quindecillion)
  IF_GE(quattuordecillion)
  IF_GE(tredecillion)
  IF_GE(duodecillion)
  IF_GE(undecillion)
  IF_GE(decillion)
  IF_GE(nonillion)
  IF_GE(octillion)
  IF_GE(septillion)
  IF_GE(sextillion)
#endif /* ZORBA_WITH_BIG_INTEGER */
  IF_GE(quintillion)
  IF_GE(quadrillion)
  IF_GE(trillion)
  IF_GE(billion)
  IF_GE(million)
  IF_GE(thousand)
  IF_GE(hundred)
  IF_GE_DECIM(90, "ninety", "ninetieth")
  IF_GE_DECIM(80, "eighty", "eightieth")
  IF_GE_DECIM(70, "seventy","seventieth")
  IF_GE_DECIM(60, "sixty",  "sixtieth")
  IF_GE_DECIM(50, "fifty",  "fiftieth")
  IF_GE_DECIM(40, "forty", "fortieth")
  IF_GE_DECIM(30, "thirty", "thirtieth")
  IF_GE_DECIM(20, "twenty", "twentieth")
  IF_GE_DECIM(19, "nineteen", "nineteenth")
  IF_GE_DECIM(18, "eighteen", "eighteenth")
  IF_GE_DECIM(17, "seventeen", "seventeenth")
  IF_GE_DECIM(16, "sixteen", "sixteenth")
  IF_GE_DECIM(15, "fifteen", "fifteenth")
  IF_GE_DECIM(14, "fourteen", "fourteenth")
  IF_GE_DECIM(13, "thirteen", "thirteenth")
  IF_GE_DECIM(12, "twelve", "twelfth")
  IF_GE_DECIM(11, "eleven", "eleventh")
  IF_GE_DECIM(10, "ten", "tenth")
  IF_GE_DECIM(9, "nine", "ninth")
  IF_GE_DECIM(8, "eight", "eighth")
  IF_GE_DECIM(7, "seven", "seventh")
  IF_GE_DECIM(6, "six", "sixth")
  IF_GE_DECIM(5, "five", "fifth")
  IF_GE_DECIM(4, "four", "fourth")
  IF_GE_DECIM(3, "three", "third")
  IF_GE_DECIM(2, "two", "second")
  IF_GE_DECIM(1, "one", "first")
  else if (valueInteger == xs_integer::zero())
  {
    if(!is_ordinal)
      resultString += "zero";
    else
      resultString += "zeroth";
  }
}

bool FormatIntegerIterator::isDecimalDigitPattern(utf8_string<zstring> &utf8_picture,
                                  unsigned int *picture_size, 
                                  unsigned int *groupingInterval,
                                  utf8_string<zstring>::value_type *groupingChar,
                                  utf8_string<zstring>::value_type *utf8zero)
{
  //first char is either optional digit # or mandatory digit
  size_t  all_size = utf8_picture.size();
  if(all_size == 0)
    return false;
  *picture_size = all_size;
  *groupingInterval = 0;
  *utf8zero = 0;
  utf8_string<zstring>::value_type  prev_groupingChar = 0;
  unsigned int prev_grouping_pos = 0;
  bool can_have_grouping_interval = true;
  utf8_string<zstring>::const_iterator  pictureit;
  bool is_optional = false;
  bool prev_is_grouping = false;
  bool has_digits = false;
  unsigned int pos;
  unicode::code_point  zerotemp;
  //c = utf8_picture[0];
  pictureit = utf8_picture.begin();
  if(*pictureit == '#')
    is_optional = true;
  else if(unicode::is_UnicodeNd(*pictureit, &zerotemp))
  {
    *utf8zero = zerotemp;
    has_digits = true;
  }
  else
    return false;
  pos = 1;
  pictureit++;
  while(pos < all_size)
  {
    if(*pictureit == '#')
    {
      if(has_digits)
        return false;
      prev_is_grouping = false;
    }
    else if(unicode::is_UnicodeNd(*pictureit, &zerotemp))
    {
      if(*utf8zero)
      {
        if(*utf8zero != zerotemp)
          return false;
      }
      else
        *utf8zero = zerotemp;
      is_optional = false;
      has_digits = true;
      prev_is_grouping = false;
    }
    else if(!check_codepoint_category(*pictureit, unicode::UNICODE_Nd) &&
            !check_codepoint_category(*pictureit, unicode::UNICODE_Nl) &&
            !check_codepoint_category(*pictureit, unicode::UNICODE_No) &&
            !check_codepoint_category(*pictureit, unicode::UNICODE_Lu) &&
            !check_codepoint_category(*pictureit, unicode::UNICODE_Ll) &&
            !check_codepoint_category(*pictureit, unicode::UNICODE_Lt) &&
            !check_codepoint_category(*pictureit, unicode::UNICODE_Lm) &&
            !check_codepoint_category(*pictureit, unicode::UNICODE_Lo))
    {
      //is grouping
      if(prev_is_grouping)
        return false;
      prev_is_grouping = true;
      if(prev_groupingChar)
      {
        if(prev_groupingChar == *pictureit)
        {
          if(*groupingInterval)
          {
            if((pos - prev_grouping_pos) == *groupingInterval)
              prev_grouping_pos = pos;
            else
            {
              *groupingInterval = 0;
              can_have_grouping_interval = false;
            }
          }
          else if(can_have_grouping_interval)
          {
            *groupingInterval = pos - prev_grouping_pos;
            if(prev_grouping_pos > *groupingInterval)
            {
              can_have_grouping_interval = false;
              *groupingInterval = 0;
            }
            else
              prev_grouping_pos = pos;
          }
        }
        else
        {
          *groupingInterval = 0;
          can_have_grouping_interval = false;
        }
      }
      else
      {
        prev_groupingChar = *pictureit;
        prev_grouping_pos = pos;
      }
    }
    else
    {
      //possibly end of primary token
      break;
    }
    pictureit++;
    pos++;
  }
  if(prev_is_grouping)
    return false;
  if(!has_digits && !is_optional)
    return false;
  *picture_size = pos;
  if(!*utf8zero)
    *utf8zero = '0';//default
  if(can_have_grouping_interval && prev_groupingChar)
  {
    if(*groupingInterval)
    {
      if(*groupingInterval != (pos - prev_grouping_pos))
        *groupingInterval = 0;
    }
    else
    {
      *groupingInterval = pos - prev_grouping_pos;
      if(prev_grouping_pos > *groupingInterval)
        *groupingInterval = 0;
    }
  }
  else
    *groupingInterval = 0;
  *groupingChar = prev_groupingChar;
  return true;
}

void FormatIntegerIterator::formatIntegerDecimalPattern(zstring::const_reverse_iterator   valueit, 
                            zstring::const_reverse_iterator   &valueit_rend, 
                            std::vector<unicode::code_point>::const_reverse_iterator  pictureit, 
                            std::vector<unicode::code_point>::const_reverse_iterator  &pictureit_rend, 
                            unsigned int picture_pos,
                            unsigned int grouping_interval, 
                            utf8_string<zstring>::value_type grouping_char,
                            utf8_string<zstring>::value_type utf8zero, 
                            utf8_string<zstring> &utf8_result)
{
  if(valueit == valueit_rend)
  {
    if((pictureit == pictureit_rend) || (*pictureit == '#'))
      return;
  }
  if(grouping_interval && !((picture_pos+1)%grouping_interval))
  {
    if((pictureit != pictureit_rend) && (*pictureit == grouping_char))
    {
      pictureit++;//ignore it automatically
      if(valueit == valueit_rend)
      {
        if((pictureit == pictureit_rend) || (*pictureit == '#'))
          return;
      }
    }
    formatIntegerDecimalPattern(valueit, valueit_rend, pictureit, pictureit_rend, picture_pos+1, grouping_interval, grouping_char, utf8zero, utf8_result);
    utf8_result += (grouping_char);
    return;
  }

  if(valueit == valueit_rend)
  {
    if(unicode::check_codepoint_category(*pictureit, unicode::UNICODE_Nd))
    {
      formatIntegerDecimalPattern(valueit, valueit_rend, pictureit+1, pictureit_rend, picture_pos+1, grouping_interval, grouping_char, utf8zero, utf8_result);
      utf8_result += (utf8zero);
      return;
    }
    else
      return;//it is grouping char
  }
  else
  {
    if(pictureit != pictureit_rend)
    {
      if(*pictureit == '#' || unicode::check_codepoint_category(*pictureit, unicode::UNICODE_Nd))
      {
        formatIntegerDecimalPattern(valueit+1, valueit_rend, pictureit+1, pictureit_rend, picture_pos+1, grouping_interval, grouping_char, utf8zero, utf8_result);
        utf8_result += (utf8zero + *valueit - '0');
        return;
      }
      else
      {
        formatIntegerDecimalPattern(valueit, valueit_rend, pictureit+1, pictureit_rend, picture_pos+1, grouping_interval, grouping_char, utf8zero, utf8_result);
        utf8_result += (*pictureit);
        return;
      }
    }
    else
    {
      formatIntegerDecimalPattern(valueit+1, valueit_rend, pictureit, pictureit_rend, picture_pos+1, grouping_interval, grouping_char, utf8zero, utf8_result);
      utf8_result += (utf8zero + *valueit - '0');
      return;
    }
  }
}

void   FormatIntegerIterator::addOrdinalEnglish(zstring &valueString, 
                                                unsigned int valuelen, 
                                                utf8_string<zstring> &utf8_result)
{
  if((valuelen >= 2) && (valueString[valuelen - 2] == '1'))
  {
    utf8_result += "th";
  }
  else if(valueString[valuelen-1] == '1')
  {
    utf8_result += "st";
  }
  else if(valueString[valuelen-1] == '2')
  {
    utf8_result += "nd";
  }
  else if(valueString[valuelen-1] == '3')
  {
    utf8_result += "rd";
  }
  else
  {
    utf8_result += "th";
  }
}

bool
FormatIntegerIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t value_item;
  store::Item_t picture_item;
  store::Item_t language_item;
  zstring resultString;
  utf8_string<zstring>    utf8_result(resultString);
  zstring languageString;
  zstring pictureString;
  utf8_string<zstring>  utf8_picture(pictureString);
  xs_integer valueInteger;
  bool  is_neg = false;
  const TypeManager* tm = theSctx->get_typemanager();
  const RootTypeManager& rtm = GENV_TYPESYSTEM;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(value_item, theChildren[0].getp(), planState))
  {
    valueInteger = value_item->getIntegerValue();
    if(valueInteger < xs_integer::zero())
    {
      valueInteger = -valueInteger;
      is_neg = true;
    }
    
    consumeNext(picture_item, theChildren[1].getp(), planState);  
    pictureString = picture_item->getStringValue();
    if(utf8_picture.size() == 0)
    {
      throw XQUERY_EXCEPTION(err::FOFI0002, ERROR_PARAMS(ZED(format_integer_picture_empty)), ERROR_LOC(loc));
    }

    if (theChildren.size() == 3) 
    {
      consumeNext(language_item, theChildren[2].getp(), planState);
      languageString = language_item->getStringValue();
      if(!GenericCast::isCastable(languageString, &*rtm.LANGUAGE_TYPE_ONE, tm))
      {
        throw XQUERY_EXCEPTION(err::FOFI0001, ERROR_PARAMS( languageString ), ERROR_LOC( loc )
        );
      }
    }

    try
    {
      bool is_ordinal = false;
      bool is_traditional = false;
      unsigned int picture_size = 0;
      unsigned int grouping_interval = 0;
      utf8_string<zstring>::value_type    grouping_char;
      utf8_string<zstring>::value_type    c0;
      utf8_string<zstring>::value_type    utf8zero;
      zstring word_terminal;
      utf8_string<zstring> utf8_word_terminal(word_terminal);
      c0 = utf8_picture[0];

      if((c0 == 'a') || (c0 == 'A'))
      {
        checkOptionalModifier(utf8_picture, 1, &is_ordinal, &is_traditional, utf8_word_terminal);
        if(valueInteger > xs_integer::zero())
        {
          if(is_neg)
            resultString += '-';
          formatIntegerAZ(valueInteger-xs_integer::one(), c0, resultString);
        }
      }
      else if((c0 == 'i') || (c0 == 'I'))
      {
        checkOptionalModifier(utf8_picture, 1, &is_ordinal, &is_traditional, utf8_word_terminal);
        if(valueInteger > xs_integer::zero())
        {
          if(is_neg)
            resultString += ("-");
          formatIntegerRoman(valueInteger, resultString);
          if(c0 == 'i')
            ascii::to_lower(resultString);
        }
      }
      else if((c0 == 'w') || (c0 == 'W'))
      {
        utf8_string<zstring>::value_type    c1 = 0;
        bool title_case = false;
        if(utf8_picture.size() > 1)
        {
          c1 = utf8_picture[1];
          if((c0 == 'W') && (c1 == 'w'))
          {
            title_case = true;
            checkOptionalModifier(utf8_picture, 2, &is_ordinal, &is_traditional, utf8_word_terminal);
          }
          else
            checkOptionalModifier(utf8_picture, 1, &is_ordinal, &is_traditional, utf8_word_terminal);
        }
        //only english for now
        if(is_neg)
          resultString = "minus ";
        formatIntegerEnglish(valueInteger, is_ordinal, resultString);
        if(c0 == 'W')
        {
          if(!title_case)
            ascii::to_upper(resultString);
          else if(resultString[0] != '-')
          {
            char cup[2];
            cup[0] = ascii::to_upper(resultString[0]);
            cup[1] = 0;
            resultString.replace(0, 1, cup);
          }
          else
          {
            char cup[2];
            cup[0] = ascii::to_upper(resultString[1]);
            cup[1] = 0;
            resultString.replace(1, 1, cup);
          }
        }
      }
      else if(c0 == 0x2081) //SUBSCRIPT ONE  (decimal, 0-9)
      {
        checkOptionalModifier(utf8_picture, 1, &is_ordinal, &is_traditional, utf8_word_terminal);
        zstring   valueString = valueInteger.toString();
        zstring::iterator   valueit;
        for(valueit = valueString.begin(); valueit != valueString.end(); valueit++)
        {
          if(!isdigit(*valueit))
          {
            utf8_result += (*valueit);
          }
          else
            utf8_result += (0x2080 + *valueit - '0');
        }
      }
      else if((c0 == 0x2460) || //CIRCLED DIGIT ONE  (1-20)
              (c0 == 0x2474) || //PARENTHESIZED DIGIT ONE (1-20)
              (c0 == 0x2488))   //DIGIT ONE FULL STOP (1-20)
      {
        checkOptionalModifier(utf8_picture, 1, &is_ordinal, &is_traditional, utf8_word_terminal);
        xs_int val_int = to_xs_int(valueInteger);
        if((val_int < 1) || (val_int > 20))
        {
          throw XQUERY_EXCEPTION(err::FOFI0002, ERROR_PARAMS(ZED(format_integer_value_1_20), val_int), ERROR_LOC(loc));
        }
        utf8_result += (c0 + val_int - 1);
      }
      else if((c0 == 0x1369) || //ETHIOPIC DIGIT ONE (1-10)
              (c0 == 0x24F5) || //DOUBLE CIRCLED DIGIT ONE (1-10)
              (c0 == 0x2776) || //DINGBAT NEGATIVE CIRCLED DIGIT ONE (1-10)
              (c0 == 0x2780) || //DINGBAT CIRCLED SANS-SERIF DIGIT ONE (1-10)
              (c0 == 0x278A) || //DINGBAT NEGATIVE CIRCLED SANS-SERIF DIGIT ONE (1-10)
              (c0 == 0x3220) || //PARENTHESIZED IDEOGRAPH ONE  (1-10)
              (c0 == 0x3280) || //CIRCLED IDEOGRAPH ONE (1-10)
              (c0 == 0x10107) || //AEGEAN NUMBER ONE (1-10)
              (c0 == 0x10E60) || //RUMI DIGIT ONE (1-10)
              (c0 == 0x11052) || //BRAHMI NUMBER ONE (1-10)
              (c0 == 0x1D360)) //COUNTING ROD UNIT DIGIT ONE (1-10)
      {
        checkOptionalModifier(utf8_picture, 1, &is_ordinal, &is_traditional, utf8_word_terminal);
        xs_int val_int = to_xs_int(valueInteger);
        if((val_int < 1) || (val_int > 10))
        {
          throw XQUERY_EXCEPTION(err::FOFI0002, ERROR_PARAMS(ZED(format_integer_value_1_10), val_int), ERROR_LOC(loc));
        }
        utf8_result += (c0 + val_int - 1);
      }
      else if(isDecimalDigitPattern(utf8_picture, &picture_size, &grouping_interval, &grouping_char, &utf8zero))
      {
        checkOptionalModifier(utf8_picture, picture_size, &is_ordinal, &is_traditional, utf8_word_terminal);

        zstring   valueString = valueInteger.toString();
        zstring::const_reverse_iterator   valueit = valueString.rbegin();
        zstring::const_reverse_iterator   valueit_rend = valueString.rend();
        utf8_string<zstring>::const_iterator    pictureit;
        std::vector<unicode::code_point>        picture_cp;
        for(pictureit = utf8_picture.begin(); pictureit != utf8_picture.end();pictureit++)
        {
          picture_cp.push_back(*pictureit);
        }
        std::vector<unicode::code_point>::const_reverse_iterator       picture_cp_rbegin = picture_cp.rbegin();
        std::vector<unicode::code_point>::const_reverse_iterator       picture_cp_rend = picture_cp.rend();
        picture_cp_rbegin += (utf8_picture.length() - picture_size);
        if(is_neg)
          utf8_result += ("-");
        formatIntegerDecimalPattern(valueit, valueit_rend,
                                   picture_cp_rbegin, picture_cp_rend, 
                                   0,
                                   grouping_interval, grouping_char,
                                   utf8zero, 
                                   utf8_result);
        unsigned int valuelen = valueString.length();
        if(is_ordinal && (utf8zero == '0') && (valuelen >= 1))
        {
          addOrdinalEnglish(valueString, valuelen, utf8_result);
        }
      }
      else
      {
        throw XQUERY_EXCEPTION(err::FOFI0002, ERROR_PARAMS(ZED(format_integer_bad_picture_format), pictureString), ERROR_LOC(loc));
      }
    }
    catch (ZorbaException& e)
    {
      set_source(e, loc);
      throw;
    }
    catch (std::range_error const&re)
    {
      //"FOCA0003", "\"$1\": value too large for integer"
      throw XQUERY_EXCEPTION(err::FOCA0003, ERROR_PARAMS(re.what()), ERROR_LOC(loc));
    }
    STACK_PUSH (GENV_ITEMFACTORY->createString(result, resultString), state);
  
  }
  else
  {
    STACK_PUSH (GENV_ITEMFACTORY->createString(result, resultString), state);
  }
  STACK_END (state);
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
