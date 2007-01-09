/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: xml_ostream.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 */

#ifndef XQP_XML_OSTREAM_H
#define XQP_XML_OSTREAM_H

#include "../../types/qname.h"
#include "xml_typecodes.h"

//#include "xml_store.h"
//#include "text_store.h"

namespace xqp {

#define BLOCK_SIZE 4096

class xml_ostream
{
protected:
	unsigned char cbuf[BLOCK_SIZE];
	uint32_t offset;
	uint64_t id;

	//xml_storage_manager* xml_store_p;
	//text_storage_manager* text_store_p;

public:
	xml_ostream();
	~xml_ostream();

public:	// ostream interface

	// Perform formatted output operations (insertion)
	xml_ostream& operator<<(uint32_t val);
	xml_ostream& operator<<(uint64_t val);

	// deferred implementations
	//xml_ostream& operator<<(float val);
	//xml_ostream& operator<<(double val);
	//xml_ostream& operator<<(void* val);

	// stream manipulator
	//xml_ostream& operator<<(xml_ostream& (*pf)(xml_istream&));

	xml_ostream& operator<<(QName const&);
	xml_ostream& operator<<(std::string const&);

	friend xml_ostream& operator<<(xml_ostream& os, char ch);
	friend xml_ostream& operator<<(xml_ostream& os, signed char ch);
	friend xml_ostream& operator<<(xml_ostream& os, unsigned char ch);
	friend xml_ostream& operator<<(xml_ostream& os, const char* str);
	friend xml_ostream& operator<<(xml_ostream& os, const signed char* str);
	friend xml_ostream& operator<<(xml_ostream& os, const unsigned char* str);

	// Flush buffer
	xml_ostream& flush();

	// Put a single character into output stream
	xml_ostream& put(char ch); 

	// Set position of put pointer.
	xml_ostream&  seekp(std::streampos pos);
	xml_ostream&  seekp(std::streamoff off, std::ios_base::seekdir dir);

	// Get position of put pointer
	std::streampos tellp();

	// Write a sequence of characters
	xml_ostream&  write(const char* str, std::streamsize n);

private:
	bool overflow(uint32_t) const;


};


}	/* namespace xqp */
#endif	/* XQP_XML_OSTREAM_H */









/*
class xml_ostream
{
protected:
	uint64_t id;
	xml_storage_manager* xml_store_p;
	text_storage_manager* text_store_p;

public:
	xml_ostream();
	~xml_ostream();

public:

	// Perform formatted output operations
	xml_ostream& operator<<(uint32_t val);
	xml_ostream& operator<<(uint64_t val);
	xml_ostream& operator<<(float val);
	xml_ostream& operator<<(double val);
	xml_ostream& operator<<(void* val);
  xml_ostream& operator<<(QName const&);
	xml_ostream& operator<<(std::string const&);

	// stream manipulator
	xml_ostream& operator<<(xml_ostream& (*pf)(xml_istream&));

	friend xml_ostream& operator<<(xml_ostream& os, char ch);
	friend xml_ostream& operator<<(xml_ostream& os, signed char ch);
	friend xml_ostream& operator<<(xml_ostream& os, unsigned char ch);
	friend xml_ostream& operator<<(xml_ostream& os, const char* str);
	friend xml_ostream& operator<<(xml_ostream& os, const signed char* str);
	friend xml_ostream& operator<<(xml_ostream& os, const unsigned char* str);

	// Flush buffer
	xml_ostream& flush();

	// Put a single character into output stream
	xml_ostream& put(char ch); 

	// Set position of put pointer.
	xml_ostream&  seekp(std::streampos pos);
	xml_ostream&  seekp(std::streamoff off, std::ios_base::seekdir dir);

	// Get position of put pointer
	std::streampos tellp();

	// Write a sequence of characters
	xml_ostream&  write(const char* str, std::streamsize n);

private:
	bool overflow(uint32_t) const;

};
*/