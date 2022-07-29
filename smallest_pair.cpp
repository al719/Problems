#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int min1,min2;
    if(arr[0]<=arr[1]){
        min1 = arr[0];
        min2 = arr[1];
    }
    else{
        min1=arr[1];
        min2=arr[0];
    }
    int k,m;
    for(int i=2;i<n;++i){
        if(min1>=arr[i]){
            min2=min1;min1 =arr[i];
            k=i;
        }
        else if(min2>arr[i]){
            min2 = arr[i];   
            m=i;
        }
        if(min1 == arr[i-2]) k=i-2;
        if(min2 == arr[i-2]) m=i-2;
    }
    //cout<<min1<<" "<<min2<<" "<<endl;
    //cout<<k<<" "<<m<<endl;
    cout<<"Output: "<<min1+min2+m-k<<endl;
}