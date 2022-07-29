#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    bool is_palind =false;
    for(int j=0,k=n-1;j<n/2;j++,k--){
            if(arr[k] == arr[j]){
                is_palind = true;
                continue;
            }
            is_palind =false;
    }
    if(is_palind) cout<<"YES\n";
    else cout<<"NO\n";
}