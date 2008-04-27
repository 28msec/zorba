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
#include "system/globalenv.h"
#include "functions/ContextFunctions.h"
#include "runtime/context/ContextImpl.h"

using namespace std;

namespace zorba
{
/*______________________________________________________________________
 *
 * 16 Context Functions
 *_______________________________________________________________________*/

/*
 * 16.3 fn:current-dateTime
 *-----------------------*/

fn_current_dateTime::fn_current_dateTime(
  const signature& sig)
:
  function(sig)
{
}

PlanIter_t
fn_current_dateTime::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new FnCurrentDateTimeIterator(loc, argv);
}



/*
 * 16.4 fn:current-date
 *-----------------------*/

fn_current_date::fn_current_date(
  const signature& sig)
:
  function(sig)
{
}

PlanIter_t
fn_current_date::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new FnCurrentDateIterator(loc, argv);
}



/*
 * 16.5 fn:current-time
 *-----------------------*/

fn_current_time::fn_current_time(
  const signature& sig)
:
  function(sig)
{
}

PlanIter_t
fn_current_time::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new FnCurrentTimeIterator(loc, argv);
}



/*
 * 16.6 fn:implicit-timezone
 *-----------------------*/

fn_implicit_timezone::fn_implicit_timezone(
  const signature& sig)
:
  function(sig)
{
}

PlanIter_t
fn_implicit_timezone::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new FnImplicitTimezoneIterator(loc, argv);
}



/*
 * 16.7 fn:default-collation
 *-----------------------*/

fn_default_collation::fn_default_collation(
  const signature& sig)
:
  function(sig)
{
}

PlanIter_t
fn_default_collation::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new FnDefaultCollationIterator(loc, argv);
}



} /* namespace zorba */
