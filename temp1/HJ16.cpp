#include <iostream>
#include <vector>
using namespace std;

struct Item {
    int v;
    int p;
    int q;
};

int dpHandle (vector<Item>& items, int N) {
    //创建二维数组dp, 大小为items.size()+1 * N+1，即物品的数量+1 * 总钱数+1， 用于存储每种状态下的最大价值
    vector<vector<int>> dp(items.size()+1, vector<int>(N+1, 0));

    //填充数组，遍历物品
    for (int i = 1; i < items.size(); i++)
    {
        for (size_t v = 0; v < N; v++)
        {
            if (items[i])
            {
                /* code */
            }
            
        }
        
    }
    


 
}

int main() {
    int N, m;
    cin >> N >> m;

    vector<Item> items(m);
    for (int i=0; i<m; ++i) {
        cin >> items[i].v >> items[i].p >> items[i].q;
    }

}

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// struct Item {
//     int v, p; // 价格和重要度
//     vector<Item> attachments; // 附件列表
// };

// int main() {
//     int N, m;
//     cin >> N >> m; // 输入预算和物品数量

//     vector<Item> items(m+1); // 存储所有物品
//     vector<vector<int>> dp(m+1, vector<int>(N+1, 0)); // dp数组

//     // 读取物品信息
//     for (int i = 1; i <= m; i++) {
//         int v, p, q;
//         cin >> v >> p >> q;
//         if (q == 0) { // 如果是主件
//             items[i].v = v;
//             items[i].p = p;
//         } else { // 如果是附件
//             items[q].attachments.push_back({v, p});
//         }
//     }

//     // 动态规划处理每个物品
//     for (int i = 1; i <= m; i++) {
//         // 对于主件及其附件的每种组合进行选择
//         for (int j = N; j >= 0; j--) {
//             // 选项1：只选择主件
//             if (j >= items[i].v) {
//                 dp[i][j] = max(dp[i][j], dp[i-1][j - items[i].v] + items[i].v * items[i].p);
//             }
//             // 选项2：选择主件+第一个附件
//             if (items[i].attachments.size() >= 1 && j >= items[i].v + items[i].attachments[0].v) {
//                 dp[i][j] = max(dp[i][j], dp[i-1][j - items[i].v - items[i].attachments[0].v] + items[i].v * items[i].p + items[i].attachments[0].v * items[i].attachments[0].p);
//             }
//             // 选项3：选择主件+第二个附件
//             if (items[i].attachments.size() == 2 && j >= items[i].v + items[i].attachments[1].v) {
//                 dp[i][j] = max(dp[i][j], dp[i-1][j - items[i].v - items[i].attachments[1].v] + items[i].v * items[i].p + items[i].attachments[1].v * items[i].attachments[1].p);
//             }
//             // 选项4：选择主件+两个附件
//             if (items[i].attachments.size() == 2 && j >= items[i].v + items[i].attachments[0].v + items[i].attachments[1].v) {
//                 dp[i][j] = max(dp[i][j], dp[i-1][j - items[i].v - items[i].attachments[0].v - items[i].attachments[1].v] + items[i].v * items[i].p + items[i].attachments[0].v * items[i].attachments[0].p + items[i].attachments[1].v * items[i].attachments[1].p);
//             }
//         }
//     }

//     // 输出最大满意度
//     cout << dp[m][N] << endl;
//     return 0;
// }