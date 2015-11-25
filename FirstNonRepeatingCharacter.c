#include <stdlib.h>
#include <stdio.h>

#define MAX 256

// usage: ./FirstNonRepeatingCharacter ThisIsSampleInput
//			output: First unique character is T

int *getCharCountArray(char *str) {
	int *count = (int *)calloc(sizeof(int), MAX); 
	int i; 
	for (i = 0; *(str+i); ++i) 
		count[*(str+i)]++; 
	return count; 
}

int getIndexNonRepeating(char *str) 
{
	int *count = getCharCountArray(str); 
	int index = -1, i; 

	for (i = 0; *(str+i); ++i) {
		if (count[*(str+i)] == 1)
		{
			index = i; 
			break; 
		} 
	}
	free(count); 
	return index; 
}

int main(int argc, char** argv){
	if (argc != 2) {
		printf("error input\n"); 
		return -1; 
	}

	char *str = argv[1]; 
	int index = getIndexNonRepeating(str); 
	if (index == -1)
		printf("string is empty or non unique character exist"); 
	else 
		printf("First unique character is %c\n", str[index]); 

	getchar();  
	return 0; 
}