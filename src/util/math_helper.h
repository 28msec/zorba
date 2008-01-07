/**
 * @copyright
 * ========================================================================
 *  Copyright FLWOR Foundation
 * ========================================================================
 *
 * @author Daniel Turcanu (daniel.turcanu@ipdevel.ro)
 * @author Sorin Nasoi (sorin.nasoi@ipdevel.ro)
 * @file util/math_helper.h
 *
 */

#ifndef MATH_HELPER_FUNCTIONS_FOR_ZORBA_25_OCT_2007
#define MATH_HELPER_FUNCTIONS_FOR_ZORBA_25_OCT_2007

namespace xqp {

double round(double d);
double roundHalfToEven(double arg, int precision);

#if WIN32 & !UNIX
#define		isnan			_isnan
#define		finite		_finite
#endif
}/* namespace xqp */
#endif
