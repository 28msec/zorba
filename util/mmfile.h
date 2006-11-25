/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: mmfile.h,v 1.2 2006/10/22 01:32:22 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR Foundation.  All Rights Reserved.
 *
 */

#ifndef XQP_MMFILE_H
#define XQP_MMFILE_H

#include <string>
#include "xqpexception.h"

namespace xqp {

/*_____________________________________________________________
|
|  Memory-mapping utilities
|______________________________________________________________*/

class mmfile
{
public:  // state
  std::string path;			// backing file path name
  int fd;								// backing file id
  off_t eofoff;					// offset to eof
  char* data;						// raw bytes
	uint32_t depth;				// doublings = size base 4096

public:	//ctor,dtor
	mmfile(std::string const& path, uint32_t depth);
	~mmfile();

public:
  void initialize(uint32_t _depth);
  void fill(char initval);
  void double_array(bool init = false);
  void unmap();
  void renam(const std::string& new_path);
	void reopen();

	std::string get_path() const { return path; }
	off_t get_eofoff() const { return eofoff; }

};


}  /* namespace xqp */
#endif  /* XQP_MMFILE_H */
