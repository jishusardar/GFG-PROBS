/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/

class Solution {
  public:
    // Function to remove a loop in the linked list
    void removeLoop(Node* head) {
        // code here
        // just remove the loop without losing any nodes
        Node* slow=head;
        Node* fast=head;
        while(fast&&fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            break;
        }
        if(!fast||!fast->next)
        return;
        int count=1;
        while(slow->next!=fast)
        {
            count++;
            slow=slow->next;
        }
        fast=slow=head;
        while(count--)
        fast=fast->next;
        while(slow!=fast)
        {
            slow=slow->next;
            fast=fast->next;
        }
        while(slow->next!=fast)
        slow=slow->next;
        slow->next=NULL;
    }
};
