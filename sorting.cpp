#include <bits/stdc++.h>
using namespace std;
//using buble sort
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int j;
    int temp=0;
    for(int i=0,j=i+1;i<n-1;){
        if(arr[j]<arr[i]){
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
        if(j == n-1){
            i++;
            j=i+1;
            continue;
        }
        j++;
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
}
