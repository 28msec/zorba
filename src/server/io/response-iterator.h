#ifndef ZORBA_SERVER_IO_RESPONSE_ITERATOR_H_
#define ZORBA_SERVER_IO_RESPONSE_ITERATOR_H_

#include <string>

#include "zorba/item.h"
#include "zorba/iterator.h"

namespace zorba
{
namespace server
{
namespace io
{
  class ResponseIterator : public zorba::Iterator
  {
  public:
    ResponseIterator(zorba::XQuery_t aQuery);
    ResponseIterator(zorba::Iterator_t aIterator);

    bool isEmpty();
    bool isBinary();
    const std::string& getContentType();

    /*
     * Iterator functions
     */
    void open();
    bool next(Item& aItem);
    void close();
    bool isOpen() const;
    virtual int64_t count();
    bool skip(int64_t count);

  private:
    void initialize();

    bool theIsOpen;
    zorba::Iterator_t theWrappedIterator;

    bool theIsInitialized;
    zorba::Item theItem;
    bool theIsEmpty;
    bool theIsBinary;
    std::string theContentType;
  };
}
}
}

#endif

