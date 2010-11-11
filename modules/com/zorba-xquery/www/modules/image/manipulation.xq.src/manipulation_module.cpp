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

#include "manipulation.h"
#include "manipulation_module.h"

namespace zorba { namespace imagemodule {  namespace manipulationmodule {



StatelessExternalFunction*
ManipulationModule::getExternalFunction(String aLocalname) const
{
  StatelessExternalFunction*& lFunc = theFunctions[aLocalname];
  if (!lFunc) {
    if (1 == 0) {
    } else if (aLocalname.equals("resize")) {
      lFunc = new ResizeFunction(this);
    } else if (aLocalname.equals("zoom-by-width")) {
      lFunc = new ZoomByWidthFunction(this);
    } else if (aLocalname.equals("zoom-by-height")) {
      lFunc = new ZoomByHeightFunction(this);
    } else if (aLocalname.equals("zoom")) {
      lFunc = new ZoomFunction(this);
    } else if (aLocalname.equals("sub-image")) {
      lFunc = new SubImageFunction(this);
    } else if (aLocalname.equals("overlay-impl")) {
      lFunc = new OverlayFunction(this);
    } else if (aLocalname.equals("chop")) {
      lFunc = new ChopFunction(this);
    } else if (aLocalname.equals("crop")) {
      lFunc = new CropFunction(this);
    } else if (aLocalname.equals("rotate")) {
      lFunc = new RotateFunction(this);
    } else if (aLocalname.equals("erase")) {
      lFunc = new EraseFunction(this);
    } else if (aLocalname.equals("flop")) {
      lFunc = new FlopFunction(this);
    } else if (aLocalname.equals("flip")) {
      lFunc = new FlipFunction(this); 
    } else if (aLocalname.equals("trim")) {
      lFunc = new TrimFunction(this);
    } else if (aLocalname.equals("add-noise-impl")) {
      lFunc = new AddNoiseFunction(this);
    } else if (aLocalname.equals("blur")) {
      lFunc = new BlurFunction(this);
    } else if (aLocalname.equals("despeckle")) {
      lFunc = new DespeckleFunction(this);
    } else if (aLocalname.equals("enhance")) {
      lFunc = new EnhanceFunction(this);
    } else if (aLocalname.equals("equalize")) {
      lFunc = new EqualizeFunction(this);
    } else if (aLocalname.equals("edge")) {
      lFunc = new EdgeFunction(this);
    } else if (aLocalname.equals("charcoal")) {
      lFunc = new CharcoalFunction(this);
    } else if (aLocalname.equals("emboss")) {
      lFunc = new EmbossFunction(this);
    } else if (aLocalname.equals("solarize")) {
      lFunc = new SolarizeFunction(this);
    } else if (aLocalname.equals("stereo")) {
      lFunc = new StereoFunction(this);
    } else if (aLocalname.equals("transparent-impl")) {
      lFunc = new TransparentFunction(this);
    } else if (aLocalname.equals("swirl")) {
      lFunc = new SwirlFunction(this);
    } else if (aLocalname.equals("reduce-noise")) {
      lFunc = new ReduceNoiseFunction(this);
    } else if (aLocalname.equals("contrast")) {
      lFunc = new ContrastFunction(this); 
    } else if (aLocalname.equals("gamma")) {
      lFunc = new GammaFunction(this);
    } else if (aLocalname.equals("implode")) {
      lFunc = new ImplodeFunction(this);
    } else if (aLocalname.equals("oil-paint")) {
      lFunc = new OilPaintFunction(this); 
    } else if (aLocalname.equals("watermark")) {
      lFunc = new WaterMarkFunction(this);
    }  
  }   
  return lFunc;
}


} /* namespace manipulationmodule */ } /* namespace imagemodule */ } /* namespace zorba */
