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
#ifndef API_COLLECTION_H
#define API_COLLECTION_H

class Collection
{
private:
  zorba::Collection_t theCollection;

public:
  Collection(const Collection& aMgr) : theCollection(aMgr.theCollection) {}
  Collection(zorba::Collection* aMgr) : theCollection(aMgr) {}

  ItemSequence contents();
  void deleteNodeFirst();
  void deleteNodeLast();
  void deleteNodes(const ItemSequence &aNodes );
  void deleteNodesFirst(unsigned long aNumNodes );
  void deleteNodesLast(unsigned long aNumNodes );
  //std::vector< Annotation > getAnnotations():
  Item getName();
  TypeIdentifier getType();
  long long indexOf(const Item &aNode );
  void insertNodesAfter(const Item &aTarget, const ItemSequence &aNodes );
  void insertNodesBefore(const Item &aTarget, const ItemSequence &aNodes );
  void insertNodesFirst(const ItemSequence &aNodes );
  void insertNodesLast(const ItemSequence &aNodes );
  bool isStatic();
  //void  registerDiagnosticHandler(DiagnosticHandler *aDiagnosticHandler );
};

#endif