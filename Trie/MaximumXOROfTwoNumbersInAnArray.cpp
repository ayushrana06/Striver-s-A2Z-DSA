# include <bits/stdc++.h>
using namespace std;

struct Node{
    Node* links[2];

    bool containsKey(int bit){
        return links[bit] != NULL;
    }

    Node* get(int bit){
        return links[bit];
    }

    void put(int bit, Node* node){
        links[bit] = node;
    }
};

class Trie{
private: Node* root;

public:

    Trie(){
        root = new Node();
    }

    void insert(int num){
        Node* node = root;
        for (int i = 31; i >= 0; i--){
            int bit = (num >> i) & 1;
            if (!node -> containsKey(bit)){
                node -> put(bit, new Node());
            }
            node = node -> get(bit);
        }
    }

    int getMax(int num){
        Node* node = root;
        int maxi = 0;
        for (int i = 31; i >= 0; i--){
            int bit = (num >> i) & 1;
            if (node -> containsKey(1-bit)){
                maxi = maxi | (1<<i);
                node = node -> get(1-bit);
            }
            else {
                node = node -> get(bit);
            }
        }
        return maxi;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        Trie* obj = new Trie();
        for (int i = 0; i < n; i++){
            obj -> insert(nums[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++){
            ans = max(ans, obj -> getMax(nums[i]));
        }
        return ans;
    }
};