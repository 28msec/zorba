/*
 * Copyright 2006-2010 The FLWOR Foundation.
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

#include <context/default_uri_mappers.h>
#include <context/default_url_resolvers.h>
#include <util/uri_util.h>
#include <util/fs_util.h>
#include <zorbatypes/URI.h>
#include <context/static_context.h>
#include <compiler/translator/module_version.h>

#include <cctype>

namespace zorba {

namespace internal {

/******
 * Fileize mapper.
 ******/

void
FileizeURIMapper::mapURI(
    zstring const& aUri,
    EntityData const* aEntityData,
    static_context const& aSctx,
    std::vector<zstring>& oUris)
{
  // File-izing isn't for collections. Also, Thesauri use fake URIs that can
  // choke our URI class, so skip them.
  EntityData::Kind lKind = aEntityData->getKind();
  if (lKind == EntityData::COLLECTION
#ifndef ZORBA_NO_FULL_TEXT
      || lKind == EntityData::THESAURUS
#endif
      ) {
    return;
  }

  // Append extension / filename as necessary.
  zstring lExtension;
  switch (lKind)
  {
    case EntityData::SCHEMA:
      lExtension = ".schema";
      break;
    case EntityData::MODULE:
      lExtension = ".module";
      break;
    default:
      break;
  }
  URI lUri(aUri);
  zstring lPath = lUri.get_encoded_path();
  bool lChanged = false;
  if (lPath.length() == 0 && lUri.get_host().length() > 0) {
    // If URI has *no* path component (eg. "http://www.functx.com" with no
    // trailing slash), provide a path of "/". Note: the check for a non-empty
    // host is to work around a possibly bogus FOTS test module-URIs-19.
    lPath.append("/");
  }
  if (ZA_ENDS_WITH(lPath, "/")) {
    // If URI's path component ends with /, append "index.<extension>".
    lPath.append("index");
    lPath.append(lExtension);
    lChanged = true;
  }
  else {
    // If not, append ".schema" or ".module" if it's not already there.
    if (!ascii::ends_with(lPath, lExtension)) {
      lPath.append(lExtension);
      lChanged = true;
    }
  }

  // If anything changed, return new URI and the original.
  if (lChanged) {
    lUri.set_path(lPath);
    oUris.push_back(aUri);
    oUris.push_back(lUri.toString());
  }
}


/******
 * Module versioning mapper.
 ******/

void
ModuleVersioningURIMapper::mapURI
(zstring const& aUri, EntityData const* aEntityData,
  static_context const& aSctx, std::vector<zstring>& oUris)
{
  if (aEntityData->getKind() != EntityData::MODULE) {
    return;
  }

  // Parse the version defintion. If none exists, don't attempt versioning.
  ModuleVersion lModVer(aUri);
  if ( ! lModVer.is_valid_version()) {
    return;
  }

  // Ensure that the namespace URI ends in ".module", and then strip it.
  zstring const lBaseUri = lModVer.namespace_uri();
  if ( ! ZA_ENDS_WITH(lBaseUri, ".module")) {
    return;
  }
  zstring const lRootUri = lBaseUri.substr(0, lBaseUri.size() - 7);

  // Ok, we've successfully parsed a version-request fragment. Form up a set of
  // new URIs based on the original minus the fragment.

  // Iterate through all requested major versions.
  for (int lMaj = lModVer.max_major(); lMaj >= lModVer.min_major(); lMaj--) {
    std::stringstream lFormat;
    lFormat << lRootUri << "_" << lMaj;
    if (lModVer.is_exact()) {
      // Note that lExact can only be set if there was NO range specified, so
      // it's OK to check here even though we're looping.
      lFormat << "." << lModVer.min_minor();
    }
    lFormat << ".module";
    oUris.push_back(zstring(lFormat.str()));
  }

  // Finally, push back the original URI (minus fragment) as well.
  oUris.push_back(lBaseUri);
}


/******
 * Automatic filesystem mapper.
 ******/

void
AutoFSURIMapper::mapURI
(zstring const& aUri, EntityData const* aEntityData,
  static_context const& aSctx, std::vector<zstring>& oUris)
{
  // Filesystem resolution doesn't make sense for collections
  EntityData::Kind lKind = aEntityData->getKind();
  if (lKind == EntityData::COLLECTION
#ifndef ZORBA_NO_FULL_TEXT
      || lKind == EntityData::THESAURUS
#endif
      ) {
    return;
  }
  // Automatic resolution is for NON-file: URIs
  uri::scheme lScheme = uri::get_scheme(aUri);
  if (lScheme == uri::file) {
    return;
  }

  // Convert to filesystem path
  URI lUri(aUri);
  zstring lPathNotation = lUri.toPathNotation();

  // lPathNotation is a relative path. Form a corresponding absolute
  // file: URI based on every member of the static context's module
  // paths, and return that URI to the caller.
  std::vector<zstring> lModulePaths;
  aSctx.get_full_uri_path(lModulePaths);
  for (std::vector<zstring>::const_iterator lIter = lModulePaths.begin();
       lIter != lModulePaths.end(); lIter++)
  {
#ifndef WIN32
    zstring lCandidateURI("file://");
#else
    zstring lCandidateURI("file:///");
#endif
    // If module-path entry is relative, normalize it against the
    // static context's base URI.
    if (!fs::is_absolute(*lIter)) {
      zstring lAbsPath = fs::normalize_path(*lIter, aSctx.get_base_uri());
      lCandidateURI.append(lAbsPath);
    }
    else {
      lCandidateURI.append(*lIter);
    }

    fs::append(lCandidateURI, lPathNotation);
    oUris.push_back(lCandidateURI);
  }

  // Finally, append the original URI, so that it will be resolved
  // as-is if there's nothing appropriate on the local filesystem.
  oUris.push_back(aUri);
}

ZorbaCollectionURIMapper::~ZorbaCollectionURIMapper()
{
}

URIMapper::Kind
ZorbaCollectionURIMapper::mapperKind()
{
  return URIMapper::CANDIDATE;
}

void
ZorbaCollectionURIMapper::mapURI
(zstring const& aUri, EntityData const* aEntityData,
  static_context const& aSctx, std::vector<zstring>& oUris)
{
  if (aEntityData->getKind() != EntityData::COLLECTION) {
    return;
  }

  oUris.push_back(aUri);
}

} /* namespace zorba::impl */

} /* namespace zorba */

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
