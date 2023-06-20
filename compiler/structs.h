enum tokenTypes {
    T_VAR,
    T_LIT
};
struct mathToken {
    enum tokenTypes tokenType;
    int len;
    char * txt;
};
struct statement {
    int len;
    struct mathToken * tokPart;
};
struct ruleForm {
    int nPre;
    int nPro;
    struct statement * pState;
};