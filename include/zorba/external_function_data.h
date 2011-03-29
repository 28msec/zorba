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
#ifndef ZORBA_EXTERNAL_FUNCTION_DATA_H
#define ZORBA_EXTERNAL_FUNCTION_DATA_H

#include <zorba/config.h>
#include <zorba/api_shared_types.h>

namespace zorba {

  /** \brief Base class for all external function classes.
   */
  class ZORBA_DLL_PUBLIC ExternalFunctionData 
  {
    public:

      /** \brief Raise an error from an external function.
       *
       * This function may be used in the implementation of an external function.
       * If the function is called, an error with QName
       * http://www.w3.org/2005/xqt-errors#FOER0000 will be raised.
       * Calling this function is equivalent to invoking the fn:error function
       * with no arguments.
       */
      static void
      error();

      /** \brief Raise an error from an external function.
       *
       * This function may be used in the implementation of an external function.
       * If the function is called, an error with the given QName will be raised.
       * If the given QName is NULL, an error with the default QName
       * http://www.w3.org/2005/xqt-errors#FOER0000 will be raised.
       * Calling this function is equivalent to invoking the fn:error function
       * with one argument.
       *
       * @param aQName name of the error that will be raised
       *        (argument may be NULL)
       */
      static void
      error(const Item& aQName);

      /** \brief Raise an error from an external function.
       *
       * This function may be used in the implementation of an external function.
       * If the function is called, an error with the given QName and error
       * description will be raised. If the given QName is NULL, an error
       * with the default QName http://www.w3.org/2005/xqt-errors#FOER0000
       * will be raised.
       * The result is equal to calling fn:error (with two arguments) in XQuery.
       *
       * @param aQName name of the error that will be raised
       *        (argument may be NULL).
       * @param aDescription description of the error that will be raised.
       */
      static void
      error(const Item& aQName, const String& aDescription);

      /** \brief Raise an error from an external function.
       *
       * This function may be used in the implementation of an external function.
       * If the function is called, an error with the given QName, error
       * description, and error object  will be raised. If the given QName is NULL,
       * an error with the default QName http://www.w3.org/2005/xqt-errors#FOER0000
       * will be raised.
       * Calling this function is equivalent to invoking the fn:error function
       * with three arguments.
       *
       * @param aQName name of the error that will be raised
       *        (argument may be NULL).
       * @param aDescription description of the error that will be raised.
       * @param aErrorObject error object for the error that will be raised.
       */
      static void
      error(
          const Item& aQName,
          const String& aDescription,
          const ItemSequence_t& aErrorObject);

  };

} /* namespace zorba */
#endif
