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

#ifndef ZORBA_INTERNAL_PROXY_H
#define ZORBA_INTERNAL_PROXY_H

namespace zorba {
namespace internal {
namespace ztd {

///////////////////////////////////////////////////////////////////////////////

/**
 * \internal
 * A %proxy<T> is-a \c T that also contains a T* -- a pointer to the original.
 */
template<class OriginalType>
class proxy : public OriginalType {
public:
  proxy( OriginalType *p ) : original_( p ) { }

  OriginalType* original() const {
    return original_;
  }
private:
  OriginalType *original_;
};

///////////////////////////////////////////////////////////////////////////////

} // namespace ztd
} // namespace internal
} // namespace zorba
#endif  /* ZORBA_INTERNAL_PROXY_H */
/* vim:set et sw=2 ts=2: */
