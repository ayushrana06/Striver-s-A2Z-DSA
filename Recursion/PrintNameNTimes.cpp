# include <bits/stdc++.h>
using namespace std;

void func(int cntr){
    if (cntr == 0){
        return ;
    }
    cout<<"Ayush Rana"<<endl;
    func(cntr-1);
}

int32_t main(){
    int n;
    cin>>n;
    func(n);
}