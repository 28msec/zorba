#include <zorba/util/uri.h>
#include <zorba/zorbastring.h>

#include <zorbatypes/URI.h>
#include <api/unmarshaller.h>

namespace zorba {

String URIHelper::decodeFileURI(const String& uri)
{
  xqpStringStore_t lURI = Unmarshaller::getInternalString(uri);
  xqpStringStore_t lFileURI;
  URI::decode_file_URI(lURI, lFileURI);
  return String(lFileURI.getp());
}

String URIHelper::encodeFileURI(const String &fileUri)
{
  xqpStringStore_t lFileUri = Unmarshaller::getInternalString(fileUri);
  xqpStringStore_t lUri;
  URI::encode_file_URI(lFileUri, lUri);
  return String(lUri.getp());
}

} //namespace zorba
