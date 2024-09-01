#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

string checkPassword(const string& password){
    int UpperLetter = 0;
    int LowerLetter = 0;
    int number = 0;
    int symbol = 0;
    int sum = 0;

    //字符种类
    for(const char& letter : password){
        if(letter>='0' && letter<='9'){
            number = 1;
        }else if(letter >= 'a' && letter <= 'z'){
            LowerLetter = 1;
        }else if (letter >= 'A' && letter <= 'Z') {
            UpperLetter = 1;
        }else {
            symbol = 1;
        }
    }
    sum = UpperLetter + LowerLetter + number + symbol;
    if (sum < 3 ) {
        return "NG";
    }

    //长度
    if(password.length()<=8) {
        return "NG";
    }

    //重复子字符串
    unordered_set<string> substrings;
    for(size_t i=0 ; i< password.size() ; ++i) {
        //从长度3开始，直到字符串末尾, 将从i开始的子字符串都存到set中
        for (size_t len=3; i+len<=password.size(); ++len) {
            string substring = password.substr(i, len);
            //判定set中是否已经有重复的子串
            if (substrings.find(substring) != substrings.end()){
                return "NG";
            }
            //如果没有找到重复的子串，将其插入到set中
            substrings.insert(substring);
        }
    }
    return "OK";
}


int main() {
    vector<string> passwords;
    string password;

    while (getline(cin, password)) {
        //处理每一行的输入， 插入到vector中
        passwords.push_back(password);
    }

    // for(const string password :  passwords){
    //     cout << password << endl;
    // }

    for(const string password :  passwords){
        //处理密码的函数, 函数的返回应该打印出来
        cout << checkPassword(password) << endl;
    }
    return 0;
}
