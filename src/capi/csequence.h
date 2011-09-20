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
#ifndef ZORBAC_CSEQUENCE_H
#define ZORBAC_CSEQUENCE_H

#include <zorba/zorbac.h>
#include <zorba/item.h>
#include <vector>

using namespace zorba;

namespace zorbac {

class CSequence 
{
 public:
  static XQC_Error
  next(XQC_Sequence* sequence);

  static XQC_Error
  item_type(const XQC_Sequence* sequence, XQC_ItemType* type);

  static XQC_Error
  type_name(const XQC_Sequence* sequence, const char** uri, const char** name);

  static XQC_Error
  string_value(const XQC_Sequence* sequence, const char** string_value);

  static XQC_Error
  integer_value(const XQC_Sequence* sequence, int* int_value);

  static XQC_Error
  double_value(const XQC_Sequence* sequence, double* double_value);

  static XQC_Error
  node_name(const XQC_Sequence* sequence, const char** uri, const char** name);

  static void*
  get_interface(const XQC_Sequence* sequence, const char* name);      

  static CSequence*
  get(const XQC_Sequence* sequence);

  static void
  free(XQC_Sequence* sequence);

public:
  CSequence(Iterator_t iter, XQC_ErrorHandler* handler);

  CSequence(ItemSequence* items, bool free_when_done, XQC_ErrorHandler* handler);

  ~CSequence();

  Iterator_t
  getCPPIterator();

  Item
  getCPPItem();

  XQC_Sequence*
  getXQC();

 private:
  void
  init_xqc();

private:
  XQC_Sequence               theXQCSeq;
  // buffer to store strings that we return
  // they are valid until next() is called
  std::vector<zorba::String> theStrings;
  Item                       theItem;
  Iterator_t                 theIterator;
  bool                       theIsOpen;
  XQC_ErrorHandler*          theErrorHandler;
}; /* class Sequence */


} /* namespace zorbac */

#endif
/* vim:set et sw=2 ts=2: */
