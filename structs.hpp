#pragma once

#include <string>
#include <vector>
#include <variant>
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
        std::string cName;
        statel preState;
        statel proveState;
};
using resultClass = std::vector<ruleForm>;
using op_t = std::variant<
    std::string,
    int,
    resultClass,
    statem
>;
class userInput {
    std::string cTitle;
    std::vector<op_t> options;
};

using resultClass = std::vector<ruleForm>;

