// User function Template for C++

class Solution {
    class TrieNode{
        public:
        TrieNode* child[26];
        bool isendofword;
        TrieNode(){
            isendofword=0;
            for(int i=0;i<26;i++)
            child[i]=NULL;
        }
    };
    class Trie{
        TrieNode* root;
        public:
        Trie(){
            root=new TrieNode();
        }
        void insert(string word){
            TrieNode* node=root;
            for(char c:word){
                int index=c-'a';
                if(node->child[index]==NULL)
                node->child[index]=new TrieNode();
                node=node->child[index];
            }
            node->isendofword=1;
        }
        void searchContact(TrieNode* node,string prefix,vector<string>&temp){
            if(node->isendofword){
               temp.push_back(prefix);
            }
            for(char c='a';c<='z';c++){
                int index=c-'a';
                if(node->child[index])
                searchContact(node->child[index],prefix+c,temp);
            }
        }
        vector<string> findcontact(string s){
            TrieNode* node=root;
            for(char c:s){
                int index=c-'a';
                if(node->child[index]==NULL)
                return {"0"};
                node=node->child[index];
            }
            vector<string>temp;
            searchContact(node,s,temp);
            return temp;
        }
    };
  public:
    vector<vector<string>> displayContacts(int n, string contact[], string s) {
        // code here
        Trie* root=new Trie();
        for(int i=0;i<n;i++){
            root->insert(contact[i]);
        }
        vector<vector<string>>ans;
        string prefix="";
        for(int i=0;i<s.size();i++){
            prefix+=s[i];
            vector<string>temp=root->findcontact(prefix);
            ans.push_back(temp);
        }
        return ans;
    }
};