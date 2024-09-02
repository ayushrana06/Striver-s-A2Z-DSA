# include <bits/stdc++.h>
using namespace std;

void print(int arr[], int ind, int n, int sum, int k, vector <int>& vec){
    if (ind == n){
        if (sum == k){
            for (int i = 0; i < vec.size(); i++){
                cout<<vec[i]<<" ";
            }
            cout<<endl;
        }
        return ;
    }
    // pick
    vec.push_back(arr[ind]);
    print(arr, ind+1, n, sum+arr[ind], k, vec);

    // not pick
    vec.pop_back();
    print(arr, ind+1, n, sum, k, vec);
    return ;
}

int32_t main(){
    int n, k;
    cin>>n>>k;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin>>arr[i];
    }
    vector <int> vec;
    print(arr, 0, n, 0, k, vec);
}