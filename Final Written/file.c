#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>


int main(int argc, char ** argv){
	char * filecontent;
	uint32_t fsize = 0;
	
	//check for the correct arguments
	if (argc!= 4){
		fprintf(stderr, "%s: takes exactly three arguments\n", argv[0]);
		return 1;	
	}
	char src = argv[2][0];
	char dest = argv[1][0];
	char * filename = argv[3];

	
	FILE * fh;
	fh = fopen(filename,"r+");
	if (!(fh)){ 
		fprintf(stderr, "File %s did not open", filename);
		return 1;
	}
	
	fseek(fh, 0, SEEK_END);
	fsize = ftell(fh);
	fseek(fh,0,SEEK_SET);
	filecontent = (char *)malloc(fsize+1);
	fread(filecontent,fsize,1,fh);
	
	//read all of file into
	for (int i = 0; i <=fsize; i++){
		if (filecontent[i] == dest){
			filecontent[i] = src;
		}	
	}
	fseek(fh,0,SEEK_SET);
	fwrite(filecontent,fsize,1,fh);
	int x = strlen(filecontent);
		
	fclose(fh);

return 0;
}
