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
#include <iostream>
#include <zorba/empty_sequence.h>
#include <zorba/singleton_item_sequence.h>
#include <zorba/zorba.h>
#include "paint_module.h"
#include "draw_in_c.h"
#include <cstring>

namespace zorba {  namespace imagemodule { namespace paintmodule {

using namespace zorba::imagemodule;  


//*****************************************************************************

PaintImplFunction::PaintImplFunction(const ImageModule* aModule) : ImageFunction(aModule)
{
}

ItemSequence_t
PaintImplFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const 
{

  Magick::Blob lBlob;
  Magick::Image lImage;
  // this may be a little slower then getting the blob directly, but it ensures the correct use of the error handling facility.
  ImageFunction::getOneImageArg(aDynCtx, aArgs, 0, lImage);
  lImage.write(&lBlob);

  Item lNextPaint;
  while (aArgs[1]->next(lNextPaint)) {
    applyShape(lBlob, lNextPaint);
  }

  // pass the blob back as base64Binary ...
  String lEncodedContent = ImageFunction::getEncodedStringFromBlob(lBlob);
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));

}

bool
PaintImplFunction::getCommonValues(Iterator_t& aChildIterator, 
                                   Item& aLastItemFound, 
                                   double* aStrokeWidth, 
                                   std::string& aStrokeColor, 
                                   std::string& aFillColor) const {
  
  bool lFoundStrokeWidth = false;
  bool lFoundStrokeColor = false;
  bool lFoundFillColor = false;
  // fill in default values
  *aStrokeWidth = 1;
  aStrokeColor = "#000000";
  aFillColor = "#FFFFFF";
  bool lAntiAliasing = false;
   
  aChildIterator->next(aLastItemFound);
  // we just check through the first four elements
  for (int i = 0; i < 4; ++i) {
    Item lNodeName; 
    aLastItemFound.getNodeName(lNodeName);
    String lName = lNodeName.getStringValue(); 
    
    if (!lFoundStrokeWidth && lName.endsWith("Width")) {
      *aStrokeWidth = getDoubleValue(aLastItemFound); 
      lFoundStrokeWidth = true;
      aChildIterator->next(aLastItemFound);
    } else if (!lFoundStrokeColor && lName.endsWith("eColor")) {
      aStrokeColor = aLastItemFound.getStringValue().c_str();
      lFoundStrokeColor = true;
      aChildIterator->next(aLastItemFound);
      if (i < 1) { i = 1; }
    } else if (!lFoundFillColor && lName.endsWith("Color")) {
      aFillColor = aLastItemFound.getStringValue().c_str();
      lFoundFillColor = true;
      aChildIterator->next(aLastItemFound);
      if (i < 2) { i = 2; }
    } else if (lName.endsWith("ing")) {
      String lAntiAliasingString = aLastItemFound.getStringValue();
      if (lAntiAliasingString.endsWith("ue")) {
        lAntiAliasing = true;
      } else {
        lAntiAliasing = false;
      }  
      
      // iterate to next and break
      aChildIterator->next(aLastItemFound); 
      break;
    }  
    
  }  
  return lAntiAliasing;
}  


void
PaintImplFunction::applyShape(Magick::Blob& aBlob, Item& aShape) const {
    Item lNodeName;
    aShape.getNodeName(lNodeName);
    String lName = lNodeName.getStringValue();
    // removing the uri prefix
    if (lName.endsWith("line")) {
      applyLine(aBlob, aShape);
    } else if (lName.endsWith("dPolyLine")) {
      applyStrokedPolyLine(aBlob, aShape);
    }  else if (lName.endsWith("Line")) {
      applyPolyLine(aBlob, aShape);
    } else if (lName.endsWith("rectangle")) {
      applyRectangle(aBlob, aShape);
    } else if (lName.endsWith("gle")) {
      applyRoundedRectangle(aBlob, aShape);
    } else if (lName.endsWith("cle")) {
      applyCircle(aBlob, aShape);
    } else if (lName.endsWith("se")) {
      applyEllipse(aBlob, aShape);
    } else if (lName.endsWith("c")) {
      applyArc(aBlob, aShape);
    } else if (lName.endsWith("n")) {
      applyPolygon(aBlob, aShape);
    } else if (lName.endsWith("t")) {
      applyText(aBlob, aShape);
    }  
}


double
PaintImplFunction::getDoubleValue(Item& aDoubleItem) const{
  std::stringstream lConverter;
  lConverter << aDoubleItem.getStringValue().c_str();
  double lResult;
  lConverter >> lResult;
  return lResult; 

}

void
PaintImplFunction::getDoublesFromPoint(Item& aPoint, double aPointValues[2]) const {
  Item lXItem, lYItem, lX, lY;

  Iterator_t lPointChildren = aPoint.getChildren();
  lPointChildren->open(); 
  lPointChildren->next(lXItem);
  Iterator_t lXItemIterator = lXItem.getChildren();
  lXItemIterator->open();
  lXItemIterator->next(lX);
  lXItemIterator->close();

  lPointChildren->next(lYItem);
  Iterator_t lYItemIterator = lYItem.getChildren();
  lYItemIterator->open();
  lYItemIterator->next(lY);
  lYItemIterator->close();
  lPointChildren->close();
  
  aPointValues[0] = getDoubleValue(lX);
  aPointValues[1] = getDoubleValue(lY);
   
}


void 
PaintImplFunction::applyLine(Magick::Blob& aBlob, Item& aLine) const {
  Item lStartPoint, lEndPoint;
  Iterator_t lChildren = aLine.getChildren();
  lChildren->open();
  double lStrokeWidth = 0;
  std::string lStrokeColor = "";
  std::string lFillColor = "";
  bool lAntiAliasing; 
  // lStartPoint will contain the item of the start point after this operation
  lAntiAliasing = getCommonValues(lChildren, lStartPoint, &lStrokeWidth, lStrokeColor, lFillColor); 
  
  lChildren->next(lEndPoint);
  lChildren->close(); 

  double lFirst[2];
  double lSecond[2];
  getDoublesFromPoint(lStartPoint, lFirst);
  getDoublesFromPoint(lEndPoint, lSecond);
  double lXValues[2] = {lFirst[0], lSecond[0]};
  double lYValues[2] = {lFirst[1], lSecond[1]};

  long lBlobLength = (long) aBlob.length();
  void * lBlobPointer = DrawPolyLine(aBlob.data(), &lBlobLength, &lXValues[0], &lYValues[0], 2, lStrokeColor, lStrokeWidth, lAntiAliasing, NULL, 0);
  Magick::Blob lBlobWithPolyLine(lBlobPointer, lBlobLength);
  // now read the blob back into an image to pass it back as encoded string 
  aBlob = lBlobWithPolyLine; 
}  

void
PaintImplFunction::applyPolyLine(Magick::Blob& aBlob, Item& aLine) const {
  Item lFirstPoint;
  Iterator_t lChildren = aLine.getChildren();
  lChildren->open();
  double lStrokeWidth = 0; 
  std::string lStrokeColor = "";
  std::string lFillColor = "";
  bool lAntiAliasing;

  lAntiAliasing = getCommonValues(lChildren, lFirstPoint, &lStrokeWidth, lStrokeColor, lFillColor);
 
  std::vector<double> lXValues;
  std::vector<double> lYValues;

  double lFirst[2];
  getDoublesFromPoint(lFirstPoint, lFirst);
  lXValues.push_back(lFirst[0]);
  lYValues.push_back(lFirst[1]);
  Item lPoint;
  int lCounter = 1;
  while(lChildren->next(lPoint)) {
    lCounter++;
    double lPointValues[2];
    getDoublesFromPoint(lPoint, lPointValues);
    lXValues.push_back(lPointValues[0]);
    lYValues.push_back(lPointValues[1]);
  }
  lChildren->close();
  
  long lBlobLength = (long) aBlob.length();
  double* lXValuesArray = new double[lCounter];
  double* lYValuesArray = new double[lCounter];
  std::memcpy(lXValuesArray, &lXValues[0], lCounter*sizeof(lXValues[0]));
  std::memcpy(lYValuesArray, &lYValues[0], lCounter*sizeof(lYValues[0]));
    
  void * lBlobPointer = DrawPolyLine(aBlob.data(), &lBlobLength, &lXValuesArray[0], &lYValuesArray[0], lCounter, lStrokeColor, lStrokeWidth, lAntiAliasing, NULL, 0);
  
  delete[] lXValuesArray;
  delete[] lYValuesArray;
  
  Magick::Blob lBlobWithPolyLine(lBlobPointer, lBlobLength);
  // now read the blob back into an image to pass it back as encoded string 
  aBlob = lBlobWithPolyLine;
 

}

void
PaintImplFunction::applyStrokedPolyLine(Magick::Blob& aBlob, Item& aLine) const {
  Item lFirstPoint;
  Iterator_t lChildren = aLine.getChildren();
  lChildren->open();
  double lStrokeWidth = 0; 
  std::string lStrokeColor = "";
  std::string lFillColor = "";
  bool lAntiAliasing;
  lAntiAliasing = getCommonValues(lChildren, lFirstPoint, &lStrokeWidth, lStrokeColor, lFillColor);
  std::vector<double> lXValues;
  std::vector<double> lYValues;

  double lFirst[2];
  getDoublesFromPoint(lFirstPoint, lFirst);
  lXValues.push_back(lFirst[0]);
  lYValues.push_back(lFirst[1]);
  Item lPoint;
  int lCounter = 1;
  while(lChildren->next(lPoint)) {
    // make sure that we aren't reading in the gap length as point
    if (lCounter >= 3) {
      Item lNodeName;
      aLine.getNodeName(lNodeName);
      String lName = lNodeName.getStringValue();
      if (!lName.endsWith("oint")) {
        break;
      }  
    }  
    lCounter++;
    double lPointValues[2];
    getDoublesFromPoint(lPoint, lPointValues);
    lXValues.push_back(lPointValues[0]);
    lYValues.push_back(lPointValues[1]);
  }
  // lPoint now contains the strokeLength
  double lStrokeArray[2];
  lStrokeArray[0] = getDoubleValue(lPoint); 
  lChildren->next(lPoint);
  lStrokeArray[1] = getDoubleValue(lPoint); 
  lChildren->close();

  long lBlobLength = (long) aBlob.length();
  
  double* lXValuesArray = new double[lCounter];
  double* lYValuesArray = new double[lCounter];
  memcpy(lXValuesArray, &lXValues[0], lCounter*sizeof(lXValues[0]));
  memcpy(lYValuesArray, &lYValues[0], lCounter*sizeof(lYValues[0]));
  
  void * lBlobPointer = DrawPolyLine(aBlob.data(), &lBlobLength, &lXValuesArray[0], &lYValuesArray[0], lCounter, lStrokeColor, lStrokeWidth, lAntiAliasing, lStrokeArray, 2);
  
  delete[] lXValuesArray;
  delete[] lYValuesArray;
  
  Magick::Blob lBlobWithPolyLine(lBlobPointer, lBlobLength);
  // now read the blob back into an image to pass it back as encoded string 
  aBlob = lBlobWithPolyLine;

}

void              
PaintImplFunction::applyRectangle(Magick::Blob& aBlob, Item& aRectangle) const {
  Item lFirstPoint;
  Iterator_t lChildren = aRectangle.getChildren();
  lChildren->open();
  double lStrokeWidth = 0; 
  std::string lStrokeColor = "";
  std::string lFillColor = "";
  bool lAntiAliasing;
  lAntiAliasing = getCommonValues(lChildren, lFirstPoint, &lStrokeWidth, lStrokeColor, lFillColor);
  // now lFirstPoint contains the upper left corner of this rectangle
  double lUpperLeft[2];
  getDoublesFromPoint(lFirstPoint, lUpperLeft);
  lChildren->next(lFirstPoint);
  lChildren->close();
  double lLowerRight[2];
  getDoublesFromPoint(lFirstPoint, lLowerRight);
  long lBlobLength = (long) aBlob.length();
  void * lBlobPointer = DrawRoundedRect(aBlob.data(), &lBlobLength, lUpperLeft[0], lUpperLeft[1], lLowerRight[0], lLowerRight[1], 0, 0, lStrokeColor, lFillColor, lStrokeWidth, lAntiAliasing);
  Magick::Blob lBlobWithPolyLine(lBlobPointer, lBlobLength);
  // now read the blob back into an image to pass it back as encoded string 
  aBlob = lBlobWithPolyLine;

}

void              
PaintImplFunction::applyRoundedRectangle(Magick::Blob& aBlob, Item& aRectangle) const {
  Item lFirstPoint;
  Iterator_t lChildren = aRectangle.getChildren();
  lChildren->open();
  double lStrokeWidth = 0; 
  std::string lStrokeColor = "";
  std::string lFillColor = "";
  bool lAntiAliasing;
  lAntiAliasing = getCommonValues(lChildren, lFirstPoint, &lStrokeWidth, lStrokeColor, lFillColor);
  // now lFirstPoint contains the upper left corner of this rectangle
  double lUpperLeft[2];
  getDoublesFromPoint(lFirstPoint, lUpperLeft);
  lChildren->next(lFirstPoint);
  double lLowerRight[2];
  getDoublesFromPoint(lFirstPoint, lLowerRight);
  Item lCorner;
  lChildren->next(lCorner);
  double lCornerWidth = getDoubleValue(lCorner);
  lChildren->next(lCorner);
  double lCornerHeight = getDoubleValue(lCorner);
  
  long lBlobLength = (long) aBlob.length();
  void * lBlobPointer = DrawRoundedRect(aBlob.data(), &lBlobLength, lUpperLeft[0], lUpperLeft[1], lLowerRight[0], lLowerRight[1], lCornerWidth, lCornerHeight, lStrokeColor, lFillColor, lStrokeWidth, lAntiAliasing);
  Magick::Blob lBlobWithPolyLine(lBlobPointer, lBlobLength);
  // now read the blob back into an image to pass it back as encoded string 
  aBlob = lBlobWithPolyLine;

}

void              
PaintImplFunction::applyCircle(Magick::Blob& aBlob, Item& aCircle) const {
  Item lFirstPoint;
  Iterator_t lChildren = aCircle.getChildren();
  lChildren->open();
  double lStrokeWidth = 0; 
  std::string lStrokeColor = "";
  std::string lFillColor = "";
  bool lAntiAliasing;
  lAntiAliasing = getCommonValues(lChildren, lFirstPoint, &lStrokeWidth, lStrokeColor, lFillColor);
 
  double lOriginCoordinates[2];
  getDoublesFromPoint(lFirstPoint, lOriginCoordinates);
  Item lPeremeterItem;
  lChildren->next(lPeremeterItem);
  double lPeremeter = getDoubleValue(lPeremeterItem); 
  lChildren->close();
  Magick::Image lImage(aBlob);
  lImage.strokeAntiAlias(lAntiAliasing);
  lImage.strokeWidth(lStrokeWidth);
  Magick::ColorRGB lStrokeColorForMagick;
  Magick::ColorRGB lFillColorForMagick;
  ImageFunction::getColorFromString(lStrokeColor.c_str(), lStrokeColorForMagick);
  ImageFunction::getColorFromString(lFillColor.c_str(), lFillColorForMagick);
  lImage.strokeColor(lStrokeColorForMagick);
  lImage.fillColor(lFillColorForMagick);
  lImage.draw(Magick::DrawableEllipse(lOriginCoordinates[0], lOriginCoordinates[1], lPeremeter, lPeremeter, 0, 360));
  Magick::Blob lBlob;
  lImage.write(&lBlob);
  aBlob = lBlob;

}

void              
PaintImplFunction::applyEllipse(Magick::Blob& aBlob, Item& aCircle) const {
  Item lFirstPoint;
  Iterator_t lChildren = aCircle.getChildren();
  lChildren->open();
  double lStrokeWidth = 0; 
  std::string lStrokeColor = "";
  std::string lFillColor = "";
  bool lAntiAliasing;
  lAntiAliasing = getCommonValues(lChildren, lFirstPoint, &lStrokeWidth, lStrokeColor, lFillColor);
 
  double lOriginCoordinates[2];
  getDoublesFromPoint(lFirstPoint, lOriginCoordinates);
  Item lPeremeterItem;
  lChildren->next(lPeremeterItem);
  double lPeremeterX = getDoubleValue(lPeremeterItem);
  lChildren->next(lPeremeterItem);
  double lPeremeterY = getDoubleValue(lPeremeterItem);
  lChildren->close();
  Magick::Image lImage(aBlob);
  lImage.strokeAntiAlias(lAntiAliasing);
  lImage.strokeWidth(lStrokeWidth);
  Magick::ColorRGB lStrokeColorForMagick;
  Magick::ColorRGB lFillColorForMagick;
  ImageFunction::getColorFromString(lStrokeColor.c_str(), lStrokeColorForMagick);
  ImageFunction::getColorFromString(lFillColor.c_str(), lFillColorForMagick);
  lImage.strokeColor(lStrokeColorForMagick);
  lImage.fillColor(lFillColorForMagick);
  lImage.draw(Magick::DrawableEllipse(lOriginCoordinates[0], lOriginCoordinates[1], lPeremeterX, lPeremeterY, 0, 360));
  Magick::Blob lBlob;
  lImage.write(&lBlob);
  aBlob = lBlob;
}

void              
PaintImplFunction::applyArc(Magick::Blob& aBlob, Item& aCircle) const {
  Item lFirstPoint;
  Iterator_t lChildren = aCircle.getChildren();
  lChildren->open();
  double lStrokeWidth = 0; 
  std::string lStrokeColor = "";
  std::string lFillColor = "";
  bool lAntiAliasing;
  lAntiAliasing = getCommonValues(lChildren, lFirstPoint, &lStrokeWidth, lStrokeColor, lFillColor);
 
  double lOriginCoordinates[2];
  getDoublesFromPoint(lFirstPoint, lOriginCoordinates);
  Item lPeremeterItem;
  lChildren->next(lPeremeterItem);
  double lPeremeterX = getDoubleValue(lPeremeterItem);
  lChildren->next(lPeremeterItem);
  double lPeremeterY = getDoubleValue(lPeremeterItem);
  Item lDegreesItem;
  lChildren->next(lDegreesItem);
  double lStartDegrees = getDoubleValue(lDegreesItem);
  lChildren->next(lDegreesItem);
  double lEndDegrees = getDoubleValue(lDegreesItem);
  
  lChildren->close();
  Magick::Image lImage(aBlob);
  lImage.strokeAntiAlias(lAntiAliasing);
  lImage.strokeWidth(lStrokeWidth);
  Magick::ColorRGB lStrokeColorForMagick;
  Magick::ColorRGB lFillColorForMagick;
  ImageFunction::getColorFromString(lStrokeColor.c_str(), lStrokeColorForMagick);
  ImageFunction::getColorFromString(lFillColor.c_str(), lFillColorForMagick);
  lImage.strokeColor(lStrokeColorForMagick);
  lImage.fillColor(lFillColorForMagick);
  lImage.draw(Magick::DrawableEllipse(lOriginCoordinates[0], lOriginCoordinates[1], lPeremeterX, lPeremeterY, lStartDegrees, lEndDegrees));
  Magick::Blob lBlob;
  lImage.write(&lBlob);
  aBlob = lBlob;
}


void              
PaintImplFunction::applyPolygon(Magick::Blob& aBlob, Item& aLine) const {
  Item lFirstPoint;
  Iterator_t lChildren = aLine.getChildren();
  lChildren->open();
  double lStrokeWidth = 0; 
  std::string lStrokeColor = "";
  std::string lFillColor = "";
  bool lAntiAliasing;

  lAntiAliasing = getCommonValues(lChildren, lFirstPoint, &lStrokeWidth, lStrokeColor, lFillColor);
 
  std::vector<double> lXValues;
  std::vector<double> lYValues;

  double lFirst[2];
  getDoublesFromPoint(lFirstPoint, lFirst);
  lXValues.push_back(lFirst[0]);
  lYValues.push_back(lFirst[1]);
  Item lPoint;
  int lCounter = 1;
  while(lChildren->next(lPoint)) {
    lCounter++;
    double lPointValues[2];
    getDoublesFromPoint(lPoint, lPointValues);
    lXValues.push_back(lPointValues[0]);
    lYValues.push_back(lPointValues[1]);
  }
  lChildren->close();
  
  long lBlobLength = (long) aBlob.length();
  
  double* lXValuesArray = new double[lCounter];
  double* lYValuesArray = new double[lCounter];
  memcpy(lXValuesArray, &lXValues[0], lCounter*sizeof(lXValues[0]));
  memcpy(lYValuesArray, &lYValues[0], lCounter*sizeof(lYValues[0]));
    
  void * lBlobPointer = DrawPolygon(aBlob.data(), &lBlobLength, &lXValuesArray[0], &lYValuesArray[0], lCounter, lStrokeColor, lFillColor, lStrokeWidth, lAntiAliasing);
  
  delete[] lXValuesArray;
  delete[] lYValuesArray;
  
  Magick::Blob lBlobWithPolyLine(lBlobPointer, lBlobLength);
  // now read the blob back into an image to pass it back as encoded string 
  aBlob = lBlobWithPolyLine;
 

}

void              
PaintImplFunction::applyText(Magick::Blob& aBlob, Item& aText) const {
  Item lFirstPoint;
  Iterator_t lChildren = aText.getChildren();
  lChildren->open();
  double lStrokeWidth = 0; 
  std::string lStrokeColor = "";
  std::string lFillColor = "";
  bool lAntiAliasing;

  lAntiAliasing = getCommonValues(lChildren, lFirstPoint, &lStrokeWidth, lStrokeColor, lFillColor);
 

  double lFirst[2];
  getDoublesFromPoint(lFirstPoint, lFirst);

  Item lTextItem;
  lChildren->next(lTextItem);
  String lText = lTextItem.getStringValue();
  Item lFontFamilyItem;
  lChildren->next(lFontFamilyItem);
  String lFontFamily = lFontFamilyItem.getStringValue();
  Item lFontSizeItem;
  lChildren->next(lFontSizeItem);
  double lFontSize = getDoubleValue(lFontSizeItem);

  lChildren->close();
  
    
  long lBlobLength = (long) aBlob.length();
  void * lBlobPointer = DrawText(aBlob.data(), &lBlobLength, lText.c_str() , lFirst[0], lFirst[1], lFontFamily.c_str(), lFontSize, lStrokeColor.c_str());
  Magick::Blob lBlobWithPolyLine(lBlobPointer, lBlobLength);
  // now read the blob back into an image to pass it back as encoded string 
  aBlob = lBlobWithPolyLine;
 


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


