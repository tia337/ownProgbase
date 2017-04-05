#include <stdio.h>
#include <math.h>

int main (void) 
{

	double a, a0, a1, a2;
	double x, y, z;
	double u = 1/z;
	printf("enter x :");
	scanf("%lf", &x);
	printf("enter y :");
	scanf("%lf", &y);
	printf("enter z :");
	scanf("%lf", &z);
	if (z == x - y || x == y || x == - y || z == y - x)  
	{
		printf("Deviding by zero is unable\n");
		
	}
	else
	{
		a0 = ( pow(x, y+1)) / ( pow((x - y), u));
		a1 = y / (8 * fabs(x+y));
		a2 = pow((2 + sin(y)), (cos(x)/(z + fabs(x-y))));
		a = a0 + a1 + a2; 
		printf("Your result is: %.10f\n", a); 
	}	
	return 0;
}

