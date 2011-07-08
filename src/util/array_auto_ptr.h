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


#include <memory>

namespace zorba{

template <class _Ty>
class array_auto_ptr : public std::auto_ptr<_Ty>
{	// is like std::auto_ptr only it does delete[] in destructor
public:
  ~array_auto_ptr() {delete[] std::auto_ptr<_Ty>::release();}
};

} // namespace zorba
/* vim:set et sw=2 ts=2: */
