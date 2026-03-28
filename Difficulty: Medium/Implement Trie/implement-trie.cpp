// User function template for C++
class TrieNode{
    public:
    TrieNode* child[26];
    bool isEndOfWord;
    TrieNode(){
        isEndOfWord=0;
        for(int i=0;i<26;i++)
        child[i]=NULL;
    }
};
class Trie {
  public:
  TrieNode* root;
    Trie() {
        // implement Trie
        root=new TrieNode();
    }

    void insert(string &word) {
        // insert word into Trie
        TrieNode* node=root;
        for(char c:word){
            int index=c-'a';
            if(node->child[index]==NULL)
            node->child[index]=new TrieNode();
            node=node->child[index];
        }
        node->isEndOfWord=1;
    }

    bool search(string &word) {
        // search word in the Trie
        TrieNode* node=root;
        for(char c:word){
            int index=c-'a';
            if(node->child[index]==NULL)
            return 0;
            node=node->child[index];
        }
        return node->isEndOfWord;
    }

    bool isPrefix(string &word) {
        // search prefix word in the Trie
        TrieNode* node=root;
        for(char c:word){
            int index=c-'a';
            if(node->child[index]==NULL)
            return 0;
            node=node->child[index];
        }
        return 1;
    }
};
