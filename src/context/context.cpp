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
#include "context/context.h"

namespace zorba {

void
context::set_module_paths(const std::vector<std::string>& aModulePaths)
{
  module_paths = aModulePaths;
}

void
context::get_module_paths(std::vector<std::string>& aModulePaths) const
{
  aModulePaths.insert(aModulePaths.end(),
                      module_paths.begin(), module_paths.end());
}

void
context::get_full_module_paths(std::vector<std::string>& aFullModulePaths) const
{
  if (parent != NULL) {
    parent->get_full_module_paths(aFullModulePaths);
  }
  get_module_paths(aFullModulePaths);
}

} /* namespace zorba */
