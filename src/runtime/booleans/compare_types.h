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
#ifndef ZORBA_COMPARE_TYPES_H
#define ZORBA_COMPARE_TYPES_H

namespace zorba {
class CompareConsts {
public:
  enum CompareType{
    VALUE_EQUAL, GENERAL_EQUAL, NODE_EQUAL,
    VALUE_NOT_EQUAL, GENERAL_NOT_EQUAL, NODE_NOT_EQUAL,
    VALUE_LESS, GENERAL_LESS,
    VALUE_LESS_EQUAL, GENERAL_LESS_EQUAL,
    VALUE_GREATER, GENERAL_GREATER,
    VALUE_GREATER_EQUAL, GENERAL_GREATER_EQUAL
  };
};
}

#endif
