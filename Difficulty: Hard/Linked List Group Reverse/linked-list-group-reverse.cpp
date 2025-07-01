/*
  Node is defined as
    struct node
    {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/

class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        Node* first=new Node(0);
        first->next=head;
        Node* ans=first;
        while(first->next){
            Node* second=first->next;
            int x=k;
            Node* curr=second;
            Node* prev=first;
            while(x&&curr){
                Node* fut=curr->next;
                curr->next=prev;
                prev=curr;
                curr=fut;
                x--;
            }
            first->next=prev;
            second->next=curr;
            first=second;
        }
        return ans->next;
    }
};