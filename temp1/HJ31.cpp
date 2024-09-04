#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    string line;
    getline(cin, line);

    vector<string> words;
    string word;

    //将处理后的line， 存入到words中
    for(const char& letter : line) {
        if(isalpha(letter)){
            word.push_back(letter);
        }else if(!word.empty()){   //确保仅在 word 不为空时才 push_back
            words.push_back(word);
            word.clear();
        }
    }
    //确保循环结束后，最后一个单词也要插入到words中
    if(!word.empty()){
        words.push_back(word);
    }

    //逆向输出words
    reverse(words.begin(), words.end());
    for(string& word : words) {
        cout << word << ' ' ;
    }
    return 0;

}
