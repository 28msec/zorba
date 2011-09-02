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

#include "common/common.h"
#include <assert.h>
#include <time.h>
#include <sys/timeb.h>
#ifdef UNIX
#include <sys/time.h>
#endif

#include "store/api/iterator.h"
#include "store/api/temp_seq.h"
#include "store/api/item_factory.h"
#include "store/api/store.h"
#include "store/api/index.h"
#include "store/api/ic.h"

#include "system/globalenv.h"

#include "context/dynamic_context.h"
#include "context/static_context.h"
#include "context/namespace_context.h"

#include "compiler/expression/var_expr.h"
#include "compiler/xqddf/value_index.h"
#include "compiler/parsetree/parsenodes.h"

#include "types/root_typemanager.h"

#include "runtime/api/plan_wrapper.h"
#include "runtime/base/plan_iterator.h"

#include "zorbautils/hashmap_itemp.h"
#include "util/string_util.h"

#include "diagnostics/assert.h"

using namespace std;

namespace zorba
{


/*******************************************************************************

********************************************************************************/
dynamic_context::VarValue::~VarValue() 
{
  switch (theState)
  {
  case VarValue::undeclared:
  case VarValue::declared:
    assert(theValue.item == NULL);
    break;
  case VarValue::item:
    assert(theValue.item != NULL);
    theValue.item->removeReference();
    theValue.item = NULL;
    break;
  case VarValue::temp_seq:
    assert(theValue.temp_seq != NULL);
    RCHelper::removeReference(theValue.temp_seq);
    theValue.temp_seq = NULL;
    break;
  default:
    ZORBA_ASSERT(false);
  }

  theState = VarValue::undeclared;
}


dynamic_context::VarValue::VarValue(const VarValue& other) 
{
  switch (other.theState)
  {
  case VarValue::undeclared:
  case VarValue::declared:
    assert(other.theValue.item == NULL);
    theValue.item = NULL;
    break;
  case VarValue::item:
    assert(other.theValue.item != NULL);
    theValue.item = other.theValue.item;
    theValue.item->addReference();
    break;
  case VarValue::temp_seq:
    assert(other.theValue.temp_seq != NULL);
    theValue.temp_seq = other.theValue.temp_seq;
    RCHelper::addReference(theValue.temp_seq);
    break;
  default:
    ZORBA_ASSERT(false);
  }

  theState = other.theState;
}


/*******************************************************************************

********************************************************************************/
dynamic_context::dynamic_context(dynamic_context* parent)
  :
  theParent(NULL),
  theAvailableIndices(NULL),
  theDocLoadingUserTime(0.0),
  theDocLoadingTime(0)
{
  theParent = parent;

  if(parent == NULL)
  {
    reset_current_date_time();
  }
  else
  {
    theCurrentDateTime = parent->theCurrentDateTime;
    theTimezone = parent->theTimezone;
    theDefaultCollectionUri = parent->theDefaultCollectionUri;
  }
}


/*******************************************************************************

********************************************************************************/
dynamic_context::~dynamic_context()
{
  if (theAvailableIndices)
    delete theAvailableIndices;
}


/*******************************************************************************

********************************************************************************/
store::Item_t dynamic_context::get_default_collection() const
{
  return theDefaultCollectionUri;
}


void dynamic_context::set_default_collection(const store::Item_t& default_collection_uri)
{
  theDefaultCollectionUri = default_collection_uri;
}


void dynamic_context::set_implicit_timezone(long tzone_seconds)
{
  theTimezone = tzone_seconds;
}


long dynamic_context::get_implicit_timezone() const
{
  return theTimezone;
}


void dynamic_context::set_current_date_time(const store::Item_t& aDateTimeItem)
{
  this->theCurrentDateTime = aDateTimeItem;
}


void dynamic_context::reset_current_date_time()
{
  int lTimeShift = 0;
#if defined (WIN32)
  struct _timeb timebuffer;
  _ftime_s( &timebuffer );
  struct ::tm gmtm;
  localtime_s(&gmtm, &timebuffer.time); //thread safe localtime on Windows
  lTimeShift = -timebuffer.timezone*60;
  if (gmtm.tm_isdst != 0)
    lTimeShift += 3600;
#else
  struct timeb timebuffer;
  ftime( &timebuffer );
  struct ::tm gmtm;
  localtime_r(&timebuffer.time, &gmtm); //thread safe localtime on Linux
  lTimeShift = gmtm.tm_gmtoff;
#endif

  set_implicit_timezone(lTimeShift);//in seconds

  GENV_ITEMFACTORY->createDateTime(theCurrentDateTime,
                                   static_cast<short>(gmtm.tm_year + 1900),
                                   static_cast<short>(gmtm.tm_mon + 1),
                                   static_cast<short>(gmtm.tm_mday),
                                   static_cast<short>(gmtm.tm_hour),
                                   static_cast<short>(gmtm.tm_min),
                                   gmtm.tm_sec + timebuffer.millitm/1000.0,
                                   static_cast<short>(theTimezone/3600));

}


store::Item_t dynamic_context::get_current_date_time() const
{
  return theCurrentDateTime;
}


/*******************************************************************************

********************************************************************************/
void dynamic_context::add_variable(ulong varid, store::Iterator_t& value) 
{
  declare_variable(varid);
  set_variable(varid, NULL, QueryLoc::null, value);
}


/*******************************************************************************

********************************************************************************/
void dynamic_context::add_variable(ulong varid, store::Item_t& value) 
{
  declare_variable(varid);
  set_variable(varid, NULL, QueryLoc::null, value);
}


/*******************************************************************************

********************************************************************************/
void dynamic_context::declare_variable(ulong varid)
{
  assert(varid > 0);

  if (varid >= theVarValues.size())
    theVarValues.resize(varid+1);

  if (theVarValues[varid].theState == VarValue::undeclared)
    theVarValues[varid].theState = VarValue::declared;
}


/*******************************************************************************

********************************************************************************/
void dynamic_context::set_variable(
    ulong varid,
    const store::Item_t& varname,
    const QueryLoc& loc,
    store::Iterator_t& valueIter)
{
  if (varid >= theVarValues.size() ||
      theVarValues[varid].theState == VarValue::undeclared)
  {
    throw XQUERY_EXCEPTION(
      err::XPDY0002,
      ERROR_PARAMS( varname->getStringValue(), ZED( VariabledUndeclared ) ),
      ERROR_LOC( loc )
    );
  }

  valueIter->open();

  // For now, use eager eval because the assignment expression may reference
  // the variable itself, and the current value of the variable is overwriten
  // here by this temp sequence. TODO: use lazy eval if we know the the 
  // assignment expression does not reference the variable itself.
  store::TempSeq_t seq = GENV_STORE.createTempSeq(valueIter, 
                                                  false, // no copy
                                                  false); // no lazy eval

  valueIter->close();

  VarValue& var = theVarValues[varid];

  // variables can be set multiple times, so we need to make sure to remove
  // previously set temp sequences
  if (var.theState == VarValue::item)
  {
    assert(var.theValue.item != NULL);
    var.theValue.item->removeReference();
  }
  else if (var.theState == VarValue::temp_seq)
  {
    assert(var.theValue.temp_seq != NULL);
    RCHelper::removeReference(var.theValue.temp_seq);
  }
  else if (var.theState == VarValue::declared)
  {
    assert(var.theValue.item == NULL);
  }
  else
  {
    ZORBA_ASSERT(false);
  }

  var.theState = VarValue::temp_seq;
  var.theValue.temp_seq = seq.release();
}


/*******************************************************************************

********************************************************************************/
void dynamic_context::set_variable(
    ulong varid,
    const store::Item_t& varname,
    const QueryLoc& loc,
    store::Item_t& valueItem)
{
  if (varid >= theVarValues.size() ||
      theVarValues[varid].theState == VarValue::undeclared)
  {
    throw XQUERY_EXCEPTION(
      err::XPDY0002,
      ERROR_PARAMS( varname->getStringValue(), ZED( VariabledUndeclared ) ),
      ERROR_LOC( loc )
    );
  }

  VarValue& var = theVarValues[varid];

  // variables can be set multiple times, so we need to make sure to remove
  // previously set temp sequences
  if (var.theState == VarValue::item)
  {
    assert(var.theValue.item != NULL);
    var.theValue.item->removeReference();
  }
  else if (var.theState == VarValue::temp_seq)
  {
    assert(var.theValue.temp_seq != NULL);
    RCHelper::removeReference(var.theValue.temp_seq);
  }
  else if (var.theState == VarValue::declared)
  {
    assert(var.theValue.item == NULL);
  }
  else 
  {
    ZORBA_ASSERT(false);
  }

  var.theState = VarValue::item;
  var.theValue.item = valueItem.release();
}


/*******************************************************************************

********************************************************************************/
void dynamic_context::unset_variable(
    ulong varid,
    const store::Item_t& varname,
    const QueryLoc& loc)
{
  if (varid >= theVarValues.size() ||
      theVarValues[varid].theState == VarValue::undeclared)
  {
    throw XQUERY_EXCEPTION(
      err::XPDY0002,
      ERROR_PARAMS( varname->getStringValue(), ZED( VariabledUndeclared ) ),
      ERROR_LOC( loc )
    );
  }

  VarValue& var = theVarValues[varid];

  if (var.theState == VarValue::item)
  {
    assert(var.theValue.item != NULL);
    var.theValue.item->removeReference();
  }
  else if (var.theState == VarValue::temp_seq)
  {
    assert(var.theValue.temp_seq != NULL);
    RCHelper::removeReference(var.theValue.temp_seq);
  }
  else if (var.theState == VarValue::declared)
  {
    assert(var.theValue.item == NULL);
  }
  else 
  {
    ZORBA_ASSERT(false);
  }

  var.theState = VarValue::declared;
  var.theValue.item = NULL;
}


/*******************************************************************************

********************************************************************************/
void dynamic_context::get_variable(
    ulong varid,
    const store::Item_t& varname,
    const QueryLoc& loc,
    store::Item_t& itemValue,
    store::TempSeq_t& seqValue) const
{
  itemValue = NULL;
  seqValue = NULL;

  if (varid >= theVarValues.size() ||
      theVarValues[varid].theState == VarValue::undeclared)
  {
    zstring lVarName = static_context::var_name(varname.getp());
    throw XQUERY_EXCEPTION(
      err::XPDY0002,
      ERROR_PARAMS( lVarName, ZED( VariabledUndeclared ) ),
      ERROR_LOC( loc )
    );
  }

  if (theVarValues[varid].theState == VarValue::declared)
  {
    zstring lVarName = static_context::var_name(varname.getp());
    throw XQUERY_EXCEPTION(
      err::XPDY0002,
      ERROR_PARAMS( lVarName, ZED( VariabledHasNoValue ) ),
      ERROR_LOC( loc )
    );
  }

  const VarValue& var = theVarValues[varid];

  if (var.theState == VarValue::item)
    itemValue = var.theValue.item;
  else
    seqValue = var.theValue.temp_seq;
}


/*******************************************************************************

********************************************************************************/
bool dynamic_context::exists_variable(ulong varid)
{
  if (varid >= theVarValues.size() ||
      theVarValues[varid].theState == VarValue::undeclared)
  {
    return false; // variable not found
  }

  return true;
}


/*******************************************************************************

********************************************************************************/
ulong dynamic_context::get_next_var_id() const
{
  // 0 is reserved as an invalide var id, and 1 is taken by the context item
  // in the main module.
  return (theVarValues.empty() ? 2 : theVarValues.size());
}


/*******************************************************************************

********************************************************************************/
void dynamic_context::destroy_dctx_value(dctx_value_t* val) 
{
  switch (val->type)
  {
  case dynamic_context::dctx_value_t::no_val:
    break;
  default:
    ZORBA_ASSERT (false);
  }

  val->type = dynamic_context::dctx_value_t::no_val;
}


/*******************************************************************************

********************************************************************************/
store::Index* dynamic_context::getIndex(store::Item* qname) const
{
  if (theAvailableIndices == NULL)
    return NULL;

  store::Index_t index;

  if (theAvailableIndices->get(qname, index))
  {
    return index.getp();
  }
  else
  {
    return NULL;
  }
}


/*******************************************************************************

********************************************************************************/
void dynamic_context::bindIndex(
    store::Item* qname,
    store::Index_t& index)
{
  if (theAvailableIndices == NULL)
    theAvailableIndices = new IndexMap(0, NULL, 8, false);

  if (!theAvailableIndices->insert(qname, index))
  {
    ZORBA_ASSERT(false);
  }
}


/*******************************************************************************

********************************************************************************/
void dynamic_context::unbindIndex(store::Item* qname)
{
  if (theAvailableIndices != NULL)
    theAvailableIndices->remove(qname);
}


/*******************************************************************************

********************************************************************************/
store::Iterator_t dynamic_context::listActiveICNames()
{
  return GENV_STORE.listActiveICNames();
}


/*******************************************************************************

********************************************************************************/
store::IC* dynamic_context::getIC(const store::Item* qname)
{
  return GENV_STORE.getIC(qname);
}


/*******************************************************************************

********************************************************************************/
bool dynamic_context::addExternalFunctionParam (
    const std::string& aName,
    void* aValue )
{
  dctx_value_t val;
  val.type = dynamic_context::dctx_value_t::ext_func_param;
  val.func_param = aValue;

  return keymap.put ( aName, val);
}


/*******************************************************************************

********************************************************************************/
bool dynamic_context::getExternalFunctionParam (
  const std::string& aName,
  void*& aValue) const
{
  dctx_value_t val;
  val.type = dynamic_context::dctx_value_t::no_val;
  val.func_param = 0;

  if ( !keymap.get(aName, val) ) {
    if (theParent)
      return theParent->getExternalFunctionParam(aName, aValue);
    else
      return false;
  }

  ZORBA_ASSERT(val.type == dynamic_context::dctx_value_t::ext_func_param);
  aValue = val.func_param;
  return true;
}


/*
std::vector<zstring>* dynamic_context::get_all_keymap_keys() const
{
  std::auto_ptr<std::vector<zstring> > keys;
  if (theParent != NULL)
    keys.reset(theParent->get_all_keymap_keys());
  else
    keys.reset(new std::vector<zstring>);

  for (unsigned int i=0; i<keymap.size(); i++)
    keys->push_back(keymap.getentryKey(i));

  return keys.release();
}
*/


} // namespace zorba
/* vim:set et sw=2 ts=2: */
