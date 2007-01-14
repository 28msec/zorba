/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: xml_istream.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 */

#include "xml_istream.h"

using namespace std;
namespace xqp {

xml_istream::xml_istream()
{
}
	
xml_istream::~xml_istream()
{
}

xml_istream& xml_istream::operator>>(bool& val)
{
	val = false;
	return *this;
}

xml_istream& xml_istream::operator>>(int16_t& val)
{
	val = 0;
	return *this;
}

xml_istream& xml_istream::operator>>(uint16_t& val)
{
	val = 0;
	return *this;
}

xml_istream& xml_istream::operator>>(int32_t& val)
{
	val = 0;
	return *this;
}

xml_istream& xml_istream::operator>>(uint32_t& val)
{
	val = 0;
	return *this;
}

xml_istream& xml_istream::operator>>(int64_t& val)
{
	val = 0;
	return *this;
}

xml_istream& xml_istream::operator>>(uint64_t& val)
{
	val = 0;
	return *this;
}

xml_istream& xml_istream::operator>>(float& val)
{
	val = 0;
	return *this;
}

xml_istream& xml_istream::operator>>(double& val)
{
	val = 0;
	return *this;
}

xml_istream& xml_istream::operator>>(QName& val)
{
	val.set_prefix("xqp");
	val.set_name("test");
	return *this;
}

streamsize xml_istream::gcount() const
{
	return 0;
}
	
int xml_istream::get()
{
	return 0;
}

xml_istream& xml_istream::get(char& c)
{
	c = 0;
	return *this;
}

xml_istream& xml_istream::get(char* s, streamsize n)
{
	*s = 0;
	return *this;
}

xml_istream& xml_istream::get(char* s, streamsize n, char delim)
{
	*s = 0;
	return *this;
}

xml_istream& xml_istream::getline(char* s, streamsize n)
{
	*s = 0;
	return *this;
}

xml_istream& xml_istream::getline(char* s, streamsize n, char delim)
{
	*s = 0;
	return *this;
}
	
xml_istream& xml_istream::ignore(streamsize n, int delim) 
{
	return *this;
}
	
int xml_istream::peek()
{
	return 0;
}
	
xml_istream& xml_istream::putback(char c) 
{
	return *this;
}
	
xml_istream& xml_istream::read(char* s, streamsize n) 
{
	return *this;
}
	
streamsize xml_istream::readsome(char* s, streamsize n)
{
	return 0;
}
	
int xml_istream::sync()
{
	return 0;
}
	
streampos xml_istream::tellg()
{
	return 0;
}
	
xml_istream& xml_istream::unget()
{
	return *this;
}

bool xml_istream::underflow(uint32_t) const
{
	return false;
}


////////////////////////////////
//	friends
////////////////////////////////

xml_istream& operator>>(xml_istream& os, char& ch)
{
	return os;
}

xml_istream& operator>>(xml_istream& os, signed char& ch)
{
	return os;
}

xml_istream& operator>>(xml_istream& os, unsigned char& ch)
{
	return os;
}

xml_istream& operator>>(xml_istream& os, const char* str)
{
	return os;
}

xml_istream& operator>>(xml_istream& os, const signed char* str)
{
	return os;
}

xml_istream& operator>>(xml_istream& os, const unsigned char* str)
{
	return os;
}
	

}	/* namespace xqp */

