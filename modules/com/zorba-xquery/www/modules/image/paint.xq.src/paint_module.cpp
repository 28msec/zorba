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
#include "paint_module.h"

namespace zorba { namespace imagemodule { namespace paintmodule {

StatelessExternalFunction*
PaintModule::getExternalFunction(String aLocalname) const
{
  StatelessExternalFunction*& lFunc = theFunctions[aLocalname];
  if (!lFunc) {
    if (1 == 0) {
    } else if (aLocalname.equals("draw-poly-line")) {
      lFunc = new DrawPolyLineFunction(this); 
    } else if (aLocalname.equals("draw-stroked-poly-line")) {
      lFunc = new DrawStrokedPolyLineFunction(this);
    } else if (aLocalname.equals("draw-rectangle")) {
      lFunc = new DrawRectangleFunction(this);
    } else if (aLocalname.equals("draw-rounded-rectangle")) {
      lFunc = new DrawRoundedRectangleFunction(this);
    } else if (aLocalname.equals("draw-arc")) {
      lFunc = new DrawArcFunction(this);
    } else if (aLocalname.equals("draw-polygon")) {
      lFunc = new DrawPolygonFunction(this);
    } else if (aLocalname.equals("draw-text")) {
      lFunc = new DrawTextFunction(this);
    }   
  }
  return lFunc;
}

} /* namespace paintmodule */ } /* namespace imagemodule */ } /* namespace zorba */
