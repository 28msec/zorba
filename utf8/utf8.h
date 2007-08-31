#ifndef XQP_UTF8_H
#define XQP_UTF8_H

#include "errors/errors.h"
#include "errors/Error.h"

using namespace std;
namespace xqp {
	// Unicode constants
	// Leading (high) surrogates: 0xd800 - 0xdbff
	// Trailing (low) surrogates: 0xdc00 - 0xdfff
	const uint16_t LEAD_SURROGATE_MIN  = 0xd800u;
	const uint16_t LEAD_SURROGATE_MAX  = 0xdbffu;
	const uint16_t TRAIL_SURROGATE_MIN = 0xdc00u;
	const uint16_t TRAIL_SURROGATE_MAX = 0xdfffu;
	const uint16_t LEAD_OFFSET         = LEAD_SURROGATE_MIN - (0x10000 >> 10);
	const uint32_t SURROGATE_OFFSET    = 0x10000u - (LEAD_SURROGATE_MIN << 10) - TRAIL_SURROGATE_MIN;

	// Maximum valid value for a Unicode code point
	const uint32_t CODE_POINT_MAX      = 0x0010ffffu;


	/**
	 * The iterator class adapts the underlying octet iterator to iterate
	 * over the sequence of code points, rather than raw octets.
	 */
	template <typename octet_iterator>
			class iterator : public std::iterator <std::bidirectional_iterator_tag, uint32_t> {
		octet_iterator it;
				public:
					iterator () {};
					explicit iterator (const octet_iterator& octet_it): it(octet_it) {}
			
					octet_iterator base () const { return it; }
					uint32_t operator * () const
					{
						octet_iterator temp = it;
						return next(temp);
					}
					bool operator == (const iterator& rhs) const
					{
						return (it == rhs.it);
					}
					bool operator != (const iterator& rhs) const
					{
						return !(operator == (rhs));
					}
					iterator& operator ++ ()
					{
						std::advance(it, sequence_length(it));
						return *this;
					}
					iterator operator ++ (int)
					{
						iterator temp = *this;
						std::advance(it, sequence_length(it));
						return temp;
					}
					iterator& operator -- ()
					{
						prior(it);
						return *this;
					}
					iterator operator -- (int)
					{
						iterator temp = *this;
						prior(it);
						return temp;
					}
			}; // class iterator
	
	
	
	template <typename u16>
			inline bool is_surrogate(u16 cp)
	{
		return (cp >= LEAD_SURROGATE_MIN && cp <= TRAIL_SURROGATE_MAX);
	}
	
	template <typename u32>
			inline bool is_code_point_valid(u32 cp)
	{
		return (cp <= CODE_POINT_MAX && !is_surrogate(cp) && cp != 0xfffe && cp != 0xffff);
	}

	template<typename octet_type>
			inline uint8_t mask8(octet_type oc)
	{
		return static_cast<uint8_t>(0xff & oc);
	}

	template<typename octet_type>
			inline bool is_trail(octet_type oc)
	{
		return ((mask8(oc) >> 6) == 0x2);
	}

	template <typename octet_iterator>
    inline typename std::iterator_traits<octet_iterator>::difference_type
	sequence_length(octet_iterator lead_it)
	{
			uint8_t lead = mask8(*lead_it);
			if (lead < 0x80)
					return 1;
			else if ((lead >> 5) == 0x6)
					return 2;
			else if ((lead >> 4) == 0xe)
					return 3;
			else if ((lead >> 3) == 0x1e)
					return 4;
			else
					return 0;
	}
		
	/**
	 * Given the iterator to the beginning of the UTF-8 sequence
	 * it returns the code point and moves the iterator to the next position
	 */
	template <typename octet_iterator>
		uint32_t next(octet_iterator& it)
	{
		uint32_t cp = mask8(*it);

		typename std::iterator_traits<octet_iterator>::difference_type length = sequence_length(it);
		switch (length) {
			case 1:
				break;
			case 2:
				it++;
				cp = ((cp << 6) & 0x7ff) + ((*it) & 0x3f);
				break;
			case 3:
				++it;
				cp = ((cp << 12) & 0xffff) + ((mask8(*it) << 6) & 0xfff);
				++it;
				cp += (*it) & 0x3f;
				break;
			case 4:
				++it;
				cp = ((cp << 18) & 0x1fffff) + ((mask8(*it) << 12) & 0x3ffff);
				++it;
				cp += (mask8(*it) << 6) & 0xfff;
				++it;
				cp += (*it) & 0x3f;
				break;
		}
		++it;
		return cp;
	}

	/**
	 * Decreases the iterator until it hits the beginning of the previous UTF-8
	 * encoded code point and returns the 32 bits representation of the code point.
	 */
	template <typename octet_iterator>
		uint32_t prior(octet_iterator& it)
	{
		while (is_trail(*(--it))) ;
		octet_iterator temp = it;
		return next(temp);
	}

	template <typename octet_iterator>
		typename std::iterator_traits<octet_iterator>::difference_type
		UTF8Distance (octet_iterator first, octet_iterator last)
	{
		typename std::iterator_traits<octet_iterator>::difference_type dist;
		for (dist = 0; first < last; ++dist)
			next(first);
		return dist;
	}
			
	/**
	 * Encodes a 32 bit code point as a UTF-8 sequence of octets
	 * 
	 * @param cp a 32 bit integer representing a code point to append to the sequence
	 * @param result an output iterator to the place in the sequence where to append the code point
	 * @return an iterator pointing to the place after the newly appended sequence
	 */
	template <typename octet_iterator>
			octet_iterator UTF8Encode(uint32_t cp, octet_iterator result)
	{
		if (!is_code_point_valid(cp))
				ZorbaErrorAlerts::error_alert(
					error_messages::FOCH0001_Code_point_not_valid,
					error_messages::RUNTIME_ERROR,
					NULL,
					true
				);

		if (cp < 0x80)                        // one octet
			*(result++) = static_cast<uint8_t>(cp);
		else if (cp < 0x800) {                // two octets
			*(result++) = static_cast<uint8_t>((cp >> 6)            | 0xc0);
			*(result++) = static_cast<uint8_t>((cp & 0x3f)          | 0x80);
		}
		else if (cp < 0x10000) {              // three octets
			*(result++) = static_cast<uint8_t>((cp >> 12)           | 0xe0);
			*(result++) = static_cast<uint8_t>((cp >> 6) & 0x3f     | 0x80);
			*(result++) = static_cast<uint8_t>((cp & 0x3f)          | 0x80);
		}
		else if (cp <= CODE_POINT_MAX) {      // four octets
			*(result++) = static_cast<uint8_t>((cp >> 18)           | 0xf0);
			*(result++) = static_cast<uint8_t>((cp >> 12)& 0x3f     | 0x80);
			*(result++) = static_cast<uint8_t>((cp >> 6) & 0x3f     | 0x80);
			*(result++) = static_cast<uint8_t>((cp & 0x3f)          | 0x80);
		}
		
		return result;
	}

	/**
	 * Given the iterator to the beginning of the UTF-8 sequence, it returns the code point.
	 *
	 * @param it a reference to an iterator pointing to the beginning of an UTF-8 encoded code point.
	 * @return the 32 bit representation of the processed UTF-8 code point
	 * @note After the function returns, @param it is incremented to point to the beginning
	 * of the next code point
	 */
	template <typename octet_iterator>
			uint32_t UTF8Decode(octet_iterator& it)
	{
		return next(it);
	}
}/* namespace xqp */

#endif /* XQP_UTF8_H */
