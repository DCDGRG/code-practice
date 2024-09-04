#include <cctype>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
主要想法是将英文字母提取出来再排序，然后重构一个字符串， 即遍历原始字符串，如果是字母的话从排好序后的新字符串取出并替换
*/

string sortString(const string &str)
{
    // 提取所有英文字母
    vector<pair<char, int> > lettersOrder;
    for (int i = 0; i < str.size(); ++i)
    {
        if (isalpha(str[i]))
        {
            lettersOrder.push_back(make_pair(str[i], i));
        }
    }
    // 对提取了所有的英文字母后排序
    // 关于lambda: 如果把普通函数看作是你提前写好、随时可以调用的工具，lambda 表达式更像是你随手写的一个小工具，只在一个地方使用
    sort(lettersOrder.begin(), lettersOrder.end(), [](const pair<char, int> &a, const pair<char, int> &b)
         {
        //相同字母不排序
        if(tolower(a.first) != tolower(b.first)) {
            //这里return就是定义了排序规则
            return tolower(a.first) < tolower(b.first);
        }
        return a.second < b.second; });

    // 重构字符串，对字母替换，非字母不动
    string output;
    for (int i = 0; i < str.size(); ++i)
    {
        if (isalpha(str[i]))
        {
            // front返回容器中第一个元素的引用
            output.push_back(lettersOrder.front().first);
            // 抹除掉lettersOrder中的第一个元素
            lettersOrder.erase(lettersOrder.begin());
        }
        else // 非字母直接插入
        {
            output.push_back(str[i]);
        }
    }

    return output;
}

int main()
{
    string str;
    getline(cin, str);

    cout << sortString(str) << endl;
    return 0;
}
