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
#ifndef ZORBA_STORE_STORE_H
#define ZORBA_STORE_STORE_H

#include "zorbatypes/representations.h"

#include "common/shared_types.h"

namespace zorba { namespace store {

class Latch;


/**
 * Manages XDM Instances 
 */
class Store
{
public:
  virtual ~Store() { }

  /*---------------------------- Zorba Engine Internal ----------------------------*/

  /**
   *  Get the item factory used by this store.
   */
  virtual ItemFactory* getItemFactory() const = 0;

  virtual Latch& getGlobalLock() = 0;

  /**
   * Creates a new TempSeq. The instance can be used, e.g. for variable bindings.
   *
   * @param iterator   The source for the XMDInstance
   * @param copyNodes  If true, all nodes are copied before they are saved in the
   *                   temp sequence.
   * @param lazy			 Hint for the store. If possible a XMDInstance should be
   *                   evaluated lazily. For XQueryP it might be necassary to set
   *                   this to false.
   */
  virtual TempSeq_t createTempSeq(
        Iterator* iterator,
        bool copyNodes = false,
        bool lazy = true) = 0;


  /* -------------------------- Reference Management --------------------------*/
		
  /** 
   * Computes the URI of the passed item.
   *
   * @param item XDM item
   * @return Returns an item of type xs:uri 
   */
  virtual bool getReference(Item_t& result, const Item* node) = 0;
		
  /**
   * Returns Item which is identified by a reference
   *
   * @param uri Has to be an xs:URI item
   * @returns referenced item if it exists, otherwise NULL
   */
  virtual bool getNodeByReference(Item_t& result, const Item* uri) = 0;
		
		
  /* --------------------------- Node Id Management ---------------------------*/

  /**
   * Compares two nodes, based on their node id.
   * @param node1
   * @param node2
   * @return 	-1, if node1.id &lt; node2.id
   *					 0, if node1.id == node2.id
   *					+1, if node1.id &gt; node2.id
   */
  virtual long compareNodes(Item* node1, Item* node2) const = 0;
		
  /**
   * Sorts the nodes produced by the passed iterator
   * @param iterator to sort
   * @param ascendent true for ascendent and false for descendant
   * @param duplicate duplicate elemination should be applied
   * @return iterator which produces the sorted nodes
   */
  virtual Iterator_t sortNodes(
        Iterator* iterator,
        bool ascendent,
        bool duplicateElemination,
        bool aAcceptAtomics = false) = 0;
		
  /** 
   * Eliminate the duplicates in sequence of nodes produced by the given iterator
   * @param iterator
   */
  virtual Iterator_t distinctNodes(Iterator*, bool aAllowAtomics = false) = 0;


  /* ------------------------ Document Management ---------------------------*/

  /**
   * Load a document to the store. The document is loaded from an input stream.
   *
   * @param uri The uri of the document to load.
   * @return rchandle to the newly created document or NULL if a document
   *         with the given uri exists already.
   */
  virtual Item_t loadDocument(xqpStringStore_t& uri, std::istream& stream) = 0;
  /**
   * Load a document to the store. The document is loaded from an input stream.
     Do the lazy loading of document. The stream will be freed by Zorba when finished.
   *
   * @param uri The uri of the document to load.
   * @param stream User allocated stream. This will be freed by Zorba when finishing loading doc.
   * @return rchandle to the newly created document or NULL if a document
   *         with the given uri exists already.
   */
  virtual Item_t loadDocument(xqpStringStore_t& uri, std::istream* stream) = 0;

  virtual void addNode(const xqpStringStore* uri, const Item_t& node) = 0;

  /**
   * Get an rchandle to the root node of the document with the given uri.
   *
   * @param uri The uri of the document to access.
   */
  virtual Item_t getDocument(const xqpStringStore_t& uri) = 0;

  /**
   * Delete the document with the given uri.
   *
   * @param uri The uri of the document to delete.
   */
  virtual void deleteDocument(const xqpStringStore_t& uri) = 0;
		

  /* ------------------------ Collection Management ---------------------------*/

  /**
   * Creates a new unique URI which can be used as an ID for a collection.
   *
   * @return URI
   */
  virtual Item_t createUri() = 0;
	
  /**
   * Creates a collection in the store.
   * 
   * @param URI The URI of the collection to create.
   * @return rchandle to the newly created collection or NULL if a collection
   *         with the given uri exists already.
   */
  virtual Collection_t createCollection(xqpStringStore_t& uri) = 0;

  /** Creates a collection in the store (without given URI).
   * 
   * @return handle object of the newly created collection
   */
  virtual Collection_t createCollection() = 0;
	
  /** Returns an XDM instance which is saved in the store 
   * (corresponds to the opening of a connection to a database)
   *
   * @param URI of the colleciton
   * @return handle object of the collection. Returns NULL if the collection does not exist
   */
  virtual Collection_t getCollection(const xqpStringStore_t& uri) = 0;
		
  /** Deletes a collection.
   *
   * @param URI to identify the collection to delete.
   */
  virtual void deleteCollection(const xqpStringStore_t& uri) = 0;
};


} // namespace store
} // namespace zorba

#endif /* ZORBA_STORE_STORE_H */
