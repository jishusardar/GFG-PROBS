
/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */
class Solution{
  public: 
    bool find(Node* root,int start,int end)
    {
        if(!root)
        return 0;
        if(!root->left&&!root->right){
          if(root->data-start==1&&end-root->data==1)
          return 1;
        }
        return find(root->left,start,root->data)||find(root->right,root->data,end);
    }
    bool isDeadEnd(Node *root)
    {
        return find(root,0,INT_MAX);
        //Your code here
    }
};

