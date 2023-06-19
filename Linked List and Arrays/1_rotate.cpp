/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

int length(Node *&head)
{
    Node *temp = head;
    int count = 0;
    while (temp)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

Node *rotate(Node *&head, int &k)
{
    if (!head->next || !k)
        return head;
    int len = length(head);
    k %= len;
    if (!k)
        return head;
    Node *l = head, *r = head;
    while (k--)
        r = r->next;
    while (r->next)
        l = l->next, r = r->next;
    Node *ret = l->next;
    l->next = nullptr;
    r->next = head;
    return ret;
}