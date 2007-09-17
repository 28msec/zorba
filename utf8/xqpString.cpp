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

#include "xqpString.h"

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
		os << utf8_src;
		return os;
	}

	//xqpString::compare
	int xqpString::compare(const xqpString& src)	const{
		//TODO optimize the code here
		std::vector<char> v0;
		std::vector<char> v1;
		char * c0;
		char * c1;
		size_type vLength;
		uint32_t cp0, cp1;
		
		vLength = bytes();
		if (vLength > src.bytes())
			vLength = src.bytes();

		v0.reserve(bytes());
		std::strcpy(&v0[0], utf8String.c_str());
		c0 = &v0[0];

		v1.reserve(src.bytes());
		std::strcpy(&v1[0], src.utf8String.c_str());
		c1 = &v1[0];

		while( vLength > 0 ){
			cp0 = UTF8Decode(c0);
			cp1 = UTF8Decode(c1);

			if(cp0 < cp1)
				return -1;
			else if(cp0 > cp1)
				return 1;

			vLength--;
		}

		if(bytes() == src.bytes())
			return 0;
		else if(bytes() < src.bytes())
			return -1;
		else
			return 1;
	}

	int xqpString::compare(const char* src)	const{
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
	
	const char* xqpString::c_str() {
		return utf8String.c_str();
	}
}/* namespace xqp */
