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
#ifndef ZORBA_TREE_ID_GENERATOR_H
#define ZORBA_TREE_ID_GENERATOR_H

#include <zorbautils/hashmap_itemh.h>
#include <zorbautils/mutex.h>

#include "tree_id.h"

namespace zorba {

namespace simplestore {

/*******************************************************************************
  This class is an abstract class for tree ID generation. It provides
  a creation method, two comparison methods (= and <) as well as a way
  to parse a string back to an ID.
********************************************************************************/
class TreeIdGenerator 
{
public:
  virtual ~TreeIdGenerator() {}

  virtual TreeId create() = 0;
};


/*******************************************************************************
  Zorba's implementation of the tree ID generator.
********************************************************************************/
class SimpleTreeIdGenerator : public TreeIdGenerator 
{
private:
  ulong theNextId;
  SYNC_CODE(Mutex theCounterMutex;)

public:
  SimpleTreeIdGenerator() : theNextId(1) {}

  virtual TreeId create();
};


/*******************************************************************************
  This class allows generation of independent tree ID generators (each of
  them might have its own counter).
********************************************************************************/
class TreeIdGeneratorFactory 
{
public:
  virtual ~TreeIdGeneratorFactory() {}
  
  virtual TreeIdGenerator* createTreeGenerator(ulong aCollectionId) = 0;

  virtual TreeIdGenerator& getDefaultTreeIdGenerator() = 0;
};


/*******************************************************************************
  Zorba's implementation of the tree ID generator factory.
********************************************************************************/
class SimpleTreeIdGeneratorFactory : public TreeIdGeneratorFactory 
{
protected:
  SimpleTreeIdGenerator theDefaultGenerator;

public:
  virtual TreeIdGenerator* createTreeGenerator(ulong aCollectionId);

  virtual TreeIdGenerator& getDefaultTreeIdGenerator();
};

} // simplestore
} // zorba

#endif /* ZORBA_TREE_ID_GENERATOR_H */
