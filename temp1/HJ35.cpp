/*
蛇形矩阵是由1开始的自然数依次排列成的一个矩阵上三角形。
例如，当输入5时，应该输出的三角形为：
1 3 6 10 15
2 5 9 14
4 8 13
7 12
11
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n, 0));
    int num = 1;
    for (int i = 0; i < n; i++)
    {
        int row = i;
        int col = 0;
        while (row >= 0 && col < n)
        {
            /*
            row--和col++是后置递减和后置递增操作，这意味着在赋值语句执行后，才会执行递减和递增操作*/
            // matrix[row--][col++] = num++;
            matrix[row][col] = num; // 先赋值
            num++;                  // 然后自增 num
            row--;                  // 再递减 row
            col++;                  // 最后递增 col
        }
    }

    // 打印矩阵
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (matrix[i][j] != 0)
            {
                cout << matrix[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
// 64 位输出请用 printf("%lld")