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
#ifndef ZORBA_SHARED_TYPES_INCL_H
#define ZORBA_SHARED_TYPES_INCL_H

#include <memory>

#include <boost/smart_ptr.hpp>

namespace zorba {

  class XQuery;
  class StaticContext;
  class DynamicContext;
  class XmlDataManager;
  class Iterator;
  class ResultIterator;
  class StatelessExternalFunction;
  class TypeIdentifier;
  class ItemSequence;
  class Collection;

  class ErrorHandler;

  // smart pointers
  typedef boost::shared_ptr<XQuery>                     XQuery_t;
  typedef boost::shared_ptr<StaticContext>              StaticContext_t;
  typedef boost::shared_ptr<Iterator>                   Iterator_t;
  typedef boost::shared_ptr<TypeIdentifier>             TypeIdentifier_t;
  typedef boost::shared_ptr<Collection>                 Collection_t;

  // auto pointer (used for transfering ownership of the return type of external functions)
  typedef std::auto_ptr<ItemSequence>                   ItemSequence_t;

  // data handlers 
  class Item;
  class String;

} /* namespace zorba */
#endif
