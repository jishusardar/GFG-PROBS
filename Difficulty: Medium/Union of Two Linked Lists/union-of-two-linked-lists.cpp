//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }

    int data = arr[0];
    Node* head = new Node(data);
    Node* tail = head;
    for (int i = 1; i < arr.size(); ++i) {
        data = arr[i];
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/*
// structure of the node is as follows

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};

*/
class Solution {
  public:
    struct Node* convert(set<int>arr){
        Node* ans=new Node(0);
        Node* temp=ans;
        for(auto i:arr){
            temp->next=new Node(i);
            temp=temp->next;
        }
        temp->next=NULL;
        return ans->next;
    }
    struct Node* makeUnion(struct Node* head1, struct Node* head2) {
        // code here
        set<int>s;
        for(Node* i=head1;i!=NULL;i=i->next){
            s.insert(i->data);
        }
        for(Node* i=head2;i!=NULL;i=i->next){
            s.insert(i->data);
        }
        return convert(s);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        Node* first = buildList();

        Node* second = buildList();
        Solution obj;
        Node* head = obj.makeUnion(first, second);
        printList(head);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends