#include "synchronous_logger.h"


zorba::synchronous_logger::SynchronousLogger::SynchronousLogger( std::ostream &stream )
:
m_stream(stream)
{
}

zorba::synchronous_logger::SynchronousLogger& zorba::synchronous_logger::SynchronousLogger::operator<<( const long input )
{
	AutoLock lock(m_lock, Lock::WRITE);
	m_stream << input;
	m_stream.flush();
	return *this;
}

zorba::synchronous_logger::SynchronousLogger& zorba::synchronous_logger::SynchronousLogger::operator<<( const zorba::String input )
{
	AutoLock lock(m_lock, Lock::WRITE);
	m_stream << input;
	m_stream.flush();
	return *this;
}

