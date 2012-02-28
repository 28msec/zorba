/*
 * Copyright 2006-2008 The FLWOR Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ZORBA_MMAP_STREAMBUF_H
#define ZORBA_MMAP_STREAMBUF_H

#include <streambuf>

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

/**
 * A %mem_streambuf is-a std::streambuf for a fixed-size chunk of memory.
 */
class mem_streambuf : public std::streambuf {
public:
  typedef std::streambuf::char_type char_type;
  typedef std::streambuf::int_type int_type;
  typedef std::streambuf::off_type off_type;
  typedef std::streambuf::pos_type pos_type;
  typedef std::streambuf::traits_type traits_type;

  /**
   * Default constructor.
   */
  mem_streambuf();

  /**
   * Constructs a %mem_streambuf.
   *
   * @param begin A pointer to the beginning of the memory chunk.
   * @param end A pointer to one past the end of the memory chunk.
   */
  mem_streambuf( char_type *begin, char_type *end );

  /**
   * Constructs a %mem_streambuf.
   *
   * @param begin A pointer to the beginning of the memory chunk.
   * @param size The size of the memory chunk.
   */
  mem_streambuf( char_type *begin, off_type size );

  /**
   * Sets the memory chunk.
   *
   * @param begin A pointer to the beginning of the memory chunk.
   * @param end A pointer to one past the end of the memory chunk.
   */
  void set( char_type *begin, char_type *end );

  /**
   * Sets the memory chunk.
   *
   * @param begin A pointer to the beginning of the memory chunk.
   * @param size The size of the memory chunk.
   */
  void set( char_type *begin, off_type size );

protected:
  int_type overflow( int_type c );
  int_type pbackfail( int_type c );
  pos_type seekoff( off_type, std::ios_base::seekdir, std::ios_base::openmode );
  pos_type seekpos( pos_type, std::ios_base::openmode  );
  std::streamsize showmanyc();
  int_type underflow();
  std::streamsize xsgetn( char_type*, std::streamsize );
  std::streamsize xsputn( char_type const*, std::streamsize );

private:
  char_type *begin_, *end_;

  void our_setg( char_type *ptr ) {
    setg( begin_, ptr, end_ );
  }

  void our_setp( char_type *ptr ) {
    setp( ptr, end_ );
  }

  // forbid
  mem_streambuf( mem_streambuf const& );
  mem_streambuf& operator=( mem_streambuf const& );
};

inline void mem_streambuf::set( char_type *begin, off_type size ) {
  set( begin, begin + size );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
#endif  /* ZORBA_MMAP_STREAMBUF_H */
/* vim:set et sw=2 ts=2: */
