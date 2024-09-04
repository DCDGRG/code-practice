#include <iostream>
#include <unordered_map>
using namespace std;

void handleWord(const string& word){
    unordered_map<char, int> charCount;

    //记录每个字符的出现次数
    for(const char& c : word) {
        charCount[c]++;
    }

    //找到最小的出现次数
    int minFreq = INT_MAX;
    for(const auto& pair : charCount) {
        minFreq = min(minFreq, pair.second);
    }

    //排除出现次数最少的字符， 打印新的字符串
    for(const char& c : word) {
        if (charCount[c] != minFreq) {
            cout << c;
        }
    }
}

int main() {
    string word;
    cin >> word;

    handleWord(word);
    return 0;

}
