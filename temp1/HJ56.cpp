/*
完全数（Perfect number），又称完美数或完备数，是一些特殊的自然数。
它所有的真因子（即除了自身以外的约数）的和（即因子函数），恰好等于它本身。
例如：28，它有约数1、2、4、7、14、28，除去它本身28外，其余5个数相加，1+2+4+7+14=28。

输入n，请输出n以内(含n)完全数的个数。
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> perfect_numbers;
    for (int i = 2; i <= n; i++)
    {
        int sum = 1;    //1是所有数的约数
        for (int j = 2; j < sqrt(i); j++)     //所以就从2开始， 2到n
        {
            if (i % j == 0)
            {
                sum += j;
                if(j != i / j)  // 避免平方数重复加入, 比如 4 = 2 * 2， 2只加一次。同时也加入另一个约数
                {
                    sum += i / j;
                }
            }
        }
        if (sum == i)
        {
            perfect_numbers.push_back(i);
        }
    }

    cout << perfect_numbers.size() << endl;

    return 0;
}