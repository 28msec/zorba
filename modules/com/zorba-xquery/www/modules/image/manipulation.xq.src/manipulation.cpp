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
#include <zorba/empty_sequence.h>
#include <zorba/singleton_item_sequence.h>
#include <zorba/zorba.h>
#include "manipulation_module.h"

namespace zorba {  namespace imagemodule { namespace manipulationmodule {

using namespace zorba::imagemodule;

//*****************************************************************************

ResizeFunction::ResizeFunction(const ManipulationModule* aModule) : ManipulationFunction(aModule)
{
}

ItemSequence_t
ResizeFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  Magick::Image lImage;
  int lNewWidth, lNewHeight;
  lImage = ImageFunction::getOneImageArg(aArgs, 0);
  lNewWidth = ImageFunction::getOneUnsignedIntArg(aArgs, 1);
  lNewHeight = ImageFunction::getOneUnsignedIntArg(aArgs, 2);
  lImage.size(Magick::Geometry(lNewWidth, lNewHeight));
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage);
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
}

//*****************************************************************************


ZoomFunction::ZoomFunction(const ManipulationModule* aModule) : ManipulationFunction(aModule)
{
}

ItemSequence_t
ZoomFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  Magick::Image lImage;
  int lNewWidth, lNewHeight;
  lImage = ImageFunction::getOneImageArg(aArgs, 0);
  lNewWidth = ImageFunction::getOneUnsignedIntArg(aArgs, 1);
  lNewHeight = ImageFunction::getOneUnsignedIntArg(aArgs, 2);
  lImage.zoom(Magick::Geometry(lNewWidth, lNewHeight));
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage);
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
}

//*****************************************************************************

ZoomByWidthFunction::ZoomByWidthFunction(const ManipulationModule* aModule) : ManipulationFunction(aModule)
{
}

ItemSequence_t
ZoomByWidthFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{

  Magick::Image lImage;
  int lNewWidth, lRatio;
  lImage = ImageFunction::getOneImageArg(aArgs, 0);
  lNewWidth = ImageFunction::getOneUnsignedIntArg(aArgs, 1);
  lRatio = lNewWidth/lImage.columns();
  lImage.zoom(Magick::Geometry(lNewWidth, lImage.rows()*lRatio));
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage);
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));

}

//*****************************************************************************


ZoomByHeightFunction::ZoomByHeightFunction(const ManipulationModule* aModule) : ManipulationFunction(aModule)
{
}

ItemSequence_t
ZoomByHeightFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{


  Magick::Image lImage;
  int lNewHeight, lRatio;
  lImage = ImageFunction::getOneImageArg(aArgs, 0);
  lNewHeight = ImageFunction::getOneUnsignedIntArg(aArgs, 1);
  lRatio = lNewHeight / lImage.rows();
  lImage.zoom(Magick::Geometry(lImage.columns()*lRatio, lNewHeight));
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage);
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));

}

//*****************************************************************************


ZoomByRatioFunction::ZoomByRatioFunction(const ManipulationModule* aModule) : ManipulationFunction(aModule)
{
}


ItemSequence_t
ZoomByRatioFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{

  Magick::Image lImage;
  double lRatio;
  lImage = ImageFunction::getOneImageArg(aArgs, 0);
  lRatio = ImageFunction::getOneDoubleArg(aArgs, 1);
  lImage.zoom(Magick::Geometry(lImage.columns()*lRatio, lImage.rows()*lRatio));
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage);
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
}

//*****************************************************************************

SubImageFunction::SubImageFunction(const ManipulationModule* aModule) : ManipulationFunction(aModule)
{
}


ItemSequence_t
SubImageFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{

  Magick::Image lImage;
  lImage = ImageFunction::getOneImageArg(aArgs, 0);
  int lLeftUpperX = ImageFunction::getOneUnsignedIntArg(aArgs, 1);
  int lLeftUpperY = ImageFunction::getOneUnsignedIntArg(aArgs, 2);
  int lRightLowerX = ImageFunction::getOneUnsignedIntArg(aArgs, 3);
  int lRightLowerY = ImageFunction::getOneUnsignedIntArg(aArgs, 4);
  // chop away everything that is either left of lLeftUpperX or above lLeftUpperY
  lImage.chop(Magick::Geometry(lLeftUpperX, lLeftUpperY));
  // crop away everything that is either right of lRightLowerX or below lRightLowerY
  lImage.crop(Magick::Geometry(lRightLowerX, lRightLowerY));
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage);
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
}

//*****************************************************************************

ChopFunction::ChopFunction(const ManipulationModule* aModule) : ManipulationFunction(aModule)
{
}


ItemSequence_t
ChopFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{

  Magick::Image lImage;
  lImage = ImageFunction::getOneImageArg(aArgs, 0);
  int lLeftUpperX = ImageFunction::getOneUnsignedIntArg(aArgs, 1);
  int lLeftUpperY = ImageFunction::getOneUnsignedIntArg(aArgs, 2);
  // chop away everything that is either left of lLeftUpperX or above lLeftUpperY
  lImage.chop(Magick::Geometry(lLeftUpperX, lLeftUpperY));
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage);
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
}

//*****************************************************************************

CropFunction::CropFunction(const ManipulationModule* aModule) : ManipulationFunction(aModule)
{
}

ItemSequence_t
CropFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{

  Magick::Image lImage;
  lImage = ImageFunction::getOneImageArg(aArgs, 0);
  int lRightLowerX = ImageFunction::getOneUnsignedIntArg(aArgs, 1);
  int lRightLowerY = ImageFunction::getOneUnsignedIntArg(aArgs, 2);
  // crop away everything that is either right of lRightLowerX or below lRightLowerY
  lImage.crop(Magick::Geometry(lRightLowerX, lRightLowerY));
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage);
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
}

//*****************************************************************************

RotateFunction::RotateFunction(const ManipulationModule* aModule) : ManipulationFunction(aModule)
{
}


ItemSequence_t
RotateFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  Magick::Image lImage;
  lImage = ImageFunction::getOneImageArg(aArgs, 0);
  int lAngle = ImageFunction::getOneUnsignedIntArg(aArgs, 1);
  lImage.rotate(lAngle%360);
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage);
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
}

//*****************************************************************************

EraseFunction::EraseFunction(const ManipulationModule* aModule) : ManipulationFunction(aModule)
{
}

ItemSequence_t
EraseFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{

  Magick::Image lImage;
  lImage = ImageFunction::getOneImageArg(aArgs, 0);
  lImage.erase();
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage);
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
}

//*****************************************************************************

FlopFunction::FlopFunction(const ManipulationModule* aModule) : ManipulationFunction(aModule)
{
}

ItemSequence_t
FlopFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{

  Magick::Image lImage;
  lImage = ImageFunction::getOneImageArg(aArgs, 0);
  lImage.flop();
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage);
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
}

//*****************************************************************************

FlipFunction::FlipFunction(const ManipulationModule* aModule) : ManipulationFunction(aModule)
{
}

ItemSequence_t
FlipFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  Magick::Image lImage;
  lImage = ImageFunction::getOneImageArg(aArgs, 0);
  lImage.flip();
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage);
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
}

//*****************************************************************************

TrimFunction::TrimFunction(const ManipulationModule* aModule) : ManipulationFunction(aModule)
{
}

ItemSequence_t
TrimFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  Magick::Image lImage;
  lImage = ImageFunction::getOneImageArg(aArgs, 0);
  lImage.trim();
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage);
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
}

//*****************************************************************************

AddNoiseFunction::AddNoiseFunction(const ManipulationModule* aModule) : ManipulationFunction(aModule)
{
}

ItemSequence_t
AddNoiseFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{

  Magick::Image lImage;
  String lNoiseType;
  lImage = ImageFunction::getOneImageArg(aArgs, 0);
  lNoiseType = ManipulationFunction::getOneStringArg(aArgs, 1);  

  // add the right noise type to image based on the second argument
  if (lNoiseType.equals("UniformNoise")) {
    lImage.addNoise(Magick::UniformNoise);
  } else if (lNoiseType.equals("GaussianNoise")) {
    lImage.addNoise(Magick::GaussianNoise);
  } else if (lNoiseType.equals("MultiplicativeGaussianNoise")) {
    lImage.addNoise(Magick::MultiplicativeGaussianNoise);
  } else if (lNoiseType.equals("ImpulseNoise")) {
    lImage.addNoise(Magick::ImpulseNoise);
  } else if (lNoiseType.equals("LaplacianNoise")) {
    lImage.addNoise(Magick::LaplacianNoise);
  } else if (lNoiseType.equals("PoissonNoise")) {
    lImage.addNoise(Magick::PoissonNoise);
  }

  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage);
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
}

//*****************************************************************************

BlurFunction::BlurFunction(const ManipulationModule* aModule) : ManipulationFunction(aModule)
{
}


ItemSequence_t
BlurFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{

  Magick::Image lImage;
  lImage = ImageFunction::getOneImageArg(aArgs, 0);
  int lRadius = ImageFunction::getOneUnsignedIntArg(aArgs, 1);
  int lSigma = ImageFunction::getOneUnsignedIntArg(aArgs, 2);
  lImage.blur(lRadius, lSigma);
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage);
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());

  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
}

//*****************************************************************************


DespeckleFunction::DespeckleFunction(const ManipulationModule* aModule) : ManipulationFunction(aModule)
{
}

ItemSequence_t
DespeckleFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{

  Magick::Image lImage;
  lImage = ImageFunction::getOneImageArg(aArgs, 0);
  lImage.despeckle();
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage);
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
}

//*****************************************************************************

EnhanceFunction::EnhanceFunction(const ManipulationModule* aModule) : ManipulationFunction(aModule)
{
}

ItemSequence_t
EnhanceFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  Magick::Image lImage;
  lImage = ImageFunction::getOneImageArg(aArgs, 0);
  lImage.enhance();
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage);
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
}

//*****************************************************************************

EqualizeFunction::EqualizeFunction(const ManipulationModule* aModule) : ManipulationFunction(aModule)
{
}

ItemSequence_t
EqualizeFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{

  Magick::Image lImage;
  lImage = ImageFunction::getOneImageArg(aArgs, 0);
  lImage.equalize();
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage);
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
}

//*****************************************************************************

EdgeFunction::EdgeFunction(const ManipulationModule* aModule) : ManipulationFunction(aModule)
{
}

ItemSequence_t
EdgeFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{

  Magick::Image lImage;
  lImage = ImageFunction::getOneImageArg(aArgs, 0);
  Item lItem;   
  // check if second argument was given
  if (!aArgs[1]->next(lItem)) {
    lImage.edge(0);
  } else {
    lImage.edge(lItem.getIntValue());
  }
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage);
  lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
}

//*****************************************************************************

CharcoalFunction::CharcoalFunction(const ManipulationModule* aModule) : ManipulationFunction(aModule)
{
}

ItemSequence_t
CharcoalFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{

  Magick::Image lImage;
  double lRadius = ImageFunction::getOneDoubleArg(aArgs, 1);  
  double lSigma = ImageFunction::getOneDoubleArg(aArgs, 2);
  lImage = ImageFunction::getOneImageArg(aArgs, 0);
  lImage.charcoal(lRadius, lSigma);
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage);
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
}


//*****************************************************************************

EmbossFunction::EmbossFunction(const ManipulationModule* aModule) : ManipulationFunction(aModule)
{
}

ItemSequence_t
EmbossFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{

  Magick::Image lImage;
  double lRadius = ImageFunction::getOneDoubleArg(aArgs, 1);
  double lSigma = ImageFunction::getOneDoubleArg(aArgs, 2);
  lImage = ImageFunction::getOneImageArg(aArgs, 0);
  lImage.emboss(lRadius, lSigma);
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage);
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
}


//*****************************************************************************

SolarizeFunction::SolarizeFunction(const ManipulationModule* aModule) : ManipulationFunction(aModule)
{
}

ItemSequence_t
SolarizeFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{

  Magick::Image lImage;
  double lFactor = ImageFunction::getOneDoubleArg(aArgs, 1);
  lImage = ImageFunction::getOneImageArg(aArgs, 0);
  lImage.solarize(lFactor);
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage);
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
}


//*****************************************************************************

StereoFunction::StereoFunction(const ManipulationModule* aModule) : ManipulationFunction(aModule)
{
}

ItemSequence_t
StereoFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{

  Magick::Image lFirstImage = ImageFunction::getOneImageArg(aArgs, 0);
  Magick::Image lSecondImage = ImageFunction::getOneImageArg(aArgs, 1);
  lFirstImage.stereo(lSecondImage);
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lFirstImage);
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
}

//*****************************************************************************

TransparentFunction::TransparentFunction(const ManipulationModule* aModule) : ManipulationFunction(aModule)
{
}

ItemSequence_t
TransparentFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{

  Magick::Image lImage;
  Magick::ColorRGB lColor = ImageFunction::getOneColorArg(aArgs, 1);
  lImage = ImageFunction::getOneImageArg(aArgs, 0);
  lImage.transparent(lColor);
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage);
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
}

//*****************************************************************************

SwirlFunction::SwirlFunction(const ManipulationModule* aModule) : ManipulationFunction(aModule)
{ 
}

ItemSequence_t
SwirlFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{

  Magick::Image lImage;
  double lDegrees = ImageFunction::getOneDoubleArg(aArgs, 1);
  lImage = ImageFunction::getOneImageArg(aArgs, 0);
  lImage.swirl(lDegrees);
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage);
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
}

//*****************************************************************************

ReduceNoiseFunction::ReduceNoiseFunction(const ManipulationModule* aModule) : ManipulationFunction(aModule)
{ 
}

ItemSequence_t
ReduceNoiseFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{

  Magick::Image lImage;
  double lOrder  = ImageFunction::getOneDoubleArg(aArgs, 1);
  lImage = ImageFunction::getOneImageArg(aArgs, 0);
  lImage.reduceNoise(lOrder);
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage);
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
}


//*****************************************************************************

ContrastFunction::ContrastFunction(const ManipulationModule* aModule) : ManipulationFunction(aModule)
{ 
}

ItemSequence_t
ContrastFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{

  Magick::Image lImage;
  double lSharpen = ImageFunction::getOneDoubleArg(aArgs, 1);
  lImage = ImageFunction::getOneImageArg(aArgs, 0);
  lImage.contrast(lSharpen);
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage);
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
}


//*****************************************************************************

GammaFunction::GammaFunction(const ManipulationModule* aModule) : ManipulationFunction(aModule)
{ 
}

ItemSequence_t
GammaFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  Item lItem;
  Magick::Image lImage;
  lImage = ImageFunction::getOneImageArg(aArgs, 0);
  // check if the one gamma value version was called or the version with seperate values for r g and b. Doing this by looking if the 3. argument exists.
  if (!aArgs[2]->next(lItem)) {
    double lGammaRed = ImageFunction::getOneDoubleArg(aArgs, 1);
    double lGammaGreen = ImageFunction::getOneDoubleArg(aArgs, 2);
    double lGammaBlue = ImageFunction::getOneDoubleArg(aArgs, 3);
    lImage.gamma(lGammaRed, lGammaGreen, lGammaBlue);
  } else {
    double lGamma = ImageFunction::getOneDoubleArg(aArgs, 1);
    lImage.gamma(lGamma);
  } 
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage);
  lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
}

//*****************************************************************************

ImplodeFunction::ImplodeFunction(const ManipulationModule* aModule) : ManipulationFunction(aModule)
{ 
}

ItemSequence_t
ImplodeFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{

  Magick::Image lImage;
  double lFactor = ImageFunction::getOneDoubleArg(aArgs, 1);
  lImage = ImageFunction::getOneImageArg(aArgs, 0);
  lImage.implode(lFactor);
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage);
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
}


//*****************************************************************************

OilPaintFunction::OilPaintFunction(const ManipulationModule* aModule) : ManipulationFunction(aModule)
{ 
}

ItemSequence_t
OilPaintFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{

  Magick::Image lImage;
  double lRadius = ImageFunction::getOneDoubleArg(aArgs, 1);
  lImage = ImageFunction::getOneImageArg(aArgs, 0);
  lImage.oilPaint(lRadius);
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage);
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
}


} /* namespace manipulationmodule */  } /* namespace imagemodule */ } /* namespace zorba */


#ifdef WIN32
#  define DLL_EXPORT __declspec(dllexport)
#else
#  define DLL_EXPORT __attribute__ ((visibility("default")))
#endif

extern "C" DLL_EXPORT zorba::ExternalModule* createModule() {
  return new zorba::imagemodule::manipulationmodule::ManipulationModule();
}
