/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (!head || !head->next)
            return nullptr;
        ListNode *slow = head, *fast = head;
        do
        {
            slow = slow->next, fast = fast->next->next;
            if (!fast || !fast->next)
                return nullptr;
        } while (slow != fast);
        fast = head;
        while (slow != fast)
            slow = slow->next, fast = fast->next;
        return slow;
    }
};