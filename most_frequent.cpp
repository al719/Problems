#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int count=0;
    int last=0;
    int j = 0,temp;
    for(int k=0;k<n;){

        if(arr[k] == arr[j]){
            count++;  
        }
        if(j == n-1){
            j=0;
            if(last < count){
            last = count;
            temp = k;        
            }
            count=0;
        k++;
        continue;
        }
            j++;
        
    }
    cout<<arr[temp]<<" repeated: "<<last<<" times\n";

    
}