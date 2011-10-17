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
#ifndef ZORBA_EXTERNAL_FUNCTION_PARAM_API_H
#define ZORBA_EXTERNAL_FUNCTION_PARAM_API_H

namespace zorba {

/**
 * Instances of subclasses of this abstract class may
 * be used as parameters to the DynamicContext::addExternalFunctionParameter
 * function. This is useful in the implementation of
 * external modules/functions in order to store information
 * between several invocations of the same function.
 *
 * The destroy method is called by Zorba at the end
 * of the execution of an XQuery program, when the corresponding
 * DynamicContext is destroyed.
 *
 */
class ExternalFunctionParameter
{
public:
  /**
   * This function is invoked by Zorba when the DynamicContext
   * that contains the instance is destroyed. This allows
   * the user to release resources. In the simplest case,
   * an implementation might simply call "delete this" to
   * destroy the object.
   */
  virtual void destroy() throw() = 0;

  /**
   * Virtual destructor with an empty implementation
   */
  virtual ~ExternalFunctionParameter() {}
};

}

#endif
