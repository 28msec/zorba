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

#ifndef ZORBA_COLLATION_H
#define ZORBA_COLLATION_H

#include <string>

namespace zorba {

class collation : public SimpleRCObject
{
protected:
	std::string name;

public:
	collation( std::string const& _name) : name(_name) { }
	collation() : name("") { }
	~collation() {}

public:
	std::string get_name() const { return name; }

};

}	/* namespace zorba*/
#endif	/* ZORBA_COLLATION_H */
