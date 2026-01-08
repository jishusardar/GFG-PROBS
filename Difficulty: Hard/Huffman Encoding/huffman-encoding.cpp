class Solution {;
  public:
  class Node
    {
        public:
        int freq;
        char c;
        Node* left,*right;
        Node(int freq,char c)
        {
            this->freq=freq;
            this->c=c;
            left=NULL;
            right=NULL;
        }
    };
    class comp{
        public:
        int freq;
        bool operator()(Node* a,Node* b)
        {
            return a->freq > b->freq;
        }
    };
    
    void preorder(Node* root,string &temp,vector<string>&ans)
    {
        if(!root)
        return;
        
        if(!root->left&&!root->right){
            ans.push_back(temp);
            return;
        }
        temp.push_back('0');
        preorder(root->left,temp,ans);
        temp.pop_back();
        temp.push_back('1');
        preorder(root->right,temp,ans);
        temp.pop_back();
    }
    vector<string> huffmanCodes(string S, vector<int> f, int N) {
        // Code here
        priority_queue<Node*,vector<Node*>,comp>pq;
        for(int i=0;i<N;i++){
            pq.push(new Node(f[i],S[i]));
        }
        while(pq.size()>1){
            Node* first=pq.top();
            pq.pop();
            Node* second=pq.top();
            pq.pop();
            Node* root=new Node(first->freq+second->freq,'$');
            root->left=first;
            root->right=second;
            pq.push(root);
        }
        Node* root=pq.top();
        pq.pop();
        vector<string>ans;
        string temp;
        preorder(root,temp,ans);
        return ans;
    }
};