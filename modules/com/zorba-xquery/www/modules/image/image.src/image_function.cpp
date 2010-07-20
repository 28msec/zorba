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

#include <sstream>
#include <zorba/zorba.h>
#include <Magick++.h>
#include <zorba/base64.h>
#include <zorba/empty_sequence.h>
#include <zorba/singleton_item_sequence.h>
#include "image_function.h"



namespace zorba {  namespace imagemodule {



void
ImageFunction::throwError(
        const std::string aErrorMessage,
            const XQUERY_ERROR& aErrorType)
{
  throw zorba::ExternalFunctionData::createZorbaException(aErrorType,
              aErrorMessage.c_str(), __FILE__, __LINE__);
}

void
ImageFunction::throwImageError(const char *aMessage) {
  std::stringstream lErrorMessage;
  if (std::string(aMessage).find("zero-length") != std::string::npos) {
    lErrorMessage << "Passed xs:base64Binary seems to be empty.";
    throwError(lErrorMessage.str(), XPST0083);
  } else {
    lErrorMessage << "Error while processing xs:base64Binary. Possibly not a valid image type.";
    throwError(lErrorMessage.str(), XPST0083);
  }           
  
}

void 
ImageFunction::checkIfItemIsNull(Item& aItem) {
  if (aItem.isNull()) {
    throw ExternalFunctionData::createZorbaException(XPTY0004, "Error while building the base64binary item. ", __FILE__, __LINE__);
  }
}

String
ImageFunction::getOneStringArg(
    const StatelessExternalFunction::Arguments_t& aArgs,
    int aPos)
{
  Item lItem;
  if (!aArgs[aPos]->next(lItem)) {
    std::stringstream lErrorMessage;
    lErrorMessage << "An empty-sequence is not allowed as "
                  << aPos << ". parameter.";
    throwError(lErrorMessage.str(), XPTY0004);
  }
  zorba::String lTmpString = lItem.getStringValue();
  if (aArgs[aPos]->next(lItem)) {
    std::stringstream lErrorMessage;
    lErrorMessage << "A sequence of more then one item is not allowed as "
                  << aPos << ". parameter.";
    throwError(lErrorMessage.str(), XPTY0004);
  }
  return lTmpString;
}



Magick::ColorRGB 
ImageFunction::getOneColorArg(
    const StatelessExternalFunction::Arguments_t& aArgs,
    int aPos)

{
  Item lItem;
  if (!aArgs[aPos]->next(lItem)) {
    std::stringstream lErrorMessage;
    lErrorMessage << "An empty-sequence is not allowed as "
                  << aPos << ". parameter.";
    throwError(lErrorMessage.str(), XPTY0004);
  }
  zorba::String lTmpString = lItem.getStringValue();
  if (aArgs[aPos]->next(lItem)) {
    std::stringstream lErrorMessage;
    lErrorMessage << "A sequence of more then one item is not allowed as "
                  << aPos << ". parameter.";
    throwError(lErrorMessage.str(), XPTY0004);
  }
  double lRed, lGreen, lBlue;
  
  // get color components as unsinged doubles  from 0 to 255
  std::stringstream lStringStream;
  lStringStream << std::hex << lTmpString.substring(1,2).c_str();
  lStringStream >> lRed; 
  lStringStream.str(std::string());
  
  lStringStream << std::hex << lTmpString.substring(3,2).c_str();
  lStringStream >> lGreen; 
  lStringStream.str(std::string());

  lStringStream << std::hex << lTmpString.substring(5,2).c_str();
  lStringStream >> lBlue;

  Magick::ColorRGB lResult(lRed/255.0, lGreen/255.0, lBlue/255.0);
  return lResult;
  
}



int
ImageFunction::getOneIntArg(
    const StatelessExternalFunction::Arguments_t& aArgs,
    int aPos)
{
  Item lItem;
  if (!aArgs[aPos]->next(lItem)) {
    std::stringstream lErrorMessage;
    lErrorMessage << "An empty-sequence is not allowed as "
                  << aPos << ". parameter.";
    throwError(lErrorMessage.str(), XPTY0004);
  }
  int lTmpInt = (int) lItem.getIntValue();
  if (aArgs[aPos]->next(lItem)) {
    std::stringstream lErrorMessage;
    lErrorMessage << "A sequence of more then one item is not allowed as "
                  << aPos << ". parameter.";
    throwError(lErrorMessage.str(), XPTY0004);
  }
  return lTmpInt;

}



int
ImageFunction::getOneUnsignedIntArg(
    const StatelessExternalFunction::Arguments_t& aArgs,
    int aPos)
{
  Item lItem;
  if (!aArgs[aPos]->next(lItem)) {
    std::stringstream lErrorMessage;
    lErrorMessage << "An empty-sequence is not allowed as "
                  << aPos << ". parameter.";
    throwError(lErrorMessage.str(), XPTY0004);
  }
  int lTmpInt = (int) lItem.getUnsignedIntValue();
  if (aArgs[aPos]->next(lItem)) {
    std::stringstream lErrorMessage;
    lErrorMessage << "A sequence of more then one item is not allowed as "
                  << aPos << ". parameter.";
    throwError(lErrorMessage.str(), XPTY0004);
  }
  return lTmpInt;

}



double
ImageFunction::getOneDoubleArg(
    const StatelessExternalFunction::Arguments_t& aArgs,
    int aPos)
{
  Item lItem;
  if (!aArgs[aPos]->next(lItem)) {
    std::stringstream lErrorMessage;
    lErrorMessage << "An empty-sequence is not allowed as "
                  << aPos << ". parameter.";
    throwError(lErrorMessage.str(), XPTY0004);
  }
  double lTmpDouble =  lItem.getDoubleValue();
  if (aArgs[aPos]->next(lItem)) {
    std::stringstream lErrorMessage;
    lErrorMessage << "A sequence of more then one item is not allowed as "
                  << aPos << ". parameter.";
    throwError(lErrorMessage.str(), XPTY0004);
  }
  return lTmpDouble;

}

String 
ImageFunction::getEncodedStringFromBlob(Magick::Blob& aBlob) {

    std::string lStringOfBlobContent((char *)aBlob.data(), aBlob.length());
    String lZorbaStringOfBlobContent(lStringOfBlobContent);

    return zorba::encoding::Base64::encode(lZorbaStringOfBlobContent);
}




String 
ImageFunction::getEncodedStringFromImage(Magick::Image& aImage) {
  Magick::Blob lBlob;
  try {
    aImage.write(&lBlob);
  } catch (Magick::Exception& error) {
    throwImageError(error.what());
  }   
  return getEncodedStringFromBlob(lBlob);
} 





Magick::Image 
ImageFunction::getOneImageArg(const StatelessExternalFunction::Arguments_t& aArgs,
                                    int aPos)
{

  String lData;
  lData = getOneStringArg(aArgs, aPos);
  return getImageFromString(lData);
}


Magick::Image 
ImageFunction::getImageFromString(String aString) {

  Magick::Blob lBlob;
  Magick::Image lImage;

  try {
    lBlob.base64(aString.c_str());
    lImage.read(lBlob);

  } catch (Magick::Exception &error)   {
      throwImageError(error.what());
  }
    return lImage;

}


} // imagemodule 
} // zorba

