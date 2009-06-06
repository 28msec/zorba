#ifndef DEBUGGER_COMMUNICATION_H
#define DEBUGGER_COMMUNICATION_H

#include "debugger_protocol.h"
#include "socket.h"

namespace zorba {
	class DebuggerCommunicator {
	public:
		DebuggerCommunicator(unsigned short aCommandPort, unsigned short aEventPort);
		virtual ~DebuggerCommunicator();

	public:
		void handshake();
		AbstractCommandMessage* handleTCPClient();
		void sendEvent(AbstractCommandMessage* aMessage);
		void sendReplyMessage(AbstractCommandMessage* aMessage);

	private:
		TCPSocket* m_commandSocket;
		TCPSocket* m_eventSocket;
	};
}

#endif // DEBUGGER_COMMUNICATION_H

