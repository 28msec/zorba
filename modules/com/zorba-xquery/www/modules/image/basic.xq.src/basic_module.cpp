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
#include "basic_module.h"

namespace zorba { namespace imagemodule { namespace basicmodule {

  
StatelessExternalFunction*
BasicModule::getExternalFunction(String aLocalname) const
{
  StatelessExternalFunction*& lFunc = theFunctions[aLocalname];
  if (!lFunc) {
    if (1 == 0) {
    } else if (aLocalname.equals("width")) {
      lFunc = new WidthFunction(this);
    } else if (aLocalname.equals("height")) {
      lFunc = new HeightFunction(this);
    } else if (aLocalname.equals("type")) {
      lFunc = new TypeFunction(this);
    } else if (aLocalname.equals("convert-impl")) {
      lFunc = new ConvertFunction(this);
    } else if (aLocalname.equals("compress")) {
      lFunc = new CompressFunction(this);
    } else if (aLocalname.equals("create-impl")) {
      lFunc = new CreateFunction(this); 
    } else if (aLocalname.equals("equals")) {
      lFunc = new EqualsFunction(this);
    } else if (aLocalname.equals("exif")) {
      lFunc = new ExifFunction(this);
    }  
  }
  return lFunc;
}

} /* namespace basicmodule */ } /* namespace imagemodule */ } /* namespace zorba */
