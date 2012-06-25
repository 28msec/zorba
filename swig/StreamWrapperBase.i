/*
 * Copyright 2006-2012 The FLWOR Foundation.
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

%feature("director") StreamWrapperBase;

%{  // start Implementation

#include "StreamWrapperBase.h"
#include <cassert>
#include <iostream>

int StreamWrapperBase::getEOF()
{
  std::cout << "Log: getEOF\n";
  return traits_type::eof();
}

int StreamWrapperBase::underflow()
{
    std::cout << "Log: underflow\n";
    if (current_ == end_)
        return traits_type::eof();

    return traits_type::to_int_type(*current_);
}

int StreamWrapperBase::uflow()
{
    std::cout << "Log: uflow\n";
    if (current_ == end_)
        return traits_type::eof();

    return traits_type::to_int_type(*current_++);
}

int StreamWrapperBase::pbackfail(int ch)
{
    std::cout << "Log: pbackfail\n";
    if (current_ == begin_ || (ch != traits_type::eof() && ch != current_[-1]))
        return traits_type::eof();

    return traits_type::to_int_type(*--current_);
}

std::streamsize StreamWrapperBase::showmanyc()
{
    std::cout << "Log: showmanyc\n";
    assert(std::less_equal<const char *>()(current_, end_));
    return end_ - current_;
}

%}  // end   Implementation

%include "StreamWrapperBase.h"