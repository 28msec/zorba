/**
 *
 * @copyright
 * ========================================================================
 *	Copyright 2007 FLWOR Foundation
 *
 *	Licensed under the Apache License, Version 2.0 (the "License");
 *	you may not use this file except in compliance with the License.
 *	You may obtain a copy of the License at
 *
 *		http://www.apache.org/licenses/LICENSE-2.0
 *
 *	Unless required by applicable law or agreed to in writing, software
 *	distributed under the License is distributed on an "AS IS" BASIS,
 *	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *	See the License for the specific language governing permissions and
 *	limitations under the License.
 * ========================================================================
 *
 * @author Sorin Nasoi (sorin.nasoi@ipdevel.ro)
 * @file utf8/xqpString.h
 *
 */ 
#ifndef XQP_STRING_UTF8_STRING_REPRESENTATION_30_AUG_2007
#define XQP_STRING_UTF8_STRING_REPRESENTATION_30_AUG_2007

#ifdef WIN32
#include "util/win32/compatib_defs.h"
#endif

#include <iostream>
#include <stdlib.h>

#include <unicode/utypes.h>
#include <unicode/coll.h>
#include <unicode/ustring.h>

#include "util/utf8/utf8.h"

namespace xqp {
	class xqpString
	{
		public:
			typedef std::string::size_type	size_type;
			
		//! @name constructor/destructor
		//! @{
			/**
			 * Construct an empty stdString
				*/
			xqpString();

			/**
			 * Construct a xqpString as a copy of another xqpString
			 * @param src A source UTF-8 encoded string
			 */
			xqpString(const xqpString& src);

			/**
			 * Construct a xqpString given a std::string
			 * @param src A source std::string containin ASCII characters
			 */
			xqpString(const std::string& src);

			/**
			 * Construct a xqpString as a copy of a C string.
			 * @param src %Source C string that is encoded as UTF-8
			 */
			xqpString(const char* src);
			
			~xqpString();
		//! @}
			
		//! @name xqpString::operator=()
		//! @{
			xqpString& operator=(const xqpString& src);
			xqpString& operator=(const std::string& src);
			xqpString& operator=(const char* src);
			/**
			 * @param cp Codepoint
			 */
			xqpString& operator=(uint32_t cp);
			xqpString& operator=(char c);
		//! @}
			
		//! @name xqpString::operator+=()
		//! @{
			xqpString& operator+=(const xqpString& src);
			xqpString& operator+=(const char* src);
			/**
			 * @param cp Codepoint
			 */
			xqpString& operator+=(uint32_t cp);
			xqpString& operator+=(char c);
		//! @}

		//! @name xqpString::operator==()
		//! @{
			inline bool operator==(const xqpString& src) const{
				return (compare(src) == 0);
			}

			inline bool operator==(const char* src) const{
				return (compare(src) == 0);
			}
		//!@}

		//! @name xqpString::operator!=()
		//! @{
			inline bool operator!=(const xqpString& src) const{
				return (compare(src) != 0);
			}

			inline bool operator!=(const char* src) const{
				return (compare(src) != 0);
			}
		//!@}

		//! @name xqpString::operator<()
		//!@{

			inline bool operator<(const xqpString& src) const {
				return compare(src) == -1; }

		//!@}

		//! @name xqpString::operator>()
		//!@{
			inline bool operator>(const xqpString& src) const {
				return compare(src) == 1; }
		//!@}

		//! @name xqpString::Compare
		//! @{
			int compare(const xqpString& src) const;

		/**
			* Compare 2 strings based on a specific collation for a locale.
			*	@param loc locale as lowercase two-letter or three-letter ISO-639 code. In ICU4C one can also send something like "de_ch".
			* http://www.loc.gov/standards/iso639-2/ has a list of language codes (de stands for German language)
			* http://www.iso.org/iso/en/prods-services/iso3166ma/index.html a list of countries (ch stands for Switzerland)
			*/
			int compare(const xqpString& src, const char * loc) const;
			int compare(const char* src) const;
		//! @}

		//! @name xqpString::Length
		//! @{
			/**
			 * @return the number of unicode characters (without the null termination)
			 */
			size_type length() const;

			/**
			 * @return the number of unicode characters (without the null termination)
			 */
			size_type size() const;

			/**
			 * @return the number of bytes (without the null termination)
			 */
			size_type bytes() const;

			/**
			 * @return true is the xqpString is empty
			 */
			bool empty()  const;

			/**
			 *	Sets the capacity of the string to at least size
			 */
			void reserve(size_type size=0);
		//! @}

		//! @name xqpString::Clear
		//! @{
			void clear();
		//! @}

		//! @name xqpString::Codepointsize()
		//!@{
			std::vector<int> getCodepoints(const char* src);
		//!@}
		
			const char* c_str() const;
			
			inline	operator std::string() const{
				return utf8String;
			}
		public:
			std::string        utf8String;
private:
			/**
			*Return an UnicodeString (UTF-16 encoded) given a xqpString (UTF-8 encoded)
			*/
			UnicodeString getUnicodeString(const xqpString& in) const;
			/**
			*Return a xqpString (UTF-8 encoded) given an UnicodeString (UTF-16 encoded)
			*/
			xqpString getXqpString(UnicodeString in);

	};

	//! @name xqpString::stream I/O operators
	//! @{
	std::istream& operator>>(std::istream& is, xqp::xqpString& utf8_src);
	std::ostream& operator<<(std::ostream& os, const xqp::xqpString& utf8_src);
	//!@}
	
	//! @name xqpString::concatenation operator+()
	//! @{
	inline xqpString operator+(const xqpString& lsrc, const xqpString& rsrc){
		xqpString tmp (lsrc);
		tmp += rsrc;
		return tmp;
	}

	inline xqpString operator+(const xqpString& lsrc, const char* rsrc){
		xqpString tmp (lsrc);
		tmp += rsrc;
		return tmp;
	}

	inline xqpString operator+(const char* lsrc, const xqpString& rsrc){
		xqpString tmp (lsrc);
		tmp += rsrc;
		return tmp;
	}
	//! @}
}/* namespace xqp */

#endif

