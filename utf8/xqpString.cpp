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
		EncodeUtf8(cp, seq);
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
		EncodeUtf8(cp, seq);
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
		//TODO call constructor for a non UTF-8 encoded string
		utf8_src = buffer;
		return is;
	}

	std::ostream& operator<<(std::ostream& os, const xqpString& utf8_src){
		//TODO convert from utf8 encoded string to normal string !?
		os << utf8_src;
		return os;
	}

	//xqpString::compare
	int32_t xqpString::compare(const xqpString& src)	const{
		//TODO call a function from utf8.h that does a utf8 comparison...
		return utf8String.compare(src.utf8String);
	}
	
	int32_t xqpString::compare(const char* src)	const{
		//TODO call a function from utf8.h that does a utf8 comparison...
		return utf8String.compare(src);
	}
	
}/* namespace xqp */
