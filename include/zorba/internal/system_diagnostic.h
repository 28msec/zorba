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

#ifndef ZORBA_INTERNAL_SYSTEM_DIAGNOSTIC_H
#define ZORBA_INTERNAL_SYSTEM_DIAGNOSTIC_H

#include <map>

#include <zorba/diagnostic.h>

#include "ztd.h"

namespace zorba {
namespace internal {

///////////////////////////////////////////////////////////////////////////////

class ZORBA_DLL_PUBLIC SystemDiagnosticBase : public Diagnostic {
public:
  /**
   * Given a diagnostic's local-name, finds its corresponding %Diagnostic
   * object.
   *
   * @param localname The local-name.
   * @return Returns the corresponding %Diagnostic object or \c NULL if not
   * found.
   */
  static Diagnostic const* find( char const *localname ) {
    map_type const &m = get_map();
    map_type::const_iterator const i = m.find( localname );
    return i != m.end() ? i->second : 0;
  }

private:
  typedef std::map<char const*,Diagnostic const*,ztd::less<char const*> >
          map_type;

  static map_type& get_map();

  SystemDiagnosticBase( char const *localname ) {
    get_map()[ localname ] = this;
  }

  // Only a SystemDiagnostic can derive from SystemDiagnosticBase.
  template<class QNameType> friend class SystemDiagnostic;
};

/**
 * \internal
 * A %SystemDiagnostic is-a Diagnostic for built-in diagnostics.
 *
 * @tparam QNameType The QName type.
 */
template<class QNameType>
class ZORBA_DLL_PUBLIC SystemDiagnostic : public SystemDiagnosticBase {
public:

  /**
   * Constructs a %SystemDiagnostic.
   *
   * @param localname The local-name of the diagnostic.
   */
  SystemDiagnostic( char const *localname ) :
    SystemDiagnosticBase( localname ), qname_( localname )
  {
  }

  // inherited
  zorba::diagnostic::category category() const { return qname_.category(); }
  zorba::diagnostic::kind kind() const { return qname_.kind(); }
  zorba::diagnostic::QName const& qname() const { return qname_; }

protected:
  // inherited
  Diagnostic const* clone() const { return this; }
  void destroy() const { /* do nothing */ }

private:
  QNameType qname_;
};

///////////////////////////////////////////////////////////////////////////////

} // namespace internal
} // namespace zorba
#endif /* ZORBA_INTERNAL_SYSTEM_DIAGNOSTIC_H */
/* vim:set et sw=2 ts=2: */
