//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// Function for Inorder Traversal
void printInorder(Node* root) {
    if (!root)
        return;

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}


// } Driver Code Ends

/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void finds(Node* root,int &l,int &r,int level)
    {
        if(!root)
        return;
        l=min(l,level);
        r=max(r,level);
        finds(root->left,l,r,level-1);
        finds(root->right,l,r,level+1);
    }
    vector<vector<int>> Traverse(Node* root,int l,int r)
    {
        vector<vector<int>>neg(l+1);
        vector<vector<int>>posi(r+1);
        stack<Node*>st;
        stack<int>sn;
        st.push(root);
        sn.push(0);
        while(!st.empty()){
            Node* temp=st.top();
            int pos=sn.top();
            st.pop();
            sn.pop();
            if(pos>=0)
            posi[pos].push_back(temp->data);
            else
            neg[abs(pos)].push_back(temp->data);
            if(temp->right){
                st.push(temp->right);
                sn.push(pos+1);
            }
            if(temp->left){
                st.push(temp->left);
                sn.push(pos-1);
            }
        }
        vector<vector<int>>ans;
        for(int i=neg.size()-1;i>=0;i--){
            if(neg[i].size()>0)
            ans.push_back(neg[i]);
        }
        for(int i=0;i<posi.size();i++){
            if(posi[i].size()>0)
            ans.push_back(posi[i]);
        }
        return ans;
    }
    vector<vector<int>> verticalOrder(Node *root) {
        // Your code here
        vector<vector<int>>ans;
        int l=0,r=0;
        finds(root,l,r,0);
        return Traverse(root,abs(l),r);
        
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        // string c;
        // getline(cin,c);
        Solution obj;
        Node* root = buildTree(s);

        vector<vector<int>> res = obj.verticalOrder(root);
        cout << "[ ";
        for (auto& vec : res) {
            cout << "[ ";
            for (int val : vec) {
                cout << val << " ";
            }
            cout << "] ";
        }
        cout << "]" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends