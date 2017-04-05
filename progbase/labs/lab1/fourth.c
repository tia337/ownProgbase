#include <stdio.h>
#include<math.h>
#include<stdio.h>
int main(void)
{
	int m, n, i, j;
	double sum1 = 0, sum = 0;
	double pi = 3.141592 ;
	double x; 
	printf ("enter integer m:");
	scanf("%i", &m);
	printf ("enter integer n:");
	scanf("%i", &n);
	
		
		
	for(i = 1; i < n; i++ )
	{
		sum1 = 0;
		for (j = 1; j < m; j++);
		{
			sum1 += cos((j*pi)/2);
			
		}
		sum += (2 + i)*sum1;
	}
					
	printf("%.10f", sum);
		
	return 0;
}
