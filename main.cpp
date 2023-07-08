#include "structs.hpp"
#include "parse.hpp"
#include "lang.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <format>
#include <iostream>
#include "back.hpp"
#include "clback.hpp"
#include <vector>


int main(int argc, char * argv[]) {
    //printf("%d",argc);
    if (argc < 2) {
		std::cerr << "Please enter a file.\n";
        return EXIT_FAILURE;
	}
    FILE *file = fopen(argv[argc-1], "r");

    if (file == NULL) {
		std::cerr << "Please enter a (valid) file.\n";
        return EXIT_FAILURE;
    }

    yy::Scanner scanner(file, std::cout);
    resultClass * results = new resultClass({});

    yy::parser parser(scanner,results);

    

    
    parser();
    //std::cout << (*results)[0].preState[0][0].txt << std::endl;
    //if (argc > 2) makeFile(*results,argv[argc-2]);
    //else makeFile(*results);
    //testOutput(*results);
	std::vector<std::string> tokList = getTokens(*results);

	std::string curInput = "";

	
	while (curInput != "Quit") {
		std::cout << "\t> ";
		std::getline(std::cin,curInput);
		//This is gonna be bad
		std::vector<op_t> curCmd = fromStringCmd(curInput);
        
        if (curCmd.size() > 0) {
		    std::string startCmd = std::get<std::string>(curCmd[0]);
            
		    
		    if (startCmd == "list") { for (auto a : tokList) std::cout << a << std::endl << "-----" << std::endl; }
		    else if (startCmd == "") {}
        }
		
	}
    return 0;
 


}

