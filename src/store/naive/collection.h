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
#ifndef ZORBA_SIMPLESTORE_COLLECTION
#define ZORBA_SIMPLESTORE_COLLECTION

#include "shared_types.h"

#include "store/api/collection.h"


namespace zorba { namespace simplestore {

/*******************************************************************************
  Interface for Collection used in the SimpleStore

  theName        : The user-provided qname of the collection.
********************************************************************************/
class Collection : public store::Collection
{
protected:
  store::Item_t                 theName;

public:
  /***************************** Constructors *********************************/

  Collection(const store::Item_t& aName)
    : 
    theName(aName)
  {
  }

  Collection()
  {
  }

  virtual ~Collection() {}

  /***************** zorba::store::Collection interface ***********************/

  const store::Item* getName() const { return theName.getp(); }

  zorba::xs_integer size() const  = 0;

  zorba::store::Iterator_t getIterator() = 0;

  virtual zorba::store::Item_t nodeAt(xs_integer position) = 0;

  virtual bool findNode(const store::Item* node, xs_integer& position) const = 0;

  virtual bool isDynamic() const = 0;

  virtual void getAnnotations(std::vector<zorba::store::Annotation_t>&) const = 0;

  /************************* Updates on collection ****************************/

  virtual void addNode(store::Item* node, xs_integer position = xs_integer(-1)) = 0;

  virtual zorba::xs_integer addNodes(
      std::vector<store::Item_t>& nodes,
      const store::Item* targetNode,
      bool before) = 0;

  virtual bool removeNode(store::Item* node, xs_integer& pos) = 0;

  virtual bool removeNode(xs_integer position) = 0;

  virtual zorba::xs_integer removeNodes(xs_integer position, xs_integer num) = 0;

  virtual void removeAll() = 0;

  virtual void adjustTreePositions() = 0;

  /***************************** ID Management ********************************/

  virtual ulong getId() const = 0;

  virtual ulong createTreeId() = 0;

  /*********************** Indices ********************************************/
  static void getIndexes(
      const store::Item* name,
      std::vector<store::Index*>& indexes);

  void getIndexes(std::vector<store::Index*>& indexes);

  /**** Returns active integrity constraints referencing this collection ******/
  static void getActiveICs(
      const store::Item* name,
      std::vector<store::IC*>& ics);

  void getActiveICs(std::vector<store::IC*>& ics);

  /**************************** Claim of ownership ****************************/
protected:
  virtual void claimOwnership(simplestore::XmlTree* aTree);
  
}; /* class Collection */


} /* namespace simplestore */ } /* namespace zorba */

#endif
