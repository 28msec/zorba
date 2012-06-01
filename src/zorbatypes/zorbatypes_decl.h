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
#ifndef ZORBA_ZORBATYPES_DECL_H
#define ZORBA_ZORBATYPES_DECL_H

#include <zorba/config.h>

namespace zorba 
{
  /* numerics */
  class Decimal;

#ifdef ZORBA_WITH_BIG_INTEGER
  class IntegerImpl;
  typedef IntegerImpl Integer;
  typedef IntegerImpl UInteger;
#else
  template<typename T> class IntegerImpl;
  typedef IntegerImpl<long long> Integer;
  typedef IntegerImpl<unsigned long long> UInteger;
#endif /* ZORBA_WITH_BIG_INTEGER */

  template<typename T> class FloatImpl;
  typedef FloatImpl<double> Double;
  typedef FloatImpl<float>  Float;

  /* datetime */
  class DateTime;
  class Duration;
  class TimeZone;

  /* string */
  class XQPCollator;
};

#endif /* ZORBA_ZORBATYPES_DECL_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
