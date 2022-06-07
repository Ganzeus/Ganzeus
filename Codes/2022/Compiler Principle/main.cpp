#include <bits/stdc++.h>
#include <fstream>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 550;
set<string> res_word = { "begin", "end", "int", "if", "else", "then", "while", "do" };
set<string> symbol = { "+", "*", "=", "<", ">", "!=", ">=", "<=", "==", ",", ";", "(", ")" };
map<string, string> name;   // （标识符，中文名）
vector<string> wordTable;   // 检测到的单词表
int Index = 0;  // 单词表指针
struct IDT {    // 标识符
    string type;
    string name;
    int value;
    IDT() {}
    IDT(string type_, string name_, int value_) : type{type_}, name{name_}, value{value_} {
    }
};
vector<IDT> idtTable;   // 标识符表
map<string, int> idtIndex;  // （标识符名，下标）
int cnt = 0;    // 标识符下标
int tmpIndex = 1;   // 临时变量下标

struct FourTuple {  // 四元式
    string op;
    string addr1;
    string addr2;
    string dest;
    FourTuple() {}
    FourTuple(string op_, string addr1_, string addr2_, string dest_) : op(op_), addr1{addr1_}, addr2{addr2_}, dest{dest_} {}
    
};

vector<FourTuple> node; // 四元式表

// 重要函数声明
string readTxt();       // 读入txt
void Lex(string str);   // 词法分析
void Syntax();          // 语法分析
bool match(string type);    // 类型匹配
void parseProgram();    // <程序>
void parseExplainVars();    // <变量说明部分>
void parseStmtSection();        // <语句部分>
void parseStmtSectionP();       // <语句部分p>
void parseIdentifierList();     // <标识符列表>
void parseIdentifierListP();   // <标识符列表p>
void parseStmt();       // <语句>
void parseAssign();     // <赋值语句>
void parseIf();         // <条件语句>
void parseLoop();       // <循环语句>
pair<string, string> parseExpression();     // <表达式>
pair<string, string> parseExpressionP(pair<string, string> p1);    // <表达式p>
pair<string, string> parseItem();       // <项>
pair<string, string> parseItemP(pair<string, string> p1);      // <项p>
pair<string, string> parseFactor();     // <因子>
void parseCompound();   // <复合语句>
void parseRecursive();  // <嵌套语句>
pair<string, string> parseTerms();      // <条件>

void init() {
    name["+"] = "加法运算符";
    name["*"] = "乘法运算符";
    name["<"] = name[">"] = name["!="] = name["<="] = name[">="] = name["=="] = "关系运算符";
    name[","] = "逗号";
    name[";"] = "分号";
    name["("] = "左括号";
    name[")"] = "右括号";
    name["="] = "赋值运算符";
    name["a"] = name["b"] = name["b"] = name["c"] = name["d"] = name["e"] = name["f"] = name["g"] = name["h"] = name["i"] = name["j"] = name["k"] = name["l"] = name["m"] = name["n"] = name["o"] = name["p"] = name["q"] = name["r"] = name["s"] = name["t"] = name["u"] = name["v"] = name["w"] = name["x"] = name["y"] = name["z"] = name["A"] = name["B"] = name["C"] = name["D"] = name["E"] = name["F"] = name["G"] = name["H"] = name["I"] = name["J"] = name["K"] = name["L"] = name["M"] = name["N"] = name["O"] = name["P"] = name["Q"] = name["R"] = name["S"] = name["T"] = name["U"] = name["V"] = name["W"] = name["X"] = name["Y"] = name["Z"] = "字母";
}

bool isletter(char c) {
    return (c <= 'z' && c >= 'a') || (c >= 'A' && c <= 'Z');
}
bool isNum(char c) {
    return c <= '9' && c >= '0';
}
bool isReservedWord(string str) {
    return res_word.find(str) != res_word.end();
}
bool isSymbol(string str) {
    return symbol.find(str) != symbol.end();
}
bool isNumber(string str) {     // 判断常量（数字序列）
    for(int i = 0; i < str.length(); i++) {
        if(!isNum(str[i])) return false;
    }
    return true;
}
bool isIdentifier(string str) {     // 判断标识符
    if(!(str[0] == '$' && isletter(str[1]))) return false;
    for(int i = 2; i < str.length(); i++) {
        if(!(isletter(str[i]) || isNum(str[i]))) return false;   // 既不是字母也不是数字
    }
    return true;
}
void output(string str) {   // 输出二元式
    if(isReservedWord(str)) {
        cout << "(" << str << ", " << str << ")" << endl;
    }else if(isSymbol(str)) {
        cout << "(" << name[str] << ", " << str << ")" << endl;
    }else if(isIdentifier(str)) {   // 标识符
        cout << "(标识符, " << str << ")" << endl;
    }else if(isNumber(str)){    // 常量
        cout << "(数字, " << str << ")" << endl;
    }else {
        cout << "(未知符号, " << str << ")" << endl;
    }
}


void Lex(string str) {    // 词法分析
    int p = 0;  // 读头指针
    string tmp = "";    // 当前字符串
    int state = 1;  // 状态
    while(str[p] != '#') {
        if(str[p] == ' ') { // 跳过空格
            p++;
            continue;
        }
        if(state == 1) tmp = ""; // 清空当前字符串
        char now = str[p];
        tmp += now;

        if(state == 1) {    // 初态
            switch (now) {
            case '$':
                state = 2;
                break;
            case ';':
                wordTable.push_back(";");   // 加入表
                break;
            case ',':
                wordTable.push_back(",");
                break;
            case '=':
                if(str[p+1] == '=') {
                    wordTable.push_back("==");
                    p++;
                }else wordTable.push_back("=");
                break;
            case '+':
                wordTable.push_back("+");
                break;
            case '*':
                wordTable.push_back("*");
                break;
            case '<':
                if(str[p+1] == '=') {
                    wordTable.push_back("<=");
                    p++;
                }else wordTable.push_back("<");
                break;
            case '>':
                if(str[p+1] == '=') {
                    wordTable.push_back(">=");
                    p++;
                }else wordTable.push_back(">");
                break;
            case '!':
                state = 14;
                break;
            case '(':
                wordTable.push_back("(");
                break;
            case ')':
                wordTable.push_back(")");
                break;
            case 'i':
                state = 18;
                break;
            case 't':
                state = 22;
                break;
            case 'b':
                state = 26;
                break;
            case 'e':
                state = 31;
                break;
            case 'w':
                state = 37;
                break;
            case 'd':
                state = 42;
                break;
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                state = 44;
                break;
            default:    // 其他字符
                wordTable.push_back(tmp);   // 未知符号加入表
                break;
            }
            p++;
            continue;   // 检测下一个字符
        }else {     // 中间状态
            if(state == 2) {
                if(isletter(now)) state = 3;
                else {  // $后不是字母，则是未知符号
                    wordTable.push_back("$"); 
                    state = 1;
                    p--; // 回退一个字符
                }
            }else if(state == 3) {
                if(isletter(now) || isNum(now)) {   // 字母或数字，是标识符
                    state = 3;
                }else { // 既不是字母也不是数字
                    wordTable.push_back(tmp.substr(0, tmp.size()-1));
                    p--;
                    state = 1;
                }
            }else if(state == 14) {
                if(now == '=') {
                    wordTable.push_back("!=");
                    state = 1;
                }else {
                    wordTable.push_back("!");
                    p--;
                    state = 1;
                }
            }else if(state == 18) {
                if(now == 'n') state = 19;
                else if(now == 'f') {
                    wordTable.push_back("if");
                    state = 1;
                }else { // 未知符号
                    wordTable.push_back("i");
                    state = 1;
                    p--;
                }
            }else if(state == 19) {
                if(now == 't') {
                    wordTable.push_back("int");
                    state = 1;
                }else {
                    wordTable.push_back("i");
                    wordTable.push_back("n");
                    state = 1;
                    p--;
                }
            }else if(state == 22) {
                if(now == 'h') state = 23;
                else {
                    wordTable.push_back("t");
                    state = 1;
                    p--;
                }
            }else if(state == 23) {
                if(now == 'e') state = 24;
                else {
                    wordTable.push_back("t");
                    wordTable.push_back("h");
                    state = 1;
                    p--;
                }
            }else if(state == 24) {
                if(now == 'n') {
                    wordTable.push_back("then");
                    state = 1;
                }else {
                    wordTable.push_back("t");
                    wordTable.push_back("h");
                    wordTable.push_back("e");
                    state = 1;
                    p--;
                }
            }else if(state == 26) {
                if(now == 'e') state = 27;
                else {
                    wordTable.push_back("b");
                    state = 1;
                    p--;
                }
            }else if(state == 27) {
                if(now == 'g') state = 28;
                else {
                    wordTable.push_back("b");
                    wordTable.push_back("e");
                    state = 1;
                    p--;
                }
            }else if(state == 28) {
                if(now == 'i') state = 29;
                else {
                    wordTable.push_back("b");
                    wordTable.push_back("e");
                    wordTable.push_back("g");
                    state = 1;
                    p--;
                }
            }else if(state == 29) {
                if(now == 'n') {
                    wordTable.push_back("begin");
                    state = 1;
                }else {
                    wordTable.push_back("b");
                    wordTable.push_back("e");
                    wordTable.push_back("g");
                    wordTable.push_back("i");
                    state = 1;
                    p--;
                }
            }else if(state == 31) {
                if(now == 'n') state = 32;
                else if(now == 'l') state = 33;
                else {
                    wordTable.push_back("e");
                    p--;
                    state = 1;
                }
            }else if(state == 32) {
                if(now == 'd') {
                    wordTable.push_back("end");
                    state = 1;
                }else {
                    wordTable.push_back("e");
                    wordTable.push_back("n");
                    p--;
                    state = 1;
                }
            }else if(state == 33) {
                if(now == 's') state = 35;
                else {
                    wordTable.push_back("e");
                    wordTable.push_back("l");
                    p--;
                    state = 1;
                }
            }else if(state == 35) {
                if(now == 'e') {
                    wordTable.push_back("else");
                    state = 1;
                }else {
                    wordTable.push_back("e");
                    wordTable.push_back("l");
                    wordTable.push_back("s");
                    p--;
                    state = 1;
                }
            }else if(state == 37) {
                if(now == 'h') state = 38;
                else {
                    wordTable.push_back("w");
                    p--;
                    state = 1;
                }
            }else if(state == 38) {
                if(now == 'i') state = 39;
                else {
                    wordTable.push_back("w");
                    wordTable.push_back("h");
                    p--;
                    state = 1;
                }
            }else if(state == 39) {
                if(now == 'l') state = 40;
                else {
                    wordTable.push_back("w");
                    wordTable.push_back("h");
                    wordTable.push_back("i");
                    p--;
                    state = 1;
                }
            }else if(state == 40) {
                if(now == 'e') {
                    wordTable.push_back("while");
                    state = 1;
                }else {
                    wordTable.push_back("w");
                    wordTable.push_back("h");
                    wordTable.push_back("i");
                    wordTable.push_back("l");
                    p--;
                    state = 1;
                }
            }else if(state == 42) {
                if(now == 'o') {
                    wordTable.push_back("do");
                    state = 1;
                }else {
                    wordTable.push_back("d");
                    state = 1;
                    p--;
                }
            }else if(state == 44) {
                if(!isNum(now)) {
                    wordTable.push_back(tmp.substr(0, tmp.size()-1));
                    state = 1;
                    p--;
                }
            }
            p++;
            continue;
        }
    }
    if(state != 1 && tmp != "") wordTable.push_back(tmp);
}


bool match(string type) {
    if(type == "error") return false;
    cout << "----匹配" << type << "----" << endl;
    string now = wordTable[Index];
    cout << "检测到单词：";
    output(now);
    bool flag = true;
    if(type == "标识符") {      // 匹配标识符
        flag = isIdentifier(now);
    }else if(isReservedWord(type)) {    // 匹配保留字 
        flag = (now == type);
    }else if(type == "常量") {  // 匹配常量
        flag = isNumber(now);
    }else {
        flag = (name[now] == type);
    }

    if(flag) {
        cout << "匹配成功！" << endl;
        Index++;
        return true;
    }else {
        cout << "匹配失败！" << endl;
        return false;
    }
}

void Syntax() {
    Index = 0;  // 单词指针置0
    wordTable.push_back("#");
    parseProgram();
    if(wordTable[Index] != "#") {
        cout << "出错位置前的代码：" << endl;
        for(int i = 0; i < Index; i++) cout << wordTable[i];
        cout << endl;
    }else {
        cout << "检测到结束符(#, #)" << endl;
        cout << "词法分析结束" << endl;
    }
}

void parseProgram() {    // <程序>
    cout << "【语】推导：<程序> →<变量说明部分>;<语句部分>" << endl;
    parseExplainVars();
    match("分号");
    parseStmtSection();
    cout << "语法分析结束" << endl;
}

void parseExplainVars(){    // <变量说明部分>
    cout << "【语】推导：<变量说明部分> → <变量说明><标识符列表>" << endl;
    match("int");
    parseIdentifierList();
}

void parseIdentifierList(){     // <标识符列表>
    cout << "【语】推导：<标识符列表> → <标识符><标识符列表p>" << endl;
    if(isIdentifier(wordTable[Index])) {    // 赋值语句语义分析
        idtTable.push_back(IDT("int", wordTable[Index], 0));  // 加入标识符表
        idtIndex[wordTable[Index]] = cnt++;     // 记录标识符下标
        // cout << "声明了变量" << wordTable[Index] << endl;
        match("标识符");
    }
    parseIdentifierListP();
}

void parseIdentifierListP(){   // <标识符列表p>
    cout << "【语】推导：<标识符列表p> → ,<标识符><标识符列表p>|null" << endl;
    string next = wordTable[Index];
    if(next == ",") {
        match("逗号");
        next = wordTable[Index];
        if(isIdentifier(next)) {
            idtTable.push_back(IDT("int", next, 0));
            match("标识符");
            if(idtIndex.find(next) != idtIndex.end()) {
                cout << "warning: 标识符" << next << "重定义" << endl;
            }else idtIndex[next] = cnt++;
        }else {cout << "语法错误：标识符列表以逗号结束" << endl; return; }
        parseIdentifierListP();
    }else cout << "【语】推导：<标识符列表p> → null" << endl;
}

void parseStmtSection(){       // <语句部分>
    cout << "【语】推导：<语句部分> → <语句>;<语句部分p>" << endl;
    parseStmt();
    bool flag = match("分号");
    if(!flag) return;
    parseStmtSectionP();
}

void parseStmtSectionP(){       // <语句部分p>
    cout << "【语】推导：<语句部分p> → <语句>;<语句部分p>|null" << endl;
    string next = wordTable[Index];
    if(next == "if" || next == "while" || isIdentifier(next)) { // 下面可能是语句
        parseStmt();
        bool flag = match("分号");
        if(!flag) cout << "语句缺少分号" << endl;
        parseStmtSectionP();
    }else cout << "【语】推导：<语句部分p> → null" << endl;
}

void parseStmt(){       // <语句>
    cout << "【语】推导：<语句> → <赋值语句>|<条件语句>|<循环语句>" << endl;
    string next = wordTable[Index];
    if(isIdentifier(next)) {
        parseAssign();
    }else if(next == "if") {
        parseIf();
    }else if(next == "while") {
        parseLoop();
    }
    // else {}
}
void parseAssign(){     // <赋值语句>
    cout << "【语】推导：<赋值语句> → <标识符>=<表达式>" << endl;
    string name;
    if(isIdentifier(wordTable[Index])) {
        name = wordTable[Index];
        match("标识符");
        if(idtIndex.find(name) == idtIndex.end()) {
            cout << "语义错误：变量未声明-" << name << endl;
            return;
        }
    }
    bool flag = match("赋值运算符");
    if(!flag) return;
    pair<string, string> tmp = parseExpression();   // 递归分析表达式，返回最终的临时变量(类型，名称)
    node.push_back(FourTuple{"=", tmp.second, "null", name});
    idtTable[idtIndex[name]].value = tmp.first == "数字" ? stoi(tmp.second) : idtTable[idtIndex[tmp.second]].value;
}

void parseIf(){         // <条件语句>
    cout << "【语】推导：<条件语句> → if （<条件>） then <嵌套语句>; else <嵌套语句>" << endl;
    match("if");
    match("左括号");
    pair<string, string> p = parseTerms();  // 条件表达式的临时变量
    match("右括号");
    match("then");
    node.push_back(FourTuple{"jnz", p.second, "null", to_string(node.size() + 2)});    // 条件为真的四元式

    int fail = node.size();  // fail是条件为假的四元式下标
    node.push_back(FourTuple{"j", "null", "null", "0"});    // 待回填
    
    parseRecursive();   // 执行嵌套语句
    int exit = node.size(); // exit为嵌套语句结束后的四元式
    node.push_back(FourTuple{"j", "null", "null", "0"});

    node[fail].dest = to_string(node.size());
    
    match("分号");
    match("else");
    parseRecursive();
    node[exit].dest = to_string(node.size());   // 修改为整条if语句的下一条四元式的下标
}

void parseLoop(){       // <循环语句>
    cout << "【语】推导：<循环语句> → while （<条件>） do <嵌套语句>" << endl;
    match("while");
    match("左括号");
    int st = node.size();   // 起始四元式下标

    pair<string, string> p = parseTerms();
    node.push_back(FourTuple{"jnz", p.second, "null", to_string(node.size() + 2)});
    int fail = node.size();
    node.push_back(FourTuple{"j", "null", "null", "0"});    // 待回填

    match("右括号");
    match("do");
    parseRecursive();
    // 执行完后回到条件判断
    node.push_back(FourTuple{"j", "null", "null", to_string(st)});
    node[fail].dest = to_string(node.size());
}

pair<string, string> parseExpression(){     // <表达式>
    cout << "【语】推导：<表达式> → <项><表达式p>" << endl;
    pair<string, string> p1 = parseItem();
    pair<string, string> p2 = parseExpressionP(p1);  // 把加法前面的项传入后面分析
    return p2;
}

pair<string, string> parseExpressionP(pair<string, string> p1) {    // <表达式p>
    cout << "【语】推导：<表达式p> → <加法运算符><项><表达式p>|null" << endl;
    string next = wordTable[Index];
    if(next == "+") {
        bool flag = match("加法运算符");
        if(!flag) cout << "error: 表达式缺少加法运算符" << endl;
        pair<string, string> p2 = parseItem();
        if(p2.first == "标识符" && idtIndex.find(p2.second) == idtIndex.end()) {
            cout << "语义错误：变量未声明-" << p2.second << endl;
        }
        if(p1.first == "标识符" && idtIndex.find(p1.second) == idtIndex.end()) {
            cout << "语义错误：变量未声明-" << p1.second << endl;
        }
        IDT tmp;   // 创建临时变量
        tmp.name = "T";
        tmp.name += to_string(tmpIndex++);
        tmp.type = "int";
        int d1, d2;
        if(p1.first == "数字") d1 = stoi(p1.second);
        else d1 = idtTable[idtIndex[p1.second]].value;
        if(p2.first == "数字") d2 = stoi(p2.second);
        else d2 = idtTable[idtIndex[p2.second]].value;
        tmp.value = d1 + d2;
        idtIndex[tmp.name] = cnt++;     // 临时变量加入标识符表
        idtTable.push_back(tmp);
        node.push_back(FourTuple{"+", p1.second, p2.second, tmp.name});
        pair<string, string> p3 = parseExpressionP(make_pair("临时变量", tmp.name));
        return p3;
    }else { // 只有前面一项，直接返回
        cout << "【语】推导：<表达式p> → null" << endl;
        return p1;
    }
}

pair<string, string> parseItem(){       // <项>
    cout << "【语】推导：<项> → <因子><项p>" << endl;
    pair<string, string> p1 = parseFactor();
    pair<string, string> p2 = parseItemP(p1);    // 传入因子
    return p2;
}

pair<string, string> parseItemP(pair<string, string> p1){      // <项p>
    cout << "【语】推导：<项p> → <乘法运算符><因子><项p>|null" << endl;
    string next = wordTable[Index];
    if(next == "*") {
        bool flag = match("乘法运算符");
        if(!flag) cout << "语法错误: 项p缺少乘法运算符" << endl;
        pair<string, string> p2 = parseFactor();

        if(p2.first == "标识符" && idtIndex.find(p2.second) == idtIndex.end()) {
            cout << "语义错误：标识符未声明-" << p2.second << endl;
        }
        if(p1.first == "标识符" && idtIndex.find(p1.second) == idtIndex.end()) {
            cout << "语义错误：标识符未声明-" << p1.second << endl;
        }

        IDT tmp;     // 创建临时变量
        tmp.name = "T";
        tmp.name += to_string(tmpIndex++);
        tmp.type = "int";
        int d1, d2;
        if(p1.first == "数字") d1 = stoi(p1.second);
        else d1 = idtTable[idtIndex[p1.second]].value;
        if(p2.first == "数字") d2 = stoi(p2.second);
        else d2 = idtTable[idtIndex[p2.second]].value;
        tmp.value = d1 * d2;
        idtIndex[tmp.name] = cnt++;     // 临时变量加入标识符表
        idtTable.push_back(tmp);
        node.push_back(FourTuple{"*", p1.second, p2.second, tmp.name});
        pair<string, string> p3 = parseItemP(make_pair("临时变量", tmp.name));
        return p3;
    }else {
        cout << "【语】推导：<项p> → null" << endl;
        return p1;
    }
}

pair<string, string> parseFactor(){     // <因子>
    cout << "【语】推导：<因子> → <标识符>|<常量>|(<表达式>)" << endl;
    string next = wordTable[Index];
    if(isIdentifier(next)) {
        match("标识符");
        if(idtIndex.find(next) == idtIndex.end()) {
            cout << "语义错误：变量" << next << "未声明" << endl;
        }
        return make_pair("标识符", next);
    }else if(isNumber(next)) {
        match("常量");
        return make_pair("数字", next);    // 直接返回常量
    }else if(next == "(") {
        bool flag1 = match("左括号");
        if(!flag1) cout << "语法错误：因子表达式缺少左括号" << endl;
        pair<string, string> p = parseExpression();
        bool flag2 = match("右括号");
        if(!flag2) cout << "语法错误：因子表达式缺少右括号" << endl;
        return p;
    }else {
        cout << "语法错误：缺少因子" << endl;
        return make_pair("0", "0");
    }
}

void parseCompound(){   // <复合语句>
    cout << "【语】推导：<复合语句> → begin <语句部分> end" << endl;
    bool f = match("begin");
    if(!f) {
        match("error");
        return;
    }
    parseStmtSection();
    match("end");
}

void parseRecursive(){  // <嵌套语句>
    cout << "【语】推导：<嵌套语句> → <语句>|<复合语句>" << endl;
    string next = wordTable[Index];
    if(next == "begin") {
        parseCompound();
    }else parseStmt();
}

pair<string, string> parseTerms(){      // <条件>
    cout << "【语】推导：<条件> → <表达式><关系运算符><表达式>" << endl;
    pair<string, string> p1 = parseExpression();
    string op = wordTable[Index];
    bool flag = match("关系运算符");
    if(!flag) cout << "语法错误：条件判断语句缺少关系运算符！" << endl;
    else {
        pair<string, string> p2 = parseExpression();
        int d1, d2;
        if(p1.first == "数字") d1 = stoi(p1.second);
        else d1 = idtTable[idtIndex[p1.second]].value;
        if(p2.first == "数字") d2 = stoi(p2.second);
        else d2 = idtTable[idtIndex[p2.second]].value;
        IDT tmp;
        tmp.name = "T";
        tmp.name += to_string(tmpIndex++);
        tmp.type = "bool";
        if(op == "<"){
            tmp.value = (d1 < d2);
        }else if(op == ">") {
            tmp.value = (d1 > d2);
        }else if(op == "!=") {
            tmp.value = (d1 != d2);
        }else if(op == ">=") {
            tmp.value = (d1 >= d2);
        }else if(op == "<=") {
            tmp.value = (d1 <= d2);
        }else {
            tmp.value = (d1 == d2);
        }
        idtIndex[tmp.name] = cnt++;     // 临时变量加入标识符表
        idtTable.push_back(tmp);
        node.push_back(FourTuple{op, p1.second, p2.second, tmp.name});
        return make_pair("临时变量", tmp.name);
    } 
}

string readTxt() {  // 读文件
    string ret = "";
    fstream f;
    f.open("source.txt", ios::in);
    char c;
    string ch = " ";
    while((c = f.get()) != EOF) {
        ch[0] = c;
        ret.append(ch);
    }
    return ret + "#";
}

int main() {
    init();
    string src = readTxt();
    cout << src << endl;
    Lex(src);
    for(int i = 0; i < wordTable.size(); i++) {
        output(wordTable[i]);
    }
    Syntax();
err:
    cout << "---标识符表----" << endl;
    cout << "名称   类型   值" << endl;
    for(int i = 0; i < idtTable.size(); i++) {
        cout << idtTable[i].name << "     " << idtTable[i].type << "    " << idtTable[i].value << endl;
    }
    cout << "---目标代码---" << endl;
    for(int i = 0; i < node.size(); i++) {
        printf("(%d) (%s, %s, %s, %s)\n", i, node[i].op.c_str(), node[i].addr1.c_str(), node[i].addr2.c_str(), node[i].dest.c_str());
    }
    return 0;
}