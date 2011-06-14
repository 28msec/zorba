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
    * @brief Decodes a uri to a file uri.
    *
    * This function is useful if you need to decode a file uri from a given uri.
    *
    * @arg uri A uri of a file.
    * @returns The file uri of uri.
    */
  static String decodeFileURI(const String& uri);
  /**
    * @brief Encodes a file uri to a uri.
    *
    * This function encodes a given uri to a file uri.
    *
    * @arg fileUri The file uri of a file.
    * @returns The encoded uri of the file.
    */
  static String encodeFileURI(const String& fileUri);
};

} //namespace zorba

#endif // URI_H
/* vim:set et sw=2 ts=2: */
