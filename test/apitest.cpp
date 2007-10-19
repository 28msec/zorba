

////using the C++ API

#include "zorba_api/zorba_api.h"
#include "store/native/basic_item_factory.h"

#ifndef _WIN32_WCE
int main(int argc, char* argv[])
#else
int _tmain(int argc, _TCHAR* argv[])
#endif
{
	BasicItemFactory basicItemFactory;
	SimpleStore simpleStore;
	ZorbaFactory	zorba_factory(&basicItemFactory);
	

	///thread specific

	zorba_factory.InitThread(&basicItemFactory);



	XQuery*		query;
	query = zorba_factory.CreateQuery("1+1");

	query->compile();

	XQueryResult		*result;

	result = query->execute();

	Item_t		it;

	it = result->next();

	cout << it->show() << endl;

	delete result;
	delete query;

	zorba_factory.UninitThread();

}

