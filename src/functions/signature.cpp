/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: signature.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR Foundation.
 *  Authors: John Cowan,Paul Pedersen
 *
 */
 
#include "signature.h"
#include "context/common.h"
#include <zorba/item.h>

using namespace std;

namespace zorba {

  signature::signature (Item_t name, xqtref_t arg1,
                        bool variadic, xqtref_t return_type)
    : signature_base (variadic),
      qname_p(name)
  {
    argv.push_back(return_type);
    argv.push_back(arg1);
  }

signature::signature(
  Item_t name,
  xqtref_t return_type)
:
  qname_p(name)
{
  argv.push_back(return_type);
}

signature::signature(
  Item_t name,
  xqtref_t arg1,
  xqtref_t return_type)
:
  qname_p(name)
{
  argv.push_back(return_type);
  argv.push_back(arg1);
}

signature::signature(
  Item_t name,
  xqtref_t arg1,
  xqtref_t arg2,
  xqtref_t return_type)
:
  qname_p(name)
{
  argv.push_back(return_type);
  argv.push_back(arg1);
  argv.push_back(arg2);
}

signature::signature(
  Item_t name,
  xqtref_t arg1,
  xqtref_t arg2,
  xqtref_t arg3,
  xqtref_t return_type)
:
  qname_p(name)
{
  argv.push_back(return_type);
  argv.push_back(arg1);
  argv.push_back(arg2);
  argv.push_back(arg3);
}

signature::signature(
  Item_t name,
  xqtref_t arg1,
  xqtref_t arg2,
  xqtref_t arg3,
  xqtref_t arg4,
  xqtref_t return_type)
:
  qname_p(name)
{
  argv.push_back(return_type);
  argv.push_back(arg1);
  argv.push_back(arg2);
  argv.push_back(arg3);
  argv.push_back(arg4);
}

signature::signature(Item_t name,
                     const vector<xqtref_t>& _argv,
                     xqtref_t return_type)
  : qname_p(name)
{
  argv.push_back (return_type);
  copy (_argv.begin (), _argv.end (), back_inserter (argv));
}

signature::~signature()
{
}


} /* namespace zorba */

