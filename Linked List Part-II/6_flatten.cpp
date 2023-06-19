/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */

Node *sortTwoLists(Node *p1, Node *p2)
{
    Node *dummy = new Node(), *temp = dummy;
    while (p1 && p2)
    {
        if (p1->data <= p2->data)
            temp->child = p1, p1 = p1->child;
        else
            temp->child = p2, p2 = p2->child;
        temp = temp->child;
    }
    while (p1)
        temp->child = p1, p1 = p1->child, temp = temp->child;
    while (p2)
        temp->child = p2, p2 = p2->child, temp = temp->child;
    return dummy->child;
}

Node *flattenLinkedList(Node *&head)
{
    Node *nxt = head->next;
    while (nxt)
    {
        head = sortTwoLists(head, nxt);
        nxt = nxt->next;
    }
    nxt = head;
    while (nxt)
    {
        if (nxt->next)
            nxt->next = nullptr;
        nxt = nxt->child;
    }
    return head;
}