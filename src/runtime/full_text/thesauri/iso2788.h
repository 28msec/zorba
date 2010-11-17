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

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

/**
 * ISO 2788: Guidelines for the establishment and development of monolingual
 * thesauri.
 */
namespace iso2788 {

  /**
   * Relationship abbreviations from section 4.1.
   */
  enum rel_type {
    unknown,
    BT,   // broader term
    BTG,  // broader term (generic)
    BTP,  // broader term (partitive)
    NT,   // narrower term
    NTG,  // narrower term (generic)
    NTP,  // narrower term (partitive)
    RT,   // related term
    TT,   // top term
    UF,   // non-preferred term
    USE,  // preferred term
  };
  extern char const *const string_of[];

  /**
   * Attempts to find the ISO-2788 relationship corresponding to the given
   * string.
   *
   * @param relationship The relationship to find.  It must be lower-case.
   * @return Returns the corresponding relationship or \c unknown.
   */
  rel_type find_rel( char const *relationship );

  /**
   * Attempts to find the ISO-2788 relationship corresponding to the given
   * string.
   *
   * @tparam The string type.
   * @param relationship The relationship to find.  It must be lower-case.
   * @return Returns the corresponding relationship or \c unknown.
   */
  template<class StringType> inline
  rel_type find_rel( StringType const &relationship ) {
    return find_rel( relationship.c_str() );
  }
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
#endif  /* ZORBA_ISO_2788_H */
/* vim:set et sw=2 ts=2: */
