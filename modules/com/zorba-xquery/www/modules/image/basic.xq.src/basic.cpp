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

#include "basic.h"
#include <list> 
#include <sstream>
#include <string>
#include <zorba/empty_sequence.h>
#include <zorba/base64.h>
#include <zorba/singleton_item_sequence.h>
#include <zorba/zorba.h>
#include "basic_module.h"
#include "draw_in_c.h"

namespace zorba { namespace imagemodule { namespace basicmodule {

using namespace zorba::imagemodule;  


//*****************************************************************************

WidthFunction::WidthFunction(const ImageModule* aModule) : ImageFunction(aModule)
{
}

ItemSequence_t
WidthFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{

  Magick::Image lImage;
  ImageFunction::getOneImageArg(aDynCtx, aArgs, 0, lImage);
  int lResult = lImage.columns();
  return ItemSequence_t(new SingletonItemSequence(
      theModule->getItemFactory()->createUnsignedInt(lResult)));

}

//*****************************************************************************

HeightFunction::HeightFunction(const ImageModule* aModule) : ImageFunction(aModule)
{
}

ItemSequence_t
HeightFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{

  Magick::Image lImage;
  ImageFunction::getOneImageArg(aDynCtx, aArgs, 0, lImage);
  int lResult = lImage.rows();
  return ItemSequence_t(new SingletonItemSequence(
      theModule->getItemFactory()->createUnsignedInt(lResult)));

}

//*****************************************************************************

TypeFunction::TypeFunction(const ImageModule* aModule) : ImageFunction(aModule)
{
}

ItemSequence_t
TypeFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  Magick::Image lImage;
  ImageFunction::getOneImageArg(aDynCtx, aArgs, 0, lImage);
  Magick::Blob lBlob;
  lImage.write(&lBlob); 
  long lBlobLength = (long) lBlob.length();
  std::string lImageType = GetImageType(lBlob.data(), &lBlobLength);
  String lResult(lImageType);
  return ItemSequence_t(new SingletonItemSequence(
      theModule->getItemFactory()->createString(lResult)));
}


//*****************************************************************************

ConvertSVGFunction::ConvertSVGFunction(const ImageModule* aModule) : ImageFunction(aModule)
{
}

ItemSequence_t
ConvertSVGFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  Magick::Image lImage;
  ImageFunction::getOneImageArg(aDynCtx, aArgs, 0, lImage);
  if (lImage.magick().compare("SVG") != 0) {
    ImageFunction::throwErrorWithQName(aDynCtx, "IM002", "The passed xs:base64Binary is not an image of type SVG");
  }
  String lType = ImageFunction::getOneStringArg(aArgs, 1);
  lImage.magick(lType.c_str());  
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(aDynCtx, lImage);
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());

  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
   
}


//*****************************************************************************

ConvertFunction::ConvertFunction(const ImageModule* aModule) : ImageFunction(aModule)
{
}


ItemSequence_t
ConvertFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{

  Magick::Image lImage;
  ImageFunction::getOneImageArg(aDynCtx, aArgs, 0 , lImage);
      
  String lType;
  lType = ImageFunction::getOneStringArg(aArgs, 1);


  lImage.magick(lType.c_str()); // Set output format 
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(aDynCtx, lImage); 
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());

  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));

}

//*****************************************************************************

CompressFunction::CompressFunction(const ImageModule* aModule) : ImageFunction(aModule)
{
}


ItemSequence_t
CompressFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{

  Magick::Image lImage;
  ImageFunction::getOneImageArg(aDynCtx, aArgs, 0 , lImage);
  int lQuality = ImageFunction::getOneUnsignedIntArg(aArgs, 1);
  // make sure that we have at most a quality of 100 (highest possible value)
  if (lQuality > 100) {
    lQuality = 100;
  } else if (lQuality < 0) {
    lQuality = 0;
  }
  lImage.quality(lQuality); // Set output format 
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(aDynCtx, lImage);
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));

}

//*****************************************************************************

CreateFunction::CreateFunction(const ImageModule* aModule) : ImageFunction(aModule)
{
}


ItemSequence_t
CreateFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  String lType;
  lType = ImageFunction::getOneStringArg(aArgs, 2);
  const unsigned int width = ImageFunction::getOneUnsignedIntArg(aArgs, 0);
  const unsigned int height = ImageFunction::getOneUnsignedIntArg(aArgs, 1);  
  Magick::Image lBlankImage( Magick::Geometry(width, height), "white");
  lBlankImage.magick(lType.c_str()); // Set output format 

  String lEncodedContent = ImageFunction::getEncodedStringFromImage(aDynCtx, lBlankImage); 
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
                                                   
}                        

//*****************************************************************************

EqualsFunction::EqualsFunction(const ImageModule* aModule) : ImageFunction(aModule)
{
}


ItemSequence_t
EqualsFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  Magick::Image lFirst;
  Magick::Image lSecond;
  ImageFunction::getOneImageArg(aDynCtx, aArgs, 0, lFirst);
  ImageFunction::getOneImageArg(aDynCtx, aArgs, 1, lSecond);
  lFirst.compare(lSecond);
  bool lResult = (lFirst.normalizedMeanError() < 0.0018);
  return ItemSequence_t(new SingletonItemSequence(
      theModule->getItemFactory()->createBoolean(lResult)));

}


//*****************************************************************************

ExifFunction::ExifFunction(const ImageModule* aModule) : ImageFunction(aModule)
{
}


ItemSequence_t
ExifFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  Magick::Image lImage;
  ImageFunction::getOneImageArg(aDynCtx, aArgs, 0, lImage);
  String lTag = ImageFunction::getOneStringArg(aArgs, 1);
  std::string lTagWithExif("EXIF:");
  lTagWithExif += lTag.c_str(); 
  Magick::Blob lBlob;
  lImage.write(&lBlob); 
  long lBlobLength = (long) lBlob.length();
  std::string lExifValue = GetExifValue(lBlob.data(), &lBlobLength, lTagWithExif);
  if (lExifValue == "") {
    return ItemSequence_t(new EmptySequence());
  }
  return ItemSequence_t(new SingletonItemSequence(
      theModule->getItemFactory()->createString(String(lExifValue)))); 
}




} /* namespace basicmodule */  } /* namespace imagemodule */ }  /* namespace zorba */


#ifdef WIN32
#  define DLL_EXPORT __declspec(dllexport)
#else
#  define DLL_EXPORT __attribute__ ((visibility("default")))
#endif

extern "C" DLL_EXPORT zorba::ExternalModule* createModule() {
  return new zorba::imagemodule::basicmodule::BasicModule();
}



