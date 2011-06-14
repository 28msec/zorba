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

#ifndef ZORBA_AUDIT_SCOPED_H
#define ZORBA_AUDIT_SCOPED_H

#include <iostream>
#include <sstream>
#include <zorba/audit.h>
#include <zorba/util/timer.h>

namespace zorba {
namespace audit {

  class ZORBA_DLL_PUBLIC ScopedRecord {
  public:
    ScopedRecord(Event* event) : theEvent(event), theRecord(0) {
    }

    ~ScopedRecord() {
      if (theRecord) {
        theEvent->submitRecord(theRecord);
        theRecord = 0;
      }
    }

    Event* getEvent() {
      return theEvent;
    }

    Record* getRecord() {
      if (! theRecord) {
        theRecord = theEvent->createRecord();
      }
      return theRecord;
    }

  private:
      Event*  theEvent;
      Record* theRecord;
  };

  template <class T> struct AuditorTraits {
  };

  template <class T> class ScopedAuditor {
  public:
    ScopedAuditor(ScopedRecord& record, const Property& prop, T& value)
      : theRecord(record), theProperty(prop), theValue(value) {
      theNeedToAuditFlag = record.getEvent()->audit(prop);
      if (theNeedToAuditFlag) {
        AuditorTraits<T>::start(value);
      }
    }

    ScopedAuditor(ScopedRecord& record, const String& prop_name, T& value)
      : theRecord(record),
        theProperty(*record.getEvent()->getDynamicProperty(prop_name)),
        theValue(value) {
      theNeedToAuditFlag = record.getEvent()->audit(prop_name);
      if (theNeedToAuditFlag) {
        AuditorTraits<T>::start(value);
      }
    }

    ~ScopedAuditor() {
      now();
    }

    void now() {
      if (theNeedToAuditFlag) {
        Record* rec = theRecord.getRecord();
        rec->add(theProperty, AuditorTraits<T>::end(theValue));
        theNeedToAuditFlag = false;
      }
    }

  private:
    ScopedRecord&   theRecord;
    const Property& theProperty;
    bool            theNeedToAuditFlag;
    T&              theValue;
  };

  typedef ScopedAuditor<zorba::time::Timer> ScopedTimeAuditor;

  template<> struct AuditorTraits<String> {
    typedef String value_type;
    typedef String audit_type;
    static inline void start(value_type& value) {
    }
    static inline audit_type end(value_type& value) {
      return value;
    }
  };

  template<> struct AuditorTraits< std::pair<std::streampos, std::istream*> > {
    typedef std::pair<std::streampos, std::istream*> value_type;
    typedef long long      audit_type;
    static inline void start(value_type& value) {
      value.first = value.second->tellg();
    }
    static inline audit_type end(value_type& value) {
      return value.second->tellg() - value.first;
    }
  };

  template<> struct AuditorTraits<zorba::time::Timer> {
    typedef zorba::time::Timer value_type;
    typedef long long          audit_type;
    static inline void start(value_type& value) {
      value.start();
    }
    static inline audit_type end(value_type& value) {
      return value.elapsed();
    }
  };

}
}
#endif
