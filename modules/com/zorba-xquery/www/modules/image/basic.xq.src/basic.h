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
#ifndef ZORBA_IMAGEMODULE_BASICMODULE_BASIC_H
#define ZORBA_IMAGEMODULE_BASICMODULE_BASIC_H

#include <zorba/options.h>
#include "basic_function.h"

namespace zorba { 
  
  class ItemFactory;
  class SerializationItemProvider;

  namespace imagemodule { namespace basicmodule {
    
//*****************************************************************************

class WidthFunction : public BasicFunction 

  {
    public:
      WidthFunction(const BasicModule* aModule);
      virtual String getLocalName() const { return "width";}

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };


//*****************************************************************************


class HeightFunction : public BasicFunction 

  {
    public:
      HeightFunction(const BasicModule* aModule);
      virtual String getLocalName() const { return "height";}

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };


//*****************************************************************************





  class TypeFunction : public BasicFunction
  {
    public:
      TypeFunction(const BasicModule* aModule);
      virtual String getLocalName() const { return "type"; }

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };

//*****************************************************************************


class ConvertFunction : public BasicFunction
  {
    public:
      ConvertFunction(const BasicModule* aModule);
      virtual String getLocalName() const { return "convert"; }

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };

//*****************************************************************************

class CreateFunction : public BasicFunction
  {
    public:
      CreateFunction(const BasicModule* aModule);
      virtual String getLocalName() const { return "create"; }

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };


//*****************************************************************************


class CreateAnimatedGifFunction : public BasicFunction
  {
    public:
      CreateAnimatedGifFunction(const BasicModule* aModule);
      virtual String getLocalName() const { return "create-animated-gif"; }

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };


} /* namespace basicmodule */  } /* namespace imagemodule */ }  /* namespace zorba */

#endif /* ZORBA_IMAGEMODULE_BASICMODULE_BASIC_H */
