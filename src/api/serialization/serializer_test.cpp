#include "api/serialization/serializer.h"
#include <zorba/item.h>
#include "util/list.h"
#include "store/naive/basic_item_factory.h"

using namespace zorba;

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
