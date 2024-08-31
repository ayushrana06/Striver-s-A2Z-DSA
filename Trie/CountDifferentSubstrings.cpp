# include <bits/stdc++.h>
using namespace std;

struct Node{
    Node* links[26];

    bool containsKey(char c){
        return links[c-'a'];
    }

    void put(char c, Node* node){
        links[c-'a'] = node;
    }

    Node* get(char c){
        return links[c-'a'];
    }
};

int countDistinctSubstrings(string &s)
{
    //    Write your code here.

    // Using set, brute force approach

    // T.C = O(N^2LogM) S.C = O(N^3)

    // set <string> st;
    // int n = s.size();
    // for (int i = 0; i < n; i++){
    //     string tmp;
    //     for (int j = i; j < n; j++){
    //         tmp.push_back(s[j]);
    //         st.insert(tmp);
    //     }
    // }
    // return st.size()+1;

    // Using Trie T.C = O(N^2) S.C=O(N^2)

    Node* root = new Node();
    int n = s.size(), cntr = 0;
    for (int i = 0; i < n; i++){
        Node* node = root;
        for (int j = i; j < n; j++){
            if (!node -> containsKey(s[j])){
                node -> put(s[j], new Node());
                cntr++;
            }
            node = node -> get(s[j]);
        }
    }
    return cntr+1;
}