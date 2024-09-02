# include <bits/stdc++.h>
using namespace std;

struct Node{
    Node* links[26];
    bool flag = false;

    bool containsKey(char c){
        return links[c-'a'] != NULL;
    }

    void put(char c, Node* node){
        links[c-'a'] = node;
    }

    Node* get(char c){
        return links[c-'a'];
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
            }
            node -> flag = true;
        }

        bool isPrefix(string &word){
            Node* node = root;
            for (int i = 0; i < word.size(); i++){
                if (!node -> containsKey(word[i])){
                    return false;
                }
                node = node -> get(word[i]);
            }
            return true;
        }

        bool hasPrefix(string &word){
            Node* node = root;
            for (int i = 0; i < word.size(); i++){
                node = node -> get(word[i]);
                if (i != word.size()-1 && (node -> flag == true)){
                    return true;
                }
            }
            return false;
        }
};

string findSimilar(vector<string>& A)
{
    // Write your code here.
    int n = A.size();
    Trie* obj = new Trie();
    for (int i = 0; i < n; i++){
        if (i > 0 && obj -> isPrefix(A[i])){
            return A[i];
        }
        obj -> insert(A[i]);
        if (i > 0 && obj -> hasPrefix(A[i])){
            return A[i];
        } 
    }
    return "not found";
}