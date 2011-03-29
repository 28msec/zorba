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

#ifndef ZORBA_ERROR_HANDLER_API_H
#define ZORBA_ERROR_HANDLER_API_H

#include <zorba/config.h>

namespace zorba {

class ZorbaException;

/** \brief ErrorHandler defines an interface. Classes that implement this interface
 *         can be used as callback classes.
 *
 * Specifically, they can be registered with an XQuery object. This way, all 
 * errors that would have been reported by throwing an exception are reported 
 * by calling the according function of this interface. Subclasses of the 
 * ZorbaException class that would have been thrown are passed as parameter
 * to the callback function.
 */
class ZORBA_DLL_PUBLIC ErrorHandler {
public:
  virtual ~ErrorHandler() {}

  /** \brief Callback function that is called for static errors 
   *         as defined in the XQuery 1.0 Specification 
   *         (see http://www.w3.org/TR/xquery/#id-kinds-of-errors 
   *
   * @param exception information about the error.
   */
  virtual void error( ZorbaException const &exception ) = 0;
};

} // namespace zorba

#endif /* ZORBA_ERROR_HANDLER_API_H */
/* vim:set et sw=2 ts=2: */
