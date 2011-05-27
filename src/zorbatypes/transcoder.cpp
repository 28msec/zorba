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

#include "zorbatypes/transcoder.h"
#include "diagnostics/assert.h"

#ifndef ZORBA_NO_UNICODE
#include "zorbatypes/libicu.h"
#endif
#include "util/utf8_util.h"

namespace zorba {


transcoder::transcoder(std::ostream& output_stream, bool in_utf16)
  :
  os(output_stream),
  utf16(in_utf16)
{
  if (utf16)
  {
#ifndef ZORBA_NO_UNICODE
    UErrorCode status = U_ZERO_ERROR;
    conv = ucnv_open("utf-8", &status);
    ZORBA_ASSERT(U_SUCCESS(status));
    chars_in_buffer = 0;
    chars_expected = 1;
#else
    ZORBA_ASSERT(false);
#endif
  }
}


transcoder::~transcoder()
{
#ifndef ZORBA_NO_UNICODE
  if (utf16)
    ucnv_close(conv);
#endif
}


transcoder& transcoder::write_utf16(const char* str, std::streamsize len)
{
#ifndef ZORBA_NO_UNICODE
  UChar temp;
  UErrorCode status = U_ZERO_ERROR;
  int target_size = ucnv_toUChars(conv, &temp, 1, str, len, &status);

  status = U_ZERO_ERROR;
  UChar* target = new UChar[target_size+1];
  char* target2 = (char*)target;
  target_size = ucnv_toUChars(conv, target, target_size, str, len, &status);

  if (U_FAILURE(status))
  {
    ZORBA_ASSERT(0);
  }

  for (unsigned int i = 0; i < target_size*sizeof(UChar); i++)
    os << target2[i];

  delete[] target;
  return *this;
#endif
}


transcoder& transcoder::write_utf16_char(const char ch)
{
#ifndef ZORBA_NO_UNICODE
  int done = 0;
  buffer[chars_in_buffer++] = ch;

  if (chars_expected == 1)
  {
    utf8::size_type const len = utf8::char_length( ch );
    if (len > 1)
      chars_expected = len;
    else
      done = 1;

  }
  else if (chars_expected == chars_in_buffer)
    done = 1;

  if (done)
  {
    UErrorCode status = U_ZERO_ERROR;
    UChar target[20];
    char* target2 = (char*)target;

    int target_size = ucnv_toUChars(conv, target, 20, buffer, chars_in_buffer, &status);

    if (U_FAILURE(status))
    {
      ZORBA_ASSERT(0);
    }

    for (unsigned int i=0; i<target_size*sizeof(UChar); i++)
      os << target2[i];

    chars_in_buffer = 0;
    chars_expected = 1;
  }

  return *this;
#endif
}


} /* namespace zorba */
