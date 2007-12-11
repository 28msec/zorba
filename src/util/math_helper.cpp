/**
 * @copyright
 * ========================================================================
 *  Copyright FLWOR Foundation
 * ========================================================================
 *
 * @author Daniel Turcanu (daniel.turcanu@ipdevel.ro)
 * @author Sorin Nasoi (sorin.nasoi@ipdevel.ro)
 * @file util/math_helper.cpp
 *
 */
 
#include <math.h>

namespace xqp {
  double round(double d)
  {
	 double	fraction;
	 double	retval;
  
	 fraction = modf(d, &retval);
	 if(fraction < 0)
		  if(fraction < -0.5)
			 return retval-1;
		  else
			 return retval;
	 else
		  if(fraction < 0.5)
			 return retval;
		  else
			 return retval+1;
  }
  
  double roundHalfToEven(double arg, int precision)
  {
    double retval, nr, tmpVal, tmpFraction;
    double  fraction;
    
    nr = arg * pow((float)10, -precision);
    fraction = modf(nr, &retval);

    if(fabs(fraction) == 0.5)
    {
      tmpFraction = modf((retval/2), &tmpVal);
      if(tmpFraction !=0)
        (fraction==-0.5)?--retval:++retval;
    }
    else
    {
      nr = arg * pow((float)10, precision);
      nr = round(nr);
      retval = nr * pow((float)10, -precision);
    }
    return retval;
  }
}/*namespace xqp */
