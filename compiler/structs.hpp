#pragma once

#include <string>
#include <vector>
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