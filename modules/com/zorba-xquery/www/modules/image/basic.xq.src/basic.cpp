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
#include <zorba/singleton_item_sequence.h>
#include <zorba/zorba.h>
#include "basic_module.h"


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
  ImageFunction::getOneImageArg(aArgs, 0, lImage);
  int lResult = lImage.columns();
  return ItemSequence_t(new SingletonItemSequence(
      theModule->getItemFactory()->createInt(lResult)));

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
  ImageFunction::getOneImageArg(aArgs, 0, lImage);
  int lResult = lImage.rows();
  return ItemSequence_t(new SingletonItemSequence(
      theModule->getItemFactory()->createInt(lResult)));

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

  String lData;
  bool lIsError = false;
  // getOneString already checks if there is exactly one item at aPos ...
  lData = ImageFunction::getOneStringArg(aArgs, 0);
  Magick::Blob lBlob;
  Magick::Image lImage;
  try {
    lBlob.base64(lData.c_str());
    lImage.read(lBlob);

  } catch (Magick::Exception &aError)   {
    lIsError = true;
  }
  // return empty sequence if we encounter an error  
  if (lIsError) {
    return ItemSequence_t(new EmptySequence());
  }

  String lResult;
  lResult = lImage.magick();
  return ItemSequence_t(new SingletonItemSequence(
      theModule->getItemFactory()->createString(lResult)));
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
  ImageFunction::getOneImageArg(aArgs, 0 , lImage);
  String lType;
  lType = ImageFunction::getOneStringArg(aArgs, 1);
    
  lImage.magick(lType.c_str()); // Set output format 
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage); 
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
  ImageFunction::getOneImageArg(aArgs, 0 , lImage);
  int lQuality = ImageFunction::getOneUnsignedIntArg(aArgs, 1);
  // make sure that we have at most a quality of 100 (highest possible value)
  if (lQuality > 100) {
    lQuality = 100;
  } else if (lQuality < 0) {
    lQuality = 0;
  }
  lImage.quality(lQuality); // Set output format 
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage);
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

  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lBlankImage); 
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
  ImageFunction::getOneImageArg(aArgs, 0, lFirst);
  ImageFunction::getOneImageArg(aArgs, 1, lSecond);
  bool lResult = lFirst.compare(lSecond);
  return ItemSequence_t(new SingletonItemSequence(
      theModule->getItemFactory()->createBoolean(lResult)));

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



