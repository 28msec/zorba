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
 * @author Nicolae Brinza (nbrinza@ipdevel.ro)
 * @file serialization/serializer_test.cpp
 *
 */



#include "api/serialization/serializer.h"
#include "store/api/item.h"
#include "util/list.h"
#include "store/naive/basic_item_factory.h"

using namespace xqp;

int main (int argc, char** argv)
{
	list<Item_t> items;      

	BasicItemFactory bif;

	items.push_back(bif.createInteger(23));
	items.push_back(bif.createInteger(55));
	items.push_back(bif.createInteger(63));
	items.push_back(bif.createInteger(78));

	serializer* ser = new serializer();
	ser->serialize_as_xml(items, cout);	


	return 0;
}
