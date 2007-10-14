/**
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
 * @file utf8/xqpString.cpp
 *
 */ 

#include "util/utf8/xqpString.h"

namespace xqp {

	xqpString::xqpString()
	:
		utf8String()
	{}

	xqpString::xqpString(const xqpString& src)
	:
		utf8String(src.utf8String)
	{}

	xqpString::xqpString(const std::string& src)
	:
		utf8String(src)
	{}

	xqpString::xqpString(const char* src)
	:
		utf8String(src)
	{}

	xqpString::~xqpString()
	{}

	//xqpString::operator=()
	xqpString& xqpString::operator=(const xqpString& src){
		utf8String = src.utf8String;
		return *this;
	}
	
	xqpString& xqpString::operator=(const std::string& src){
		utf8String = src;
		return *this;
	}
	
	xqpString& xqpString::operator=(const char* src){
		utf8String = src;
		return *this;
	}
	
	xqpString& xqpString::operator=(uint32_t cp){
		utf8String.reserve(4);
		char seq[4] = {0,0,0,0};
		UTF8Encode(cp, seq);
		utf8String = seq;
		return *this;
	}
	
	xqpString& xqpString::operator=(char c){
		utf8String = c;
		return *this;
	}
	
	//xqpString::operator+=()
	xqpString& xqpString::operator+=(const xqpString& src){
		utf8String += src.utf8String;
		return *this;
	}

	xqpString& xqpString::operator+=(const char* src){
		utf8String += src;
		return *this;
	}

	xqpString& xqpString::operator+=(uint32_t cp){
		utf8String.reserve(4);
		char seq[4] = {0,0,0,0};
		UTF8Encode(cp, seq);
		utf8String += seq;
		return *this;
	}

	xqpString& xqpString::operator+=(char c){
		utf8String += c;
		return *this;
	}

	//xqpString::stream I/O operators
	std::istream& operator>>(std::istream& is, xqpString& utf8_src){
		std::string buffer;
		is >> buffer;
		//TODO is there a need to perform charset conversion to/from the current locale ?!?!
		utf8_src = buffer;
		return is;
	}

	std::ostream& operator<<(std::ostream& os, const xqpString& utf8_src){
		//TODO is there a need to perform charset conversion to/from the current locale ?!?!
		os << utf8_src.utf8String;
		return os;
	}

	//xqpString::compare
	int xqpString::compare(const xqpString& src) const{
		//create the collator object
		UErrorCode status = U_ZERO_ERROR;

		//TODO make the collator a global object
		//NOTE By passing "root" as a locale parameter the root locale is used.
		//Root locale implements the UCA rules
		//(see DUCET from http://www.unicode.org/Public/UCA/5.0.0/allkeys.txt)
		Collator *coll = Collator::createInstance(Locale("root"), status);
	
		if(U_FAILURE(status)) {
			ZorbaErrorAlerts::error_alert(
					error_messages::XQP0014_SYSTEM_SHOUD_NEVER_BE_REACHED,
					error_messages::SYSTEM_ERROR,
					NULL
				);
		}

		//set level 1 comparison for the collator
		coll->setStrength(Collator::PRIMARY);

		Collator::EComparisonResult result = Collator::EQUAL;

		//compare the 2 strings
		result = coll->compare(getUnicodeString(utf8String), getUnicodeString(src));

		//close the collator
		delete coll;

		return result;
}

	int xqpString::compare(const xqpString& src, const char * loc) const{
		//create the collator object
		UErrorCode status = U_ZERO_ERROR;

		Collator *coll = Collator::createInstance(Locale(loc), status);
	
		if(U_FAILURE(status)) {
			ZorbaErrorAlerts::error_alert(
					error_messages::XQP0014_SYSTEM_SHOUD_NEVER_BE_REACHED,
					error_messages::SYSTEM_ERROR,
					NULL
				);
		}

		//set level 1 comparison for the collator
		coll->setStrength(Collator::PRIMARY);

		Collator::EComparisonResult result = Collator::EQUAL;

		//compare the 2 strings
		result = coll->compare(getUnicodeString(utf8String), getUnicodeString(src));

		//close the collator
		delete coll;

		return result;
}

	int xqpString::compare(const char* src) const{
		//TODO optimize the code here
		xqpString tmp(src);
		return compare(tmp);
	}

	//xqpString::Length
	xqpString::size_type xqpString::size() const{
		std::vector<char> v;
		char * c;

		v.reserve(bytes());
		std::strcpy(&v[0], utf8String.c_str());
		c = &v[0];
		
		return UTF8Distance(c, c + utf8String.size());
	}

	xqpString::size_type xqpString::length() const{
		std::vector<char> v;
		char * c;

		v.reserve(bytes());
		std::strcpy(&v[0], utf8String.c_str());
		c = &v[0];
		
		return UTF8Distance(c, c + utf8String.size());
	}

	xqpString::size_type xqpString::bytes() const{
		return utf8String.size();
	}

	bool xqpString::empty() const{
		return utf8String.empty();
	}

	void xqpString::reserve(xqpString::size_type size){
		utf8String.reserve(size);
	}

	//xqpString::Clear
	void xqpString::clear(){
		utf8String.erase();
	}

	//
	std::vector<int> xqpString::getCodepoints(){
		std::vector<int> tt;
	
		std::vector<char> v;
		char * c;
		uint16_t vLength;
	
		vLength = bytes() + 1;
		v.reserve(vLength);
		std::strcpy(&v[0], utf8String.c_str());
		c = &v[0];
	
		while( --vLength > 0 ){
			tt.push_back(UTF8Decode(c));
		}
		return tt;
	}

	const char* xqpString::c_str() const{
		return utf8String.c_str();
	}

	// Private methods
	UnicodeString xqpString::getUnicodeString(const xqpString& in) const{
		UnicodeString ret;
		UErrorCode status = U_ZERO_ERROR;
		int32_t len = in.bytes();
		UChar* buffer = ret.getBuffer(len);

		u_strFromUTF8(buffer, ret.getCapacity(), &len, in.c_str(), len, &status);

		ret.releaseBuffer(U_SUCCESS(status) ? len : 0);

		if(U_FAILURE(status)) {
			ZorbaErrorAlerts::error_alert(
						error_messages::XQP0014_SYSTEM_SHOUD_NEVER_BE_REACHED,
						error_messages::SYSTEM_ERROR,
						NULL
					);
		}

		return ret;
	}

	xqpString getXqpString(UnicodeString in){
		//TODO implement it
		return xqpString();
	}

}/* namespace xqp */
