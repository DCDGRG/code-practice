/*
输入一个单向链表，输出该链表中倒数第k个结点，链表的倒数第1个结点为链表的尾指针。
*/

#include <iostream>
using namespace std;

struct ListNode
{
    int value;
    ListNode *NextNode;
};

// 寻找倒数第k个节点,双指针
ListNode *ToFindK(ListNode *head, int k)
{
    // 排除空链表的情况
    if (head == nullptr || k <= 0)
    {
        return nullptr;
    }
    /*  一个指针先走 k 步，然后两个指针一起走，直到第一个指针到达链表的末尾，
    第二个指针所在的位置就是倒数第 k 个结点。*/
    ListNode *fast = head;
    ListNode *slow = head;

    // 让 fast 指针先走 k 步
    for (int i = 0; i < k; i++)
    {
        fast = fast->NextNode;
    }

    while (fast != nullptr)
    {
        fast = fast->NextNode;
        slow = slow->NextNode;
    }
    return slow;
}

// 创建新链表节点的函数
ListNode *CreateNode(int value)
{
    ListNode *newNode = new ListNode();
    newNode->value = value;
    newNode->NextNode = nullptr;
    return newNode;
}

// 打印链表，参数为头节点
void printList(ListNode *head)
{
    ListNode *current = head;
    while (current != nullptr)
    {
        cout << current->value << ' ';
        current = current->NextNode;
    }
    cout << endl;
}

// 用户输入多组用例
int main()
{

    while (cin)
    {
        int n;
        //cin >> n 也已经在这个判断中执行了
        if (!(cin >> n)) break;  // 如果输入无效，退出循环

        // 先将一个数插入到链表中, 当作头节点，利于之后操作
        int value;
        cin >> value;
        ListNode *head = CreateNode(value);
        ListNode *current = head;

        // 将数组的其他数字也插入到链表中
        for (int i = 1; i < n; i++)
        {
            cin >> value;
            current->NextNode = CreateNode(value);
            current = current->NextNode;
        }
        //
        //printList(head);

        int k;
        cin >> k;
        ListNode *result = ToFindK(head, k);

        cout << result->value << endl;
    }

    return 0;
}
