# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set <char> st;
        int i = 0, j = 0, n = s.size(), ans = 0;
        while (j < n){
            if (st.find(s[j]) == st.end()){
                st.insert(s[j]);
                int sz = st.size();
                ans = max(ans, sz);
            }
            else{
                while (s[i] != s[j]){
                    st.erase(s[i]);
                    i++;
                }
                st.erase(s[i]);
                st.insert(s[j]);
                i++;
            }
            j++;
        }
        return ans;
    }
};