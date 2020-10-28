// import all headers


#include <stdio.h>
#include <stdlib.h>
#include "parse.h"
int test(int argc, char const *argv[]){

    int option;

	do{

		printf("* \n Please Enter Option \n Input the option number corresponding to the desired input: \n\n");

		printf("0: Exit\n");
		printf("1: Create parse tree \n");
		printf("2: Traverse the parse tree to construct typeExpressionTable \n");
		printf("3: Print parse tree \n");
		printf("4: Print typeExpressionTable \n");
		scanf("%d", &option);

        // Add functions corresponding to each option
    }
    while(option !=0);

    return 0;
}
