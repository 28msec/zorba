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

#include <assert.h>

#include "common/common.h"
#include "store/api/iterator.h"
#include "store/api/temp_seq.h"
#include "store/api/item_factory.h"
#include "store/api/store.h"
#include "store/api/index.h"
#include "store/api/ic.h"
#include "store/api/iterator_factory.h"

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
#include "util/time_util.h"

#include "diagnostics/assert.h"
#include "diagnostics/util_macros.h"
#include <zorba/external_function_parameter.h>

using namespace std;

#ifdef UNIX
extern char **environ;
#  ifdef APPLE
#    include <crt_externs.h>
#    define environ (*_NSGetEnviron())
#  endif
#endif

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
  theIsExternalOrLocal = other.theIsExternalOrLocal;
}


/*******************************************************************************

********************************************************************************/
dynamic_context::dynamic_context(dynamic_context* parent)
  :
  theParent(NULL),
  keymap(NULL),
  theAvailableIndices(NULL),
  theAvailableMaps(NULL),
  theEnvironmentVariables(NULL),
  theSnapshotID(0),
  theDocLoadingUserTime(0.0),
  theDocLoadingTime(0)
{
  theParent = parent;

  if(parent == NULL)
  {
    reset_current_date_time();
    theLang = GENV.get_host_lang();
    theCountry = GENV.get_host_country();
    theCalendar = time::calendar::get_default();
  }
  else
  {
    theCurrentDateTimeStamp = parent->theCurrentDateTimeStamp;
    theTimezone = parent->theTimezone;
    theDefaultCollectionUri = parent->theDefaultCollectionUri;
    theLang = parent->theLang;
    theCountry = parent->theCountry;
    theCalendar = parent->theCalendar;
  }
}


/*******************************************************************************

********************************************************************************/
dynamic_context::~dynamic_context()
{
  if (keymap)
  {
    for (ValueMap::iterator lIter = keymap->begin();
         lIter != keymap->end();
         ++lIter)
    {
      dctx_value_t lValue = lIter.getValue();
      if (lValue.type == dctx_value_t::ext_func_param_typed &&
          lValue.func_param)
      {
        static_cast<ExternalFunctionParameter*>(lValue.func_param)->destroy();
      }
    }
    delete keymap;
  }

  if(theEnvironmentVariables)
    delete theEnvironmentVariables;

  if (theAvailableIndices)
    delete theAvailableIndices;

  if (theAvailableMaps)
    delete theAvailableMaps;
}


/*******************************************************************************

********************************************************************************/
store::Item_t dynamic_context::get_default_collection() const
{
  return theDefaultCollectionUri;
}


/*******************************************************************************

********************************************************************************/
void dynamic_context::set_default_collection(const store::Item_t& default_collection_uri)
{
  theDefaultCollectionUri = default_collection_uri;
}


/*******************************************************************************

********************************************************************************/
void dynamic_context::set_implicit_timezone(long tzone_seconds)
{
  if (tzone_seconds > 14*3600 || tzone_seconds < -14*3600)
    throw XQUERY_EXCEPTION(err::FODT0003, ERROR_PARAMS(tzone_seconds));

  theTimezone = tzone_seconds;
}


/*******************************************************************************

********************************************************************************/
long dynamic_context::get_implicit_timezone() const
{
  return theTimezone;
}


/*******************************************************************************

********************************************************************************/
void dynamic_context::set_current_date_time(const store::Item_t& aDateTimeItem)
{
  this->theCurrentDateTimeStamp = aDateTimeItem;
}


/*******************************************************************************

********************************************************************************/
void dynamic_context::reset_current_date_time()
{
  time::sec_type sec;
  time::usec_type usec;
  time::get_epoch( &sec, &usec );
  time::ztm tm;
  time::get_localtime( &tm, sec );

  set_implicit_timezone( tm.ZTM_GMTOFF );

  GENV_ITEMFACTORY->createDateTimeStamp(
    theCurrentDateTimeStamp,
    static_cast<short>( tm.tm_year + TM_YEAR_BASE ),
    static_cast<short>( tm.tm_mon + 1 ),
    static_cast<short>( tm.tm_mday ),
    static_cast<short>( tm.tm_hour ),
    static_cast<short>( tm.tm_min ),
    tm.tm_sec + usec / 1000000.0,
    static_cast<int>( tm.ZTM_GMTOFF )
  );
}


/*******************************************************************************

********************************************************************************/
store::Item_t dynamic_context::get_current_date_time() const
{
  return theCurrentDateTimeStamp;
}


/*******************************************************************************

********************************************************************************/
void dynamic_context::set_environment_variables()
{
  if (!theEnvironmentVariables)
    theEnvironmentVariables = new EnvVarMap();

#if defined (WIN32)
    LPTCH envVarsCH = GetEnvironmentStrings();
    LPTSTR envVarsSTR = (LPTSTR) envVarsCH;

    while (*envVarsSTR)
    {
      int size = lstrlen(envVarsSTR);

      char * envVar = new char[size+1];

      WideCharToMultiByte( CP_ACP,
                           WC_NO_BEST_FIT_CHARS|WC_COMPOSITECHECK|WC_DEFAULTCHAR,
                           envVarsSTR,
                           size+1,
                           envVar,
                           size+1,
                           NULL,
                           NULL);

      zstring envVarZS(envVar);

      int eqPos = envVarZS.find_first_of("=");

      if (eqPos > 0)
      {
        zstring varname(envVarZS.substr(0, eqPos));
        zstring varvalue(envVarZS.substr(eqPos+1, size));

        if (!varname.empty() || !varvalue.empty())
          theEnvironmentVariables->insert(std::pair<zstring, zstring>(varname,varvalue));
      }

      delete envVar;
      envVarsSTR += lstrlen(envVarsSTR) + 1;
    }

    FreeEnvironmentStrings(envVarsCH);
#else
    const char* invalid_char;
    for (char **env = environ; *env; ++env)
    {
      zstring envVarZS(*env);

      if ((invalid_char = utf8::validate(envVarZS.c_str())) != NULL)
        throw XQUERY_EXCEPTION(err::FOCH0001,
          ERROR_PARAMS(zstring("#x") +
          BUILD_STRING(std::uppercase << std::hex
            << (static_cast<unsigned int>(*invalid_char)&0xFF))));

      if ((invalid_char = utf8::validate(envVarZS.c_str())) != NULL)
      {
        throw XQUERY_EXCEPTION(err::FOCH0001,
        ERROR_PARAMS(zstring("#x") +
        BUILD_STRING(std::uppercase << std::hex
                     << (static_cast<unsigned int>(*invalid_char) & 0xFF)) ));
      }

      int size = envVarZS.size();

      int eqPos = envVarZS.find_first_of("=");

      if (eqPos > 0)
      {
        zstring varname(envVarZS.substr(0, eqPos));
        zstring varvalue(envVarZS.substr(eqPos+1, size));

        if (!varname.empty() || !varvalue.empty())
          theEnvironmentVariables->insert(std::pair<zstring, zstring>(varname,varvalue));
      }
    }

#endif

}
/*******************************************************************************

********************************************************************************/
store::Iterator_t dynamic_context::available_environment_variables()
{
  if (!theEnvironmentVariables)
  {
    set_environment_variables();
  }

  EnvVarMap::iterator lIte = theEnvironmentVariables->begin();
  EnvVarMap::iterator lEnd = theEnvironmentVariables->end();

  std::vector<store::Item_t> lVarNames;

  for (;lIte != lEnd; ++lIte)
  {
    store::Item_t varname;
    zstring zsvarname = lIte->first;
    GENV_ITEMFACTORY->createString(varname, zsvarname);
    lVarNames.push_back(varname);
  }

  if (lVarNames.empty())
  {
    return NULL;
  }

  return GENV_STORE.createTempSeq(lVarNames)->getIterator();
}

/*******************************************************************************

********************************************************************************/
store::Item_t dynamic_context::get_environment_variable(const zstring& varname)
{

  if (!theEnvironmentVariables)
  {
    set_environment_variables();
  }

  EnvVarMap::iterator lIter = theEnvironmentVariables->find(varname);

  if (lIter == theEnvironmentVariables->end())
  {
    return NULL;
  }

  store::Item_t value;
  zstring varvalue = lIter->second;
  GENV_ITEMFACTORY->createString(value, varvalue);
  return value;
}


/*******************************************************************************

********************************************************************************/
void dynamic_context::add_variable(ulong varid, store::Iterator_t& value)
{
  declare_variable(varid, false);
  set_variable(varid, NULL, QueryLoc::null, value);
}


/*******************************************************************************

********************************************************************************/
void dynamic_context::add_variable(ulong varid, store::Item_t& value)
{
  declare_variable(varid, false);
  set_variable(varid, NULL, QueryLoc::null, value);
}


/*******************************************************************************

********************************************************************************/
void dynamic_context::declare_variable(ulong varid, bool external)
{
  assert(varid > 0);

  if (varid >= theVarValues.size())
    theVarValues.resize(varid+1);

  if (theVarValues[varid].theState == VarValue::undeclared)
    theVarValues[varid].theState = VarValue::declared;

  theVarValues[varid].theIsExternalOrLocal = external;
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
    RAISE_ERROR(err::XPDY0002, loc,
    ERROR_PARAMS(ZED(XPDY0002_VariableUndeclared_2), varname->getStringValue()));
  }

  valueIter->open();

  // For now, use eager eval because the assignment expression may reference
  // the variable itself, and the current value of the variable is overwriten
  // here by this temp sequence. TODO: use lazy eval if we know the the
  // assignment expression does not reference the variable itself.
  store::TempSeq_t seq = GENV_STORE.createTempSeq(valueIter, false); // no lazy eval

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
    RAISE_ERROR(err::XPDY0002, loc,
    ERROR_PARAMS(ZED(XPDY0002_VariableUndeclared_2), varname->getStringValue()));
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
    RAISE_ERROR(err::XPDY0002, loc,
    ERROR_PARAMS(ZED(XPDY0002_VariableUndeclared_2), varname->getStringValue()));
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
    zstring varName = static_context::var_name(varname.getp());

    if (varid >= theVarValues.size() ||
        theVarValues[varid].theIsExternalOrLocal ||
        (varid > 0 && varid < MAX_IDVARS_RESERVED))
    {
      RAISE_ERROR(err::XPDY0002, loc,
      ERROR_PARAMS(ZED(XPDY0002_VariableUndeclared_2), varName));
    }
    else
    {
      RAISE_ERROR(err::XQDY0054, loc, ERROR_PARAMS(varName));
    }
  }

  const VarValue& var = theVarValues[varid];

  if (var.theState == VarValue::declared)
  {
    zstring varName = static_context::var_name(varname.getp());

    if (var.theIsExternalOrLocal)
    {
      RAISE_ERROR(err::XPDY0002, loc,
      ERROR_PARAMS(ZED(XPDY0002_VariableHasNoValue_2), varName));
    }
    else
    {
      RAISE_ERROR(err::XQDY0054, loc, ERROR_PARAMS(varName));
    }
  }

  if (var.theState == VarValue::item)
    itemValue = var.theValue.item;
  else
    seqValue = var.theValue.temp_seq;
}


/*******************************************************************************

********************************************************************************/
bool dynamic_context::is_set_variable(ulong varid) const
{
  if (varid >= theVarValues.size() ||
      theVarValues[varid].theState == VarValue::undeclared ||
      theVarValues[varid].theState == VarValue::declared)
  {
    return false;
  }

  return true;
}


/*******************************************************************************

********************************************************************************/
bool dynamic_context::exists_variable(ulong varid) const
{
  if (varid >= theVarValues.size() ||
      theVarValues[varid].theState == VarValue::undeclared)
  {
    return false;
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
    theAvailableIndices = new IndexMap(HashMapItemPointerCmp(0, NULL), 8, false);

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
    theAvailableIndices->erase(qname);
}


/*******************************************************************************

********************************************************************************/
store::Index* dynamic_context::getMap(
    store::Item* qname,
    bool lookupParent) const
{
  store::Index_t map;
  const dynamic_context* c = this;

  while (c)
  {
    if (c->theAvailableMaps && c->theAvailableMaps->get(qname, map))
    {
      return map.getp();
    }
    else
    {
      if (lookupParent)
        c = c->getParent();
      else
        c = NULL;
      continue;
    }
  }
  return NULL;
}


/*******************************************************************************

********************************************************************************/
void dynamic_context::bindMap(
    store::Item* qname,
    store::Index_t& map)
{
  if (theAvailableMaps == NULL)
    theAvailableMaps = new IndexMap(HashMapItemPointerCmp(0, NULL), 8, false);

  if (!theAvailableMaps->insert(qname, map))
  {
    ZORBA_ASSERT(false);
  }
}


/*******************************************************************************

********************************************************************************/
void dynamic_context::unbindMap(store::Item* qname)
{
  store::Index_t map;

  if (theAvailableMaps && theAvailableMaps->get(qname, map))
  {
    theAvailableMaps->erase(qname);
  }
}


/*******************************************************************************

********************************************************************************/
void dynamic_context::getMapNames(std::vector<store::Item_t>& names) const
{
  const dynamic_context* c = this;

  while (c)
  {
    if (c->theAvailableMaps)
    {
      for (IndexMap::iterator lIter = c->theAvailableMaps->begin();
           lIter != c->theAvailableMaps->end();
           ++lIter)
      {
        names.push_back(lIter.getKey());
      }
    }
    c = c->getParent();
  }
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
bool dynamic_context::addExternalFunctionParam(
    const std::string& aName,
    void* aValue)
{
  dctx_value_t val;
  val.type = dynamic_context::dctx_value_t::ext_func_param;
  val.func_param = aValue;

  if (!keymap)
  {
    keymap = new ValueMap(8, false);
  }
  if (!keymap->insert(aName, val))
  {
    keymap->update(aName, val);
    return false;
  }
  else
  {
    return true;
  }
}


/*******************************************************************************

********************************************************************************/
bool dynamic_context::getExternalFunctionParam(
  const std::string& aName,
  void*& aValue) const
{
  if (!keymap)
  {
    if (theParent)
    {
      return theParent->getExternalFunctionParam(aName, aValue);
    }
    else
    {
      return false;
    }
  }

  dctx_value_t val;
  val.type = dynamic_context::dctx_value_t::no_val;
  val.func_param = 0;

  ValueMap::iterator lIter = keymap->find(aName);
  if ( lIter == keymap->end() )
  {
    if (theParent)
      return theParent->getExternalFunctionParam(aName, aValue);
    else
      return false;
  }

  val = lIter.getValue();

  if (val.type == dynamic_context::dctx_value_t::ext_func_param)
  {
    aValue = val.func_param;
    return true;
  }
  else
  {
    // could also be of type ext_func_param_typed
    return false;
  }
}


/*******************************************************************************

********************************************************************************/
bool dynamic_context::addExternalFunctionParameter(
   const std::string& aName,
   ExternalFunctionParameter* aValue) const
{
  if (!keymap)
  {
    keymap = new ValueMap(8, false);
  }

  dctx_value_t val;
  val.type = dynamic_context::dctx_value_t::ext_func_param_typed;
  val.func_param = aValue;

  ExternalFunctionParameter* lValue = getExternalFunctionParameter(aName);
  if (lValue)
  {
    // destroy the object if it's already contained in the map
    lValue->destroy();
    keymap->erase(aName);
    keymap->insert(aName, val);
    return false;
  }
  else
  {
    keymap->insert(aName, val);
    return true;
  }
}


/*******************************************************************************

********************************************************************************/
ExternalFunctionParameter*
dynamic_context::getExternalFunctionParameter(const std::string& aName) const
{
  if (!keymap)
  {
    if (theParent)
    {
      return theParent->getExternalFunctionParameter(aName);
    }
    else
    {
      return 0;
    }
  }

  dctx_value_t val;
  val.type = dynamic_context::dctx_value_t::no_val;
  val.func_param = 0;

  ValueMap::iterator lIter = keymap->find(aName);
  if (lIter == keymap->end())
  {
    if (theParent)
      return theParent->getExternalFunctionParameter(aName);
    else
      return 0;
  }

  val = lIter.getValue();

  ExternalFunctionParameter* lRes =
  static_cast<ExternalFunctionParameter*>(val.func_param);

  return lRes;
}


/*******************************************************************************
 Debugging info
********************************************************************************/
#ifndef NDEBUG
std::string dynamic_context::toString()
{
  std::stringstream ss;
  
  ss << "dynamic_context: " << this;
  dynamic_context* parent = getParent();
  while (parent != NULL)
  {
    ss << " -> " << parent;
    parent = parent->getParent();
  }
  ss << std::endl;

  for (csize i=0; i < theVarValues.size(); i++)
  {
    ss << "    var[" << i << "]: ";
    if (theVarValues[i].hasItemValue())
      ss << theVarValues[i].theValue.item->toString();
    else if (theVarValues[i].hasSeqValue())
      ss << theVarValues[i].theValue.temp_seq->toString();
    ss << std::endl;
  }
  
  return ss.str();
}
#endif

uint64_t dynamic_context::getSnapshotID() const
{
  if (theParent)
    return theParent->getSnapshotID();
  else
    return theSnapshotID;
}

void dynamic_context::changeSnapshot()
{
  if (theParent)
    theParent->changeSnapshot();
  else
    ++theSnapshotID;

}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
