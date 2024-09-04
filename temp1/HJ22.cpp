#include <iostream>
#include <vector>
using namespace std;

int main() {
    int number;
    vector<int> inputs;

    //当读到0的时候结束输入
    while (cin >> number && number != 0) {
        inputs.push_back(number);
    }

    //数字除以3， 看商是多少， 加上余数再除以3， 直到最后商加余数等于2时，可以再加1，等于1时不再加1，等于0时就结束
    for(const int& number : inputs) {
        int rem = number % 3;
        int res = number / 3;
        int output = res;

        while (rem + res > 3)
        {
            int temp = rem + res;
            rem = temp % 3;
            res = temp / 3;
            output += res;
        }

        if (rem + res == 2 || rem + res == 3)
        {
            output += 1;
        }
        cout << output << endl;
    }
    return 0;
    
}