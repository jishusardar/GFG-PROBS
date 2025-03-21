//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


vector <int> bottomView(Node *root);

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

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

//Function to return a list containing the bottom view of the given tree.

class Solution {
  public:
    void find(Node* root,int &l,int &r,int pos)
    {
        if(!root)
        return;
        
        l=min(l,pos);
        r=max(r,pos);
        find(root->left,l,r,pos-1);
        find(root->right,l,r,pos+1);
        
    }
    void traverse(Node* root,int pos,vector<int>&ans,vector<int>&count,int leveel)
    {
        if(!root)
        return;
        if(count[pos]<=leveel){
            ans[pos]=root->data;
            count[pos]=leveel;
        }
        if(root->left)
        traverse(root->left,pos-1,ans,count,leveel+1);
        if(root->right)
        traverse(root->right,pos+1,ans,count,leveel+1);
    }
    vector <int> bottomView(Node *root) {
        // Your Code Here
        int l=0,r=0;
        find(root,l,r,0);
        vector<int>ans(r-l+1);
        vector<int>count(r-l+1,INT_MIN);
        traverse(root,-1*l,ans,count,0);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.bottomView(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    
cout << "~" << "\n";
}
    return 0;
}



// } Driver Code Ends