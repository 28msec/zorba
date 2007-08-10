/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: file.h,v 1.4 2006/10/22 01:32:21 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 *	Author: Paul Pedersen
 *
 */

#ifndef XQP_FILE_H
#define XQP_FILE_H

#ifndef _WIN32_WCE
	#include <sys/types.h>
	#include <sys/stat.h>
	#include <fcntl.h>
#else
	#include <windows.h>
	#include <types.h>
#endif
#ifdef WIN32
#include <Windows.h>
	#include "win32/compatib_defs.h"
#else
	#include <sys/vfs.h>
	#include <dirent.h>
#endif

#include <time.h>
#include <string>

#include "../errors/Error.h"
#include "rchandle.h"

namespace xqp {

class file : public rcobject
{
public:
  enum filetype {
    type_invalid,
    type_non_existent,
    type_directory,
    type_link,
    type_file,
    type_volume
  };

public:
  enum rwaccess {
    ro = 1, // Read-Only
    wo = 2, // WriteOnly
    rw = 3  // Read and Write
  };

protected:
  std::string path;
  enum filetype type; 

private:	// file attributes
  int64_t  size;      		// size in bytes
#ifndef WIN32
  time_t   atime;     		// most recent access time
  time_t   mtime;     		// most recent mod time
#else
	FILETIME	atime;
	FILETIME	mtime;
#endif
#ifndef WIN32
  uint32_t owner;     		// file owner uid
  uint32_t group;     		// file group gid
  uint32_t perms;     		// file permissions
#endif

#ifndef WIN32
private:	// volume attributes
  uint64_t filtotal;    	// total number of file inodes in file system
  uint64_t filfree;     	// number of free file inodes in file system
  uint64_t filavail;    	// number of free file inodes available to non super-users
  uint64_t fsid; 		      // file system id
  uint64_t fstype;        // numeric file system type identifier (fs-specific)
  uint64_t blksize;     	// recommended file system block size in bytes
  uint64_t blktotal;    	// total number of blocks in file system
  uint64_t blkfree;     	// number of free blocks in file system
  uint64_t blkavail;    	// number of free blocks available to non super-users
  std::string fstypename;	// string name of file system type (null-terminated)
  enum rwaccess access;   // level of read/write access
  bool setuid;            // allows setuid/setguid
	bool truncnames;        // truncates long filenames
#endif

public:
  file(std::string const& pathname) throw (xqp_exception);
  file(std::string const& rootpath, std::string const& name) throw (xqp_exception);
  ~file();

public:	// common methods
  void set_path(std::string const& _path ) { path = _path; }
  void set_filetype(enum filetype _type ) { type = _type ; }
  std::string const& get_path() const { return path; }
  enum filetype get_filetype() throw (xqp_exception);

  bool is_directory() const { return (type==type_directory); }  
  bool is_file() const { return (type==type_file); }  
  bool is_link() const { return (type==type_link); }  
  bool is_volume() const { return (type==type_volume); }  

  bool is_invalid() const { return (type==type_invalid); }  
  bool exists() const { return (type!=type_non_existent && type!=type_invalid); }  
  static volatile void error(std::string const& location, std::string const& msg) throw (xqp_exception);
  static void sync() { 
#ifndef WIN32
		::sync(); 
#else
	_flushall();
#endif
	}


public:	// file methods
  void create() throw (xqp_exception);
  void remove(bool ignore) throw (xqp_exception);
  void rename(std::string const& newpath) throw (xqp_exception);
	void touch() throw (xqp_exception);

  int64_t get_size() const				{ return size; }
#ifndef WIN32
  time_t  get_acctime() const			{ return atime; }
  time_t  get_modtime() const			{ return mtime; }
	uint32_t get_ownerid() const		{ return owner; }
  uint32_t get_groupid() const		{ return group; }
  uint32_t get_permissions() const	{ return perms; }
#else
  FILETIME  get_acctime() const			{ return atime; }
  FILETIME  get_modtime() const			{ return mtime; }

#endif

	int readfile(
		char* docbuf,
		uint32_t maxlen) throw (xqp_exception);

public:	// directory methods
	class dir_iterator : public rcobject
	{
	public:
  	std::string dirpath;
  	std::string path;
#ifndef WIN32
  	DIR *dir;
  	struct dirent *dirent;
#else
		HANDLE						win32_dir;
		WIN32_FIND_DATA		win32_direntry;
#endif
	public:
  	dir_iterator(const std::string& path, bool end_iterator = false) throw (xqp_exception);
  	~dir_iterator();
	public:	// iterator interface
		void operator++();
#ifndef WIN32
		const char* operator*() { 
			return dirent->d_name; 
		}
#else
		const TCHAR* operator*() { 
			return win32_direntry.cFileName;
		}
#endif
	public:	
#ifndef WIN32
		const char* get_name() const { 
			return dirent?dirent->d_name:0;
#else
		const TCHAR* get_name() const { 
			return (win32_dir != INVALID_HANDLE_VALUE) ? win32_direntry.cFileName : NULL;
		}
#endif
	};

	void mkdir() throw (xqp_exception);
	void rmdir(bool ignore) throw (xqp_exception);
#ifndef _WIN32_WCE
	void chdir() throw (xqp_exception);
#endif

  dir_iterator begin();
  dir_iterator end();

	friend bool operator!=(dir_iterator const& x, dir_iterator const& y);

#ifndef WIN32
public:	// volume methods
  uint64_t get_block_size() const   { return blksize; }
  uint64_t get_total_blocks() const { return blktotal; }
  uint64_t get_avail_blocks() const { return blkavail; }
  uint64_t get_total_inodes() const { return filtotal; }
  uint64_t get_avail_inodes() const { return filavail; } 

  std::string get_volume_type() const { return fstypename; }
  enum rwaccess get_access() const { return access; }
	bool has_set_uid() const { return setuid; }
  bool has_truncated_names() const { return truncnames; }
#endif
  
	bool is_empty() const { return (size == (int64_t)0); }

#ifndef WIN32
  void do_statfs(std::string const& path) throw (xqp_exception);
#endif
};


} /* namespace xqp */
#endif /* XQP_FILE_H */
