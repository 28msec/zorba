/*
 * Copyright 2006-2011 The FLWOR Foundation.
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

#include <map>
#include <sstream>

#include <zorba/diagnostic_list.h>

#include "diagnostics/xquery_exception.h"
#include "runtime/datetime/datetime.h"
#include "store/api/item_factory.h"
#include "system/globalenv.h"
#include "util/ascii_util.h"
#include "util/strptime.h"
#include "util/time_util.h"

using namespace std;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

static void try_strptime( zstring const &buf, zstring const &fmt,
                          time::ztm *tm, QueryLoc const &loc ) {
  try {
    time::strptime( buf, fmt, tm );
  }
  catch ( time::invalid_specification const &e ) {
    throw XQUERY_EXCEPTION(
      zerr::ZDTP0001_INVALID_SPECIFICATION,
      ERROR_PARAMS( ascii::printable_char( e.get_spec() ) ),
      ERROR_LOC( loc )
    );
  }
  catch ( time::invalid_value const &e ) {
    throw XQUERY_EXCEPTION(
      zerr::ZDTP0002_INVALID_VALUE,
      ERROR_PARAMS( e.get_value(), e.get_specs() ),
      ERROR_LOC( loc )
    );
  }
  catch ( time::literal_mismatch const &e ) {
    throw XQUERY_EXCEPTION(
      zerr::ZDTP0003_LITERAL_MISMATCH,
      ERROR_PARAMS(
        ascii::printable_char( e.get_got() ),
        ascii::printable_char( e.get_expected() )
      ),
      ERROR_LOC( loc )
    );
  }
}

///////////////////////////////////////////////////////////////////////////////

bool CurrentDate::nextImpl( store::Item_t& result,
                            PlanState &plan_state ) const {
  time::ztm tm;
  time::get_gmtime( &tm );

  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, plan_state );

  GENV_ITEMFACTORY->createDate(
    result,
    static_cast<short>( tm.tm_year + TM_YEAR_BASE ),
    static_cast<short>( tm.tm_mon + 1 ),
    static_cast<short>( tm.tm_mday )
  );

  STACK_PUSH( true, state );
  STACK_END( state );
}

bool CurrentDateTime::nextImpl( store::Item_t& result,
                                PlanState &plan_state ) const {
  time_t sec;
  time::usec_type usec;
  time::get_epoch( &sec, &usec );
  time::ztm tm;
  time::get_gmtime( &tm, sec );

  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, plan_state );

  GENV_ITEMFACTORY->createDateTime(
    result,
    static_cast<short>( tm.tm_year + TM_YEAR_BASE ),
    static_cast<short>( tm.tm_mon + 1 ),
    static_cast<short>( tm.tm_mday ),
    static_cast<short>( tm.tm_hour ),
    static_cast<short>( tm.tm_min ),
    tm.tm_sec + usec / 1000000.0,
    static_cast<short>( tm.ZTM_GMTOFF / 3600 )
  );

  STACK_PUSH( true, state );
  STACK_END( state );
}

bool CurrentTime::nextImpl( store::Item_t& result,
                            PlanState &plan_state ) const {
  time_t sec;
  time::usec_type usec;
  time::get_epoch( &sec, &usec );
  time::ztm tm;
  time::get_gmtime( &tm, sec );

  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, plan_state );

  GENV_ITEMFACTORY->createTime(
    result,
    static_cast<short>( tm.tm_hour ),
    static_cast<short>( tm.tm_min ),
    tm.tm_sec + usec / 1000000.0,
    static_cast<short>( tm.ZTM_GMTOFF / 3600 )
  );

  STACK_PUSH( true, state );
  STACK_END( state );
}

bool ParseDate::nextImpl( store::Item_t& result, PlanState &plan_state ) const {
  store::Item_t item;
  time::ztm tm;
  zstring buf, fmt;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, plan_state );

  consumeNext( item, theChild0, plan_state );
  item->getStringValue2( buf );
  consumeNext( item, theChild1, plan_state );
  item->getStringValue2( fmt );

  try_strptime( buf, fmt, &tm, loc );

  GENV_ITEMFACTORY->createDate(
    result,
    static_cast<short>( tm.tm_year + TM_YEAR_BASE ),
    static_cast<short>( tm.tm_mon + 1 ),
    static_cast<short>( tm.tm_mday )
  );

  STACK_PUSH( true, state );
  STACK_END( state );
}

bool ParseDateTime::nextImpl( store::Item_t& result,
                              PlanState &plan_state ) const {
  store::Item_t item;
  zstring buf, fmt;
  time::ztm tm;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, plan_state );

  consumeNext( item, theChild0, plan_state );
  item->getStringValue2( buf );
  consumeNext( item, theChild1, plan_state );
  item->getStringValue2( fmt );

  try_strptime( buf, fmt, &tm, loc );

  GENV_ITEMFACTORY->createDateTime(
    result,
    static_cast<short>( tm.tm_year + TM_YEAR_BASE ),
    static_cast<short>( tm.tm_mon + 1 ),
    static_cast<short>( tm.tm_mday ),
    static_cast<short>( tm.tm_hour ),
    static_cast<short>( tm.tm_min ),
    static_cast<short>( tm.tm_sec ),
    static_cast<short>( tm.ZTM_GMTOFF / 3600 )
  );

  STACK_PUSH( true, state );
  STACK_END( state );
}

bool ParseTime::nextImpl( store::Item_t& result, PlanState &plan_state ) const {
  store::Item_t item;
  time::ztm tm;
  zstring buf, fmt;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, plan_state );

  consumeNext( item, theChild0, plan_state );
  item->getStringValue2( buf );
  consumeNext( item, theChild1, plan_state );
  item->getStringValue2( fmt );

  try_strptime( buf, fmt, &tm, loc );

  GENV_ITEMFACTORY->createTime(
    result,
    static_cast<short>( tm.tm_hour ),
    static_cast<short>( tm.tm_min ),
    tm.tm_sec,
    static_cast<short>( tm.ZTM_GMTOFF / 3600 )
  );

  STACK_PUSH( true, state );
  STACK_END( state );
}

bool Timestamp::nextImpl( store::Item_t& result,
                          PlanState &plan_state ) const {
  time_t sec;
  time::get_epoch( &sec );

  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, plan_state );
  GENV_ITEMFACTORY->createLong( result, sec );
  STACK_PUSH( true, state );
  STACK_END( state );
}

bool UTCOffset::nextImpl( store::Item_t& result,
                          PlanState &plan_state ) const {
  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, plan_state );
  GENV_ITEMFACTORY->createLong( result, time::get_gmt_offset() );
  STACK_PUSH( true, state );
  STACK_END( state );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
