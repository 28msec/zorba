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

#ifndef ZORBA_AUDIT_H
#define ZORBA_AUDIT_H

#include <iostream>
#include <vector>
#include <zorba/config.h>
#include <zorba/zorba_string.h>

namespace zorba {
namespace audit {

  /**
    * an identifier for a set of pieces of information that can be audited
    * together.
    * It is assumed that all instances of PropertyGroup are created statically
    * and that they exist while a process exists.
    */
  class ZORBA_DLL_PUBLIC PropertyGroup {
  public:
    virtual size_t      pathLength()       const = 0;
    virtual const char* getSegment(size_t) const = 0;
  };

  /**
    * an identifier for a specific piece of information that can be audited.
    * It is assumed that all instances of Property are created statically
    * and that they exist while a process exists.
    */
  class ZORBA_DLL_PUBLIC Property {
  public:
    enum Type {
      INT,
      STRING
    };

    virtual ~Property();

    virtual const PropertyGroup& group() const = 0;
    virtual const char*          name()  const = 0;
    virtual long                 id()    const = 0;
    virtual Type                 type()  const = 0;
  };

  class ZORBA_DLL_PUBLIC Observation {
  public:
    virtual const Property&    property()    const = 0;
    virtual const String& stringValue() const = 0;
    virtual long long          longValue()   const = 0;
  };

  class ZORBA_DLL_PUBLIC Configuration {
  public:
    static void            getPropertyNames(std::vector<String>&);
    static size_t          getPropertyCount();
    static const Property& getProperty(size_t i);
    static bool            enableProperty(Configuration*, const std::vector<String>&, const String&);

    virtual size_t size() const                                         = 0;
    virtual void   enableAudit(size_t i)                                = 0;
    virtual void   enableAudit(const String& aPropertyName)        = 0;
    virtual bool   auditEnabled(size_t i) const                         = 0;
    virtual bool   auditEnabled(const String& aPropertyName) const = 0;

    virtual const Property* getDynamicProperty(const String&) const = 0;

    virtual std::ostream& write(std::ostream&) const = 0;
    
    virtual ~Configuration() {}
  };

  class ZORBA_DLL_PUBLIC Record {
  public:
    virtual const PropertyGroup& group() const = 0;

    virtual size_t             size()       const = 0;
    virtual const Observation& at(size_t i) const = 0;

    virtual void add(const Property& prop, long long val)          = 0;
    virtual void add(const Property& prop, const String& val) = 0;
  };

  class ZORBA_DLL_PUBLIC Event {
  public:
    static Event* get();

    virtual bool audit(const Property&) const = 0;
    virtual bool audit(const String&) const = 0;

    virtual const Property* getDynamicProperty(const String&) const = 0;

    virtual Record* createRecord()        = 0;
    virtual void    submitRecord(Record*) = 0;

    virtual size_t        size()     const = 0;
    virtual const Record* at(size_t) const = 0;

    virtual std::ostream& write(std::ostream&) const = 0;
    
    virtual ~Event() {}
  };

  class ZORBA_DLL_PUBLIC Provider {
  public:
    virtual Configuration* createConfiguration(size_t = 0)      = 0;
    virtual void           destroyConfiguration(Configuration*) = 0;

    virtual Event* createEvent(const Configuration*) = 0;
    virtual void   submitEvent(Event*)               = 0;
  };

} /* namespace audit */
} /* namespace zorba */

inline std::ostream& operator<<(std::ostream& os, const zorba::audit::Configuration& c) {
  return c.write(os);
}

inline std::ostream& operator<<(std::ostream& os, const zorba::audit::Event& e) {
  return e.write(os);
}

#endif
/* vim:set et sw=2 ts=2: */
