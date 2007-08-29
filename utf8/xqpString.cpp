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
		string_()
	{}

	xqpString::xqpString(const xqpString& src)
	:
		string_(src.string_)
	{}

	xqpString::xqpString(const std::string& src)
	:
		string_(src)
	{}

	xqpString::xqpString(const char* src)
	:
		string_(src)
	{}

	xqpString::~xqpString()
	{}

	//xqpString::operator=()
	xqpString& xqpString::operator=(const xqpString& src){
		string_ = src.string_;
		return *this;
	}
	
	xqpString& xqpString::operator=(const std::string& src){
		string_ = src;
		return *this;
	}
	
	xqpString& xqpString::operator=(const char* src){
		string_ = src;
		return *this;
	}
	
	xqpString& xqpString::operator=(uint cp){
		string_.reserve(4);
		char seq[4] = {0,0,0,0};
		EncodeUtf8(cp, seq);
		string_ = seq;
		return *this;
	}
	
	xqpString& xqpString::operator=(char c){
		string_ = c;
		return *this;
	}
	
	//xqpString::operator+=()
	xqpString& xqpString::operator+=(const xqpString& src){
		string_ += src.string_;
		return *this;
	}

	xqpString& xqpString::operator+=(const char* src){
		string_ += src;
		return *this;
	}

	xqpString& xqpString::operator+=(uint cp){
		string_.reserve(4);
		char seq[4] = {0,0,0,0};
		EncodeUtf8(cp, seq);
		string_ += seq;
		return *this;
	}

	xqpString& xqpString::operator+=(char c){
		string_ += c;
		return *this;
	}
	
}/* namespace xqp */
