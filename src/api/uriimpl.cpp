#include <zorba/util/uri.h>
#include <zorba/zorbastring.h>

#include <zorbatypes/URI.h>
#include <zorbatypes/zstring.h>

#include <api/unmarshaller.h>

namespace zorba {

String URIHelper::decodeFileURI(const String& uri)
{
  zstring lURI = Unmarshaller::getInternalString(uri);
  zstring lFileURI;
  URI::decode_file_URI(lURI, lFileURI);
  return String(lFileURI.str());
}

String URIHelper::encodeFileURI(const String &fileUri)
{
  zstring lFileUri = Unmarshaller::getInternalString(fileUri);
  zstring lUri;
  URI::encode_file_URI(lFileUri, lUri);
  return String(lUri.str());
}

} //namespace zorba
