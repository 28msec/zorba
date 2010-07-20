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

#ifndef ZORBA_IMAGEMODULE_MANIPULATIONMODULE_MANIPULATION_FUNCTION_H
#define ZORBA_IMAGEMODULE_MANIPULATIONMODULE_MANIPULATION_FUNCTION_H 

#include <Magick++.h>
#include <zorba/external_function.h>
#include "image_function.h"

namespace zorba { namespace imagemodule { namespace manipulationmodule {
  

  class ManipulationModule;


  class ManipulationFunction : public zorba::imagemodule::ImageFunction 
  {


    protected:
      const ManipulationModule* theModule;
      virtual String
        getURI() const;
       

    public:
      ManipulationFunction(const ManipulationModule* module);
      ~ManipulationFunction();


  };





} /* namespace manipulationmodule */
} /* namespace imagemodule */
} /* namespace zorba */

#endif // ZORBA_IMAGEMODULE_MANIPULATIONMODULE_MANIPULATION_FUNCTION_H_
