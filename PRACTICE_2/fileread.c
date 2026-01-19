#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	FILE* fp = fopen("file.txt", "r");
	if (fp == NULL)
	{
		perror("Failed to open file");
		return -1;
	}
	
	fseek(fp, 0, SEEK_END);
	long size = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	// rewind(fp);
	
	char* buffer = malloc(sizeof(char) * size); 
	fread(buffer, 1, size, fp);
	printf("The file content is: %s\n", buffer);
	printf("\n");
	return 0;
}