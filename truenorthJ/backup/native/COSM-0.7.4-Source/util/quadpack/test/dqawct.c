#include <stdio.h>
#include <float.h>
#include <math.h>
#include "cquadpak.h"

double f(double x)
{
   double result;
   result = 1.0/(5.0*pow(x,3.0)+6.0);
   return result;
}

/* [einirv] - change main return type from void to int */
int main()
{
    double a,b,c,epsabs,epsrel,abserr,result;
    int neval,ier;

/*  a and b are the integration limits */
    a = -1.0;
    b = 5.0;

/*  c is the parameter of the weight function */
    c = 0.0;

/*  epsabs and epsrel determine the accuracy requirement */
    epsabs = 0.0;
    epsrel = 1.0e-3;

    result = dqawc(f,a,b,c,epsabs,epsrel,&abserr,
            &neval,&ier);

    printf("Integral approximation = %.12lf\n",result);
    printf("Estimate of absolute error = %.12lf\n",abserr);
    printf("Number of function evaluations = %d\n",neval);
    printf("Error code = %d\n",ier);
	return 0;
}
