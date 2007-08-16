#include <iostream>
#include <boost/shared_ptr.hpp>

#include "parser/xquery_driver.h"
#include "values/primitive_values.h"
#include "timer.h"

using namespace std;

// template < typename T>
// class smart : public boost::shared_ptr<T> {
// smart(T* realPtr = 0)
// };


item_t returnItems1() {
 	item_t i = new numericValue(xs_integer, 10);
 	return i;
}

item_t passer1() {
	item_t i = returnItems1();
	return i;
}

item* returnItems2() {
 	item* i = new numericValue(xs_integer, 10);
 	return i;
}

item* passer2() {
	item* i = returnItems2();
	return i;
}

boost::shared_ptr<item> returnItems3() {
 	boost::shared_ptr<item> i(new numericValue(xs_integer, 10));
 	return i;
}

boost::shared_ptr<item> passer3() {
	boost::shared_ptr<item> i = returnItems3();
	return i;
}

void test() {
	item_t it;
	item* ip;
	boost::shared_ptr<item> is;
	long long l = 0;
	Timer timer;
	
	cout << "START" << endl;
	for(int n = 1; n < 10; n++){
		cout << n << "X" << endl;
		l = 0;
		timer.start();
		for(int i = 0; i < 10000000 * n; i++) {
			it = passer1();
			l += 1;
		}
		timer.end();
		cout << l << endl;
		timer.print();
		
		timer.start();
		l = 0;
		for(int i = 0; i < 10000000 * n; i++) {
			ip = passer2();
			delete ip;
			l += 1;
		}
		timer.end();
		cout << l << endl;
		timer.print();
		
		timer.start();
		l = 0;
		for(int i = 0; i < 10000000 * n; i++) {
			is = passer3();
			l += 1;
		}
		timer.end();
		cout << l << endl;
		timer.print();
		
	}
	cout << "END" << endl;
}

int main(int argc, char* argv[]) {
	test();
}
