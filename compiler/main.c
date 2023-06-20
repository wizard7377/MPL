#include "structs.h"
#include <stdio.h>


int main(int argc, char * argv[]) {
   //printf("%d",argc);
    if (argc > 1) {
        printf(argv[1]);
        FILE * inFile = fopen(argv[1],"r");
        
        if (inFile) yyrestart(inFile);
    } else {
        printf("No files provided");
    }
 


}