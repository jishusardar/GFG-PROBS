//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
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


// } Driver Code Ends

/*Complete the function below
Node is as follows:
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    // Function to check if two nodes are cousins in a tree
    int leveel(Node* root,int x)
    {
        queue<Node*>q;
        q.push(root);
        int level=0;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                Node* temp=q.front();
                q.pop();
                if(temp->data==x)
                return level;
                if(temp->left)
                q.push(temp->left);
                if(temp->right)
                q.push(temp->right);
            }
            level++;
        }
        return -1;
    }
    bool parentof(Node* root,int x,int y)
    {
        if(!root)
        return 0;
        if(root->left&&root->right){
            if(root->left->data==x&&root->right->data==y)
            return 1;
            if(root->left->data==y&&root->right->data==x)
            return 1;
        }
        return parentof(root->left,x,y)||parentof(root->right,x,y);
    }
    bool isCousins(Node* root, int x, int y) {
        // write code here
        if(x==y)
        return 0;
        int l1=leveel(root,x);
        int l2=leveel(root,y);
        if(l1!=l2)
        return 0;
        if(l1==-1||l2==-1)
        return 0;
        return !parentof(root,x,y);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    scanf("%d ", &t);
    Solution solution;
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        int x, y;
        scanf("%d ", &x);
        scanf("%d ", &y);
        cout << solution.isCousins(root, x, y) << endl;
        cout << "~" << endl;
    }
    return 1;
}
// } Driver Code Ends