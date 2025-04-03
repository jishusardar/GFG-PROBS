//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

vector<int> diagonal(Node* root);

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
    Node* root = newNode(stoi(ip[0]));

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
            currNode->left = newNode(stoi(currVal));

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
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends

/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
    void finds(Node* root,int& l,int& r,int pos)
    {
        if(!root)
        return;
        l=max(l,pos);
        finds(root->left,l,r,pos+1);
        finds(root->right,l,r,pos);
    }
    vector<int> Traverse(Node* root,int l,int r)
    {
        vector<vector<int>>arr(l+1);
        vector<int>ans;
        stack<Node*>st;
        stack<int>sn;
        st.push(root);
        sn.push(0);
        while(!st.empty()){
            Node* temp=st.top();
            st.pop();
            int pos=sn.top();
            sn.pop();
            arr[pos].push_back(temp->data);
            if(temp->right){
                st.push(temp->right);
                sn.push(pos);
            }
            if(temp->left){
                st.push(temp->left);
                sn.push(pos+1);
            }
        }
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<arr[i].size();j++){
                ans.push_back(arr[i][j]);
            }
        }
        return ans;
    }
    vector<int> diagonal(Node *root) {
        // code here
        int l=0,r=0;
        finds(root,l,r,0);
        return Traverse(root,l,r);
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s, ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution obj;
        vector<int> diagonalNode = obj.diagonal(root);
        for (int i = 0; i < diagonalNode.size(); i++) {
            if (i < diagonalNode.size() - 1)
                cout << diagonalNode[i] << " ";
            else
                cout << diagonalNode[i];
        }
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends