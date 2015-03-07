#include "mymalloc.h"
#include <stdlib.h>
#include <stdio.h>

#define malloc(x) my_malloc(x, __FILE__,__LINE__)
#define free(x) my_free(x, __FILE__, __LINE__)
		 


int main(int argc, char **argv){
	//this should work fine
	char *large_frag = malloc(4862);
	char *small_frag = malloc(289);
	free(large_frag);
	free(small_frag);
	//saturation check should produce error
	char *satcheck = malloc(5000);
	//double free check should produce error
	char *doublecheck = malloc(100);
	free(doublecheck);
	free(doublecheck);
	
	//free pointer that wasn't allocated should produce error
	int x = 3;
	free(&x);
	
	//free pointer not allocated with malloc should give an error
	char *test1 = malloc(30);
	free(test1 + 10);
	exit(0);

}
