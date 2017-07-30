#include <stdio.h>
#include <stdlib.h>
void multiply_table( void *aInValue);
int main()
{
    int lNum1 = 10;
    int lNum2 = 2;
    multiply_table((void *)&lNum1);
    multiply_table((void *)&lNum2);
    exit(EXIT_SUCCESS);
}
void multiply_table( void *aInValue)
{
    int *lInValue = NULL;
    lInValue = (int *)aInValue;
    int index = 1;
    for(index = 1; index <= 10; index++)
    {
        printf("%d * %d = %d\n", *lInValue, index, (*lInValue)*index);
    }
}
