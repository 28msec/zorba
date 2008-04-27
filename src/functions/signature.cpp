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
#include "signature.h"
#include "store/api/item.h"

using namespace std;

namespace zorba {

  signature::signature (store::Item_t name, xqtref_t arg1,
                        bool variadic, xqtref_t return_type)
    : signature_base (variadic),
      qname_p(name)
  {
    argv.push_back(return_type);
    argv.push_back(arg1);
  }

signature::signature(
  store::Item_t name,
  xqtref_t return_type)
:
  qname_p(name)
{
  argv.push_back(return_type);
}

signature::signature(
  store::Item_t name,
  xqtref_t arg1,
  xqtref_t return_type)
:
  qname_p(name)
{
  argv.push_back(return_type);
  argv.push_back(arg1);
}

signature::signature(
  store::Item_t name,
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
  store::Item_t name,
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
  store::Item_t name,
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

signature::signature(store::Item_t name,
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

