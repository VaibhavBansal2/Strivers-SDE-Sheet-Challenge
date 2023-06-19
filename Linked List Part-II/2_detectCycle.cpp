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

bool detectCycle(Node *&head)
{
    if (!head || !head->next)
        return false;
    Node *slow = head, *fast = head;
    do
    {
        slow = slow->next, fast = fast->next->next;
        if (!fast || !fast->next)
            return false;
    } while (slow != fast);
    return true;
}