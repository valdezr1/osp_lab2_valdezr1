#include <stdio.h>
#include <stdlib.h>

int wordCount(char* str){
	char* tkn;
	int count = 0;

	tkn = strtok(str, " ");

	while(tkn != NULL){
		count++;
		tkn = strtok(str, " ");	
	}

	return count;
}


int main(int argc, char** argv){


	FILE* file;

	if(argc == 2){
		//[-l | -c] | [file.txt]
		//File
		if(strcmp(argv[1],"-c") || strcmp(argv[1], "-l")){
			file = fopen(argv[1], "r");
			if(file == NULL){
				printf("Invalid File");
			}
			
		}
	}

	return 0;

}
