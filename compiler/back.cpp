#include "structs.hpp"
#include <string>
#include <filesystem>
#include <iostream>
#include <fstream>
#include <cstdint>
namespace fs = std::filesystem;

char * itoc(int inInt) {
	char * rVal = new char[4];
	int mask = 0b11111111;
	for (int i = 0; i < 4; i++) rVal[i] = (char)(mask & (inInt >> i * 4));
	return rVal;
}
char * dtoc(uint64_t inInt) {
	char * rVal = new char[8];
	int mask = 0b11111111;
	for (int i = 0; i < 8; i++) rVal[i] = (char)(mask & (inInt >> i * 4));
	return rVal;
}
char * ctoc(char inChar) {
	char * cVal = new char[1];
	cVal[0] = inChar;
	return cVal;
}

uint64_t headers[4] = {0,0,0,0};
std::vector<std::string> getTokens(resultClass inState) {
	std::vector<std::string> tokenList;
	for (auto hypo : inState) {
		statel stateList = hypo.preState;
		for (auto proveStates : hypo.proveState) stateList.push_back(proveStates);

		for (auto statements : stateList) {
			for (auto tokens : statements) {
				bool itemLook = true;
				for (auto tList : tokenList) { if (itemLook) itemLook = (tList != tokens.txt); }
				if (itemLook) tokenList.push_back(tokens.txt);

					

			}
		}

	}
	return tokenList;

}

int getTokenIndex(std::vector<std::string> tokens, std::string inStr) {
	for (int i = 0; i < tokens.size(); i++) {
		if (tokens[i] == inStr) return i;
	}
	return -1;
}
int makeFile(resultClass inState, std::string outFile) {
    fs::path fPath = fs::path(outFile);
    char zBuf[1] = {0};
	char ztBuf[4] = {0,0,0,0};
	char dBuf[1] = {(char)(0b11111111)};
	*zBuf = 0;
	//std::cout << fPath << std::endl;
    std::fstream binFile = std::fstream(fPath,std::fstream::in | std::fstream::out | std::fstream::trunc | std::fstream::binary);
	for (int i = 0; i < 16; i++) binFile.write(ztBuf,4);
	std::vector<std::string> tokenList = getTokens(inState);
    headers[0] = (int)(binFile.tellp()/4);
	int curSpace = (int)(binFile.tellp()/4) + tokenList.size();
	for (int i = 0; i < tokenList.size(); i++) {
		binFile.write(itoc(curSpace),4);
		curSpace += tokenList[i].length();
	}
	headers[1] = (int)(binFile.tellp()/4);
	for (int i = 0; i < tokenList.size(); i++) {
		for (int ii = 0; ii < tokenList[i].size(); ii++) {
			binFile.write(itoc(tokenList[i][ii]),4);
		}
	}
	//Ok now the hard part
	
	headers[2] = (int)(binFile.tellp()/4);
	
	std::vector<int> sizes;
	for (int i = 0; i < inState.size(); i++) {
		sizes.push_back(0);
		sizes[i] += inState[i].preState.size() + inState[i].proveState.size();
		statel stateList = inState[i].preState;
		for (auto proveStates : inState[i].proveState) stateList.push_back(proveStates);

		for (auto statements : stateList) {
			sizes[i] += statements.size() * 5;
		}
	}
	curSpace = (int)(binFile.tellp()/4) + (3 * inState.size());

	for (int i = 0; i < sizes.size(); i++) {
		binFile.write(itoc(curSpace),4);
		binFile.write(itoc(inState[i].preState.size()),4);
		binFile.write(itoc(inState[i].proveState.size()),4);
		curSpace += sizes[i];
	}
	binFile.write(ztBuf,4-(curSpace % 4));

	headers[3] = (int)(binFile.tellp()/4);
	for (int i = 0; i < inState.size(); i++) {
		statel stateList = inState[i].preState;
		for (auto proveStates : inState[i].proveState) stateList.push_back(proveStates);
		
		for (int ii = 0; ii < stateList.size(); ii++) {
			for (int iii = 0; iii < stateList[ii].size(); iii++) binFile.write(ctoc(stateList[ii][iii].tType),1);
			binFile.write(dBuf,1);
		}
		for (int ii = 0; ii < stateList.size(); ii++) {
			for (int iii = 0; iii < stateList[ii].size(); iii++) binFile.write(itoc(getTokenIndex(tokenList,stateList[ii][iii].txt)),1);
		}
		for (int iii = 0; iii < ((binFile.tellp()) % 4); iii++) binFile.write(zBuf,1);
	}

			

	binFile.seekp(0);
	binFile.write(dtoc(headers[0]),8);
	binFile.write(dtoc(headers[1]),8);
	binFile.write(dtoc(headers[2]),8);
	binFile.write(dtoc(headers[3]),8);

	//TODO

	return 0;
}
