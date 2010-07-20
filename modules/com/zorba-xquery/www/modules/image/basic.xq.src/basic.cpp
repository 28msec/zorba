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



namespace zorba {  namespace imagemodule { namespace basicmodule {

using namespace zorba::imagemodule;  



//*****************************************************************************


WidthFunction::WidthFunction(const BasicModule* aModule) : BasicFunction(aModule)
{
}


ItemSequence_t
WidthFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{

  Magick::Image lImage;
  lImage = ImageFunction::getOneImageArg(aArgs, 0);
  int lResult = lImage.columns();
  return ItemSequence_t(new SingletonItemSequence(
      theModule->getItemFactory()->createInt(lResult)));

}

//*****************************************************************************


HeightFunction::HeightFunction(const BasicModule* aModule) : BasicFunction(aModule)
{
}


ItemSequence_t
HeightFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{

  Magick::Image lImage;
  lImage = ImageFunction::getOneImageArg(aArgs, 0);
  int lResult = lImage.rows();
  return ItemSequence_t(new SingletonItemSequence(
      theModule->getItemFactory()->createInt(lResult)));

}

//*****************************************************************************

TypeFunction::TypeFunction(const BasicModule* aModule) : BasicFunction(aModule)
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

ConvertFunction::ConvertFunction(const BasicModule* aModule) : BasicFunction(aModule)
{
}


ItemSequence_t
ConvertFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{

  Magick::Image lImage;
  lImage = ImageFunction::getOneImageArg(aArgs, 0);
  String lType;
  lType = ImageFunction::getOneStringArg(aArgs, 1);
    
  lImage.magick(lType.c_str()); // Set output format 
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lImage); 
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());

  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));

}

//*****************************************************************************

CreateFunction::CreateFunction(const BasicModule* aModule) : BasicFunction(aModule)
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
  const int width = ImageFunction::getOneUnsignedIntArg(aArgs, 0);
  const int height = ImageFunction::getOneUnsignedIntArg(aArgs, 1);  
  Magick::Image lBlankImage( Magick::Geometry(width, height), "white");
  lBlankImage.magick(lType.c_str()); // Set output format 

 
  String lEncodedContent = ImageFunction::getEncodedStringFromImage(lBlankImage); 

  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
   
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
                                                   
}                        


//*****************************************************************************

CreateAnimatedGifFunction::CreateAnimatedGifFunction(const BasicModule* aModule) : BasicFunction(aModule)
{
}


ItemSequence_t
CreateAnimatedGifFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  
  int lDelay = ImageFunction::getOneUnsignedIntArg(aArgs, 1);
  int lIterations = ImageFunction::getOneUnsignedIntArg(aArgs, 2);
  // the list of images which occure in the animation
  std::list<Magick::Image>  lImageList; 
  // the animated image
  Magick::Image lAnimatedImage;
  Item lItem;
  // make sure there is at least one item at the position
  if (!aArgs[0]->next(lItem)) {
    throwError("An empty sequence is not allowed as first parameter", XPTY0004);
  }

  Magick::Image lFirstImage = ImageFunction::getImageFromString(lItem.getStringValue());
  lFirstImage.animationDelay(lDelay);
  lFirstImage.animationIterations(lIterations);
  lFirstImage.gifDisposeMethod(3);
  lImageList.push_back(lFirstImage);  
  Magick::Image lTempImage; 
  while (aArgs[0]->next(lItem)) {
    lTempImage = ImageFunction::getImageFromString(lItem.getStringValue());
    lTempImage.animationDelay(lDelay);
    lTempImage.gifDisposeMethod(3);
    lImageList.push_back(lTempImage);
  }
  Magick::Blob lBlob;
  Magick::writeImages(lImageList.begin(), lImageList.end(),  &lBlob, true);
  String lEncodedContent = ImageFunction::getEncodedStringFromBlob(lBlob); 
  
  lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
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



