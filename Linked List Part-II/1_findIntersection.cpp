/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };

*****************************************************************/

int length(Node *head)
{
    int ans = 0;
    while (head)
    {
        head = head->next;
        ans++;
    }
    return ans;
}

Node *findIntersection(Node *&headA, Node *&headB)
{
    int la = length(headA), lb = length(headB), d;
    Node *templ, *temps;
    if (la > lb)
    {
        templ = headA;
        temps = headB;
        d = la - lb;
    }
    else
    {
        templ = headB;
        temps = headA;
        d = lb - la;
    }
    while (d--)
        templ = templ->next;
    while (templ)
    {
        if (templ == temps)
            return templ;
        templ = templ->next;
        temps = temps->next;
    }
    return nullptr;
}