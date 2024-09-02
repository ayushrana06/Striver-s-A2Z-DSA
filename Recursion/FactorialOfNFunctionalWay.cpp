# include <bits/stdc++.h>
using namespace std;

int fact (int n){
    if (n == 0){
        return 1;
    }
    return n * fact(n-1);
}

int32_t main(){
    int n;
    cin>>n;
    cout<<fact(n)<<endl;
}