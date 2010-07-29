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

ResizeFunction::ResizeFunction(const ImageModule* aModule) : ImageFunction(aModule)
{
}

ItemSequence_t
ResizeFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  Magick::Image lImage;
  ImageFunction::getOneImageArg(aArgs, 0, lImage);
  const unsigned int lNewWidth = ImageFunction::getOneUnsignedIntArg(aArgs, 1);
  const unsigned int lNewHeight = ImageFunction::getOneUnsignedIntArg(aArgs, 2);
  lImage.size(Magick::Geometry(lNewWidth, lNewHeight));
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage);
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
}

//*****************************************************************************


ZoomByWidthFunction::ZoomByWidthFunction(const ImageModule* aModule) : ImageFunction(aModule)
{
}

ItemSequence_t
ZoomByWidthFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{

  Magick::Image lImage;
  ImageFunction::getOneImageArg(aArgs, 0, lImage);
  const unsigned int lNewWidth = ImageFunction::getOneUnsignedIntArg(aArgs, 1);
  const unsigned int lRatio = lNewWidth/lImage.columns();
  lImage.zoom(Magick::Geometry(lNewWidth, lImage.rows()*lRatio));
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage);
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));

}

//*****************************************************************************


ZoomByHeightFunction::ZoomByHeightFunction(const ImageModule* aModule) : ImageFunction(aModule)
{
}

ItemSequence_t
ZoomByHeightFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{


  Magick::Image lImage;
  ImageFunction::getOneImageArg(aArgs, 0, lImage);
  const unsigned int lNewHeight = ImageFunction::getOneUnsignedIntArg(aArgs, 1);
  const unsigned int lRatio = lNewHeight / lImage.rows();
  lImage.zoom(Magick::Geometry(lImage.columns()*lRatio, lNewHeight));
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage);
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));

}

//*****************************************************************************


ZoomFunction::ZoomFunction(const ImageModule* aModule) : ImageFunction(aModule)
{
}


ItemSequence_t
ZoomFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{

  Magick::Image lImage;
  ImageFunction::getOneImageArg(aArgs, 0, lImage);
  const double lRatio = ImageFunction::getOneDoubleArg(aArgs, 1);
  lImage.zoom(Magick::Geometry(lImage.columns()*lRatio, lImage.rows()*lRatio));
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage);
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
}

//*****************************************************************************

SubImageFunction::SubImageFunction(const ImageModule* aModule) : ImageFunction(aModule)
{
}

ItemSequence_t
SubImageFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{

  Magick::Image lImage;
  ImageFunction::getOneImageArg(aArgs, 0, lImage);
  const unsigned int lLeftUpperX = ImageFunction::getOneUnsignedIntArg(aArgs, 1);
  const unsigned int lLeftUpperY = ImageFunction::getOneUnsignedIntArg(aArgs, 2);
  const unsigned int lWidth= ImageFunction::getOneUnsignedIntArg(aArgs, 3);
  const unsigned int lHeight = ImageFunction::getOneUnsignedIntArg(aArgs, 4);
  // chop away everything that is either left of lLeftUpperX or above lLeftUpperY
  lImage.chop(Magick::Geometry(lLeftUpperX, lLeftUpperY));
  // crop away everything that is either right of lRightLowerX or below lRightLowerY
  lImage.crop(Magick::Geometry(lWidth, lHeight));
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage);
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
}


//*****************************************************************************


OverlayFunction::OverlayFunction(const ImageModule* aModule) : ImageFunction(aModule)
{
}


ItemSequence_t
OverlayFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{

  Magick::Image lImage;
  Magick::Image lOverlayImage;
  ImageFunction::getOneImageArg(aArgs, 0, lImage);
  ImageFunction::getOneImageArg(aArgs, 1, lOverlayImage);
  const unsigned int lLeftUpperX = ImageFunction::getOneUnsignedIntArg(aArgs, 2);
  const unsigned int lLeftUpperY = ImageFunction::getOneUnsignedIntArg(aArgs, 3);
  String lOverlayOperator = ImageFunction::getOneStringArg(aArgs, 4);
  if (lOverlayOperator.equals("OverCompositeOp")) {
    lImage.composite(lOverlayImage, lLeftUpperX, lLeftUpperY, Magick::OverlayCompositeOp);
  } else if (lOverlayOperator.equals("InCompositeOp")) {
    lImage.composite(lOverlayImage, lLeftUpperX, lLeftUpperY, Magick::InCompositeOp);
  } else if (lOverlayOperator.equals("OutCompositeOp")) {
    lImage.composite(lOverlayImage, lLeftUpperX, lLeftUpperY, Magick::OutCompositeOp);
  } else if (lOverlayOperator.equals("AtopCompositeOp")) {
    lImage.composite(lOverlayImage, lLeftUpperX, lLeftUpperY, Magick::AtopCompositeOp);
  } else if (lOverlayOperator.equals("XorCompositeOp")) {
    lImage.composite(lOverlayImage, lLeftUpperX, lLeftUpperY, Magick::XorCompositeOp);
  } else if (lOverlayOperator.equals("PlusCompositeOp")) {
    lImage.composite(lOverlayImage, lLeftUpperX, lLeftUpperY, Magick::PlusCompositeOp);
  } else if (lOverlayOperator.equals("MinusCompositeOp")) {
    lImage.composite(lOverlayImage, lLeftUpperX, lLeftUpperY, Magick::MinusCompositeOp);
  } else if (lOverlayOperator.equals("AddCompositeOp")) {
    lImage.composite(lOverlayImage, lLeftUpperX, lLeftUpperY, Magick::AddCompositeOp);
  } else if (lOverlayOperator.equals("SubtractCompositeOp")) {
    lImage.composite(lOverlayImage, lLeftUpperX, lLeftUpperY, Magick::SubtractCompositeOp);
  } else if (lOverlayOperator.equals("DifferenceCompositeOp")) {
    lImage.composite(lOverlayImage, lLeftUpperX, lLeftUpperY, Magick::DifferenceCompositeOp);
  } else if (lOverlayOperator.equals("BumpmapCompositeOp")) {
    lImage.composite(lOverlayImage, lLeftUpperX, lLeftUpperY, Magick::BumpmapCompositeOp);
  } 
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage);
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
}

//*****************************************************************************

ChopFunction::ChopFunction(const ImageModule* aModule) : ImageFunction(aModule)
{
}


ItemSequence_t
ChopFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{

  Magick::Image lImage;
  ImageFunction::getOneImageArg(aArgs, 0, lImage);
  unsigned int lLeftUpperX = ImageFunction::getOneUnsignedIntArg(aArgs, 1);
  unsigned int lLeftUpperY = ImageFunction::getOneUnsignedIntArg(aArgs, 2);
  // chop away everything that is either left of lLeftUpperX or above lLeftUpperY
  lImage.chop(Magick::Geometry(lLeftUpperX, lLeftUpperY));
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage);
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
}

//*****************************************************************************

CropFunction::CropFunction(const ImageModule* aModule) : ImageFunction(aModule)
{
}

ItemSequence_t
CropFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{

  Magick::Image lImage;
  ImageFunction::getOneImageArg(aArgs, 0, lImage);
  unsigned int lRightLowerX = ImageFunction::getOneUnsignedIntArg(aArgs, 1);
  unsigned int lRightLowerY = ImageFunction::getOneUnsignedIntArg(aArgs, 2);
  // crop away everything that is either right of lRightLowerX or below lRightLowerY
  lImage.crop(Magick::Geometry(lRightLowerX, lRightLowerY));
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage);
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
}

//*****************************************************************************

RotateFunction::RotateFunction(const ImageModule* aModule) : ImageFunction(aModule)
{
}

ItemSequence_t
RotateFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  Magick::Image lImage;
  ImageFunction::getOneImageArg(aArgs, 0, lImage);
  int lAngle = ImageFunction::getOneIntArg(aArgs, 1);
  lImage.rotate(lAngle%360);
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage);
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
}

//*****************************************************************************

EraseFunction::EraseFunction(const ImageModule* aModule) : ImageFunction(aModule)
{
}

ItemSequence_t
EraseFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{

  Magick::Image lImage;
  ImageFunction::getOneImageArg(aArgs, 0, lImage);
  lImage.erase();
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage);
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
}

//*****************************************************************************

FlopFunction::FlopFunction(const ImageModule* aModule) : ImageFunction(aModule)
{
}

ItemSequence_t
FlopFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{

  Magick::Image lImage;
  ImageFunction::getOneImageArg(aArgs, 0, lImage);
  lImage.flop();
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage);
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
}

//*****************************************************************************

FlipFunction::FlipFunction(const ImageModule* aModule) : ImageFunction(aModule)
{
}

ItemSequence_t
FlipFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  Magick::Image lImage;
  ImageFunction::getOneImageArg(aArgs, 0, lImage);
  lImage.flip();
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage);
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
}

//*****************************************************************************

TrimFunction::TrimFunction(const ImageModule* aModule) : ImageFunction(aModule)
{
}

ItemSequence_t
TrimFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  Magick::Image lImage;
  ImageFunction::getOneImageArg(aArgs, 0, lImage);
  lImage.trim();
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage);
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
}

//*****************************************************************************

AddNoiseFunction::AddNoiseFunction(const ImageModule* aModule) : ImageFunction(aModule)
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
  ImageFunction::getOneImageArg(aArgs, 0, lImage);
  lNoiseType = ImageFunction::getOneStringArg(aArgs, 1);  

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
  } else {
    lImage.addNoise(Magick::UniformNoise);
  }     

  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage);
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
}

//*****************************************************************************

BlurFunction::BlurFunction(const ImageModule* aModule) : ImageFunction(aModule)
{
}


ItemSequence_t
BlurFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{

  Magick::Image lImage;
  ImageFunction::getOneImageArg(aArgs, 0, lImage);
  int  lRadius = ImageFunction::getOneIntArg(aArgs, 1);
  int  lSigma = ImageFunction::getOneIntArg(aArgs, 2);
  lImage.blur(lRadius, lSigma);
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage);
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());

  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
}

//*****************************************************************************


DespeckleFunction::DespeckleFunction(const ImageModule* aModule) : ImageFunction(aModule)
{
}

ItemSequence_t
DespeckleFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{

  Magick::Image lImage;
  ImageFunction::getOneImageArg(aArgs, 0, lImage);
  lImage.despeckle();
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage);
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
}

//*****************************************************************************

EnhanceFunction::EnhanceFunction(const ImageModule* aModule) : ImageFunction(aModule)
{
}

ItemSequence_t
EnhanceFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  Magick::Image lImage;
  ImageFunction::getOneImageArg(aArgs, 0, lImage);
  lImage.enhance();
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage);
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
}

//*****************************************************************************

EqualizeFunction::EqualizeFunction(const ImageModule* aModule) : ImageFunction(aModule)
{
}

ItemSequence_t
EqualizeFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{

  Magick::Image lImage;
  ImageFunction::getOneImageArg(aArgs, 0, lImage);
  lImage.equalize();
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage);
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
}

//*****************************************************************************

EdgeFunction::EdgeFunction(const ImageModule* aModule) : ImageFunction(aModule)
{
}

ItemSequence_t
EdgeFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{

  Magick::Image lImage;
  ImageFunction::getOneImageArg(aArgs, 0, lImage);
  Item lItem;   
  // check if second argument was given
  lImage.edge(ImageFunction::getOneUnsignedIntArg(aArgs,1));
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage);
  lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
}

//*****************************************************************************

CharcoalFunction::CharcoalFunction(const ImageModule* aModule) : ImageFunction(aModule)
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
  ImageFunction::getOneImageArg(aArgs, 0, lImage);
  lImage.charcoal(lRadius, lSigma);
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage);
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
}


//*****************************************************************************

EmbossFunction::EmbossFunction(const ImageModule* aModule) : ImageFunction(aModule)
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
  ImageFunction::getOneImageArg(aArgs, 0, lImage);
  lImage.emboss(lRadius, lSigma);
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage);
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
}


//*****************************************************************************

SolarizeFunction::SolarizeFunction(const ImageModule* aModule) : ImageFunction(aModule)
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
  ImageFunction::getOneImageArg(aArgs, 0, lImage);
  lImage.solarize(lFactor);
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage);
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
}


//*****************************************************************************

StereoFunction::StereoFunction(const ImageModule* aModule) : ImageFunction(aModule)
{
}

ItemSequence_t
StereoFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{

  Magick::Image lFirstImage;
  ImageFunction::getOneImageArg(aArgs, 0, lFirstImage);
  Magick::Image lSecondImage;
  ImageFunction::getOneImageArg(aArgs, 1, lSecondImage);
  if (lFirstImage.size() != lSecondImage.size()) {
    lSecondImage.size(lFirstImage.size());      
  }
  lFirstImage.stereo(lSecondImage);
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lFirstImage);
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
}

//*****************************************************************************

TransparentFunction::TransparentFunction(const ImageModule* aModule) : ImageFunction(aModule)
{
}

ItemSequence_t
TransparentFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{

  Magick::Image lImage;
  Magick::ColorRGB lColor;
  ImageFunction::getOneImageArg(aArgs, 0, lImage);
  Item lItem; 
  aArgs[1]->next(lItem);
  String lTmpString = lItem.getStringValue();
  int lRed = 0;
  int lGreen = 0;
  int lBlue = 0;
  sscanf(lTmpString.substring(1,2).c_str(), "%x", &lRed);
  sscanf(lTmpString.substring(3,2).c_str(), "%x", &lGreen);
  sscanf(lTmpString.substring(5,2).c_str(), "%x", &lBlue);
  lImage.transparent(Magick::ColorRGB((double)lRed/255.0, (double)lGreen/255.0, (double)lBlue/255.0));
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage);
  lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
}

//*****************************************************************************

SwirlFunction::SwirlFunction(const ImageModule* aModule) : ImageFunction(aModule)
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
  ImageFunction::getOneImageArg(aArgs, 0, lImage);
  lImage.swirl(lDegrees);
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage);
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
}

//*****************************************************************************

ReduceNoiseFunction::ReduceNoiseFunction(const ImageModule* aModule) : ImageFunction(aModule)
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
  ImageFunction::getOneImageArg(aArgs, 0, lImage);
  lImage.reduceNoise(lOrder);
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage);
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
}


//*****************************************************************************

ContrastFunction::ContrastFunction(const ImageModule* aModule) : ImageFunction(aModule)
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
  ImageFunction::getOneImageArg(aArgs, 0, lImage);
  lImage.contrast(lSharpen);
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage);
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
}


//*****************************************************************************

GammaFunction::GammaFunction(const ImageModule* aModule) : ImageFunction(aModule)
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
  ImageFunction::getOneImageArg(aArgs, 0, lImage);
  // check if the one gamma value version was called or the version with seperate values for r g and b. Doing this by looking if the 3. argument exists.
  if (aArgs.size() > 2) {
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

ImplodeFunction::ImplodeFunction(const ImageModule* aModule) : ImageFunction(aModule)
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
  ImageFunction::getOneImageArg(aArgs, 0, lImage);
  lImage.implode(lFactor);
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage);
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
}


//*****************************************************************************

OilPaintFunction::OilPaintFunction(const ImageModule* aModule) : ImageFunction(aModule)
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
  ImageFunction::getOneImageArg(aArgs, 0, lImage);
  lImage.oilPaint(lRadius);
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage);
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
}


//*****************************************************************************

WaterMarkFunction::WaterMarkFunction(const ImageModule* aModule) : ImageFunction(aModule)
{
}

ItemSequence_t
WaterMarkFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{

  Magick::Image lImage, lWatermark;
  ImageFunction::getOneImageArg(aArgs, 0, lImage);
  ImageFunction::getOneImageArg(aArgs, 1, lImage);
  lImage.stegano(lWatermark);
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
