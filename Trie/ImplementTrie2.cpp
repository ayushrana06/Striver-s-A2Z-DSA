# include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* links[26];
    int ew = 0, cp = 0;

    bool containsKey(char c){
        return links[c-'a'] != NULL;
    }

    void put (char c, Node* node){
        links[c-'a'] = node;
    }

    Node* get (char c){
        return links[c-'a'];
    }
};

class Trie{
    private: Node* root;

    public: 
        Trie(){
            root = new Node();
        }

        void insert (string& word){
            Node* node = root;
            for (int i = 0; i < word.size(); i++){
                if (!node -> containsKey(word[i])){
                    node -> put(word[i], new Node());
                }
                node = node -> get(word[i]);
                node -> cp++;
            }
            node -> ew ++;
        }

        int countWordsEqualTo(string &word){
            Node* node = root;
            for (int i = 0; i < word.size(); i++){
                if (!node -> containsKey(word[i])){
                    return 0;
                }
                node = node -> get(word[i]);
            }
            return node -> ew;
        }

        int countWordsStartingWith(string &word){
            Node* node = root;
            for (int i = 0; i < word.size(); i++){
                if (!node -> containsKey(word[i])){
                    return 0;
                }
                node = node -> get(word[i]);
            }
            return node -> cp;
        }

        void erase(string &word){
            Node* node = root;
            for (int i = 0; i < word.size(); i++){
                node = node -> get(word[i]);
                node -> cp --;
            }
            node -> ew --;
        }
};