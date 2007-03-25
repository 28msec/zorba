/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: file.cpp,v 1.3 2006/10/13 06:53:30 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 *	Author: Paul Pedersen
 *
 */

#include "file.h"

#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>

#include <sys/param.h>
#include <sys/mount.h>

#include <fcntl.h>
#include <unistd.h>
#include <sys/vfs.h>
#include <iostream>
#include <sstream>
#include <string>

#include "xqp_exception.h"


using namespace std;
namespace xqp {

static const uint64_t FS_TYPES[] = {
    0x0000EF53, 0x0000adf5, 0x0000adff, 0x73757245, 0x00001373, 0x00414A53,
    0x0000EF53, 0x0000EF53, 0xf995e849, 0x00009660, 0x000072b6, 0x0000137F,
    0x0000138F, 0x00002468, 0x00002478, 0x00004d44, 0x00006969, 0x00009fa1,
    0x00009fa0, 0x0000002f, 0x52654973, 0x012FF7B3, 0x012FF7B4, 0x012FF7B5,
    0x012FF7B6, 0x00009fa2
  };

static const char *FS_NAMES[] = {
    "ext2", "adfs", "affs", "coda", "devfs", "efs", "ext2", "ext3", "hpfs", 
		"isofs", "jffs2", "minix", "minix_30charnames", "minix2", "minix2_30charnames",
		"msdos", "nfs", "openprom", "proc", "qnx4", "reiserfs", "xenix", "sysv4",
		"sysv2", "coh", "usbdevice"
  };


file::file(const std::string& _path)
throw (xqp_exception)
:
	path(_path),
  type(type_non_existent)
{
	struct stat st;
  if (::stat(path.c_str(), &st)) {
    if (errno!=ENOENT) error(__FUNCTION__,"stat failed on "+path);
  } 
	else {
  	size	= st.st_size;
  	atime	= st.st_atime;
  	mtime	= st.st_mtime;
		type 	=	(st.st_mode & S_IFDIR)  ? type_directory :
  					(st.st_mode & S_IFREG ) ? type_file :
  					(st.st_mode & S_IFLNK)  ? type_link : type_invalid;
	}
}


file::file(
	std::string const& base,
	std::string const& name) throw (xqp_exception)
:
	path(base+"/"+name),
  type(type_non_existent)
{
	struct stat st;
  if (::stat(path.c_str(), &st)) {
    if (errno!=ENOENT) error(__FUNCTION__,"stat failed on "+path);
  } 
	else {
  	size	= st.st_size;
  	atime	= st.st_atime;
  	mtime	= st.st_mtime;
		type 	=	(st.st_mode & S_IFDIR)  ? type_directory :
  					(st.st_mode & S_IFREG ) ? type_file :
  					(st.st_mode & S_IFLNK)  ? type_link : type_invalid;
	}
}


file::~file()
{
}


enum file::filetype file::get_filetype( )
throw (xqp_exception)
{
  if (type!=type_non_existent) return type;

	// call native file system status
	struct stat st;
  if (::stat(path.c_str(), &st)) {
    if (errno==ENOENT) {
			errno = 0;
    	return (type = type_non_existent);
		}
    error(__FUNCTION__,"stat failed on "+path);
  } 
  size	= st.st_size;
  atime	= st.st_atime;
  mtime	= st.st_mtime;
	return (type 	=	(st.st_mode & S_IFDIR)  ? type_directory :
  								(st.st_mode & S_IFREG ) ? type_file :
  								(st.st_mode & S_IFLNK)  ? type_link : type_invalid );
}


volatile void file::error(
	string const& location,
	string const& msg)
throw (xqp_exception)
{
  std::string err = strerror(errno);
  errno = 0;
  throw xqp_exception(location, msg + " ["+err+']');
}


void file::create()
throw (xqp_exception)
{
  int fd = ::creat(path.c_str(),0666);
  if (fd < 0) error(__FUNCTION__, "failed to create file "+path);
  ::close(fd);
  set_filetype(type_file); 
}


void file::mkdir()
throw (xqp_exception)
{
	if (::mkdir(path.c_str(),0777)) {
		ostringstream oss;
		oss<<"mkdir failed ["<<strerror(errno) << "]"<<"] for: "<<path;
		cout << oss.str() << endl;	//XXX DEBUG
    error(__FUNCTION__,oss.str());
	}
  set_filetype(file::type_directory);
}


void file::remove(bool ignore)
throw (xqp_exception)
{
  if (::remove(path.c_str()) && !ignore) {
    error(__FUNCTION__, "failed to remove "+path);
	}
  set_filetype(type_non_existent);
}


void file::rmdir(bool ignore)
throw (xqp_exception)
{
	if (::rmdir(path.c_str()) && !ignore) {
    error(__FUNCTION__, "rmdir failed on "+path);
	}
  set_filetype(file::type_non_existent);
}


void file::chdir()
throw (xqp_exception)
{
  if (!is_directory()) return;
  if (::chdir(path.c_str())) {
    error(__FUNCTION__, "chdir failed on "+path);
	}
}


void file::rename(
	std::string const& newpath)
throw (xqp_exception)
{
  if (::rename(path.c_str(), newpath.c_str())) {
    ostringstream oss;
    oss << path << " to " << newpath;
    error(__FUNCTION__, "failed to rename: "+oss.str());
  }
  set_path(newpath);
}


void file::touch()
throw (xqp_exception)
{
  int fd = 0;
	fd = open(path.c_str(),O_CREAT|O_WRONLY,0666);
  if (fd<0) error(__FUNCTION__, "failed to open "+path);
  try {
    if (fsync(fd)) error(__FUNCTION__, "failed to fsync "+path);
  } catch (xqp_exception &e) {
    close(fd);
    throw;
  }
  if (close(fd)) error(__FUNCTION__, "failed to close "+path);
}


void file::do_statfs(
	std::string const& path)
throw (xqp_exception)
{
  struct statfs buf;
  if (statfs(path.c_str(),&buf))
		error(__FUNCTION__,"statfs failed on "+path);

  blksize  = buf.f_bsize;
  blktotal = buf.f_blocks;
  blkfree  = buf.f_bfree;
  blkavail = buf.f_bavail;
  filtotal = buf.f_files;
  filfree  = buf.f_ffree;
  filavail = buf.f_ffree;
  fsid     = buf.f_fsid;
  fstype   = buf.f_type;

  for (uint32_t i = 0; i < sizeof(FS_TYPES); ++i) {
    if (FS_TYPES[i]==fstype) {
      fstypename = FS_NAMES[i];
      break;
    }
  }

  access = rw;
  setuid = true;
  truncnames = false;
}


// read a file into a buffer
int file::readfile(
	char* docbuf,
	uint32_t maxlen)
throw (xqp_exception)
{
  int fd = open(path.c_str(), O_RDONLY);
  if (fd < 0) {
		error(__FUNCTION__, "open("+path+") failed ["+strerror(errno)+"]");
	}
  ssize_t n = read(fd, docbuf, size);
  if (n<0) {
		error(__FUNCTION__, "read("+path+") failed ["+strerror(errno)+"]");
  }
	if (close(fd)==-1) {
		error(__FUNCTION__, "close("+path+") failed ["+strerror(errno)+"]");
  }
	return n;
}



// dir_iterator

#define END true

file::dir_iterator file::begin()
{
  return file::dir_iterator(path);
}

file::dir_iterator file::end()
{
  return file::dir_iterator(path, END);
}

file::dir_iterator::dir_iterator(
	string const& path,
	bool end_iterator)
throw (xqp_exception)
:
	dirpath(path),
	dir(opendir(path.c_str())),
  dirent(0)
{
  if (dir==0) {
    error(__FUNCTION__, "opendir failed on "+dirpath);
	}
  if (!end_iterator) operator++();
}


file::dir_iterator::~dir_iterator()
{
  if (dir!=0) closedir(dir);
}


void file::dir_iterator::operator++()
{
  if (dir!=0) {
    while (true) {
      dirent = readdir(dir);
      if (dirent==0) { 
        closedir(dir); 
        dir = 0; 
        break; 
      }
      if (strcmp(dirent->d_name,".") &&
          strcmp(dirent->d_name,"..") &&
          strcmp(dirent->d_name,"lost+found")) {
        break;
			}
    }
  }
}


bool operator!=(
	file::dir_iterator const& x,
	file::dir_iterator const& y)
{
	if (x.dirpath==y.dirpath) return false;
	if (x.dirent==y.dirent) return false;
	return true;
}


} /* namespace xqp */

