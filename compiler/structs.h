#pragma once
enum tokenTypes {
    T_VAR,
    T_LIT
};

struct mtoken {
    enum tokenTypes tType;
    char * txt;
};
struct statement {
    int len;
    struct mtoken * tokPart;
};
struct stateList {
    int len;
    struct statement * lState;
};
struct ruleForm {
    struct stateList preState;
    struct stateList proveState;
};