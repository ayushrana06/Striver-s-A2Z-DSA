# include <bits/stdc++.h>
using namespace std;

void func (int cntr){
    if (cntr == 0){
        return ;
    }
    cout<<cntr<<endl;
    cntr--;
    func(cntr);
}

int32_t main(){
    int n;
    cin>>n;
    func(n);
}