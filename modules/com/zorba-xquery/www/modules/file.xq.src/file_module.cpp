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

namespace zorba { namespace filemodule {

  ItemFactory* FileModule::theFactory = 0;


FileModule::~FileModule()
{
  for (FuncMap_t::const_iterator lIter = theFunctions.begin();
       lIter != theFunctions.end(); ++lIter) {
    delete lIter->second;
  }
  theFunctions.clear();
}
  
StatelessExternalFunction*
FileModule::getExternalFunction(const String& aLocalname)
{
  StatelessExternalFunction*& lFunc = theFunctions[aLocalname];
  if (!lFunc) {
    if (1 == 0) {

    } else if (aLocalname.equals("copy")) {
      lFunc = new CopyFunction(this);
    } else if (aLocalname.equals("exists")) {
      lFunc = new ExistsFunction(this);
    } else if (aLocalname.equals("files")) {
      lFunc = new FilesFunction(this);
    } else if (aLocalname.equals("is-directory")) {
      lFunc = new IsDirectoryFunction(this);
    } else if (aLocalname.equals("is-file")) {
      lFunc = new IsFileFunction(this);
    } else if (aLocalname.equals("last-modified")) {
      lFunc = new LastModifiedFunction(this);
    } else if (aLocalname.equals("mkdir")) {
      lFunc = new MkdirFunction(this);
    } else if (aLocalname.equals("mkdirs")) {
      lFunc = new MkdirsFunction(this);
    } else if (aLocalname.equals("path-separator")) {
      lFunc = new PathSeparator(this);
    } else if (aLocalname.equals("path-to-full-path")) {
      lFunc = new PathToFullPathFunction(this);
    } else if (aLocalname.equals("path-to-uri")) {
      lFunc = new PathToUriFunction(this);
    } else if (aLocalname.equals("read")) {
      lFunc = new ReadFunction(this);
    } else if (aLocalname.equals("read-html")) {
      lFunc = new MkdirsFunction(this);
    } else if (aLocalname.equals("read-text")) {
      lFunc = new ReadTextFunction(this);
    } else if (aLocalname.equals("read-xml")) {
      lFunc = new ReadXmlFunction(this);
    } else if (aLocalname.equals("remove")) {
      lFunc = new RemoveFunction(this);
    } else if (aLocalname.equals("write")) {
      lFunc = new WriteFunction(this);
    } else if (aLocalname.equals("normalize-path")) {
      lFunc = new NormalizePathFunction(this);
    }
  }
  return lFunc;
}

void
FileModule::destroy()
{
  if (!dynamic_cast<FileModule*>(this)) {
    return;
  }
  delete this;
}

} /* namespace filemodule */ } /* namespace zorba */
