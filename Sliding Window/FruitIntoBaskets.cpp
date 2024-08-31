# include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int totalFruits(vector<int> &arr) {
        map <int, int> mp;
        int i = 0, j = 0, n = arr.size(), ans = 0;
        while (j < n){
            mp[arr[j]]++;
            if (mp.size() <= 2){
                int total = 0;
                for (auto it : mp){
                    total += it.second;
                }
                ans = max(ans, total);
            }
            else{
                while (mp.size() > 2){
                    mp[arr[i]]--;
                    if (mp[arr[i]] == 0) mp.erase(arr[i]);
                    i++;
                }
            }
            j++;
        }
        return ans;
    }
};