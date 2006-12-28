/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: xml_istream.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 */

#ifndef XQP_XML_ISTREAM_H
#define XQP_XML_ISTREAM_H

#include <istream>
#include "../../types/qname.h"
#include "xml_typecodes.h"

//#include "xml_storage_manager.h"
//#include "text_storage_manager.h"


namespace xqp {

#define BLOCK_SIZE 4096


class xml_istream : public std::istream
{
protected:
	unsigned char cbuf[BLOCK_SIZE];
	uint32_t offset;
	uint64_t id;
	//xml_storage_manager* xml_store_p;
	//text_storage_manager* text_store_p;

public:

	xml_istream();
	~xml_istream();

public:	// istream interface

	// Perform formatted output operations (insertion)
	xml_istream& operator>>(bool& val);
	xml_istream& operator>>(int16_t& val);
	xml_istream& operator>>(uint16_t& val);
	xml_istream& operator>>(int32_t& val);
	xml_istream& operator>>(uint32_t& val);
	xml_istream& operator>>(int64_t& val);
	xml_istream& operator>>(uint64_t& val);
	xml_istream& operator>>(float& val);
	xml_istream& operator>>(double& val);
	/*xml_istream& operator>>(void*& val); */
	/*xml_istream& operator>>(xml_istream& (*pf)(xml_istream&)); */
	xml_istream& operator>>(QName const&);

	friend xml_istream& operator>>(xml_istream& os, char& ch);
	friend xml_istream& operator>>(xml_istream& os, signed char& ch);
	friend xml_istream& operator>>(xml_istream& os, unsigned char& ch);
	friend xml_istream& operator>>(xml_istream& os, const char* str);
	friend xml_istream& operator>>(xml_istream& os, const signed char* str);
	friend xml_istream& operator>>(xml_istream& os, const unsigned char* str);
	

	//	Get number of characters extracted by last unformatted input operation
	streamsize gcount() const;
	
	//	Extract unformatted data from stream
	int get();
	istream& get(char& c);
	istream& get(char* s, streamsize n);
	istream& get(char* s, streamsize n, char delim);
	istream& get(streambuf& sb);
	istream& get(streambuf& sb, char delim);
	
	//	Get a line from stream
	istream& getline(char* s, streamsize n);
	istream& getline(char* s, streamsize n, char delim);
	
	//	Extract and discard characters
	istream&  ignore( streamsize n = 1, int delim = EOF); 
	
	//	Peek next character
	int peek();
	
	//	Put the last character back to stream
	istream&  putback(char c); 
	
	//	Read a block of data
	istream&  read(char* s, streamsize n); 
	
	//	Read a block of data
	streamsize  readsome(char* s, streamsize n);
	
	//	Set position of the get pointer
	istream&  seekg(streampos pos);
	istream&  seekg(streamoff off, ios_base::seekdir dir);
	
	//	Syncronize stream's buffer with source of characters
	int sync();
	
	//	Get position of the get pointer
	streampos tellg();
	
	//	Make last character got from stream available again
	istream& unget( );


private:
	bool underflow(uint32_t) const;


};


}	/* namespace xqp */
#endif	/* XQP_XML_ISTREAM_H */
