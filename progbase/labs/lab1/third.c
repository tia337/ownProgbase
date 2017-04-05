#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main(void)
{

	int op = 0, a = 0, b = 0, temporary = 0, min = 0, max = 0, power = 0;
	double var = 0.0, def = 0.0,  pi = 3.14159; 
		
	printf("enter integer a:\n");
	scanf("%i", &a);
	printf("enter integer b:\n");
	scanf("%i", &b);
	printf("enter operation code:\n'");
	scanf("%i", &op);
		
				var = ((6 * cos(b * pi)) / (a - 2));
				
				def = (op % abs(a + 1)) + (op % abs(b + 1)); 
		
					if (op < 0)
					{
						op = abs(op);
						a = temporary;
						temporary = b;
						a = b;		
					}
					
					
					if (a > b)
					{
						max = a;
					}
					else
					{
						max = b;
					}
					
					if (a > b)
					{
						min = b;
					}
					else
					{
					      min = a;
					}
					
					power = pow(a, b);
			
			switch (op)
			{
				case 0:
					printf("a + b = %i\n", a + b);
					break;
				case 1:
					printf("a - b = %i\n", a - b);
					break;
				case 2:
					printf("a * b = %i\n", a * b);
					break;
				case 3:
					printf("a / b = %i\n", a / b);
					break;
				case 4:
					printf("abs(a) = %i\n", abs(a));
					break;
				case 5:	
					printf("min(a, b) = %i\n", min);
					break;
				case 6:
					printf("max(a, b) = %i\n", max);
					break;
				case 7:
				case 13:
					printf("pow(a, b) = %i\n", power);
					break;
				case 8:
					if (a == 2)
					{
						printf("Deviding by zero\n");	
					}
					else
					{
						printf("var(a, b) = %f\n", var);
					}
					break;
			      default:
			      	if(a == -1 || b == -1)
			      	{
			      	printf("Deviding by zero\n");
			      	}
			      	else
			      	{
			      	printf("def(a, b) = %f\n", def);
			      	}
					
				}
			
		return 0;
}
