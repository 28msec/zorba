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
#ifndef ZORBA_TREE_ID_H
#define ZORBA_TREE_ID_H

#include "store/naive/shared_types.h"
#include "zorbautils/hashmap_itemh.h"

namespace zorba {

/*
This class is an abstract class for tree IDs.
You can convert an ID to a string, or copy it to another instance.
*/

class TreeId {
public:
  virtual ~TreeId() {}
public:
  virtual zstring toString() = 0;
  // Caller gets pointer ownership.
  virtual TreeId* copy() = 0;
};

/*
The type alias used everywhere in the program.
Only assign IDs with = if lvalue is taking over ownership.
Otherwise, copy.
*/
typedef std::auto_ptr<TreeId> TreeId_t;

/*
This class is an abstract class for tree ID generation. It provides
a creation method, two comparison methods (= and <) as well as a way
to parse a string back to an ID.
*/
class TreeIdGenerator {
public:
  virtual ~TreeIdGenerator() {}

  virtual TreeId_t create() = 0;
  virtual bool equals(const TreeId_t& id1, const TreeId_t& id2) const = 0;
  virtual bool isBefore(const TreeId_t& id1, const TreeId_t& id2) const = 0;
  virtual TreeId_t fromString(const zstring&) const = 0;
};

/*
This class allows generation of independent tree ID generators (each of
them might have its own counter).
*/
class TreeIdGeneratorFactory {
public:
  virtual ~TreeIdGeneratorFactory() {}
  
  virtual TreeIdGenerator* createTreeGenerator() = 0;
  virtual TreeIdGenerator& getDefaultTreeIdGenerator() = 0;
};

/*
Zorba's implementation of tree IDs, using an unsigned long.
*/
class ZorbaTreeId : public TreeId {
friend class ZorbaTreeIdGenerator;
private:
  ulong theId;
  ZorbaTreeId(ulong idKey);
public:
  zstring toString();  
  virtual TreeId* copy();
};

/*
Zorba's implementation of the tree ID generator.
*/
class ZorbaTreeIdGenerator : public TreeIdGenerator {
private:
  ulong theNextId;
public:
  ZorbaTreeIdGenerator() : theNextId(1) {}
  virtual TreeId_t create();
  virtual bool equals(const TreeId_t& id1, const TreeId_t& id2) const;
  virtual bool isBefore(const TreeId_t& id1, const TreeId_t& id2) const;
  virtual TreeId_t fromString(const zstring&) const;
};

/*
Zorba's implementation of the tree ID generator factory.
*/
class ZorbaTreeIdGeneratorFactory : public TreeIdGeneratorFactory {
public:
  virtual TreeIdGenerator* createTreeGenerator();
  virtual TreeIdGenerator& getDefaultTreeIdGenerator();
};

}

#endif /* ZORBA_TREE_ID_H */
