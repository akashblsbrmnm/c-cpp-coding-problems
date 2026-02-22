#include<stdio.h>
#include<stdlib.h>

void reverse_sentence(char* str)
{
	char* words[100];
	int count = 0;

	char* token =  strok(str, " ");
	while(token != NULL)
	{
		words[count++] = token;
		token = strtok(NULL, " ");
	}
	
	for(int i = count; i>=0; i--)
	{
		printf("%s", words[i]);
	}
	return;
}

