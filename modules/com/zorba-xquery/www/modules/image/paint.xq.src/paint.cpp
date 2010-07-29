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

#include "paint.h"
#include <list> 
#include <sstream>
#include <string>
#include <zorba/empty_sequence.h>
#include <zorba/singleton_item_sequence.h>
#include <zorba/zorba.h>
#include "paint_module.h"



namespace zorba {  namespace imagemodule { namespace paintmodule {

using namespace zorba::imagemodule;  



//*****************************************************************************

DrawPolyLineFunction::DrawPolyLineFunction(const ImageModule* aModule) : ImageFunction(aModule)
{
}

ItemSequence_t
DrawPolyLineFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{

  Magick::Image lImage;
  ImageFunction::getOneImageArg(aArgs, 0, lImage);
  std::list<Magick::Coordinate> lCoordinatesList;
  ImageFunction::getCoordinatesArgs(aArgs, 1, 2, lCoordinatesList); 
  
  std::list<Magick::Drawable> lPolyLine;

  // get background color, if none is passed then set background to be opaque.
  double lStrokeWidth = ImageFunction::getStrokeWidthArg(aArgs, 5);
  lPolyLine.push_back(Magick::DrawableStrokeWidth(lStrokeWidth)); 
  bool lAntiAlias = ImageFunction::getAntiAliasingArg(aArgs, 6);
  ImageFunction::setStrokeColor(aArgs, 3, lPolyLine);
  ImageFunction::setOpaqueOrFill(aArgs, 4, lPolyLine);


  lPolyLine.push_back(Magick::DrawableStrokeAntialias(lAntiAlias));
  // push the coordinates into the drawable list (if not, they don't get painted ...)
  lPolyLine.push_back(Magick::DrawablePolyline(lCoordinatesList));
  lPolyLine.push_back(Magick::DrawableFillColor(lImage.backgroundColor()));
  lImage.draw(lPolyLine);
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage);
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
}


//*****************************************************************************

DrawStrokedPolyLineFunction::DrawStrokedPolyLineFunction(const ImageModule* aModule) : ImageFunction(aModule)
{
}

ItemSequence_t
DrawStrokedPolyLineFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{

  Magick::Image lImage;
  ImageFunction::getOneImageArg(aArgs, 0, lImage);
  std::list<Magick::Coordinate> lCoordinatesList;
  ImageFunction::getCoordinatesArgs(aArgs, 1, 2, lCoordinatesList);

  std::list<Magick::Drawable> lPolyLine;
  // get stroke length and push it into poly-line
  double lStrokeLength = ImageFunction::getOneDoubleArg(aArgs, 3);
  double lGapLength = ImageFunction::getOneDoubleArg(aArgs, 4);
  double lPattern[] = {lStrokeLength, lGapLength, 0};
  lPolyLine.push_back(Magick::DrawableDashArray(lPattern));
  // check if a color was passed, if true, then set the stroke color  
  ImageFunction::setStrokeColor(aArgs, 5, lPolyLine);

  
  double lStrokeWidth = ImageFunction::getStrokeWidthArg(aArgs, 6);
  lPolyLine.push_back(Magick::DrawableStrokeWidth(lStrokeWidth));
  bool lAntiAlias = ImageFunction::getAntiAliasingArg(aArgs, 7);
  lPolyLine.push_back(Magick::DrawableStrokeAntialias(lAntiAlias));
  // push the coordinates into the drawable list (if not, they don't get painted ...)
  lPolyLine.push_back(Magick::DrawablePolyline(lCoordinatesList));
  lPolyLine.push_back(Magick::DrawableFillOpacity(0.0));
  lImage.draw(lPolyLine);
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage);
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
}

//*****************************************************************************

DrawRectangleFunction::DrawRectangleFunction(const ImageModule* aModule) : ImageFunction(aModule)
{
}


ItemSequence_t
DrawRectangleFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{

  Magick::Image lImage;
  ImageFunction::getOneImageArg(aArgs, 0, lImage);
  double lUpperLeftX = ImageFunction::getOneDoubleArg(aArgs, 1);
  double lUpperLeftY = ImageFunction::getOneDoubleArg(aArgs, 2);
  double lLowerRightX = ImageFunction::getOneDoubleArg(aArgs, 3);
  double lLowerRightY = ImageFunction::getOneDoubleArg(aArgs, 4);    


  std::list<Magick::Drawable> lDrawable;
  // get stroke length and push it into poly-line
  ImageFunction::setStrokeColor(aArgs, 5, lDrawable);
  ImageFunction::setOpaqueOrFill(aArgs, 6, lDrawable);
  double lStrokeWidth = ImageFunction::getStrokeWidthArg(aArgs, 7);
  lDrawable.push_back(Magick::DrawableStrokeWidth(lStrokeWidth));
  bool lAntiAlias = ImageFunction::getAntiAliasingArg(aArgs, 8);
  lDrawable.push_back(Magick::DrawableStrokeAntialias(lAntiAlias));
  lDrawable.push_back(Magick::DrawableRectangle(lUpperLeftX, lUpperLeftY, lLowerRightX, lLowerRightY));
  lImage.draw(lDrawable);
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage);
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
}

//*****************************************************************************

DrawRoundedRectangleFunction::DrawRoundedRectangleFunction(const ImageModule* aModule) : ImageFunction(aModule)
{
}

ItemSequence_t
DrawRoundedRectangleFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{

  Magick::Image lImage;
  ImageFunction::getOneImageArg(aArgs, 0, lImage);
  double lUpperLeftX = ImageFunction::getOneDoubleArg(aArgs, 1);
  double lUpperLeftY = ImageFunction::getOneDoubleArg(aArgs, 2);
  double lLowerRightX = ImageFunction::getOneDoubleArg(aArgs, 3);
  double lLowerRightY = ImageFunction::getOneDoubleArg(aArgs, 4);
  double lCornderWidth = ImageFunction::getOneDoubleArg(aArgs, 5);
  double lCornerHeight = ImageFunction::getOneDoubleArg(aArgs, 6);

  std::list<Magick::Drawable> lDrawable;
  // get stroke length and push it into poly-line
  ImageFunction::setStrokeColor(aArgs, 7, lDrawable);
  ImageFunction::setOpaqueOrFill(aArgs, 8, lDrawable);
  double lStrokeWidth = ImageFunction::getStrokeWidthArg(aArgs, 9);
  lDrawable.push_back(Magick::DrawableStrokeWidth(lStrokeWidth));
  bool lAntiAlias = ImageFunction::getAntiAliasingArg(aArgs, 10);
  lDrawable.push_back(Magick::DrawableStrokeAntialias(lAntiAlias));
  lDrawable.push_back(Magick::DrawableRoundRectangle(lUpperLeftX, lUpperLeftY, lLowerRightX, lLowerRightY, lCornderWidth, lCornerHeight));
  lImage.draw(lDrawable);
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage);
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
}

//*****************************************************************************

DrawArcFunction::DrawArcFunction(const ImageModule* aModule) : ImageFunction(aModule)
{
}

ItemSequence_t
DrawArcFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{

  Magick::Image lImage;
  ImageFunction::getOneImageArg(aArgs, 0, lImage);
  double lXCoordinate = ImageFunction::getOneDoubleArg(aArgs, 1);
  double lYCoordinate = ImageFunction::getOneDoubleArg(aArgs, 2);
  double lPerimeterX = ImageFunction::getOneDoubleArg(aArgs, 3);
  double lPerimeterY = ImageFunction::getOneDoubleArg(aArgs, 4);
  double lStartDegrees = ImageFunction::getOneDoubleArg(aArgs, 5);
  double lEndDegrees = ImageFunction::getOneDoubleArg(aArgs, 6);
  std::list<Magick::Drawable> lDrawable;
  // get stroke length and push it into poly-line
  ImageFunction::setStrokeColor(aArgs, 7, lDrawable);
  ImageFunction::setOpaqueOrFill(aArgs, 8, lDrawable);
  double lStrokeWidth = ImageFunction::getStrokeWidthArg(aArgs, 9);
  lDrawable.push_back(Magick::DrawableStrokeWidth(lStrokeWidth));
  bool lAntiAlias = ImageFunction::getAntiAliasingArg(aArgs, 10);
  lDrawable.push_back(Magick::DrawableStrokeAntialias(lAntiAlias));
  lDrawable.push_back(Magick::DrawableEllipse(lXCoordinate, lYCoordinate, lPerimeterX, lPerimeterY, lStartDegrees, lEndDegrees));
  lImage.draw(lDrawable);
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage);
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
}

//*****************************************************************************

DrawPolygonFunction::DrawPolygonFunction(const ImageModule* aModule) : ImageFunction(aModule)
{
}

ItemSequence_t
DrawPolygonFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{

  Magick::Image lImage;
  ImageFunction::getOneImageArg(aArgs, 0, lImage);
  std::list<Magick::Coordinate> lCoordinatesList;
  ImageFunction::getCoordinatesArgs(aArgs, 1, 2, lCoordinatesList);

  std::list<Magick::Drawable> lPolyLine;

  // check if a color was passed, if true, then set the stroke color  
  ImageFunction::setStrokeColor(aArgs, 3, lPolyLine);
  // get background color, if none is passed then set background to be opaque.
  ImageFunction::setOpaqueOrFill(aArgs, 4, lPolyLine);
  double lStrokeWidth = ImageFunction::getStrokeWidthArg(aArgs, 5);
  lPolyLine.push_back(Magick::DrawableStrokeWidth(lStrokeWidth));
  bool lAntiAlias = ImageFunction::getAntiAliasingArg(aArgs, 6);
  lPolyLine.push_back(Magick::DrawableStrokeAntialias(lAntiAlias));
  // push the coordinates into the drawable list (if not, they don't get painted ...)
  lPolyLine.push_back(Magick::DrawablePolygon(lCoordinatesList));
  lPolyLine.push_back(Magick::DrawableFillColor(lImage.backgroundColor()));
  lImage.draw(lPolyLine);
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage);
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
}


//*****************************************************************************

DrawTextFunction::DrawTextFunction(const ImageModule* aModule) : ImageFunction(aModule)
{
}

ItemSequence_t
DrawTextFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{

  Magick::Image lImage;
  ImageFunction::getOneImageArg(aArgs, 0, lImage);
  String lText = ImageFunction::getOneStringArg(aArgs, 1);
  double lXCoordinate = ImageFunction::getOneDoubleArg(aArgs, 2);
  double lYCoordinate = ImageFunction::getOneDoubleArg(aArgs, 3); 
  String lFontFamily = ImageFunction::getOneStringArg(aArgs, 4);
  

  double lFontSize = 12;
  int lFontWeight = 400;
  Magick::StyleType lFontStyle = Magick::NormalStyle;
  // get values that are possibly just an empty sequence
  
  Item lItem;
  if (aArgs[5]->next(lItem)) {
    lFontSize = lItem.getDoubleValue();
  }
  if (aArgs[6]->next(lItem)) {
    lFontWeight = lItem.getIntValue();
  }
  if (aArgs[7]->next(lItem)) {
    String lTemp = lItem.getStringValue();
    if (lTemp.equals("Italic")) {
      lFontStyle = Magick::ItalicStyle;
    } else if (lTemp.equals("Oblique")) {
      lFontStyle = Magick::ObliqueStyle;
    }
  }
  
  int lRed = 0;
  int lGreen = 0;
  int lBlue = 0;

  if (aArgs[8]->next(lItem)) {
    String lTmpString = lItem.getStringValue();
    sscanf(lTmpString.substring(1,2).c_str(), "%x", &lRed);
    sscanf(lTmpString.substring(3,2).c_str(), "%x", &lGreen);
    sscanf(lTmpString.substring(5,2).c_str(), "%x", &lBlue);
  }

  
  // push all values into a drawable
  std::list<Magick::Drawable> lDrawable;
  lDrawable.push_back(Magick::DrawableStrokeColor(Magick::ColorRGB((double)lRed/255.0, (double)lGreen/255.0, (double)lBlue/255.0)));
  lDrawable.push_back(Magick::DrawableFillColor(Magick::ColorRGB((double)lRed/255.0, (double)lGreen/255.0, (double)lBlue/255.0)));
  lDrawable.push_back(Magick::DrawableFont(lFontFamily.c_str(), lFontStyle, lFontWeight, Magick::NormalStretch));
  lDrawable.push_back(Magick::DrawableText(lXCoordinate, lYCoordinate, lText.c_str()));
  lDrawable.push_back(Magick::DrawablePointSize(lFontSize));  
  lImage.draw(lDrawable);
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage);
  lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
}








} /* namespace paintmodule */  } /* namespace imagemodule */ }  /* namespace zorba */


#ifdef WIN32
#  define DLL_EXPORT __declspec(dllexport)
#else
#  define DLL_EXPORT __attribute__ ((visibility("default")))
#endif

extern "C" DLL_EXPORT zorba::ExternalModule* createModule() {
  return new zorba::imagemodule::paintmodule::PaintModule();
}



