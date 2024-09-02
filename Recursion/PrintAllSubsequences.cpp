# include <bits/stdc++.h>
using namespace std;

void print(vector <int>& vec, int arr[], int n, int i){
    if (i >= n){
        for (int i = 0; i < vec.size(); i++){
            cout<<vec[i]<<" ";
        }cout<<endl;
        return ;
    }
    // pick
    vec.push_back(arr[i]);
    print(vec, arr, n, i+1);

    // not pick
    vec.pop_back();
    print(vec, arr, n, i+1);
}

int32_t main (){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin>>arr[i];
    }
    vector <int> vec;
    print(vec, arr, n, 0);
}