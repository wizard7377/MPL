#pragma once

#include "structs.hpp"
#include <iostream>
#include <string>

int makeFile(resultClass inState, std::string outFile = "out.mbc");
resultClass fromString(std::string inStr);
std::vector<std::string> getTokens(resultClass inState);
int getTokenIndex(std::vector<std::string> tokens, std::string inStr);