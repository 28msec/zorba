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

#include "image_module.h"
#include <zorba/external_function.h>


namespace zorba { namespace imagemodule { 

  ItemFactory* ImageModule::theFactory = 0;

ImageModule::~ImageModule()
{
  for (FuncMap_t::const_iterator lIter = theFunctions.begin();
       lIter != theFunctions.end(); ++lIter) {
    delete lIter->second;
  }
  theFunctions.clear();
}

StatelessExternalFunction*
ImageModule::getExternalFunction(const String& aLocalname)
{
  StatelessExternalFunction*& lFunc = theFunctions[aLocalname];
  return lFunc;
}

void
ImageModule::destroy()
{
  if (!dynamic_cast<ImageModule*>(this)) {
    return;
  }
  delete this;
}
}  /* namespace imagemodule */ } /* namespace zorba */
