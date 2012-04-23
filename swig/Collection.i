/*
 * Copyright 2006-2012 The FLWOR Foundation.
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

%{  // start Implementation

  ItemSequence Collection::contents()
  {
    return ItemSequence( theCollection->contents() );
  }

  void Collection::deleteNodeFirst()
  {
    theCollection->deleteNodeFirst();
  }

  void Collection::deleteNodeLast()
  {
    theCollection->deleteNodeLast();
  }

  void Collection::deleteNodes(const SingletonItemSequence &aNodes )
  {
    theCollection->deleteNodes( aNodes.theItemSequence );
  }

  void Collection::deleteNodesFirst(unsigned long aNumNodes )
  {
    theCollection->deleteNodesFirst(aNumNodes);
  }

  void Collection::deleteNodesLast(unsigned long aNumNodes )
  {
    theCollection->deleteNodesLast(aNumNodes);
  }

  Item Collection::getName()
  {
    return Item( theCollection->getName() );
  }

  TypeIdentifier Collection::getType()
  {
    return TypeIdentifier( theCollection->getType() );
  }

  long long Collection::indexOf(const Item &aNode )
  {
    return theCollection->indexOf( aNode.theItem );
  }

  void Collection::insertNodesAfter(const Item &aTarget, const SingletonItemSequence &aNodes )
  {
    theCollection->insertNodesAfter( aTarget.theItem, aNodes.theItemSequence );
  }

  void Collection::insertNodesBefore(const Item &aTarget, const SingletonItemSequence &aNodes )
  {
    theCollection->insertNodesBefore( aTarget.theItem, aNodes.theItemSequence );
  }

  void Collection::insertNodesFirst(const SingletonItemSequence &aNodes )
  {
    theCollection->insertNodesFirst( aNodes.theItemSequence );
  }

  void Collection::insertNodesLast(const SingletonItemSequence &aNodes )
  {
    theCollection->insertNodesLast( aNodes.theItemSequence );
  }

  bool Collection::isStatic()
  {
    return theCollection->isStatic();
  }

%}  // end   Implementation

%include "Collection.h"
