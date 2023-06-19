#include <bits/stdc++.h>
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int> *findMiddle(LinkedListNode<int> *&head)
{
    LinkedListNode<int> *slow = head, *fast = head;
    while (fast && fast->next)
        slow = slow->next, fast = fast->next->next;
    return slow;
}

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *&head)
{
    LinkedListNode<int> *prev = nullptr, *curr = head, *next = head;
    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool isPalindrome(LinkedListNode<int> *&head)
{
    if (!head || !head->next)
        return true;
    LinkedListNode<int> *mid = findMiddle(head), *temp = head;
    while (temp->next != mid)
        temp = temp->next;
    LinkedListNode<int> *p = reverseLinkedList(mid), *q = p;
    temp->next = p;
    temp = head;
    while (temp != q)
    {
        if (temp->data != p->data)
            return false;
        temp = temp->next, p = p->next;
    }
    return true;
}