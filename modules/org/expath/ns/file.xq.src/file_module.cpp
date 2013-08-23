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

#include "file.h"
#include "file_module.h"
#include "file_function.h"

namespace zorba {
namespace filemodule {

///////////////////////////////////////////////////////////////////////////////

FileModule::~FileModule() {
  for ( FuncMap_t::const_iterator i = theFunctions.begin();
        i != theFunctions.end(); ++i ) {
    delete i->second;
  }
}
  
ExternalFunction* FileModule::getExternalFunction( String const &aLocalname ) {
  ExternalFunction *&lFunc = theFunctions[ aLocalname ];
  if ( !lFunc ) {
    if ( aLocalname == "append-text" )
      lFunc = new AppendTextFunction( this );
    else if ( aLocalname == "append-text-lines" )
      lFunc = new AppendTextLinesFunction( this );
    else if ( aLocalname == "append-binary" )
      lFunc = new AppendBinaryFunction( this );
    else if ( aLocalname == "base-name" )
      lFunc = new BaseNameFunction( this );
    else if ( aLocalname == "copy-file-impl" )
      lFunc = new CopyFileImplFunction( this );
    else if ( aLocalname == "create-directory" )
      lFunc = new CreateDirectoryFunction( this );
    else if ( aLocalname == "delete-file-impl" )
      lFunc = new DeleteFileImplFunction( this );
    else if ( aLocalname == "dir-name" )
      lFunc = new DirNameFunction( this );
    else if ( aLocalname == "directory-separator" )
      lFunc = new DirectorySeparator( this );
    else if ( aLocalname == "exists" )
      lFunc = new ExistsFunction( this );
    else if ( aLocalname == "is-directory" )
      lFunc = new IsDirectoryFunction( this );
    else if ( aLocalname == "is-file" )
      lFunc = new IsFileFunction( this );
    else if ( aLocalname == "is-symlink" )
      lFunc = new IsSymlinkFunction( this );
    else if ( aLocalname == "last-modified" )
      lFunc = new LastModifiedFunction( this );
    else if ( aLocalname == "list" )
      lFunc = new ListFunction( this );
    else if ( aLocalname == "path-separator" )
      lFunc = new PathSeparator( this );
    else if ( aLocalname == "path-to-native" )
      lFunc = new PathToNativeFunction( this );
    else if ( aLocalname == "path-to-uri" )
      lFunc = new PathToUriFunction( this );
    else if ( aLocalname == "read-binary" )
      lFunc = new ReadBinaryFunction( this );
    else if ( aLocalname == "read-text" )
      lFunc = new ReadTextFunction( this );
    else if ( aLocalname == "read-text-lines" )
      lFunc = new ReadTextLinesFunction( this );
    else if ( aLocalname == "resolve-path" )
      lFunc = new ResolvePathFunction( this );
    else if ( aLocalname == "write-text" )
      lFunc = new WriteTextFunction( this );
    else if ( aLocalname == "write-text-lines" )
      lFunc = new WriteTextLinesFunction( this );
    else if ( aLocalname == "write-binary" )
      lFunc = new WriteBinaryFunction( this );
    else if ( aLocalname == "size" )
      lFunc = new SizeFunction( this );
  }
  return lFunc;
}

void FileModule::destroy() {
  delete this;
}

String FileModule::getURI() const {
  return "http://expath.org/ns/file";
}

///////////////////////////////////////////////////////////////////////////////

} // namespace filemodule
} // namespace zorba
/* vim:set et sw=2 ts=2: */
