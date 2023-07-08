#include "structs.hpp"
#include "clparse.hpp"
#include "cllang.hpp"
#include <string>
#include <filesystem>
#include <iostream>
#include <fstream>
#include <cstdint>
namespace fs = std::filesystem;

std::vector<op_t> fromStringCmd(std::string inStr) {
    std::vector<op_t> * results = new std::vector<op_t>({});    
    cl::Scanner scanner(inStr, std::cout);
    cl::parser parser(scanner,results);
    parser();
	return *results;
}
