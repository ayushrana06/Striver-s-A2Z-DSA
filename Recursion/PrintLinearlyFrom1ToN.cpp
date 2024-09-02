# include <bits/stdc++.h>
using namespace std;

void func (int cntr, int n){
    if (cntr == n+1){
        return ;
    }
    cout<<cntr<<endl;
    cntr++;
    func(cntr, n);
}

int32_t main(){
    int n;
    cin>>n;
    func(1, n);
}