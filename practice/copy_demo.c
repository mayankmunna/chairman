#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int copy_print(char *word);
/*void copy_print(char *word)
{
	char *new_word = NULL;
	new_word = (char *)malloc(strlen(word)+1);
	strcpy(new_word,word);
	printf("Input word = %s\n",word);
	printf("Copied word = %s\n",new_word);
	free(new_word);
	
}*/
main(int argc, char *argv[])
{
	int i=0;
	i= argc;
	i = copy_print(argv[1]);
	return 0;
}

int copy_print(char *word)
{
        char *new_word = NULL;
        new_word = (char *)malloc(strlen(word)+1);
        strcpy(new_word,word);
        printf("Input word = %s\n",word);
        printf("Copied word = %s\n",new_word);
        free(new_word);
	return 0;

}

