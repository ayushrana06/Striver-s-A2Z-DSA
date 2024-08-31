# include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* links[2];

    bool containsKey(int bit){
        return links[bit] != NULL;
    }

    Node* get(int bit){
        return links[bit];
    }

    void put (int bit, Node* node){
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
                int bit = (num>>i)&1;
                if (!node -> containsKey(bit)){
                    node -> put(bit, new Node());
                }
                node = node -> get(bit);
            }
        }   

        int getMax(int num){
            Node* node = root;
            if (!node -> containsKey(0) && !node -> containsKey(1)) return -1;
            int maxi = 0;
            for (int i = 31; i >= 0; i--){
                int bit = (num >> i)&1;
                if (node -> containsKey(1-bit)){
                    maxi = maxi | (1<<i);
                    node = node -> get(1-bit);
                }
                else node = node -> get(bit);
            }
            return maxi;
        }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();
        vector <int> ans(m, -1);
        vector <pair <int, pair<int, int>>> vec;
        for (int i = 0; i < m; i++){
            vec.push_back({queries[i][1], {queries[i][0], i}});
        }
        Trie* obj = new Trie();
        sort(vec.begin(), vec.end());
        sort(nums.begin(), nums.end());
        int ind = 0;
        for (int i = 0; i < m; i++){
            while (ind < n && vec[i].first >= nums[ind]){
                obj -> insert(nums[ind]);
                ind++;
            }
            ans[vec[i].second.second] = obj -> getMax(vec[i].second.first);
        }
        return ans;
    }
};