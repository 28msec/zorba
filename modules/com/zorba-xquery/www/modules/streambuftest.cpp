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
#include <string.h>
#include "csv.xq.src/stringiterator_streambuf.h"
#include <istream>
#include <stdio.h>

class TestStreambuf : public zorba::StringIteratorStreamBuf
{
  std::string strings[3];
  int current_string;
  int max_repetitions;
public:
  TestStreambuf(int _max_repetitions = 1) : max_repetitions(_max_repetitions)
  {
    strings[0] = "ab";
    strings[1] = "cde";
    strings[2] = "f";

    current_string = 0;
  }
  virtual ~TestStreambuf() {}

  virtual bool next(std::string &next_string)
  {
    if(current_string >= 3)
    {
      max_repetitions--;
      if(!max_repetitions)
        return false;
      else
        current_string = 0;
    }
    next_string = strings[current_string++];
    return true;
  }
  virtual bool reset()
  {
    current_string = 0;
    return true;
  }

};

bool test1()
{
  TestStreambuf sbuf;
  std::istream *is = new std::istream(&sbuf);

  char result[100];
  memset(result, 0, sizeof(result));
  is->read(result, sizeof(result));
  if(strcmp(result, "abcdef"))
    return false;
  return true;
}

bool test2()
{
  TestStreambuf sbuf;
  std::istream *is = new std::istream(&sbuf);

  std::string result;
  while(!is->eof())
  {
    char c;
    (*is)>>c;
    if(is->eof())
      break;
    result += c;
  }
  if(result.compare("abcdef"))
    return false;
  return true;
}

bool test3()
{
  TestStreambuf sbuf;
  std::istream *is = new std::istream(&sbuf);

  std::string result;
  char c;
  (*is)>>c;//a
  result += c;
  is->unget();
  (*is)>>c;//a
  result += c;
  if(result.compare("aa"))
    return false;
  return true;
}

bool test4()
{
  TestStreambuf sbuf;
  std::istream *is = new std::istream(&sbuf);

  std::string result;
  char c;
  (*is)>>c;//a
  result += c;
  (*is)>>c;//b
  result += c;
  (*is)>>c;//c
  result += c;
  is->unget();
  is->unget();
  (*is)>>c;//b
  result += c;
  (*is)>>c;//c
  result += c;
  is->unget();
  is->putback('t');
  (*is)>>c;//t
  result += c;
  if(result.compare("abcbct"))
    return false;
  return true;
}

bool test5()
{
  TestStreambuf sbuf;
  std::istream *is = new std::istream(&sbuf);

  std::string result;
  char c;
  (*is)>>c;//a
  result += c;
  (*is)>>c;//b
  result += c;
  (*is)>>c;//c
  result += c;
  is->seekg(1);
  c = 0;
  (*is)>>c;//b
  result += c;
  (*is)>>c;//c
  result += c;
  if(result.compare("abcbc"))
    return false;
  return true;
}

bool test6()
{
  TestStreambuf sbuf;
  std::istream *is = new std::istream(&sbuf);

  std::string result;
  char c;
  is->seekg(-1, std::ios::end);
  c = 0;
  (*is)>>c;//f
  result += c;
  if(result.compare("f"))
    return false;
  return true;
}

bool test7()
{
  TestStreambuf sbuf;
  std::istream *is = new std::istream(&sbuf);

  std::string result;
  char c;
  is->seekg(1, std::ios::cur);
  c = 0;
  (*is)>>c;//b
  result += c;
  if(result.compare("b"))
    return false;
  is->seekg(-2, std::ios::cur);
  c = 0;
  (*is)>>c;//a
  result += c;
  if(result.compare("ba"))
    return false;
  is->seekg(5, std::ios::beg);
  c = 0;
  (*is)>>c;//f
  result += c;
  if(result.compare("baf"))
    return false;
  is->seekg(4);
  c = 0;
  (*is)>>c;//e
  result += c;
  if(result.compare("bafe"))
    return false;
  return true;
}

bool test8()
{
  TestStreambuf sbuf(10 * 1000 * 1000);
  std::istream *is = new std::istream(&sbuf);

  char result[100];
  memset(result, 0, sizeof(result));
  do{
    is->read(result, 6);
    if(is->eof())
      break;
    if(strcmp(result, "abcdef"))
      return false;
  }while(!is->eof());
  return true;
}


int streambuftest (int argc, char* argv[])
{
  if(!test1())
  {
    printf("streamable string streambuf test1 failed!\n");
    return 1;
  }
  if(!test2())
  {
    printf("streamable string streambuf test2 failed!\n");
    return 1;
  }
  if(!test3())
  {
    printf("streamable string streambuf test3 failed!\n");
    return 1;
  }
  if(!test4())
  {
    printf("streamable string streambuf test4 failed!\n");
    return 1;
  }
  if(!test5())
  {
    printf("streamable string streambuf test5 failed!\n");
    return 1;
  }
  if(!test6())
  {
    printf("streamable string streambuf test6 failed!\n");
    return 1;
  }
  if(!test7())
  {
    printf("streamable string streambuf test7 failed!\n");
    return 1;
  }
  if(!test8())
  {
    printf("streamable string streambuf test8 failed!\n");
    return 1;
  }
  return 0;
}
