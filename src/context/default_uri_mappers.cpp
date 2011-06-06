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
#include <util/uri_util.h>
#include <util/fs_util.h>
#include <zorbatypes/URI.h>
#include <context/static_context.h>
#include <compiler/translator/module_version.h>

#include <cctype>

namespace zorba {

namespace impl {

/******
 * Fileize mapper.
 ******/

void
FileizeURIMapper::mapURI
(zstring const& aUri, Resource::EntityType aEntityType,
  static_context const& aSctx, std::vector<zstring>& oUris) throw()
{
  // File-izing is only for schemas and modules.
  if (aEntityType != Resource::SCHEMA && aEntityType != Resource::MODULE) {
    return;
  }

  // Append extension / filename as necessary
  zstring lExtension(aEntityType == Resource::SCHEMA ? ".xsd": ".xq");
  URI lUri(aUri);
  zstring lPath = lUri.get_encoded_path();
  bool lChanged = false;
  if (ascii::ends_with(aUri, "/")) {
    // If URI ends with /, append "index.xsd" or "index.xq".
    lPath.append("index");
    lPath.append(lExtension);
    lChanged = true;
  }
  else {
    // If not, append ".xsd" or ".xq" if it's not already there.
    if (!ascii::ends_with(lPath, lExtension)) {
      lPath.append(lExtension);
      lChanged = true;
    }
  }

  // If anything changed, return new URI and the original.
  if (lChanged) {
    lUri.set_path(lPath);
    oUris.push_back(lUri.toString());
    oUris.push_back(aUri);
  }
}


/******
 * Module versioning mapper.
 ******/

void
ModuleVersioningURIMapper::mapURI
(zstring const& aUri, Resource::EntityType aEntityType,
  static_context const& aSctx, std::vector<zstring>& oUris) throw()
{
  if (aEntityType != Resource::MODULE) {
    return;
  }

  // Parse the version defintion. If none exists, don't attempt versioning.
  ModuleVersion lModVer(aUri);
  if ( ! lModVer.is_valid_version()) {
    return;
  }

  // Ensure that the namespace URI ends in ".xq".
  zstring const lBaseUri = lModVer.namespace_uri();
  if ( ! ascii::ends_with(lBaseUri, ".xq")) {
    return;
  }

  // Ok, we've successfully parsed a version-request fragment. Form up a set of
  // new URIs based on the original minus the fragment.

  // Iterate through all requested major versions.
  for (int lMaj = lModVer.max_major(); lMaj >= lModVer.min_major(); lMaj--) {
    std::stringstream lFormat;
    lFormat << lBaseUri << "." << lMaj;
    if (lModVer.is_exact()) {
      // Note that lExact can only be set if there was NO range specified, so
      // it's OK to check here even though we're looping.
      lFormat << "." << lModVer.min_minor();
    }
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
(zstring const& aUri, Resource::EntityType aEntityType,
  static_context const& aSctx, std::vector<zstring>& oUris) throw()
{
  // Automatic resolution is (currently?) only for schemas and modules
  if (aEntityType != Resource::SCHEMA && aEntityType != Resource::MODULE) {
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
  aSctx.get_full_module_paths(lModulePaths);
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
      zstring lAbsPath = fs::get_normalized_path(*lIter, aSctx.get_base_uri());
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

} /* namespace zorba::impl */

} /* namespace zorba */

/*
 * Local variables:
 * mode: c++
 * End:
 */
