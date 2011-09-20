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

#pragma once
#ifndef ZORBA_DIAGNOSTIC_DICT_IMPL_H
#define ZORBA_DIAGNOSTIC_DICT_IMPL_H

namespace zorba {
namespace diagnostic {
namespace dict {

///////////////////////////////////////////////////////////////////////////////

/**
 * A dictionary %entry.
 */
struct entry {
  char const *key;
  char const *value;
};

#define DEF_DICT_END(LANG) \
  extern ::zorba::diagnostic::dict::entry const *const dict_##LANG##_end = \
    dict_##LANG + sizeof( dict_##LANG ) / sizeof( dict_##LANG[0] )

///////////////////////////////////////////////////////////////////////////////

} // namespace dict
} // namespace diagnostic
} // namespace zorba
#endif /* ZORBA_DIAGNOSTIC_DICT_IMPL_H */
/* vim:set et sw=2 ts=2: */
