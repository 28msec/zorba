#include <zorba/util/uri.h>
#include <zorba/zorbastring.h>

using namespace zorba;

int uri_file_decoding_test(int argc, char* argv[]) {
  String lTestString("file:////hello_world");
  String res = URIHelper::decodeFileURI(lTestString);
  if (res != "/hello_world")
    return 1;
  return 0;
}
