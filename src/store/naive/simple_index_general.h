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
#ifndef ZORBA_SIMPLE_STORE_INDEX_HASH_GENERAL
#define ZORBA_SIMPLE_STORE_INDEX_HASH_GENERAL

#include "store/naive/simple_index.h"
#include "store/naive/store_defs.h"

namespace zorba 
{ 

namespace simplestore 
{

/**************************************************************************//**
  Class ValueSet represents a value set as a vector of item handles.
*******************************************************************************/
class GeneralIndexValue
{
public:
  struct NodeInfo
  {
    store::Item_t theNode;
    bool          theMultiKey;
    bool          theUntyped;
  };

  typedef std::vector<NodeInfo>::const_iterator iterator;

protected:
  std::vector<NodeInfo> theNodes;

public:
  GeneralIndexValue(ulong size = 0) : theNodes(size) {}

  void addNode(store::Item_t& node, bool multikey, bool untyped);

  void clear() { theNodes.clear(); }

  iterator begin() { return theNodes.begin(); }

  iterator end()   { return theNodes.end(); }
};


/******************************************************************************

*******************************************************************************/
class GeneralIndex : public IndexImpl
{
  friend class SimpleStore;

protected:
  store::Item       * theLastNode;

protected:
  GeneralIndex(
        const store::Item_t& qname,
        const store::IndexSpecification& spec);

  bool isTyped() const { return (theSpec.theKeyTypes[0] != NULL); }

  void startInsertSession() { theLastNode = NULL; }

  void stopInsertSession()  { theLastNode = NULL; }
};


/******************************************************************************

*******************************************************************************/
class GeneralHashIndex : public GeneralIndex
{
  friend class SimpleStore;
  friend class GeneralHashProbeIterator;

  typedef HashMap<const store::IndexKey*,
                  GeneralIndexValue*,
                  IndexCompareFunction> IndexMap;

private:
  IndexCompareFunction   theCompFunction;
  IndexMap             * theMaps[XS_LAST];
  IndexMap             * theSingleMap;

protected:
  GeneralHashIndex(
        const store::Item_t& qname,
        const store::IndexSpecification& spec);

  ~GeneralHashIndex();

  bool insert(
        store::IndexKey*& key,
        store::Item_t& item);

  bool insertInMap(
        store::IndexKey*& key,
        store::Item_t& node,
        IndexMap*& targetMap,
        bool untyped);

  bool remove(
        const store::IndexKey* key,
        store::Item_t& item);
};


/******************************************************************************

********************************************************************************/
class GeneralHashProbeIterator : public store::IndexProbeIterator
{
protected:
  rchandle<GeneralHashIndex>                 theIndex;

  rchandle<IndexPointConditionImpl>          theCondition;

  std::vector<GeneralIndexValue*>            theResultSets;
  std::vector<GeneralIndexValue*>::iterator  theResultSetsIte;
  std::vector<GeneralIndexValue*>::iterator  theResultSetsEnd;
  GeneralIndexValue::iterator                theIte;
  GeneralIndexValue::iterator                theEnd;

public:
  GeneralHashProbeIterator(const store::Index_t& index);

  void init(const store::IndexCondition_t& cond);

  void open();

  bool next(store::Item_t& result);
  
  void reset();

  void close();
};



}
}

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
