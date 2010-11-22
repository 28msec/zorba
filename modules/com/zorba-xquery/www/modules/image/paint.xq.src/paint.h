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
#ifndef ZORBA_IMAGEMODULE_PAINTMODULE_PAINT_H
#define ZORBA_IMAGEMODULE_PAINTMODULE_PAINT_H

#include "image_function.h"
#include <wand/MagickWand.h>
#include <string>

namespace zorba { 
  
  class ItemFactory;
  class SerializationItemProvider;

  namespace imagemodule { namespace paintmodule {
    


//*****************************************************************************

class PaintImplFunction : public zorba::imagemodule::ImageFunction

  {
    public:
      PaintImplFunction(const ImageModule* aModule);
      virtual String getLocalName() const { return "paint-impl";}

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;
      
      virtual void
      applyShape(Magick::Blob& aBlob, Item& aShape) const;
  
      virtual void
      applyLine(Magick::Blob& aBlob, Item& aShape) const;

      virtual void
      applyPolyLine(Magick::Blob& aBlob, Item& aShape) const;

      virtual void
      applyStrokedPolyLine(Magick::Blob& aBlob, Item& aShape) const;      
      
      virtual void
      applyRectangle(Magick::Blob& aBlob, Item& aShape) const;      
  
      virtual void
      applyRoundedRectangle(Magick::Blob& aBlob, Item& aShape) const;      
    
      virtual void
      applyCircle(Magick::Blob& aBlob, Item& aShape) const;      
      
      virtual void
      applyEllipse(Magick::Blob& aBlob, Item& aShape) const;      
    
      virtual void
      applyArc(Magick::Blob& aBlob, Item& aShape) const;      
  
  
      virtual void
      applyPolygon(Magick::Blob& aBlob, Item& aShape) const;      
  

      virtual void
      applyText(Magick::Blob& aBlob, Item& aShape) const;      

      virtual bool
      getCommonValues(Iterator_t& aChildIterator, 
                      Item& aLastItemFound, 
                      double* aStrokeWidth, 
                      std::string& aStrokeColor, 
                      std::string& aFillColor) const; 


      double
      getDoubleValue(Item& aDoubleItem) const;


      void
      getDoublesFromPoint(Item& aPointItem, double aPoint[2]) const; 


  
  };

} /* namespace paintmodule */ } /* namespace imagemodule */ } /* namespace zorba */

#endif /* ZORBA_IMAGEMODULE_PAINTMODULE_PAINT_H */

