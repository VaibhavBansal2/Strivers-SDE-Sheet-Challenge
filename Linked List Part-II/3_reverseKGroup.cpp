// CodeStudio

#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
        };

*****************************************************************/

Node *reverseKGroup(Node *&head, int b[], int &n, int i = 0)
{
    if (i == n)
        return head;
    if (!b[i])
        return reverseKGroup(head, b, n, i + 1);
    Node *prev = nullptr, *curr = head, *next = nullptr;
    int count = 0;
    while (count < b[i] && curr)
    {
        count++;
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    if (curr)
        head->next = reverseKGroup(curr, b, n, i + 1);
    return prev;
}

Node *getListAfterReverseOperation(Node *&head, int &n, int b[])
{
    return reverseKGroup(head, b, n);
}

// Leetcode

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
    ListNode *reverseKGroup(ListNode *head, int &k)
    {
        ListNode *dummy = new ListNode();
        ListNode *before = dummy, *after = head;
        ListNode *prev = nullptr, *curr = head, *next = nullptr;
        while (1)
        {
            ListNode *temp = curr;
            for (int i = 0; i < k; i++)
            {
                if (!temp)
                    return dummy->next;
                temp = temp->next;
            }
            for (int i = 0; i < k; i++)
            {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            after->next = curr;
            before->next = prev;
            before = after;
            after = curr;
            prev = nullptr;
        }
    }
};