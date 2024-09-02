# include <bits/stdc++.h>
using namespace std;

void func(int cntr){
    if (cntr == 0){
        return ;
    }
    func(cntr-1);
    cout<<cntr<<endl;
}

int32_t main(){
    int n;
    cin>>n;
    func(n);
}