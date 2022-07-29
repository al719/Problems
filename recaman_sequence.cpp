#include <bits/stdc++.h>
using namespace std;
//concept of frequent array
int main(){
    int n;
    cin>>n;
    int arr[n];
    arr[0] =0;
    int freq_arr[201] {0};
    freq_arr[arr[0]]++;
    bool is_exist = false;
    for(int i=1;i<=n;i++){
        if((arr[i-1]-i)>0 && is_exist == false){
            arr[i] = arr[i-1]-i;
            freq_arr[arr[i]]++;
        }
        else{
            arr[i] = arr[i-1]+i;
            freq_arr[arr[i]]++;
        }
        if(freq_arr[arr[i]-i-1] != 0){
            is_exist = true;
        }
        else is_exist =false;
    }
    for(int i=0;i<=n;i++){
        cout<<arr[i]<<" ";
    }
}

/*
int n;
    cin>>n;
    int arr[n];
    arr[0]=0;
    int count =0;
    bool is_exist =true;
    int last=0;//last = arr[count]         
    for( int x=1;x<n;x++){
        last= arr[count]-count-1;
         for(int i=count-1;i>=0;i--){
        if(arr[i] == last){
            is_exist = true;
            break;
        }
        is_exist==false;
    } 
        if((arr[x-1]-x)>0 && is_exist==false){
            arr[x] = arr[x-1]-x;
            is_exist==true;
        }
        else{
            arr[x] = arr[x-1] + x;
            is_exist==false;
        }
      
      count++;
    }
*/