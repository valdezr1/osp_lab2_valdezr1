#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){

	//Two arguments indicating the following: ./new_tail [file.txt]
	if(argc == 2){
		printf("Two arguments indicating ./new_tail [file.txt]");
		
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
