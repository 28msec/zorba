/**
 * @copyright
 * ========================================================================
 *  Copyright FLWOR Foundation
 * ========================================================================
 *
 * @author Sorin Nasoi (sorin.nasoi@ipdevel.ro)
 * @file functions/ContextFunctions.cpp
 *
 */

#include "system/globalenv.h"
#include "functions/ContextFunctions.h"
#include "runtime/context/ContextImpl.h"

using namespace std;

namespace xqp
{
/*______________________________________________________________________
 *
 * 16 Context Functions
 *_______________________________________________________________________*/

/*
 * 16.1 fn:position
 *-----------------------*/

fn_position::fn_position(
  const signature& sig)
:
  function(sig)
{
}

PlanIter_t
fn_position::operator()(
  const QueryLoc& loc, 
  vector<PlanIter_t>& argv) const
{
  return new FnPositionIterator(loc, argv);
}

xqtref_t
fn_position::type_check(
  signature&) const
{
  return GENV_TYPESYSTEM.INTEGER_TYPE_ONE;
}

bool
fn_position::validate_args(
  vector<PlanIter_t>& argv) const
{
  return (argv.size()==0);
}

/*
 * 16.2 fn:last
 *-----------------------*/

fn_last::fn_last(
  const signature& sig)
:
  function(sig)
{
}

PlanIter_t
fn_last::operator()(
  const QueryLoc& loc, 
  vector<PlanIter_t>& argv) const
{
  return new FnLastIterator(loc, argv);
}

xqtref_t
fn_last::type_check(
  signature&) const
{
  return GENV_TYPESYSTEM.INTEGER_TYPE_ONE;
}

bool
fn_last::validate_args(
  vector<PlanIter_t>& argv) const
{
  return (argv.size()==0);
}

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
fn_current_dateTime::operator()(
  const QueryLoc& loc, 
  vector<PlanIter_t>& argv) const
{
  return new FnCurrentDateTimeIterator(loc, argv);
}

xqtref_t
fn_current_dateTime::type_check(
  signature&) const
{
  return GENV_TYPESYSTEM.DATETIME_TYPE_ONE;
}

bool
fn_current_dateTime::validate_args(
  vector<PlanIter_t>& argv) const
{
  return (argv.size()==0);
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
fn_current_date::operator()(
  const QueryLoc& loc, 
  vector<PlanIter_t>& argv) const
{
  return new FnCurrentDateIterator(loc, argv);
}

xqtref_t
fn_current_date::type_check(
  signature&) const
{
  return GENV_TYPESYSTEM.DATE_TYPE_ONE;
}

bool
fn_current_date::validate_args(
  vector<PlanIter_t>& argv) const
{
  return (argv.size()==0);
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
fn_current_time::operator()(
  const QueryLoc& loc, 
  vector<PlanIter_t>& argv) const
{
  return new FnCurrentTimeIterator(loc, argv);
}

xqtref_t
fn_current_time::type_check(
  signature&) const
{
  return GENV_TYPESYSTEM.TIME_TYPE_ONE;
}

bool
fn_current_time::validate_args(
  vector<PlanIter_t>& argv) const
{
  return (argv.size()==0);
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
fn_implicit_timezone::operator()(
  const QueryLoc& loc, 
  vector<PlanIter_t>& argv) const
{
  return new FnImplicitTimezoneIterator(loc, argv);
}

xqtref_t
fn_implicit_timezone::type_check(
  signature&) const
{
  return GENV_TYPESYSTEM.DT_DURATION_TYPE_ONE;
}

bool
fn_implicit_timezone::validate_args(
  vector<PlanIter_t>& argv) const
{
  return (argv.size()==0);
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
fn_default_collation::operator()(
  const QueryLoc& loc, 
  vector<PlanIter_t>& argv) const
{
  return new FnDefaultCollationIterator(loc, argv);
}

xqtref_t
fn_default_collation::type_check(
  signature&) const
{
  return GENV_TYPESYSTEM.STRING_TYPE_ONE;
}

bool
fn_default_collation::validate_args(
  vector<PlanIter_t>& argv) const
{
  return (argv.size()==0);
}

/*
 * 16.8 fn:static-base-uri
 *-----------------------*/

fn_static_base_uri::fn_static_base_uri(
  const signature& sig)
:
  function(sig)
{
}

PlanIter_t
fn_static_base_uri::operator()(
  const QueryLoc& loc, 
  vector<PlanIter_t>& argv) const
{
  return new FnStaticBaseURIIterator(loc, argv);
}

xqtref_t
fn_static_base_uri::type_check(
  signature&) const
{
  return GENV_TYPESYSTEM.ANY_URI_TYPE_QUESTION;
}

bool
fn_static_base_uri::validate_args(
  vector<PlanIter_t>& argv) const
{
  return (argv.size()==0);
}

} /* namespace xqp */
