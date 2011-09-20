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

#include "stdafx.h"

#include "module_version.h"
#include <zorbatypes/URI.h>


namespace zorba {

/**
 * Utility function: Given a string aStr and position aPos, populate
 * aInt with the integer at that position in the string. aPos will be
 * updated to next character.
 * @return true if an integer found, false if not.
 */
static bool
getInteger(zstring const& aStr, size_t& aPos, int& aInt)
{
  char lChar;
  size_t lLen = aStr.length();
  size_t const lOrigPos = aPos;

  aInt = 0;
  while (aPos < lLen && isdigit(lChar = aStr[aPos])) {
    aInt = aInt * 10 + (lChar - '0');
    aPos++;
  }
  return (aPos != lOrigPos);
}


ModuleVersion::ModuleVersion(zstring const& aUri)
  : theMinMajor(0),
    theMaxMajor(1000000),
    theMinMinor(0),
    theMinPatch(0),
    theIsExact(false),
    theValidVersion(false),
    theNamespaceURI(aUri),
    theVersionedURI(aUri)
{
  URI lUri(aUri);

  // Check for fragment in URI; if none, no versioning to be attempted.
  zstring const lFrag = lUri.get_encoded_fragment();
  if (lFrag == "") {
    return;
  }

  if (initValues(lFrag)) {
    lUri.clear_fragment();
    theNamespaceURI = lUri.toString();
  }
}

ModuleVersion::ModuleVersion(zstring const& aUri, zstring const& aVersionDef)
  : theMinMajor(0),
    theMaxMajor(1000000),
    theMinMinor(0),
    theMinPatch(0),
    theIsExact(false),
    theValidVersion(false),
    theNamespaceURI(aUri),
    theVersionedURI(aUri)
{
  if (initValues(aVersionDef)) {
    // "cons up" a fully-versioned URI
    theVersionedURI.append("#");
    theVersionedURI.append(aVersionDef);
  }
}

bool
ModuleVersion::initValues(zstring const& aVersionDef)
{
  // Parse fragment for legal version specification. If any illegal
  // characters found, no versioning to be attempted.
  int lMajor, lMinor, lPatch = 0, lMajorB = -1;
  bool lExact = false;
  size_t lPos = 0;
  size_t lLen = aVersionDef.length();
  if (!getInteger(aVersionDef, lPos, lMajor)) {
    return false;
  }
  if (lPos >= lLen) {
    return false;
  }
  if (aVersionDef[lPos++] != '.') {
    return false;
  }
  if (!getInteger(aVersionDef, lPos, lMinor)) {
    return false;
  }
  if (lPos < lLen && aVersionDef[lPos] == '.') {
    // There's (potentially) a patch version specified as well
    lPos ++;
    if (lPos >= lLen) {
      return false;
    }
    if (!getInteger(aVersionDef, lPos, lPatch)) {
      return false;
    }
  }
  if (lPos < lLen) {
    // Found legal major.minor, but there's more to parse - could be "!"
    // or "-major.0"
    char lChar = aVersionDef[lPos++];
    if (lChar == '!' && lPos == lLen) {
      lExact = true;
    }
    else if (lChar == '-') {
      if (!getInteger(aVersionDef, lPos, lMajorB)) {
        return false;
      }
      if (lPos >= lLen || aVersionDef[lPos++] != '.') {
        return false;
      }
      if (lPos >= lLen || aVersionDef[lPos++] != '0') {
        return false;
      }
    }
    else {
      return false;
    }
  }

  // Verify there's no more to read.
  if (lPos != lLen) {
    return false;
  }

  // Ok, we successfully parsed a version definition; set all our variables.
  theMinMajor = lMajor;
  theMinMinor = lMinor;
  theMinPatch = lPatch;
  theMaxMajor = lMajorB == -1 ? lMajor : lMajorB;
  theIsExact = lExact;
  theValidVersion = true;
  return true;
}

bool
ModuleVersion::satisfies(const ModuleVersion &aOther) const
{
  // 1. The namespace URIs must be equal.
  if (theNamespaceURI != aOther.namespace_uri()) {
    return false;
  }

  // 4. If the given ModuleVersion is "exact", then this ModuleVersion must
  // have exactly the same min_major, max_major, and min_minor. If the given
  // ModuleVersion has a non-zero min_patch, then this ModuleVersion must also
  // have exactly the same min_patch.
  if (aOther.is_exact()) {
    int const lOtherMinPatch = aOther.min_patch();
    return (theMinMajor == aOther.min_major() &&
            theMaxMajor == aOther.max_major() &&
            theMinMinor == aOther.min_minor() &&
            (lOtherMinPatch == 0 || theMinPatch == lOtherMinPatch));
  }

  // 2. The minimum major version of this ModuleVersion must be in the range
  // [min_major, max_major] of the given ModuleVersion.
  if (theMinMajor < aOther.min_major() || theMinMajor > aOther.max_major()) {
    return false;
  }

  // 3. If the minimum major of this ModuleVersion is equal to the given
  // ModuleVersion's min_major, then the minimum minor version of this
  // ModuleVersion must be in the range [min_minor, infinity).
  if (theMinMajor == aOther.min_major() && theMinMinor < aOther.min_minor()) {
    return false;
  }

  return true;
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
