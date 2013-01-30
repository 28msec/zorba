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
#include "stdafx.h"

#include "api/auditimpl.h"

#include <iostream>
#include <stdexcept>
#include <cassert>
#include <cstring>
#include <memory>

namespace zorba {
namespace audit {

//************************************************************************
// PropertyGroupImpl
//************************************************************************

const char* XQUERY_COMPILATION_PATH[] = { "xquery", "compilation" };

const PropertyGroupImpl EMPTY_OBJECT      (0, NULL);
const PropertyGroupImpl XQUERY_COMPILATION(2, XQUERY_COMPILATION_PATH);

PropertyGroupImpl::PropertyGroupImpl(const size_t pathLength, const char** path)
  : m_pathLength(pathLength), m_path(path) {
}

size_t PropertyGroupImpl::pathLength() const {
  return m_pathLength;
}

const char* PropertyGroupImpl::getSegment(size_t i) const {
  return i < m_pathLength ? *(m_path + i) : "";
}

//************************************************************************
// Property
//************************************************************************

Property::~Property() {
}

//************************************************************************
// PropertyImpl
//************************************************************************

const PropertyImpl INVALID("");

const PropertyImpl XQUERY_COMPILATION_FILENAME(
    XQUERY_COMPILATION, "filename", 0, Property::STRING);

const PropertyImpl XQUERY_COMPILATION_PARSE_DURATION(
    XQUERY_COMPILATION, "parse-duration", 1, Property::INT);

const PropertyImpl XQUERY_COMPILATION_TRANSLATION_DURATION(
    XQUERY_COMPILATION, "translation-duration", 2, Property::INT);

const PropertyImpl XQUERY_COMPILATION_OPTIMIZATION_DURATION(
    XQUERY_COMPILATION, "optimization-duration", 3, Property::INT);

const PropertyImpl XQUERY_COMPILATION_CODEGENERATION_DURATION(
    XQUERY_COMPILATION, "codegeneration-duration", 4, Property::INT);

const PropertyImpl* PROPERTIES[] = {
  &XQUERY_COMPILATION_FILENAME,
  &XQUERY_COMPILATION_PARSE_DURATION,
  &XQUERY_COMPILATION_TRANSLATION_DURATION,
  &XQUERY_COMPILATION_OPTIMIZATION_DURATION,
  &XQUERY_COMPILATION_CODEGENERATION_DURATION
};

PropertyImpl::PropertyImpl(const PropertyGroup& g, const char n[], long i, Type t)
  : m_group(g), m_id(i), m_type(t) {
  String result;
  for (size_t i = 0; i < m_group.pathLength(); ++i) {
    result.append(m_group.getSegment(i)).append("/");
  }
  result.append(n);
  m_name = new char[result.size() + 1];
  strcpy(m_name, result.c_str());
}

PropertyImpl::PropertyImpl(const String& n)
  : m_group(EMPTY_OBJECT), m_id(-1), m_type(Property::STRING) {
  m_name = new char[n.size() + 1];
  strcpy(m_name, n.c_str());
}

PropertyImpl::~PropertyImpl() {
  delete [] m_name;
}

const PropertyGroup& PropertyImpl::group() const {
  return m_group;
}

const char* PropertyImpl::name() const {
  return m_name;
}

long PropertyImpl::id() const {
  return m_id;
}

Property::Type PropertyImpl::type() const {
  return m_type;
}

//************************************************************************
// Observation
//************************************************************************

Observation::~Observation() {
}

//************************************************************************
// ObservationImpl
//************************************************************************

ObservationImpl::ObservationImpl(const Property& property, long long value)
  : m_property(&property) {
  m_value.l = value;
}

ObservationImpl::ObservationImpl(const Property& property, size_t value,
                                 const std::vector<String>* strings)
  : m_property(&property), m_strings(strings) {
  m_value.s = value;
}

const Property& ObservationImpl::property() const {
  return *m_property;
}

const String& ObservationImpl::stringValue() const {
  return m_strings->at(m_value.s);
}

long long ObservationImpl::longValue() const {
  return m_value.l;
}

//************************************************************************
// Configuration
//************************************************************************

Configuration::~Configuration() {
}

void Configuration::getPropertyNames(std::vector<String>& names) {
  size_t len = getPropertyCount();
  for (size_t i = 0; i < len; ++i) {
    names.push_back(PROPERTIES[i]->name());
  }
}

size_t Configuration::getPropertyCount() {
  return sizeof(PROPERTIES) / sizeof(PROPERTIES[0]);
}

const Property& Configuration::getProperty(size_t i) {
  return *(PROPERTIES[i]);
}

bool Configuration::enableProperty(
  Configuration* aConfig,
  const std::vector<String>& somePropertyNames,
  const String& aPropertyName) {
  for (size_t i = 0; i < somePropertyNames.size(); ++i) {
    if (somePropertyNames.at(i) == aPropertyName) {
      aConfig->enableAudit(i);
      return true;
    }
  }
  aConfig->enableAudit(aPropertyName);
  return false;
}

//************************************************************************
// ConfigurationImpl
//************************************************************************

ConfigurationImpl::ConfigurationImpl(size_t size)
  : m_size(size), m_enabled(0) {
  m_enabled = new bool[m_size];
  for (bool* itr = m_enabled; itr < m_enabled + m_size; ++itr) {
    *itr = false;
  }
}

ConfigurationImpl::~ConfigurationImpl() {
  for (DynPropsMap::iterator it = m_dyn_props.begin();
       it != m_dyn_props.end(); ++it) {
    delete (*it).second;
  }
  delete [] m_enabled;
}

size_t ConfigurationImpl::size() const {
  return m_size;
}

void ConfigurationImpl::enableAudit(size_t i) {
  m_enabled[i] = true;
}

void ConfigurationImpl::enableAudit(const String& aPropertyName) {
  DynPropsMap::const_iterator it = m_dyn_props.find(aPropertyName);
  if (it == m_dyn_props.end()) {
    std::auto_ptr<PropertyImpl> lImpl(new PropertyImpl(aPropertyName));
    m_dyn_props[aPropertyName] = lImpl.release();
  }
}

bool ConfigurationImpl::auditEnabled(size_t i) const {
  return m_enabled[i];
}

bool ConfigurationImpl::auditEnabled(const String& aPropertyName) const {
  return m_dyn_props.find(aPropertyName) != m_dyn_props.end();
}

const Property* ConfigurationImpl::getDynamicProperty(const String& prop_name) const {
  DynPropsMap::const_iterator it = m_dyn_props.find(prop_name);
  if (it != m_dyn_props.end()) {
    return (*it).second;
  }
  return &INVALID;
}

std::ostream& ConfigurationImpl::write(std::ostream& os) const {
  for (size_t i = 0; i < this->size(); ++i) {
    String line(m_enabled[i] ? "[X] " : "[ ] ");
    line.append(Configuration::getProperty(i).name());
    os << line;
  }
  return os;
}

//************************************************************************
// Record
//************************************************************************

Record::~Record() {
}

//************************************************************************
// RecordImpl
//************************************************************************

const PropertyGroup& RecordImpl::group() const {
  return m_parameters.size() > 0 ?  m_parameters.at(0).property().group() : EMPTY_OBJECT;
}

size_t RecordImpl::size() const {
  return m_parameters.size();
}

const Observation& RecordImpl::at(size_t i) const {
  return m_parameters.at(i);
}

void RecordImpl::add(const Property& prop, long long val) {
  assert(&(group()) == &EMPTY_OBJECT || &(group()) == &(prop.group()));
  m_parameters.push_back(ObservationImpl(prop, val));
}

void RecordImpl::add(const Property& prop, const String& val) {
  assert(&(group()) == &EMPTY_OBJECT || &(group()) == &(prop.group()));
  const size_t pos = m_event->m_strings.size();
  m_event->m_strings.push_back(val);
  m_parameters.push_back(ObservationImpl(prop, pos, &m_event->m_strings));
}

//************************************************************************
// EventImpl
//************************************************************************

EventImpl::EventImpl(const Configuration* config)
  : m_provider(0), m_config(config) {
}

EventImpl::~EventImpl() {
  std::set<RecordImpl*>::iterator itrA = m_recordsActive.begin();
  std::set<RecordImpl*>::iterator endA = m_recordsActive.end();
  while (itrA != endA) {
    delete *itrA;
    ++itrA;
  }
  m_recordsActive.clear();

  std::vector<RecordImpl*>::iterator itrS = m_recordsSubmitted.begin();
  std::vector<RecordImpl*>::iterator endS = m_recordsSubmitted.end();
  while (itrS != endS) {
    delete *itrS;
    ++itrS;
  }
  m_recordsSubmitted.clear();
}

bool EventImpl::audit(const Property& prop) const {
  return m_config->auditEnabled(prop.id());
}

bool EventImpl::audit(const String& prop_name) const {
  return m_config->auditEnabled(prop_name);
}

const Property* EventImpl::getDynamicProperty(const String& prop_name) const {
  return m_config->getDynamicProperty(prop_name);
}

Record* EventImpl::createRecord() {
  RecordImpl* rec = new RecordImpl(this);
  m_recordsActive.insert(rec); // TODO duplicates?
  return rec;
}

void EventImpl::submitRecord(Record* rec) {
  RecordImpl* reci = dynamic_cast<RecordImpl*>(rec);
  if (reci == 0) {
    throw "unknown record"; // TODO error handling
  }
  std::set<RecordImpl*>::iterator itr = m_recordsActive.find(reci);
  if (itr == m_recordsActive.end()) {
    throw "unknown record"; // TODO error handling
  }
  m_recordsActive.erase(itr);
  m_recordsSubmitted.push_back(reci);
}

size_t EventImpl::size() const {
  return m_recordsSubmitted.size();
}

const Record* EventImpl::at(size_t i) const {
  return m_recordsSubmitted.at(i);
}

std::ostream& EventImpl::write(std::ostream& os) const {
  os << std::dec;
  os << "<event>" << std::endl;
  for (size_t i = 0; i < this->size(); ++i) {
    const Record* record = this->at(i);
    os << "  <record>" << std::endl;
    for (size_t j = 0; j < record->size(); ++j) {
      const Observation& param = record->at(j);
      os << "    <property name=\"" << param.property().name() << "\">";
      switch (param.property().type()) {
      case Property::INT:
        os << param.longValue();
        break;
      case Property::STRING:
        os << param.stringValue();
        break;
      }
      os <<"</property>" << std::endl;
    }
    os << "  </record>" << std::endl;
  }
  os << "</event>" << std::endl;
  return os;
}

//************************************************************************
// NOPEventImpl
//************************************************************************

NOPEventImpl::NOPEventImpl() {}
NOPEventImpl::~NOPEventImpl() {}

bool NOPEventImpl::audit(const Property&) const {
  return false;
}

bool NOPEventImpl::audit(const String&) const {
  return false;
}

const Property* NOPEventImpl::getDynamicProperty(const String&) const {
  return 0;
}

Record* NOPEventImpl::createRecord() {
  return 0;
}

void NOPEventImpl::submitRecord(Record*) {
}

size_t  NOPEventImpl::size() const {
  return 0;
}

const Record* NOPEventImpl::at(size_t) const {
  return 0;
} 

std::ostream& NOPEventImpl::write(std::ostream& os) const {
  return os;
}

NOPEventImpl NOP_EVENT_IMPL;

//************************************************************************
// Event
//************************************************************************

Event::~Event() {
}

Event*
Event::get() {
  return &NOP_EVENT_IMPL;
}

//************************************************************************
// Provider
//************************************************************************

Provider::~Provider() {
}

//************************************************************************
// ProviderImpl
//************************************************************************

Configuration* ProviderImpl::createConfiguration(size_t size) {
  if (!size) {
    size = Configuration::getPropertyCount();
  }
  return new ConfigurationImpl(size);
}

void ProviderImpl::destroyConfiguration(Configuration* config) {
  delete config;
}

Event* ProviderImpl::createEvent(const Configuration* config) {
  return new EventImpl(config);
}

void ProviderImpl::submitEvent(Event* event) {
  delete event;
}

ProviderImpl PROVIDER_IMPL;

}
}

/* vim:set et sw=2 ts=2: */
