#include <stdio.h>
#include <float.h>
#include <math.h>
#include <stdlib.h>
// [einirv] - commented out (no malloc.h in OS X)
//#include <malloc.h>
#include "cquadpak.h"
#include "dqdefs.h"

double fx(double x)
{
	return exp(-x);
}

/* [einirv] - change main return type from void to int */
int main()
{
	double a,b,omega,result,abserr,epsabs,epsrel;
    double **chebmo;
    int i,ier,icall,n,neval,momcom;
	n = 21;
	chebmo = (double **)calloc(n,sizeof(double *));
	for (i = 0;i < n; i++)
		chebmo[i] = (double *)calloc(25,sizeof(double));

	a = 0.0;
	b = 11.0;
	omega = 20.0;
	icall = 1;	
	momcom = 0;
	epsabs = 1e-8;
	epsrel = 1e-12;
    result = dqfour(fx,a,b,omega,COSINE,epsabs,epsrel,
        icall,MAXP1,&abserr,&neval,&ier,&momcom,chebmo);
	printf("\nresult = %.17lg\n",result);
	printf("abserr = %.17lg\n",abserr);
	printf("neval = %d\n",neval);
	printf("momcom = %d\n",momcom);
	for (i = 0; i < n; i++)
		free(chebmo[i]);
	free(chebmo);
	return 0;
}
