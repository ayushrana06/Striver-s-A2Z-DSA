# include <bits/stdc++.h>
using namespace std;

void sum (int n, int ans){
    if (n == 0){
        cout<<ans<<endl;
        return ;
    }
    sum(n-1, ans+n);
}

int32_t main(){
    int n, ans = 0;
    cin>>n;
    sum(n, ans);
}