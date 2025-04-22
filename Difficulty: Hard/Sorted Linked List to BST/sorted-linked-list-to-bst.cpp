//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct LNode {
    int data;
    struct LNode* next;

    LNode(int x) {
        data = x;
        next = NULL;
    }
};

struct TNode {
    int data;
    struct TNode* left;
    struct TNode* right;

    TNode(int x) {
        data = x;
        left = right = NULL;
    }
};

void preOrder(TNode* node) {
    if (node == NULL)
        return;
    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}


// } Driver Code Ends

/*
struct LNode { //Linked List
    int data;
    struct LNode* next;
    LNode(int x){
        data = x;
        next = NULL; }
};
struct TNode {   //Tree
    int data;
    struct TNode* left;
    struct TNode* right;
    TNode(int x){
        data=x;
        left=right=NULL; }
}; */
class Solution {
  public:
    TNode* CreateBST(vector<int>&arr,int start,int end)
    {
        if(start>end)
        return NULL;
        int mid=start+(end-start+1)/2;
        TNode* temp=new TNode(arr[mid]);
        temp->left=CreateBST(arr,start,mid-1);
        temp->right=CreateBST(arr,mid+1,end);
        return temp;
    }
    TNode *sortedListToBST(LNode *head) {
        // code here
        vector<int>arr;
        LNode* temp=head;
        while(temp){
            arr.emplace_back(temp->data);
            temp=temp->next;
        }
        return CreateBST(arr,0,arr.size()-1);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        LNode* head = new LNode(data);
        LNode* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new LNode(data);
            tail = tail->next;
        }

        Solution ob;
        TNode* Thead = ob.sortedListToBST(head);
        preOrder(Thead);
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends