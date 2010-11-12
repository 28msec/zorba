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

#include "animation.h"
#include <list> 
#include <sstream>
#include <string>
#include <zorba/empty_sequence.h>
#include <zorba/singleton_item_sequence.h>
#include <zorba/zorba.h>
#include "animation_module.h"



namespace zorba {  namespace imagemodule { namespace animationmodule {

using namespace zorba::imagemodule;  


//*****************************************************************************


CreateAnimatedGifFunction::CreateAnimatedGifFunction(const ImageModule* aModule) : ImageFunction(aModule)
{
}


ItemSequence_t
CreateAnimatedGifFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  
  const unsigned int lDelay = ImageFunction::getOneUnsignedIntArg(aArgs, 1);
  const unsigned int lIterations = ImageFunction::getOneUnsignedIntArg(aArgs, 2);
  // the list of images which occure in the animation
  std::list<Magick::Image>  lImageList; 
  // the animated image
  ImageFunction::getOneOrMoreImageArg(theModule, aArgs, 0, lImageList, lDelay, lIterations);

  Magick::Blob lBlob;
  Magick::writeImages(lImageList.begin(), lImageList.end(),  &lBlob, true);
  String lEncodedContent = ImageFunction::getEncodedStringFromBlob(lBlob); 
   
  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
}


//*****************************************************************************


CreateMorphedGifFunction::CreateMorphedGifFunction(const ImageModule* aModule) : ImageFunction(aModule)
{
}


ItemSequence_t
CreateMorphedGifFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{

  const unsigned int lDelay = ImageFunction::getOneUnsignedIntArg(aArgs, 1);
  const unsigned int lIterations = ImageFunction::getOneUnsignedIntArg(aArgs, 2);
  const unsigned int lAddedImages = ImageFunction::getOneUnsignedIntArg(aArgs, 3);
  // the list of images which occure in the animation
  std::list<Magick::Image>  lImageList;
  ImageFunction::getOneOrMoreImageArg(theModule, aArgs, 0, lImageList, lDelay, lIterations);

  // create morph effect for images
  Magick::morphImages(&lImageList, lImageList.begin(), lImageList.end(), lAddedImages);
  Magick::Blob lBlob;
  Magick::writeImages(lImageList.begin(), lImageList.end(),  &lBlob, true);
  String lEncodedContent = ImageFunction::getEncodedStringFromBlob(lBlob);

  Item lItem = theModule->getItemFactory()->createBase64Binary(lEncodedContent.c_str(), lEncodedContent.bytes());
  ImageFunction::checkIfItemIsNull(lItem);
  return ItemSequence_t(new SingletonItemSequence(lItem));
}



} /* namespace animationmodule */  } /* namespace imagemodule */ }  /* namespace zorba */


#ifdef WIN32
#  define DLL_EXPORT __declspec(dllexport)
#else
#  define DLL_EXPORT __attribute__ ((visibility("default")))
#endif

extern "C" DLL_EXPORT zorba::ExternalModule* createModule() {
  return new zorba::imagemodule::animationmodule::AnimationModule();
}



