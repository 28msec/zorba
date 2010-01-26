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

std::vector<xqp_string>* context::get_all_str_keys() const
{
  std::auto_ptr<std::vector<xqp_string> > keys;
  if (parent != NULL)
    keys.reset(parent->get_all_str_keys());
  else
    keys.reset(new std::vector<xqp_string>);

  for (unsigned int i=0; i<str_keymap.size(); i++)
    keys->push_back(str_keymap.getentryKey(i));

  return keys.release();
}

std::vector<xqp_string>* context::get_all_keymap_keys() const
{
  std::auto_ptr<std::vector<xqp_string> > keys;
  if (parent != NULL)
    keys.reset(parent->get_all_keymap_keys());
  else
    keys.reset(new std::vector<xqp_string>);

  for (unsigned int i=0; i<keymap.size(); i++)
    keys->push_back(keymap.getentryKey(i));

  return keys.release();
}

// Explicit template instantiation
template bool context::context_value<context::ctx_value_t>(xqp_string key, context::ctx_value_t& val) const;

template bool context::context_value<xqpString>(xqp_string key, xqpString& val) const;

template<class V> bool context::context_value(xqp_string key, V &val) const
{
  if (lookup_once(key, val))
    return true;
  else
    return parent == NULL ? false : parent->context_value (key, val);
}

/* Debugging purposes */
std::ostream& operator<<(std::ostream& stream, const context::ctx_value_t& object)
{
  stream << (int)object.type;
  return stream;
}

} /* namespace zorba */
