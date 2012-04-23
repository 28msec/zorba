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
#pragma once

#ifndef ZORBA_API_AUDIT_IMPL_H
#define ZORBA_API_AUDIT_IMPL_H

#include <zorba/audit.h>
#include <zorba/audit_scoped.h>
#include <map>
#include <set>
#include "zorbatypes/zstring.h"

namespace zorba {
namespace audit {

  class Provider;
  class EventImpl;

  class PropertyGroupImpl : public PropertyGroup {
  public:

    PropertyGroupImpl(const size_t pathLength, const char** path);

    virtual size_t      pathLength()       const;
    virtual const char* getSegment(size_t) const;

  private:
    const size_t m_pathLength;
    const char** m_path;
  };

  extern const PropertyGroupImpl XQUERY_COMPILATION;

  class PropertyImpl : public Property {
  public:

    /**
     * constructor for "static" audit properties (properties defined in zorba)
     */
    PropertyImpl(const PropertyGroup& g, const char n[], long i, Type t);
    /**
     * constructor for "dynamic" audit properties (properties defined by users
     * of the audit facility)
     */
    PropertyImpl(const String& n);
    virtual ~PropertyImpl();

    const PropertyGroup& group() const;
    const char*          name()  const;
    long                 id()    const;
    Type                 type()  const;

  private:
    PropertyImpl(const PropertyImpl&); // not implemented
    PropertyImpl& operator=(const PropertyImpl&);  // not implemented

    const PropertyGroup& m_group;
    char*                m_name;
    const long           m_id;
    const Type           m_type;
  };

  extern const PropertyImpl XQUERY_COMPILATION_FILENAME;
  extern const PropertyImpl XQUERY_COMPILATION_PARSE_DURATION;
  extern const PropertyImpl XQUERY_COMPILATION_TRANSLATION_DURATION;
  extern const PropertyImpl XQUERY_COMPILATION_OPTIMIZATION_DURATION;
  extern const PropertyImpl XQUERY_COMPILATION_CODEGENERATION_DURATION;

  class ObservationImpl : public Observation {
  public:
    union Value {
      long long l;
      size_t    s;
    };

    ObservationImpl(const Property& property, long long value);
    ObservationImpl(const Property& property, size_t value, const std::vector<String>*);

    virtual const Property&    property()    const;
    virtual const String& stringValue() const;
    virtual long long          longValue()   const;

  private:
    const Property*                 m_property;
    union Value                     m_value;
    const std::vector<String>* m_strings;
  };

  class ConfigurationImpl : public Configuration {
  public:

    virtual size_t size() const;
    virtual void   enableAudit(size_t i);
    virtual void   enableAudit(const String& aPropertyName);
    virtual bool   auditEnabled(size_t i) const;
    virtual bool   auditEnabled(const String& aPropertyName) const;

    virtual const Property* getDynamicProperty(const String& prop_name) const;

    virtual std::ostream& write(std::ostream&) const;
  private:
    typedef std::map<const String, const Property*> DynPropsMap;

    friend class EventImpl;
    friend class ProviderImpl;

    ConfigurationImpl(size_t size);
    ConfigurationImpl(const ConfigurationImpl&); // not implemented
    ConfigurationImpl& operator=(const ConfigurationImpl&);  // not implemented
    virtual ~ConfigurationImpl();

    size_t m_size;
    bool* m_enabled;
    DynPropsMap m_dyn_props;
  };

  class RecordImpl : public Record {
  public:
    virtual const PropertyGroup& group() const;

    virtual size_t             size()       const;
    virtual const Observation& at(size_t i) const;

    virtual void add(const Property& prop, long long val);
    virtual void add(const Property& prop, const String& val);

  private:
    friend class EventImpl;

    RecordImpl(EventImpl* event) : m_event(event) {}
    virtual ~RecordImpl() {}
    
    EventImpl* m_event;
    std::vector<ObservationImpl> m_parameters;
  };

  class EventImpl : public Event {
  public:
    EventImpl(const Configuration* config);
    virtual ~EventImpl();

    virtual bool audit(const Property& prop) const;
    virtual bool audit(const String& prop_name) const;

    virtual const Property* getDynamicProperty(const String& prop_name) const;

    virtual Record* createRecord();
    virtual void    submitRecord(Record*);

    virtual size_t        size()       const;
    virtual const Record* at(size_t i) const;

    virtual std::ostream& write(std::ostream&) const;

  private:
    friend class RecordImpl;

    EventImpl(const Event&); // not implemented
    Event& operator=(const Event&); // not implemented

    Provider*                m_provider;
    const Configuration*     m_config;
    std::set<RecordImpl*>    m_recordsActive;
    std::vector<RecordImpl*> m_recordsSubmitted;
    std::vector<String> m_strings;
  };

  class NOPEventImpl : public Event {
  public:
    NOPEventImpl();
    virtual ~NOPEventImpl();

    virtual bool audit(const Property& prop) const;
    virtual bool audit(const String& prop_name) const;

    virtual const Property* getDynamicProperty(const String&) const;

    virtual Record* createRecord();
    virtual void    submitRecord(Record*);

    virtual size_t        size()       const;
    virtual const Record* at(size_t i) const;

    virtual std::ostream& write(std::ostream&) const;
  };

  extern NOPEventImpl NOP_EVENT_IMPL;

  class ProviderImpl : public Provider {
  public:
    virtual Configuration* createConfiguration(size_t);
    virtual void           destroyConfiguration(Configuration*);

    virtual Event* createEvent(const Configuration*);
    virtual void   submitEvent(Event*);
  };

  extern ProviderImpl PROVIDER_IMPL;
}
}

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
