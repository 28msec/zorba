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
#ifndef ZORBA_SIMPLE_STORE_ITERATOR_FACTORY
#define ZORBA_SIMPLE_STORE_ITERATOR_FACTORY

#include "store/api/iterator_factory.h"


namespace zorba 
{

namespace simplestore 
{


class SimpleIteratorFactory : public store::IteratorFactory
{
public: 
  ~SimpleIteratorFactory() { }

  store::ChildrenIterator* createChildrenIterator();

  store::ChildrenReverseIterator* createChildrenReverseIterator();

  store::AttributesIterator* createAttributesIterator();

  store::IndexProbeIterator* createIndexProbeIterator(const store::Index_t& index);

  store::TempSeqIterator* createTempSeqIterator(bool lazy);
};

}
}
#endif
/* vim:set et sw=2 ts=2: */
