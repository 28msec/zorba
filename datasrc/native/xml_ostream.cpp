/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: xml_ostream.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 */

#include "xml_ostream.h"

#include <ostream>
#include "../../types/qname.h"

#include "xml_store.h"
#include "text_store.h"

using namespace xqp;
namespace xqp {


xml_ostream::xml_ostream()
:
	offset(0),
	id(0)
{
}

xml_ostream::~xml_ostream()
{
}


xml_ostream& xml_ostream::operator<<(bool val)
{
	if (overflow(2)) flush();
	cbuf[offset++] = bool_code | 0x01;
	cbuf[offset++] = (val ? 1 : 0);

	return *this;
}

xml_ostream& xml_ostream::operator<<(int16_t val)
{
	unsigned char a = (unsigned char)((val & 0xff00) >> 8);
	unsigned char b = (unsigned char)((val & 0x00ff));

	if (a!=0) {
		if (overflow(3)) flush();
		cbuf[offset++] = int16_code | 2;
		cbuf[offset++] = a;
		cbuf[offset++] = b;
	}
	else {
		if (overflow(2)) flush();
		cbuf[offset++] = int16_code | 1;
		cbuf[offset++] = b;
	}

	return *this;
}

xml_ostream& xml_ostream::operator<<(uint16_t val)
{
	unsigned char a = (unsigned char)((val & 0xff00) >> 8);
	unsigned char b = (unsigned char)((val & 0x00ff));

	if (a!=0) {
		if (overflow(3)) flush();
		cbuf[offset++] = uint16_code | 2;
		cbuf[offset++] = a;
		cbuf[offset++] = b;
	}
	else {
		if (overflow(2)) flush();
		cbuf[offset++] = uint16_code | 1;
		cbuf[offset++] = b;
	}

	return *this;
}

xml_ostream& xml_ostream::operator<<(int32_t val)
{
	unsigned char a = (unsigned char)((val & 0xff000000) >> 24);
  unsigned char b = (unsigned char)((val & 0x00ff0000) >> 16);
  unsigned char c = (unsigned char)((val & 0x0000ff00) >>  8);
  unsigned char d = (unsigned char)((val & 0x000000ff));     

  if (a!=0) {
		if (overflow(5)) flush();
		cbuf[offset++] = int32_code | 4;
		cbuf[offset++] = a;
		cbuf[offset++] = b;
		cbuf[offset++] = c;
		cbuf[offset++] = d;
	}
  else if (b!=0) {
		if (overflow(5)) flush();
		cbuf[offset++] = int32_code | 3;
		cbuf[offset++] = b;
		cbuf[offset++] = c;
		cbuf[offset++] = d;
	}
  else if (c!=0) {
		if (overflow(4)) flush();
		cbuf[offset++] = int32_code | 2;
		cbuf[offset++] = c;
		cbuf[offset++] = d;
	}
	else {
		if (overflow(2)) flush();
		cbuf[offset++] = int32_code | 1;
		cbuf[offset++] = d;
	}

	return *this;
}

xml_ostream& xml_ostream::operator<<(uint32_t val)
{
	unsigned char a = (unsigned char)((val & 0xff000000) >> 24);
  unsigned char b = (unsigned char)((val & 0x00ff0000) >> 16);
  unsigned char c = (unsigned char)((val & 0x0000ff00) >>  8);
  unsigned char d = (unsigned char)((val & 0x000000ff));     

  if (a!=0) {
		if (overflow(5)) flush();
		cbuf[offset++] = uint32_code | 4;
		cbuf[offset++] = a;
		cbuf[offset++] = b;
		cbuf[offset++] = c;
		cbuf[offset++] = d;
	}
  else if (b!=0) {
		if (overflow(5)) flush();
		cbuf[offset++] = uint32_code | 3;
		cbuf[offset++] = b;
		cbuf[offset++] = c;
		cbuf[offset++] = d;
	}
  else if (c!=0) {
		if (overflow(4)) flush();
		cbuf[offset++] = uint32_code | 2;
		cbuf[offset++] = c;
		cbuf[offset++] = d;
	}
	else {
		if (overflow(2)) flush();
		cbuf[offset++] = uint32_code | 1;
		cbuf[offset++] = d;
	}

	return *this;
}

xml_ostream& xml_ostream::operator<<(int64_t val)
{
	unsigned char a = (unsigned char)((val & 0xff00000000000000LL) >> 56);
  unsigned char b = (unsigned char)((val & 0x00ff000000000000LL) >> 48);
  unsigned char c = (unsigned char)((val & 0x0000ff0000000000LL) >> 40);
  unsigned char d = (unsigned char)((val & 0x000000ff00000000LL) >> 32);     
	unsigned char e = (unsigned char)((val & 0x00000000ff000000LL) >> 24);
  unsigned char f = (unsigned char)((val & 0x0000000000ff0000LL) >> 16);
  unsigned char g = (unsigned char)((val & 0x000000000000ff00LL) >>  8);
  unsigned char h = (unsigned char)((val & 0x00000000000000ffLL));     

  if (a!=0) {
		if (overflow(9)) flush();
		cbuf[offset++] = int64_code | 8;
		cbuf[offset++] = a;
		cbuf[offset++] = b;
		cbuf[offset++] = c;
		cbuf[offset++] = d;
		cbuf[offset++] = e;
		cbuf[offset++] = f;
		cbuf[offset++] = g;
		cbuf[offset++] = h;
	}
  else if (b!=0) {
		if (overflow(8)) flush();
		cbuf[offset++] = int64_code | 7;
		cbuf[offset++] = b;
		cbuf[offset++] = c;
		cbuf[offset++] = d;
		cbuf[offset++] = e;
		cbuf[offset++] = f;
		cbuf[offset++] = g;
		cbuf[offset++] = h;
	}
  else if (c!=0) {
		if (overflow(7)) flush();
		cbuf[offset++] = int64_code | 6;
		cbuf[offset++] = c;
		cbuf[offset++] = d;
		cbuf[offset++] = e;
		cbuf[offset++] = f;
		cbuf[offset++] = g;
		cbuf[offset++] = h;
	}
	else if (d!=0) {
		if (overflow(6)) flush();
		cbuf[offset++] = int64_code | 5;
		cbuf[offset++] = d;
		cbuf[offset++] = e;
		cbuf[offset++] = f;
		cbuf[offset++] = g;
		cbuf[offset++] = h;
	}
  else if (e!=0) {
		if (overflow(5)) flush();
		cbuf[offset++] = int64_code | 4;
		cbuf[offset++] = e;
		cbuf[offset++] = f;
		cbuf[offset++] = g;
		cbuf[offset++] = h;
	}
  else if (f!=0) {
		if (overflow(5)) flush();
		cbuf[offset++] = int64_code | 3;
		cbuf[offset++] = f;
		cbuf[offset++] = g;
		cbuf[offset++] = h;
	}
  else if (g!=0) {
		if (overflow(4)) flush();
		cbuf[offset++] = int64_code | 2;
		cbuf[offset++] = g;
		cbuf[offset++] = h;
	}
	else {
		if (overflow(2)) flush();
		cbuf[offset++] = int64_code | 1;
		cbuf[offset++] = h;
	}

	return *this;
}


xml_ostream& xml_ostream::operator<<(uint64_t val)
{
	unsigned char a = (unsigned char)((val & 0xff00000000000000LL) >> 56);
  unsigned char b = (unsigned char)((val & 0x00ff000000000000LL) >> 48);
  unsigned char c = (unsigned char)((val & 0x0000ff0000000000LL) >> 40);
  unsigned char d = (unsigned char)((val & 0x000000ff00000000LL) >> 32);     
	unsigned char e = (unsigned char)((val & 0x00000000ff000000LL) >> 24);
  unsigned char f = (unsigned char)((val & 0x0000000000ff0000LL) >> 16);
  unsigned char g = (unsigned char)((val & 0x000000000000ff00LL) >>  8);
  unsigned char h = (unsigned char)((val & 0x00000000000000ffLL));     

  if (a!=0) {
		if (overflow(9)) flush();
		cbuf[offset++] = uint64_code | 8;
		cbuf[offset++] = a;
		cbuf[offset++] = b;
		cbuf[offset++] = c;
		cbuf[offset++] = d;
		cbuf[offset++] = e;
		cbuf[offset++] = f;
		cbuf[offset++] = g;
		cbuf[offset++] = h;
	}
  else if (b!=0) {
		if (overflow(8)) flush();
		cbuf[offset++] = uint64_code | 7;
		cbuf[offset++] = b;
		cbuf[offset++] = c;
		cbuf[offset++] = d;
		cbuf[offset++] = e;
		cbuf[offset++] = f;
		cbuf[offset++] = g;
		cbuf[offset++] = h;
	}
  else if (c!=0) {
		if (overflow(7)) flush();
		cbuf[offset++] = uint64_code | 6;
		cbuf[offset++] = c;
		cbuf[offset++] = d;
		cbuf[offset++] = e;
		cbuf[offset++] = f;
		cbuf[offset++] = g;
		cbuf[offset++] = h;
	}
	else if (d!=0) {
		if (overflow(6)) flush();
		cbuf[offset++] = uint64_code | 5;
		cbuf[offset++] = d;
		cbuf[offset++] = e;
		cbuf[offset++] = f;
		cbuf[offset++] = g;
		cbuf[offset++] = h;
	}
  else if (e!=0) {
		if (overflow(5)) flush();
		cbuf[offset++] = uint64_code | 4;
		cbuf[offset++] = e;
		cbuf[offset++] = f;
		cbuf[offset++] = g;
		cbuf[offset++] = h;
	}
  else if (f!=0) {
		if (overflow(5)) flush();
		cbuf[offset++] = uint64_code | 3;
		cbuf[offset++] = f;
		cbuf[offset++] = g;
		cbuf[offset++] = h;
	}
  else if (g!=0) {
		if (overflow(4)) flush();
		cbuf[offset++] = uint64_code | 2;
		cbuf[offset++] = g;
		cbuf[offset++] = h;
	}
	else {
		if (overflow(2)) flush();
		cbuf[offset++] = uint64_code | 1;
		cbuf[offset++] = h;
	}

	return *this;
}

xml_ostream& xml_ostream::operator<<(float val)
{
	uint32_t fval = (uint32_t)(val);

	unsigned char a = (unsigned char)((fval & 0xff000000) >> 24);
  unsigned char b = (unsigned char)((fval & 0x00ff0000) >> 16);
  unsigned char c = (unsigned char)((fval & 0x0000ff00) >>  8);
  unsigned char d = (unsigned char)((fval & 0x000000ff));     

	if (overflow(5)) flush();
	cbuf[offset++] = float32_code | 4;
	cbuf[offset++] = a;
	cbuf[offset++] = b;
	cbuf[offset++] = c;
	cbuf[offset++] = d;

	return *this;
}

xml_ostream& xml_ostream::operator<<(double val)
{
	uint64_t dval = (uint64_t)(val);

	unsigned char a = (unsigned char)((dval & 0xff00000000000000LL) >> 56);
  unsigned char b = (unsigned char)((dval & 0x00ff000000000000LL) >> 48);
  unsigned char c = (unsigned char)((dval & 0x0000ff0000000000LL) >> 40);
  unsigned char d = (unsigned char)((dval & 0x000000ff00000000LL) >> 32);     
	unsigned char e = (unsigned char)((dval & 0x00000000ff000000LL) >> 24);
  unsigned char f = (unsigned char)((dval & 0x0000000000ff0000LL) >> 16);
  unsigned char g = (unsigned char)((dval & 0x000000000000ff00LL) >>  8);
  unsigned char h = (unsigned char)((dval & 0x00000000000000ffLL));     

	if (overflow(9)) flush();
	cbuf[offset++] = double64_code | 8;
	cbuf[offset++] = a;
	cbuf[offset++] = b;
	cbuf[offset++] = c;
	cbuf[offset++] = d;
	cbuf[offset++] = e;
	cbuf[offset++] = f;
	cbuf[offset++] = g;
	cbuf[offset++] = h;

	return *this;
}

xml_ostream& xml_ostream::operator<<(QName const& q)
{
	string prefix = q.get_prefix();
	string   name = q.get_name();
	uint64_t  uri = q.get_namespace_hash();

	uint16_t prefix_len = prefix.length();
	uint16_t name_len = name.length();
	uint16_t len = 0;

	if (prefix_len>0) len = (prefix_len + 1);
	len += name_len;
	if (len==0) return *this;

	if (uri!=0) {
		if (overflow(1)) flush();
		cbuf[offset++] = qname1_code;
		operator<<(uri);
	}
	else {
		if (overflow(1)) flush();
		cbuf[offset++] = qname0_code;
	}

	operator<<(len);

	if (overflow(len)) flush();
	for (uint32_t j=0; j<prefix_len; ++j) {
		cbuf[offset++] = prefix[j];
	}
	if (prefix_len>0) cbuf[offset++] = ':';
	for (uint32_t j=0; j<name_len; ++j) {
		cbuf[offset++] = name[j];
	}

	return *this;
}


bool xml_ostream::overflow(uint32_t len) const
{
	return (offset+len >= BLOCK_SIZE);
}

xml_ostream& xml_ostream::flush()
{
/*
	storage_manager.put(cbuf);
	cbuf_id = storage_manager.get(cbuf);
*/
	cout.write((const char*)cbuf,offset);
	memset(cbuf,0,BLOCK_SIZE);
	offset = 0;
	return *this;
}


xml_ostream& xml_ostream::put(char ch)
{
	if (overflow(2)) flush();
	cbuf[offset++] = pcdata_code;
	cbuf[offset++] = ch;
	return *this;
}

xml_ostream& xml_ostream::seekp(std::streampos pos)
{
	return *this;
}

xml_ostream& xml_ostream::seekp(std::streamoff off, std::ios_base::seekdir dir)
{
	return *this;
}

std::streampos xml_ostream::tellp()
{
	return 0; 
}

xml_ostream& xml_ostream::write(const char* str, std::streamsize n)
{
	if (n<16) {
		if (overflow(n+1)) flush();
		cbuf[offset++] = pcdata_code | n;
		memcpy(&cbuf[offset],str,n);
		offset += n;
	}
	else {
		if (overflow(1)) flush();
		cbuf[offset++] = pcdata_code;
		operator<<((uint32_t)n);
		memcpy(&cbuf[offset],str,n);
		offset += n;
	}
	return *this;
}


xml_ostream& operator<<(xml_ostream& os, char ch)
{
	return operator<<(os, (unsigned char)ch);
}

xml_ostream& operator<<(xml_ostream& os, signed char ch)
{
	return operator<<(os, (unsigned char)ch);
}

xml_ostream& operator<<(xml_ostream& os, unsigned char ch)
{
	if (os.overflow(1)) os.flush();
	os.cbuf[os.offset++] = pcdata_code;
	os.cbuf[os.offset++] = ch;
	return os;
}

xml_ostream& operator<<(xml_ostream& os, const char* str)
{
	return operator<<(os,(const unsigned char*)str);
}

xml_ostream& operator<<(xml_ostream& os, const signed char* str)
{
	return operator<<(os,(const unsigned char*)str);
}

xml_ostream& operator<<(xml_ostream& os, const unsigned char* str)
{
	uint32_t n = strlen((const char*)str);
	if (n<16) {
		if (os.overflow(n+1)) os.flush();
		os.cbuf[os.offset++] = pcdata_code | n;
		memcpy(&os.cbuf[os.offset],str,n);
		os.offset += n;
	}
	else {
		if (os.overflow(1)) os.flush();
		os.cbuf[os.offset++] = pcdata_code;
		os.operator<<(n);
		memcpy(&os.cbuf[os.offset],str,n);
		os.offset += n;
	}
	return os;
}


}	/* namespace xqp */
