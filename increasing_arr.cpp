#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    bool is_increase = true;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for (int j = 0; j < n-1; j++)
    {
        if(arr[j]>arr[j+1]){is_increase=0;break;}
        {is_increase = arr[j]<arr[j+1];
        continue;}
        is_increase = false;
    }
    if(is_increase) cout<<"YES\n";
    else cout<<"NO\n";
    
}