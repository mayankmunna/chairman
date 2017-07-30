#include <stdio.h>
#include <string.h>

main()
{
	int k;
	
	char a[] = "hello";
	char b[] = "hellp";

	printf("comparing \n");
	k = strcmp(a,b);	
	printf("comp result = %d \n",k);

	return 0;
}
