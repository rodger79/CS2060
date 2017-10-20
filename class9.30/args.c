#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


//int main(int,char **); prototype definition



int main(int argc, char * argv[]){


	
	
	if (argc!= 2){
	//	print out usage
	return 1;	
	}
	//check for arg
	if (!(strcmp (argv[1], "-L"))){
	puts ("do L");
	}
	//check for arg
	if (!(strcmp (argv[1], "-W"))){
	puts ("do w");
	} else {
	return 1
	}

	printf("%s\n", argv[0]);
	if (argc > 1){
		
		int argVal = atoi(argv[1]);
		printf("%d\n", argVal);
	}
	
	printf("%d\n", argc);

return 0;

}
