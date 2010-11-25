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
#include "animation_module.h"

namespace zorba { namespace imagemodule { namespace animationmodule {



  
StatelessExternalFunction*
AnimationModule::getExternalFunction(const String& aLocalname)
{
  StatelessExternalFunction*& lFunc = theFunctions[aLocalname];
  if (!lFunc) {
    if (1 == 0) {
    } else if (aLocalname.equals("create-animated-gif")) {
      lFunc = new CreateAnimatedGifFunction(this); 
    } else if (aLocalname.equals("create-morphed-gif")) {
      lFunc = new CreateMorphedGifFunction(this);
    }
  }
  return lFunc;
}

} /* namespace animationmodule */ } /* namespace imagemodule */ } /* namespace zorba */
