/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: mmfile.h,v 1.2 2006/10/22 01:32:22 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 *	Author: Paul Pedersen
 *
 */

#ifndef XQP_MMFILE_H
#define XQP_MMFILE_H

#ifdef WIN32
	#include "win32/compatib_defs.h"
	#include <windows.h>
#endif

#ifndef _WIN32_WCE
	#include <sys/types.h>
#else
	#include <windows.h>
	#include <types.h>
#endif

#include <string>

#include "../errors/Error.h"

namespace xqp {
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
#ifndef WIN32
  int fd;								// backing file id
#else
	HANDLE	fd;
	HANDLE	file_mapping;
#endif

public:			// ctor,dtor
	mmfile(std::string const& path, uint32_t initial_size=4096);
	~mmfile();

public:			// mm array interface
  void fill(char initval);
  void expand(bool init = false) throw (xqp_exception);
  void unmap() throw (xqp_exception);
  void rename_backing_file(std::string const& new_path) throw (xqp_exception);
	void destroy() throw (xqp_exception);

public:			// manipulators
	std::string get_path() const { return path; }
	off_t get_eofoff() const { return eofoff; }
	char * get_data() const { return data; }
	uint32_t get_size() const { return eofoff; }

};

}  /* namespace xqp */
#endif  /* XQP_MMFILE_H */
