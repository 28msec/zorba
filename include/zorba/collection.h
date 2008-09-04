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
#ifndef ZORBA_COLLECTION_API_H
#define ZORBA_COLLECTION_API_H

#include <zorba/config.h>
#include <zorba/api_shared_types.h>
#include <zorba/item.h>

namespace zorba {

/** \brief A Collection is a sequence of Node Items.
 *
 * Each Collection is created by the XmlDataManager and referenced by a URI.
 * The URI can be accessed in a query's fn:collection function.
 *
 * Note: This class is reference counted. When writing multi-threaded clients,
 * it is the responibility of the client code to synchronize assignments to the
 * SmartPtr holding this object.
 */
class ZORBA_EXTERN_DECL Collection : public SmartObject
{
  public:
    /** \brief Destructor.
     */
    virtual ~Collection() {}

    /** \brief Get the URI of a collection as an anyURI Item.
     *
     * @return Item the anyURI Item of the Collection.
     */
    virtual Item
    getUri() = 0;

    /** \brief Returns the number of items in the collection.
     *
     * @return The number of items in the collection.
     */
    virtual unsigned long
    size() const = 0;

    /** \brief Adds a Node Item to the Collection.
     *
     * @param aNode the Node Item to add.
     * @param aPosition the position where the node will be inserted.
     * By default the data will be appended at the end.
     * @return true if the Node Item was added to the Collection, false otherwise.
     */
    virtual bool
    addNode(const Item& aNode, long aPosition = -1) = 0;

    /** \brief Adds a Node Item to the Collection after the targetNode.
     *
     * @param aNode the Node Item to add.
     * @param aTargetNode the aNode will be added before the aTargetNode.
     * @param sOrder if true the aNode will be inserted before the aTarget.
     * Otherwise aNode will be inserted after aTarget.
     * @return true if the Node Item was added to the Collection, false otherwise.
     */
    virtual bool
    addNode(const Item& aNode, const Item& aTargetNode, bool aOrder) = 0;

    /** \brief Deletes the given Item from the Collection.
     *
     * @param aNode the Node Item to delete
     * @return true if the given Node Item was deleted, false otherwise.
     */
    virtual bool
    deleteNode(const Item& aNode) = 0;

    /** \brief Deletes the Item at the given position from the Collection.
     *
     * @param aPosition the position of the Node that will be removed from collection.
     * By default the last Node will be removed from collection.
     * @return true if the given Node Item was deleted, false otherwise.
     */
    virtual bool
    deleteNode(long aPosition = -1) = 0;

    /** \brief Get the node at the given position in the collection as a Node Item.
     *
     * @param aPosition the position of the Node in the collection.
     * @return the Node Item at the given position.
     */
    virtual Item
    nodeAt(long aPosition) = 0;

    /** \brief Adds the Node Items retrieved from the given ResultIterator to the Collection.
     *
     * @param aResultIterator the ResultIterator that produces the Node Items to add.
     * @return true if all the Node Items of the given ResultIterator were added to the Collection,
     *         false otherwise.
     */
    virtual bool
    addNodes(const ResultIterator* aResultIterator) = 0;

    /** \brief Adds the document retrieved from the given input stream to the Collection.
     *
     * @param aInStream the input stream from which to parse the document.
     * @param aPosition the position where the node will be inserted.
     * By default the data will be appended at the end.
     * @return true if the document was added to the collection (e.g. was a valid document), 
     *         false otherwise.
     */
    virtual bool
    addDocument(std::istream& aInStream, long aPosition = -1) = 0;

}; /* class Collection */

} /* namespace zorba */

#endif
