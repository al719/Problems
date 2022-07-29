#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    int arr[201];
    int freqArr[201];
    int cnt=0;
    int s;
    int x=0;
   for(int i=0;i<n;i++){
    cin>>s;
    for(;;){
        arr[x] = s%10;
      //  freqArr[arr[x]]++;
        s /=10;
        cnt++;
        x++;
        if(s == 0)break;
    }
   }
  // for(int i=0;i<cnt;i++){
  // cout<<arr[i]<<" repeated: "<<freqArr[arr[i]]<<" times\n";
  // }
   
    int last=0;
    int count=0;
    int j = 0;
    for(int k=0;k<cnt;){

        if(arr[k] == arr[j]){
            count++;  
        }
        if(j == cnt-1){
        j=0;
        if(arr[k] != last){
        cout<<arr[k]<<" repeated: "<<count<<" times\n";
        last = arr[k];   
        }
        count=0;
        k++;
        continue;
        }
            j++;    
    }

 
}