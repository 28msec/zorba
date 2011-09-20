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

#ifndef ZORBA_UTIL_UUID_H
#define ZORBA_UTIL_UUID_H

#undef uuid_t

namespace zorba {

typedef struct {
  xs_unsignedInt    time_low;
  xs_unsignedShort  time_mid;
  xs_unsignedShort  time_hi_and_version;
  xs_unsignedByte   clock_seq_hi_and_reserved;
  xs_unsignedByte   clock_seq_low;
  xs_byte           node[6];
} uuid_t;

/* uuid_create -- generate a UUID */
int uuid_create(uuid_t * uuid);

/* uuidToString -- transform a UUID to a string */
zstring uuidToString(const uuid_t& uuid);

} // namespace zorba
#endif /* ZORBA_UTIL_UUID_H */
/* vim:set et sw=2 ts=2: */
