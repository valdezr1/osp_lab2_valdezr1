#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){

	int i = 1;

	//if only one argument (the program)
	if(argc == 1){
		printf("\n");
	}
	else{
		//iterate through arguments and print each of them
		for(i=1; i < argc; i++){
			printf(argv[i]);
			printf(" ");
		}
	}

	printf("\n");
	return 0;

}
