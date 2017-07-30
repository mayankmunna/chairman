#include <stdio.h>

int fact(int);
int main (void)
{
   int lResult = 0;
   lResult = fact(5);
   printf("Factorial is %d\n", lResult);
   return 0;
}

int fact( int aInValue)
{
    if (aInValue == 0)
    {
        return 1;
    }   
    else
    {
        return aInValue * fact (aInValue - 1);
    }
}
