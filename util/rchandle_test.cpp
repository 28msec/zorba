/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: rchandle_unittest.cpp,v 1.1 2006/10/09 07:08:02 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR Foundation.  All Rights Reserved.
 *
 */

#include "rchandle.h"
#include <math.h>
#include <iostream>

using namespace std;
using namespace xqp;


/*______________________________________________________________________
|                                                                       |
|  Unit test module for rchandle reference counting handles.            |
| 'complex' is a sample class we use to test the rchandles.             |
|                                                                       |
|_______________________________________________________________________*/

class complex : public rcobject
{
	double re;
	double im;

public:
	complex(double _re, double _im) : re(_re), im(_im) {}
	complex(double _re) : re(_re), im(0) {}
	complex(const complex& c) : re(c.re), im(c.im) {}
	~complex() {}

public:
	double real() const { return re; }
	double imag() const { return im; }

	double norm() const { return sqrt(re*re+im*im); }
	double norm2() const { return (re*re+im*im); }
	complex conjugate() const { return complex(re,-im); }
	complex inverse() const { return complex(re/norm2(), -im/norm2()); }

	friend complex operator+(complex a, complex b);
	friend complex operator-(complex a, complex b);
	friend complex operator*(complex a, complex b);
	friend complex operator/(complex a, complex b);
	friend ostream& operator<<(ostream& os, complex x);

};

ostream& operator<<(ostream& os, complex x)
{
	os << x.re;
	if (x.im>0) return os << " + " << x.im << 'i';
	if (x.im==0) return os;
	return os << " - " << -x.im << 'i';
}

complex operator+(complex a, complex b)
{
	return complex(a.re+b.re, a.im+b.im);
}

complex operator-(complex a, complex b)
{
	return complex(a.re-b.re, a.im-b.im);
}

complex operator*(complex a, complex b)
{
	return complex(a.re*b.re-a.im*b.im, a.re*b.im+a.im*b.re);
}

complex operator/(complex a, complex b)
{
	complex b0 = b.inverse();
	return a*b0;
}


int main(int argc, char* argv[])
{

	rchandle<complex> x = new complex(1,2);
	cout << "x  handle = "<<x.debug()<<endl;
	rchandle<complex> y = new complex(3,4);

	cout << "x = " << *x << endl;
	cout << "y = " << *y << endl;
	cout << "(x + y) = " << (*x + *y) << endl;
	cout << "(x - y) = " << (*x - *y) << endl;
	cout << "(x * y) = " << (*x * *y) << endl;
	cout << "(x / y) = " << (*x / *y) << endl;
	cout << "(x / y) * y = " << (*x / *y) * (*y) << endl;

	{
		rchandle<complex> x1 = x;
		cout << "x1 = " << *x1 << endl;
		cout << "  x  handle = "<<x.debug()<<endl;
		cout << "  x1 handle = "<<x1.debug()<<endl;

		{
			rchandle<complex> x2 = x1;
			cout << "x2 = " << *x2 << endl;
			cout << "    x  handle = "<<x.debug()<<endl;
			cout << "    x1 handle = "<<x1.debug()<<endl;
			cout << "    x2 handle = "<<x2.debug()<<endl;
		}

		cout << "  x  handle = "<<x.debug()<<endl;
		cout << "  x1 handle = "<<x1.debug()<<endl;
	}

	cout << "x  handle = "<<x.debug()<<endl;

}
