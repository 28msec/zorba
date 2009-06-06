#include "DebuggerTestClient.h"
#include "DebuggerTestHandler.h"

#include <string>
#include <iostream>

#ifdef WIN32
#define sleep(n) Sleep(1000*n)
#endif

namespace zorba {
	int test_run() {
		sleep(8);
		std::cout << "Run Test" << std::endl;
		DebuggerTestClient client("test.xq", "<a>Hello World</a>");
		Sleep(8000);
		client.run();
		DebuggerTestHandler::DebugEvent evt = client.getNextEvent();
		/*if (evt != DebuggerTestHandler::TERMINATED) {
			return -1;
		}*/
		while (evt != DebuggerTestHandler::TERMINATED) {
			evt = client.getNextEvent();
			sleep(1);
		}
		std::string res = client.getQueryResult();
		if (res != "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<a>Hello World</a>") {
			std::cerr << "Result:" << res << std::endl;
			return -1;
		}
		return 0;
	}
}

int test_debugger_server (int argc, char* argv[]) {
	if (zorba::test_run() != 0) {
		return 1;
	}
	return 0;
}
