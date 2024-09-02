# include <bits/stdc++.h>
using namespace std;

void fact (int n, int ans){
    if (n == 0){
        cout<<ans<<endl;
        return ;
    }
    fact(n-1, ans*n);
}

int32_t main(){
    int n, ans = 1;
    cin>>n;
    fact(n, ans);
}