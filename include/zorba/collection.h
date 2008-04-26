#ifndef ZORBA_COLLECTION_API_H
#define ZORBA_COLLECTION_API_H

#include <zorba/api_shared_types.h>
#include <zorba/item.h>

namespace zorba {

/** \brief A Collection is a sequence of Node Items.
 *
 * Each Collection is created by the XmlDataManager and referenced by a URI.
 * The URI can be accessed in a query's fn:collection function.
 */
class Collection
{
  public:
    /** \brief Destructor
     */
    virtual ~Collection() {}

    /** \brief Get the URI of a collection as an anyURI Item.
     *
     * @return Item the anyURI Item of the Collection.
     */
    virtual Item
    getUri() = 0;

    /** \brief Adds a Node Item to the Collection
     *
     * @param Item the Node Item to add.
     * @return true if the Node Item was added to the Collection, false otherwise.
     */
    virtual bool
    addItem(const Item& aItem) = 0;

    /** \brief Deletes the given Item from the Collection.
     *
     * @param Item the Node Item to delete
     * @return true if the given Node Item was deleted, false otherwise.
     */
    virtual bool
    deleteItem(const Item& aItem) = 0;

    /** \brief Adds the Node Items retrieved from the given ResultIterator to the Collection.
     *
     * @param ResultIterator the ResultIterator that produces the Node Items to add.
     * @return true if all the Node Items of the given ResultIterator were added to the Collection,
     *         false otherwise.
     */
    virtual bool
    addItems(const ResultIterator_t& aResultIterator) = 0;

    /** \brief Adds the document retrieved from the given input stream to the Collection.
     *
     * @param istream the input stream from which to parse the document.
     * @return true if the document was added to the collection (e.g. was a valid document), 
     *         false otherwise.
     */
    virtual bool
    addDocument(std::istream& lInStream) = 0;

}; /* class Collection */

} /* namespace zorba */

#endif
