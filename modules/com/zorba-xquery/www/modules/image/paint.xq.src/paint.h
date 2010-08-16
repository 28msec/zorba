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


namespace zorba { 
  
  class ItemFactory;
  class SerializationItemProvider;

  namespace imagemodule { namespace paintmodule {
    

//*****************************************************************************

class DrawStrokedPolyLineFunction : public zorba::imagemodule::ImageFunction

  {
    public:
      DrawStrokedPolyLineFunction(const ImageModule* aModule);
      virtual String getLocalName() const { return "draw-stroked-poly-line";}

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };

//*****************************************************************************

class DrawRectangleFunction : public zorba::imagemodule::ImageFunction

  {
    public:
      DrawRectangleFunction(const ImageModule* aModule);
      virtual String getLocalName() const { return "draw-rectangle";}

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };

//*****************************************************************************

class DrawRoundedRectangleFunction : public zorba::imagemodule::ImageFunction

  {
    public:
      DrawRoundedRectangleFunction(const ImageModule* aModule);
      virtual String getLocalName() const { return "draw-rounded-rectangle";}

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };


//*****************************************************************************

class DrawArcFunction : public zorba::imagemodule::ImageFunction

  {
    public:
      DrawArcFunction(const ImageModule* aModule);
      virtual String getLocalName() const { return "draw-arc";}

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };


//*****************************************************************************

class DrawPolygonFunction : public zorba::imagemodule::ImageFunction

  {
    public:
      DrawPolygonFunction(const ImageModule* aModule);
      virtual String getLocalName() const { return "draw-polygon";}

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };


//*****************************************************************************

class DrawTextFunction : public zorba::imagemodule::ImageFunction

  {
    public:
      DrawTextFunction(const ImageModule* aModule);
      virtual String getLocalName() const { return "draw-text";}

      virtual ItemSequence_t
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  };

} /* namespace paintmodule */  } /* namespace imagemodule */ }  /* namespace zorba */

#endif /* ZORBA_IMAGEMODULE_PAINTMODULE_PAINT_H */
