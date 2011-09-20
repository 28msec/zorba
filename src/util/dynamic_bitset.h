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
#ifndef ZORBA_DYNAMIC_BITSET_H
#define ZORBA_DYNAMIC_BITSET_H

#include <vector>

#include "zorbamisc/config/stdint.h"
#include "zorbamisc/config/platform.h"

namespace zorba {

class DynamicBitset 
{
private:
  typedef std::vector<uint8_t> bits_t;

private:
  ulong    m_num_bits;
  bits_t m_bits;

public:
  DynamicBitset() { }

  DynamicBitset(ulong size)
    :
    m_num_bits(size),
    m_bits((size >> 3) + ((size & 7) ? 1 : 0)) 
  { 
  }

  ~DynamicBitset() { }

  ulong size() const
  {
    return m_num_bits;
  }

  void getSet(std::vector<ulong>& set) const
  {
    ulong numBytes = (ulong)m_bits.size();
    for (ulong i = 0; i < numBytes; ++i)
    {
      if (m_bits[i] == 0)
        continue;

      for (ulong j = 0; j < 8; ++j) 
      {
        if ((m_bits[i] & (128 >> j)) != 0) // 128 = 1000 0000
          set.push_back(i * 8 + j);
      }
    }
  }


  bool get(int bit) const
  {
    int off = getByteIndex(bit);
    if (m_bits.size() <= (unsigned)off)
      return false;

    uint8_t byte = m_bits[off];
    return (byte & (128 >> getBitWithinByte(bit))) != 0;
  }

  void set(ulong bit, bool value)
  {
    ulong off = getByteIndex(bit);
    if (!value && m_bits.size() <= (unsigned)off)
      return;

    if (m_bits.size() <= (unsigned)off)
      m_bits.resize(off + 1);
 
    ulong bitnum = getBitWithinByte(bit);
    if (value) 
    {
      m_bits[off] |= (128 >> bitnum);
    }
    else 
    {
      m_bits[off] &= ~(128 >> bitnum);
    }
  }
  
  void reset()
  {
    bits_t::iterator end = m_bits.end();
    for(bits_t::iterator i = m_bits.begin(); i != end; ++i) 
    {
      *i = 0;
    }
  }
  
  DynamicBitset& set_union(const DynamicBitset& rhs)
  {
    ulong idx = 0;
    while(idx < m_bits.size() && idx < rhs.m_bits.size()) 
    {
      m_bits[idx] |= rhs.m_bits[idx];
      ++idx;
    }

    if (idx < rhs.m_bits.size()) 
    {
      m_bits.resize(rhs.m_bits.size());
      while(idx < rhs.m_bits.size()) 
      {
        m_bits.push_back(rhs.m_bits[idx++]);
      }
    }
    return *this;
  }
  
  DynamicBitset& set_intersect(const DynamicBitset& rhs)
  {
    ulong idx = 0;
    while(idx < m_bits.size() && idx < rhs.m_bits.size()) 
    {
      m_bits[idx] &= rhs.m_bits[idx];
      ++idx;
    }
    while(idx < m_bits.size()) 
    {
      m_bits[idx++] = 0;
    }
    return *this;
  }


private:
  static ulong getByteIndex(ulong bit)
  {
    return bit >> 3;
  }
  
  static ulong getBitWithinByte(ulong bit)
  {
    // bit = 8 ==> bit & 7 = 0,
    // bit = 9 ==> bit & 7 = 1, etc
    return bit & 7;
  }
};


std::ostream& operator <<(std::ostream& s, const DynamicBitset& set);

}

#endif /* ZORBA_DYNAMIC_BITSET_H */
/* vim:set et sw=2 ts=2: */
