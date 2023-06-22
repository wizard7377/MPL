#include "structs.hpp"
#include "parse.hpp"
#include "lang.hpp"
#include <stdlib.h>
#include <stdio.h>



int main(int argc, char * argv[]) {
    //printf("%d",argc);
    if (argc < 2)
        return EXIT_FAILURE;

    FILE *file = fopen(argv[1], "r");

    if (file == NULL) {
        perror("Cannot open file");
        return EXIT_FAILURE;
    }

    yy::Scanner scanner(file, std::cout);
    
    yy::parser parser(scanner);

    
    parser();
    /*
    int res = 
    while (res != yy::parser::token::token_kind_type::TOK_YYEOF) {
        std::cout << res << std::endl;
       
        res = ;
    }

    std::cout << res << std::endl;
    */
    
    return 0;
 


}