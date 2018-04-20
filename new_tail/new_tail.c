#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])

	//Five
	const size_t FIVE = 5;
	//Create an array of c-strings
	char** strArr;
	//char* strArr[5];
	//Create a c-string
	char* cstr;
	char** first;
	char** last = NULL;
        //Account for malloc params (nbytes)
	const size_t nbytes = 256; 
	int read = 0;
	int i = 0;
		

	//One argument indicating the following: ./new_tail
	if(argc == 1){

		//Sets up dynamic array of char* of size FIVE
		strArr = (char**)malloc(FIVE*sizeof(char*));

		//loops through dynamic array and allocates memory per str
		for(i = 0; i < FIVE; i++){
			strArr[0] = (char*)malloc(nbytes);
		}
		
		first = strArr; //sets first to beginning of strArr
		i = 0; //resets counter
			
		//while getline is legit
		while(1){
			read = getline(&strArr[i], &nbytes, stdin);
			if(read == -1){
				break;
			}
			if(i == FIVE - 1){
				i = 0;
				
			}
			if(first == last){
				if(i + 1 == FIVE){
					first = strArr[0];
				}
				else{
					first = strArr[i+1];
				}
			}
			last = strArr[i];
			i++;
		}










		
		buff = (char*)malloc(nbytes*sizeof(array));
		ptr = ptrArr;

		//Print last five lines user enters
		for(i = 0; i < MAX; i++){
			read = getline(&buff, &nbytes, stdin);
			ptrArr[i] = buff;
			buff = NULL;
		}
		
	}
	//Two arguments indicating the following: ./new_tail [file.txt]
	else if(argc == 2){
		printf("Two arguments indicating ./new_tail [file.txt]");
		//If two arguments print last five lines of the file specified	
	}
	//Four arguments indicating the following: ./new_tail -n N [file.txt];
	else if(argc == 4){
		printf("Four arguments indicating ./new_tail -n N [file.txt]");
		//TODO: Order should not matter for these: [-n N] [file.txt]
	}
	//Wrong amount of arguments
	else{
		printf("Arguments not valid.");
	}

	return 0;

}
