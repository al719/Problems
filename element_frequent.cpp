#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int temp=0;
    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j =0;j<n;j++){
            if(arr[i]==arr[j])
            {
                cnt++;
                temp=j;
            }
        }
          
           if(i<=temp){
           cout<<arr[temp]<<" repeated: "<<cnt<<" Times\n";}
        }
}