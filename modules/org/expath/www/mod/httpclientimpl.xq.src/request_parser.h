#ifndef REQUEST_PARSER_H
#define REQUEST_PARSER_H

namespace zorba {
class Item;

namespace http_client {
class RequestHandler;

class RequestParser {
protected:
  RequestHandler* theHandler;

public:
  RequestParser(RequestHandler* aHandler) : theHandler(aHandler) {}
  bool parse(const Item& aItem);

private:
  bool parseItem(const Item& aItem);
  bool handleRequest(const Item& aItem);
  bool handleResponse(const Item aItem);
  bool handleHeader(const Item& aItem);
  bool handleBody(const Item& aItem);
  bool handleMultipart(const Item& aItem);
};
} //namespace zorba
} //namespace http_request

#endif // REQUEST_PARSER_H
