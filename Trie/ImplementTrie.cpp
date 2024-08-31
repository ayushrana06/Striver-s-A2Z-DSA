# include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* links[26];
    bool flag = false;

    bool containsKey(char c){
        return links[c-'a'] != NULL;
    }

    void put (char c, Node* node){
        links[c-'a'] = node;
    }

    void setEnd (){
        flag = true;
    }

    Node* get(char c){
        return links[c-'a'];
    }

    bool isEnd(){
        return flag;
    }
};

class Trie {
    
private: Node* root;

public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++){
            if (!node -> containsKey(word[i])){
                node -> put(word[i], new Node());
            }
            node = node -> get(word[i]);
        }
        node -> setEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++){
            if (!node -> containsKey(word[i])){
                return false;
            }
            else{
                node = node -> get(word[i]);
            }
        }
        return node -> isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for (int i = 0; i < prefix.size(); i++){
            if (!node -> containsKey(prefix[i])){
                return false;
            }
            node = node -> get(prefix[i]);
        }
        return true;
    }
};