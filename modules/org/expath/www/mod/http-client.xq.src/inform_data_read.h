#ifndef INFORM_DATA_READ_H
#define INFORM_DATA_READ_H
namespace zorba { namespace http_client {
  class InformDataRead {
  public:
    virtual ~InformDataRead();
  public:
    virtual void beforeRead() = 0;
    virtual void afterRead() = 0;
  };
}} //namespace zorba, http_client
#endif //INFORM_DATA_READ_H
