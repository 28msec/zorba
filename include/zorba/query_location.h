#ifndef QUERYLOCATION_H
#define QUERYLOCATION_H

#include <zorba/config.h>
#include <zorba/smart_ptr.h>
#include <zorba/api_shared_types.h>

namespace zorba{

  /**
   * Representation of the current location location
   * in the remote query.
   * This location goes from the starting line and column
   * to the ending line and column.
   */
  class ZORBA_DLL_PUBLIC QueryLocation: public SmartObject
  {
    public:

      virtual
      ~QueryLocation(){}

      virtual String
      getFileName() const = 0;

      virtual unsigned int
      getLineBegin() const = 0;

      virtual unsigned int
      getLineEnd() const = 0;

      virtual unsigned int
      getColumnBegin() const = 0;

      virtual unsigned int
      getColumnEnd() const = 0;

      virtual String
      toString() const = 0;
  };

} // namespace zorba

#endif // QUERYLOCATION_H
