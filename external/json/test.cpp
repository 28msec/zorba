
#include <iostream>
using namespace std;

#include "value.h"
#include "parser.h"

int main(){
	cout<< "Hello World" <<endl;
	json::parser parser;
	json::value *testval=parser.parse("{ a : 1, b: 3.1415926, c: \"Where {the} bee drops, there drop I\", d:{ a:2, b:6.183, c: \"On a cool\"}}");
	wstring *teststr=testval->getstring(L"",true);
	wcout<<(*teststr)<<endl;
	//delete [] teststr;
}

