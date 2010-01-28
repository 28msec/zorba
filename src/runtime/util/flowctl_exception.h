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
#ifndef FLOWCTL_EXCEPTION
#include "common/common.h"
#include "zorbaerrors/errors.h"

namespace zorba {

  class FlowCtlException : public error::ZorbaInternalException {
  public:
    enum action {
      BREAK, CONTINUE, EXIT, INTERRUPT
    };
  public:
    enum action act;

    FlowCtlException (enum action act_)
      : act (act_) 
    {}
  };

  class ExitException : public FlowCtlException {
  public:
    virtual ~ExitException();
    store::Iterator_t val;
    ExitException (store::Iterator_t val_);
  };
}

#define FLOWCTL_EXCEPTION 
#endif // FLOWCTL_EXCEPTION
