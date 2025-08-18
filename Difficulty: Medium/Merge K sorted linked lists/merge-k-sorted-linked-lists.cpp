/*Linked list Node structure

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        // Your code here
        priority_queue<pair<int,Node*>,vector<pair<int,Node*>>,greater<pair<int,Node*>>>q;
        for(int i=0;i<arr.size();i++){
            q.push(make_pair(arr[i]->data,arr[i]));
        }
        Node* ans=new Node(0);
        Node* temp=ans;
        while(!q.empty()){
            pair<int,Node*>p=q.top();
            q.pop();
            temp->next=p.second;
            temp=temp->next;
            if(p.second->next){
                q.push(make_pair(p.second->next->data,p.second->next));
            }
        }
        temp->next=NULL;
        return ans->next;
    }
};