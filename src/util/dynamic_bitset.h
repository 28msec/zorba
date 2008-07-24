#ifndef ZORBA_DYNAMIC_BITSET_H
#define ZORBA_DYNAMIC_BITSET_H

#include <ostream>
#include <vector>

namespace zorba {

class DynamicBitset {
  private:
    typedef std::vector<uint8_t> bits_t;

  public:
    DynamicBitset() { }
    DynamicBitset(int size)
      : m_size(size),
      m_bits((size >> 3) + ((size & 7) ? 1 : 0)) { }
    ~DynamicBitset() { }

    int size() const
    {
      return m_size;
    }

    bool get(int bit) const
    {
      int off = getByteIndex(bit);
      if (m_bits.size() <= (unsigned)off) {
        return false;
      }
      uint8_t byte = m_bits[off];
      return (byte & (1 << getBitWithinByte(bit))) != 0;
    }

    void set(int bit, bool value)
    {
      int off = getByteIndex(bit);
      if (!value && m_bits.size() <= (unsigned)off) {
        return;
      }
      if (m_bits.size() <= (unsigned)off) {
        m_bits.resize(off + 1);
      }
      int bitnum = getBitWithinByte(bit);
      if (value) {
        m_bits[off] |= (1 << bitnum);
      } else {
        m_bits[off] &= ~(1 << bitnum);
      }
    }

    void reset()
    {
      bits_t::iterator end = m_bits.end();
      for(bits_t::iterator i = m_bits.begin(); i != end; ++i) {
        *i = 0;
      }
    }

    DynamicBitset& set_union(const DynamicBitset& rhs)
    {
      int idx = 0;
      while((unsigned)idx < m_bits.size() && (unsigned)idx < rhs.m_bits.size()) {
        m_bits[idx] |= rhs.m_bits[idx];
        ++idx;
      }
      if ((unsigned)idx < rhs.m_bits.size()) {
        m_bits.resize(rhs.m_bits.size());
        while((unsigned)idx < rhs.m_bits.size()) {
          m_bits.push_back(rhs.m_bits[idx++]);
        }
      }
      return *this;
    }

    DynamicBitset& set_intersect(const DynamicBitset& rhs)
    {
      int idx = 0;
      while((unsigned)idx < m_bits.size() && (unsigned)idx < rhs.m_bits.size()) {
        m_bits[idx] &= rhs.m_bits[idx];
        ++idx;
      }
      while((unsigned)idx < m_bits.size()) {
        m_bits[idx++] = 0;
      }
      return *this;
    }

  private:
    int m_size;
    bits_t m_bits;

    static int getByteIndex(int bit)
    {
      return bit >> 3;
    }

    static int getBitWithinByte(int bit)
    {
      return bit & 7;
    }
};

std::ostream& operator <<(std::ostream& s, const DynamicBitset& set)
{
  s << "BitSet[" << set.size() << "] = {";
  for(int i = 0; i < set.size(); ++i) {
    if (set.get(i)) {
      s << i << ", ";
    }
  }
  s << "}";
  return s;
}

}

#endif /* ZORBA_DYNAMIC_BITSET_H */
/* vim:set ts=2 sw=2: */
