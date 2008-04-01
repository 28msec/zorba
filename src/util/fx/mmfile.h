/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: mmfile.h,v 1.2 2006/10/22 01:32:22 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 *	Author: Paul Pedersen
 *
 */

#ifndef ZORBA_MMFILE_H
#define ZORBA_MMFILE_H

#include "common/common.h"
#include <string>


namespace zorba {
/*_____________________________________________________________
|
|  A raw array of memory-mapped bytes.
|  The default initial size is 4096 bytes = common block size.
|  (There is no point mapping an array smaller than the block
|  size.)
|
|______________________________________________________________*/

class mmfile
{
protected:	// state
  std::string path;			// backing file path name
  off_t eofoff;					// offset to eof = size of array in bytes
  char* data;						// raw bytes
#if defined(WIN32) && !defined(CYGWIN)
	HANDLE	fd;
	HANDLE	file_mapping;
#else
  int fd;	// backing file id
#endif

public:			// ctor,dtor
	mmfile(std::string const& path, uint32_t initial_size=4096);
	~mmfile();

public:			// mm array interface
  void fill(char initval);
  void expand(bool init = false);
  void unmap();
  void rename_backing_file(std::string const& new_path);
	void destroy();

public:			// manipulators
	std::string get_path() const { return path; }
	off_t get_eofoff() const { return eofoff; }
	char * get_data() const { return data; }
	uint32_t get_size() const { return eofoff; }

};

}  /* namespace zorba */
#endif  /* ZORBA_MMFILE_H */
