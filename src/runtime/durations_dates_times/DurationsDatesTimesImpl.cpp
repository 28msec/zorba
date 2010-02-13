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

#include "zorbatypes/datetime.h"
#include "zorbatypes/duration.h"
#include "zorbatypes/numconversions.h"
#include "zorbatypes/datetime/parse.h"

#include "system/globalenv.h"

#include "types/casting.h"

#include "context/static_context.h"
#include "context/dynamic_context.h"

#include "compiler/api/compilercb.h"

#include "runtime/durations_dates_times/DurationsDatesTimesImpl.h"
#include "runtime/core/arithmetic_impl.h"
#include "runtime/api/runtimecb.h"
#include "runtime/visitors/planiter_visitor.h"

#include "store/api/item.h"
#include "store/api/item_factory.h"
#include "store/api/store.h"

namespace zorba
{
SERIALIZABLE_CLASS_VERSIONS(FnDateTimeConstructorIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnDateTimeConstructorIterator)

SERIALIZABLE_CLASS_VERSIONS(FnFormatDateTimeIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnFormatDateTimeIterator)


SERIALIZABLE_CLASS_VERSIONS(FnAdjustToTimeZoneIterator_1)
END_SERIALIZABLE_CLASS_VERSIONS(FnAdjustToTimeZoneIterator_1)

SERIALIZABLE_CLASS_VERSIONS(FnAdjustToTimeZoneIterator_2)
END_SERIALIZABLE_CLASS_VERSIONS(FnAdjustToTimeZoneIterator_2)


BINARY_ACCEPT(FnDateTimeConstructorIterator);

NARY_ACCEPT(FnFormatDateTimeIterator);

UNARY_ACCEPT(FnAdjustToTimeZoneIterator_1);

BINARY_ACCEPT(FnAdjustToTimeZoneIterator_2);



bool FnDateTimeConstructorIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t item0;
  store::Item_t item1;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (!consumeNext(item0, theChild0.getp(), planState) || !consumeNext(item1, theChild1.getp(), planState))
    STACK_PUSH(false, state);
  else
    STACK_PUSH(GENV_ITEMFACTORY->createDateTime(result, item0, item1), state);

  STACK_END (state);
}


/**
 *______________________________________________________________________
 *
 * 10.7.1 fn:adjust-dateTime-to-timezone
 * 10.7.2 fn:adjust-date-to-timezone
 * 10.7.3 fn:adjust-time-to-timezone
 *
 * fn:adjust-dateTime-to-timezone($arg as xs:dateTime?, $timezone as xs:dayTimeDuration?) as xs:dateTime?
 *
 *_______________________________________________________________________*/
bool
FnAdjustToTimeZoneIterator_1::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t item0;
  store::Item_t item1;
  std::auto_ptr<DateTime> dt;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  // If $arg is the empty sequence, then the result is the empty sequence.
  if (!consumeNext(item0, theChild.getp(), planState))
    STACK_PUSH(false, state);
  else
  {
    try
    {
      dt = std::auto_ptr<DateTime>(item0->getDateTimeValue().adjustToTimeZone(
        planState.theRuntimeCB->theDynamicContext->get_implicit_timezone()));
    }
    catch (InvalidTimezoneException)
    {
      ZORBA_ERROR(FODT0003);
    }
    STACK_PUSH(GENV_ITEMFACTORY->createDateTime(result, dt.get()), state);
  }

  STACK_END (state);
}


bool
FnAdjustToTimeZoneIterator_2::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t item0;
  store::Item_t item1;
  bool s1;
  std::auto_ptr<DateTime> dt;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (!consumeNext(item0, theChild0.getp(), planState))
    STACK_PUSH(false, state);
  else
  {
    s1 = consumeNext(item1, theChild1.getp(), planState);
    try
    {
      dt = std::auto_ptr<DateTime>(item0->getDateTimeValue().adjustToTimeZone(!s1 ? NULL : &item1->getDayTimeDurationValue()));
    }
    catch (InvalidTimezoneException)
    {
      ZORBA_ERROR(FODT0003);
    }
    STACK_PUSH(GENV_ITEMFACTORY->createDateTime(result, dt.get()), state);
  }

  STACK_END (state);
}

/**
 *______________________________________________________________________
 *
 * fn:format-dateTime()
 *
 *_______________________________________________________________________*/

class Modifier
{
public:
  xqpStringStore_t presentation_modifier;
  xqpStringStore_t second_modifier;

  // for min_width and max_width
  // -3 means an error in the picture
  // -2 means width modifiers are not specified
  // -1 means '*'
  // >=0 means explicitly specified width
  int min_width_modifier;
  int max_width_modifier;

  Modifier() : presentation_modifier(new xqpStringStore()), second_modifier(new xqpStringStore()),min_width_modifier(-2), max_width_modifier(-2)
	{};
};

static void format_number(xqpStringStore_t& str, long number, Modifier& modifier)
{
  // Presentation modifier can be:
  // 'Ww', "Nn', 'W', 'w', 'N', 'n'
  // 'i', 'I', '1', '00...01'
  // the modifier will not be checked if it is supported or not
  xqpString temp;

  if (modifier.presentation_modifier->bytes() > 0 && modifier.presentation_modifier->byteAt(0) == '0')
  {
    temp.append_in_place(NumConversions::longToStr(number).c_str());
    while (temp.bytes() < modifier.presentation_modifier->bytes())
      temp = "0" + temp;
  }
  else // "1" or fallback
  {
    temp.append_in_place(NumConversions::longToStr(number).c_str());
  }

  if (modifier.second_modifier->byteEqual("o", 1))
  {
    if ((number % 10) == 1 && (number % 100) != 11)
      temp.append_in_place("st");
    else if ((number % 10) == 2 && (number % 100) != 12)
      temp.append_in_place("nd");
    else if ((number % 10) == 3 && (number % 100) != 13)
      temp.append_in_place("rd");
    else
      temp.append_in_place("th");
  }

  if (modifier.min_width_modifier >= 0)
    while (temp.bytes() < (unsigned int)modifier.min_width_modifier)
	  temp = "0" + temp;

  str->append_in_place(temp.c_str());
}


static void format_string_width(
    xqpStringStore_t& destination,
    xqpStringStore_t& source,
    Modifier& modifier)
{
  xqpStringStore temp = *source;
  while (modifier.max_width_modifier > 0 && temp.bytes() < (unsigned int)modifier.max_width_modifier)
	temp.append_in_place(" ");
  destination->append_in_place(temp.c_str());
}


static bool format_string(
    xqpStringStore_t& destination,
    xqpStringStore& source,
    Modifier& modifier)
{
  xqpString temp;
  if (modifier.presentation_modifier->bytes() == 0 ||
      modifier.presentation_modifier->byteEqual("n", 1))
    temp.append_in_place(source.lowercase());
  else if (modifier.presentation_modifier->byteEqual("N", 1))
    temp.append_in_place(source.uppercase());
  else if (modifier.presentation_modifier->byteEqual("Nn", 2))
  {
    temp.append_in_place(source.byteSubstr(0, 1)->uppercase());
    temp.append_in_place(source.byteSubstr(1,source.size()-1)->lowercase());
  }
  else
    return false;

  format_string_width(destination, temp.theStrStore, modifier);
  return true;
}


static bool format_string(
    xqpStringStore_t& destination,
    const char* source,
    Modifier& modifier)
{
  xqpStringStore temp(source);
  return format_string(destination, temp, modifier);
}


static void format_component(
    xqpStringStore_t& destination,
    long number,
    xqpStringStore& source,
    Modifier& modifier)
{
  if (!format_string(destination, source, modifier))
    format_number(destination, number, modifier);
}


static void output_month(
    xqpStringStore_t& destination,
    long number,
    Modifier& modifier)
{
  static const char* month[12]  = { "january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};
  xqpString temp(month[number-1]);
  if (modifier.max_width_modifier > 0 && (unsigned int)modifier.max_width_modifier < temp.size())
    temp = temp.substr(0, modifier.max_width_modifier);

  format_component(destination, number, *temp.theStrStore, modifier);
}


static void output_day_of_week(
    xqpStringStore_t& destination,
    long number,
    Modifier& modifier)
{
  static const char* day[7]  = { "sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday"};
  xqpString temp(day[number]);
  if (modifier.max_width_modifier > 0 && (unsigned int)modifier.max_width_modifier < temp.size())
    temp = temp.substr(0, modifier.max_width_modifier);

  format_component(destination, number, *temp.theStrStore, modifier);
}


static void parse_presentation_modifier(
    xqpStringStore_t& str,
    unsigned int& position,
    xqpStringStore_t& result)
{
  result = new xqpStringStore("");

  if (position+1 >= str->bytes())
    return;

  xqpString modifier = xqpString("");

  if (position+2 < str->bytes() &&
      (str->byteSubstr(position+1, 2)->byteEqual("Ww", 2) ||
       str->byteSubstr(position+1, 2)->byteEqual("Nn", 2)))
  {
    modifier.append_in_place(str->byteSubstr(position+1, 2));
    position += 2;
  }
  else if (str->byteAt(position+1) == '1' || str->byteAt(position+1) == 'i' || str->byteAt(position+1) == 'I'
           || str->byteAt(position+1) == 'a' || str->byteAt(position+1) == 'A'
           || str->byteAt(position+1) == 'w' || str->byteAt(position+1) == 'W'
           || str->byteAt(position+1) == 'n' || str->byteAt(position+1) == 'N' )
  {
    modifier.append_in_place(str->byteAt(position+1));
    position++;
  }
  else if (str->byteAt(position+1) == '0')
  {
    int start = position;
    while (position+1 < str->bytes() && str->byteAt(position+1) == '0')
    {
      modifier.append_in_place(str->byteAt(position+1));
      position++;
    }

    if (position+1 >= str->bytes() || str->byteAt(position+1) != '1')
    {
      position = start;
      return;
    }

    modifier.append_in_place(str->byteAt(position+1));
    position++;
  }

  result = modifier.theStrStore;
}


static void parse_second_modifier(
    xqpStringStore_t& str,
    unsigned int& position,
    xqpStringStore_t& result)
{
  result = new xqpStringStore("");

  if (position+1 >= str->bytes())
    return;

  position++;
  if (str->byteAt(position) == 't')
    result = new xqpStringStore("t");
  else if (str->byteAt(position) == 'o')
    result = new xqpStringStore("o");
  else
    position--;
}


// for min_width and max_width
// -3 means an error in the picture
// -2 means width modifiers are not specified
// -1 means '*'
// >=0 means explicitly specified width
static void parse_width_modifier(
    xqpStringStore_t& str,
    unsigned int& position,
    int& min_width,
    int& max_width)
{
  min_width = -2;
  max_width = -2;

  if (position+1 >= str->bytes() || str->byteAt(position+1) != ',')
    return;

  position++;

  // The min_width must be present if there is a comma symbol
  min_width = -3;
  if (position+1 >= str->bytes())
    return;

  if (str->byteAt(position+1) == '*')
  {
    min_width = -1;
    position++;
  }
  else
  {
    if (parse_int(*str, position, min_width, -1, -1, 1))
      min_width = -3;
  }

  if (position+1 >= str->bytes() || str->byteAt(position+1) != '-')
    return;

  position++;
  if (str->byteAt(position+1) == '*')
  {
    max_width = -1;
    position++;
  }
  else
  {
    if (parse_int(*str, position, max_width, -1, -1, 1))
      min_width = -3;
  }
}


static int get_data_type(char component)
{
  switch (component)
  {
  case 'Y':
    return DateTime::YEAR_DATA;
  case 'M':
    return DateTime::MONTH_DATA;
  case 'D':
    return DateTime::DAY_DATA;
  case 'd':  // day in year
    return DateTime::DAY_DATA;
  case 'F':  // day of week
    return DateTime::DAY_DATA;
  case 'W':  // week in year
    return DateTime::DAY_DATA;
  case 'w':  // week in month
    return DateTime::DAY_DATA;
  case 'H':  // hour in day (24 hours)
    return DateTime::HOUR_DATA;
  case 'h':  // hour in half-day (12 hours)
    return DateTime::HOUR_DATA;
  case 'P':  // am/pm marker
    return DateTime::HOUR_DATA;
  case 'm':
    return DateTime::MINUTE_DATA;
  case 's':
    return DateTime::SECONDS_DATA;
  case 'f': // fractional seconds
    return DateTime::FRACSECONDS_DATA;
  case 'Z': // timezone as a time offset from UTC, or if an alphabetic modifier is present the conventional name of a timezone (such as PST)
    return -1;
  case 'z': // timezone as a time offset using GMT, for example GMT+1
    return -1;
  case 'C': // calendar: the name or abbreviation of a calendar name
    return -1;
  case 'E': // era: the name of a baseline for the numbering of years, for example the reign of a monarch
    return -1;
  default:
    return -1;
  }
}


bool
FnFormatDateTimeIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  bool variable_marker;
  xqpStringStore_t pictureString, resultString;
  store::Item_t dateTimeItem, picture;
  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (planState.theCompilerCB->theRootSctx->xquery_version() == StaticContextConsts::xquery_version_1_0)
    ZORBA_ERROR_LOC_DESC(XPST0017, loc, "The date/time formatting functions are only available in the XQuery 1.1 processing mode.");

  if (!consumeNext(dateTimeItem, theChildren[0].getp(), planState))
  {
    // Got void, returning void
    STACK_PUSH(false, state);
  }
  else
  {
  	consumeNext(picture, theChildren[1].getp(), planState);
    pictureString = picture->getStringValue();
    resultString = new xqpStringStore("");
    variable_marker = false;
    for (unsigned int i=0; i<pictureString->bytes(); i++)
    {
      if (variable_marker)
      {
        char component = 0;
        Modifier modifier;

        switch (pictureString->byteAt(i))
        {
        case 'Y': case 'M': case 'D': case 'd': case 'F': case 'W': case 'w':
        case 'H': case 'h': case 'P': case 'm': case 's': case 'f':
        case 'Z': case 'z': case 'C': case 'E':
          component = pictureString->byteAt(i);
          break;

        case ']':
          variable_marker = false;
          break;

        default:
          ZORBA_ERROR_LOC(XTDE1340, loc);
          break;
        }

        if (variable_marker == false)
          continue;

        parse_presentation_modifier(pictureString, i, modifier.presentation_modifier);
        parse_second_modifier(pictureString, i, modifier.second_modifier);
        parse_width_modifier(pictureString, i, modifier.min_width_modifier, modifier.max_width_modifier);

        // min_width_modifier is -3, there was an error in the picture
        if (modifier.min_width_modifier == -3)
          ZORBA_ERROR_LOC(XTDE1340, loc);

        int data_type = get_data_type(component);
        if (data_type != -1 && (!DateTime::FACET_MEMBERS[facet_type][data_type]))
          ZORBA_ERROR_LOC(XTDE1350, loc);

        switch (component)
        {
        case 'Y':
          // TODO: year can be negative
          format_number(resultString, dateTimeItem->getDateTimeValue().getYear(), modifier);
          break;
        case 'M':
          output_month(resultString, dateTimeItem->getDateTimeValue().getMonth(), modifier);
          break;
        case 'D':
          format_number(resultString, dateTimeItem->getDateTimeValue().getDay(), modifier);
          break;
        case 'd':  // day in year
          format_number(resultString, dateTimeItem->getDateTimeValue().getDayOfYear(), modifier);
          break;
        case 'F':  // day of week
          output_day_of_week(resultString, dateTimeItem->getDateTimeValue().getDayOfWeek(), modifier);
          break;
        case 'W':  // week in year
          format_number(resultString, dateTimeItem->getDateTimeValue().getWeekInYear(), modifier);
          break;
        case 'w':  // week in month
          format_number(resultString, dateTimeItem->getDateTimeValue().getWeekInMonth(), modifier);
          break;
        case 'H':  // hour in day (24 hours)
          format_number(resultString, dateTimeItem->getDateTimeValue().getHours(), modifier);
          break;
        case 'h':  // hour in half-day (12 hours)
          // Convert hour from:      0  1  ...  12  13  ...  23   0
          //                to:     12  1  ...  12   1  ...  11  12
          format_number(resultString, 1 + (11 + dateTimeItem->getDateTimeValue().getHours()) % 12,
                        modifier);
          break;
        case 'P':  // am/pm marker
          format_string(resultString, dateTimeItem->getDateTimeValue().getHours() >= 12 ? "pm" : "am", modifier);
          break;
        case 'm':
          if (modifier.presentation_modifier->size() == 0)
            modifier.presentation_modifier->append_in_place("01");
          format_number(resultString, dateTimeItem->getDateTimeValue().getMinutes(), modifier);
          break;
        case 's':
          if (modifier.presentation_modifier->size() == 0)
            modifier.presentation_modifier->append_in_place("01");
          format_number(resultString, dateTimeItem->getDateTimeValue().getIntSeconds(), modifier);
          break;
        case 'f': // fractional seconds
          format_number(resultString, (long)(dateTimeItem->getDateTimeValue().getFractionalSeconds()*1000.0/DateTime::FRAC_SECONDS_UPPER_LIMIT),
                        modifier);
          break;
        case 'Z': // timezone as a time offset from UTC, or if an alphabetic modifier is present the conventional name of a timezone (such as PST)
          // deliberate fall-through
        case 'z': // timezone as a time offset using GMT, for example GMT+1
          {
		        xqpString temp = "gmt" + dateTimeItem->getDateTimeValue().getTimezone().toString();
            format_string(resultString, *temp.theStrStore, modifier);
		      }
          break;
        case 'C': // calendar: the name or abbreviation of a calendar name
          format_string(resultString, "gregorian", modifier);
          break;
        case 'E': // era: the name of a baseline for the numbering of years, for example the reign of a monarch
          format_string(resultString, dateTimeItem->getDateTimeValue().getYear() < 0 ? "ad" : "bc", modifier);
          break;
        }
      }
      else
      {
        if (pictureString->byteAt(i) == '[')
        {
          // check for quoted "[["
          if (i<pictureString->bytes()-1 && pictureString->byteAt(i+1) == '[')
            i++;
          else
          {
            variable_marker = true;
            continue;
          }
        }
        else if (pictureString->byteAt(i) == ']')
        {
          // check for quoted "]]"
          if (i<pictureString->bytes()-1 && pictureString->byteAt(i+1) == ']')
            i++;
        }

        resultString->append_in_place(pictureString->byteAt(i));
      }
    }

  	STACK_PUSH(GENV_ITEMFACTORY->createString(result, resultString), state);
  }

  STACK_END (state);
}


}
