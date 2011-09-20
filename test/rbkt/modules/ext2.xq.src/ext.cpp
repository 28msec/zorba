/*
 * Copyright 2006-2011 The FLWOR Foundation.
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
#include "ext.h"
#include <zorba/item_factory.h>
#include <zorba/singleton_item_sequence.h>

namespace zorba { namespace extmodule {

ExtModule::ExtModule()
{
  theFunc = new FuncFunction(this);
}

ExtModule::~ExtModule()
{
  delete theFunc;
}

void
ExtModule::destroy()
{
  delete this;
}

zorba::ExternalFunction*
ExtModule::getExternalFunction(const zorba::String& aLocalname)
{
  if (aLocalname == "func") {
    return theFunc;
  }
  return NULL;
}

FuncFunction::FuncFunction(const ExtModule* aModule)
  : theModule(aModule)
{
}

zorba::ItemSequence_t
FuncFunction::evaluate(Arguments_t const& aArgs,
  zorba::StaticContext const* aSctx, zorba::DynamicContext const* aDctx) const
{
  zorba::Item lStr =
    Zorba::getInstance(0)->getItemFactory()->createString("hello, v2");
  return zorba::ItemSequence_t(new zorba::SingletonItemSequence(lStr));
}

} /* namespace extmodule */
} /* namespace zorba */

#ifdef WIN32
#  define DLL_EXPORT __declspec(dllexport)
#else
#  define DLL_EXPORT __attribute__ ((visibility("default")))
#endif

extern "C" DLL_EXPORT zorba::ExternalModule* createModule() {
  return new zorba::extmodule::ExtModule();
}
