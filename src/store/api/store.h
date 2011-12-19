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

#include <zorba/config.h>
#include "zorbatypes/schema_types.h"

#include "store/api/shared_types.h"
#include "store/api/load_properties.h"

#ifndef ZORBA_NO_FULL_TEXT
#include "runtime/full_text/stemmer.h"
#endif /* ZORBA_NO_FULL_TEXT */

namespace zorba 
{ 

SYNC_CODE(class Lock;)


namespace store 
{

class IndexSpecification;
class IteratorFactory;


/**
 * Manages XDM Instances 
 */
class  Store
{
public:
  virtual ~Store() { }


  /*-------------------------- Zorba Engine Internal -------------------------*/

  /**
   *  Get the item factory used by this store.
   */
  virtual ItemFactory* getItemFactory() const = 0;

  /**
   *  Get the iterator factory used by this store.
   */
  virtual IteratorFactory* getIteratorFactory() const = 0;

  SYNC_CODE(virtual Lock& getGlobalLock() = 0;)

  /*----------------------------- Temp Sequences -----------------------------*/

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
  virtual TempSeq_t createTempSeq(const Iterator_t& iterator, bool lazy) = 0;

  /**
   * Creates a new TempSeq that is initialized with the given vector.
   */
  virtual TempSeq_t createTempSeq(std::vector<Item_t>& item_v) = 0;

  /**
   * Creates a new TempSeq that is initialized with the given vector.
   */
  virtual TempSeq_t createTempSeq(Item_t& item) = 0;

  /**
   * Creates a new, empty TempSeq.
   */
  virtual TempSeq_t createTempSeq(bool lazy) = 0;

  /* ---------------------- Node Reference Management ------------------------*/

  /**
   * Computes the reference of the given node.
   *
   * @param node XDM node
   * @return the identifier as an item of type xs:anyURI
   */
  virtual bool getNodeReference(Item_t& result, Item* node) = 0;

  /**
   * Returns whether a reference has already been generated for the given node.
   *
   * @param item XDM node
   * @return whether a reference has already been generated for the given node.
   */
  virtual bool hasReference(const Item* node) = 0;

  /**
   * Returns the node which is identified by the given reference.
   * If the given reference is not a valid reference, as generated by
   * getReference, error ZAPI0028 is raised.
   *
   * @param reference an xs:anyURI item
   * @returns the node identified by the reference, NULL otherwise
   */
  virtual bool getNodeByReference(store::Item_t& result, const zstring& reference) = 0;

  /* ------------------ Structural Information Management ----------------------*/

  /**
   * Computes the structural information of the passed item.
   *
   * @param item XDM item
   * @return Returns an item of type xs:uri
   */
  virtual bool getStructuralInformation(Item_t& result, const Item* node) = 0;

  /* --------------------------- Node Id Management ---------------------------*/

  /**
   * Compares two nodes, based on their node id.
   * @param node1
   * @param node2
   * @return 	-1, if node1.id &lt; node2.id
   *					 0, if node1.id == node2.id
   *					+1, if node1.id &gt; node2.id
   */
  virtual short compareNodes(Item* node1, Item* node2) const = 0;
		
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
   * Create and return an iterator that eliminates the duplicate nodes in the
   * set of nodes which are produced by the given input iterator.
   *
   * @param input The input iterator that produces the sequence over which
   *        duplicate elimination will be performed.
   * @param aAllowAtomics If true, the input sequence may consist of nodes only
   *        or atomic values only. In the later case, no duplicate elimination
   *        is performed. If false, then the input sequence must contain nodes
   *        only.
   */
  virtual Iterator_t distinctNodes(Iterator*, bool aAllowAtomics = false) = 0;

  /** 
   * Create and return an iterator that makes sure the sequence produced by the
   * given input iterator does not contain any duplicate nodes (it is assumed
   * that the input iterator produces nodes only).
   *
   * @param input The input iterator that produces the sequence over which
   *        duplicate nodes check will be performed.
   */
  virtual Iterator_t checkDistinctNodes(Iterator* input) = 0;

#ifdef DATAGUIDE
  /**
   *
   */
  bool getPathInfo(
        const store::Item*               docUri,
        std::vector<const store::Item*>& contextPath,
        std::vector<const store::Item*>& relativePath,
        bool                             isAttrPath,
        bool&                            found,
        bool&                            unique);
#endif

  /* ------------------------ Document Management ---------------------------*/

  /**
   * Load a document to the store. The document is loaded from an input stream.
   *
   * @param baseUri The base uri of the document to load.
   * @param docUri The uri of the document to load. This uri can be used to refer
   *        to the document in the store.
   * @param stream User heap allocated stream. This will NOT be freed by Zorba when
   *        finishing loading doc.
   * @param loadProperties Properties on how to do the document loading
   * @return rchandle to the newly created document or NULL if a document with
   *         the given uri exists already.
   */
  virtual Item_t loadDocument(
         const zstring& baseUri,
         const zstring& docUri,
         std::istream& stream,
         const LoadProperties& loadProperties) = 0;

  /**
   * Load a document to the store. The document is loaded from an input stream.
   * Do the lazy loading of document. The stream will be freed by Zorba when finished.
   *
   * @param baseUri The base uri of the document to load.
   * @param docUri The uri of the document to load. This uri can be used to refer
   *        to the document in the store.
   * @param stream User heap allocated stream. This will be freed by Zorba when
   *        finishing loading doc.
   * @param loadProperties Properties on how to do the document loading
   * @return rchandle to the newly created document or NULL if a document with
   *         the given uri exists already.
   * @deprecate
   */
  virtual Item_t loadDocument(
        const zstring& baseUri,
        const zstring& docUri,
        std::istream* stream,
        const LoadProperties& loadProperties) = 0;


  /**
   * Get an rchandle to the root node of the document with the given uri.
   *
   * @param uri The uri of the document to access.
   */
  virtual Item_t getDocument(const zstring& uri) = 0;

  virtual void addNode(const zstring& uri, const Item_t& node) = 0;

  virtual Iterator_t getDocumentNames() const = 0;

  /* ------------------------ Collection Management ---------------------------*/

  /** Returns an XDM instance which is saved in the store 
   * (corresponds to the opening of a connection to a database)
   *
   * @param QName the name of the collection
   * @param bool whether the collection searched is a dynamic or static collection
   * @return handle object of the collection. Returns NULL if the collection
   *         does not exist
   */
  virtual Collection_t getCollection(
      const Item* name,
      bool aDynamicCollection = false) = 0;

  /** 
   * Returns an iterator that lists the names of all the available collections.
   */
  virtual Iterator_t listCollectionNames(bool aDynamicCollections = false) = 0;


  /* ------------------------ Index Management ---------------------------*/

  /**
   * Creates a new index. Used for temp indexes only (non-temp indexes are
   * created via PUL primitives).
   *
   * @param qname The qname identifying the index. Node: The map between 
   *        qnames and temp indices is stored in the dynamic context.
   * @param spec The index specification. It specifies the index properties
   *        (@see index.h)
   * @param sourceIter It produces the entries to be inserted in the index.
   *        Note: Given that iterators can produce only a single item at a time, 
   *        the given source iterator does not actually produce whole index 
   *        entries. Instead, the items of each index entry are produced one
   *        at a time: first the domain node, followed by each of the key items.
   */
  virtual Index_t createIndex(
        const Item_t& qname,
        const IndexSpecification& spec,
        Iterator* sourceIter) = 0;

  /**
   * Gets an existing index.
   *
   * @param qname The qname identifying the index. For non-temporary indices,
   *        the store maintains the map between qnames and indices and makes
   *        sure that there are no two indices with the same qname.
   */
  virtual Index* getIndex(const Item* qname) = 0;

  /** 
   * Returns an iterator that lists the names of all the available indexes.
   */
  virtual Iterator_t listIndexNames() = 0;


  /* ------------------- Integrity Constraints Management ------------------- */

  /**
   * Lists all active integrity constraints.
   */
  virtual Iterator_t listActiveICNames() = 0;

  /**
   * Returns integrity constraint  for this name, NULL if not active.
   */
  virtual IC* getIC(const Item* icQName)  = 0;

  /* --------------------------- Map Management ------------------------------*/

  virtual Index* getMap(const Item* aQName) const = 0;

  virtual Iterator_t listMapNames() = 0;

#ifdef ZORBA_WITH_JSON
  /* ----------------------- JSON Array  Management --------------------------*/

  virtual void populateJSONArray(
      Item* array,
      Iterator* iter,
      const store::CopyMode& copymode) = 0;
#endif

#ifndef ZORBA_NO_FULL_TEXT
  /* ------------------------ Full-Text -------------------------------------*/

  /**
   * Sets the StemmerProvider to use.
   *
   * @param p The StemmerProvider to use or NULL to use the default.
   */
  virtual void setStemmerProvider(internal::StemmerProvider const *p) = 0;

  /**
   * Gets the StemmerProvider in use.
   *
   * @return Returns said StemmerProvider.
   */
  virtual internal::StemmerProvider const* getStemmerProvider() const = 0;

  /**
   * Sets the TokenizerProvider to use.
   *
   * @param provider The TokenizerProvider to use or NULL to use the default.
   */
  virtual void setTokenizerProvider(TokenizerProvider const *provider) = 0;

  /**
   * Gets the TokenizerProvider in use.
   *
   * @return Returns said TokenizerProvider.
   */
  virtual TokenizerProvider const* getTokenizerProvider() const = 0;

#endif /* ZORBA_NO_FULL_TEXT */

#ifdef ZORBA_WITH_JSON
  virtual Item_t parseJSON(
      std::istream& stream,
      internal::diagnostic::location* relative_error_loc
    ) = 0;

#endif
};

} // namespace store
} // namespace zorba

#endif /* ZORBA_STORE_STORE_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
