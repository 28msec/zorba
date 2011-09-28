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
#include "zorbatypes/m_apm.h"
#include "zorbatypes/numconversions.h"
#include "zorbautils/hashfun.h"


uint32_t MAPM::hash() const
{
  if (is_integer())
  {
    if (sign() < 0)
    {
      if (*this >= MAPM::getMinInt64())
      {
        char buffer[exponent() + 3];
        toIntegerString(buffer);
        std::stringstream strstream(buffer);
        int64_t longv;
        strstream >> longv;
        assert(strstream.eof());
        return static_cast<uint32_t>(longv & 0xffffffff);
      }
    }
    else if (*this <= MAPM::getMaxUInt64())
    {
      char buffer[exponent() + 3];
      toIntegerString(buffer);
      std::stringstream strstream(buffer);
      uint64_t longv;
      strstream >> longv;
      assert(strstream.eof());
      return static_cast<uint32_t>(longv & 0xffffffff);
    }
  }

  // In all other cases, hash it as double
  char buffer[exponent() + 3];
  toIntegerString(buffer);
  std::stringstream strstream(buffer);
  double doublev;
  strstream >> doublev;
  assert(strstream.eof());
  return static_cast<uint32_t>(doublev);
}

/* vim:set et sw=2 ts=2: */
