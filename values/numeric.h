/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: numeric.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#ifndef XQP_NUMERIC_H
#define XQP_NUMERIC_H

#include "values.h"
#include "decNum.h"

namespace xqp {


/*______________________________________________________________________
|
|	numeric values base class
|_______________________________________________________________________*/

class numeric_val : public atomic_value
{
public:
  numeric() {}
  numeric(const simple_type& ): atomic_value(t) {}
  numeric(const numeric& value): atomic_value(value) {}
  ~numeric() {}

public:
  simple_type integer_simple_type() const;
  simple_type decimal_simple_type() const;
  simple_type double_simple_type() const;
  simple_type float_simple_type() const;

public:
  virtual void put(std::ostream&, context const&) const = 0;
  virtual void describe(std::ostream&,  context const&) const = 0;

};



/*______________________________________________________________________
|  
|	decimal values, base of the integral numeric values
|_______________________________________________________________________*/

class decimal_val : public numeric_val
{
public:
  decNum d;

public:
  decimal_val(const simple_type&, const char* buf, uint32_t length);
  decimal_val(const simple_type& t, const decimal&);
  decimal_val(const decimal_val&);
  ~decimal_val();

public:
  void put(std::ostream&, context const&) const;
  void describe(std::ostream&,  context const&) const;

public:
  bool operator==(decimal_val const& d) const { return d==z.d; }
  bool operator!=(decimal_val const& d) const { return d!=z.d; }
  bool operator<=(decimal_val const& d) const { return d<=z.d; }
  bool operator>=(decimal_val const& d) const { return d>=z.d; }
  bool operator<(decimal_val const& d) const { return d<z.d; }
  bool operator>(decimal_val const& d) const { return d>z.d; }

};




/*______________________________________________________________________
|  
|	integer values
|_______________________________________________________________________*/

class integer_val : public decimal_val
{
public:
  integer_val(simple_type const&, char const* buf, uint32_t length);
  integer_val(simple_type const& t, decimal const&);
  integer_val(integer_val const&);
  ~integer_val();

public:
  void put(std::ostream&, context const&) const;
  void describe(std::ostream&, context const&) const;

public:
  bool is_int() const;
  bool is_unsignedInt() const;
  bool is_long() const;
  bool is_unsignedLong() const;

};




/*______________________________________________________________________
|  
|	float values
|_______________________________________________________________________*/

class float_val : public numeric_val
{
public:
  float f;
	enum fl_non_standard {
		NaN,
		NegativeInf,
		PositiveInf,
		NegativeZero
	};

public:
  float_val(simple_type const&, char const* buf, uint32_t length);
  float_val(simple_type const&, float);
  float_val(float_val const&);
  float_val(decimal_val const&);
  ~float_val();

public:
  void put(std::ostream&, context const&) const;
  void describe(std::ostream&, context const&) const;

public:
	enum fl_non_standard non_standard() const {
		if (f==ieee_float_nan) return NaN;
		if (f==ieee_float_neginf) return negativeInf;
		if (f==ieee_float_posinf) return positiveInf;
		if (f==ieee_float_negzero) return negativeZero;
	};

  bool operator==(float_val const& z) const { return f==z.val; }
  bool operator!=(float_val const& z) const { return f!=z.val; }
  bool operator<=(float_val const& z) const { return f<=z.val; }
  bool operator>=(float_val const& z) const { return f>=z.val; }
  bool operator<(float_val const& z) const { return f<z.val; }
  bool operator>(float_val const& z) const { return f>z.val; }

  bool operator==(float z) const { return f==z; }
  bool operator!=(float z) const { return f!=z; }
  bool operator<=(float z) const { return f<=z; }
  bool operator>=(float z) const { return f>=z; }
  bool operator<(float z) const { return f<z; }
  bool operator>(float z) const { return f>z; }

};



/*______________________________________________________________________
|  
|	double values
|_______________________________________________________________________*/

class double_val : public numeric_val
{
public:
  double d;
	enum dl_non_standard {
		NaN,
		NegativeInf,
		PositiveInf,
		NegativeZero
	};

public:
  double_val(simple_type const&, char const* buf, uint32_t length);
  double_val(simple_type const&, double);
  double_val(double_val const&);
  double_val(decimal_val const&);
  double_val(float_val const&);
  ~double_val();

public:
  void put(std::ostream&, context const&) const;
  void describe(std::ostream&, context const&) const;

public:
	enum dl_non_standard non_standard() const {
		if (f==ieee_double_nan) return NaN;
		if (f==ieee_double_neginf) return NegativeInf;
		if (f==ieee_double_posinf) return PosisitiveInf;
		if (f==ieee_double_negzero) return NegativeZero;
	};

  bool operator==(double_val const& z) const { return d==z.d; }
  bool operator!=(double_val const& z) const { return d!=z.d; }
  bool operator<=(double_val const& z) const { return d<=z.d; }
  bool operator>=(double_val const& z) const { return d>=z.d; }
  bool operator<(double_val const& z) const { return d<z.d; }
  bool operator>(double_val const& z) const { return d>z.d; }

  bool operator==(double z) const { return f==z; }
  bool operator!=(double z) const { return f!=z; }
  bool operator<=(double z) const { return f<=z; }
  bool operator>=(double z) const { return f>=z; }
  bool operator<(double z) const { return f<z; }
  bool operator>(double z) const { return f>z; }

};


} /* namespace xqp */
#endif /* XQP_NUMERIC_H */


