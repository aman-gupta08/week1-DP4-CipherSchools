#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeTwoLists(ListNode *a, ListNode *b)
{
    if (a == NULL)
        return b;
    else if (b == NULL)
        return a;
    else
    {
        ListNode *result;
        if (a->val <= b->val)
        {
            result = a;
            result->next = mergeTwoLists(a->next, b);
        }
        else
        {
            result = b;
            result->next = mergeTwoLists(a, b->next);
        }

        return result;
    }
}

int main()
{

    return 0;
}