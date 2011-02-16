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

#include "image_function.h"

namespace zorba { 
  
  class ItemFactory;
  class SerializationItemProvider;

  namespace imagemodule { namespace manipulationmodule {
  
 
    
//*****************************************************************************

class ResizeFunction : public ImageFunction
  {
    public:
      ResizeFunction(const ImageModule* aModule);
      virtual String getLocalName() const { return "resize"; }

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };

//*****************************************************************************


class ZoomByWidthFunction : public ImageFunction
  {
    public:
      ZoomByWidthFunction(const ImageModule* aModule);
      virtual String getLocalName() const { return "zoom-by-width"; }

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };

//*****************************************************************************


class ZoomByHeightFunction : public ImageFunction

  {
    public:
      ZoomByHeightFunction(const ImageModule* aModule);
      virtual String getLocalName() const { return "zoom-by-height"; }

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };

//*****************************************************************************


class ZoomFunction : public ImageFunction

  {
    public:
      ZoomFunction(const ImageModule* aModule);
      virtual String getLocalName() const { return "zoom";}

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };

//*****************************************************************************

class SubImageFunction : public ImageFunction

  {
    public:
      SubImageFunction(const ImageModule* aModule);
      virtual String getLocalName() const { return "sub-image";}

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };

//*****************************************************************************

class OverlayFunction : public ImageFunction

  {
    public:
      OverlayFunction(const ImageModule* aModule);
      virtual String getLocalName() const { return "overlay-impl";}

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };

//*****************************************************************************

class ChopFunction : public ImageFunction

  {
    public:
      ChopFunction(const ImageModule* aModule);
      virtual String getLocalName() const { return "chop";}

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };

//*****************************************************************************

class CropFunction : public ImageFunction

  {
    public:
      CropFunction(const ImageModule* aModule);
      virtual String getLocalName() const { return "crop";}

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };

//*****************************************************************************

class RotateFunction : public ImageFunction

  {
    public:
      RotateFunction(const ImageModule* aModule);
      virtual String getLocalName() const { return "rotate";}

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };

//*****************************************************************************

class EraseFunction : public ImageFunction

  {
    public:
      EraseFunction(const ImageModule* aModule);
      virtual String getLocalName() const { return "erase";}
      
      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;
    

  };

//*****************************************************************************

class  FlopFunction : public ImageFunction

  {
    public:
      FlopFunction(const ImageModule* aModule);
      virtual String getLocalName() const { return "flop";}

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };

//*****************************************************************************

class FlipFunction : public ImageFunction

  {
    public:
      FlipFunction(const ImageModule* aModule);
      virtual String getLocalName() const { return "flip";}

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };

//*****************************************************************************

class TrimFunction : public ImageFunction

  {
    public:
      TrimFunction(const ImageModule* aModule);
      virtual String getLocalName() const { return "trim";}

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };

//*****************************************************************************

class AddNoiseFunction : public ImageFunction

  {
    public:
      AddNoiseFunction(const ImageModule* aModule);
      virtual String getLocalName() const { return "add-noise-impl";}

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };

//*****************************************************************************

class BlurFunction : public ImageFunction

  {
    public:
      BlurFunction(const ImageModule* aModule);
      virtual String getLocalName() const { return "blur";}

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };

//*****************************************************************************

class DespeckleFunction : public ImageFunction

  {
    public:
      DespeckleFunction(const ImageModule* aModule);
      virtual String getLocalName() const { return "despeckle";}

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };

//*****************************************************************************

class EnhanceFunction : public ImageFunction

  {
    public:
      EnhanceFunction(const ImageModule* aModule);
      virtual String getLocalName() const { return "enhance";}

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };

//*****************************************************************************

class EqualizeFunction : public ImageFunction

  {
    public:
      EqualizeFunction(const ImageModule* aModule);
      virtual String getLocalName() const { return "equalize";}

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };

//*****************************************************************************

class EdgeFunction : public ImageFunction

  {
    public:
      EdgeFunction(const ImageModule* aModule);
      virtual String getLocalName() const { return "edge";}

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };

//*****************************************************************************

class CharcoalFunction : public ImageFunction

  {
    public:
      CharcoalFunction(const ImageModule* aModule);
      virtual String getLocalName() const { return "charcoal";}

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };

//*****************************************************************************

class EmbossFunction : public ImageFunction

  {
    public:
      EmbossFunction(const ImageModule* aModule);
      virtual String getLocalName() const { return "emboss";}

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };

//*****************************************************************************

class SolarizeFunction : public ImageFunction

  {
    public:
      SolarizeFunction(const ImageModule* aModule);
      virtual String getLocalName() const { return "solarize";}

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };

//*****************************************************************************

class StereoFunction : public ImageFunction

  {
    public:
      StereoFunction(const ImageModule* aModule);
      virtual String getLocalName() const { return "stereo";}

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };

//*****************************************************************************

class TransparentFunction : public ImageFunction

  {
    public:
      TransparentFunction(const ImageModule* aModule);
      virtual String getLocalName() const { return "transparent-impl";}

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };

//*****************************************************************************

class SwirlFunction : public ImageFunction

  {
    public:
      SwirlFunction(const ImageModule* aModule);
      virtual String getLocalName() const { return "swirl";}

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };

//*****************************************************************************

class ReduceNoiseFunction : public ImageFunction

  {
    public:
      ReduceNoiseFunction(const ImageModule* aModule);
      virtual String getLocalName() const { return "reduce-noise";}

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };

//*****************************************************************************

class ContrastFunction : public ImageFunction

  {
    public:
      ContrastFunction(const ImageModule* aModule);
      virtual String getLocalName() const { return "contrast";}

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };

//*****************************************************************************

class GammaFunction : public ImageFunction

  {
    public:
      GammaFunction(const ImageModule* aModule);
      virtual String getLocalName() const { return "gamma";}

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };


//*****************************************************************************

class ImplodeFunction : public ImageFunction

  {
    public:
      ImplodeFunction(const ImageModule* aModule);
      virtual String getLocalName() const { return "implode";}

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };

//*****************************************************************************

class OilPaintFunction : public ImageFunction

  {
    public:
      OilPaintFunction(const ImageModule* aModule);
      virtual String getLocalName() const { return "oil-paint";}

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };

//*****************************************************************************

class WaterMarkFunction : public ImageFunction

  {
    public:
      WaterMarkFunction(const ImageModule* aModule);
      virtual String getLocalName() const { return "watermark";}

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };


} /* namespace manipulationmodule */ } /* namespace imagemodule */ } /* namespace zorba */

#endif /* ZORBA_IMAGEMODULE_MANIPULATIONMODULE_MANIPULATION_H */
