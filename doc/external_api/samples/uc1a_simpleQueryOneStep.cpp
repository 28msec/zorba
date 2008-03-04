
#include <zorba/zorba_singlethread.h>

#include <iostream>

using namespace std;
using namespace zorba;

/*
	Using Zorba in single thread mode.
	Execute an xquery in a single step.
*/

int uc1a_simpleQueryOneStep(int argc, char* argv[])
{
	ZorbaSingleThread::execute("1+2", std::cout);

	return 0;
}
