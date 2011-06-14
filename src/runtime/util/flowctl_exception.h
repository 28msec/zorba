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

#ifndef RUNTIME_FLOWCTL_EXCEPTION
#define RUNTIME_FLOWCTL_EXCEPTION 

#include "common/common.h"
#include "store/api/iterator.h"

namespace zorba {

// TODO: should derive from std::exception
class FlowCtlException 
{
public:
  enum action 
  {
    BREAK,
    CONTINUE,
    EXIT,
    INTERRUPT
  };

public:
  action act;

public:
  FlowCtlException( action act_ ) : act( act_ )
  {
  }
};


class ExitException : public FlowCtlException 
{
public:
  store::Iterator_t val;

public:
  ExitException(store::Iterator_t val_);

  virtual ~ExitException();
};


} // namespace zorba

#endif /* FLOWCTL_EXCEPTION */

/*
 * Local variables:
 * mode: c++
 * End:
 */ 
/* vim:set et sw=2 ts=2: */
