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
#ifndef ZORBA_EXT_H
#define ZORBA_EXT_H

#include <zorba/zorba.h>
#include <zorba/external_module.h>
#include <zorba/function.h>

namespace zorba { namespace extmodule {

class FuncFunction;

class ExtModule : public ExternalModule
  {
  public:
    ExtModule();

    virtual ~ExtModule();

    virtual void destroy();

    virtual zorba::ExternalFunction*
    getExternalFunction(const zorba::String& aLocalname);

    virtual zorba::String
    getURI() const { return "http://zorba-tests.28.io/modules/ext"; }

  private:
    FuncFunction* theFunc;
  };

  class FuncFunction : public ContextualExternalFunction
  {
  public:
    FuncFunction(const ExtModule* aModule);

    virtual ~FuncFunction() {}

    virtual zorba::String
    getLocalName() const { return "func"; }

    virtual zorba::String
    getURI() const { return theModule->getURI(); }

    virtual zorba::ItemSequence_t
    evaluate(Arguments_t const& aArgs, zorba::StaticContext const* aSctx,
      zorba::DynamicContext const* aDctx) const;

  private:
    ExtModule const* theModule;
  };

} /* namespace extmodule */
} /* namespace zorba */


#endif /* ZORBA_EXT_H */
