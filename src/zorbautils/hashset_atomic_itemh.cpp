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

#include "zorbautils/hashset_atomic_itemh.h"

#include "runtime/booleans/BooleanImpl.h"


namespace zorba 
{

AtomicItemHandleHashSet::AtomicItemHandleHashSet(
    ValueCompareParam* compParam,
    csize size)
  :
  theCompareParam(compParam),
  theCompareFunction(compParam),
  theSet(theCompareFunction, size, false)
{
}


AtomicItemHandleHashSet::~AtomicItemHandleHashSet()
{
  clear();

  if (theCompareParam)
    delete theCompareParam; 
}


void AtomicItemHandleHashSet::clear()
{
  HashSet<store::Item*, AtomicItemHandleHashSet::CompareFunction>::iterator ite;
  HashSet<store::Item*, AtomicItemHandleHashSet::CompareFunction>::iterator end;

  ite = theSet.begin();
  end = theSet.end();

  for (; ite != end; ++ite)
  {
    store::Item* n = (*ite).first;
    n->removeReference();
  }

  theSet.clear(); 
}

}

/* vim:set et sw=2 ts=2: */
