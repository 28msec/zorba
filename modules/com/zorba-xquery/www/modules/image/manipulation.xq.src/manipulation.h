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
#ifndef ZORBA_IMAGEMODULE_MANIPULATIONMODULE_MANIPULATION_H
#define ZORBA_IMAGEMODULE_MANIPULATIONMODULE_MANIPULATION_H

#include <zorba/options.h>
#include "manipulation_function.h"

namespace zorba { 
  
  class ItemFactory;
  class SerializationItemProvider;

  namespace imagemodule { namespace manipulationmodule {
  
 
    
//*****************************************************************************

  class ResizeFunction : public ManipulationFunction
  {
    public:
      ResizeFunction(const ManipulationModule* aModule);
      virtual String getLocalName() const { return "resize"; }

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };

//*****************************************************************************


class  ZoomFunction : public ManipulationFunction

  {
    public:
      ZoomFunction(const ManipulationModule* aModule);
      virtual String getLocalName() const { return "zoom"; }

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };

//*****************************************************************************


class  ZoomByWidthFunction : public ManipulationFunction

  {
    public:
      ZoomByWidthFunction(const ManipulationModule* aModule);
      virtual String getLocalName() const { return "zoom-by-width"; }

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };

//*****************************************************************************


class  ZoomByHeightFunction : public ManipulationFunction

  {
    public:
      ZoomByHeightFunction(const ManipulationModule* aModule);
      virtual String getLocalName() const { return "zoom-by-height"; }

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };


//*****************************************************************************


class  ZoomByRatioFunction : public ManipulationFunction

  {
    public:
      ZoomByRatioFunction(const ManipulationModule* aModule);
      virtual String getLocalName() const { return "zoom-by-ratio";}

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };

//*****************************************************************************



class  SubImageFunction : public ManipulationFunction

  {
    public:
      SubImageFunction(const ManipulationModule* aModule);
      virtual String getLocalName() const { return "sub-image";}

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };

//*****************************************************************************


class  ChopFunction : public ManipulationFunction

  {
    public:
      ChopFunction(const ManipulationModule* aModule);
      virtual String getLocalName() const { return "chop";}

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };

//*****************************************************************************


class  CropFunction : public ManipulationFunction

  {
    public:
      CropFunction(const ManipulationModule* aModule);
      virtual String getLocalName() const { return "crop";}

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };

//*****************************************************************************


class  RotateFunction : public ManipulationFunction

  {
    public:
      RotateFunction(const ManipulationModule* aModule);
      virtual String getLocalName() const { return "rotate";}

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };

//*****************************************************************************


class  EraseFunction : public ManipulationFunction

  {
    public:
      EraseFunction(const ManipulationModule* aModule);
      virtual String getLocalName() const { return "erase";}
      
      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;
    

  };

//*****************************************************************************


class  FlopFunction : public ManipulationFunction

  {
    public:
      FlopFunction(const ManipulationModule* aModule);
      virtual String getLocalName() const { return "flop";}

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };

//*****************************************************************************


class  FlipFunction : public ManipulationFunction

  {
    public:
      FlipFunction(const ManipulationModule* aModule);
      virtual String getLocalName() const { return "flip";}

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };

//*****************************************************************************


class  TrimFunction : public ManipulationFunction

  {
    public:
      TrimFunction(const ManipulationModule* aModule);
      virtual String getLocalName() const { return "trim";}

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };

//*****************************************************************************


class  AddNoiseFunction : public ManipulationFunction

  {
    public:
      AddNoiseFunction(const ManipulationModule* aModule);
      virtual String getLocalName() const { return "add-noise";}

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };

//*****************************************************************************


class  BlurFunction : public ManipulationFunction

  {
    public:
      BlurFunction(const ManipulationModule* aModule);
      virtual String getLocalName() const { return "blur";}

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };

//*****************************************************************************


class  DespeckleFunction : public ManipulationFunction

  {
    public:
      DespeckleFunction(const ManipulationModule* aModule);
      virtual String getLocalName() const { return "despeckle";}

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };

//*****************************************************************************


class  EnhanceFunction : public ManipulationFunction

  {
    public:
      EnhanceFunction(const ManipulationModule* aModule);
      virtual String getLocalName() const { return "enhance";}

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };

//*****************************************************************************


class  EqualizeFunction : public ManipulationFunction

  {
    public:
      EqualizeFunction(const ManipulationModule* aModule);
      virtual String getLocalName() const { return "despeckle";}

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };

//*****************************************************************************


class  EdgeFunction : public ManipulationFunction

  {
    public:
      EdgeFunction(const ManipulationModule* aModule);
      virtual String getLocalName() const { return "edge";}

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };

//*****************************************************************************


class  CharcoalFunction : public ManipulationFunction

  {
    public:
      CharcoalFunction(const ManipulationModule* aModule);
      virtual String getLocalName() const { return "charcoal";}

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };

//*****************************************************************************

class  EmbossFunction : public ManipulationFunction

  {
    public:
      EmbossFunction(const ManipulationModule* aModule);
      virtual String getLocalName() const { return "emboss";}

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };

//*****************************************************************************

class  SolarizeFunction : public ManipulationFunction

  {
    public:
      SolarizeFunction(const ManipulationModule* aModule);
      virtual String getLocalName() const { return "solarize";}

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };

//*****************************************************************************

class  StereoFunction : public ManipulationFunction

  {
    public:
      StereoFunction(const ManipulationModule* aModule);
      virtual String getLocalName() const { return "stereo";}

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };

//*****************************************************************************

class  TransparentFunction : public ManipulationFunction

  {
    public:
      TransparentFunction(const ManipulationModule* aModule);
      virtual String getLocalName() const { return "transparent";}

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };

//*****************************************************************************

class  SwirlFunction : public ManipulationFunction

  {
    public:
      SwirlFunction(const ManipulationModule* aModule);
      virtual String getLocalName() const { return "swirl";}

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };

//*****************************************************************************

class  ReduceNoiseFunction : public ManipulationFunction

  {
    public:
      ReduceNoiseFunction(const ManipulationModule* aModule);
      virtual String getLocalName() const { return "reduce-noise";}

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };

//*****************************************************************************

class  ContrastFunction : public ManipulationFunction

  {
    public:
      ContrastFunction(const ManipulationModule* aModule);
      virtual String getLocalName() const { return "contrast";}

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };

//*****************************************************************************

class  GammaFunction : public ManipulationFunction

  {
    public:
      GammaFunction(const ManipulationModule* aModule);
      virtual String getLocalName() const { return "gamma";}

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };


//*****************************************************************************

class  ImplodeFunction : public ManipulationFunction

  {
    public:
      ImplodeFunction(const ManipulationModule* aModule);
      virtual String getLocalName() const { return "implode";}

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };

//*****************************************************************************

class  OilPaintFunction : public ManipulationFunction

  {
    public:
      OilPaintFunction(const ManipulationModule* aModule);
      virtual String getLocalName() const { return "oil-paint";}

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };




} /* namespace manipulationmodule */ } /* namespace imagemodule */ } /* namespace zorba */

#endif /* ZORBA_IMAGEMODULE_MANIPULATIONMODULE_MANIPULATION_H */
