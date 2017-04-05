#include <stdio.h>
#include <math.h>
#include<stdlib.h>

int main (void)
{

	int a, b, c, modmin = 0, sum2 = 0, min = 0, max = 0, base = 1, result = 0;
 
 	printf("enter integer a:");
		scanf("%i", &a);
	printf("enter integer b:");
		scanf("%i", &b);
	printf("enter integer c:");
		scanf("%i", &c);
	
	if(a < 0 && b < 0 && c < 0) 
	{
		 if(a < b)
		 {
			modmin = abs(a);
		 }
		 else 
		 {
		 	modmin = abs(b);
		 }     
		 if (abs(c) > modmin)
		 {
			modmin = abs(c);
		 }
		 
	
		sum2 = (a + b + c) + modmin;
	
		while(base <= modmin)
		{ 
			base = base * 2;
		}
		if(modmin == base && sum2 > -256) 
		{
			result = 1;
		}
		else if( abs(sum2) > 16 || modmin > 8)
		{
			result = 1;
		}	
		else
		{
			result = 0;
		}
		
	}
	
	else if (a <= 0 || b <= 0 || c <= 0 || a > 0 || b > 0 || c > 0 )
		{
		
			if (a < 0 && b > 0 && c > 0 && a > -256 || b < 0 && a > 0 && c > 0 && b > -256 || c < 0 && b > 0 && a > 0 && c > -256 )
			{
				result = 1;
			}
else
			{
				result = 0;
			}		
		
		
		
			 if (a <= 0 && b <= 0 && c >= 0 && 9*(a+b) > -256 || a <= 0 && c <= 0 && b >= 0 && 9*(a+c) > -256 || b <= 0 && c <= 0 && a >= 0 && 9*(b+c) > -256 )
			{
				result = 1;
			}
			 else 
			 {
			 	result = 0;
			 }	
		}
			
	 if (a >= 0 && b >= 0 && c >= 0)
	{
		if(a > b)
		 {
			max = a;
		 }
		 else 
		 {
		 	max = b;
		 }     
		 if (c > max)
		 {
			max = c;
	 	 }
	 	 
	 	 if(a < b)
		 {
			min = a;
		 }
		 else 
		 {
		 	min = b;
		 }     
		 if (c > modmin)
		 {
			min = c;
	 	 }
	}
		
	if  (min * max > 256)
	{
		result = 1;	
	}
	else
	{
		result = 0;		
	}	
			
	if (result == 1)
	{
		printf("true\n");
	}
	else
	{
		printf("false\n");
	}
	return 0;
					
}
		
		
		
		
		
