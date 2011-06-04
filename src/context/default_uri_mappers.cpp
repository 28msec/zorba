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

#include "context/default_uri_mappers.h"
#include "util/uri_util.h"
#include "util/fs_util.h"
#include "zorbatypes/URI.h"
#include "context/static_context.h"

namespace zorba {

namespace impl {

/******
 * Automatic filesystem mapper.
 ******/

ZorbaAutoFSURIMapper::~ZorbaAutoFSURIMapper()
{
}

URIMapper::Kind
ZorbaAutoFSURIMapper::mapperKind() throw ()
{
  return URIMapper::CANDIDATE;
}

void
ZorbaAutoFSURIMapper::mapURI
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

  // Append extension / filename as necessary
  if (aEntityType == Resource::SCHEMA) {
    if (!ascii::ends_with(lPathNotation, ".xsd", 4)) {
      lPathNotation.append(".xsd");
    }
  }
  else if (aEntityType == Resource::MODULE) {
    if (!ascii::ends_with(lPathNotation, ".xq", 3)) {
      if (!ascii::ends_with(lPathNotation, "/", 1)) {
        lPathNotation.append(".xq");
      }
      else {
        lPathNotation.append("index.xq");
      }
    }
  }

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
