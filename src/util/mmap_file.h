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
#pragma once
#ifndef ZORBA_MMAP_FILE_H
#define ZORBA_MMAP_FILE_H

#include <zorba/config.h>
#ifdef ZORBA_WITH_FILE_ACCESS

#include <cstddef>                      /* for ptrdiff_t, size_t */
#include <fstream>                      /* for openmode */
#include <iterator>
#include <string>
#include <sys/types.h>                  /* needed by FreeBSD systems */

#ifdef WIN32
# include <windows.h>                   /* for HANDLE */
#endif /* WIN32 */

#include "fs_util.h"

//
// Some C headers on some implementations define open/close as macros to remap
// them to functions that handle files larger than 2 GB.  This works fine in C,
// but can break C++ where classes have open/close member functions.  Undefine
// them and live with the consequence of not being able to deal with large
// files on such implementations.
//
#ifdef  open
# undef open
#endif
#ifdef  close
# undef close
#endif

namespace zorba {

/**
 * An %mmap_file is an object that maps a file into memory (via the Unix system
 * call mmap(2)) allowing it to be accessed via iterators.  Processing a file,
 * especially files accessed randomly, is MUCH faster than standard I/O.
 */
class mmap_file {
public:

  ////////// typedefs /////////////////////////////////////////////////////////

  typedef char value_type;
  typedef value_type* pointer;
  typedef value_type const* const_pointer;
  typedef value_type& reference;
  typedef value_type const& const_reference;
  typedef fs::size_type size_type;
  typedef ptrdiff_t difference_type;

  typedef pointer iterator;
  typedef const_pointer const_iterator;
  typedef std::reverse_iterator<iterator> reverse_iterator;
  typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

  ////////// constructors & destructor ////////////////////////////////////////

  /**
   * Constructs an %mmap_file not mapped to any file.
   */
  mmap_file() {
    init();
  }

  /**
   * Constructs an %mmap_file mapped to the given file.
   *
   * @param path The full path of the file to map.
   * @param mode The mode to use for opening/mapping the file.
   */
  explicit mmap_file( char const *path,
                      std::ios::openmode mode = std::ios::in ) {
    init();
    open( path, mode );
  }

  /**
   * Destructs this %mmap_file that unmaps the file.
   */
  ~mmap_file() {
    close();
  }

  ////////// iterators ////////////////////////////////////////////////////////

  /**
   * Returns a read/write iterator positioned at the first byte of the file.
   * 
   * @return Returns said iterator.
   */
  iterator begin() {
    return static_cast<iterator>( addr_ );
  }

  /**
   * Returns a read-only iterator positioned at the first byte of the file.
   * 
   * @return Returns said iterator.
   */
  const_iterator begin() const {
    return static_cast<const_iterator>( addr_ );
  }

  /**
   * Returns a read/write iterator positioned at one past the last byte of the
   * file.
   * 
   * @return Returns said iterator.
   */
  iterator end() {
    return begin() + size_;
  }

  /**
   * Returns a read-only iterator positioned at one past the last byte of the
   * file.
   * 
   * @return Returns said iterator.
   */
  const_iterator end() const {
    return begin() + size_;
  }

  /**
   * Returns a read/write reverse iterator positioned at the last byte of the
   * file.
   * 
   * @return Returns said iterator.
   */
  reverse_iterator rbegin() {
    return reverse_iterator( end() );
  }

  /**
   * Returns a read-only reverse iterator positioned at the last byte of the
   * file.
   * 
   * @return Returns said iterator.
   */
  const_reverse_iterator rbegin() const {
    return const_reverse_iterator( end() );
  }

  /**
   * Returns a read/write reverse iterator positioned at the last byte of the
   * file.
   * 
   * @return Returns said iterator.
   */
  reverse_iterator rend() {
    return reverse_iterator( begin() );
  }

  /**
   * Returns a read-only reverse iterator positioned at the last byte of the
   * file.
   * 
   * @return Returns said iterator.
   */
  const_reverse_iterator rend() const {
    return const_reverse_iterator( begin() );
  }

  ////////// other functions //////////////////////////////////////////////////

  /**
   * Gets the last character.
   *
   * @return Returns a reference to said character.
   */
  reference back() {
    return *( end() - 1 );
  }

  /**
   * Gets the last character.
   *
   * @return Returns a reference to said character.
   */
  const_reference back() const {
    return *( end() - 1 );
  }

  /**
   * Gets the first character.
   *
   * @return Returns a reference to said character.
   */
  reference front() {
    return *begin();
  }

  /**
   * Gets the first character.
   *
   * @return Returns a reference to said character.
   */
  const_reference front() const {
    return *begin();
  }

  /**
   * Maps the given file.  If this %mmap_file is already mapped to a file, that
   * file is unmapped first.
   *
   * @param path The full path of the file to map.
   * @param mode The mode to use for opening/mapping the file.
   */
  void open( char const *path, std::ios::openmode = std::ios::in );

  /**
   * Unmaps the file.  If this %mmap_file is not mapped to a file, does
   * nothing.
   */
  void close();

  /**
   * Checks whether the mapped file is empty.
   *
   * @return Returns \c true either if the mapped file is empty or this
   * %mmap_file is not mapped to a file.
   */
  bool empty() const {
    return !size_;
  }

  /**
   * Gets the size of the mapped file.
   *
   * @return Returns said size or 0 if this %mmap_file is not mapped to a file.
   */
  size_type size() const {
    return size_;
  }

  /**
   * Checks whether this %mmap_file is mapped to a file.
   *
   * @return Returns \c true only if it is.
   */
  operator bool() const {
    return !!addr_;
  }

  /**
   * Gets the ith character.
   *
   * @param i The index of the character.
   * @return Returns a reference to said character.
   */
  reference operator[]( size_type i ) {
    return *( begin() + i );
  }

  /**
   * Gets the ith character.
   *
   * @param i The index of the character.
   * @return Returns a reference to said character.
   */
  const_reference operator[]( size_type i ) const {
    return *( begin() + i );
  }

 ////////////////////////////////////////////////////////////////////////////// 

private:
  std::string path_;
#ifdef WIN32
  HANDLE      fd_;
  HANDLE      mapping_;
#else
  int         fd_;
#endif /* WIN32 */
  size_type   size_;
  void        *addr_;

  void        init();

  // forbid these
  mmap_file( mmap_file const& );
  mmap_file& operator=( mmap_file const& );
};

} // namespace zorba
#endif /* ZORBA_WITH_FILE_ACCESS */
#endif /* ZORBA_MMAP_FILE_H */
/* vim:set et sw=2 ts=2: */
