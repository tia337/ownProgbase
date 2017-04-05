#include<stdio.h>
#include<math.h>
#include<progbase.h>
#include<time.h>
#include<pbconsole.h>

int main (void)
{
    int A[10];
    char S[10];
    int sum = 0;
    int count = 0;
    int max = 0;
    int index = 0;
    int i = 0;
    int min = 0;
    float arythmean = 0.0;

    srand(time(0));
    printf("1. Random array of 10 numbers: \n");
    for (i = 0; i <= 9; i++)
    {
        A[i] = rand() % 199 -99;
        printf("%i\t", A[i]);
    }
    printf("\n2. Set color for numbers greater than 50: \n");
    for (i = 0; i <= 9; i++)
    {
        if(A[i] > 50 )
        {
            conSetAttr(FG_RED);
            printf("%i\t", A[i]);
            conReset();
        }
        else
        {
            printf("%i\t", A[i]);
        }


    }
    printf("\n3. Set color for numbers greater than -50 and less than 50 their sum and amount and arythmean: \n");
    for (i = 0; i <= 9; i++)
    {
        if(A[i] >= -50 && A[i] <= 50 )
        {
            conSetAttr(FG_RED);
            printf("%i\t", A[i]);
            conReset();
            count++;
            sum += A[i];
            if(count != 0)
            {
                arythmean = (double)(sum / (double)count);
            }
            else
            {
                printf("deviding by zero");
            }
        }
        else
        {
            printf("%i\t", A[i]);
        }
    }
    printf("\n amount of numbers greater than -50 and less than 50 is: %i\n", count);
    printf("\n sum of numbers greater than -50 and less than 50 is: %i\n", sum);
    printf("\n arythmean of numbers greater than -50 and less than 50 is: %.3f\n", arythmean);

    printf("\n4. Output value and index of greatest negative element in array. \n");
    max = -99;
    for (i = 0; i <= 9; i++)
    {
        if(A[i] > max && A[i] < 0 )
        {
            max = A[i];
            index = i;
        }
    }
    printf("\n value and index of greatest negative element in array is (value) (index) : %i %i\n", max, index);

    printf("\n5. Output value and index of the first least element in array. \n");
    min = 200;
    for (i = 0; i <= 9; i++)
    {
        if(A[i] < min)
        {
            min = A[i];
            index = i;
        }
    }
    printf("\n the first least element in array is (value) (index) : %i %i\n", min, index);

    printf("\n6. Create new char array and rewrite elements from A[] according the rule. \n");
    for (i = 0; i <= 9; i++)
    {
        if(i == 9)
        {
            S[9] = '\0';
        }
        else
        {
            S[i] = (abs(A[i]) % 95 + 32);
        }

    }
    puts(S);
    
    printf("\n7. Assign all elements less than 50 value of 0 and colorize them : \n");
    for (i = 0; i <= 9; i++)
    {
        if(A[i] < 50 )
        {
            A[i] = 0;
            conSetAttr(FG_RED);
            printf("%i\t", A[i]);
            conReset();
        }
        else
        {
            printf("%i\t", A[i]);
        }
    }
    printf("\n");
    return 0;
}
