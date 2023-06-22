#include "structs.hpp"
#include "parse.hpp"
#include "lang.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <format>
#include <iostream>
#include <vector>

/*
enum tokenTypes {
    T_VAR,
    T_LIT
};

class mtoken {
    public:
        enum tokenTypes tType;
        std::string txt;
};
using statem = std::vector<mtoken>;
using statel = std::vector<statem>;
class ruleForm {
    public:
        statel preState;
        statel proveState;
};

using resultClass = std::vector<ruleForm>;
std::vector<std::vector<std::vector<std::vector

void testOutput(resultClass testRes) {
    for (auto a : testRes) {
        for (auto b : a.preState) {
            for (auto c : b) {
                for (auto d : c) {
                    if (d.tType == T_VAR) std::cout << "$";
                    std::cout << d.txt;
                }
                
            }
            std::cout << ";\n";

        }

        std::cout << ":\n\n";

        for (auto b : a.proveState) {
            for (auto c : b) {
                for (auto d : c) {
                    if (d.tType == T_VAR) std::cout << "$";
                    std::cout << d.txt;
                }
                
            }
            std::cout << ";\n";

        }
        
        

    }
}
*/
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
    resultClass * results = new resultClass({});

    yy::parser parser(scanner,results);

    

    
    parser();
    std::cout << (*results)[1].preState[0][0].txt << std::endl;
    //testOutput(*results);
    
    return 0;
 


}

