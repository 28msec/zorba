
/*
 * Copyright 2006-2012 The FLWOR Foundation.
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
#ifndef ZORBA_COMPILER_API_CONSTS_H
#define ZORBA_COMPILER_API_CONSTS_H

namespace zorba
{

enum xqdoc_component_t
{
  xqdoc_component_none = 0,
  xqdoc_component_comments = 1,
  xqdoc_component_imports = 2,
  xqdoc_component_variables = 4,
  xqdoc_component_functions = 8,
  xqdoc_component_collections = 16,
  xqdoc_component_indexes = 32
};

}

#endif
