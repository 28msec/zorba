/*
 * Copyright 2006-2011 The FLWOR Foundation.
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
#ifndef ZORBA_MODULE_VERSION_H
#define ZORBA_MODULE_VERSION_H

#include <zorbatypes/zstring.h>

namespace zorba {

/**
 * The ModuleVersion class is a pair of a module namespace URI and a version
 * definition. A definition is one of the following:
 *
 *  A.B[.p] - represents major version A and minor version *at least* B
 *  A.B[.p]! - represents exactly major version A and minor version B, no other
 *  A.B[.p]-C.0 - represents any major version between A and C; if it is A, then
 *            the minor version must be at least B
 *
 * In all of the above, [.p] represents an optional patch version number. If
 * patch is not specified, it is assumed to be 0.
 *
 * A ModuleVersion may represent an explicit version (eg., the version of a
 * module which has actually been imported), or a requested version range (eg.,
 * a URI from an "import module" statement).
 */
class ModuleVersion {
public:
  /**
   * Construct a ModuleVersion from a string of the form "uri#ver"; that is, a
   * URI with the fragment being a version definition. If the URI does not have
   * a valid version definition, "#0.0.0-1000000.0.0" will be assumed - that is,
   * any available version. (In that case, namespace_uri() will return the
   * complete original URI passed to the constructor.)
   */
  ModuleVersion(zstring const& aUri);

  /**
   * Construct a ModuleVersion from a URI (presumed to not have a version
   * definition fragment) and a separate version definition string.
   */
  ModuleVersion(zstring const& aUri, zstring const& aVersionDef);

  /**
   * Returns whether the given ModuleVersion is "satisfied" by this
   * ModuleVersion, which means:
   *   1. The namespace URIs must be equal.
   *   2. The minimum major version of this ModuleVersion must be in the
   *      range [min_major, max_major] of the given ModuleVersion.
   *   3. If the minimum major of this ModuleVersion is equal to the given
   *      ModuleVersion's min_major, then the minimum minor version of this
   *      ModuleVersion must be in the range [min_minor, infinity), and the
   *      minimum patch version of this ModuleVersion must be in the range
   *      [min_patch, infinity).
   *   4. If the given ModuleVersion is "exact", then this ModuleVersion must
   *      have exactly the same min_major, max_major, and min_minor. If the
   *      given ModuleVersion has a non-zero min_patch, then this ModuleVersion
   *      must also have exactly the same min_patch.
   */
  bool satisfies(ModuleVersion const& aModuleVersion) const;

  /**
   * Return the namespace URI.
   */
  zstring const& namespace_uri() const {
    return theNamespaceURI;
  }

  /**
   * Return the minimum major version that satisifies the version definition.
   */
  int min_major() const {
    return theMinMajor;
  }

  /**
   * Return the maximum major version that satisifies the version definition.
   */
  int max_major() const {
    return theMaxMajor;
  }

  /**
   * Return the minimum minor version (for the minimum major version) that
   * satisfies the version definition.
   */
  int min_minor() const {
    return theMinMinor;
  }

  /**
   * Return the minimum patch version (for the minimum major version) that
   * satisfies the version definition.
   */
  int min_patch() const {
    return theMinPatch;
  }

  /**
   * Returns whether this version definition is exact.
   */
  bool is_exact() const {
    return theIsExact;
  }

  /**
   * Returns whether this ModuleVersion was initialized with a valid version
   * specification or not.
   */
  bool is_valid_version() const {
    return theValidVersion;
  }

  /**
   * Returns the full URI, complete with version definition.
   */
  zstring const& versioned_uri() const {
    return theVersionedURI;
  }

  /**
   * Returns the full versioned URI as a C string (so this class can be used as
   * a key in a zorba::hashmap).
   */
  const char* c_str() const {
    return theVersionedURI.c_str();
  }

private:

  bool initValues(zstring const& aVersionDef);

  int theMinMajor;
  int theMaxMajor;
  int theMinMinor;
  int theMinPatch;
  bool theIsExact;
  bool theValidVersion;
  zstring theNamespaceURI;
  zstring theVersionedURI;
};

} // namespace zorba

#endif // ZORBA_MODULE_VERSION_H
/* vim:set et sw=2 ts=2: */
