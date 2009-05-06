#ifndef SYNCHRONOUS_LOGGER
#define SYNCHRONOUS_LOGGER

#include "zorba/config.h"
#include "zorba/zorbastring.h"
#include "zorbautils/lock.h"

#include <iostream>
#include <string>

namespace zorba {
	namespace synchronous_logger {
		class ZORBA_DLL_PUBLIC SynchronousLogger {
		public:
			SynchronousLogger(std::ostream &stream);

			SynchronousLogger& operator<<(const long input);
			SynchronousLogger& operator<<(const zorba::String input);

		private:
			std::ostream &m_stream;
		};
		static Lock m_lock;
		static SynchronousLogger cerr(std::cerr);
		static SynchronousLogger clog(std::clog);
		static SynchronousLogger cout(std::cout);
	}
}

#endif // SYNCHRONOUS_LOGGER