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
#include "link.h"
#include <zorba/item_factory.h>
#include <zorba/singleton_item_sequence.h>
#include <zorba/internal/unique_ptr.h>

#include <xercesc/util/XMLDouble.hpp>
#include "../ourlib/ourlib.h"

#pragma warning ( disable: 4005 )

XERCES_CPP_NAMESPACE_USE

namespace zorba { namespace linkmodule {

LinkModule::LinkModule()
{
  theXercesFunc = new XercesFuncFunction(this);
  theOurFunc = new OurFuncFunction(this);
}

LinkModule::~LinkModule()
{
  delete theXercesFunc;
  delete theOurFunc;
}

void
LinkModule::destroy()
{
  delete this;
}

zorba::ExternalFunction*
LinkModule::getExternalFunction(const zorba::String& aLocalname)
{
  if (aLocalname == "xerces-func") {
    return theXercesFunc;
  }
  else if (aLocalname == "our-func") {
    return theOurFunc;
  }
  return NULL;
}

XercesFuncFunction::XercesFuncFunction(const LinkModule* aModule)
  : theModule(aModule)
{
}

zorba::ItemSequence_t
XercesFuncFunction::evaluate(Arguments_t const& aArgs,
  zorba::StaticContext const* aSctx, zorba::DynamicContext const* aDctx) const
{
  // Silly test case
  XMLCh doub1[2], doub2[2];
  doub1[0] = '1';
  doub2[0] = '2';
  doub1[1] = doub2[1] = '\0';
  std::unique_ptr<XMLDouble> xdoub1(new XMLDouble(doub1));
  std::unique_ptr<XMLDouble> xdoub2(new XMLDouble(doub2));
  int lComp = XMLDouble::compareValues(xdoub1.get(), xdoub2.get());
  zorba::Item lStr =
    Zorba::getInstance(0)->getItemFactory()->createInteger(lComp);
  return zorba::ItemSequence_t(new zorba::SingletonItemSequence(lStr));
}

OurFuncFunction::OurFuncFunction(const LinkModule* aModule)
  : theModule(aModule)
{
}

zorba::ItemSequence_t
OurFuncFunction::evaluate(Arguments_t const& aArgs,
  zorba::StaticContext const* aSctx, zorba::DynamicContext const* aDctx) const
{
  // Silly test case
  std::unique_ptr<Ourlib> lOurlib(new Ourlib(55));
  int lVal = lOurlib->ourfunc();
  zorba::Item lStr =
    Zorba::getInstance(0)->getItemFactory()->createInteger(lVal);
  return zorba::ItemSequence_t(new zorba::SingletonItemSequence(lStr));
}

} /* namespace linkmodule */
} /* namespace zorba */

#ifdef WIN32
#  define DLL_EXPORT __declspec(dllexport)
#else
#  define DLL_EXPORT __attribute__ ((visibility("default")))
#endif

extern "C" DLL_EXPORT zorba::ExternalModule* createModule() {
  return new zorba::linkmodule::LinkModule();
}
