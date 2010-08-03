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

#ifndef ZORBA_IMAGEMODULE_IMAGE_FUNCTION_H
#define ZORBA_IMAGEMODULE_IMAGE_FUNCTION_H

#include <zorba/external_function.h>
#include <Magick++.h>

namespace zorba { namespace imagemodule {


  class ImageModule;

  class ImageFunction : public NonePureStatelessExternalFunction
  {

    public:
      ImageFunction(const ImageModule* module);
      ~ImageFunction();
    

    protected:
  
     const ImageModule* theModule;
     virtual String 
       getURI() const;

     static void throwImageError(const char* aMessage);   
      

     static void
        throwError(
          const std::string errorMessage,
          const XQUERY_ERROR& errorType);

      static String
        getOneStringArg(
          const StatelessExternalFunction::Arguments_t& args,
          int pos);


      static bool
        getOneBoolArg(
            const StatelessExternalFunction::Arguments_t& args,
            int pos);


      static void 
          getOneImageArg(
            const StatelessExternalFunction::Arguments_t& aArgs,
            int aPos,
            Magick::Image& aImage);
      
      static void
         getOneOrMoreImageArg(
              const StatelessExternalFunction::Arguments_t& aArgs,
              int aPos,
              std::list<Magick::Image>& aImages,
              const unsigned int aDelay,
              const unsigned int aIterations);

     static unsigned int 
          getOneUnsignedIntArg(const StatelessExternalFunction::Arguments_t& aArgs,
          int aPos);


      static int getOneIntArg(
          const StatelessExternalFunction::Arguments_t& args,
          int pos);
      

      static double  getOneDoubleArg(
          const StatelessExternalFunction::Arguments_t& args,
          int pos);
        
      static double  getOneOrNullDoubleArg (
          const StatelessExternalFunction::Arguments_t& args,
          int pos); 
      
        
      

      static void getOneColorArg(
           const StatelessExternalFunction::Arguments_t& aArgs,
           int aPos,
           Magick::ColorRGB& aColor);

      static void getColorFromString(
          const String aColorString,
          Magick::ColorRGB& aColor);

      static String getEncodedStringFromBlob(Magick::Blob& aBlob);
    
      static String getEncodedStringFromImage(Magick::Image& aImage);

      static void getImageFromString(const String aString, Magick::Image& aImage);
      
      static void checkIfItemIsNull(Item& aItem); 

      static bool getAntiAliasingArg(
          const StatelessExternalFunction::Arguments_t& aArgs,
          int aPos);

      static double getStrokeWidthArg(
          const StatelessExternalFunction::Arguments_t& aArgs,
          int aPos);

  }; 


} /* namespace imagemodule*/ } /* namespace zorba */

#endif // ZORBA_IMAGEMODULE_IMAGE_FUNCTION_H
