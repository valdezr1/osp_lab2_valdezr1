#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main(int argc, char** argv){
	const int MAX = 1000; //to initialize char array. Max to 1000 char per line
	FILE* fp; //instance of file
	char str[MAX];//char array
	char* buff;
	int read = 0;
	size_t nbytes = 1000;

	if(argc > 2){
		//argv[0] = programName
		//arg[1] = readFile
		//if argc is greater than 2, then there are too many
		
		printf("Invalid argument provided\n");
		exit(EXIT_FAILURE);

	}
	else if(argc == 2){ //if it is 2 then print the file, only accept one file

		fp = fopen(argv[1], "r"); //read the file (if it exists)

		//File not found or does not exist
		if(fp == NULL){
			printf("File not found\n");
			exit(EXIT_FAILURE);
		}

		//keep reading file and print untill null (eof)
		while(fgets(str, MAX, fp) != NULL){
			printf("%s", str);
		}

		//close file
		fclose(fp);
	}
	else{
		//argc == 1 where only the program is ran but no other args
		
		buff = (char*)malloc(nbytes*sizeof(str));
		
		while(1){
			read = getline(&buff, &nbytes, stdin);
			if(read == -1){
				break;
			}
			printf(buff);
		}

		free(buff);

	}


	return 0;

}
