#include <stdio.h>
#include <math.h>

int main(void) {
	double x = 0.0;       
	double f1 = 0.0;
	double f2 = 3.5 * cos(1.5 * x - 2) + 3;
	double sum ;
	double multiply ;
	double divide1 ;
	double divide2 ;
		for (x=-10; x<=10 ; x=x+0.5) 
		{
			if (x == -1)
			{
				printf("F1(x) Can`t be computed. Division on zero\n");
			}
			else 
			{
				 f1 = (2 / (3 * x +3));
				 printf("F1(%.1f) = %f\n", x, f1 );
				
			}
				 printf("F2(%.1f) = %f\n", x, f2 );
					
					sum = f1 + f2;
					multiply = f1 * f2;
					divide1 = f1 / f2;
					divide2 = f2 / f1;
					printf("F1 + F2 = %f\n", sum);
					printf("F1 * F2 = %f\n", multiply);
					printf("F1 / F2 = %f\n", divide1);
					printf("F2 / F1 = %f\n", divide2);
					
		}
	return 0;
}
