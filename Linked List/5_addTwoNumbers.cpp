/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *p1 = l1, *p2 = l2;
        while (p1 && p2)
            p1 = p1->next, p2 = p2->next;
        if (!p1)
            swap(l1, l2);
        bool carry = 0;
        ListNode *temp = l1;
        while (temp->next)
        {
            temp->val += carry;
            if (l2)
                temp->val += l2->val, l2 = l2->next;
            if (temp->val >= 10)
                temp->val -= 10, carry = 1;
            else
                carry = 0;
            temp = temp->next;
        }
        if (l2)
            temp->val += l2->val;
        temp->val += carry;
        if (temp->val >= 10)
            temp->next = new ListNode(1), temp->val -= 10;
        return l1;
    }
};