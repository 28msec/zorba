#ifndef DEBUGGER_HELPER_FUNCTIONS
#define DEBUGGER_HELPER_FUNCTIONS

namespace zorba {
	class xqpString;
	class debugger_helper_functions {
	public:
		static xqpString deascapeString(xqpString str);
	};
}

#endif //DEBUGGER_HELPER_FUNCTIONS