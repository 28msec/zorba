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
#include <store/api/iterator.h>

namespace zorba {

/**
 * A class to hold an input stream for the x:parse() function
 * Author: Nicolae Brinza
 */
class FragmentIStream : public std::istream
{
public:
  static const unsigned int DEFAULT_BUFFER_SIZE = 4096;
  static const unsigned int PARSED_NODES_BATCH_SIZE = 1024;
  
  // names of these states are orientative
  enum FRAGMENT_PARSER_STATE {
    FRAGMENT_FIRST_START_DOC = 0,
    FRAGMENT_PROLOG,
    FRAGMENT_CONTENT                   // this state is set once an element is encountered
  };

public:
  std::istringstream* theIss;
  std::istream* theStream;
  StreamReleaser theStreamReleaser;
  std::vector<char> theBuffer;
  unsigned long bytes_in_buffer;
  unsigned long current_offset;
  int current_element_depth;
  int root_elements_to_skip;
  xmlParserCtxtPtr ctxt;
  FRAGMENT_PARSER_STATE state;
  bool forced_parser_stop;
  bool reached_eof;
  unsigned int parsed_nodes_count;
  store::Iterator_t children;
  bool only_one_doc_node;           // If set to true, all parsed fragments will be added to one
                                    // single document node, instead of having one for each fragment.
  
public:
  FragmentIStream()
    :
    std::istream(NULL),
    theIss(NULL),
    theStream(NULL),
    theStreamReleaser(nullptr),
    bytes_in_buffer(0),
    current_offset(0),
    current_element_depth(0),
    root_elements_to_skip(0),
    ctxt(NULL),
    state(FRAGMENT_FIRST_START_DOC),
    forced_parser_stop(false),
    reached_eof(false),
    parsed_nodes_count(0),
    children(NULL),
    only_one_doc_node(false)
  {
  };

  bool stream_is_consumed()
  {
    return reached_eof && current_offset >= bytes_in_buffer;
  }
  
  StreamReleaser getStreamReleaser()
  {
    return theStreamReleaser;
  }
  
  void setStreamReleaser(StreamReleaser aReleaser)
  {
    theStreamReleaser = aReleaser;
  }

  void reset()
  {
    theBuffer.clear();

    if (theIss)
    {
      delete theIss;
    }
    
    if (theStreamReleaser)
    {
      theStreamReleaser(theStream);
    }

    if (ctxt)
    {
      xmlCtxtReset(ctxt);
      xmlFreeParserCtxt(ctxt);
    }

    theIss = NULL;
    theStream = NULL;
    bytes_in_buffer = 0;
    current_offset = 0;
    current_element_depth = 0;
    root_elements_to_skip = 0;
    ctxt = NULL;
    state = FRAGMENT_FIRST_START_DOC;
    forced_parser_stop = false;
    reached_eof = false;
    parsed_nodes_count = 0;
    children = NULL;
    only_one_doc_node = false;
  }
  
  virtual ~FragmentIStream()
  {
    reset();
  }
};

}
#endif
/*
 * Local variables:
 * mode: c++
 * End:
 */
