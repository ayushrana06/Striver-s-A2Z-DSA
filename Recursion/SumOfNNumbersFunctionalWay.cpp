# include <bits/stdc++.h>
using namespace std;

int sum(int cntr){
    if (cntr == 0){
        return cntr;
    }
    return cntr + sum(cntr-1);
}

int32_t main(){
    int n;
    cin>>n;
    cout<<sum(n)<<endl;
}