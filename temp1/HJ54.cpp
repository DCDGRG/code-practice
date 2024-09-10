/*
四则运算
*/

#include <iostream>
#include <vector>
using namespace std;

//字符串转数字
int string2integer(const string &number)
{
    int result = 0;
    for (const char &c : number)
    {
        result = result * 10 + (c - '0');
    }
    return result;
}

//优先级处理
int precedence(const string &op) {
    if (op == "+" || op == "-") return 1;
    if (op == "*" || op == "/") return 2;
    return 0;
}

//执行运算函数
int execute(int a, int b, const string &op) {
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*") return a * b;
    if (op == "/") return a / b;
    return 0;
}

int evaluate(const string &line){

}

int main()
{
    string line;
    getline(cin, line);

    string number;

    // 先将数字和符号都存储到string vector中，再遍历vector处理
    // 当前看可能需要数字和操作符分开处理，存入两个不同的栈中
    vector<string> numbers;
    vector<string> operations;
    for (const char &c : line)
    {
        if (c >= '0' && c <= '9')
        {
            number.push_back(c);
        }
        else
        {
            numbers.push_back(number);
            // 清空number
            number.clear();
            
            operations.emplace_back(1, c);
        }
    }

    // 循环结束后检查number是否还有未插入到vector中的数字
    if (!numbers.empty()){
        numbers.push_back(number);
    }

    // test
    for (const string &str : numbers){
        cout << str << endl;
    }
    for (const string &str : operations){
        cout << str << endl;
    }

    // 处理运算
    //1. string 数字转换为整数
    vector<int> nums;
    for (const string &str : numbers){
        int num = string2integer(str);
        nums.push_back(num);
    }
    



    //
   
    return 0;
}
 