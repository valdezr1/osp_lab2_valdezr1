#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//returns number of words in str
int wordCount(char* str){
	char* tkn;
	int count = 0;

	tkn = strtok(str, " ");

	while(tkn != NULL){
		count++;
		tkn = strtok(NULL, " ");	
	}

	return count;
}

//returns number of chars in str
int charCount(char* str){
	int count = 0; 
	int len = strlen(str);
	return len;
}


int main(int argc, char** argv){

	char* str;
	size_t buffer = 256;
	int read = 0;

	int LCount = 0;
	int WCount = 0;
	int CCount = 0;
	FILE* file;

	if(argc == 2){
		//[-l | -c] | [file.txt]
		//File
		//
		//Gist:
		//Open file if file is invoked
		//Allocate string memory
		//getline until file is ended
		//count the words, chars/lines until end of str then add to previous values
		//
		//
		//
		if( 0 != strcmp(argv[1],"-c") && 0 != strcmp(argv[1], "-l")){ //just the file
			file = fopen(argv[1], "r");
			if(file == NULL){
				printf("Invalid File\n");
			}
			str = malloc(buffer);
			while(read != -1){
				read = getline(&str, &buffer, file); 
				if(read == -1){
					break;
				}

				WCount = wordCount(str) + WCount;
			}
			free(str);
			fclose(file);
			printf("Number of words: %d\n", WCount);
			
		}
		else if(0 == strcmp(argv[1], "-c")){ //-c
			str = malloc(buffer);
			while(read != -1){
				read = getline(&str, &buffer, stdin);
				if(read == -1){
					break;
				}

				WCount = wordCount(str) + WCount;
				CCount = charCount(str) + CCount;
			}
			free(str);
			printf("Number of words: %d\n", WCount);
			printf("Number of chars: %d\n", CCount);

		}
		else { //-l
			str = malloc(buffer);
			while(read != -1){
				read = getline(&str, &buffer, stdin);
				if(read == -1){
					break;
				}

				WCount = wordCount(str) + WCount;
				LCount++;
			}
			free(str);
			printf("Number of words: %d\n", WCount);
			printf("Number of lines: %d\n", LCount);

		}
	}
	//Both [-l|-c] [file.txt]
	else if(argc == 3){
		if(strcmp(argv[1], "-l") != 0 && strcmp(argv[1], "-c") != 0){ //file first
			file = fopen(argv[1], "r");
			if(file == NULL){
				printf("Invalid File\n");
				return 0;
			}
			if(strcmp(argv[2], "-c") == 0){ //file and -c
				str = malloc(buffer);
				while(read != -1){
					read = getline(&str, &buffer, file);
					if(read == -1){
						break;
					}

					WCount = wordCount(str) + WCount;
					CCount = charCount(str) + CCount;
				}
				free(str);
				printf("Number of words: %d\n", WCount);
				printf("Number of chars: %d\n", CCount);
			}
			else if(strcmp(argv[2], "-l") == 0){ //file and -l
				str = malloc(buffer);
				while(read != -1){
					read = getline(&str, &buffer, file);
					if(read == -1){
						break;
					}
					WCount = wordCount(str) + WCount;
					LCount++;
				}
				free(str);
				printf("Number of words: %d\n", WCount);
				printf("Number of lines: %d\n", LCount);
			}
			else{
				fclose(file);
				printf("Invalid Arguments\n");
				return 0;
			}
		}
	}
	//One argument only
	else if(argc == 1){
		
		str = malloc(buffer);
		while(read != -1){
			read = getline(&str, &buffer, stdin); //user input
			if(read == -1){
				break;
			}

			WCount = wordCount(str) + WCount;
		}
		free(str);
		printf("Number of words: %d\n", WCount);

	}
	//invalid number of arguments
	else{
		printf("Invalid Arguments\n");
	}


	return 0;

}
