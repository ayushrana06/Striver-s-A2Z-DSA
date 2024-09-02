# include <bits/stdc++.h>
using namespace std;

void reverse(int n, int i, int arr[]){
    if (i >= n/2){
        return ;
    }
    swap(arr[i], arr[n-i-1]);
    reverse(n, i+1, arr);
}

int32_t main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin>>arr[i];
    }
    reverse(n, 0, arr);
    for (int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}