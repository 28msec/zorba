#include "draw_in_c.h"
#include <wand/MagickWand.h>

void *
DrawPolygon(const void* aBlob, 
            long* aLength, 
            double aXValues[], 
            double aYValues[], 
            int aNumberOfPoints, 
            std::string& aStrokeColor, 
            std::string& aFillColor, 
            double aStrokeWidth, 
            bool aAntiAliasing) {
  
  MagickWandGenesis();
  MagickWand * lMagickWand  = NewMagickWand();
  const size_t lLength = (size_t) *aLength;
  MagickReadImageBlob(lMagickWand, aBlob, lLength);                                     
  DrawingWand * lDrawingWand = NewDrawingWand();
  PixelWand * lPixelWand = NewPixelWand();

  PushDrawingWand(lDrawingWand);
  PixelSetColor(lPixelWand, aStrokeColor.c_str());
  DrawSetStrokeColor(lDrawingWand, lPixelWand);
    
  if (aFillColor.compare("opaque") == 0) {
    DrawSetFillOpacity(lDrawingWand, 0);
  } else {
    PixelSetColor(lPixelWand, aFillColor.c_str());
    DrawSetFillColor(lDrawingWand, lPixelWand);
  }
  if (aAntiAliasing) {
    DrawSetStrokeAntialias(lDrawingWand, MagickTrue);
  } else {
    DrawSetStrokeAntialias(lDrawingWand, MagickFalse);
  }
  DrawSetStrokeWidth(lDrawingWand, aStrokeWidth);

  ZorbaArrayAutoPointer<PointInfo> lPoints (new PointInfo[aNumberOfPoints]);
  
  for (int i = 0; i < aNumberOfPoints; i++) {
       (lPoints.get())[i].x = aXValues[i];
       (lPoints.get())[i].y = aYValues[i];
  }
  DrawPolygon(lDrawingWand, aNumberOfPoints, lPoints.get());
  PopDrawingWand(lDrawingWand);
  MagickDrawImage(lMagickWand, lDrawingWand);
  size_t lBlobLength;
  void *lResultPointer;
  lResultPointer = (void *) MagickGetImageBlob(lMagickWand, &lBlobLength);
  *aLength  =  (long) lBlobLength;
  return lResultPointer;
}  
  
void *
DrawPolyLine(const void* aBlob, 
             long* aLength, 
             double aXValues[], 
             double aYValues[], 
             int aNumberOfPoints, 
             std::string& aStrokeColor, 
             double aStrokeWidth, 
             bool aAntiAliasing, 
             double aStrokeArray[], 
             int aNumberOfStrokeValues) 
{
  MagickWandGenesis();                                                                                                           
  MagickWand * lMagickWand  = NewMagickWand();                                                                                   
  const size_t lLength = (size_t) *aLength;
  MagickReadImageBlob(lMagickWand, aBlob, lLength);                                     
  DrawingWand * lDrawingWand = NewDrawingWand();
  PixelWand * lPixelWand = NewPixelWand();

  PushDrawingWand(lDrawingWand);                                                                                                 
  PixelSetColor(lPixelWand, aStrokeColor.c_str());                                                                               
  DrawSetStrokeColor(lDrawingWand, lPixelWand);
  
  // set fill opacity to 0 as we don't want Polylines to be filled ...
  DrawSetFillOpacity(lDrawingWand, 0.0);

  if (aAntiAliasing) {                                                                                                           
    DrawSetStrokeAntialias(lDrawingWand, MagickTrue);                                                                            
  } else {
    DrawSetStrokeAntialias(lDrawingWand, MagickFalse);                                                                           
  } 
  DrawSetStrokeWidth(lDrawingWand, aStrokeWidth);   

  ZorbaArrayAutoPointer<PointInfo> lPoints (new PointInfo[aNumberOfPoints]);                                                     
  
  for (int i = 0; i < aNumberOfPoints; i++) {                                                                                    
       (lPoints.get())[i].x = aXValues[i];
       (lPoints.get())[i].y = aYValues[i];                                                                                       
  }    
  if (aNumberOfStrokeValues > 0) {
    DrawSetStrokeDashArray(lDrawingWand, aNumberOfStrokeValues, aStrokeArray);
  }

  DrawPolyline(lDrawingWand, aNumberOfPoints, lPoints.get()); 
  PopDrawingWand(lDrawingWand);
  MagickDrawImage(lMagickWand, lDrawingWand);
  size_t lBlobLength;
  void *lResultPointer;                                                                                                          
  lResultPointer = (void *) MagickGetImageBlob(lMagickWand, &lBlobLength);                                                       
  *aLength  =  (long) lBlobLength;
  return lResultPointer;
 
}

void *
DrawRoundedRect(const void* aBlob, 
                long* aLength, 
                double aUpperLeftX , 
                double aUpperLeftY, 
                double aLowerRightX, 
                double aLowerRightY, 
                double aCornerWidth, 
                double aCornerHeight, 
                std::string& aStrokeColor, 
                std::string& aFillColor,  
                double aStrokeWidth, 
                bool aAntiAliasing) 
{
  MagickWandGenesis();                                                                                                           
  MagickWand * lMagickWand  = NewMagickWand();                                                                                   
  const size_t lLength = (size_t) *aLength;
  MagickReadImageBlob(lMagickWand, aBlob, lLength);                                     
  DrawingWand * lDrawingWand = NewDrawingWand();
  PixelWand * lPixelWand = NewPixelWand();

  PushDrawingWand(lDrawingWand);                                                                                                 
  PixelSetColor(lPixelWand, aStrokeColor.c_str());                                                                               
  DrawSetStrokeColor(lDrawingWand, lPixelWand);
  
  if (aFillColor.compare("opaque") == 0) {
    DrawSetFillOpacity(lDrawingWand, 0);
  } else {
    PixelSetColor(lPixelWand, aFillColor.c_str());
    DrawSetFillColor(lDrawingWand, lPixelWand);
  }

  if (aAntiAliasing) {
    DrawSetStrokeAntialias(lDrawingWand, MagickTrue);
  } else {
    DrawSetStrokeAntialias(lDrawingWand, MagickFalse);
  }
  DrawSetStrokeWidth(lDrawingWand, aStrokeWidth);

  if ((aCornerWidth <= 0) || (aCornerHeight <= 0)) {
    DrawRectangle(lDrawingWand, aUpperLeftX, aUpperLeftY, aLowerRightX, aLowerRightY);
  } else {
    DrawRoundRectangle(lDrawingWand, aUpperLeftX, aUpperLeftY, aLowerRightX, aLowerRightY, aCornerWidth, aCornerHeight);
  }
  PopDrawingWand(lDrawingWand);
  MagickDrawImage(lMagickWand, lDrawingWand);
  size_t lBlobLength;
  void *lResultPointer;
  lResultPointer = (void *) MagickGetImageBlob(lMagickWand, &lBlobLength);
  *aLength  =  (long) lBlobLength;
  return lResultPointer;

}

void *
DrawText(const void* aBlob, 
         long* aLength, 
         const char* aText, 
         double aX, 
         double aY, 
         const char* aFont, 
         double aFontSize, 
         const char* aColor) {
  MagickWandGenesis();
  MagickWand * lMagickWand  = NewMagickWand();
  const size_t lLength = (size_t) *aLength;
  MagickReadImageBlob(lMagickWand, aBlob, lLength);
  DrawingWand * lDrawingWand = NewDrawingWand();
  PixelWand * lPixelWand = NewPixelWand();

  PushDrawingWand(lDrawingWand);
  PixelSetColor(lPixelWand, aColor);
  DrawSetStrokeColor(lDrawingWand, lPixelWand);
  DrawSetFillColor(lDrawingWand, lPixelWand);
  DrawSetFont(lDrawingWand, aFont);
  DrawSetFontSize(lDrawingWand, aFontSize);

  DrawAnnotation(lDrawingWand, aX, aY, reinterpret_cast<const unsigned char *>(aText));

  PopDrawingWand(lDrawingWand);


  MagickDrawImage(lMagickWand, lDrawingWand);
  size_t lBlobLength;
  void *lResultPointer;
  lResultPointer = (void *) MagickGetImageBlob(lMagickWand, &lBlobLength);
  *aLength  =  (long) lBlobLength;
  return lResultPointer;


}  


std::string
GetImageType(const void* aBlob, 
             long* aLength) {
  MagickWandGenesis();                                                                                                           
  MagickWand * lMagickWand  = NewMagickWand(); 
  const size_t lLength = (size_t) *aLength;
  MagickReadImageBlob(lMagickWand, aBlob, lLength);
  std::string lResult = MagickGetImageFormat(lMagickWand);
  return lResult;
}



std::string
GetExifValue(const void* aBlob, 
             long* aLength, 
             std::string& aExifTag) {
  MagickWandGenesis();                                                                                                           
  MagickWand * lMagickWand  = NewMagickWand(); 
  const size_t lLength = (size_t) *aLength;
  MagickReadImageBlob(lMagickWand, aBlob, lLength);
  char * lResult = MagickGetImageProperty(lMagickWand, aExifTag.c_str());
  if (lResult == NULL) {
  std::string lNothing("");
  return lNothing;
  }
  std::string lStringResult (lResult);
  return lStringResult;
}


