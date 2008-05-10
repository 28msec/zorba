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

#include <zorba/exception.h>

namespace zorba {

  /** \brief ErrorHandler defines an interface. Classes that implement this interface
   *         can be used as callback classes.
   *
   * Specifically, they can be registered with an XQuery object. This way, all 
   * errors that would have been reported by throwing an exception are reported 
   * by calling the according function of this interface. Subclasses of the 
   * ZorbaException class that would have been thrown are passed as parameter
   * to the callback function.
   */
  class ErrorHandler 
  {
    public:
      /** \brief Destructor
       *
       */
      virtual ~ErrorHandler() {}

      /** \brief Callback function that is called for static errors 
       *         as defined in the XQuery 1.0 Specification 
       *         (see http://www.w3.org/TR/xquery/#id-kinds-of-errors 
       *
       * @param aStaticError information about the error.
       */
      virtual void
      staticError ( const StaticException& aStaticError ) = 0;

      /** \brief Callback function that is called for dynamic errors 
       *         as defined in the XQuery 1.0 Specification 
       *         (see http://www.w3.org/TR/xquery/#id-kinds-of-errors 
       *
       * @param aDynamicError information about the error.
       */
      virtual void
      dynamicError ( const DynamicException& aDynamicError ) = 0;

      /** \brief Callback function that is called for type errors 
       *         as defined in the XQuery 1.0 Specification 
       *         (see http://www.w3.org/TR/xquery/#id-kinds-of-errors 
       *
       * @param aTypeError information about the error.
       */
      virtual void
      typeError ( const TypeException& aTypeError ) = 0;

      /** \brief Callback function that is called for errors that occur during
       *         serialization of a query result.
       *         (see http://www.w3.org/TR/2005/CR-xslt-xquery-serialization-20051103/)
       *
       * @param aSerializationError information about the error.
       */
      virtual void
      serializationError ( const  SerializationException& aSerializationError ) = 0;

      /** \brief Callback function that is called for errors that occur in the system.
       *
       * @param aSystemError information about the error.
       */
      virtual void
      systemError ( const SystemException& aSystemError ) = 0;
   };

} /* namespace zorba */

#endif
