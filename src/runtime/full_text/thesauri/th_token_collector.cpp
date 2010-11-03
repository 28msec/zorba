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

#include "th_token_collector.h"

using namespace std;
using namespace zorba::locale;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

th_token_collector::th_token_collector( int token_no, int sent_no,
                                        iso639_1::type lang,
                                        FTTokenSeqIterator::FTTokens &tokens ) :
  tokens_( tokens ), token_no_( token_no ), sent_no_( sent_no ), lang_( lang )
{
}

void th_token_collector::operator()( char const *utf8_s, int utf8_len, int, int,
                                     int, void* ) {
  FTToken const t( utf8_s, utf8_len, token_no_, sent_no_, lang_ );
  tokens_.push_back( t );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
