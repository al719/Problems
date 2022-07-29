#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    int subArr[k];
    for(int i=0;i<k;i++){
        cin>>subArr[i];
    }
    
    int j=0;
    int temp=0;
    bool is_not_exist =false;
    for(int i=0;i<k;){
        if(subArr[i] == arr[j]){
            temp = j;
            is_not_exist = true;
        }
        if(j == n-1 && is_not_exist ==true) 
        {
            cout<<subArr[i]<<" Exists in position: "<<temp<<endl;
            i++;
            j=0;
            is_not_exist = false;
            continue;
        }
        else if(j == n-1 && is_not_exist ==false) 
        {
            cout<<subArr[i]<<" NOT Exists in the given array: "<<-1<<endl;
            i++;
            j=0;
            continue;
        }
        j++;
    }
    

}