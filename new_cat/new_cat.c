#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
	const int MAX = 1000;
	FILE* fp;
	char str[MAX];

	if(argc != 2){
		//argv[0] = programName
		//arg[1] = readFile
		//if argc is not 2, then there are too many
		//	arguments or not enough.
		
		printf("Invalid argument provided\n");
		exit(EXIT_FAILURE);

	}

	fp = fopen(argv[1], "r"); //read the file (if it exists)

	//File not found or does not exist
	if(fp == NULL){
		printf("File not found\n");
		exit(EXIT_FAILURE);
	}

	while(fgets(str, MAX, fp) != NULL){
		printf("%s", str);
	}

	fclose(fp);
	return 0;

}
