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

  template<typename F> class FloatImpl;
  typedef FloatImpl<double> Double;
  typedef FloatImpl<float>  Float;

  template<class C> class IntegerImpl;
  class integer_check;
  class nonPositive_check;
  class nonNegative_check;
  class positive_check;
  typedef IntegerImpl<integer_check> Integer;
  typedef IntegerImpl<nonPositive_check> NonPositiveInteger;
  typedef IntegerImpl<nonNegative_check> NonNegativeInteger;
  typedef IntegerImpl<positive_check> PositiveInteger;

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
