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

#ifndef ZORBA_ERROR_API_H
#define ZORBA_ERROR_API_H

#include <zorba/internal/system_diagnostic.h>
#include <zorba/internal/qname.h>

namespace zorba {

class Diagnostic;
namespace serialization {
  class Archiver;
  void operator&( serialization::Archiver&, const Diagnostic*& );
}

///////////////////////////////////////////////////////////////////////////////

typedef Diagnostic Error;

/**
 * An %XQueryErrorCode is a diagnostic for all XQuery-specific errors.
 */
typedef internal::SystemDiagnostic<internal::XQueryErrQName> XQueryErrorCode;

/**
 * A %ZorbaErrorCode is a diagnostic for all Zorba-specific errors.
 */
typedef internal::SystemDiagnostic<internal::ZorbaErrQName> ZorbaErrorCode;

///////////////////////////////////////////////////////////////////////////////

/**
 * A %UserError is-a Diagnostic for user-defined errors via \c fn:error().
 */
class ZORBA_DLL_PUBLIC UserError : public Diagnostic {
public:
  /**
   * Copy-constructs a %UserError.
   *
   * @param from The %UserError to copy from.
   */
  UserError( UserError const &from );

  /**
   * Destroys this %UserError.
   */
  ~UserError();

  /**
   * Assigns this %UserError from another.
   *
   * @param from The %UserError to assign from.
   * @return Returns \c *this.
   */
  UserError& operator=( UserError const &from );

  // inherited
  diagnostic::QName const& qname() const;
  diagnostic::category category() const;

protected:
  // inherited
  Diagnostic const* clone() const;

private:
  typedef internal::VariableQName<std::string> QName;
  QName qname_;

  /**
   * Constructs a %UserError.
   *
   * @param ns The error's namespace URI.
   * @param prefix The error's prefix.
   * @param localname The error's local-name.
   */
  UserError( char const *ns, char const *prefix, char const *localname );

  friend class UserException;
  friend UserError make_user_error( char const*, char const*, char const* );

  // for plan serialization
  UserError( serialization::Archiver& );
  friend void serialization::operator&( serialization::Archiver&,
                                        const Diagnostic*& );
};

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
#endif /* ZORBA_ERROR_API_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
