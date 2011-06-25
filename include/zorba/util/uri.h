#ifndef URI_H
#define URI_H

#include <zorba/config.h>
#include <zorba/api_shared_types.h>

namespace zorba {

/**
  * @brief A helper class to do uri conversions
  *
  */
class ZORBA_DLL_PUBLIC URIHelper
{
public:
  /**
    * @brief Decodes a file:// URI to a filesystem path in native form.
    *
    * @arg uri A file:// URI.
    * @returns The filesystem path.
    */
  static String decodeFileURI(const String& uri);
  /**
    * @brief Encodes a native filesystem path to a file:// URI.
    *
    * @arg filepath The filesystem path.
    * @returns The encoded URI of the file.
    */
  static String encodeFileURI(const String& filepath);
};

} //namespace zorba

#endif // URI_H
/* vim:set et sw=2 ts=2: */
