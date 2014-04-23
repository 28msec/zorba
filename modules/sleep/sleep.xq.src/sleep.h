/*
 * Copyright 2006-2014 The FLWOR Foundation.
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
#ifndef ZORBA_MODULES_SLEEP_H
#define ZORBA_MODULES_SLEEP_H

#include <zorba/zorba.h>
#include <zorba/external_module.h>
#include <zorba/function.h>

namespace zorba { namespace sleep {

class SleepModule : public ExternalModule
{
public:
  virtual ~SleepModule();

  virtual void destroy();

  virtual zorba::String
  getURI() const { return "http://zorba.io/modules/sleep"; }

  virtual zorba::ExternalFunction*
  getExternalFunction(const zorba::String& aLocalname);

protected:
  struct ltstr
  {
    bool operator()(const String& s1, const String& s2) const
    {
      return s1.compare(s2) < 0;
    }
  };

  typedef std::map<String, ExternalFunction*, ltstr> FuncMap_t;

  FuncMap_t theFunctions;
};


class MillisFunction : public ContextualExternalFunction
{
public:
  MillisFunction(const SleepModule* aModule)
    : theModule(aModule)
  {}

  virtual ~MillisFunction();

  virtual zorba::String
  getLocalName() const { return "millis"; }

  virtual zorba::String
  getURI() const { return theModule->getURI(); }

  virtual zorba::ItemSequence_t
  evaluate(const Arguments_t&,
           const zorba::StaticContext*,
           const zorba::DynamicContext*) const;

protected:
  const SleepModule* theModule;
};

} /* namespace sleep */ } /* namespace zorba */

#ifdef WIN32
#  define DLL_EXPORT __declspec(dllexport)
#else
#  define DLL_EXPORT __attribute__ ((visibility("default")))
#endif
extern "C" DLL_EXPORT zorba::ExternalModule* createModule() {
  return new zorba::sleep::SleepModule();
}

#endif
