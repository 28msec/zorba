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
#pragma once
#ifndef ZORBA_LINK_H
#define ZORBA_LINK_H

#include <zorba/zorba.h>
#include <zorba/external_module.h>
#include <zorba/function.h>

namespace zorba { namespace linkmodule {

class XercesFuncFunction;
class OurFuncFunction;

class LinkModule : public ExternalModule
{
public:
  LinkModule();

  virtual ~LinkModule();

  virtual void destroy();

  virtual zorba::ExternalFunction*
  getExternalFunction(const zorba::String& aLocalname);

  virtual zorba::String
  getURI() const { return "http://zorba-tests.28.io/modules/link"; }
  
private:
  XercesFuncFunction* theXercesFunc;
  OurFuncFunction* theOurFunc;
};

class XercesFuncFunction : public ContextualExternalFunction
{
public:
  XercesFuncFunction(const LinkModule* aModule);
  
  virtual ~XercesFuncFunction() {}

  virtual zorba::String
  getLocalName() const { return "xerces-func"; }

  virtual zorba::String
  getURI() const { return theModule->getURI(); }

  virtual zorba::ItemSequence_t
  evaluate(Arguments_t const& aArgs, zorba::StaticContext const* aSctx,
    zorba::DynamicContext const* aDctx) const;

private:
  LinkModule const* theModule;
};

class OurFuncFunction : public ContextualExternalFunction
{
public:
  OurFuncFunction(const LinkModule* aModule);
  
  virtual ~OurFuncFunction() {}

  virtual zorba::String
  getLocalName() const { return "our-func"; }

  virtual zorba::String
  getURI() const { return theModule->getURI(); }

  virtual zorba::ItemSequence_t
  evaluate(Arguments_t const& aArgs, zorba::StaticContext const* aSctx,
    zorba::DynamicContext const* aDctx) const;

private:
  LinkModule const* theModule;
};

} /* namespace linkmodule */
} /* namespace zorba */


#endif /* ZORBA_LINK_H */
