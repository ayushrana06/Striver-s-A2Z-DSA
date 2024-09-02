# include <bits/stdc++.h>
using namespace std;

bool check (string s, int n, int i){
    if (i >= n/2){
        return true;
    }
    if (s[i] != s[n-i-1]){
        return false;
    }
    return check(s, n, i+1);
}

int32_t main(){
    int n;
    string s;
    cin>>s;
    n = s.size();
    cout<<check(s, n, 0)<<endl;
}