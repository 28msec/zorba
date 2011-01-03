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

#ifndef ZORBA_ISO_2788_H
#define ZORBA_ISO_2788_H

#include <iostream>

#include "zorbautils/locale.h"

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

/**
 * ISO 2788: Guidelines for the establishment and development of monolingual
 * thesauri.
 *
 * ANSI/NISO Z39.19-2005: Guidelines for the Construction, Format, and
 * Management of Monolingual Controlled Vocabularies.
 */
namespace iso2788 {

  /**
   * Relationship abbreviations from ISO 2788 section 4.1 and ANSI Z39.19-2005
   * section 4.2.  Note: we do not implement "HN" (History Note) or "X SN" (See
   * Scope Note for...).
   */
  enum rel_type {
    unknown,
    BT,   ///< Broader Term
    BTG,  ///< Broader Term (generic)
    BTI,  ///< Broader Term (instance)
    BTP,  ///< Broader Term (partitive)
    NT,   ///< Narrower Term
    NTG,  ///< Narrower Term (generic)
    NTI,  ///< Narrower Term (instance)
    NTP,  ///< Narrower Term (partitive)
    RT,   ///< Related Term
    SN,   ///< Scope Note
    TT,   ///< Top Term
    UF,   ///< Non-preferred Term
    USE,  ///< Preferred Term
  };
  extern char const *const string_of[];

  inline std::ostream& operator<<( std::ostream &o, rel_type t ) {
    return o << string_of[ t ];
  }

  /**
   * Attempts to find the ISO-2788 relationship corresponding to the given
   * string.
   *
   * @param relationship The relationship to find.  It must be lower-case.
   * @param lang The language of the relationship.
   * @return Returns the corresponding relationship or \c unknown.
   */
  rel_type find_rel( char const *relationship, locale::iso639_1::type lang );

  /**
   * Attempts to find the ISO-2788 relationship corresponding to the given
   * string.
   *
   * @tparam The string type.
   * @param relationship The relationship to find.  It must be lower-case.
   * @param lang The language of the relationship.
   * @return Returns the corresponding relationship or \c unknown.
   */
  template<class StringType> inline
  rel_type find_rel( StringType const &relationship,
                     locale::iso639_1::type lang ) {
    return find_rel( relationship.c_str(), lang );
  }
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
#endif  /* ZORBA_ISO_2788_H */
/* vim:set et sw=2 ts=2: */
