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

#ifndef ZORBA_RUNTIME_PARSING_AND_SERIALIZING_FRAGMENT_ISTREAM_H
#define ZORBA_RUNTIME_PARSING_AND_SERIALIZING_FRAGMENT_ISTREAM_H

#include <iostream>
#include <libxml/parser.h>

namespace zorba {

/**
 * A class to hold an input stream for the parse-xml-fragment function
 * Author: Nicolae Brinza
 */
class FragmentIStream : public std::istream
{
public:
  FragmentIStream()
    :
    std::istream(NULL),
    theIss(NULL),
    theStream(NULL),
    theBuffer(NULL),
    buffer_size(0),
    current_offset(0),
    current_element_depth(0),
    root_elements_to_skip(0),
    ctxt(NULL),
    saved_instate(XML_PARSER_START),
    first_start_doc(true)
  {
  };

  void reset()
  {
    if (theBuffer)
    {
      delete[] theBuffer;
    }

    if (theIss)
    {
      delete theIss;
    }

    if (ctxt)
    {
      xmlCtxtReset(ctxt);
      xmlFreeParserCtxt(ctxt);
    }

    theIss = NULL;
    theStream = NULL;
    theBuffer = NULL;
    buffer_size = 0;
    current_offset = 0;
    current_element_depth = 0;
    root_elements_to_skip = 0;
    ctxt = NULL;
    saved_instate = XML_PARSER_START;
    first_start_doc = true;
  }

  virtual ~FragmentIStream()
  {
    reset();
  }

public:
  std::istringstream* theIss;
  std::istream* theStream;
  char* theBuffer;
  unsigned long buffer_size;
  unsigned long current_offset;
  int current_element_depth;
  int root_elements_to_skip;
  xmlParserCtxtPtr ctxt;
  xmlParserInputState saved_instate;
  bool first_start_doc;
};

}
#endif
/*
 * Local variables:
 * mode: c++
 * End:
 */
