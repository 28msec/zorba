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
#ifndef ZORBA_EXTERNAL_MODULE_H
#define ZORBA_EXTERNAL_MODULE_H

#include <zorba/config.h>
#include <zorba/zorba_string.h>


namespace zorba {


class ExternalFunction;


/***************************************************************************//**
  An external module represents a group of external functions, all belonging to
  the same target namespace. Class ExternalModule provides the interface for
  retrieving the target namespace URI and/or the implementation of each contained
  external function by function name. 

  An external module can be a library module by itself, or be a component of
  a library module.
 
  Instances of this class must be implemented by the application and provide 
  storage for the implementations of the external functions. The instances must
  be registered in the static context in order for the functions to be accessible
  by a query (see <a href="../../zorba/html/external_functions.html">
  here</a> for more details.). 
********************************************************************************/
class ZORBA_DLL_PUBLIC ExternalModule 
{
 public:
  virtual ~ExternalModule() {}

  /**
   * @return the target namespace URI of the module.
   */
  virtual String
  getURI() const = 0;

  /**
   * @return the implementation of the function with the given name.
   */
  virtual ExternalFunction*
  getExternalFunction(const String& aLocalname) = 0;

  /**
   * \brief Function used for destroying the ExternalModule object
   *        passed as parameter.
   *
   * The user needs to override this function if the module
   * passed as parameter was created using the createModule function
   * which is used for dynamically loading modules from a shared
   * library.
   */
  virtual void
  destroy() {}

};


} /* namespace zorba */

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
