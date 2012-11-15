/*
 * Copyright 2006-2008 The FLWOR Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef ZORBA_ERROR_PRINTER_H
#define ZORBA_ERROR_PRINTER_H

#include <ostream>

namespace zorba {

class XQueryException;

class ZORBA_DLL_PUBLIC ErrorPrinter {

  public:

    /**
     * Generates an error message out of an XQuery exception.
     *
     * @param aException The exception.
     * @param aOut       Stream to which the error message is written to.
     * @param aAsXml     Error message in XML format?
     * @param aIndet     Error message indented?
     */
    static std::ostream&
    print(
      const XQueryException& aException,
      std::ostream&          aOut,
      bool                   aAsXml,
      bool                   aIndent);

}; /* class ErrorPrinter */

} /* namespace zorba */

#endif //ZORBA_ERROR_PRINTER_H
