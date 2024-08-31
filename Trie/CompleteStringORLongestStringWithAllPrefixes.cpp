#include <bits/stdc++.h> 
using namespace std;

struct Node{
    Node* links[26];
    int ew = 0, cp = 0;

    bool containsKey(char c){
        return links[c-'a'] != NULL;
    }

    Node* get(char c){
        return links[c-'a'];
    }

    void put (char c, Node* node){
        links[c-'a'] = node;
    }
};

class Trie{
    private: Node* root;

    public: 
        Trie(){
            root = new Node();
        }

        void insert(string &word){
            Node* node = root;
            for (int i = 0; i < word.size(); i++){
                if (!node -> containsKey(word[i])){
                    node -> put(word[i], new Node()); 
                }
                node = node -> get(word[i]);
                node -> cp++;
            }
            node -> ew++;
        }

        bool isContained(string &word){
            Node* node = root;
            for (int i = 0; i < word.size(); i++){
                if (!node -> containsKey(word[i])){
                    return false;
                }
                node = node -> get(word[i]);
            }
            return node -> ew;
        }
};

string completeString(int n, vector<string> &a){
    // Write your code here.
    set <string> st;
    string ans;
    Trie *obj = new Trie();
    for (int i = 0; i < n; i++){
        obj->insert(a[i]);
    }
    for (int i = 0; i < n; i++){
        bool flag = true;
        string tmp;
        for (int j = 0; j < a[i].size(); j++){
            tmp.push_back(a[i][j]);
            if (!obj->isContained(tmp)){
                flag = false;
                break;
            }
        }
        if (flag) st.insert(a[i]);
    }
    int len = 0;
    for (auto it : st){
        if (len < it.size()){
            ans = it;
            len = it.size();
        }
    }
    if (st.size() == 0) return "None";
    return ans;

}