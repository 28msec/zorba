
#include "itemstore.h"

using namespace std;
using namespace xqp;

int main(int argc, char* argv[])
{
	itemstore istore("itemdata",1<<16);
	vector<void*> refv;
	context ctx;

	cout << "istore.eos() = " << istore.eos() << endl;
	refv.push_back(new(istore) text_node("this is the first sentence"));
	cout << "istore.eos() = " << istore.eos() << endl;
	refv.push_back(new(istore) text_node("this is the second sentence"));
	cout << "istore.eos() = " << istore.eos() << endl;

	text_node * tn_p;
	vector<itemref>::const_iterator it = refv.begin();
	for (; it!=refv.end(); ++it) {
		tn_p = new(*it) text_node();
		tn_p->put(&ctx) << endl;
	}

}
