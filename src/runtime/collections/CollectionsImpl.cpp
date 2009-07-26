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

#include "zorbaerrors/Assert.h"
#include "zorbaerrors/error_messages.h"

#include "zorbatypes/zorbatypesError.h"
#include "zorbatypes/URI.h"
#include "zorbatypes/numconversions.h"

#include "store/api/item_factory.h"
#include "store/api/store.h"
#include "store/api/collection.h"

#include "api/collectionimpl.h"

#include "system/globalenv.h"

#include "runtime/api/runtimecb.h"

#include "context/dynamic_context.h"
#include "context/internal_uri_resolvers.h"
#include "store/api/pul.h"

#include "CollectionsImpl.h"

#include "api/serialization/serializer.h"
#include "store/api/copymode.h"

#include <fstream>

namespace zorba {

SERIALIZABLE_CLASS_VERSIONS(ZorbaCollectionExistsIterator)
END_SERIALIZABLE_CLASS_VERSIONS(ZorbaCollectionExistsIterator)

SERIALIZABLE_CLASS_VERSIONS(ZorbaNodeCountIterator)
END_SERIALIZABLE_CLASS_VERSIONS(ZorbaNodeCountIterator)

SERIALIZABLE_CLASS_VERSIONS(ZorbaNodeAtIterator)
END_SERIALIZABLE_CLASS_VERSIONS(ZorbaNodeAtIterator)

SERIALIZABLE_CLASS_VERSIONS(ZorbaIndexOfIterator)
END_SERIALIZABLE_CLASS_VERSIONS(ZorbaIndexOfIterator)

SERIALIZABLE_CLASS_VERSIONS(ZorbaExportXmlIterator)
END_SERIALIZABLE_CLASS_VERSIONS(ZorbaExportXmlIterator)

SERIALIZABLE_CLASS_VERSIONS(ZorbaListCollectionsIterator)
END_SERIALIZABLE_CLASS_VERSIONS(ZorbaListCollectionsIterator)



SERIALIZABLE_CLASS_VERSIONS(ZorbaImportXmlIterator)
END_SERIALIZABLE_CLASS_VERSIONS(ZorbaImportXmlIterator)

SERIALIZABLE_CLASS_VERSIONS(ZorbaImportCatalogIterator)
END_SERIALIZABLE_CLASS_VERSIONS(ZorbaImportCatalogIterator)

SERIALIZABLE_CLASS_VERSIONS(ZorbaImportFolderIterator)
END_SERIALIZABLE_CLASS_VERSIONS(ZorbaImportFolderIterator)

SERIALIZABLE_CLASS_VERSIONS(ZorbaCreateCollectionIterator)
END_SERIALIZABLE_CLASS_VERSIONS(ZorbaCreateCollectionIterator)

SERIALIZABLE_CLASS_VERSIONS(ZorbaDeleteCollectionIterator)
END_SERIALIZABLE_CLASS_VERSIONS(ZorbaDeleteCollectionIterator)

SERIALIZABLE_CLASS_VERSIONS(ZorbaDeleteAllCollectionsIterator)
END_SERIALIZABLE_CLASS_VERSIONS(ZorbaDeleteAllCollectionsIterator)

SERIALIZABLE_CLASS_VERSIONS(ZorbaInsertNodeFirstIterator)
END_SERIALIZABLE_CLASS_VERSIONS(ZorbaInsertNodeFirstIterator)

SERIALIZABLE_CLASS_VERSIONS(ZorbaInsertNodeLastIterator)
END_SERIALIZABLE_CLASS_VERSIONS(ZorbaInsertNodeLastIterator)

SERIALIZABLE_CLASS_VERSIONS(ZorbaInsertNodeBeforeIterator)
END_SERIALIZABLE_CLASS_VERSIONS(ZorbaInsertNodeBeforeIterator)

SERIALIZABLE_CLASS_VERSIONS(ZorbaInsertNodeAfterIterator)
END_SERIALIZABLE_CLASS_VERSIONS(ZorbaInsertNodeAfterIterator)

SERIALIZABLE_CLASS_VERSIONS(ZorbaInsertNodeAtIterator)
END_SERIALIZABLE_CLASS_VERSIONS(ZorbaInsertNodeAtIterator)

SERIALIZABLE_CLASS_VERSIONS(ZorbaRemoveNodeIterator)
END_SERIALIZABLE_CLASS_VERSIONS(ZorbaRemoveNodeIterator)

SERIALIZABLE_CLASS_VERSIONS(ZorbaRemoveNodeAtIterator)
END_SERIALIZABLE_CLASS_VERSIONS(ZorbaRemoveNodeAtIterator)

SERIALIZABLE_CLASS_VERSIONS(FnCollectionIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnCollectionIterator)


/*******************************************************************************
  fn:collection() as node()*
  fn:collection($uri as xs:string?) as node()*
********************************************************************************/
FnCollectionIteratorState::FnCollectionIteratorState()
  :
  theIteratorOpened(false)
{
}


FnCollectionIteratorState::~FnCollectionIteratorState()
{
  if ( theIterator != NULL ) 
  {
    // closing the iterator is necessary here if an exception occurs
    // in the producer or if the iterator is not fully consumed
    if (theIteratorOpened) 
    {
      theIterator->close();
      theIteratorOpened = false;
    }
    theIterator = NULL;
  }
}


void FnCollectionIteratorState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
  theIterator = NULL;
}


void FnCollectionIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);

  if ( theIterator != NULL ) 
  {
    // closing the iterator is necessary here if an exception occurs
    // in the producer or if the iterator is not fully consumed
    if (theIteratorOpened) {
      theIterator->close();
      theIteratorOpened = false;
    }
    theIterator = NULL;
  }
}


bool FnCollectionIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t       lURI, resolvedURIItem;
  store::Collection_t coll;
  xqpStringStore_t    resolvedURIString, tt;

  FnCollectionIteratorState *state;
  DEFAULT_STACK_INIT(FnCollectionIteratorState, state, planState);

  if (theChildren.size() == 1 &&
      consumeNext(lURI, theChildren[0].getp(), planState)) 
  {
    try 
    {
      tt = lURI->getStringValue();
      resolvedURIString = getStaticContext(planState)->
                          resolve_relative_uri(lURI->getStringValueP(),
                                               xqp_string()).getStore();

      GENV_ITEMFACTORY->createAnyURI(resolvedURIItem, resolvedURIString);
    }
    catch (error::ZorbaError&) 
    {
      ZORBA_ERROR_LOC_DESC(FODC0002, loc, "Error retrieving resource.");
    }
  }
  else 
  {
    resolvedURIItem = planState.theRuntimeCB->theDynamicContext->
                      get_default_collection();

    if( NULL == resolvedURIItem)
      ZORBA_ERROR_LOC_DESC(FODC0002, loc,
                           "Default collection is undefined in the dynamic context.");
  }

  coll =  getStaticContext(planState)->get_collection_uri_resolver()->
          resolve(resolvedURIItem, getStaticContext(planState));

  if (coll == 0) 
  {
    ZORBA_ERROR_LOC_PARAM(FODC0004, loc,
                          resolvedURIItem->getStringValue()->c_str(), "");
  }

  /** return the nodes of the collection */
  state->theIterator = coll->getIterator(false);
  ZORBA_ASSERT(state->theIterator!=NULL);
  state->theIterator->open();
  state->theIteratorOpened = true;

  while(state->theIterator->next(result))
    STACK_PUSH (true, state);

  // close as early as possible
  state->theIterator->close();
  state->theIteratorOpened = false;

  STACK_END (state);
}


/*******************************************************************************
  declare function collection-exists() as xs:boolean

  declare function collection-exists( $uri as xs:string?) as xs:boolean

  Returns true if a collection with the requested $uri is found in the collection
  pool, false otherwise.

  Error conditions:
  - If the collection URI is empty and the default collection
    is not defined in the dynamic context, FODC0002 is raised
  - XQST0046: could not resolve uri or given uri is not a valid uri
********************************************************************************/
bool
ZorbaCollectionExistsIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  PlanIteratorState  *state;
  store::Item_t       item, resolvedURIItem;
  xqpStringStore_t    resolvedURIString;
  store::Collection_t lCollection;
  bool                res = false;

  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if((theChildren.size()==0) ||
      ((theChildren.size()==1) &&
      !consumeNext(item, theChildren[0].getp(), planState)))
  {
    item = planState.theRuntimeCB->theDynamicContext->get_default_collection();
    if(NULL == item)
      ZORBA_ERROR_LOC_DESC(FODC0002, loc,
                           "Default collection undefined in the dynamic context.");
  }

  try
  {
    resolvedURIString = getStaticContext(planState)->
                        resolve_relative_uri(item->getStringValueP(),
                                              xqp_string()).getStore();

    GENV_ITEMFACTORY->createAnyURI(resolvedURIItem, resolvedURIString);
  }
  catch (error::ZorbaError&)
  {
    ZORBA_ERROR_LOC_PARAM(XQST0046,
                          loc,
                          item->getStringValue()->c_str(),
                          "URI literal empty or is not in the lexical space of xs:anyURI" );
  }

  lCollection = getStaticContext(planState)->get_collection_uri_resolver()->
                resolve(resolvedURIItem, getStaticContext(planState));
  res = (lCollection != NULL);

  GENV_ITEMFACTORY->createBoolean(result, res);
  STACK_PUSH(true, state );

  STACK_END (state);
}


/*******************************************************************************
  declare function import-xml($uri as xs:anyURI) as none

  This function will create a new collection and import a given XML document
  into it. The document to import is identified by the $uri parameter; this uri
  will be used as the uri of the collection. If the $uri is found in the 
  collection pool no import is done.

  Error conditions:
  - If the XML file specified by the $uri parameter does not exist, an error is
    raised (API0033_FILE_OR_FOLDER_DOES_NOT_EXIST - the file or folder does not
    exist).
  - If the XML file cannot be opened, an error is raised 
    (API0034_FILE_OR_FOLDER_CANNOT_BE_OPENED - a file or folder cannot be opened).
********************************************************************************/
bool
ZorbaImportXmlIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t       uriItem;
  store::Item_t       resolvedURIItem;
  xqpStringStore_t    resolvedURIString;
  store::Item_t       node;
  store::Item_t       copyNode;
  store::Collection_t theColl;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(uriItem, theChildren[0].getp(), planState))
  {
    try
    {
      resolvedURIString = getStaticContext(planState)->
                          resolve_relative_uri(uriItem->getStringValueP(),
                               xqp_string()).getStore();

      GENV_ITEMFACTORY->createAnyURI(resolvedURIItem, resolvedURIString);
    }
    catch (error::ZorbaError&)
    {
      ZORBA_ERROR_LOC_PARAM(XQST0046, loc, uriItem->getStringValue()->c_str(),
                                "URI literal empty or is not in the lexical space of xs:anyURI" );
    }

    try 
    {
    theColl = getStaticContext(planState)->get_collection_uri_resolver()->
        resolve(resolvedURIItem, getStaticContext(planState));

    if (theColl == NULL)
    {
        theColl = GENV_STORE.createCollection(resolvedURIString);

        node = GENV_STORE.getDocument(resolvedURIString);

        if (node == NULL) 
      {
          node = getStaticContext(planState)->get_document_uri_resolver()->
                 resolve(resolvedURIItem, getStaticContext(planState), false, false);
          
          theColl->addNode(node, 1);
      }
        else
      {
          store::CopyMode lCopyMode;
          copyNode = node->copy(NULL, NULL, lCopyMode);
          theColl->addNode(copyNode, 1);
      }
        }
    }
        catch (error::ZorbaError& e) 
        {
          ZORBA_ERROR_LOC_DESC(e.theErrorCode, loc, e.theDescription);
        }
      }

  STACK_END (state);
}


/*******************************************************************************
  declare function import-catalog($uri as xs:anyURI) as none

  The function will open the given XML file and interpret it as a catalog.
  Assuming $uri is 'file://localhost/home/user_1/catalog.xml', it must have the
  following structure:
  <catalog>
  <doc href="file1.xml"/>
  <doc href="path/file2.xml"/>
  <doc href="path/file3.xml"/>
  ...
  </catalog>

  Each of the uris referenced in the <doc> tags is first looked up in the store's
  collection pool. If it is already present, nothing is done; otherwise the doc
  is loaded, a new collection is created for it with the same uri, and the doc is
  added to this new collection.

  The URIs of the catalog and the files may include a protocol specification,
  such as "file://" or "http://". 

  The function will not validate the catalog file's structure. In case it is
  malformed - no XML files will be imported (actually, zorba will crash ???).

  In case a href attribute contains no path, only the name of the file (see the
  first href attribute in the example above) the file will be looked in the same
  path as the catalog ('file://localhost/home/user_1/file1.xml' in the example
  above).

  Error conditions:
  - If the catalog file specified by the $uri parameter or any of the files
    specified by the href attributes does not exist, an error is raised
    (API0033_FILE_OR_FOLDER_DOES_NOT_EXIST - the file or folder does not exist).
  - If the catalog file or the href files cannot be opened, an error is raised
    (API0034_FILE_OR_FOLDER_CANNOT_BE_OPENED - a file or folder cannot be opened)

********************************************************************************/
bool
ZorbaImportCatalogIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t       catalogUriItem;
  store::Item_t       catalogResolvedUriItem;
  URI                 catalogURI;
  xqpStringStore_t    catalogUriString;
  xqpStringStore_t    catalogResolvedUriString;

  store::Item_t       catalogRootNode;
  store::Item_t       catalogNode;
  store::Item_t       catalogAttr;
  store::Iterator_t   childrenIte;
  store::Iterator_t   attributesIte;

  store::Item_t       docUriItem;
  store::Item_t       docResolvedUriItem;
  URI                 docURI;
  xqpStringStore_t    docUriString;
  xqpStringStore_t    docResolvedUriString;

  store::Collection_t theColl;
  store::Item_t       docRootNode;
  store::Item_t       copyNode;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (!consumeNext(catalogUriItem, theChildren[0].getp(), planState))
    ZORBA_ASSERT(false);

  // Resolve the URI of the catalog document.
  try 
  {
    catalogURI = URI(catalogUriItem->getStringValue().getp());

    catalogUriString = catalogURI.toString().getStore();

    catalogResolvedUriString = getStaticContext(planState)->
                               resolve_relative_uri(catalogUriString.getp(),
                                               xqp_string()).getStore();

    GENV_ITEMFACTORY->createAnyURI(catalogResolvedUriItem, catalogResolvedUriString);
    }
    catch (error::ZorbaError& e) 
    {
      ZORBA_ERROR_LOC_DESC(FODC0005, loc, e.theDescription);
    }

  // Load the catalog document, if it has not been loaded before
    try 
    {
    catalogRootNode = GENV_STORE.getDocument(catalogResolvedUriString);

    if (catalogRootNode == NULL) 
    {
      catalogRootNode = getStaticContext(planState)->get_document_uri_resolver()->
                        resolve(catalogResolvedUriItem,
                                getStaticContext(planState),
                                false,
                                false);
    }
  }
    catch (error::ZorbaError& e) 
    {
      ZORBA_ERROR_LOC_DESC(e.theErrorCode, loc, e.theDescription);
    }

  // Navigate the catalog doc to extract the uri of each data doc and then, if
  // the data doc is not loaded already, create a collection for it, load the
  // doc, and add it to its associated collection.
  if(catalogRootNode->getNodeKind() == store::StoreConsts::documentNode) 
  {
    childrenIte = catalogRootNode->getChildren();
    childrenIte->open();
    childrenIte->next(catalogNode);
    childrenIte->close();

    childrenIte = catalogNode->getChildren();
    childrenIte->open();

    while(childrenIte->next(catalogNode)) 
    {
      if(catalogNode->getNodeKind() == store::StoreConsts::elementNode &&
         catalogNode->getNodeName()->getLocalName()->byteEqual("doc", 3)) 
      {
        attributesIte = catalogNode->getAttributes();
        attributesIte->open();

        for (; attributesIte->next(catalogAttr); ) 
        {
          if(catalogAttr->getNodeName()->getLocalName()->byteEqual("href", 4)) 
          {
            try
            {
              if (catalogAttr->getStringValue()->indexOf("/") == -1)
                docURI = URI(catalogURI, catalogAttr->getStringValue().getp());
            else
                docURI = URI(catalogAttr->getStringValue().getp());

              docUriString = docURI.toString().getStore();

              docResolvedUriString = docUriString;

              GENV_ITEMFACTORY->createAnyURI(docResolvedUriItem, docResolvedUriString);
            }
            catch (error::ZorbaError& e) 
            {
              ZORBA_ERROR_LOC_DESC(FODC0005, loc, e.theDescription);
            }

              try 
              {
              theColl = getStaticContext(planState)->get_collection_uri_resolver()->
                        resolve(docResolvedUriItem, getStaticContext(planState));

              if (theColl == NULL) 
              {
                theColl = GENV_STORE.createCollection(docResolvedUriString);

                docRootNode = GENV_STORE.getDocument(docResolvedUriString);

                if (docRootNode == NULL) 
                {
                  docRootNode = getStaticContext(planState)->get_document_uri_resolver()->
                                resolve(docResolvedUriItem,
                                        getStaticContext(planState),
                                        false,
                                        false);
          
                  theColl->addNode(docRootNode, 1);
              }
                else
              {
                  store::CopyMode lCopyMode;
                  copyNode = docRootNode->copy(NULL, NULL, lCopyMode);
                  theColl->addNode(copyNode, 1);
              }
              }
            }
              catch (error::ZorbaError& e) 
              {
                ZORBA_ERROR_LOC_DESC(e.theErrorCode, loc, e.theDescription);
              }
            }
          }
        attributesIte->close();
        }
      }
    childrenIte->close();
    }

  STACK_END (state);
}


/*******************************************************************************
  declare function import-folder($uri as xs:anyURI) as none

  The function will scan the given folder and import the specified XML files.
  The URI may also have a number of query parameters, written in the form:
  "file:///path/folder?parameter=value&parameter=value&..."
 
  Supported parameters are:
  recurse   yes | no (default)    searches folders recursively for files.
  select    pattern               controls which files will be opened.
                                  Wildcards such as "*.xml" can be used.

  Error conditions:
  - If the folder specified by the $uri parameter does not exist, an error is
    raised (API0033_FILE_OR_FOLDER_DOES_NOT_EXIST - the file or folder does
    not exist).
  - If the folder or the any of the files selected by the parameters cannot
    be opened, an error is raised (API0034_FILE_OR_FOLDER_CANNOT_BE_OPENED -
    a file or folder cannot be opened)
********************************************************************************/
bool
ZorbaImportFolderIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t       itemURI;
  URI                 uri;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemURI, theChildren[0].getp(), planState))
    uri = URI(itemURI->getStringValue().getp());

  if( uri.get_scheme() != xqpString("file") && !uri.get_scheme().empty())
    ZORBA_ERROR_LOC_DESC (FOER0000,
                          loc,
                          "ZorbaImportFolderIterator implemented only for 'file' scheme.");

  STACK_END (state);
}



/*******************************************************************************
  declare function list-collections() as xs:anyURI*

  The function will return a sequence of URIs of all currently known collections.
********************************************************************************/
ZorbaListCollectionsState::~ZorbaListCollectionsState()
{
  if ( uriItState != NULL ) {
    uriItState->close();
    uriItState = NULL;
  }
}


void ZorbaListCollectionsState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
  uriItState = NULL;
}


void ZorbaListCollectionsState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  if ( uriItState != NULL ) {
    uriItState->close();
    uriItState = NULL;
  }
}


bool
ZorbaListCollectionsIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  ZorbaListCollectionsState * state;
  store::Item_t               uriItem;

  DEFAULT_STACK_INIT(ZorbaListCollectionsState, state, planState);

  for ((state->uriItState = GENV_STORE.listCollectionUris())->open ();
       state->uriItState->next(uriItem); ) 
  {
    result = uriItem;
    STACK_PUSH( true, state);
  }

  state->uriItState->close();

  STACK_END (state);
}


/*******************************************************************************
  declare sequential function
  create-collection($uri as xs:anyURI) as none

  declare sequential function
  create-collection($uri as xs:anyURI,$nodes as node()*) as none

  The first function will create a new, empty, collection. The second function
  will create a new collection and will add the given nodes to it.

  Error conditions:
  -  If the collection already exists, an error is raised
     (API0005_COLLECTION_ALREADY_EXISTS - collection already exists).
  - XQP0000_DYNAMIC_RUNTIME_ERROR if the argument is the empty sequence
********************************************************************************/
bool ZorbaCreateCollectionIterator::nextImpl(
    store::Item_t& result,
    PlanState& aPlanState) const
{
  store::Item_t             uriItem;
  store::Item_t             resolvedUriItem;
  xqpStringStore_t          resolvedUriString;

  store::Item_t             node;
  store::Item_t             copyNode;
  store::Collection_t       coll;
  std::auto_ptr<store::PUL> pul;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, aPlanState);

  // check argument
  if (!consumeNext(uriItem, theChildren[0].getp(), aPlanState)) 
  {
    ZORBA_ERROR_LOC_DESC(XQP0000_DYNAMIC_RUNTIME_ERROR, loc,
                         "The empty-sequence is not allowed as first argument to create-collection");
  }

  resolvedUriString = getStaticContext(aPlanState)->
                      resolve_relative_uri(uriItem->getStringValueP(),
                                           xqp_string()).getStore();

  GENV_ITEMFACTORY->createAnyURI(resolvedUriItem, resolvedUriString);

  // check if the collection already exists
  try
  {
    coll = getCollection(getStaticContext(aPlanState), resolvedUriString, loc);
  }
  catch (error::ZorbaError&)
  {
    // we come here if the collection does not exist already
  }

  if (coll != NULL)
  {
    ZORBA_ERROR_LOC_DESC(API0005_COLLECTION_ALREADY_EXISTS, loc,
                         "The collection already exists.");
  }

  // create the pul and add the primitive
  pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

  pul->addCreateCollection(getStaticContext(aPlanState), resolvedUriString);

  // also add some optional nodes to the collection
  if(theChildren.size() == 2) 
  {
    static_context* sctx;
    store::CopyMode lCopyMode;
    bool typePreserve;
    bool nsPreserve;
    bool nsInherit;
    
    sctx = getStaticContext(aPlanState);

    typePreserve = (sctx->construction_mode() == StaticContextConsts::cons_preserve ?
                    true : false);
    nsPreserve = (sctx->preserve_mode() == StaticContextConsts::preserve_ns ?
                  true : false);
    nsInherit = (sctx->inherit_mode() == StaticContextConsts::inherit_ns ?
                 true : false);

    lCopyMode.set(true, typePreserve, nsPreserve, nsInherit);

    while (consumeNext(node, theChildren[1].getp(), aPlanState))
    {
      copyNode = node->copy(NULL, NULL, lCopyMode);

      pul->addInsertIntoCollection(getStaticContext(aPlanState),
                                   resolvedUriItem,
                                   copyNode);
  }
  }

  result = pul.release();
  STACK_PUSH( result != NULL, state);

  STACK_END (state);
}


/*******************************************************************************
  declare sequential function delete-collection() as none

  declare sequential function delete-collection($uri as xs:string?) as none

  The function will delete the collection identified by the given URI.

  Error conditions:
  - If the collection URI is empty and the default collection
    is not defined in the dynamic context, FODC0002 is raised
  - If the collection does not exist, an error is raised.
    (API0006_COLLECTION_NOT_FOUND - collection does not exist).
********************************************************************************/
bool
ZorbaDeleteCollectionIterator::nextImpl(store::Item_t& result, PlanState& aPlanState) const
{
  PlanIteratorState         *state;
  store::Item_t             item;
  store::Collection_t       coll;
  std::auto_ptr<store::PUL> pul;
  bool                      setDefCollNull = false;

  DEFAULT_STACK_INIT(PlanIteratorState, state, aPlanState);

  if((theChildren.size()==0) ||
     ((theChildren.size()==1) &&
      !consumeNext(item, theChildren[0].getp(), aPlanState)))
  {
    item = aPlanState.theRuntimeCB->theDynamicContext->get_default_collection();
    if(NULL != item)
      setDefCollNull = true;
    else
      ZORBA_ERROR_LOC_DESC(FODC0002, loc, "Default collection undefined in the dynamic context.");
  }

  coll = getCollection(getStaticContext(aPlanState), item->getStringValueP(), loc);

  pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

  item = coll->getUri();
  pul->addDeleteCollection(getStaticContext(aPlanState), item);

  if(setDefCollNull)
    aPlanState.theRuntimeCB->theDynamicContext->set_default_collection(NULL);

  result = pul.release();
  STACK_PUSH( result != NULL, state);

  STACK_END (state);
}


/*******************************************************************************
  declare sequential function delete-all-collections() as none

  The function will delete all existing collections.
********************************************************************************/
bool ZorbaDeleteAllCollectionsIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Iterator_t             uriItState;
  store::Item_t                 uriItem;
  std::auto_ptr<store::PUL>     pul;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

  for ((uriItState = GENV_STORE.listCollectionUris())->open ();
        uriItState->next(uriItem);) 
  {
    pul->addDeleteCollection(getStaticContext(planState), uriItem);
  }

  uriItState->close();

  result = pul.release();
  STACK_PUSH( result != NULL, state);

  STACK_END (state);
}


/*******************************************************************************
  declare sequential function
  insert-nodes-first($newnode as node()*) as none

  declare sequential function
  insert-nodes-first($uri as xs:string?, $newnode as node()*) as none

  The function will insert the given node(s) as the first node(s) of the given
  collection. If multiple nodes are inserted, the nodes remain adjacent and
  their order preserves the node ordering of the source expression.

  Error conditions:
  - If the collection URI is empty and the default collection
    is not defined in the dynamic context, FODC0002 is raised
  - If the specified collection does not exist, an error is raised
    (API0006_COLLECTION_NOT_FOUND - collection does not exist).
********************************************************************************/
bool
ZorbaInsertNodeFirstIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Collection_t        coll;
  store::Item_t              uriItem;
  store::Item_t              node;
  store::Item_t              copyNode;
  std::vector<store::Item_t> nodes;
  std::auto_ptr<store::PUL>  pul;

  static_context* sctx;
  store::CopyMode lCopyMode;
  bool typePreserve;
  bool nsPreserve;
  bool nsInherit;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  sctx = getStaticContext(planState);

  typePreserve = (sctx->construction_mode() == StaticContextConsts::cons_preserve ?
                  true : false);
  nsPreserve = (sctx->preserve_mode() == StaticContextConsts::preserve_ns ?
                true : false);
  nsInherit = (sctx->inherit_mode() == StaticContextConsts::inherit_ns ?
               true : false);

  lCopyMode.set(true, typePreserve, nsPreserve, nsInherit);

  if(theChildren.size() == 1 ||
     (theChildren.size() == 2 &&
      !consumeNext(uriItem, theChildren[0].getp(), planState)))
  {
    uriItem = planState.theRuntimeCB->theDynamicContext->get_default_collection();
    if(NULL == uriItem)
      ZORBA_ERROR_LOC_DESC(FODC0002, loc,
      "Default collection undefined in the dynamic context.");
  }

  coll = getCollection(getStaticContext(planState), uriItem->getStringValueP(), loc);
  uriItem = coll->getUri();

  while (consumeNext(node, theChildren[theChildren.size()-1].getp(), planState))
  {
    copyNode = node->copy(NULL, NULL, lCopyMode);
    nodes.push_back(copyNode);
  }

  // create the pul and add the primitive
  pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

  pul->addInsertFirstIntoCollection(getStaticContext(planState), uriItem, nodes);

  // this should not be necessary. we reset everything in the sequential iterator
  theChildren[theChildren.size()-1]->reset(planState);

  result = pul.release();
  STACK_PUSH( result != NULL, state);

  STACK_END (state);
}


/*******************************************************************************
  declare sequential function
  insert-nodes-last($newnode  as node()*) as none

  declare sequential function
  insert-nodes-last($uri as xs:string?, $newnode as node()*) as none

  The function will insert the given node(s) as the last node(s) of the given
  collection. If multiple nodes are inserted, the nodes remain adjacent and 
  their order preserves the node ordering of the source expression.

  Error conditions:
  - If the collection URI is empty and the default collection
    is not defined in the dynamic context, FODC0002 is raised
  - If the specified collection does not exist, an error is raised
    (API0006_COLLECTION_NOT_FOUND - collection does not exist).
  - If the node is already in the collection, an error is raised
    (API0031_NODE_ALREADY_IN_COLLECTION) 
********************************************************************************/
bool
ZorbaInsertNodeLastIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Collection_t       coll;
  store::Item_t              uriItem;
  store::Item_t              node;
  store::Item_t              copyNode;
  std::vector<store::Item_t> nodes;
  std::auto_ptr<store::PUL>  pul;

  static_context* sctx;
  store::CopyMode lCopyMode;
  bool typePreserve;
  bool nsPreserve;
  bool nsInherit;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  sctx = getStaticContext(planState);

  typePreserve = (sctx->construction_mode() == StaticContextConsts::cons_preserve ?
                  true : false);
  nsPreserve = (sctx->preserve_mode() == StaticContextConsts::preserve_ns ?
                true : false);
  nsInherit = (sctx->inherit_mode() == StaticContextConsts::inherit_ns ?
               true : false);

  lCopyMode.set(true, typePreserve, nsPreserve, nsInherit);

  if(theChildren.size() == 1 ||
     (theChildren.size() == 2 &&
      !consumeNext(uriItem, theChildren[0].getp(), planState)))
  {
    uriItem = planState.theRuntimeCB->theDynamicContext->get_default_collection();
    if(NULL == uriItem)
      ZORBA_ERROR_LOC_DESC(FODC0002, loc,
      "Default collection undefined in the dynamic context.");
  }

  coll = getCollection(getStaticContext(planState), uriItem->getStringValueP(), loc);
  uriItem = coll->getUri();

  while (consumeNext(node, theChildren[theChildren.size()-1].getp(), planState))
  {
    copyNode = node->copy(NULL, NULL, lCopyMode);
    nodes.push_back(copyNode);
  }

  // create the pul and add the primitive
  pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

  pul->addInsertLastIntoCollection(getStaticContext(planState), uriItem, nodes);

  // this should not be necessary. we reset everything in the sequential iterator
  theChildren[theChildren.size()-1]->reset(planState);

  result = pul.release();
  STACK_PUSH( result != NULL, state);

  STACK_END (state);
}


/*******************************************************************************
  declare sequential function
  insert-nodes-before($target as node()+, $newnode  as node()*) as none

  declare sequential function
  insert-nodes-before($uri as xs:string?,
                                                  $target   as node()+,
                                                  $newnode  as node()*) as none


  The inserted nodes become the preceding (or following) nodes of the target.
  The $target should be a non-updating expression (e.g. an XPath expression)
  identifying a node that is part of the given collection at the top-level.
  If the expression returns more than one node, the first one is used. If 
  multiple nodes are inserted by a single insert expression, the nodes remain
  adjacent and their order preserves the node ordering of the source expression.

  Error conditions:
  - If the collection URI is empty and the default collection
    is not defined in the dynamic context, FODC0002 is raised
  - If the specified collection does not exist, an error is raised
    (API0006_COLLECTION_NOT_FOUND - collection does not exist).
  - If the target node is not part of the collection, an error is raised
    (API0029_NODE_DOES_NOT_BELONG_TO_COLLECTION - the node does not belong
    to the given collection).
  - If any of the new nodes is already part of the collection an error is
    raised (API0031_NODE_ALREADY_IN_COLLECTION).
********************************************************************************/
bool
ZorbaInsertNodeBeforeIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Collection_t        coll;
  store::Item_t              itemUri;
  store::Item_t              targetNode, tmpItem;
  store::Item_t              node;
  store::Item_t              copyNode;
  std::vector<store::Item_t> nodes;
  std::auto_ptr<store::PUL>  pul;

  static_context* sctx;
  store::CopyMode lCopyMode;
  bool typePreserve;
  bool nsPreserve;
  bool nsInherit;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  sctx = getStaticContext(planState);

  typePreserve = (sctx->construction_mode() == StaticContextConsts::cons_preserve ?
                  true : false);
  nsPreserve = (sctx->preserve_mode() == StaticContextConsts::preserve_ns ?
                true : false);
  nsInherit = (sctx->inherit_mode() == StaticContextConsts::inherit_ns ?
               true : false);

  lCopyMode.set(true, typePreserve, nsPreserve, nsInherit);

  if(theChildren.size() == 2 ||
     (theChildren.size()==3 &&
      !consumeNext(itemUri, theChildren[0].getp(), planState)))
  {
    itemUri = planState.theRuntimeCB->theDynamicContext->get_default_collection();
    if(NULL == itemUri)
      ZORBA_ERROR_LOC_DESC(FODC0002, loc,
      "Default collection undefined in the dynamic context.");
  }

  coll = getCollection(getStaticContext(planState), itemUri->getStringValueP(), loc);
  itemUri = coll->getUri();

  if(!consumeNext(targetNode, theChildren[theChildren.size()-2].getp(), planState)) 
  {
    ZORBA_ERROR_LOC_DESC(XQP0000_DYNAMIC_RUNTIME_ERROR, loc,
                         "The empty-sequence is not allowed as second argument to insert-nodes-before");
  }

  if(consumeNext(tmpItem, theChildren[theChildren.size()-2].getp(), planState)) 
  {
    ZORBA_ERROR_LOC_DESC(XQP0000_DYNAMIC_RUNTIME_ERROR, loc,
                         "A sequence with more then one item is not allowed as second argument to insert-nodes-before");
  }


  if (coll->indexOf(targetNode.getp()) == -1) 
  {
    ZORBA_ERROR_LOC_DESC_OSS(XQP0000_DYNAMIC_RUNTIME_ERROR, loc,
                         "The target node passed as second parameter to insert-nodes-before does not exist in the given collection "
                         << coll->getUri()->getStringValue());
  }

  while (consumeNext(node, theChildren[theChildren.size()-1].getp(), planState))
  {
    copyNode = node->copy(NULL, NULL, lCopyMode);
    nodes.push_back(copyNode);
  }

  // create the pul and add the primitive
  pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

  pul->addInsertBeforeIntoCollection(getStaticContext(planState),
                                     itemUri,
                                     targetNode,
                                     nodes);

  // this should not be necessary. we reset everything in the sequential iterator
  theChildren[theChildren.size()-2]->reset(planState);
  theChildren[theChildren.size()-1]->reset(planState);

  result = pul.release();
  STACK_PUSH( result != NULL, state);

  STACK_END (state);
}


/*******************************************************************************
  declare sequential function insert-nodes-after( $target   as node()+,
                                                  $newnode  as node()*) as none

  declare sequential function insert-nodes-after( $uri      as xs:string?,
                                                  $target   as node()+,
                                                  $newnode  as node()*) as none

  The inserted nodes become the following nodes of the $target.
  The $target should be a non-updating expression (e.g. an XPath expression)
  identifying a node that is part of the given collection at the top-level.
  If the expression returns more than one node, the first one is used.
  A predicate can be used to select a different node in this case.
  If multiple nodes are inserted by a single insert expression,
  the nodes remain adjacent and their order preserves the node ordering of
  the source expression.

Error conditions:
  - If the collection URI is empty and the default collection
    is not defined in the dynamic context, FODC0002 is raised
********************************************************************************/
bool
ZorbaInsertNodeAfterIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Collection_t       coll;
  store::Item_t              itemUri;
  store::Item_t              targetNode;
  store::Item_t              tmpItem;
  store::Item_t              node;
  store::Item_t              copyNode;
  std::vector<store::Item_t> nodes;
  std::auto_ptr<store::PUL>  pul;

  static_context* sctx;
  store::CopyMode lCopyMode;
  bool typePreserve;
  bool nsPreserve;
  bool nsInherit;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  sctx = getStaticContext(planState);

  typePreserve = (sctx->construction_mode() == StaticContextConsts::cons_preserve ?
                  true : false);
  nsPreserve = (sctx->preserve_mode() == StaticContextConsts::preserve_ns ?
                true : false);
  nsInherit = (sctx->inherit_mode() == StaticContextConsts::inherit_ns ?
               true : false);

  lCopyMode.set(true, typePreserve, nsPreserve, nsInherit);

  if(theChildren.size() == 2 ||
     (theChildren.size() == 3 &&
      !consumeNext(itemUri, theChildren[0].getp(), planState)))
  {
    itemUri = planState.theRuntimeCB->theDynamicContext->get_default_collection();
    if(NULL == itemUri)
      ZORBA_ERROR_LOC_DESC(FODC0002, loc,
      "Default collection undefined in the dynamic context.");
  }

  coll = getCollection(getStaticContext(planState), itemUri->getStringValueP(), loc);
  itemUri = coll->getUri();

  if(!consumeNext(targetNode, theChildren[theChildren.size()-2].getp(), planState)) 
  {
    ZORBA_ERROR_LOC_DESC(XQP0000_DYNAMIC_RUNTIME_ERROR, loc, 
                         "The empty-sequence is not allowed as second argument to insert-nodes-after");
  }

  if(consumeNext(tmpItem, theChildren[theChildren.size()-2].getp(), planState)) 
  {
    ZORBA_ERROR_LOC_DESC(XQP0000_DYNAMIC_RUNTIME_ERROR, loc, 
                         "A sequence with more then one item is not allowed as second argument to insert-nodes-after");
  }

  if (coll->indexOf(targetNode.getp()) == -1) 
  {
    ZORBA_ERROR_LOC_DESC_OSS(XQP0000_DYNAMIC_RUNTIME_ERROR, loc, 
                         "The target node passed as second parameter to insert-nodes-before does not exist in the given collection "
                         << coll->getUri()->getStringValue());
  }

  // create the pul and add the primitive
  pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

  while (consumeNext(node, theChildren[theChildren.size()-1].getp(), planState))
  {
    copyNode = node->copy(NULL, NULL, lCopyMode);
    nodes.push_back(copyNode);
  }

  pul->addInsertAfterIntoCollection(getStaticContext(planState),
                                    itemUri,
                                    targetNode,
                                    nodes);

  // this should not be necessary. we reset everything in the sequential iterator
  theChildren[theChildren.size()-2]->reset(planState);
  theChildren[theChildren.size()-1]->reset(planState);

  result = pul.release();
  STACK_PUSH( result != NULL, state);

  STACK_END (state);
}


/*******************************************************************************
  declare sequential function
  insert-nodes-at($position as xs:integer, $newnode as node()*) as none

  declare sequential function
  insert-nodes-at($uri as xs:string?,
                                              $position as xs:integer,
                                              $newnode  as node()*) as none

  Inserts the node(s) into the given collection, at the specified position.
  If $position is negative, the node(s) will be inserted at the beginning of
  the collection. If $position is greater or equal to the number of nodes in
  the collection, the node(s) will be inserted as the last node(s) of the
  collection.

  Error conditions:
  - If the collection URI is empty and the default collection
    is not defined in the dynamic context, FODC0002 is raised
  - If the specified collection does not exist, an error is raised
    (API0006_COLLECTION_NOT_FOUND - collection does not exist).
  - If the node is already part of the collection an error is raised
    (API0031_NODE_ALREADY_IN_COLLECTION).
********************************************************************************/
bool
ZorbaInsertNodeAtIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Collection_t        coll;
  store::Item_t              itemUri, itemPos, tmpItem;
  store::Item_t              node;
  store::Item_t              copyNode;
  std::vector<store::Item_t> nodes;
  std::auto_ptr<store::PUL>  pul;
  xqp_uint                   pos;

  static_context* sctx;
  store::CopyMode lCopyMode;
  bool typePreserve;
  bool nsPreserve;
  bool nsInherit;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  sctx = getStaticContext(planState);

  typePreserve = (sctx->construction_mode() == StaticContextConsts::cons_preserve ?
                  true : false);
  nsPreserve = (sctx->preserve_mode() == StaticContextConsts::preserve_ns ?
                true : false);
  nsInherit = (sctx->inherit_mode() == StaticContextConsts::inherit_ns ?
               true : false);

  lCopyMode.set(true, typePreserve, nsPreserve, nsInherit);

  if(theChildren.size() == 2 ||
     (theChildren.size() == 3 &&
      !consumeNext(itemUri, theChildren[0].getp(), planState)))
  {
    itemUri = planState.theRuntimeCB->theDynamicContext->get_default_collection();
    if(NULL == itemUri)
      ZORBA_ERROR_LOC_DESC(FODC0002, loc,
      "Default collection undefined in the dynamic context.");
  }

  coll = getCollection(getStaticContext(planState), itemUri->getStringValueP(), loc);
  itemUri = coll->getUri();

  if(!consumeNext(itemPos, theChildren[theChildren.size()-2].getp(), planState)) 
  {
    ZORBA_ERROR_LOC_DESC(XQP0000_DYNAMIC_RUNTIME_ERROR, loc, 
                         "The empty-sequence is not allowed as second argument to insert-nodes-at");
  }

  if(consumeNext(tmpItem, theChildren[theChildren.size()-2].getp(), planState)) 
  {
    ZORBA_ERROR_LOC_DESC(XQP0000_DYNAMIC_RUNTIME_ERROR, loc, 
                         "A sequence with more then one item is not allowed as second argument to insert-nodes-at");
  }

  if(itemPos->getIntegerValue() < Integer::zero())
  {
    ZORBA_ERROR_LOC_DESC_OSS(XQP0000_DYNAMIC_RUNTIME_ERROR, loc, 
                             "The target position passed as second argument to insert-nodes-at (" 
                              << itemPos->getStringValue() << ") must be positive");
  }

  NumConversions::strToUInt(itemPos->getIntegerValue().toString(), pos);

  // create the pul and add the primitive
  pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

  while (consumeNext(node, theChildren[theChildren.size()-1].getp(), planState))
  {
    copyNode = node->copy(NULL, NULL, lCopyMode);
    nodes.push_back(copyNode);
  }

  pul->addInsertAtIntoCollection(getStaticContext(planState),
                                 itemUri,
                                 pos,
                                 nodes);

  // this should not be necessary. we reset everything in the sequential iterator
  theChildren[theChildren.size()-2]->reset(planState);
  theChildren[theChildren.size()-1]->reset(planState);

  result = pul.release();
  STACK_PUSH( result != NULL, state);

  STACK_END (state);
}


/*******************************************************************************
  declare sequential function remove-nodes($target  as node()+) as none

  declare sequential function remove-nodes($uri     as xs:string?,
                                           $target  as node()+) as none

  The function will remove the node(s) identified by the $target expression
  from the given collection. The nodes themselves will not be deleted and
  they may remain as parts of other collections. If the expression identifies
  more than one node, all of them will be removed from the collection. 

  Error conditions:
  - If the collection URI is empty and the default collection
    is not defined in the dynamic context, FODC0002 is raised
  - If the specified collection does not exist, an error is raised
    (API0006_COLLECTION_NOT_FOUND - collection does not exist).
  - If the given expression points to a node that is not part of the collection,
    an error is raised (API0029_NODE_DOES_NOT_BELONG_TO_COLLECTION - the node
    does not belong to the given collection). 
********************************************************************************/
bool
ZorbaRemoveNodeIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Collection_t                     coll;
  store::Item_t               uriItem;
  store::Item_t               node;
  std::vector<store::Item_t>              nodes;
  std::auto_ptr<store::PUL>               pul;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if(theChildren.size() == 1 ||
     (theChildren.size() == 2 &&
      !consumeNext(uriItem, theChildren[0].getp(), planState)))
  {
    uriItem = planState.theRuntimeCB->theDynamicContext->get_default_collection();
    if(NULL == uriItem)
      ZORBA_ERROR_LOC_DESC(FODC0002, loc,
      "Default collection undefined in the dynamic context.");
  }

  coll = getCollection(getStaticContext(planState), uriItem->getStringValueP(), loc);
  uriItem = coll->getUri();

  while (consumeNext(node, theChildren[theChildren.size()-1].getp(), planState)) 
  {
    if (coll->indexOf(node.getp()) == -1)
      ZORBA_ERROR_LOC_DESC_OSS(API0029_NODE_DOES_NOT_BELONG_TO_COLLECTION, loc, 
                           "The node passed as second parameter to remove-nodes does not exist in the given collection "
                           << coll->getUri()->getStringValue());

    nodes.push_back(node);
  }

  // create the pul and add the primitive
  pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

  pul->addRemoveFromCollection(getStaticContext(planState), uriItem, nodes);

  // this should not be necessary. we reset everything in the sequential iterator
  theChildren[theChildren.size()-1]->reset(planState);

  result = pul.release();
  STACK_PUSH( result != NULL, state);

  STACK_END (state);
}


/*******************************************************************************
  declare sequential function
  remove-node-at($position as xs:integer) as none

  declare sequential function
  remove-node-at($uri as xs:string?, $position as xs:integer) as none

  The function will remove from the given collection the node positioned at
  $position.

  Error conditions:
  - If the collection URI is empty and the default collection
    is not defined in the dynamic context, FODC0002 is raised
  - If the specified collection does not exist, an error is raised 
    (API0006_COLLECTION_NOT_FOUND - collection does not exist).
  - If the collection has fewer nodes than $position + 1, nothing is removed
    and an error is raised (API0030_NO_NODE_AT_GIVEN_POSITION - there is no
    node at the given position, the collection has fewer nodes). 
********************************************************************************/
bool ZorbaRemoveNodeAtIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Collection_t        coll;
  store::Item_t              uriItem;
  store::Item_t              posItem;
  store::Item_t              tmpItem;
  uint32_t                   lpos;
  std::auto_ptr<store::PUL>  pul;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if(theChildren.size() == 1 ||
     (theChildren.size() == 2 &&
      !consumeNext(uriItem, theChildren[0].getp(), planState)))
  {
    uriItem = planState.theRuntimeCB->theDynamicContext->get_default_collection();
    if(NULL == uriItem)
      ZORBA_ERROR_LOC_DESC(FODC0002, loc,
      "Default collection undefined in the dynamic context.");
  }

  coll = getCollection(getStaticContext(planState), uriItem->getStringValueP(), loc);
  uriItem = coll->getUri();

  if(!consumeNext(posItem, theChildren[theChildren.size()-1].getp(), planState)) 
  {
    ZORBA_ERROR_LOC_DESC(XQP0000_DYNAMIC_RUNTIME_ERROR, loc, 
                         "The empty-sequence is not allowed as second argument to remove-node-at");
  }

  if(consumeNext(tmpItem, theChildren[theChildren.size()-1].getp(), planState)) 
  {
    ZORBA_ERROR_LOC_DESC(XQP0000_DYNAMIC_RUNTIME_ERROR, loc, 
                         "A sequence with more then one item is not allowed as second argument to remove-node-at");
  }

  if(posItem->getIntegerValue() < Integer::zero())
  {
    ZORBA_ERROR_LOC_DESC(XQP0000_DYNAMIC_RUNTIME_ERROR, loc, 
                         "An negative integer is not allowed as as second argument to remove-node-at");
  }

  NumConversions::strToUInt(posItem->getIntegerValue().toString(),lpos);

  if (coll->size() < lpos)
  {
    ZORBA_ERROR_LOC_DESC(API0030_NO_NODE_AT_GIVEN_POSITION, loc, 
                         "The size of the collection is smaller then the parameter passed as second argument to remove-node-at");
  }

  // create the pul and add the primitive
  pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

  pul->addRemoveAtFromCollection(getStaticContext(planState), uriItem, lpos);

  // this should not be necessary. we reset everything in the sequential iterator
  theChildren[theChildren.size()-1]->reset(planState);

  result = pul.release();
  STACK_PUSH( result != NULL, state);

  STACK_END (state);
}


/*******************************************************************************
  declare sequential function nodes-count() as xs:integer?

  declare sequential function nodes-count(xs:string?) as xs:integer?

  The function returns the number of nodes in the given collection.

  Error conditions:
  - If the collection URI is empty and the default collection
    is not defined in the dynamic context, FODC0002 is raised
  - If the specified collection does not exist, an error is raised
    (API0006_COLLECTION_NOT_FOUND - collection does not exist).
********************************************************************************/
bool
ZorbaNodeCountIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Collection_t theColl;
  store::Item_t       itemUri;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if((theChildren.size()==0) ||
      ((theChildren.size()==1) &&
      !consumeNext(itemUri, theChildren[0].getp(), planState)))
  {
    itemUri = planState.theRuntimeCB->theDynamicContext->get_default_collection();
    if(NULL == itemUri)
      ZORBA_ERROR_LOC_DESC(FODC0002, loc, "Default collection undefined in the dynamic context.");
  }

  theColl = getCollection(getStaticContext(planState), itemUri->getStringValue(), loc);

  STACK_PUSH(GENV_ITEMFACTORY->createInteger(
            result,
            Integer::parseInt(theColl.getp()->size())), state);

  STACK_END (state);
}


/*******************************************************************************
  declare sequential function node-at($position as xs:integer) as node()?

  declare sequential function node-at($uri      as xs:string?,
                                      $position as xs:integer) as node()?

  The function will return the node positioned at $position in the given collection.

  Error conditions:
  - If the collection URI is empty and the default collection
    is not defined in the dynamic context, FODC0002 is raised
  - If the specified collection does not exist, an error is raised
    (API0006_COLLECTION_NOT_FOUND - collection does not exist).
  - If the collection has fewer nodes than $position + 1 an error is raised
    (API0030_NO_NODE_AT_GIVEN_POSITION - there is no node at the given position,
    the collection has fewer nodes). 
********************************************************************************/
bool
ZorbaNodeAtIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Collection_t theColl;
  store::Item_t       item;
  uint32_t            lpos;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if((theChildren.size()==1) ||
      ((theChildren.size()==2) &&
      !consumeNext(item, theChildren[0].getp(), planState)))
  {
    item = planState.theRuntimeCB->theDynamicContext->get_default_collection();
    if(NULL == item)
      ZORBA_ERROR_LOC_DESC(FODC0002, loc, "Default collection undefined in the dynamic context.");
  }

  theColl = getCollection(getStaticContext(planState), item->getStringValue(), loc);

  if (consumeNext(item, theChildren[theChildren.size()-1].getp(), planState))
  {
    if(item->getIntegerValue() >= Integer::zero())
    {
      NumConversions::strToUInt(item->getIntegerValue().toString(),lpos);
      result = theColl->nodeAt(lpos);
      STACK_PUSH(true, state);
    }
  }

  STACK_END (state);
}


/*******************************************************************************
  declare function index-of($target as node()) as xs:integer

  declare function index-of($uri as xs:string?,
                            $target as node()) as xs:integer

  The function will return the index of the  $target node within the collection
  identified by $uri.

  Error condition:
  - If the collection URI is empty and the default collection
    is not defined in the dynamic context, FODC0002 is raised
  - If the specified collection does not exist, an error is raised
    (API0006_COLLECTION_NOT_FOUND - collection does not exist).
  - If the node does not belong to the given collection, an error is raised
    (API0029_NODE_DOES_NOT_BELONG_TO_COLLECTION - the node does not belong
    to the given collection).
********************************************************************************/
bool
ZorbaIndexOfIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Collection_t theColl;
  store::Item_t       item;
  int                 pos = 1;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if((theChildren.size()==1) ||
      ((theChildren.size()==2) &&
      !consumeNext(item, theChildren[0].getp(), planState)))
  {
    item = planState.theRuntimeCB->theDynamicContext->get_default_collection();
    if(NULL == item)
      ZORBA_ERROR_LOC_DESC(FODC0002, loc, "Default collection undefined in the dynamic context.");
  }

  theColl = getCollection(getStaticContext(planState), item->getStringValue(), loc);

  if (consumeNext(item, theChildren[theChildren.size()-1].getp(), planState))
  {
    pos = theColl->indexOf(item);

    if( -1 == pos)
      ZORBA_ERROR_LOC_DESC (API0029_NODE_DOES_NOT_BELONG_TO_COLLECTION,
                            loc,
                            "The node does not belong to collection.");

    STACK_PUSH(GENV_ITEMFACTORY->createInteger(
              result,
              Integer::parseInt(pos)), state);
  }

  STACK_END (state);
}


/*******************************************************************************
  declare updating function
  export-xml($uri as xs:string) as none

  declare updating function
  export-xml($uri as xs:string, $targeturi as xs:string) as none

  Saves the given collection to the target URI as an XML file. Intended
  supported targets (protocols) are: "file:///path/file.xml" : (e.g.
  "file://c:/path/folder/file.xml") - saves the collection to a file, in the
  serialized form. "http://www.example.com/path/file.xml" - saves the
  collection to a remote location, via the HTTP PUT request (to be implemented
  by the REST library).

  If the protocol is omitted in the URI, "file://" is assumed.

  The first function will use the collection's URI (the $uri parameter) as the
  target URI.

  The collection will be exported only if it can be serialized correctly - i.e.
  it is a well-formed XML document. In all other cases an error will be returned
  (API0035_COLLECTION_CANNOT_BE_SERIALIZED - the collection cannot be serialized).

********************************************************************************/
bool ZorbaExportXmlIterator::nextImpl(
    store::Item_t& result, 
    PlanState& planState) const
{
  store::Collection_t coll;
  store::Item_t       uriItem;
  store::Item_t       targetUriItem;
  URI                 targetURI;
  store::Item_t       node;
  store::Iterator_t   collIterator;
  std::ostringstream  ss;
  std::ostream*       lOutputStream;
  std::auto_ptr<std::ostream> lFileStream;

  error::ErrorManager lErrorManager;
  serializer          ser(&lErrorManager);
  ser.set_parameter("omit-xml-declaration", "yes");

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if(!consumeNext(uriItem, theChildren[0].getp(), planState))
    ZORBA_ASSERT(false);

  coll = getCollection(getStaticContext(planState), uriItem->getStringValue(), loc);

  if(theChildren.size() == 2)
  {
    if (!consumeNext(targetUriItem, theChildren[1].getp(), planState))
      ZORBA_ASSERT(false);

    targetURI = URI(targetUriItem->getStringValue().getp());
    }
    else
    {
    targetURI = URI(coll->getUri()->getStringValue()->c_str());
    }

  if(targetURI.get_scheme() != xqpString("file") && !targetURI.get_scheme().empty())
    {
    ZORBA_ERROR_LOC_DESC(FOER0000, loc,
                            "ZorbaExportXmlIterator implemented only for 'file' scheme.");
    }

  lFileStream.reset(new std::ofstream(targetURI.get_path().c_str()));
  lOutputStream = lFileStream.get();
    if ( !lOutputStream->good() )
  {
    ZORBA_ERROR_LOC_DESC_OSS(API0033_FILE_OR_FOLDER_DOES_NOT_EXIST, loc,
    "File or folder does not exist: " << targetURI.get_path().c_str());
  }

  collIterator = coll->getIterator(true);

    collIterator->open();

  while (collIterator->next(node))
    ser.serialize(node, ss);
  
    collIterator->close();

    *lOutputStream << ss.str() << std::endl;

  STACK_END (state);
}


store::Collection_t getCollection(
    static_context* sctx,
    const xqpStringStore_t strURI,
    const QueryLoc& loc)
{
  store::Item_t       resolvedURIItem;
  xqpStringStore_t    resolvedURIString;

  try 
  {
    resolvedURIString = sctx->resolve_relative_uri(strURI.getp(),
                                             xqp_string()).getStore();

    GENV_ITEMFACTORY->createAnyURI(resolvedURIItem, resolvedURIString);
  }
  catch (error::ZorbaError& e) 
  {
    ZORBA_ERROR_LOC_PARAM(API0006_COLLECTION_NOT_FOUND, loc, strURI, e.theDescription);
  }

  store::Collection_t lCollection = sctx->get_collection_uri_resolver()->
                                    resolve(resolvedURIItem, sctx);
  if (lCollection == NULL) 
  {
    ZORBA_ERROR_LOC_PARAM(API0006_COLLECTION_NOT_FOUND, loc, strURI,
                          "The requested collection could not be found.");
  }

  return lCollection;
}


} /* namespace zorba */
