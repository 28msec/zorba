/*
 * Copyright 2006-2010 The FLWOR Foundation.
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
#ifndef ZORBA_FILEMODULE_FILE_H
#define ZORBA_FILEMODULE_FILE_H

#include <map>
#include <zorba/zorba.h>
#include <zorba/external_module.h>
#include <zorba/function.h>

namespace zorba { namespace datetimemodule {

/******************************************************************************
 *****************************************************************************/
class DateTimeModule : public ExternalModule
{
protected:
  class ltstr
  {
  public:
    bool operator()(const String& s1, const String& s2) const
    {
      return s1.compare(s2) < 0;
    }
  };
  
  typedef std::map<String, ExternalFunction*, ltstr> FuncMap_t;

  FuncMap_t theFunctions;

public:
  virtual zorba::String
  getURI() const { return "http://www.zorba-xquery.com/modules/datetime"; }

  virtual zorba::ExternalFunction*
  getExternalFunction(const zorba::String& aLocalname);

  virtual void
  destroy();

  virtual
  ~DateTimeModule();
};


/******************************************************************************
 *****************************************************************************/
class CurrentDateTimeFunction : public ContextualExternalFunction
{
public:
  CurrentDateTimeFunction(const DateTimeModule* aModule)
    : theModule(aModule) {}

  virtual ~CurrentDateTimeFunction() {}

  virtual zorba::String
  getLocalName() const { return "current-dateTime"; }

  virtual zorba::ItemSequence_t
  evaluate(const Arguments_t&,
           const zorba::StaticContext*,
           const zorba::DynamicContext*) const;

  virtual String
  getURI() const { return theModule->getURI(); }

protected:
  const DateTimeModule* theModule;
};

/******************************************************************************
 *****************************************************************************/
class CurrentDateFunction : public ContextualExternalFunction
{
public:
  CurrentDateFunction(const DateTimeModule* aModule)
    : theModule(aModule) {}

  virtual ~CurrentDateFunction() {}

  virtual zorba::String
  getLocalName() const { return "current-date"; }

  virtual zorba::ItemSequence_t
  evaluate(const Arguments_t&,
           const zorba::StaticContext*,
           const zorba::DynamicContext*) const;

  virtual String
  getURI() const { return theModule->getURI(); }

protected:
  const DateTimeModule* theModule;
};

/******************************************************************************
 *****************************************************************************/
class CurrentTimeFunction : public ContextualExternalFunction
{
public:
  CurrentTimeFunction(const DateTimeModule* aModule)
    : theModule(aModule) {}

  virtual ~CurrentTimeFunction() {}

  virtual zorba::String
  getLocalName() const { return "current-time"; }

  virtual zorba::ItemSequence_t
  evaluate(const Arguments_t&,
           const zorba::StaticContext*,
           const zorba::DynamicContext*) const;

  virtual String
  getURI() const { return theModule->getURI(); }

protected:
  const DateTimeModule* theModule;
};

/******************************************************************************
 *****************************************************************************/
class TimestampFunction : public ContextualExternalFunction
{
public:
  TimestampFunction(const DateTimeModule* aModule)
    : theModule(aModule) {}

  virtual ~TimestampFunction() {}

  virtual zorba::String
  getLocalName() const { return "timestamp"; }

  virtual zorba::ItemSequence_t
  evaluate(const Arguments_t&,
           const zorba::StaticContext*,
           const zorba::DynamicContext*) const;

  virtual String
  getURI() const { return theModule->getURI(); }

protected:
  const DateTimeModule* theModule;
};

} /* namespace datetimemodule */ } /* namespace zorba */

#endif
