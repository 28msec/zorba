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

#include "system/globalenv.h"

#include "runtime/random/random.h"
#include "diagnostics/diagnostic.h"

#include "zorbatypes/numconversions.h"

#include "store/api/item.h"
#include "store/api/item_factory.h"
#include <zorba/util/time.h>
#include <limits>

#include "util/uuid/uuid.h"

namespace zorba {

bool
SeededRandomIterator::nextImpl(
  store::Item_t& result,
  PlanState& planState) const
{
  store::Item_t    seed;
  store::Item_t    num;
  unsigned int     int_seed;

  SeededRandomIteratorState* state;
  DEFAULT_STACK_INIT(SeededRandomIteratorState, state, planState);

  consumeNext(seed, theChildren[0].getp(), planState);
  consumeNext(num, theChildren[1].getp(), planState);
  if ( num->getIntegerValue() < xs_integer( 0 ) ) 
  {
    STACK_PUSH(false, state);
  }
  else
  {
    state->theSeqLength = num->getIntegerValue();
    state->theCurrCounter = 0;

    if ( seed->getIntegerValue() < xs_integer ( 0 ) )
    {
      throw XQUERY_EXCEPTION(
          zerr::ZXQD0004_INVALID_PARAMETER,
          ERROR_PARAMS (
            ZED( ZXQD0004_NON_NEGATIVE ),
            seed->getIntegerValue()
          ),
          ERROR_LOC ( loc )
      );
    }

    try
    {
      int_seed = static_cast<unsigned int>(
          to_xs_int( seed->getIntegerValue() ) );
    } catch (std::range_error& e)
    {
      throw XQUERY_EXCEPTION(
          zerr::ZXQD0004_INVALID_PARAMETER,
          ERROR_PARAMS (
            ZED( ZXQD0004_NOT_WITHIN_RANGE ),
            seed->getIntegerValue()
          ),
          ERROR_LOC ( loc )
      );
    }

    std::srand( int_seed );

    while ( state->theCurrCounter < state->theSeqLength )
    {
      GENV_ITEMFACTORY->createInteger(result, Integer(std::rand()));
      state->theCurrCounter++;
      STACK_PUSH (true, state);
    }
    STACK_PUSH (false, state);
  }

  STACK_END (state);
}

bool
RandomIterator::nextImpl(
  store::Item_t& result,
  PlanState& planState) const
{
  store::Item_t    num;
  unsigned int     int_seed;
  long             walltime_millis;
  zstring ltmp;

  RandomIteratorState* state;
  DEFAULT_STACK_INIT(RandomIteratorState, state, planState);

  consumeNext(num, theChildren[0].getp(), planState);
  if ( num->getIntegerValue() < xs_integer( 0 ) ) 
  {
    STACK_PUSH(false, state);
  }
  else
  {
    state->theSeqLength = num->getIntegerValue();
    state->theCurrCounter = 0;

    // provide the seed using the current walltime in milli seconds
    // broken down to the limits of unsigned int
    time::walltime lCurrWallTime;
    time::get_current_walltime( lCurrWallTime );
    walltime_millis = time::get_walltime_in_millis( lCurrWallTime );

    uuid_t  u;
    memset(&u, 0, sizeof(uuid_t));
    uuid_create(&u);

    walltime_millis += u.time_low;

    int_seed = walltime_millis % std::numeric_limits<unsigned int>::max();

    std::srand( int_seed );

    while ( state->theCurrCounter < state->theSeqLength )
    {
      GENV_ITEMFACTORY->createInteger(result, Integer(std::rand()));
      state->theCurrCounter++;
      STACK_PUSH (true, state);
    }
    STACK_PUSH (false, state);
  }

  STACK_END (state);
}

bool
UuidIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t item;
  uuid_t  u;
  zstring uuidStr;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  memset(&u, 0, sizeof(uuid_t));

  uuid_create(&u);
  uuidStr = uuidToString(u);

  GENV_ITEMFACTORY->createString(result, uuidStr);
  STACK_PUSH(true, state);

  STACK_END (state);
}

} /* namespace zorba */
/* vim:set et sw=2 ts=2: */
