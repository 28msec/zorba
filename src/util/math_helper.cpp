
#include <math.h>

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

