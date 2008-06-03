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
#include "zorbaerrors/Assert.h"

namespace zorba {

int get_utf8_length(char ch)
{
  unsigned char lead = (unsigned char)ch;
  
  if (lead < 0x80)
    return 1;
  else if ((lead >> 5) == 0x6)
    return 2;
  else if ((lead >> 4) == 0xe)
    return 3;
  else if ((lead >> 3) == 0x1e)
    return 4;
  else
    return 0;
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Default transcoder (transparent)                                           //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

transcoder::transcoder(std::ostream& output_stream)
  :
  os(output_stream)
{
}

void
transcoder::verbatim(const char ch)
{
  os << ch;
}


#ifndef ZORBA_NO_UNICODE

/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  UTF-8 to UTF-16 transcoder                                                 //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

utf8_to_utf16_transcoder::utf8_to_utf16_transcoder(std::ostream& output_stream)
  :
  transcoder(output_stream)
{
  UErrorCode status = U_ZERO_ERROR;
  conv = ucnv_open("utf-8", &status);
  ZORBA_ASSERT(U_SUCCESS(status));
  chars_in_buffer = 0;
  chars_expected = 1;
}

utf8_to_utf16_transcoder::~utf8_to_utf16_transcoder()
{
  ucnv_close(conv);
}

utf8_to_utf16_transcoder& utf8_to_utf16_transcoder::operator<<(const char* str)
{
  ulong len = strlen(str);

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

  return *this;
}

utf8_to_utf16_transcoder& utf8_to_utf16_transcoder::operator<<(const char ch)
{
  int done = 0;
  buffer[chars_in_buffer++] = ch;

  if (chars_expected == 1)
  {
    if (get_utf8_length(ch) > 1)
      chars_expected = get_utf8_length(ch);
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
}

#endif//#ifndef ZORBA_NO_UNICODE

} /* namespace zorba */
